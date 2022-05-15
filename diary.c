#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "diary.h"

int CreatePost(Post *p, int index, char id[15], int mode)
{
    char today[11] = "";
    char year[5] = "";
    char mon[3] = "";
    char day[3] = "";

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    // printf("Writer`s name : ");
    // scanf(" %[^\n]s", p->name);
    strcpy(p->name, id);

    printf("Title of Post : ");
    scanf(" %[^\n]s", p->title);
    // getchar();

    printf("Contents : ");
    scanf(" %[^\n]s", p->content);
    // getchar();

    do
    {
        printf("Having attached photo(Y/N)? : ");
        scanf(" %c", &p->isAttached);
        if (p->isAttached == 'Y' || p->isAttached == 'N')
            break;
        printf("\'Y\' or \'N\' only you can choose\n");
    } while (true);

    if (mode == 1)
    {
        p->isPublic = 'Y';
    }
    else
    {
        do
        {
            printf("Do you want to set this post as public so that everyone can see it? (Y/N)? : ");
            scanf(" %c", &p->isPublic);
            if (p->isPublic == 'Y' || p->isPublic == 'N')
                break;
            printf("\'Y\' or \'N\' only you can choose\n");
        } while (true);
    }

    sprintf(year, "%d", tm->tm_year + 1900);
    sprintf(mon, "%d", tm->tm_mon + 1);
    sprintf(day, "%d", tm->tm_mday);

    strcat(today, year);
    strcat(today, "-");
    strcat(today, mon);
    strcat(today, "-");
    strcat(today, day);

    strcpy(p->date, today);

    p->num = index;

    p->isDeleted = false;
    return 1;
}

void ReadPost(Post p)
{
    printf("%d\t%s\t%s\t%s\t%.10s ...\n", p.num, p.title, p.name, p.date, p.content);
}

void ListBoard(Post *p, int idx)
{
    printf("\n****************************************************\n");
    printf("no\ttitle\twriter\tdate\t\tcontent\n");
    for (int i = 0; i < idx; i++)
    {
        if (!p[i].isDeleted)
            ReadPost(p[i]);
    }
    printf("****************************************************\n\n");
}
int UpdatePost(Post *p, int count, char id[15], int no)
{
    char today[11] = "";
    char year[5] = "";
    char mon[3] = "";
    char day[3] = "";

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    showDetail(p, no);

    int updateNo = 1;
    while (1)
    {
        printf("Choose what you want to update (1:title 2:content 3:AttacedPhoto 0:exit) : ");
        scanf("%d", &updateNo);

        if (updateNo == 0)
        {
            break;
        }
        else if (updateNo == 1)
        {
            printf("New title of Post : ");
            scanf(" %[^\n]s", p->title);
        }
        else if (updateNo == 2)
        {
            printf("New content : ");
            scanf(" %[^\n]s", p->content);
        }
        else if (updateNo == 3)
        {
            do
            {
                printf("Having attached photo(Y/N)? : ");
                scanf(" %c", &p->isAttached);
                if (p->isAttached == 'Y' || p->isAttached == 'N')
                    break;
                printf("\'Y\' or \'N\' only you can choose\n");
            } while (true);
        }
        sprintf(year, "%d", tm->tm_year + 1900);
        sprintf(mon, "%d", tm->tm_mon + 1);
        sprintf(day, "%d", tm->tm_mday);

        strcpy(today, "");
        strcat(today, year);
        strcat(today, "-");
        strcat(today, mon);
        strcat(today, "-");
        strcat(today, day);

        strcpy(p->date, today);
    }

    return 1;
}
int DeletePost(Post *p, int no)
{
    p[no].isDeleted = true;
    return 1;
}
void SaveBoard(Post *p, int idx, char id[15], int mode)
{
    char filename[20];
    strcpy(filename, strcat(id, ".txt"));
    FILE *fp, *fp2;
    if (mode == 1)
    {
        fp = fopen("public.txt", "w");
        fp2 = fopen(filename, "w");
    }
    else if (mode == 2)
    {
        fp = fopen(filename, "w");
        fp2 = fopen("public.txt", "w");
    }
    int j = 1;
    for (int i = 0; i < idx; i++)
    {
        if (!p[i].isDeleted)
        {
            fprintf(fp, "%d\t%s\t%s\t%s\t%c\n", j, p[i].title, p[i].name, p[i].date, p[i].isPublic);
            fprintf(fp, "%s\n", p[i].content);
            if (mode == 2 && p[i].isPublic == 'Y')
            {
                fprintf(fp2, "%d\t%s\t%s\t%s\t%c\n", j, p[i].title, p[i].name, p[i].date, p[i].isPublic);
                fprintf(fp2, "%s\n", p[i].content);
                // if (fp2 = fopen("public.txt", "r"))
                // {
                //     fclose(fp2);
                //     fp2 = fopen("public.txt", "a");
                //     fprintf(fp,"%d\t%s\t%s\t%s\t%c\n", j, p[i].title, p[i].name, p[i].date, p[i].isPublic);
                //     fprintf(fp,"%s\n", p[i].content);
                //     fclose(fp2);
                // }
                // else
                // {
                //     fp2 = fopen("public.txt", "w");
                //     fprintf(fp,"%d\t%s\t%s\t%s\t%c\n", j, p[i].title, p[i].name, p[i].date, p[i].isPublic);
                //     fprintf(fp,"%s\n", p[i].content);
                //     fclose(fp2);
                // }
            }

            j++;
        }
    }
    fclose(fp);
    fclose(fp2);
}

int LoadBoard(Post *p, char id[15], int mode)
{
    FILE *fp;
    char filename[20];
    strcpy(filename, id);
    strcat(filename, ".txt");

    if (mode == 1)
    {
        fp = fopen("public.txt", "rt");
    }
    else if (mode == 2)
    {
        fp = fopen(filename, "rt");
    }

    int j;
    int i = 0;
    while (!feof(fp))
    {
        printf("1\n");
        fscanf(fp, "%d %s %s %s %c", &j, p[i].title, p[i].name, p[i].date, &p[i].isPublic);
        fscanf(fp, "%s", p[i].content);
        i++;
    }
    fclose(fp);

    return j;
}
int ShowMenu()
{
    int menu;
    printf("\n*** My Mood Diary ***\n");
    printf("1. Show Board\n");
    printf("2. Show detail in a Post\n");
    printf("3. Create Post\n");
    printf("4. Update Post\n");
    printf("5. Delete Post\n");
    printf("6. Save Board\n");
    printf("7. Searching\n");
    printf("0. exit\n\n");
    printf("=> What do you want? ");
    scanf("%d", &menu);
    // getchar();
    return menu;
}
void SearchPost(Post *p, int idx)
{
    int select;
    printf("\n*** Search Diary ***\n");
    printf("1. Find by Number\n");
    printf("2. Find by Title\n");
    printf("3. Find by Writer\n");
    printf("4. Find by Date\n");
    printf("5. Find by Content\n\n");
    printf("=> 원하는 찾기 메뉴는? ");
    scanf("%d", &select);
    getchar();
    printf("\n");

    int scnt = 0;

    if (select == 1)
    {
        int search;
        printf("Search Number: ");
        scanf("%d", &search);
        getchar();
        printf("\n****************************************************\n");

        for (int i = 0; i < idx; i++)
        {
            if (p[i].isDeleted)
                continue;
            if (p[i].num == search)
            {
                ReadPost(p[i]);
                scnt++;
                break;
            }
        }
        printf("****************************************************\n");
    }
    else if (select == 2)
    {
        char search[20];
        printf("Search Title: ");
        scanf("%s", search);
        getchar();
        printf("\n****************************************************\n");

        for (int i = 0; i < idx; i++)
        {
            if (p[i].isDeleted)
                continue;
            if (strstr(p[i].title, search))
            {
                ReadPost(p[i]);
                scnt++;
            }
        }
        printf("****************************************************\n");
    }
    else if (select == 3)
    {
        char search[20];
        printf("Search Writer: ");
        scanf("%s", search);
        getchar();
        printf("\n****************************************************\n");

        for (int i = 0; i < idx; i++)
        {
            if (p[i].isDeleted)
                continue;
            if (strstr(p[i].name, search))
            {
                ReadPost(p[i]);
                scnt++;
            }
        }
        printf("****************************************************\n");
    }
    else if (select == 4)
    {
        char search[20];
        printf("Search Writer: ");
        scanf("%s", search);
        getchar();
        printf("\n****************************************************\n");

        for (int i = 0; i < idx; i++)
        {
            if (p[i].isDeleted)
                continue;
            if (strstr(p[i].date, search))
            {
                ReadPost(p[i]);
                scnt++;
            }
        }
        printf("****************************************************\n");
    }
    else if (select == 5)
    {
        char search[20];
        printf("Search Content: ");
        scanf("%s", search);
        getchar();
        printf("\n****************************************************\n");

        for (int i = 0; i < idx; i++)
        {
            if (p[i].isDeleted)
                continue;
            if (strstr(p[i].content, search))
            {
                ReadPost(p[i]);
                scnt++;
            }
        }
        printf("****************************************************\n");
    }
    else
    {
        printf("Invalid Selection\n");
        return;
    }

    if (scnt == 0)
    {
        printf("There are no search results!!!\n");
    }

    return;
}
void showDetail(Post *p, int no)
{
    printf("\nno\ttitle\twriter\tdate\n");
    printf("%d\t%s\t%s\t%s\ncontent : %s\n\n", p[no].num, p[no].title, p[no].name, p[no].date, p[no].content);
    return;
}

int SelectPostNo(Post *p, int index)
{
    int idx;
    ListBoard(p, index);
    while (true)
    {
        printf("number(cancel : 0)? ");
        scanf("%d", &idx);
        // getchar();
        if (idx == 0)
            break;
        if (idx <= index)
            break;
        printf("No such data.\n");
    }

    return idx;
}
