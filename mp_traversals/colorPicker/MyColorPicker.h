#pragma once

#include "ColorPicker.h"
#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

using namespace cs225;

/**
 * A color picker class using your own color picking algorithm
 */
class MyColorPicker : public ColorPicker {
public:
 	HSLAPixel getColor(unsigned x, unsigned y);
	MyColorPicker( HSLAPixel color1_, HSLAPixel color2_, HSLAPixel color3_);

private:
	//PNG png;
	HSLAPixel color1;
	HSLAPixel color2;
	HSLAPixel color3;
	double hue;
};
