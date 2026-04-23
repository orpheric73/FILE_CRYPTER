#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<math.h>
#include<io.h>
extern int ani;
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
void Animation();
int PermuteDataInFile(FILE*, int, int);
int Copy_File(FILE *, FILE *);
int FileExistanceChecking(char *);
void show_message_async(const char *, const char *);
