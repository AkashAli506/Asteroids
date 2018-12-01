/*
 * MiniAsteroid.h
 *
 *  Created on: May 9, 2018
 *      Author: akash
 */

#ifndef MINIASTEROID_H_
#define MINIASTEROID_H_
#include <iostream>
#include "Asteroid.h"
#include "Point.h"
#include "util.h"
#include "stdlib.h"
#include "time.h"
using namespace std;

class MiniAsteroid :public Asteroid
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
	MiniAsteroid(double,double);
	~MiniAsteroid();
	void Draw();
	void Shoot();
	void Move(char);
	void nextStateCheck(char);
	void Rotate(double);
	bool Alive();
	Point getCenter();
	int getRadius();
	void setAlive(bool alive);
};

#endif /* MINIASTEROID_H_ */
