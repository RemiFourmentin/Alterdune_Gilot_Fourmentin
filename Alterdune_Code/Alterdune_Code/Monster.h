#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Monster
{
private:
	string categorie;
	string nom;
	int statistiques[3]; //hp, atk, def
	int mercyGoal;
	string act[4];
	int compteur;

public:
	Monster() {}

	Monster(string ligne) {
		stringstream ss(ligne);
		getline(ss, this->categorie, ';');
		getline(ss, this->nom, ';');
		string tampon;
		for (int i = 0; i < 3; i++) {
			getline(ss, tampon, ';');
			this->statistiques[i] = stoi(tampon);
		}
		getline(ss, tampon, ';');
		this->mercyGoal = stoi(tampon);
		for (int i = 0; i < 4; i++) {
			getline(ss, this->act[i], ';');
		}
		this->compteur = -1;
	}

	string getCategorie() { return this->categorie; }
	string getNom() { return this->nom; }
	int* getStatistiques() { return this->statistiques; }
	int getMercyGoal() { return this->mercyGoal; }
	string* getAct() { return this->act; }
	int getCompteur() { return this->compteur; }

	void setCompteur(int compteur) { this->compteur = compteur; }

	void afficherMonster() {
		cout << this->categorie << " " << this->nom << " " << this->statistiques[0] << " " << this->statistiques[1] << " " << this->statistiques[2] << " " << this->mercyGoal << " " << this->act[0] << " " << this->act[1] << " " << this->act[2] << " " << this->act[3] << endl;
	}
};