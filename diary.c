#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

    printf("첨부 사진 여부 (Y/N)\n");
    scanf("%c", &p->isAttached);

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
    return 0;
}
void SaveBoard(Post *p)
{
    return;
}
int LoadBoard(Post *p)
{
    return 0;
}
int ShowMenu()
{
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 상세보기\n");
    printf("3. 추가\n");
    printf("4. 수정\n");
    printf("5. 삭제\n");
    printf("6. 저장\n");
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
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &idx);
    getchar();
    return idx;
}