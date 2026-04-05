#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "item.h"
#include "monster.h"
using namespace std;


Item* RecupItems() {
	ifstream items("../../items.csv");
	string ligne;
	int lcompt = 0;
	while (getline(items, ligne)) { lcompt++; }
	items.clear();
	items.seekg(0);
	Item* tabitems = new Item[lcompt];
	ligne = "";
	int i = 0;
	while(getline(items, ligne)) {
		Item it(ligne);
		tabitems[i] = it;
		i++;
	}
	items.close();
	tabitems->setCompteur(lcompt);
	return tabitems;
}

Monster* RecupMonsters() {
	ifstream monsters("../../monsters.csv");
	string ligne;
	int lcompt = 0;
	while (getline(monsters, ligne)) { lcompt++; }
	monsters.clear();
	monsters.seekg(0);
	Monster* tabmonsters = new Monster[lcompt];
	ligne = "";
	int i = 0;
	while (getline(monsters, ligne)) {
		Monster mon(ligne);
		tabmonsters[i] = mon;
		i++;
	}
	monsters.close();
	tabmonsters->setCompteur(lcompt);
	return tabmonsters;
}

void Partie() {
	cout << "nom du joueur: " << endl;
	string nomjoueur = "";
	cin >> nomjoueur;
	cout << endl;
	Item* tabitems = RecupItems();
	cout << "Items:" << endl;
	for (int i = 0; i < tabitems->getCompteur(); i++) {
		tabitems[i].afficherItem();
	}
	cout << endl;
	Monster* tabmonsters = RecupMonsters();
	cout << "Monstres:" << endl;
	for (int i = 0; i < tabmonsters->getCompteur(); i++) {
		tabmonsters[i].afficherMonster();
	}
}


int main() {
    Partie();
}