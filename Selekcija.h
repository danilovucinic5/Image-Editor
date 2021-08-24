#pragma once
#include "BmpImage.h"
#include "Sloj.h"





class Oblik
{
	int lenght;
	int width;
	int x;
	int y;



public:
		Oblik(int sirina,int visina,int xx,int yy):lenght(visina),width(sirina),x(xx),y(yy){}

		int Visina() {
			return lenght;
		}

		int Sirina()
		{
			return width;
		}
		int X()
		{
			return x;
		}
		int Y()
		{
			return y;
		}

};

class Selekcija
{
	vector<Oblik> oblici;
	
	bool active;

public:
	Selekcija(vector<Oblik> a):oblici(a),active(true){}

	void Aktiviraj()
	{
		active = 1;
	 }
	void Deaktiviraj()
	{
		active = 0;
	}

	int Duzina()
	{
		return oblici.size();
	}

	bool IsActive()
	{
		return active;
	}

	Oblik VratiOblik(int i)
	{
		return oblici[i];
	}

	void oboj(Sloj* b)
	{
		
		if (IsActive())
		{
			cout <<endl<< "Ako zelite da obojite u crveno pritisnite 0,plavo 1,zeleno 2,belo 3,crno 4";
			int pp;

			cin >> pp;

			int bb, g, r;

			if (pp == 0)
			{
				r = 255;
				bb = 0;
				g = 0;
			}
			if (pp == 1)
			{
				r = 0;
				bb = 255;
				g = 0;
			}
			if (pp == 2)
			{
				r = 0;
				bb = 0;
				g = 255;
			}
			if (pp == 4)
			{
				r = 0;
				bb = 0;
				g = 0;
			}
			if (pp == 3)
			{
				r = 255;
				bb = 255;
				g = 255;
			}
			for (int i = 0; i < Duzina(); i++)
			{

				Oblik o = VratiOblik(i);


				int visina = o.Visina();
				int sirina = o.Sirina();
				int x = o.X();
				int y = o.Y();


				if (x > b->Visina() - 1)
				{
					cout << "Pogresna X kordinata u odnosu na sliku";
					exit(2);
				}
				if (y > b->Sirina() - 1)
				{
					cout << "Pogresna Y kordinata u odnosu na sliku";
					exit(3);
				}

				if (x + visina > b->Visina() - 1)
				{
					cout << "Previsoka selekcija u odnosu na sliku";

					exit(4);
				}

				if (y + visina > b->Sirina() - 1)
				{
					cout << "Presiroka selekcija u odnosu na sliku";
					exit(5);

				}
				


				for (int i = x; i < x + visina; i++)
				{
					for (int j = y; j < y + sirina; j++)
					{
						b->Slika()[i][j]->setBlue(bb);
						b->Slika()[i][j]->setGreen(g);
						b->Slika()[i][j]->setRed(r);

					}
				}
			}

		}
		else cout <<endl<< "Selekcija nije aktivna";



	}














};

