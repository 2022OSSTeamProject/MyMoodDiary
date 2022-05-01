# MyMoodDiary

주제: 게시판 
들어갈 내용- 글 번호, 작성자, 제목, 날짜, 내용, 사진첨부여부
활용 언어 : c
공용 github: https://github.com/2022OSSTeamProject/MyMoodDiary.git 
대석 github: https://github.com/muyaho-universe/2022OSSTeamProject_Daeseok.git
건하 github: https://github.com/rjsgk789/2022OSS_Baek
위키: https://github.com/2022OSSTeamProject/MyMoodDiary/wiki 


typedef Struct {
int num;
char name[20];
char title[50];
char date[11];
char content[100];
char isAttached; //Y or N
} Post;

CreatePost(Post)
ReadPost()
ListBoard
UpdatePost
DeletePost
SaveBoard
LoadBoard
ShowMenu()
SearchPost
showDetail




설계 : CRUD 기능, 데이터 파일 저장/읽어오기, 검색 등 메뉴(종료메뉴 제외) 등 구조체와 10개 이상 함수 정의, github의 issue 를 이용하여 충분한 토론 후 기획하고 정의할 것
