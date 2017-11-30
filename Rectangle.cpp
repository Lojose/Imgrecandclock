#include <iostream>
#include "Rectangle.h"
#include "Frame.h"
#include "Global.h"

extern Frame frame;
Rectangle::Rectangle(double h, double w, double x, double y) : h(h), w(w), x(x), y(y) {}

void Rectangle::setColor(byte r, byte g, byte b) {
	this->r = r;
	this->g = g;
	this->b = b;
}

void Rectangle::setVelocity(double dx, double dy) {
	this->dx = dx;
	this->dy = dy;
}

void Rectangle::update(double dt) {
	x += dx*dt;
	y += dy*dt;
}

void Rectangle::draw() const {
	int p = W - w;
	if (p - x  < 0) return;

	int j = H - h;
	if (j - y < 0) return;

	double x0 = x;
	double x1 = x + w;
	double y0 = y;
	double y1 = y + h;
	for (double y = y0; y < y1; ++y) {
		for (double x = x0; x < x1; ++x) {
			frame.setPixel(x, y, r, g, b);
		}
	}
}
