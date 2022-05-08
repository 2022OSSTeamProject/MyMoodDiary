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

    printf("작성자\n");
    scanf("%[^\n]s", p->name);
    getchar();

    printf("제목\n");
    scanf("%[^\n]s", p->title);
    getchar();

    printf("내용\n");
    scanf("%[^\n]s", p->content);
    getchar();
    do
    {
        printf("첨부 사진 여부 (Y/N)\n");
        scanf("%c", &p->isAttached);
        if (p->isAttached == 'Y' || p->isAttached == 'N')
            break;
        printf("\'Y\'나 \'N\'으로 입력해주세요\n");
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
    printf("****************************************************\n");
    printf("%s\n%s\n%s\n%s\n", p.name, p.title, p.date, p.content);
    printf("****************************************************\n");
}

void ListBoard(Post *p, int idx)
{
    printf("****************************************************\n");
    for (int i = 0; i < idx; i++)
    {
        printf("%d\t%s\t%s\t%s\n", p[i].num, p[i].title, p[i].date, p[i].name);
    }
    printf("****************************************************\n");
}
int UpdatePost(Post *p, int count, int idx)
{
    return 0;
}
int DeletePost(Post *p, int idx)    
{
    p[idx].isDeleted = true;
    return 1;
}
void SaveBoard(Post *p, int idx)
{
    char filename[20] = "dairy.txt";
    FILE * fp;
    fp = fopen(filename, "w");
    int j = 1;
    for (int i = 0; i < idx; i++)
    {
        if (!p[i].isDeleted)
        {
            fprintf(fp,"%d\t%s\t%s\t%s\n", j, p[i].title, p[i].date, p[i].name);
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
    printf("1. 일기조회\n");
    printf("2. 내용 상세보기\n");
    printf("3. 글 추가\n");
    printf("4. 글 수정\n");
    printf("5. 글 삭제\n");
    printf("6. 현재 내용 저장\n");
    printf("7. 찾기\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    getchar();
    return menu;
}
void SearchPost(Post *p, int idx)
{
    return;
}
void showDetail(Post *p, int idx)
{
    return;
}

int SelectPostNo(Post *p, int index)
{
    int idx;
    ListBoard(p, index);
    while (true)
    {
        printf("번호는 (취소 : 0)? ");
        scanf("%d", &idx);
        getchar();
        if (idx <= index)
            break;
        printf("해당 데이터는 없습니다.\n");
    }
    
    return idx;
}