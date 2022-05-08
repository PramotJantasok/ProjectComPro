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
int count_list(){
    char str[200];
    int member = 0;
    FILE *mem = fopen("list.dat", "r+");
    while ((fgets(str, 200, mem)) != NULL) {
        member++;
    }
    return member;
}
int main_exit;
void menu();
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

char day[20];
char officer_name[50];
int officer_id;
char l_name[50];

struct member_list{
    float diposit;
    float Withdraw;
};
void list(int acc, float get, int t);
void search_list();
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

void menu();
void look();

int main()
{
    printf("\n\n\n\n\n\t\t\t\t\t Loading ");
    for (i = 0; i < 7; i ++){
        delay(100000000);
        printf(".");
    }
    system("cls");
    printf("\n\n\t\t\t Enter officer ID :");
    scanf("%d", &officer_id);
    printf("\n\n\t\t\t Enter officer Name :");
    scanf("%s", officer_name);
    printf("\n\n\t\t\t TO Day :");
    scanf("%s", day);
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
    }else if (choice == 6){
        system("cls");
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
    printf("\n\t\t\tType of account:\n");
    printf("\t\t\t#Saving\n");
    printf("\t\t\t#Current\n");
    printf("\t\t\tEnter your choice:");
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
    char conf[5];
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
            {
                char con_addr[5];
                char old_add[50];
                strcpy(old_add, add.address);
                printf("\n\n\t\t\tEnter the new address:");
                scanf("%s",upd.address);
                printf("\n\t\t Account number %d Old email: %s change the Email to %s\n", add.acc_no, old_add,upd.address);
                printf("\n\t\t Confirm the correction, please check the information [yes/no]:");
                scanf("%s", con_addr);
                if (strcmp(con_addr, "yes") == 0){
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
                    fclose(old);
                    fclose(newrec);
                    remove("record.dat");
                    rename("new.dat","record.dat");
                }else{
                    break;
                }

            }
            else if(choice==2)

            {   int old_phone = add.phone;
                char con_ph[5];

                printf("\n\n\t\t\tEnter the new phone number:");
                scanf("%d",&upd.phone);

                printf("\n\t\t Account number %d Old phone: %d change the Phone to %d\n", add.acc_no, old_phone,upd.phone);
                printf("\n\t\t Confirm the correction, please check the information [yes/no]:");
                scanf("%s", con_ph);

                if (strcmp(con_ph, "yes") == 0){
                    fprintf(newrec,"%d %s %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",add.acc_no,
                            add.name,add.lastname,add.dob.month,add.dob.day,
                            add.dob.year,add.age,add.address,upd.phone,
                            add.acc_type,add.amt,add.deposit.month,
                            add.deposit.day,add.deposit.year);
                    system("cls");
                    printf("\n\t\tChanges saved!");
                    fclose(old);
                    fclose(newrec);
                    remove("record.dat");
                    rename("new.dat","record.dat");
                }else{
                    break;
                }

            } else if (choice == 3){
                char old_name[50];
                strcpy(old_name, add.name);
                printf("\n\n\t\t\tEnter the new Name:");
                scanf("%s",upd.name);
                printf("\n\t\t Account number %d Name: %s change the name to %s\n", add.acc_no, old_name,upd.name);
                printf("\n\t\t Confirm the correction, please check the information [yes/no]:");
                scanf("%s", conf);
                if (strcmp(conf, "yes") == 0){
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
                    fclose(old);
                    fclose(newrec);
                    remove("record.dat");
                    rename("new.dat","record.dat");
                } else{
                    break;
                }

            }else if (choice == 4){
                char con_last[5];
                char old_lastname[50];
                strcpy(old_lastname, add.lastname);
                printf("\n\n\t\t\tEnter the new Lastname:");
                scanf("%s",upd.lastname);

                printf("\n\t\t Account number %d Last name: %s change the Last name to %s\n", add.acc_no, old_lastname,upd.lastname);
                printf("\n\t\t Confirm the correction, please check the information [yes/no]:");
                scanf("%s", con_last);
                if (strcmp(con_last, "yes") == 0){
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
                    fclose(old);
                    fclose(newrec);
                    remove("record.dat");
                    rename("new.dat","record.dat");
                }

            }else{
                break;
            }


        }
        else
            fprintf(newrec,"%d %s %s %d/%d/%d %d %s %d %s %f %d/%d/%d\n",add.acc_no,add.name,
                    add.lastname,add.dob.month,add.dob.day,
                    add.dob.year,add.age,add.address,add.phone,
                    add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
    }


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
        if (main_exit==0)
            edit_infor();
        else
            menu();
    }
}
void transact(){   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    char con_t[5];
    printf("\n\n\t\t\tEnter the account no. of the customer:");
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
        {
            float old_m = add.amt;

            test=1;
            printf("\n\t\tAccount number :%d Name: %s money in the account now %f", add.acc_no, add.name, old_m);
            printf("\n\n\t\t\tDo you want to ?\n\n\t\t\t1.Deposit\n\t\t\t2.Withdraw?\n\n\t\t\tEnter your choice:");
            scanf("%d",&choice);
            if (choice==1)
            {

                system("cls");
                printf("\n\n\t\t\tEnter the amount you want to deposit:$ ");
                scanf("%f",&transaction.amt);

                printf("\n\t\t\t Name: %s money in the account now %f\n", add.name, old_m);
                printf("\t\t\t You want to deposit :$ %f ?\n", transaction.amt);
                printf("\t\t\t Confirm the amount you want to deposit [yes/no]");
                scanf("%s", con_t);

                float save_list = transaction.amt;
                strcpy(l_name,add.name);
                int l_acc = add.acc_no;
                int t = 1;
                list(l_acc, save_list, t);
                if (strcmp(con_t , "yes") == 0){
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
                    printf("\n\n\t\t\tDeposited successfully!\n");
                    printf("\n\t\t\t Name: %s money in the account now :$ %f\n", add.name, add.amt);
                }else{
                    break;
                }

            }
            else
            {
                system("cls");
                printf("\n\n\t\t\tEnter the amount you want to withdraw:$ ");
                scanf("%f",&transaction.amt);
                printf("\n\t\t\t Name: %s money in the account now %f\n", add.name, old_m);
                printf("\t\t\t You want to withdraw :$ %f ?\n", transaction.amt);
                printf("\t\t\t Confirm the amount you want withdraw [yes/no]:");
                scanf("%s", con_t);

                float save_list = transaction.amt;
                strcpy(l_name,add.name);
                int l_acc = add.acc_no;
                int t = 1;
                list(l_acc, save_list, t);
                if (strcmp(con_t , "yes") == 0){
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
                    printf("\n\n\t\t\t Withdrawn successfully!\n");
                    printf("\n\t\t\t Name: %s money in the account now :$ %f\n", add.name, add.amt);
                }else{
                    break;
                }

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
        printf("\n\n\n\t\t\tEnter 1 to try again, Enter 0 to main menu :");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1){
            transact();
        }
        else{
            menu();
        }

    }
    else
    {
        printf("\n\t\t\tEnter 1 to transaction again Enter 0 to main menu :");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1){
            transact();
        }

        else{
            menu();
        }

    }

}
void remove_account(){

    FILE *old,*newrec;
    int test=0;
    char con[5];
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("\n\n\n\t\t\tEnter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    int old_acc = rem.acc_no;
    printf("\n\n\t\t\tConfirm and delete the account %d ? [yes/no] :" ,old_acc);
    scanf("%s", con);

    if (strcmp(con, "yes")==0){
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
            printf("\n\t\t\tRecord not found!!\a\a\a");
            erase_invalid:
            printf("\n\t\t\tEnter 0 to try again,1 to return to main menu :");
            scanf("%d",&main_exit);

            if (main_exit==1){
                menu();
            }
            else if(main_exit==0){
                remove_account();
            }
        }
        else
        {printf("\n\t\t\tEnter 0 to remove again ,Enter 1 to main menu :");
            scanf("%d",&main_exit);
            system("cls");
            if (main_exit==1){
                menu();
            }
            else
                remove_account();}
    } else{
        menu();
    }

}
void list(int acc, float get, int t){
    FILE * save;
    int b;
    save = fopen("list.dat", "a+");
    if (t == 0){
        fprintf(save ,"%d %s Diposit %f $ ,Officer :%d %s %s\n", acc, l_name, get,officer_id,officer_name,day); // acc name money  officer id name day
    }else {
        fprintf(save ,"%d %s Withdraw %f $ ,Officer :%d %s %s\n", acc, l_name, get,officer_id,officer_name,day); // acc name money  officer id name day
    }

    fclose(save);
}
void search_list(){
    int n = count_list();
    FILE  *mem = fopen("list.dat", "r+");
    int line = 0;
    char str[150];
    char buffer[n][150];
    while ((fgets(str, 150, mem)) != NULL){
        strcpy(buffer[line], str);
        line++;
    }
    fclose(mem);
    int s_list;
    printf("\n\n\t\t\t Search customer list\n");
    printf("\n\t\t\t1. Search all list\n");
    printf("\t\t\t2. Search list by account number\n");
    printf("\t\t\t3. Search list by name\n");
    printf("\n\t\t\tEnter option search :");
    scanf("%d", &s_list);
    system("cls");

    if (s_list == 1){
        int op;
        printf("\n\n\t\t\t_______________________________________________________________________\n");
        printf("\t\t\tSort order: account/name/transaction/amount/officer id/officer name/day\n");
        printf("\t\t\t-----------------------------------------------------------------------\n");
        for (i = 0; i < n; i++){
            printf("\n\t\t\t| %d. |%s\n",i+1, buffer[i]);
        }
        printf("\n\t\t\t Enter 0 to Search list menu , Enter 1 to Search menu 1:");
        scanf("%d", &op);
        if (op == 0){
            system("cls");
            search_list();
        }else{
            system("cls");
            look();
        }

    }
    else if (s_list == 2){
        char id[20];
        char get_id[20];
        int point = -1;
        int op ;
        printf("\n\n\t\t\tEnter customer's account number:");
        scanf("%s", id);
        printf("\n\t\t\t_______________________________________________________________________\n");
        printf("\t\t\tSort order: account/name/transaction/amount/officer id/officer name/day\n");
        printf("\t\t\t-----------------------------------------------------------------------\n");
        for (i=0; i < n; i++){

            for (j = 0; j < strlen(buffer[i]); j++){
                if (buffer[i][j] != ' '){
                    get_id[j] = buffer[i][j];
                } else{break;}
            }
            if (strcmp(id, get_id) == 0){
                point = i;
                break;
            }
        }
        if (point != -1){

            printf("\n\t\t\t| 1. |%s\n", buffer[point]);
        }else{
            printf("\n\t\t\t! Account number %s Not found\n", id);
        }
        printf("\n\t\t\t Enter 0 to Search list menu , Enter 1 to Search menu 1:");
        scanf("%d", &op);
        if (op == 0){
            system("cls");
            search_list();
        }else{
            system("cls");
            look();
        }
    }

    else if (s_list == 3){
        char search_name[50];
        int len = strlen(search_name);
        char get_name[len];
        int num = 0;
        int op;
        printf("\n\n\t\t\tEnter customer's Name:");
        scanf("%s", search_name);
        printf("\n\n\t\t\t_______________________________________________________________________\n");
        printf("\t\t\tSort order: account/name/transaction/amount/officer id/officer name/day\n");
        printf("\t\t\t-----------------------------------------------------------------------\n");
        for (i = 0; i < n; i++){
            int c = 0;
            int unlock = 0;
            for (j = 0; j < strlen(buffer[i]) ; j ++){
                if (buffer[i][j] == ' ' && unlock == 0){
                    unlock = 1;
                    j++;
                }
                if (unlock == 1 && buffer[i][j] != ' '){
                    get_name[c] = buffer[i][j];
                    c++;
                }else if (unlock == 1 && buffer[i][j] == ' '){
                    unlock = 2;
                }

            }
            if (strcmp(search_name, get_name) == 0){
                num++;
                printf("\n\t\t\t| %d. |%s\n", num,buffer[i]);
            }
        }
        if (num == 0){
            printf("\n\t\t\t! Account number %s Not found\n", search_name);
        }
        printf("\n\t\t\t Enter 0 to Search list menu , Enter 1 to Search menu 1:");
        scanf("%d", &op);
        if (op == 0){
            system("cls");
            search_list();
        }else{
            system("cls");
            look();
        }
    }
    else{
        search_list();
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
    printf("\t\t\t1. Search all customer information\n\t\t\t2. Search by account number\n\t\t\t3. Search by name\n\t\t\t4. Search list\n\t\t\t5. back to menu");
    printf("\n\t\t\tEnter option search :");
    scanf("%d", &option);
    system("cls");
    if (option == 1){
        printf("\n\n\n\t____________________________________________________________________________________________________\n");
        printf("\tSort order: account/name/lastname/birthday/age/Email/phone/type/account/money/account opening date\n");
        printf("\t----------------------------------------------------------------------------------------------------\n");
        for (i = 0; i < n;i++){
            printf("\t\t| %d. |%s\n",i+1, buffer[i]);
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
            printf("\t----------------------------------------------------------------------------------------------------\n");
            printf("\t\t| 1. |%s", buffer[account_point]);
        }else{
            int ask;
            printf("\n\n\n\t____________________________________________________________________________________________________\n");
            printf("\tSort order: account/name/lastname/birthday/age/Email/phone/type/account/money/account opening date\n");
            printf("\t----------------------------------------------------------------------------------------------------\n");
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
        printf("\t----------------------------------------------------------------------------------------------------\n");
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
                printf("\t\t| %d. |%s\n", name_point, buffer[i]);
            }
            l=0;
        }

        if (name_point ==0){
            printf("\n\t\t\t! Account name %s not found account name", name_check);
        }
    }
    else if ( option == 4){
        search_list();
    }


    printf("\n\n\t\t\t Enter 1 to Search menu Enter 0 to main menu :");
    scanf("%d", &option);
    if (option == 1){
        system("cls");
        look();
    }else{system("cls");menu();}


}


