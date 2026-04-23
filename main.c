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
    int MODE, con, clb;
    system("color 0A && title FILE_CRYPTER");
    Animation();
    home(0);
    do{
        con=1;
        home(1);
        if(scanf("%d",&MODE) != 1){
            type_effect("\nINVALID INPUT,TRY AGAIN.");
            while((clb=getchar()) != '\n' && clb != EOF);
            con=0;
        }
        printf("\n");
    }while(con!=1 || (MODE<1 || MODE>5 ));
    if(MODE==1 || MODE==3){
        if(MODE==1){
            type_effect("##############################################   1-> ENCRYPT FILE    ###################################################");
            printf("\n");
        }
        else{
            type_effect("###########################################   3-> ENCRYPTION PLANNING    ###############################################");
            printf("\n");
        }
        color_change1();
        int nb, K, I, c, S, M, H, h, m, s, y, mo, d, dw, Md, result, remo, Hf, pv, i, prmr, lan=0;
        char *dwn, *ehou;
        char rmdec;
        if(MODE==3){
            do{
                con=1;
                printf("\nIN HOW MUCH TIME YOU WANT TO START ENCRYPTION(LESS THAN 49 DAYS)(TURN THE PC OFF WILL DELETE THE PROCESS)");
                printf("\n> H: ");
                if(scanf("%d",&H)!=1){
                    printf("\nINVALID INPUT,TRY AGAIN.");
                    while((clb=getchar()) != '\n' && clb != EOF);
                    con=0;
                }
                printf("\n> M: ");
                if(scanf("%d",&M)!=1){
                    printf("\nINVALID INPUT,TRY AGAIN.");
                    while((clb=getchar()) != '\n' && clb != EOF);
                    con=0;
                }
                printf("\n> S: ");
                if(scanf("%d",&S)!=1){
                    printf("\nINVALID INPUT,TRY AGAIN.");
                    while((clb=getchar()) != '\n' && clb != EOF);
                    con=0;
                }
                if(con!=0){
                    printf("\n");
                    type_effect("YOU PLANNED THE ENCRYPTION IN");
                    printf(" %d ",H);
                    type_effect("HOUR(S)");
                    printf(" %d ",M);
                    type_effect("MINUTE(S)");
                    printf(" %d ",S);
                    type_effect("SECOND(S)");
                    printf("\nENTER 1 TO CONFIRM THE TIME AND ANOTHER NUMBER TO RE-ENTER ");
                    printf("\n> ");
                    if(scanf("%d",&con)!=1){
                        printf("\nINVALID INPUT,TRY AGAIN.");
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
            LANGID lang;
            lang = GetUserDefaultUILanguage();
            if(PRIMARYLANGID(lang) == LANG_ENGLISH){
                lan=1;
            }
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
            dwn=DayOfWeek(dw, lan);
            if(lan==1){
                Hf=H;
                if(H>11){
                    ehou="PM";
                }
                else{
                    ehou="AM";
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
            printf("OPENING ERROR\n");
            MessageBeep(MB_ICONHAND);
            MessageBox(NULL, "ERROR(MAYBE INSUFFICIENT MEMORY)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
            return 1;
        }
        for(K=0;K<nb;K++){
            do{
                con=1;
                crt[K].ney=calloc(200,sizeof(char));
                if(crt[K].ney==NULL){
                    printf("ERROR\n");
                    free(crt);
                    MessageBeep(MB_ICONHAND);
                    MessageBox(NULL, "ERROR(MAYBE INSUFFICIENT MEMORY)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    return 1;
                }
                printf("\nENTER THE FULL PATH OF THE FILE BY DRAGGING AND DROPPING THE FILE");
                printf("\n> ");
                if(scanf(" %199[^\n]",crt[K].ney) != 1){
                    printf("\nINVALID INPUT,TRY AGAIN.");
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
                            printf("\nOPENING ERROR\n");
                            free(crt[K].ney);
                            con=0;
                        }
                    }
                }
            }while(con!=1);
            do{
                con=1;
                MessageBeep(MB_ICONQUESTION);
                result = MessageBox(NULL, "DO YOU WANT TO REMOVE THE FILE AFTER ENCRYPTION ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONINFORMATION | MB_TOPMOST | MB_SETFOREGROUND);
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
                    printf("OPENING ERROR\n");
                    free(crt[K].ney);
                    if(MODE==1){
                        fclose(crt[K].fl);
                    }
                    free(crt);
                    MessageBeep(MB_ICONHAND);
                    MessageBox(NULL, "ENCRYPTION FAILED", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    return 1;
            }
            if(MODE==3){
                printf("\n");
                type_effect("THE ENCRYPTION WILL START AT :");
                printf("\n\t%d:%d:%d",H,M,S);
                if(lan==1){
                    printf(" %s",ehou);
                    H=Hf;
                }
                printf("\n%s %d/%d/%d",dwn,mo,d,y);
                Sleep(2000);
                MessageBeep(MB_ICONEXCLAMATION);
                MessageBox(NULL, "DON'T TURN OFF THE DEVICE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONEXCLAMATION);
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
                        result=MessageBox(NULL, "\tDATE PAST\nTHE ENCRYPTING WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                        if(result==IDYES){
                            ct=1;
                        }
                        else if(result==IDNO){
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                        else{
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                    }
                    else if(yn==y && mon>mo){
                        MessageBeep(MB_ICONQUESTION);
                        result=MessageBox(NULL, "\tDATE PAST\nTHE ENCRYPTING WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                        if(result==IDYES){
                            ct=1;
                        }
                        else if(result==IDNO){
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                        else{
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                    }
                    else if(yn==y && mon==mo && dn>d){
                        MessageBeep(MB_ICONQUESTION);
                        result=MessageBox(NULL, "\tDATE PAST\nTHE ENCRYPTING WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                        if(result==IDYES){
                            ct=1;
                        }
                        else if(result==IDNO){
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                        else{
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                    }
                    else if(yn==y && mon==mo && dn==d && Hn>H){
                        MessageBeep(MB_ICONQUESTION);
                        result=MessageBox(NULL, "\tDATE PAST\nTHE ENCRYPTING WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                        if(result==IDYES){
                            ct=1;
                        }
                        else if(result==IDNO){
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                        else{
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                    }
                    else if(yn==y && mon==mo && dn==d && Hn==H && Mn>M){
                        MessageBeep(MB_ICONQUESTION);
                        result=MessageBox(NULL, "\tDATE PAST\nTHE ENCRYPTING WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                        if(result==IDYES){
                            ct=1;
                        }
                        else if(result==IDNO){
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                        else{
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                    }
                    else if(yn==y && mon==mo && dn==d && Hn==H && Mn==M && Sn>S){
                        MessageBeep(MB_ICONQUESTION);
                        result=MessageBox(NULL, "\tDATE PAST\nTHE ENCRYPTING WASN'T DONE\nDO YOU WANT TO ENCRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                        if(result==IDYES){
                            ct=1;
                        }
                        else if(result==IDNO){
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                        else{
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE ENCRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                    }
                }while(ct!=1);
                if((crt[K].fl=fopen(crt[K].ney,"rb"))==NULL){
                    MessageBeep(MB_ICONASTERISK);
                    snprintf(crt[K].neyp, sizeof(crt[K].neyp), "%s NOT FOUND\nTHE PROCESS END WITHOUT FILE ENCRYPTING", crt[K].ney);
                    show_message_async(crt[K].neyp, "FILE_CRYPTER");
                    free(crt[K].ney);
                    free(crt[K].neyp);
                    free(crt);
                    Sleep(2000);
                    return 1;
                }
            }
            sprintf(crt[K].neyp,"%sc",crt[K].ney);
            if((prmr = FileExistanceChecking(crt[K].neyp)) == 0){
                do{
                    con=1;
                    MessageBeep(MB_ICONHAND);
                    result = MessageBox(NULL, "A FILE WITH SAME NAME DETECTED\nCONTINUING WILL DELETE THIS ONE\nDO YOU WANT TO CONTINUE ?", "FILE_CRYPTER", MB_YESNO | MB_ICONWARNING);
                    if(result==IDYES){
                        show_message_async("THE OLD FILE WILL BE DELETED AND REPLACED BY THE NEW ONE","FILE_CRYPTER");
                        Sleep(2000);
                    }
                    else if(result==IDNO){
                        free(crt[K].ney);
                        free(crt[K].neyp);
                        fclose(crt[K].fl);
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "ENCRYPTION STOPPED\nYOU CAN MAKE THIS EXISTING FILE COPY TO SAVE IT AND RESTART SAFELY", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        free(crt);
                        return 1;
                    }
                    else{
                        con=0;
                    }
                }while(con!=1);
            }
            if((crt[K].flo=fopen(crt[K].neyp,"wb+"))==NULL){
                printf("ERROR\n");
                free(crt[K].ney);
                free(crt[K].neyp);
                fclose(crt[K].fl);
                MessageBeep(MB_ICONHAND);
                MessageBox(NULL, "ENCRYPTION FAILED", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
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
                if(MODE==1){
                    MessageBeep(MB_ICONHAND);
                    MessageBox(NULL, "ENCRYPTION FAILED(PERMUTTING GONE WRONG)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                }
                if(MODE==3){
                    MessageBeep(MB_ICONHAND);
                    MessageBox(NULL, "ENCRYPTION FAILED(PERMUTTING GONE WRONG)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                }
                free(crt);
                return 1;
            }
            free(crt[K].neyp);
            fclose(crt[K].fl);
            fclose(crt[K].flo);
            if(MODE==1){
                printf("\n");
                type_effect("NOW ENCRYPTING");
                loading();
                printf("\n%s ",crt[K].ney);
                if(remo==1){
                    remove(crt[K].ney);
                }
                type_effect("ENCRYPTED SUCCESSFULLY");
                printf("\n");
                if(nb==K+1){
                    MessageBeep(MB_ICONASTERISK);
                    show_message_async("ALL DONE", "FILE_CRYPTER");
                    Sleep(2000);
                }
            }
            if(MODE==3){
                if(remo==1){
                    remove(crt[K].ney);
                }
                MessageBeep(MB_ICONASTERISK);
                MessageBox(NULL,"ENCRYPTION MADE SUCCESSFULLY\n\t\t\t\t\t\t\tSUCCESS", "FILE_CRYPTER", MB_OK | MB_ICONINFORMATION);
            }
            free(crt[K].ney);
        }
        free(crt);
    }
    else if(MODE==2 || MODE==4){
        if(MODE==2){
            type_effect("##############################################   2-> DECRYPT FILE    ###################################################");
            printf("\n");
        }
        else{
            type_effect("###########################################   4-> DECRYPTION PLANNING    ###############################################");
            printf("\n");
        }
        color_change1();
        int nb, K, I, c, S, M, H, h, m, s, y, mo, d, dw, Md, Hf, pv, i, prmr, copr, result, lan=0;
        char *dwn, *ehou, *neypp;
        char rmdec;
        FILE* flp;
        if(MODE==4){
            do{
                con=1;
                printf("\nIN HOW MUCH TIME YOU WANT TO START DECRYPTION(LESS THAN 49 DAYS)(TURN THE PC OFF WILL DELETE THE PROCESS)");
                printf("\n> H: ");
                if(scanf("%d",&H)!=1){
                    printf("\nINVALID INPUT,TRY AGAIN.");
                    while((clb=getchar()) != '\n' && clb != EOF);
                    con=0;
                }
                printf("\n> M: ");
                if(scanf("%d",&M)!=1){
                    printf("\nINVALID INPUT,TRY AGAIN.");
                    while((clb=getchar()) != '\n' && clb != EOF);
                    con=0;
                }
                printf("\n> S: ");
                if(scanf("%d",&S)!=1){
                    printf("\nINVALID INPUT,TRY AGAIN.");
                    while((clb=getchar()) != '\n' && clb != EOF);
                    con=0;
                }
                if(con!=0){
                    printf("\n");
                    type_effect("YOU PLANNED THE DECRYPTION IN");
                    printf(" %d ",H);
                    type_effect("HOUR(S)");
                    printf(" %d ",M);
                    type_effect("MINUTE(S)");
                    printf(" %d ",S);
                    type_effect("SECOND(S)");
                    printf("\nENTER 1 TO CONFIRM THE TIME AND ANOTHER NUMBER TO RE-ENTER ");
                    printf("\n> ");
                    if(scanf("%d",&con)!=1){
                        printf("\nINVALID INPUT,TRY AGAIN.");
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
            LANGID lang;
            lang = GetUserDefaultUILanguage();
            if(PRIMARYLANGID(lang) == LANG_ENGLISH){
                lan=1;
            }
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
            dwn=DayOfWeek(dw, lan);
            if(lan==1){
                Hf=H;
                if(H>11){
                    ehou="PM";
                }
                else{
                    ehou="AM";
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
            printf("ERROR\n");
            MessageBeep(MB_ICONHAND);
            MessageBox(NULL, "ERROR(MAYBE INSUFFICIENT MEMORY)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
            return 1;
        }
        for(K=0;K<nb;K++){
            do{
                con=1;
                crt[K].ney=calloc(200,sizeof(char));
                if(crt[K].ney==NULL){
                    printf("ERROR\n");
                    free(crt);
                    MessageBeep(MB_ICONHAND);
                    MessageBox(NULL, "ERROR(MAYBE INSUFFICIENT MEMORY)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    return 1;
                }
                printf("\nENTER THE FULL PATH OF THE CRYPTED FILE BY DRAGGING AND DROPPING THE FILE");
                printf("\n> ");
                if(scanf(" %199[^\n]",crt[K].ney) != 1){
                    printf("\nINVALID INPUT,TRY AGAIN.");
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
                            printf("\nOPENING ERROR\n");
                            free(crt[K].ney);
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
                    printf("OPENING ERROR\n");
                    free(crt[K].ney);
                    fclose(crt[K].fl);
                    MessageBeep(MB_ICONHAND);
                    MessageBox(NULL, "DECRYPTION FAILED", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                    free(crt);
                    return 1;
            }
            if(MODE==4){
                printf("\n");
                type_effect("THE DECRYPTION WILL START AT :");
                printf("\n\t%d:%d:%d",H,M,S);
                if(lan==1){
                    printf(" %s",ehou);
                    H=Hf;
                }
                printf("\n%s %d/%d/%d",dwn,mo,d,y);
                Sleep(2000);
                MessageBeep(MB_ICONEXCLAMATION);
                MessageBox(NULL, "DON'T TURN OFF THE DEVICE", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONEXCLAMATION);
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
                        result=MessageBox(NULL, "\tDATE PAST\nTHE DECRYPTING WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                        if(result==IDYES){
                            ct=1;
                        }
                        else if(result==IDNO){
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                        else{
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                    }
                    else if(yn==y && mon>mo){
                        MessageBeep(MB_ICONQUESTION);
                        result=MessageBox(NULL, "\tDATE PAST\nTHE DECRYPTING WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                        if(result==IDYES){
                            ct=1;
                        }
                        else if(result==IDNO){
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                        else{
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                    }
                    else if(yn==y && mon==mo && dn>d){
                        MessageBeep(MB_ICONQUESTION);
                        result=MessageBox(NULL, "\tDATE PAST\nTHE DECRYPTING WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                        if(result==IDYES){
                            ct=1;
                        }
                        else if(result==IDNO){
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                        else{
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                    }
                    else if(yn==y && mon==mo && dn==d && Hn>H){
                        MessageBeep(MB_ICONQUESTION);
                        result=MessageBox(NULL, "\tDATE PAST\nTHE DECRYPTING WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                        if(result==IDYES){
                            ct=1;
                        }
                        else if(result==IDNO){
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                        else{
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                    }
                    else if(yn==y && mon==mo && dn==d && Hn==H && Mn>M){
                        MessageBeep(MB_ICONQUESTION);
                        result=MessageBox(NULL, "\tDATE PAST\nTHE DECRYPTING WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                        if(result==IDYES){
                            ct=1;
                        }
                        else if(result==IDNO){
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                        else{
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                    }
                    else if(yn==y && mon==mo && dn==d && Hn==H && Mn==M && Sn>S){
                        MessageBeep(MB_ICONQUESTION);
                        result=MessageBox(NULL, "\tDATE PAST\nTHE DECRYPTING WASN'T DONE\nDO YOU WANT TO DECRYPT NOW ?", "FILE_CRYPTER", MB_YESNOCANCEL | MB_ICONWARNING | MB_TOPMOST | MB_SETFOREGROUND);
                        if(result==IDYES){
                            ct=1;
                        }
                        else if(result==IDNO){
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                        else{
                            MessageBeep(MB_ICONASTERISK);
                            show_message_async("\tTHE PROCESS END WITHOUT FILE DECRYPTING", "FILE_CRYPTER");
                            Sleep(2000);
                            free(crt[K].ney);
                            free(crt[K].neyp);
                            free(crt);
                            return 1;
                        }
                    }
                }while(ct!=1);
                if((crt[K].fl=fopen(crt[K].ney,"rb"))==NULL){
                    MessageBeep(MB_ICONASTERISK);
                    snprintf(crt[K].neyp,sizeof(crt[K].neyp),"%s NOT FOUND\nTHE PROCESS END WITHOUT FILE DECRYPTING",crt[K].ney);
                    show_message_async(crt[K].neyp, "FILE_CRYPTER");
                    free(crt[K].ney);
                    free(crt[K].neyp);
                    free(crt);
                    Sleep(2000);
                    return 1;
                }
            }
            strcpy(crt[K].neyp,crt[K].ney);
            crt[K].neyp[strlen(crt[K].neyp)-1]='\0';
            if((prmr = FileExistanceChecking(crt[K].neyp)) == 0){
                do{
                    con=1;
                    MessageBeep(MB_ICONHAND);
                    result = MessageBox(NULL, "A FILE WITH SAME NAME DETECTED\nCONTINUING WILL DELETE THIS ONE\nDO YOU WANT TO CONTINUE ?", "FILE_CRYPTER", MB_YESNO | MB_ICONWARNING);
                    if(result==IDYES){
                        show_message_async("THE OLD FILE WILL BE DELETED AND REPLACED BY THE NEW ONE","FILE_CRYPTER");
                        Sleep(2000);
                    }
                    else if(result==IDNO){
                        free(crt[K].ney);
                        free(crt[K].neyp);
                        fclose(crt[K].fl);
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "DECRYPTION STOPPED\nYOU CAN MAKE THIS EXISTING FILE COPY TO SAVE IT AND RESTART SAFELY", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        free(crt);
                        return 1;
                    }
                    else{
                        con=0;
                    }
                }while(con!=1);
            }
            if((crt[K].flo=fopen(crt[K].neyp,"wb"))==NULL){
                printf("ERROR\n");
                free(crt[K].ney);
                free(crt[K].neyp);
                fclose(crt[K].fl);
                MessageBeep(MB_ICONHAND);
                MessageBox(NULL, "DECRYPTION FAILED", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                free(crt);
                return 1;
            }
            neypp=calloc(200,sizeof(char));
            if(neypp==NULL){
                printf("OPENING ERROR\n");
                free(crt[K].ney);
                fclose(crt[K].fl);
                fclose(crt[K].flo);
                remove(crt[K].neyp);
                free(crt[K].neyp);
                MessageBeep(MB_ICONHAND);
                MessageBox(NULL, "DECRYPTION FAILED", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                free(crt);
                return 1;
            }
            sprintf(neypp,"%ss",crt[K].ney);
            if((prmr = FileExistanceChecking(neypp)) == 0){
                do{
                    con=1;
                    MessageBeep(MB_ICONHAND);
                    result = MessageBox(NULL, "A FILE WITH SAME NAME DETECTED\nCONTINUING WILL DELETE THIS ONE\nDO YOU WANT TO CONTINUE ?", "FILE_CRYPTER", MB_YESNO | MB_ICONWARNING);
                    if(result==IDYES){
                        show_message_async("THE OLD FILE WILL BE DELETED AND REPLACED BY THE NEW ONE","FILE_CRYPTER");
                        Sleep(2000);
                    }
                    else if(result==IDNO){
                        free(crt[K].ney);
                        free(neypp);
                        fclose(crt[K].fl);
                        fclose(crt[K].flo);
                        remove(crt[K].neyp);
                        free(crt[K].neyp);
                        MessageBeep(MB_ICONHAND);
                        MessageBox(NULL, "DECRYPTION STOPPED\nYOU CAN MAKE THIS EXISTING FILE COPY TO SAVE IT AND RESTART SAFELY", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
                        free(crt);
                        return 1;
                    }
                    else{
                        con=0;
                    }
                }while(con!=1);
            }
            if((flp=fopen(neypp,"wb+"))==NULL){
                printf("OPENING ERROR\n");
                free(crt[K].ney);
                free(neypp);
                fclose(crt[K].fl);
                fclose(crt[K].flo);
                remove(crt[K].neyp);
                free(crt[K].neyp);
                MessageBeep(MB_ICONHAND);
                MessageBox(NULL, "DECRYPTION FAILED", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
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
                MessageBox(NULL, "DECRYPTION FAILED(COPYING GONE WRONG)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
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
                MessageBox(NULL, "DECRYPTION FAILED(PERMUTTING GONE WRONG)", "FILE_CRYPTER", MB_OKCANCEL | MB_ICONERROR);
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
            if(MODE==2){
                printf("\n");
                type_effect("NOW DECRYPTING");
                loading();
                printf("\n%s ",crt[K].ney);
                type_effect("DECRYPTED SUCCESSFULLY");
                printf("\n");
                if(nb==K+1){
                    MessageBeep(MB_ICONASTERISK);
                    show_message_async("ALL DONE", "FILE_CRYPTER");
                    Sleep(2000);
                }
            }
            free(crt[K].neyp);
            fclose(crt[K].fl);
            fclose(crt[K].flo);
            if(MODE==4){
                MessageBeep(MB_ICONHAND);
                MessageBox(NULL,"DECRYPTION MADE SUCCESSFULLY\n\t\t\t\t\t\t\tSUCCESS", "FILE_CRYPTER", MB_OK | MB_ICONINFORMATION);
            }
            free(crt[K].ney);
            fclose(flp);
            remove(neypp);
            free(neypp);
        }
        free(crt);
    }
    else{
        printf("\n");
        type_effect("##############################################   5-> EXIT            ###################################################");
        color_change1();
        printf("\n");
        type_effect("NOW CLOSING");
        loading();
    }
    return 0;
}
