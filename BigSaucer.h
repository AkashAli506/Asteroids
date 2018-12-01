/*
 * BigSaucer.h
 *
 *  Created on: Apr 28, 2018
 *      Author: akash
 */

#ifndef BIGSAUCER_H_
#define BIGSAUCER_H_
#include <iostream>
#include "EnemySaucer.h"
#include "Bullet.h"
using namespace std;

class BigSaucer :public EnemySaucer
{
	Point *shape;
	Point center;
	int radius;
	int angle;
	//Bullet *fire;
	Bullet **fire;
	int fireSize;
	bool alive;
public:
	BigSaucer();
	void Draw();
	void Shoot();
	void Move(char);
	bool Alive();
	void nextStateCheck(char);
	void Rotate(double);
	int getRadius();
	Bullet* getBullet(int i);
	Point getCenter();
	 ~BigSaucer();
	void setAlive(bool alive);
};

#endif /* BIGSAUCER_H_ */
