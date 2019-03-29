//main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <cstdio> 
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>

#include "Image.h"
#include "ReadWrite.h"
#include "ImageBlending.h"
#include "ImageZoom.h"

void info(Image& img, char* filename);
//polymorphism

int main()
{
	ReadWrite* rw = new ReadWrite();
	ImageBlending* Blend = new ImageBlending();
	ImageZoom* Zoom = new ImageZoom();
	//creating class objects

	std::clock_t timer;
	double time;

	std::cout << "************************************" << std::endl;

	std::cout << "Image Stacker / Image Scaler" << std::endl;

	std::cout << "************************************" << "\n \n" << std::endl;

	Image *imgMean = new ImageBlending(3264, 2448);
	//creating a new image for mean blending

	Image *imgMedian = new ImageBlending(3264, 2448);
	//cretaing a new image for median blending

	Image *imgSigma = new ImageBlending(3264, 2448);
	//creating a new image for sigma clipping

	Image *img2Zoom = new ImageZoom(750 * 2, 750 * 2);
	//creating a new image for 2X zoom

	Image *img4Zoom = new ImageZoom(750 * 4, 750 * 4);
	//creating a new image for 4x zoom

	std::cout << "1: Mean Blending" << std::endl;
	std::cout << "2: Median blending" << std::endl;
	std::cout << "3: Sigma clipping" << std::endl;
	std::cout << "4: 2X zoom" << std::endl;
	std::cout << "5: 4X zoom" << std::endl;

	char input = ' ';
	std::cin.get(input);

	if (input == '1')
	{
		timer = std::clock();

		Blend->MeanBlending(imgMean);
		//passing the image to MeanBlending function

		time = (std::clock() - timer) / (double)CLOCKS_PER_SEC;
		std::cout << time << " Seconds" << std::endl;

		rw->writePPM(*imgMean, "MeanBlendedPPM.ppm");
		//writing the image that has been returned from the Mean Blending function

		info(*imgMean, "MeanBlendedPPM.ppm");
		//calling info fucntion
	}
	else if (input == '2')
	{
		timer = std::clock();
		Blend->MedianBlending(imgMedian);
		//passing the image to MedianBlending fucntion
		time = (std::clock() - timer) / (double)CLOCKS_PER_SEC;
		std::cout << time << " Seconds" << std::endl;

		rw->writePPM(*imgMedian, "MedianBlended.ppm");
		//writing the image that has been returned by the meadian Blending fucntion

		info(*imgMedian, "MedianBlended.ppm");
		//calling info fucntion
	}
	else if (input == '3')
	{
		timer = std::clock();

		Blend->SigmaClipping(imgSigma);
		//passing the image to SigmaBledning funtion 

		time = (std::clock() - timer) / (double)CLOCKS_PER_SEC;
		std::cout << time << " Seconds" << std::endl;

		rw->writePPM(*imgSigma, "SigmaClipped.ppm");
		//writing the image that has been returned from the Sigma Clipping fucntion

		info(*imgSigma, "SigmaClipped.ppm");
		//calling info fucntion

	}
	else if (input == '4')
	{
		timer = std::clock();

		Zoom->twoXzoom(img2Zoom);
		//passing the image to the 2X zoom funtion

		time = (std::clock() - timer) / (double)CLOCKS_PER_SEC;
		std::cout << time << " Seconds" << std::endl;

		rw->writePPM(*img2Zoom, "2XZoom.ppm");
		//writing the image that has been returned

		info(*img2Zoom, "2XZoom.ppm");
		//calling info fucntion

	}
	else if (input == '5')
	{
		timer = std::clock();

		Zoom->fourXzoom(img4Zoom);
		//passing the image to the 4X zoom funtion

		time = (std::clock() - timer) / (double)CLOCKS_PER_SEC;
		std::cout << time << " Seconds" << std::endl;

		rw->writePPM(*img4Zoom, "4XZoom.ppm");
		//writing the image that has been returned

		info(*img4Zoom, "4XZoom.ppm");
		//calling info fucntion

	}

	delete imgMean;
	imgMean = NULL;
	delete imgMedian;
	imgMedian = NULL;
	delete imgSigma;
	imgSigma = NULL;
	delete img2Zoom;
	img2Zoom = NULL;
	delete img4Zoom;
	img4Zoom = NULL;

	delete rw;
	delete Blend;
	delete Zoom;
	//deleting objects

	system("pause");


	return 0;
}

void info(Image& img, char* filename)
{
	img.getImageInfo("ImageInfo.txt", filename);
	//will change what fucntion is called depending on what Image is passed
}



