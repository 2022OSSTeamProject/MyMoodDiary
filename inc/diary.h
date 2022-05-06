//CRUD 헤더파일

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef Struct {
    int num;
    char name[20];
    char title[50];
    char date[11];
    char content[100];
    char isAttached; //Y or N
} Post;

CreatePost(Post * p);// create a post
ReadPost(Post p); // read a post
ListBoard(Post ** p, int idx); // list all posts in board
UpdatePost(Post * p, int idx); // update a post
DeletePost(Post * p, int idx); // delete a post