#include <stdio.h>
#include "account.h"

int LoadAccount(Account* a[])
{
    FILE * fp;
    int i = 0;
    if(fp = fopen("account.txt", "r"))
    {
        while (!feof(fp)){
            int t_price, t_num;     //temporary variable for reading from file
            char t_name[20];
            char t_type;
            int t = fscanf(fp,"%d %d %c %[^\n]s",  &t_num, &t_price, &t_type, t_name);
            if (t <= 0) break;
            p[i] = (struct Account*) malloc(sizeof(struct Account));
            strcpy(p[i]->name, t_name);
            p[i]->num = t_num;
            p[i]->price = t_price;
            p[i]->type = t_type;
            i++;
        }
        printf("=> 로딩 성공!\n");
        fclose(fp);
    }
    else{
        printf("\n=> 파일 없음\n");
    }
    
    return i;
}