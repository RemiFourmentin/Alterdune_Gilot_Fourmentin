#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "item.h"
#include "monster.h"
#include "Joueur.h"
#include <cstdlib>
#include <ctime>
#include "Combat.h"

#include <filesystem>
using namespace std;

void MenuPrincipal(Joueur j, Item* tabitems, Monster* tabmonsters);

void Partie(Joueur j, Item* tabitems, Monster* tabmonsters){
	int random = rand() % tabmonsters->getCompteur();
	Monster monstre = tabmonsters[random];
	Combat comb(monstre, j);
	char c = ' ';
	while (!comb.getFin()) {
		comb.afficherMenu();
		cin >> c;
		system("cls");
		switch(c){
			case 'F':
				comb.Fight();
				break;

			case 'A':
				comb.Act();
				break;

			case 'I':
				comb.UseItem();
				break;

			case 'M':
				comb.Mercy();
				break;

			default:
				break;
		}
	}
}

void Bestiaire(Joueur j, Item* tabitems, Monster* tabmonsters) {

	std::cout << "BESTIAIRE" << endl << endl;
	for (int i = 0; i < j.getBestiaire()->getCompteur(); i++) {
		j.getBestiaire()[i].afficherMonster();
	}
	cout << endl << endl << "--Quitter [Q]";
	char c = ' ';
	while (c != 'Q') {
		cin >> c;
	}
	system("cls");
	MenuPrincipal(j, tabitems, tabmonsters);
}

void Statistiques(Joueur j, Item* tabitems, Monster* tabmonsters) {

	cout << "STATISTIQUES " << j.getNom() << endl << endl;
	j.afficherStatistiques();
	cout << endl << endl << "--Quitter [Q]";
	char c = ' ';
	while (c != 'Q') {
		cin >> c;
	}
	system("cls");
	MenuPrincipal(j, tabitems, tabmonsters);
}

void Items(Joueur j, Item* tabitems, Monster* tabmonsters) {

	std::cout << "INVENTAIRE ITEMS" << endl << endl;
	for (int i = 0; i < j.getListeItems()->getCompteur(); i++) {
		j.getListeItems()[i].afficherItem();
	}
	cout << endl << endl<< "--Quitter [Q]";
	char c = ' ';
	while (c != 'Q') {
		cin >> c;
	}
	system("cls");
	MenuPrincipal(j, tabitems, tabmonsters);
}

void MenuPrincipal(Joueur j, Item* tabitems, Monster* tabmonsters) {

	char c = ' ';
	while (c != 'Q') {
		std::cout << "MENU PRINCIPAL" << endl << endl;
		std::cout << "--Bestiaire [B]" << endl << "--Demarrer un combat [D]" << endl << "--Statistiques du personnage [S]" << endl << "--Items [I]" << endl << "--Quitter [Q]"<<endl<<endl;
		cin >> c;
		system("cls");
		switch (c) {
		case 'B':
			Bestiaire(j, tabitems, tabmonsters);
			break;

		case 'D':
			Partie(j, tabitems, tabmonsters);
			break;

		case 'S':
			Statistiques(j, tabitems, tabmonsters);
			break;

		case 'I':
			Items(j, tabitems, tabmonsters);
			break;

		case 'Q':
			std::cout << "FIN DU PROGRAMME";
			break;

		default:
			break;
		}
	}
}

Item* RecupItems() {
	ifstream items("../../../items.csv");
	string ligne;
	int lcompt = 0;
	while (getline(items, ligne)) { lcompt++; }
	items.clear();
	items.seekg(0);
	Item* tabitems = new Item[lcompt];
	ligne = "";
	int i = 0;
	while (getline(items, ligne)) {
		Item it(ligne);
		tabitems[i] = it;
		i++;
	}
	items.close();
	tabitems->setCompteur(lcompt);
	return tabitems;
}

Monster* RecupMonsters() {
	ifstream monsters("../../../monsters.csv");
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

void LancementJeu() {
	std::cout << "saisissez le nom de votre personnage: " << endl;
	string nom;
	cin >> nom;
	Joueur j(nom);
	Item* tabitems = RecupItems();
	Monster* tabmonsters = RecupMonsters();
	srand(time(0));
	system("cls");
	MenuPrincipal(j, tabitems, tabmonsters);
}

int main() {
	LancementJeu();
}