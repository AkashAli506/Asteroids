/*
 * Bullet.cpp
 *
 *  Created on: May 8, 2018
 *      Author: akash
 */

#include "Bullet.h"
#include"util.h"


Bullet::Bullet(double x, double y,int r,int ang,bool a)
{
	center.assign(x,y);
	radius=r;
	angle=ang;
	display=a;
	time1=0;
	alive=false;
}
void Bullet::Draw()
{
	DrawCircle(center.getX(), center.getY(),radius, colors[RED]);
	//cout<<"a";
	time1++;


}
void Bullet::setBullet(double x, double y,int ang)
{
	center.assign(x,y);
	angle=ang;
	time1=0;
}
void Bullet::Shoot()
{

}
void Bullet::Move(char c)
{

	if (center.getX()>1100)
	{
		center.setX(center.getX()-1100);
	}
	if (center.getX()<0)
	{
		center.setX(center.getX()+1100);
	}
	if (center.getY()>890)
	{
		center.setY(center.getY()-890);
	}
	if (center.getY()<0)
	{
		center.setY(center.getY()+890);
	}
	center.assign(center.getX()+15*sin(Deg2Rad(angle)),center.getY()+15*cos(Deg2Rad(angle)));
	//cout<<center.getX()<<" "<<center.getY()<<endl;

}
void Bullet::Rotate(double)
{

}
bool Bullet::Alive()
{
	return alive;
}
void Bullet::nextStateCheck(char)
{

}
Point Bullet::getCenter()
{
	return center;
}
int Bullet::getRadius()
{
	return radius;
}

Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}

bool Bullet::isDisplay() const {
	return display;
}

int Bullet::getTime1() const {
	return time1;
}

void Bullet::setDisplay(bool display) {
	this->display = display;
	//cout<<display<<endl;
}

void Bullet::setTime1(int time1) {
	this->time1 = time1;
}

void Bullet::setAlive(bool alive) {
	this->alive = alive;
}
