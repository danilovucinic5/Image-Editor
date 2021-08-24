#pragma once
#include <fstream>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "Piksel.h"
#include <string>
using namespace std;

class Pam
{
public:

	
	int height;
	int width;
	string str1="codica";
	int n1;
	string str2="codica";
	int n2;
	uint8_t depth;
	vector<vector<Piksel*>> data;

public:
	Pam(const char* n) {
		//str1 = new string(5);
		//str2 = new string(5);
		read(n);
	}

	void read(const char* name)
	{
		std::ifstream inp{ name, std::ios_base::binary };
		if (inp) {



			uint16_t tmp1;
			inp.read((char*)&tmp1, sizeof(uint16_t));



			if (tmp1 != 0x3750) {
				throw std::runtime_error("Error! Unrecognized file format.");
			}

			for (int i = 1; i <= 7; i++)
			{
				unsigned char tmp;
				inp.read((char*)&tmp, sizeof(unsigned char));

			}

			unsigned char tmp;
			
			inp.read((char*)&tmp, sizeof(unsigned char));
			

			
			int i = 0;
			
			while (tmp != 0x0a)
			{
				str1[i]=tmp;
				i++;
				inp.read((char*)&tmp, sizeof(unsigned char));
				
			}
			
			n1 = i - 1;
			

			width =stoi(str1);

			for (int i = 1; i <= 7; i++)
			{
				unsigned char tmp;
				inp.read((char*)&tmp, sizeof(unsigned char));

			}

			
			
			inp.read((char*)&tmp, sizeof(unsigned char));
			 i = 0;

			 

			 while (tmp != 0x0a)
			 {
				 str2[i] = tmp;
				 i++;
				 inp.read((char*)&tmp, sizeof(unsigned char));

			 }

			 n2 = i - 1;

			 height = stoi(str2);

			
			for (int i = 1; i <= 6; i++)
			{
				unsigned char tmp;
				inp.read((char*)&tmp, sizeof(unsigned char));

			}
			
			inp.read((char*)&tmp, sizeof(unsigned char));

			depth = tmp;

			inp.read((char*)&tmp, sizeof(unsigned char));
			inp.read((char*)&tmp, sizeof(unsigned char));
			while (tmp != 0x0a)
			{
				inp.read((char*)&tmp, sizeof(unsigned char));
			}
			inp.read((char*)&tmp, sizeof(unsigned char));
			while (tmp != 0x0a)
			{
				inp.read((char*)&tmp, sizeof(unsigned char));
			}
			inp.read((char*)&tmp, sizeof(unsigned char));
			while (tmp != 0x0a)
			{
				inp.read((char*)&tmp, sizeof(unsigned char));
			}

			
			vector<Piksel*> vec;


			for (int i = 0; i < height; i++)
			{




				for (int j = 0; j < width; j++)
				{

					

				
					Piksel* tmp = new Piksel
					(0, 0, 0, 0);
					vec.push_back(tmp);
					//data[i][j] = tmp;

				}
				data.push_back(vec);
				vec.erase(vec.begin(), vec.end());
				
			}
			
			

			


			for (int i= height-1; i >=0; i--)
			{
			
				
				for (int j = 0; j <width; j++)
				{
					
					unsigned char b;
					unsigned char g;
					unsigned char r;
					unsigned char a;


					inp.read((char*)&r, sizeof(b));

					inp.read((char*)&g, sizeof(b));

					inp.read((char*)&b, sizeof(b));

					if (depth =='4')
						inp.read((char*)&a, sizeof(b));
					else
						a = 255;
					
					
					data[i][j]->setRed(r);
					data[i][j]->setGreen(g);
					data[i][j]->setBlue(b);
					data[i][j]->setAlpha(a);


				}
				
				//inp.read((char*)&tmp, sizeof(unsigned char));
			}
			


		}


	}

	void write(const char* name)
	{
		std::ofstream of{ name, std::ios_base::binary };
		if (of) {


			unsigned char g = 'P';
			of.write((char*)&g, sizeof(unsigned char));

			g = 0x37;

			of.write((char*)&g, sizeof(unsigned char));

			g = 0x0a;
			of.write((char*)&g, sizeof(unsigned char));

			g = 'W';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'I';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'D';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'T';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'H';
			of.write((char*)&g, sizeof(unsigned char));
			g = 0x20;
			of.write((char*)&g, sizeof(unsigned char));

			int i = 0;

			while (i<=n1)
			{
				g = str1[i];
				of.write((char*)&g, sizeof(unsigned char));
				i++;

			}
			g = 0x0a;
			of.write((char*)&g, sizeof(unsigned char));


			g = 'H';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'E';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'I';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'G';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'H';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'T';
			of.write((char*)&g, sizeof(unsigned char));
			g = 0x20;
			of.write((char*)&g, sizeof(unsigned char));





			 i = 0;

			while (i<=n2)
			{
				g = str2[i];
				of.write((char*)&g, sizeof(unsigned char));
				i++;

			}
			g = 0x0a;
			of.write((char*)&g, sizeof(unsigned char));

			g = 'D';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'E';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'P';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'T';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'H';
			of.write((char*)&g, sizeof(unsigned char));
			g = 0x20;
			of.write((char*)&g, sizeof(unsigned char));

			of.write((char*)&depth, sizeof(unsigned char));
			g = 0x0a;
			of.write((char*)&g, sizeof(unsigned char));


			g = 'M';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'A';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'X';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'V';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'A';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'L';
			of.write((char*)&g, sizeof(unsigned char));
			g = 0x20;
			of.write((char*)&g, sizeof(unsigned char));
			g = 0x32;
			of.write((char*)&g, sizeof(unsigned char));
			g = 0x35;
			of.write((char*)&g, sizeof(unsigned char));
			g = 0x35;
			of.write((char*)&g, sizeof(unsigned char));
			g = 0x0a;
			of.write((char*)&g, sizeof(unsigned char));


			g = 'T';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'U';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'P';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'L';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'T';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'Y';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'P';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'E';
			of.write((char*)&g, sizeof(unsigned char));
			g = 0x20;
			of.write((char*)&g, sizeof(unsigned char));

			g = 'R';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'G';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'B';
			of.write((char*)&g, sizeof(unsigned char));
			if (depth == '4')
			{
				g = '_';
				of.write((char*)&g, sizeof(unsigned char));
				g = 'A';
				of.write((char*)&g, sizeof(unsigned char));
				g = 'L';
				of.write((char*)&g, sizeof(unsigned char));
				g = 'P';
				of.write((char*)&g, sizeof(unsigned char));
				g = 'H';
				of.write((char*)&g, sizeof(unsigned char));
				g = 'A';
				of.write((char*)&g, sizeof(unsigned char));


			}
			g = 0x0a;
			of.write((char*)&g, sizeof(unsigned char));
			g = 'E';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'N';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'D';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'H';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'D';
			of.write((char*)&g, sizeof(unsigned char));
			g = 'R';
			of.write((char*)&g, sizeof(unsigned char));
			g = 0x0a;
			of.write((char*)&g, sizeof(unsigned char));



			for (int i = data.size()-1; i >=0; i--)

			{



				for (int j = 0; j < data[i].size(); j++)
				{
					//*k = *k + 1;

					unsigned char b = data[i][j]->getBlue();
					unsigned char g = data[i][j]->getGreen();
					unsigned char r = data[i][j]->getRed();
					unsigned char a = data[i][j]->getAlpha();


					of.write((char*)&r, sizeof(unsigned char));

					of.write((char*)&g, sizeof(unsigned char));

					of.write((char*)&b, sizeof(unsigned char));

					if (depth =='4')
						of.write((char*)&a, sizeof(unsigned char));

				}
				//g = 0x0a;
				//of.write((char*)&g, sizeof(unsigned char));

			}

		}




	}














};