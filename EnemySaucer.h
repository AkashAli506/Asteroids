/*
 * EnemySaucer.h
 *
 *  Created on: Apr 28, 2018
 *      Author: akash
 */

#ifndef ENEMYSAUCER_H_
#define ENEMYSAUCER_H_
#include <iostream>
#include "GameObject.h"
using namespace std;

class EnemySaucer : public GameObject
{
public:
	EnemySaucer();
	void Draw()=0;
	void Shoot()=0;
	void Move(char)=0;
	bool Alive()=0;
	void Rotate(double)=0;
	Point getCenter()=0;
	int getRadius()=0;
	void nextStateCheck(char)=0;
	virtual void setAlive(bool)=0;
	~EnemySaucer();
};

#endif /* ENEMYSAUCER_H_ */
