#include <stdio.h>

#include <string.h>

#include <math.h>

#include <stdlib.h>

#include <time.h>

#include <Windows.h>

#include "iGraphics.h"

int cont_box;

int  get_score;

int temp3;

int box_x=-130;

int box_y=550;

int credit_x=800;

int credit_y=500;

int title_x=350;

int title_y=813;

int gift_x;

int gift_y;

int isgift=0;

int additional_length=0;

int duration;

int gift_type;

int timer;

int ara[1000][1000];

int p1=0;

int p2=790;

int isballstarted=0;

int px,py;

int ball_x=100;

int ball_y=20;

int dx=5;

int dy=5;

int rad=10;

int stick_x=60;

int stick_y=0;

int stick_len=60;

int stick_wi=10;

int score;

int i,j,xx,yy;

int colour;

char update[800];

char finale[800];

char newline[800];

int cover=0;

int clr1=50,clr2=50,clr3=50;

int clr[2000][3];

int rate_x=1;

int rate_y=1;

int option;

char str[100];

char str2[100];

char temp_arr[100];

int len;

int mode;

int fi,se;

int c1,c2;

int p,q;

int temp1,temp2;

int  ba1,ba2,ba3,ba4,flag;

int cod[100][3];

int xi,yi;

int level=1;

int gift[100];

int h_brick[100];

int g;

int hb;

int isfireball=0;

int high_scorei;

char high_score[100];


int x = 300, y = 300, r =15;

/* 
	function iDraw() is called again and again by the system.
	
*/
void drawTextBox();
void updateScore();
void iDraw()
{

    iClear();

    if(cover==0)
    {
        iShowBMP(0,0,"black.bmp");

        iSetColor(0,255,0);

        iRectangle(box_x,box_y,130,100);

        if(title_y<=600) if(box_x<340) box_x+=10;

        iSetColor(255,255,255);

        iText(title_x,title_y,"DX  BALL",GLUT_BITMAP_TIMES_ROMAN_24);

        if(title_y>600) title_y-=10;

        iSetColor(255,223,0);

        iText(credit_x,credit_y,"-by SACHIN & SAMEE",GLUT_BITMAP_HELVETICA_18);

        if(box_x>=340) if(credit_x>320) credit_x-=10;

        iSetColor(0,255,255);

        iText(300,300,"PLAY",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(300,260,"RULES",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(300,220,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(300,180,"HIGH SCORE",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(0,0,255);

        iFilledCircle(285,310,5);
        iFilledCircle(285,270,5);
        iFilledCircle(285,230,5);
        iFilledCircle(285,190,5);

        if(option==1){
            iSetColor(255,255,255);
            iFilledRectangle(290,290,80,40);
            iSetColor(0,0,0);
            iText(300,300,"PLAY",GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if(option==2){
            iSetColor(255,255,255);
            iFilledRectangle(290,250,90,40);
            iSetColor(0,0,0);
            iText(300,260,"RULES",GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if(option==3){
            iSetColor(255,255,255);
            iFilledRectangle(290,210,80,40);
            iSetColor(0,0,0);
            iText(300,220,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
        }

        if(option==4){
            iSetColor(255,255,255);
            iFilledRectangle(290,170,160,40);
            iSetColor(0,0,0);
            iText(300,180,"HIGH SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
        }

    }



    if(cover==1){

        iShowBMP(0,0,"mosaic.bmp");

        sprintf(update,"Score : %d",score);

        iSetColor(0,255,255);

        iText(740,810,update,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(740,780,str2,GLUT_BITMAP_TIMES_ROMAN_24);

        if(isfireball==1) iSetColor(178,34,34);
        else iSetColor(0,255,0);
        iFilledCircle(ball_x,ball_y,rad);

        iSetColor(0,255,255);
        iFilledRectangle(stick_x,stick_y,stick_len,stick_wi);

        if(isgift==1)
        {
            iSetColor(230,122,169);
            iFilledCircle(gift_x,gift_y,5);
        }
        for(fi=1;fi<=100;fi++)
        {
            if(cod[fi][2]>=1)
            {
                if(gift[fi]==1)
                      iSetColor(0,0,255);
                else if(h_brick[fi]==1)
                {
                    if(cod[fi][2]==3) iSetColor(150,150,150); ///ash
                    else if(cod[fi][2]==2) iSetColor(203,65,84); ///brick red
                    else  iSetColor(212,175,55); ///golden

                }
                else{
                    if(level==2) iSetColor(128,0,128);
                    else if(level==3) iSetColor(0,255,0);
                    else iSetColor(255,0,0);
                }

                iFilledRectangle(cod[fi][0],cod[fi][1],50,40);
                iSetColor(0,0,0);
                iRectangle(cod[fi][0],cod[fi][1],50,40);
            }
        }
    }


    if(cover==2){

        iShowBMP(0,0,"file.bmp");

        iSetColor(0,255,0);

        iRectangle(340,630,130,70);

        iSetColor(255,255,255);

        iText(350,650,"DX  BALL",GLUT_BITMAP_TIMES_ROMAN_24);


        iSetColor(255,255,255);

        iText(245,590,"GAME  IS  OVER !  WELL   PLAYED ! !",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(0,255,0);

        sprintf(finale,"Player: %s",str2);

        sprintf(newline,"YOUR FINAL SCORE IS  : %d",score);

        iText(250,300,finale,GLUT_BITMAP_TIMES_ROMAN_24);

        iText(250,250,newline,GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(0,0,255);

        iText(250,200,"PRESS  '/'  TO CONTINUE",GLUT_BITMAP_TIMES_ROMAN_24);

    }



    if(cover==3){

        iShowBMP(0,0,"rules.bmp");

        iSetColor(0,0,255);

        iRectangle(290,640,100,50);

        iSetColor(0,0,0);

        iText(300,650," RULES " ,GLUT_BITMAP_TIMES_ROMAN_24);

        iText(250,600,"Press spacebar key to shoot the ball.",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(250,560,"Press  '-->'  and  '<--'  keys to move the bar.",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(250,530,"Press  'p'  to pause the game.",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(250,500,"Press  'r'  to resume the game.",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(250,470,"Hit the blue bricks to get gifts",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(250,440,"Hardened black bricks must be hit twice",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(250,390,"Press  '*'  to go back.",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(178,190,181);

        iFilledCircle(235,610,5);
        iFilledCircle(235,570,5);
        iFilledCircle(235,540,5);
        iFilledCircle(235,510,5);
        iFilledCircle(235,480,5);
        iFilledCircle(235,450,5);
    }

    if(cover==4)
    {
        drawTextBox();

        if(mode == 1)
        {
            iSetColor(255, 255, 255);
            iText(255, 410 , str);
        }

        iText(10, 100, "Click to activate the box, enter to finish.");
    }


    if(cover==5)
    {
            iSetColor(255,255,255);

            iFilledRectangle(0,0,800,850);

            iSetColor(255,0,0);

            iText(370,800,"HIGH SCORE",GLUT_BITMAP_TIMES_ROMAN_24);

            iShowBMP(320,800,"cup.bmp");
            iShowBMP(275,800,"cup.bmp");
            iShowBMP(230,800,"cup.bmp");

            iShowBMP(520,800,"cup.bmp");
            iShowBMP(565,800,"cup.bmp");
            iShowBMP(610,800,"cup.bmp");

            sprintf(high_score," %d ",high_scorei);

            ///char dataToBeRead[50];

            /*while( fgets ( dataToBeRead, 50, fp ) != NULL )
            {
                    sscanf("%s",dataToBeRead);
             }*/

            ///sprintf(dataToBeRead,"%d %s",&high_scorei,temp_arr);



            ///iSetColor(0,0,128);
            ///iFilledRectangle(355,495,100,34);

            iSetColor(0,255,255);
            iFilledRectangle(305,495,30,34);
            iSetColor(0,0,0);
            iText(315,498,"1",GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(0,0,0);
            iFilledRectangle(335,495,120,34);
            iSetColor(255,255,255);
            iText(350,500,temp_arr,GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(0,255,255);
            iFilledRectangle(455,495,80,34);
            iSetColor(0,0,0);
            iText(470,500,high_score,GLUT_BITMAP_TIMES_ROMAN_24);


            iText(325,400,"Press '*' to go back",GLUT_BITMAP_TIMES_ROMAN_24);
    }

}

void drawTextBox()
{
	iSetColor(150, 150, 150);

	iText(170,410,"NAME:",GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(0,255,255);

	iRectangle(250, 400, 250, 30);

	if(cont_box==1)
        {
            iSetColor(255,255,255);

            iFilledRectangle(320,280,130,30);

            iSetColor(0,255,0);

            iText(330,285,"CONTINUE",GLUT_BITMAP_HELVETICA_18);
        }

    if(cont_box==0)
    {
        iSetColor(150,150,150);

        iText(330,285,"CONTINUE",GLUT_BITMAP_HELVETICA_18);

        iSetColor(0,0,255);

        iRectangle(320,280,130,30);
    }
}



/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
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
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{

if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)

    {

        if(mx >= 250 && mx <= 500 && my >= 400 && my <= 430 && mode == 0)
		{
			mode = 1;
		}

		/*else if(cover == 4 && mx >= 320 && mx <= 450 && my >= 280 && my <= 310)
        {
            cover = 1/*,music=1*//*;
        }*/

    }

if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)

    {



    }

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{

    int i;
	if(mode == 1)
	{
        if(key == 'a')
		{
			mode = 0;
			strcpy(str2,str);
			for(i = 0; i <len; i++)
				str[i] = 0;
			len = 0;
		}
		else
		{
			str[len] = key;
			len++;
		}
	}

    if(key == '/')
    {
        cover=0;///here we start the game again
    }

    if(key == 'p')
    {
        iPauseTimer(0);

    }

    if(key=='*')
    {
        cover=0;
    }

    if(key == 'r')
    {
        iResumeTimer(0);
    }

    if(key==' ') isballstarted=1;

    if(key == 'a')
    {
        if(option == 1) score=0,cover=4,option=0;

        else if(option == 2) cover=3;

        else if(option == 3) exit(0),option=0;

        else if(option == 4)
        {
                updateScore();
                cover=5;
        }

        else if(cont_box==1)
        {
                cover=1;
        }
    }
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

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }

    if(key == GLUT_KEY_LEFT)
    {
        if(stick_x>0)
       {

            stick_x-=15;

            if(isballstarted==0) ball_x-=15;
       }

    }

    if(key == GLUT_KEY_RIGHT)
    {
        if(stick_x+stick_len<=785)
        {
            stick_x+=15;
            if(isballstarted==0) ball_x+=15/*,music=0*/;
        }

    }

    if(key == GLUT_KEY_DOWN)
    {
        if(cover==0 && option != 4) option++;

        if(cover==4) cont_box=1;
    }

    if(key ==GLUT_KEY_UP)
    {
        if(option != 1) option--;
    }

}

void updateScore()
{
        FILE *fp;

        fp=fopen("F:\DX Ball\Score.txt","r");

        if(fp==NULL){
            printf("No file..");
           return ;
        }

        fscanf(fp,"%d %[^\n]",&high_scorei,temp_arr);

            if(score>high_scorei)
            {
               high_scorei=score;
               strcpy(temp_arr,str2);

               //iSetColor(0,0,0);
               //iText(250,600,str2,GLUT_BITMAP_TIMES_ROMAN_24);
               //iText(350,600,update,GLUT_BITMAP_TIMES_ROMAN_24);
            }
            fclose(fp);

            FILE *fptr;
            fptr=fopen("F:\DX Ball\Score.txt","w");

            fprintf(fptr,"%d %s",high_scorei,temp_arr);

            ///sprintf(high_score," %d ",high_scorei);
            ///iSetColor(0,0,0);
            ///iText(250,600,temp_arr,GLUT_BITMAP_TIMES_ROMAN_24);
            ///iText(350,600,high_score,GLUT_BITMAP_TIMES_ROMAN_24);

            fclose(fptr);

            FILE *f;
            f=fopen("F:\DX Ball\Score.txt","r");

            fscanf(f,"%d %s",&high_scorei,temp_arr);

            fclose(f);
}


void initialize()
{
    int pi,qi,cox,coy,cp1,cp2;
    if(level==1)
    {
        for(xi=1;xi<100;xi++)
        {
            cod[xi][0]=0;
            cod[xi][1]=0;
            cod[xi][2]=0;
            gift[xi]=0;
            h_brick[xi]=0;
        }

       cox=400,coy=800;
       cod[1][0]=cox;
       cod[1][1]=coy;
       cod[1][2]=1;
       xi=2;

      for(pi=1;pi<=6;pi++)
      {
        cox-=25;
        coy-=40;
        cp1=cox;
        cp2=coy;

        for(qi=0;qi<=pi;qi++)
        {
          cod[xi][0]=cp1;
          cod[xi][1]=cp2;
          cod[xi][2]=1;
          cp1+=50;
          xi++;
        }
      }

  for(pi=5;pi>=1;pi--)
  {
    cox+=25;
    coy-=40;
    cp1=cox;
    cp2=coy;
    for(qi=0;qi<=pi;qi++)
    {
       cod[xi][0]=cp1;
       cod[xi][1]=cp2;
       cod[xi][2]=1;
       cp1+=50;
       xi++;
    }
  }
    cox+=25;
    coy-=40;
    cod[49][0]=cox;
    cod[49][1]=coy;
    cod[49][2]=1;
    }


    if(level==2)
    {
         for(xi=1;xi<100;xi++)
         {
           cod[xi][0]=0;
           cod[xi][1]=0;
           cod[xi][2]=0;
           gift[xi]=0;
           h_brick[xi]=0;
         }
         cox=100;
         coy=800;
         xi=1;
         for(pi=1;pi<=6;pi++)
         {
            cp1=cox;
            cp2=coy;
            for(qi=1;qi<=pi;qi++)
            {
                    cod[xi][0]=cp1;
                    cod[xi][1]=cp2;
                    if((cp1==450&&cp2==640)||(cp1==600&&cp2==760)||(cp1==550&&cp2==640)||(cp1==100&&cp2==680)||(cp1==250&&cp2==640))
                    {
                         cod[xi][2]=2;
                         h_brick[xi]=1;
                    }
                    else
                    {
                        cod[xi][2]=1;
                        if((cp1==150&&cp2==720)||(cp1==400&&cp2==600)||(cp1==650&&cp2==720))
                        {
                            gift[xi]=1;
                        }
                    }
                    cp1+=50;
                    xi++;
            }
            coy-=40;
        }
        cox=650;
        coy=800;
        for(pi=1;pi<=6;pi++)
        {
            cp1=cox;
            cp2=coy;
            for(qi=1;qi<=pi;qi++)
            {
                    cod[xi][0]=cp1;
                    cod[xi][1]=cp2;
                    if((cp1==450&&cp2==640)||(cp1==600&&cp2==760)||(cp1==550&&cp2==640)||(cp1==100&&cp2==680)||(cp1==250&&cp2==640))
                        {
                            cod[xi][2]=2;
                            h_brick[xi]=1;
                        }
                    else
                    {
                        cod[xi][2]=1;
                        if((cp1==150&&cp2==720)||(cp1==400&&cp2==600)||(cp1==650&&cp2==720))
                        {
                            gift[xi]=1;
                        }
                    }
                    cp1-=50;
                    xi++;
            }
            coy-=40;
        }
    }

    if(level==3)
    {
            for(xi=1;xi<100;xi++)
            {
                cod[xi][0]=0;
                cod[xi][1]=0;
                cod[xi][2]=0;
                gift[xi]=0;
                h_brick[xi]=0;
            }

            cox=200;
            coy=800;
            xi=1;

            for(pi=1;pi<=10;pi++)
            {
                    cp1=cox,cp2=coy;
                    for(qi=1;qi<=8;qi++)
                    {
                            cod[xi][0]=cp1,cod[xi][1]=cp2;
                            if( ((cp1==200||cp1==550) && (cp2>=440 || cp2<=800))  || ((cp2==800||cp2==440) && (cp1>=250||cp1<=550)) )
                            {
                                    cod[xi][2]=3;
                                    h_brick[xi]=1;
                            }
                            else if( ((cp1==250||cp1==500) && (cp2>=480 || cp2<=760))  || ((cp2==760||cp2==480) && (cp1>=300||cp1<=500)) )
                            {
                                    cod[xi][2]=2;
                                    h_brick[xi]=1;
                            }
                            else cod[xi][2]=1;
                            xi++;
                            cp1+=50;
                    }
                    coy-=40;
            }
    }

}


void ballchange(){

    if(isballstarted==1)
    {
        ball_x+=dx;

        ball_y+=dy;

        if(isgift==1)
            gift_y-=3;
         if(duration>0 && isfireball==1)
         {
             duration--;
         }
         else
            isfireball=0;
        for(i=1;i<=100;i++)
        {
            if(cod[i][0]<=ball_x+rad*rate_x&&cod[i][0]+50>=ball_x+rad*rate_x&&cod[i][1]<=ball_y+rad*rate_y&&cod[i][1]+40>=ball_y+rad*rate_y&&cod[i][2]>=1)
            {

                 ///PlaySound("F:\\DX Ball\\Grenade-SoundBible.com-1777900486-[AudioTrimmer.com].wav", NULL, SND_ASYNC);

                if(gift[i]==1&&isgift==0)
                {
                    gift_x=cod[i][0];
                    gift_y=cod[i][1];
                    isgift=1;
                }
                cod[i][2]--;

                ///if(cod[i][2]==1)  score+=2;

                score++;

                if(score==171)
                {
                        cover=2;
                }

                if(score==49)
                {
                        level=2;
                        dx=5;
                        dy=-5;
                        rate_x=1;
                        rate_y=-1;
                        stick_x=60;
                        stick_y=0;
                        stick_len=60;
                        stick_wi=10;
                        rad=10;
                        ball_x=stick_x+stick_len/2;
                        ball_y=stick_wi+rad;
                        isfireball=2;
                        isballstarted=0;
                        initialize();
                }

                if(score==91)
                {
                        level=3;
                        dx=5;
                        dy=-5;
                        rate_x=1;
                        rate_y=-1;
                        stick_x=60;
                        stick_y=0;
                        stick_len=60;
                        stick_wi=10;
                        rad=10;
                        ball_x=stick_x+stick_len/2;
                        ball_y=stick_wi+rad;
                        isfireball=2;
                        isballstarted=0;
                        initialize();
                }

                if(isfireball==0)
                {
                    if(ball_y+rad*rate_y==cod[i][1]+40||ball_y+rad*rate_y==cod[i][1])
                {
                    dy=-dy;
                    rate_y=-rate_y;
                }
                else
                {
                    dx=-dx;
                    rate_x=-rate_x;
                }
                }
                break;
            }
        }
        if(gift_x+5<=stick_x+stick_len&&gift_x-5>=stick_x&&gift_y-5==stick_wi&&isgift>=1)
        {
            isgift=0;
            srand(time(NULL));
            gift_type=rand()%3;
            if(gift_type==0)
               {
                   stick_len+=40;

               }
            else if(gift_type==1)
            {
                isballstarted=0;
                ball_x=stick_x+stick_len/2;
                ball_y=stick_wi+rad;
            }
             else if(gift_type==2)
             {
                 isfireball=1;
                 duration=500;
             }
        }
        if(isgift>=1&&gift_y<=0)
            isgift=0;
        if(ball_x>790 || ball_x<10) dx=-dx,rate_x=-rate_x,PlaySound("F:\\DX Ball\\Bounce.wav", NULL, SND_ASYNC|SND_NOSTOP);

        if(ball_y>840) dy=-dy,rate_y=-rate_y,PlaySound("F:\\DX Ball\\Bounce.wav", NULL, SND_ASYNC | SND_NOSTOP);

        if(ball_x+rad>=stick_x&&ball_x-rad<=stick_x+stick_len&&ball_y-rad==stick_y+stick_wi)
        {

            dy=-dy,rate_y=-rate_y;

            PlaySound("F:\\DX Ball\\Bounce.wav", NULL, SND_ASYNC|SND_NOSTOP);

            if(ball_x-rad==stick_x+stick_len||ball_x+rad==stick_x) dx=-dx,rate_x=-rate_x;

        }
        else
        {

            if(ball_y-rad<stick_y){
                    updateScore();
                    cont_box=0;
                    cover=2;
                    level=1;
                    option=0;
                    mode=0;
                    isballstarted=0;
                    dx=5;
                    dy=5;
                    rate_x=rate_y=1;
                    stick_x=60;
                    stick_y=0;
                    stick_len=60;
                    stick_wi=10;
                    isfireball=0;
                    ball_x=stick_x+stick_len/2;
                    ball_y=stick_wi+rad;
                    initialize();
            }

        }

    }
}



int main()
{
    //PlaySound("F:\\DX Ball\\Action_Sport.wav", NULL, SND_LOOP | SND_ASYNC|SND_NOSTOP);
    score=0;
    iSetTimer(10,ballchange);
    initialize();
    iInitialize(800,850,"DX_BALL");
	iStart();
    return 0;
}

