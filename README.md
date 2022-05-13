# MyMoodDiary

주제 : 다이어리<br>
소개 : 글을 원하는대로 쓰고 읽고 저장하고 삭제할 수 있게 해주는 프로그램이다.<br>
들어갈 내용 : 글 번호, 작성자, 제목, 날짜, 내용, 사진첨부여부 등<br>
활용 언어 : C<br>

팀 소개 및 역할 :
 - 백건하(아이디어, 구현 협업)
 - 김대석(아이디어, 구현 협업)
 - 정윤석(아이디어, 구현 협업)

공용 github : https://github.com/2022OSSTeamProject/MyMoodDiary.git<br>
대석 github : https://github.com/muyaho-universe/2022OSSTeamProject_Daeseok.git<br>
건하 github : https://github.com/rjsgk789/2022OSS_Baek<br>
윤석 github : https://github.com/YS-Jeong-21800673/MyMoodDiary<br>
위키 : https://github.com/2022OSSTeamProject/MyMoodDiary/wiki<br>


설계 :<br>
typedef Struct {<br>
int num;<br>
char name[20];<br>
char title[50];<br>
char date[11];<br>
char content[100];<br>
char isAttached; //Y or N<br>
} Post;<br>

struct Account<br>
{<br>
    char user_name[15];     // user name upto 15 characters<br>
    char user_pwd[15];      // user password upto 15 characters<br>
};<br>

int AccountMenu();<br>
int LoadAccount(struct Account* p[]);<br>
int Login(struct Account* p[], char n[15], char pw[15], int count);<br>
void SignUp(struct Account* p[], int count);<br>

CreatePost(Post * p) // create a post<br>
ReadPost(Post p) // read a post<br>
ListBoard(Post ** p, int idx) // list all posts in board<br>
UpdatePost(Post * p, int idx) // update a post<br>
DeletePost(Post * p, int idx) // delete a post<br>
SaveBoard(Post * p) // save all posts in board<br>
LoadBoard(Post * p) // load all posts in board<br>
ShowMenu() // show menus<br>
SearchPost(Post * p, int idx) // searching in board<br>
showDetail(Post * p, int idx) // read descript from a post<br>



