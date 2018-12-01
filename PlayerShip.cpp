/*
 * PlayerShip.cpp
 *
 *  Created on: Apr 28, 2018
 *      Author: akash
 */

#include "PlayerShip.h"
#include "util.h"
#include "math.h"

PlayerShip::PlayerShip()
{
	ship=new Point[4];
	temp=new Point[4];
	ship[0].assign(0,30);
	ship[1].assign(25,-30);
	ship[2].assign(0,-10);
	ship[3].assign(-25,-30);
	for (int i=0;i<4;i++)
	{
		temp[i]=ship[i];
	}
	radius=50;
	ref.assign(510,430);
	rangle=0;
	movingAngle=0;
	count=0;
	lives=3;
	alive=true;
	time2=0;
	immune=120;
	immunity=true;

	fireSize=10;
	fire=new Bullet*[fireSize];
	for(int i=0;i<fireSize;i++)
	{
		fire[i]=new Bullet;
	}
}
//PlayerShip::PlayerShip(Point a1,Point b1,Point c1):GameObject()
//{
//	a=a1;
//	b=b1;
//	c=c1;
//	bullet.setX(-100);
//	bullet.setY(-100);
//	bulletfire=false;
//}
//PlayerShip::PlayerShip(double a1,double b1,double c1,double a2,double b2,double c2):GameObject()
//{
//	a.setX(a1);
//	a.setY(a2);
//	b.setX(b1);
//	b.setY(b2);
//	c.setX(c1);
//	c.setY(c2);
//	bullet.setX(-100);
//	bullet.setY(-100);
//	bulletfire=false;
//}


void PlayerShip::Rotate(double Deg_ang)
{
	rangle-=static_cast<int>(Deg_ang);
	rangle%=360;

	for (int i=0;i<4;i++)
	{
		temp[i].assign(ship[i].getX()*cos(Deg2Rad(rangle))-ship[i].getY()*sin(Deg2Rad(rangle)),
					   ship[i].getX()*sin(Deg2Rad(rangle))+ship[i].getY()*cos(Deg2Rad(rangle)));
	}
	if (Deg_ang<0)
	{
		movingAngle-=15;
	}
	else
		movingAngle+=15;
}
void PlayerShip::nextStateCheck(char c)
{
	if (Alive()==true)
	{
		this->Draw();

		if (c=='s')
		{
			for (int i=0;i<fireSize;i++)
			{
				if (fire[i]->isDisplay()==false)
				{
					fire[i]->setDisplay(true);
					fire[i]->setBullet(ref.getX(),ref.getY(),movingAngle);
					break;
				}
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
	if (Alive()==false)
	{
		time2++;
		if (time2>=30 && lives>0)
		{
			for (int i=0;i<4;i++)
			{
				temp[i]=ship[i];
			}
			ref.assign(510,430);
			rangle=0;
			movingAngle=0;
			time2=0;
			alive=true;
		}
	}



}

Point PlayerShip::getCenter()
{
	return ref;
}

void PlayerShip::hyperspace()
{
	if (count>=150)
	{
		ref.assign((GetRandInRange(100, 900)),(GetRandInRange(100, 700)));
		count=0;
	}

}


void PlayerShip::Draw()
{

	if (immune>0)
	{
		for (int i = 0; i < 4; ++i)
		{
			DrawLine(temp[i].getX()+ref.getX(), temp[i].getY()+ref.getY(),temp[(i+1)%4].getX()+ref.getX(), temp[(i+1)%4].getY()+ref.getY(), 10, colors[GREEN]);
		}
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			DrawLine(temp[i].getX()+ref.getX(), temp[i].getY()+ref.getY(),temp[(i+1)%4].getX()+ref.getX(), temp[(i+1)%4].getY()+ref.getY(), 10, colors[RED]);
		}
	}
	for (int i=0;i<fireSize;i++)
	{
		if (fire[i]->isDisplay())
		{
			fire[i]->Draw();
			//cout<<"a"<<endl;
		}
	}

	int x=850;
	for (int i=0;i<lives;i++)
	{

		for (int i = 0; i < 4; ++i)
		{
			DrawLine(ship[i].getX()/2+x, ship[i].getY()/2+810,ship[(i+1)%4].getX()/2+x, ship[(i+1)%4].getY()/2+810, 10, colors[RED]);
		}
		x+=30;
	}

	immune--;
	if (immune<0)
	{
		immunity=false;
	}

	if (count>=150)
	{
		DrawString(10, 800, "Hyper", colors[GREEN]);
	}
	count++;

}
Bullet* PlayerShip::getBullet(int i)
{
	return fire[i];
}
void PlayerShip::Shoot()
{

}
void PlayerShip::Move(char c)
{
	if (ref.getX()>1100)
	{
		ref.setX(ref.getX()-1100);
	}
	if (ref.getX()<0)
	{
		ref.setX(ref.getX()+1100);
	}
	if (ref.getY()>890)
	{
		ref.setY(ref.getY()-890);
	}
	if (ref.getY()<0)
	{
		ref.setY(ref.getY()+890);
	}

	ref.assign(ref.getX()+10*sin(Deg2Rad(movingAngle)),ref.getY()+10*cos(Deg2Rad(movingAngle)));
	//cout<<ref.getX()<<" "<<ref.getY()<<endl;
}
bool PlayerShip::Alive()
{
	return alive;
}

const Point& PlayerShip::getRef() const {
	return ref;
}

void PlayerShip::setRef(Point& ref) {
	this->ref = ref;
}
int PlayerShip::getRadius()
{
	return radius;
}


PlayerShip::~PlayerShip() {
	// TODO Auto-generated destructor stub
}

int PlayerShip::getLives() const {
	return lives;
}

void PlayerShip::setLives(int lives) {
	if (lives>=0)
	this->lives = lives;
}

void PlayerShip::setAlive(bool alive) {
	this->alive = alive;
}

int PlayerShip::getImmune() const {
	return immune;
}

void PlayerShip::setImmune(int immune) {
	this->immune = immune;
}

bool PlayerShip::isImmunity() const {
	return immunity;
}

void PlayerShip::setImmunity(bool immunity) {
	this->immunity = immunity;
}
