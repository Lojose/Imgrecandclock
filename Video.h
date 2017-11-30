#pragma once
#include <stdio.h>
#include <cstring>

class Video {
public:
	void Videoload(int w, int h);
	FILE *pipe;
	void closePipe();
private:
};