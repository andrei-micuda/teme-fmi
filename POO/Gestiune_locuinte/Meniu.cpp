#include <iostream>
#include <set>
#include <utility>
#include "Gestiune.h"

int main() {
	std::set<std::pair<Locuinta*, std::string>> evidentaTotala;
	Gestiune<Apartament> evidentaApartamente;
	Gestiune<Casa> evidentaCase;
	int op;
	do {
		std::cout << "GESTIUNE LOCUINTE:\n";
		std::cout << "1. Adauga apartament\n";
		std::cout << "2. Adauga casa\n";
		std::cout << "3. Afiseaza toate locuintele\n";
		std::cout << "4. Afiseaza apartament\n";
		std::cout << "5. Afiseaza casa\n";
		std::cout << "6. Calculeaza chiria\n";
		std::cout << "7. Calculeaza chiria totala case\n";
		std::cout << "0. Exit\n";

		std::cin >> op;
		std::cout << "\n\n";
		if (op == 1) {
			std::cout << "1. Adauga apartament\n\n";
			Apartament* ap = new Apartament();
			try {
				std::cin >> (*ap);
			}
			catch (std::exception& e) {
				std::cout << e.what();
			}
			
			evidentaApartamente += (*ap);
			evidentaTotala.insert(std::make_pair(ap, ap->what()));
		}
		else if (op == 2) {
			std::cout << "2. Adauga casa\n\n";
			Casa* c = new Casa();
			try {
				std::cin >> (*c);
			}
			catch (std::exception& e) {
				std::cout << e.what();
			}
			
			evidentaCase += (*c);
			evidentaTotala.insert(std::make_pair(c, c->what()));
		}
		else if (op == 3) {
			std::cout << "3. Afiseaza toate locuintele\n\n";
			for (auto it = evidentaTotala.begin(); it != evidentaTotala.end(); ++it) {
				std::cout << (*it->first) << "\n\n";
			}
		}else if (op == 4) {
			std::cout << "4. Afiseaza apartament - Alegeti apartamentul:\n\n";
			int k = 0;
			for (auto it = evidentaTotala.begin(); it != evidentaTotala.end(); ++it) {
				if (it->second == "apartament") {
					std::cout << k++ << ": ";
					it->first->brief();
				}
			}
			int op_ap; std::cin >> op_ap;
			k = 0;
			for (auto it = evidentaTotala.begin(); it != evidentaTotala.end(); ++it) {
				if (it->second == "apartament") {
					if (op_ap == k) {
						std::cout << (*it->first);
					}
					k++;
				}
			}
		}else if (op == 5) {
			std::cout << "4. Afiseaza casa - Alegeti casa:\n\n";
			int k = 0;
			for (auto it = evidentaTotala.begin(); it != evidentaTotala.end(); ++it) {
				if (it->second == "casa") {
					std::cout << k++ << ": ";
					it->first->brief();
				}
			}
			int op_ap; std::cin >> op_ap;
			k = 0;
			for (auto it = evidentaTotala.begin(); it != evidentaTotala.end(); ++it) {
				if (it->second == "casa") {
					if (op_ap == k) {
						std::cout << (*it->first);
					}
					k++;
				}
			}
		}else if (op == 6) {
			std::cout << "6. Calculeaza chiria - Alegeti locuinta:\n";
			int k = 0;
			for (auto it = evidentaTotala.begin(); it != evidentaTotala.end(); ++it) {
				std::cout << k++ << ": ";
				it->first->brief();
			}
			int op_ap; std::cin >> op_ap;
			k = 0;
			for (auto it = evidentaTotala.begin(); it != evidentaTotala.end(); ++it) {
				if (op_ap == k) {
					std::cout << (it->first->calcChirie());
				}
				k++;
			}
		}else if (op == 7) {
			std::cout << "7. Calculeaza chiria totala case\n";
			std::cout << evidentaCase.totalChirie();
		}
		std::cout << "\n\n";
	}while (op);
	return 0;
}