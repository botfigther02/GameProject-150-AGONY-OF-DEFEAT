/*
    Original Author: S. M. Shahriar Nirjon
    Last Modified by: Mohammad Saifur Rahman
    last modified: October 13, 2015
    Version: 2.0
*/
// Crated by Amit Hassan Joy
// Created by Abu Hurayra Niloy

#include<iostream>
using namespace std;
# include "iGraphics.h"

#define screenwidth 1480
#define screenHight 1080
#define Jumplimit 350

//Defining game states 
int gamestate = -1;
//Jump varriables 
bool jumpUP = false ;
bool jumpDown = false ;
bool jump = false ;
int jumpCordinateY = 0 ;
//Background Slizes
char mainBackground[60][30] = { "Background\\tile000.bmp", "Background\\tile001.bmp", "Background\\tile002.bmp", "Background\\tile003.bmp", "Background\\tile004.bmp", "Background\\tile005.bmp", "Background\\tile006.bmp", "Background\\tile007.bmp", "Background\\tile008.bmp", "Background\\tile009.bmp", "Background\\tile010.bmp", "Background\\tile011.bmp", "Background\\tile012.bmp",
"Background\\tile013.bmp", "Background\\tile014.bmp", "Background\\tile015.bmp", "Background\\tile016.bmp", "Background\\tile017.bmp", "Background\\tile018.bmp", "Background\\tile019.bmp", "Background\\tile020.bmp", "Background\\tile021.bmp", "Background\\tile022.bmp", "Background\\tile023.bmp", "Background\\tile024.bmp", "Background\\tile025.bmp", "Background\\tile026.bmp", "Background\\tile027.bmp", "Background\\tile028.bmp", "Background\\tile029.bmp", "Background\\tile030.bmp" ,
"Background\\tile031.bmp", "Background\\tile032.bmp", "Background\\tile033.bmp", "Background\\tile034.bmp", "Background\\tile035.bmp", "Background\\tile036.bmp", "Background\\tile037.bmp", "Background\\tile038.bmp", "Background\\tile039.bmp", "Background\\tile040.bmp", "Background\\tile041.bmp", "Background\\tile042.bmp", "Background\\tile043.bmp", "Background\\tile044.bmp", "Background\\tile045.bmp", "Background\\tile046.bmp", "Background\\tile047.bmp", "Background\\tile048.bmp",
"Background\\tile049.bmp", "Background\\tile050.bmp", "Background\\tile051.bmp", "Background\\tile052.bmp", "Background\\tile053.bmp", "Background\\tile054.bmp", "Background\\tile055.bmp", "Background\\tile056.bmp", "Background\\tile057.bmp", "Background\\tile058.bmp", "Background\\tile059.bmp" };

//Run Slizes
char characterRun[8][20] = { "Run\\run_001.bmp", "Run\\run_002.bmp", "Run\\run_003.bmp", "Run\\run_004.bmp", "Run\\run_005.bmp", "Run\\run_006.bmp", "Run\\run_007.bmp", "Run\\run_008.bmp"};
//Jump Slizes
char JUMP[2][30] = { "Jump//jump_01.bmp", "Jump//jump_02.bmp" };

// Obsticle
char ObsticleSlize [3][40] = { "Obsticle//obstical_01.bmp", "Obsticle//obstical_02.bmp", "Obsticle//obstical_03.bmp" };


int obscordinateY = 230 ;
int OBSticle[3];


int Background[60]; //Background slice Index

int mposx,  mposy;

//Character cordinates 
int charCordinatesX = 125 ; // Character Initial Cordinate at X axis
int charCordinatesY = 230 ; // Character Initial Cordinate at Y axis
int charIndex = 0; //Character Index indicate the character slice number 
int bgslice = 60; // The total num of Background slices is 60
int bgslicepixel = 32; // Background slice pixel is 32

bool music = true ;
// Showing score 
int score = 0;
char Number[100];
/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	iClear();
	if (gamestate == -1)
	{
		iShowBMP(0, 0, "Menu//menu.bmp");
	}
	
	else if (gamestate == 1)
	{

		iShowBMP(0, 0, mainBackground[15]); // First Slize that stay at (0,0)
	
		for (int i = 0; i < 60; i++)
		{
			iShowBMP(Background[i], 0, mainBackground[i]); // Showing Background Slizes 
		}
		for (int j = 0; j < 3; j++)
		{
			
			iShowBMP2(OBSticle[j], obscordinateY, ObsticleSlize[j], 0); // Showing Obsticle Slizes 
		}

		// Showing Jump UP & Jump Down
		if (jump)
		{
			if (jumpUP)
				iShowBMP2(charCordinatesX, charCordinatesY + jumpCordinateY, JUMP[0], 0);
			else
				iShowBMP2(charCordinatesX, charCordinatesY + jumpCordinateY, JUMP[1], 0);
		}
		else
		{
			iShowBMP2 ( charCordinatesX , charCordinatesY, characterRun[charIndex] , 0); // Showing Running Slizes 
		}
		//Showing score 
		string scoreText = to_string(score); //converting score to string
		for (int i = 0; i < scoreText.length(); i++)
		{
			Number[i] = scoreText[i]  ; //Counting score according to Box
		}
		iSetColor(255, 255, 255); //Setting Colour white 
		iText(20, 1010, "Score : ", GLUT_BITMAP_TIMES_ROMAN_24); //
		iText(20, 980, Number , GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (gamestate == 2)
	{
		// showing Instruction
		iShowBMP(90, 100, "Instruction//instruction_01.bmp");

	}
	else if (gamestate == 3)
	{
		// showing About US 
		iShowBMP(0, 0, "About//Info.bmp");
	}
	else if (gamestate == 5)
	{
		// showing About US 
		//iShowBMP(100, 180, "Game Over//gameover_03.bmp");
		iShowBMP(0, 0, "Game Over//gameover_03.bmp");
		PlaySound(0, 0, 0);
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
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if (gamestate == -1)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mx >= 514 && mx <= 1006 && my >= 780 && my <= 860)
			{
				gamestate = 1;
			}
			if (mx >= 514 && mx <= 1006 && my >= 660 && my <= 740)
				gamestate = 2;
			if (mx >= 514 && mx <= 1006 && my >= 540 && my <= 620)
				gamestate = 3;
			if (mx >= 514 && mx <= 1006 && my >= 420 && my <= 500)
				exit(0);
		}
	}

	
	
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here

 mposx = mx;
 mposy = my;
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'a' )
	{
		charCordinatesX -= 10; //Press a for moving backward 10 at X-Axis
		if (charCordinatesX <= 0)
			charCordinatesX = screenwidth;

	}
	if (key == 's')
	{
		//charCordinatesY -= 10;
		//if (charCordinatesY <= 230)
			//charCordinatesY = 230;
		//do something with 's'
	}
	if (key == 'd')
	{
		charCordinatesX += 10;  //Press a for moving forward 10 at X-Axis
		if (charCordinatesX >= screenwidth)
			charCordinatesX = 0;
			
	}
	//Jump logics 
	if (key == 'w')
	{
		if (!jump)
		{
			jump = true;
			jumpUP = true;
			//jumpDown = true;
		}
	}
	if (key == ' ')
	{
		if (!jump)
		{
			jump = true;
			jumpUP = true;
			//jumpDown = true;
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
	if (key == GLUT_KEY_LEFT)
	{
		charCordinatesX -= 10; //Press a for moving backward 10 at X-Axis
		if (charCordinatesX <= 0)
			charCordinatesX = screenwidth;
	}

	if (key == GLUT_KEY_RIGHT)
	{
		charCordinatesX += 10;  //Press a for moving forward 10 at X-Axis
		if (charCordinatesX >= screenwidth)
			charCordinatesX = 0;
	}

	if (key == GLUT_KEY_UP)
	{
		if (!jump)
		{
			jump = true;
			jumpUP = true;
			//jumpDown = true;
		}
	}
	if (key == GLUT_KEY_HOME)
	{
		gamestate = -1;
	}
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
}


void setAll()
{

		for (int i = 0; i < bgslice; i++)
		{
			Background[i] = bgslicepixel * i; //Every slize will shift 32 Pixel at X axis 
		}
	
}


void characterRunchange()
{
	charIndex++; //changing character slizes to draw run
	if (charIndex >= 7) //if character slize reach to 4 then return to the index 0
	{
		charIndex = 0;
	}
	if (jump)
	{
		if (jumpUP )
		{
			jumpCordinateY += 30;  //Moving forward at Y axis 

			if (jumpCordinateY >= Jumplimit)
			{
				jumpUP = false;
			}
		}

		else 
		{
			jumpCordinateY -= 25 ;  //Moving backward at Y axis 
			if (jumpCordinateY < 0)
			{
				jump = false ;
				jumpCordinateY = 0 ;
				jumpDown = false;
			}
		}
	}
}


void Backgroundchange()
{
	if (gamestate == 1)
	{
		for (int i = 0; i < bgslice; i++)
		{
			Background[i] -= 16 ; // Shifting 8 at X-axis
			if (Background[i] <= 0) // if the slize collide  X-axis at Zero then it will disaappear 
			{
				Background[i] = screenwidth ;
			}
		}
	}
}


void Obsticlechange()
{
	if (gamestate == 1)
	{
		for (int k = 0; k < 3 ; k++)
		{
			OBSticle[k] -= 35 ; // Shifting 8 at X-axis
			
			if (OBSticle[0] <= 0) // if the slize collide  X-axis at Zero then it will disaappear 
			{
				OBSticle[0] = screenwidth + rand() ;
				score++;
			}
			if (OBSticle[1] <= 0) // if the slize collide  X-axis at Zero then it will disaappear 
			{
				OBSticle[1] = screenwidth + rand() % 500 + 500 ;
				score++;
			}
			if (OBSticle[2] <= 0) // if the slize collide  X-axis at Zero then it will disaappear 
			{
				OBSticle[2] = screenwidth +  rand() % 200  ;
				score++;
			}
		}
		
		for (int i = 0; i < 3; i++)
			{
				if (jump)
				{
					// Jump Collision Logic 
					if (charCordinatesX + 60 >= OBSticle[i] && charCordinatesX + 60 <= OBSticle[i] + 100 &&
						charCordinatesY + jumpCordinateY >= obscordinateY  && charCordinatesY + jumpCordinateY <= obscordinateY + 150)
					{
						
						gamestate = 5;
					}
				}
				else
				{
					if (charCordinatesX+100 >= OBSticle[i] && charCordinatesX+100 <= OBSticle[i] + 100) //When jump is not true then if the character collided at X axis he will be dead 
					{
						gamestate = 5;
					}
				}
			}

	}
}


//
int main()
{
	setAll();
 	if (music == true)
	{
		PlaySound("Music\\9convert.com - Naruto OST 2  Afternoon of Konoha.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	iSetTimer(70, characterRunchange); //Run Changing time 
	iSetTimer(100, Obsticlechange); //Obsticle Changing time 
	iSetTimer(15, Backgroundchange); //Background Changing time
	iInitialize(screenwidth,screenHight, "Agony of Defeat");
	return 0;
}
