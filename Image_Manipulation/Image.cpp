#include "Image.h"

Image::Image(const Image &im)
{
	w = im.w;
	h = im.h;
	pixels = new Rgb[im.w * im.h];
	for (int i = 0; i < im.w * im.h; ++i)
		pixels[i] = im.pixels[i];
}

Image::~Image()
{
	if (pixels != NULL)
		delete[] pixels;
}

const Image::Rgb Image::kBlack = Image::Rgb(0);
const Image::Rgb Image::kWhite = Image::Rgb(1);
const Image::Rgb Image::kRed = Image::Rgb(1, 0, 0);
const Image::Rgb Image::kGreen = Image::Rgb(0, 1, 0);
const Image::Rgb Image::kBlue = Image::Rgb(0, 0, 1);

void Image::getImageInfo(char* file, char* filename)
{
	std::ofstream infoStream;
	infoStream.open("ImageInfo.txt");
	//opening text to be written to

	infoStream << "Image width: " << this->w << "\n";
	infoStream << "Image height: " << this->h << "\n";
	infoStream << "Total pixels: " << this->w * this->h << "\n";
	infoStream << "Filename: " << file << "\n";
	infoStream << "Colour depth: 24 Bit colour" << "\n";

	std::cout << "Image info written to file THIS IS A NORMAL IMAGE FUNCTION CALL" << std::endl;

	infoStream.close();
	//closing text file
}