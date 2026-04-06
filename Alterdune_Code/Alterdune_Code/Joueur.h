#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Item.h"
#include "Monster.h"
using namespace std;

class Joueur
{
private:
	string nom;
	int statistiques[4]; //hpmax, atk, def, mercy
	int hp;
	Item* listeItems;
	int victoires;
	int tues;
	int epargnes;
	Monster* bestiaire;

public:
	Joueur(string nom) { 
		this->nom = nom;
		this->statistiques[0] = 100;
		this->statistiques[1] = 20;
		this->statistiques[2] = 80;
		this->statistiques[3] = 50;
		this->hp = 100;
		this->victoires = 0;
		this->tues = 0;
		this->epargnes = 0;
		Monster* bestiaire;
		bestiaire->setCompteur(0);
		this->bestiaire = bestiaire;
	}
	
	string getNom() { return this->nom; }
	int* getStatistiques() { return this->statistiques; }
	int getHp() { return this->hp; }
	Item* getListeItems() { return this->listeItems; }
	int getVictoire() { return this->victoires; }
	int getTues() { return this->tues; }
	int getEpagnes() { return this->epargnes; }
	Monster* getBestiaire() { return this->bestiaire; }

	void AjouterMonstre(Monster monstre) {
		Monster* bestiaire = new Monster[this->bestiaire->getCompteur() + 1];
		bestiaire->setCompteur(this->bestiaire->getCompteur() + 1);
		for (int i = 0; i < this->bestiaire->getCompteur(); i++) {
			bestiaire[i] = this->bestiaire[i];
		}
		bestiaire[this->bestiaire->getCompteur()] = monstre;
		this->bestiaire = bestiaire;
	}

	void Tue(Monster monstre) {
		this->tues++;
		this->victoires++;
		AjouterMonstre(monstre);
	}

	void Epargne(Monster monstre) {
		this->epargnes++;
		this->victoires++;
		AjouterMonstre(monstre);
	}

	void afficherStatistiques() {
		cout << this->hp <<"/"<< this->statistiques[0] <<" HP"<< endl;
		cout << this->statistiques[1] << " ATK" << endl;
		cout << this->statistiques[2] << " DEF" << endl;
		cout << "STATUT: ";
		if (this->statistiques[3] < 20) {
			cout << "Meurtrier impitoyable" << endl;
		}
		else if (this->statistiques[3] < 50) {
			cout << "Guerrier insensible" << endl;
		}
		else if (this->statistiques[3] < 80) {
			cout << "Combattant diplomate" << endl;
		}
		else {
			cout << "Pacificateur magnanime" << endl;
		}
		cout << "Victoires: " << this->victoires << " (" << this->tues << " tué(s), " << this->epargnes << " epargné(s))";
	}
};

