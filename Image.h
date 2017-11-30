#pragma once
#include "Object.h"
#include "Global.h"

class Image: public Object {
public:
	Image();
	~Image() { delete[] pixels; }

	virtual void draw() const;
	virtual void update(double dt);

	void load(const char * filename, int w, int h);
	void setVelocity(double dx, double dy);
	void setStartingpts(int x, int y);

private:
	byte * pixels;
	double dx;
	double dy;
	int w;  // width of image in pixels
	int h;  // height of image in pixels
	double x;  // Location of image inside of the frame.
	double y;
};