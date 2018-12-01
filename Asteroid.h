/*
 * Asteroid.h
 *
 *  Created on: Apr 28, 2018
 *      Author: akash
 */

#ifndef ASTEROID_H_
#define ASTEROID_H_
#include <iostream>
#include "GameObject.h"
using namespace std;

class Asteroid :public GameObject
{
public:
	Asteroid();
	void Draw()=0;
	void Shoot()=0;
	void Move(char)=0;
	void Rotate(double)=0;
	Point getCenter()=0;
	int getRadius()=0;
	virtual void nextStateCheck(char)=0;
	virtual void setAlive(bool)=0;
	bool Alive()=0;
	~Asteroid();
};

#endif /* ASTEROID_H_ */
