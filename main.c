#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define altura 16
#define largura 32

typedef struct cobrinha
{
    int posX, posY;
} cobrinha;

int x=0, y=0, rand_x, rand_y, cont=0, coleta=0, availablePos[largura*altura], contAvailable=largura*altura, contAtual;
char mover, aux;
//char buffer[47];
cobrinha cobra[10]= {0};
int main()
{
    //setvbuf(stdout, buffer, _IOFBF, sizeof(buffer));
    for(int i=0; i<contAvailable; i++)
    {
        availablePos[i]=i;
    }
    srand(time(NULL));
    contAtual=rand()%contAvailable;
    rand_x=availablePos[contAtual]%largura;
    rand_y=(availablePos[contAtual]-availablePos[contAtual]%largura)/largura;
    cobra[0].posX=largura/2;
    cobra[0].posY=altura/2;

    //primeiro frame
    printf("Aperte qualquer tecla para iniciar\n");
    printf("%c",201);
    for(int i=0; i<largura+1; i++)
    {
        printf("%c",205);
    }
    printf("%c\n",187);
    for(int i=0; i<altura; i++)
    {
        printf("%c",186);
        printf(" ");
        for(int j=0; j<largura; j++)
        {
            if(i==altura/2 && j==largura/2)
            {
                printf("$");
            }
            else if(i==rand_y && j==rand_x)
            {
                printf("@");
            }
            else
            {
                printf(" ");
            }
        }
        printf("%c\n",186);
    }
    printf("%c",200);
    for(int i=0; i<largura+1; i++)
    {
        printf("%c",205);
    }
    printf("%c\n",188);

    aux='d';
    mover=getch();
    if(mover!='w'&&mover!='s'&&mover!='a'&&mover!='d')
    {
        mover=aux;
    }
    if(mover=='w')
    {
        x=0;
        y=-1;
    }
    if(mover=='s')
    {
        x=0;
        y=1;
    }
    if(mover=='d')
    {
        x=1;
        y=0;
    }
    if(mover=='a')
    {
        x=-1;
        y=0;
    }

    system("cls");
    while(1)
    {


        //detecção
        if(kbhit())
        {
            aux=mover;
            mover=getch();
            if((mover=='w'&&aux=='s')||(mover=='s'&&aux=='w')||(mover=='a'&&aux=='d')||(mover=='d'&&aux=='a')||(mover!='w'&&mover!='s'&&mover!='a'&&mover!='d'))
            {
                mover=aux;
            }
            if(mover=='w')
            {
                x=0;
                y=-1;
            }
            if(mover=='s')
            {
                x=0;
                y=1;
            }
            if(mover=='d')
            {
                x=1;
                y=0;
            }
            if(mover=='a')
            {
                x=-1;
                y=0;
            }

        }

        //movimento
        for(int k=cont; k>0; k--)
        {
            cobra[k].posX=cobra[k-1].posX;
            cobra[k].posY=cobra[k-1].posY;
        }

        cobra[0].posX+=x;
        cobra[0].posY+=y;

        //colisão
        for(int k=0; k<=cont; k++)
        {
            if(cobra[k].posX==largura)
            {
                cobra[k].posX=0;
            }
            if(cobra[k].posX==-1)
            {
                cobra[k].posX=largura-1;
            }
            if(cobra[k].posY==altura)
            {
                cobra[k].posY=0;
            }
            if(cobra[k].posY==-1)
            {
                cobra[k].posY=altura-1;
            }
        }

        //derrota
        for(int k=1; k<=cont; k++)
        {
            if(cobra[k].posX==cobra[0].posX && cobra[k].posY==cobra[0].posY && !coleta)
            {
                system("cls");
                for(int i=0; i<(altura)/2; i++)
                {
                    printf("\n");
                }
                for(int i=0; i<(largura-7)/2; i++)
                {
                    printf(" ");
                }
                printf("Perdeu!");
                for(int i=0; i<(altura)/2; i++)
                {
                    printf("\n");
                }
                getch();
                return 0;
            }
        }

        //coleta
        if(cobra[0].posX==rand_x && cobra[0].posY==rand_y)
        {
            cont++;
            cobra[cont].posX=rand_x;
            cobra[cont].posY=rand_y;
            for(int k=0; k<=cont; k++)
            {
                contAtual=largura*cobra[k].posY+cobra[k].posX;
                for(int i=0; i<contAvailable; i++)
                {
                    if(availablePos[i]==contAtual)
                    {
                        for(int j=i; j<contAvailable-1; j++)
                        {
                            availablePos[j]=availablePos[j+1];
                        }
                        contAvailable--;
                        goto B;
                    }
                }
B:
                ;
            }
            contAtual=rand()%contAvailable;
            rand_x=availablePos[contAtual]%largura;
            rand_y=(availablePos[contAtual]-availablePos[contAtual]%largura)/largura;
            contAvailable=largura*altura;
            for(int i=0; i<contAvailable; i++)
            {
                availablePos[i]=i;
            }
        }

        //caixa
        for(int i=0; i<(largura-10)/2; i++)
        {
            printf(" ");
        }
        printf("pontua%c%co : %d\n",135,198,cont);
        printf("%c",201);
        for(int i=0; i<largura+1; i++)
        {
            printf("%c",205);
        }
        printf("%c\n",187);
        for(int j=0; j<altura; j++)
        {
            printf("%c",186);
            printf(" ");
            for(int i=0; i<largura; i++)
            {
                for(int k=0; k<=cont; k++)
                {
                    if(cobra[k].posX==i && cobra[k].posY==j)
                    {
                        printf("$");
                        goto A;
                    }
                }
                if(i==rand_x && j==rand_y)
                {
                    printf("@");
                }
                else
                {
                    printf(" ");
                }
A:
                ;
            }
            printf("%c\n",186);
        }
        printf("%c",200);
        for(int i=0; i<largura+1; i++)
        {
            printf("%c",205);
        }
        printf("%c\n",188);
        if(mover=='w'||mover=='s')
        {
            Sleep(200);
        }
        else
        {
            Sleep(100);
        }
        system("cls");
    }
}
