#pragma once
#include <string>
#define CHANNELS 3
//RGB colour object

typedef struct {
	unsigned char rgb[CHANNELS];
} COLOUR;

//Row-column coordinate object
typedef struct {
	int row;
	int col;
} COORD;

class Drawing
{
private:
	unsigned w;
	unsigned h;
	unsigned char *pixels;
public:
	Drawing(unsigned width, unsigned height, COLOUR clr = { 0,0,0 });
	~Drawing() { delete[] pixels; }
	bool saveBMP(std::string file_name);
	void setPixel(COORD coord, COLOUR clr);
	void drawLine(COORD start, COORD end, COLOUR clr);
};