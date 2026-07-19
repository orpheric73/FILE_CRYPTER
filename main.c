/*
 * FILE_CRYPTER
 * Author: Orphéric SANGNIDJO
 *
 * Copyright (c) 2026 Orphéric SANGNIDJO
 *
 * This source code is part of the FILE_CRYPTER project.
 * See the LICENSE file for license information.
 */
#include"FUNCTION.h"
#include <shellapi.h>
#include <shlobj.h>
#ifdef _WIN32
    #include<direct.h>
    #define MKDIR(PATH) _mkdir(PATH)
    #define SEP '\\'
#else
    #include<sys/stat.h>
    #define MKDIR(PATH) mkdir(PATH,0777)
    #define SEP '/'
#endif
typedef struct{
    FILE *InputFile;
    FILE *OutputFile;
    char *InputFileName;
    char *OutputFileName;
    char Password[11];
    int Key[10];
    int v;
}crypt;
int main(){
    system("color 0A && title FILE_CRYPTER");
    int MODE, con, clb, lan, res=1;
    HWND hwnd = GetConsoleWindow();
    HICON icon = LoadIcon(
        GetModuleHandleA(NULL),
        MAKEINTRESOURCE(1)
    );
    if(hwnd && icon){
        SetClassLongPtrA(hwnd, GCLP_HICON, (LONG_PTR)icon);
        SetClassLongPtrA(hwnd, GCLP_HICONSM, (LONG_PTR)icon);

        SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)icon);
        SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)icon);

        DrawMenuBar(hwnd);
    }
    LANGID lang;
    lang = GetUserDefaultUILanguage();
    if(PRIMARYLANGID(lang) == LANG_FRENCH){
        lan=0;
    }
    else{
        lan=1;
    }
    LanguageChosing(lan);
    AskForAnimation();
    HKEY hKey;
    LONG ret;
    DWORD disposition;
    ret = RegCreateKeyExA(
        HKEY_CURRENT_USER,
        "Software\\Classes\\.cflow",
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,
        KEY_WRITE,
        NULL,
        &hKey,
        &disposition
    );
    if(ret != ERROR_SUCCESS){
        if(lge==1){
            TypingEffect("\n[ ERROR ] ERROR CREATING KEY .cflow");
        }
        else{
            TypingEffect("\n[ ERROR ] ERREUR LORS DE LA CREATION DE LA CLE .cflow");
        }
        Sleep(3000);
        return 1;
    }
    if(disposition == REG_CREATED_NEW_KEY){
        const char *type = "CipherFlow.File";
        RegSetValueExA(
            hKey,
            NULL,
            0,
            REG_SZ,
            (const BYTE *)type,
            (DWORD)(strlen(type) + 1)
        );
    }
    RegCloseKey(hKey);
    ret = RegCreateKeyExA(
        HKEY_CURRENT_USER,
        "Software\\Classes\\CipherFlow.File",
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,
        KEY_WRITE,
        NULL,
        &hKey,
        &disposition
    );
    if(ret != ERROR_SUCCESS){
        if(lge==1){
            TypingEffect("\n[ ERROR ] ERROR CREATING KEY CipherFlow.File");
        }
        else{
            TypingEffect("\n[ ERROR ] ERREUR LORS DE LA CREATION DE LA CLE CipherFlow.File");
        }
        Sleep(3000);
        return 1;
    }
    if(disposition == REG_CREATED_NEW_KEY){
        const char *description = "CipherFlow Encrypted File";
        RegSetValueExA(
            hKey,
            NULL,
            0,
            REG_SZ,
            (const BYTE *)description,
            (DWORD)(strlen(description) + 1)
        );
    }
    RegCloseKey(hKey);
    char exePath[MAX_PATH];
    char iconPath[MAX_PATH + 3];
    if(GetModuleFileNameA(NULL, exePath, MAX_PATH) == 0){
        if(lge==1){
            printf("\n[ ERROR ] ERROR GETTING FILENAME : %lu",GetLastError());
        }
        else{
            printf("\n[ ERROR ] ERREUR D'OBTENTION DU NOM DE L'EXE : %lu.", GetLastError());
        }
        Sleep(3000);
        return 1;
    }
    snprintf(iconPath, sizeof(iconPath), "%s,0", exePath);
    ret = RegCreateKeyExA(
        HKEY_CURRENT_USER,
        "Software\\Classes\\CipherFlow.File\\DefaultIcon",
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,
        KEY_WRITE,
        NULL,
        &hKey,
        &disposition
    );
    if(ret != ERROR_SUCCESS){
        if(lge==1){
            printf("\n[ ERROR ] ERROR CREATING DEFAULT ICON : %ld", ret);
        }
        else{
            printf("\n[ ERROR ] ERREUR DE CREATION DE L'ICONE PAR DEFAUT : %ld.", ret);
        }
        Sleep(3000);
        return 1;
    }
    RegSetValueExA(
        hKey,
        NULL,
        0,
        REG_SZ,
        (const BYTE *)iconPath,
        (DWORD)(strlen(iconPath) + 1)
    );
    RegCloseKey(hKey);
    ret = RegCreateKeyExA(
        HKEY_CURRENT_USER,
        "Software\\Classes\\CipherFlow.File\\shell\\open\\command",
        0,
        NULL,
        0,
        KEY_WRITE,
        NULL,
        &hKey,
        &disposition
    );
    if(ret != ERROR_SUCCESS){
        if(lge==1){
            printf("\n[ ERROR ] ERROR CREATING DEFAULT APP : %ld", ret);
        }
        else{
            printf("\n[ ERROR ] ERREUR DE CREATION DE L'APP PAR DEFAUT : %ld.", ret);
        }
        Sleep(3000);
        return 1;
    }
    RegSetValueExA(
        hKey,
        NULL,
        0,
        REG_SZ,
        (const BYTE *)exePath,
        (DWORD)(strlen(exePath) + 1)
    );
    RegCloseKey(hKey);
    ret = RegCreateKeyExA(
        HKEY_CURRENT_USER,
        "Software\\Classes\\*\\shell\\Open with CipherFlow",
        0,
        NULL,
        0,
        KEY_WRITE,
        NULL,
        &hKey,
        NULL
    );
    if(ret != ERROR_SUCCESS){
        if(lge==1){
            printf("\n[ ERROR ] ERROR CREATING MENU : %ld", ret);
        }
        else{
            printf("\n[ ERROR ] ERREUR DE CREATION DU MENU %ld.", ret);
        }
        Sleep(3000);
        return 1;
    }
    RegSetValueExA(
        hKey,
        NULL,
        0,
        REG_SZ,
        (const BYTE *)"Open with CipherFlow",
        (DWORD)(strlen("Open with CipherFlow") + 1)
    );
    RegSetValueExA(
        hKey,
        "Icon",
        0,
        REG_SZ,
        (const BYTE *)iconPath,
        (DWORD)(strlen(iconPath) + 1)
    );
    RegCloseKey(hKey);
    ret = RegCreateKeyExA(
        HKEY_CURRENT_USER,
        "Software\\Classes\\*\\shell\\Open with CipherFlow\\command",
        0,
        NULL,
        0,
        KEY_WRITE,
        NULL,
        &hKey,
        NULL
    );
    if(ret != ERROR_SUCCESS){
        if(lge==1){
            printf("\n[ ERROR ] ERROR CREATING COMMAND : %ld", ret);
        }
        else{
            printf("\n[ ERROR ] ERREUR DE CREATION DE LA COMMANDE %ld.", ret);
        }
        Sleep(3000);
        return 1;
    }
    char command[MAX_PATH + 10];
    sprintf(command, "\"%s\"", exePath);
    RegSetValueExA(
        hKey,
        NULL,
        0,
        REG_SZ,
        (BYTE *)command,
        (DWORD)(strlen(command) + 1)
    );
    RegCloseKey(hKey);
    SHChangeNotify(
        SHCNE_ASSOCCHANGED,
        SHCNF_IDLIST,
        NULL,
        NULL
    );
    HomeOrMenu(0);
    SetConsoleCtrlHandler(ConsoleHandler, TRUE);
    while (res==1){
        res=0;
        do{
            con=1;
            HomeOrMenu(1);
            if(scanf("%d",&MODE) != 1){
                if(lge==1){
                    TypingEffect("\n[ ERROR ] ENTER A NUMBER BETWEEN 1 AND 7");
                }
                else{
                    TypingEffect("\n[ ERROR ] ENTRER UN NOMBRE ENTRE 1 ET 7");
                }
                while((clb=getchar()) != '\n' && clb != EOF);
                con=0;
            }
            printf("\n\n");
        }while(con!=1 || (MODE<1 || MODE>7));
        if(MODE==1 || MODE==3){
            if(MODE==1){
                if(lge==1){
                    TypingEffect("###########################################      1-> ENCRYPT FILE        ###############################################");
                    printf("\n");
                }
                else{
                    TypingEffect("#########################################   1-> CHIFFRER UN/DES FICHIER(S)   ###########################################");
                    printf("\n");
                }
            }
            else{
                if(lge==1){
                    TypingEffect("###########################################   3-> SCHEDULE ENCRYPTION    ###############################################");
                    printf("\n");
                }
                else{
                    TypingEffect("#########################################  3-> PLANIFIER UN CHIFFREMENT      ###########################################");
                    printf("\n");
                }
            }
            if(ani==1){
                DynamicColor();
            }
            int nb, K, I, c, S, M, H, h, m, s, y, mo, d, dw, Md, result, remo, Hf, i, prmr, me;
            long pv;
            char dwn[11], ehou[3];
            char rmdec;
            if(MODE==3){
                if(lge==1){
                    printf("\n");
                    TypingEffect("==================================================  ENCRYPTION TIMER  ==================================================");
                    printf("\n");
                }
                else{
                    printf("\n");
                    TypingEffect("================================================= TIMER DE CHIFFREMENT =================================================");
                    printf("\n");
                }
                if(lge==1){
                    printf("\nSET DELAY BEFORE SCHEDULED ENCRYPTION(TURNING THE DEVICE OFF WILL DELETE THE PROCESS)");
                }
                else{
                    printf("\nDEFINIR LE DELAI AVANT LE CHIFFREMENT PROGRAMMEE(ETEINDRE L'APPAREIL SUPPRIMERA LE PROCESSUS)");
                }
                do{
                    con=1;
                    printf("\ncipherflow> H: ");
                    if(scanf("%d",&H)!=1){
                        if(lge==1){
                            printf("\n[ ERROR ] ENTER A VALID NUMBER");
                        }
                        else{
                            printf("\n[ ERROR ] ENTRER UN NOMBRE VALIDE");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                        H=0;
                        M=0;
                        S=0;
                        continue;
                    }
                    printf("\ncipherflow> M: ");
                    if(scanf("%d",&M)!=1){
                        if(lge==1){
                            printf("\n[ ERROR ] ENTER A VALID NUMBER");
                        }
                        else{
                            printf("\n[ ERROR ] ENTRER UN NOMBRE VALIDE");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                        M=0;
                        S=0;
                        continue;
                    }
                    printf("\ncipherflow> S: ");
                    if(scanf("%d",&S)!=1){
                        if(lge==1){
                            printf("\n[ ERROR ] ENTER A VALID NUMBER");
                        }
                        else{
                            printf("\n[ ERROR ] ENTRER UN NOMBRE VALIDE");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                        S=0;
                        continue;
                    }
                    if(lge==1){
                        printf("\n");
                        TypingEffect("ENCRYPTION SCHEDULED IN");
                        printf(" %d ",H);
                        TypingEffect("HOUR(S)");
                        printf(" %d ",M);
                        TypingEffect("MINUTE(S)");
                        printf(" %d ",S);
                        TypingEffect("SECOND(S)");
                        printf("\nENTER 1 TO CONFIRM");
                    }
                    else{
                        printf("\n");
                        TypingEffect("CHIFFREMENT PREVU DANS");
                        printf(" %d ",H);
                        TypingEffect("HEURE(S)");
                        printf(" %d ",M);
                        TypingEffect("MINUTE(S)");
                        printf(" %d ",S);
                        TypingEffect("SECONDE(S)");
                        printf("\nENTRER 1 POUR CONFIRMER");
                    }
                    printf("\ncipherflow> ");
                    if(scanf("%d",&con)!=1){
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                    }
                }while(con!=1 || (H<0 || M<0 || S<0));
                SYSTEMTIME st;
                GetLocalTime(&st);
                y=st.wYear;
                mo=st.wMonth;
                d=st.wDay;
                dw=st.wDayOfWeek;
                h=st.wHour;
                m=st.wMinute;
                s=st.wSecond;
                H=H+h;
                M=M+m;
                S=S+s;
                while(S>59){
                    S-=60;
                    M+=1;
                }
                while(M>59){
                    M-=60;
                    H+=1;
                }
                while(H>23){
                    H-=24;
                    d+=1;
                    dw+=1;
                }
                while(d>(Md=NumberOfDaysInMonth(mo, y))){
                    d-=(Md=NumberOfDaysInMonth(mo, y));
                    mo+=1;
                }
                while(mo>12){
                    mo-=12;
                    y+=1;
                }
                dw=(dw%7);
                DayOfWeek(dwn, dw, lan);
                if(lan==1){
                    Hf=H;
                    if(H>11){
                        strcpy(ehou,"PM");
                    }
                    else{
                        strcpy(ehou,"AM");
                    }
                    H=(H%12);
                    if(H==0){
                        H=12;
                    }
                }
            }
            if(MODE==1){
                nb=InputNumberOfFile();
            }
            else{
                nb=1;
            }
            if(nb>1){
                rmdec=AskForSamePasswordUse();
            }
            else{
                rmdec='N';
            }
            int mdec=1;
            crypt *crt;
            crt=(crypt *)calloc(nb,sizeof(crypt));
            if(crt==NULL){
                if(lge==1){
                    printf("\n[ ERROR ] ALLOCATION ERROR");
                    MessageBeep(MB_ICONHAND);
                    MessageBox(NULL, "[ ERROR ] ALLOCATING MEMORY SPACE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                }
                else{
                    printf("\n[ ERROR ] ERREUR D'ALLOCATION");
                    MessageBeep(MB_ICONHAND);
                    MessageBox(NULL, "[ ERROR ] ALLOCATION D'ESPACE MEMOIRE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                }
                return 1;
            }
            for(K=0;K<nb;K++){
                if(lge==1){
                    printf("\n");
                    TypingEffect("===================================================  FILE SELECTION  ===================================================");
                    printf("\n");
                }
                else{
                    printf("\n");
                    TypingEffect("================================================= SELECTION DU FICHIER =================================================");
                    printf("\n");
                }
                do{
                    con=1;
                    crt[K].InputFileName=calloc(200,sizeof(char));
                    if(crt[K].InputFileName==NULL){
                        if(lge==1){
                            printf("\n[ ERROR ] ALLOCATION ERROR");
                            free(crt);
                            MessageBeep(MB_ICONHAND);
                            MessageBox(NULL, "[ ERROR ] ALLOCATING MEMORY SPACE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        else{
                            printf("\n[ ERROR ] ERREUR D'ALLOCATION");
                            free(crt);
                            MessageBeep(MB_ICONHAND);
                            MessageBox(NULL, "[ ERROR ] ALLOCATION D'ESPACE MEMOIRE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        return 1;
                    }
                    if(lge==1){
                        printf("\nENTER THE FULL PATH OF THE FILE OR DRAG AND DROP IT HERE");
                    }
                    else{
                        printf("\nENTRER LE CHEMIN COMPLET DU FICHIER OU GLISSER ET DEPOSER LE FICHIER ICI");
                    }
                    printf("\ncipherflow> ");
                    if(scanf(" %199[^\n]",crt[K].InputFileName) != 1){
                        if(lge==1){
                            printf("\n[ ERROR ] ENTER A VALID PATH");
                        }
                        else{
                            printf("\n[ ERROR ] ENTRER UN CHEMIN VALIDE");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                    }
                    while((clb=getchar()) != '\n' && clb != EOF);
                    if(crt[K].InputFileName[0]== '\'' || crt[K].InputFileName[0]== '\"' ){
                        memmove(crt[K].InputFileName, crt[K].InputFileName + 1, strlen(crt[K].InputFileName)+1);
                    }
                    if(crt[K].InputFileName[strlen(crt[K].InputFileName)-1]== '\'' || crt[K].InputFileName[strlen(crt[K].InputFileName)-1]== '\"' ){
                        crt[K].InputFileName[strlen(crt[K].InputFileName)-1]='\0';
                    }
                    if(con!=0){
                        if(MODE==1){
                            if((crt[K].InputFile=fopen(crt[K].InputFileName,"rb"))==NULL){
                                if(lge==1){
                                    printf("\n[ ERROR ] FILE OPENING ERROR");
                                }
                                else{
                                    printf("\n[ ERROR ] ERREUR D'OUVERTURE DU FICHIER");
                                }
                                free(crt[K].InputFileName);
                                con=0;

                            }
                        }
                        else if(MODE==3){
                            if(strnlen(crt[K].InputFileName, 200) == 200 || crt[K].InputFileName[0] == '\0' ){
                                if(lge==1){
                                    printf("\n[ ERROR ] ENTER A VALID PATH");
                                }
                                else{
                                    printf("\n[ ERROR ] ENTRER UN CHEMIN VALIDE");
                                }
                                con=0;
                            }
                        }
                    }
                }while(con!=1);
                do{
                    con=1;
                    MessageBeep(MB_ICONQUESTION);
                    if(lge==1){
                        result = MessageBox(NULL, "[ INFO ] DO YOU WANT TO REMOVE THE FILE AFTER ENCRYPTION ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONINFORMATION | MB_TOPMOST | MB_SETFOREGROUND);
                    }
                    else{
                        result = MessageBox(NULL, "[ INFO ] VOUDRIEZ-VOUS SUPPRIMER LE FICHIER APRES CHIFFREMENT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONINFORMATION | MB_TOPMOST | MB_SETFOREGROUND);
                    }
                    if(result==IDYES){
                        remo=1;
                    }
                    else if(result==IDNO){
                        remo=0;
                    }
                    else{
                        con=0;
                    }
                }while(con!=1);
                if(mdec==1){
                    InputPassword(crt[K].Password);
                    crt[K].v=InputVersion();
                    for(I=0;I<10;I++){
                        if(I==0){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Password[I+2]+crt[K].Password[I+3]-crt[K].Password[I+4]+crt[K].Password[I+5]-crt[K].Password[I+6]+crt[K].Password[I+7]-crt[K].Password[I+8]+crt[K].Password[I+9];
                        }
                        else if(I==1){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Password[I+2]+crt[K].Password[I+3]-crt[K].Password[I+4]+crt[K].Password[I+5]-crt[K].Password[I+6]+crt[K].Password[I+7]-crt[K].Password[I+8]+crt[K].Key[I-1];
                        }
                        else if(I==2){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Password[I+2]+crt[K].Password[I+3]-crt[K].Password[I+4]+crt[K].Password[I+5]-crt[K].Password[I+6]+crt[K].Password[I+7]-crt[K].Key[I-1]+crt[K].Key[I-2];
                        }
                        else if(I==3){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Password[I+2]+crt[K].Password[I+3]-crt[K].Password[I+4]+crt[K].Password[I+5]-crt[K].Password[I+6]+crt[K].Key[I-1]-crt[K].Key[I-2]+crt[K].Key[I-3];
                        }
                        else if(I==4){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Password[I+2]+crt[K].Password[I+3]-crt[K].Password[I+4]+crt[K].Password[I+5]-crt[K].Key[I-1]+crt[K].Key[I-2]-crt[K].Key[I-3]+crt[K].Key[I-4];
                        }
                        else if(I==5){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Password[I+2]+crt[K].Password[I+3]-crt[K].Password[I+4]+crt[K].Key[I-1]-crt[K].Key[I-2]+crt[K].Key[I-3]-crt[K].Key[I-4]+crt[K].Key[I-5];
                        }
                        else if(I==6){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Password[I+2]+crt[K].Password[I+3]-crt[K].Key[I-1]+crt[K].Key[I-2]-crt[K].Key[I-3]+crt[K].Key[I-4]-crt[K].Key[I-5]+crt[K].Key[I-6];
                        }
                        else if(I==7){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Password[I+2]+crt[K].Key[I-1]-crt[K].Key[I-2]+crt[K].Key[I-3]-crt[K].Key[I-4]+crt[K].Key[I-5]-crt[K].Key[I-6]+crt[K].Key[I-7];
                        }
                        else if(I==8){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Key[I-1]+crt[K].Key[I-2]-crt[K].Key[I-3]+crt[K].Key[I-4]-crt[K].Key[I-5]+crt[K].Key[I-6]-crt[K].Key[I-7]+crt[K].Key[I-8];
                        }
                        else{
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Key[I-1]-crt[K].Key[I-2]+crt[K].Key[I-3]-crt[K].Key[I-4]+crt[K].Key[I-5]-crt[K].Key[I-6]+crt[K].Key[I-7]-crt[K].Key[I-8]+crt[K].Key[I-9];
                        }
                    }
                }
                if(rmdec=='Y'){
                    int rm, irm;
                    for(rm=0;rm<nb;rm++){
                        for(irm=0;irm<10;irm++){
                            crt[rm].Key[irm]=crt[K].Key[irm];
                        }
                    }
                    for(rm=0;rm<nb;rm++){
                        crt[rm].v=crt[K].v;
                    }
                    rmdec='N';
                    mdec=2;
                }
                crt[K].OutputFileName=calloc(300,sizeof(char));
                if(crt[K].OutputFileName==NULL){
                        if(lge==1){
                            printf("\n[ ERROR ] MEMORY ALLOCATION ERROR");
                        }
                        else{
                            printf("\n[ ERROR ] ERREUR D'ALLOCATION DE MEMOIRE");
                        }
                        free(crt[K].InputFileName);
                        if(MODE==1){
                            fclose(crt[K].InputFile);
                        }
                        for(me=0;me<nb;me++){
                            memset(crt[me].Password, 0, 11);
                            memset(crt[me].Key, 0, 10*sizeof(int));
                            crt[K].v=0;
                        }
                        free(crt);
                        MessageBeep(MB_ICONHAND);
                        if(lge==1){
                            MessageBox(NULL, "[ ERROR ] ENCRYPTION FAILED(ALLOCATION ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        else{
                            MessageBox(NULL, "[ ERROR ] LE CHIFFREMENT A ECHOUE(ERREUR D'ALLOCATION)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        return 1;
                }
                if(MODE==3){
                    printf("\n");
                    if(lge==1){
                        TypingEffect("[ INFO ] THE ENCRYPTION WILL START AT :");
                    }
                    else{
                        TypingEffect("[ INFO ] LE CHIFFREMENT DEMARRERA A :");
                    }
                    printf("\n\t%d:%d:%d",H,M,S);
                    if(lan==1){
                        printf(" %s",ehou);
                        H=Hf;
                    }
                    printf("\n%s %d/%d/%d",dwn,mo,d,y);
                    Sleep(2000);
                    MessageBeep(MB_ICONEXCLAMATION);
                    if(lge==1){
                        MessageBox(NULL, "[ INFO ] DON'T TURN OFF THE DEVICE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONEXCLAMATION);
                    }
                    else{
                        MessageBox(NULL, "[ INFO ] N'ETEIGNEZ PAS L'APPAREIL", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONEXCLAMATION);
                    }
                    HWND hwnd = GetConsoleWindow();
                    ShowWindow(hwnd, SW_HIDE);
                    FreeConsole();
                    int mon,dn,yn,Hn,Mn,Sn,ct;
                    SYSTEMTIME st;
                    do{
                        ct=0;
                        Sleep(1000);
                        GetLocalTime(&st);
                        yn=st.wYear;
                        mon=st.wMonth;
                        dn=st.wDay;
                        Hn=st.wHour;
                        Mn=st.wMinute;
                        Sn=st.wSecond;
                        if(yn==y){
                            ct=1;
                            if(mon==mo){
                                ct=1;
                                if(dn==d){
                                    ct=1;
                                    if(Hn==H){
                                        ct=1;
                                        if(Mn==M){
                                            ct=1;
                                            if(Sn==S){
                                                ct=1;
                                            }
                                            else{
                                                ct=0;
                                            }
                                        }
                                        else{
                                            ct=0;
                                        }
                                    }
                                    else{
                                        ct=0;
                                    }
                                }
                                else{
                                    ct=0;
                                }
                            }
                            else{
                                ct=0;
                            }
                        }
                        else{
                            ct=0;
                        }
                        if(yn>y){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "[ INFO ] DATE PAST\nTHE ENCRYPTION WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else{
                                result=MessageBox(NULL, "[ INFO ] DATE DEPASSEE\nLE CRYPTAGE N'A PAS ETE EFFECTUE\nVOULEZ-VOUS CRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ] THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ] LE PROCESSUS S'EST INTERROMPU SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ] THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ] LE PROCESSUS S'EST INTERROMPU SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                        }
                        else if(yn==y && mon>mo){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "[ INFO ] DATE PAST\nTHE ENCRYPTION WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else{
                                result=MessageBox(NULL, "[ INFO ] DATE DEPASSEE\nLE CRYPTAGE N'A PAS ETE EFFECTUE\nVOULEZ-VOUS CRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ]THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ]LE PROCESSUS S'EST INTERROMPU SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ]THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ]LE PROCESSUS S'EST INTERROMPU SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                        }
                        else if(yn==y && mon==mo && dn>d){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "[ INFO ] DATE PAST\nTHE ENCRYPTION WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else{
                                result=MessageBox(NULL, "[ INFO ] DATE DEPASSEE\nLE CRYPTAGE N'A PAS ETE EFFECTUE\nVOULEZ-VOUS CRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ]THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ]LE PROCESSUS S'EST INTERROMPU SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ]THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ]LE PROCESSUS S'EST INTERROMPU SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                        }
                        else if(yn==y && mon==mo && dn==d && Hn>H){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "[ INFO ] DATE PAST\nTHE ENCRYPTION WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else{
                                result=MessageBox(NULL, "[ INFO ] DATE DEPASSEE\nLE CRYPTAGE N'A PAS ETE EFFECTUE\nVOULEZ-VOUS CRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ]THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ]LE PROCESSUS S'EST INTERROMPU SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ]THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ]LE PROCESSUS S'EST INTERROMPU SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                        }
                        else if(yn==y && mon==mo && dn==d && Hn==H && Mn>M){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "[ INFO ] DATE PAST\nTHE ENCRYPTION WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else{
                                result=MessageBox(NULL, "[ INFO ] DATE DEPASSEE\nLE CRYPTAGE N'A PAS ETE EFFECTUE\nVOULEZ-VOUS CRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ]THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ]LE PROCESSUS S'EST INTERROMPU SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ]THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ]LE PROCESSUS S'EST INTERROMPU SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                        }
                        else if(yn==y && mon==mo && dn==d && Hn==H && Mn==M && Sn>S){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "[ INFO ] DATE PAST\nTHE ENCRYPTION WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else{
                                result=MessageBox(NULL, "[ INFO ] DATE DEPASSEE\nLE CRYPTAGE N'A PAS ETE EFFECTUE\nVOULEZ-VOUS CRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ]THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ]LE PROCESSUS S'EST INTERROMPU SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ]THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ]LE PROCESSUS S'EST INTERROMPU SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                        }
                    }while(ct!=1);
                    if((crt[K].InputFile=fopen(crt[K].InputFileName,"rb"))==NULL){
                        for(me=0;me<nb;me++){
                            memset(crt[me].Password, 0, 11);
                            memset(crt[me].Key, 0, 10*sizeof(int));
                            crt[K].v=0;
                        }
                        MessageBeep(MB_ICONHAND);
                        if(lge==1){
                            snprintf(crt[K].OutputFileName, 300, "[ ERROR ]%s NOT FOUND\nTHE PROCESS END WITHOUT FILE ENCRYPTING", crt[K].InputFileName);
                        }
                        else{
                            snprintf(crt[K].OutputFileName, 300, "[ ERROR ]%s N'A PAS ETE TROUVE\nLE PROCESSUS S'EST INTERROMPU SANS AVOIR CRYPTER LE FICHIER", crt[K].InputFileName);
                        }
                        MessageBox(NULL, crt[K].OutputFileName, "FILE_CRYPTER", MB_OK);
                        free(crt[K].InputFileName);
                        free(crt[K].OutputFileName);
                        free(crt);
                        return 1;
                    }
                }
                sprintf(crt[K].OutputFileName,"%s.cflow",crt[K].InputFileName);
                if((prmr = FileExistanceChecker(crt[K].OutputFileName)) == 0){
                    do{
                        con=1;
                        MessageBeep(MB_ICONHAND);
                        if(lge==1){
                            result = MessageBox(NULL, "[ INFO ]A FILE WITH THE SAME NAME DETECTED\nCONTINUING WILL DELETE THIS ONE\nDO YOU WANT TO CONTINUE ?", "FILE_CRYPTER", MB_YESNO | MB_ICONWARNING);
                        }
                        else{
                            result = MessageBox(NULL, "[ INFO ]FICHIER AVEC LE MEME NOM DETECTE\nCONTINUER SUPPRIMERA CELUI CI\nVOUDRIEZ-VOUS CONTINUER ?", "FILE_CRYPTER", MB_YESNO | MB_ICONWARNING);
                        }
                        if(result==IDYES){
                            if(lge==1){
                                IndependentMessageBox("[ INFO ]THE OLD FILE WILL BE DELETED AND REPLACED BY THE NEW ONE","FILE_CRYPTER");
                            }
                            else{
                                IndependentMessageBox("[ INFO ]L'ANCIEN FICHIER SERA SUPPRIME ET REMPLACE PAR LE NOUVEAU","FILE_CRYPTER");
                            }
                        }
                        else if(result==IDNO){
                            free(crt[K].InputFileName);
                            free(crt[K].OutputFileName);
                            fclose(crt[K].InputFile);
                            for(me=0;me<nb;me++){
                                memset(crt[me].Password, 0, 11);
                                memset(crt[me].Key, 0, 10*sizeof(int));
                                crt[K].v=0;
                            }
                            MessageBeep(MB_ICONHAND);
                            if(lge==1){
                                MessageBox(NULL, "[ INFO ]ENCRYPTION STOPPED\nYOU CAN MAKE THIS EXISTING FILE COPY TO SAVE IT AND RESTART SAFELY", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                            }
                            else{
                                MessageBox(NULL, "[ INFO ]LE CHIFFREMENT A ETE INTERROMPU\nVOUS POUVEZ FAIRE LA COPIE DU FICHIER EXISTANT POUR LE SAUVEGARDER ET RECOMMENCEZ EN SECURITE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                            }
                            free(crt);
                            return 1;
                        }
                        else{
                            con=0;
                        }
                    }while(con!=1);
                }
                if((crt[K].OutputFile=fopen(crt[K].OutputFileName,"wb+"))==NULL){
                    if(lge==1){
                        printf("\n[ ERROR ] OPENING ERROR");
                    }
                    else{
                        printf("\n[ ERROR ] ERREUR D'OUVERTURE");
                    }
                    free(crt[K].InputFileName);
                    free(crt[K].OutputFileName);
                    fclose(crt[K].InputFile);
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL, "[ ERROR ]ENCRYPTION FAILED(OPENING ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    else{
                        MessageBox(NULL, "[ ERROR ]LE CHIFFREMENT A ECHOUE(ERREUR D'OUVERTURE)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    for(me=0;me<nb;me++){
                        memset(crt[me].Password, 0, 11);
                        memset(crt[me].Key, 0, 10*sizeof(int));
                        crt[K].v=0;
                    }
                    free(crt);
                    return 1;
                }
                pv=((crt[K].v+crt[K].Key[0]+crt[K].Key[1]+crt[K].Key[2]+crt[K].Key[3]+crt[K].Key[4]+crt[K].Key[5]+crt[K].Key[6]+crt[K].Key[7]+crt[K].Key[8]+crt[K].Key[9])/11);
                i=0;
                while((c=getc(crt[K].InputFile)) != EOF){
                    i+=1;
                    if(i%10==0){
                        c=c-crt[K].Key[0];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[0]=crt[K].Key[0]+(crt[K].v-3);
                    }
                    else if(i%10==1){
                        c=c-crt[K].Key[1];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[1]=crt[K].Key[1]+(crt[K].v-3);
                    }
                    else if(i%10==2){
                        c=c-crt[K].Key[2];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[2]=crt[K].Key[2]+(crt[K].v-3);
                    }
                    else if(i%10==3){
                        c=c-crt[K].Key[3];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[3]=crt[K].Key[3]+(crt[K].v-3);
                    }
                    else if(i%10==4){
                        c=c-crt[K].Key[4];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[4]=crt[K].Key[4]+(crt[K].v-3);
                    }
                    else if(i%10==5){
                        c=c-crt[K].Key[5];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[5]=crt[K].Key[5]+(crt[K].v-3);
                    }
                    else if(i%10==6){
                        c=c-crt[K].Key[6];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[6]=crt[K].Key[6]+(crt[K].v-3);
                    }
                    else if(i%10==7){
                        c=c-crt[K].Key[7];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[7]=crt[K].Key[7]+(crt[K].v-3);
                    }
                    else if(i%10==8){
                        c=c-crt[K].Key[8];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[8]=crt[K].Key[8]+(crt[K].v-3);
                    }
                    else{
                        c=c-crt[K].Key[9];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[9]=crt[K].Key[9]+(crt[K].v-3);
                    }
                }
                printf("\n");
                if((prmr = PermuteDataInFile(crt[K].OutputFile, pv, 1)) == 0){
                    free(crt[K].InputFileName);
                    fclose(crt[K].InputFile);
                    fclose(crt[K].OutputFile);
                    RemoveFile(crt[K].OutputFileName);
                    free(crt[K].OutputFileName);
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL, "[ ERROR ]ENCRYPTION FAILED(PERMUTTING GONE WRONG)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    else{
                        MessageBox(NULL, "[ ERROR ]LE CHIFFREMENT A ECHOUE(LA PERMUTATION N'A PAS MARCHE)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    for(me=0;me<nb;me++){
                        memset(crt[me].Password, 0, 11);
                        memset(crt[me].Key, 0, 10*sizeof(int));
                        crt[K].v=0;
                    }
                    free(crt);
                    return 1;
                }
                free(crt[K].OutputFileName);
                fclose(crt[K].InputFile);
                fclose(crt[K].OutputFile);
                if(MODE==1){
                    if(ani==1){
                        printf("\n");
                        if(lge==1){
                            TypingEffect("[ INFO ]NOW ENCRYPTING");
                        }
                        else{
                            TypingEffect("[ INFO ]CHIFFREMENT EN COURS");
                        }
                        LoadingEffect();
                        printf("\n");
                        MatrixSimulation();
                    }
                    printf("\n[ SUCCESS ] %s ",crt[K].InputFileName);
                    if(lge==1){
                        TypingEffect("ENCRYPTED SUCCESSFULLY");
                    }
                    else{
                        TypingEffect("CRYPTE AVEC SUCCES");
                    }
                    if(remo==1){
                        RemoveFile(crt[K].InputFileName);
                    }
                    printf("\n");
                    memset(crt[K].Password, 0, 11);
                    memset(crt[K].Key, 0, 10*sizeof(int));
                    crt[K].v=0;
                    if(nb==K+1){
                        MessageBeep(MB_ICONASTERISK);
                        if(lge==1){
                            IndependentMessageBox("[ SUCCESS ]ALL DONE", "FILE_CRYPTER");
                        }
                        else{
                            IndependentMessageBox("[ SUCCESS ]TERMINE", "FILE_CRYPTER");
                        }
                        Sleep(2000);
                    }
                }
                if(MODE==3){
                    if(remo==1){
                        RemoveFile(crt[K].InputFileName);
                    }
                    memset(crt[K].Password, 0, 11);
                    memset(crt[K].Key, 0, 10*sizeof(int));
                    crt[K].v=0;
                    MessageBeep(MB_ICONASTERISK);
                    if(lge==1){
                        MessageBox(NULL,"[ SUCCESS ]ENCRYPTION COMPLETED SUCCESSFULLY", "FILE_CRYPTER", MB_OK | MB_ICONINFORMATION);
                    }
                    else{
                        MessageBox(NULL,"[ SUCCESS ]CHIFFREMENT EFFECTUE AVEC SUCCES", "FILE_CRYPTER", MB_OK | MB_ICONINFORMATION);
                    }
                }
                free(crt[K].InputFileName);
            }
            free(crt);
            if(MODE==1){
                do{
                    con=1;
                    if(lge==1){
                        printf("\nDO YOU WANT TO PERFORM ANOTHER OPERATION?\n[1] YES\n[0] EXIT");
                    }
                    else{
                        printf("\nVOULEZ-VOUS EFFECTUEZ UNE AUTRE OPERATION?\n[1] OUI\n[0] QUITTER");
                    }
                    printf("\ncipherflow> ");
                    if(scanf("%d",&res)!=1){
                        if(lge==1){
                            printf("\n[ ERROR ] ENTER A NUMBER BETWEEN 1 AND 0");
                        }
                        else{
                            printf("\n[ ERROR ] ENTRER UN NOMBRE ENTRE 1 ET 0");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                    }
                }while(con!=1 || (res!=1 && res!=0));
                system("cls");
            }
        }
        else if(MODE==2 || MODE==4){
            if(MODE==2){
                if(lge==1){
                    TypingEffect("###########################################       2-> DECRYPT FILE       ###############################################");
                    printf("\n");
                }
                else{
                    TypingEffect("#########################################   2-> DECHIFFRER UN/DES FICHIER(S)   #########################################");
                    printf("\n");
                }
            }
            else{
                if(lge==1){
                    TypingEffect("###########################################   4-> SCHEDULE DECRYPTION    ###############################################");
                    printf("\n");
                }
                else{
                    TypingEffect("#########################################   4-> PLANIFIER UN DECHIFFREMENT     #########################################");
                    printf("\n");
                }
            }
            if(ani==1){
                DynamicColor();
            }
            int nb, K, I, c, S, M, H, h, m, s, y, mo, d, dw, Md, Hf, i, prmr, copr, result, me;
            long pv;
            char dwn[11], ehou[3], *TempFileName;
            char rmdec;
            FILE* TempFile;
            if(MODE==4){
                if(lge==1){
                    printf("\n");
                    TypingEffect("==================================================  DECRYPTION TIMER  ==================================================");
                    printf("\n");
                }
                else{
                    printf("\n");
                    TypingEffect("================================================= TIMER DE DECHIFFREMENT ===============================================");
                    printf("\n");
                }
                if(lge==1){
                    printf("\nSET DELAY BEFORE SCHEDULED DECRYPTION(TURN THE PC OFF WILL DELETE THE PROCESS)");
                }
                else{
                    printf("\nDEFINIR LE DELAI AVANT LE DECHIFFREMENT PROGRAMME(TURN THE PC OFF WILL DELETE THE PROCESS)");
                }
                do{
                    con=1;
                    printf("\ncipherflow> H: ");
                    if(scanf("%d",&H)!=1){
                        if(lge==1){
                            printf("\n[ ERROR ] ENTER A VALID NUMBER");
                        }
                        else{
                            printf("\n[ ERROR ] ENTRER UN NOMBRE VALIDE");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                        H=0;
                        M=0;
                        S=0;
                        continue;
                    }
                    printf("\ncipherflow> M: ");
                    if(scanf("%d",&M)!=1){
                        if(lge==1){
                            printf("\n[ ERROR ] ENTER A VALID NUMBER");
                        }
                        else{
                            printf("\n[ ERROR ] ENTRER UN NOMBRE VALIDE");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                        M=0;
                        S=0;
                        continue;
                    }
                    printf("\ncipherflow> S: ");
                    if(scanf("%d",&S)!=1){
                        if(lge==1){
                            printf("\n[ ERROR ] ENTER A VALID NUMBER");
                        }
                        else{
                            printf("\n[ ERROR ] ENTRER UN NOMBRE VALIDE");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                        S=0;
                        continue;
                    }
                    if(lge==1){
                        printf("\n");
                        TypingEffect("DECRYPTION SCHEDULED IN");
                        printf(" %d ",H);
                        TypingEffect("HOUR(S)");
                        printf(" %d ",M);
                        TypingEffect("MINUTE(S)");
                        printf(" %d ",S);
                        TypingEffect("SECOND(S)");
                        printf("\nENTER 1 TO CONFIRM");
                    }
                    else{
                        printf("\n");
                        TypingEffect("DECHIFFREMENT PREVU DANS");
                        printf(" %d ",H);
                        TypingEffect("HEURE(S)");
                        printf(" %d ",M);
                        TypingEffect("MINUTE(S)");
                        printf(" %d ",S);
                        TypingEffect("SECONDE(S)");
                        printf("\nENTRER 1 POUR CONFIRMER");
                    }
                    printf("\ncipherflow> ");
                    if(scanf("%d",&con)!=1){
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                    }
                }while(con!=1 || (H<0 || M<0 || S<0));
                SYSTEMTIME st;
                GetLocalTime(&st);
                y=st.wYear;
                mo=st.wMonth;
                d=st.wDay;
                dw=st.wDayOfWeek;
                h=st.wHour;
                m=st.wMinute;
                s=st.wSecond;
                H=H+h;
                M=M+m;
                S=S+s;
                while(S>59){
                    S-=60;
                    M+=1;
                }
                while(M>59){
                    M-=60;
                    H+=1;
                }
                while(H>23){
                    H-=24;
                    d+=1;
                    dw+=1;
                }
                while(d>(Md=NumberOfDaysInMonth(mo, y))){
                    d-=(Md=NumberOfDaysInMonth(mo, y));
                    mo+=1;
                }
                while(mo>12){
                    mo-=12;
                    y+=1;
                }
                dw=(dw%7);
                DayOfWeek(dwn, dw, lan);
                if(lan==1){
                    Hf=H;
                    if(H>11){
                        strcpy(ehou,"PM");
                    }
                    else{
                        strcpy(ehou,"AM");
                    }
                    H=(H%12);
                    if(H==0){
                        H=12;
                    }
                }
            }
            if(MODE==2){
                nb=InputNumberOfFile();
            }
            else{
                nb=1;
            }
            if(nb>1){
                rmdec=AskForSamePasswordUse();
            }
            else{
                rmdec='N';
            }
            int mdec=1;
            crypt *crt;
            crt=(crypt *)calloc(nb,sizeof(crypt));
            if(crt==NULL){
                if(lge==1){
                    printf("\n[ ERROR ] ALLOCATION ERROR");
                    MessageBeep(MB_ICONHAND);
                    MessageBox(NULL, "[ ERROR ] ALLOCATING MEMORY SPACE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                }
                else{
                    printf("\n[ ERROR ] ERREUR D'ALLOCATION");
                    MessageBeep(MB_ICONHAND);
                    MessageBox(NULL, "[ ERROR ] ALLOCATION D'ESPACE MEMOIRE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                }
                return 1;
            }
            for(K=0;K<nb;K++){
                if(lge==1){
                    printf("\n");
                    TypingEffect("===================================================  FILE SELECTION  ===================================================");
                    printf("\n");
                }
                else{
                    printf("\n");
                    TypingEffect("================================================= SELECTION DU FICHIER =================================================");
                    printf("\n");
                }
                do{
                    con=1;
                    crt[K].InputFileName=calloc(200,sizeof(char));
                    if(crt[K].InputFileName==NULL){
                        if(lge==1){
                            printf("\n[ ERROR ] ALLOCATION ERROR");
                            free(crt);
                            MessageBeep(MB_ICONHAND);
                            MessageBox(NULL, "[ ERROR ] ALLOCATING MEMORY SPACE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        else{
                            printf("\n[ ERROR ] ERREUR D'ALLOCATION");
                            free(crt);
                            MessageBeep(MB_ICONHAND);
                            MessageBox(NULL, "[ ERROR ] ALLOCATION D'ESPACE MEMOIRE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        return 1;
                    }
                    if(lge==1){
                        printf("\nENTER THE FULL PATH OF THE FILE OR DRAG AND DROP IT HERE");
                    }
                    else{
                        printf("\nENTRER LE CHEMIN COMPLET DU FICHIER OU GLISSER ET DEPOSER LE FICHIER ICI");
                    }
                    printf("\ncipherflow> ");
                    if(scanf(" %199[^\n]",crt[K].InputFileName) != 1){
                        if(lge==1){
                            printf("\n[ ERROR ] ENTER A VALID PATH");
                        }
                        else{
                            printf("\n[ ERROR ] ENTRER UN CHEMIN VALIDE");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                    }
                    while((clb=getchar()) != '\n' && clb != EOF);
                    if(crt[K].InputFileName[0]== '\'' || crt[K].InputFileName[0]== '\"' ){
                        memmove(crt[K].InputFileName, crt[K].InputFileName + 1, strlen(crt[K].InputFileName)+1);
                    }
                    if(crt[K].InputFileName[strlen(crt[K].InputFileName)-1]== '\'' || crt[K].InputFileName[strlen(crt[K].InputFileName)-1]== '\"' ){
                        crt[K].InputFileName[strlen(crt[K].InputFileName)-1]='\0';
                    }
                    if(con!=0){
                        if(MODE==2){
                            if((crt[K].InputFile=fopen(crt[K].InputFileName,"rb"))==NULL){
                                if(lge==1){
                                    printf("\n[ ERROR ] FILE OPENING ERROR");
                                }
                                else{
                                    printf("\n[ ERROR ] ERREUR D'OUVERTURE DU FICHIER");
                                }
                                free(crt[K].InputFileName);
                                con=0;
                            }
                        }
                        else if(MODE==4){
                            if(strnlen(crt[K].InputFileName, 200) == 200 || crt[K].InputFileName[0] == '\0' ){
                                if(lge==1){
                                    printf("\n[ ERROR ] ENTER A VALID PATH");
                                }
                                else{
                                    printf("\n[ ERROR ] ENTRER UN CHEMIN VALIDE");
                                }
                                con=0;
                            }
                        }
                    }
                    if(con!=0){
                        if(crt[K].InputFileName[strlen(crt[K].InputFileName)-1] != 'w' || crt[K].InputFileName[strlen(crt[K].InputFileName)-2] != 'o' || crt[K].InputFileName[strlen(crt[K].InputFileName)-3] != 'l' || crt[K].InputFileName[strlen(crt[K].InputFileName)-4] != 'f' || crt[K].InputFileName[strlen(crt[K].InputFileName)-5] != 'c' || crt[K].InputFileName[strlen(crt[K].InputFileName)-6] != '.'){
                            if(lge==1){
                                printf("\nINVALID FILE. ENTER A CipherFlow ENCRYPTED FILE");
                            }
                            else{
                                printf("\nFICHIER INVALIDE. ENTRER UN FICHIER CRYPTE CipherFlow");
                            }
                            con=0;
                        }
                    }
                }while(con!=1);
                if(mdec==1){
                    InputPassword(crt[K].Password);
                    crt[K].v=InputVersion();
                    for(I=0;I<10;I++){
                        if(I==0){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Password[I+2]+crt[K].Password[I+3]-crt[K].Password[I+4]+crt[K].Password[I+5]-crt[K].Password[I+6]+crt[K].Password[I+7]-crt[K].Password[I+8]+crt[K].Password[I+9];
                        }
                        else if(I==1){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Password[I+2]+crt[K].Password[I+3]-crt[K].Password[I+4]+crt[K].Password[I+5]-crt[K].Password[I+6]+crt[K].Password[I+7]-crt[K].Password[I+8]+crt[K].Key[I-1];
                        }
                        else if(I==2){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Password[I+2]+crt[K].Password[I+3]-crt[K].Password[I+4]+crt[K].Password[I+5]-crt[K].Password[I+6]+crt[K].Password[I+7]-crt[K].Key[I-1]+crt[K].Key[I-2];
                        }
                        else if(I==3){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Password[I+2]+crt[K].Password[I+3]-crt[K].Password[I+4]+crt[K].Password[I+5]-crt[K].Password[I+6]+crt[K].Key[I-1]-crt[K].Key[I-2]+crt[K].Key[I-3];
                        }
                        else if(I==4){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Password[I+2]+crt[K].Password[I+3]-crt[K].Password[I+4]+crt[K].Password[I+5]-crt[K].Key[I-1]+crt[K].Key[I-2]-crt[K].Key[I-3]+crt[K].Key[I-4];
                        }
                        else if(I==5){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Password[I+2]+crt[K].Password[I+3]-crt[K].Password[I+4]+crt[K].Key[I-1]-crt[K].Key[I-2]+crt[K].Key[I-3]-crt[K].Key[I-4]+crt[K].Key[I-5];
                        }
                        else if(I==6){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Password[I+2]+crt[K].Password[I+3]-crt[K].Key[I-1]+crt[K].Key[I-2]-crt[K].Key[I-3]+crt[K].Key[I-4]-crt[K].Key[I-5]+crt[K].Key[I-6];
                        }
                        else if(I==7){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Password[I+2]+crt[K].Key[I-1]-crt[K].Key[I-2]+crt[K].Key[I-3]-crt[K].Key[I-4]+crt[K].Key[I-5]-crt[K].Key[I-6]+crt[K].Key[I-7];
                        }
                        else if(I==8){
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Password[I+1]-crt[K].Key[I-1]+crt[K].Key[I-2]-crt[K].Key[I-3]+crt[K].Key[I-4]-crt[K].Key[I-5]+crt[K].Key[I-6]-crt[K].Key[I-7]+crt[K].Key[I-8];
                        }
                        else{
                            crt[K].Key[I]=crt[K].Password[I];
                            crt[K].Key[I]=crt[K].Key[I]-((crt[K].v+5)*10)+crt[K].Key[I-1]-crt[K].Key[I-2]+crt[K].Key[I-3]-crt[K].Key[I-4]+crt[K].Key[I-5]-crt[K].Key[I-6]+crt[K].Key[I-7]-crt[K].Key[I-8]+crt[K].Key[I-9];
                        }
                    }
                }

                if(rmdec=='Y'){
                    int rm, irm;
                    for(rm=0;rm<nb;rm++){
                        for(irm=0;irm<10;irm++){
                            crt[rm].Key[irm]=crt[K].Key[irm];
                        }
                    }
                    for(rm=0;rm<nb;rm++){
                        crt[rm].v=crt[K].v;
                    }
                    rmdec='N';
                    mdec=2;
                }
                crt[K].OutputFileName=calloc(300,sizeof(char));
                if(crt[K].OutputFileName==NULL){
                        if(lge==1){
                            printf("\n[ ERROR ] MEMORY ALLOCATION ERROR");
                        }
                        else{
                            printf("\n[ ERROR ] ERREUR D'ALLOCATION DE MEMOIRE");
                        }
                        free(crt[K].InputFileName);
                        fclose(crt[K].InputFile);
                        MessageBeep(MB_ICONHAND);
                        if(lge==1){
                            MessageBox(NULL, "[ ERROR ] DECRYPTION FAILED(ALLOCATION ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        else{
                            MessageBox(NULL, "[ ERROR ] LE DECHIFFREMENT A ECHOUE(ERREUR D'ALLOCATION)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        for(me=0;me<nb;me++){
                            memset(crt[me].Password, 0, 11);
                            memset(crt[me].Key, 0, 10*sizeof(int));
                            crt[K].v=0;
                        }
                        free(crt);
                        return 1;
                }
                if(MODE==4){
                    printf("\n");
                    if(lge==1){
                        TypingEffect("[ INFO ] THE DECRYPTION WILL START AT :");
                    }
                    else{
                        TypingEffect("[ INFO ] LE DECHIFFREMENT DEMARRERA A :");
                    }
                    printf("\n\t%d:%d:%d",H,M,S);
                    if(lan==1){
                        printf(" %s",ehou);
                        H=Hf;
                    }
                    printf("\n%s %d/%d/%d",dwn,mo,d,y);
                    Sleep(2000);
                    MessageBeep(MB_ICONEXCLAMATION);
                    if(lge==1){
                        MessageBox(NULL, "[ INFO ] DON'T TURN OFF THE DEVICE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONEXCLAMATION);
                    }
                    else{
                        MessageBox(NULL, "[ INFO ] N'ETEIGNEZ PAS L'APPAREIL", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONEXCLAMATION);
                    }
                    HWND hwnd = GetConsoleWindow();
                    ShowWindow(hwnd, SW_HIDE);
                    FreeConsole();
                    int mon,dn,yn,Hn,Mn,Sn,ct;
                    SYSTEMTIME st;
                    do{
                        ct=0;
                        Sleep(1000);
                        GetLocalTime(&st);
                        yn=st.wYear;
                        mon=st.wMonth;
                        dn=st.wDay;
                        Hn=st.wHour;
                        Mn=st.wMinute;
                        Sn=st.wSecond;
                        if(yn==y){
                            ct=1;
                            if(mon==mo){
                                ct=1;
                                if(dn==d){
                                    ct=1;
                                    if(Hn==H){
                                        ct=1;
                                        if(Mn==M){
                                            ct=1;
                                            if(Sn==S){
                                                ct=1;
                                            }
                                            else{
                                                ct=0;
                                            }
                                        }
                                        else{
                                            ct=0;
                                        }
                                    }
                                    else{
                                        ct=0;
                                    }
                                }
                                else{
                                    ct=0;
                                }
                            }
                            else{
                                ct=0;
                            }
                        }
                        else{
                            ct=0;
                        }
                        if(yn>y){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "[ INFO ] DATE PAST\nTHE DECRYPTION WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else{
                                result=MessageBox(NULL, "[ INFO ] DATE DEPASSEE\nLE DECRYPTAGE N'A PAS ETE EFFECTUE\nVOULEZ-VOUS DECRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ] THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ] LE PROCESSUS S'EST INTERROMPU SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ] THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ] LE PROCESSUS S'EST INTERROMPU SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                        }
                        else if(yn==y && mon>mo){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "[ INFO ] DATE PAST\nTHE DECRYPTION WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else{
                                result=MessageBox(NULL, "[ INFO ] DATE DEPASSEE\nLE DECRYPTAGE N'A PAS ETE EFFECTUE\nVOULEZ-VOUS DECRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ] THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ] LE PROCESSUS S'EST INTERROMPU SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ] THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ] LE PROCESSUS S'EST INTERROMPU SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                        }
                        else if(yn==y && mon==mo && dn>d){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "[ INFO ] DATE PAST\nTHE DECRYPTION WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else{
                                result=MessageBox(NULL, "[ INFO ] DATE DEPASSEE\nLE DECRYPTAGE N'A PAS ETE EFFECTUE\nVOULEZ-VOUS DECRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ] THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ] LE PROCESSUS S'EST INTERROMPU SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ] THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ] LE PROCESSUS S'EST INTERROMPU SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                        }
                        else if(yn==y && mon==mo && dn==d && Hn>H){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "[ INFO ] DATE PAST\nTHE DECRYPTION WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else{
                                result=MessageBox(NULL, "[ INFO ] DATE DEPASSEE\nLE DECRYPTAGE N'A PAS ETE EFFECTUE\nVOULEZ-VOUS DECRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ] THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ] LE PROCESSUS S'EST INTERROMPU SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ] THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ] LE PROCESSUS S'EST INTERROMPU SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                        }
                        else if(yn==y && mon==mo && dn==d && Hn==H && Mn>M){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "[ INFO ] DATE PAST\nTHE DECRYPTION WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else{
                                result=MessageBox(NULL, "[ INFO ] DATE DEPASSEE\nLE DECRYPTAGE N'A PAS ETE EFFECTUE\nVOULEZ-VOUS DECRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ] THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ] LE PROCESSUS S'EST INTERROMPU SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ] THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ] LE PROCESSUS S'EST INTERROMPU SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                        }
                        else if(yn==y && mon==mo && dn==d && Hn==H && Mn==M && Sn>S){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "[ INFO ] DATE PAST\nTHE DECRYPTION WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else{
                                result=MessageBox(NULL, "[ INFO ] DATE DEPASSEE\nLE DECRYPTAGE N'A PAS ETE EFFECTUE\nVOULEZ-VOUS DECRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ] THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ] LE PROCESSUS S'EST INTERROMPU SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    IndependentMessageBox("[ INFO ] THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else{
                                    IndependentMessageBox("[ INFO ] LE PROCESSUS S'EST INTERROMPU SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                free(crt[K].InputFileName);
                                free(crt[K].OutputFileName);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].Password, 0, 11);
                                    memset(crt[me].Key, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                Sleep(3000);
                                return 1;
                            }
                        }
                    }while(ct!=1);
                    if((crt[K].InputFile=fopen(crt[K].InputFileName,"rb"))==NULL){
                        for(me=0;me<nb;me++){
                            memset(crt[me].Password, 0, 11);
                            memset(crt[me].Key, 0, 10*sizeof(int));
                            crt[K].v=0;
                        }
                        MessageBeep(MB_ICONASTERISK);
                        if(lge==1){
                            snprintf(crt[K].OutputFileName, 300, "[ ERROR ] %s NOT FOUND\nTHE PROCESS END WITHOUT FILE DECRYPTING", crt[K].InputFileName);
                        }
                        else{
                            snprintf(crt[K].OutputFileName, 300, "[ ERROR ] %s N'A PAS ETE TROUVE\nLE PROCESSUS S'EST INTERROMPU SANS AVOIR DECRYPTER LE FICHIER", crt[K].InputFileName);
                        }
                        MessageBox(NULL, crt[K].OutputFileName, "FILE_CRYPTER", MB_OK);
                        free(crt[K].InputFileName);
                        free(crt[K].OutputFileName);
                        free(crt);
                        return 1;
                    }
                }
                strcpy(crt[K].OutputFileName,crt[K].InputFileName);
                crt[K].OutputFileName[strlen(crt[K].OutputFileName)-6]='\0';
                if((prmr = FileExistanceChecker(crt[K].OutputFileName)) == 0){
                    do{
                        con=1;
                        MessageBeep(MB_ICONHAND);
                        if(lge==1){
                            result = MessageBox(NULL, "[ INFO ] A FILE WITH THE SAME NAME DETECTED\nCONTINUING WILL DELETE THIS ONE\nDO YOU WANT TO CONTINUE ?", "FILE_CRYPTER", MB_YESNO | MB_ICONWARNING);
                        }
                        else{
                            result = MessageBox(NULL, "[ INFO ] FICHIER AVEC LE MEME NOM DETECTE\nCONTINUER SUPPRIMERA CE FICHIER\nVOUDRIEZ-VOUS CONTINUER ?", "FILE_CRYPTER", MB_YESNO | MB_ICONWARNING);
                        }
                        if(result==IDYES){
                            if(lge==1){
                                IndependentMessageBox("[ INFO ] THE OLD FILE WILL BE DELETED AND REPLACED BY THE NEW ONE","FILE_CRYPTER");
                            }
                            else{
                                IndependentMessageBox("[ INFO ] L'ANCIEN FICHIER SERA SUPPRIME ET REMPLACE PAR LE NOUVEAU FICHIER","FILE_CRYPTER");
                            }
                            Sleep(2000);
                        }
                        else if(result==IDNO){
                            free(crt[K].InputFileName);
                            free(crt[K].OutputFileName);
                            fclose(crt[K].InputFile);
                            for(me=0;me<nb;me++){
                                memset(crt[me].Password, 0, 11);
                                memset(crt[me].Key, 0, 10*sizeof(int));
                                crt[K].v=0;
                            }
                            MessageBeep(MB_ICONHAND);
                            if(lge==1){
                                MessageBox(NULL, "[ INFO ] DECRYPTION STOPPED\nYOU CAN MAKE THIS EXISTING FILE COPY TO SAVE IT AND RESTART SAFELY", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                            }
                            else{
                                MessageBox(NULL, "[ INFO ] LE DECHIFFREMENT A ETE ARRETE\nVOUS POUVEZ FAIRE LA COPIE DU FICHIER EXISTANT POUR LE SAUVEGARDER ET RECOMMENCEZ EN SECURITE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                            }
                            free(crt);
                            return 1;
                        }
                        else{
                            con=0;
                        }
                    }while(con!=1);
                }
                if((crt[K].OutputFile=fopen(crt[K].OutputFileName,"wb"))==NULL){
                    if(lge==1){
                        printf("\n[ ERROR ] FILE OPENING ERROR");
                    }
                    else{
                        printf("\n[ ERROR ] ERREUR D'OUVERTURE DU FICHIER");
                    }
                    free(crt[K].InputFileName);
                    free(crt[K].OutputFileName);
                    fclose(crt[K].InputFile);
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL, "[ ERROR ] DECRYPTION FAILED(OPENING ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    else{
                        MessageBox(NULL, "[ ERROR ] LE DECHIFFREMENT A ECHOUE(ERREUR D'OUVERTURE)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    for(me=0;me<nb;me++){
                        memset(crt[me].Password, 0, 11);
                        memset(crt[me].Key, 0, 10*sizeof(int));
                        crt[K].v=0;
                    }
                    free(crt);
                    return 1;
                }
                TempFileName=calloc(200,sizeof(char));
                if(TempFileName==NULL){
                    if(lge==1){
                        printf("\n[ ERROR ] MEMORY ALLOCATION ERROR");
                    }
                    else{
                        printf("\n[ ERROR ] ERREUR D'ALLOCATION DE MEMOIRE");
                    }
                    free(crt[K].InputFileName);
                    fclose(crt[K].InputFile);
                    fclose(crt[K].OutputFile);
                    RemoveFile(crt[K].OutputFileName);
                    free(crt[K].OutputFileName);
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL, "[ ERROR ] DECRYPTION FAILED(ALLOCATION ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    else{
                        MessageBox(NULL, "[ ERROR ] LE DECHIFFREMENT A ECHOUE(ERREUR D'ALLOCATION)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    for(me=0;me<nb;me++){
                        memset(crt[me].Password, 0, 11);
                        memset(crt[me].Key, 0, 10*sizeof(int));
                        crt[K].v=0;
                    }
                    free(crt);
                    return 1;
                }
                sprintf(TempFileName,"%ss",crt[K].InputFileName);
                if((prmr = FileExistanceChecker(TempFileName)) == 0){
                    do{
                        con=1;
                        MessageBeep(MB_ICONHAND);
                        if(lge==1){
                            result = MessageBox(NULL, "[ INFO ] A FILE WITH THE SAME NAME DETECTED\nCONTINUING WILL DELETE THIS ONE\nDO YOU WANT TO CONTINUE ?", "FILE_CRYPTER", MB_YESNO | MB_ICONWARNING);
                        }
                        else{
                            result = MessageBox(NULL, "[ INFO ] FICHIER AVEC LE MEME NOM DETECTE\nCONTINUER SUPPRIMERA CELUI CI\nVOUDRIEZ-VOUS CONTINUER ?", "FILE_CRYPTER", MB_YESNO | MB_ICONWARNING);
                        }
                        if(result==IDYES){
                            if(lge==1){
                                IndependentMessageBox("[ INFO ] THE OLD FILE WILL BE DELETED AND REPLACED BY THE NEW ONE","FILE_CRYPTER");
                            }
                            else{
                                IndependentMessageBox("[ INFO ] L'ANCIEN FICHIER SERA SUPPRIME ET REMPLACE PAR LE NOUVEAU","FILE_CRYPTER");
                            }
                            Sleep(2000);
                        }
                        else if(result==IDNO){
                            free(crt[K].InputFileName);
                            free(crt[K].OutputFileName);
                            fclose(crt[K].InputFile);
                            for(me=0;me<nb;me++){
                                memset(crt[me].Password, 0, 11);
                                memset(crt[me].Key, 0, 10*sizeof(int));
                                crt[K].v=0;
                            }
                            MessageBeep(MB_ICONHAND);
                            if(lge==1){
                                MessageBox(NULL, "[ INFO ] DECRYPTION STOPPED\nYOU CAN MAKE THIS EXISTING FILE COPY TO SAVE IT AND RESTART SAFELY", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                            }
                            else{
                                MessageBox(NULL, "[ INFO ] LE DECHIFFREMENT A ETE ARRETE\nVOUS POUVEZ FAIRE LA COPIE DU FICHIER EXISTANT POUR LE SAUVEGARDER ET RECOMMENCEZ EN SECURITE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                            }
                            free(crt);
                            return 1;
                        }
                        else{
                            con=0;
                        }
                    }while(con!=1);
                }
                if((TempFile=fopen(TempFileName,"wb+"))==NULL){
                    if(lge==1){
                        printf("\n[ ERROR ] FILE OPENING ERROR");
                    }
                    else{
                        printf("\n[ ERROR ] ERREUR D'OUVERTURE DU FICHIER");
                    }
                    free(crt[K].InputFileName);
                    free(TempFileName);
                    fclose(crt[K].InputFile);
                    fclose(crt[K].OutputFile);
                    RemoveFile(crt[K].OutputFileName);
                    free(crt[K].OutputFileName);
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL, "[ ERROR ] DECRYPTION FAILED(OPENING ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    else{
                        MessageBox(NULL, "[ ERROR ] LE DECHIFFREMENT A ECHOUE(ERREUR D'OUVERTURE)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    for(me=0;me<nb;me++){
                        memset(crt[me].Password, 0, 11);
                        memset(crt[me].Key, 0, 10*sizeof(int));
                        crt[K].v=0;
                    }
                    free(crt);
                    return 1;
                }
                SetFileAttributes(TempFileName, FILE_ATTRIBUTE_HIDDEN);
                if((copr = FileCopyMaker(crt[K].InputFile, TempFile)) == 0){
                    free(crt[K].InputFileName);
                    fclose(crt[K].InputFile);
                    fclose(crt[K].OutputFile);
                    fclose(TempFile);
                    RemoveFile(crt[K].OutputFileName);
                    RemoveFile(TempFileName);
                    free(crt[K].OutputFileName);
                    free(TempFileName);
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL, "[ ERROR ] DECRYPTION FAILED(COPYING ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    else{
                        MessageBox(NULL, "[ ERROR ] LE DECHIFFREMENT A ECHOUE(ERREUR LORS DE LA COPIE)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    for(me=0;me<nb;me++){
                        memset(crt[me].Password, 0, 11);
                        memset(crt[me].Key, 0, 10*sizeof(int));
                        crt[K].v=0;
                    }
                    free(crt);
                    return 1;
                }
                printf("\n");
                pv=((crt[K].v+crt[K].Key[0]+crt[K].Key[1]+crt[K].Key[2]+crt[K].Key[3]+crt[K].Key[4]+crt[K].Key[5]+crt[K].Key[6]+crt[K].Key[7]+crt[K].Key[8]+crt[K].Key[9])/11);
                if((prmr = PermuteDataInFile(TempFile, pv, 2)) == 0){
                    free(crt[K].InputFileName);
                    fclose(crt[K].InputFile);
                    fclose(crt[K].OutputFile);
                    fclose(TempFile);
                    RemoveFile(crt[K].OutputFileName);
                    RemoveFile(TempFileName);
                    free(crt[K].OutputFileName);
                    free(TempFileName);
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL, "[ ERROR ] DECRYPTION FAILED(PERMUTTING GONE WRONG)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    else{
                        MessageBox(NULL, "[ ERROR ] LE DECHIFFREMENT A ECHOUE(LA PERMUTATION S'EST MAL DEROULEE)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    for(me=0;me<nb;me++){
                        memset(crt[me].Password, 0, 11);
                        memset(crt[me].Key, 0, 10*sizeof(int));
                        crt[K].v=0;
                    }
                    free(crt);
                    return 1;
                }
                i=0;
                while((c=getc(TempFile)) != EOF){
                    i+=1;
                    if(i%10==0){
                        c=c+crt[K].Key[0];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[0]=crt[K].Key[0]+(crt[K].v-3);
                    }
                    else if(i%10==1){
                        c=c+crt[K].Key[1];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[1]=crt[K].Key[1]+(crt[K].v-3);
                    }
                    else if(i%10==2){
                        c=c+crt[K].Key[2];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[2]=crt[K].Key[2]+(crt[K].v-3);
                    }
                    else if(i%10==3){
                        c=c+crt[K].Key[3];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[3]=crt[K].Key[3]+(crt[K].v-3);
                    }
                    else if(i%10==4){
                        c=c+crt[K].Key[4];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[4]=crt[K].Key[4]+(crt[K].v-3);
                    }
                    else if(i%10==5){
                        c=c+crt[K].Key[5];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[5]=crt[K].Key[5]+(crt[K].v-3);
                    }
                    else if(i%10==6){
                        c=c+crt[K].Key[6];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[6]=crt[K].Key[6]+(crt[K].v-3);
                    }
                    else if(i%10==7){
                        c=c+crt[K].Key[7];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[7]=crt[K].Key[7]+(crt[K].v-3);
                    }
                    else if(i%10==8){
                        c=c+crt[K].Key[8];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[8]=crt[K].Key[8]+(crt[K].v-3);
                    }
                    else{
                        c=c+crt[K].Key[9];
                        fputc(c, crt[K].OutputFile);
                        crt[K].Key[9]=crt[K].Key[9]+(crt[K].v-3);
                    }
                }
                fclose(TempFile);
                RemoveFile(TempFileName);
                free(TempFileName);
                free(crt[K].OutputFileName);
                fclose(crt[K].InputFile);
                fclose(crt[K].OutputFile);
                if(MODE==2){
                    if(ani==1){
                        printf("\n");
                        if(lge==1){
                            TypingEffect("[ INFO ] NOW DECRYPTING");
                        }
                        else{
                            TypingEffect("[ INFO ] DECHIFFREMENT EN COURS");
                        }
                        LoadingEffect();
                        printf("\n");
                        MatrixSimulation();
                    }
                    printf("\n[ SUCCESS ] %s ",crt[K].InputFileName);
                    if(lge==1){
                        TypingEffect("DECRYPTED SUCCESSFULLY");
                    }
                    else{
                        TypingEffect("DECRYPTE AVEC SUCCES");
                    }
                    printf("\n");
                    memset(crt[K].Password, 0, 11);
                    memset(crt[K].Key, 0, 10*sizeof(int));
                    crt[K].v=0;
                    if(nb==K+1){
                        MessageBeep(MB_ICONASTERISK);
                        if(lge==1){
                            IndependentMessageBox("[ INFO ] ALL DONE", "FILE_CRYPTER");
                        }
                        else{
                            IndependentMessageBox("[ INFO ] TERMINE", "FILE_CRYPTER");
                        }
                        Sleep(2000);
                    }
                }
                if(MODE==4){
                    memset(crt[K].Password, 0, 11);
                    memset(crt[K].Key, 0, 10*sizeof(int));
                    crt[K].v=0;
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL,"[ SUCCESS ] DECRYPTION COMPLETED SUCCESSFULLY", "FILE_CRYPTER", MB_OK | MB_ICONINFORMATION);
                    }
                    else{
                        MessageBox(NULL,"[ SUCCESS ] DECHIFFREMENT EFFECTUE AVEC SUCCES", "FILE_CRYPTER", MB_OK | MB_ICONINFORMATION);
                    }
                }
                free(crt[K].InputFileName);
            }
            free(crt);
            if(MODE==2){
                do{
                    con=1;
                    if(lge==1){
                        printf("\nDO YOU WANT TO PERFORM ANOTHER OPERATION?\n[1] YES\n[0] EXIT");
                    }
                    else{
                        printf("\nVOULEZ-VOUS EFFECTUEZ UNE AUTRE OPERATION?\n[1] OUI\n[0] QUITTER");
                    }
                    printf("\ncipherflow> ");
                    if(scanf("%d",&res)!=1){
                        if(lge==1){
                            printf("\n[ ERROR ] ENTER A NUMBER BETWEEN 1 AND 0");
                        }
                        else{
                            printf("\n[ ERROR ] ENTRER UN NOMBRE ENTRE 1 ET 0");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                    }
                }while(con!=1 || (res!=1 && res!=0));
                system("cls");
            }
        }
        else if(MODE==5){
            if(lge==1){
                TypingEffect("#############################################        5-> FILE TRANSFER         #########################################");
            }
            else{
                TypingEffect("##############################################   5-> TRANSFERT DE FICHIER(S)   #########################################");
            }
            if(ani==1){
                DynamicColor();
            }
            char TRANSFER;
            int Port, scon;
            FILE* File;
            WSADATA wsa;
            SOCKET s;
            do{
                con=1;
                if(lge==1){
                    printf("\n\n");
                    TypingEffect("#############################################        [S]-> SEND FILE(S)        #########################################");
                    printf("\n\n");
                    TypingEffect("#############################################       [R]-> RECEIVE FILE(S)      #########################################");
                    printf("\ncipherflow> ");
                }
                else{
                    printf("\n\n");
                    TypingEffect("############################################   [E]-> ENVOYER UN/DES FICHIER(S)   #######################################");
                    printf("\n\n");
                    TypingEffect("############################################   [R]-> RECEVOIR UN/DES FICHIER(S)  #######################################");
                    printf("\ncipherflow> ");
                }
                if(scanf(" %c",&TRANSFER) != 1){
                    if(lge==1){
                        printf("\n[ ERROR ] ENTER A CARACTER (S, E, R)");
                    }
                    else{
                        printf("\n[ ERROR ] ENTRER UN CARACTERE (S, E, R)");
                    }
                    while((clb=getchar()) != '\n' && clb != EOF);
                    con=0;
                }
                while((clb=getchar()) != '\n' && clb != EOF);
            }while(con!=1 || (TRANSFER!='S' && TRANSFER!='E' && TRANSFER!='R'));
            if(TRANSFER=='S' || TRANSFER=='E'){
                char *FileName, *FileInfo, *IP, filename[200], state[256];
                long file_len;
                struct in_addr addr;
                struct sockaddr_in server;
                int restart_sending;
                if(lge==1){
                    printf("\n");
                    TypingEffect("===============================================  CONNECTION TO RECEIVER  ===============================================");
                    printf("\n");
                }
                else{
                    printf("\n");
                    TypingEffect("===============================================  CONNEXION AU RECEPTEUR  ===============================================");
                    printf("\n");
                }
                do{
                    scon=1;
                    do{
                        con=1;
                        IP=NULL;
                        IP=calloc(16,sizeof(char));
                        if(IP==NULL){
                            if(lge==1){
                                printf("\n[ ERROR ] MEMORY ALLOCATION ERROR");
                                MessageBeep(MB_ICONHAND);
                                MessageBox(NULL, "[ ERROR ] SENDING FAILED(ALLOCATION ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                            }
                            else{
                                printf("\n[ ERROR ] ERREUR D'ALLOCATION DE MEMOIRE");
                                MessageBeep(MB_ICONHAND);
                                MessageBox(NULL, "[ ERROR ] L'ENVOI A ECHOUE(ERREUR D'ALLOCATION)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                            }
                            return 1;
                        }
                        if(lge==1){
                            printf("\nENTER THE RECEIVER IP(IPv4)");
                        }
                        else{
                            printf("\nENTRER L'IP DU RECEVEUR(IPv4)");
                        }
                        printf("\ncipherflow> ");
                        scanf(" %15s",IP);
                        while((clb=getchar()) != '\n' && clb != EOF);
                        if(InetPton(AF_INET, IP, &addr) != 1){
                            if(lge==1){
                                printf("\n[ ERROR ] INVALID IPv4 ADDRESS");
                            }
                            else{
                                printf("\n[ ERROR ] ADRESSE IPv4 INVALIDE");
                            }
                            con=0;
                        }
                    }while(con!=1);
                    do{
                        con=1;
                        if(lge==1){
                            printf("\nENTER THE SENDING PORT");
                        }
                        else{
                            printf("\nENTRER LE PORT D'ENVOI");
                        }
                        printf("\ncipherflow> ");
                        if(scanf("%d",&Port) != 1){
                            if(lge==1){
                                printf("\n[ ERROR ] INVALID PORT");
                            }
                            else{
                                printf("\n[ ERROR ] PORT INVALIDE");
                            }
                            con=0;
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                    }while(con!=1 || Port<1 || Port>65535);
                    if(lge==1){
                        printf("\n===========  SEND TO  ===========\n\nRECEIVER IP : %s\n\nPORT : %d\n",IP,Port);
                        printf("\n=================================\n");
                        printf("ENTER 1 TO CONFIRM");
                    }
                    else{
                        printf("\n=========== ENVOYER A ===========\n\nIP DU RECEVEUR : %s\n\nPORT : %d\n",IP,Port);
                        printf("\n=================================\n");
                        printf("ENTRER 1 POUR CONFIRMER");
                    }
                    printf("\ncipherflow> ");
                    if(scanf("%d",&scon)!=1){
                        scon=0;
                    }
                    while((clb=getchar()) != '\n' && clb != EOF);
                }while(scon!=1);
                if(lge==1){
                    printf("\n");
                    TypingEffect("[ INFO ] INITIALIZING NETWORK");
                }
                else{
                    printf("\n");
                    TypingEffect("[ INFO ] INITIALISATION DU RESEAU");
                }
                if(ani==1){
                    LoadingEffect();
                }
                if(WSAStartup(MAKEWORD(2,2), &wsa) == 0){
                    if(lge==1){
                        printf("\n");
                        TypingEffect("[ INFO ] SUCCESSFUL INITIALIZATION");
                    }
                    else{
                        printf("\n");
                        TypingEffect("[ INFO ] INITIALISATION REUSSIE");
                    }
                }
                else{
                    if(lge==1){
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "[ ERROR ] ERROR DURING NETWORK INITIALIZATION", "FILE_CRYPTER", MB_OK | MB_ICONERROR);
                    }
                    else{
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "[ ERROR ] ERREUR LORS DE L'INITIALISATION DU RESEAU", "FILE_CRYPTER", MB_OK | MB_ICONERROR);
                    }
                    free(IP);
                    res=1;
                    printf("\n");
                    continue;
                }
                if(lge==1){
                    printf("\n");
                    TypingEffect("[ INFO ] CREATING SOCKET");
                }
                else{
                    printf("\n");
                    TypingEffect("[ INFO ] CREATION DU SOCKET");
                }
                if(ani==1){
                    LoadingEffect();
                }
                s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                if(s == INVALID_SOCKET){
                    if(lge==1){
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "[ ERROR ] ERROR DURING SOCKET CREATION", "FILE_CRYPTER", MB_OK | MB_ICONERROR);
                    }
                    else{
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "[ ERROR ] ERREUR LORS DE LA CREATION DU SOCKET", "FILE_CRYPTER", MB_OK | MB_ICONERROR);
                    }
                    free(IP);
                    WSACleanup();
                    res=1;
                    printf("\n");
                    continue;
                }
                else{
                    if(lge==1){
                        printf("\n");
                        TypingEffect("[ INFO ] SOCKET SUCCESFULLY CREATED");
                    }
                    else{
                        printf("\n");
                        TypingEffect("[ INFO ] SOCKET CREE AVEC SUCCES");
                    }
                }
                memset(&server, 0, sizeof(server));
                server.sin_family = AF_INET;
                server.sin_port = htons(Port);
                InetPton(AF_INET, IP, &server.sin_addr);
                if(lge==1){
                    MessageBox(NULL, "[ IMPORTANT ] THE RECEIVER SHOULD BE IN RECEPTION MODE", "FILE_CRYPTER", MB_OK | MB_ICONINFORMATION);
                }
                else{
                    MessageBox(NULL, "[ IMPORTANT ] LE RECEVEUR DOIT ETRE EN MODE RECEPTION", "FILE_CRYPTER", MB_OK | MB_ICONINFORMATION);
                }
                struct sockaddr_in addres;
                char hostname[NI_MAXHOST];
                memset(&addres, 0, sizeof(addres));
                addres.sin_family = AF_INET;
                inet_pton(AF_INET, IP, &addres.sin_addr);
                int resulte = getnameinfo((struct sockaddr*)&addres, sizeof(addres), hostname, sizeof(hostname), NULL, 0, 0);
                if(resulte != 0){
                    strcpy(hostname,"Unknown");
                }
                if(lge==1){
                    printf("\n\n");
                    TypingEffect("==================  CONNECTING TO  ==================");
                    printf("\n\nDEVICE NAME : %s\nIP : %s\nPort : %d\n\n=====================================================\n", hostname, IP, Port);
                }
                else{
                    printf("\n\n");
                    TypingEffect("===================  CONNEXION A  ===================");
                    printf("\n\nNOM DE L'APPAREIL : %s\nIP : %s\nPort : %d\n\n=====================================================\n", hostname, IP, Port);
                }
                if(ani==1){
                    LoadingEffect();
                }
                if(lge==1){
                    IndependentMessageBox("[ INFO ] WAIT WHILE THE RECEIVER ACCEPTS THE CONNECTION REQUEST.", "FILE_CRYPTER");
                }
                else{
                    IndependentMessageBox("[ INFO ] VEUILLEZ PATIENTER LE TEMPS QUE LE RECEVEUR ACCEPTE LA DEMANDE DE CONNEXION.", "FILE_CRYPTER");
                }
                if(connect(s, (struct sockaddr *)&server, sizeof(server)) == 0){
                    if(lge==1){
                        printf("\n");
                        TypingEffect("[ INFO ] CONNECTION ESTABLISHED");
                    }
                    else{
                        printf("\n");
                        TypingEffect("[ INFO ] CONNEXION ETABLIE");
                    }
                }
                else{
                    if(lge==1){
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "[ ERROR ] CONNECTION FAILED", "FILE_CRYPTER", MB_OK | MB_ICONERROR);
                        printf("\nERROR CODE : %d",WSAGetLastError());
                        if(WSAGetLastError()==10061){
                            printf("(THE SERVER IS NOT RUNNING OR LISTENING ON THIS PORT)");
                        }
                        else if(WSAGetLastError()==10060){
                            printf("(NETWORK OR FIREWALL PROBLEM)");
                        }
                        else if(WSAGetLastError()==10065){
                            printf("(HOST UNREACHABLE(BAD IP ADRESS))");
                        }
                        else if(WSAGetLastError()==10051){
                            printf("(NETWORK UNREACHABLE)");
                        }
                        else if(WSAGetLastError()==10049){
                            printf("(INVALID ADRESS)");
                        }
                        else if(WSAGetLastError()==10047){
                            printf("(UNSUPPORTED IP ADDRESS FAMILY)");
                        }
                        else if(WSAGetLastError()==10056){
                            printf("(CONNECTION ALREADY ESTABLISHED ON THIS SOCKET(ALREADY CONNECTED))");
                        }
                        else if(WSAGetLastError()==10022){
                            printf("(INVALID PARAMETER)");
                        }
                        else if(WSAGetLastError()==10038){
                            printf("(THIS IS NOT A SOCKET)");
                        }
                    }
                    else{
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "[ ERROR ] ECHEC DE LA CONNEXION", "FILE_CRYPTER", MB_OK | MB_ICONERROR);
                        printf("\nCODE D'ERREUR: %d",WSAGetLastError());
                        if(WSAGetLastError()==10061){
                            printf("(LE SERVEUR N'EST PAS LANCE OU N'ECOUTE PAS SUR CE PORT(CONNEXION REFUSEE))");
                        }
                        else if(WSAGetLastError()==10060){
                            printf("(PROBLEME RESEAU(DELAI DEPASSE) OU PARE-FEU)");
                        }
                        else if(WSAGetLastError()==10065){
                            printf("(HOTE INACCESSIBLE(MAUVAISE ADRESSE IP))");
                        }
                        else if(WSAGetLastError()==10051){
                            printf("(RESEAU INACCESSIBLE)");
                        }
                        else if(WSAGetLastError()==10049){
                            printf("(ADRESSE INVALIDE)");
                        }
                        else if(WSAGetLastError()==10047){
                            printf("(FAMILLE D'ADRESSES NON SUPPORTEE)");
                        }
                        else if(WSAGetLastError()==10056){
                            printf("(CONNEXION DEJA ETABLIE SUR CETTE SOCKET(DEJA CONNECTE))");
                        }
                        else if(WSAGetLastError()==10022){
                            printf("(PARAMETRE INVALIDE)");
                        }
                        else if(WSAGetLastError()==10038){
                            printf("(CE N'EST PAS UNE SOCKET)");
                        }
                    }
                    free(IP);
                    closesocket(s);
                    WSACleanup();
                    res=1;
                    printf("\n");
                    continue;
                }
                if(lge==1){
                    printf("\n");
                    TypingEffect("===================================================  FILE SELECTION  ===================================================");
                    printf("\n");
                }
                else{
                    printf("\n");
                    TypingEffect("================================================= SELECTION DU FICHIER =================================================");
                    printf("\n");
                }
                do{
                    con=1;
                    FileName=calloc(200,sizeof(char));
                    if(FileName==NULL){
                        if(lge==1){
                            printf("\n[ ERROR ] MEMORY ALLOCATION ERROR");
                            MessageBeep(MB_ICONHAND);
                            MessageBox(NULL, "[ ERROR ] SENDING FAILED(ALLOCATION ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        else{
                            printf("\n[ ERROR ] ERREUR D'ALLOCATION DE MEMOIRE");
                            MessageBeep(MB_ICONHAND);
                            MessageBox(NULL, "[ ERROR ] L'ENVOI A ECHOUE(ERREUR D'ALLOCATION)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        WSACleanup();
                        closesocket(s);
                        free(IP);
                        return 1;
                    }
                    if(lge==1){
                        printf("\nENTER THE FULL PATH OF THE FILE YOU WANT TO SEND OR DRAG AND DROP IT HERE");
                    }
                    else{
                        printf("\nENTRER LE CHEMIN COMPLET DU FICHIER A ENVOYER OU GLISSER ET DEPOSER LE FICHIER ICI");
                    }
                    printf("\ncipherflow> ");
                    scanf(" %199[^\n]",FileName);
                    while((clb=getchar()) != '\n' && clb != EOF);
                    if(FileName[0]== '\'' || FileName[0]== '\"' ){
                        memmove(FileName, FileName + 1, strlen(FileName)+1);
                    }
                    if(FileName[strlen(FileName)-1]== '\'' || FileName[strlen(FileName)-1]== '\"' ){
                        FileName[strlen(FileName)-1]='\0';
                    }
                    if((File=fopen(FileName,"rb"))== NULL){
                        if(lge==1){
                            printf("\n[ ERROR ] FILE OPENING ERROR");
                        }
                        else{
                            printf("\n[ ERROR ] ERREUR D'OUVERTURE DU FICHIER");
                        }
                        free(FileName);
                        con=0;
                    }
                }while(con!=1);
                if(FileName[strlen(FileName)-1] == 'c'){
                    if(lge==1){
                        strcpy(state,"PROBABLY ENCRYPTED BY FILE CRYPTER(CIPHER FLOW SYSTEM)");
                    }
                    else{
                        strcpy(state,"PROBABLEMENT CHIFFRE PAR FILE CRYPTER(CIPHER FLOW SYSTEM)");
                    }
                }
                else{
                    strcpy(state,"NORMAL");
                    if(lge==1){
                        printf("\n[ IMPORTANT ] THE FILE YOU ARE ABOUT TO SEND ISN'T ENCRYPTED YET\nYOU SHOULD ENCRYPT IT FOR MORE SAFETY\nENTER 1 TO ENCRYPT THE FILE BEFORE SENDING AND ANOTHER NUMBER TO CONTINUE SENDING");
                    }
                    else{
                        printf("\n[ IMPORTANT ] LE FICHIER QUE VOUS VOULEZ ENVOYER N'EST PAS ENCORE CHIFFRE\nVOUS DEVRIEZ LE CHIFFRER POUR PLUS DE SECURITE\nENTRER 1 POUR CHIFFRER LE FICHIER AVANT D'EFFECTUER L'ENVOI ET N'IMPORTE QUEL AUTRE NOMBRE POUR CONTINUER L'ENVOI");
                    }
                    printf("\ncipherflow> ");
                    if(scanf("%d",&restart_sending) != 1){
                        restart_sending = 0;
                    }
                    while((clb=getchar()) != '\n' && clb != EOF);
                }
                if (restart_sending == 1){
                    WSACleanup();
                    closesocket(s);
                    free(IP);
                    free(FileName);
                    fclose(File);
                    res=1;
                    printf("\n");
                    continue;
                }
                if(fseek(File, 0, SEEK_END) !=0){
                    MessageBeep(MB_ICONEXCLAMATION);
                    if(lge==1){
                        IndependentMessageBox("[ ERROR ] FILE SENDING PROCESS MEET ISSUES", "FILE_CRYPTER");
                    }
                    else{
                        IndependentMessageBox("[ ERROR ] PROBLEME RENCONTREE LORS DE L'ENVOI DU FICHIER", "FILE_CRYPTER");
                    }
                    WSACleanup();
                    closesocket(s);
                    free(IP);
                    free(FileName);
                    fclose(File);
                    res=1;
                    printf("\n");
                    continue;
                }
                file_len = ftell(File);
                rewind(File);
                if(file_len <= 0){
                    MessageBeep(MB_ICONEXCLAMATION);
                    if(lge==1){
                        IndependentMessageBox("[ ERROR ] FILE SENDING PROCESS MEET ISSUES", "FILE_CRYPTER");
                    }
                    else{
                        IndependentMessageBox("[ ERROR ] PROBLEME RENCONTREE LORS DE L'ENVOI DU FICHIER", "FILE_CRYPTER");
                    }
                    WSACleanup();
                    closesocket(s);
                    free(IP);
                    free(FileName);
                    fclose(File);
                    res=1;
                    printf("\n");
                    continue;
                }
                FileInfo=calloc(700,sizeof(char));
                if(FileInfo==NULL){
                    MessageBeep(MB_ICONEXCLAMATION);
                    if(lge==1){
                        IndependentMessageBox("[ ERROR ] FILE SENDING PROCESS MEET ISSUES", "FILE_CRYPTER");
                    }
                    else{
                        IndependentMessageBox("[ ERROR ] PROBLEME RENCONTREE LORS DE L'ENVOI DU FICHIER", "FILE_CRYPTER");
                    }
                    WSACleanup();
                    closesocket(s);
                    free(IP);
                    free(FileName);
                    fclose(File);
                    Sleep(3000);
                    return 1;
                }
                char *last = strrchr(FileName, '\\');
                if(last != NULL){
                    sprintf(filename, "%s", last+1);
                }
                else{
                    last = strrchr(FileName, '/');
                    if(last != NULL)
                        sprintf(filename, "%s", last+1);
                    else
                        strcpy(filename, FileName);
                }
                if(lge==1){
                    sprintf(FileInfo, "=========  RECEPTION OF   =========\nFILENAME : %s\n\nSIZE : %ld OCTETS\n\nSTATE : %s", filename, file_len, state);
                }
                else{
                    sprintf(FileInfo, "=========   RECEPTION DE  =========\nNOM DU FICHIER : %s\n\nTAILLE : %ld OCTETS\n\nETAT : %s", filename, file_len, state);
                }
                if(lge==1){
                    printf("\n[ INFO ] THE RECEPTION KEY IS : %zu", strlen(FileInfo));
                }
                else{
                    printf("\n[ INFO ] LA CLE DE RECEPTION EST : %zu", strlen(FileInfo));
                }
                if(SendAll(s, FileInfo, strlen(FileInfo)) == -1){
                    MessageBeep(MB_ICONERROR);
                    if(lge==1){
                        printf("\n[ ERROR ] FILE INFO SENDING PROCESS MEET ISSUES : %d",WSAGetLastError());
                    }
                    else{
                        printf("\n[ ERROR ] PROBLEME RENCONTRE LORS DE L'ENVOI DES INFO DU FICHIER : %d",WSAGetLastError());
                    }
                    WSACleanup();
                    closesocket(s);
                    free(IP);
                    free(FileName);
                    fclose(File);
                    free(FileInfo);
                    res=1;
                    printf("\n");
                    continue;
                }
                free(FileInfo);
                if(SendFile(s, File, (uint64_t)file_len) == -1){
                    MessageBeep(MB_ICONERROR);
                    if(lge==1){
                        printf("\n[ ERROR ] FILE SENDING PROCESS MEET ISSUES : %d",WSAGetLastError());
                    }
                    else{
                        printf("\n[ ERROR ] PROBLEME RENCONTRE LORS DE L'ENVOI DU FICHIER : %d",WSAGetLastError());
                    }
                    WSACleanup();
                    rewind(File);
                    closesocket(s);
                    free(IP);
                    free(FileName);
                    fclose(File);
                    res=1;
                    printf("\n");
                    continue;
                }
                else{
                    if(lge==1){
                        printf("\n[ SUCCESS ] %s SENT SUCCESFULLY", FileName);
                    }
                    else{
                        printf("\n[ SUCCESS ] %s ENVOYE AVEC SUCCES", FileName);
                    }
                }
                rewind(File);
                closesocket(s);
                free(IP);
                WSACleanup();
                fclose(File);
                free(FileName);
            }
            else if(TRANSFER=='R'){
                struct sockaddr_in server;
                struct sockaddr_in client_addr;
                socklen_t len = sizeof(client_addr);
                char ip[INET_ADDRSTRLEN], *Folder, *FileInfo, Taille[100];
                int rcon, result, acceptfile, extr, extract = 0;
                size_t recv_code;
                SOCKET client_socket;
                if(lge==1){
                    printf("\n");
                    TypingEffect("================================================= SERVER CONFIGURATION =================================================");
                    printf("\n");
                }
                else{
                    printf("\n");
                    TypingEffect("========================================= CONFIGURATION DU SERVEUR DE RECEPTION ========================================");
                    printf("\n");
                }
                do{
                    con=1;
                    if(lge==1){
                        printf("\nENTER THE LISTENING PORT\n[SUGGESTED PORT : 5000, 5001, 6000, 7000, 7777, 8000, 8080, 8081, 8888, 9000, 9090, 10000, 12000, 15000, 20000, 30000]");
                    }
                    else{
                        printf("\nENTRER LE PORT D'ECOUTE\n[PORT SUGGEREES : 5000, 5001, 6000, 7000, 7777, 8000, 8080, 8081, 8888, 9000, 9090, 10000, 12000, 15000, 20000, 30000]");
                    }
                    printf("\ncipherflow> ");
                    if(scanf("%d",&Port) != 1){
                        if(lge==1){
                            printf("\n[ ERROR ] INVALID PORT");
                        }
                        else{
                            printf("\n[ ERROR ] PORT INVALIDE");
                        }
                        con=0;
                    }
                    while((clb=getchar()) != '\n' && clb != EOF);
                }while(con!=1 || Port<1 || Port>65535);
                if(lge==1){
                        printf("\n");
                        TypingEffect("[ INFO ] INITIALIZING NETWORK");
                }
                else{
                    printf("\n");
                    TypingEffect("[ INFO ] INITIALISATION DU RESEAU");
                }
                if(ani==1){
                    LoadingEffect();
                }
                if(WSAStartup(MAKEWORD(2,2), &wsa) == 0){
                    if(lge==1){
                        printf("\n");
                        TypingEffect("[ INFO ] SUCCESSFUL INITIALIZATION");
                    }
                    else{
                        printf("\n");
                        TypingEffect("[ INFO ] INITIALISATION REUSSIE");
                    }
                }
                else{
                    if(lge==1){
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "[ ERROR ] ERROR DURING NETWORK INITIALIZATION", "FILE_CRYPTER", MB_OK | MB_ICONERROR);
                    }
                    else{
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "[ ERROR ] ERREUR LORS DE L'INITIALISATION DU RESEAU", "FILE_CRYPTER", MB_OK | MB_ICONERROR);
                    }
                    res=1;
                    printf("\n");
                    continue;
                }
                if(lge==1){
                    printf("\n");
                    TypingEffect("[ INFO ] CREATING SOCKET");
                }
                else{
                    printf("\n");
                    TypingEffect("[ INFO ] CREATION DU SOCKET");
                }
                if(ani==1){
                    LoadingEffect();
                }
                s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
                if(s == INVALID_SOCKET){
                    if(lge==1){
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "[ ERROR ] ERROR DURING SOCKET CREATION", "FILE_CRYPTER", MB_OK | MB_ICONERROR);
                    }
                    else{
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "[ ERROR ] ERREUR LORS DE LA CREATION DU SOCKET", "FILE_CRYPTER", MB_OK | MB_ICONERROR);
                    }
                    WSACleanup();
                    res=1;
                    printf("\n");
                    continue;
                }
                else{
                    if(lge==1){
                        printf("\n");
                        TypingEffect("[ INFO ] SOCKET SUCCESFULLY CREATED");
                    }
                    else{
                        printf("\n");
                        TypingEffect("[ INFO ] SOCKET CREE AVEC SUCCES");
                    }
                }
                server.sin_family = AF_INET;
                server.sin_port = htons(Port);
                server.sin_addr.s_addr = htonl(INADDR_ANY);
                if(lge==1){
                    printf("\n");
                    TypingEffect("[ INFO ] BINDING NOW");
                }
                else{
                    printf("\n");
                    TypingEffect("[ INFO ] LIAISON EN COURS");
                }
                if(ani==1){
                    LoadingEffect();
                }
                if(bind(s, (struct sockaddr *)&server, sizeof(server)) == 0){
                    if(lge==1){
                        printf("\n");
                        TypingEffect("[ INFO ] BINDING DONE");
                    }
                    else{
                        printf("\n");
                        TypingEffect("[ INFO ] LIAISON REUSSI");
                    }
                }
                else{
                    if(lge==1){
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "[ ERROR ] BINDING FAILED", "FILE_CRYPTER", MB_OK | MB_ICONERROR);
                        printf("\nERROR CODE : %d ",WSAGetLastError());
                        if(WSAGetLastError()==10048){
                            printf("(THE PORT IS ALREADY USED)");
                        }
                        else if(WSAGetLastError()==10013){
                            printf("(ACCESS DENIED)");
                        }
                    }
                    else{
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "[ ERROR ] ECHEC DU BIND", "FILE_CRYPTER", MB_OK | MB_ICONERROR);
                        printf("\nCODE D'ERREUR: %d",WSAGetLastError());
                        if(WSAGetLastError()==10048){
                            printf("(LE PORT EST DEJA UTILISE)");
                        }
                        else if(WSAGetLastError()==10013){
                            printf("(ACCES REFUSE)");
                        }
                    }
                    closesocket(s);
                    WSACleanup();
                    res=1;
                    printf("\n");
                    continue;
                }
                printf("\n========================================\n||                                    ||\n||       ");
                if(lge == 1){
                    TypingEffect("RECEPTION MODE");
                }
                else{
                    TypingEffect("MODE RECEPTION");
                }
                printf("               ||\n||                                    ||\n========================================\n\n");
                if(lge == 1){
                    TypingEffect("DESKTOP NAME : ");
                }
                else{
                    TypingEffect("NOM DE L'ORDINATEUR : ");
                }
                char ComputerName[MAX_COMPUTERNAME_LENGTH + 1];
                DWORD Size = sizeof(ComputerName);
                if(GetComputerNameA(ComputerName, &Size)){
                    printf("%s\n\n", ComputerName);
                }
                else{
                    printf("Unknown\n\n");
                }
                if(lge == 1){
                    printf("IP ADDRESS :\n\n\t");
                }
                else{
                    printf("IP DISPONIBLES :\n\n\t");
                }
                struct addrinfo hints;
                struct addrinfo *resulte;
                struct addrinfo *ptr;
                ZeroMemory(&hints, sizeof(hints));
                hints.ai_family = AF_INET;
                hints.ai_socktype = SOCK_STREAM;
                if(getaddrinfo(ComputerName, NULL, &hints, &resulte) != 0){
                    if(lge == 1){
                        printf("\n[ ERROR ] ERROR WHILE GETTING IP : %d\n\t", WSAGetLastError());
                    }
                    else{
                        printf("\n[ ERROR ] ERREUR D'OBTENTION D'IP : %d\n\t", WSAGetLastError());
                    }
                }
                else{
                    for (ptr = resulte ;ptr != NULL; ptr = ptr ->ai_next){
                        struct sockaddr_in *addre;
                        addre = (struct sockaddr_in *)ptr ->ai_addr;
                        printf("%s\n\t", inet_ntoa(addre->sin_addr));
                    }
                    freeaddrinfo(resulte);
                }
                printf("\nPORT : %d\n\n========================================\n",Port);
                if(listen(s, SOMAXCONN) == 0){
                    if(lge==1){
                        printf("\n");
                        TypingEffect("[ INFO ] WAITING FOR CONNECTION");
                    }
                    else{
                        printf("\n");
                        TypingEffect("[ INFO ] EN ATTENTE D'UNE CONNEXION");
                    }
                }
                else{
                    if(lge==1){
                        printf("\n[ ERROR ] ERROR WHEN LISTENING : %d",WSAGetLastError());
                    }
                    else{
                        printf("\n[ ERROR ] ERREUR LORS DE L'ECOUTE : %d",WSAGetLastError());
                    }
                    closesocket(s);
                    WSACleanup();
                    res=1;
                    printf("\n");
                    continue;
                }
                if(ani==1){
                    LoadingEffect();
                }
                if(lge==1){
                    IndependentMessageBox("[ INFO ] WAIT WHILE LOOKING FOR A CONNECTION REQUEST.", "FILE_CRYPTER");
                }
                else{
                    IndependentMessageBox("[ INFO ] VEUILLEZ PATIENTER LE TEMPS QU'ON RECHERCHE UNE DEMANDE DE CONNEXION.", "FILE_CRYPTER");
                }
                struct sockaddr_in addres;
                char hostname[NI_MAXHOST];
                do{
                    rcon = 1;
                    client_socket = accept(s, (struct sockaddr *)&client_addr, &len);
                    if(client_socket == INVALID_SOCKET){
                        if(lge==1){
                            printf("\n[ ERROR ] ERROR WHILE ACCEPTING : %d",WSAGetLastError());
                        }
                        else{
                            printf("\n[ ERROR ] PROBLEME RENCONTRE LORS DE LA CONNECTION : %d",WSAGetLastError());
                        }
                        rcon=0;
                    }
                    if(rcon!=0){
                        inet_ntop(AF_INET, &client_addr.sin_addr, ip, sizeof(ip));
                        memset(&addres, 0, sizeof(addres));
                        addres.sin_family = AF_INET;
                        inet_pton(AF_INET, ip, &addres.sin_addr);
                        int resulte = getnameinfo((struct sockaddr*)&addres, sizeof(addres), hostname, sizeof(hostname), NULL, 0, 0);
                        if(resulte != 0){
                            strcpy(hostname,"Unknown");
                        }
                        if(lge==1){
                            printf("\n[ INFO ] INCOMING CONNECTION DETECTED\n\n==================  CONNECTION INFO  ==================\n\nDEVICE NAME : %s\n\nIP : %s \n\n=======================================================\nENTER 1 TO ACCEPT THE CONNECTION",hostname, ip);
                        }
                        else{
                            printf("\n[ INFO ] CONNECTION ENTRANTE DETECTE\n\n============== INFORMATIONS DE CONNECTION ==============\n\nNOM DE L'APPAREIL : %s\n\nIP : %s \n\n=======================================================\nENTRER 1 POUR ACCEPTER LA CONNEXION",hostname, ip);
                        }
                        printf("\ncipherflow> ");
                        if(scanf("%d",&rcon)!=1){
                            rcon=0;
                            closesocket(client_socket);
                        }
                        else{
                            if(rcon!=1){
                                closesocket(client_socket);
                            }
                        }
                    }
                    while((clb=getchar()) != '\n' && clb != EOF);
                }while(rcon!=1);
                if(lge==1){
                    printf("\n[ INFO ] CLIENT CONNECTED SUCCESSFULLY");
                }
                else{
                    printf("\n[ INFO ] CLIENT CONNECTE AVEC SUCCES");
                }
                if(lge==1){
                    printf("\n");
                    TypingEffect("=============================================  RECEPTION FOLDER SELECTION  =============================================");
                    printf("\n");
                }
                else{
                    printf("\n");
                    TypingEffect("=========================================== SELECTION DU DOSSIER DE RECEPTION ==========================================");
                    printf("\n");
                }
                do{
                    con=1;
                    Folder=calloc(400,sizeof(char));
                    if(Folder==NULL){
                        if(lge==1){
                            printf("\n[ ERROR ] MEMORY ALLOCATION ERROR");
                            MessageBeep(MB_ICONHAND);
                            MessageBox(NULL, "[ ERROR ] RECEPTION FAILED(ALLOCATION ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        else{
                            printf("\n[ ERROR ] ERREUR D'ALLOCATION DE MEMOIRE");
                            MessageBeep(MB_ICONHAND);
                            MessageBox(NULL, "[ ERROR ] LA RECEPTION A ECHOUE(ERREUR D'ALLOCATION)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        closesocket(client_socket);
                        closesocket(s);
                        WSACleanup();
                        return 1;
                    }
                    if(lge==1){
                        printf("\nENTER THE FULL PATH OF AN RANDOM FILE FROM FOLDER IN WHICH YOU WOULD LIKE TO RECEIVE FILE (YOU CAN DRAG AND DROP THE FILE INTO THE CONSOLE)(THIS RANDOM FILE WILL NOT BE MODIFIED)");
                    }
                    else{
                        printf("\nENTRER LE CHEMIN COMPLET D'UN FICHIER ALEATOIRE DU DOSSIER DANS LEQUEL VOUS SOUHAITEZ RECEVOIR LE FICHIER(VOUS POUVEZ GLISSER ET DEPOSER LE FICHIER DANS LA CONSOLE)(CE FICHIER ALEATOIRE NE SERA PAS MODIFIER)");
                    }
                    printf("\ncipherflow> ");
                    scanf(" %199[^\n]",Folder);
                    while((clb=getchar()) != '\n' && clb != EOF);
                    if(Folder[0] == '\'' || Folder[0] == '\"' ){
                        memmove(Folder, Folder + 1, strlen(Folder)+1);
                    }
                    if(Folder[strlen(Folder)-1]== '\'' || Folder[strlen(Folder)-1]== '\"' ){
                        Folder[strlen(Folder)-1]='\0';
                    }
                    if(FileExistanceChecker(Folder)==1){
                        if(lge==1){
                            printf("\n[ ERROR ] ENTER A VALID PATH");
                        }
                        else{
                            printf("\n[ ERROR ] ENTRER UN CHEMIN VALIDE");
                        }
                        free(Folder);
                        con=0;
                    }
                    else{
                        char *last = strrchr(Folder, '\\');
                        if(last != NULL){
                            *(last+1) = '\0';
                        }
                        else{
                            last = strrchr(Folder, '/');
                            if(last != NULL){
                                *(last+1) = '\0';
                            }
                            else{
                                if(lge==1){
                                    printf("\n[ ERROR ] ENTER A ABSOLUTE PATH");
                                }
                                else{
                                    printf("\n[ ERROR ] ENTRER UN CHEMIN ABSOLUE");
                                }
                                free(Folder);
                                con=0;
                            }
                        }
                    }
                }while(con!=1);
                do{
                    con=1;
                    if(lge==1){
                        printf("\nENTER THE RECEPTION KEY");
                    }
                    else{
                        printf("\nENTRER LA CLE DE RECEPTION");
                    }
                    printf("\ncipherflow> ");
                    if(scanf("%zu",&recv_code) != 1){
                        if(lge==1){
                            printf("\n[ ERROR ] INVALID RECEPTION CODE");
                        }
                        else{
                            printf("\n[ ERROR ] CODE DE RECEPTION INVALIDE");
                        }
                        con=0;
                    }
                    while((clb=getchar()) != '\n' && clb != EOF);
                    if(con!=0){
                        if(lge==1){
                            printf("\n[ WARNING ] A FAKE RECEPTION KEY CAN CAUSE DATA CORUPTION WHILE RECEIVING\nENTER 1 TO CONFIRM THE KEY");
                        }
                        else{
                            printf("\n[ WARNING ] UNE FAUSSE CLE DE RECEPTION PEUT ENTRAINER UNE CORRUPTION DES DONNEES LORS DE LA RECEPTION\nENTRER 1 POUR CONFIRMER LA CLE");
                        }
                        printf("\ncipherflow> ");
                        if(scanf("%d",&con)!=1){
                            con=0;
                        }
                    }
                    while((clb=getchar()) != '\n' && clb != EOF);
                }while(con!=1);
                FileInfo = calloc(700, sizeof(char));
                if(FileInfo==NULL){
                    if(lge==1){
                        printf("\n[ ERROR ] MEMORY ALLOCATION ERROR");
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "[ ERROR ] RECEPTION FAILED(ALLOCATION ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    else{
                        printf("\n[ ERROR ] ERREUR D'ALLOCATION DE MEMOIRE");
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "[ ERROR ] LA RECEPTION A ECHOUE(ERREUR D'ALLOCATION)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    free(Folder);
                    closesocket(client_socket);
                    closesocket(s);
                    WSACleanup();
                    return 1;
                }
                if(RecvAll(client_socket, FileInfo, recv_code) == -1){
                    if(lge==1){
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "[ ERROR ] ERROR DURING FILE INFO RECEPTION ", "FILE_CRYPTER", MB_OK | MB_ICONERROR);                    }
                    else{
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "[ ERROR ] ERREUR LORS DE LA RECEPTION DES INFO DU FICHIER", "FILE_CRYPTER", MB_OK | MB_ICONERROR);
                    }
                    free(Folder);
                    free(FileInfo);
                    closesocket(client_socket);
                    closesocket(s);
                    WSACleanup();
                    res=1;
                    printf("\n");
                    continue;
                }
                do{
                    con=1;
                    MessageBeep(MB_ICONQUESTION);
                    if(lge==1){
                        result = MessageBox(NULL, FileInfo, "FILE_CRYPTER", MB_YESNO | MB_ICONQUESTION | MB_TOPMOST);
                    }
                    else{
                        result = MessageBox(NULL, FileInfo, "FILE_CRYPTER", MB_YESNO | MB_ICONQUESTION | MB_TOPMOST);
                    }
                    if(result==IDYES){
                        acceptfile = 1;
                    }
                    else if(result==IDNO){
                        acceptfile = 0;
                    }
                    else{
                        con=0;
                    }
                }while(con!=1);
                if (acceptfile == 0){
                    free(Folder);
                    free(FileInfo);
                    closesocket(client_socket);
                    closesocket(s);
                    WSACleanup();
                    res = 1;
                    printf("\n\n");
                    continue;
                }
                for(extr = 0; extr < (int)strlen(FileInfo); extr++){
                    if(FileInfo[extr] == ':'){
                        extract += 1;
                    }
                    if(FileInfo[extr] == ':' && extract == 1){
                        extr += 2;
                        while(FileInfo[extr] != '\n'){
                            int leng = strlen(Folder);
                            Folder[leng] = FileInfo[extr];
                            Folder[leng + 1] = '\0';
                            extr += 1;
                        }
                    }
                    if(FileInfo[extr] == ':' && extract == 2){
                        extr += 2;
                        Taille[0] = '\0';
                        while(FileInfo[extr] != ' '){
                            Taille[strlen(Taille)] = FileInfo[extr];
                            Taille[strlen(Taille) + 1] = '\0';
                            extr += 1;
                        }
                        break;
                    }
                }
                if(FileExistanceChecker(Folder) == 0){
                    if(lge==1){
                        printf("\n[ INFO ] A FILE ALREADY EXISTS WITH THE SAME NAME AS THE ONE TO BE RECEIVED\nTHE RECEPTION WILL BE INTERRUPTED TO AVOID REMOVING OF EXISTING DATA");
                    }
                    else{
                        printf("\n[ INFO ] UN FICHIER EXISTE DEJA AVEC LE MEME NOM QUE CELUI A RECEVOIR\nLA RECEPTION SERA INTERROMPU POUR EVITER LA SUPPRESSION DE DONNEES EXISTANTES");
                    }
                    free(Folder);
                    free(FileInfo);
                    closesocket(client_socket);
                    closesocket(s);
                    WSACleanup();
                    res = 1;
                    printf("\n\n");
                    continue;
                }
                if((File=fopen(Folder,"wb"))== NULL){
                    if(lge==1){
                        printf("\n[ ERROR ] RECEPTION FILE OPENING ERROR");
                    }
                    else{
                        printf("\n[ ERROR ] ERREUR D'OUVERTURE DU FICHIER DE RECEPTION");
                    }
                    free(Folder);
                    free(FileInfo);
                    closesocket(client_socket);
                    closesocket(s);
                    WSACleanup();
                    res = 1;
                    printf("\n\n");
                    continue;
                }
                uint64_t taille = strtoull(Taille, NULL, 10);
                if(RecvFile(client_socket, File, taille) == -1){
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL, "[ ERROR ] ERROR DURING FILE RECEPTION ", "FILE_CRYPTER", MB_OK | MB_ICONERROR);                    }
                    else{
                        MessageBox(NULL, "[ ERROR ] ERREUR LORS DE LA RECEPTION DU FICHIER", "FILE_CRYPTER", MB_OK | MB_ICONERROR);
                    }
                    free(FileInfo);
                    fclose(File);
                    closesocket(client_socket);
                    remove(Folder);
                    free(Folder);
                    closesocket(s);
                    WSACleanup();
                    res=1;
                    printf("\n");
                    continue;
                }
                else{
                    if(lge == 1){
                        printf("\n[ SUCCESS ] %s RECEIVED SUCCESFULLY", Folder);
                    }
                    else{
                        printf("\n[ SUCCESS ] %s RECU AVEC SUCCES", Folder);
                    }
                }
                free(Folder);
                free(FileInfo);
                fclose(File);
                closesocket(client_socket);
                closesocket(s);
                WSACleanup();
            }
            do{
                con=1;
                if(lge==1){
                    printf("\nDO YOU WANT TO PERFORM ANOTHER OPERATION?\n[1] YES\n[0] EXIT");
                }
                else{
                    printf("\nVOULEZ-VOUS EFFECTUEZ UNE AUTRE OPERATION?\n[1] OUI\n[0] QUITTER");
                }
                printf("\ncipherflow> ");
                if(scanf("%d",&res)!=1){
                    if(lge==1){
                        printf("\n[ ERROR ] ENTER A NUMBER BETWEEN 1 AND 0");
                    }
                    else{
                        printf("\n[ ERROR ] ENTRER UN NOMBRE ENTRE 1 ET 0");
                    }
                    while((clb=getchar()) != '\n' && clb != EOF);
                    con=0;
                }
            }while(con!=1 || (res!=1 && res!=0));
            system("cls");
        }
        else if(MODE==6){
            printf("########################################################################################################################\n");
            TypingEffect("                                                 ABOUT CIPHERFLOW                                                       ");
            printf("\n########################################################################################################################\n\n");
            Info(lge);
            do{
                con=1;
                if(lge==1){
                    printf("\nWOULD YOU NOW LIKE TO ACCESS THE MAIN INTERFACE?\n[1] YES\n[0] EXIT");
                }
                else{
                    printf("\nVOUDRIEZ-VOUS MAINTENANT ACCEDER A L'INTERFACE PRINCIPALE?\n[1] OUI\n[0] QUITTER");
                }
                printf("\ncipherflow> ");
                if(scanf("%d",&res)!=1){
                    if(lge==1){
                        printf("\n[ ERROR ] ENTER A NUMBER BETWEEN 1 AND 0");
                    }
                    else{
                        printf("\n[ ERROR ] ENTRER UN NOMBRE ENTRE 1 ET 0");
                    }
                    while((clb=getchar()) != '\n' && clb != EOF);
                    con=0;
                }
            }while(con!=1 || (res!=1 && res!=0));
            system("cls");
            if(res==1){
                HomeOrMenu(0);
            }
        }
        else{
            if(lge==1){
                TypingEffect("###########################################      7-> EXIT            ###################################################");
            }
            else{
                TypingEffect("###########################################     7-> QUITTER          ###################################################");
            }
            if(ani==1){
                DynamicColor();
                printf("\n");
                if(lge==1){
                    TypingEffect("[ INFO ] NOW CLOSING");
                }
                else{
                    TypingEffect("[ INFO ] FERMETURE EN COURS");
                }
                LoadingEffect();
            }
        }
    }
    if(MODE==1 || MODE==2 || MODE==5 || MODE==6 || MODE==7){
        printf("\n");
        if(lge==1){
            TypingEffect("[ END ] SESSION ENDED. THANK YOU FOR USING CIPHER FLOW.");
        }
        else{
            TypingEffect("[ END ] SESSION TERMINEE. MERCI D'AVOIR UTILISE CIPHER FLOW.");
        }
        Sleep(2000*ani+1000);
    }
    return 0;
}
