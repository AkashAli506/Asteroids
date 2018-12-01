/*
 * ComplexAsteroid.h
 *
 *  Created on: May 9, 2018
 *      Author: akash
 */

#ifndef COMPLEXASTEROID_H_
#define COMPLEXASTEROID_H_
#include <iostream>
#include "Asteroid.h"
#include "Point.h"
#include "util.h"
#include "stdlib.h"
#include "time.h"
using namespace std;

class ComplexAsteroid :public Asteroid
{

	Point center;
	Point *points;
	Point *temp;
	int npoints;
	int movingAngle;
	int rotationAngle;
	int radius;
	int count;
	bool alive;

public:
	ComplexAsteroid(double,double);
	void Draw();
	void Shoot();
	void Move(char);
	void nextStateCheck(char);
	void Rotate(double);
	bool Alive();
	Point getCenter();
	int getRadius();
	~ComplexAsteroid();
	void setCount(int count);
	void setAlive(bool alive);
};

#endif /* COMPLEXASTEROID_H_ */
