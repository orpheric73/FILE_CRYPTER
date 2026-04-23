#include"FUNCTION.h"
int ani=0;
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
    Sleep(200*ani);
    system("color 0C");
    Sleep(200*ani);
    system("color 0A");
    Sleep(200*ani);
}

void loading(){
    int j;
    for(j=0;j<3;j++){
        Sleep(200*ani);
        printf(".");
        Sleep(200*ani);
        printf(".");
        Sleep(200*ani);
        printf(".");
        Sleep(200*ani);
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
        printf("========================================================================================================================\n===============================================     ");
        type_effect("[1] ENCRYPT FILE");
        printf("             =======================================\n===============================================     ");
        type_effect("[2] DECRYPT FILE");
        printf("             =======================================\n===============================================     ");
        type_effect("[3] SCHEDULED ENCRYPTION");
        printf("     =======================================\n===============================================     ");
        type_effect("[4] SCHEDULED DECRYPTION");
        printf("     =======================================\n===============================================     ");
        type_effect("[5] EXIT");
        printf("                     =======================================\n");
        type_effect("> ");
    }
}

char* DayOfWeek(int day, int la){
    char *dow;
    if(la==0){
        switch(day){
            case 0:
                dow="Dimanche";
                break;
            case 1:
                dow="Lundi";
                break;
            case 2:
                dow="Mardi";
                break;
            case 3:
                dow="Mercredi";
                break;
            case 4:
                dow="Jeudi";
                break;
            case 5:
                dow="Vendredi";
                break;
            case 6:
                dow="Samedi";
                break;
        }
    }
    else{
        switch(day){
            case 0:
                dow="Sunday";
                break;
            case 1:
                dow="Monday";
                break;
            case 2:
                dow="Tuesday";
                break;
            case 3:
                dow="Wednesday";
                break;
            case 4:
                dow="Thursday";
                break;
            case 5:
                dow="Friday";
                break;
            case 6:
                dow="Saturday";
                break;
        }
    }
    return dow;
}

int NumbOfFile(){
    int fcon, nbr, clb;
     do{
        fcon=1;
        printf("\nENTER THE NUMBER OF FILES");
        printf("\n> ");
        if(scanf("%d",&nbr)!=1){
            printf("\nINVALID INPUT,TRY AGAIN.");
            while((clb=getchar()) != '\n' && clb != EOF);
            fcon=0;
        }
        if(fcon!=0){
            printf("\nENTER 1 TO CONFIRM THE NUMBER AND ANOTHER NUMBER TO RE-ENTER ");
            printf("\n> ");
            if(scanf("%d",&fcon)!=1){
                printf("\nINVALID INPUT,TRY AGAIN.");
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
        result = MessageBox(NULL, "DO YOU WANT TO USE THE SAME PASSWORD AND VERSION FOR ALL ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONINFORMATION | MB_TOPMOST | MB_SETFOREGROUND);
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
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c ULTRA-SECURE",219,219,219,219,219,219,219,219,219,219,219,219,219,219);
    }
    else if(occ==1){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c VERY-SECURE",219,219,219,219,219,219,219,219,219,219,176,176,176,176);
    }
    else if(occ==3){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c SECURE",219,219,219,219,219,219,219,219,219,176,176,176,176,176);
    }
    else if(occ==6){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c RELIABLE",219,219,219,219,219,219,219,219,176,176,176,176,176,176);
    }
    else if(occ==10){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c ADEQUATE",219,219,219,219,219,219,219,176,176,176,176,176,176,176);
    }
    else if(occ==15){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c MEDIUM",219,219,219,219,219,219,176,176,176,176,176,176,176,176);
    }
    else if(occ==21){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c WEAK",219,219,219,219,219,176,176,176,176,176,176,176,176,176);
    }
    else if(occ==28){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c VERY-WEAK",219,219,219,219,176,176,176,176,176,176,176,176,176,176);
    }
    else if(occ==36){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c FRAGILE",219,219,219,176,176,176,176,176,176,176,176,176,176,176);
    }
    else if(occ==45){
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c RISKY",176,176,176,176,176,176,176,176,176,176,176,176,176,176);
        MessageBeep(MB_ICONEXCLAMATION);
        MessageBox(NULL,"THE PASSWORD ISN'T SECURED","FILE_CRYPTER",MB_OK | MB_ICONWARNING);
    }
    return;
}
void PasswdInp(char *pass){
    int fcon, siz, clb;
    do{
        fcon=1;
        printf("\nENTER THE PASSWORD(10 CHARACTERS EVEN IF THIS IS MORE THAN 10 ONLY THE FIRST 10 WILL BE USED)");
        printf("\n> ");
        Sleep(500);
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
            printf("\nYOU ENTERED :**********\nENTER 1 TO CONFIRM THE PASSWORD AND ANOTHER NUMBER TO RE-ENTER ");
            printf("\n> ");
            if(scanf("%d",&fcon)!=1){
                printf("\nINVALID INPUT,TRY AGAIN.");
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
        printf("\nENTER THE COMPLEXITY VERSION(0-5)");
        printf("\n> ");
        system("color 00");
        if(scanf("%d",&fv)!=1){
            printf("\nINVALID INPUT,TRY AGAIN.");
            while((clb=getchar()) != '\n' && clb != EOF);
            fcon=0;
        }
        system("color 0A");
        if(fcon!=0){
            printf("\nENTER 1 TO CONFIRM THE VERSION AND ANOTHER NUMBER TO RE-ENTER ");
            printf("\n> ");
            if(scanf("%d",&fcon)!=1){
                printf("\nINVALID INPUT,TRY AGAIN.");
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
        resul = MessageBox(NULL, "DISPLAYING WITH ANIMATION ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONINFORMATION);
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

int PermuteDataInFile(FILE* file, int prmcst, int act){
    long file_len;
    char *temp_string;
    if(fseek(file, 0, SEEK_END) !=0){
        MessageBeep(MB_ICONEXCLAMATION);
        show_message_async("FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        return 0;
    }
    file_len = ftell(file);
    rewind(file);
    if(file_len <= 0){
        MessageBeep(MB_ICONEXCLAMATION);
        show_message_async("FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        return 0;
    }
    temp_string=malloc(file_len);
    if(!temp_string){
        MessageBeep(MB_ICONEXCLAMATION);
        show_message_async("FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        return 0;
    }
    size_t nl = fread(temp_string, 1, file_len, file);
    rewind(file);
    if(nl != (size_t)file_len){
        MessageBeep(MB_ICONEXCLAMATION);
        show_message_async("FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        free(temp_string);
        return 0;
    }
    if(act==1){
        char tmp;
        long jp=0, ip;
        for(ip=0; ip<file_len;ip++){
            jp=(ip+prmcst+jp) % file_len;
            tmp=temp_string[ip];
            temp_string[ip]=temp_string[jp];
            temp_string[jp]=tmp;
        }
    }
    else if(act==2){
        char tmp;
        long jp, ip, kp;
        for(ip=file_len-1; ip>=0;ip--){
            jp=0;
            for(kp=0; kp<ip;kp++){
                jp=(kp+prmcst+jp) % file_len;
            }
            jp=(ip+prmcst+jp) % file_len;
            tmp=temp_string[ip];
            temp_string[ip]=temp_string[jp];
            temp_string[jp]=tmp;
        }
    }
    else{
        MessageBeep(MB_ICONEXCLAMATION);
        show_message_async("FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        free(temp_string);
        return 0;
    }
    size_t nlw = fwrite(temp_string, 1, file_len, file);
    rewind(file);
    if(nlw != (size_t)file_len){
        MessageBeep(MB_ICONEXCLAMATION);
        show_message_async("FILE DATA PERMUTTING GONE WRONG", "FILE_CRYPTER");
        free(temp_string);
        return 0;
    }
    fflush(file);
    free(temp_string);
    return 1;
}

int Copy_File(FILE *src, FILE *dst){
    if(!src){
        MessageBeep(MB_ICONEXCLAMATION);
        show_message_async("COPYING GONE WRONG", "FILE_CRYPTER");
        return 0;
    }
    char buf[4096];
    size_t n;
    rewind(src);
    rewind(dst);
    while((n = fread(buf, 1, sizeof(buf), src)) > 0){
        if(fwrite(buf, 1, n, dst) != n){
            MessageBeep(MB_ICONEXCLAMATION);
            show_message_async("COPYING GONE WRONG", "FILE_CRYPTER");
            return 0;
        }
    }
    if(ferror(src)){
        MessageBeep(MB_ICONEXCLAMATION);
        show_message_async("COPYING GONE WRONG", "FILE_CRYPTER");
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

typedef struct {
    char *msg;
    char *title;
} MsgData;

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
