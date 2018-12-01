/*
 * ComplexAsteroid.cpp
 *
 *  Created on: May 9, 2018
 *      Author: akash
 */

#include "ComplexAsteroid.h"

ComplexAsteroid::ComplexAsteroid(double cenx,double ceny):Asteroid()
{

	center.assign(cenx,ceny);
	radius = 35;
	alive=true;
	count=0;
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
int ComplexAsteroid::getRadius()
{
	return radius;
}
Point ComplexAsteroid::getCenter()
{
	return center;
}
void ComplexAsteroid::Draw()
{

	for (int i = 0; i < npoints; ++i) {
		DrawLine(temp[i].getX()+center.getX(), temp[i].getY()+center.getY(),temp[(i+1)%npoints].getX()+center.getX(), temp[(i+1)%npoints].getY()+center.getY(), 10, colors[MAGENTA]);
	}

}
void ComplexAsteroid::Shoot()
{

}
void ComplexAsteroid::Move(char c)
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

	count++;

	center.assign(center.getX()+3-cos(Deg2Rad(movingAngle)),center.getY()+3+sin(Deg2Rad(movingAngle)));

	if (count>=90)
	{
		movingAngle=GetRandInRange(5, 355);
	}
	count%=90;
}

void ComplexAsteroid::nextStateCheck(char c)
{
	if (Alive())
	{
		this->Draw();
		this->Rotate(5);
		this->Move(c);
	}
}
bool ComplexAsteroid::Alive()
{
	return alive;
}
void ComplexAsteroid::Rotate(double a)
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


ComplexAsteroid::~ComplexAsteroid() {
	// TODO Auto-generated destructor stub
}

void ComplexAsteroid::setCount(int count) {
	this->count = count;
}

void ComplexAsteroid::setAlive(bool alive) {
	this->alive = alive;
}
