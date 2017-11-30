#include "Engine.h"
#include "StartObject.h"
#include "Clock.h"

Clock clock(30, 30); 
int main(int argc, char * argv[]) {

	StartObject startObject;
	Engine::addObject(&startObject);
	return Engine::run();
}