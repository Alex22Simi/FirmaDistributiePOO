#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class FirmaDistributie
{
	const int id;
	string denumire;
	int nrProduse;
	int* cantitati;
public:
	FirmaDistributie() :id(0)
	{
		this->denumire = "Necunoscut";
		this->nrProduse = 0;
		this->cantitati = nullptr;
	}
	FirmaDistributie(int id, string denumire, int nrProduse, int* cantitati) :id(id)
	{
		this->denumire = denumire;
		this->nrProduse = nrProduse;
		this->cantitati = new int[this->nrProduse];
		for (int i = 0; i < nrProduse; i++)
		{
			this->cantitati[i] = cantitati[i];
		}
	}
	FirmaDistributie(const FirmaDistributie& f):id(f.id)
	{
		this->denumire = f.denumire;
		this->nrProduse = f.nrProduse;
		this->cantitati = new int[this->nrProduse];
		for (int i = 0; i < f.nrProduse; i++)
		{
			this->cantitati[i] = f.cantitati[i];
		}
	}
	FirmaDistributie& operator=(const FirmaDistributie& f)
	{
		if (this != &f)
		{
			if (this->cantitati != NULL)
			{
				delete[] this->cantitati;
			}
			this->denumire = f.denumire;
			this->nrProduse = f.nrProduse;
			this->cantitati = new int[this->nrProduse];
			for (int i = 0; i < f.nrProduse; i++)
			{
				this->cantitati[i] = f.cantitati[i];
			}
			return *this;
		}
	}
	int getNrProduse()
	{
		return this->nrProduse;
	}
	void setNrProduse(int nrProduse)
	{
		if (this->nrProduse > 0)
		{
			this->nrProduse = nrProduse;
		}
	}
	friend ostream& operator<<(ostream& out, const FirmaDistributie& f)
	{
		out << f.id << endl;
		out << f.denumire << endl;
		out << f.nrProduse << endl;
		for (int i = 0; i < f.nrProduse; i++)
		{
			out << f.cantitati[i] << ", ";
		}
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in,  FirmaDistributie& f)
	{
		cout << "Introduceti numele: " << endl;
		getline(in, f.denumire);

		cout << "Introduceti nr de produse: " << endl;
		in >> f.nrProduse;
		cout << "Introduceti cantitatile" << endl;
		if (f.cantitati != NULL)

		{
			delete[] f.cantitati;
		}
		f.cantitati = new int[f.nrProduse];
		for (int i = 0; i < f.nrProduse; i++)
		{
			in >> f.cantitati[i];
		}
		return in;
	}
	friend ofstream& operator<<(ofstream& out, const FirmaDistributie& f)
	{
		out << f.denumire << endl;
		out << f.nrProduse << endl;
		for (int i = 0; i < f.nrProduse; i++)
		{
			out << f.cantitati[i] << ", ";
		}
		cout << endl;
		return out;
	}
	friend ifstream& operator>>(ifstream& in, FirmaDistributie& f)
	{
		in >> ws;
		getline(in, f.denumire);

		in >> ws;
		in >> f.nrProduse;

		in >> ws;
		if (f.cantitati != NULL)
		{
			delete[] f.cantitati;
		}
		f.cantitati = new int[f.nrProduse];
		for (int i = 0; i < f.nrProduse; i++)
		{
			in >> f.cantitati[i];
		}
		return in;
	}


	~FirmaDistributie()
	{
		if (this->cantitati != NULL)
		{
			delete[] this->cantitati;
		}
	}

	int& operator[](int index)
	{
		if (nrProduse > 0 && index < nrProduse)
		{
			return cantitati[index];
		}
		
	}

	//operator! ->returneaza true daca nrProduse > 0
	//bool operator!()
	//{
	//	if (nrProduse > 0) return true;
	//}

	//
	friend bool operator!(FirmaDistributie);
	/*FirmaDistributie operator++()
	{
		nrProduse++;
		return *this;
	}*/
	friend FirmaDistributie operator++(FirmaDistributie f);
};
bool operator!(FirmaDistributie f)
{
	if (f.nrProduse > 0) return true;
}
FirmaDistributie operator++(FirmaDistributie f) //->post
{
	f.nrProduse++;
	return f;
}
FirmaDistributie operator++(FirmaDistributie f, int i) //->



//suplimentar relatia has a
class Patron

{
	string nume;
	int nrFirmeDistributie;
	FirmaDistributie* firme;
public:
	Patron()
	{
		this->nume = "Necunoscut";
		this->nrFirmeDistributie = 0;
		this->firme = nullptr;
	}
	Patron(string nume, int nrFirmeDistributie, FirmaDistributie* firme)
	{
		this->nume = nume;
		this->nrFirmeDistributie = nrFirmeDistributie;
		this->firme = new FirmaDistributie[this->nrFirmeDistributie];
		for (int i = 0; i < nrFirmeDistributie; i++)
		{
			this->firme[i] = firme[i];
		}
	}
	Patron(const Patron& p)
	{
		this->nume = p.nume;
		this->nrFirmeDistributie = p.nrFirmeDistributie;
		this->firme = new FirmaDistributie[this->nrFirmeDistributie];
		for (int i = 0; i < p.nrFirmeDistributie; i++)
		{
			this->firme[i] = p.firme[i];
		}
	}
	Patron& operator=(const Patron& p)
	{
		if (this != &p)
		{
			if (this->firme != NULL)
			{
				delete[] this->firme;
			}
			this->nume = p.nume;
			this->nrFirmeDistributie = p.nrFirmeDistributie;
			this->firme = new FirmaDistributie[this->nrFirmeDistributie];
			for (int i = 0; i < p.nrFirmeDistributie; i++)
			{
				this->firme[i] = p.firme[i];
			}
			
		
		}
		return *this;
	}
	~Patron()
	{
		if (this->firme != NULL)
		{
			delete[] this->firme;
		}
	}
	friend ostream& operator<<(ostream& out, const Patron& f)
	{
		out << f.nume << endl;
		out << f.nrFirmeDistributie << endl;
		for (int i = 0; i < f.nrFirmeDistributie; i++)
		{
			out << f.firme[i] << ", ";
		}
		out << endl;
		return out;
	}

};

int main()
{
	FirmaDistributie fd;
	cout << fd << endl;

	int cantitati1[] = { 100, 200};
	FirmaDistributie fd1(1, "ABC", 2, cantitati1);
	cout << fd1 << endl;

	int cantitati2[] = { 100, 220, 333 };
	FirmaDistributie fd2(2, "DEF", 3, cantitati2);
	cout << fd2 << endl;

	int cantitati3[] = { 1200, 500 };
	FirmaDistributie fd3(3, "QQQ", 2, cantitati3);
	cout << fd3 << endl;

	FirmaDistributie fd4(fd3);
	cout << fd4 << endl;

	fd4 = fd;
	cout << fd4 << endl;

	cout << fd3[0] << endl;
	fd3[0] = 2222;
	cout << fd3[0] << endl;

	FirmaDistributie firmeDistr[] = { fd1, fd2 , fd3 };
	Patron p1("Ionel", 3, firmeDistr);
	cout << p1 << endl;

	/*cin >> fd2;
	cout << fd2 << endl;*/

	ofstream f("Firma.txt", ios::out);
	f << fd2;
	cout << endl << endl << endl;
	ifstream g("Firma.txt", ios::in);
	cout << fd3 << endl;
	g >> fd3;
	cout << fd2 << endl;

	cout << fd2 << endl;
	if (!fd2)
	{
		cout << "Numarul de prod eeste > 0\n";
	}
	else
		cout << "Numarul de prod este < 0\n";

	cout << fd2 << endl;
	//fd2.operator++();
	operator++(fd2);
	cout << fd2 << endl;

	cout << endl << endl << endl;

	cout << fd1 << endl;
	cout << fd2 << endl;
	fd1 = ++fd2;
	cout << fd1 << endl;
	cout << fd2 << endl;
}