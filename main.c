#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "diary.h"
#include "account.h"

int main(void)
{
    Post p[32];
    int count = 0; // the numbers of post
    int account_count = 0;
    int account_menu;
    int menu;
    int index = 0; // now index
    int no;        // select number you want
    int login;
    int mode; // for public or private mode
    struct Account* a[20];
    char id[15], pwd[15];
    
    account_count = LoadAccount(a);
    while (1)
    {  
        account_menu = AccountMenu();
        if (account_menu == 1)
        {
           printf("Enter your ID: ");
           scanf("%s", id);
           printf("Enter your PWD: ");
           scanf("%s", pwd);
           login = Login(a, id, pwd, account_count);
           if (login == 1)
            break;
        }
        if (account_menu == 2)
        {
            SignUp(a, account_count);
            account_count = LoadAccount(a);
        }
        else
            printf("Enter the menu again.\n");
    }

    printf("\nWelcome, %s!! We missed you :)\n", id);
    
    while(1){
        printf("1. public mode\n");
        printf("2. private mode\n");
        printf("Choose the mode! (only 1 or 2) : ");
        scanf("%d", &mode);

        if (mode == 1 || mode == 2) break;
        else printf("Wrong input!\n");
    }
    count = 0;
    
    index = LoadBoard(p, id, mode);
    count = index;

    while (1)
    {
        menu = ShowMenu();
        if (menu == 0)
            break;
        if (menu == 1)
        {
            // ListBoard
            if (count > 0)
                ListBoard(p, index);
            else
                printf("No data.\n");
        }
        else if (menu == 2)
        {
            // showDetail function
            no = SelectPostNo(p, index);
            showDetail(p, no-1);
        }
        else if (menu == 3)
        {
            // CreatePost
            count += CreatePost(&p[count], ++index, id, mode);
        }
        else if (menu == 4)
        {
            // UpdatePost
            no = SelectPostNo(p, index);
            if (no == 0)
            {
                printf("=> Canceled!\n");
                continue;
            }
            if (UpdatePost(p, count, id, no-1))
                printf("=> Update Complete!\n");
        }
        else if (menu == 5)
        {
            // DeletePost
            no = SelectPostNo(p, index);
            if (no == 0)
            {
                printf("=> Canceled!\n");
                continue;
            }
            int deleteOk;
            printf("Are you sure you want to delete it? (delete : 1)? ");
            scanf("%d", &deleteOk);
            if (deleteOk == 1)
            {
                if (DeletePost(p, no-1))
                {
                    count--;
                    printf("=> Delete Complete!\n");
                }
            }
        }
        else if (menu == 6)
        {
            // SaveBoard
            // if mode == 1
            if (mode == 1){
                // save public board
                SaveBoard(p, index, id, mode);
            }
            // if mode == 2
            else if (mode == 2){
                // save private board
                SaveBoard(p, index, id, mode);
            }
        }
        else if (menu == 7)
        {
            // SearchPost
            SearchPost(p, index);
        }
    }
    printf("Exit!\n");
    return 0;
}
