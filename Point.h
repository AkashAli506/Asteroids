/*
 * Point.h
 *
 *  Created on: Apr 28, 2018
 *      Author: akash
 */

#ifndef POINT_H_
#define POINT_H_
#include<iostream>
using namespace std;

class Point
{
private:
	double x;
	double y;
public:
	Point();
	Point(double,double);
	Point(Point&);
	void assign(double,double);
	void operator=(const Point &);
	void operator+=(const Point &);
	void operator-=(const Point &);
	Point operator+(const Point &);
	Point operator-(const Point &);
	double getX() const;
	void setX(double x);
	double getY() const;
	void setY(double y);
	virtual ~Point();
};

#endif /* POINT_H_ */
