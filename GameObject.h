/*
 * GameObject.h
 *
 *  Created on: Apr 28, 2018
 *      Author: akash
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_
#include <iostream>
#include "Point.h"
using namespace std;

class GameObject
{
public:
	GameObject();
	virtual void Draw()=0;
	virtual void Shoot()=0;
	virtual void Move(char)=0;
	virtual void Rotate(double)=0;
	virtual bool Alive()=0;
	virtual void nextStateCheck(char)=0;
	virtual Point getCenter()=0;
	virtual int getRadius()=0;
	virtual void setAlive(bool)=0;
	virtual ~GameObject();
};

#endif /* GAMEOBJECT_H_ */
