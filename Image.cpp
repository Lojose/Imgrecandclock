#include <stdio.h>
#include <cstring>
#include <iostream>
#include <cerrno>
#include "Image.h"
#include <sstream>
#include "Global.h"
#include "Frame.h"

extern Frame frame;

Image::Image() : pixels(0), w(0), h(0), x(x), y(y) { }

void Image::load(const char * filename, int w, int h) {
	this->w = w;
	this->h = h;
	pixels = new byte[w * h * 3];

	std::stringstream ss;
	ss << "ffmpeg ";
	ss << "-i ";
	ss << filename;
	ss << " ";
	ss << "-f rawvideo ";
	ss << "-pix_fmt rgb24 ";
	ss << "-vf scale=";
	ss << w << ":" << h;
	ss << " - ";
#ifdef _WIN32
	FILE * pipe = _popen(ss.str().c_str(), "rb");
#else
	FILE * pipe = popen(cmd, "r");
#endif
	if (pipe == 0) {
		std::cout << "error: " << strerror(errno) << std::endl;
		exit(1);
	}
	fread(pixels, 3, w * h, pipe);

	fflush(pipe);
#ifdef _WIN32
	_pclose(pipe);
#else
	pclose(pipe);
#endif
}

void Image::setVelocity(double dx, double dy) {
	this->dx = dx;
	this->dy = dy;
}

void Image::update(double dt) {
	x += dx*dt;
	y += dy*dt;
}

void Image::setStartingpts(int x, int y) {
	this->x = x;
	this->y = y;
}

void Image::draw() const {
	int p = W - w;
	if (p - x  < 0) return;

	int j = H - h;
	if (j - y < 0) return;

	for (int i = 0; i < w; ++i) {
		for (int j = 0; j < h; ++j) {
			byte r = pixels[j * w * 3 + i * 3 + 0];
			byte g = pixels[j * w * 3 + i * 3 + 1];
			byte b = pixels[j * w * 3 + i * 3 + 2];
			frame.setPixel(x + i, y + j, r, g, b);
		}
	}
}