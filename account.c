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

int LoadAccount(struct Account* p[])
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
            p[i] = (struct Account*) malloc(sizeof(struct Account));
            strcpy(p[i]->user_name, t_name);
            strcpy(p[i]->user_pwd, t_pwd);
            i++;
        }
        printf("=> Loading Success\n");
        fclose(fp);
    }
    else
    {
        FILE * fp;
        printf("\n=> File doesn't exit.\n New file created\n");
        fp = fopen("account.txt", "w");
        fprintf(fp,"NULL 0\n");         //fake value for creating new file
        fclose(fp);
        int tmp = LoadAccount(p);
    }
    
    return i;
}

int Login(struct Account* p[], char n[15], char pw[15], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(p[i]->user_name, n) == 0)
        {
            if ((strcmp(p[i]->user_pwd, pw) == 0))
            {
                printf("Login Success!\n");
                return 1;
            }
            printf("Wrong Password!\n");
            return -1;
        }
    }
    printf("Account doesn't exit!\n");
    return 0;
}

void SignUp(struct Account* p[], int count)
{
    char t_n[15], t_pw[15], t_pw2[15];
    int go;
    while (1)
    {
        go = 1;
        printf("Enter your ID: ");
        scanf("%s", t_n);
        
        for (int i = 0; i < count; i++)
        {
            if (strcmp(p[i]->user_name, t_n) == 0)
            {
                printf("ID already exuts! Try again!\n");
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
    if ((strcmp(p[0]->user_name, "NULL") == 0) &&(strcmp(p[0]->user_pwd, "0000") == 0))
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