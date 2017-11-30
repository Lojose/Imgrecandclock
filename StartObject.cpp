#include <iostream>
#include "Image.h"
#include "StartObject.h"
#include "Engine.h"
#include "Clock.h"

extern  Clock clock; 
StartObject::StartObject() {
	Image *img1 = new Image(); 
	img1->load("ducky.bmp", 100, 100);
	img1->setStartingpts(0, 0);
	img1->setVelocity(100, 0);
	images.push_back(img1); 

	Image *img2 = new Image();
	img2->load("dice.png", 100, 100);
	img2->setStartingpts(100, 100);
	img2->setVelocity(0, 50);
	images.push_back(img2);

	Image *img3 = new Image(); 
	img3->load("dice.png", 100, 100);
	img3->setStartingpts(300, 100);
	img3->setVelocity(100, 0);
	images.push_back(img3);

	Rectangle *r1 = new Rectangle(100, 100, 200, 0); 
	r1->setColor(300, 100, 0); 
	r1->setVelocity(100, 100); 
	rectangles.push_back(r1); 

	for (int i = 0; i < images.size(); ++i) {
		Engine::addObject(images[i]);
	}

	for (int i = 0; i < rectangles.size(); ++i) {
		Engine::addObject(rectangles[i]);
	}
}

StartObject::~StartObject () {
	for (int i = 0; i < images.size(); ++i) {
		delete images[i];
	}

	for (int i = 0; i < rectangles.size(); ++i) {
		delete rectangles[i];
	}
}

void StartObject::update(double dt) {	
	for (int i = 0; i < images.size(); ++i) {
		images[i]->update(dt); 
	}

	for (int i = 0; i < rectangles.size(); ++i) {
		rectangles[i]->update(dt);
	}
	clock.update(dt); 
}

void StartObject::draw() const {
	for (int i = 0; i < images.size(); ++i) {
		images[i]->draw();
	}

	for (int i = 0; i < rectangles.size(); ++i) {
		rectangles[i]->draw();
	}
	clock.draw(); 
}

