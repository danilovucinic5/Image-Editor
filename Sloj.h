#pragma once

#include "Piksel.h"
#include "BmpImage.h"
#include "PAM.h"
class Sloj
{


	vector<vector<Piksel*>> data;
	int sirina, visina;
	int active, visible;
	int prozirnost;
public:

	Sloj(int s,int v, int p) {
		prozirnost = p;
		vector<vector<Piksel*>> v1;
		vector<Piksel*> v2;
		sirina = s;
		visina = v;
		for (int i = 0; i < v; i++)
		{
			
			for (int j = 0; j < s; j++)
			{
				Piksel* p = new Piksel(0, 0, 0, 0);
				v2.push_back(p);
			}
			v1.push_back(v2);
			v2.erase(v2.begin(), v2.end());
		}
		data = v1;

		active = 1;
		visible = 1;

	}
	Sloj(vector<vector<Piksel*>> v1, int p)
	{
		data = v1;
		prozirnost = p;
	}

	Sloj(BMP* bmp,int p)
	{
		if (p < 0 || p>100)
		{
			cout << "Pogresan izbor prozirnosti(mora biti 0-100)";
			exit(256);
		}

		prozirnost = p;
		data = bmp->data;
		for (int i = 0; i < data.size(); i++)
		{
			for (int j = 0; j < data[i].size(); j++)
			{
				data[i][j]->setAlpha ( data[i][j]->getAlpha()*p / 100.0);
			}
		}
		sirina=bmp->bmp_info_header.width;
		visina = bmp->bmp_info_header.height;
		active = 1;
		visible = 1;
	}

	Sloj(Pam* pam, int p)
	{
		if (p < 0 || p>100)
		{
			cout << "Pogresan izbor prozirnosti(mora biti 0-100)";
			exit(256);
		}

		prozirnost = p;
		data = pam->data;
		for (int i = 0; i < data.size(); i++)
		{
			for (int j = 0; j < data[i].size(); j++)
			{
				data[i][j]->setAlpha(data[i][j]->getAlpha()*p / 100.0);
			}
		}
		sirina = pam->width;
		visina = pam->height;
		active = 1;
		visible = 1;
	}
	void SetNovuProzirnost(int a)
	{
		for (int i = 0; i < data.size(); i++)
		{
			for (int j = 0; j < data[i].size(); j++)
			{
				data[i][j]->setAlpha(data[i][j]->getAlpha()* a / prozirnost);
			}

		}
		this->SetProzirnost(a);

	}

	vector<vector<Piksel*>>& Slika()
	{
		return data;
	}

	bool IsActive()
	{
		return active;
	}
	bool IsVisible()
	{
		return visible;
	}

	int Prozirnost()
	{
		return prozirnost;
	}
	int Visina()
	{
		return visina;
	}
	int Sirina()
	{
		return sirina;
	}
	void SetVisinu(int i)
	{
		visina = i;
	}
	void SetSirinu(int i)
	{
		sirina = i;
	}

	void SetVisible(bool a)
	{
		visible = a;
	}
	void SetActivity(bool a)
	{
		active = a;
	}
	void SetProzirnost(int a)
	{
		 prozirnost=a;
	}






};
