void Toupper(char str[]);
void Text_Color(int clrr);
void doctor_main();                                 //Located in the Doctor header
void patient_main();                                //Located in the patient header
void change_password(char idorname[], int doc_or_pat);
void cat();                                         //Located in the .c file
void print_doc_info(char docId[], int cnt);
void find_doctor(char specialist[], char doc_location[]);
void search_doctor();
bool check_doc(char doc_id[]);
char *takepassword(char pass[50]);
void search_patient();
int Main();                                         //Located in the .c file
void doctor_edit_profile(char doctor_id[]);
void after_doctor_login(char doc_id[]);
void patient_edit_profile(char patient_name[]);
void add_medicine(char patient_name[]);
void after_patient_login(char patient_name[]);
void Login(bool DorP);
void view_doctor_profile(char doctorId[]);          //Located in the Doctor header
void view_patient_profile(char patient_name[]);     //Located in the patient header
void SignUp(bool DorP);
void show_specialist();


void Toupper(char str[])
{
    int j=0;

    while (str[j])
    {

        str[j]=toupper(str[j]);
        j++;

    }

}



void Text_Color(int clrr)
{
    WORD wColor;
    HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut,&csbi))
    {
        wColor=(csbi.wAttributes & 0xF0)+(clrr & 0x0F);
        SetConsoleTextAttribute(hStdOut,wColor);
    }
}



void change_password(char idorname[], int doc_or_pat)
{
    char doc_addr[100]= {"C:\\GetYourDoctor\\Doctor\\"}, pat_addr[100]= {"C:\\GetYourDoctor\\Patient\\"}, old_pass[70];
    char user_pass[70], new_pass[70], confirm_pass[70], hold[70];

    FILE *f;

    system("cls");
    Text_Color(14);
    printf("\n\n\t\t\t\t\t___Change Password___");
    Text_Color(15);

    if(doc_or_pat==1)
    {
        strcat(doc_addr,idorname);
        strcat(doc_addr,"\\");
        strcat(doc_addr,"password.txt");

        f=fopen(doc_addr,"r");

        fgets(old_pass,70,f);
        fclose(f);


        printf("\n\n\n\n\t\t\t\tEnter previous password\t:\t");
        incl;
        gets(user_pass);

        if(strcmp(user_pass,old_pass)==0)
        {

            printf("\n\n\n\t\t\t\tEnter new password\t:\t");
            incl;
            takepassword(new_pass);
            printf("\n\n\n\t\t\t\tConfirm new password\t:\t");
            incl;
            takepassword(confirm_pass);

            if(strcmp(new_pass,confirm_pass)==0)
            {

                f=fopen(doc_addr,"w");
                fputs(new_pass,f);
                fclose(f);

                Text_Color(6);
                printf("\n\n\n\t\t\t\tPassword changed successfully!");
                Text_Color(7);

                printf("\n\n\n\n\t\t\t\tPress any key to continue...");
                getch();
            }

            else
            {
                cat(hold,idorname);

                Text_Color(4);
                printf("\n\n\n\t\t\t\t\tPassword not matched!\n\n\t\t\t\t\t    Try again!");
                Text_Color(7);

                printf("\n\n\n\n\t\t\t\tPress any key to continue...");
                getch();

                change_password(hold,1);
            }
        }

        else
        {
            Text_Color(4);
            printf("\n\n\n\t\t\t\t\tPassword not matched!\n\n\t\t\t\t\t    Try again!\n");
            Text_Color(7);


            printf("\n\n\n\t\t\t\tPress any key to continue...");
            getch();

            cat(hold,idorname);

            change_password(hold,1);

        }

    }


    else
    {
        strcat(pat_addr,idorname);
        strcat(pat_addr,"\\");
        strcat(pat_addr,"password.txt");

        f=fopen(pat_addr,"r");

        fgets(old_pass,70,f);
        fclose(f);



        printf("\n\n\n\n\t\t\t\tEnter previous password\t:\t");
        incl;
        gets(user_pass);

        if(strcmp(user_pass,old_pass)==0)
        {

            printf("\n\n\n\t\t\t\tEnter new password\t:\t");
            incl;
            takepassword(new_pass);
            printf("\n\n\n\t\t\t\tConfirm new password\t:\t");
            incl;
            takepassword(confirm_pass);

            if(strcmp(new_pass,confirm_pass)==0)
            {

                f=fopen(pat_addr,"w");
                fputs(new_pass,f);
                fclose(f);

                Text_Color(6);
                printf("\n\n\n\t\t\t\tPassword changed successfully");
                Text_Color(7);
                printf("\n\n\n\t\t\t\tPress any key to continue...");
                getch();
            }

            else
            {
                char hold[70];

                cat(hold,idorname);


                Text_Color(4);
                printf("\n\n\n\t\t\t\t\tPassword not matched!\n\n\t\t\t\t\t    Try again!");
                Text_Color(7);

                printf("\n\n\n\n\n\t\t\t\tPress any key to continue...");
                getch();

                change_password(hold,0);
            }
        }
        else
        {
            Text_Color(4);
            printf("\n\n\t\t\t\t\tPassword not matched!\n\n\t\t\t\t\t    Try again!");
            Text_Color(7);


            printf("\n\n\n\n\n\t\t\t\tPress any key to continue...");
            getch();

            cat(hold,idorname);

            change_password(hold,0);

        }
    }


}




void print_doc_info(char docId[], int cnt)
{

    char Uaddr[100]="C:\\GetYourDoctor\\Doctor\\";
    strcat(Uaddr,docId);
    strcat(Uaddr,"\\");
    strcat(Uaddr,"Personal_profile.txt");


    FILE *f;

    f= fopen(Uaddr,"r");

    if(f==NULL) printf("\n(%s) doctor's file not found\n",docId);

    else
    {

        fread(&dobj, sizeof(dobj), 1, f);

        Text_Color(14);
        printf("\n\n\t\t\t\t%d.\n",cnt);
        Text_Color(15);

        printf("\t\t\t\tDoctor name\t:\tDr.%s\n",dobj.doctorname);
        printf("\n\t\t\t\tDoctor Id\t:\t%s\n",dobj.doctorid);
        printf("\n\t\t\t\tSpecialist in\t:\t%s\n",dobj.speciality);
        printf("\n\t\t\t\tContact number\t:\t%s\n",dobj.phonenumber);
        printf("\n\t\t\t\tPresent Location:\t%s\n",dobj.location);
        printf("\n\t\t\t\tDoctor Email\t:\t%s\n",dobj.email);
        printf("\n\t\t\t\tAvailability\t:\t%s\n",dobj.available);

        Text_Color(7);
        printf("\n\t\t\t========================================================\n");
        Text_Color(10);
    }


}


void find_doctor(char specialist[], char doc_location[])
{
    char file_addr[100]= {"C:\\GetYourDoctor\\Doctor\\speciality.txt"};
    char doc_ID_from_file[20], speciality_from_file[60], location_from_file[100];
    int counT=1,cnt=1;

    FILE *f;

    f= fopen(file_addr,"r");

    while(!feof(f))
    {
        int matching=0,len;

        fscanf(f,"%s %s %s",doc_ID_from_file,speciality_from_file,location_from_file);

        len= strlen(specialist);


        //Checking partial matching
        for(int i=0; i<3; i++)
        {
            if(matching>=2)
            {
                //printf("\n%d = %s, %s, %s\n",matching,doc_ID_from_file,speciality_from_file,location_from_file);

                break;
            }

            if(specialist[i] == speciality_from_file[i] && location_from_file[i] == doc_location[i] )
            {

                matching++;

            }

        }


        if(feof(f))
        {

            Text_Color(6);
            printf("\n\n\n\t\t\t\t'%d' Results found!!",cnt-1);
            Text_Color(15);
            break;
        }

        if(matching>=2)
        {

            print_doc_info(doc_ID_from_file, counT);

            counT++;
            cnt++;

        }

    }
    fclose(f);


    if(counT==1)
    {
        Text_Color(4);
        printf("\n\n\t\t\t\tNo doctor found nearby!! \n");
//        printf("\n\n\t\t\t\t\tPress any key to continue...");
//        getch();
    }



}




void search_doctor()
{

    char speciality[60], doctors_location[100];

    system("cls");

    Text_Color(14);
    printf("\n\n\t\t\t\t\t___Search Doctor___\n");
    Text_Color(15);

    printf("\n\n\t\t\t\tEnter Speciality :\t");
    incl;
    gets(speciality);

    printf("\n\n\t\t\t\tEnter location   :\t");
    incl;
    gets(doctors_location);

    Toupper(speciality);
    Toupper(doctors_location);


    find_doctor(speciality,doctors_location);


    Text_Color(7);
    printf("\n\n\t\t\t\tPress any key to continue...");
    getch();


}




bool check_doc(char doc_id[])
{
    char id[14];
    bool flag=false;
    FILE *f;
    f=fopen("C:\\GetYourDoctor\\Doctor_id.txt","r");

    if(f==NULL)printf("Doctor id list not found\n");
    else
    {
        //Checking that the doctor Id is in the doctor.txt file or nor.
        while(!feof(f))
        {
            fgets(id,12,f);

            if(strcmp(doc_id,id)==0)
            {
                flag=true;
                break;
            }
        }
        fclose(f);


        //If the the doc_id matched with the id read from file then it will return true else return false.
        return flag;
    }
}


char *takepassword(char pass[50])
{
    int i;
    char ch;
    while(1)
    {
        ch = getch();
        if(ch == ENTER || ch == TAB)
        {
            pass[i] = '\0';
            break;
        }
        else if(ch == BCKSPC)
        {
            if(i>0)
            {
                i--;
                printf("\b \b");    // 1 2 3
            }
        }
        else
        {
            pass[i++] = ch;
            printf("* \b");
        }
    }
    printf("\n");
    return (char *)pass;
}




void search_patient()
{
    char nam[100], Uaddr[100]="C:\\GetYourDoctor\\Patient\\";

    system("cls");
    Text_Color(14);
    printf("\n\n\n\t\t\t\t\t___View patient Info!___\n\n");
    Text_Color(15);
    printf("\n\n\t\t\t\tEnter patient Username :\t");
    incl;
    gets(nam);

    //Creating address
    strcat(Uaddr,nam);
    strcat(Uaddr,"\\");
    strcat(Uaddr,"personal_profile.txt");


    FILE *f;

    f=fopen(Uaddr,"r");

    //if the file is NULL it means their is no patient with the name.
    if(f==NULL)
    {
        fclose(f);

        Text_Color(6);
        printf("\n\n\t\t\t    No result found for the Username [%s]\n",nam);
        Text_Color(7);
        printf("\n\n\t\t\t\tPress any key to continue...");
        getch();
    }


    else
    {

        //reading the patient info from file
        fread(&pobj,sizeof(pobj),1,f);
        fclose(f);

        system("cls");

        Toupper(nam);
        Text_Color(14);
        printf("\n\n\t\t\t\tPatient information of '%s' ...\n",nam);
        Text_Color(15);

        //Printing patient info
        printf("\n\n\t\t\t\tName\t\t:\t%s\n",pobj.name);
        printf("\n\t\t\t\tAge\t\t:\t%s\n",pobj.age);
        printf("\n\t\t\t\tHeight\t\t:\t%s\n",pobj.height);
        printf("\n\t\t\t\tWeight\t\t:\t%s\n",pobj.weight);
        printf("\n\t\t\t\tBlood Group\t:\t%s\n",pobj.bloodgrp);
        printf("\n\t\t\t\tBlood Pressure\t:\t%s\n",pobj.bp);
        printf("\n\t\t\t\tBlood sugar\t:\t%s\n",pobj.bs);
        printf("\n\t\t\t\tPrevious Medicines:\t%s\n",pobj.previous_med);
        Text_Color(7);
        printf("\n\n\t\t\t\tPress any key to continue...");
        getch();
    }


}





void doctor_edit_profile(char doctor_id[])
{
    char personal_profile[100]="C:\\GetYourDoctor\\Doctor\\";

    char file_doc_name[100], file_doc_speciality[80];

    strcat(personal_profile,doctor_id);
    strcat(personal_profile,"\\");
    strcat(personal_profile,"personal_profile.txt");

    cat(dobj.doctorid,doctor_id);

    FILE *f;

    f= fopen(personal_profile,"r");

    if(f==NULL) printf("\n\tCannot open the personal.txt file\n");

    else
    {
        fread(&dobj, sizeof(dobj), 1, f);

        cat(file_doc_name,dobj.doctorname);
        cat(file_doc_speciality,dobj.speciality);

    }
    fclose(f);



    system("cls");
    Text_Color(14);
    printf("\n\t\t\t\t\t    ___Edit Profile___\n");
    Text_Color(7);

    printf("\n\n\t\t\t     Your name\t\t      :\t%s",file_doc_name);
    //printf("\n\t\t\t\t\t[Note: You cannot change your name!]\n");


    printf("\n\t\t\t     Your doctor Id\t      :\t%s",doctor_id);
    //printf("\n\t\t\t\t\t[Note: You cannot change your doctor Id!]\n");

    printf("\n\t\t\t     Your speciality\t      :\t%s",file_doc_speciality);
    printf("\n\t\t\t     [Note: You cannot change your name, doctor Id and speciality!]\n");
    Text_Color(15);


    printf("\n\t\t\t     Enter your contact number:\t");
    incl;
    gets(dobj.phonenumber);
    printf("\n\t\t\t     Enter your location      :\t");
    incl;
    gets(dobj.location);

    int len= strlen(dobj.location);

    if(len==0)
    {
        Text_Color(4);
        printf("\n\n\n\t\t\t\t    You didnt insert any location\n");
        printf("\n\t\t\t\t    Try again with a valid location\n");
        Text_Color(7);

        printf("\n\n\t\t\t\tPress any key to continue...");
        getch();

        //SignUp(1);
        after_doctor_login(doctor_id);
    }
    else if(len<3)
    {
        Text_Color(4);
        printf("\n\n\n\t\t\t\t    Inserted location is too short\n");
        printf("\n\t\t\t\t    Try again with a valid location\n");
        Text_Color(7);

        printf("\n\n\t\t\t\tPress any key to continue...");
        getch();

        //SignUp(1);
        after_doctor_login(doctor_id);
    }


    printf("\n\t\t\t     Enter your E-mail\t      :\t");
    incl;
    gets(dobj.email);
    printf("\n\t\t\t     Enter your availability  :\t");
    incl;
    gets(dobj.available);


    //File overwritting
    //Removing the previous location name for this doctorId
    //which was saved in speciality.txt file

    f=fopen("C:\\GetYourDoctor\\Doctor\\speciality.txt","r+");

    char complete_line[100],ch;
    len= strlen(file_doc_speciality);


    while(!feof(f))
    {
        if(f==NULL) break;

        int i=0;
        char Id_from_file[14];


        for( i=0; i<11; i++)
        {
            Id_from_file[i]= fgetc(f);
        }
        ch=fgetc(f);
        ch=fgetc(f);

        Id_from_file[i]='\0';


        if(strcmp(doctor_id,Id_from_file)==0)
        {
            fseek(f, -1, SEEK_CUR);

            //making string with the size of speciality written in speciality.txt file
            char str[30];

            int j;
            for( j=0; j<len; j++)
            {

                if(j%2 == 1)
                {
                    str[j]='+';
                }
                else if(j%2 == 0)
                {
                    str[j]='-';
                }

            }
            str[j]='\0';

            fprintf(f,"%s",str);

            fseek(f, 0, SEEK_CUR);

        }

        fgets(complete_line,60,f);

    }
    fclose(f);


    //reading the personal file to get the speciality
    char addr[100]= {"C:\\GetYourDoctor\\Doctor\\"}, read_speciality[80];

    strcat(addr,doctor_id);
    strcat(addr,"\\");
    strcat(addr,"Personal_profile");

    f=fopen(addr,"r");

    fread(&dobj, sizeof(dobj),1,f);

    cat(read_speciality,dobj.speciality);
    fclose(f);




    //Updating the location in speciality.txt file

    f=fopen("C:\\GetYourDoctor\\Doctor\\speciality.txt","a");

    Toupper(read_speciality);
    Toupper(dobj.location);

    fprintf(f,"%s %s %s\n",doctor_id,read_speciality, dobj.location);

    fclose(f);



    //Now writing the updated information in personal.txt file
    f= fopen(personal_profile,"w");

    if(f==NULL) printf("\n\tCannot open the personal.txt file\n");

    else
    {
        fwrite(&dobj, sizeof(dobj), 1, f);

        Text_Color(6);
        printf("\n\n\t\t\t\t     Your changes saved successfully!\n");
        Text_Color(15);

    }
    fclose(f);

}




void after_doctor_login(char doc_id[])
{

    system("cls");
    Text_Color(14);
    printf("\n\n\t\t\t\tDoctor Id : [%s]\n",doc_id);
    printf("\t\t\t\t=========================\n\n");
    Text_Color(15);
    printf("\n\t\t\t\t\t[1] View your profile\n");
    printf("\n\t\t\t\t\t[2] View patient Info!\n");
    printf("\n\t\t\t\t\t[3] Edit profile\n");
    printf("\n\t\t\t\t\t[4] Change password\n");
    printf("\n\t\t\t\t\t[5] Main menu");

    Text_Color(6);
    int choice;
    printf("\n\n\t\t\t\t\t=> ");
    scanf("%d",&choice);
    Text_Color(10);

    if(choice==1)
    {

        view_doctor_profile(doc_id);
        after_doctor_login(doc_id);
    }
    else if(choice==2)
    {
        search_patient();
        after_doctor_login(doc_id);
    }
    else if(choice==3)
    {

        doctor_edit_profile(doc_id);

        printf("\n\n\t\t\t\t\tPress any key to continue...");
        getch();

        after_doctor_login(doc_id);
    }
    else if(choice==4)
    {

        change_password(doc_id,1);

        after_doctor_login(doc_id);
    }
    else if(choice==5)
    {
        Main();
    }
    else
    {
        Text_Color(4);
        printf("\n\t\t\t\t\tWrong Input!\n");
        incl;
        Text_Color(7);
        printf("\n\t\t\t\t\tPress any key to continue...");
        getch();
        after_doctor_login(doc_id);

    }

}




void patient_edit_profile(char patient_name[])
{
    char personal_profile[100]="C:\\GetYourDoctor\\Patient\\";
    char prev_med[200];

    strcat(personal_profile,patient_name);
    strcat(personal_profile,"\\");
    strcat(personal_profile,"personal_profile.txt");

    FILE *f;
    f=fopen(personal_profile,"r");

    if(f==NULL) printf("\nfile not found!!  Can't save info in personal profile file\n");
    else
    {

        fread(&pobj,sizeof(pobj),1,f);

        cat(prev_med,pobj.previous_med);
    }
    fclose(f);


    system("cls");
    Text_Color(14);
    printf("\n\t\t\t\t\t    ___Edit Profile___\n");
    Text_Color(7);

    printf("\n\n\t\t\t\tYour name\t\t:\t%s\n",patient_name);
    printf("\t\t\t\t[Note: You cannot change your Username!]\n");
    Text_Color(15);


    cat(pobj.name,patient_name);

    printf("\n\t\t\t\tEnter your age\t\t:\t");
    incl;
    gets(pobj.age);
    printf("\n\t\t\t\tEnter your weight\t:\t");
    incl;
    gets(pobj.weight);
    printf("\n\t\t\t\tEnter your height\t:\t");
    incl;
    gets(pobj.height);
    printf("\n\t\t\t\tEnter your blood group\t:\t");
    incl;
    gets(pobj.bloodgrp);
    printf("\n\t\t\t\tEnter your Blood pressure:\t");
    incl;
    gets(pobj.bp);
    printf("\n\t\t\t\tEnter your Blood sugar\t:\t");
    incl;
    gets(pobj.bs);
    printf("\n\t\t\t\tPrevious medicines\t:\t%s",prev_med);
    cat(pobj.previous_med,prev_med);
    Text_Color(7);
    printf("\n\t\t\t\t[Note: Medicines cannot be change from here!]\n");
    Text_Color(15);



    f=fopen(personal_profile,"w");

    if(f==NULL) printf("\nfile not found!!  Can't save info in personal profile file\n");
    else
    {

        fwrite(&pobj,sizeof(pobj),1,f);

        Text_Color(6);
        printf("\n\n\t\t\t\t\tYour changes saved successfully!\n");
        Text_Color(15);
    }
    fclose(f);

}





void add_medicine(char patient_name[])
{
    char new_medi[100],height[10], prev_medi[260],age[10],weight[10],bloodgroup[15],bp[10],bs[10];
    char personal_profile[100]="C:\\GetYourDoctor\\Patient\\";

    strcat(personal_profile,patient_name);
    strcat(personal_profile,"\\");
    strcat(personal_profile,"personal_profile.txt");

    system("cls");


    FILE *f;

    f= fopen(personal_profile,"r");

    if(f==NULL) printf("\nPersonal profile file not found (r)\n");

    else
    {

        fread(&pobj, sizeof(pobj), 1, f);

        strcat(height,pobj.height);
        strcat(age,pobj.age);
        strcat(weight,pobj.weight);
        strcat(bloodgroup,pobj.bloodgrp);
        strcat(bp,pobj.bp);
        strcat(bs,pobj.bs);
        strcat(prev_medi,pobj.previous_med);
        strcat(prev_medi,", ");


        Text_Color(14);
        printf("\n\n\t\t\t\t\t___Add Medicine___\n");
        Text_Color(15);

        incl;
        printf("\n\n\t\t\t\tEnter new medicine\t:\t");
        gets(new_medi);

        strcat(prev_medi,new_medi);

    }
    fclose(f);


    f= fopen(personal_profile,"w");

    if(f==NULL) printf("\nPersonal profile file not found (w)\n");

    else
    {


        cat(pobj.name,patient_name);
        cat(pobj.age,age);
        cat(pobj.height,height);
        cat(pobj.weight,weight);
        cat(pobj.bloodgrp,bloodgroup);
        cat(pobj.bp,bp);
        cat(pobj.bs,bs);
        cat(pobj.previous_med,prev_medi);

        fwrite(&pobj, sizeof(pobj), 1, f);

        Text_Color(6);
        printf("\n\n\t\t\t\tNew medicines saved successfully!!\n\n\n");
        Text_Color(15);
    }
    fclose(f);

}





void after_patient_login(char patient_name[])
{

    system("cls");
    Text_Color(14);
    printf("\n\n\t\t\t\tUsername : [%s]\n",patient_name);
    printf("\t\t\t\t==========\n\n");
    Text_Color(15);
    printf("\n\t\t\t\t\t[1] Search doctor\n");
    printf("\n\t\t\t\t\t[2] View profile\n");
    printf("\n\t\t\t\t\t[3] Edit profile\n");
    printf("\n\t\t\t\t\t[4] Add new medicine\n");
    printf("\n\t\t\t\t\t[5] Specialist Info!\n");
    printf("\n\t\t\t\t\t[6] Change password!\n");
    printf("\n\t\t\t\t\t[7] Main menu");

    Text_Color(6);
    printf("\n\n\t\t\t\t\t=> ");

    int choice;
    scanf("%d",&choice);
    Text_Color(10);
    if(choice==1)
    {

        search_doctor();
        after_patient_login(patient_name);
    }
    else if(choice==2)
    {
        view_patient_profile(patient_name);
        after_patient_login(patient_name);
    }
    else if(choice==3)
    {
        patient_edit_profile(patient_name);

        printf("\n\t\t\t\t\tPress any key to continue...");
        getch();

        after_patient_login(patient_name);

    }
    else if(choice==4)
    {
        add_medicine(patient_name);

        printf("\n\t\t\t\tPress any key to continue...");
        getch();

        after_patient_login(patient_name);

    }
    else if(choice==5)
    {
        show_specialist();

        after_patient_login(patient_name);

    }
    else if(choice==6)
    {
        change_password(patient_name,0);

        after_patient_login(patient_name);

    }

    else if(choice==7)
    {
        Main();
    }

    else
    {
        Text_Color(4);
        printf("\n\t\t\t\t\tWrong Input!\n");
        incl;
        Text_Color(10);
        printf("\n\t\t\t\t\tPress any key to continue...");
        getch();
        after_patient_login(patient_name);

    }

}





void Login(bool DorP)
{
    char name[80],doctorId[40], password[80],pwrd[80],Uaddr[100]="C:\\GetYourDoctor\\",FileUserAddr[100]="mkdir ";


    //For Doctor login
    if(DorP)
    {
        system("cls");
        Text_Color(14);
        printf("\n\n\n\t\t\t\t\t____Doctor Login___\n\n");
        Text_Color(15);

        printf("\n\n\t\t\t\tEnter your doctor ID : \t");
        incl;
        gets(doctorId);
        incl;
        printf("\n\n\t\t\t\tEnter your password  :\t");
        //gets(password);
        takepassword(password);
        incl;


        //Creating address
        strcat(Uaddr,"Doctor\\");
        strcat(Uaddr,doctorId);
        strcat(Uaddr,"\\password.txt");


        FILE *f;
        f=fopen(Uaddr,"r");

        //checking that, their is any registration with this Id or not
        if(f==NULL)
        {
            Text_Color(4);
            printf("\n\n\t\t\t\tNO record found for the Id [%s]",doctorId);
            Text_Color(6);
            printf("\n\n\t\t\t\t\tTry again!!\n\n",doctorId);

            Text_Color(7);
            printf("\n\n\t\t\t\tPress any key to continue...");
            getch();
        }
        else
        {
            char id[15], name[100],location[100];

            //getting the password from password.txt file
            fgets(pwrd,80,f);
            fclose(f);


            //Checking the password with password.txt file
            if(strcmp(password,pwrd))
            {
                Text_Color(4);
                printf("\n\n\n\t\t\t\t\tWrong Password!!");
                Text_Color(6);
                printf("\n\n\t\t\t\t\t   Try again...\n\n");
                Text_Color(7);
                printf("\n\n\t\t\t\tPress any key to continue...");
                getch();
            }
            else
            {
                Text_Color(6);
                printf("\n\n\n\t\t\t\t\tLogin Successfully!!\n\n");

                FILE *f;

                f=fopen("C:\\GetYourDoctor\\Doctor_id.txt","r");


                //taking the name from doctor_id.txt file to show at the welcome section
                while(!feof(f))
                {

                    fscanf(f,"%s %s %s",id,name,location);

                    if(strcmp(doctorId,id)==0)
                    {
                        Toupper(name);
                        Text_Color(14);
                        printf("\n\t\t\t\t   Welcome Dr. %s !!\n\n",name);
                        Text_Color(7);
                        break;
                    }
                }
                fclose(f);


                printf("\n\n\t\t\t\tPress any key to see the menu...");
                getch();


                //Calling the after_doctor_login() function after successfully login
                after_doctor_login(doctorId);

            }

        }

    }



    //Patient login

    else
    {
        system("cls");

        Text_Color(14);

        printf("\n\n\n\t\t\t\t\t____Patient Login___\n\n");
        Text_Color(15);
        printf("\n\n\t\t\t\tEnter your name     :\t");
        incl;
        gets(name);
        incl;
        printf("\n\n\t\t\t\tEnter your password :\t");
        //gets(password);
        takepassword(password);
        incl;

        strcat(Uaddr,"Patient\\");
        strcat(Uaddr,name);
        strcat(Uaddr,"\\password.txt");
        FILE *f;
        f=fopen(Uaddr,"r");

        //firstly checking the user name is correct or wrong
        if(f==NULL)
        {
            fclose(f);
            Text_Color(4);
            printf("\n\n\t\t\t\t\tWrong Username!!");
            Text_Color(6);
            printf("\n\n\t\t\t\t\t   Try again\n\n");
            Text_Color(7);
            printf("\n\n\t\t\t\tPress any key to continue...");
            getch();
            patient_main();
            //SignUp(0);
        }
        else
        {
            //taking the password from password file
            fgets(pwrd,80,f);
            fclose(f);


            //Double checking: checking the password
            if(strcmp(password,pwrd))
            {
                Text_Color(4);
                printf("\n\n\t\t\t\t\tWrong Password!!");
                Text_Color(6);
                printf("\n\n\t\t\t\t\t   Try again...\n\n");
                Text_Color(7);
                printf("\n\n\t\t\t\tPress any key to continue...");
                getch();

                //if the password does not match it will again show the option for login
                //Login(0);
                patient_main();
            }

            //here else means: password matched
            else
            {
                Toupper(name);
                Text_Color(6);
                printf("\n\n\t\t\t\t      Login Successfully!!\n\n");
                Text_Color(14);
                printf("\n\t\t\t\t\tWelcome %s!!!\n",name);
                Text_Color(7);

                printf("\n\n\t\t\t\tPress any key to see the menu...");
                getch();

                //after successfully login it will call the after_patient_login() functin.
                after_patient_login(name);


            }
        }
    }
}



void SignUp(bool DorP)
{
    char name[80],doctorId[40], password[80],Uaddr[100]="C:\\GetYourDoctor\\",FileUserAddr[100]="mkdir ";

    char checkdoctor[100]="C:\\GetYourDoctor\\Doctorlist\\",speciality[40];
    int ln,i;
    char phone_number[20],location[100],email[600],availability[30];


    //For Doctor signup
    if(DorP)
    {
        system("cls");
        Text_Color(14);
        printf("\n\n\t\t\t\t\t____Doctor Signup___\n\n");
        Text_Color(15);


        printf("\n\n\t\t\t\tEnter your doctor ID    :\t");
        incl;
        gets(doctorId);


        //checking that whether the Id is valid or not

        if(check_doc(doctorId)==false)
        {
            Text_Color(4);

            printf("\n\n\t\t\t\t    Your doctor ID [%s] is not valid\n",doctorId);
            Text_Color(7);
            printf("\n\n\t\t\t\tPress any key to continue...");
            getch();

            doctor_main();

        }

            FILE *f;

            strcat(Uaddr,"Doctor\\");
            strcat(Uaddr,doctorId);


            //making the personal profile address
            char personal_profile[100];
            cat(personal_profile,Uaddr);
            strcat(personal_profile,"\\Personal_profile.txt");

            strcat(Uaddr,"\\password.txt");


            f=fopen(Uaddr,"r");

            if(f!=NULL)
            {
                Text_Color(4);
                printf("\n\n\t\t\t\tAn account already created with this Id: (%s)",doctorId);
                Text_Color(6);
                printf("\n\n\n\t\t\t\tTry again with your own Id...\n",doctorId);
                Text_Color(7);


                printf("\n\n\t\t\t\tPress any key to continue...");
                getch();
                doctor_main();
            }
            fclose(f);


        incl;
        printf("\n\t\t\t\tEnter your specialities :\t");
        gets(speciality);

        int len=strlen(speciality);
        if(len<4)
        {
            Text_Color(4);
            printf("\n\n\t\t\t\t    Your entered speciality is too short\n");
            printf("\n\t\t\t\tPlease try again with the correct speciality\n\n");
            Text_Color(7);


            printf("\n\t\t\t\t\tPress any key to continue...");
            getch();

            doctor_main();
        }

        incl;
        printf("\n\t\t\t\tEnter your phone number :\t");
        gets(phone_number);
        incl;
        printf("\n\t\t\t\tEnter your location \t:\t");
        gets(location);
        incl;

        len=strlen(location);

        if(len==0)
        {
            Text_Color(4);
            printf("\n\n\n\t\t\t\t    You didnt insert any location\n");
            printf("\n\t\t\t\t    Try again with a valid location\n");
            Text_Color(7);

            printf("\n\n\t\t\t\tPress any key to continue...");
            getch();

            //SignUp(1);
            doctor_main();
        }
        else if(len<3)
        {
            Text_Color(4);
            printf("\n\n\n\t\t\t\t    Inserted location is too short\n");
            printf("\n\t\t\t\t    Try again with a valid location\n");
            Text_Color(7);

            printf("\n\n\t\t\t\tPress any key to continue...");
            getch();

            //SignUp(1);
            doctor_main();
        }

        printf("\n\t\t\t\tEnter your email address:\t");
        gets(email);
        incl;
        printf("\n\t\t\t\tEnter your availability :\t");
        gets(availability);

        incl;
        printf("\n\t\t\t\tEnter your password     :\t");
        //gets(password);
        takepassword(password);
        incl;

        len= strlen(password);

        if(len==0)
        {
            Text_Color(4);
            printf("\n\n\t\t\t\t    You didn't insert any password!\n\n\t\t\t\t\t    Try again!\n\n");
            Text_Color(7);

            printf("\n\t\t\t\tPress any key to continue...");
            getch();

            doctor_main();
        }

        Toupper(speciality);


        //check whether doctor ID is valid or not
        //If the check_doc() function returns false, it means that the doctor Id is not found in the doctor_id.txt file.
        if(check_doc(doctorId))
        {
            //FILE *f;

//            strcat(Uaddr,"Doctor\\");
//            strcat(Uaddr,doctorId);


            //making the personal profile address
//            char personal_profile[60];
//            cat(personal_profile,Uaddr);
//            strcat(personal_profile,"\\Personal_profile.txt");
//
//            strcat(Uaddr,"\\password.txt");


            f=fopen(Uaddr,"r");


            //If file!= NULL, it means that an account is already created with this Id
            if(f==NULL)
            {
                fclose(f);

                char namefromfile[50],idfromfile[20], locationfromfile[50];

                f=fopen("C:\\GetYourDoctor\\Doctor_id.txt","r");
                int flag=0;

                if(f==NULL) printf("\ndoctor_id.txt file not found. Doctor name cant be read\n");

                //finding the doctor name from Doctor_id.txt file
                while(!feof(f))
                {

                    fscanf(f,"%s %s %s",idfromfile,namefromfile,locationfromfile);

                    if(strcmp(doctorId,idfromfile)==0)
                    {
                        flag=1;
                        break;
                    }

                }
                fclose(f);

                if(flag==0)
                {
                    Text_Color(6);
                    printf("\nName not found for the Id (%s)\n",doctorId);
                    Text_Color(10);
                }




                //Loading info in doctor_bio structure
                cat(dobj.doctorname,namefromfile);
                cat(dobj.doctorid,doctorId);
                cat(dobj.speciality,speciality);
                cat(dobj.phonenumber,phone_number);
                cat(dobj.location,location);
                cat(dobj.email,email);
                cat(dobj.available,availability);


                //Creating folder with doctor Id
                strcat(FileUserAddr,"\"C:\\GetYourDoctor\\Doctor\\");
                strcat(FileUserAddr,doctorId);
                strcat(FileUserAddr,"\"");

                system(FileUserAddr);


                //writing structer in personal profile
                f=fopen(personal_profile,"w");
                fwrite(&dobj,sizeof(dobj),1,f);
                fclose(f);


                //Putting the password in password.txt file
                f=fopen(Uaddr,"w");
                fputs(password,f);
                fclose(f);


                //appending the speciality,doctor Id and location in speciality.txt file
                f=fopen("C:\\GetYourDoctor\\Doctor\\speciality.txt","a+");

                if(f==NULL)
                {
                    printf("\nSpeciality file not found\n");
                    fclose(f);
                }

                else
                {
                    Toupper(speciality);
                    Toupper(location);

                    fprintf(f,"%s %s %s\n",doctorId,speciality,location);

                }
                fclose(f);


                Text_Color(14);
                printf("\n\n\t\t\t\t\tSuccessfully Registered!\n");
                Text_Color(7);
                printf("\n\n\t\t\t\t\tPress any key to continue...");
                getch();

                //Calling the login function after completing the sign-up process
                Login(1);
            }

            else
            {
                fclose(f);

                Text_Color(4);
                printf("\n\n\t\t\t\tAn account already created with this Id: (%s)",doctorId);
                Text_Color(6);
                printf("\n\n\n\t\t\t\tTry again with your own Id...\n",doctorId);
                Text_Color(7);


                printf("\n\n\t\t\t\tPress any key to continue...");
                getch();
            }
        }


        //Doctor Id is not in the doctor.txt file
        else
        {

            Text_Color(4);

            printf("\n\n\t\t\t\t    Your doctor ID is not valid\n");
            Text_Color(7);
            printf("\n\n\t\t\t\tPress any key to continue...");
            getch();

            doctor_main();

        }

    }



    //For Patient signup
    else
    {
        char height[10], prev_medi[200],age[10],weight[10],bloodgroup[15],bp[10],bs[10];
        //int age,weight,bp,bs;

        system("cls");
        Text_Color(14);
        printf("\n\t\t\t\t\t____Patient Signup___\n");
        Text_Color(15);

        printf("\n\n\t\t\t\tEnter your name\t\t:\t");
        incl;
        gets(name);

        int len=strlen(name);
        char personal_profile[100];


        strcat(Uaddr,"Patient\\");
        strcat(Uaddr,name);

        cat(personal_profile,Uaddr);
        strcat(personal_profile,"\\");
        strcat(personal_profile,"personal_profile.txt");


        strcat(Uaddr,"\\password.txt");

        FILE *f;
        f=fopen(Uaddr,"r");

        if(f!=NULL)
        {
            Text_Color(4);
            printf("\n\n\t\t\t\t\t  User name already exist!\n\n\t\t\t\t\t   Try with another one...\n");
            Text_Color(7);
            printf("\n\n\t\t\t\tPress any key to continue...");
            getch();
            patient_main();
        }
        fclose(f);


        if(len<3 )
        {
            Text_Color(4);
            printf("\n\n\t\t\t\t   Your entered name is too short\n");
            printf("\n\n\t\t\t\tPlease try again with a useful name\n\n");
            Text_Color(7);


            printf("\n\n\t\t\t\tPress any key to continue...");
            getch();

            //SignUp(0);

            patient_main();
        }

        printf("\n\t\t\t\tEnter your age\t\t:\t");
        incl;
        gets(age);
        printf("\n\t\t\t\tEnter your weight\t:\t");
        incl;
        gets(weight);
        printf("\n\t\t\t\tEnter your height\t:\t");
        incl;
        gets(height);
        printf("\n\t\t\t\tEnter your blood group\t:\t");
        incl;
        gets(bloodgroup);
        printf("\n\t\t\t\tEnter your Blood pressure:\t");
        incl;
        gets(bp);
        printf("\n\t\t\t\tEnter your Blood sugar\t:\t");
        incl;
        gets(bs);
        printf("\n\t\t\t\tEnter Previous medicine\t:\t");
        incl;
        gets(prev_medi);
        incl;
        printf("\n\t\t\t\tEnter your password\t:\t");
        takepassword(password);
        //gets(password);
        incl;

        len= strlen(password);

        if(len==0)
        {
            Text_Color(4);
            printf("\n\n\t\t\t\t    You didn't insert any password!\n\n\t\t\t\t\tTry again!\n\n");
            Text_Color(7);

            printf("\n\t\t\t\t\tPress any key to continue...");
            getch();

            //SignUp(0);
            patient_main();
        }

//        char personal_profile[60];

//        strcat(Uaddr,"Patient\\");
//        strcat(Uaddr,name);

        //making address for patient personal profile
//        cat(personal_profile,Uaddr);
//        strcat(personal_profile,"\\");
//        strcat(personal_profile,"personal_profile.txt");



        //Loading the info in structure

        cat(pobj.name,name);
        cat(pobj.age,age);
        cat(pobj.weight,weight);
        cat(pobj.height,height);
        cat(pobj.bloodgrp,bloodgroup);
        cat(pobj.bp,bp);
        cat(pobj.bs,bs);
        cat(pobj.previous_med,prev_medi);


        //checking that the User name is already exist or not
        //strcat(Uaddr,"\\password.txt");
        //FILE *f;
        f=fopen(Uaddr,"r");

        if(f==NULL)
        {
            fclose(f);

            //creating folder for each patient
            strcat(FileUserAddr,"\"C:\\GetYourDoctor\\Patient\\");
            strcat(FileUserAddr,name);
            strcat(FileUserAddr,"\"");
            system(FileUserAddr);


            //writing the password in password.txt file
            f=fopen(Uaddr,"w");
            fputs(password,f);
            fclose(f);



            //writing info with a structer in personal profile
            //printf("\n%s sign up writing structure\n",personal_profile);
            f=fopen(personal_profile,"w");
            if(f==NULL) printf("\nFile not found!!  Can't save info in personal profile file\n");
            else
            {

                fwrite(&pobj,sizeof(pobj),1,f);

                Text_Color(6);
                printf("\n\n\t\t\t\t\tRegistration Successfull!\n");
                Text_Color(7);

            }
            fclose(f);

            printf("\n\n\t\t\t\tPress any key to continue...");
            getch();

            //calling the login function after completing the sign-up process
            Login(0);

        }
        else
        {
            Text_Color(4);
            printf("\n\n\t\t\t\t\t  User name already exist!\n\n\t\t\t\t\t   Try with another one...\n");
            Text_Color(7);
            printf("\n\n\t\t\t\tPress any key to continue...");
            getch();
            patient_main();
        }
    }
}




void show_specialist()
{
    FILE *f;

    f=fopen("C:\\GetYourDoctor\\specialist_info.txt","r");

    system("cls");
    Text_Color(14);


    printf("\n\n\t\t\t\t\t    Doctor Speciality Info!");
    //printf("\n\t\t\t\t\t-----------------------");
    printf("\n\t\t\t\t\t   -=======================-\n\n");

    Text_Color(15);

    while(!feof(f))
    {
        char str[201];
        if(f==NULL)
        {
            break;
        }

        fgets(str,200,f);

        printf("\t%s\n",str);


    }
    Text_Color(10);

    printf("\n\n\t\t\t\t\tPress any key to continue...");
    getch();


}







