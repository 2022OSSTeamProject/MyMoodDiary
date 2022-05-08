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

    while (1)
    {
        menu = ShowMenu();
        if (menu == 0)
            break;
        if (menu == 1)
        {
            if (count > 0)
                ListBoard(p, index);
            else
                printf("?°?΄?°κ°? ??΅??€.\n");
        }
        else if (menu == 2)
        {
            int idx = SelectPostNo(p, index);
            ReadPost(p[idx]);
        }
        else if (menu == 3)
        {
            count += CreatePost(&p[count], ++index);
        }
        else if (menu == 4)
        {
            int idx = SelectPostNo(p, index);
            if (idx == 0)
            {
                printf("=> μ·¨μ?¨!\n");
                continue;
            }
            if (UpdatePost(p, count, idx))
                printf("=> ??  ?±κ³?!");
        }
        else if (menu == 5)
        {
            int idx = SelectPostNo(p, index);
            if (idx == 0)
            {
                printf("=> μ·¨μ?¨!\n");
                continue;
            }
            int deleteOk;
            printf("? λ§λ‘ ?­? ??κ² μ΅?κΉ? (?­?  : 1)? ");
            scanf("%d", &deleteOk);
            if (deleteOk == 1)
            {
                if (DeletePost(p, idx))
                {
                    count--;
                    printf("=> ?­? ?¨!");
                }
            }
        }
        else if (menu == 6)
        {
            SaveBoard(p, index);
        }
        else if (menu == 7)
        {
            int idx = SelectPostNo(p, index);
            SearchPost(p, idx);
        }
    }
    printf("μ’λ£?¨!\n");
    return 0;
}
