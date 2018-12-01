/*
 * PlayerShip.h
 *
 *  Created on: Apr 28, 2018
 *      Author: akash
 */

#ifndef PLAYERSHIP_H_
#define PLAYERSHIP_H_
#include <iostream>
#include "GameObject.h"
#include "Point.h"
#include "Bullet.h"
using namespace std;

class PlayerShip : public GameObject
{
	Point *ship;
	Point *temp;
	Point ref;
	int rangle;
	int movingAngle;
	int radius;
	//Bullet *fire;
	Bullet **fire;
	int fireSize;
	int count;
	int lives;
	bool alive;
	int time2;
	double factor;
	int immune;
	bool immunity;

public:
	PlayerShip();
//	PlayerShip(Point,Point,Point);
//	PlayerShip(double,double,double,double,double,double);
	void Draw();
	void Shoot();
	void Move(char);
	void Rotate(double);
	bool Alive();
	void nextStateCheck(char);
	void hyperspace();
	~PlayerShip();
	Point getCenter();
	int getRadius();
	const Point& getRef() const;
	void setRef( Point& ref);
	Bullet* getBullet(int i);
	int getLives() const;
	void setLives(int lives);
	void setAlive(bool alive);
	int getImmune() const;
	void setImmune(int immune);
	bool isImmunity() const;
	void setImmunity(bool immunity);
};

#endif /* PLAYERSHIP_H_ */
