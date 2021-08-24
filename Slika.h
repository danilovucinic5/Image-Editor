#pragma once
#include "Sloj.h"



class Slika
{
	vector<Sloj*> slojevi;
	int visina, sirina;
	BMP b32;
	BMP b24;
	Pam pam;
	vector<vector<Piksel*>> data;
public:
	Slika(BMP& b322, BMP& b244,Pam pamm):b32(b322.file_header, b322.bmp_info_header, b322.bmp_color_header), b24(b244.file_header, b244.bmp_info_header, b244.bmp_color_header),pam(pamm){}
	
	void DodajSloj(Sloj* sloj);


	void NapraviSliku();

	vector<Sloj*>& VratiSlojeve()
	{
		return slojevi;
	}

	void ObrisiSloj()
	{
		int i;

		cout << endl << "Unesite sloj koji zelite da obrisete" << endl;

		cin >> i;
		slojevi.erase(slojevi.begin() + i - 1, slojevi.begin() + i);
	}
	
	int Sirina()
	{
		return sirina;
	}
	int Visina()
	{
		return visina;
	}

	
	
};
