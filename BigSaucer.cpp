/*
 * BigSaucer.cpp
 *
 *  Created on: Apr 28, 2018
 *      Author: akash
 */

#include "BigSaucer.h"
#include"util.h"

BigSaucer::BigSaucer()
{
	shape=new Point[10];
	shape[0].assign(30,60);
	shape[1].assign(0,30);
	shape[2].assign(30,0);
	shape[3].assign(100,0);
	shape[4].assign(130,30);
	shape[5].assign(100,60);
	shape[6].assign(80,90);
	shape[7].assign(50,90);
	shape[8].assign(30,60);
	shape[9].assign(100,60);

	radius=60;
	alive=true;

	center.assign(100,650);
	angle=0;

	fireSize=1;
	fire=new Bullet*[fireSize];
	for(int i=0;i<fireSize;i++)
	{
		fire[i]=new Bullet;
	}
}
int BigSaucer::getRadius()
{
	return radius;
}
void BigSaucer::Draw()
{
	for (int i=0;i<10;i++)
	{
		DrawLine(shape[i].getX()+center.getX(), shape[i].getY()+center.getY(),shape[(i+1)%10].getX()+center.getX(), shape[(i+1)%10].getY()+center.getY(), 10, colors[PINK]);
	}
	for (int i=0;i<fireSize;i++)
	{
		if (fire[i]->isDisplay())
		{
			fire[i]->Draw();
		}
	}



}
void BigSaucer::Shoot()
{

}
Bullet* BigSaucer::getBullet(int i)
{
	return fire[i];
}

void BigSaucer::nextStateCheck(char c)
{
	if (Alive())
	{
		this->Draw();
		this->Move(c);

		for (int i=0;i<fireSize;i++)
		{
			if (fire[i]->isDisplay()==0)
			{
				fire[i]->setDisplay(true);
				fire[i]->setBullet(center.getX(),center.getY(),GetRandInRange(5,360));
			}
		}
		for (int i=0;i<fireSize;i++)
		{
			if (fire[i]->getTime1()>60)
			{
				fire[i]->setDisplay(false);
			}
			if (fire[i]->isDisplay())
			{
				fire[i]->Move(c);
			}
		}
	}

}

void BigSaucer::Move(char c)
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

	center.assign(center.getX()+2,center.getY()+(3*cos(Deg2Rad(angle))));
	angle+=3;
	if (angle>=360)
	{
		angle%=360;
	}
}
bool BigSaucer::Alive()
{
	return alive;
}
Point BigSaucer::getCenter()
{
	return center;
}
void BigSaucer::Rotate(double)
{

}

void BigSaucer::setAlive(bool alive) {
	this->alive = alive;
}

BigSaucer::~BigSaucer() {
	// TODO Auto-generated destructor stub
}
