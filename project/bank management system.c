#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

int i,j;
int count_member(){
    char str[200];
    int member = 0;
    FILE *mem = fopen("record.dat", "r+");
    while ((fgets(str, 200, mem)) != NULL) {
        member++;
    }
    return member;
}
int main_exit;
void menu();
int atm();
void close();
struct date{
    int month,day,year;

};
struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char lastname[50];
    int phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

}add,upd,check,rem,transaction;



void delay(int j)
{   int i,k;
    for(i=0;i<j;i++)
        k=i;
}
void new_account();
void search_all();

void edit_infor();
void transact();
void remove_account();
void close(void)
{
    printf("\n\n\n\nBrought To You by code-projects.org");
}
void menu();
void look();

int main()
{
    printf("\n\n\n\n\n\t\t\t\t\t Loading ");
    for (i = 0; i < 7; i ++){
        delay(70000000);
        printf(".");
    }
    system("cls");
    menu();
    return 0;
}   // main

// ----------------------- function
void menu(){
    int choice;
    system("cls");
    system("color 7");
    printf("\n\t\t\t\t   Bank Management System \n");
    printf("\n\n\t\t\t WELCOME TO THE MAIN MENU \n");
    printf("\t\t\t1.) Create a new account\n");
    printf("\t\t\t2.) Update customer information\n");
    printf("\t\t\t3.) Search customer information\n");
    printf("\t\t\t4.) Remove existing account\n");
    printf("\t\t\t5.) Transactions\n");
    printf("\t\t\t6.) close Program\n");
    printf("\t\t\tEnter option number:");
    scanf("%d",&choice);

    if (choice == 1){
        system("cls");
        new_account();
    } else if (choice == 2){
        system("cls");
        edit_infor();
    } else if (choice == 3){
        system("cls");
        look();
    } else if (choice == 4){
        system("cls");
        remove_account();
    } else if (choice == 5){
        system("cls");
        transact();
    }else{
    	menu();
	}
}
void new_account(){
    int choice;
    char confirm[5];
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    printf("\n\t\t\t\t----  ADD RECORD  ----");
    printf("\n\n\t\t\tEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\n\t\t\tEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",
                 &add.acc_no,
                 add.name,
                 add.lastname,
                 &add.dob.month,
                 &add.dob.day,
                 &add.dob.year,
                 &add.age,
                 add.address,
                 &add.phone,
                 add.acc_type,
                 &add.amt,
                 &add.deposit.month,
                 &add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no==add.acc_no)
        {printf("Account no. already in use!");
            delay(1000000000);
            goto account_no;

        }
    }
    add.acc_no=check.acc_no;
    printf("\n\t\t\tEnter the name:");
    scanf("%s#",add.name);
    printf("\n\t\t\tEnter the Lastname:");
    scanf("%s",add.lastname);
    printf("\n\t\t\tEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\n\t\t\tEnter the age:");
    scanf("%d",&add.age);
    printf("\n\t\t\tEnter the Email-address:");
    scanf("%s",add.address);
    printf("\n\t\t\tEnter the phone number: ");
    scanf("%d",&add.phone);
    printf("\n\t\t\tEnter the amount to deposit:$");
    scanf("%f",&add.amt);
    printf("\n\t\t\tType of account:\n\t\t\t#Saving\n\t\t\t\t#Current\n\t\t\tEnter your choice:");
    scanf("%s",add.acc_type);

    printf("\n\n\t\t\tConfirm adding customer information [yes/no] :") ;
    scanf("%s", confirm);
    if (strcmp(confirm,"yes") == 0 || strcmp(confirm,"YES") == 0 || strcmp(confirm,"Yes") == 0){
        fprintf(ptr,"%d %s %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",add.acc_no,add.name,
                add.lastname,
                add.dob.month,
                add.dob.day,
                add.dob.year,
                add.age,
                add.address,
                add.phone,
                add.acc_type,
                add.amt,
                add.deposit.month,
                add.deposit.day,
                add.deposit.year);
        fclose(ptr);
    } else{
        printf("\n\n\n\t\tEnter 1 add new account \n\t\tEnter 0 Back to menu :");
        scanf("%d", &main_exit);
        if (main_exit == 1){
            system("cls");
            new_account();
        } else{
            system("cls");
            menu();
        }
    }

    printf("\nAccount created successfully!");
    printf("\n\n\n\t\tEnter 1 add new account \n\t\tEnter 0 Back to menu :");
    scanf("%d", &main_exit);
    if (main_exit == 1){
        system("cls");
        new_account();
    } else{
        system("cls");
        menu();
    }
}
void edit_infor(){
    int choice,test=0;
    char b_name[50];
    char b_lastname[50];
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\n\n\t\tEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %s %d/%d/%d %d %s %d %s %f %d/%d/%d",&add.acc_no,
                 add.name,add.lastname,&add.dob.month,&add.dob.day,&add.dob.year,
                 &add.age,add.address,&add.phone,add.acc_type,&add.amt,
                 &add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\n\t\t\tName: %s  Lastname: %s",b_name,b_lastname);
            printf("\n\t\t\tWhich information do you want to change?\n\t\t\t1.Address\n\t\t\t2.Phone\n\t\t\t3.Name\n\t\t\t4.Lastname\n\t\t\tEnter your choice :");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
            {printf("\t\t\tEnter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",add.acc_no,
                        add.name,add.lastname,
                        add.dob.month,add.dob.day,
                        add.dob.year,add.age,
                        upd.address,add.phone,
                        add.acc_type,add.amt,
                        add.deposit.month,add.deposit.day,
                        add.deposit.year);
                system("cls");
                printf("\n\t\tChanges saved!");
            }
            else if(choice==2)
            {
                printf("\t\t\tEnter the new phone number:");
                scanf("%d",&upd.phone);

                fprintf(newrec,"%d %s %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",add.acc_no,
                        add.name,add.lastname,add.dob.month,add.dob.day,
                        add.dob.year,add.age,add.address,upd.phone,
                        add.acc_type,add.amt,add.deposit.month,
                        add.deposit.day,add.deposit.year);
                system("cls");
                printf("\n\t\tChanges saved!");
            } else if (choice == 3){
                printf("\t\t\tEnter the new Name:");
                scanf("%s",upd.name);
                fprintf(newrec,"%d %s %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",add.acc_no,
                        upd.name,add.lastname,
                        add.dob.month,add.dob.day,
                        add.dob.year,add.age,
                        add.address,add.phone,
                        add.acc_type,add.amt,
                        add.deposit.month,add.deposit.day,
                        add.deposit.year);
                system("cls");
                printf("\n\t\tChanges saved!");
            }else if (choice == 4){
                printf("\t\t\tEnter the new Lastname:");
                scanf("%s",upd.lastname);
                fprintf(newrec,"%d %s %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",add.acc_no,
                        add.name,upd.lastname,
                        add.dob.month,add.dob.day,
                        add.dob.year,add.age,
                        add.address,add.phone,
                        add.acc_type,add.amt,
                        add.deposit.month,add.deposit.day,
                        add.deposit.year);
                system("cls");
                printf("\n\t\tChanges saved!");
            }

        }
        else
            fprintf(newrec,"%d %s %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",add.acc_no,add.name,
                    add.lastname,add.dob.month,add.dob.day,
                    add.dob.year,add.age,add.address,add.phone,
                    add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

    if(test!=1)
    {   system("cls");
        printf("\n\n\t\t\tRecord not found!!\a\a\a");
        edit_invalid:
        printf("\n\t\t\tEnter 0 to try again,\n\t\t\tEnter 1 to return to menu :");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            edit_infor();
    }
    else
    {printf("\n\t\t\tEnter 0 to edit again,\n\t\t\tEnter 1 to return to menu :");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            edit_infor();
        else
            menu();
    }
}
void transact(){   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %s %d/%d/%d %d %s %d %s %f %d/%d/%d",
                  &add.acc_no,
                  add.name,
                  add.lastname,
                  &add.dob.month,
                  &add.dob.day,
                  &add.dob.year,
                  &add.age,
                  add.address,
                  &add.phone,
                  add.acc_type,
                  &add.amt,
                  &add.deposit.month,
                  &add.deposit.day,
                  &add.deposit.year)!=EOF)
    {
        if(add.acc_no==transaction.acc_no)
        {   test=1;
            if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
            {
                printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                delay(1000000000);
                system("cls");
                menu();

            }
            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
            scanf("%d",&choice);
            if (choice==1)
            {
                printf("Enter the amount you want to deposit:$ ");
                scanf("%f",&transaction.amt);
                add.amt+=transaction.amt;
                fprintf(newrec,"%d %s %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",add.acc_no,
                        add.name,
                        add.lastname,
                        add.dob.month,
                        add.dob.day,
                        add.dob.year,
                        add.age,
                        add.address,
                        add.phone,
                        add.acc_type,
                        add.amt,
                        add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\n\nDeposited successfully!");
            }
            else
            {
                printf("Enter the amount you want to withdraw:$ ");
                scanf("%f",&transaction.amt);
                add.amt-=transaction.amt;
                fprintf(newrec,"%d %s %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",add.acc_no,
                        add.name,
                        add.lastname,
                        add.dob.month,
                        add.dob.day,
                        add.dob.year,
                        add.age,
                        add.address,
                        add.phone,
                        add.acc_type,
                        add.amt,
                        add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\n\nWithdrawn successfully!");
            }

        }
        else
        {
            fprintf(newrec,"%d %s %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",add.acc_no,
                    add.name,
                    add.lastname,
                    add.dob.month,
                    add.dob.day,
                    add.dob.year,
                    add.age,
                    add.address,
                    add.phone,
                    add.acc_type,
                    add.amt,
                    add.deposit.month,add.deposit.day,add.deposit.year);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test!=1)
    {
        printf("\n\nRecord not found!!");
        transact_invalid:
        printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==0)
            transact();
        else if (main_exit==1)
            menu();
        else if (main_exit==2)
            close();
        else
        {
            printf("\nInvalid!");
            goto transact_invalid;
        }

    }
    else
    {
        printf("\nEnter 1 to transaction again Enter 0 to main menu:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            transact();
        else
            menu();
    }

}
void remove_account(){
    {
        FILE *old,*newrec;
        int test=0;
        old=fopen("record.dat","r");
        newrec=fopen("new.dat","w");
        printf("Enter the account no. of the customer you want to delete:");
        scanf("%d",&rem.acc_no);
        while (fscanf(old,"%d %s %s %d/%d/%d %d %s %d %s %f %d/%d/%d",&add.acc_no,
                      add.name,
                      add.lastname,
                      &add.dob.month,
                      &add.dob.day,
                      &add.dob.year,
                      &add.age,
                      add.address,
                      &add.phone,
                      add.acc_type,&add.amt,
                      &add.deposit.month,
                      &add.deposit.day,
                      &add.deposit.year)!=EOF)
        {
            if(add.acc_no!=rem.acc_no)
                fprintf(newrec,"%d %s %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",
                        add.acc_no,
                        add.name,
                        add.lastname,
                        add.dob.month,
                        add.dob.day,
                        add.dob.year,
                        add.age,
                        add.address,
                        add.phone,
                        add.acc_type,
                        add.amt,
                        add.deposit.month,
                        add.deposit.day,
                        add.deposit.year);
            else
            {test++;
                printf("\nRecord deleted successfully!\n");
            }
        }
        fclose(old);
        fclose(newrec);
        remove("record.dat");
        rename("new.dat","record.dat");
        if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
            printf("\nEnter 0 to try again,1 to return to main menu :");
            scanf("%d",&main_exit);

            if (main_exit==1)
                menu();

            else if(main_exit==0)
                remove_account();
        }
        else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&main_exit);
            system("cls");
            if (main_exit==1)
                menu();
            else
                close();
        }

    }
}

void  look() {
    FILE *see;
    int n = count_member();
    see = fopen("record.dat", "r+");
    int line = 0;
    int option;
    char buffer[n][200];
    char str[200];
    printf("\n\n");
    while ((fgets(str, 200, see)) != NULL) {
        strcpy(buffer[line], str);
        line++;
    }
    fclose(see);


    printf("\n\n\t\t\t Search customers information\n");
    printf("\t\t\t1. Search all customer information\n\t\t\t2. Search by account number\n\t\t\t3.Search by name \n\t\t\t4. back to menu");
    printf("\n\t\t\tEnter option search :");
    scanf("%d", &option);
    system("cls");
    if (option == 1){
    	printf("\n\n\n\n\t\t\t\t Loading all customer information ");
    	for (i = 0; i < n; i++){
    		if (i <= 5){
    			printf(". ");
			}
    		delay(40000000);
		}
		system("cls");
        printf("\n\n\n\t____________________________________________________________________________________________________\n");
        printf("\tSort order: account/name/lastname/birthday/age/Email/phone/type/account/money/account opening date\n");
        printf("\t----------------------------------------------------------------------------------------------------\n\n");
        for (i = 0; i < n;i++){
            printf("\t\t|%s\n", buffer[i]);
        }
    }else if (option == 2){
        char id[15];

        system("cls");
        printf("\n\n\t\t\tEnter customer account number : ");
        scanf("%s", id);
        int account_point = -1;
        for (i = 0; i < n; i++){
            char get_in[15];
            for (j = 0; j < 20; j++){
                if (buffer[i][j] == ' '){
                    break;
                }
                get_in[j] = buffer[i][j];
            }
            if (strcmp(id, get_in) == 0){
                account_point = i;
            }
        }
        if (account_point != -1){
        printf("\n\n\n\t____________________________________________________________________________________________________\n");
        printf("\tSort order: account/name/lastname/birthday/age/Email/phone/type/account/money/account opening date\n");
        printf("\t----------------------------------------------------------------------------------------------------\n\n");
            printf("\t\t|%s", buffer[account_point]);
        }else{
            int ask;
        printf("\n\n\n\t____________________________________________________________________________________________________\n");
        printf("\tSort order: account/name/lastname/birthday/age/Email/phone/type/account/money/account opening date\n");
        printf("\t----------------------------------------------------------------------------------------------------\n\n");
            printf("\n\t\t\t! Account number %s not found account number", id);
        }
    }else if (option == 3){
        char name_check[50];
        int name_point = 0;
        system("cls");
        printf("\n\n\t\t\tEnter customer's name : ");
        scanf("%s", name_check);
        printf("\n\n\n\t____________________________________________________________________________________________________\n");
        printf("\tSort order: account/name/lastname/birthday/age/Email/phone/type/account/money/account opening date\n");
        printf("\t----------------------------------------------------------------------------------------------------\n\n");
        int unlock_2 = 0;
        char get_name[50];
        for (i = 0; i < n; i++){
            int c = 0,m,l=0;
            for (j = 0; j < strlen(buffer[i]); j++){
                c++;
                if (buffer[i][j] == ' '){
                    break;}
            }
            for (m = c; m < strlen(buffer[i]); m++){
                if (buffer[i][m] == ' '){
                    break;
                }
                get_name[l] = buffer[i][m];
                l++;
            }
            if (strcmp(name_check, get_name) == 0){
            	name_point++;
                printf("\t\t|%s\n", buffer[i]);
            }
            l=0;
        }
        if (name_point ==0){
        	printf("\n\t\t\t! Account name %s not found account name", name_check);
		}
    }


    printf("\n\n\t\t\t Enter 1 to Search menu Enter 0 to main menu :");
    scanf("%d", &option);
    if (option == 1){
        system("cls");
        look();
    }else{system("cls");menu();}


}


