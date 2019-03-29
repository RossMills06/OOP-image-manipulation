#pragma once

#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

#include "Image.h"
#include "ReadWrite.h"

class ImageBlending : public Image
{
public:
	ImageBlending();

	ImageBlending(const unsigned int &_w, const unsigned int &_h, const Rgb &c = kBlack);


	void MeanBlending(Image *img);

	void MedianBlending(Image *img);

	void SigmaClipping(Image *img);

	void getImageInfo(char* file, char* filename);
	
private:
	ReadWrite rw;
};
