/*
 * MiniSaucer.h
 *
 *  Created on: May 9, 2018
 *      Author: akash
 */

#ifndef MINISAUCER_H_
#define MINISAUCER_H_
#include <iostream>
#include "EnemySaucer.h"
#include "Bullet.h"
using namespace std;

class MiniSaucer :public EnemySaucer
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
	MiniSaucer();
	void Draw();
	void Shoot();
	void Move(char);
	bool Alive();
	void nextStateCheck(char);
	void Rotate(double);
	int getRadius();
	Bullet* getBullet(int i);
	Point getCenter();
	virtual ~MiniSaucer();
	void setAlive(bool alive);
};


#endif /* MINISAUCER_H_ */
