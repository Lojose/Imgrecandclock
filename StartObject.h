#pragma once
#include <vector>
#include <iostream>
#include "Object.h"
#include "Image.h"
#include"Rectangle.h"
#include "Clock.h"

class StartObject :public Object  {
public:
	StartObject();
	~StartObject();
	virtual void update(double dt);
	virtual void draw() const; 
private:
	std::vector<Image* > images; 
	std::vector<Rectangle* > rectangles;
};


