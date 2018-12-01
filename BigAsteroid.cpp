/*
 * BigAsteroid.cpp
 *
 *  Created on: Apr 28, 2018
 *      Author: akash
 */

#include "BigAsteroid.h"


BigAsteroid::BigAsteroid()
{

	center.assign((GetRandInRange(100, 900)),(GetRandInRange(100, 900)));
	radius = 50;
	alive=true;
	npoints=GetRandInRange(4, 9);
	movingAngle=GetRandInRange(50, 300);
	rotationAngle=GetRandInRange(-360, 360);

	points=new Point[npoints];
	temp=new Point[npoints];

	int dAngle = 360 / npoints;
	float tAngle  = GetRandInRange(5, dAngle );

	int cx = radius * cos(Deg2Rad(tAngle)), cy = radius * sin(Deg2Rad(tAngle));
	int xx1 = cx;
	int yy1 = cy;
	points[0].assign(xx1,yy1);
	int sAngle = dAngle;
	for (int i = 0; i < npoints - 1; ++i) {
		tAngle = GetRandInRange(sAngle, sAngle + dAngle);
		int xx2 =  radius * cos(Deg2Rad(tAngle)), yy2 = radius * sin(Deg2Rad(tAngle));
		if (i%2==1)
		{
			points[i+1].assign(xx2,yy2);
		}

		xx1 = xx2;
		yy1 = yy2;

		if (i%2==0)
		{
			points[i+1].assign(xx1,yy1);
		}
		sAngle += dAngle;
	}

	for (int i=0;i<npoints;i++)
	{
		temp[i]=points[i];
		cout<<temp[i].getX()<<" "<<temp[i].getY()<<endl;
	}

}
int BigAsteroid::getRadius()
{
	return radius;
}
Point BigAsteroid::getCenter()
{
	return center;
}
void BigAsteroid::Draw()
{

	for (int i = 0; i < npoints; ++i) {
		DrawLine(temp[i].getX()+center.getX(), temp[i].getY()+center.getY(),temp[(i+1)%npoints].getX()+center.getX(), temp[(i+1)%npoints].getY()+center.getY(), 10, colors[SKY_BLUE]);
	}

}
void BigAsteroid::Shoot()
{

}
void BigAsteroid::Move(char c)
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

	center.assign(center.getX()+1-cos(Deg2Rad(movingAngle)),center.getY()+1+sin(Deg2Rad(movingAngle)));
}

void BigAsteroid::nextStateCheck(char c)
{
	if (Alive())
	{
		this->Draw();
		this->Rotate(5);
		this->Move(c);
	}
}
bool BigAsteroid::Alive()
{
	return alive;
}
void BigAsteroid::Rotate(double a)
{

	for (int i=0;i<npoints;i++)
	{
		temp[i].assign(points[i].getX()*cos(Deg2Rad(rotationAngle))-points[i].getY()*sin(Deg2Rad(rotationAngle)),
					   points[i].getX()*sin(Deg2Rad(rotationAngle))+points[i].getY()*cos(Deg2Rad(rotationAngle)));
	}
	if (rotationAngle<0)
	{
		rotationAngle-=1;
	}
	else
	{
		rotationAngle+=1;
	}

}

void BigAsteroid::setAlive(bool alive) {
	this->alive = alive;
}

BigAsteroid::~BigAsteroid() {
	// TODO Auto-generated destructor stub
}
