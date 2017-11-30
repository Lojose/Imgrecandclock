#pragma once
class Object {
public:
	virtual void update(double t) = 0;
	virtual void draw() const = 0; 
};