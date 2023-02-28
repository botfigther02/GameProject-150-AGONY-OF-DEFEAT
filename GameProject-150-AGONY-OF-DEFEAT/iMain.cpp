/*
    Original Author: S. M. Shahriar Nirjon
    Last Modified by: Mohammad Saifur Rahman
    last modified: October 13, 2015
    Version: 2.0
*/


#include<iostream>
using namespace std;
# include "iGraphics.h"

#define screenwidth 1420
#define screenHight 1080
//#define screenwidth 1200 
//#define screenHight 675

//Background Slizes
char mainBackground[60][30] = { "Background\\tile000.bmp", "Background\\tile001.bmp", "Background\\tile002.bmp", "Background\\tile003.bmp", "Background\\tile004.bmp", "Background\\tile005.bmp", "Background\\tile006.bmp", "Background\\tile007.bmp", "Background\\tile008.bmp", "Background\\tile009.bmp", "Background\\tile010.bmp", "Background\\tile011.bmp", "Background\\tile012.bmp",
"Background\\tile013.bmp", "Background\\tile014.bmp", "Background\\tile015.bmp", "Background\\tile016.bmp", "Background\\tile017.bmp", "Background\\tile018.bmp", "Background\\tile019.bmp", "Background\\tile020.bmp", "Background\\tile021.bmp", "Background\\tile022.bmp", "Background\\tile023.bmp", "Background\\tile024.bmp", "Background\\tile025.bmp", "Background\\tile026.bmp", "Background\\tile027.bmp", "Background\\tile028.bmp", "Background\\tile029.bmp", "Background\\tile030.bmp" ,
"Background\\tile031.bmp", "Background\\tile032.bmp", "Background\\tile033.bmp", "Background\\tile034.bmp", "Background\\tile035.bmp", "Background\\tile036.bmp", "Background\\tile037.bmp", "Background\\tile038.bmp", "Background\\tile039.bmp", "Background\\tile040.bmp", "Background\\tile041.bmp", "Background\\tile042.bmp", "Background\\tile043.bmp", "Background\\tile044.bmp", "Background\\tile045.bmp", "Background\\tile046.bmp", "Background\\tile047.bmp", "Background\\tile048.bmp",
"Background\\tile049.bmp", "Background\\tile050.bmp", "Background\\tile051.bmp", "Background\\tile052.bmp", "Background\\tile053.bmp", "Background\\tile054.bmp", "Background\\tile055.bmp", "Background\\tile056.bmp", "Background\\tile057.bmp", "Background\\tile058.bmp", "Background\\tile059.bmp" };

//Run Slizes
char characterRun[8][20] = { "Run\\run_001.bmp", "Run\\run_002.bmp", "Run\\run_003.bmp", "Run\\run_004.bmp", "Run\\run_005.bmp", "Run\\run_006.bmp", "Run\\run_007.bmp", "Run\\run_008.bmp"};

int Background[60];

int mposx,  mposy;

//Character cordinates 
int charCordinatesX = 125 ;
int charCordinatesY = 230 ;
int charIndex = 0;

bool music = true;


/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	iClear();
	/*
	for (int i = 0; i < 2; i++)
	{
		iShowBMP(BG[i], 0, bg[i]);
	}
	*/
	iShowBMP(0 , 0, mainBackground[15]); // First Slize that stay at (0,0)
	for (int i = 0; i < 60; i++)
	{
		iShowBMP(Background[i], 0, mainBackground[i]); // Showing Background Slizes 
	}
	//for (int i = 0; i < 4; i++)
	//{
	iShowBMP2(charCordinatesX, charCordinatesY, characterRun[charIndex] , 0 ); // Showing Running Slizes 
	//}
	

	
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
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
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
		
	}
	if (key == 's')
	{
		//do something with 'q'
	}
	if (key == 'd')
	{
		//do something with 'q'
			
	}
	if (key == 'w')
	{
		//do something with 'q'
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

	if(key == GLUT_KEY_UP)
	{
		exit(0);
	}
}


void setAll()
{
	
	
	for (int i = 0; i < 60; i++)
	{ 
		Background[i] = 32 * i; //Every slize will shift 32 Pixel at X axis 
	}
}


void characterRunchange()
{
	charIndex++; //changing character slizes to draw run
	if (charIndex >= 7) //if character slize reach to 4 then return to the index 0
	{
		charIndex = 0;
	}
}


void Backgroundchange()
{
	
	for (int i = 0; i < 60; i++) 
	{
		Background[i] -= 8; // Shifting 8 at X-axis
		if (Background[i] <= 0) // if the slize collide  X-axis at Zero then it will disaappear 
		{
			Background[i] = screenwidth - 16; 
		}
	}
	
	


}

//
int main()
{
	setAll();
	iSetTimer(80, characterRunchange); //Run Changing time  
	iSetTimer(25, Backgroundchange); //Background Changing time
	iInitialize(screenwidth,screenHight, "Agony of Defeat");
	return 0;
}
