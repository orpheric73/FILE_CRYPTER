#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
extern int ani;
extern int lge;
void TypingEffect(char *);
void DynamicColor();
void LoadingEffect();
int LeapYearChecking(int);
int NumberOfDaysInMonth(int, int);
void HomeOrMenu(int);
void DayOfWeek(char*, int, int);
int InputNumberOfFile();
char AskForSamePasswordUse();
void InputPassword(char *);
int InputVersion();
void SecurityLevel(char *);
void AskForAnimation();
void LanguageChosing(int);
int PermuteDataInFile(FILE*, long, int);
int FileCopyMaker(FILE *, FILE *);
int FileExistanceChecker(char *);
void IndependentMessageBox(const char *, const char *);
void MatrixSimulation();
void Info(int);
DWORD WINAPI msg_thread(LPVOID param);
BOOL WINAPI ConsoleHandler(DWORD signal);
