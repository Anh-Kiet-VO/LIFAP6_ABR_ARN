#include <iostream>
#include <chrono>
#include <cmath>
#include <fstream>

#include "./ElementA.h"
#include "./Arbre_binaire/Arbre.h"
#include "./ARN/ARN.h"

using namespace std;

int main() {
    cout << endl << endl << endl << "------TEST PERFORMANCE------" << endl << endl << endl ;

    // Créations des fichiers txt pour mettre nos résultats
    string const fichier_resultats_1 = "./Performance/ARN_Performance.txt";
    ofstream file_1(fichier_resultats_1.c_str());

    string const fichier_resultats_2 = "./Performance/ABR_Performance.txt";
    ofstream file_2(fichier_resultats_2.c_str());
    
    file_1 << "# \"moy\" \"arbre\"" << endl;
    file_2 << "# \"moy\" \"arbre\"" << endl;

    const int nbElemArbre = 8000;
    const int nbArbre = 6000;

    // Nos tableaux d'Arbre
    ARN tabARN[nbArbre];
    Arbre tabABR[nbArbre];

    std::chrono::time_point<std::chrono::system_clock> start, end;
    float elapsed;
    float moy, moy2;
     
    for(int i = 0; i < nbElemArbre; i++) {
        start = std::chrono::system_clock::now();
        for(int j = 0; j < nbArbre; j++) { 
            tabARN[j].insererElement(rand()%2*nbArbre);
            
        }
        end = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        moy = elapsed / nbArbre;
        file_1 <<i<< " " <<moy<<endl;

        start = std::chrono::system_clock::now();
        for(int j = 0; j < nbArbre; j++) { 
            tabABR[j].insererElement(rand()%2*nbArbre);
            
        }
        end = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        moy2 = elapsed / nbArbre;
        file_2 <<i<< " " <<moy2<< endl;
    }
    cout<<"Temps moyens pour l'ABR: "<<moy2<<endl;
    cout<<"Temps moyens pour l'ARN: "<<moy<<endl;
}
