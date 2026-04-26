#include"FUNCTION.h"
#include <time.h>
int ani=0;
int lge=0;
typedef struct {
    char *msg;
    char *title;
} MsgData;

void type_effect(char *text){
    int i;
    for(i=0; text[i] != '\0'; i++){
        printf("%c",text[i]);
        fflush(stdout);
        Sleep(10*ani);
    }
}

void color_change1(){
    system("color 09");
    Sleep(200);
    system("color 0C");
    Sleep(200);
    system("color 0A");
    Sleep(200);
}

void loading(){
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

int isLeapYear(int yea){
    return (yea % 4 == 0 && yea % 100 !=0) || (yea % 400 == 0);
}

int GetDaysInMonth(int MON, int YEA){
    switch(MON) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            return 31;

        case 4: case 6: case 9: case 11:
            return 30;

        case 2:
            return isLeapYear(YEA) ? 29 : 28;
        default:
            return 0;
    }
}

void home(int set){
    if(set==0){
        printf("\n");
        UINT originalCP = GetConsoleOutputCP();
        SetConsoleOutputCP(CP_UTF8);
        printf("========================================================================================================================\n");
        printf("======================");
        type_effect("███████╗██╗██████╗ ██╗  ██╗███████╗██████╗ ███████╗██╗      ██████╗ ██╗    ██╗");
        printf("====================\n======================");
        type_effect("██╔════╝██║██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝██║     ██╔═══██╗██║    ██║");
        printf("====================\n======================");
        type_effect("██║     ██║██████╔╝███████║█████╗  ██████╔╝█████╗  ██║     ██║   ██║██║ █╗ ██║");
        printf("====================\n======================");
        type_effect("██║     ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗██╔══╝  ██║     ██║   ██║██║███╗██║");
        printf("====================\n======================");
        type_effect("███████╗██║██║     ██║  ██║███████╗██║  ██║██║     ███████╗╚██████╔╝╚███╔███╔╝");
        printf("====================\n======================");
        type_effect("╚══════╝╚═╝╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝     ╚══════╝ ╚═════╝  ╚══╝╚══╝ ");
        SetConsoleOutputCP(originalCP);
        printf("====================\n================================================       ");
        type_effect("CIPHERFLOW SYSTEM");
        printf("       =========================================\n==========================================       ");
        type_effect("SECURE - DYNAMIC - SCHEDULED");
        printf("     ======================================\n");
    }
    if(set==1){
        if(lge==1){
            printf("========================================================================================================================\n===============================================     ");
            type_effect("[1] ENCRYPT FILE");
            printf("             =======================================\n===============================================     ");
            type_effect("[2] DECRYPT FILE");
            printf("             =======================================\n===============================================     ");
            type_effect("[3] SCHEDULE ENCRYPTION");
            printf("      =======================================\n===============================================     ");
            type_effect("[4] SCHEDULE DECRYPTION");
            printf("      =======================================\n===============================================     ");
            type_effect("[5] EXIT");
            printf("                     =======================================\n");
            type_effect("> ");
        }
        else if(lge==0){
            printf("========================================================================================================================\n==========================================     ");
            type_effect("[1] CRYPTER UN/DES FICHIER(S)");
            printf("   =========================================\n==========================================     ");
            type_effect("[2] DECRYPTER UN/DES FICHIER(S)");
            printf("  ========================================\n==========================================     ");
            type_effect("[3] PLANIFIER UN CRYPTAGE");
            printf("         =======================================\n==========================================     ");
            type_effect("[4] PLANIFIER UN DECRYPTAGE");
            printf("       =======================================\n==========================================     ");
            type_effect("[5] QUITTER");
            printf("                       =======================================\n");
            type_effect("> ");
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

int NumbOfFile(){
    int fcon, nbr, clb;
     do{
        fcon=1;
        if(lge==1){
            printf("\nENTER THE NUMBER OF FILE(S)");
        }
        else if(lge==0){
            printf("\nENTRER LE NOMBRE DE FICHIER(S)");
        }
        printf("\n> ");
        if(scanf("%d",&nbr)!=1){
            if(lge==1){
                printf("\nINVALID INPUT,TRY AGAIN.");
            }
            else if(lge==0){
                printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
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
            printf("\n> ");
            if(scanf("%d",&fcon)!=1){
                if(lge==1){
                    printf("\nINVALID INPUT,TRY AGAIN.");
                }
                else if(lge==0){
                    printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
                }
                while((clb=getchar()) != '\n' && clb != EOF);
                fcon=0;
            }
        }
    }while(fcon!=1 || nbr<1);
    return nbr;
}

char SamePasswd (){
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

void SecureLevel(char *pasw){
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
        else if(lge==0){
            printf(" ULTRA-SECURISE");
        }
    }
    else if(occ==1){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,176,176,176,176);
        if(lge==1){
            printf(" VERY-SECURE");
        }
        else if(lge==0){
            printf(" TRéS-SECURISE");
        }
    }
    else if(occ==3){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,176,176,176,176,176);
        if(lge==1){
            printf(" SECURE");
        }
        else if(lge==0){
            printf(" SECURISE");
        }
    }
    else if(occ==6){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,176,176,176,176,176,176);
        if(lge==1){
            printf(" RELIABLE");
        }
        else if(lge==0){
            printf(" FIABLE");
        }
    }
    else if(occ==10){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,176,176,176,176,176,176,176);
        if(lge==1){
            printf(" ADEQUATE");
        }
        else if(lge==0){
            printf(" ADEQUAT");
        }
    }
    else if(occ==15){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,176,176,176,176,176,176,176,176);
        if(lge==1){
            printf(" MEDIUM");
        }
        else if(lge==0){
            printf(" MOYEN");
        }
    }
    else if(occ==21){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,176,176,176,176,176,176,176,176,176);
        if(lge==1){
            printf(" WEAK");
        }
        else if(lge==0){
            printf(" FAIBLE");
        }
    }
    else if(occ==28){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,176,176,176,176,176,176,176,176,176,176);
        if(lge==1){
            printf(" VERY-WEAK");
        }
        else if(lge==0){
            printf(" TRES-FAIBLE");
        }
    }
    else if(occ==36){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,176,176,176,176,176,176,176,176,176,176,176);
        if(lge==1){
            printf(" FRAGILE");
        }
        else if(lge==0){
            printf(" FRAGILE");
        }
    }
    else if(occ==45){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",176,176,176,176,176,176,176,176,176,176,176,176,176,176);
        if(lge==1){
            printf(" RISKY");
        }
        else if(lge==0){
            printf(" RISQUE");
        }
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            MessageBox(NULL,"THE PASSWORD ISN'T SECURED","FILE_CRYPTER",MB_OK | MB_ICONWARNING);
        }
        else if(lge==0){
            MessageBox(NULL,"LE MOT DE PASSE N'EST PAS SECURISE","FILE_CRYPTER",MB_OK | MB_ICONWARNING);
        }
    }
    return;
}
void PasswdInp(char *pass){
    int fcon, siz, clb;
    do{
        fcon=1;
        if(lge==1){
            printf("\nENTER THE PASSWORD(10 CHARACTERS), IF THIS IS MORE THAN 10 ONLY THE FIRST 10 WILL BE CONSIDERED)");
        }
        else if(lge==0){
            printf("\nENTRER LE MOT DE PASSE(10 CARACTERES), SI PLUS DE 10 SEUL LES 10 PREMIERS SERONT CONSIDERES)");
        }
        printf("\n> ");
        scanf(" %10[^\n]",pass);
        while((clb=getchar()) != '\n' && clb != EOF);
        siz=strlen(pass);
        if(siz!=10){
            fcon=0;
        }
        if(fcon!=0){
            SecureLevel(pass);
        }
        if(fcon!=0){
            if(lge==1){
                printf("\nYOU ENTERED :**********\nENTER 1 TO CONFIRM");
            }
            else if(lge==0){
                printf("\nVOUS AVEZ ENTRE :**********\nENTRER 1 POUR CONFIRMER");
            }
            printf("\n> ");
            if(scanf("%d",&fcon)!=1){
                if(lge==1){
                    printf("\nINVALID INPUT,TRY AGAIN.");
                }
                else if(lge==0){
                    printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
                }
                while((clb=getchar()) != '\n' && clb != EOF);
                fcon=0;
            }
        }
    }while(fcon!=1);
}

int VerInp(){
    int fcon, fv, clb;
     do{
        fcon=1;
        if(lge==1){
            printf("\nENTER THE VERSION(1-15)");
        }
        else if(lge==0){
            printf("\nENTRER LA VERSION(1-15)");
        }
        printf("\n> ");
        if(scanf("%d",&fv)!=1){
            if(lge==1){
                printf("\nINVALID INPUT,TRY AGAIN.");
            }
            else if(lge==0){
                printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
            }
            while((clb=getchar()) != '\n' && clb != EOF);
            fcon=0;
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
            printf("\n> ");
            if(scanf("%d",&fcon)!=1){
                if(lge==1){
                    printf("\nINVALID INPUT,TRY AGAIN.");
                }
                else if(lge==0){
                    printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
                }
                while((clb=getchar()) != '\n' && clb != EOF);
                fcon=0;
            }
        }
    }while(fcon!=1);
    return fv;
}

void Animation(){
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

void Language(int language){
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
            resul = MessageBox(NULL, "FR/EN\nFRANCAIS DETECTE\nUTILISER COMME LANGUE D'AFFICHAGE?", "FILE_CRYPTER", MB_YESNO | MB_ICONQUESTION);
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

int PermuteDataInFile(FILE* file, int prmcst, int act){
    long file_len;
    char *temp_string;
    if(fseek(file, 0, SEEK_END) !=0){
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            show_message_async("FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        }
        else if(lge==0){
            show_message_async("LA PERMUTATION DU FICHIER S'EST MAL PASSEE", "FILE_CRYPTER");
        }
        return 0;
    }
    file_len = ftell(file);
    rewind(file);
    if(file_len <= 0){
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            show_message_async("FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        }
        else if(lge==0){
            show_message_async("LA PERMUTATION DU FICHIER S'EST MAL PASSEE", "FILE_CRYPTER");
        }
        return 0;
    }
    temp_string=malloc(file_len);
    if(!temp_string){
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            show_message_async("FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        }
        else if(lge==0){
            show_message_async("LA PERMUTATION DU FICHIER S'EST MAL PASSEE", "FILE_CRYPTER");
        }
        return 0;
    }
    size_t nl = fread(temp_string, 1, file_len, file);
    rewind(file);
    if(nl != (size_t)file_len){
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            show_message_async("FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        }
        else if(lge==0){
            show_message_async("LA PERMUTATION DU FICHIER S'EST MAL PASSEE", "FILE_CRYPTER");
        }
        memset(temp_string, 0, strlen(temp_string)+1);
        free(temp_string);
        return 0;
    }
    if(act==1){
        char tmp;
        long jp=0, ip, step;
        if (file_len > 500000000){
            if(lge==1){
                show_message_async("WARNING : BIG FILE DETECTED\nTHE PROCESS WILL BE VERY LONG(DEPEND OF THE FILE SIZE),PLEASE WAIT", "FILE_CRYPTER");
            }
            else if(lge==0){
                show_message_async("ATTENTION : GROS FICHIER DETECTE\nTRAITEMENT TRES LONG POSSIBLE(DEPEND DE LA TAILLE DU FICHIER),VEUILLEZ PATIENTER", "FILE_CRYPTER");
            }
            step = 500000;
        }
        else if (file_len > 100000000){
            if(lge==1){
                show_message_async("LONG FILE DETECTED\nTHE PROCESS WILL BE LONG,PLEASE WAIT", "FILE_CRYPTER");
            }
            else if(lge==0){
                show_message_async("LONG FICHIER DETECTE\nTRAITEMENT LONG POSSIBLE,VEUILLEZ PATIENTER", "FILE_CRYPTER");
            }
            step = 100000;
        }
        for(ip=0; ip<file_len;ip++){
            jp=(ip+prmcst+jp) % file_len;
            tmp=temp_string[ip];
            temp_string[ip]=temp_string[jp];
            temp_string[jp]=tmp;
            if(file_len>100000000){
                if(ip%step == 0){
                    printf("\rPROGRESSION: %ld / % ld", ip, file_len);
                    fflush(stdout);
                }
            }
        }
    }
    else if(act==2){
        char tmp;
        long jp, ip, kp, step;
        if (file_len > 500000){
            if(lge==1){
                show_message_async("WARNING : VERY BIG FILE DETECTED\nTHE PROCESS WILL BE VERY VERY LONG(DEPEND OF THE FILE SIZE),PLEASE WAIT", "FILE_CRYPTER");
            }
            else if(lge==0){
                show_message_async("ATTENTION : TRES GROS FICHIER DETECTE\nTRAITEMENT TRES TRES LONG POSSIBLE(DEPEND DE LA TAILLE DU FICHIER),VEUILLEZ PATIENTER", "FILE_CRYPTER");
            }
            step = 50000;
        }
        else if (file_len > 50000){
            if(lge==1){
                show_message_async("WARNING : BIG FILE DETECTED\nTHE PROCESS WILL BE VERY LONG(DEPEND OF THE FILE SIZE),PLEASE WAIT", "FILE_CRYPTER");
            }
            else if(lge==0){
                show_message_async("ATTENTION : GROS FICHIER DETECTE\nTRAITEMENT TRES LONG POSSIBLE(DEPEND DE LA TAILLE DU FICHIER),VEUILLEZ PATIENTER", "FILE_CRYPTER");
            }
            step = 10000;
        }
        else if (file_len > 20000){
            if(lge==1){
                show_message_async("LONG FILE DETECTED\nTHE PROCESS WILL BE LONG,PLEASE WAIT", "FILE_CRYPTER");
            }
            else if(lge==0){
                show_message_async("LONG FICHIER DETECTE\nTRAITEMENT LONG POSSIBLE,VEUILLEZ PATIENTER", "FILE_CRYPTER");
            }
            step = 1000;
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
            if(file_len>20000){
                if(ip%step == 0){
                    printf("\rPROGRESSION: %ld / % ld", ip, file_len);
                    fflush(stdout);
                }
            }
        }
    }
    else{
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            show_message_async("FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        }
        else if(lge==0){
            show_message_async("LA PERMUTATION DU FICHIER S'EST MAL PASSEE", "FILE_CRYPTER");
        }
        memset(temp_string, 0, strlen(temp_string)+1);
        free(temp_string);
        return 0;
    }
    size_t nlw = fwrite(temp_string, 1, file_len, file);
    rewind(file);
    if(nlw != (size_t)file_len){
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            show_message_async("FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        }
        else if(lge==0){
            show_message_async("LA PERMUTATION DU FICHIER S'EST MAL PASSEE", "FILE_CRYPTER");
        }
        memset(temp_string, 0, strlen(temp_string)+1);
        free(temp_string);
        return 0;
    }
    fflush(file);
    memset(temp_string, 0, strlen(temp_string)+1);
    free(temp_string);
    return 1;
}

int Copy_File(FILE *src, FILE *dst){
    if(!src){
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            show_message_async("COPYING GONE WRONG", "FILE_CRYPTER");
        }
        else if(lge==0){
            show_message_async("LA COPIE S'EST MAL DEROULEE", "FILE_CRYPTER");
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
                show_message_async("COPYING GONE WRONG", "FILE_CRYPTER");
            }
            else if(lge==0){
                show_message_async("LA COPIE S'EST MAL DEROULEE", "FILE_CRYPTER");
            }
            return 0;
        }
    }
    if(ferror(src)){
        MessageBeep(MB_ICONEXCLAMATION);
        if(lge==1){
            show_message_async("COPYING GONE WRONG", "FILE_CRYPTER");
        }
        else if(lge==0){
            show_message_async("LA COPIE S'EST MAL DEROULEE", "FILE_CRYPTER");
        }
        return 0;
    }
    rewind(src);
    rewind(dst);
    return 1;
}

int FileExistanceChecking(char *path){
    FILE *f;
    if((f=fopen(path,"rb"))==NULL){
        return 1;
    }
    fclose(f);
    return 0;
}

DWORD WINAPI msg_thread(LPVOID param){
    MsgData *data = (MsgData*)param;
    MessageBoxA(NULL, data->msg, data->title, MB_OK | MB_ICONINFORMATION);
    free(data->msg);
    free(data->title);
    free(data);

    return 0;
}

void show_message_async(const char *msg, const char *title){
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

void AnimationCrypt(){
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
