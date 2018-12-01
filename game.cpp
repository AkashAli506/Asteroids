//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Brick Slayer...
//============================================================================

#ifndef AsteroidS_CPP_
#define AsteroidS_CPP_
#include "Board.h"
#include "util.h"
#include "GameObject.h"
#include "PlayerShip.h"
#include "Bullet.h"
#include "Point.h"
#include "EnemySaucer.h"
#include "BigSaucer.h"
#include "MiniSaucer.h"
#include "Asteroid.h"
#include "BigAsteroid.h"
#include "MiniAsteroid.h"
#include "ComplexAsteroid.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}




void DrawAsteroid(int x/*starting x*/, int y/*starting y*/,
		ColorNames color/*color*/, float radius = 6/*Asteroid radius in Units*/,
		const int corners = 7/*Asteroid corners*/) {
	int ogr = 6, ogh = 7;

	glPushMatrix();
	float sx = (float) radius / ogr;
	//glTranslatef(x, y, 1);
	//glScalef(sx, 1, 1);

	// Draw Asteroid here
	const int nvertices = 722;
	GLfloat vertices[nvertices][2];
	float hdegree = M_PI / (corners/2);
	float angle = 0;
	for (int i = 0; i < nvertices ; ++i) {
		vertices[i][0] = radius * cos(angle);
		vertices[i][1] = radius * sin(angle);
		angle += hdegree;
	}

	glColor3fv(colors[color]); // set the circle color
	glBegin(GL_TRIANGLE_FAN);
	glVertex4f(x, y, 0, 1);
	for (int i = 0; i < nvertices; ++i)
		glVertex4f(x + vertices[i][0], y + vertices[i][1], 0, 1);
	glEnd();
	
	glPopMatrix();
}

//Number of Vertices used to draw Bomberman Circle...
// x= r cos (theta), y= r sin(theta)
const int npmvertices = 1220;
GLfloat pmvertices[npmvertices][2];
void InitPMVertices(float radius) {

	float hdegree = (M_PI - M_PI / 2.0) / 360.0;
	float angle = M_PI + M_PI / 6.0;
	for (int i = 0; i < npmvertices; ++i) {
		pmvertices[i][0] = radius * cos(angle);
		pmvertices[i][1] = radius * sin(angle);
		angle += hdegree;
	}
}

void DrawBomberman(float sx/*center x*/, float sy/*center y*/,
		float radius/*Radius*/,
		const ColorNames &colorname/*Bomberman Colour*/) {

	glColor3fv(colors[colorname]); // set the circle color
	InitPMVertices(radius);
	glBegin (GL_TRIANGLE_FAN);
	glVertex4f(sx, sy, 0, 1);
	for (int i = 0; i < npmvertices; ++i)
		glVertex4f(sx + pmvertices[i][0], sy + pmvertices[i][1], 0, 1);
	glEnd();
	DrawCircle(sx - radius + radius / 2, sy + (radius - radius / 2),
			radius / 10, colors[BLACK]);
}
/*
 * Main Canvas drawing function.
 * */
Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	// draw four asteroids
	//b->Draw();
	if (b->isGamePause()==1)
	{
		DrawString(420, 800, "<< GAME PAUSED >>", colors[GREEN]);
	}

	for (int i=0;i<200;i++)
	{

		DrawCircle(b->getX(i),b->getY(i),1,colors[GetRandInRange(5, 30)]);
	}

	if (b->getCheck()==0)
	{
		static BigSaucer a;
		a.Draw();
		static BigAsteroid c;
		c.Draw();
		static BigAsteroid d;
		d.Draw();
		static BigAsteroid e;
		e.Draw();
		static BigAsteroid f;
		f.Draw();
		static MiniSaucer g;
		g.Draw();
		static BigAsteroid h;
		h.Draw();
		static PlayerShip i;
		i.Draw();
		static ComplexAsteroid j(200,200);
		j.Draw();
		static ComplexAsteroid k(600,200);
		k.Draw();
		static MiniAsteroid l(400,100);
		l.Draw();
		static MiniAsteroid m(800,100);
		m.Draw();
		DrawString(300, 300,"<<Press Enter to Start the Game>>", colors[5]);
	}

	if (b->getCheck()==1)
	{
		b->nextStateCheck('c');


		DrawString(80, 800, "Score:", colors[5]);
		DrawString(145, 800, Num2Str(b->getScore()), colors[5]);

		DrawString(240, 800, "Level:", colors[5]);
		DrawString(300, 800, Num2Str(b->getLevel()), colors[5]);
	}

	//b->GetInitRandomPosition(x, y);
	//DrawAsteroid(xasteroid, yasteroid, PURPLE, 0.8 * b->GetCellSize(), 6);
//
//	b->GetInitRandomPosition(x, y);
//	DrawAsteroid(x, y, GREEN, 0.8 * b->GetCellSize(), 6);
//
//	b->GetInitRandomPosition(x, y);
//	DrawAsteroid(x, y, YELLOW, 0.8 * b->GetCellSize(), 6);
	//DrawCircle(500, 500, 5, colors[PINK]);

//	b->GetInitRandomPosition(x, y);
//	DrawAsteroid(x, y, RED, 0.8 * b->GetCellSize(), 8);
//	b->GetInitRandomPosition(x, y);
//	DrawBomberman(x,y,50,RED);
//	b->GetInitRandomPosition(x, y);
//	float aa=0.9;
//	float *aaaa=&aa;
//	Torus2d(x,y,120,70,20.0,60.0,5,aaaa);

	//b->GetInitBombermanPosition(x, y);
	//DrawBomberman(x, y, b->GetCellSize() / 2 - 2, YELLOW);

	//b->GetInitTextPosition(x, y);
//	cout << endl <<"Text Position = "<< x << "  y= " << y << endl << flush;
	


	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		 b->pointer[0]->Rotate(-15);
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {

		//ptr[0]->Rotate(-15);
		//b->p.Rotate(-15);
		 b->pointer[0]->Rotate(15);
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

		//ptr[0]->Move();
		//b->p.Move();
		  b->pointer[0]->Move('a');
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		b->p->hyperspace();

	}
	//glutPostRedisplay();
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	/*
	 glutPostRedisplay();
	 */
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	if (key==13)
	{
		b->setCheck(1);
	}
	if (key == 'b' || key == 'B') //Key for placing the bomb
	{
		b->p->nextStateCheck('s');
	}
	if (key == 'p' || key == 'p') //Key for placing the bomb
	{
		if (b->isGamePause()==false)
		{
			b->setGamePause(true);
			glutPostRedisplay();
		}
		else
		{
			b->setGamePause(false);
		}
	}

	//glutPostRedisplay();
}
/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
//	b->Rotate();
//	b->Move();
	b->checkCollision();
	//a.Move();
	if (b->isGamePause()==false)
	{
		glutPostRedisplay();
	}
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0/30, Timer, 0);
}

/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	srand(time(NULL));
	b = new Board(60, 60); // create a new board object to use in the Display Function ...
	//ptr[0]=new PlayerShip(400,450,425,400,400,480);
//	for (int i=0;i<5;i++)
//	{
//		ptr[i]=new BigAsteroid();
//	}
	int width = 1020, height = 840;
	b->InitalizeBoard(width, height);

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("CP's Asteroids"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
#ifdef WITH_TEXTURES
	RegisterTextures();
#endif
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0/30, Timer, 0);

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
