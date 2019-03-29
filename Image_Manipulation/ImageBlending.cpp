#include "ImageBlending.h"

ImageBlending::ImageBlending() : Image()
{
}

ImageBlending::ImageBlending(const unsigned int & _w, const unsigned int & _h, const Rgb & c) : Image(_w, _h, c)
{
}

void ImageBlending::MeanBlending(Image *img)
{
	Image tempImage;
	//creating  atemp image to store values being read in

	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
			tempImage = rw.readPPM("Images/ImageStacker_set1/IMG_1.ppm");
		else if (i == 1)
			tempImage = rw.readPPM("Images/ImageStacker_set1/IMG_2.ppm");
		else if (i == 2)
			tempImage = rw.readPPM("Images/ImageStacker_set1/IMG_3.ppm");
		else if (i == 3)
			tempImage = rw.readPPM("Images/ImageStacker_set1/IMG_4.ppm");
		else if (i == 4)
			tempImage = rw.readPPM("Images/ImageStacker_set1/IMG_5.ppm");
		else if (i == 5)
			tempImage = rw.readPPM("Images/ImageStacker_set1/IMG_6.ppm");
		else if (i == 6)
			tempImage = rw.readPPM("Images/ImageStacker_set1/IMG_7.ppm");
		else if (i == 7)
			tempImage = rw.readPPM("Images/ImageStacker_set1/IMG_8.ppm");
		else if (i == 8)
			tempImage = rw.readPPM("Images/ImageStacker_set1/IMG_9.ppm");
		else if (i == 9)
			tempImage = rw.readPPM("Images/ImageStacker_set1/IMG_10.ppm");
		else if (i == 10)
			tempImage = rw.readPPM("Images/ImageStacker_set1/IMG_11.ppm");
		else if (i == 11)
			tempImage = rw.readPPM("Images/ImageStacker_set1/IMG_12.ppm");
		else if (i == 12)
			tempImage = rw.readPPM("Images/ImageStacker_set1/IMG_13.ppm");

		for (int i = 0; i < img->w * img->h; i++)
		{
			//Add the values from the tempImage to img
			img->pixels[i].r += tempImage.pixels[i].r;
			img->pixels[i].g += tempImage.pixels[i].g;
			img->pixels[i].b += tempImage.pixels[i].b;
		}

		//repeating for all 10 images
	}

	for (int i = 0; i < img->w * img->h; i++)
	{
		img->pixels[i].r /= 13;
		img->pixels[i].g /= 13;
		img->pixels[i].b /= 13;
		//dividing pixel values buy 10 to calculate mean
	}
}

void ImageBlending::MedianBlending(Image *img)
{
	Image img1;
	img1 = rw.readPPM("Images/ImageStacker_set1/IMG_1.ppm");
	Image img2;
	img2 = rw.readPPM("Images/ImageStacker_set1/IMG_2.ppm");
	Image img3;
	img3 = rw.readPPM("Images/ImageStacker_set1/IMG_3.ppm");
	Image img4;
	img4 = rw.readPPM("Images/ImageStacker_set1/IMG_4.ppm");
	Image img5;
	img5 = rw.readPPM("Images/ImageStacker_set1/IMG_5.ppm");
	Image img6;
	img6 = rw.readPPM("Images/ImageStacker_set1/IMG_6.ppm");
	Image img7;
	img7 = rw.readPPM("Images/ImageStacker_set1/IMG_7.ppm");
	Image img8;
	img8 = rw.readPPM("Images/ImageStacker_set1/IMG_8.ppm");
	Image img9;
	img9 = rw.readPPM("Images/ImageStacker_set1/IMG_9.ppm");
	Image img10;
	img10 = rw.readPPM("Images/ImageStacker_set1/IMG_10.ppm");
	Image img11;
	img11 = rw.readPPM("Images/ImageStacker_set1/IMG_11.ppm");
	Image img12;
	img12 = rw.readPPM("Images/ImageStacker_set1/IMG_12.ppm");
	Image img13;
	img13 = rw.readPPM("Images/ImageStacker_set1/IMG_13.ppm");
	//reading in all 13 images to individual objects

	for (int i = 0; i < img1.w * img1.h; i++)
	{
		std::vector<float> containerR;
		std::vector<float> containerG;
		std::vector<float> containerB;
		//creating vectors to store R, G, B for each pixel

		containerR.push_back(img1.pixels[i].r);
		containerR.push_back(img2.pixels[i].r);
		containerR.push_back(img3.pixels[i].r);
		containerR.push_back(img4.pixels[i].r);
		containerR.push_back(img5.pixels[i].r);
		containerR.push_back(img6.pixels[i].r);
		containerR.push_back(img7.pixels[i].r);
		containerR.push_back(img8.pixels[i].r);
		containerR.push_back(img9.pixels[i].r);
		containerR.push_back(img10.pixels[i].r);
		containerR.push_back(img11.pixels[i].r);
		containerR.push_back(img12.pixels[i].r);
		containerR.push_back(img13.pixels[i].r);
		//storing individual R values for one pixel across the 13 images

		containerG.push_back(img1.pixels[i].g);
		containerG.push_back(img2.pixels[i].g);
		containerG.push_back(img3.pixels[i].g);
		containerG.push_back(img4.pixels[i].g);
		containerG.push_back(img5.pixels[i].g);
		containerG.push_back(img6.pixels[i].g);
		containerG.push_back(img7.pixels[i].g);
		containerG.push_back(img8.pixels[i].g);
		containerG.push_back(img9.pixels[i].g);
		containerG.push_back(img10.pixels[i].g);
		containerG.push_back(img11.pixels[i].g);
		containerG.push_back(img12.pixels[i].g);
		containerG.push_back(img13.pixels[i].g);
		//storing individual G values for one pixel across the 13 images

		containerB.push_back(img1.pixels[i].b);
		containerB.push_back(img2.pixels[i].b);
		containerB.push_back(img3.pixels[i].b);
		containerB.push_back(img4.pixels[i].b);
		containerB.push_back(img5.pixels[i].b);
		containerB.push_back(img6.pixels[i].b);
		containerB.push_back(img7.pixels[i].b);
		containerB.push_back(img8.pixels[i].b);
		containerB.push_back(img9.pixels[i].b);
		containerB.push_back(img10.pixels[i].b);
		containerB.push_back(img11.pixels[i].b);
		containerB.push_back(img12.pixels[i].b);
		containerB.push_back(img13.pixels[i].b);
		//storing individual B values for one pixel across the 13 images

		std::sort(containerR.begin(), containerR.end());
		std::sort(containerG.begin(), containerG.end());
		std::sort(containerB.begin(), containerB.end());
		//soritng the vectors 

		img->pixels[i].r = containerR[6];
		img->pixels[i].g = containerG[6];
		img->pixels[i].b = containerB[6];
		//taking the middle (median) value 

	}

}

void ImageBlending::SigmaClipping(Image * img)
{
	Image img1;
	img1 = rw.readPPM("Images/ImageStacker_set1/IMG_1.ppm");
	Image img2;
	img2 = rw.readPPM("Images/ImageStacker_set1/IMG_2.ppm");
	Image img3;
	img3 = rw.readPPM("Images/ImageStacker_set1/IMG_3.ppm");
	Image img4;
	img4 = rw.readPPM("Images/ImageStacker_set1/IMG_4.ppm");
	Image img5;
	img5 = rw.readPPM("Images/ImageStacker_set1/IMG_5.ppm");
	Image img6;
	img6 = rw.readPPM("Images/ImageStacker_set1/IMG_6.ppm");
	Image img7;
	img7 = rw.readPPM("Images/ImageStacker_set1/IMG_7.ppm");
	Image img8;
	img8 = rw.readPPM("Images/ImageStacker_set1/IMG_8.ppm");
	Image img9;
	img9 = rw.readPPM("Images/ImageStacker_set1/IMG_9.ppm");
	Image img10;
	img10 = rw.readPPM("Images/ImageStacker_set1/IMG_10.ppm");
	Image img11;
	img11 = rw.readPPM("Images/ImageStacker_set1/IMG_11.ppm");
	Image img12;
	img12 = rw.readPPM("Images/ImageStacker_set1/IMG_12.ppm");
	Image img13;
	img13 = rw.readPPM("Images/ImageStacker_set1/IMG_13.ppm");
	//reading in all 13 images to individual objects

	for (int i = 0; i < (img1.w * img1.h); i++)
	{
		std::vector<float> containerR;
		std::vector<float> containerG;
		std::vector<float> containerB;
		//creating vectors to store R, G, B for each pixel

		containerR.push_back(img1.pixels[i].r);
		containerR.push_back(img2.pixels[i].r);
		containerR.push_back(img3.pixels[i].r);
		containerR.push_back(img4.pixels[i].r);
		containerR.push_back(img5.pixels[i].r);
		containerR.push_back(img6.pixels[i].r);
		containerR.push_back(img7.pixels[i].r);
		containerR.push_back(img8.pixels[i].r);
		containerR.push_back(img9.pixels[i].r);
		containerR.push_back(img10.pixels[i].r);
		containerR.push_back(img11.pixels[i].r);
		containerR.push_back(img12.pixels[i].r);
		containerR.push_back(img13.pixels[i].r);
		//storing individual R values for one pixel across the 13 images

		containerG.push_back(img1.pixels[i].g);
		containerG.push_back(img2.pixels[i].g);
		containerG.push_back(img3.pixels[i].g);
		containerG.push_back(img4.pixels[i].g);
		containerG.push_back(img5.pixels[i].g);
		containerG.push_back(img6.pixels[i].g);
		containerG.push_back(img7.pixels[i].g);
		containerG.push_back(img8.pixels[i].g);
		containerG.push_back(img9.pixels[i].g);
		containerG.push_back(img10.pixels[i].g);
		containerG.push_back(img11.pixels[i].g);
		containerG.push_back(img12.pixels[i].g);
		containerG.push_back(img13.pixels[i].g);
		//storing individual G values for one pixel across the 13 images

		containerB.push_back(img1.pixels[i].b);
		containerB.push_back(img2.pixels[i].b);
		containerB.push_back(img3.pixels[i].b);
		containerB.push_back(img4.pixels[i].b);
		containerB.push_back(img5.pixels[i].b);
		containerB.push_back(img6.pixels[i].b);
		containerB.push_back(img7.pixels[i].b);
		containerB.push_back(img8.pixels[i].b);
		containerB.push_back(img9.pixels[i].b);
		containerB.push_back(img10.pixels[i].b);
		containerB.push_back(img11.pixels[i].b);
		containerB.push_back(img12.pixels[i].b);
		containerB.push_back(img13.pixels[i].b);
		//storing individual B values for one pixel across the 13 images

		float totalR = 0, totalG = 0, totalB = 0;
		float meanR = 0, meanG = 0, meanB = 0;

		for (int i = 0; i < 13; i++)
		{
			totalR = totalR + containerR[i];
			totalG = totalG + containerG[i];
			totalB = totalB + containerB[i];
		}
		//adding up all R, G, B values

		meanR = totalR / 13;
		meanG = totalG / 13;
		meanB = totalB / 13;
		//calculating mean of R, G, B values

		float totalDeviationSquaredR = 0;
		float totalDeviationSquaredG = 0;
		float totalDeviationSquaredB = 0;

		for (int i = 0; i < 13; i++)
		{
			totalDeviationSquaredR += ((containerR[i] - meanR) * (containerR[i] - meanR));
			totalDeviationSquaredG += ((containerG[i] - meanG) * (containerG[i] - meanG));
			totalDeviationSquaredB += ((containerB[i] - meanB) * (containerB[i] - meanB));
		}
		//calculating total deviations 

		float standardDeviationR = 0;
		float standardDeviationG = 0;
		float standardDeviationB = 0;

		standardDeviationR = totalDeviationSquaredR / 13;
		standardDeviationR = sqrt(totalDeviationSquaredR);

		standardDeviationG = totalDeviationSquaredG / 13;
		standardDeviationG = sqrt(totalDeviationSquaredG);

		standardDeviationB = totalDeviationSquaredB / 13;
		standardDeviationB = sqrt(totalDeviationSquaredB);	
		//calcultation individual standard deviations

		float minValueR = 0, maxValueR = 0;
		float minValueG = 0, maxValueG = 0;
		float minValueB = 0, maxValueB = 0;

		float sigmaValue = 0.25;

		minValueR = meanR - (sigmaValue * standardDeviationR);
		maxValueR = meanR + (sigmaValue * standardDeviationR);

		minValueG = meanG - (sigmaValue * standardDeviationG);
		maxValueG = meanG + (sigmaValue * standardDeviationG);

		minValueB = meanB - (sigmaValue * standardDeviationB);
		maxValueB = meanB + (sigmaValue * standardDeviationB);

		std::vector<float> clippedR;
		std::vector<float> clippedG;
		std::vector<float> clippedB;

		for (int i = 0; i < 13; i++)
		{
			if ((containerR[i] >= minValueR) && (containerR[i] <= maxValueR))
			{
				clippedR.push_back(containerR[i]);
			}
			//adding elements to the new vector if they are within the requirements

			if ((containerG[i] >= minValueG) && (containerG[i] <= maxValueG))
			{
				clippedG.push_back(containerG[i]);
			}
			//adding elements to the new vector if they are within the requirements

			if ((containerB[i] >= minValueB) && (containerB[i] <= maxValueB))
			{
				clippedB.push_back(containerB[i]);
			}
			//adding elements to the new vector if they are within the requirements
		}

		float totalClippedR = 0;
		float totalClippedG = 0;
		float totalClippedB = 0;

		for (int i = 0; i < clippedR.size(); i++)
		{
			totalClippedR += clippedR[i];
		}
		//totalling the values for the cipped R values

		for (int i = 0; i < clippedG.size(); i++)
		{
			totalClippedG += clippedG[i];
		}
		//totalling the values for the cipped G values

		for (int i = 0; i < clippedB.size(); i++)
		{
			totalClippedB += clippedB[i];
		}
		//totalling the values for the cipped B values

		img->pixels[i].r = (totalClippedR / clippedR.size());
		img->pixels[i].g = (totalClippedG / clippedG.size());
		img->pixels[i].b = (totalClippedB / clippedB.size());
		//calculating mean for the clipped values

	}

}


void ImageBlending::getImageInfo(char* file, char* filename)
{
	std::ofstream infoStream;
	infoStream.open("ImageInfo.txt");
	//opening text to be written to

	infoStream << "Image width: " << this->w << "\n";
	infoStream << "Image height: " << this->h << "\n";
	infoStream << "Total pixels: " << this->w * this->h << "\n";
	infoStream << "Filename: " << filename << "\n";
	infoStream << "Colour depth: 24 Bit colour" << "\n";

	std::cout << "Image info written to file THIS IS A BLENDED IMAGE FUNCTION CALL" << std::endl;

	infoStream.close();
	//closing text file
}