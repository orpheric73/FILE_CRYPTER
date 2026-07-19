/*
 * FILE_CRYPTER
 * Author: Orphéric SANGNIDJO
 *
 * Copyright (c) 2026 Orphéric SANGNIDJO
 *
 * This source code is part of the FILE_CRYPTER project.
 * See the LICENSE file for license information.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<winsock2.h>
#include<ws2tcpip.h>
#include<windows.h>
#include<stdint.h>
#define BUFFER_SIZE 4096
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
void RemoveFile(char *);
DWORD WINAPI msg_thread(LPVOID param);
BOOL WINAPI ConsoleHandler(DWORD signal);
int SendAll(SOCKET, const void *, size_t);
int RecvAll(SOCKET, void *, size_t);
int SendFile(SOCKET, FILE *, uint64_t);
int RecvFile(SOCKET, FILE *, uint64_t);
