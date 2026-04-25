#include"FUNCTION.h"
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
    FILE *fl;
    FILE *flo;
    char *ney;
    char *neyp;
    char paswd[11];
    int paswdi[10];
    int v;
}crypt;
int main(){
    int MODE, con, clb, lan, res=1;
    system("color 0A && title FILE_CRYPTER");
    LANGID lang;
    lang = GetUserDefaultUILanguage();
    if(PRIMARYLANGID(lang) == LANG_FRENCH){
        lan=0;
    }
    else{
        lan=1;
    }
    Language(lan);
    Animation();
    home(0);
    while (res==1){
        res=0;
        do{
            con=1;
            home(1);
            if(scanf("%d",&MODE) != 1){
                if(lge==1){
                    type_effect("\nINVALID INPUT,TRY AGAIN.");
                }
                else if(lge==0){
                    type_effect("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
                }
                while((clb=getchar()) != '\n' && clb != EOF);
                con=0;
            }
            printf("\n");
        }while(con!=1 || (MODE<1 || MODE>5));
        if(MODE==1 || MODE==3){
            if(MODE==1){
                if(lge==1){
                    type_effect("##############################################   1-> ENCRYPT FILE    ###################################################");
                    printf("\n");
                }
                else if(lge==0){
                    type_effect("#########################################   1-> CRYPTER UN/DES FICHIER(S)    ###########################################");
                    printf("\n");
                }
            }
            else{
                if(lge==1){
                    type_effect("###########################################   3-> ENCRYPTION PLANNING    ###############################################");
                    printf("\n");
                }
                else if(lge==0){
                    type_effect("#########################################   3-> PLANIFIER UN CRYPTAGE    ###############################################");
                    printf("\n");
                }
            }
            if(ani==1){
                color_change1();
            }
            int nb, K, I, c, S, M, H, h, m, s, y, mo, d, dw, Md, result, remo, Hf, pv, i, prmr, me;
            char dwn[11], ehou[3];
            char rmdec;
            if(MODE==3){
                do{
                    con=1;
                    if(lge==1){
                        printf("\nSET DELAY BEFORE SCHEDULED ENCRYPTION(TURN THE DEVICE OFF WILL DELETE THE PROCESS)");
                    }
                    else if(lge==0){
                        printf("\nDEFINIR LE DELAI AVANT LE CHIFFREMENT PROGRAMME(ETEINDRE L'APPAREIL SUPPRIMERA LE PROCESSUS)");
                    }
                    printf("\n> H: ");
                    if(scanf("%d",&H)!=1){
                        if(lge==1){
                            printf("\nINVALID INPUT,TRY AGAIN.");
                        }
                        else if(lge==0){
                            printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                    }
                    printf("\n> M: ");
                    if(scanf("%d",&M)!=1){
                        if(lge==1){
                            printf("\nINVALID INPUT,TRY AGAIN.");
                        }
                        else if(lge==0){
                            printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                    }
                    printf("\n> S: ");
                    if(scanf("%d",&S)!=1){
                        if(lge==1){
                            printf("\nINVALID INPUT,TRY AGAIN.");
                        }
                        else if(lge==0){
                            printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                    }
                    if(con!=0){
                        if(lge==1){
                            printf("\n");
                            type_effect("ENCRYPTION SCHEDULED IN");
                            printf(" %d ",H);
                            type_effect("HOUR(S)");
                            printf(" %d ",M);
                            type_effect("MINUTE(S)");
                            printf(" %d ",S);
                            type_effect("SECOND(S)");
                            printf("\nENTER 1 TO CONFIRM");
                        }
                        else if(lge==0){
                            printf("\n");
                            type_effect("CHIFFREMENT PREVU DANS");
                            printf(" %d ",H);
                            type_effect("HEURE(S)");
                            printf(" %d ",M);
                            type_effect("MINUTE(S)");
                            printf(" %d ",S);
                            type_effect("SECONDE(S)");
                            printf("\nENTRER 1 POUR CONFIRMER");
                        }
                        printf("\n> ");
                        if(scanf("%d",&con)!=1){
                            if(lge==1){
                                printf("\nINVALID INPUT,TRY AGAIN.");
                            }
                            else if(lge==0){
                                printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
                            }
                            while((clb=getchar()) != '\n' && clb != EOF);
                            con=0;
                        }
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
                while(d>(Md=GetDaysInMonth(mo, y))){
                    d-=(Md=GetDaysInMonth(mo, y));
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
                nb=NumbOfFile();
            }
            else{
                nb=1;
            }
            if(nb>1){
                rmdec=SamePasswd();
            }
            else{
                rmdec='N';
            }
            int mdec=1;
            crypt *crt;
            crt=(crypt *)calloc(nb,sizeof(crypt));
            if(crt==NULL){
                if(lge==1){
                    printf("ALLOCATION ERROR\n");
                    MessageBeep(MB_ICONHAND);
                    MessageBox(NULL, "ERROR(MAYBE INSUFFICIENT MEMORY)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                }
                else if(lge==0){
                    printf("ERREUR D'ALLOCATION\n");
                    MessageBeep(MB_ICONHAND);
                    MessageBox(NULL, "ERREUR(PEUT-ETRE DUE A UNE MEMOIRE INSUFFISANTE)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                }
                return 1;
            }
            for(K=0;K<nb;K++){
                do{
                    con=1;
                    crt[K].ney=calloc(200,sizeof(char));
                    if(crt[K].ney==NULL){
                        if(lge==1){
                            printf("ALLOCATION ERROR\n");
                            free(crt);
                            MessageBeep(MB_ICONHAND);
                            MessageBox(NULL, "ERROR(MAYBE INSUFFICIENT MEMORY)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        else if(lge==0){
                            printf("ERREUR D'ALLOCATION\n");
                            free(crt);
                            MessageBeep(MB_ICONHAND);
                            MessageBox(NULL, "ERREUR(PEUT-ETRE DUE A UNE MEMOIRE INSUFFISANTE)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        return 1;
                    }
                    if(lge==1){
                        printf("\nENTER THE FULL PATH OF THE FILE BY DRAGGING AND DROPPING THE FILE INTO THE CONSOLE");
                    }
                    else if(lge==0){
                        printf("\nENTRER LE CHEMIN COMPLET DU FICHIER EN GLISSANT ET DEPOSANT LE FICHIER DANS LA CONSOLE");
                    }
                    printf("\n> ");
                    if(scanf(" %199[^\n]",crt[K].ney) != 1){
                        if(lge==1){
                            printf("\nINVALID INPUT,TRY AGAIN.");
                        }
                        else if(lge==0){
                            printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                    }
                    while((clb=getchar()) != '\n' && clb != EOF);
                    if(crt[K].ney[0]== '\'' || crt[K].ney[0]== '\"' ){
                        memmove(crt[K].ney, crt[K].ney + 1, strlen(crt[K].ney)+1);
                    }
                    if(crt[K].ney[strlen(crt[K].ney)-1]== '\'' || crt[K].ney[strlen(crt[K].ney)-1]== '\"' ){
                        crt[K].ney[strlen(crt[K].ney)-1]='\0';
                    }
                    if(con!=0){
                        if(MODE==1){
                            if((crt[K].fl=fopen(crt[K].ney,"rb"))==NULL){
                                if(lge==1){
                                    printf("\nOPENING ERROR\n");
                                }
                                else if(lge==0){
                                    printf("\nERREUR D'OUVERTURE\n");
                                }
                                free(crt[K].ney);
                                con=0;

                            }
                        }
                        else if(MODE==3){
                            if(strnlen(crt[K].ney, 200) == 200 || crt[K].ney[0] == '\0' ){
                                if(lge==1){
                                    printf("\nINVALID STRING\n");
                                }
                                else if(lge==0){
                                    printf("\nCHAINE INVALIDE\n");
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
                        result = MessageBox(NULL, "DO YOU WANT TO REMOVE THE FILE AFTER ENCRYPTION ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONINFORMATION | MB_TOPMOST | MB_SETFOREGROUND);
                    }
                    else if(lge==0){
                        result = MessageBox(NULL, "VOUDRIEZ-VOUS SUPPRIMER LE FICHIER APRES CRYPTAGE ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONINFORMATION | MB_TOPMOST | MB_SETFOREGROUND);
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
                    PasswdInp(crt[K].paswd);
                    crt[K].v=VerInp();
                    for(I=0;I<10;I++){
                        if(I==0){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswd[I+2]+crt[K].paswd[I+3]-crt[K].paswd[I+4]+crt[K].paswd[I+5]-crt[K].paswd[I+6]+crt[K].paswd[I+7]-crt[K].paswd[I+8]+crt[K].paswd[I+9];
                        }
                        else if(I==1){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswd[I+2]+crt[K].paswd[I+3]-crt[K].paswd[I+4]+crt[K].paswd[I+5]-crt[K].paswd[I+6]+crt[K].paswd[I+7]-crt[K].paswd[I+8]+crt[K].paswdi[I-1];
                        }
                        else if(I==2){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswd[I+2]+crt[K].paswd[I+3]-crt[K].paswd[I+4]+crt[K].paswd[I+5]-crt[K].paswd[I+6]+crt[K].paswd[I+7]-crt[K].paswdi[I-1]+crt[K].paswdi[I-2];
                        }
                        else if(I==3){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswd[I+2]+crt[K].paswd[I+3]-crt[K].paswd[I+4]+crt[K].paswd[I+5]-crt[K].paswd[I+6]+crt[K].paswdi[I-1]-crt[K].paswdi[I-2]+crt[K].paswdi[I-3];
                        }
                        else if(I==4){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswd[I+2]+crt[K].paswd[I+3]-crt[K].paswd[I+4]+crt[K].paswd[I+5]-crt[K].paswdi[I-1]+crt[K].paswdi[I-2]-crt[K].paswdi[I-3]+crt[K].paswdi[I-4];
                        }
                        else if(I==5){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswd[I+2]+crt[K].paswd[I+3]-crt[K].paswd[I+4]+crt[K].paswdi[I-1]-crt[K].paswdi[I-2]+crt[K].paswdi[I-3]-crt[K].paswdi[I-4]+crt[K].paswdi[I-5];
                        }
                        else if(I==6){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswd[I+2]+crt[K].paswd[I+3]-crt[K].paswdi[I-1]+crt[K].paswdi[I-2]-crt[K].paswdi[I-3]+crt[K].paswdi[I-4]-crt[K].paswdi[I-5]+crt[K].paswdi[I-6];
                        }
                        else if(I==7){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswd[I+2]+crt[K].paswdi[I-1]-crt[K].paswdi[I-2]+crt[K].paswdi[I-3]-crt[K].paswdi[I-4]+crt[K].paswdi[I-5]-crt[K].paswdi[I-6]+crt[K].paswdi[I-7];
                        }
                        else if(I==8){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswdi[I-1]+crt[K].paswdi[I-2]-crt[K].paswdi[I-3]+crt[K].paswdi[I-4]-crt[K].paswdi[I-5]+crt[K].paswdi[I-6]-crt[K].paswdi[I-7]+crt[K].paswdi[I-8];
                        }
                        else{
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswdi[I-1]-crt[K].paswdi[I-2]+crt[K].paswdi[I-3]-crt[K].paswdi[I-4]+crt[K].paswdi[I-5]-crt[K].paswdi[I-6]+crt[K].paswdi[I-7]-crt[K].paswdi[I-8]+crt[K].paswdi[I-9];
                        }
                    }
                }
                if(rmdec=='Y'){
                    int rm, irm;
                    for(rm=0;rm<nb;rm++){
                        for(irm=0;irm<10;irm++){
                            crt[rm].paswdi[irm]=crt[K].paswdi[irm];
                        }
                    }
                    for(rm=0;rm<nb;rm++){
                        crt[rm].v=crt[K].v;
                    }
                    rmdec='N';
                    mdec=2;
                }
                crt[K].neyp=calloc(300,sizeof(char));
                if(crt[K].neyp==NULL){
                        if(lge==1){
                            printf("ALLOCATION ERROR\n");
                        }
                        else if(lge==0){
                            printf("ERREUR D'ALLOCATION\n");
                        }
                        free(crt[K].ney);
                        if(MODE==1){
                            fclose(crt[K].fl);
                        }
                        for(me=0;me<nb;me++){
                            memset(crt[me].paswd, 0, 11);
                            memset(crt[me].paswdi, 0, 10*sizeof(int));
                            crt[K].v=0;
                        }
                        free(crt);
                        MessageBeep(MB_ICONHAND);
                        if(lge==1){
                            MessageBox(NULL, "ENCRYPTION FAILED(ALLOCATION ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        else if(lge==0){
                            MessageBox(NULL, "LE CRYPTAGE A ECHOUE(ERREUR D'ALLOCATION)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }

                        return 1;
                }
                if(MODE==3){
                    printf("\n");
                    if(lge==1){
                        type_effect("THE ENCRYPTION WILL START AT :");
                    }
                    else if(lge==0){
                        type_effect("LE CRYPTAGE DEMARRERA A :");
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
                        MessageBox(NULL, "DON'T TURN OFF THE DEVICE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONEXCLAMATION);
                    }
                    else if(lge==0){
                        MessageBox(NULL, "N'ETEIGNEZ PAS L'APPAREIL", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONEXCLAMATION);
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
                                result=MessageBox(NULL, "\tDATE PAST\nTHE ENCRYPTION WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else if(lge==0){
                                result=MessageBox(NULL, "\tDATE DEPASSEE\nLE CRYPTAGE N'A PAS ETE FAIT\nVOULEZ-VOUS CRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                        }
                        else if(yn==y && mon>mo){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "\tDATE PAST\nTHE ENCRYPTION WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else if(lge==0){
                                result=MessageBox(NULL, "\tDATE DEPASSEE\nLE CRYPTAGE N'A PAS ETE FAIT\nVOULEZ-VOUS CRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                        }
                        else if(yn==y && mon==mo && dn>d){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "\tDATE PAST\nTHE ENCRYPTION WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else if(lge==0){
                                result=MessageBox(NULL, "\tDATE DEPASSEE\nLE CRYPTAGE N'A PAS ETE FAIT\nVOULEZ-VOUS CRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                        }
                        else if(yn==y && mon==mo && dn==d && Hn>H){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "\tDATE PAST\nTHE ENCRYPTION WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else if(lge==0){
                                result=MessageBox(NULL, "\tDATE DEPASSEE\nLE CRYPTAGE N'A PAS ETE FAIT\nVOULEZ-VOUS CRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                        }
                        else if(yn==y && mon==mo && dn==d && Hn==H && Mn>M){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "\tDATE PAST\nTHE ENCRYPTION WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else if(lge==0){
                                result=MessageBox(NULL, "\tDATE DEPASSEE\nLE CRYPTAGE N'A PAS ETE FAIT\nVOULEZ-VOUS CRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                        }
                        else if(yn==y && mon==mo && dn==d && Hn==H && Mn==M && Sn>S){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "\tDATE PAST\nTHE ENCRYPTION WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else if(lge==0){
                                result=MessageBox(NULL, "\tDATE DEPASSEE\nLE CRYPTAGE N'A PAS ETE FAIT\nVOULEZ-VOUS CRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR CRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                        }
                    }while(ct!=1);
                    if((crt[K].fl=fopen(crt[K].ney,"rb"))==NULL){
                        for(me=0;me<nb;me++){
                            memset(crt[me].paswd, 0, 11);
                            memset(crt[me].paswdi, 0, 10*sizeof(int));
                            crt[K].v=0;
                        }
                        MessageBeep(MB_ICONHAND);
                        if(lge==1){
                            snprintf(crt[K].neyp, 300, "%s NOT FOUND\nTHE PROCESS END WITHOUT FILE ENCRYPTING", crt[K].ney);
                        }
                        else if(lge==0){
                            snprintf(crt[K].neyp, 300, "%s N'A PAS ETE TROUVE\nLE PROCESSUS S'EST TERMINE SANS AVOIR CRYPTER LE FICHIER", crt[K].ney);
                        }
                        MessageBox(NULL, crt[K].neyp, "FILE_CRYPTER", MB_OK);
                        free(crt[K].ney);
                        free(crt[K].neyp);
                        free(crt);
                        return 1;
                    }
                }
                sprintf(crt[K].neyp,"%sc",crt[K].ney);
                if((prmr = FileExistanceChecking(crt[K].neyp)) == 0){
                    do{
                        con=1;
                        MessageBeep(MB_ICONHAND);
                        if(lge==1){
                            result = MessageBox(NULL, "A FILE WITH THE SAME NAME DETECTED\nCONTINUING WILL DELETE THIS ONE\nDO YOU WANT TO CONTINUE ?", "FILE_CRYPTER", MB_YESNO | MB_ICONWARNING);
                        }
                        else if(lge==0){
                            result = MessageBox(NULL, "FICHIER AVEC LE MEME NOM DETECTE\nCONTINUER SUPPRIMERA CELUI CI\nVOUDRIEZ-VOUS CONTINUER ?", "FILE_CRYPTER", MB_YESNO | MB_ICONWARNING);
                        }
                        if(result==IDYES){
                            if(lge==1){
                                show_message_async("THE OLD FILE WILL BE DELETED AND REPLACED BY THE NEW ONE","FILE_CRYPTER");
                            }
                            else if(lge==0){
                                show_message_async("L'ANCIEN FICHIER SERA SUPPRIME ET REMPLACE PAR LE NOUVEAU","FILE_CRYPTER");
                            }
                        }
                        else if(result==IDNO){
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            fclose(crt[K].fl);
                            for(me=0;me<nb;me++){
                                memset(crt[me].paswd, 0, 11);
                                memset(crt[me].paswdi, 0, 10*sizeof(int));
                                crt[K].v=0;
                            }
                            MessageBeep(MB_ICONHAND);
                            if(lge==1){
                                MessageBox(NULL, "ENCRYPTION STOPPED\nYOU CAN MAKE THIS EXISTING FILE COPY TO SAVE IT AND RESTART SAFELY", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                            }
                            else if(lge==0){
                                MessageBox(NULL, "LE CRYPTAGE A ETE ARRETE\nVOUS POUVEZ FAIRE LA COPIE DU FICHIER EXISTANT POUR LE SAUVEGARDER ET RECOMMENCEZ EN SECURITE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                            }
                            free(crt);
                            return 1;
                        }
                        else{
                            con=0;
                        }
                    }while(con!=1);
                }
                if((crt[K].flo=fopen(crt[K].neyp,"wb+"))==NULL){
                    if(lge==1){
                        printf("OPENING ERROR\n");
                    }
                    else if(lge==0){
                        printf("ERREUR D'OUVERTURE\n");
                    }
                    free(crt[K].ney);
                    free(crt[K].neyp);
                    fclose(crt[K].fl);
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL, "ENCRYPTION FAILED(OPENING ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    else if(lge==0){
                        MessageBox(NULL, "LE CRYPTAGE A ECHOUE(ERREUR D'OUVERTURE)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    for(me=0;me<nb;me++){
                        memset(crt[me].paswd, 0, 11);
                        memset(crt[me].paswdi, 0, 10*sizeof(int));
                        crt[K].v=0;
                    }
                    free(crt);
                    return 1;
                }
                pv=((crt[K].v+crt[K].paswdi[0]+crt[K].paswdi[1]+crt[K].paswdi[2]+crt[K].paswdi[3]+crt[K].paswdi[4]+crt[K].paswdi[5]+crt[K].paswdi[6]+crt[K].paswdi[7]+crt[K].paswdi[8]+crt[K].paswdi[9])/11);
                i=0;
                while((c=getc(crt[K].fl)) != EOF){
                    i+=1;
                    if(i%10==0){
                        c=c-crt[K].paswdi[0];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[0]=crt[K].paswdi[0]+(crt[K].v-3);
                    }
                    else if(i%10==1){
                        c=c-crt[K].paswdi[1];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[1]=crt[K].paswdi[1]+(crt[K].v-3);
                    }
                    else if(i%10==2){
                        c=c-crt[K].paswdi[2];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[2]=crt[K].paswdi[2]+(crt[K].v-3);
                    }
                    else if(i%10==3){
                        c=c-crt[K].paswdi[3];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[3]=crt[K].paswdi[3]+(crt[K].v-3);
                    }
                    else if(i%10==4){
                        c=c-crt[K].paswdi[4];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[4]=crt[K].paswdi[4]+(crt[K].v-3);
                    }
                    else if(i%10==5){
                        c=c-crt[K].paswdi[5];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[5]=crt[K].paswdi[5]+(crt[K].v-3);
                    }
                    else if(i%10==6){
                        c=c-crt[K].paswdi[6];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[6]=crt[K].paswdi[6]+(crt[K].v-3);
                    }
                    else if(i%10==7){
                        c=c-crt[K].paswdi[7];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[7]=crt[K].paswdi[7]+(crt[K].v-3);
                    }
                    else if(i%10==8){
                        c=c-crt[K].paswdi[8];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[8]=crt[K].paswdi[8]+(crt[K].v-3);
                    }
                    else{
                        c=c-crt[K].paswdi[9];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[9]=crt[K].paswdi[9]+(crt[K].v-3);
                    }
                }
                if((prmr = PermuteDataInFile(crt[K].flo, pv, 1)) == 0){
                    free(crt[K].ney);
                    fclose(crt[K].fl);
                    fclose(crt[K].flo);
                    remove(crt[K].neyp);
                    free(crt[K].neyp);
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL, "ENCRYPTION FAILED(PERMUTTING GONE WRONG)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    else if(lge==0){
                        MessageBox(NULL, "LE CRYPTAGE A ECHOUE(LA PERMUTATION N'A PAS MARCHE)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    for(me=0;me<nb;me++){
                        memset(crt[me].paswd, 0, 11);
                        memset(crt[me].paswdi, 0, 10*sizeof(int));
                        crt[K].v=0;
                    }
                    free(crt);
                    return 1;
                }
                free(crt[K].neyp);
                fclose(crt[K].fl);
                fclose(crt[K].flo);
                if(MODE==1){
                    if(ani==1){
                        printf("\n");
                        if(lge==1){
                            type_effect("NOW ENCRYPTING");
                        }
                        else if(lge==0){
                            type_effect("CRYPTAGE EN COURS");
                        }
                        loading();
                        printf("\n");
                        AnimationCrypt();
                    }
                    printf("\n%s ",crt[K].ney);
                    if(lge==1){
                        type_effect("ENCRYPTED SUCCESSFULLY");
                    }
                    else if(lge==0){
                        type_effect("CRYPTE AVEC SUCCES");
                    }
                    if(remo==1){
                        remove(crt[K].ney);
                    }
                    printf("\n");
                    memset(crt[K].paswd, 0, 11);
                    memset(crt[K].paswdi, 0, 10*sizeof(int));
                    crt[K].v=0;
                    if(nb==K+1){
                        MessageBeep(MB_ICONASTERISK);
                        if(lge==1){
                            show_message_async("ALL DONE", "FILE_CRYPTER");
                        }
                        else if(lge==0){
                            show_message_async("TERMINE", "FILE_CRYPTER");
                        }
                        Sleep(2000);
                    }
                }
                if(MODE==3){
                    if(remo==1){
                        remove(crt[K].ney);
                    }
                    memset(crt[K].paswd, 0, 11);
                    memset(crt[K].paswdi, 0, 10*sizeof(int));
                    crt[K].v=0;
                    MessageBeep(MB_ICONASTERISK);
                    if(lge==1){
                        MessageBox(NULL,"ENCRYPTION MADE SUCCESSFULLY", "FILE_CRYPTER", MB_OK | MB_ICONINFORMATION);
                    }
                    else if(lge==0){
                        MessageBox(NULL,"CRYPTAGE FAIT AVEC SUCCES", "FILE_CRYPTER", MB_OK | MB_ICONINFORMATION);
                    }
                }
                free(crt[K].ney);
            }
            free(crt);
            if(MODE==1){
                do{
                    con=1;
                    if(lge==1){
                        printf("\nDO YOU WANT TO PERFORM ANOTHER OPERATION (1) OR EXIT (0)");
                    }
                    else if(lge==0){
                        printf("\nVOULEZ-VOUS EFFECTUEZ UNE AUTRE OPERATION (1) OU QUITTER (0)");
                    }
                    printf("\n> ");
                    if(scanf("%d",&res)!=1){
                        if(lge==1){
                            printf("\nINVALID INPUT,TRY AGAIN.");
                        }
                        else if(lge==0){
                            printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
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
                    type_effect("##############################################   2-> DECRYPT FILE    ###################################################");
                    printf("\n");
                }
                else if(lge==0){
                    type_effect("#########################################   2-> DECRYPTER UN/DES FICHIER(S)    #########################################");
                    printf("\n");
                }
            }
            else{
                if(lge==1){
                    type_effect("###########################################   4-> DECRYPTION PLANNING    ###############################################");
                    printf("\n");
                }
                else if(lge==0){
                    type_effect("#########################################   4-> PLANIFIER UN DECRYPTAGE    #############################################");
                    printf("\n");
                }
            }
            if(ani==1){
                color_change1();
            }
            int nb, K, I, c, S, M, H, h, m, s, y, mo, d, dw, Md, Hf, pv, i, prmr, copr, result, me;
            char dwn[11], ehou[3], *neypp;
            char rmdec;
            FILE* flp;
            if(MODE==4){
                do{
                    con=1;
                    if(lge==1){
                        printf("\nSET DELAY BEFORE SCHEDULED ENCRYPTION(LESS THAN 49 DAYS)(TURN THE PC OFF WILL DELETE THE PROCESS)");
                    }
                    else if(lge==0){
                        printf("\nDEFINIR LE DELAI AVANT LE DECHIFFREMENT PROGRAMME(LESS THAN 49 DAYS)(TURN THE PC OFF WILL DELETE THE PROCESS)");
                    }
                    printf("\n> H: ");
                    if(scanf("%d",&H)!=1){
                        if(lge==1){
                            printf("\nINVALID INPUT,TRY AGAIN.");
                        }
                        else if(lge==0){
                            printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                    }
                    printf("\n> M: ");
                    if(scanf("%d",&M)!=1){
                        if(lge==1){
                            printf("\nINVALID INPUT,TRY AGAIN.");
                        }
                        else if(lge==0){
                            printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                    }
                    printf("\n> S: ");
                    if(scanf("%d",&S)!=1){
                        if(lge==1){
                            printf("\nINVALID INPUT,TRY AGAIN.");
                        }
                        else if(lge==0){
                            printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                    }
                    if(con!=0){
                        if(lge==1){
                            printf("\n");
                            type_effect("DECRYPTION SCHEDULED IN");
                            printf(" %d ",H);
                            type_effect("HOUR(S)");
                            printf(" %d ",M);
                            type_effect("MINUTE(S)");
                            printf(" %d ",S);
                            type_effect("SECOND(S)");
                            printf("\nENTER 1 TO CONFIRM");
                        }
                        else if(lge==0){
                            printf("\n");
                            type_effect("DECHIFFREMENT PREVU DANS");
                            printf(" %d ",H);
                            type_effect("HEURE(S)");
                            printf(" %d ",M);
                            type_effect("MINUTE(S)");
                            printf(" %d ",S);
                            type_effect("SECONDE(S)");
                            printf("\nENTRER 1 POUR CONFIRMER");
                        }
                        printf("\n> ");
                        if(scanf("%d",&con)!=1){
                            if(lge==1){
                                printf("\nINVALID INPUT,TRY AGAIN.");
                            }
                            else if(lge==0){
                                printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
                            }
                            while((clb=getchar()) != '\n' && clb != EOF);
                            con=0;
                        }
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
                while(d>(Md=GetDaysInMonth(mo, y))){
                    d-=(Md=GetDaysInMonth(mo, y));
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
                nb=NumbOfFile();
            }
            else{
                nb=1;
            }
            if(nb>1){
                rmdec=SamePasswd();
            }
            else{
                rmdec='N';
            }
            int mdec=1;
            crypt *crt;
            crt=(crypt *)calloc(nb,sizeof(crypt));
            if(crt==NULL){
                if(lge==1){
                    printf("ALLOCATION ERROR\n");
                    MessageBeep(MB_ICONHAND);
                    MessageBox(NULL, "ERROR(MAYBE INSUFFICIENT MEMORY)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                }
                else if(lge==0){
                    printf("ERREUR D'ALLOCATION\n");
                    MessageBeep(MB_ICONHAND);
                    MessageBox(NULL, "ERREUR(PEUT-ETRE DUE A UNE MEMOIRE INSUFFISANTE)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                }
                return 1;
            }
            for(K=0;K<nb;K++){
                do{
                    con=1;
                    crt[K].ney=calloc(200,sizeof(char));
                    if(crt[K].ney==NULL){
                        if(lge==1){
                            printf("ALLOCATION ERROR\n");
                            free(crt);
                            MessageBeep(MB_ICONHAND);
                            MessageBox(NULL, "ERROR(MAYBE INSUFFICIENT MEMORY)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        else if(lge==0){
                            printf("ERREUR D'ALLOCATION\n");
                            free(crt);
                            MessageBeep(MB_ICONHAND);
                            MessageBox(NULL, "ERREUR(PEUT-ETRE DUE A UNE MEMOIRE INSUFFISANTE)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        return 1;
                    }
                    if(lge==1){
                        printf("\nENTER THE FULL PATH OF THE FILE BY DRAGGING AND DROPPING THE FILE INTO THE CONSOLE");
                    }
                    else if(lge==0){
                        printf("\nENTRER LE CHEMIN COMPLET DU FICHIER EN GLISSANT ET DEPOSANT LE FICHIER DANS LA CONSOLE");
                    }
                    printf("\n> ");
                    if(scanf(" %199[^\n]",crt[K].ney) != 1){
                        if(lge==1){
                            printf("\nINVALID INPUT,TRY AGAIN.");
                        }
                        else if(lge==0){
                            printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                    }
                    while((clb=getchar()) != '\n' && clb != EOF);
                    if(crt[K].ney[0]== '\'' || crt[K].ney[0]== '\"' ){
                        memmove(crt[K].ney, crt[K].ney + 1, strlen(crt[K].ney)+1);
                    }
                    if(crt[K].ney[strlen(crt[K].ney)-1]== '\'' || crt[K].ney[strlen(crt[K].ney)-1]== '\"' ){
                        crt[K].ney[strlen(crt[K].ney)-1]='\0';
                    }
                    if(con!=0){
                        if(MODE==2){
                            if((crt[K].fl=fopen(crt[K].ney,"rb"))==NULL){
                                if(lge==1){
                                    printf("\nOPENING ERROR\n");
                                }
                                else if(lge==0){
                                    printf("\nERREUR D'OUVERTURE\n");
                                }
                                free(crt[K].ney);
                                con=0;
                            }
                        }
                        else if(MODE==4){
                            if(strnlen(crt[K].ney, 200) == 200 || crt[K].ney[0] == '\0' ){
                                if(lge==1){
                                    printf("\nINVALID STRING\n");
                                }
                                else if(lge==0){
                                    printf("\nCHAINE INVALIDE\n");
                                }
                                con=0;
                            }
                        }
                    }
                }while(con!=1);
                if(mdec==1){
                    PasswdInp(crt[K].paswd);
                    crt[K].v=VerInp();
                    for(I=0;I<10;I++){
                        if(I==0){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswd[I+2]+crt[K].paswd[I+3]-crt[K].paswd[I+4]+crt[K].paswd[I+5]-crt[K].paswd[I+6]+crt[K].paswd[I+7]-crt[K].paswd[I+8]+crt[K].paswd[I+9];
                        }
                        else if(I==1){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswd[I+2]+crt[K].paswd[I+3]-crt[K].paswd[I+4]+crt[K].paswd[I+5]-crt[K].paswd[I+6]+crt[K].paswd[I+7]-crt[K].paswd[I+8]+crt[K].paswdi[I-1];
                        }
                        else if(I==2){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswd[I+2]+crt[K].paswd[I+3]-crt[K].paswd[I+4]+crt[K].paswd[I+5]-crt[K].paswd[I+6]+crt[K].paswd[I+7]-crt[K].paswdi[I-1]+crt[K].paswdi[I-2];
                        }
                        else if(I==3){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswd[I+2]+crt[K].paswd[I+3]-crt[K].paswd[I+4]+crt[K].paswd[I+5]-crt[K].paswd[I+6]+crt[K].paswdi[I-1]-crt[K].paswdi[I-2]+crt[K].paswdi[I-3];
                        }
                        else if(I==4){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswd[I+2]+crt[K].paswd[I+3]-crt[K].paswd[I+4]+crt[K].paswd[I+5]-crt[K].paswdi[I-1]+crt[K].paswdi[I-2]-crt[K].paswdi[I-3]+crt[K].paswdi[I-4];
                        }
                        else if(I==5){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswd[I+2]+crt[K].paswd[I+3]-crt[K].paswd[I+4]+crt[K].paswdi[I-1]-crt[K].paswdi[I-2]+crt[K].paswdi[I-3]-crt[K].paswdi[I-4]+crt[K].paswdi[I-5];
                        }
                        else if(I==6){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswd[I+2]+crt[K].paswd[I+3]-crt[K].paswdi[I-1]+crt[K].paswdi[I-2]-crt[K].paswdi[I-3]+crt[K].paswdi[I-4]-crt[K].paswdi[I-5]+crt[K].paswdi[I-6];
                        }
                        else if(I==7){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswd[I+2]+crt[K].paswdi[I-1]-crt[K].paswdi[I-2]+crt[K].paswdi[I-3]-crt[K].paswdi[I-4]+crt[K].paswdi[I-5]-crt[K].paswdi[I-6]+crt[K].paswdi[I-7];
                        }
                        else if(I==8){
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswd[I+1]-crt[K].paswdi[I-1]+crt[K].paswdi[I-2]-crt[K].paswdi[I-3]+crt[K].paswdi[I-4]-crt[K].paswdi[I-5]+crt[K].paswdi[I-6]-crt[K].paswdi[I-7]+crt[K].paswdi[I-8];
                        }
                        else{
                            crt[K].paswdi[I]=crt[K].paswd[I];
                            crt[K].paswdi[I]=crt[K].paswdi[I]-((crt[K].v+5)*10)+crt[K].paswdi[I-1]-crt[K].paswdi[I-2]+crt[K].paswdi[I-3]-crt[K].paswdi[I-4]+crt[K].paswdi[I-5]-crt[K].paswdi[I-6]+crt[K].paswdi[I-7]-crt[K].paswdi[I-8]+crt[K].paswdi[I-9];
                        }
                    }
                }

                if(rmdec=='Y'){
                    int rm, irm;
                    for(rm=0;rm<nb;rm++){
                        for(irm=0;irm<10;irm++){
                            crt[rm].paswdi[irm]=crt[K].paswdi[irm];
                        }
                    }
                    for(rm=0;rm<nb;rm++){
                        crt[rm].v=crt[K].v;
                    }
                    rmdec='N';
                    mdec=2;
                }
                crt[K].neyp=calloc(300,sizeof(char));
                if(crt[K].neyp==NULL){
                        if(lge==1){
                            printf("\nALLOCATION ERROR\n");
                        }
                        else if(lge==0){
                            printf("\nERREUR D'ALLOCATION\n");
                        }
                        free(crt[K].ney);
                        fclose(crt[K].fl);
                        MessageBeep(MB_ICONHAND);
                        if(lge==1){
                            MessageBox(NULL, "DECRYPTION FAILED(ALLOCATION ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        else if(lge==0){
                            MessageBox(NULL, "LE DECRYPTAGE A ECHOUE(ERREUR D'ALLOCATION)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        }
                        for(me=0;me<nb;me++){
                            memset(crt[me].paswd, 0, 11);
                            memset(crt[me].paswdi, 0, 10*sizeof(int));
                            crt[K].v=0;
                        }
                        free(crt);
                        return 1;
                }
                if(MODE==4){
                    printf("\n");
                    if(lge==1){
                        type_effect("THE DECRYPTION WILL START AT :");
                    }
                    else if(lge==0){
                        type_effect("LE DECRYPTAGE DEMARRERA A :");
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
                        MessageBox(NULL, "DON'T TURN OFF THE DEVICE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONEXCLAMATION);
                    }
                    else if(lge==0){
                        MessageBox(NULL, "N'ETEIGNEZ PAS L'APPAREIL", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONEXCLAMATION);
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
                                result=MessageBox(NULL, "\tDATE PAST\nTHE DECRYPTION WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else if(lge==0){
                                result=MessageBox(NULL, "\tDATE DEPASSEE\nLE DECRYPTAGE N'A PAS ETE FAIT\nVOULEZ-VOUS DECRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                        }
                        else if(yn==y && mon>mo){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "\tDATE PAST\nTHE DECRYPTION WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else if(lge==0){
                                result=MessageBox(NULL, "\tDATE DEPASSEE\nLE DECRYPTAGE N'A PAS ETE FAIT\nVOULEZ-VOUS DECRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                        }
                        else if(yn==y && mon==mo && dn>d){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "\tDATE PAST\nTHE DECRYPTION WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else if(lge==0){
                                result=MessageBox(NULL, "\tDATE DEPASSEE\nLE DECRYPTAGE N'A PAS ETE FAIT\nVOULEZ-VOUS DECRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                        }
                        else if(yn==y && mon==mo && dn==d && Hn>H){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "\tDATE PAST\nTHE DECRYPTION WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else if(lge==0){
                                result=MessageBox(NULL, "\tDATE DEPASSEE\nLE DECRYPTAGE N'A PAS ETE FAIT\nVOULEZ-VOUS DECRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                        }
                        else if(yn==y && mon==mo && dn==d && Hn==H && Mn>M){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "\tDATE PAST\nTHE DECRYPTION WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else if(lge==0){
                                result=MessageBox(NULL, "\tDATE DEPASSEE\nLE DECRYPTAGE N'A PAS ETE FAIT\nVOULEZ-VOUS DECRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                        }
                        else if(yn==y && mon==mo && dn==d && Hn==H && Mn==M && Sn>S){
                            MessageBeep(MB_ICONQUESTION);
                            if(lge==1){
                                result=MessageBox(NULL, "\tDATE PAST\nTHE DECRYPTION WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            else if(lge==0){
                                result=MessageBox(NULL, "\tDATE DEPASSEE\nLE DECRYPTAGE N'A PAS ETE FAIT\nVOULEZ-VOUS DECRYPTER MAINTENANT ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                            }
                            if(result==IDYES){
                                ct=1;
                            }
                            else if(result==IDNO){
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                            else{
                                MessageBeep(MB_ICONASTERISK);
                                if(lge==1){
                                    show_message_async("THE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                                }
                                else if(lge==0){
                                    show_message_async("LE PROCESSUS S'EST TERMINE SANS AVOIR DECRYPTER LE FICHIER", "FILE_CRYPTER");
                                }
                                Sleep(2000);
                                free(crt[K].ney);
                                free(crt[K].neyp);
                                for(me=0;me<nb;me++){
                                    memset(crt[me].paswd, 0, 11);
                                    memset(crt[me].paswdi, 0, 10*sizeof(int));
                                    crt[K].v=0;
                                }
                                free(crt);
                                return 1;
                            }
                        }
                    }while(ct!=1);
                    if((crt[K].fl=fopen(crt[K].ney,"rb"))==NULL){
                        for(me=0;me<nb;me++){
                            memset(crt[me].paswd, 0, 11);
                            memset(crt[me].paswdi, 0, 10*sizeof(int));
                            crt[K].v=0;
                        }
                        MessageBeep(MB_ICONASTERISK);
                        if(lge==1){
                            snprintf(crt[K].neyp, 300, "%s NOT FOUND\nTHE PROCESS END WITHOUT FILE DECRYPTING", crt[K].ney);
                        }
                        else if(lge==0){
                            snprintf(crt[K].neyp, 300, "%s N'A PAS ETE TROUVE\nLE PROCESSUS S'EST TERMINE SANS AVOIR DECRYPTER LE FICHIER", crt[K].ney);
                        }
                        MessageBox(NULL, crt[K].neyp, "FILE_CRYPTER", MB_OK);
                        free(crt[K].ney);
                        free(crt[K].neyp);
                        free(crt);
                        return 1;
                    }
                }
                strcpy(crt[K].neyp,crt[K].ney);
                crt[K].neyp[strlen(crt[K].neyp)-1]='\0';
                if((prmr = FileExistanceChecking(crt[K].neyp)) == 0){
                    do{
                        con=1;
                        MessageBeep(MB_ICONHAND);
                        if(lge==1){
                            result = MessageBox(NULL, "A FILE WITH THE SAME NAME DETECTED\nCONTINUING WILL DELETE THIS ONE\nDO YOU WANT TO CONTINUE ?", "FILE_CRYPTER", MB_YESNO | MB_ICONWARNING);
                        }
                        else if(lge==0){
                            result = MessageBox(NULL, "FICHIER AVEC LE MEME NOM DETECTE\nCONTINUER SUPPRIMERA CELUI CI\nVOUDRIEZ-VOUS CONTINUER ?", "FILE_CRYPTER", MB_YESNO | MB_ICONWARNING);
                        }
                        if(result==IDYES){
                            if(lge==1){
                                show_message_async("THE OLD FILE WILL BE DELETED AND REPLACED BY THE NEW ONE","FILE_CRYPTER");
                            }
                            else if(lge==0){
                                show_message_async("L'ANCIEN FICHIER SERA SUPPRIME ET REMPLACE PAR LE NOUVEAU","FILE_CRYPTER");
                            }
                            Sleep(2000);
                        }
                        else if(result==IDNO){
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            fclose(crt[K].fl);
                            for(me=0;me<nb;me++){
                                memset(crt[me].paswd, 0, 11);
                                memset(crt[me].paswdi, 0, 10*sizeof(int));
                                crt[K].v=0;
                            }
                            MessageBeep(MB_ICONHAND);
                            if(lge==1){
                                MessageBox(NULL, "DECRYPTION STOPPED\nYOU CAN MAKE THIS EXISTING FILE COPY TO SAVE IT AND RESTART SAFELY", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                            }
                            else if(lge==0){
                                MessageBox(NULL, "LE DECRYPTAGE A ETE ARRETE\nVOUS POUVEZ FAIRE LA COPIE DU FICHIER EXISTANT POUR LE SAUVEGARDER ET RECOMMENCEZ EN SECURITE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                            }
                            free(crt);
                            return 1;
                        }
                        else{
                            con=0;
                        }
                    }while(con!=1);
                }
                if((crt[K].flo=fopen(crt[K].neyp,"wb"))==NULL){
                    if(lge==1){
                        printf("\nOPENING ERROR\n");
                    }
                    else if(lge==0){
                        printf("\nERREUR D'OUVERTURE\n");
                    }
                    free(crt[K].ney);
                    free(crt[K].neyp);
                    fclose(crt[K].fl);
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL, "DECRYPTION FAILED(OPENING ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    else if(lge==0){
                        MessageBox(NULL, "LE DECRYPTAGE A ECHOUE(ERREUR D'OUVERTURE)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    for(me=0;me<nb;me++){
                        memset(crt[me].paswd, 0, 11);
                        memset(crt[me].paswdi, 0, 10*sizeof(int));
                        crt[K].v=0;
                    }
                    free(crt);
                    return 1;
                }
                neypp=calloc(200,sizeof(char));
                if(neypp==NULL){
                    if(lge==1){
                        printf("ALLOCATION ERROR\n");
                    }
                    else if(lge==0){
                        printf("ERREUR D'ALLOCATION\n");
                    }
                    free(crt[K].ney);
                    fclose(crt[K].fl);
                    fclose(crt[K].flo);
                    remove(crt[K].neyp);
                    free(crt[K].neyp);
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL, "DECRYPTION FAILED(ALLOCATION ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    else if(lge==0){
                        MessageBox(NULL, "LE DECRYPTAGE A ECHOUE(ERREUR D'ALLOCATION)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    for(me=0;me<nb;me++){
                        memset(crt[me].paswd, 0, 11);
                        memset(crt[me].paswdi, 0, 10*sizeof(int));
                        crt[K].v=0;
                    }
                    free(crt);
                    return 1;
                }
                sprintf(neypp,"%ss",crt[K].ney);
                if((prmr = FileExistanceChecking(neypp)) == 0){
                    do{
                        con=1;
                        MessageBeep(MB_ICONHAND);
                        if(lge==1){
                            result = MessageBox(NULL, "A FILE WITH THE SAME NAME DETECTED\nCONTINUING WILL DELETE THIS ONE\nDO YOU WANT TO CONTINUE ?", "FILE_CRYPTER", MB_YESNO | MB_ICONWARNING);
                        }
                        else if(lge==0){
                            result = MessageBox(NULL, "FICHIER AVEC LE MEME NOM DETECTE\nCONTINUER SUPPRIMERA CELUI CI\nVOUDRIEZ-VOUS CONTINUER ?", "FILE_CRYPTER", MB_YESNO | MB_ICONWARNING);
                        }
                        if(result==IDYES){
                            if(lge==1){
                                show_message_async("THE OLD FILE WILL BE DELETED AND REPLACED BY THE NEW ONE","FILE_CRYPTER");
                            }
                            else if(lge==0){
                                show_message_async("L'ANCIEN FICHIER SERA SUPPRIME ET REMPLACE PAR LE NOUVEAU","FILE_CRYPTER");
                            }
                            Sleep(2000);
                        }
                        else if(result==IDNO){
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            fclose(crt[K].fl);
                            for(me=0;me<nb;me++){
                                memset(crt[me].paswd, 0, 11);
                                memset(crt[me].paswdi, 0, 10*sizeof(int));
                                crt[K].v=0;
                            }
                            MessageBeep(MB_ICONHAND);
                            if(lge==1){
                                MessageBox(NULL, "DECRYPTION STOPPED\nYOU CAN MAKE THIS EXISTING FILE COPY TO SAVE IT AND RESTART SAFELY", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                            }
                            else if(lge==0){
                                MessageBox(NULL, "LE DECRYPTAGE A ETE ARRETE\nVOUS POUVEZ FAIRE LA COPIE DU FICHIER EXISTANT POUR LE SAUVEGARDER ET RECOMMENCEZ EN SECURITE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                            }
                            free(crt);
                            return 1;
                        }
                        else{
                            con=0;
                        }
                    }while(con!=1);
                }
                if((flp=fopen(neypp,"wb+"))==NULL){
                    if(lge==1){
                        printf("\nOPENING ERROR\n");
                    }
                    else if(lge==0){
                        printf("\nERREUR D'OUVERTURE\n");
                    }
                    free(crt[K].ney);
                    free(neypp);
                    fclose(crt[K].fl);
                    fclose(crt[K].flo);
                    remove(crt[K].neyp);
                    free(crt[K].neyp);
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL, "DECRYPTION FAILED(OPENING ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    else if(lge==0){
                        MessageBox(NULL, "LE DECRYPTAGE A ECHOUE(ERREUR D'OUVERTURE)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    for(me=0;me<nb;me++){
                        memset(crt[me].paswd, 0, 11);
                        memset(crt[me].paswdi, 0, 10*sizeof(int));
                        crt[K].v=0;
                    }
                    free(crt);
                    return 1;
                }
                if((copr = Copy_File(crt[K].fl, flp)) == 0){
                    free(crt[K].ney);
                    fclose(crt[K].fl);
                    fclose(crt[K].flo);
                    fclose(flp);
                    remove(crt[K].neyp);
                    remove(neypp);
                    free(crt[K].neyp);
                    free(neypp);
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL, "DECRYPTION FAILED(COPYING ERROR)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    else if(lge==0){
                        MessageBox(NULL, "LE DECRYPTAGE A ECHOUE(ERREUR LORS DE LA COPIE)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    for(me=0;me<nb;me++){
                        memset(crt[me].paswd, 0, 11);
                        memset(crt[me].paswdi, 0, 10*sizeof(int));
                        crt[K].v=0;
                    }
                    free(crt);
                    return 1;
                }
                pv=((crt[K].v+crt[K].paswdi[0]+crt[K].paswdi[1]+crt[K].paswdi[2]+crt[K].paswdi[3]+crt[K].paswdi[4]+crt[K].paswdi[5]+crt[K].paswdi[6]+crt[K].paswdi[7]+crt[K].paswdi[8]+crt[K].paswdi[9])/11);
                if((prmr = PermuteDataInFile(flp, pv, 2)) == 0){
                    free(crt[K].ney);
                    fclose(crt[K].fl);
                    fclose(crt[K].flo);
                    fclose(flp);
                    remove(crt[K].neyp);
                    remove(neypp);
                    free(crt[K].neyp);
                    free(neypp);
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL, "DECRYPTION FAILED(PERMUTTING GONE WRONG)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    else if(lge==0){
                        MessageBox(NULL, "LE DECRYPTAGE A ECHOUE(LA PERMUTATION S'EST MAL PASSEE)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    }
                    for(me=0;me<nb;me++){
                        memset(crt[me].paswd, 0, 11);
                        memset(crt[me].paswdi, 0, 10*sizeof(int));
                        crt[K].v=0;
                    }
                    free(crt);
                    return 1;
                }
                i=0;
                while((c=getc(flp)) != EOF){
                    i+=1;
                    if(i%10==0){
                        c=c+crt[K].paswdi[0];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[0]=crt[K].paswdi[0]+(crt[K].v-3);
                    }
                    else if(i%10==1){
                        c=c+crt[K].paswdi[1];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[1]=crt[K].paswdi[1]+(crt[K].v-3);
                    }
                    else if(i%10==2){
                        c=c+crt[K].paswdi[2];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[2]=crt[K].paswdi[2]+(crt[K].v-3);
                    }
                    else if(i%10==3){
                        c=c+crt[K].paswdi[3];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[3]=crt[K].paswdi[3]+(crt[K].v-3);
                    }
                    else if(i%10==4){
                        c=c+crt[K].paswdi[4];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[4]=crt[K].paswdi[4]+(crt[K].v-3);
                    }
                    else if(i%10==5){
                        c=c+crt[K].paswdi[5];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[5]=crt[K].paswdi[5]+(crt[K].v-3);
                    }
                    else if(i%10==6){
                        c=c+crt[K].paswdi[6];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[6]=crt[K].paswdi[6]+(crt[K].v-3);
                    }
                    else if(i%10==7){
                        c=c+crt[K].paswdi[7];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[7]=crt[K].paswdi[7]+(crt[K].v-3);
                    }
                    else if(i%10==8){
                        c=c+crt[K].paswdi[8];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[8]=crt[K].paswdi[8]+(crt[K].v-3);
                    }
                    else{
                        c=c+crt[K].paswdi[9];
                        fputc(c, crt[K].flo);
                        crt[K].paswdi[9]=crt[K].paswdi[9]+(crt[K].v-3);
                    }
                }
                fclose(flp);
                remove(neypp);
                free(neypp);
                free(crt[K].neyp);
                fclose(crt[K].fl);
                fclose(crt[K].flo);
                if(MODE==2){
                    if(ani==1){
                        printf("\n");
                        if(lge==1){
                            type_effect("NOW DECRYPTING");
                        }
                        else if(lge==0){
                            type_effect("DECRYPTAGE EN COURS");
                        }
                        loading();
                        printf("\n");
                        AnimationCrypt();
                    }
                    printf("\n%s ",crt[K].ney);
                    if(lge==1){
                        type_effect("DECRYPTED SUCCESSFULLY");
                    }
                    else if(lge==0){
                        type_effect("DECRYPTE AVEC SUCCES");
                    }
                    printf("\n");
                    memset(crt[K].paswd, 0, 11);
                    memset(crt[K].paswdi, 0, 10*sizeof(int));
                    crt[K].v=0;
                    if(nb==K+1){
                        MessageBeep(MB_ICONASTERISK);
                        if(lge==1){
                            show_message_async("ALL DONE", "FILE_CRYPTER");
                        }
                        else if(lge==0){
                            show_message_async("TERMINE", "FILE_CRYPTER");
                        }
                        Sleep(2000);
                    }
                }
                if(MODE==4){
                    memset(crt[K].paswd, 0, 11);
                    memset(crt[K].paswdi, 0, 10*sizeof(int));
                    crt[K].v=0;
                    MessageBeep(MB_ICONHAND);
                    if(lge==1){
                        MessageBox(NULL,"DECRYPTION MADE SUCCESSFULLY", "FILE_CRYPTER", MB_OK | MB_ICONINFORMATION);
                    }
                    else if(lge==0){
                        MessageBox(NULL,"DECRYPTAGE FAIT AVEC SUCCES", "FILE_CRYPTER", MB_OK | MB_ICONINFORMATION);
                    }
                }
                free(crt[K].ney);
            }
            free(crt);
            if(MODE==2){
                do{
                    con=1;
                    if(lge==1){
                        printf("\nDO YOU WANT TO PERFORM ANOTHER OPERATION (1) OR EXIT (0)");
                    }
                    else if(lge==0){
                        printf("\nVOULEZ-VOUS EFFECTUEZ UNE AUTRE OPERATION (1) OU QUITTER (0)");
                    }
                    printf("\n> ");
                    if(scanf("%d",&res)!=1){
                        if(lge==1){
                            printf("\nINVALID INPUT,TRY AGAIN.");
                        }
                        else if(lge==0){
                            printf("\nENTREE INVALIDE, VEUILLEZ REESSAYEZ.");
                        }
                        while((clb=getchar()) != '\n' && clb != EOF);
                        con=0;
                    }
                }while(con!=1 || (res!=1 && res!=0));
                system("cls");
            }
        }
        else{
            if(lge==1){
                type_effect("##############################################   5-> EXIT            ###################################################");
            }
            else if(lge==0){
                type_effect("###########################################     5-> QUITTER          ###################################################");
            }
            if(ani==1){
                color_change1();
                printf("\n");
                if(lge==1){
                    type_effect("NOW CLOSING");
                }
                else if(lge==0){
                    type_effect("FERMETURE EN COURS");
                }
                loading();
            }
        }
    }
    return 0;
}
