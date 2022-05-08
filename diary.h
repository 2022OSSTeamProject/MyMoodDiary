typedef struct
{
    int num;            // post`s index
    char name[20];      // writer`s name
    char title[50];     // post`s title
    char date[11];      // post`s last modified date
    char content[100];  // post`s content
    char isAttached;    // Y or N
} Post;

int CreatePost(Post *p, int index);          // create a post
    // input  : the post`s address, last index
    // output : 1 (for count)
void ReadPost(Post p);                       // read a post
    // input  : the post`s value
void ListBoard(Post *p, int idx);            // list all posts in board
    // input  : the board`s address, last index
int UpdatePost(Post *p, int count, int idx); // call SelectPostNo & update the post
    // input  : the board`s address, last index
    // output : 1?
int DeletePost(Post *p, int idx);            // call SelectPostNo & delete the post
    // input  : the board`s address, last index
    // output : 1?
void SaveBoard(Post *p);                     // save all posts in board
    // input  : the board`s address
int LoadBoard(Post *p);                      // load all posts in board
    // input  : the board`s address
int ShowMenu();                              // show menus
void SearchPost(Post *p, int idx);           // searching in board
    // input  : the board`s address, last index
void showDetail(Post *p, int idx);           // call SelectPostNo & read descript from the post
    // input  : the board`s address, last index
int SelectPostNo(Post *p, int index);        // show ListBoard() & choose the index
    // input  : the board`s address, last index
    // output : the index that user chooses