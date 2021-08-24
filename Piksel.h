#pragma once
#include <iostream>
using namespace std;


class Piksel
{
	int red;
	int blue;
	int green;
	double alpha;

public:Piksel(int red, int blue, int green, int alpha)
{
	this->red = red;
	this->alpha = alpha;
	this->green = green;
	this->blue = blue;
}

	   int getBlue()
	   {
		   return blue;
	   }
	   int getRed()
	   {
		   return red;
	   }
	   int getGreen()
	   {
		   return green;
	   }

	   double getAlpha()
	   {
		   return alpha;
	   }



	   void setBlue(int a)
	   {
		   blue = a;
	   }
	   void setRed(int b)
	   {
		   red = b;
	   }

	   void setGreen(int a)
	   {
		   green = a;
	   }

	   void setAlpha(double a)
	   {
		   alpha=a;
	   }


};
