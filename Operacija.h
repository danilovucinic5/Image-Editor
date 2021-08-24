#pragma once
#include "Selekcija.h"
#include "Slika.h"
#include <math.h>
#include <algorithm> 


class Operacija
{
protected:vector<Selekcija>& selekcije;
         Slika& slika;
          int k=0;

public:
	Operacija(vector<Selekcija>& sel, Slika& sli):selekcije(sel),slika(sli){}

	virtual void DodajOperaciju(Operacija* o)
	{

	}
	void SetK(int a)
	{                             //slucajno imam ovu i u ostalim operacijama metodu
		k = a;
	}


	virtual void f(vector<vector<Piksel*>>& sl, int i, int j)=0;

	


	virtual void ispis(ofstream& myfile) = 0;  //za ispis u datoteci

	virtual void ispis() = 0;                //ova mi je za ispis u konzoli




	void F()
	{
		bool bl = 0;

		for (Selekcija sel : selekcije)
		{
			if (sel.IsActive())
			{
				bl = 1;
				break;

			}
		}

		if (bl)

		{

			for (Sloj* sloj : slika.VratiSlojeve())
			{
				if (sloj->IsActive())
				{
					for (Selekcija sel : selekcije)
					{
						if (sel.IsActive())
						{

							for (int i = 0; i < sel.Duzina(); i++)
							{

								Oblik o = sel.VratiOblik(i);


								int visina = o.Visina();
								int sirina = o.Sirina();
								int x = o.X();
								int y = o.Y();


								if (x > sloj->Visina() - 1)
								{
									cout << "Pogresna X kordinata u odnosu na sliku";
									exit(2);
								}
								if (y > sloj->Sirina() - 1)
								{
									cout << "Pogresna Y kordinata u odnosu na sliku";
									exit(3);
								}

								if (x + visina > sloj->Visina() - 1)
								{
									cout << "Previsoka selekcija u odnosu na sliku";

									exit(4);
								}

								if (y + visina > sloj->Sirina() - 1)
								{
									cout << "Presiroka selekcija u odnosu na sliku";
									exit(5);

								}



								for (int i = x; i < x + visina; i++)
								{
									for (int j = y; j < y + sirina; j++)
									{
										f(sloj->Slika(), i, j);


										if (sloj->Slika()[i][j]->getBlue() > 255)
											sloj->Slika()[i][j]->setBlue(255);
										if (sloj->Slika()[i][j]->getBlue() < 0)
											sloj->Slika()[i][j]->setBlue(0);

										if (sloj->Slika()[i][j]->getRed() > 255)
											sloj->Slika()[i][j]->setRed(255);
										if (sloj->Slika()[i][j]->getRed() < 0)
											sloj->Slika()[i][j]->setRed(0);

										if (sloj->Slika()[i][j]->getGreen() > 255)
											sloj->Slika()[i][j]->setGreen(255);
										if (sloj->Slika()[i][j]->getGreen() < 0)
											sloj->Slika()[i][j]->setGreen(0);


									}
								}
							}

						}
					}

				}
				
				
			  }


			}
		else
		{
			for (Sloj* sloj : slika.VratiSlojeve())
			{
				if (sloj->IsActive())
				{

					for (int i = 0; i < sloj->Visina(); i++)
					{
						for (int j = 0; j < sloj->Sirina(); j++)
						{
							f(sloj->Slika(), i, j);


							if (sloj->Slika()[i][j]->getBlue() > 255)
								sloj->Slika()[i][j]->setBlue(255);
							if (sloj->Slika()[i][j]->getBlue() < 0)
								sloj->Slika()[i][j]->setBlue(0);

							if (sloj->Slika()[i][j]->getRed() > 255)
								sloj->Slika()[i][j]->setRed(255);
							if (sloj->Slika()[i][j]->getRed() < 0)
								sloj->Slika()[i][j]->setRed(0);

							if (sloj->Slika()[i][j]->getGreen() > 255)
								sloj->Slika()[i][j]->setGreen(255);
							if (sloj->Slika()[i][j]->getGreen() < 0)
								sloj->Slika()[i][j]->setGreen(0);


						}
					}
				}
			}
		}


	}

};

class Sabiranje :public Operacija
{

public:
	Sabiranje(vector<Selekcija>& sel, Slika& sli):Operacija(sel,sli)
	{
		
	}
	void UnesiKonstantu()
	{
	}
	void SetK(int a)
	{
		k = a;
	}
	void ispis(ofstream& myfile)
	{
		myfile << "<Sabiranje><" << k << ">\n";
	}
	void ispis()
	{
		cout << "<Sabiranje><" << k << ">\n";
	}

	void f(vector<vector<Piksel*>>& sl, int i, int j)
	{
		sl[i][j]->setBlue(sl[i][j]->getBlue() + k);
		
		sl[i][j]->setRed(sl[i][j]->getRed() + k);
		
		sl[i][j]->setGreen(sl[i][j]->getGreen() + k);
		
	}


};

class Oduzimanje :public Operacija
{

public:
	Oduzimanje(vector<Selekcija>& sel, Slika& sli) :Operacija(sel, sli)
	{
		
	}

	void SetK(int a)
	{
		k = a;
	}


	void ispis(ofstream& myfile)
	{
		myfile << "<Oduzimanje><"<<k<<">\n";
	}
	void ispis()
	{
		cout << "<Oduzimanje><" << k << ">\n";
	}
	void f(vector<vector<Piksel*>>& sl, int i, int j)
	{
		sl[i][j]->setBlue(sl[i][j]->getBlue() - k);
		sl[i][j]->setRed(sl[i][j]->getRed() - k);
		sl[i][j]->setGreen(sl[i][j]->getGreen() - k);
		

	}


};
class InverznoOduzimanje :public Operacija
{

public:
	InverznoOduzimanje(vector<Selekcija>& sel, Slika& sli) :Operacija(sel, sli)
	{
		
	}


	void ispis(ofstream& myfile)
	{
	myfile << "<InverznoOduzimanje><" << k << ">\n";
}
	void ispis()
	{
		cout<< "<InverznoOduzimanje><" << k << ">\n";
	}
	void f(vector<vector<Piksel*>>& sl, int i, int j)
	{
		sl[i][j]->setBlue(k-sl[i][j]->getBlue());
		sl[i][j]->setRed(k-sl[i][j]->getRed());
		sl[i][j]->setGreen(k-sl[i][j]->getGreen());

	}
	void SetK(int a)
	{
		k = a;
	}

};
class Mnozenje :public Operacija
{

public:
	Mnozenje(vector<Selekcija>& sel, Slika& sli) :Operacija(sel, sli)
	{
		
	}
	void SetK(int a)
	{
		k = a;
	}
	void ispis(ofstream& myfile)
	{
		myfile << "<Mnozenje><" << k << ">\n";
	}
	void ispis()
	{
		cout << "<Mnozenje><" << k << ">\n";
	}

	void f(vector<vector<Piksel*>>& sl, int i, int j)
	{
		sl[i][j]->setBlue(sl[i][j]->getBlue()*k);
		sl[i][j]->setRed( sl[i][j]->getRed()*k);
		sl[i][j]->setGreen(sl[i][j]->getGreen()*k);
		

	}


};
class Deljenje :public Operacija
{

public:
	
 Deljenje(vector<Selekcija>& sel, Slika& sli) :Operacija(sel, sli)
	{
		
	}
 void SetK(int a)
 {
	 k = a;
 }
 void ispis(ofstream& myfile)
 {
	 myfile << "<Deljenje><" << k << ">\n";
 }
 void ispis()
 {
	 cout << "<Deljenje><" << k << ">\n";
 }
	void f(vector<vector<Piksel*>>& sl, int i, int j)
	{
		sl[i][j]->setBlue(sl[i][j]->getBlue()/k);
		sl[i][j]->setRed(sl[i][j]->getRed()/k);
		sl[i][j]->setGreen(sl[i][j]->getGreen()/k);

	}


};


class InverznoDeljenje :public Operacija
{

public:
	
	InverznoDeljenje(vector<Selekcija>& sel, Slika& sli) :Operacija(sel, sli)
	{
		
	}
	void SetK(int a)
	{
		k = a;
	}
	void ispis(ofstream& myfile)
	{
		myfile << "<InverznoDeljenje><" << k << ">\n";
	}
	void ispis()
	{
		cout << "<InverznoDeljenje><" << k << ">\n";
	}


	void f(vector<vector<Piksel*>>& sl, int i, int j)
	{
		if (sl[i][j]->getBlue()!=0)
		sl[i][j]->setBlue( k/sl[i][j]->getBlue() );
		if (sl[i][j]->getRed() != 0)
		sl[i][j]->setRed(k/sl[i][j]->getRed());
		if (sl[i][j]->getGreen() != 0)
		sl[i][j]->setGreen(k/sl[i][j]->getGreen());
		
	}


};



class Stepen :public Operacija
{

public:
	
	Stepen(vector<Selekcija>& sel, Slika& sli) :Operacija(sel, sli)
	{
		
	}
	void SetK(int a)
	{
		k = a;
	}
	void ispis(ofstream& myfile)
	{
		myfile << "<Stepen><" << k << ">\n";
	}
	void ispis()
	{
		cout << "<Stepen><" << k << ">\n";
	}


	void f(vector<vector<Piksel*>>& sl, int i, int j)
	{
		sl[i][j]->setBlue( pow(sl[i][j]->getBlue(),k));
		sl[i][j]->setRed( pow(sl[i][j]->getRed(),k));
		sl[i][j]->setGreen(pow( sl[i][j]->getGreen(),k));
		
	}


};

class Logaritam :public Operacija
{

public:
	Logaritam(vector<Selekcija>& sel, Slika& sli) :Operacija(sel, sli)
	{
		
	}
	void ispis(ofstream& myfile)
	{
		myfile << "<Logaritam>\n";
	}
	void ispis()
	{
		cout << "<Logaritam>\n";
	}
	void SetK(int a)
	{
		k = a;
	}
	void f(vector<vector<Piksel*>>& sl, int i, int j)
	{
		sl[i][j]->setBlue(log(sl[i][j]->getBlue()));
		sl[i][j]->setRed(log(sl[i][j]->getRed()));
		sl[i][j]->setGreen(log(sl[i][j]->getGreen()));
	}


};
class Abs :public Operacija
{

public:
	Abs(vector<Selekcija>& sel, Slika& sli) :Operacija(sel, sli)
	{

	}
	void SetK(int a)
	{
		k = a;
	}
	void ispis(ofstream& myfile)
	{
		myfile << "<Abs>\n";
	}
	void ispis()
	{
		cout << "<Abs>\n";
	}
	void f(vector<vector<Piksel*>>& sl, int i, int j)
	{
		
		if (sl[i][j]->getBlue() < 0)
			sl[i][j]->setBlue(sl[i][j]->getBlue()*(-1));


		if (sl[i][j]->getRed() < 0)
			sl[i][j]->setRed(sl[i][j]->getRed()*(-1));


		if (sl[i][j]->getGreen() < 0)
			sl[i][j]->setGreen(sl[i][j]->getGreen()*(-1));


	}


};



class Min :public Operacija
{

public:
	Min(vector<Selekcija>& sel, Slika& sli) :Operacija(sel, sli)
	{
		
	}
	void ispis(ofstream& myfile)
	{
		myfile << "<Min><" << k << ">\n";
	}
	void ispis()
	{
		cout << "<Min><" << k << ">\n";
	}
	void SetK(int a)
	{
		k = a;
	}
	void f(vector<vector<Piksel*>>& sl, int i, int j)
	{
		if (sl[i][j]->getBlue() < k);
		sl[i][j]->setBlue(k);

		if (sl[i][j]->getRed() < k);
		sl[i][j]->setRed(k);

		if (sl[i][j]->getGreen() < k);
		sl[i][j]->setGreen(k);


	}


};



class Max :public Operacija
{

public:
	Max(vector<Selekcija>& sel, Slika& sli) :Operacija(sel, sli)
	{
		
	}
	void ispis(ofstream& myfile)
	{
		myfile << "<Max><" << k << ">\n";
	}
	void ispis()
	{
		cout<< "<Max><" << k << ">\n";
	}
	void SetK(int a)
	{
		k = a;
	}
	void f(vector<vector<Piksel*>>& sl, int i, int j)
	{
		if (sl[i][j]->getBlue() > k);
		sl[i][j]->setBlue(k);

		if (sl[i][j]->getRed() > k);
		sl[i][j]->setRed(k);

		if (sl[i][j]->getGreen() > k);
		sl[i][j]->setGreen(k);


	}


};


class Inverzija :public Operacija
{

public:
	Inverzija(vector<Selekcija>& sel, Slika& sli) :Operacija(sel, sli)
	{
		
		 k=255;
	}
	void ispis(ofstream& myfile)
	{
		myfile << "<Inverzija>\n";
	}
	void ispis()
	{
		cout << "<Inverzija>\n";
	}
	void SetK(int a)
	{
		k = a;
	}
	void f(vector<vector<Piksel*>>& sl, int i, int j)
	{
		sl[i][j]->setBlue(k - sl[i][j]->getBlue());
		
		sl[i][j]->setRed(k - sl[i][j]->getRed());
	
		sl[i][j]->setGreen(k - sl[i][j]->getGreen());
		

	}


};
class NijanseSive :public Operacija
{

public:
	NijanseSive(vector<Selekcija>& sel, Slika& sli) :Operacija(sel, sli)
	{

		
	}
	void ispis(ofstream& myfile)
	{
		myfile << "<NijanseSive>\n";
	}
	void ispis()
	{
		cout << "<NijanseSive>\n";
	}
	void SetK(int a)
	{
		k = a;
	}
	void f(vector<vector<Piksel*>>& sl, int i, int j)
	{

		int c = (sl[i][j]->getBlue() + sl[i][j]->getRed() + sl[i][j]->getGreen()) / 3;

		sl[i][j]->setBlue(c);
		sl[i][j]->setRed(c);
		sl[i][j]->setGreen(c);


	}


};

class CrnoBela :public Operacija
{

public:
	CrnoBela(vector<Selekcija>& sel, Slika& sli) :Operacija(sel, sli)
	{


	}
	void SetK(int a)
	{
		k = a;
	}
	void ispis(ofstream& myfile)
	{
		myfile << "<CrnoBela>\n";
	}
	void ispis()
	{
		cout << "<CrnoBela>\n";
	}
	void f(vector<vector<Piksel*>>& sl, int i, int j)
	{

		int c = (sl[i][j]->getBlue() + sl[i][j]->getRed() + sl[i][j]->getGreen()) / 3;

		if (c < 127)
		{
			sl[i][j]->setBlue(0);
			sl[i][j]->setRed(0);
			sl[i][j]->setGreen(0);
		}
		else
		{
			sl[i][j]->setBlue(255);
			sl[i][j]->setRed(255);
			sl[i][j]->setGreen(255);

		}



		
	}

};

class Medijana :public Operacija
{

	vector<vector<Piksel*>> nova;

public:
	Medijana(vector<Selekcija>& sel, Slika& sli) :Operacija(sel, sli)
	{
		int visina = sli.Visina();
		int sirina = sli.Sirina();

	
	}
	void SetK(int a)
	{
		k = a;
	}
	void ispis(ofstream& myfile)
	{
		myfile << "<Medijana>\n";
	}
	void ispis()
	{
		cout << "<Medijana>\n";
	}
	void f(vector<vector<Piksel*>>& sl, int i, int j)
	{

		vector<int> red;
		vector<int> blue;
		vector<int> green;

		if (sl.size() - 1 == i)
		{
			if (j == 0)
			{
				red.push_back(sl[i][j]->getRed());
				red.push_back(sl[i][1]->getRed());
				red.push_back(sl[i-1][0]->getRed());


				blue.push_back(sl[i][j]->getBlue());
				blue.push_back(sl[i][1]->getBlue());
				blue.push_back(sl[i - 1][0]->getBlue());


				green.push_back(sl[i][j]->getGreen());
				green.push_back(sl[i][1]->getGreen());
				green.push_back(sl[i - 1][0]->getGreen());


			}
			else if (j == sl[0].size() - 1)
			{
				red.push_back(sl[i][j]->getRed());
				red.push_back(sl[i][j-1]->getRed());
				red.push_back(sl[i - 1][j]->getRed());


				blue.push_back(sl[i][j]->getBlue());
				blue.push_back(sl[i][j-1]->getBlue());
				blue.push_back(sl[i - 1][j]->getBlue());


				green.push_back(sl[i][j]->getGreen());
				green.push_back(sl[i][j-1]->getGreen());
				green.push_back(sl[i - 1][j]->getGreen());


			}
			else
			{

				red.push_back(sl[i][j]->getRed());
				red.push_back(sl[i][j - 1]->getRed());
				red.push_back(sl[i][j + 1]->getRed());
				red.push_back(sl[i - 1][j]->getRed());


				blue.push_back(sl[i][j]->getBlue());
				blue.push_back(sl[i][j - 1]->getBlue());
				blue.push_back(sl[i][j +1]->getBlue());
				blue.push_back(sl[i - 1][j]->getBlue());


				green.push_back(sl[i][j]->getGreen());
				green.push_back(sl[i][j - 1]->getGreen());
				green.push_back(sl[i][j + 1]->getGreen());
				green.push_back(sl[i - 1][j]->getGreen());

			}



				
		}
		else if (i == 0)
		{
			if (j == 0)
			{
				red.push_back(sl[i][j]->getRed());
				red.push_back(sl[i][1]->getRed());
				red.push_back(sl[i + 1][0]->getRed());


				blue.push_back(sl[i][j]->getBlue());
				blue.push_back(sl[i][1]->getBlue());
				blue.push_back(sl[i + 1][0]->getBlue());


				green.push_back(sl[i][j]->getGreen());
				green.push_back(sl[i][1]->getGreen());
				green.push_back(sl[i + 1][0]->getGreen());


			}
			else if (j == sl[0].size() - 1)
			{
				red.push_back(sl[i][j]->getRed());
				red.push_back(sl[i][j - 1]->getRed());
				red.push_back(sl[i + 1][j]->getRed());


				blue.push_back(sl[i][j]->getBlue());
				blue.push_back(sl[i][j - 1]->getBlue());
				blue.push_back(sl[i + 1][j]->getBlue());


				green.push_back(sl[i][j]->getGreen());
				green.push_back(sl[i][j - 1]->getGreen());
				green.push_back(sl[i + 1][j]->getGreen());


			}
			else
			{

				red.push_back(sl[i][j]->getRed());
				red.push_back(sl[i][j - 1]->getRed());
				red.push_back(sl[i][j + 1]->getRed());
				red.push_back(sl[i + 1][j]->getRed());


				blue.push_back(sl[i][j]->getBlue());
				blue.push_back(sl[i][j - 1]->getBlue());
				blue.push_back(sl[i][j + 1]->getBlue());
				blue.push_back(sl[i + 1][j]->getBlue());


				green.push_back(sl[i][j]->getGreen());
				green.push_back(sl[i][j - 1]->getGreen());
				green.push_back(sl[i][j + 1]->getGreen());
				green.push_back(sl[i + 1][j]->getGreen());

			}


		}
		else if (j == 0)
		{

		red.push_back(sl[i][j]->getRed());
		red.push_back(sl[i][j + 1]->getRed());
		red.push_back(sl[i+1][j]->getRed());
		red.push_back(sl[i - 1][j]->getRed());


		blue.push_back(sl[i][j]->getBlue());
		blue.push_back(sl[i][j + 1]->getBlue());
		blue.push_back(sl[i-1][j ]->getBlue());
		blue.push_back(sl[i + 1][j]->getBlue());


		green.push_back(sl[i][j]->getGreen());
		green.push_back(sl[i][j + 1]->getGreen());
		green.push_back(sl[i-1][j ]->getGreen());
		green.push_back(sl[i + 1][j]->getGreen());






         }
		else if (j == sl[0].size() - 1)
		{

		red.push_back(sl[i][j]->getRed());
		red.push_back(sl[i][j - 1]->getRed());
		red.push_back(sl[i + 1][j]->getRed());
		red.push_back(sl[i - 1][j]->getRed());


		blue.push_back(sl[i][j]->getBlue());
		blue.push_back(sl[i][j - 1]->getBlue());
		blue.push_back(sl[i - 1][j]->getBlue());
		blue.push_back(sl[i + 1][j]->getBlue());


		green.push_back(sl[i][j]->getGreen());
		green.push_back(sl[i][j - 1]->getGreen());
		green.push_back(sl[i - 1][j]->getGreen());
		green.push_back(sl[i + 1][j]->getGreen());





         }
		else
		{
		red.push_back(sl[i][j]->getRed());
		red.push_back(sl[i][j - 1]->getRed());
		red.push_back(sl[i + 1][j]->getRed());
		red.push_back(sl[i - 1][j]->getRed());
		red.push_back(sl[i][j + 1]->getRed());


		blue.push_back(sl[i][j]->getBlue());
		blue.push_back(sl[i][j - 1]->getBlue());
		blue.push_back(sl[i - 1][j]->getBlue());
		blue.push_back(sl[i + 1][j]->getBlue());
		blue.push_back(sl[i][j + 1]->getBlue());


		green.push_back(sl[i][j]->getGreen());
		green.push_back(sl[i][j - 1]->getGreen());
		green.push_back(sl[i - 1][j]->getGreen());
		green.push_back(sl[i + 1][j]->getGreen());
		green.push_back(sl[i][j +1]->getGreen());

         }


		if (red.size() == blue.size() && red.size() == green.size() && green.size() == blue.size())      //provera da nije neka greska
		{
		    sort(red.begin(), red.end());
			sort(blue.begin(), blue.end());
			sort(green.begin(), green.end());



			if (red.size() % 2 == 0)
			{
				int pp = (red.size() - 1) / 2;
				int pp1 = pp + 1;

				int r, g, b;


				r = (red[pp] + red[pp1]) / 2;
				b = (blue[pp] + blue[pp1]) / 2;
				g = (green[pp] + green[pp1]) / 2;

				sl[i][j]->setRed(r);
				sl[i][j]->setBlue(b);
				sl[i][j]->setGreen(g);



			}
			else
			{
				
				int pp = (red.size() - 1) / 2;

				sl[i][j]->setRed(red[pp]);
				sl[i][j]->setBlue(blue[pp]);
				sl[i][j]->setGreen(green[pp]);




			}

		}
		else
			cout << endl << "Greska kod medijane";


		




	}

};


class Kompozitna :public Operacija
{
	
	 vector<Operacija*> operacije;

public :
	Kompozitna(vector<Selekcija>& sel, Slika& sli) :Operacija(sel, sli){}

	void DodajOperaciju(Operacija* o)
	{
		operacije.push_back(o);
	}
	void ispis(ofstream& myfile)
	{
		for (Operacija* o : operacije)
			o->ispis(myfile);
	}
	void ispis()
	{
		for (Operacija* o : operacije)
			o->ispis();
	}
	void f(vector<vector<Piksel*>>& sl, int i, int j)
	{

		for (int y = 0; y < operacije.size(); y++)
		{
			operacije[y]->f( sl,  i,  j);
		}


	}

};


