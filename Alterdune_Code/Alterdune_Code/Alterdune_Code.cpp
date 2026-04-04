#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(){}

void Partie() {
	cout << "nom du joueur: " << endl;
	string nomjoueur = "";
	cin >> nomjoueur;

	ifstream items("items.csv");
	string ligne;
	getline(items, ligne);

    while (getline(items, ligne)) {
        stringstream ss(ligne);
        string colonne;

        while (getline(ss, colonne, ';')) {
            cout << colonne << " ";
        }
        std::cout << std::endl;
    }

    items.close();
}