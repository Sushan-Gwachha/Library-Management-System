#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void whoareyou();

void admin();
void mainpageforAdmin();

void loginPage();

void signupPage();
void signupAdmin();
void signupStaff();

void UpdatePage();
void upkey();
void uppass();
void updateAdmin();
void updateStaff();

void deletePage();
void admindel();
void userdel();

void exitPage();

void Key();
void makeKey();

void staff();
void mainpageforStaff();
void loginpageforStaff();
void exitpageforStaff();

void membership(int *mrole);

void viewMember(int *mrole);
void searchMember(int *mrole);
void addMember(int *mrole);
void deleteMember(int *mrole);

void start();
void startforStaff();

void list();
void listforstaff();

void addBook();

void viewBook(int *vrole);
void viewallbook(int *vrole);
void viewissuedbook(int *vrole);
void viewavailablebook(int *vrole);

void searchBook(int *srole);

void searchBookid(int *srole);
void searchBookName(int *srole);
void searchBookAuthor(int *srole);

void issueBook(int *irole);

void returnBook(int *rrole);
void returnBookforStaff();

void updateBook();
void Uupbookid(int bookid);
void Uupbooktitle(int bookid);
void Uupbookauthor(int bookid);

void deleteBook();

void helpBook(int *hrole);

void manual(int *hrole);

void aboutus(int *arole);

void exitProgram(int *erole);

struct User
{
    char userName[100];
    char passWord[100];
    char key[100];
} L;

struct Book
{
    int bookId;
    char bookName[100];
    char Author[100];
    int isIssued; // 0 = Available
                  // 1 = Issued

} B;

struct tbook
{
    int bookId;
    char bookName[100];
    char Author[100];
    int isIssued;
} T;

struct mem
{
    int memId;
    char memName[100];
    int memSex;
} M;

int main() // *Address bar completed
{
    makeKey();
    system("cls");
    printf("Home>\n");
    whoareyou();

    return (0);
}

void whoareyou()
{
    int choice;
    int arole = 46;

    printf("\n=== Library Management System ===\n");
    printf("\n=== Who Are You? ===\n");
    printf("\n*Continue as 'Admin' or 'Staff'.\n");
    printf("\n|1.Admin|");
    printf("\n|2.Staff|");
    printf("\n|3.About us|");
    printf("\n|0.Exit|\n");
    printf("\nYour choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        system("cls");
        admin();
        break;

    case 2:
        system("cls");
        staff();
        break;

    case 3:
        system("cls");
        aboutus(&arole);
        break;

    case 0:
        system("cls");
        printf("BYE BYE...");
        exit(0);
        break;

    default:
        system("cls");
        printf("Home>\n");
        whoareyou();
        break;
    }
}

void admin() // *Adress bar completed
{
    char pass[100];
    char Key[100];
    FILE *fp;
    fp = fopen("KEY.txt", "r");
    if (fp == NULL)
    {
        printf("File not found...");
    }
    fscanf(fp, "%s", Key);
    fclose(fp);

    printf("\n*To Enter as an Admin,\n");
    printf("Enter Authorized Key: ");
    scanf("%s", pass);

    if (strcmp(pass, Key) == 0)
    {
        system("cls");
        printf("Home> Admin>\n");
        mainpageforAdmin();
    }
    if (strcmp(pass, Key) != 0)
    {
        system("cls");
        printf("Home>\n");
        printf("\nYou are not eligible to continue as Admin!\n");
        printf("%s%s", pass, Key);
        whoareyou();
    }
}

void mainpageforAdmin() // Admin page for login,signup,etc. *Address bar completed
{

    int choice;
    int mrole = 0;

    printf("\n==== Library Management System ====\n");
    printf("\n--- Admin ---\n");
    printf("\n--- WELCOME ---\n");
    printf("\n|1.Login|");
    printf("\n|2.Sign up|");
    printf("\n|3.Update User & Key|");
    printf("\n|4.Remove User|");
    printf("\n|5.Membership|");
    printf("\n|0.Exit|");
    printf("\nNote: username and password should not contain 'space'.\n");

    printf("\nYour choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        system("cls");
        printf("Home> Admin> Login>\n");
        loginPage();
        break;
    case 2:
        system("cls");
        printf("Home> Admin> Signup>\n\n");
        signupPage();
        break;

    case 3:
        system("cls");
        printf("Home> Admin> Update>\n\n");
        UpdatePage();
        break;

    case 4:
        system("cls");
        printf("Home> Admin> Delete>\n\n");
        deletePage();
        break;

    case 5:
        system("cls");
        printf("Home> Admin> Membership>\n");
        membership(&mrole);
        break;

    case 0:
        system("cls");
        printf("Home> Admin> Exit>\n\n");
        exitPage();
        break;

    default:
        system("cls");

        printf("Home> Admin>\n");

        printf("\n|====================================================================|\n");
        printf("\tPlease choose option '1' or option '2' to continue....");
        printf("\n|====================================================================|\n");

        mainpageforAdmin();
        break;
    }
}

void loginPage() // *Adress bar completed
{
    char userName[100];
    char passWord[100];

    int userExists = 0;
    int passExists = 0;
    int success = 0;
    int count = 3;

    FILE *f, *t;
    while (count > 0)
    {

        f = fopen("AData.txt", "r");

        if (f == NULL)
        {
            t = fopen("AData.txt", "w");
            fclose(t);
            printf("\nSign up to continue...\n");
            printf("\nPress 'Enter' to go back: ");
            getchar();
            printf("Home> Admin>\n\n");
            mainpageforAdmin();
        }

        // check if file is empty or not
        fseek(f, 0, SEEK_END); // move pointer to end.
        int size = ftell(f);   // get position of the pointer.
        rewind(f);             // returns pointer to the top.

        if (size == 0) // if empty.
        {
            printf("\nSignup to continue!\n");
            printf("\nPress 'Enter' to go back: ");
            getchar();

            printf("Home> Admin>\n\n");
            mainpageforAdmin();
        }

        printf("\n=== Login ===\n\n");

        printf("Username: ");
        scanf("%s", userName);

        printf("Password: ");
        scanf("%s", passWord);

        while (fscanf(f, "%s\n%s", L.userName, L.passWord) != EOF) // read data
        {
            if (strcmp(userName, L.userName) == 0 && strcmp(passWord, L.passWord) == 0) // check if username and password is correct.
            {
                success = 1;
                break;
            }

            if (strcmp(userName, L.userName) == 0) // check if 'username'is correct.
            {
                userExists = 1;
            }

            if (strcmp(passWord, L.passWord) == 0) //  check if 'password' is correct.
            {
                passExists = 1;
            }
        }

        if (success)
        {
            system("cls");
            printf("Home> Admin> Login> %s>\n", L.userName);
            start();
            exit(0);
        }

        else if (userExists)
        {
            system("cls");

            printf("\nIncorrect Username or Password\n\n");

            if (count == 1)
            {
                system("cls");

                printf("Home> Admin>\n");

                printf("\nInvalid!!\n");
                count--;

                mainpageforAdmin();
            }
            else
            {
                printf("You have %d chance left\n\n", count - 1);
                count--;
            }
        }

        else if (passExists)
        {
            system("cls");

            printf("\nIncorrect Username or Password\n\n");

            if (count == 1)
            {
                system("cls");

                printf("Home> Admin>\n");

                printf("\nInvalid!!\n");
                count--;

                mainpageforAdmin();
            }
            else
            {
                printf("You have %d chance left\n\n", count - 1);
                count--;
            }
        }

        else
        {
            system("cls");
            printf("\nError: No User Data!!\n\n");

            if (count == 1)
            {
                system("cls");

                printf("Home> Admin>\n");

                printf("\nInvalid!!\n");
                count--;

                mainpageforAdmin();
            }
            else
            {
                printf("You have %d chance left\n\n", count - 1);
                count--;
            }
        }

        success = 0;
        userExists = 0;
        passExists = 0;
        fclose(f);
    }
}

void signupPage() //*
{
    int choice;

    printf("=== Signup ===\n\n");
    printf("*Signup as:\n");
    printf("\n1.|Admin|");
    printf("\n2.|Staff|");
    printf("\n0.|Go Back|\n");
    printf("\nYour Choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        system("cls");
        printf("Home> Admin> Signup> SignupAdmin>\n\n");
        signupAdmin();
        break;

    case 2:
        system("cls");
        printf("Home> Admin> Signup> signupStaff>\n\n");
        signupStaff();
        break;

    case 0:
        system("cls");
        printf("Home> Admin>\n");
        mainpageforAdmin();
        break;

    default:
        system("cls");
        printf("Home> Admin> Signup>\n\n");
        signupPage();
        break;
    }
}

void signupAdmin() //*
{
    char userName[100];
    char passWord[100];

    char key[100];
    char username[100];
    char password[100];

    FILE *f, *fp, *k, *Check;

    fp = fopen("KEY.txt", "r");

    if (fp == NULL)
    {
        printf("\nProblem solved........\n");
        makeKey();
    }

    printf("=== Sign up ===\n");
    printf("\nEnter authorized key: ");
    scanf("%s", L.key);

    fscanf(fp, "%s", key);

    fclose(fp);

    if (strcmp(L.key, key) != 0) // if user has no authority.
    {
        system("cls");

        printf("Home> Admin> Signup>\n");

        printf("\nYou are not eligible to Signup!\n\n");

        signupPage();
    }
    else
    {
        system("cls");

        printf("=== Sign up ===\n");
        printf("\nPlease enter details for new user.\n");
    again:
        printf("Username: ");
        scanf("%s", L.userName);
        printf("Password: ");
        scanf("%s", L.passWord);

        Check = fopen("AData", "r");

        if (Check == NULL)
        {
            printf("\nCan't open...\n");
        }

        while (fscanf(Check, "%s\n%s\n", userName, passWord) != EOF)
        {
            if (strcmp(L.userName, userName) == 0)
            {
                printf("\nUsername Exists!");
                printf("\nChoose another.....\n");
                goto again;
            }
        }

        fclose(Check);

        f = fopen("AData.txt", "a");

        if (f == NULL)
        {
            printf("Can't open");
            return;
        }

        fprintf(f, "%s\n%s\n", L.userName, L.passWord);

        fclose(f);

        system("cls");

        printf("Home> Admin> Signup>\n");

        printf("\nSignup Successful.....");
        printf("\nAdmin '%s'", L.userName);
        printf(",You can login now.\n\n");

        signupPage();
    }
}

void signupStaff() //*
{
    char userName[100];
    char passWord[100];

    char key[100];
    char username[100];
    char password[100];

    FILE *f, *fp, *k, *Check;

    fp = fopen("KEY.txt", "r");

    if (fp == NULL)
    {
        printf("\nProblem solved........\n");
        makeKey();
    }

    printf("=== Sign up ===\n");
    printf("\nEnter authorized key: ");
    scanf("%s", L.key);

    fscanf(fp, "%s", key);

    fclose(fp);

    if (strcmp(L.key, key) != 0) // if user has no authority.
    {
        system("cls");

        printf("Home> Admin> Signup>\n");

        printf("\nYou are not eligible to Signup!\n\n");

        signupPage();
    }
    else
    {
        system("cls");

        printf("=== Sign up ===\n");
        printf("\nPlease enter details for new user.\n");
    again:
        printf("Username: ");
        scanf("%s", L.userName);
        printf("Password: ");
        scanf("%s", L.passWord);

        Check = fopen("userData", "r");

        if (Check == NULL)
        {
            printf("\nCan't open...\n");
        }

        while (fscanf(Check, "%s\n%s\n", userName, passWord) != EOF)
        {
            if (strcmp(L.userName, userName) == 0)
            {
                printf("\nUsername Exists!");
                printf("\nChoose another.....\n");
                goto again;
            }
        }

        fclose(Check);

        f = fopen("userData.txt", "a");

        if (f == NULL)
        {
            printf("Can't open");
            return;
        }

        fprintf(f, "%s\n%s\n", L.userName, L.passWord);

        fclose(f);

        system("cls");

        printf("Home> Admin> Signup>\n");

        printf("\nSignup Successful.....");
        printf("\nStaff '%s'", L.userName);
        printf(",You can login now.\n\n");

        signupPage();
    }
}

void UpdatePage() //*
{
    int helpChoice;

    printf("=== Help ===\n");
    printf("\n1.Update key.");
    printf("\n2.Update User password.");
    printf("\n0.Go back.");
    printf("\n");

    printf("\nYour choice: ");
    scanf("%d", &helpChoice);
    getchar();

    switch (helpChoice)
    {
    case 1:
        system("cls");
        printf("Home> Admin> Update> Updatekey>\n");
        upkey();
        break;

    case 2:
        system("cls");
        printf("Home> Admin> Update> Updatepassword>\n\n");
        uppass();
        break;

    case 0:
        system("cls");
        printf("Home> Admin>\n");
        mainpageforAdmin();
        break;

    default:
        system("cls");
        printf("Home> Admin> Update>\n\n");
        UpdatePage();
        break;
    }
}

void upkey() //*
{
    char udKey;
    printf("\nPress 'Enter' to Update the key / 'n' to go back: ");
    scanf("%c", &udKey);

    if (udKey == 'y' || udKey == 'Y' || udKey == '\n') // continue if pressed 'enter' like getchar but it can take input like 'n' to not continue the function.
    {
        Key();
    }
    else
    {
        system("cls");
        printf("Home> Admin> Update>\n\n");
        UpdatePage();
    }
}

void uppass() //*
{

    int choice;

    printf("=== Update password ===\n");
    printf("\n1.|Admin|");
    printf("\n2.|Staff|");
    printf("\n0.|Go Back|\n");
    printf("\nYour choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        system("cls");
        printf("Home> Admin> Update> UpdateAdminPassword>\n\n");
        updateAdmin();
        break;

    case 2:
        system("cls");
        printf("Home> Admin> Update> UpdateStaffPassword>\n\n");
        updateStaff();
        break;

    case 0:
        system("cls");
        printf("Home> Admin> Update>\n\n");
        UpdatePage();
        break;

    default:
        system("cls");
        printf("Home> Admin> Update> Updatepassword>\n\n");
        uppass();
        break;
    }
}

void updateAdmin() //*
{
    char key[100];
    char userName[100];
    char passWord[100];
    int found = 0;

    FILE *fp, *f, *temp;
    fp = fopen("KEY.txt", "r");

    printf("=== Update password ===\n");
    printf("\nEnter authorized Key: ");
    scanf("%s", key);

    fscanf(fp, "%s", L.key);

    fclose(fp);

    if (strcmp(L.key, key) == 0)
    {
        f = fopen("AData.txt", "r");
        if (f == NULL)
        {
            printf("Can't locate File....");
            return;
        }

        temp = fopen("Tempp.txt", "w");
        if (temp == NULL)
        {
            printf("File NOT OPENING....");
            return;
        }

        printf("Enter username: ");
        scanf("%s", userName);

        while (fscanf(f, "%s\n%s\n", L.userName, L.passWord) != EOF)
        {

            if (strcmp(L.userName, userName) == 0)
            {

                printf("Enter new password: ");
                scanf("%s", passWord);
                fprintf(temp, "%s\n%s\n", L.userName, passWord);
                found = 1;
            }
            else
            {
                fprintf(temp, "%s\n%s\n", L.userName, L.passWord);
            }
        }

        fclose(f);
        fclose(temp);

        remove("AData.txt");
        rename("Tempp.txt", "AData.txt");

        if (found)
        {
            system("cls");
            printf("Home> Admin> Update> Updatepassword>\n");
            printf("\nUSER Updated Successfully.......\n\n");

            uppass();
        }

        if (!found)
        {
            system("cls");
            printf("Home> Admin> Update> Updatepassword>\n");
            printf("\nUser not Found!\n\n");

            uppass();
        }
    }
    else
    {
        system("cls");
        printf("Home> Admin> Update> Updatepassword>\n");
        printf("\nYou don't have authority...\n\n");

        uppass();
    }
}

void updateStaff() //*
{
    char key[100];
    char userName[100];
    char passWord[100];
    int found = 0;

    FILE *fp, *f, *temp;
    fp = fopen("KEY.txt", "r");

    printf("=== Update password ===\n");
    printf("\nEnter authorized Key: ");
    scanf("%s", key);

    fscanf(fp, "%s", L.key);

    fclose(fp);

    if (strcmp(L.key, key) == 0)
    {
        f = fopen("userData.txt", "r");
        if (f == NULL)
        {
            printf("Can't locate File....");
            return;
        }

        temp = fopen("Tempp.txt", "w");
        if (temp == NULL)
        {
            printf("File NOT OPENING....");
            return;
        }

        printf("Enter username: ");
        scanf("%s", userName);

        while (fscanf(f, "%s\n%s\n", L.userName, L.passWord) != EOF)
        {

            if (strcmp(L.userName, userName) == 0)
            {

                printf("Enter new password: ");
                scanf("%s", passWord);
                fprintf(temp, "%s\n%s\n", L.userName, passWord);
                found = 1;
            }
            else
            {
                fprintf(temp, "%s\n%s\n", L.userName, L.passWord);
            }
        }

        fclose(f);
        fclose(temp);

        remove("userData.txt");
        rename("Tempp.txt", "userData.txt");
        if (found)
        {
            system("cls");
            printf("Home> Admin> Update> Updatepassword>\n");
            printf("\nUSER Updated Successfully.......\n\n");

            uppass();
        }

        if (!found)
        {
            system("cls");
            printf("Home> Admin> Update> Updatepassword>\n");
            printf("\nUser not Found!\n\n");

            uppass();
        }
    }
    else
    {
        system("cls");
        printf("Home> Admin> Update> Updatepassword>\n");
        printf("\nYou don't have authority...\n\n");

        uppass();
    }
}

void deletePage() //*
{
    int choice;

    printf("=== Delete User ===\n");
    printf("\n1.|Admin|");
    printf("\n2.|Staff|");
    printf("\n0.|Go Back|\n");
    printf("\nYour choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        system("cls");
        printf("Home> Admin> Delete> Deleteadmin>\n\n");
        admindel();
        break;

    case 2:
        system("cls");
        printf("Home> Admin> Delete> Deletestaff>\n\n");
        userdel();
        break;

    case 0:
        system("cls");
        printf("Home> Admin>\n");
        mainpageforAdmin();
        break;

    default:
        system("cls");
        printf("Home> Admin> Delete>\n\n");
        deletePage();
        break;
    }
}

void admindel() //*
{
    char key[100];
    char userName[100];
    int found = 0;

    FILE *fp, *f, *temp;
    fp = fopen("KEY.txt", "r");

    printf("=== Delete User(admin) ===\n");
    printf("\nEnter authorized Key: ");
    scanf("%s", key);

    fscanf(fp, "%s", L.key);

    fclose(fp);

    if (strcmp(L.key, key) == 0)
    {
        f = fopen("AData.txt", "r");
        if (f == NULL)
        {
            printf("Can't locate File....");
            return;
        }

        temp = fopen("Tempp.txt", "w");
        if (temp == NULL)
        {
            printf("File NOT OPENING....");
            return;
        }

        system("cls");

        printf("=== Delete User(admin) ===\n");
        printf("\nEnter username: ");
        scanf("%s", userName);

        while (fscanf(f, "%s\n%s\n", L.userName, L.passWord) != EOF)
        {

            if (strcmp(L.userName, userName) == 0)
            {
                found = 1;
            }
            else
            {
                fprintf(temp, "%s\n%s\n", L.userName, L.passWord);
            }
        }

        fclose(f);
        fclose(temp);

        remove("AData.txt");
        rename("Tempp.txt", "AData.txt");
        if (found)
        {
            system("cls");
            printf("Home> Admin> Delete>\n");
            printf("\nUSER(admin) deleted Successfully.......\n\n");

            deletePage();
        }

        if (!found)
        {
            system("cls");
            printf("Home> Admin> Delete>\n");
            printf("\nUser(admin) not Found!\n\n");

            deletePage();
        }
    }
    else
    {
        system("cls");
        printf("Home> Admin> Delete>\n");
        printf("\nYou don't have authority...\n\n");

        deletePage();
    }
}

void userdel() //* (deletes staff)
{
    char key[100];
    char userName[100];
    int found = 0;

    FILE *fp, *f, *temp;
    fp = fopen("KEY.txt", "r");

    printf("=== Delete User(staff) ===\n");
    printf("\nEnter authorized Key: ");
    scanf("%s", key);

    fscanf(fp, "%s", L.key);

    fclose(fp);

    if (strcmp(L.key, key) == 0)
    {
        f = fopen("userData.txt", "r");
        if (f == NULL)
        {
            printf("Can't locate File....");
            return;
        }

        temp = fopen("Tempp.txt", "w");
        if (temp == NULL)
        {
            printf("File NOT OPENING....");
            return;
        }

        system("cls");
        printf("=== Delete User(staff) ===\n");
        printf("\nEnter username: ");
        scanf("%s", userName);

        while (fscanf(f, "%s\n%s\n", L.userName, L.passWord) != EOF)
        {

            if (strcmp(L.userName, userName) == 0)
            {
                found = 1;
            }
            else
            {
                fprintf(temp, "%s\n%s\n", L.userName, L.passWord);
            }
        }

        fclose(f);
        fclose(temp);

        remove("userData.txt");
        rename("Tempp.txt", "userData.txt");
        if (found)
        {
            system("cls");
            printf("Home> Admin> Delete>\n");
            printf("\nUSER(staff) deleted Successfully.......\n\n");

            deletePage();
        }

        if (!found)
        {
            system("cls");
            printf("Home> Admin> Delete>\n");
            printf("\nUser(staff) not Found!\n\n");

            deletePage();
        }
    }
    else
    {
        system("cls");
        printf("Home> Admin> Delete>\n");
        printf("\nYou don't have authority...\n\n");

        deletePage();
    }
}

void exitPage() //*
{
    int choice;

    printf("=== Exit ===\n");

    printf("\n|1.go back|(if u didn't click exit intentionaly..)");
    printf("\n|2.Log out|");
    printf("\n|3.Exit Program|\n");
    printf("\nYour Choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        system("cls");
        printf("Home> Admin>\n");
        mainpageforAdmin();
        break;
    case 2:
        system("cls");
        printf("Home>\n");
        whoareyou();
        break;
    case 3:
        system("cls");
        printf("Program Exited....\n");
        printf("\nBYE BYE......");
        exit(0);
        break;

    default:
        printf("Home> Admin> Exit>\n");
        exitPage();
        break;
    }
}

void Key() //*
{
    char ukey[100];

    FILE *fp, *U;
    fp = fopen("KEY.txt", "r");

    if (fp == NULL)
    {
        makeKey();
    }

    printf("\nEnter your key: ");
    scanf("%s", ukey);

    fscanf(fp, "%s", L.key);

    fclose(fp);

    if (strcmp(L.key, ukey) == 0)
    {

        U = fopen("KEY.txt", "w");

        printf("Enter your new key: ");
        scanf("%s", L.key);
        fprintf(U, "%s", L.key);

        fclose(U);

        system("cls");
        printf("Home> Admin> Update>\n");
        printf("\nKey updated successfully!!\n\n");
    }
    else
    {
        system("cls");
        printf("Home> Admin> Update>\n");
        printf("\nEntered Incorrect key!\n\n");
    }

    UpdatePage();
}

void makeKey() //*
{

    char admin[10] = "admin";

    FILE *k;
    k = fopen("KEY.txt", "w");

    if (k == NULL)
    {
        printf("File not open....");
        return;
    }

    fprintf(k, "%s", admin);

    fclose(k);
}

void staff() //*
{
    printf("Home> Staff>\n");
    mainpageforStaff();
}

void mainpageforStaff() //*
{
    int choice;
    int mrole = 1;

    printf("\n==== Library Management System ====\n");
    printf("\n--- Staff ---\n");
    printf("\n--- WELCOME ---\n");
    printf("\n|1.Login|");
    printf("\n|2.Membership|");
    printf("\n|0.Exit|");
    printf("\nNote: username and password should not contain 'space'.\n");
    printf("\nYour choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        system("cls");
        printf("Home> Staff> Login>\n\n");
        loginpageforStaff();
        break;

    case 2:
        system("cls");
        printf("Home> Staff> Membership>\n");
        membership(&mrole);
        break;

    case 0:
        system("cls");
        printf("Home> Staff> Exit>\n\n");
        exitpageforStaff();
        break;

    default:
        system("cls");

        printf("Home> Staff>\n");

        printf("\n|====================================================================|\n");
        printf("\tPlease choose option '1' or option '2' to continue....");
        printf("\n|====================================================================|\n");

        mainpageforStaff();
        break;
    }
}

void loginpageforStaff() //*
{
    char userName[100];
    char passWord[100];

    int userExists = 0;
    int passExists = 0;
    int success = 0;
    int count = 3;

    FILE *f, *t;
    while (count > 0)
    {

        f = fopen("userData.txt", "r");

        if (f == NULL)
        {
            t = fopen("userData.txt", "w");
            fclose(t);
            printf("\nSign up to continue...\n");
            printf("\nPress 'Enter' to go back: ");
            getchar();

            printf("Home> Staff>\n\n");
            mainpageforStaff();
        }

        // check if file is empty or not
        fseek(f, 0, SEEK_END); // move pointer to end.
        int size = ftell(f);   // get position of the pointer.
        rewind(f);             // returns pointer to the top.

        if (size == 0) // if empty.
        {
            printf("\nSignup to continue!\n");
            printf("\nPress 'Enter' to go back: ");
            getchar();

            printf("Home> Staff>\n\n");
            mainpageforStaff();
        }

        printf("=== Login ===\n\n");

        printf("Username: ");
        scanf("%s", userName);

        printf("Password: ");
        scanf("%s", passWord);

        while (fscanf(f, "%s\n%s", L.userName, L.passWord) != EOF) // read data
        {
            if (strcmp(userName, L.userName) == 0 && strcmp(passWord, L.passWord) == 0) // check if username and password is correct.
            {
                success = 1;
                break;
            }

            if (strcmp(userName, L.userName) == 0) // check if 'username'is correct.
            {
                userExists = 1;
            }

            if (strcmp(passWord, L.passWord) == 0) //  check if 'password' is correct.
            {
                passExists = 1;
            }
        }

        if (success)
        {
            system("cls");
            printf("Home> Staff> Login> %s>\n", L.userName);
            startforStaff();
        }

        else if (userExists)
        {
            system("cls");

            printf("Incorrect Username or Password\n\n");

            if (count == 1)
            {
                system("cls");
                printf("Home> Staff>\n");

                printf("\nInvalid!!\n");
                count--;

                mainpageforStaff();
            }
            else
            {
                printf("You have %d chance left\n\n", count - 1);
                count--;
            }
        }

        else if (passExists)
        {
            system("cls");

            printf("Incorrect Username or Password\n\n");

            if (count == 1)
            {
                system("cls");
                printf("Home> Staff>\n");

                printf("\nInvalid!!\n");
                count--;

                mainpageforStaff();
            }
            else
            {
                printf("You have %d chance left\n\n", count - 1);
                count--;
            }
        }

        else
        {
            system("cls");
            printf("Error: No User Data!!\n\n");

            if (count == 1)
            {
                system("cls");
                printf("Home> Staff>\n");

                printf("\nInvalid!!\n");
                count--;

                mainpageforStaff();
            }
            else
            {
                printf("You have %d chance left\n\n", count - 1);
                count--;
            }
        }

        success = 0;
        userExists = 0;
        passExists = 0;
        fclose(f);
    }
}

void exitpageforStaff() //*
{
    int choice;

    system("cls");

    printf("=== Exit ===\n");

    printf("\n|1.go back|");
    printf("\n|2.Log out|");
    printf("\n|3.Exit Program|\n");
    printf("\nYour Choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        system("cls");
        printf("Home> Staff>\n");
        mainpageforStaff();
        break;
    case 2:
        system("cls");
        printf("Home>\n");
        whoareyou();
        break;
    case 3:
        system("cls");
        printf("Program Exited....\n");
        printf("\nBYE BYE......");
        exit(0);
        break;

    default:
        system("cls");
        printf("Home> Staff> Exit>\n\n");
        exitpageforStaff();
        break;
    }
}

void membership(int *mrole) //*
{
    int choice;

    printf("\n=== MEMBERSHIP ===\n\n");
    printf("1.|View Members|\n");
    printf("2.|Search Member|\n");
    printf("3.|Add Member|\n");
    printf("4.|Delete Member|\n");
    printf("0.|Go Back|\n");
    printf("\nYour choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        system("cls");
        if (*mrole == 0)
        {
            printf("Home> Admin> Membership> Viewmember>\n");
        }
        if (*mrole == 1)
        {
            printf("Home> Staff> Membership> Viewmember>\n");
        }
        viewMember(mrole);
        break;

    case 2:
        system("cls");
        if (*mrole == 0)
        {
            printf("Home> Admin> Membership> Searchmember>\n");
        }
        if (*mrole == 1)
        {
            printf("Home> Staff> Membership> Searchmember>\n");
        }
        searchMember(mrole);
        break;

    case 3:
        system("cls");
        if (*mrole == 0)
        {
            printf("Home> Admin> Membership> Addmember>\n");
        }
        if (*mrole == 1)
        {
            printf("Home> Staff> Membership> Addmember>\n");
        }
        addMember(mrole);
        break;

    case 4:
        system("cls");
        if (*mrole == 0)
        {
            printf("Home> Admin> Membership> Deletemember>\n");
        }
        if (*mrole == 1)
        {
            printf("Home> Staff> Membership> Deletemember>\n");
        }
        deleteMember(mrole);
        break;

    case 0:
        system("cls");
        if (*mrole == 0)
        {
            printf("Home> Admin>\n");
            mainpageforAdmin();
        }
        if (*mrole == 1)
        {
            printf("Home> Staff>\n");
            mainpageforStaff();
        }
        break;

    default:
        system("cls");
        if (*mrole == 0)
        {
            printf("Home> Admin> Membership>\n");
        }
        if (*mrole == 1)
        {
            printf("Home> Staff> Membership>\n");
        }
        membership(mrole);
        break;
    }
}

void viewMember(int *mrole) //*
{
    FILE *mem = fopen("Member.txt", "r");
    if (mem == NULL)
    {
        printf("No members found.\n");
    }

    printf("\n==================== Members ====================\n");
    printf("%-10s | %-20s | %-10s\n", "Member ID", "Name", "Gender");
    printf("-------------------------------------------------\n");

    while (fscanf(mem, "%d\n%99[^\n]\n%d\n", &M.memId, M.memName, &M.memSex) == 3)
    {
        printf("%-10d | %-20s | %-10s\n",
               M.memId,
               M.memName,
               !M.memSex ? "Male" : "Female");
    }

    printf("=================================================\n\n");

    fclose(mem);

    printf("\nPress 'ENTER' to go back -->> ");
    getchar();

    system("cls");
    if (*mrole == 0)
    {
        printf("Home> Admin> Membership>\n");
    }
    if (*mrole == 1)
    {
        printf("Home> Staff> Membership>\n");
    }
    membership(mrole);
}

void searchMember(int *mrole) //*
{
    int memId;
    int found = 0;

    FILE *mem = fopen("Member.txt", "r");
    if (mem == NULL)
    {
        printf("No members found.\n");
    }

    printf("\n=== Search Member ===\n");
    printf("\nMember Id: ");
    scanf("%d", &memId);
    getchar();

    while (fscanf(mem, "%d\n%99[^\n]\n%d\n", &M.memId, M.memName, &M.memSex) != EOF)
    {
        if (memId == M.memId)
        {
            printf("\n=====================================================\n");
            printf("                 Member Information                  \n");
            printf("=====================================================\n");
            printf("   Member ID   : %d\n", M.memId);
            printf("   Name        : %s\n", M.memName);
            printf("   Sex/Gender  : %s\n", !M.memSex ? "Male" : "Female");
            printf("=====================================================\n\n");
            found = 1;
            break;
        }
    }
    fclose(mem);

    if (!found)
    {
        printf("No member detected!");
    }

    printf("\nPress 'ENTER' to go back -->> ");
    getchar();

    system("cls");
    if (*mrole == 0)
    {
        printf("Home> Admin> Membership>\n");
    }
    if (*mrole == 1)
    {
        printf("Home> Staff> Membership>\n");
    }
    membership(mrole);
}

void addMember(int *mrole) //*
{
    char memName[100];
    int memSex; // 0 = male ; 1 = female ;
    int Schoice;

    FILE *mem = fopen("Member.txt", "a");
    if (mem == NULL)
    {
        printf("File could not be opened...\n");
        return;
    }

    printf("\n=== Add Member ===\n");

    printf("\nEnter Name: ");
    scanf("%99[^\n]", memName);
again:
    printf("Enter Sex: ");
    printf("\n1.|Male|");
    printf("\n2.|Female|\n");
    printf("Your choice==> ");
    scanf("%d", &Schoice);
    getchar();

    switch (Schoice)
    {
    case 1:
        memSex = 0;
        break;

    case 2:
        memSex = 1;
        break;

    default:
        printf("\n");
        goto again;
        break;
    }

    FILE *mread;
    mread = fopen("Member.txt", "r");

    if (mread == NULL)
    {
        printf("\nFile couldn't be readed!...\n");
    }

    while (fscanf(mread, "%d\n%s\n%d\n", &M.memId, M.memName, &M.memSex) != EOF)
    {
        M.memId = M.memId + 1;
    }

    fclose(mread);

    fprintf(mem, "%d\n%s\n%d\n", M.memId, memName, memSex);

    fclose(mem);
    system("cls");

    if (*mrole == 0)
    {
        printf("Home> Admin> Membership>\n");
    }
    if (*mrole == 1)
    {
        printf("Home> Staff> Membership>\n");
    }

    printf("\nMember added successfully!\n");

    membership(mrole);
}

void deleteMember(int *mrole) //*
{
    char memId;
    char memName[100];
    int found = 0;
    int seek = 0;

    FILE *mdel, *mtemp;
    mdel = fopen("Member.txt", "r");
    if (mdel == NULL)
    {
        printf("File just desn't open");
    }

    printf("\n=== Delete Memmber ===\n");

    printf("\nEnter member's Id: ");
    scanf("%d", &memId);
    getchar();
    printf("Enter Name: ");
    scanf("%99[^\n]", memName);

    mtemp = fopen("mtemp.txt", "w");
    if (mtemp == NULL)
    {
        printf("File just desn't open");
    }

    while (fscanf(mdel, "%d\n%s\n%d\n", &M.memId, M.memName, &M.memSex) != EOF)
    {
        if ((M.memId == memId) && (strcmp(M.memName, memName) == 0))
        {
            found = 1;
        }
        else
        {
            fprintf(mtemp, "%d\n%s\n%d\n", M.memId, M.memName, M.memSex);
        }
        if ((M.memId == memId) || (strcmp(M.memName, memName) == 0))
        {
            seek = 1;
        }
    }

    fclose(mdel);
    fclose(mtemp);

    remove("Member.txt");
    rename("mtemp.txt", "Member.txt");

    system("cls");

    if (*mrole == 0)
    {
        printf("Home> Admin> Membership>\n");
    }
    if (*mrole == 1)
    {
        printf("Home> Staff> Membership>\n");
    }

    if (found)
    {
        printf("\nMember Deleted Successfully!\n");
    }

    if (!found)
    {
        printf("\nNo Member Detected!\n");
        if (seek)
        {
            printf("Member id or Member Name might be incorrect!...");
            seek = 0;
        }
    }

    membership(mrole);
}

// the library is from here.
void start() //*
{
    int choice;
    int vrole = 0;
    int srole = 0;
    int irole = 0;
    int rrole = 0;
    int hrole = 0;
    int arole = 0;
    int erole = 0;

    printf("\n===== Library Management System =====\n");
    list();
    printf("\n");
    printf("your choice: ");

    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        system("cls");
        printf("Home > Admin > Login > % s > Addbook >\n", L.userName);
        addBook();
        break;
    case 2:
        system("cls");
        printf("Home> Admin> Login> %s> Viewbook>\n", L.userName);
        viewBook(&vrole);
        break;
    case 3:
        system("cls");
        printf("Home> Admin> Login> %s> Searchbook>\n", L.userName);
        searchBook(&srole);
        break;
    case 4:
        system("cls");
        printf("Home> Admin> Login> %s> Issuebook>\n", L.userName);
        issueBook(&irole);
        break;
    case 5:
        system("cls");
        printf("Home> Admin> Login> %s> Returnbook>\n", L.userName);
        returnBook(&rrole);
        break;

    case 6:
        system("cls");
        printf("Home> Admin> Login> %s> Updatebook>\n", L.userName);
        updateBook();
        break;

    case 7:
        system("cls");
        printf("Home> Admin> Login> %s> Deletebook>\n", L.userName);
        deleteBook();
        break;

    case 8:
        system("cls");
        printf("Home> Admin> Login> %s> Help>\n", L.userName);
        helpBook(&hrole);
        break;

    case 9:
        system("cls");
        printf("Home> Admin> Login> %s> Aboutus>\n", L.userName);
        aboutus(&arole);
        break;

    case 0:
        system("cls");
        printf("Home> Admin> Login> %s> Exit>\n", L.userName);
        exitProgram(&erole);
        break;

    default:
        system("cls");
        printf("Home> Admin> Login> %s>\n", L.userName);
        printf("Invalid!!");
        start();
        break;
    }
}

void startforStaff() //*
{
    int choice, z;
    int vrole = 1;
    int srole = 1;
    int irole = 1;
    int rrole = 1;
    int hrole = 1;
    int arole = 1;
    int erole = 1;

    printf("\n===== Library Management System =====\n");
    listforstaff();
    printf("\n");
    printf("your choice: ");

    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        system("cls");
        printf("Home> Staff> Login> %s> Viewbook>\n", L.userName);
        viewBook(&vrole);
        break;

    case 2:
        system("cls");
        printf("Home> Staff> Login> %s> Searchbook>\n", L.userName);
        searchBook(&srole);
        break;

    case 3:
        system("cls");
        printf("Home> Staff> Login> %s> Issuebook>\n", L.userName);
        issueBook(&irole);
        break;

    case 4:
        system("cls");
        printf("Home> Staff> Login> %s> Returnbook>\n", L.userName);
        returnBook(&rrole);
        break;

    case 5:
        system("cls");
        printf("Home> Staff> Login> %s> Help>\n", L.userName);
        helpBook(&hrole);
        break;

    case 6:
        system("cls");
        printf("Home> Staff> Login> %s> Aboutus>\n", L.userName);
        aboutus(&arole);
        break;

    case 0:
        system("cls");
        printf("Home> Staff> Login> %s> Exit>\n", L.userName);
        exitProgram(&erole);
        break;

    default:
        printf("Invalid!!");
        printf("Home> Staff> Login> %s>\n", L.userName);
        startforStaff();
        break;
    }
}

void list()
{
    printf("\n");
    printf("1.|Add Book|");
    printf("\n");
    printf("2.|View All Books|");
    printf("\n");
    printf("3.|Search Book|");
    printf("\n");
    printf("4.|Issue Book|");
    printf("\n");
    printf("5.|Return Book|");
    printf("\n");
    printf("6.|Update Book|");
    printf("\n");
    printf("7.|Delete Book|");
    printf("\n");
    printf("8.|Help|");
    printf("\n");
    printf("9.|About Us|");
    printf("\n");
    printf("0.|Exit|");
    printf("\n");
}

void listforstaff()
{
    printf("\n");
    printf("1.|View Books|");
    printf("\n");
    printf("2.|Search Book|");
    printf("\n");
    printf("3.|Issue Book|");
    printf("\n");
    printf("4.|Return Book|");
    printf("\n");
    printf("5.|Help|");
    printf("\n");
    printf("6.|About Us|");
    printf("\n");
    printf("0.|Exit|");
    printf("\n");
}

void addBook() //*
{
    int bookId;
    char bookTitle[100];
    char author[100];
    int found = 0;
    int issue;

    FILE *fp, *f;
    fp = fopen("library.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("\n=== Add Book ===\n\n");
again:
    printf("Enter Book ID: ");
    scanf("%d", &B.bookId);

    f = fopen("library.txt", "r");
    if (f == NULL)
    {
        printf("Don't know the id!");
    }

    while (fscanf(f, "%d\n%99[^\n]\n%99[^\n]\n%d\n", &bookId, bookTitle, author, &issue) != EOF)
    {
        if (bookId == B.bookId)
        {
            found = 1;
            break;
        }
    }

    fclose(f);

    if (found)
    {
        system("cls");
        printf("=== Add Book ===\n");
        printf("\nBook ID '%d' already exists!\n\n", bookId);
        found = 0;
        goto again;
    }

    printf("Enter Book Title: ");
    scanf(" %99[^\n]", B.bookName);
    printf("Enter Author Name: ");
    scanf(" %99[^\n]", B.Author);
    B.isIssued = 0;

    fprintf(fp, "%d\n%s\n%s\n%d\n", B.bookId, B.bookName, B.Author, B.isIssued);

    fclose(fp);

    system("cls");
    printf("Home> Admin> Login> %s>\n", L.userName);
    printf("\nBook added successfully!!\n");

    start();
}

void viewBook(int *vrole) //*
{
    char choise;

    printf("\n=== View Book ===\n");

    printf("\n1.|View All Books|");
    printf("\n2.|View Issued Book|");
    printf("\n3.|View Available Book|");
    printf("\n0.|Go back|\n");
    printf("\nYour choice: ");
    scanf("%d", &choise);
    getchar();

    switch (choise)
    {
    case 1:
        system("cls");
        if (*vrole == 0)
        {
            printf("Home> Admin> Login> %s> Viewbook> Viewallbook>\n", L.userName);
        }
        if (*vrole == 1)
        {
            printf("Home> Staff> Login> %s> Viewbook> Viewallbook>\n", L.userName);
        }
        viewallbook(vrole);
        break;
    case 2:
        system("cls");
        if (*vrole == 0)
        {
            printf("Home> Admin> Login> %s> Viewbook> Viewissuedbook>\n", L.userName);
        }
        if (*vrole == 1)
        {
            printf("Home> Staff> Login> %s> Viewbook> Viewissuedbook>\n", L.userName);
        }
        viewissuedbook(vrole);
        break;
    case 3:
        system("cls");
        if (*vrole == 0)
        {
            printf("Home> Admin> Login> %s> Viewbook> Viewavailablebook>\n", L.userName);
        }
        if (*vrole == 1)
        {
            printf("Home> Staff> Login> %s> Viewbook> Viewavailablebook>\n", L.userName);
        }
        viewavailablebook(vrole);
        break;
    case 0:
        system("cls");
        if (*vrole == 0)
        {
            printf("Home> Admin> Login> %s>\n", L.userName);
            start();
        }
        if (*vrole == 1)
        {
            printf("Home> Staff> Login> %s>\n", L.userName);
            startforStaff();
        }

        break;
    default:
        system("cls");
        if (*vrole == 0)
        {
            printf("Home> Admin> Login> %s> Viewbook>\n", L.userName);
        }
        if (*vrole == 1)
        {
            printf("Home> Staff> Login> %s> Viewbook>\n", L.userName);
        }
        viewBook(vrole);
        break;
    }
}

void viewallbook(int *vrole) //*
{
    FILE *fp;
    fp = fopen("library.txt", "r");
    if (fp == NULL)
    {
        printf("\nNo books found!\n");
        printf("Add books......\n");
        return;
    }

    printf("\n==================== Book List ====================\n");
    printf("%-5s | %-25s | %-20s | %-10s\n", "ID", "Title", "Author", "Status");
    printf("---------------------------------------------------\n");

    while (fscanf(fp, "%d\n%99[^\n]\n%99[^\n]\n%d\n",
                  &B.bookId, B.bookName, B.Author, &B.isIssued) != EOF)
    {
        printf("%-5d | %-25s | %-20s | %-10s\n",
               B.bookId,
               B.bookName,
               B.Author,
               !B.isIssued ? "Available" : "Issued");
    }

    printf("===================================================\n\n");

    fclose(fp);
    printf("\n");
    printf("Press 'Enter' to return to Menu: "); // From book
    getchar();

    system("cls");

    if (*vrole == 0)
    {
        printf("Home> Admin> Login> %s> Viewbook>\n", L.userName);
        viewBook(vrole);
    }

    if (*vrole == 1)
    {
        printf("Home> Staff> Login> %s> Viewbook>\n", L.userName);
        viewBook(vrole);
    }
}

void viewissuedbook(int *vrole) //*
{

    FILE *fp;
    fp = fopen("library.txt", "r");
    if (fp == NULL)
    {
        printf("\nNo books found!\n");
        printf("Add books......\n");
        return;
    }

    printf("\n==================== Issued Books ====================\n");
    printf("%-5s | %-25s | %-20s | %-10s\n", "ID", "Title", "Author", "Status");
    printf("------------------------------------------------------\n");

    while (fscanf(fp, "%d\n%99[^\n]\n%99[^\n]\n%d\n",
                  &B.bookId, B.bookName, B.Author, &B.isIssued) != EOF)
    {
        if (B.isIssued)
        {
            printf("%-5d | %-25s | %-20s | %-10s\n",
                   B.bookId,
                   B.bookName,
                   B.Author,
                   "Issued");
        }
    }

    printf("======================================================\n\n");

    fclose(fp);
    printf("\n");
    printf("Press 'Enter' to return to Menu: "); // From book
    getchar();

    system("cls");

    if (*vrole == 0)
    {
        printf("Home> Admin> Login> %s> Viewbook>\n", L.userName);
        viewBook(vrole);
    }

    if (*vrole == 1)
    {
        printf("Home> Staff> Login> %s> Viewbook>\n", L.userName);
        viewBook(vrole);
    }
}

void viewavailablebook(int *vrole) //*
{
    FILE *fp;
    fp = fopen("library.txt", "r");
    if (fp == NULL)
    {
        printf("\nNo books found!\n");
        printf("Add books......\n");
        return;
    }

    printf("\n==================== Available Books ====================\n");
    printf("%-5s | %-25s | %-20s | %-10s\n", "ID", "Title", "Author", "Status");
    printf("---------------------------------------------------------\n");
    while (fscanf(fp, "%d\n%99[^\n]\n%99[^\n]\n%d\n",
                  &B.bookId, B.bookName, B.Author, &B.isIssued) != EOF)
    {
        if (!B.isIssued)
        {
            printf("%-5d | %-25s | %-20s | %-10s\n",
                   B.bookId,
                   B.bookName,
                   B.Author,
                   "Available");
        }
    }
    printf("=========================================================\n\n");

    fclose(fp);
    printf("\n");
    printf("Press 'Enter' to return to Menu: "); // From book
    getchar();

    system("cls");

    if (*vrole == 0)
    {
        printf("Home> Admin> Login> %s> Viewbook>\n", L.userName);
        viewBook(vrole);
    }

    if (*vrole == 1)
    {
        printf("Home> Staff> Login> %s> Viewbook>\n", L.userName);
        viewBook(vrole);
    }
}

void searchBook(int *srole) //*
{
    int choice;

    printf("\n=== Search Book === \n");
    printf("\n*Search Book by:");
    printf("\n1.Book Id");
    printf("\n2.Book Name");
    printf("\n3.Author");
    printf("\n0.Go Back\n");
    printf("\nYour choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        system("cls");
        if (*srole == 0)
        {
            printf("Home> Admin> Login> %s> Searchbook> Searchbookid>\n", L.userName);
        }
        if (*srole == 1)
        {
            printf("Home> Staff> Login> %s> Searchbook> Searchbookid>\n", L.userName);
        }
        searchBookid(srole);
        break;
    case 2:
        system("cls");
        if (*srole == 0)
        {
            printf("Home> Admin> Login> %s> Searchbook> Searchbookname>\n", L.userName);
        }
        if (*srole == 1)
        {
            printf("Home> Staff> Login> %s> Searchbook> Searchbookname>\n", L.userName);
        }
        searchBookName(srole);
        break;
    case 3:
        system("cls");
        if (*srole == 0)
        {
            printf("Home> Admin> Login> %s> Searchbook> Searchbookauthor>\n", L.userName);
        }
        if (*srole == 1)
        {
            printf("Home> Staff> Login> %s> Searchbook> Searchbookauthor>\n", L.userName);
        }
        searchBookAuthor(srole);
        break;

    case 0:
        system("cls");
        if (*srole == 0)
        {
            printf("Home> Admin> Login> %s>\n", L.userName);
            start();
        }
        if (*srole == 1)
        {
            printf("Home> Staff> Login> %s>\n", L.userName);
            startforStaff();
        }

        break;

    default:
        system("cls");
        if (*srole == 0)
        {
            printf("Home> Admin> Login> %s> Searchbook>\n", L.userName);
        }
        if (*srole == 1)
        {
            printf("Home> Staff> Login> %s> Searchbook>\n", L.userName);
        }
        searchBook(srole);
        break;
    }
}

void searchBookid(int *srole) //*
{
    int id;
    int found = 0;

    FILE *fp;
    fp = fopen("library.txt", "r");
    if (fp == NULL)
    {
        printf("No books found!\n");
        printf("Add books......");
        return;
    }

    printf("\n=== Search Book === \n\n");

    printf("Enter Book id: ");
    scanf("%d", &id);
    getchar();

    while ((fscanf(fp, "%d\n%99[^\n]\n%99[^\n]\n%d\n", &B.bookId, B.bookName, B.Author, &B.isIssued)) != EOF)
    {
        if (B.bookId == id)
        {
            system("cls");

            if (*srole == 0)
            {
                printf("Home> Admin> Login> %s> Searchbook>\n", L.userName);
            }

            if (*srole == 1)
            {
                printf("Home> Staff> Login> %s> Searchbook>\n", L.userName);
            }

            if (B.bookId == id)
            {
                printf("\n=====================================================\n");
                printf("                      Book Found!                     \n");
                printf("=====================================================\n");
                printf("   Book ID   : %d\n", B.bookId);
                printf("   Title     : %s\n", B.bookName);
                printf("   Author    : %s\n", B.Author);
                printf("   Status    : %s\n", B.isIssued ? "Issued" : "Available");
                printf("=====================================================\n\n");
                found = 1;
                break;
            }
        }
    }

    if (!found)
    {
        system("cls");

        if (*srole == 0)
        {
            printf("Home> Admin> Login> %s> Searchbook>\n", L.userName);
        }

        if (*srole == 1)
        {
            printf("Home> Staff> Login> %s> Searchbook>\n", L.userName);
        }

        printf("\n");
        printf("!!Book not found!!");
        printf("\n");
    }

    fclose(fp);

    searchBook(srole);
}

void searchBookName(int *srole) //*
{
    int found = 0;
    char bookName[100];

    FILE *fp;
    fp = fopen("library.txt", "r");
    if (fp == NULL)
    {
        printf("No books found!\n");
        printf("Add books......");
        return;
    }

    printf("\n=== Search Book === \n\n");

    printf("Enter Book Title: ");
    scanf(" %99[^\n]", bookName);

    while ((fscanf(fp, "%d\n%99[^\n]\n%99[^\n]\n%d\n", &B.bookId, B.bookName, B.Author, &B.isIssued)) != EOF)
    {
        if (strcmp(B.bookName, bookName) == 0)
        {
            system("cls");

            if (*srole == 0)
            {
                printf("Home> Admin> Login> %s> Searchbook>\n", L.userName);
            }

            if (*srole == 1)
            {
                printf("Home> Staff> Login> %s> Searchbook>\n", L.userName);
            }

            printf("\n=====================================================\n");
            printf("                   Book Found!                       \n");
            printf("=====================================================\n");
            printf("   Book ID   : %d\n", B.bookId);
            printf("   Title     : %s\n", B.bookName);
            printf("   Author    : %s\n", B.Author);
            printf("   Status    : %s\n", B.isIssued ? "Issued" : "Available");
            printf("=====================================================\n\n");
            found = 1;
        }
    }
    if (!found)
    {
        system("cls");

        if (*srole == 0)
        {
            printf("Home> Admin> Login> %s> Searchbook>\n", L.userName);
        }

        if (*srole == 1)
        {
            printf("Home> Staff> Login> %s> Searchbook>\n", L.userName);
        }

        printf("\n");
        printf("!!Book not found!!");
        printf("\n");
    }

    fclose(fp);

    searchBook(srole);
}

void searchBookAuthor(int *srole) //*
{
    int found = 0;
    char Author[100];

    FILE *fp;
    fp = fopen("library.txt", "r");
    if (fp == NULL)
    {
        printf("No books found!\n");
        printf("Add books......");
        return;
    }

    printf("\n=== Search Book === \n\n");

    printf("Enter Book Author: ");
    scanf(" %99[^\n]", Author);

    system("cls");

    if (*srole == 0)
    {
        printf("Home> Admin> Login> %s> Searchbook>\n", L.userName);
    }

    if (*srole == 1)
    {
        printf("Home> Staff> Login> %s> Searchbook>\n", L.userName);
    }

    while ((fscanf(fp, "%d\n%99[^\n]\n%99[^\n]\n%d\n", &B.bookId, B.bookName, B.Author, &B.isIssued)) != EOF)
    {
        if (strcmp(B.Author, Author) == 0)
        {
            printf("\n=====================================================\n");
            printf("                     Book Found!                     \n");
            printf("=====================================================\n");
            printf("   Book ID   : %d\n", B.bookId);
            printf("   Title     : %s\n", B.bookName);
            printf("   Author    : %s\n", B.Author);
            printf("   Status    : %s\n", B.isIssued ? "Issued" : "Available");
            printf("=====================================================\n\n");
            found = 1;
        }
    }
    if (!found)
    {
        system("cls");

        if (*srole == 0)
        {
            printf("Home> Admin> Login> %s> Searchbook>\n", L.userName);
        }

        if (*srole == 1)
        {
            printf("Home> Staff> Login> %s> Searchbook>\n", L.userName);
        }

        printf("\n");
        printf("!!Book not found!!");
        printf("\n");
    }

    fclose(fp);
    searchBook(srole);
}

void issueBook(int *irole) //*
{
    int id;
    char bookName[100];
    int memId;
    int found = 0;
    int mfound = 0;

    FILE *fp, *temp, *fread;
    fp = fopen("library.txt", "r");

    if (fp == NULL)
    {
        printf("Error: Could not open file.\n");
        return;
    }

    temp = fopen("Temp.txt", "w");

    if (temp == NULL)
    {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("\n=== Issue Book ===\n");

    printf("\n*To Take book from the library S/he should be member of the library...\n");
    printf("\nEnter Member's Id: ");
    scanf("%d", &memId);
    getchar();

    fread = fopen("Member.txt", "r");
    if (fread == NULL)
    {
        printf("There doesn't suppose to be any member.");
        printf("Please make sure there is members in your system....");
        return;
    }

    while (fscanf(fread, "%d\n%99[^\n]\n%d\n", &M.memId, M.memName, &M.memSex) != EOF)
    {
        if (memId == M.memId)
        {
            printf("\n|=================| The member you are about to issue to |=========================================================|\n\n");
            printf("\tID: %d | Name: %s | Sex: %s", M.memId, M.memName, !M.memSex ? "Male" : "Female");
            printf("\n|==================================================================================================================|\n");

            mfound = 1;
            break;
        }
    }

    fclose(fread);

    if (!mfound)
    {
        system("cls");
        printf("Home> Admin> Login> %s>\n", L.userName);
        printf("\nThere is no such member!\n");

        start();
    }

    mfound = 0;

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    while ((fscanf(fp, "%d\n%99[^\n]\n%99[^\n]\n%d\n", &B.bookId, B.bookName, B.Author, &B.isIssued)) != EOF)
    {
        if (B.bookId == id)
        {
            found = 1;

            if (B.isIssued)
            {
                system("cls");

                if (*irole == 0)
                {
                    printf("Home> Admin> Login> %s>\n", L.userName);
                }

                if (*irole == 1)
                {
                    printf("Home> Staff> Login> %s>\n", L.userName);
                }

                printf("\nAlready Issued!!\n");
                fprintf(temp, "%d\n%s\n%s\n%d\n", B.bookId, B.bookName, B.Author, B.isIssued);
            }
            else
            {
                B.isIssued = 1;
                fprintf(temp, "%d\n%s\n%s\n%d\n", B.bookId, B.bookName, B.Author, B.isIssued);

                system("cls");

                if (*irole == 0)
                {
                    printf("Home> Admin> Login> %s>\n", L.userName);
                }

                if (*irole == 1)
                {
                    printf("Home> Staff> Login> %s>\n", L.userName);
                }
                printf("\nBook issued successfully!!\n");
            }
        }
        else
        {
            fprintf(temp, "%d\n%s\n%s\n%d\n", B.bookId, B.bookName, B.Author, B.isIssued);
        }
    }

    if (!found)
    {
        system("cls");

        if (*irole == 0)
        {
            printf("Home> Admin> Login> %s>\n", L.userName);
        }

        if (*irole == 1)
        {
            printf("Home> Staff> Login> %s>\n", L.userName);
        }

        printf("\n");
        printf("!!Book not found!!");
        printf("\n");
    }

    fclose(fp);
    fclose(temp);

    remove("library.txt");
    rename("Temp.txt", "library.txt");

    if (*irole == 0)
    {
        start();
    }

    if (*irole == 1)
    {
        startforStaff();
    }
}

void returnBook(int *rrole) //*
{
    int id;
    char bookName[100];
    char Name[100];
    int phoneNumber;
    int found = 0;

    FILE *fp, *temp;
    fp = fopen("library.txt", "r");

    if (fp == NULL)
    {
        printf("Error: Could not open file.\n");
        return;
    }

    temp = fopen("Temp.txt", "w");

    if (temp == NULL)
    {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("\n=== Return Book ===\n");

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    while ((fscanf(fp, "%d\n%99[^\n]\n%99[^\n]\n%d\n", &B.bookId, B.bookName, B.Author, &B.isIssued)) != EOF)
    {
        if (B.bookId == id)
        {
            found = 1;

            if (!B.isIssued)
            {
                system("cls");
                if (*rrole == 0)
                {
                    printf("Home> Admin> Login> %s>\n", L.userName);
                }
                if (*rrole == 1)
                {
                    printf("Home> Staff> Login> %s>\n", L.userName);
                }
                printf("\nAlready Returned!!\n");
                fprintf(temp, "%d\n%s\n%s\n%d\n", B.bookId, B.bookName, B.Author, B.isIssued);
            }
            else
            {
                B.isIssued = 0;
                fprintf(temp, "%d\n%s\n%s\n%d\n", B.bookId, B.bookName, B.Author, B.isIssued);

                system("cls");
                if (*rrole == 0)
                {
                    printf("Home> Admin> Login> %s>\n", L.userName);
                }
                if (*rrole == 1)
                {
                    printf("Home> Staff> Login> %s>\n", L.userName);
                }
                printf("\nBook Returned successfully!!\n");
            }
        }
        else
        {
            fprintf(temp, "%d\n%s\n%s\n%d\n", B.bookId, B.bookName, B.Author, B.isIssued);
        }
    }

    if (!found)
    {
        system("cls");
        if (*rrole == 0)
        {
            printf("Home> Admin> Login> %s>\n", L.userName);
        }
        if (*rrole == 1)
        {
            printf("Home> Staff> Login> %s>\n", L.userName);
        }
        printf("\n");
        printf("!!Book not found!!");
        printf("\n");
    }

    fclose(fp);
    fclose(temp);

    remove("library.txt");
    rename("Temp.txt", "library.txt");

    if (*rrole == 0)
    {
        start();
    }
    if (*rrole == 1)
    {
        startforStaff();
    }
}

void updateBook() //*
{
    int choice;
    int bookId;
    int found = 0;

    printf("\n=== Update Book Details ===\n");
again:
    printf("\n*Give the 'ID' of the book yoo want to update.\n");

    printf("\nEnter Book id: ");
    scanf("%d", &bookId);
    getchar();

    system("cls");

    FILE *scan;
wrong:
    scan = fopen("library.txt", "r");

    while ((fscanf(scan, "%d\n%99[^\n]\n%99[^\n]\n%d\n", &B.bookId, B.bookName, B.Author, &B.isIssued)) != EOF)
    {
        if (bookId == B.bookId)
        {
            printf("Home> Admin> Login> %s> Updatebook>\n", L.userName);
            printf("\n|=================| The book you are about to update |===============================================================|\n\n");
            printf("\tID: %d | Title: %s | Author: %s | Status: %s", B.bookId, B.bookName, B.Author, !B.isIssued ? "Available" : "Issued");
            printf("\n|==================================================================================================================|\n");

            found = 1;
        }
    }

    fclose(scan);

    if (!found)
    {
        system("cls");
        printf("Home> Admin> Login> %s>\n", L.userName);
        printf("\n--- Book id '%d' not Found! ---\n", bookId);

        found = 0;

        start();
    }

    printf("\n|1.Update Book id|");
    printf("\n|2.Update Book Title|");
    printf("\n|3.Update Author|");
    printf("\n|0.Go back|\n");
    printf("\nYour choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        Uupbookid(bookId);
        break;

    case 2:
        Uupbooktitle(bookId);
        break;

    case 3:
        Uupbookauthor(bookId);
        break;

    case 0:
        system("cls");
        printf("Home> Admin> Login> %s>\n", L.userName);
        start();
        break;

    default:
        system("cls");
        goto wrong;
        break;
    }
}

void Uupbookid(int bookId) //*
{
    int newbookId;
    int exists = 0;

    int found = 0;

    FILE *read, *temp;

    read = fopen("library.txt", "r");
    if (read == NULL)
    {
        printf("Can't locate File....");
        return;
    }

    temp = fopen("Update.txt", "w");
    if (temp == NULL)
    {
        printf("File NOT OPENING....");
        return;
    }

    while ((fscanf(read, "%d\n%99[^\n]\n%99[^\n]\n%d\n", &B.bookId, B.bookName, B.Author, &B.isIssued)) != EOF)
    {
        if (bookId == B.bookId)
        {

        again:

            printf("\nEnter new Book id: ");
            scanf("%d", &newbookId);
            getchar();

            FILE *check = fopen("library.txt", "r");

            if (check == NULL)
            {
                printf("File NOT OPENING....");
                return;
            }

            while ((fscanf(check, "%d\n%99[^\n]\n%99[^\n]\n%d\n", &T.bookId, T.bookName, T.Author, &T.isIssued)) != EOF)
            {
                if (newbookId == T.bookId)
                {
                    printf("\n=== Book Id already exist! ===\n");
                    printf("Enter another Id.....\n");

                    exists = 1;
                    break;
                }
            }

            fclose(check);

            if (exists)
            {
                exists = 0;
                goto again;
            }

            fprintf(temp, "%d\n%s\n%s\n%d\n", newbookId, B.bookName, B.Author, B.isIssued);
            found = 1;
        }
        else
        {
            fprintf(temp, "%d\n%s\n%s\n%d\n", B.bookId, B.bookName, B.Author, B.isIssued);
        }
    }
    fclose(read);
    fclose(temp);

    remove("library.txt");
    rename("Update.txt", "library.txt");

    if (found)
    {
        system("cls");

        printf("Home> Admin> Login> %s>\n", L.userName);
        printf("\nBook Updated Successfully.......\n");

        FILE *check;
        check = fopen("library.txt", "r");

        if (check == NULL)
        {
            printf("Message might be error.");
        }

        while ((fscanf(check, "%d\n%99[^\n]\n%99[^\n]\n%d\n", &B.bookId, B.bookName, B.Author, &B.isIssued)) != EOF)
        {
            if (newbookId == B.bookId)
            {
                printf("\n|========== Result ================================================================================================|\n");
                printf("\tID: %d | Title: %s | Author: %s | Status: %s", B.bookId, B.bookName, B.Author, !B.isIssued ? "Available" : "Issued");
                printf("\n|==================================================================================================================|\n");
                break;
            }
        }

        fclose(check);

        start();
    }
}

void Uupbooktitle(int bookId) //*
{
    char newBookName[100];
    int exists = 0;

    int found = 0;

    FILE *read, *temp;

    read = fopen("library.txt", "r");
    if (read == NULL)
    {
        printf("Can't locate File....");
        return;
    }

    temp = fopen("Update.txt", "w");
    if (temp == NULL)
    {
        printf("File NOT OPENING....");
        return;
    }

    printf("\nEnter New Book Name: ");
    scanf("%99[^\n]", newBookName);
    getchar();

    while ((fscanf(read, "%d\n%99[^\n]\n%99[^\n]\n%d\n", &B.bookId, B.bookName, B.Author, &B.isIssued)) != EOF)
    {
        if (bookId == B.bookId)
        {

            fprintf(temp, "%d\n%s\n%s\n%d\n", B.bookId, newBookName, B.Author, B.isIssued);
            found = 1;
        }
        else
        {
            fprintf(temp, "%d\n%s\n%s\n%d\n", B.bookId, B.bookName, B.Author, B.isIssued);
        }
    }
    fclose(read);
    fclose(temp);

    remove("library.txt");
    rename("Update.txt", "library.txt");

    if (found)
    {
        system("cls");

        printf("Home> Admin> Login> %s>\n", L.userName);
        printf("\nBook Updated Successfully.......\n");

        FILE *check;
        check = fopen("library.txt", "r");

        if (check == NULL)
        {
            printf("Message might be error.");
        }

        while ((fscanf(check, "%d\n%99[^\n]\n%99[^\n]\n%d\n", &B.bookId, B.bookName, B.Author, &B.isIssued)) != EOF)
        {
            if (bookId == B.bookId)
            {
                printf("\n|========== Result ================================================================================================|\n");
                printf("\tID: %d | Title: %s | Author: %s | Status: %s", B.bookId, B.bookName, B.Author, !B.isIssued ? "Available" : "Issued");
                printf("\n|==================================================================================================================|\n");
                break;
            }
        }

        fclose(check);

        start();
    }
}

void Uupbookauthor(int bookId) //*
{
    char newAuthor[100];
    int exists = 0;

    int found = 0;

    FILE *read, *temp;

    read = fopen("library.txt", "r");
    if (read == NULL)
    {
        printf("Can't locate File....");
        return;
    }

    temp = fopen("Update.txt", "w");
    if (temp == NULL)
    {
        printf("File NOT OPENING....");
        return;
    }

    printf("\nEnter New Book Author: ");
    scanf("%99[^\n]", newAuthor);
    getchar();

    while ((fscanf(read, "%d\n%99[^\n]\n%99[^\n]\n%d\n", &B.bookId, B.bookName, B.Author, &B.isIssued)) != EOF)
    {
        if (bookId == B.bookId)
        {

            fprintf(temp, "%d\n%s\n%s\n%d\n", B.bookId, B.bookName, newAuthor, B.isIssued);
            found = 1;
        }
        else
        {
            fprintf(temp, "%d\n%s\n%s\n%d\n", B.bookId, B.bookName, B.Author, B.isIssued);
        }
    }
    fclose(read);
    fclose(temp);

    remove("library.txt");
    rename("Update.txt", "library.txt");

    if (found)
    {
        system("cls");

        printf("Home> Admin> Login> %s>\n", L.userName);
        printf("\nBook Updated Successfully.......\n");

        FILE *check;
        check = fopen("library.txt", "r");

        if (check == NULL)
        {
            printf("Message might be error.");
        }

        while ((fscanf(check, "%d\n%99[^\n]\n%99[^\n]\n%d\n", &B.bookId, B.bookName, B.Author, &B.isIssued)) != EOF)
        {
            if (bookId == B.bookId)
            {
                printf("\n|========== Result ================================================================================================|\n");
                printf("\tID: %d | Title: %s | Author: %s | Status: %s", B.bookId, B.bookName, B.Author, !B.isIssued ? "Available" : "Issued");
                printf("\n|==================================================================================================================|\n");
                break;
            }
        }

        fclose(check);

        start();
    }
}

void deleteBook() //*
{
    int bookId;
    char choice;
    int found = 0;
    int seek = 0;

    FILE *f, *temp;

    f = fopen("library.txt", "r");
    if (f == NULL)
    {
        printf("Can't locate File....");
        return;
    }

    temp = fopen("Delete.txt", "w");
    if (temp == NULL)
    {
        printf("File NOT OPENING....");
        return;
    }

    printf("\n=== Delete book ===\n");

    printf("\nEnter Book id: ");
    scanf("%d", &bookId);
    getchar();

    while ((fscanf(f, "%d\n%99[^\n]\n%99[^\n]\n%d\n", &B.bookId, B.bookName, B.Author, &B.isIssued)) != EOF)
    {
        if (bookId == B.bookId)
        {
            system("cls");
            printf("Home> Admin> Login> %s> Deletebook>\n", L.userName);

            printf("\n--- Warning! ---\n");
            printf("\n|=================| The book you are about to 'Delete' |===========================================================|\n\n");
            printf("\tID: %d | Title: %s | Author: %s | Status: %s", B.bookId, B.bookName, B.Author, !B.isIssued ? "Available" : "Issued");
            printf("\n|==================================================================================================================|\n");

            printf("\nDo you want to delete this book?(y/n): ");
            scanf("%c", &choice);

            if (choice == 'y' || choice == 'Y')
            {
                found = 1;
            }
            else
            {
                fprintf(temp, "%d\n%s\n%s\n%d\n", B.bookId, B.bookName, B.Author, B.isIssued);
                seek = 1;
            }
        }
        else
        {
            fprintf(temp, "%d\n%s\n%s\n%d\n", B.bookId, B.bookName, B.Author, B.isIssued);
        }
    }

    fclose(f);
    fclose(temp);

    remove("library.txt");
    rename("Delete.txt", "library.txt");

    if (found)
    {
        system("cls");
        printf("Home> Admin> Login> %s>\n", L.userName);
        printf("\nBook Deleted Successfully.......\n");

        start();
    }

    if (seek)
    {
        system("cls");
        printf("Home> Admin> Login> %s>\n", L.userName);
        printf("\nBook Not Deleted.......\n");

        start();
    }

    if (!found)
    {
        system("cls");
        printf("Home> Admin> Login> %s>\n", L.userName);
        printf("\nBook id '%d' not Found!\n", bookId);

        start();
    }
}

void helpBook(int *hrole) //*
{
    int choice;
    printf("\n=== Help ===\n");

    printf("\n|1.Manual|");
    printf("\n|0.Go back|\n");
    printf("\nYour choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        system("cls");
        if (*hrole == 0)
        {
            printf("Home> Admin> Login> %s> Help> Manual>\n", L.userName);
        }
        if (*hrole == 1)
        {
            printf("Home> Staff> Login> %s> Help> Manual>\n", L.userName);
        }
        manual(hrole);
        break;

    case 0:
        system("cls");
        if (*hrole == 0)
        {
            printf("Home> Admin> Login> %s>\n", L.userName);
            start();
        }
        if (*hrole == 1)
        {
            printf("Home> Staff> Login> %s>\n", L.userName);
            startforStaff();
        }

        break;

    default:
        system("cls");
        if (*hrole == 0)
        {
            printf("Home> Admin> Login> %s> Help>\n", L.userName);
        }
        if (*hrole == 1)
        {
            printf("Home> Staff> Login> %s> Help>\n", L.userName);
        }
        helpBook(hrole);
        break;
    }
}

void manual(int *hrole) //*
{
    printf("\n=== Manual ===\n");

    printf("\nThis manual explains the functions available in the system:\n");

    if (*hrole == 0)
    {
        printf("\n0. | Add Book |\n");
        printf("   - Allows you to add a new book to the library database.\n");
        printf("   - You will need to provide details such as Bookid, title, author.\n");
    }

    printf("\n1. | View All Books |\n");
    printf("   - Displays a list of all books currently stored in the system.\n");
    printf("   - Useful for browsing the collection or checking availability.\n");

    printf("\n2. | Search Book |\n");
    printf("   - Enables you to search for a specific book by Bookid, title, author.\n");
    printf("   - Helps quickly locate a book in the library.\n");

    printf("\n3. | Issue Book |\n");
    printf("   - Allows staff to issue a book to a member.\n");

    printf("\n4. | Return Book |\n");
    printf("   - Used when a member returns a borrowed book.\n");
    printf("   - Updates the system to mark the book as available again.\n");

    if (*hrole == 0)
    {
        printf("\n5. | Update Book |\n");
        printf("   - Lets you edit details of an existing book.\n");
        printf("   - Useful for correcting errors or updating information.\n");

        printf("\n6. | Delete Book |\n");
        printf("   - Removes a book from the library database.\n");
        printf("   - Should be used carefully to avoid accidental data loss.\n ");
    }

    printf("\nPress 'Enter' to go back:>> ");
    getchar();

    system("cls");
    if (*hrole == 0)
    {
        printf("Home> Admin> Login> %s> Help>\n", L.userName);
    }
    if (*hrole == 1)
    {
        printf("Home> Staff> Login> %s> Help>\n", L.userName);
    }
    helpBook(hrole);
}

void aboutus(int *arole) //*
{
    printf("\n=== About Us ===\n");

    printf("\nThis is the project (Library Management System) made by Sushan Gwachha.\n");
    printf("\nPress 'Enter' to go back: ");
    getchar();

    system("cls");

    if (*arole == 0)
    {
        printf("Home> Admin> Login> %s>\n", L.userName);
        start();
    }
    if (*arole == 1)
    {
        printf("Home> Staff> Login> %s>\n", L.userName);
        startforStaff();
    }
    if (*arole == 46)
    {
        printf("Home>\n");
        whoareyou();
    }
}

void exitProgram(int *erole) //*
{
    int choice;
    char exi;

    printf("\n=== Exit ===\n");

    printf("\n|1.go back|");
    printf("\n|2.Log out|");
    printf("\n|3.Exit Program|\n");
    printf("\nYour Choice: ");
    scanf("%d", &choice);
    getchar();

    switch (choice)
    {
    case 1:
        system("cls");
        if (*erole == 0)
        {
            printf("Home> Admin> Login> %s>\n", L.userName);
            start();
        }
        if (*erole == 1)
        {
            printf("Home> Staff> Login> %s>\n", L.userName);
            startforStaff();
        }

        break;

    case 2:
        system("cls");
        printf("Home>\n");
        whoareyou();
        break;

    case 3:
        system("cls");
        printf("Program Exited....\n");
        printf("\nBYE BYE......");
        exit(0);
        break;

    default:
        printf("\nPress 'Enter' to Exit the program / 'n' to go back: ");
        scanf("%c", &exi);

        if (exi == 'y' || exi == 'Y' || exi == '\n')
        {
            system("cls");
            printf("Program Exited....\n");
            printf("\nBYE BYE......");
            exit(0);
        }
        else
        {
            system("cls");
            if (*erole == 0)
            {
                printf("Home> Admin> Login> %s>\n", L.userName);
                start();
            }
            if (*erole == 1)
            {
                printf("Home> Staff> Login> %s>\n", L.userName);
                startforStaff();
            }
        }
        break;
    }
}