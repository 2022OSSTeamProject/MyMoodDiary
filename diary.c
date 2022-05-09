#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "diary.h"

int CreatePost(Post *p, int index)
{
    char today[11] = "";
    char year[5] = "";
    char mon[3] = "";
    char day[3] = "";
    
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    printf("Writer`s name : ");
    scanf(" %[^\n]s", p->name);
    //getchar();

    printf("Title of Post : ");
    scanf(" %[^\n]s", p->title);
    //getchar();

    printf("Contents : ");
    scanf(" %[^\n]s", p->content);
    //getchar();

    do
    {
        printf("Having attached photo(Y/N)? : ");
        scanf(" %c", &p->isAttached);
        if (p->isAttached == 'Y' || p->isAttached == 'N')
            break;
        printf("\'Y\' or \'N\' only you can choose\n");
    } while (true);
    
    

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
        if (!p[i].isDeleted) ReadPost(p[i]);
    }
    printf("****************************************************\n\n");
}
int UpdatePost(Post *p, int count, int no)
{
    char today[11] = "";
    char year[5] = "";
    char mon[3] = "";
    char day[3] = "";
    
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    showDetail(p, no);

    int updateNo=1;
    while(1){
        printf("Choose what you want to update (1:writer 2:title 3:content 4:AttacedPhoto 0:exit) : ");
        scanf("%d", &updateNo);

        if (updateNo == 0){
            break;
        }
        else if (updateNo == 1){
            printf("New writer`s name : ");
            scanf(" %[^\n]s", p->name);
        }
        else if (updateNo == 2){
            printf("New title of Post : ");
            scanf(" %[^\n]s", p->title);
        }
        else if (updateNo == 3){
            printf("New content : ");
            scanf(" %[^\n]s", p->content);
        }
        else if (updateNo == 4){
            do
            {
                printf("Having attached photo(Y/N)? : ");
                scanf(" %c", &p->isAttached);
                if (p->isAttached == 'Y' || p->isAttached == 'N') break;
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
void SaveBoard(Post *p, int idx)
{
    char filename[20] = "diary.txt";
    FILE * fp;
    fp = fopen(filename, "w");
    int j = 1;
    for (int i = 0; i < idx; i++)
    {
        if (!p[i].isDeleted)
        {
            fprintf(fp,"%d\t%s\t%s\t%s\n", j, p[i].title, p[i].name, p[i].date);
            fprintf(fp,"%s\n", p[i].content);
            j++;
        }
    }
}
int LoadBoard(Post *p)
{
    return 0;
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
    //getchar();
    return menu;
}
void SearchPost(Post *p, int idx)
{
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
        //getchar();
        if (idx == 0) break;
        if (idx <= index)
            break;
        printf("No such data.\n");
    }
    
    return idx;
}