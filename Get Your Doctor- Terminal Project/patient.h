void patient_main();
void view_patient_profile(char patient_name[]);

void patient_main()
{
    int choice;
    while(1)
    {
        system("cls");

        //system("COLOR 0F");
        Text_Color(14);
        printf("\n\n\t\t\t\t\t____Patient Service____\n");
        Text_Color(15);


        printf("\n\n\t\t\t\t\t[1] Login\n");
        printf("\t\t\t\t\t[2] Signup\n");
         printf("\t\t\t\t\t[3] Main menu");
        Text_Color(6);
        printf("\n\n\t\t\t\t\t=> ");
        scanf("%d",&choice);
        Text_Color(15);

        if(choice==1)
        {
            Login(0);
            //break;
        }
        else if(choice==2)
        {
            SignUp(0);
            //break;
        }
        else if(choice==3)
        {
            Main();
            //break;
        }

        else
        {
            Text_Color(4);
            printf("\n\t\t\t\t\tWrong Input!!\n");
            incl;
            Text_Color(7);
            printf("\n\n\t\t\t\t\tPress any key to continue..."); getch();
        }
    }

}



void view_patient_profile(char patient_name[])
{
    char Uaddress[60]= {"C:\\GetYourDoctor\\Patient\\"};

    strcat(Uaddress,patient_name);
    strcat(Uaddress,"\\Personal_profile.txt");

    FILE *f;

    f=fopen(Uaddress,"r");
    fread(&pobj,sizeof(pobj),1,f);
    fclose(f);


    system("cls");
    Text_Color(14);
    printf("\n\n\t\t\t\t\t___Your Profile___\n\n");
    Text_Color(15);
    printf("\n\n\t\t\t\tName\t\t:\t%s\n",pobj.name);
    printf("\n\t\t\t\tAge\t\t:\t%s\n",pobj.age);
    printf("\n\t\t\t\tHeight\t\t:\t%s\n",pobj.height);
    printf("\n\t\t\t\tWeight\t\t:\t%s\n",pobj.weight);
    printf("\n\t\t\t\tBlood Group\t:\t%s\n",pobj.bloodgrp);
    printf("\n\t\t\t\tBlood Pressure\t:\t%s\n",pobj.bp);
    printf("\n\t\t\t\tBlood sugar\t:\t%s\n",pobj.bs);
    printf("\n\t\t\t\tPrevious Medicines:\t%s\n",pobj.previous_med);
    Text_Color(7);
     printf("\n\n\n\t\t\t\tPress any key to continue...");
    getch();


}



