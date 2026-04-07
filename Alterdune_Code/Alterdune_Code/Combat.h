#pragma once
#include "Monster.h"
#include "Joueur.h"
#include "Item.h"
class Combat
{
private:
	Monster monstre;
	Joueur j;
	bool fin;

public:
	Combat(Monster monstre, Joueur j) {
		this->monstre = monstre;
		this->j = j;
		this->fin = false;
	}

	void FinCombat() {
		if (j.getHp() > 0 || monstre.getHp() > 0 || j.getStatistiques()[3] < monstre.getMercyGoal()) {
			this->fin = true;
		}
	}

	void afficherMenu() {
		cout << "FIGHT [F]" << endl << "ACT [A]" << endl << "ITEM [I]" << endl << "Mercy [M]" << endl;
	}

	void Fight() {
		int degats = rand() % this->monstre.getStatistiques()[0];
		if (degats == 0) {
			cout << "Raté... " << this->monstre.getNom() << " ne prend aucun degats";
		}
		if (degats > this->monstre.getStatistiques()[0] * 0.8 && this->monstre.getHp() > this->monstre.getStatistiques()[0] * 0.6) {
			cout << "Arghh... " << this->monstre.getNom() << " a ete tranche dans le vif";
		}
		this->monstre.Degats(degats);
		if (this->monstre.getHp() == 0) {
			this->j.Tue(this->monstre);
		}
	}

	void Act() {}

	void UseItem() {}

	void Mercy() {}

	bool getFin() { return this->fin; }
};

