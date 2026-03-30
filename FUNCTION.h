#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>
#include<math.h>
#ifdef _WIN32
    #include<direct.h>
    #define MKDIR(PATH) _mkdir(PATH)
    #define SEP '\\'
#else
    #include<sys/stat.h>
    #define MKDIR(PATH) mkdir(PATH,0777)
    #define SEP '/'
#endif
//SI UN NE SOUVRE SAUTER(fol)
typedef struct{
    FILE *fl;
    FILE *flo;
    char *ney1;
    char *ney2;
    char *ney;
    char *neyp;
    char paswd[11];
    int paswdi[10];
    int v;
}crypt;
void type_effect(char *);
void color_change1();
void loading();
int isLeapYear(int);
int GetDaysInMonth(int, int);
void home(int);
char* DayOfWeek(int, int);
int NumbOfFile();
char SamePasswd();
void PasswdInp(char *);
int VerInp();
void SecureLevel(char *);
