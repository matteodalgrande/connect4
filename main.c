#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define GRANTAB 9
int colonna,riga;
int giocatore=2;
int i,j,k;
int tabella[GRANTAB][GRANTAB];
int vittoria=0;

enum tab{VUOTO=' ',P1=248,P2=254};

void regole();
void inizializza_tabella();
void stampa_tabella();
void scelta_utente();
int trova_riga();
void inserimento_dati_in_tabella();
void controllo_vittoria();
void gestione_giocatore();


int main(){

    inizializza_tabella();
    stampa_tabella();
    system("color 0C");

    /*Inserisco un ciclo che sia in grado di di fare inserie sia agli utenti le loro scelte e che anche se ho iniziato inizialmente il giocatore a 2 lo controlla all'inizio cambiandolo.*/
    do{
    gestione_giocatore();
    scelta_utente();
    if(giocatore==1)system("color 02");
    else if(giocatore==2)system("color 0c");
    riga=trova_riga();
    inserimento_dati_in_tabella();
    stampa_tabella();
    controllo_vittoria();
    }while(vittoria!=1);

    /*Se il giocatore che vince è il primo,*/
    if(giocatore==1){system("color 0b");printf("\n VITTORIA GIOCATORE 1");}
    else if(giocatore==2){system("color 0b"); printf("\n VITTORIA GIOCATORE 2");}
    return 0;
}

void regole(){
printf("\tFORZA 4:\n");
printf("\nsi vince facendo 4 posizioni uguali  di fila\n");
};
void inizializza_tabella(){
    for(i=0;i<GRANTAB;i++)
        for(j=0;j<GRANTAB;j++)
        tabella[i][j]=VUOTO;
};
void scelta_utente(){
    if (giocatore==1)
        printf("\nGIOCATORE 1\n");
    else if(giocatore==2) printf("\nGIOCATORE 2\n");
    do{
    printf("COLONNA");
    scanf("%d",&colonna);}while(colonna<1||colonna>10);
    colonna-=1;
};
int trova_riga(){
    int controllo=0;
    int rig=9;
    do{
    --rig;
    if(tabella[rig][colonna]==VUOTO){
           controllo=1;
           }//if
    }while(controllo==0);
    return rig;
};
void stampa_tabella(){
    int contnum=49;
    int angoloasx=201;
    int angoloadx=187;
    int angolobsx=200;
    int angolobdx=188;
    int verticale=186;
    int orrizzontale=205;
    int sxdxdown=203;
    int updowndx=204;
    int dxsxup=202;
    int tutti=206;
    int updownsx=185;

    system("cls");
    regole();


    //stampa la prima riga
    printf("%c",angoloasx);
    for(i=0;i<GRANTAB;i++)
    printf("%c%c%c%c%c%c",orrizzontale,orrizzontale,orrizzontale,orrizzontale,orrizzontale,sxdxdown);
    printf("\b%c",angoloadx);


    for(i=0;i<GRANTAB;i++){
            printf("\n%c",verticale);
        for(j=0;j<GRANTAB;j++)
            printf("%3c  %c",tabella[i][j],verticale);

        printf("\n%c",updowndx);
        for(k=0;k<GRANTAB;k++)
            printf("%c%c%c%c%c%c",orrizzontale,orrizzontale,orrizzontale,orrizzontale,orrizzontale,tutti);
            printf("\b%c",updownsx);
            }//for i

    //inserisco riga con i numeri("ultima riga")
   printf("\n%c",verticale);
        for(j=0;j<GRANTAB;j++)
            printf("%3c  %c",contnum++,verticale);

        printf("\n%c",updowndx);
        for(k=0;k<GRANTAB;k++)
            printf("%c%c%c%c%c%c",orrizzontale,orrizzontale,orrizzontale,orrizzontale,orrizzontale,tutti);
            printf("\b%c",updownsx);

    //chiusura
        for(k=0;k<GRANTAB;k++)
            printf("\b\b\b\b\b\b");
        printf("\b%c",angolobsx);
        for(k=0;k<GRANTAB;k++)
        printf("%c%c%c%c%c%c",orrizzontale,orrizzontale,orrizzontale,orrizzontale,orrizzontale,dxsxup);
      printf("\b%c",angolobdx);
};
void inserimento_dati_in_tabella(){
    if(giocatore==1){
        tabella[riga][colonna]=P1;
    }
    else if(giocatore==2){
        tabella[riga][colonna]=P2;
    }
};
void controllo_vittoria(){
    //controllo  righe
    if(2<colonna&&colonna<=8&&vittoria==0){
        if((tabella[riga][colonna]==tabella[riga][colonna-1])&&(tabella[riga][colonna]==tabella[riga][colonna-2])&&(tabella[riga][colonna]==tabella[riga][colonna-3])&&giocatore==1){
            vittoria=1;
        }
        else if((tabella[riga][colonna]==tabella[riga][colonna-1])&&(tabella[riga][colonna]==tabella[riga][colonna-2])&&(tabella[riga][colonna]==tabella[riga][colonna-3])&&giocatore==2){
            vittoria=1;
        }
        }//if
    else if(0<=colonna&&colonna<=2&&vittoria==0){
        if((tabella[riga][colonna]==tabella[riga][colonna+1])&&(tabella[riga][colonna]==tabella[riga][colonna+2])&&(tabella[riga][colonna]==tabella[riga][colonna+3])&&giocatore==1){
            vittoria=1;
        }
        else if((tabella[riga][colonna]==tabella[riga][colonna+1])&&(tabella[riga][colonna]==tabella[riga][colonna+2])&&(tabella[riga][colonna]==tabella[riga][colonna+3])&&giocatore==2){
            vittoria=1;
        }
        }//if
    //controllo colonna
    if(0<=riga&&riga<=2&&vittoria==0){
        if((tabella[riga][colonna]==tabella[riga-1][colonna])&&(tabella[riga][colonna]==tabella[riga-2][colonna])&&(tabella[riga][colonna]==tabella[riga-3][colonna])&&giocatore==1){
            vittoria=1;
        }
        else if((tabella[riga][colonna]==tabella[riga-1][colonna])&&(tabella[riga][colonna]==tabella[riga-2][colonna])&&(tabella[riga][colonna]==tabella[riga-3][colonna])&&giocatore==2){
            vittoria=1;
        }
        }//if
    else if(2<riga&&riga<=8&&vittoria==0){
        if((tabella[riga][colonna]==tabella[riga+1][colonna])&&(tabella[riga][colonna]==tabella[riga+2][colonna])&&(tabella[riga][colonna]==tabella[riga+3][colonna])&&giocatore==1){
            vittoria=1;
        }

        else if((tabella[riga][colonna]==tabella[riga+1][colonna])&&(tabella[riga][colonna]==tabella[riga+2][colonna])&&(tabella[riga][colonna]==tabella[riga+3][colonna])&&giocatore==2){
            vittoria=1;
        }
        }//if
    //controllo orizzontali 1

        if((tabella[riga][colonna]==tabella[riga-1][colonna-1])&&(tabella[riga][colonna]==tabella[riga-2][colonna-2])&&(tabella[riga][colonna]==tabella[riga-3][colonna-3])&&giocatore==1){
            vittoria=1;
        }
        else if((tabella[riga][colonna]==tabella[riga-1][colonna-1])&&(tabella[riga][colonna]==tabella[riga-2][colonna-2])&&(tabella[riga][colonna]==tabella[riga-3][colonna-3])&&giocatore==2){
            vittoria=1;
        }


        if((tabella[riga][colonna]==tabella[riga+1][colonna+1])&&(tabella[riga][colonna]==tabella[riga+2][colonna+2])&&(tabella[riga][colonna]==tabella[riga+3][colonna+3])&&giocatore==1){
            vittoria=1;
        }

        else if((tabella[riga][colonna]==tabella[riga+1][colonna+1])&&(tabella[riga][colonna]==tabella[riga+2][colonna+2])&&(tabella[riga][colonna]==tabella[riga+3][colonna+3])&&giocatore==2){
            vittoria=1;
        }






        if((tabella[riga][colonna]==tabella[riga+1][colonna-1])&&(tabella[riga][colonna]==tabella[riga+2][colonna-2])&&(tabella[riga][colonna]==tabella[riga+3][colonna-3])&&giocatore==1){
            vittoria=1;
        }
        else if((tabella[riga][colonna]==tabella[riga+1][colonna-1])&&(tabella[riga][colonna]==tabella[riga+2][colonna-2])&&(tabella[riga][colonna]==tabella[riga+3][colonna-3])&&giocatore==2){
            vittoria=1;
        }


        if((tabella[riga][colonna]==tabella[riga-1][colonna+1])&&(tabella[riga][colonna]==tabella[riga-2][colonna+2])&&(tabella[riga][colonna]==tabella[riga-3][colonna+3])&&giocatore==1){
            vittoria=1;
        }

        else if((tabella[riga][colonna]==tabella[riga-1][colonna+1])&&(tabella[riga][colonna]==tabella[riga-2][colonna+2])&&(tabella[riga][colonna]==tabella[riga-3][colonna+3])&&giocatore==2){
            vittoria=1;
        }
    //controllo orizozntali sfalsati di due ed uno

        if((tabella[riga][colonna]==tabella[riga-1][colonna-1])&&(tabella[riga][colonna]==tabella[riga+1][colonna+1])&&(tabella[riga][colonna]==tabella[riga+2][colonna+2])&&giocatore==1){
            vittoria=1;
        }
        else if((tabella[riga][colonna]==tabella[riga-1][colonna-1])&&(tabella[riga][colonna]==tabella[riga+1][colonna+1])&&(tabella[riga][colonna]==tabella[riga+2][colonna+2])&&giocatore==2){
            vittoria=1;
        }


        if((tabella[riga][colonna]==tabella[riga+1][colonna+1])&&(tabella[riga][colonna]==tabella[riga-1][colonna-1])&&(tabella[riga][colonna]==tabella[riga-2][colonna-2])&&giocatore==1){
            vittoria=1;
        }

        else if((tabella[riga][colonna]==tabella[riga+1][colonna+1])&&(tabella[riga][colonna]==tabella[riga-1][colonna-1])&&(tabella[riga][colonna]==tabella[riga-2][colonna-2])&&giocatore==2){
            vittoria=1;
        }



          if((tabella[riga][colonna]==tabella[riga+1][colonna-1])&&(tabella[riga][colonna]==tabella[riga-1][colonna+1])&&(tabella[riga][colonna]==tabella[riga-2][colonna+2])&&giocatore==1){
            vittoria=1;
        }
        else if((tabella[riga][colonna]==tabella[riga+1][colonna-1])&&(tabella[riga][colonna]==tabella[riga-1][colonna+1])&&(tabella[riga][colonna]==tabella[riga-2][colonna+2])&&giocatore==2){
            vittoria=1;
        }


        if((tabella[riga][colonna]==tabella[riga-1][colonna+1])&&(tabella[riga][colonna]==tabella[riga+1][colonna-1])&&(tabella[riga][colonna]==tabella[riga+2][colonna-2])&&giocatore==1){
            vittoria=1;
        }

        else if((tabella[riga][colonna]==tabella[riga-1][colonna+1])&&(tabella[riga][colonna]==tabella[riga+1][colonna-1])&&(tabella[riga][colonna]==tabella[riga+2][colonna-2])&&giocatore==2){
            vittoria=1;
        }
};
void gestione_giocatore(){
    if(giocatore==1)giocatore=2;
    else if(giocatore==2)giocatore=1;
    };
