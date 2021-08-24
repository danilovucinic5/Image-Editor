#include "Slika.h"
#include <string>

using namespace std;



void Slika::NapraviSliku()
{
	cout << endl << "Ako zelite BMP sliku pritisnite 1 , za PAM 0" << endl;

	int a;

	cin >> a;

	data.erase(data.begin(), data.end());


	Sloj* tmp = nullptr;
	Sloj* tmp1;

	bool bl = 0;

	for (Sloj* b : slojevi)
	{
		if (b->IsVisible())
		{
			tmp = b;
			bl = 1;
		}
		if (bl)
			break;
	}

	if (!bl)
	{
		cout << "Trenutno nema vidljivih slojeva";
		exit(324);
	}

	vector<Piksel*> vec;



	Piksel* piks;
	int y;
	double p;
	double p1;
	double pp;

	int b, g, r;

	int brojac = 0;
	int i = 0;
	int j = 0;


	for (i = 0; i < visina; i++)
	{


		for (j = 0; j < sirina; j++)
		{



			y = 0;

			b = tmp->Slika()[i][j]->getBlue();
			g = tmp->Slika()[i][j]->getGreen();
			r = tmp->Slika()[i][j]->getRed();
			p = tmp->Slika()[i][j]->getAlpha() / 255.0;



			while (p < 1 && y < slojevi.size())
			{
				while ((!slojevi[y]->IsVisible()) || slojevi[y] == tmp)
				{
					y++;

					if (y == slojevi.size())
						break;
				}

				if (y < slojevi.size()) {
					if (slojevi[y]->IsVisible())
					{

						tmp1 = slojevi[y];


						p1 = tmp1->Slika()[i][j]->getAlpha() / 255.0;

						pp = p + (1 - p)*p1;

						if (pp != 0)
						{
							r = (r * p / pp + tmp1->Slika()[i][j]->getRed() *(1 - p)*p1 / pp);
							b = (b * p / pp + tmp1->Slika()[i][j]->getBlue() *(1 - p)*p1 / pp);
							g = (g * p / pp + tmp1->Slika()[i][j]->getGreen() *(1 - p)*p1 / pp);
							p = pp;






						}

						else
						{
							r = 0;
							b = 0;
							g = 0;
							p = 0;

						}

					}

					y++;
				}
			}

			piks = new Piksel(r, b, g, p * 255);
			vec.push_back(piks);


		}
		data.push_back(vec);
		vec.erase(vec.begin(), vec.end());

	}



	if (a)
	{
		cout << "Za 24 BMP pritnisnite 1 , a za 32 BMP pritnisnite 0" << endl;
		cin >> a;
		if (a)
	{

		b24.data = data;

		int tmp, n;

		n = sirina * 3;
		int i = 0;
		while (n % 4 != 0)
		{
			i++;

			n++;

		}

		int br = sirina * visina + visina * i;
		b24.bmp_info_header.width = sirina;
		b24.bmp_info_header.height = visina;
		tmp = b24.bmp_info_header.size_image;
		b24.bmp_info_header.size_image = br;
		b24.file_header.file_size = b24.file_header.file_size - tmp + br;

		char* c = new char(10);
		cout << "Unesite ime fajla gde zelite da sacuvate sliku" << endl;

		cin >> c;

		b24.write(c);


	}
	else
	{


		b32.data = data;

		int tmp;

		b32.bmp_info_header.width = sirina;
		b32.bmp_info_header.height = visina;
		tmp = b32.bmp_info_header.size_image;
		b32.bmp_info_header.size_image = sirina * visina * 4;
		b32.file_header.file_size = b32.file_header.file_size - tmp + b32.bmp_info_header.size_image;
		char* c = new char(10);
		cout << "Unesite ime fajla gde zelite da sacuvate sliku" << endl;
		cin >> c;
		b32.write(c);

	}

}
	else
	{
		cout << "Ako zelite 24 bitni PAM pritisnite 1,a za 32 bitni pritnisnite 0" << endl;
			cin >> a;
		if
			(a)
		{
			
			pam.depth = '3';

		}
		else
		{
			pam.depth = '4';
		}
		pam.data = data;
		pam.height = visina;
		pam.width = sirina;

		string w = to_string(sirina);


		int i = 0;
		int y = 0;
		while (w[i] != '\0')
		{
			i++;
			y++;
		}

		pam.str1 = w;
		pam.n1 = y - 1;






		string h = to_string(visina);


		i = 0;
		y = 0;
		while (h[i] != '\0')
		{
			i++;
			y++;
		}

		pam.str2 = h;
		pam.n2 = y - 1;


		char* ppp = new char(10);
		cout<<"Unesite ime fajla gde zelite da sacuvate sliku"<<endl;
		cin >> ppp;
		pam.write(ppp);
	}
}








void Slika:: DodajSloj(Sloj* sloj)
{
	if (sloj->Visina() < visina)
	{
		vector<Piksel*> vec;

		for (int i = sloj->Visina(); i < visina; i++)
		{
			for (int j = 0; j < sloj->Sirina(); j++)

			{
				Piksel* p = new Piksel(0, 0, 0, 0);
				vec.push_back(p);
				
			}

			sloj->Slika().push_back(vec);
			
			vec.erase(vec.begin(), vec.end());

		}
		//cout << sloj->Slika().size();

		sloj->SetVisinu(visina);
	}


	if (sloj->Sirina() < sirina)
	{
		vector<Piksel*> vec;



		for (int i = 0; i < sloj->Visina(); i++)
		{
			for (int j = sloj->Sirina(); j < sirina; j++)
			{
				Piksel* p = new Piksel(0, 0, 0, 0);
				sloj->Slika()[i].push_back(p);
			}


		}

		sloj->SetSirinu(sirina);

	}
	if (visina < sloj->Visina())
	{
		int visina1 = sloj->Visina();
		for (Sloj* sloj : slojevi)
		{
			vector<Piksel*> vec;

			for (int i = visina; i < visina1; i++)
			{
				for (int j = 0; j < sirina; j++)
				{
					Piksel* p = new Piksel(0, 0, 0, 0);
					vec.push_back(p);
				}
				sloj->Slika().push_back(vec);
				vec.erase(vec.begin(), vec.end());
			}
			sloj->SetVisinu(visina1);
		}
		visina = visina1;

	}

	if (sirina < sloj->Sirina())
	{
		int sirina1 = sloj->Sirina();
		for (Sloj* sloj : slojevi)
		{

			vector<Piksel*> vec;


			for (int i = 0; i < visina; i++)
			{
				for (int j = sirina; j < sirina1; j++)
				{
					Piksel* p = new Piksel(0, 0, 0, 0);
					sloj->Slika()[i].push_back(p);
				}

				

			}
			sloj->SetSirinu(sirina1);
		}
		sirina = sirina1;

	}


	slojevi.push_back(sloj);
}