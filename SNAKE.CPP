#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#define true 1;
#define false 0;
typedef int bool;
bool gameover=true;
const int width=20;
const int heigth=20;
int x,y,score,fruitx,fruity,i,j;
enum edirection{stop=0,left,right,up,down};
edirection dir;
int ntail,tailx[100],taily[100],k;

void setup()
{
	gameover=false;
	dir=stop;
	x=width/2;
	y=heigth/2;
	fruitx=rand()%width;
	fruity=rand()%heigth;
	score=0;
}

void input()
{
	if(kbhit())
	{
		switch(getch())
		{
		case 'a':
		dir=left;
		break;
		case 's':
		dir=right;
		break;
		case 'w':
		dir=up;
		break;
		case 'z':
		dir=down;
		break;
		case 'q':
		gameover=true;
		break;

		}
	}
}
void logic()
{
int prevx=tailx[0];
int prevy=taily[0];
tailx[0]=x;
taily[0]=y;
int prev2x,prev2y;
for(i=1;i<ntail;i++)
{
int prev2x=tailx[i];
int prev2y=taily[i];
tailx[i]=prevx;
taily[i]=prevy;
prevx=prev2x;
prevy=prev2y;
}
 switch(dir)
 {
 case left:
 x--;
 break;
 case right:
 x++;
 break;
 case up:
 y--;
 break;
 case down:
 y++;
 break;
 default:
 break;
 }
 /*
 if(x>width || x<0 || y>heigth  || y<0)
 {

 gameover=true;

 } */
 if(x>width)
 x=0;
 else if(x<0)
 x=width-1;
 if(y>heigth)
 y=0;
 else if(y<0)
 y=heigth-1;

 for(i=0;i<ntail;i++)
 {
 if(tailx[i]==x && taily[i]==y)
 gameover=true;
 }
 if(x==fruitx && y==fruity)
 {
 score+=10;
 ntail++;
fruitx=rand()%width;
fruity=rand()%heigth;
 }
}
void draw()
{
	clrscr();
	for(i=0;i<width+1;i++)
	cout<<"*";
	cout<<endl;
	for(i=0;i<heigth;i++)
	{
		for(j=0;j<width;j++)
		{
			if(j==0||j==width-1)
				cout<<"*";
			if(i==y&&j==x)
				cout<<"O";
			else if(i==fruity&&j==fruitx)
			cout<<"f";
			 else
			 {
				bool print=false;
				for(int k=0;k<ntail;k++)
				{
				 if(tailx[k]==j && taily[k]==i)
				 {
				 cout<<"o";
				 print=true;
				 }
				}
			 if(!print)
			cout<<" ";

			}
		}
	  cout<<endl;
	}
	for(i=0;i<width+1;i++)
	cout<<"*";
	cout<<endl;
	cout<<"SCORE:"<<score;

}
void main()
{
	setup();
	while(!gameover)
	{
		draw();
		input();
		logic();
		sleep(1);
	}

}