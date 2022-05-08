#include <stdbool.h>

typedef struct
{
    int num;
    char name[20];
    char title[50];
    char date[11];
    char content[100];
    char isAttached; // Y or N
    bool isDeleted;
} Post;

int CreatePost(Post *p, int index);          // create a post
void ReadPost(Post p);                       // read a post
void ListBoard(Post *p, int idx);            // list all posts in board
int UpdatePost(Post *p, int count, int idx); // update a post
int DeletePost(Post *p, int idx);            // delete a post
void SaveBoard(Post *p, int idx);                     // save all posts in board
int LoadBoard(Post *p);                      // load all posts in board
int ShowMenu();                              // show menus
void SearchPost(Post *p, int idx);           // searching in board
void showDetail(Post *p, int idx);           // read descript from a post
int SelectPostNo(Post *p, int index);