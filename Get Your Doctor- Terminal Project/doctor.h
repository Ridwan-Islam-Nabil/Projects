void doctor_main();
void view_doctor_profile(char doctorId[]);

void doctor_main()
{
    int choice;
    while(1)
    {
        system("cls");
        Text_Color(14);
        printf("\n\n\t\t\t\t\t____Doctor's Service____\n");
        Text_Color(15);

        printf("\n\n\t\t\t\t\t[1] Login\n");
        printf("\t\t\t\t\t[2] Signup\n");
        printf("\t\t\t\t\t[3] Main menu");
        Text_Color(6);
        printf("\n\n\t\t\t\t\t=> ");
        scanf("%d",&choice);
        Text_Color(10);

        if(choice==1)
        {
            Login(1);
            //break;
        }
        else if(choice==2)
        {
            SignUp(1);
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
            Text_Color(7 );
            printf("\n\n\t\t\t\t\tPress any key to continue..."); getch();
        }

    }
}


void view_doctor_profile(char doctorId[])
{
    char personal_profile[100], Uaddress[60]= {"C:\\GetYourDoctor\\Doctor\\"};

    strcat(Uaddress,doctorId);
    strcat(Uaddress,"\\Personal_profile.txt");

    FILE *f;

    //printf("%s\n",Uaddress);

    f=fopen(Uaddress,"r");
    fread(&dobj,sizeof(dobj),1,f);
    fclose(f);

    system("cls");
    Text_Color(14);
    printf("\n\n\t\t\t\t\t___Your Profile___\n\n");
    Text_Color(15);
    printf("\n\t\t\t\tName\t\t:\tDr.%s\n",dobj.doctorname);
    printf("\n\t\t\t\tDoctor Id\t:\t%s\n",dobj.doctorid);
    printf("\n\t\t\t\tSpecialist in\t:\t%s\n",dobj.speciality);
    printf("\n\t\t\t\tContact no\t:\t%s\n",dobj.phonenumber);
    printf("\n\t\t\t\tAddress\t\t:\t%s\n",dobj.location);
    printf("\n\t\t\t\tEmail\t\t:\t%s\n",dobj.email);
    printf("\n\t\t\t\tActive hours\t:\t%s\n",dobj.available);
    Text_Color(7);
    printf("\n\n\n\t\t\t\tPress any key to continue...");
    getch();


}
