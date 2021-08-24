#include "BmpImage.h"
#include <iomanip>
#include "Slika.h"
#include <cmath>>
#include "Selekcija.h"
#include "Operacija.h"
#include "PAM.h"
#include <string>
#include <regex>

/*   

class A
{
public:
	virtual void ispis(ofstream& myfile) = 0;

};


class B :public A
{
public:
	void ispis(ofstream& myfile)
	{

		//myfile.open("fun.txt");
		myfile << "<Sabiranje><10>.\n";

	}
	//myfile.close();
};

	class C :public A
	{
	public:
		void ispis(ofstream& myfile)
		{
			
			//myfile.open("fun.txt");
			myfile << "<Oduzimanje><10>.\n";
			//myfile.close();
		}
	};
	class D :public A
	{
	public:
		void ispis(ofstream& myfile)
		{

			//myfile.open("fun.txt");
			myfile << "<Mnozenje><10>.\n";
			//myfile.close();
		}
	};


	class E :public A
	{
	private:

		vector<A*> vec;

	public:
		void ispis(ofstream& myfile)
		{
			myfile << "<Kompozitna>.\n";

			for (A* a : vec)

				a->ispis(myfile);
			myfile << "<KrajKompozitne>.\n";

		}
		void DodajElem(A* pok)
		{
			vec.push_back(pok);
		}


	};

	*/

int main()
{
	/*
	B* b = new B();
	C* c = new C();
	D* d = new D();

	E* e = new E();
	ofstream myfile;
	myfile.open("fun.txt");

	e->DodajElem(b);
	e->DodajElem(c);
	e->DodajElem(d);

	e->ispis(myfile);
	myfile.close();

	*/




	Pam pam("300.pam");

	//pam.write("cokilo.pam");



	BMP a("coda.bmp");




	//Oblik o(50, 50, 0, 0);
	//Oblik o1(25, 25, 150, 150);
	//Oblik bbb(30, 20, 50, 50);
	//Oblik a123(60, 60, 100, 100);


	//vector<Oblik> vektor;
	//vector<Oblik> vektor1;

	//vektor1.push_back(o1);
	//vektor1.push_back(bbb);

	//vektor.push_back(o);
	//vektor.push_back(a123);
	//const char* cc = "coda";
	//const char* cd = "cod";


	//Selekcija ba( vektor);
	//Selekcija bb( vektor1);

	vector<Selekcija> vc;



	//cout << a.data[0][0]->getGreen();


	//vc.push_back(ba);

	//vc.push_back(bb);



	BMP b("coda32.bmp");



	Slika slika(b, a, pam);


	//BMP* c=new BMP("300.bmp");
	//BMP* p = new BMP("bbb.bmp");
	//BMP* v = new BMP("dicaa.bmp");
	//BMP* g = new BMP("resi.bmp");
	//BMP* gg = new BMP("ff.bmp");


	//Sloj* prvi = new Sloj(c,100);


	//v->write("c.bmp");




	//ba.oboj(prvi);


	//Sloj* peti = new Sloj(g,50);



	//Sloj* drugi = new Sloj(p,30);

	//Sloj* treci = new Sloj(500,600,35);

	//Sloj* cetvrti = new Sloj(v,100);
	//Sloj* treci = new Sloj(gg, 50);


	//slika.DodajSloj(peti);
	//slika.DodajSloj(prvi);
	//slika.DodajSloj(cetvrti);







	//Operacija* operacija = new Kompozitna(vc, slika);
	//Operacija* oduzmi = new Oduzimanje(vc, slika);
	//Operacija* pomnozi = new Mnozenje(vc, slika);
	//Operacija* stepen = new Stepen(vc, slika);

	//Operacija* medijana = new Medijana(vc, slika);


	//operacija->DodajOperaciju(oduzmi);
	//operacija->DodajOperaciju(pomnozi);

	//operacija->DodajOperaciju(medijana);


	//oduzmi->DodajOperaciju(stepen);



	//operacija->F();



	//Oduzimanje* pppg = new Oduzimanje(vc, slika);

	//oduzmi->DodajOperaciju(pppg);






	//slika.DodajSloj(drugi);



	//slika.ObrisiSloj();
	vector<Piksel*> vektorr;
	vector<vector<Piksel*>> vecc;


	//slika.DodajSloj(treci);


	//slika.NapraviSliku();
	int sirina, visina;
	vector<Oblik> vektor;
	Selekcija ba(vektor);
	Operacija* op1;
	Operacija* op;
	Kompozitna* kop = nullptr;
	BMP* c;
	int p, konst,br;
	Sloj* prvi;
	char* ime = new char(15);
	ofstream myfile;
	ifstream ulaz;
	string str;
	regex rg("<([^>]*)><([^>]*)>");
	regex rx("<([^>]*)><([^>]*)><([^>]*)><([^>]*)>");
	regex re("<([^>]*)><([^>]*)><([^>]*)>");
	smatch sm;
	smatch sm1;
	smatch sm2;
	//cout << endl << cetvrti->Slika()[0][0]->getBlue();
	//cout << endl << cetvrti->Slika()[0][0]->getGreen();
	//cout << endl << cetvrti->Slika()[0][0]->getRed();

	int choice;

	do
	{


		cout << endl
			<< " 1 - Dodaj sloj.\n"
			<< " 2 - Dekativiraj sloj \n"
			<< " 3 - Aktiviriaj sloj \n"
			<< " 4 - Podesi prozirnost sloja \n"
			<< " 5 - Ucini sloj vidljivim  \n"
			<< " 6 - Ucini sloj nevidljivim \n"
			<< " 7 - Obrisi sloj \n"
			<< " 8 - Dodaj selekciju\n"
			<< " 9 - Aktiviraj selekciju\n"
			<< " 10 - Deaktiviraj selekciju\n"
			<< " 11 - Oboj selekciju sloja\n"
			<< " 12 - Obrisi selekciju \n"
			<< " 13 - Operacija \n"
			<< " 14 - Ispisi sliku\n"
			<< " 15 - Upisi kompozitnu u fajl\n"               
			<< " 16 - Unesi kompozitnu iz fajla\n"
			<< " 17 - Ispisi kompozitnu \n"
			<< " 18 - Sacuvaj sliku u fajl \n"
			<< " 19 - Upisi sliku u program \n"
			<< " 20 - Exit \n"
			<< " Unesite vas izbor \n: ";

		cin >> choice;

		switch (choice)

		{
		case 1:
			int b;
			cout << "Ako zelite da dodate sliku pritisnite 1, za prazan sloj pritisnite 0" << endl;
			cin >> b;
			if (b)
			{

				cout << "Unesite ime slike" << endl;
				cin >> ime;

				cout << "Unesite prozirnost sloja" << endl;
				cin >> p;


				cout << "Ako unosite BMP format pritisnite 1, u suprotnom 0" << endl;

				cin >> b;
				if (b)
				{




					slika.DodajSloj(new Sloj(new BMP(ime), p));
				}
				else
				{
					slika.DodajSloj(new Sloj(new Pam(ime), p));
				}

			}
			else
			{
				int sir, vis, p;
				cout << "Unesite sirinu sloja" << endl;
				cin >> sir;
				cout << "Unesite visinu sloja" << endl;
				cin >> vis;
				cout << "Unesite prozirnost sloja" << endl;
				cin >> p;


				prvi = new Sloj(sir, vis, p);
				slika.DodajSloj(prvi);
			}

			break;
		case 2:
			int i;
			cout << "Unesite broj sloja koji zelite da deaktivirate" << endl;
			cin >> i;
			slika.VratiSlojeve()[i - 1]->SetActivity(0);

			break;

		case 4:

			cout << endl << "Unesite broj sloja ciju prozirnost zelite da promenite" << endl;
			cin >> i;
			cout << endl << "Unesite novu prozirnost" << endl;
			int k;
			cin >> k;
			slika.VratiSlojeve()[i - 1]->SetNovuProzirnost(k);

			break;
		case 3:


			cout << "Unesite broj sloja koji zelite da aktivirate" << endl;
			cin >> i;
			slika.VratiSlojeve()[i - 1]->SetActivity(1);


			break;
		case 5:


			cout << "Unesite broj sloja koji zelite da ucinite vidljivim" << endl;
			cin >> i;
			slika.VratiSlojeve()[i - 1]->SetVisible(1);

			break;
		case 6:


			cout << "Unesite broj sloja koji zelite da ucinite nevidljivim" << endl;
			cin >> i;
			slika.VratiSlojeve()[i - 1]->SetVisible(0);

			break;

		case 7:
			slika.ObrisiSloj();

			break;
		case 8:
			int p;
			int sir, vis, x, y;
			cout << "Unesite broj oblika koji zelite da selekcija sadrzi" << endl;
			cin >> p;

			vektor.erase(vektor.begin(), vektor.end());


			for (int i = 0; i < p; i++) {

				cout << "Unesite sirinu selekcije" << endl;
				cin >> sir;
				cout << "Unesite visinu selekcije" << endl;
				cin >> vis;
				cout << "Unesite X koordinatu donjeg levog ugla selekcije" << endl;
				cin >> x;
				cout << "Unesite Y koordinatu donjeg levog ugla selekcije" << endl;
				cin >> y;

				Oblik o(sir, vis, x, y);


				vektor.push_back(o);
			}



			vc.push_back(Selekcija(vektor)); //proveri ovo jos



			break;
		case 9:

			cout << "Unesite broj selekcije koji zelite da aktivirate" << endl;
			cin >> i;
			vc[i - 1].Aktiviraj();

			break;
		case 10:


			cout << " Unesite broj selekcije koji zelite da deaktivirate" << endl;
			cin >> i;
			vc[i - 1].Deaktiviraj();


			break;
		case 11:
			int j;
			cout << " Unesite broj selekcije koji zelite da koristite" << endl;
			cin >> i;
			cout << " Unesite broj sloja koji zelite da obojite" << endl;
			cin >> j;
			vc[i - 1].oboj(slika.VratiSlojeve()[j - 1]);
			break;
		case 12:

			cout << endl << "Unesite broj selekcije koji zelite da obrisete \n";

			cin >> i;
			vc.erase(vc.begin() + i - 1, vc.begin() + i);

			break;
		case 13:


			int choice1;





			cout << endl
				<< " 1 - Sabiranje.\n"
				<< " 2 - Oduzimanje\n"
				<< " 3 - Inverzno oduzimanje\n"
				<< " 4 - Mnozenje \n"
				<< " 5 - Deljenje\n"
				<< " 6 - Inverzno deljenje\n"
				<< " 7 - Stepen\n"
				<< " 8 - Logaritam\n"
				<< " 9 - Abs\n"
				<< " 10 - Min.\n"
				<< " 11 - Max.\n"
				<< " 12 - Medijana\n"
				<< " 13 - Kompozitna funkcija\n"
				<< " 14 -Inverzija\n"
				<< " 15 - Crno Bela\n"
				<< " 16 - Nijanse sive\n"
				<< "Unesite vas izbor ";
			cin >> choice1;

			switch (choice1)
			{
			case 1:
				op = new Sabiranje(vc, slika);
				cout << endl << "Unesite konstantu sa kojom zelite da saberete vrednosti piksele";
				cin >> konst;
				op->SetK(konst);
				op->F();
				break;
			case 2:
				op = new Oduzimanje(vc, slika);
				cout << endl << "Unesite konstantu koju zelite da oduzmete od trenutnih vrednosti piksela";
				cin >> konst;
				op->SetK(konst);
				op->F();
				break;
			case 3:
				op = new InverznoOduzimanje(vc, slika);
				cout << endl << "Unesite konstantu od koje zelite da oduzmete trenutne vrednosti piksela";
				cin >> konst;
				op->SetK(konst);
				op->F();
				break;
			case 4:
				op = new Mnozenje(vc, slika);
				cout << endl << "Unesite konstantu koju zelite da pomnozite sa trenutnom vrednostima piksela";
				cin >> konst;
				op->SetK(konst);
				op->F();
				break;
			case 5:
				op = new Deljenje(vc, slika);
				cout << endl << "Unesite konstantu koju zelite da podelite sa trenutnom vrednostima piksela";
				cin >> konst;
				op->SetK(konst);
				op->F();

				break;
			case 6:
				op = new InverznoDeljenje(vc, slika);
				cout << endl << "Unesite konstantu od koje zelite da podelite trenutne vrednosti piksela";
				cin >> konst;
				op->SetK(konst);
				op->F();
				break;
			case 7:
				op = new Stepen(vc, slika);
				cout << endl << "Unesite stepen na koji zelite da podignete trenutnu vrednost piksela";
				cin >> konst;
				op->SetK(konst);
				op->F();
				break;
			case 8:
				op = new Logaritam(vc, slika);
				op->F();
				break;
			case 9:
				op = new Abs(vc, slika);
				op->F();
				break;
			case 10:
				op = new Min(vc, slika);
				cout << endl << "Unesite zeljeni minimum vrednosti piksela ";
				cin >> konst;
				op->SetK(konst);
				op->F();
				break;
			case 11:
				op = new Max(vc, slika);
				cout << endl << "Unesite zeljeni maximum vrednosti piksela ";
				cin >> konst;
				op->SetK(konst);

				op->F();
				break;
			case 12:
				op = new Medijana(vc, slika);
				op->F();
				break;
			case 13:

				cout << endl << "Ako zelite da izvrsite kompozitnu funkciju pritisnite 1, ako zelite da je napravite pritisnite 0"<<endl;
				cin >> konst;

				if (konst)
				{
					if (kop)
						kop->F();
					else cout << "Kompozitna funkcija je prazna"<<endl;
				}
				else {

					kop = new Kompozitna(vc, slika);


					int choice1;

					cout << "Dodajte operacije u kompozitnu funkciju" << endl;

					do {


						cout << endl
							<< " 1 - Sabiranje\n"
							<< " 2 - Oduzimanje\n"
							<< " 3 - Inverzno oduzimanje\n"
							<< " 4 - Mnozenje \n"
							<< " 5 - Deljenje\n"
							<< " 6 - Inverzno deljenje\n"
							<< " 7 - Stepen\n"
							<< " 8 - Logaritam\n"
							<< " 9 - Abs\n"
							<< " 10 - Min.\n"
							<< " 11 - Max.\n"
							<< " 12 - Medijana\n"
							<< " 13 - Inverzija\n"
							<< " 14 - Crno Bela\n"
							<< " 15 - Nijanse sive\n"
							<< " 16 - Kraj biranja \n"
							<< "Unesite vas izbor ";
						cin >> choice1;

						switch (choice1)
						{
						case 1:
							op1 = new Sabiranje(vc, slika);
							cout << endl << "Unesite konstantu sa kojom zelite da saberete vrednosti piksele";
							cin >> konst;
							op1->SetK(konst);
							kop->DodajOperaciju(op1);
							break;
						case 2:
							op1 = new Oduzimanje(vc, slika);
							cout << endl << "Unesite konstantu koju zelite da oduzmete od trenutnih vrednosti piksela";
							cin >> konst;
							op1->SetK(konst);
							kop->DodajOperaciju(op1);
							break;
						case 3:
							op1 = new InverznoOduzimanje(vc, slika);
							cout << endl << "Unesite konstantu od koje zelite da oduzmete trenutne vrednosti piksela";
							cin >> konst;
							op1->SetK(konst);
							kop->DodajOperaciju(op1);
							break;
						case 4:
							op1 = new Mnozenje(vc, slika);
							cout << endl << "Unesite konstantu koju zelite da pomnozite sa trenutnom vrednostima piksela";
							cin >> konst;
							op1->SetK(konst);
							kop->DodajOperaciju(op1);
							break;
						case 5:
							op1 = new Deljenje(vc, slika);
							cout << endl << "Unesite konstantu koju zelite da podelite sa trenutnom vrednostima piksela";
							cin >> konst;
							op1->SetK(konst);
							kop->DodajOperaciju(op1);
							break;
						case 6:
							op1 = new InverznoDeljenje(vc, slika);
							cout << endl << "Unesite konstantu od koje zelite da podelite trenutne vrednosti piksela";
							cin >> konst;
							op1->SetK(konst);
							kop->DodajOperaciju(op1);
							break;
						case 7:
							op1 = new Stepen(vc, slika);
							cout << endl << "Unesite stepen na koji zelite da podignete trenutnu vrednost piksela";
							cin >> konst;
							op1->SetK(konst);
							kop->DodajOperaciju(op1);
							break;
						case 8:
							op1 = new Logaritam(vc, slika);
							kop->DodajOperaciju(op1);
							break;
						case 9:
							op1 = new Abs(vc, slika);
							kop->DodajOperaciju(op1);
							break;
						case 10:
							op1 = new Min(vc, slika);
							cout << endl << "Unesite zeljeni minimum vrednosti piksela ";
							cin >> konst;
							op1->SetK(konst);
							kop->DodajOperaciju(op1);
							break;
						case 11:
							op1 = new Max(vc, slika);
							cout << endl << "Unesite zeljeni maximum vrednosti piksela ";
							cin >> konst;
							op1->SetK(konst);
							kop->DodajOperaciju(op1);
							break;
						case 12:
							op1 = new Medijana(vc, slika);
							kop->DodajOperaciju(op1);
							break;

						case 13:
							op1 = new Inverzija(vc, slika);
							kop->DodajOperaciju(op1);
							break;
						case 14:
							op1 = new CrnoBela(vc, slika);
							kop->DodajOperaciju(op1);
							break;
						case 15:
							op1 = new NijanseSive(vc, slika);
							kop->DodajOperaciju(op1);
							break;
						case 16:
							cout << "Kraj biranja";
							break;


						default:
							cout << "Nevalidan izbor \n";

							break;


						}


					}

					while (choice1 != 16);


				}

				break;
			case 14:
				op = new Inverzija(vc, slika);
				op->F();
				break;
			case 15:
				op = new CrnoBela(vc, slika);
				op->F();
				break;
			case 16:
				op = new NijanseSive(vc, slika);
				op->F();
				break;

			}



			break;

			case 14:


				slika.NapraviSliku();



				break;
			case 15:



				myfile.open("tekst.fun");
				kop->ispis(myfile);
				//myfile << "Kraj";
				myfile.close();


				break;
			case 16:

				ulaz.open("tekst.fun");



				kop = new Kompozitna(vc, slika);

				while (getline(ulaz, str))
				{
					int br;
					regex_match(str, sm, rg);
					string ope = sm.str(1);
					if (ope != "NijanseSive" && ope != "CrnoBela" && ope != "Abs" && ope != "Inverzija" && ope != "Medijana"&& ope != "Logaritam")
						br = stoi(sm.str(2));

					if (ope == "Sabiranje")
					{
						op = new Sabiranje(vc, slika);
						op->SetK(br);
						kop->DodajOperaciju(op);


					}
					else if (ope == "Oduzimanje")
					{
						op = new Oduzimanje(vc, slika);
						op->SetK(br);
						kop->DodajOperaciju(op);

					}
					else if
						(ope == "Mnozenje")
					{
						op = new Mnozenje(vc, slika);
						op->SetK(br);
						kop->DodajOperaciju(op);
					}
					else if (ope == "Deljenje")
					{
						op = new Deljenje(vc, slika);
						op->SetK(br);
						kop->DodajOperaciju(op);
					}
					else if (ope == "InverznoDeljenje")
					{
						op = new InverznoDeljenje(vc, slika);
						op->SetK(br);
						kop->DodajOperaciju(op);
					}
					else if (ope == "InverznoOduzimanje")
					{
						op = new InverznoOduzimanje(vc, slika);
						op->SetK(br);
						kop->DodajOperaciju(op);
					}
					else if (ope == "Stepen")
					{
						op = new Stepen(vc, slika);
						op->SetK(br);
						kop->DodajOperaciju(op);
					}
					else if (ope == "Abs")
					{
						op = new Abs(vc, slika);

						kop->DodajOperaciju(op);
					}
					else if (ope == "Logaritam")
					{
						op = new Logaritam(vc, slika);

						kop->DodajOperaciju(op);
					}
					else if (ope == "Inverzija")
					{
						op = new Inverzija(vc, slika);

						kop->DodajOperaciju(op);
					}
					else if (ope == "Min")
					{
						op = new Min(vc, slika);
						op->SetK(br);
						kop->DodajOperaciju(op);
					}
					else if (ope == "Max")
					{
						op = new Max(vc, slika);
						op->SetK(br);
						kop->DodajOperaciju(op);
					}
					else if (ope == "Medijana")
					{
						op = new Medijana(vc, slika);

						kop->DodajOperaciju(op);
					}
					else if (ope == "NijanseSive")
					{
						op = new NijanseSive(vc, slika);

						kop->DodajOperaciju(op);
					}
					else if (ope == "CrnoBela")
					{
						op = new CrnoBela(vc, slika);
						kop->DodajOperaciju(op);
					}




				}

				ulaz.close();



				break;

			case 17:

				if (kop)
					kop->ispis();
				else
					cout << endl << "Ne postoji kompozitna funkcija";



				break;
			case 18:

				br = vc.size();

				myfile.open("coda.txt");
			
				myfile << br<<"\n";                 //prvo broj selekcija

				for (int i = 0; i < br; i++)
				{

					konst = vc[i].Duzina();
					myfile << konst << "\n";                 // broj oblika u selekciju
					myfile << vc[i].IsActive() << "\n";      //   aktivnost
					for (int j = 0; j < konst; j++)
					{
						myfile << "<" << vc[i].VratiOblik(j).Sirina()  << ">";
						myfile << "<" << vc[i].VratiOblik(j).Visina()  << ">";  //oblik
						myfile << "<" << vc[i].VratiOblik(j).X()  << ">";
						myfile << "<" << vc[i].VratiOblik(j).Y()  << ">"<<endl;
					}


				}
				br = slika.VratiSlojeve().size();

				myfile << br << "\n";  //broj slojeva 

				myfile <<  slika.Visina() << "\n";  //visina
					myfile << slika.Sirina() << "\n";       //sirina                      
				for (int i = 0; i < br; i++)
				{
					myfile << "<" << slika.VratiSlojeve()[i]->IsActive() << ">";//aktivnost sloja
					myfile << "<" << slika.VratiSlojeve()[i]->IsVisible() << ">";   //vidiljivost
					myfile << "<" << slika.VratiSlojeve()[i]->Prozirnost() << ">"<<endl;// prozirnost

					for (int p = 0; p < slika.Visina(); p++)
					{
						for (int l = 0;l < slika.Sirina(); l++)
						{
							myfile<< "<"<<slika.VratiSlojeve()[i]->Slika()[p][l]->getBlue()<<">";   //plava
							myfile << "<" << slika.VratiSlojeve()[i]->Slika()[p][l]->getGreen() << ">";   //zelena
							myfile << "<" << slika.VratiSlojeve()[i]->Slika()[p][l]->getRed() << ">";    //crvena
							myfile << "<" << slika.VratiSlojeve()[i]->Slika()[p][l]->getAlpha() << ">"<<endl;   //alfa

						}

					}



				}



				myfile.close();


				



				break;
			case 19:
				vc.erase(vc.begin(), vc.end());
				vektor.erase(vektor.begin(), vektor.end());
				slika.VratiSlojeve().erase(slika.VratiSlojeve().begin(), slika.VratiSlojeve().end());
				

				ulaz.open("coda.txt");

				getline(ulaz, str);

				br = stoi(str);

				for (int i = 0; i < br; i++)
			{
					getline(ulaz, str);
					konst = stoi(str);

					getline(ulaz, str);
					int aktivnost = stoi(str);


					for (int i = 0; i < konst; i++)
					{
						getline(ulaz, str);
						regex_match(str, sm, rx);
						
						int sirina= stoi(sm.str(1));
						int visina = stoi(sm.str(2));
						int x = stoi(sm.str(3));
						int y = stoi(sm.str(4));
						
						Oblik o(sirina, visina, x, y);


						vektor.push_back(o);

					}

					vc.push_back(vektor);
					vektor.erase(vektor.begin(), vektor.end());
			 }


				getline(ulaz, str);
				br = stoi(str);


				 getline(ulaz, str);
				 visina = stoi(str);

				getline(ulaz, str);
				 sirina = stoi(str);
				 

				 for (int i = 0; i < br; i++)
				 {
					 
					 for (int i = 0; i < visina; i++)
					 {
						 for (int j = 0; j < sirina; j++)
						 {
							 Piksel* p = new Piksel(0, 0, 0, 0);
							 vektorr.push_back(p);

						 }
						 vecc.push_back(vektorr);
						 vektorr.erase(vektorr.begin(), vektorr.end());
					 }



					 getline(ulaz, str);
					 regex_match(str, sm, re);

					 int aktivnost = stoi(sm.str(1));
					 int vidljivost = stoi(sm.str(2));
					 int prozirnost = stoi(sm.str(3));
					 for (int p = 0; p < visina; p++)
					 {
						 for (int l = 0; l < sirina; l++)
						 {
							 getline(ulaz, str);
							 regex_match(str, sm, rx);


							 int plava = stoi(sm.str(1));
							 int zelena = stoi(sm.str(2));
							 int crvena = stoi(sm.str(3));
							 double alfa= stod(sm.str(4));

							 vecc[p][l]->setBlue(plava);
							 vecc[p][l]->setGreen(zelena);
							 vecc[p][l]->setRed(crvena);
							 vecc[p][l]->setAlpha(alfa);


						 }

					 }
					 Sloj * aaa= new Sloj(vecc, prozirnost);
					 aaa->SetActivity(aktivnost);
					 aaa->SetVisible(vidljivost);
					 aaa->SetProzirnost(prozirnost);

					 slika.DodajSloj(aaa);

					 vecc.erase(vecc.begin(), vecc.end());

				 }

				

				ulaz.close();

				break;
			case 20:


				cout << " Dovidjenja";



				break;



			default:
				cout << " Nevalidan izbor \n"
					<< "Probaj ponovo:\n";
				break;
			}




		} while (choice != 20);














































	
}

