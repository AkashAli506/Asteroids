/*
 * Bullet.h
 *
 *  Created on: May 8, 2018
 *      Author: akash
 */

#ifndef BULLET_H_
#define BULLET_H_
#include <iostream>
#include "Point.h"
#include "util.h"
#include "GameObject.h"
using namespace std;

class Bullet : public GameObject
{
	Point center;
	int radius;
	int angle;
	bool display;
	int time1;
	bool alive;

public:
	Bullet(double=0, double=0,int=3,int=0,bool=false);
	void Draw();
	void Shoot();
	void Move(char);
	void Rotate(double);
	bool Alive();
	void nextStateCheck(char);
	Point getCenter();
	int getRadius();
	virtual ~Bullet();
	void setBullet(double,double,int);
	bool isDisplay() const;
	void setDisplay(bool display);
	int getTime1() const;
	void setAlive(bool alive);
	void setTime1(int time1);
};

#endif /* BULLET_H_ */
