
#pragma once
#include <fstream>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "Piksel.h"
using namespace std;

#pragma pack(push, 1)
struct BMPFileHeader {
	uint16_t file_type{ 0x4D42 };        
	uint32_t file_size{ 0 };               
	uint16_t reserved1{ 0 };               
	uint16_t reserved2{ 0 };              
	uint32_t offset_data{ 0 };             
};

struct BMPInfoHeader {
	uint32_t size{ 0 };                      
	int32_t width{ 0 };                      
	int32_t height{ 0 };                    
											 
	uint16_t planes{ 1 };                   
	uint16_t bit_count{ 0 };                
	uint32_t compression{ 0 };              
	uint32_t size_image{ 0 };               
	int32_t x_pixels_per_meter{ 0 };
	int32_t y_pixels_per_meter{ 0 };
	uint32_t colors_used{ 0 };              
	uint32_t colors_important{ 0 };         
};

struct BMPColorHeader {
	uint32_t red_mask{ 0x00ff0000 };         
	uint32_t green_mask{ 0x0000ff00 };       
	uint32_t blue_mask{ 0x000000ff };       
	uint32_t alpha_mask{ 0xff000000 };       
	uint32_t color_space_type{ 0x73524742 }; 
	uint32_t unused[16]{ 0 };                
};
#pragma pack(pop)

struct BMP {
	BMPFileHeader file_header;
	BMPInfoHeader bmp_info_header;
	BMPColorHeader bmp_color_header;
	vector<vector<Piksel*>> data;
	

	BMP(const char *fname) {
		read(fname);
	}

	BMP(BMPFileHeader fh, BMPInfoHeader ih, BMPColorHeader ch)
	{
		file_header = fh;
		bmp_info_header = ih;
		bmp_color_header = ch;

	}

	void read(const char *fname) {
		std::ifstream inp{ fname, std::ios_base::binary };
		if (inp) {
			inp.read((char*)&file_header, sizeof(file_header));
			if (file_header.file_type != 0x4D42) {
				throw std::runtime_error("Error! Unrecognized file format.");
			}
			inp.read((char*)&bmp_info_header, sizeof(bmp_info_header));
			if (bmp_info_header.bit_count == 32 ||(bmp_info_header.bit_count == 24 && ((bmp_info_header.width*3)%4==0)))
			{
				
				if (bmp_info_header.bit_count == 32)
				inp.read((char*)&bmp_color_header, sizeof(bmp_color_header));
//				int*k = new int(0);
				inp.seekg(file_header.offset_data, inp.beg);




				



				vector<Piksel*> vec;


				for (int i = 0; i < bmp_info_header.height; i++)
				{
					if (i > 0) {

						data.push_back(vec);
						vec.erase(vec.begin(), vec.end());
						
						
					}
					for (int j = 0; j < bmp_info_header.width; j++)
					{
						//*k = *k + 1;
						unsigned char b;
						unsigned char g;
						unsigned char r;
						unsigned char a;


						inp.read((char*)&b, sizeof(b));

						inp.read((char*)&g, sizeof(b));

						inp.read((char*)&r, sizeof(b));

						if (bmp_info_header.bit_count == 32)
							inp.read((char*)&a, sizeof(b));
						else
							a = 255;
						Piksel* tmp = new Piksel
						(r, b, g, a);
						vec.push_back(tmp);
						//data[i][j] = tmp;

					}
				}
				data.push_back(vec);
				//cout << *k;

			}
			else if
				(bmp_info_header.bit_count == 24 && ((bmp_info_header.width * 3) % 4 != 0)){


				inp.seekg(file_header.offset_data, inp.beg);

				vector<Piksel*> vec;
				int n = bmp_info_header.width * 3;
				

				
				for (int i = 0; i < bmp_info_header.height; i++)
				{
					if (i > 0) {

						data.push_back(vec);
						vec.erase(vec.begin(), vec.end());
						while (n % 4 != 0)
						{
							unsigned char g;
							inp.read((char*)&g, sizeof(unsigned char ));
							n++;
							
						}
						n = bmp_info_header.width * 3;

					}
					for (int j = 0; j < bmp_info_header.width; j++)
					{
						unsigned char b;
						unsigned char g;
						unsigned char r;
						unsigned char a;
						


						inp.read((char*)&b, sizeof(b));

						inp.read((char*)&g, sizeof(b));

						inp.read((char*)&r, sizeof(b));

						
							a = 255;
						Piksel* tmp = new Piksel
						(r, b, g, a);
						vec.push_back(tmp);
						//data[i][j] = tmp;

					}
				}

				data.push_back(vec);

				while (n % 4 != 0)
				{
					unsigned char g;
					inp.read((char*)&g, sizeof(g));
					n++;

				}



		}

		}

	}



	void write(const char *fname) {
		std::ofstream of{ fname, std::ios_base::binary };
		if (of) {
			if (bmp_info_header.bit_count == 32) {
				write_headers_and_data(of);
			}
			else if (bmp_info_header.bit_count == 24) {
				if (bmp_info_header.width*3 % 4 == 0) {
					write_headers_and_data(of);


				}
				else {
					
					int *l = new int(0);

					write_headers(of);
					int n = bmp_info_header.width * 3;

					for (int i = 0; i < data.size(); i++)

					{
						if (i > 0)
						{
							while (n++ % 4 != 0)
							{
								unsigned char g = 0x00;
								of.write((char*)&g, sizeof(unsigned char));
								*l++;

							}
							n = bmp_info_header.width * 3;
						}
						for (int j = 0; j < data[i].size(); j++)
						{

							int b = data[i][j]->getBlue();
							int g = data[i][j]->getGreen();
							int r = data[i][j]->getRed();
							


							of.write((char*)&b, sizeof(unsigned char));

							of.write((char*)&g, sizeof(unsigned char));

							of.write((char*)&r, sizeof(unsigned char));

							

						}
					}
					
					n = bmp_info_header.width * 3;
					while (n % 4 != 0)
					{
						unsigned char g = 0x00;
						of.write((char*)&g, sizeof(unsigned char));
						n++;
						*l++;
					}
					
					

					//cout << *l;






					
				}
			}
			else {
				throw std::runtime_error("The program can treat only 24 or 32 bits per pixel BMP files");
			}
		}
		else {
			throw std::runtime_error("Unable to open the output image file.");
		}
	}


	private:
		

		void write_headers(std::ofstream &of) {
			of.write((const char*)&file_header, sizeof(file_header));
			of.write((const char*)&bmp_info_header, sizeof(bmp_info_header));
			if (bmp_info_header.bit_count == 32) {
				of.write((const char*)&bmp_color_header, sizeof(bmp_color_header));
			}
		}

		void write_headers_and_data(std::ofstream &of) {
			write_headers(of);


			of.seekp(file_header.offset_data, of.beg);

			//int n = bmp_info_header.height*bmp_info_header.width;
			
			//int* k = new int(0);
			
			
			
			for (int i = 0; i < data.size(); i++)

			{

				for (int j = 0; j < data[i].size(); j++)
				{
					//*k = *k + 1;

					unsigned char b = data[i][j]->getBlue();
					unsigned char g = data[i][j]->getGreen();
					unsigned char r = data[i][j]->getRed();
					unsigned char a = data[i][j]->getAlpha();
					

					of.write((char*)&b, sizeof(unsigned char));

					of.write((char*)&g, sizeof(unsigned char));

					of.write((char*)&r, sizeof(unsigned char));

					if (bmp_info_header.bit_count == 32)
						of.write((char*)&a, sizeof(unsigned char));

				}
			}
			
			//cout << *k;



			
		}

		
	





};