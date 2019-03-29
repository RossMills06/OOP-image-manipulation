#pragma once

#include "ReadWrite.h"
#include "Image.h"

class ImageZoom : public Image
{
public:
	ImageZoom();

	ImageZoom(const unsigned int &_w, const unsigned int &_h, const Rgb &c = kBlack);

	void twoXzoom(Image *img2x);

	void fourXzoom(Image *img4x);

	void getImageInfo(char* file, char* filename);

private:
	ReadWrite rw;
};
