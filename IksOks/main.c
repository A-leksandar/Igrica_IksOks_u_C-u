#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char glavniMeni();
char igra();
char taster();
bool Provera(char polje);
void naslov();
void nereseno();
void pobeda0(char polje7, char polje8, char polje9, char polje4, char polje5, char polje6, char polje1, char polje2, char polje3);
void pobeda1(char polje7, char polje8, char polje9, char polje4, char polje5, char polje6, char polje1, char polje2, char polje3);
void pobeda2(char polje7, char polje8, char polje9, char polje4, char polje5, char polje6, char polje1, char polje2, char polje3);
void pobeda3(char polje7, char polje8, char polje9, char polje4, char polje5, char polje6, char polje1, char polje2, char polje3);
void pobeda4(char polje7, char polje8, char polje9, char polje4, char polje5, char polje6, char polje1, char polje2, char polje3);
void pobeda5(char polje7, char polje8, char polje9, char polje4, char polje5, char polje6, char polje1, char polje2, char polje3);
void pobeda6(char polje7, char polje8, char polje9, char polje4, char polje5, char polje6, char polje1, char polje2, char polje3);
void pobeda7(char polje7, char polje8, char polje9, char polje4, char polje5, char polje6, char polje1, char polje2, char polje3);

int main()
{
    FILE *fp;

    char opcija = glavniMeni();
    int brojacIks=0;
    int brojacOks=0;

    switch(opcija)
    {
        case 'N':
        case 'n':
            brojacIks=0;
            brojacOks=0;
            fp = fopen("rezultati.txt","w");
                fprintf(fp,"%d %d", brojacIks, brojacOks);
            fclose(fp);
            break;

        case 'C':
        case 'c':
            fp=fopen("rezultati.txt","r");
                fscanf(fp,"%d %d", &brojacIks, &brojacOks);
            fclose(fp);
            break;

        case 27:
            exit(0);
    }

    char pobednik = igra(brojacIks, brojacOks);
    switch(pobednik)
    {
    case 'X':
        brojacIks += 1;
        fp = fopen("rezultati.txt","w");
        fprintf(fp,"%d %d", brojacIks, brojacOks);
        fclose(fp);
        break;
    case 'O':
        brojacOks += 1;
        fp = fopen("rezultati.txt","w");
        fprintf(fp,"%d %d", brojacIks, brojacOks);
        fclose(fp);
        break;
    default:
        break;
    }
    return 0;
}

void naslov()
{
    printf("\tx--o--x--o--x--o--x--o--x--o--x--o--x--o--x--o\n");
    printf("\t|   ___      ___\t    ___        ___   |\n");
    printf("\to    |  | / /   \t   /   \\  | / /      x\n");
    printf("\t|    |  |/  \\___\t  |     | |/  \\___   |\n");
    printf("\tx    |  |\\      \\\t  |     | |\\      \\  o\n");
    printf("\t|   -%c- | \\  ___/\t   \\___/  | \\  ___/  |\n", 0x000023C5);
    printf("\to--x--o--x--o--x--o--x--o--x--o--x--o--x--o--x\n");
}

char glavniMeni()
{

    system("cls");
    naslov();
    printf("\n\n<Odaberite jednu od opcija>\n");
    printf("\nNova Igra.....[N][n]");
    printf("\nNastavi.......[C][c]");
    printf("\nIzadji........[ESC]\n");
    char opcija;
    printf("\n");
    opcija =getch();
    switch(opcija)
    {
    case 'N':
    case 'n':
    case 'C':
    case 'c':
    case 27:
        return opcija;
        break;
    default:
        printf("\nUnos neodgovarajuc, pokusajte ponovo.\n");
        printf("Pritisnite bilo koji taster da nastavite.\n");
        opcija=getch();
        glavniMeni();
    }
    return opcija;
}

char igra(int pobedaIks, int pobedaOks)
{
    int runda=0;
    char polja[3][3]={{{'7'},{'8'},{'9'}},{{'4'},{'5'},{'6'}},{{'1'},{'2'},{'3'}}};
    char dugme;
    char pobednik;
    for(runda=0;runda<10;runda++)
    {

    bool t = false;
    char temp;

    if(runda>8)
    {
    system("cls");
    naslov();
    printf("\n\n\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\t\tx---o---x---o---x\n",polja[0][0],polja[0][1],polja[0][2]);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  O-------x-------x-------O\t\t  Pobede[X]: %d \n",pobedaIks);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\t\tx---o---x---o---x\n",polja[1][0],polja[1][1],polja[1][2]);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  O-------x-------x-------O\t\t  Pobede[O]: %d \n",pobedaOks);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\t\tx---o---x---o---x\n",polja[2][0],polja[2][1],polja[2][2]);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\n\n\n");
    nereseno();
    return NULL;
    }else{
    if(polja[0][0] == polja[0][1] && polja[0][0] == polja[0][2]){
        pobeda2(polja[0][0], polja[0][1], polja[0][2], polja[1][0], polja[1][1], polja[1][2],polja[2][0],polja[2][1],polja[2][2]);
        if(polja[0][0] == 'X'){pobednik = 'X';}else{pobednik = 'O';}
        return pobednik;
        break;
    }else if(polja[0][0] == polja[1][0] && polja[0][0] == polja[2][0]){
        pobeda0(polja[0][0], polja[0][1], polja[0][2], polja[1][0], polja[1][1], polja[1][2],polja[2][0],polja[2][1],polja[2][2]);
        if(polja[0][0] == 'X'){pobednik = 'X';}else{pobednik = 'O';}
        return pobednik;
        break;
    }else if(polja[0][0] == polja[1][1] && polja[0][0] == polja[2][2]){
        pobeda1(polja[0][0], polja[0][1], polja[0][2], polja[1][0], polja[1][1], polja[1][2],polja[2][0],polja[2][1],polja[2][2]);
        if(polja[0][0] == 'X'){pobednik = 'X';}else{pobednik = 'O';}
        return pobednik;
        break;
    }else if(polja[0][2] == polja[1][2] && polja[0][2] == polja[2][2]){
        pobeda3(polja[0][0], polja[0][1], polja[0][2], polja[1][0], polja[1][1], polja[1][2],polja[2][0],polja[2][1],polja[2][2]);
        if(polja[0][2] == 'X'){pobednik = 'X';}else{pobednik = 'O';}
        return pobednik;
        break;
    }else if(polja[0][2] == polja[1][1] && polja[0][2] == polja[2][0]){
        pobeda4(polja[0][0], polja[0][1], polja[0][2], polja[1][0], polja[1][1], polja[1][2],polja[2][0],polja[2][1],polja[2][2]);
        if(polja[0][2] == 'X'){pobednik = 'X';}else{pobednik = 'O';}
        return pobednik;
        break;
    }else if(polja[0][1] == polja[1][1] && polja[0][1] == polja[2][1]){
        pobeda5(polja[0][0], polja[0][1], polja[0][2], polja[1][0], polja[1][1], polja[1][2],polja[2][0],polja[2][1],polja[2][2]);
        if(polja[0][1] == 'X'){pobednik = 'X';}else{pobednik = 'O';}
        return pobednik;
        break;
    }else if(polja[1][0] == polja[1][1] && polja[1][0] == polja[1][2]){
        pobeda6(polja[0][0], polja[0][1], polja[0][2], polja[1][0], polja[1][1], polja[1][2],polja[2][0],polja[2][1],polja[2][2]);
        if(polja[1][0] == 'X'){pobednik = 'X';}else{pobednik = 'O';}
        return pobednik;
        break;
    }else if(polja[2][0] == polja[2][1] && polja[2][0] == polja[2][2]){
        pobeda7(polja[0][0], polja[0][1], polja[0][2], polja[1][0], polja[1][1], polja[1][2],polja[2][0],polja[2][1],polja[2][2]);
        if(polja[2][0] == 'X'){pobednik = 'X';}else{pobednik = 'O';}
        return pobednik;
        break;
    }
    system("cls");
    naslov();
    printf("       Pritisnite [ESC] kako bi zaustavili rad programa");
    printf("\n\n\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\t\tx---o---x---o---x\n",polja[0][0],polja[0][1],polja[0][2]);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  O-------x-------x-------O\t\t  Pobede[X]: %d \n",pobedaIks);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\t\tx---o---x---o---x\n",polja[1][0],polja[1][1],polja[1][2]);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  O-------x-------x-------O\t\t  Pobede [O]: %d \n",pobedaOks);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\t\tx---o---x---o---x\n",polja[2][0],polja[2][1],polja[2][2]);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\nPritisnite dugme sa nekim brojem [1-9]: ");

    while(t==false){
        dugme = taster();
        if(dugme == '1'){//--------------------------------------
            temp = polja[2][0];
            t = Provera(temp);
            if(t==false)
            {
            }else{
                if(runda % 2 == 0)
                {
                    polja[2][0] = 'X';
                    break;
                }else{
                    polja[2][0] = 'O';
                    break;
                }
            }
        }//------------------------------------------------------

        if(dugme == '2'){//--------------------------------------
            temp = polja[2][1];
            t = Provera(temp);
            if(t==true)
            {
                if(runda % 2 == 0)
                {
                    polja[2][1] = 'X';
                    break;
                }else{
                    polja[2][1] = 'O';
                    break;
                }
            }
        }//------------------------------------------------------

        if(dugme == '3'){//--------------------------------------
            temp = polja[2][2];
            t = Provera(temp);
            if(t==true)
            {
                if(runda % 2 ==0)
                {
                    polja[2][2] = 'X';
                    break;
                }else{
                    polja[2][2] = 'O';
                    break;
                }
            }
         }//------------------------------------------------------

        if(dugme == '4'){//---------------------------------------
            temp = polja[1][0];
            t = Provera(temp);
            if(t==true)
            {
                if(runda % 2 ==0)
                {
                    polja[1][0] = 'X';
                    break;
                }else{
                    polja[1][0] = 'O';
                    break;
                }
            }
        }//------------------------------------------------------

        if(dugme == '5'){//--------------------------------------
            temp = polja[1][1];
            t = Provera(temp);
            if(t==true)
            {
                if(runda % 2 ==0)
                {
                    polja[1][1] = 'X';
                    break;
                }else{
                    polja[1][1] = 'O';
                    break;
                }
            }
        }//------------------------------------------------------

        if(dugme == '6'){//--------------------------------------
            temp = polja[1][2];
            t = Provera(temp);
            if(t==true)
            {
                if(runda % 2 ==0)
                {
                    polja[1][2] = 'X';
                    break;
                }else{
                    polja[1][2] = 'O';
                    break;
                }
            }
        }//------------------------------------------------------

        if(dugme == '7'){//--------------------------------------
            temp = polja[0][0];
            t = Provera(temp);
            if(t==true)
            {
                if(runda % 2 ==0)
                {
                    polja[0][0] = 'X';
                    break;
                }else{
                    polja[0][0] = 'O';
                    break;
                }
            }
        }//------------------------------------------------------

        if(dugme == '8'){//--------------------------------------
            temp = polja[0][1];
            t = Provera(temp);
            if(t==true)
            {
                if(runda % 2 ==0)
                {
                    polja[0][1] = 'X';
                    break;
                }else{
                    polja[0][1] = 'O';
                    break;
                }
            }
        }//------------------------------------------------------

        if(dugme == '9'){//--------------------------------------
            temp = polja[0][2];
            t = Provera(temp);
            if(t==true)
            {
                if(runda % 2 ==0)
                {
                    polja[0][2] = 'X';
                    break;
                }else{
                    polja[0][2] = 'O';
                    break;
                }
            }
        }//------------------------------------------------------
        }
    }
    }
}

char taster(){
    char dugme = getch();
    switch(dugme)
    {
    case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        return dugme;
        break;
    case 27:
        exit(0);
    default:
        printf("\nUnos neodgovarajuc pokusajte ponovo: ");
        taster();
    }
}

bool Provera(char polje)
{
    if(polje != 'X' && polje != 'O')
    {
        return true;
    }else{
        return false;
    }
}

void nereseno()
{
    printf("x--o--x--o--x--o--x--o--x--o--x--o--x--o--x--o--x--o--x--o--x--o--x\n");
    printf("|              ____  ___    ____    \\/   ____           ___       |\n");
    printf("o     |\\    | |     |   \\  |       ____ |     |\\    |  /   \\      o\n");
    printf("|     | \\   | |____ |    | |____  /     |____ | \\   | |     |     |\n");
    printf("|     |  \\  | |     |___/  |      \\___  |     |  \\  | |     |     |\n");
    printf("o     |   \\ | |     |   \\  |          \\ |     |   \\ | |     |     o\n");
    printf("|     |    \\| |____ |    \\ |____  ____/ |____ |    \\|  \\___/      |\n");
    printf("x--o--x--o--x--o--x--o--x--o--x--o--x--o--x--o--x--o--x--o--x--o--x\n");
    printf("\nPritisnite  bilo koji taster kako bi ugasili program\n");
    char pauza = getch();
}

void pobeda0(char polje7, char polje8, char polje9, char polje4, char polje5, char polje6, char polje1, char polje2, char polje3)
{
    system("cls");
    naslov();
    printf("\n\n\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\t\t  |   |   |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje7,polje8,polje9);
    printf("\t\t  |   |   |       |       |\n");
    printf("\t\t  O-------x-------x-------O\n");
    printf("\t\t  |   |   |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje4,polje5,polje6);
    printf("\t\t  |   |   |       |       |\n");
    printf("\t\t  O-------x-------x-------O\n");
    printf("\t\t  |   |   |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje1,polje2,polje3);
    printf("\t\t  |   |   |       |       |\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\nPobednik je: [%c]!\n", polje7);
    printf("\nPritisnite  bilo koji taster kako bi ugasili program\n");
    char pauza = getch();
}

void pobeda1(char polje7, char polje8, char polje9, char polje4, char polje5, char polje6, char polje1, char polje2, char polje3)
{
    system("cls");
    naslov();
    printf("\n\n\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\t\t  | \\     |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje7,polje8,polje9);
    printf("\t\t  |     \\ |       |       |\n");
    printf("\t\t  O-------x-------x-------O\n");
    printf("\t\t  |       | \\     |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje4,polje5,polje6);
    printf("\t\t  |       |     \\ |       |\n");
    printf("\t\t  O-------x-------x-------O\n");
    printf("\t\t  |       |       | \\     |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje1,polje2,polje3);
    printf("\t\t  |       |       |     \\ |\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\n\tPobednik je: [%c]!\n",polje7);
    printf("\nPritisnite  bilo koji taster kako bi ugasili program\n");
    char pauza = getch();
}

void pobeda2(char polje7, char polje8, char polje9, char polje4, char polje5, char polje6, char polje1, char polje2, char polje3)
{
    system("cls");
    naslov();
    printf("\n\n\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  |---%c---|---%c---|---%c---|\n",polje7,polje8,polje9);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  O-------x-------x-------O\n");
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje4,polje5,polje6);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  O-------x-------x-------O\n");
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje1,polje2,polje3);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\n\tPobednik je: [%c]!\n", polje7);
    printf("\nPritisnite  bilo koji taster kako bi ugasili program\n");
    char pauza = getch();
}

void pobeda3(char polje7, char polje8, char polje9, char polje4, char polje5, char polje6, char polje1, char polje2, char polje3)
{
    system("cls");
    naslov();
    printf("\n\n\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\t\t  |       |       |   |   |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje7,polje8,polje9);
    printf("\t\t  |       |       |   |   |\n");
    printf("\t\t  O-------x-------x-------O\n");
    printf("\t\t  |       |       |   |   |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje4,polje5,polje6);
    printf("\t\t  |       |       |   |   |\n");
    printf("\t\t  O-------x-------x-------O\n");
    printf("\t\t  |       |       |   |   |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje1,polje2,polje3);
    printf("\t\t  |       |       |   |   |\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\n\tPobednik je: [%c]!\n", polje9);
    printf("\nPritisnite  bilo koji taster kako bi ugasili program\n");
    char pauza = getch();
}

void pobeda4(char polje7, char polje8, char polje9, char polje4, char polje5, char polje6, char polje1, char polje2, char polje3)
{
    system("cls");
    naslov();
    printf("\n\n\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\t\t  |       |       |     / |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje7,polje8,polje9);
    printf("\t\t  |       |       | /     |\n");
    printf("\t\t  O-------x-------x-------O\n");
    printf("\t\t  |       |     / |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje4,polje5,polje6);
    printf("\t\t  |       | /     |       |\n");
    printf("\t\t  O-------x-------x-------O\n");
    printf("\t\t  |     / |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje1,polje2,polje3);
    printf("\t\t  | /     |       |       |\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\n\tPobednik je: [%c]!\n", polje9);
    printf("\nPritisnite  bilo koji taster kako bi ugasili program\n");
    char pauza = getch();
}

void pobeda5(char polje7, char polje8, char polje9, char polje4, char polje5, char polje6, char polje1, char polje2, char polje3)
{
    system("cls");
    naslov();
    printf("\n\n\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\t\t  |       |   |   |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje7,polje8,polje9);
    printf("\t\t  |       |   |   |       |\n");
    printf("\t\t  O-------x-------x-------O\n");
    printf("\t\t  |       |   |   |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje4,polje5,polje6);
    printf("\t\t  |       |   |   |       |\n");
    printf("\t\t  O-------x-------x-------O\n");
    printf("\t\t  |       |   |   |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje1,polje2,polje3);
    printf("\t\t  |       |   |   |       |\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\n\tPobednik je: [%c]!\n", polje8);
    printf("\nPritisnite  bilo koji taster kako bi ugasili program\n");
    char pauza = getch();
}

void pobeda6(char polje7, char polje8, char polje9, char polje4, char polje5, char polje6, char polje1, char polje2, char polje3)
{
    system("cls");
    naslov();
    printf("\n\n\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje7,polje8,polje9);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  O-------x-------x-------O\n");
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  |---%c---|---%c---|---%c---|\n",polje4,polje5,polje6);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  O-------x-------x-------O\n");
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje1,polje2,polje3);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\n\tPobednik je: [%c]!\n", polje5);
    printf("\nPritisnite  bilo koji taster kako bi ugasili program\n");
    char pauza = getch();
}

void pobeda7(char polje7, char polje8, char polje9, char polje4, char polje5, char polje6, char polje1, char polje2, char polje3)
{
    system("cls");
    naslov();
    printf("\n\n\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje7,polje8,polje9);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  O-------x-------x-------O\n");
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  |   %c   |   %c   |   %c   |\n",polje4,polje5,polje6);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  O-------x-------x-------O\n");
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  |---%c---|---%c---|---%c---|\n",polje1,polje2,polje3);
    printf("\t\t  |       |       |       |\n");
    printf("\t\t  x-------O-------O-------x\n");
    printf("\n\tPobednik je: [%c]!\n", polje2);
    printf("\nPritisnite  bilo koji taster kako bi ugasili program\n");
    char pauza = getch();
}
