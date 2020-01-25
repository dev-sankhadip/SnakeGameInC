#include <stdio.h> 
#include<stdlib.h>
#include <conio.h> 
#include <dos.h>
#include <time.h>

int w=20,h=20;
int x,y,fruitX,fruitY,score,gameover,flag;
int tailX[100],tailY[100];
int countTail=0;
void setup()
{
    gameover=0;
    x=w/2;
    y=h/2;
    
    lable1:
    fruitX=rand()%20;
    if(fruitX==0)
    goto lable1;
    
    lable2:
    fruitY=rand()%20;
    if(fruitY==0)
    goto lable2;
    
    score=0;
}
void draw()
{
	system("cls");
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<h;j++)
        {
            if(i==0||i==h-1||j==0||j==w-1)
            {
            printf("*");
            }
            else
            {
                if(i==x && j==y)
                printf("O");
                else if(i==fruitX && j==fruitY)
                printf("F");
                else
                {
                	int ch=0;
                	for(int k=0;k<countTail;k++)
                	{
                		if(i==tailX[k] && j==tailY[k])
                		{
                			printf("o");
                			ch=1;
						}
					}
					if(ch==0)
					{
						printf(" ");
					}
				}
            }
        }
        printf("\n");
    }
    printf("SCORE=%d",score);
}
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case 'a':
            flag=1;
            break;
            case 'd':
            flag=2;
            break;
            case 'w':
            flag=3;
            break;
            case 's':
            flag=4;
            break;
            case 'x':
            gameover=1;
            break;
        }
    }
}
void MakeLogic()
{
	int prevX=tailX[0];
	int prevY=tailY[0];
	int prev2X,prev2Y;
	tailX[0]=x;
	tailY[0]=y;
	
	for(int i=1;i<countTail;i++)
	{
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
	
    switch(flag)
    {
        case 1:
        y--;
        break;
        case 2:
        y++;
        break;
        case 3:
        x--;
        break;
        case 4:
        x++;
        break;
        default:
        break;
    }
    
    if(x>=w) x=0;else if(x<0) x=w-1;
    if(y>=h) y=0;else if(y<0) y=h-1;
    
    if(x<0||x>w||y<0||y>h)
    {
    gameover=1;
    }
    for(int i=0;i<countTail;i++)
    {
    	if(x==tailX[i] && y==tailY[i])
    	{
    		gameover=1;
		}
	}
    if(x==fruitX && y==fruitY)
    {
    lable3:
    fruitX=rand()%20;
    if(fruitX==0)
    goto lable3;
    
    lable4:
    fruitY=rand()%20;
    if(fruitY==0)
    goto lable4;
    
    score+=10;
    countTail++;
	}
}
void delay(int s)
{
	
}
int main() 
{
	char c;
	lable5:
		
    setup();
    while(!gameover)
    {
    draw();
    input();
    MakeLogic();
    delay(10000);
    delay(10000);
    }
  // printf("\nPress Y to continue again:");
    scanf("%c",&c);
    if(c=='y' || c=='Y')
    goto lable5;
    return 0; 
} 

