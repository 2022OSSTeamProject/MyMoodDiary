# MyMoodDiary

주제: 게시판<br>
들어갈 내용- 글 번호, 작성자, 제목, 날짜, 내용, 사진첨부여부<br>
활용 언어 : c<br>
공용 github: https://github.com/2022OSSTeamProject/MyMoodDiary.git<br>
대석 github: https://github.com/muyaho-universe/2022OSSTeamProject_Daeseok.git<br>
건하 github: https://github.com/rjsgk789/2022OSS_Baek<br>
위키: https://github.com/2022OSSTeamProject/MyMoodDiary/wiki<br>


typedef Struct {<br>
int num;<br>
char name[20];<br>
char title[50];<br>
char date[11];<br>
char content[100];<br>
char isAttached; //Y or N<br>
} Post;<br>

CreatePost(Post)<br>
ReadPost()<br>
ListBoard<br>
UpdatePost<br>
DeletePost<br>
SaveBoard<br>
LoadBoard<br>
ShowMenu()<br>
SearchPost<br>
showDetail<br>




설계 : CRUD 기능, 데이터 파일 저장/읽어오기, 검색 등 메뉴(종료메뉴 제외) 등 구조체와 10개 이상 함수 정의, github의 issue 를 이용하여 충분한 토론 후 기획하고 정의할 것
