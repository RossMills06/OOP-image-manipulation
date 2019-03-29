#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <cstdio> 
#include <string.h>

#include "Image.h"

class ReadWrite
{
public:
	void writePPM(const Image &img, const char* file);

	Image readPPM(const char *filename);
};
