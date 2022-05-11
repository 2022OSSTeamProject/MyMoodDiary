struct Account
{
    int user_num;   // user index number
    char user_name[15];     // user name upto 15 characters
    char user_pwd[15];      // user password upto 15 characters
};

int AccountMenu();
int LoadAccount(struct Account* p[]);
int Login(struct Account* p[], char n[15], char pw[15], int count);
int SignUp(struct Account* p[], int count);