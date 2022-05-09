#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "diary.h"

int main(void)
{
    Post p[20];
    int count = 0; // the numbers of post
    int menu;
    int index = 0; // now index
    int no;        // select number you want

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
            count += CreatePost(&p[count], ++index);
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
            if (UpdatePost(p, count, no-1))
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
            SaveBoard(p, index);
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
