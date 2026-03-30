#include"FUNCTION.h"
void type_effect(char *text){
    int i;
    for(i=0; text[i] != '\0'; i++){
        printf("%c",text[i]);
        fflush(stdout);
        Sleep(10);
    }
}

void color_change1(){
    system("color 09");
    Sleep(300);
    system("color 0C");
    Sleep(300);
    system("color 0A");
    Sleep(300);
}

void loading(){
    int j;
    for(j=0;j<3;j++){
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        printf(".");
        Sleep(500);
        Beep(1000, 300);
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

void home(int param){
    if(param==0){
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
    if(param==1){
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
    int fcon, nbr;
     do{
        fcon=1;
        printf("\nENTER THE NUMBER OF FILES");
        printf("\n> ");
        if(scanf("%d",&nbr)!=1){
            printf("\nINVALID INPUT,TRY AGAIN.");
            while(getchar() != '\n');
            fcon=0;
        }
        if(fcon!=0){
            printf("\nENTER 1 TO CONFIRM THE NUMBER AND ANOTHER NUMBER TO RE-ENTER ");
            printf("\n> ");
            if(scanf("%d",&fcon)!=1){
                printf("\nINVALID INPUT,TRY AGAIN.");
                while(getchar() != '\n');
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
        MessageBox(NULL,"THE PASSWORD ISN'T SECURED","FILE_CRYPTER",MB_OK | MB_ICONWARNING);
    }
    return;
}
void PasswdInp(char *pass){
    int fcon, siz;
    do{
        fcon=1;
        printf("\nENTER THE PASSWORD(10 CHARACTERS EVEN IF THIS IS MORE THAN 10 ONLY THE FIRST 10 WILL BE USED)(NO SPACE)");
        printf("\n> ");
        Sleep(500);
        scanf("%10s",pass);
        while(getchar() != '\n');
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
                while(getchar() != '\n');
                fcon=0;
            }
        }
    }while(fcon!=1);
}

int VerInp(){
    int fcon, fv;
     do{
        fcon=1;
        printf("\nENTER THE COMPLEXITY VERSION(0-5)");
        printf("\n> ");
        system("color 00");
        if(scanf("%d",&fv)!=1){
            printf("\nINVALID INPUT,TRY AGAIN.");
            while(getchar() != '\n');
            fcon=0;
        }
        system("color 0A");
        if(fcon!=0){
            printf("\nENTER 1 TO CONFIRM THE VERSION AND ANOTHER NUMBER TO RE-ENTER ");
            printf("\n> ");
            if(scanf("%d",&fcon)!=1){
                printf("\nINVALID INPUT,TRY AGAIN.");
                while(getchar() != '\n');
                fcon=0;
            }
        }
    }while(fcon!=1);
    return fv;
}
