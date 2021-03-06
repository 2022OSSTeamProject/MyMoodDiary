#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"

int AccountMenu()
{
    int menu;
    printf("\n*** Login Page ***\n");
    printf("1. Login\n");
    printf("2. Sign up\n");
    printf("=> What do you want? ");
    scanf("%d", &menu);
    //getchar();
    return menu;
}

int LoadAccount(struct Account* a[])
{
    FILE * fp;
    int i = 0;
    if(fp = fopen("account.txt", "r"))
    {
        while (!feof(fp)){
            int t_num;     //temporary variable for reading from file
            char t_name[15];
            char t_pwd[15];
            int t = fscanf(fp,"%s %s", t_name, t_pwd);
            if (t <= 0) break;
            a[i] = (struct Account*) malloc(sizeof(struct Account));
            strcpy(a[i]->user_name, t_name);
            strcpy(a[i]->user_pwd, t_pwd);
            i++;
        }
        printf("=> Loading Success\n");
        fclose(fp);
    }
    else
    {
        FILE * fp;
        printf("\n=> File doesn't exist.\n New file created\n Please sign-up!!\n");
        fp = fopen("account.txt", "w");
        fprintf(fp,"NULL 0000\n");         //fake value for creating new file
        fclose(fp);
        int tmp = LoadAccount(a);
    }
    
    return i;
}

int Login(struct Account* a[], char n[15], char pw[15], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(a[i]->user_name, n) == 0)
        {
            if ((strcmp(a[i]->user_pwd, pw) == 0))
            {
                printf("Login Success!\n");
                return 1;
            }
            printf("Wrong Password!\n");
            return -1;
        }
    }
    printf("Account doesn't exist!\n");
    return 0;
}

void SignUp(struct Account* a[], int count)
{
    char t_n[15], t_pw[15], t_pw2[15];
    int go;
    while (1)
    {
        go = 1;
        printf("Enter your ID: ");
        scanf("%s", t_n);
        
        if (count == 0)
        {
            a[0] = (struct Account*) malloc(sizeof(struct Account));
            strcpy(a[0]->user_name, t_n);
        }
        for (int i = 0; i < count; i++)
        {
            if (strcmp(a[i]->user_name, t_n) == 0)
            {
                printf("ID already exists! Try again!\n");
                go = 0;
                continue;
            }
        }
        if (go)
            break;
    }
    while (1)
    {
        printf("Enter your pwdD: ");
        scanf("%s", t_pw);
        printf("Re-enter password: ");
        scanf("%s", t_pw2);
        if (strcmp(t_pw, t_pw2)==0)
            break;
        printf("Passwords are not same. Please, enter it again.\n");
    }
    FILE * fp;
    if ((strcmp(a[0]->user_name, "NULL") == 0) &&(strcmp(a[0]->user_pwd, "0000") == 0))
    {
        fp = fopen("account.txt", "w");
        fprintf(fp, "%s %s\n", t_n, t_pw);
        fclose(fp);
    }
    
    else
    {
        fp = fopen("account.txt", "a");
        fprintf(fp, "%s %s\n", t_n, t_pw);
        fclose(fp);
    }
    printf("Successfully appended\n");
}