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
#include <time.h>
int ani=0;
int lge=0;
typedef struct {
    char *msg;
    char *title;
} MsgData;

void TypingEffect(char *text){
    int i;
    for(i=0; text[i] != '\0'; i++){
        printf("%c",text[i]);
        fflush(stdout);
        Sleep(10*ani);
    }
}

void DynamicColor(){
    system("color 09");
    Sleep(200);
    system("color 0C");
    Sleep(200);
    system("color 0A");
    Sleep(200);
}

void LoadingEffect(){
    int j;
    for(j=0;j<3;j++){
        Sleep(200);
        printf(".");
        Sleep(200);
        printf(".");
        Sleep(200);
        printf(".");
        Sleep(200);
        printf("\b \b\b \b\b \b");
    }
}

int LeapYearChecking(int yea){
    return (yea % 4 == 0 && yea % 100 !=0) || (yea % 400 == 0);
}

int NumberOfDaysInMonth(int MON, int YEA){
    switch(MON) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            return 31;

        case 4: case 6: case 9: case 11:
            return 30;

        case 2:
            return LeapYearChecking(YEA) ? 29 : 28;
        default:
            return 0;
    }
}

void HomeOrMenu(int set){
    if(set==0){
        printf("\n");
        UINT originalCP = GetConsoleOutputCP();
        SetConsoleOutputCP(CP_UTF8);
        printf("========================================================================================================================\n");
        printf("======================");
        TypingEffect("███████╗██╗██████╗ ██╗  ██╗███████╗██████╗ ███████╗██╗      ██████╗ ██╗    ██╗");
        printf("====================\n======================");
        TypingEffect("██╔════╝██║██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝██║     ██╔═══██╗██║    ██║");
        printf("====================\n======================");
        TypingEffect("██║     ██║██████╔╝███████║█████╗  ██████╔╝█████╗  ██║     ██║   ██║██║ █╗ ██║");
        printf("====================\n======================");
        TypingEffect("██║     ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗██╔══╝  ██║     ██║   ██║██║███╗██║");
        printf("====================\n======================");
        TypingEffect("███████╗██║██║     ██║  ██║███████╗██║  ██║██║     ███████╗╚██████╔╝╚███╔███╔╝");
        printf("====================\n======================");
        TypingEffect("╚══════╝╚═╝╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝     ╚══════╝ ╚═════╝  ╚══╝╚══╝ ");
        SetConsoleOutputCP(originalCP);
        printf("====================\n================================================     ");
        TypingEffect("CIPHERFLOW SYSTEM v1.3");
        printf("    =========================================\n=============================================     ");
        TypingEffect("SECURE - DYNAMIC - SCHEDULED");
        printf("    ======================================\n");
    }
    if(set==1){
        if(lge==1){
            printf("========================================================================================================================\n===============================================     ");
            TypingEffect("[1] ENCRYPT FILE");
            printf("             =======================================\n===============================================     ");
            TypingEffect("[2] DECRYPT FILE");
            printf("             =======================================\n===============================================     ");
            TypingEffect("[3] SCHEDULE ENCRYPTION");
            printf("      =======================================\n===============================================     ");
            TypingEffect("[4] SCHEDULE DECRYPTION");
            printf("      =======================================\n===============================================     ");
            TypingEffect("[5] FILE TRANSFER      ");
            printf("      =======================================\n===============================================     ");
            TypingEffect("[6] INFO                     ");
            printf("=======================================\n===============================================     ");
            TypingEffect("[7] EXIT");
            printf("                     =======================================\n");
            TypingEffect("SELECT OPTION> ");
        }
        else{
            printf("========================================================================================================================\n==========================================     ");
            TypingEffect("[1] CHIFFRER UN/DES FICHIER(S)");
            printf("    =======================================\n==========================================     ");
            TypingEffect("[2] DECHIFFRER UN/DES FICHIER(S)");
            printf("  =======================================\n==========================================     ");
            TypingEffect("[3] PLANIFIER UN CHIFFREMENT");
            printf("      =======================================\n==========================================     ");
            TypingEffect("[4] PLANIFIER UN DECHIFFREMENT");
            printf("    =======================================\n==========================================     ");
            TypingEffect("[5] TRANSFERT DE FICHIER(S)");
            printf("       =======================================\n==========================================     ");
            TypingEffect("[6] INFO                          ");
            printf("=======================================\n==========================================     ");
            TypingEffect("[7] QUITTER");
            printf("                       =======================================\n");
            TypingEffect("SELECTIONNER UNE OPTION> ");
        }
    }
}
void DayOfWeek(char* dow, int day, int la){
    if(la==0){
        switch(day){
            case 0:
                strcpy(dow,"Dimanche");
                break;
            case 1:
                strcpy(dow,"Lundi");
                break;
            case 2:
                strcpy(dow,"Mardi");
                break;
            case 3:
                strcpy(dow,"Mercredi");
                break;
            case 4:
                strcpy(dow,"Jeudi");
                break;
            case 5:
                strcpy(dow,"Vendredi");
                break;
            case 6:
                strcpy(dow,"Samedi");
                break;
        }
    }
    else{
        switch(day){
            case 0:
                strcpy(dow,"Sunday");
                break;
            case 1:
                strcpy(dow,"Monday");
                break;
            case 2:
                strcpy(dow,"Tuesday");
                break;
            case 3:
                strcpy(dow,"Wednesday");
                break;
            case 4:
                strcpy(dow,"Thursday");
                break;
            case 5:
                strcpy(dow,"Friday");
                break;
            case 6:
                strcpy(dow,"Saturday");
                break;
        }
    }
}

int InputNumberOfFile(){
    int fcon, nbr, clb;
     do{
        fcon=1;
        if(lge==1){
            printf("\nENTER THE NUMBER OF FILE(S)");
        }
        else{
            printf("\nENTRER LE NOMBRE DE FICHIER(S)");
        }
        printf("\ncipherflow> ");
        if(scanf("%d",&nbr)!=1){
            if(lge==1){
                printf("\n[ ERROR ] ENTER A VALID NUMBER");
            }
            else{
                printf("\n[ ERROR ] ENTRER UN NOMBRE VALIDE");
            }
            while((clb=getchar()) != '\n' && clb != EOF);
            fcon=0;
        }
        if(fcon!=0){
            if(lge==1){
                printf("\nENTER 1 TO CONFIRM");
            }
            if(lge==0){
                printf("\nENTRER 1 POUR CONFIRMER");
            }
            printf("\ncipherflow> ");
            if(scanf("%d",&fcon)!=1){
                while((clb=getchar()) != '\n' && clb != EOF);
                fcon=0;
            }
        }
    }while(fcon!=1 || nbr<1);
    return nbr;
}

char AskForSamePasswordUse(){
    char frmdec;
    int result, fcon;
    do{
        fcon=1;
        MessageBeep(MB_ICONQUESTION);
        if(lge==1){
            result = MessageBox(NULL, "DO YOU WANT TO USE THE SAME PASSWORD AND VERSION FOR ALL FILE?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONQUESTION | MB_TOPMOST | MB_SETFOREGROUND);
        }
        else{
            result = MessageBox(NULL, "VOULEZ VOUS UTILISER LE MEME MOT DE PASSE ET LA MEME VERSION POUR TOUT LES FICHIERS?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONQUESTION | MB_TOPMOST | MB_SETFOREGROUND);
        }
        if(result==IDYES){
            frmdec='Y';
        }
        else if(result==IDNO){
            frmdec='N';
        }
        else{
            fcon=0;
        }
    }while(fcon!=1);
    return frmdec;
}

void SecurityLevel(char *pasw){
    int p, b, occ=0;
    for(b=0;b<10;b++){
        for(p=b+1;p<10;p++){
            if(pasw[p]==pasw[b]){
                occ+=1;
            }
        }
    }
    if(occ==0){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        if(lge==1){
            printf(" ULTRA-SECURE");
        }
        else{
            printf(" ULTRA-SECURISE");
        }
    }
    else if(occ==1){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,176,176,176,176);
        if(lge==1){
            printf(" VERY-SECURE");
        }
        else{
            printf(" TRéS-SECURISE");
        }
    }
    else if(occ<=3){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,176,176,176,176,176);
        if(lge==1){
            printf(" SECURE");
        }
        else{
            printf(" SECURISE");
        }
    }
    else if(occ<=6){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,176,176,176,176,176,176);
        if(lge==1){
            printf(" RELIABLE");
        }
        else{
            printf(" FIABLE");
        }
    }
    else if(occ<=10){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,176,176,176,176,176,176,176);
        if(lge==1){
            printf(" ADEQUATE");
        }
        else{
            printf(" ADEQUAT");
        }
    }
    else if(occ<=15){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,176,176,176,176,176,176,176,176);
        if(lge==1){
            printf(" MEDIUM");
        }
        else{
            printf(" MOYEN");
        }
    }
    else if(occ<=21){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,176,176,176,176,176,176,176,176,176);
        if(lge==1){
            printf(" WEAK");
        }
        else{
            printf(" FAIBLE");
        }
    }
    else if(occ<=28){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,176,176,176,176,176,176,176,176,176,176);
        if(lge==1){
            printf(" VERY-WEAK");
        }
        else{
            printf(" TRES-FAIBLE");
        }
    }
    else if(occ<=36){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,176,176,176,176,176,176,176,176,176,176,176);
        if(lge==1){
            printf(" FRAGILE");
        }
        else{
            printf(" FRAGILE");
        }
    }
    else if(occ<=45){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",176,176,176,176,176,176,176,176,176,176,176,176,176,176);
        if(lge==1){
            printf(" RISKY");
        }
        else{
            printf(" RISQUE");
        }
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            MessageBox(NULL,"[ WARNING ] THE PASSWORD ISN'T SECURED","FILE_CRYPTER",MB_OK | MB_ICONWARNING);
        }
        else{
            MessageBox(NULL,"[ WARNING ] LE MOT DE PASSE N'EST PAS SECURISE","FILE_CRYPTER",MB_OK | MB_ICONWARNING);
        }
    }
    return;
}
void InputPassword(char *pass){
    int fcon, siz, clb;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    do{
        fcon=1;
        if(lge==1){
            printf("\nENTER THE PASSWORD(10 CHARACTERS), IF THIS IS MORE THAN 10 ONLY THE FIRST 10 WILL BE CONSIDERED)");
            if(ani==1){
                printf("\ncipherflow(HIDE)> ");
            }
        }
        else{
            printf("\nENTRER LE MOT DE PASSE(10 CARACTERES), SI PLUS DE 10 SEUL LES 10 PREMIERS SERONT CONSIDERES)");
            if(ani==1){
                printf("\ncipherflow(MASQUEE)> ");
            }
        }
        if(ani==0){
            printf("\ncipherflow> ");
        }
        if(ani==1){
            SetConsoleTextAttribute(hConsole, 0);
            scanf(" %10[^\n]",pass);
            SetConsoleTextAttribute(hConsole, 10);
        }
        if(ani==0){
            scanf(" %10[^\n]",pass);
        }
        while((clb=getchar()) != '\n' && clb != EOF);
        siz=strlen(pass);
        if(siz!=10){
            fcon=0;
        }
        if(fcon!=0){
            SecurityLevel(pass);
        }
        if(fcon!=0){
            if(lge==1){
                printf("\n[ INFO ] YOU ENTERED :**********\nENTER 1 TO CONFIRM");
            }
            else{
                printf("\n[ INFO ] VOUS AVEZ ENTRE :**********\nENTRER 1 POUR CONFIRMER");
            }
            printf("\ncipherflow> ");
            if(scanf("%d",&fcon)!=1){
                while((clb=getchar()) != '\n' && clb != EOF);
                fcon=0;
            }
        }
    }while(fcon!=1);
}

int InputVersion(){
    int fcon, fv, clb;
     do{
        fcon=1;
        if(lge==1){
            printf("\nENTER THE CIPHER FLOW VERSION ASSOCIATED WITH THIS OPERATION\nAVAILABLE VERSIONS:\n- 1\n- ... \n- 15");
        }
        else{
            printf("\nENTRER LA VERSION DE CIPHER FLOW ASSOCIE A CETTE OPERATION\nVERSION DISPONIBLES:\n- 1\n- ... \n- 15");
        }
        printf("\ncipherflow> ");
        if(scanf("%d",&fv)!=1){
            if(lge==1){
                printf("\n[ ERROR ] ENTER A VALID NUMBER");
            }
            else{
                printf("\n[ ERROR ] ENTRER UN NOMBRE VALIDE");
            }
            while((clb=getchar()) != '\n' && clb != EOF);
            fcon=0;
            fv = 0;
        }
        if(fv<1 || fv>15){
            if(lge==1){
                printf("\nCHOOSE VERSION BETWEEN 1 AND 15");
            }
            if(lge==0){
                printf("\nCHOISISSEZ LA VERSION ENTRE 1 ET 15");
            }
            fcon=0;
        }
        if(fcon!=0){
            if(lge==1){
                printf("\nENTER 1 TO CONFIRM");
            }
            if(lge==0){
                printf("\nENTRER 1 POUR CONFIRMER");
            }
            printf("\ncipherflow> ");
            if(scanf("%d",&fcon)!=1){
                while((clb=getchar()) != '\n' && clb != EOF);
                fcon=0;
            }
        }
    }while(fcon!=1);
    return fv;
}

void AskForAnimation(){
    int resul, fcona;
    do{
        fcona=1;
        MessageBeep(MB_ICONQUESTION);
        if(lge==1){
            resul = MessageBox(NULL, "ENABLE ANIMATIONS ?", "FILE_CRYPTER", MB_YESNO | MB_ICONQUESTION);
        }
        else{
            resul = MessageBox(NULL, "ACTIVER LES ANIMATIONS ?", "FILE_CRYPTER", MB_YESNO | MB_ICONQUESTION);
        }
        if(resul==IDYES){
            ani=1;
        }
        else if(resul==IDNO){
            ani=0;
        }
        else{
            fcona=0;
        }
    }while(fcona!=1);
}

void LanguageChosing(int language){
    int resul, fcona;
    if(language==1){
        do{
            fcona=1;
            MessageBeep(MB_ICONQUESTION);
            resul = MessageBox(NULL, "EN/FR\nCONTINUE IN ENGLISH ?", "FILE_CRYPTER", MB_YESNO | MB_ICONQUESTION);
            if(resul==IDYES){
                lge=1;
            }
            else if(resul==IDNO){
                lge=0;
            }
            else{
                fcona=0;
            }
        }while(fcona!=1);
    }
    if(language==0){
        do{
            fcona=1;
            MessageBeep(MB_ICONQUESTION);
            resul = MessageBox(NULL, "FR/EN\nLANGUE PAR DEFAUT : FRANCAIS\nUTILISER COMME LANGUE D'AFFICHAGE?", "FILE_CRYPTER", MB_YESNO | MB_ICONQUESTION);
            if(resul==IDYES){
                lge=0;
            }
            else if(resul==IDNO){
                lge=1;
            }
            else{
                fcona=0;
            }
        }while(fcona!=1);
    }
}

int PermuteDataInFile(FILE* file, long prmcst, int act){
    long file_len;
    char *temp_string;
    if(prmcst < 0){
        prmcst=labs(prmcst);
    }
    if(fseek(file, 0, SEEK_END) !=0){
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            IndependentMessageBox("[ ERROR ] FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        }
        else{
            IndependentMessageBox("[ ERROR ] LA PERMUTATION DU FICHIER S'EST MAL PASSEE", "FILE_CRYPTER");
        }
        return 0;
    }
    file_len = ftell(file);
    rewind(file);
    if(file_len <= 0){
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            IndependentMessageBox("[ ERROR ] FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        }
        else{
            IndependentMessageBox("[ ERROR ] LA PERMUTATION DU FICHIER S'EST MAL PASSEE", "FILE_CRYPTER");
        }
        return 0;
    }
    temp_string=malloc(file_len);
    if(!temp_string){
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            IndependentMessageBox("[ ERROR ] FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        }
        else{
            IndependentMessageBox("[ ERROR ] LA PERMUTATION DU FICHIER S'EST MAL PASSEE", "FILE_CRYPTER");
        }
        return 0;
    }
    size_t nl = fread(temp_string, 1, file_len, file);
    rewind(file);
    if(nl != (size_t)file_len){
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            IndependentMessageBox("[ ERROR ] FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        }
        else{
            IndependentMessageBox("[ ERROR ] LA PERMUTATION DU FICHIER S'EST MAL PASSEE", "FILE_CRYPTER");
        }
        memset(temp_string, 0, file_len);
        free(temp_string);
        return 0;
    }
    if(act==1){
        char tmp;
        long jp=0, ip, step;
        if (file_len > 500000000){
            if(lge==1){
                IndependentMessageBox("[ INFO ] WARNING : BIG FILE DETECTED\nTHE PROCESSING WILL BE VERY LONG(DEPEND OF THE FILE SIZE),PLEASE WAIT", "FILE_CRYPTER");
            }
            else{
                IndependentMessageBox("[ INFO ] ATTENTION : GROS FICHIER DETECTE\nTRAITEMENT TRES LONG POSSIBLE(DEPEND DE LA TAILLE DU FICHIER),VEUILLEZ PATIENTER", "FILE_CRYPTER");
            }
            step = 50000;
        }
        else if (file_len > 100000000){
            if(lge==1){
                IndependentMessageBox("[ INFO ] LONG FILE DETECTED\nTHE PROCESSING WILL BE LONG,PLEASE WAIT", "FILE_CRYPTER");
            }
            else{
                IndependentMessageBox("[ INFO ] LONG FICHIER DETECTE\nTRAITEMENT LONG POSSIBLE,VEUILLEZ PATIENTER", "FILE_CRYPTER");
            }
            step = 10000;
        }
        for(ip=0; ip<file_len;ip++){
            jp=(ip+prmcst+jp) % file_len;
            tmp=temp_string[ip];
            temp_string[ip]=temp_string[jp];
            temp_string[jp]=tmp;
            if(file_len>100000000){
                if(ip%step == 0 || ip == file_len-1){
                    printf("\rPROGRESSION: %ld / %ld", ip+1, file_len);
                    fflush(stdout);
                }
            }
        }
    }
    else if(act==2){
        char tmp;
        long jp, ip, kp, step, cnt;
        if (file_len > 500000){
            if(lge==1){
                IndependentMessageBox("[ INFO ] WARNING : VERY BIG FILE DETECTED\nTHE PROCESSING WILL BE VERY VERY LONG(DEPEND OF THE FILE SIZE),PLEASE WAIT", "FILE_CRYPTER");
            }
            else{
                IndependentMessageBox("[ INFO ] ATTENTION : TRES GROS FICHIER DETECTE\nTRAITEMENT TRES TRES LONG POSSIBLE(DEPEND DE LA TAILLE DU FICHIER),VEUILLEZ PATIENTER", "FILE_CRYPTER");
            }
            step = 5000;
        }
        else if (file_len > 50000){
            if(lge==1){
                IndependentMessageBox("[ INFO ] WARNING : BIG FILE DETECTED\nTHE PROCESSING WILL BE VERY LONG(DEPEND OF THE FILE SIZE),PLEASE WAIT", "FILE_CRYPTER");
            }
            else{
                IndependentMessageBox("[ INFO ] ATTENTION : GROS FICHIER DETECTE\nTRAITEMENT TRES LONG POSSIBLE(DEPEND DE LA TAILLE DU FICHIER),VEUILLEZ PATIENTER", "FILE_CRYPTER");
            }
            step = 2000;
        }
        else if (file_len > 20000){
            if(lge==1){
                IndependentMessageBox("[ INFO ] LONG FILE DETECTED\nTHE PROCESSING WILL BE LONG,PLEASE WAIT", "FILE_CRYPTER");
            }
            else{
                IndependentMessageBox("[ INFO ] LONG FICHIER DETECTE\nTRAITEMENT LONG POSSIBLE,VEUILLEZ PATIENTER", "FILE_CRYPTER");
            }
            step = 1200;
        }
        else if (file_len > 5000){
            if(lge==1){
                IndependentMessageBox("[ INFO ] FILE PROCESSING\nPLEASE WAIT", "FILE_CRYPTER");
            }
            else{
                IndependentMessageBox("[ INFO ] TRAITEMENT DU FICHIER\nVEUILLEZ PATIENTER", "FILE_CRYPTER");
            }
            step = 500;
        }
        for(ip=file_len-1; ip>=0;ip--){
            jp=0;
            for(kp=0; kp<ip;kp++){
                jp=(kp+prmcst+jp) % file_len;
            }
            jp=(ip+prmcst+jp) % file_len;
            tmp=temp_string[ip];
            temp_string[ip]=temp_string[jp];
            temp_string[jp]=tmp;
            fflush(stdout);
            if(file_len>5000){
                cnt = file_len-ip-1;
                if(cnt%step == 0 || cnt == file_len-1){
                    printf("\rPROGRESSION: %ld / %ld", cnt+1, file_len);
                    fflush(stdout);
                }
            }
        }
    }
    else{
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            IndependentMessageBox("[ ERROR ] FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        }
        else{
            IndependentMessageBox("[ ERROR ] LA PERMUTATION DU FICHIER S'EST MAL DEROULEE", "FILE_CRYPTER");
        }
        memset(temp_string, 0, file_len);
        free(temp_string);
        return 0;
    }
    size_t nlw = fwrite(temp_string, 1, file_len, file);
    if(nlw != (size_t)file_len){
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            IndependentMessageBox("[ ERROR ] FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        }
        else{
            IndependentMessageBox("[ ERROR ] LA PERMUTATION DU FICHIER S'EST MAL DEROULEE", "FILE_CRYPTER");
        }
        memset(temp_string, 0, file_len);
        free(temp_string);
        return 0;
    }
    fflush(file);
    rewind(file);
    memset(temp_string, 0, file_len);
    free(temp_string);
    return 1;
}

int FileCopyMaker(FILE *src, FILE *dst){
    if(!src){
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            IndependentMessageBox("[ ERROR ] COPYING GONE WRONG", "FILE_CRYPTER");
        }
        else{
            IndependentMessageBox("[ ERROR ] LA COPIE S'EST MAL DEROULEE", "FILE_CRYPTER");
        }
        return 0;
    }
    char buf[4096];
    size_t n;
    rewind(src);
    rewind(dst);
    while((n = fread(buf, 1, sizeof(buf), src)) > 0){
        if(fwrite(buf, 1, n, dst) != n){
            MessageBeep(MB_ICONEXCLAMATION);
            if(lge==1){
                IndependentMessageBox("[ ERROR ] COPYING GONE WRONG", "FILE_CRYPTER");
            }
            else{
                IndependentMessageBox("[ ERROR ] LA COPIE S'EST MAL DEROULEE", "FILE_CRYPTER");
            }
            return 0;
        }
    }
    if(ferror(src)){
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            IndependentMessageBox("[ ERROR ] COPYING GONE WRONG", "FILE_CRYPTER");
        }
        else{
            IndependentMessageBox("[ ERROR ] LA COPIE S'EST MAL DEROULEE", "FILE_CRYPTER");
        }
        return 0;
    }
    rewind(src);
    rewind(dst);
    return 1;
}

int FileExistanceChecker(char *path){
    FILE *f;
    if((f=fopen(path,"rb"))==NULL){
        return 1;
    }
    fclose(f);
    return 0;
}

void RemoveFile(char *path){
    FILE *f;
    if((f=fopen(path,"wb"))==NULL){
        char *epath;
        epath = calloc(230, sizeof(char));
        if(epath==NULL){
            if(lge==1){
                IndependentMessageBox("[ ERROR ] MEMORY ALLOCATION", "FILE_CRYPTER");
                MessageBeep(MB_ICONHAND);
            }
            else{
                IndependentMessageBox("[ ERROR ] (ALLOCATION MEMOIRE) ERREUR LORS DE LA SUPPRESION DU FICHIER", "FILE_CRYPTER");
                MessageBeep(MB_ICONHAND);
            }
            return;
        }
        if(lge==1){
            sprintf(epath, "[ ERROR ] %s REMOVING FAILED", path);
            MessageBeep(MB_ICONHAND);
        }
        else{
            sprintf(epath, "[ ERROR ] LA SUPPRESSION DE %s A ECHOUE", path);
            MessageBeep(MB_ICONHAND);
        }
        IndependentMessageBox(epath, "FILE_CRYPTER");
        free(epath);
        return;
    }
    fclose(f);
    remove(path);
}

DWORD WINAPI msg_thread(LPVOID param){
    MsgData *data = (MsgData*)param;
    MessageBoxA(NULL, data->msg, data->title, MB_OK | MB_ICONINFORMATION);
    free(data->msg);
    free(data->title);
    free(data);

    return 0;
}

void IndependentMessageBox(const char *msg, const char *title){
    MsgData *data = malloc(sizeof(MsgData));
    if (!data) return;
    data->msg = _strdup(msg);
    data->title = _strdup(title);
    if (!data->msg || !data->title){
        free(data->msg);
        free(data->title);
        free(data);
        return;
    }

    HANDLE hThread = CreateThread(NULL, 0, msg_thread, data, 0, NULL);

    if (hThread)
        CloseHandle(hThread);
}

void MatrixSimulation(){
    srand(time(NULL));
    int pos[120];
    int speed[120];
    int tail[120];
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &cursor);
    for (int i = 0; i < 120; i++) {
        pos[i] = rand() % 15;
        speed[i] = 1 + rand() % 3;
        tail[i] = 5 + rand() % 10;
    }
    for (int i = 0; i < 7; i++){
        for (int y = 0; y < 15; y++) {
            for (int x = 0; x < 120; x++) {
                int head = pos[x];
                int distance = head - y;
                if (distance == 0) {
                    SetConsoleTextAttribute(hConsole, 15);
                    printf("%d", rand() % 2);
                }
                else if (distance > 0 && distance < tail[x]) {
                    SetConsoleTextAttribute(hConsole, 10);
                    printf("%d", rand() % 2);
                }
                else {
                    SetConsoleTextAttribute(hConsole, 0);
                    printf(" ");
                }
            }
            printf("\n");
        }
        for (int i = 0; i < 120; i++) {
            pos[i] += speed[i];
            if (pos[i] > 15 + tail[i]) {
                pos[i] = 0;
                speed[i] = 1 + rand() % 3;
                tail[i] = 5 + rand() % 10;
            }
            if(rand()% 100 < 2){
                pos[i] = rand() % 15;
            }
        }
        Sleep(50);
    }
    SetConsoleTextAttribute(hConsole,10);
    cursor.bVisible = TRUE;
    cursor.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &cursor);
}

void Info(int infolanguage){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    UINT originalCP = GetConsoleOutputCP();
    SetConsoleOutputCP(CP_UTF8);
    if(infolanguage==1){
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("CipherFlow System ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("is a Windows-based file security application designed to provide reliable file encryption, decryption,\nscheduling, and secure file transfer through a simple and intuitive console interface.\n");
        printf("The system transforms file contents using a password-driven encryption process and supports secure data exchange over\nTCP through its built-in transfer protocol. CipherFlow runs entirely in local except when using the file transfer\nfeature(offline proccess).\n\n");
        printf("Main Features\n• File encryption\n• File decryption\n• Scheduled operations\n• Secure file transfer\n• Progress monitoring\n• Native Windows integration\n\nCurrent Version\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("Version : 1.3");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\nWhat's New in v1.3\n• Added TCP file transfer.\n• Added Send and Receive File mode.\n• Implemented a reliable transfer protocol.\n• Added transfer progress display.\n• Improved network error handling.\n");
        printf("• Introduced the « .cflow » encrypted file extension.\n• Improved the console interface and user experience.\n\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("Message boxes and warnings displayed by the application should always be taken seriously, as they may contain critical\ninformation regarding file replacement, operation confirmation, scheduling, or security-related actions.\n");
        printf("Every time this app location is changed, it should be launched to reset the internal configuration used for elements\nsuch as CipherFlow file icon, default opening app for CipherFlow file, ...\n\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
        printf("Copyright © 2026 CipherFlow System");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\nOpen Source Project\nGitHub Repository : https://github.com/orpheric73/FILE_CRYPTER\nCreated and maintened by ORPHÉRIC Sangnidjo.\n");
    }
    else{
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        printf("CipherFlow System ");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("est une application Windows de sécurité des fichiers conçue pour offrir un chiffrement, un\ndéchiffrement, une planification des opérations et un transfert sécurisé de fichiers au sein d'une interface console\nsimple, intuitive et professionnelle.\n");
        printf("Le système transforme le contenu des fichiers à l'aide d'un mot de passe afin de les rendre illisibles pour toute\npersonne ne disposant pas de la clé appropriée. Toutes les opérations sont réalisées localement sur votre ordinateur,\nà l'exception du mode de transfert de fichiers qui utilise une connexion TCP(hors-ligne).\n\n");
        printf("Fonctionnalités principales\n• Chiffrement de fichiers\n• Déchiffrement de fichiers\n• Planification des opérations\n• Transfert sécurisé de fichiers\n• Suivi de la progression des opérations\n• Intégration native à Windows\n\nVersion actuelle\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("Version : 1.3");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\nNouveautés de la version 1.3\n• Ajout du mode de transfert de fichiers TCP.\n• Ajout des fonctionnalités d'envoi et de réception de fichiers.\n• Mise en place d'un protocole de transfert fiable.\n• Ajout d'une barre de progression lors des transferts.\n• Amélioration de la gestion des erreurs réseau.\n");
        printf("• Adoption de la nouvelle extension de fichier chiffré « .cflow ».\n• Amélioration de l'interface console et de l'expérience utilisateur.\n\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("Les boîtes de dialogue et les messages d'avertissement affichés par l'application doivent toujours être pris au sérieux,\ncar ils peuvent contenir des informations importantes concernant la sécurité des données ou le déroulement des\nopérations.\n");
        printf("Chaque fois que l'emplacement de l'application est modifié, il convient de le lancer pour réinitialiser la\nconfiguration interne utilisée pour les élements tels que l'icone des fichiers CipherFlow, l'application d'ouverture par\ndefaut de ces fichiers, ...\n\n");
        SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
        printf("Copyright © 2026 CipherFlow System");
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\nProjet Open Source\nDépot GitHub : https://github.com/orpheric73/FILE_CRYPTER\nCrée et maintenu par ORPHÉRIC Sangnidjo.\n");
    }
    SetConsoleOutputCP(originalCP);
    SetConsoleTextAttribute(hConsole, 10);
}

BOOL WINAPI ConsoleHandler(DWORD signal){
    if(signal == CTRL_CLOSE_EVENT){
        if(lge==1){
            MessageBox(NULL, "CLOSING CIPHER FLOW MAY INTERRUPT ONGOING OPERATIONS AND MAY CAUSE DATA LOSS OR CORRUPT OPERATIONS.", "FILE_CRYPTER WARNING", MB_OK | MB_ICONWARNING);
        }
        else{
            MessageBox(NULL, "FERMER CIPHER FLOW PEUT INTERROMPRE LES OPERATIONS EN COURS ET PEUT ENTRAINER DES PERTES OU CORRUPTION DE DONNEES.", "FILE_CRYPTER AVERTISSEMENT", MB_OK | MB_ICONWARNING);
        }
    }
    return FALSE;
}

int SendAll(SOCKET sock, const void *buffer, size_t size){
    size_t total = 0;
    const char *ptr = (const char *)buffer;
    while (total < size){
        int sent = send(sock, ptr + total, (int)(size - total), 0);
        if(sent == SOCKET_ERROR){
           int err = WSAGetLastError();
           switch(err){
            case WSAEINTR:
                Sleep(1000);
                continue;
            case WSAEWOULDBLOCK:
                Sleep(1000);
                continue;
            default:
                printf("\n[ ERROR ] SEND() : %d\n", err);
                return -1;
           }
        }
        if (sent == 0){
            if(lge == 1){
                printf("\nCONNECTION CLOSED");
            }
            else{
                printf("\nCONNEXION FERMEE");
            }
            return -1;
        }
        total += sent;
    }
    return 0;
}

int RecvAll(SOCKET sock, void *buffer, size_t size){
    size_t total = 0;
    char *ptr = (char *)buffer;
    while (total < size){
        int received = recv(sock, ptr + total, (int)size - total, 0);
        if(received == SOCKET_ERROR){
           int err = WSAGetLastError();
           switch(err){
            case WSAEINTR:
                Sleep(1000);
                continue;
            case WSAEWOULDBLOCK:
                Sleep(1000);
                continue;
            default:
                printf("\n[ ERROR ] RECV() : %d\n", err);
                return -1;
           }
        }
        if (received == 0){
            if(lge == 1){
                printf("\nCONNECTION CLOSED");
            }
            else{
                printf("\nCONNEXION FERMEE");
            }
            return -1;
        }
        total += received;
    }
    return 0;
}

int SendFile(SOCKET sock, FILE *file, uint64_t file_size){
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    uint64_t total_sent = 0;
    int percent = -1;
    printf("\n");
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0){
        if (SendAll(sock, buffer, bytes_read) != 0){
            return -1;
        }
        total_sent += bytes_read;
        int current = (int)((total_sent * 100ULL) / file_size);
        if (current != percent){
            percent = current;
            printf("\r[");
            int bars = percent / 2;
            for (int i = 0; i < 50; i++){
                if (i < bars)
                    printf("=");
                else
                    printf(" ");
            }
            printf("] %3d%% (%llu / %llu octets)", percent, (unsigned long long)total_sent, (unsigned long long)file_size);
            fflush(stdout);
        }
    }
    if (ferror(file)){
        if(lge == 1){
            printf("\n[ ERROR ] ERROR DURING FILE READING");
        }
        else{
            printf("\n[ ERROR ] ERREUR DE LECTURE DU FICHIER");
        }
        return -1;
    }
    return 0;
}

int RecvFile(SOCKET sock, FILE *file, uint64_t file_size){
    char buffer[BUFFER_SIZE];
    uint64_t total_received = 0;
    size_t chunk;
    int percent = -1;
    printf("\n");
    while (total_received < file_size){
        chunk = (file_size - total_received > BUFFER_SIZE) ? BUFFER_SIZE : (size_t)(file_size - total_received);
        if (RecvAll(sock, buffer, chunk) != 0){
            return -1;
        }
        if (fwrite(buffer, 1, chunk, file) != chunk){
            if(lge == 1){
                printf("\n[ ERROR ] ERROR DURING WRITING IN FILE");
            }
            else{
                printf("\n[ ERROR ] ERREUR LORS DE L'ECRITURE DANS LE FICHIER");
            }
            return -1;
        }
        total_received += chunk;
        int current = (int)((total_received * 100ULL) / file_size);
        if (current != percent){
            percent = current;
            printf("\r[");
            int bars = percent / 2;
            for (int i = 0; i < 50; i++){
                if (i < bars)
                    printf("=");
                else
                    printf(" ");
            }
            printf("] %3d%% (%llu / %llu octets)", percent, (unsigned long long)total_received, (unsigned long long)file_size);
            fflush(stdout);
        }
    }
    if (ferror(file)){
        if(lge == 1){
            printf("\n[ ERROR ] ERROR DURING WRITING IN FILE");
        }
        else{
            printf("\n[ ERROR ] ERREUR D\'ECRITURE DU FICHIER");
        }
        return -1;
    }
    if (fflush(file) != 0){
        if(lge == 1){
            printf("\n[ ERROR ] ERROR WHILE EMPTYING FILE TAMPON");
        }
        else{
            printf("\n[ ERROR ] ERREUR LORS DU VIDAGE DU TAMPON DU FICHIER");
        }
        return -1;
    }
    return 0;
}
