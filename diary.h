#include <stdbool.h>

typedef struct
{
    int num;            // post`s index
    char name[20];      // writer`s name
    char title[50];     // post`s title
    char date[11];      // post`s last modified date
    char content[1024];  // post`s content
    char isAttached;    // Y or N
    bool isDeleted;
    char isPublic;
} Post;

int CreatePost(Post *p, int index, char id[15], int mode);          // create a post
    // input  : the post`s address, last index
    // output : 1 (for count)
void ReadPost(Post p);                       // read a post
    // input  : the post`s value
void ListBoard(Post *p, int idx);            // list all posts in board
    // input  : the board`s address, last index
int UpdatePost(Post *p, int count, char id[15], int no); // show ShowDetail() & update information you choose
    // input  : the board`s address, a number you choose
    // output : 1
int DeletePost(Post *p, int no);            // delete the post
    // input  : the board`s address, a number you choose
    // output : 1 (for count)
void SaveBoard(Post *p, int idx, char id[15], int mode);   // save all posts in board
    // input  : the board`s address
int LoadBoard(Post *p, char id[15], int mode);

void ListBoard(Post *p, int idx);            // load all posts in board
    // input  : the board`s address
int ShowMenu();                              // show menus
void SearchPost(Post *p, int idx);           // what kind of column do you want to search in? & searching in column
    // input  : the board`s address, last index
void showDetail(Post *p, int no);           // read descript from the post
    // input  : the board`s address, a number you choose
int SelectPostNo(Post *p, int index);        // show ListBoard() & choose the index
    // input  : the board`s address, last index
    // output : the index that user chooses