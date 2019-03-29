// *************************************

// http://tech-algorithm.com/articles/nearest-neighbor-image-scaling/

// *************************************


#include "ImageZoom.h"


ImageZoom::ImageZoom() : Image()
{
}

ImageZoom::ImageZoom(const unsigned int & _w, const unsigned int & _h, const Rgb & c) : Image(_w, _h, c)
{
}

void ImageZoom::twoXzoom(Image *img2x)
{
	//passing in an image that is twice the size of the usual image

	Image tempImage; 
	tempImage = rw.readPPM("Images/Zoom/zIMG_1.ppm");
	//redaing in image to be zoomed 

	float xRatio = 0.5;
	float yRatio = 0.5;

	float x2;
	float y2;

	for (int i = 0; i < (tempImage.h * 2); i++)
	{
		for (int j = 0; j < (tempImage.w * 2); j++)
		{
			x2 = floor(j * xRatio);
			y2 = floor(i * yRatio);
			img2x->pixels[(i*(tempImage.w * 2)) + j] = tempImage[((y2 * tempImage.w) + x2)];
		}
	}
}

void ImageZoom::fourXzoom(Image *img4x)
{
	Image tempImage;
	tempImage = rw.readPPM("Images/Zoom/zIMG_1.ppm");
	//redaing in image to be zoomed 

	float xRatio = 0.25;
	float yRatio = 0.25;

	float x2;
	float y2;

	for (int i = 0; i < (tempImage.h * 4); i++)
	{
		for (int j = 0; j < (tempImage.w * 4); j++)
		{
			x2 = floor(j * xRatio);
			y2 = floor(i * yRatio);
			img4x->pixels[(i*(tempImage.w * 4)) + j] = tempImage[((y2 * tempImage.w) + x2)];
		}
	}

}

void ImageZoom::getImageInfo(char * file, char * filename)
{
	std::ofstream infoStream;
	infoStream.open("ImageInfo.txt");
	//opening text to be written to

	infoStream << "Image width: " << this->w << "\n";
	infoStream << "Image height: " << this->h << "\n";
	infoStream << "Total pixels: " << this->w * this->h << "\n";
	infoStream << "Filename: " << filename << "\n";
	infoStream << "Colour depth: 24 Bit colour" << "\n";

	std::cout << "Image info written to file THIS IS A ZOOMED IMAGE FUNCTION CALL" << std::endl;

	infoStream.close();
	//closing text file
}
