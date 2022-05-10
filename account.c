#include <stdio.h>
#include "account.h"

int AccountMenu()
{
    int menu;
    printf("\n*** Login Page ***\n");
    printf("1. Login\n");
    printf("2. Sign up\n");
    printf("0. exit\n\n");
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
            int t = fscanf(fp,"%d %s %s",  &t_num, t_name, t_pwd);
            if (t <= 0) break;
            p[i] = (struct Account*) malloc(sizeof(struct Account));
            strcpy(p[i]->user_name, t_name);
            p[i]->user_num = t_num;
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
        fp = fopen("account.txt", 'w');
        fclose(fp);
    }
    
    return i;
}