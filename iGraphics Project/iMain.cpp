/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
#include<iostream>
using namespace std;
#include "iGraphics.h"
//#include "myheader.h"
//#include "bitmap_loader.h"


#define totalBricks 50
#define screenWidth 1200
#define screenHight 650
#define yAxisMargin 50

int mposx,mposy;

//char backGroundImage[20] = "smurf.bmp";
char score[5];
int scr=0;
int x[50];
int y[50];
//int dxx[50];
//int dyy[50];
//bool show[50];
/*for(int i=0;i<totalBricks;i++)
{
	dxx[i]=100;
}
for(int i=0;i<totalBricks;i++)
{
	dyy[i]=20;
}
for(int i=0;i<totalBricks;i++)
{
	show[i]=true;
}*/
int dxx[50]={100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
int dyy[50] = {20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20};
bool show[50] = {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true};
int red[50];
int green[50];
int blue[50];
int live = 0;
int gameover = 0;

/*struct brickStructure
{
	int x;
	int y;
	static const int dx = 100;
	static const int dy = 20;
	static const bool show = true;

	//int dx = 100;
	//int dy = 20;
    //bool show = true;
	int red;
	int green;
	int blue;

    
};

brickStructure bricks[totalBricks];*/

//int red = 0;
//int green = 0;
//int blue = 0;

int xBall =(int) screenWidth/2;
int yBall = yAxisMargin;
int radiusBall = 10;
//int dx = 7;
//int dy = 5;
int v=10;
int lamda = 30;
int dx = (int)v*cos(lamda*3.1416/180);
int dy = (int)v*sin(lamda*3.1416/180);

int xBoard = xBall - 50;
int yBoard = yBall - 20;
int dxBoard = 100;
int dyBoard = 10;

bool isStarted = false;

void ballChange();
void restartBall();
void defineBricks();


void iDraw()
{

	iClear();
	iShowBMP(0,0,"p.bmp");
    iSetColor(255, 255, 10);
	iFilledCircle(xBall, yBall, radiusBall,1000);
	iSetColor(0, 255, 255);
    iFilledRectangle(xBoard,yBoard,dxBoard,dyBoard);

	for(int i =0;i <totalBricks;i++)
	{
		if(show[i])
		{
			iSetColor(red[i],green[i],blue[i]);
			//iSetColor(255,0,blue[i]);
			iFilledRectangle(x[i],y[i],dxx[i],dyy[i]);
			//printf("%d %d\n",x[i],y[i]);
		}
	}
	iSetColor(255, 255, 255);
	iText(1020, 120, "Name ------- Score ");
	iText(1020, 100,"Ziaul -------");
	iText(1140, 100,score);

	if(live!=3)
	{
		iShowBMP(10,10,"red.bmp");
	}

	if(live!=2&&live!=3)
	{
		iShowBMP(53,10,"red.bmp");
	}

	if(live!=1&&live!=2&&live!=3)
	{
		iShowBMP(97,10,"red.bmp");
	}
	if(gameover==1)
	{
		iClear();
		iShowBMP(0,0,"p.bmp");
		iSetColor(0, 255, 255);
		iText(600,325,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
		//iText(600,325,"GAME OVER");
	}

	
	
	//iSetColor(255, 255, 255);
	//iText(10, 10, "Press p for pause, r for resume, END for exit.");
}
void iKeyboard(unsigned char key)
{
	if(key == 'r')
	{
		
	}
	else if(key == ' ')
	{
		if(!isStarted)
		{
			isStarted = true;
		}
	
	}
	
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_LEFT)
	{
		if(xBoard > 0)
		{
			xBoard-= 30;
			if(!isStarted)
			{
				xBall-=30;
			}
		}
	}
	else if(key == GLUT_KEY_RIGHT)
	{
		if(xBoard < screenWidth - dxBoard)
		{
			xBoard+= 30;
			if(!isStarted)
			{
				xBall+=30;
			}
		}
	}
	
}


void iMouseMove(int mx, int my)
{
	//place your codes here
	
}

/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
	//place your codes here
	//printf("(x,y) : %d , %d\n", mx,my);
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/


void ballChange(){
	if(isStarted)
	{
	xBall += dx;
	yBall += dy;

	if(xBall >= screenWidth || xBall <=0)
	{
		dx*=(-1);
	}
	if(yBall >= screenHight || yBall <=0)
	{
		dy*=(-1);
	}

	//collision

	for(int  i = 0;i< totalBricks;i++)
	{
		if(show[i])
		{
			if(xBall >= x[i] && xBall <= x[i] + dxx[i])
			{
				if(yBall >= y[i]&& yBall <= y[i] + dyy[i])
				{
					dy *= (-1);
					if(show[i])
					{
					    show[i] = false;
						scr+=10;
		                sprintf(score, "%d", scr);
					}
				}
			}
			else if(yBall >= y[i] && yBall <= y[i]+ dyy[i])
			{
				if(xBall >= x[i] && xBall <= x[i] + dxx[i])
				{
					dx *=(-1);
					if(show[i])
					{
					    show[i] = false;
						scr+=10;
		                sprintf(score, "%d", scr);
					}
				}
			}
		}
	}
	if(xBall >= xBoard && xBall <= xBoard + dxBoard && yBall >= yBoard && yBall <= yBoard + dyBoard)
	{
		dy *=(-1);
		lamda = (xBoard+dxBoard-xBall)+40;
		dx = (int)v*cos(lamda*3.1416/180);
		dy = (int)v*sin(lamda*3.1416/180);
	}
	else
	{
		if(yBall < yBoard  && live!=3)
		{
			restartBall();
			live++;
		}
		if(live==3)
		{
			gameover = 1;
		}
	}
 }
}

void restartBall()
{
	xBall = (int)screenWidth /2;
	yBall = yAxisMargin;
	dx = 7;
	dy = 5;

	xBoard = xBall - 50;
	yBoard = yBall - 20;

	isStarted = false;
}

void defineBricks()
{
	int sumx = 100;
	int sumy = 450;
	for(int i = 0;i < totalBricks; i++)
	{
		red[i] = rand() % 255;
		green[i] = rand() % 255;
		blue[i] = rand() % 255;
		x[i] = sumx;
		y[i] = sumy;
		sumx += 100;
		if(sumx > 1000)
		{
			sumx = 100;
			sumy += 20;
		}
	}
}



int main()
{
	//place your own initialization codes here. 
	
	defineBricks();
	iSetTimer(13, ballChange);
	iInitialize(screenWidth, screenHight, "DX-Ball");
	iStart();


	return 0;
}

