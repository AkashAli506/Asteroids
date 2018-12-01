/*
 * BigAsteroid.h
 *
 *  Created on: Apr 28, 2018
 *      Author: akash
 */

#ifndef BIGASTEROID_H_
#define BIGASTEROID_H_
#include <iostream>
#include "Asteroid.h"
#include "Point.h"
#include "util.h"
#include "stdlib.h"
#include "time.h"
using namespace std;

class BigAsteroid :public Asteroid
{

	Point center;
	Point *points;
	Point *temp;
	int npoints;
	int movingAngle;
	int rotationAngle;
	int radius;
	bool alive;


public:
	BigAsteroid();
	void Draw();
	void Shoot();
	void Move(char c);
	void nextStateCheck(char);
	void Rotate(double);
	bool Alive();
	Point getCenter();
	int getRadius();
	~BigAsteroid();
	void setAlive(bool alive);
};

#endif /* BIGASTEROID_H_ */
