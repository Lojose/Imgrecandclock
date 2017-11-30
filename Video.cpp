#include <sstream>
#include <sys/stat.h>
#include <iostream>
#include "Video.h"
#include "Global.h"
void Video::Videoload(int w, int h) {
	std::stringstream ss;
	ss << "ffmpeg ";
	ss << "-y ";
	ss << "-hide_banner ";
	ss << "-f rawvideo ";
	ss << "-pix_fmt rgb24 ";
	ss << "-video_size ";
	ss << w << ":" << h; // size of the video
	ss << " ";
	ss << "-i - ";
	ss << "-r ";
	//ss << (int)frames_per_second;
	ss << 25; 
	ss << " ";
	ss << "-vcodec mpeg4 ";
	ss << "-an ";
	ss << "-q:v 5 ";
	ss << "output.mp4 ";
#ifdef _WIN32
	pipe = _popen(ss.str().c_str(), "wb");
#else
	FILE * pipe = popen(cmd, "w");
#endif
	if (pipe == 0) {
		std::cout << "error: " << strerror(errno) << std::endl;
		exit(1);
	}
}

void Video::closePipe() {
	fflush(pipe);
#ifdef _WIN32
	_pclose(pipe);
#else
	pclose(pipe);
#endif
}