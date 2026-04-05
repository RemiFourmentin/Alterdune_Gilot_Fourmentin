#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Item
{
private:
	string nom;
	string type;
	int valeur;
	int quantite;
	int compteur;

public:
	Item() {}

	Item(string ligne) {
		stringstream ss(ligne);
		getline(ss, this->nom, ';');
		getline(ss, this->type, ';');
		string val;
		getline(ss, val, ';');
		this->valeur = stoi(val);
		string quant;
		getline(ss, quant);
		this->quantite = stoi(quant);
		this->compteur = -1;
	}

	string getNom() { return this->nom; }
	string getType() { return this->type; }
	int getValeur() { return this->valeur; }
	int getQuantite() { return this->quantite; }
	int getCompteur() { return this->compteur; }

	void setCompteur(int compteur) { this->compteur = compteur; }

	void afficherItem() {
		cout << this->nom << " " << this->type << " " << this->valeur << " " << this->quantite << endl;
	}
};