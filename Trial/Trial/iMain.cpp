#include "iGraphics.h"
#include "stdio.h"
#include "bitmap_loader.h"
#include<iostream>
using namespace std;
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define screenHeight 800
#define screenWidth 450
#define balloonNumberEasy 10
#define balloonNumberHard 5
bool musicOn = true;
int bullseyeEasy = 0;
int bullseyeHard = 0;
int pointEasy = 0;
int pointHard = 0;
int healthPointEasy = 5;
int healthPointHard = 5;
int pointShowX = 250;
int pointShowY = 410;
int bullnumbershowX = 410;
int bullnumbershowY = 410;
char StrPoint[50];
char Strbull[50];
int gameStateover = 0;
int brustEasy = 0;
int brustHard = 0;
int collcountEasy = 1;
int collcountHard = 1;

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Character Stand ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
char pirate[7][18] = {"Pic\\attack\\i1.bmp","Pic\\attack\\i2.bmp","Pic\\attack\\i3.bmp","Pic\\attack\\i4.bmp","Pic\\attack\\i5.bmp","Pic\\attack\\i6.bmp","Pic\\attack\\i7.bmp",};
int pirateX = 0;
int pirateY = 0;
int pirateIndex = 0;
bool standPosition = true;
bool pactive = true;
int standCounter = 0;
//******************************************************************Character Walk***********************************************************
char piratewalk[7][20] = {"Pic\\walk\\w1.bmp","Pic\\walk\\w2.bmp","Pic\\walk\\w3.bmp","Pic\\walk\\w4.bmp","Pic\\walk\\w5.bmp","Pic\\walk\\w6.bmp","Pic\\walk\\w7.bmp",};
int walkX = 0;
int walkY = 0;
int walkIndex = 0;
bool pwactive = true;
//******************************************************************Character Shoot************************************************************

bool shootOn = true;
int shootCounter = 0;
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Showlife::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
void showLifeEasy()
{
	if(healthPointEasy == 5)
	{
		iShowBMP2(20,400,"Pic\\attack\\l1.bmp",0);
	}
	else if(healthPointEasy == 4)
	{
		iShowBMP2(20,400,"Pic\\attack\\l2.bmp",0);
	}
	else if(healthPointEasy == 3)
	{
		iShowBMP2(20,400,"Pic\\attack\\l3.bmp",0);
	}
	else if(healthPointEasy == 2)
	{
		iShowBMP2(20,400,"Pic\\attack\\l4.bmp",0);
	}
	else if(healthPointEasy == 1)
	{
		iShowBMP2(20,400,"Pic\\attack\\l5.bmp",0);
	}
	
}

void showLifeHard()
{
	if(healthPointHard == 5)
	{
		iShowBMP2(20,400,"Pic\\attack\\l1.bmp",0);
	}
	else if(healthPointHard == 4)
	{
		iShowBMP2(20,400,"Pic\\attack\\l2.bmp",0);
	}
	else if(healthPointHard == 3)
	{
		iShowBMP2(20,400,"Pic\\attack\\l3.bmp",0);
	}
	else if(healthPointHard == 2)
	{
		iShowBMP2(20,400,"Pic\\attack\\l4.bmp",0);
	}
	else if(healthPointHard == 1)
	{
		iShowBMP2(20,400,"Pic\\attack\\l5.bmp",0);
	}

}

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Balloon::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
char balloon1[30] = "Pic\\ball\\balloon.bmp";
char balloon6[30] = "Pic\\ball\\balloon6.bmp";

struct balloonEasy
{
	int bx,by;
	bool balloonshow;
}Eballoon[balloonNumberEasy];

void BalloonMoveEasy()
{
	for(int i=0;i<balloonNumberEasy;i++)
	{
		if(Eballoon[i].balloonshow)
		{
			iShowBMP2(Eballoon[i].bx,Eballoon[i].by,balloon1,0);
			
		}
	}
}

void BalloonChangeEasy()
{
	for(int i=0;i<balloonNumberEasy;i++)
	{
		Eballoon[i].by += 2;		//slow or fast
		if(Eballoon[i].by >= screenHeight)
		{
			Eballoon[i].by = 0;
			
		}
		
	}
}

void SetBalloonEasy()
{
	for(int i = 0; i < balloonNumberEasy; i++)
	{
		Eballoon[i].bx = 150 + rand() % screenWidth;
		Eballoon[i].by = rand() % screenHeight;
		Eballoon[i].balloonshow = true;
	}
}

struct balloonHard
{
	int bx,by;
	bool balloonshow;
}Hballoon[balloonNumberHard];

void BalloonMoveHard()
{
	for(int i = 0; i < balloonNumberHard; i++)
	{
		if(Hballoon[i].balloonshow)
		{
			iShowBMP2(Hballoon[i].bx,Hballoon[i].by,balloon6,0);
		}
	}
}

void BalloonChangeHard()
{
	for(int i = 0; i < balloonNumberHard; i++)
	{
		Hballoon[i].by += 6;		//slow or fast
		if(Hballoon[i].by >= screenHeight)
		{
			Hballoon[i].by = 0;
		}
		
	}
}

void SetBalloonHard()
{
	for(int i= 0; i < balloonNumberHard; i++)
	{
		Hballoon[i].bx= 150 + rand() % screenWidth;
		Hballoon[i].by= rand() % screenHeight;
		Hballoon[i].balloonshow = true;
	}
}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Bomb::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
char Bomb1[25] = "Pic\\bomb1.bmp";
char Bomb2[25] = "Pic\\bomb2.bmp";
char BombExplosion[8][25] = {"Pic\\Bomb\\b1.bmp","Pic\\Bomb\\b2.bmp","Pic\\Bomb\\b3.bmp","Pic\\Bomb\\b4.bmp","Pic\\Bomb\\b5.bmp","Pic\\Bomb\\b6.bmp","Pic\\Bomb\\b7.bmp","Pic\\Bomb\\b8.bmp",};
int bombExIndex = 0;
bool bombEx = true;
struct BombEasy
{
	int bx,by;
	bool bombshow;
}Ebomb[2];

void BombMoveEasy()
{
	for(int i = 0; i < 2; i++)
	{
		if(Ebomb[i].bombshow)
		{
			iShowBMP2(Ebomb[i].bx,Ebomb[i].by,Bomb1,0);	
		}
	}
}
void BombChangeEasy()
{
	for(int i=0;i<2;i++)
	{
		Ebomb[i].by -= 2;		//slow or fast
		if(Ebomb[i].by<=0)
		{
			Ebomb[i].by = screenHeight;
		}
		
	}
}
void SetBombEasy()
{
	for(int i = 0; i < 2; i++)
	{
		Ebomb[i].bx = 40 + rand() % screenWidth;
		Ebomb[i].by = rand() % screenHeight;
		Ebomb[i].bombshow = true;
	}
}

void BombBrustEasy()
{	

	for(int i = 0; i < 2; i++)
	{
	 if(pwactive == true && Ebomb[i].bombshow == true)
		{
		
			if (Ebomb[i].by+5 > walkY && Ebomb[i].by+70 < walkY+160)
				{
					if (Ebomb[i].bx+5 > walkX+15 && Ebomb[i].bx+62 < walkX+145)
						{
							Ebomb[i].bombshow = false;
							bombEx = true;
							
							brustEasy++;
							collcountEasy++;
							if(Ebomb[i].bombshow == false && healthPointEasy <= 5)
							{
								    
									iShowBMP2(walkX,walkY,BombExplosion[bombExIndex],0);
									if(collcountEasy == 2 )
									{
										healthPointEasy--;
										collcountEasy = 0;
									}
							}
						}
				}
			

		}
	}
	
	
	
}
void BombExpo()
{
	bombExIndex++;
	if(bombExIndex >= 7)
	{
		bombExIndex = 0;
		bombEx = false;
	}
}

void BombReactiveEasy()
{
	if(brustEasy == 2)
	{
		brustEasy = 0;
	    for(int i = 0; i < 2; i++)
		{
          Ebomb[i].bombshow = true;
		} 
	}
}



struct BombHard
{
	int bx,by;
	bool bombshow;
}Hbomb[2];

void BombMoveHard()
{
	for(int i = 0; i < 2; i++)
	{
		if(Hbomb[i].bombshow)
		{
			iShowBMP2(Hbomb[i].bx,Hbomb[i].by,Bomb2,0);	
		}
	}
}

void BombChangeHard()
{
	for(int i = 0; i < 2; i++)
	{
		Hbomb[i].by -= 5;		//slow or fast
		if(Hbomb[i].by<=0)
		{
			Hbomb[i].by=screenHeight;
		}
		
	}
}

void SetBombHard()
{
	for(int i=0;i<2;i++)
	{
		Hbomb[i].bx = 50+rand()%screenWidth;
		Hbomb[i].by = rand()%screenHeight;
		Hbomb[i].bombshow = true;
		
	}
}


void BombBrustHard()
{	

	for(int i = 0; i < 2; i++)
	{
	 if(pwactive == true && Hbomb[i].bombshow == true)
		{
		
			if (Hbomb[i].by+5 > walkY && Hbomb[i].by+70 < walkY+160)
				{
					if (Hbomb[i].bx+5 > walkX+15 && Hbomb[i].bx+62 < walkX+145)
						{
							Hbomb[i].bombshow = false;
							bombEx = true;
							
							brustHard++;
							collcountHard++;
							if(Hbomb[i].bombshow == false && healthPointHard <= 5)
							{
								    iShowBMP2(walkX,walkY,BombExplosion[bombExIndex],0);
									if(collcountHard == 2)
									{
										healthPointHard--;
										collcountHard = 0;
									}
							}
						}
				}
			

		}
	}
	
	
		
}

void BombReactiveHard()
{
	if(brustHard==2)
	{
		brustHard=0;
	    
		for(int i=0;i<2;i++)
		{
          Hbomb[i].bombshow = true;
		 
		} 
	}
}


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::homemenu:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
struct buttonCordinate
{
	int x,y;
	
}bCordinate[5];

int gameState =- 1;
char button[5][18] = {"Pic\\play.bmp","Pic\\high.bmp","Pic\\ins.bmp","Pic\\credit.bmp","Pic\\exitb.bmp"};
char homemenu[15] = "Pic\\home2.bmp";
char play[15] = "Pic\\bg.bmp";
char ins[15] = "Pic\\inst.bmp";
char score[15] = "Pic\\score.bmp";
char credit[15] = "Pic\\cd.bmp";
char back[15] = "Pic\\exit.bmp";
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::exit Button cordinate:::::::::::::::::::::::::::::::::::::::::::::::::::::
int exitx = 720;
int exity = 380;
int bulletCount = 0;
int bulletremain = 30;
char Score[10];

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Option::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
struct optionCordinate
{
	int opx,opy;

}opCordinate[2];
 
int optionState =- 1;
char optionbutton[2][15] = {"Pic\\easy.bmp","Pic\\hard.bmp"};
char optionmenu[15] = "Pic\\obg.bmp";

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::HighScore Option :::::::::::::::::::::::::::::::::::::::::::::::::::::::

struct hsopCordinate
{
	int hsopx,hsopy;

}hsopCor[2];
 
int hsoptionState =- 1;
char hsoptionbutton[2][15] = {"Pic\\heasy.bmp","Pic\\hhard.bmp"};
char hsoptionmenu[15] = "Pic\\hih.bmp";
int hsopflag=0;


//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Bullet Easy::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
char bullets[25] = "Pic\\attack\\bullet.bmp";
struct BulletEasy
{
	int bull_x,bull_y;
	bool hasActive;
	bool deactive;
}bulleteasy[30];

void BulletShotEasy()
{
	for(int i = 0 ; i< bulletCount ; i++)
	{
		if(bulleteasy[i].hasActive)
		{
			
			bulleteasy[i].bull_x += 30;
		}
	}
}
	
void bulletShowEasy()
{
	for(int i = 0; i < bulletCount; i++)
	{
		if(bulleteasy[i].hasActive == true)
		{
			iShowBMP2(bulleteasy[i].bull_x, bulleteasy[i].bull_y, bullets, 0);
		}

		if(bulletCount == 31)
		{
			
			gameStateover = -1;
			
		}
	}
}

void gameover()
{
	bulleteasy[bulletCount-1].hasActive = false;
	iClear();
	iShowBMP(0,0,"Pic\\over.bmp");
	itoa(pointEasy,Score,10);
	iText(300,400,"Your Score:",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(450,400,Score,GLUT_BITMAP_TIMES_ROMAN_24);
}

void CountBulletEasy()
{
	if(bulletCount < 31)
		{
			bulletCount++;
			bulletremain--;
		}
}

void SetBulletEasy()
{
	CountBulletEasy();
	
	bulleteasy[bulletCount-1].hasActive = true;
	bulleteasy[bulletCount-1].bull_x = walkX+106;
	bulleteasy[bulletCount-1].bull_y = walkY+50;
}


void BalloonPopEasy()
{
	for (int i = 0; i < bulletCount ; i++)
		{
			for (int j = 0 ; j < balloonNumberEasy ; j++)
				{
					if(bulleteasy[i].hasActive && Eballoon[j].balloonshow)
						{
							if ((bulleteasy[i].bull_x+40 > Eballoon[j].bx && bulleteasy[i].bull_x+40 < Eballoon[j].bx+100) && (bulleteasy[i].bull_y+20 > Eballoon[j].by+80 && bulleteasy[i].bull_y+20 < Eballoon[j].by+160))
								{
									
											
												Eballoon[j].balloonshow = false;
												bulleteasy[i].deactive = true;
										
												bullseyeEasy++;
												if(Eballoon[j].balloonshow == false)
												{
													pointEasy += 5;
												}
											
								}
						}
				}
		}
	
}
void Pointshow()//showing number of points scored for easy mode
{
	itoa(pointEasy,StrPoint,10);//converting int to string 
	iShowBMP2(pointShowX-35, pointShowY-25, "Pic\\sco.bmp", 0);
	iSetColor(255,255,255);
	iText(pointShowX,pointShowY,"Score: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0,255,255);
	iText(pointShowX+60,pointShowY,StrPoint,GLUT_BITMAP_TIMES_ROMAN_24);
}

void bullnumbershow()//showing remaining bullet for easy
{
	itoa(bulletremain,Strbull,10);//converting int to string 
	iShowBMP2(bullnumbershowX-35,bullnumbershowY-25,"Pic\\sco2.bmp",0);
	iSetColor(255,255,255);
	iText(bullnumbershowX-5,bullnumbershowY,"Bullet: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,255,0);
	iText(bullnumbershowX+60,bullnumbershowY,Strbull,GLUT_BITMAP_TIMES_ROMAN_24);
}


void BalloonReactiveEasy()
{
	if(bullseyeEasy == balloonNumberEasy)
	{
		bullseyeEasy = 0;
	    
		for(int i=0;i<balloonNumberEasy;i++)
		{
          Eballoon[i].balloonshow = true;
		} 
	}
}


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Bullet Hard::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
int bulletCountHard = 0;
int bulletCountHardre = 50;
struct BulletHard
{
	int hbull_x,hbull_y;
	bool hasActive;
	bool deactive;
}bullethard[50];

void BulletShotHard()
{
	for(int i=0 ; i< bulletCountHard ; i++)
	{
		if(bullethard[i].hasActive)
		{
			
			bullethard[i].hbull_x += 30;
		}
	}
}
	
void bulletShowHard()
{
	for(int i = 0; i < bulletCountHard; i++)
	{
		if(bullethard[i].hasActive == true)
		{
			iShowBMP2(bullethard[i].hbull_x,bullethard[i].hbull_y,bullets,0);
		}

		if(bulletCountHard == 51)
		{
			gameStateover = -2;
		}
	}
}

void gameover1()
{
	bullethard[bulletCountHard-1].hasActive=false;
	iClear();
	iShowBMP(0,0,"Pic\\over.bmp");
	itoa(pointHard,Score,10);										//converting final score from integer to string
    iText(300,400,"Your Score:",GLUT_BITMAP_TIMES_ROMAN_24);
    iText(450,400,Score,GLUT_BITMAP_TIMES_ROMAN_24);
			
}

void CountBulletHard()
{
	if(bulletCountHard < 51)
	{
		bulletCountHard++;
		bulletCountHardre--;
	}
}

void SetBulletHard()
{
	CountBulletHard();
	
	bullethard[bulletCountHard-1].hasActive = true;
	bullethard[bulletCountHard-1].hbull_x = walkX+106;
	bullethard[bulletCountHard-1].hbull_y = walkY+50;
}

void BalloonPopHard()
{
	for (int i = 0; i < bulletCountHard ; i++)
		{
			for (int j = 0 ; j < balloonNumberHard ; j++)
				{
					if(bullethard[i].hasActive && Hballoon[j].balloonshow)
						{
							if ((bullethard[i].hbull_x+40 > Hballoon[j].bx && bullethard[i].hbull_x+40< Hballoon[j].bx+100)&&(bullethard[i].hbull_y+20 >Hballoon[j].by+80 && bullethard[i].hbull_y+20 < Hballoon[j].by+160))
								{
									Hballoon[j].balloonshow = false;
									bullethard[i].deactive=true;
									bullseyeHard++;
									if(Hballoon[j].balloonshow==false)
									{
										pointHard+=5;
									}
											
								}
						}
				}
		}
	
}
void Pointshow1()//showing total points scored for hard mode
{
	itoa(pointHard,StrPoint,10);
	iShowBMP2(pointShowX-35,pointShowY-25,"Pic\\sco.bmp",0);
	iSetColor(255,255,255);
	iText(pointShowX,pointShowY,"Score: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0,255,255);
	iText(pointShowX+60,pointShowY,StrPoint,GLUT_BITMAP_TIMES_ROMAN_24);
}

void bullnumbershow1()//showing remaining bullets for hard mode
{
	itoa(bulletCountHardre,Strbull,10);
	iShowBMP2(bullnumbershowX-35,bullnumbershowY-25,"Pic\\sco2.bmp",0);
	iSetColor(255,255,255);
	iText(bullnumbershowX-5,bullnumbershowY,"Bullet: ",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255,0,255);
	iText(bullnumbershowX+60,bullnumbershowY,Strbull,GLUT_BITMAP_TIMES_ROMAN_24);
}


void BalloonReactiveHard()
{
	if(bullseyeHard == balloonNumberHard)
	{
		bullseyeHard=0;
	    for(int i = 0; i < balloonNumberHard; i++)
		{
          Hballoon[i].balloonshow = true;
		} 
	}
}

int numberArray[100];
int arrayIndex = 0;
int numberIndex = 0;
void appendHighScore(int n)
	{
		FILE *fp = fopen("HighScore.txt", "a");
	

		if (fp != NULL)
		{
			fprintf(fp, "%d\n", n);
		}
		
		fclose(fp);
	

	}

void readHighScore()
{
	FILE *fp = fopen("HighScore.txt", "r");
	char str[100];	

	if (fp != NULL)
	{
		while (fgets(str, 15, fp) != NULL)
		{
			numberArray[arrayIndex++] = atoi(str);
		}
	}
	

	fclose(fp);
}

void SortingHighScore()//Sorting the highScores and Call from highScoreShow
{
	int temp;
	for (int i = 0; i < arrayIndex - 1; i++)
	{
		for (int j = 0; j < arrayIndex - 1; j++)
		{
			if (numberArray[j] < numberArray[j + 1])
			{
				temp = numberArray[j];
				numberArray[j] = numberArray[j + 1];
				numberArray[j + 1] = temp;
			}
		}
	}
}


char str[100];
void highScoreShow()
{
	SortingHighScore();
	iClear();
	iShowBMP(0,0,"Pic\\scobg.bmp");
	iShowBMP2(300,200,"Pic\\sboard.bmp",0);

	for(int i =0;i<1;i++)
	{
		itoa(numberArray[i], str, 10);
		iSetColor(0, 0, 0);
		iText(375, 258,"Score :",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0, 0, 255);
		iText(450, 258, str,GLUT_BITMAP_TIMES_ROMAN_24);
	}
}



int numberArrayHard[100];
int arrayIndexhard = 0;
int numberIndexhard = 0;
void appendHighScore1(int n)
{
	FILE *fp = fopen("HighScoreHard.txt", "a");

	if (fp != NULL)
	{
		fprintf(fp, "%d\n", n);
	}

	fclose(fp);
	
}

void readHighScore1()
{
	FILE *fp = fopen("HighScoreHard.txt", "r");
	char str1[100];
	

	if (fp != NULL)
	{
		while (fgets(str1, 15, fp) != NULL)
		{
			numberArrayHard[arrayIndexhard++] = atoi(str1);
		}
	}
	

	fclose(fp);

}

void SortingHighScore1()//Sorting the highScores and Call from highScoreShow1
{
	int temp1;
	

	for (int i = 0; i < arrayIndexhard - 1; i++)
	{
		for (int j = 0; j < arrayIndexhard - 1; j++)
		{
			if (numberArrayHard[j] < numberArrayHard[j + 1])
			{
				temp1 = numberArrayHard[j];
				numberArrayHard[j] = numberArrayHard[j + 1];
				numberArrayHard[j + 1] = temp1;
			}
		}
	}
		
}


char str1[100];
void highScoreShow1()
{
	SortingHighScore1();
	iClear();
	iShowBMP(0,0,"Pic\\scobg.bmp");
	iShowBMP2(300,200,"Pic\\sboard.bmp",0);
	for(int i = 0; i<1; i++)
	{
		itoa(numberArrayHard[i], str1, 10);
		iSetColor(0, 0, 0);
		iText(375, 258,"Score :",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0, 0, 255);
		iText(450, 258, str1,GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

void reset()      //reset all for new game
{
	pirateX = 0;
	pirateY = 0;
	walkX = 0;
	walkY = 0;
	gameState = -1;
	optionState = -1;
	hsoptionState=-1;
	gameStateover = 0;
	pointEasy = 0;
	pointHard = 0;
	bulletCountHard = 0;
	bulletCount = 0;
    bulletremain = 31;
	bulletCountHardre = 51;
	collcountEasy = 1;
	collcountHard = 1;
	healthPointEasy = 5;
	healthPointHard = 5;
	SetBalloonEasy();
	SetBalloonHard();
	SetBombEasy();
	SetBombHard();
	SetBulletEasy();
	SetBulletHard();

}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Music Button::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
int musX = 640;
int musY = 10;

void musicButton()
{
	if(musicOn==true)
	{
		iShowBMP2(musX,musY,"Pic\\muson.bmp",0);
	}

	else
	{
		iShowBMP2(musX,musY,"Pic\\musoff.bmp",0);
	}
}
//*************************************************************************** iDraw Fuction  ************************************************************
void iDraw()
{
		iClear();
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::GAME STATE::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
		if (gameState == -1)  
		{
			iShowBMP(0,0,homemenu);
			iShowBMP2(565,10,"Pic\\muslogo.bmp",0);                                            //Music Logo
			musicButton();
			iShowBMP2(120,320,"Pic\\pop2.bmp",255);                                            //Surname of Game
			for(int i=0;i<5;i++)
			{
				iShowBMP2(bCordinate[i].x,bCordinate[i].y,button[i],0);                        //Showing Menu Buttons 
			}

	
		}
	
		 else if(gameState == 0)
		{
				       if(optionState == -1)
					   {
							iShowBMP(0,0,optionmenu);
							iShowBMP2(10,5,"Pic\\bacins.bmp",255);
							iShowBMP2(exitx,exity,"Pic\\exit.bmp",0);
			
							for(int i = 0; i < 2; i++)
							{
								iShowBMP2(opCordinate[i].opx,opCordinate[i].opy,optionbutton[i],0);                        /// Show Easy & Hard Buttons 
							}
			
						}
						else if(optionState == 0)
						{
							    iShowBMP(0,0,play);											                      //play page
							    iShowBMP2(20,400,"Pic\\attack\\l1.bmp",0); 
												/////////////walk Statement ////////
								if(!standPosition)
								{
									iShowBMP2(walkX,walkY,piratewalk[walkIndex],0);                                 ///Character walking 
									standCounter++;
									if(standCounter>=20)                                                            
									{
										standCounter=0;
										walkIndex=0;
										standPosition=true;
									}
								}
								else
								{
										iShowBMP2(walkX,walkY,pirate[pirateIndex],0);                               /// Character  Standing
								}
								iShowBMP2(exitx,exity,"Pic\\exit.bmp",0);
								showLifeEasy();
					            BalloonMoveEasy();     
		                        BombMoveEasy();
			                    bulletShowEasy();
								bullnumbershow();
								Pointshow();
								BalloonPopEasy();
								BombBrustEasy();
								BombReactiveEasy();
								BalloonReactiveEasy();
								if(gameStateover == -1)
								{
			                        gameover();														//calling game over for Easy due to insufficient bullet
								}
								else if(healthPointEasy == 0)
								{
									gameover();														//calling game over for Easy due to low Health points
								}
			
										
				
			            }	
		
					
		

						else if(optionState == 1)
						{
							iShowBMP(0,0,play);	
							if(!standPosition)
							{
								iShowBMP2(walkX,walkY,piratewalk[walkIndex],0);                                 ///Character walking hard
								standCounter++;
								if(standCounter >= 20)                                                            
								{
									standCounter = 0;
									walkIndex = 0;
									standPosition = true;
								}
							}
							else
							{
								iShowBMP2(walkX,walkY,pirate[pirateIndex],0);
							}
							                               /// Character  Standing for hard                               
								iShowBMP2(exitx,exity,"Pic\\exit.bmp",0);
								//play page for hard
						    BalloonMoveHard();
						    BombMoveHard();
							showLifeHard();
							bulletShowHard();
							bullnumbershow1();
							Pointshow1();
							BalloonPopHard();
							BombBrustHard();
							BombReactiveHard();
						    BalloonReactiveHard();
							if(gameStateover == -2)
							{
								gameover1();						//calling gameover for Hard due to insufficient bullet
							}
							else if (healthPointHard <= 0)
							{
								gameover1();						//calling gameover for Hard due to low health points
							}
						}

		}


      else if(gameState == 1)
	{
		

						if(hsoptionState == -1)
						{
							iShowBMP(0,0,"Pic\\hih.bmp");
							iShowBMP2(400,360,"Pic\\HighScore.bmp",0);
							iShowBMP2(exitx,exity,"Pic\\exit.bmp",0);
			
							for(int i = 0; i < 2; i++)
							{
								iShowBMP2(hsopCor[i].hsopx,hsopCor[i].hsopy,hsoptionbutton[i],0);                        /// Showing Buttons at High Score page 
							}
						 }

						else if(hsoptionState == 0)												//Showing High Score for Easy Mode
						{
							iShowBMP(0,0,score);
							highScoreShow();
							iShowBMP2(exitx,exity,"Pic\\exit.bmp",0);
						}

						else if(hsoptionState == 1)												//Showing High Score for Hard Mode
						{
							iShowBMP(0,0,score);
							highScoreShow1();
							iShowBMP2(exitx,exity,"Pic\\exit.bmp",0);
						}




	} 
	 else if(gameState == 2)
	{
		iShowBMP(0,0,"Pic\\inst2.bmp");											//Instruction page
		iShowBMP2(exitx,exity,"Pic\\exit.bmp",0);
		iShowBMP2(180,0,"Pic\\mus.bmp",255);									//instruction for mute/unmute
	} 
	 else if(gameState == 3)
	{
		iShowBMP(0,0,credit);													//Credits page
		iShowBMP2(exitx,exity,"Pic\\exit.bmp",0);                        
	}
	 else if(gameState == 4)													//for Exit button
	{
		exit(0);
	}
	
	
	
}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (gameState == -1)                                                                                                //***Debug ** (button will excute only in the home page)
		{
			for(int i = 0; i < 5; i++)
			{
				if(mx >= bCordinate[i].x && mx <= bCordinate[i].x+142 && my >= bCordinate[i].y && my <= bCordinate[i].y+53)			//home button cordinate for click
				{
					gameState = i;
				}

				if(i==1)
				{
					readHighScore();								//Storing Score in file for Easy Mode
					readHighScore1();								//Storing Score in file for Hard Mode
				}
			}
		}
		
		if(gameState == 0)
		{
			for(int j = 0; j <= 1; j ++)
			{
				if(optionState == j)
				{
					if(mx >= exitx && mx <= exitx+100 && my >= exity && my <= exity+72)													//exit button cordinate for click
					{
						
						optionState = -1;
						
					}	
					
				}
			}
		}
			

		if(gameState == 2 || gameState == 3 )						//Going back to home menu from Instructions and Credits page
		{
			if(mx>=exitx && mx<=exitx+100 && my >= exity && my <= exity+72)													//exit button cordinate for click
			{
				gameState =- 1;
			}	
		}
		


	if (optionState ==- 1  && gameState == 0)                                                                                                //***Debug ** (button will excute only in the home page)
	{
		for(int i = 0; i<2; i++)
		{
			if(mx>=opCordinate[i].opx && mx<=opCordinate[i].opx+269 && my>=opCordinate[i].opy && my<=opCordinate[i].opy+120)			//home button cordinate for click
			{
				
				optionState = i;
			}
				
		}
	}
		
		
	 if(gameState == 1 && hsoptionState == -1)								//Going to Page of High Score of different levels according to Mouse Click
	 {
		 for(int k = 0; k < 2; k++)
		 {
			if(mx >= hsopCor[k].hsopx && mx <= hsopCor[k].hsopx+200 && my >= hsopCor[k].hsopy && my <= hsopCor[k].hsopy+57)
			{
				hsoptionState = k;
				
			}
		 }
	 }

	
	if(hsoptionState==0 || hsoptionState == 1)							//Going back to Home page of High Score
	{
		if(mx >= exitx && mx <= exitx+100 && my >= exity && my <= exity+72)												
		{
			hsoptionState = -1;
		}
	}
				
	if(hsoptionState == -1 && gameState == 1)
	{
		if(mx >= exitx && mx <= exitx+100 && my >= exity && my <= exity+72)
		{
			hsopflag++;
		}
	}

	
	if(hsoptionState == -1 && gameState == 1 && hsopflag == 2)				//Checking both high Scores at a time
	{
		if(mx >= exitx && mx <= exitx+100 && my >= exity && my <= exity+72)												
		{
			gameState = -1;
			hsopflag = 0;
		}
	}
		

	if(gameState==-1)
	{
		if(mx >= musX && mx <= musX+150 && my >= musY && my <= musY+75)
		{
			if(musicOn)
			{
				musicOn = false;
				PlaySound(0,0,0);															//Music off
			
			}
			else
			{
				musicOn = true;
				PlaySound("Music\\1.wav",NULL,SND_LOOP |SND_ASYNC);
			
			}
		}
	}


		
	}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
			
		if(optionState == -1 && gameState == 0)
			{
				if(mx >= exitx && mx <= exitx+100 && my >= exity && my <= exity+72)												
				{
					gameState =  -1;
				}
			}
	}

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 'm' || key == 'M')
	{
		if(musicOn)
		{
			musicOn = false;
			PlaySound(0,0,0);															//Music off
			
		}
		else
		{
			musicOn = true;
			PlaySound("Music\\1.wav",NULL,SND_LOOP |SND_ASYNC);
			
		}
	}
	

	if (key == 's' || key == 'S')				//Shooting bullets
	{
		if(optionState == 0)					//for Easy
		{
			SetBulletEasy();
		}

		if(optionState == 1)					//for Hard
		{
			SetBulletHard();
		}
	}

	if (key == 'r' || key == 'R')
	{
		appendHighScore(pointEasy);					//Appending Scores to file for Easy mode
		appendHighScore1(pointHard);				//Appending Scores to file For hard mode
		reset();									//Refreshing the game from Scratch except high scores
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

	
	if (key == GLUT_KEY_RIGHT)
	{
		if(walkX<screenWidth+200)                                                                        //Right side walk limit

		{
			walkX += 10;
			walkIndex++;
			if(walkIndex >= 6)
			{
				walkIndex = 0;
				standPosition = false;
			}
		}
	}
	if (key == GLUT_KEY_LEFT)
	{
		if(walkX > 0)																						//Left side walk limit
		{
			walkX -= 10;
			walkIndex--;
			if(walkIndex < 0)
			{
				walkIndex = 6;
				standPosition = false;
			}
		}
	}
	if (key == GLUT_KEY_UP)
	{
		if(walkY < screenHeight-480)                                                                        //Right side walk limit

		{
			walkY += 10;
			walkIndex++;
			if(walkIndex >= 6)
			{
				walkIndex = 0;
				standPosition = false;
			}
		}
	}

	if (key == GLUT_KEY_DOWN)
	{
		if(walkY>0)																						//Left side walk limit
		{
			walkY -= 10;
			walkIndex--;
			if(walkIndex<0)
			{
				walkIndex = 6;
				standPosition = false;
			}
		}
	}
	
	if (key == GLUT_KEY_HOME)
	{
	
	}
	
}
	void Stand() //main Character for Standing
	{
		pirateIndex++;

		if(pirateIndex >= 7)
		{
			pirateIndex = 0;
		}
	}
	

	

int main()
{
	srand((unsigned)time(NULL));
	iSetTimer(25,BalloonChangeEasy);
	iSetTimer(20,BalloonChangeHard);
	iSetTimer(50,BombChangeEasy);
	iSetTimer(30,BombChangeHard);
	iSetTimer(20,BulletShotEasy);
	iSetTimer(18,BulletShotHard);
	iSetTimer(200,BombExpo);
	SetBalloonEasy();
	SetBalloonHard();
	SetBombEasy();
	SetBombHard();
	
	iSetTimer(100,Stand);
	

	if(musicOn)
	{
	  PlaySound("Music\\1.wav",NULL,SND_LOOP |SND_ASYNC);  // music
	}

	int sum=100;
	for(int i = 4; i >= 0; i--)									//Spacing for home page buttons
	{
		bCordinate[i].x = 40;
		bCordinate[i].y = sum;
		sum += 50;
	}

	int opsum = 70;
	for(int i = 1; i >= 0; i--)									//Spacing for game option buttons
	{
		opCordinate[i].opx = 270;
		opCordinate[i].opy = opsum;
		opsum += 160;
	}
	 

	int hsopsum = 160;

	for(int i = 1; i >= 0; i--)									//Spacing for high Score option button
	{
		hsopCor[i].hsopx = 450;
		hsopCor[i].hsopy = hsopsum;
		hsopsum += 70;
	}
	

	iInitialize(screenHeight,screenWidth, "Surprise Pop");
	iStart();
	return 0;
}