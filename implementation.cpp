#include<iostream>
#include<string>
#include<fstream>
#include<list>


using namespace std;

template<typename T>
class Operatori {
private:
	int marimeVector;
	T* vector;
public:
	//getteri
	int getmarimeVector() {
		return this->marimeVector;
	}
	T getvector() {
		if (this->vector != nullptr)
			return this->vector;
		else
			throw new exception("Vector nul");
	}
	//setteri
	void setmarimeVector(int marimeVector) {
		if (marimeVector > 0) {
			if (marimeVector < this->marimeVector) {
				T* senzornou;
				senzornou = new T[this->numarSenzori];
				for (int i = 0; i < this->marimeVector; i++) {
					senzornou[i] = this->vector[i];
				}
				delete[]this->vector;
				this->marimeVector = marimeVector;
				this->vector = new T[marimeVector];
				for (int i = 0; i < marimeVector; i++) {
					this->vector[i] = senzornou[i];
				}
				delete[]senzornou;
			}
			else if (marimeVector > this->marimeVector) {
				T* senzornou;
				senzornou = new T[this->marimeVector];
				for (int i = 0; i < this->marimeVector; i++) {
					senzornou[i] = this->vector[i];
				}
				delete[]this->vector;
				this->vector = new T[marimeVector];
				for (int i = 0; i < this->marimeVector; i++) {
					this->vector[i] = senzornou[i];
				}
				this->marimeVector = marimeVector;
				delete[]senzornou;
			}
			else
				throw new exception("Vectorul deja contine aceasta dimensiune !");
		}
		else
			throw new exception("Introduceti o marime pozitiva !");
	}
	void setvector(T* vector) {
		if (vector != nullptr)
			this->vector = vector;
		else
			throw new exception("Introduceti un pointer nenul !");
	}
	Operatori() {
		vector = nullptr;
		marimeVector = 0;
	}
	Operatori(int marimeVector, T* vector) {
		if (marimeVector <= 0)
			throw new exception("Introduceti o marime pozitiva !");
		if (vector == nullptr)
			throw new exception("Introduceti un pointer nenul !");
		this->marimeVector = marimeVector;
		this->vector = new T[marimeVector];
		for (int i = 0; i < this->marimeVector; i++) {
			this->vector[i] = vector[i];
		}
	}
	Operatori(const Operatori& operatori) {
		this->marimeVector = operatori.marimeVector;
		this->vector = new T[operatori.marimeVector];
		for (int i = 0; i < this->marimeVector; i++) {
			this->vector[i] = operatori.vector[i];
		}
	}
	friend ostream& operator<<(ostream& scriere, const Operatori& operatori) {
		scriere << "Marime vector : " << operatori.marimeVector << endl;
		for (int i = 0; i < operatori.marimeVector; i++) {
			scriere << operatori.vector[i];
		}
		return scriere;
	}
	friend istream& operator>>(istream& citire, Operatori& operatori) {
		cout << "Introduceti marime vector : "; citire >> operatori.marimeVector;
		for (int i = 0; i < operatori.marimeVector; i++) {
			cout << "Introduceti elementul " << i << " din vector:" << endl;
			citire >> operatori.vector[i];
		}
		return citire;
	}
	Operatori operator=(const Operatori& operatori) {
		this->marimeVector = operatori.marimeVector;
		if (this->vector != nullptr)
			delete[]this->vector;
		this->vector = new T[this->marimeVector];
		for (int i = 0; i < this->marimeVector; i++) {
			this->vector[i] = operatori.vector[i];
		}
		return *this;
	}
	Operatori operator+(const Operatori& operatori) {
		if (this->marimeVector >= operatori.marimeVector) {
			Operatori o = *this;
			for (int i = 0; i < operatori.marimeVector; i++) {
				o.vector[i] = this->vector[i] + operatori.vector[i];
			}
			return o;
		}
		else if (this->marimeVector < operatori.marimeVector) {
			Operatori o = operatori;
			for (int i = 0; i < this->marimeVector; i++) {
				o.vector[i] = operatori.vector[i] + this->vector[i];
			}
			return o;
		}
	}
	Operatori operator-(const Operatori& operatori) {
		if (this->marimeVector >= operatori.marimeVector) {
			Operatori o = *this;
			for (int i = 0; i < operatori.marimeVector; i++) {
				o.vector[i] = this->vector[i] - operatori.vector[i];
			}
			return o;
		}
		else if (this->marimeVector < operatori.marimeVector) {
			Operatori o = operatori;
			for (int i = 0; i < this->marimeVector; i++) {
				o.vector[i] = operatori.vector[i] - this->vector[i];
			}
			return o;
		}
	}
	Operatori operator/(const Operatori& operatori) {
		if (this->marimeVector >= operatori.marimeVector) {
			Operatori o = *this;
			for (int i = 0; i < operatori.marimeVector; i++) {
				o.vector[i] = this->vector[i] / operatori.vector[i];
			}
			return o;
		}
		else if (this->marimeVector < operatori.marimeVector) {
			Operatori o = operatori;
			for (int i = 0; i < this->marimeVector; i++) {
				o.vector[i] = operatori.vector[i] / this->vector[i];
			}
			return o;
		}
	}
	Operatori operator++(int) {
		Operatori operatori = *this;
		for (int i = 0; i < this->marimeVector; i++) {
			this->vector[i]++;
		}
		return operatori;
	}
	Operatori operator++() {
		for (int i = 0; i < this->marimeVector; i++) {
			this->vector[i]++;
		}
		return *this;
	}
};

class Dispozitiv {
private:
	int anFabricatie;
	float pret;
public:
	//getteri
	int getanFabricatie() {
		return this->anFabricatie;
	}
	float getpret() {
		return this->pret;
	}
	//setteri
	void setanFabricatie(int anFabricatie) {
		if (anFabricatie > 0)
			this->anFabricatie = anFabricatie;
		else
			throw new exception("Ati introdus un an de fabricatie negativ !");
	}
	void setpret(float pret) {
		if (pret > 0)
			this->pret = pret;
		else
			throw new exception("Ati introdus un pret negativ!");
	}
	//constructorul DEFAULT
	Dispozitiv() {
		this->anFabricatie = 0;
		this->pret = 0;
	}
	//constructorul de copiere
	Dispozitiv(const Dispozitiv& dispozitiv) {
		this->anFabricatie = dispozitiv.anFabricatie;
		this->pret = dispozitiv.pret;
	}
	//constructorul cu parametrii
	Dispozitiv(int anFabricatie, float pret) {
		if (anFabricatie <= 0)
			throw new exception("Ati introdus un an de fabricatie negativ !");
		if (pret <= 0)
			throw new exception("Ati introdus un pret negativ!");
		this->anFabricatie = anFabricatie;
		this->pret = pret;
	}
	//constructorul cu parametrul anFabricatie
	Dispozitiv(int anFabricatie) {
		if (anFabricatie <= 0)
			throw new exception("Ati introdus un an de fabricatie negativ !");
		this->anFabricatie = anFabricatie;
	}
	//constructorul cu parametrul pret
	Dispozitiv(float pret) {
		if (pret <= 0)
			throw new exception("Ati introdus un pret negativ!");
		this->pret = pret;
	}
	//FUNCTIE VIRTUALA
	virtual string sunetEmis() = 0;
	//supraincarcare operator<<
	friend ostream& operator<<(ostream& scriere, const Dispozitiv& dispozitiv) {
		scriere << endl << "An fabricatie: " << dispozitiv.anFabricatie << " --- Pret: " << dispozitiv.pret;
		return scriere;
	}
	//supraincarcare operator>>
	friend istream& operator>>(istream& citire, Dispozitiv& dispozitiv) {
		cout << "Introduceti anul de fabricatie : "; citire >> dispozitiv.anFabricatie;
		cout << "Introduceti pretul : "; citire >> dispozitiv.pret;
		return citire;
	}
	//supraincarcare  ifstream& operator>>
	friend ifstream& operator>>(ifstream& citire, Dispozitiv& dispozitiv) {
		citire >> dispozitiv.anFabricatie;
		citire >> dispozitiv.pret;
		return citire;
	}
	//supraincarcare operator=
	Dispozitiv& operator=(const Dispozitiv& dispozitiv) {
		this->anFabricatie = dispozitiv.anFabricatie;
		this->pret = dispozitiv.pret;
		return *this;
	}
	//supraincarcare operator+=
	Dispozitiv& operator+=(const Dispozitiv& dispozitiv) {
		this->pret += dispozitiv.pret;
		return *this;
	}
	//supraincarcare operator-=
	Dispozitiv& operator-=(const Dispozitiv& dispozitiv) {
		if (this->pret > dispozitiv.pret)
			this->pret -= dispozitiv.pret;
		else
			this->pret = dispozitiv.pret - this->pret;
		return *this;
	}
	//supraincarcare operator/=
	Dispozitiv& operator/=(const Dispozitiv& dispozitiv) {
		this->pret /= dispozitiv.pret;
		return *this;
	}
	//supraincarcare operator*
	Dispozitiv& operator*(const Dispozitiv& dispozitiv) {
		Dispozitiv* d = this;
		d->pret = this->pret * dispozitiv.pret;
		return *d;
	}
	//supraincarcare operator*=
	Dispozitiv& operator*=(const Dispozitiv& dispozitiv) {
		this->pret *= dispozitiv.pret;
		return *this;
	}
	//DESTRUCTOR
	~Dispozitiv() {}
}; //
class Profil {
private:
	string clasa;
	int garantie;
	bool waterproof;
	string tipRetea;
public:
	//constructorul DEFAULT
	Profil() {
		this->clasa = "unknown";
		this->garantie = 0;
		this->waterproof = 0;
		this->tipRetea = "unknown";
	}
	//constructorul de copiere
	Profil(const Profil& profil) {
		this->clasa = profil.clasa;
		this->garantie = profil.garantie;
		this->waterproof = profil.waterproof;
		this->tipRetea = profil.tipRetea;
	}
	//constructorul cu parametrii
	Profil(const string& clasa, int garantie, bool waterproof, const string& tipRetea) {
		if (clasa.length() <= 0)
			throw new exception("Introduceti un string existent");
		if (garantie <= 0)
			throw new exception("Ati introdus o garantie negativa!");
		if (tipRetea.length() <= 0)
			throw new exception("Introduceti un string existent");
		this->clasa = clasa;
		this->garantie = garantie;
		this->waterproof = waterproof;
		this->tipRetea = tipRetea;
	}
	//getteri
	string getclasa() {
		return this->clasa;
	}
	char getclasa(int index) {
		return this->clasa[index];
	}
	char gettipRetea(int index) {
		return this->tipRetea[index];
	}
	int getgarantie() {
		return this->garantie;
	}
	bool getwaterproof() {
		return this->waterproof;
	}
	string gettipRetea() {
		return this->tipRetea;
	}
	//setteri
	void setclasa(const string& clasa) {
		if (clasa.length() > 0)
			this->clasa = clasa;
		else
			throw new exception("Introduceti un string existent");
	}
	void setgarantie(int garantie) {
		if (garantie > 0)
			this->garantie = garantie;
		else
			throw new exception("Ati introdus o garantie negativa!");
	}
	void setwaterproof(bool waterproof) {
		this->waterproof = waterproof;
	}
	void settipRetea(const string& tipRetea) {
		if (tipRetea.length() > 0)
			this->tipRetea = tipRetea;
		else
			throw new exception("Introduceti un string existent");
	}
	//supraincarcare operator=
	Profil operator=(const Profil& profil) {
		this->clasa = profil.clasa;
		this->garantie = profil.garantie;
		this->waterproof = profil.waterproof;
		this->tipRetea = profil.tipRetea;
		return *this;
	}
	//supraincarcare operator+
	Profil operator+(const Profil& profil) {
		Profil p = *this;
		p.garantie = this->garantie + profil.garantie;
		return p;
	}
	//supraincarcare operator-
	Profil operator-(const Profil& profil) {
		Profil p = *this;
		if (this->garantie > profil.garantie)
			p.garantie = this->garantie - profil.garantie;
		else
			p.garantie = profil.garantie - this->garantie;
		return p;
	}
	//supraincarcare operator/
	Profil operator/(const Profil& profil) {
		Profil p = *this;
		p.garantie = this->garantie / profil.garantie;
		return p;
	}
	//supraincarcare operator++ - post
	Profil operator++(int) {
		Profil p = *this;
		this->garantie++;
		return p;
	}
	//supraincarcare operator++ - pre
	Profil operator++() {
		this->garantie++;
		return *this;
	}
	//supraincarcare operator<<
	friend ostream& operator<<(ostream& scriere, const Profil& profil) {
		scriere << endl << "Clasa:" << profil.clasa << "---Garantie:" << profil.garantie << " ani--- Waterproof:" << profil.waterproof << "--- Tip de retea:" << profil.tipRetea << endl;
		return scriere;
	}
	//supraincarcare operator>>
	friend istream& operator>>(istream& citire, Profil& profil) {
		cout << "Clasa:"; citire >> profil.clasa;
		cout << "Garantie:"; citire >> profil.garantie;
		cout << "Waterproof:"; citire >> profil.waterproof;
		cout << "Tip de reteaL"; citire >> profil.tipRetea;
		return citire;
	}
	//supraincarcare ofstream& operator<<
	friend ofstream& operator<<(ofstream& scriere, const Profil& profil) {
		scriere << endl << "Clasa:" << profil.clasa << "---Garantie:" << profil.garantie << " ani--- Waterproof:" << profil.waterproof << "--- Tip de retea:" << profil.tipRetea << endl << endl;
		return scriere;
	}
	//DESTRUCTOR
	~Profil() {}
};
class Senzor : public Dispozitiv {//clasa Senzor mosteneste clasa Dispozitiv
private:
	const int id;
	bool s_a_c;
	static int contor;
	int numarInteractiuni = 0;
	int numarResetari = 0;
	int durataDeViata = 0;
	int* istoricDate = nullptr;
	int dimensiuneIstoricDate = 0;
	char* pozitionare = nullptr;
	float distantaFataDeUrmatorulSenzor = 0;
	float timpDeRaspuns = 0;
	bool conectareaDeLaDistanta = 0;
	string situatieCritica = "";
	bool interconectareCuAltiSenzori = 0;
	Profil profil;
public:
	friend class CasaInteligenta;
	//constructorul DEFAULT
	Senzor() :id(contor++), s_a_c(0), Dispozitiv() {
		this->pozitionare = new char[strlen("Fara nume") + 1];
		strcpy_s(this->pozitionare, strlen("Fara nume") + 1, "Fara nume");
	}
	//constructorul de copiere
	Senzor(const Senzor& senzor) :id(contor++), s_a_c(0), Dispozitiv(senzor) {
		this->numarInteractiuni = senzor.numarInteractiuni;
		this->numarResetari = senzor.numarResetari;
		this->durataDeViata = senzor.durataDeViata;
		this->dimensiuneIstoricDate = senzor.dimensiuneIstoricDate;
		if (this->istoricDate != nullptr)
			delete[]this->istoricDate;
		this->istoricDate = new int[senzor.dimensiuneIstoricDate];
		for (int i = 0; i < this->dimensiuneIstoricDate; i++) {
			this->istoricDate[i] = senzor.istoricDate[i];
		}
		if (this->pozitionare != nullptr)
			delete[]this->pozitionare;
		this->pozitionare = new char[strlen(senzor.pozitionare) + 1];
		strcpy_s(this->pozitionare, strlen(senzor.pozitionare) + 1, senzor.pozitionare);
		this->distantaFataDeUrmatorulSenzor = senzor.distantaFataDeUrmatorulSenzor;
		this->timpDeRaspuns = senzor.timpDeRaspuns;
		this->conectareaDeLaDistanta = senzor.conectareaDeLaDistanta;
		this->situatieCritica = senzor.situatieCritica;
		this->interconectareCuAltiSenzori = senzor.interconectareCuAltiSenzori;
		this->profil = senzor.profil;
	}
	//constructorul cu parametrii
	Senzor(int numarInteractiuni, int numarResetari, int durataDeViata, int* istoricDate, int dimensiuneIstoricDate, char* pozitionare, float distantaFataDeUrmatorulSenzor, float timpDeRaspuns, bool conectareaDeLaDistanta, string situatieCritica, bool interconectareCuAltiSenzori, int anFabricatie, float pret) :id(contor++), s_a_c(0), Dispozitiv(anFabricatie, pret) {
		if (numarInteractiuni <= 0)
			throw new exception("Ati introdus un numar negativ de interactiuni");
		if (numarResetari <= 0)
			throw new exception("Ati introdus un numar negativ de resetari");
		if (durataDeViata <= 0)
			throw new exception("Ati introdus o durata de viata negativa");
		if (istoricDate == nullptr)
			throw new exception("Asignati un pointer nenul");
		if (dimensiuneIstoricDate <= 0)
			throw new exception("Ati introdus o dimensiune negativa");
		if (pozitionare == nullptr)
			throw new exception("Asignati un pointer nenul");
		if (distantaFataDeUrmatorulSenzor <= 0)
			throw new exception("Ati introdus o distanta negativa fata de urmatorul senzor");
		if (timpDeRaspuns <= 0)
			throw new exception("Ati introdus un timp de raspuns negativ");
		if (situatieCritica.length() <= 0)
			throw new exception("Introduceti un string existent");
		this->numarInteractiuni = numarInteractiuni;
		this->numarResetari = numarResetari;
		this->durataDeViata = durataDeViata;
		this->dimensiuneIstoricDate = dimensiuneIstoricDate;
		this->istoricDate = new int[dimensiuneIstoricDate];
		for (int i = 0; i < dimensiuneIstoricDate; i++) {
			this->istoricDate[i] = istoricDate[i];
		}
		this->pozitionare = new char[strlen(pozitionare) + 1];
		strcpy_s(this->pozitionare, strlen(pozitionare) + 1, pozitionare);
		this->distantaFataDeUrmatorulSenzor = distantaFataDeUrmatorulSenzor;
		this->timpDeRaspuns = timpDeRaspuns;
		this->conectareaDeLaDistanta = conectareaDeLaDistanta;
		this->situatieCritica = situatieCritica;
		this->interconectareCuAltiSenzori = interconectareCuAltiSenzori;
		Profil p;
		this->profil = p;
	}

	//supraincarcare operator=
	Senzor operator=(const Senzor& senzor) {
		Dispozitiv::operator=(senzor);
		this->profil = senzor.profil;
		this->numarInteractiuni = senzor.numarInteractiuni;
		this->numarResetari = senzor.numarResetari;
		this->durataDeViata = senzor.durataDeViata;
		this->dimensiuneIstoricDate = senzor.dimensiuneIstoricDate;
		if (this->istoricDate != nullptr)
			delete[]this->istoricDate;
		this->istoricDate = new int[senzor.dimensiuneIstoricDate];
		for (int i = 0; i < this->dimensiuneIstoricDate; i++) {
			this->istoricDate[i] = senzor.istoricDate[i];
		}
		if (this->pozitionare != nullptr)
			delete[]this->pozitionare;
		this->pozitionare = new char[strlen(senzor.pozitionare) + 1];
		strcpy_s(this->pozitionare, strlen(senzor.pozitionare) + 1, senzor.pozitionare);
		this->distantaFataDeUrmatorulSenzor = senzor.distantaFataDeUrmatorulSenzor;
		this->timpDeRaspuns = senzor.timpDeRaspuns;
		this->conectareaDeLaDistanta = senzor.conectareaDeLaDistanta;
		this->situatieCritica = senzor.situatieCritica;
		this->interconectareCuAltiSenzori = senzor.interconectareCuAltiSenzori;
		return *this;
	}
	//supraincarcare operator<<
	friend ostream& operator<<(ostream& scriere, const Senzor& senzor) {
		scriere << "ID: " << senzor.id << " ; numar interactiuni: " << senzor.numarInteractiuni << "; numar resetari: " << senzor.numarResetari << "; durata de viata:" << senzor.durataDeViata << "; dimensiune istoric date:" << senzor.dimensiuneIstoricDate << "; distanta fata de urmatorul senzor:" << senzor.distantaFataDeUrmatorulSenzor << "; timp de raspuns: " << senzor.timpDeRaspuns << "; conectare de la distanta: " << senzor.conectareaDeLaDistanta << "; situatie critica:" << senzor.situatieCritica << "; interconectare cu alti senzori: " << senzor.interconectareCuAltiSenzori << endl;
		scriere << "Istoric date : ";
		if (senzor.dimensiuneIstoricDate != 0) {
			for (int i = 0; i < senzor.dimensiuneIstoricDate; i++) {
				scriere << senzor.istoricDate[i];
			}
		}
		else
			scriere << "Nu avem istoric de date";
		scriere << endl << "Pozitionare senzor : ";
		if (senzor.pozitionare != nullptr) {
			for (int i = 0; i < strlen(senzor.pozitionare); i++) {
				scriere << senzor.pozitionare[i];
			}
		}
		else
			scriere << "Nu avem pozitionare";
		scriere << (Dispozitiv&)senzor;
		scriere << senzor.profil << endl << endl;
		return scriere;
	}
	//supraincarcare operator>>
	friend istream& operator>>(istream& citire, Senzor& senzor) {
		cout << "numar interactiuni: "; citire >> senzor.numarInteractiuni; cout << "numar resetari: "; citire >> senzor.numarResetari; cout << "durata de viata:"; citire >> senzor.durataDeViata; cout << "dimensiune istoric date:"; citire >> senzor.dimensiuneIstoricDate; cout << "distanta fata de urmatorul senzor:"; citire >> senzor.distantaFataDeUrmatorulSenzor; cout << "timp de raspuns : "; citire >> senzor.timpDeRaspuns; cout << "conectare de la distanta : "; citire >> senzor.conectareaDeLaDistanta; cout << "situatie critica : "; citire >> senzor.situatieCritica; cout << "interconectare cu alti senzori : "; citire >> senzor.interconectareCuAltiSenzori;
		if (senzor.istoricDate != nullptr)
			delete[]senzor.istoricDate;
		senzor.istoricDate = new int[senzor.dimensiuneIstoricDate];
		for (int i = 0; i < senzor.dimensiuneIstoricDate; i++) {
			cout << "Introduceti cod " << i << ": ";
			citire >> senzor.istoricDate[i];
		}
		int dimensiunepozitionare;
		cout << "Introduceti dimensiunea vectorului de pozitionare : ";
		cin >> dimensiunepozitionare;
		if (senzor.pozitionare != nullptr)
			delete[]senzor.pozitionare;
		senzor.pozitionare = new char[dimensiunepozitionare + 1];
		for (int i = 0; i < dimensiunepozitionare; i++) {
			cout << "Introduceti pozitia " << i << "/" << dimensiunepozitionare;
			citire >> senzor.pozitionare[i];
		}
		senzor.pozitionare[dimensiunepozitionare] = '\0';
		citire >> (Dispozitiv&)senzor;
		return citire;
	}
	//supraincarcare ifstream& operator>>
	friend ifstream& operator>>(ifstream& citire, Senzor& senzor) {
		citire >> senzor.numarInteractiuni;
		citire >> senzor.numarResetari;
		citire >> senzor.durataDeViata;
		citire >> senzor.dimensiuneIstoricDate;
		citire >> senzor.distantaFataDeUrmatorulSenzor;
		citire >> senzor.timpDeRaspuns;
		citire >> senzor.conectareaDeLaDistanta;
		citire >> senzor.situatieCritica;
		citire >> senzor.interconectareCuAltiSenzori;
		if (senzor.istoricDate != nullptr)
			delete[]senzor.istoricDate;
		senzor.istoricDate = new int[senzor.dimensiuneIstoricDate];
		for (int i = 0; i < senzor.dimensiuneIstoricDate; i++) {
			citire >> senzor.istoricDate[i];
		}
		int dimensiunepozitionare;
		citire >> dimensiunepozitionare;
		if (senzor.pozitionare != nullptr)
			delete[]senzor.pozitionare;
		senzor.pozitionare = new char[dimensiunepozitionare + 1];
		for (int i = 0; i < dimensiunepozitionare; i++) {
			citire >> senzor.pozitionare[i];
		}
		senzor.pozitionare[dimensiunepozitionare] = '\0';
		citire >> (Dispozitiv&)senzor;
		return citire;
	}
	//supraincarcare operator+
	Senzor operator+(const Senzor& senzor) {
		Senzor s = *this;
		s.durataDeViata = this->durataDeViata + senzor.durataDeViata;
		return s;
	}
	//supraincarcare operator-
	Senzor operator-(const Senzor& senzor) {
		Senzor s = *this;
		if (senzor.durataDeViata > this->durataDeViata)
			s.durataDeViata = senzor.durataDeViata - this->durataDeViata;
		else
			s.durataDeViata = this->durataDeViata - senzor.durataDeViata;
		return s;
	}
	//supraincarcare operator/
	Senzor operator/(const Senzor& senzor) {
		Senzor s = *this;
		s.distantaFataDeUrmatorulSenzor = this->distantaFataDeUrmatorulSenzor / senzor.distantaFataDeUrmatorulSenzor;
		return s;
	}
	//supraincarcare operator++ - post
	Senzor operator++(int) {
		Senzor senzor = *this;
		this->durataDeViata++;
		return senzor;
	}
	//supraincarcare operator++ - pre
	Senzor operator++() {
		this->durataDeViata++;
		return *this;
	}

	//DESTRUCTOR
	~Senzor() {
		if (this->pozitionare != nullptr)
			delete[]this->pozitionare;
		if (this->istoricDate != nullptr)
			delete[]this->istoricDate;
	}
	//getteri
	int getdimensiuneIstoricDate() {
		return this->dimensiuneIstoricDate;
	}
	int getid() {
		return this->id;
	}
	bool gets_a_c() {
		return this->s_a_c;
	}
	int* getistoricDate() {
		if (this->istoricDate != nullptr)
			return this->istoricDate;
		else
			throw new exception("Pointer Nul");
	}
	int getnumarInteractiuni() {
		return this->numarInteractiuni;
	}
	int getnumarResetari() {
		return this->numarResetari;
	}
	int getdurataDeViata() {
		return this->durataDeViata;
	}
	char* getpozitionare() {
		return this->pozitionare;
	}
	char getpozitionare(int index) {
		if (this->pozitionare != nullptr)
			return this->pozitionare[index];
		else {
			throw "Nu avem pozitionare !";
		}
	}
	float getdistantaFataDeUrmatorulSenzor() {
		return this->distantaFataDeUrmatorulSenzor;
	}
	float gettimpDeRaspuns() {
		return this->timpDeRaspuns;
	}
	bool getconectareaDeLaDistanta() {
		return this->conectareaDeLaDistanta;
	}
	string getsituatieCritica() {
		return this->situatieCritica;
	}
	bool getinterconectareCuAltiSenzori() {
		return this->interconectareCuAltiSenzori;
	}
	Profil getprofil() {
		return this->profil;
	}
	//setteri
	void setistoricDate(int* istoricDate) {
		if (istoricDate != nullptr)
			this->istoricDate = istoricDate;
		else
			throw new exception("Asignati un pointer nenul");
	}
	void setdimensiuneIstoricDate(int dimensiuneIstoricDate) {
		if (dimensiuneIstoricDate > 0)
			this->dimensiuneIstoricDate = dimensiuneIstoricDate;
		else
			throw new exception("Ati introdus o dimensiune negativa");
	}
	void setnumarInteractiuni(int numarInteractiuni) {
		if (numarInteractiuni > 0)
			this->numarInteractiuni = numarInteractiuni;
		else
			throw new exception("Ati introdus un numar negativ de interactiuni");
	}
	void setnumarResetari(int numarResetari) {
		if (numarResetari > 0)
			this->numarResetari = numarResetari;
		else
			throw new exception("Ati introdus un numar negativ de resetari");
	}
	void setdurataDeViata(int durataDeViata) {
		if (durataDeViata > 0)
			this->durataDeViata = durataDeViata;
		else
			throw new exception("Ati introdus o durata de viata negativa");
	}
	void setpozitionare(char* pozitionare) {
		if (strlen(pozitionare) > 0)
			this->pozitionare = pozitionare;
		else
			throw new exception("Asignati un pointer nenul");
	}
	void setdistantaFataDeUrmatorulSenzor(float distantaFataDeUrmatorulSenzor) {
		if (distantaFataDeUrmatorulSenzor > 0)
			this->distantaFataDeUrmatorulSenzor = distantaFataDeUrmatorulSenzor;
		else
			throw new exception("Ati introdus o distanta negativa fata de urmatorul senzor");
	}
	void settimpDeRaspuns(float timpDeRaspuns) {
		if (timpDeRaspuns > 0)
			this->timpDeRaspuns = timpDeRaspuns;
		else
			throw new exception("Ati introdus un timp de raspuns negativ");
	}
	void setconectareaDeLaDistanta(bool conectareaDeLaDistanta) {
		this->conectareaDeLaDistanta = conectareaDeLaDistanta;
	}
	void setsituatieCritica(const string& situatieCritica) {
		if (situatieCritica.length() > 0)
			this->situatieCritica = situatieCritica;
		else
			throw new exception("Introduceti un string existent");
	}
	void setinterconectareCuAltiSenzori(bool interconectareCuAltiSenzori) {
		this->interconectareCuAltiSenzori = interconectareCuAltiSenzori;
	}
	void setprofil(const Profil& profil) {
		this->profil = profil;
	}
	string sunetEmis() {
		return "bipbip";
	}
};
class CasaInteligenta {
private:
	int numarSenzori;
	Senzor** totalitateSenzori;
	float Rating = 0;
public:
	static void corectares_a_c(Senzor** s , int marime) {
		if (s != nullptr) {
			for (int i = 0; i < marime; i++) {
				if (s[i] != nullptr) {
					s[i]->s_a_c = 1;
				}
				else
					throw new exception("Vectorul contie un senzor null");
			}
		}
		else
			throw new exception("Vectorul nu contine senzori!");
	}
	//getteri
	float getrating() {
		return this->Rating;
	}
	int getnumarSenzori() {
		return this->numarSenzori;
	}
	Senzor** gettotalitateSenzori() {
		if (this->totalitateSenzori != nullptr)
			return this->totalitateSenzori;
		else
			throw new exception("Casa inteligenta nu contine senzori!");
	}
	//setteri
	void setrating(float Rating) {
		if (Rating > 0)
			this->Rating = Rating;
		else
			throw new exception("Ati introdus un rating negativ");
	}
	void setnumarSenzori(int numarSenzori) {
		if (numarSenzori > 0) {
			if (numarSenzori < this->numarSenzori) {
				Senzor** senzornou;
				senzornou = new Senzor * [this->numarSenzori];
				for (int i = 0; i < this->numarSenzori; i++) {
					senzornou[i] = this->totalitateSenzori[i];
				}
				delete[]this->totalitateSenzori;
				int a = this->numarSenzori;
				this->numarSenzori = numarSenzori;
				this->totalitateSenzori = new Senzor * [numarSenzori];
				for (int i = 0; i < this->numarSenzori; i++) {
					this->totalitateSenzori[i] = senzornou[i];
				}
				delete[]senzornou;
			}
			else if (numarSenzori > this->numarSenzori) {
				Senzor** senzornou;
				senzornou = new Senzor * [this->numarSenzori];
				for (int i = 0; i < this->numarSenzori; i++) {
					senzornou[i] = this->totalitateSenzori[i];
				}
				delete[]this->totalitateSenzori;
				int a = this->numarSenzori;
				this->numarSenzori = numarSenzori;
				this->totalitateSenzori = new Senzor * [numarSenzori];
				for (int i = 0; i < this->numarSenzori; i++) {
					this->totalitateSenzori[i] = new Senzor();
				}
				for (int i = 0; i <a; i++) {
					this->totalitateSenzori[i] = senzornou[i];
				}
				delete[]senzornou;
			}
			else
				throw new exception("Vectorul deja contine aceasta dimensiune !");
		}
		else
			throw new exception("Ati introdus un numar negativ de senzori");
	}
	void settotalitateSenzori(Senzor** senzori) {
		if (senzori != nullptr)
			this->totalitateSenzori = senzori;
		else
			throw new exception("Introduceti un pointer nenul");
	}
	//constructorul DEFAULT
	CasaInteligenta() {
		this->numarSenzori = 0;
		this->totalitateSenzori = nullptr;
	}
	//constructorul cu parametrii
	CasaInteligenta(int numarSenzori, Senzor** totalitateSenzori) {
		if (numarSenzori <= 0)
			throw new exception("Ati introdus un numar negativ de senzori");
		if (totalitateSenzori == nullptr)
			throw new exception("Introduceti un pointer nenul");
		this->numarSenzori = numarSenzori;
		this->totalitateSenzori = new Senzor*[numarSenzori];
		for (int i = 0; i < numarSenzori; i++) {
			this->totalitateSenzori[i] = totalitateSenzori[i];
		}
		//modificare s_a_c
		for (int i = 0; i < numarSenzori; i++) {
			this->totalitateSenzori[i]->s_a_c = 1;
		}
	}
	//constructorul de copiere
	CasaInteligenta(const CasaInteligenta& casainteligenta) {
		this->numarSenzori = casainteligenta.numarSenzori;
		this->totalitateSenzori = new Senzor*[casainteligenta.numarSenzori];
		for (int i = 0; i < this->numarSenzori; i++) {
			this->totalitateSenzori[i] = new Senzor();
		}
		for (int i = 0; i < casainteligenta.numarSenzori; i++) {
			*this->totalitateSenzori[i] = *casainteligenta.totalitateSenzori[i];
		}
		//modificare s_a_c
		for (int i = 0; i < numarSenzori; i++) {
			this->totalitateSenzori[i]->s_a_c = 1;
		}
		this->Rating = casainteligenta.Rating;
	}
	//supraincarcare operator=
	CasaInteligenta operator=(const CasaInteligenta& casainteligenta) {
		if (this->totalitateSenzori != nullptr) {
			delete[]this->totalitateSenzori;
		}
		this->numarSenzori = casainteligenta.numarSenzori;
		this->totalitateSenzori = new Senzor*[casainteligenta.numarSenzori];
		for (int i = 0; i < this->numarSenzori; i++) {
			this->totalitateSenzori[i] = new Senzor();
		}
		for (int i = 0; i < casainteligenta.numarSenzori; i++) {
			*this->totalitateSenzori[i] = *casainteligenta.totalitateSenzori[i];
		}
		//modificare s_a_c
		for (int i = 0; i < numarSenzori; i++) {
			this->totalitateSenzori[i]->s_a_c = 1;
		}
		this->Rating = casainteligenta.Rating;
		return *this;
	}
	//supraincarcare operator<<
	friend ostream& operator<<(ostream& scriere, const CasaInteligenta& casainteligenta) {
		scriere << "Numar senzori casa inteligenta : " << casainteligenta.numarSenzori << endl;
		for (int i = 0; i < casainteligenta.numarSenzori; i++) {
			scriere << "Senzor " << i + 1 << " :" << endl;
			scriere << *casainteligenta.totalitateSenzori[i];
		}
		scriere << endl << "Rating Casa Inteligenta: " << casainteligenta.Rating << endl;
		return scriere;
	}
	//supraincarcare operator>>
	friend istream& operator>>(istream& citire, CasaInteligenta& casainteligenta) {
		cout << "Introduceti numar de senzori : "; citire >> casainteligenta.numarSenzori;
		if (casainteligenta.totalitateSenzori != nullptr) {
			delete[]casainteligenta.totalitateSenzori;
		}
		casainteligenta.totalitateSenzori = new Senzor*[casainteligenta.numarSenzori];
		for (int i = 0; i < casainteligenta.numarSenzori; i++) {
			casainteligenta.totalitateSenzori[i] = new Senzor();
		}
		for (int i = 0; i < casainteligenta.numarSenzori; i++) {
			cout << "Introduceti senzorul " << i << " :"<<endl;
			citire >> *casainteligenta.totalitateSenzori[i];
		}
		corectares_a_c(casainteligenta.totalitateSenzori, casainteligenta.numarSenzori);
		return citire;
	}
	//supraincarcare ifstream& operator>>
	friend ifstream& operator>>(ifstream& citire, CasaInteligenta& casainteligenta) {
		citire >> casainteligenta.numarSenzori;
		if (casainteligenta.totalitateSenzori != nullptr) {
			delete[]casainteligenta.totalitateSenzori;
		}
		casainteligenta.totalitateSenzori = new Senzor*[casainteligenta.numarSenzori];
		for (int i = 0; i < casainteligenta.numarSenzori; i++) {
			casainteligenta.totalitateSenzori[i] = new Senzor();
		}
		for (int i = 0; i < casainteligenta.numarSenzori; i++) {
			citire >> *casainteligenta.totalitateSenzori[i];
		}
		corectares_a_c(casainteligenta.totalitateSenzori, casainteligenta.numarSenzori);
		return citire;
	}
	//supraincarcare operator++ - post
	CasaInteligenta operator++(int) {
		CasaInteligenta casainteligenta = *this;
		for (int i = 0; i < this->numarSenzori; i++) {
			(*this->totalitateSenzori[i])++;
		}
		return casainteligenta;
	}
	//supraincarcare operator++ - pre
	CasaInteligenta operator++() {
		for (int i = 0; i < this->numarSenzori; i++) {
			(*this->totalitateSenzori[i])++;
		}
		return *this;
	}
	//supraincarcare operator+
	CasaInteligenta operator+(const CasaInteligenta& casainteligenta) {
		if (this->numarSenzori >= casainteligenta.numarSenzori) {
			CasaInteligenta casa = *this;
			for (int i = 0; i < casainteligenta.numarSenzori; i++) {
				*casa.totalitateSenzori[i] = *this->totalitateSenzori[i] + *casainteligenta.totalitateSenzori[i];
			}
			return casa;
		}
		else if (this->numarSenzori < casainteligenta.numarSenzori) {
			CasaInteligenta casa = casainteligenta;
			for (int i = 0; i < this->numarSenzori; i++) {
				*casa.totalitateSenzori[i] = *this->totalitateSenzori[i] + *casainteligenta.totalitateSenzori[i];
			}
			return casa;
		}
	}
	//supraincarcare operator-
	CasaInteligenta operator-(const CasaInteligenta& casainteligenta) {
		if (this->numarSenzori >= casainteligenta.numarSenzori) {
			CasaInteligenta casa = *this;
			for (int i = 0; i < casainteligenta.numarSenzori; i++) {
				*casa.totalitateSenzori[i] = *this->totalitateSenzori[i] - *casainteligenta.totalitateSenzori[i];
			}
			return casa;
		}
		else if (this->numarSenzori < casainteligenta.numarSenzori) {
			CasaInteligenta casa = casainteligenta;
			for (int i = 0; i < this->numarSenzori; i++) {
				*casa.totalitateSenzori[i] = *casainteligenta.totalitateSenzori[i] - *this->totalitateSenzori[i];
			}
			return casa;
		}
	}
	//supraincarcare operator/
	CasaInteligenta operator/(const CasaInteligenta& casainteligenta) {
		if (this->numarSenzori >= casainteligenta.numarSenzori) {
			CasaInteligenta casa = *this;
			for (int i = 0; i < casainteligenta.numarSenzori; i++) {
				*casa.totalitateSenzori[i] = *this->totalitateSenzori[i] / *casainteligenta.totalitateSenzori[i];
			}
			return casa;
		}
		else if (this->numarSenzori < casainteligenta.numarSenzori) {
			CasaInteligenta casa = casainteligenta;
			for (int i = 0; i < this->numarSenzori; i++) {
				*casa.totalitateSenzori[i] = *casainteligenta.totalitateSenzori[i] / *this->totalitateSenzori[i];
			}
			return casa;
		}
	}
	~CasaInteligenta() {
		if (this->totalitateSenzori != nullptr) {
			for (int i = 0; i < this->numarSenzori; i++){
				if (this->totalitateSenzori[i] != nullptr) {
					delete this->totalitateSenzori[i];
				}
			}
			delete[]this->totalitateSenzori;
		}	
	}
};


int  Senzor::contor = 1;

void scriereProfilCasaInteligentaInCaleaFisieruluiIntrodusDeLaTastatura(CasaInteligenta& casainteligenta) {
	string caleFisier;
	cout << "Introduceti calea fisierului : "<<endl; cin >> caleFisier;
	ofstream file(caleFisier, ios::out);
	if (!file.is_open()) {
		cout << endl << "Nu exista fisierul cu calea : " << caleFisier;
	}
	else {
		Senzor** senzori = new Senzor*[casainteligenta.getnumarSenzori()];
		for (int i = 0; i < casainteligenta.getnumarSenzori(); i++) {
			senzori[i] = casainteligenta.gettotalitateSenzori()[i];
		}
		Profil* profile = new Profil[casainteligenta.getnumarSenzori()];
		for (int i = 0; i < casainteligenta.getnumarSenzori(); i++) {
			profile[i] = senzori[i]->getprofil();
		}
		file << "Numar Senzori : " << casainteligenta.getnumarSenzori() << endl << endl << endl;
		for (int i = 0; i < casainteligenta.getnumarSenzori(); i++) {
			file << "Profil Senzor " << i << " : ";
			file << profile[i];
		}
		file << endl;
		file << "Rating Casa Inteligenta : " << casainteligenta.getrating();
		delete[]senzori;
		delete[]profile;
		file.close();
	}
}
void exceptieDacaSenzorulNuApartineSistemuluiIoT(Senzor* senzor) {
	if (senzor->gets_a_c() == 0)
		throw new exception("Senzorul nu face parte din sistemul IoT !");
}
float stabilireRatingIntermediarSenzor(Senzor& senzor) {
	Profil profil = senzor.getprofil();
	float ratingIntermediar = 0;
	if (profil.gettipRetea(0) == 's' && profil.getclasa(0) == 'm' && profil.getgarantie() > 20 && profil.getwaterproof() == 1)
		ratingIntermediar = 10;
	else if (profil.gettipRetea(0) == 's' && profil.getclasa(0) == 'm' && profil.getgarantie() > 20 && profil.getwaterproof() == 0)
		ratingIntermediar = 9.8;
	else if (profil.gettipRetea(0) == 's' && profil.getclasa(0) == 'm' && profil.getgarantie() < 20 && profil.getwaterproof() == 1)
		ratingIntermediar = 9.6;
	else if (profil.gettipRetea(0) == 's' && profil.getclasa(0) == 's' && profil.getgarantie() > 20 && profil.getwaterproof() == 1)
		ratingIntermediar = 9.4;
	else if (profil.gettipRetea(0) == 's' && profil.getclasa(0) == 'm' && profil.getgarantie() < 20 && profil.getwaterproof() == 0)
		ratingIntermediar = 9.2;
	else if (profil.gettipRetea(0) == 's' && profil.getclasa(0) == 's' && profil.getgarantie() > 20 && profil.getwaterproof() == 0)
		ratingIntermediar = 9;
	else if (profil.gettipRetea(0) == 's' && profil.getclasa(0) == 's' && profil.getgarantie() < 20 && profil.getwaterproof() == 1)
		ratingIntermediar = 8.8;
	else if (profil.gettipRetea(0) == 's' && profil.getclasa(0) == 's' && profil.getgarantie() < 20 && profil.getwaterproof() == 0)
		ratingIntermediar = 8.6;
	else if (profil.gettipRetea(0) == 'a' && profil.getclasa(0) == 'm' && profil.getgarantie() > 20 && profil.getwaterproof() == 1)
		ratingIntermediar = 8.4;
	else if (profil.gettipRetea(0) == 'a' && profil.getclasa(0) == 'm' && profil.getgarantie() > 20 && profil.getwaterproof() == 0)
		ratingIntermediar = 8.2;
	else if (profil.gettipRetea(0) == 'a' && profil.getclasa(0) == 'm' && profil.getgarantie() < 20 && profil.getwaterproof() == 1)
		ratingIntermediar = 8;
	else if (profil.gettipRetea(0) == 'a' && profil.getclasa(0) == 's' && profil.getgarantie() > 20 && profil.getwaterproof() == 1)
		ratingIntermediar = 7.8;
	else if (profil.gettipRetea(0) == 'a' && profil.getclasa(0) == 'm' && profil.getgarantie() < 20 && profil.getwaterproof() == 0)
		ratingIntermediar = 7.6;
	else if (profil.gettipRetea(0) == 'a' && profil.getclasa(0) == 's' && profil.getgarantie() > 20 && profil.getwaterproof() == 0)
		ratingIntermediar = 7.4;
	else if (profil.gettipRetea(0) == 'a' && profil.getclasa(0) == 's' && profil.getgarantie() < 20 && profil.getwaterproof() == 1)
		ratingIntermediar = 7.2;
	else if (profil.gettipRetea(0) == 'a' && profil.getclasa(0) == 's' && profil.getgarantie() < 20 && profil.getwaterproof() == 0)
		ratingIntermediar = 7;
	else if (profil.gettipRetea(0) == 'p' && profil.getclasa(0) == 'm' && profil.getgarantie() > 20 && profil.getwaterproof() == 1)
		ratingIntermediar = 6.8;
	else if (profil.gettipRetea(0) == 'p' && profil.getclasa(0) == 'm' && profil.getgarantie() > 20 && profil.getwaterproof() == 0)
		ratingIntermediar = 6.6;
	else if (profil.gettipRetea(0) == 'p' && profil.getclasa(0) == 'm' && profil.getgarantie() < 20 && profil.getwaterproof() == 1)
		ratingIntermediar = 6.4;
	else if (profil.gettipRetea(0) == 'p' && profil.getclasa(0) == 's' && profil.getgarantie() > 20 && profil.getwaterproof() == 1)
		ratingIntermediar = 6.2;
	else if (profil.gettipRetea(0) == 'p' && profil.getclasa(0) == 'm' && profil.getgarantie() < 20 && profil.getwaterproof() == 0)
		ratingIntermediar = 6;
	else if (profil.gettipRetea(0) == 'p' && profil.getclasa(0) == 's' && profil.getgarantie() > 20 && profil.getwaterproof() == 0)
		ratingIntermediar = 5.8;
	else if (profil.gettipRetea(0) == 'p' && profil.getclasa(0) == 's' && profil.getgarantie() < 20 && profil.getwaterproof() == 1)
		ratingIntermediar = 5.6;
	else if (profil.gettipRetea(0) == 'p' && profil.getclasa(0) == 's' && profil.getgarantie() < 20 && profil.getwaterproof() == 0)
		ratingIntermediar = 5.4;
	else if (profil.gettipRetea(0) == 'c' && profil.getclasa(0) == 'm' && profil.getgarantie() > 20 && profil.getwaterproof() == 1)
		ratingIntermediar = 5.2;
	else if (profil.gettipRetea(0) == 'c' && profil.getclasa(0) == 'm' && profil.getgarantie() > 20 && profil.getwaterproof() == 0)
		ratingIntermediar = 5;
	else if (profil.gettipRetea(0) == 'c' && profil.getclasa(0) == 'm' && profil.getgarantie() < 20 && profil.getwaterproof() == 1)
		ratingIntermediar = 4.8;
	else if (profil.gettipRetea(0) == 'c' && profil.getclasa(0) == 's' && profil.getgarantie() > 20 && profil.getwaterproof() == 1)
		ratingIntermediar = 4.6;
	else if (profil.gettipRetea(0) == 'c' && profil.getclasa(0) == 'm' && profil.getgarantie() < 20 && profil.getwaterproof() == 0)
		ratingIntermediar = 4.4;
	else if (profil.gettipRetea(0) == 'c' && profil.getclasa(0) == 's' && profil.getgarantie() > 20 && profil.getwaterproof() == 0)
		ratingIntermediar = 4.2;
	else if (profil.gettipRetea(0) == 'c' && profil.getclasa(0) == 's' && profil.getgarantie() < 20 && profil.getwaterproof() == 1)
		ratingIntermediar = 4;
	else if (profil.gettipRetea(0) == 'c' && profil.getclasa(0) == 's' && profil.getgarantie() < 20 && profil.getwaterproof() == 0)
		ratingIntermediar = 3.8;
	else
		ratingIntermediar = 0;
	return ratingIntermediar;

}
void stabilireRatingCasaInteligenta(CasaInteligenta& casainteligenta) {
	float suma = 0;
	for (int i = 0; i < casainteligenta.getnumarSenzori(); i++) {
		suma += stabilireRatingIntermediarSenzor(*casainteligenta.gettotalitateSenzori()[i]) / casainteligenta.getnumarSenzori();
	}
	if (suma == 0)
		throw new exception("Senzorii casei inteligente nu au profilele realizate !");
	casainteligenta.setrating(suma);
}
void stabilireProfilSenzor(Senzor& senzor) {
	Profil profil;
	if (senzor.getinterconectareCuAltiSenzori() == true)
		profil.setclasa("monitorizare");
	else
		profil.setclasa("supraveghere");
	float formula;
	formula = (senzor.getdurataDeViata() + senzor.getnumarResetari()) / 2 + senzor.getnumarInteractiuni() / 4;
	profil.setgarantie(formula);
	if (senzor.getpozitionare(0) == 'b')
		profil.setwaterproof(1);
	else if (senzor.getpozitionare(0) == 'B')
		profil.setwaterproof(1);
	else
		profil.setwaterproof(0);
	if (senzor.getconectareaDeLaDistanta() && senzor.gettimpDeRaspuns() < 1)
		profil.settipRetea("satelit");
	else if (senzor.getconectareaDeLaDistanta() && senzor.gettimpDeRaspuns() >= 1)
		profil.settipRetea("antena");
	else if (!senzor.getconectareaDeLaDistanta() && senzor.gettimpDeRaspuns() < 1)
		profil.settipRetea("peertopeer");
	else
		profil.settipRetea("cablu");
	senzor.setprofil(profil);
}
void stabilireProfilSenzoriCasaInteligenta(CasaInteligenta& casainteligenta) {
	if (casainteligenta.gettotalitateSenzori() != nullptr) {
		for (int i = 0; i < casainteligenta.getnumarSenzori(); i++) {
			stabilireProfilSenzor(*casainteligenta.gettotalitateSenzori()[i]);
		}
	}
	else
		throw new exception("Casa inteligenta nu contine senzori!");
}
void citireCasaInteligentaDinFisier(CasaInteligenta& casainteligenta) {
	ifstream fisier("SENZORI.txt", ios::in);
	if (!fisier.is_open())
		cout << endl << "Nu exista fisierul cu numele : senzori.txt";
	else {
		fisier >> casainteligenta;
		fisier.close();
	}
}
void exemplificareUtilitateFunctiiVirtuale(Senzor& senzor) {
	Dispozitiv& dispozitiv = (Dispozitiv&)senzor;
	cout << senzor.sunetEmis() << endl;
	cout << dispozitiv.sunetEmis();
}
void main() {
	try {
		int a = 2;
		Senzor** s = new Senzor * [a];
		s[0] =new Senzor(30, 40, 40, new int[3]{ 1,2,3 }, 3, new char[10]{ 'b','u','c','a','t','a','r','i','e' }, 0.2, 0.2, true, "lipsasemnal", true, 2022, 160.5);
		s[1]=new Senzor(4, 4, 4, new int[4]{ 6 , 9 , 7 , 5 }, 4, new char[4]{ 'h' , 'o' , 'l' }, 4.3, 18.9, true, "lipsabaterie", false, 2005, 80.3);
		//exceptieDacaSenzorulNuApartineSistemuluiIoT(s[0]);
		CasaInteligenta casainteligenta(2, s);
		//citireCasaInteligentaDinFisier(casainteligenta);
		cin>>casainteligenta;
		cout << casainteligenta;
		stabilireProfilSenzoriCasaInteligenta(casainteligenta);
		stabilireRatingCasaInteligenta(casainteligenta);
		scriereProfilCasaInteligentaInCaleaFisieruluiIntrodusDeLaTastatura(casainteligenta);
		//exceptieDacaSenzorulNuApartineSistemuluiIoT(s[0]);
		//exemplificareUtilitateFunctiiVirtuale(*s[0]);

		//Operatori<Senzor>s(2, new Senzor[2]{ *s[0],*s[1] });
		if (s != nullptr) {
			delete[]s;
		}
	}
	catch (exception* exceptie) {
		cout << exceptie->what();
	}
	catch (...) {
		cout << "A intervenit o problema necunoscuta";
	}
}
