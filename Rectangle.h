#pragma once
#include "Global.h"
#include "Object.h"

class Rectangle:public Object {
public:
	Rectangle(double h, double w, double x, double y);

	virtual void draw()const ;
	virtual void update(double dt);

	void setColor(byte r, byte g, byte b);
	void setVelocity(double dx, double dy);
private:
	byte r;
	byte g;
	byte b;
	double h;
	double w;
	double dx;
	double dy;
	double x;
	double y;
};
