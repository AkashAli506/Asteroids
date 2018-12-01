/*
 * Board.h
 *
 *  Created on: May 2, 2014
 *      Author: Sibt ul Hussain
 */
#ifndef _BOARD_H_
#define _BOARD_H_

#include <GL/glut.h>
#include <iostream>
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
#include "ComplexAsteroid.h"
#include "MiniAsteroid.h"
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
//#define WITH_TEXTURES
using namespace std;

class Board {

private:
	int xcellsize, ycellsize;
	int width, height;
	ColorNames pcolor, bcolor, gcolor;
	int size;
	int score;
	int *x;
	int *y;
	int level;
	int s;
	int check;

public:
	GameObject **pointer;
	PlayerShip *p;
	BigSaucer *bs;
	MiniSaucer *ms;

	bool gamePause;

	static const int BOARD_X = 17;
	static const int BOARD_Y = 14;
	/*
	 static const int BOARD_X=17;
	 static const int BOARD_Y=14;
	 */

	int board_array[BOARD_Y][BOARD_X];
	Board(int xsize = 8, int ysize = 8);

	~Board(void);
	void InitalizeBoard(int, int);
	//draw the board
	void Draw();
	void Rotate();
	void Move();
	void Remove(int);
	void AddBasteroid();
	void AddBsaucer();
	void AddMsaucer();
	void addComplexAsteroid(int);
	void addMiniAsteroid(int);
	void checkCollision();
	void nextStateCheck(char);

	static int GetBoardX() {
		return BOARD_X;
	}
	static int GetBoardY() {
		return BOARD_Y;
	}
	int GetMidX() {
		return BOARD_X * xcellsize / 2.0;
	}
	int GetMidY() {
		return BOARD_Y * ycellsize / 2.0;
	}
	int GetCellSize() {
		return xcellsize;
	}

	void GetInitRandomPosition(int &x, int &y) {
		// leave 10 units from all sides
		x = GetRandInRange(50, width - 50);
		y = GetRandInRange(50, height - 50);
	}
	int GetWidth() {
		return width;
	}
	int GetHeight() {
		return height;
	}
	void GetInitTextPosition(int &x, int &y);
	const PlayerShip& getP() const;
	int getScore() const;
	int getLevel() const;
	void setLevel(int level);
	int getCheck() const;
	void setCheck(int check);
	int getX(int) const;
	int getY(int) const;
	bool isGamePause() const;
	void setGamePause(bool gamePause);
};

#endif
