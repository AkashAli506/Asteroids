/*
 * Point.cpp
 *
 *  Created on: Apr 28, 2018
 *      Author: akash
 */

#include "Point.h"

Point::Point()
{
	x=0;
	y=0;
}
Point::Point (double x1,double y1)
{
	x=x1;
	y=y1;
}
Point::Point(Point &a)
{
	x=a.getX();
	y=a.getY();
}
void Point::assign(double x1,double y1)
{
	x=x1;
	y=y1;
}

Point::~Point()
{
	//cout<<"Destructor Called"<<endl;;
}
void Point::operator=(const Point &obj)
{
	x=obj.x;
	y=obj.y;
}

void Point::operator+=(const Point &obj)
{
	x+=obj.x;
	y+=obj.y;
}
void Point::operator-=(const Point &obj)
{
	x-=obj.x;
	y-=obj.y;
}
Point Point::operator+(const Point &obj)
{
	Point temp;
	temp.setX(obj.getX()+this->getX());
	temp.setY(obj.getY()+this->getY());
	return temp;
}
Point Point::operator-(const Point &obj)
{
	Point temp;
	temp.setX(obj.getX()-this->getX());
	temp.setY(obj.getY()-this->getY());
	return temp;
}
double Point::getX() const {
	return x;
}

void Point::setX(double x) {
	this->x = x;
}

double Point::getY() const {
	return y;
}

void Point::setY(double y) {
	this->y = y;
}
