#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<conio.h>
#include<windows.h>


//Define section
#define incl fflush(stdin)
#define ENTER 13
#define TAB 9
#define BCKSPC 8


struct doctor_bio
{
    char doctorname[60];
    char doctorid[20];
    char speciality[60];
    char phonenumber[20];
    char location[60];
    char email[60];
    char available[50];

}dobj;


struct patient_bio
{
    char name[50];
    char height[20];
    char previous_med[200];
    char age[10];
    char weight[10];
    char bloodgrp[15];
    char bp[10];
    char bs[10];

}pobj;


//User define header file
#include"Function.h"
#include"patient.h"
#include"doctor.h"


//Template
int Main();
void cat(char struc[], char normal[]);



int main()
{

    FILE *f;

    f=fopen("C:\\GetYourDoctor\\Doctor\\speciality.txt","r");
    if(f==NULL)
    {
        fclose(f);
        system("mkdir C:\\GetYourDoctor\\Doctor");
        system("mkdir C:\\GetYourDoctor\\Patient");
//        f=fopen("C:\\GetYourDoctor\\check.txt","w");
//        fclose(f);
        f=fopen("C:\\GetYourDoctor\\Doctor_id.txt","w");
        fclose(f);
        f=fopen("C:\\GetYourDoctor\\Doctor\\speciality.txt","w");
        fclose(f);
        f=fopen("C:\\GetYourDoctor\\specialist_info.txt","w");
        fclose(f);

    }
    fclose(f);

    Main();

    return 0;
}



int Main()
{
    int choice;
    while(1)
    {
        system("cls");
        Text_Color(14);
        printf("\n\n\t\t\t\t\t      Main Menu\n");
        printf("\t\t\t\t\t ----===========----\n");
        Text_Color(15);
        printf("\n\n\t\t\t[1] Search doctor                [2] Patient service\n\n\n");

        //printf("\t\t\t[2] Patient service.\n\n\n");

        printf("\n\t\t\t[3] Doctor service               [4] Specialist Info!\n\n");

        //printf("\t\t\t\t[4] Specialist Info!\n");
        printf("\n\n\t\t\t\t\t[0] Close the program...");

        Text_Color(6);
        printf("\n\n\t\t\t\t\t=> ");

        scanf("%d",&choice);
        Text_Color(15);


        if(choice==1) search_doctor();
        else if (choice==2) patient_main();
        else if(choice==3) doctor_main();
        else if(choice==4) show_specialist();
        else if(choice==0) exit(0);
        else
        {
            Text_Color(4);
            printf("\n\t\t\t\t\t       Wrong input!\n"); incl;
            Text_Color(7);
            printf("\n\n\t\t\t\t\tPress any key to continue..."); getch();
        }

    }
}


void cat(char struc[], char normal[]){

    int len1=strlen(normal);
    int i;

    for( i=0; i<len1; i++){


        struc[i]=normal[i];
    }
    struc[i]='\0';

}






/*
file name = Doctor_id.txt

Doctorlist

20211103042 Suvo_roy Cumilla
20211103043 Adiba_jahin Mirpur
20211103044 Mohammed_Iftekharul_Islam Mirpur
20211103046 Md._Siam_Shahrear Bd
20211103047 Farhana_Akter_Jedni Bd
20211103048 Akimul_Islam_Turjoy Bd
20211103050 Probin_Bhatta_Majumder Bd
20211103052 Afia_jahin Rajshahi
20211103053 Alamgir_Khan BD
20211103054 Tanjid_Hossen Bd
20211103055 Md_Mehedi_Hassan BD
20211103058 Anayet_hossain_Rakib BD
20211103059 Showrobh_kumar_Roy Mirpur
20211103060 Kazi_Ratun Madaripur
20211103062 Md.Atikur_Rahman Bd
20211103063 Radoan_Islam_Nabil Madaripur
20211103064 Ruhul_Amin_Rajib Sylhet
20211103065 Md._Abid_ul_islam Dhaka
20211103066 Akhtaruzzaman_Jisan Dhaka
20211103069 Naeema_Ferdous_Roza Bangladesh
20211103070 Md._Shahriar_Jaman Bangladesh
20211103072 Mohammed_Zahid_Hassan Rajshahi
20211103074 Abdur_Rahman Dhaka
19202103280 Shahriar_Shejan Kushtia
19202103370 Tasnim_Jahan_Samiha Bangladesh
19202103385 Shaikat_Majumder_Antu Noakhali
19202103392 Jannatul_Ferdous_Sharna Bangladesh
19202103393 Md._Omar_Faruk Bangladesh
19202103374 Muhammad_Kamruzzaman_Nahid Bangladesh
19202103365 Md_Rasidul_Islam Bd

*/



