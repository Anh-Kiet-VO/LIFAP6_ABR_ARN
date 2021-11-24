#include <iostream>
#include <chrono>
#include <cmath>
#include <fstream>

#include "./collec.h"

using namespace std;

int main() {

    Collec abis;
    
    /*abis.insererElement(20);
    abis.insererElement(12);
    abis.insererElement(22);
    abis.insererElement(4);
    abis.insererElement(30);
    abis.insererElement(17);*/

    // 1er arbre du sujet de TP
    abis.insererElement(26);
    abis.insererElement(17);
    abis.insererElement(41);
    abis.insererElement(14);
    abis.insererElement(21);

    abis.insererElement(30);
    abis.insererElement(47);
    abis.insererElement(10);
    abis.insererElement(16);
    abis.insererElement(19);

    abis.insererElement(23);
    abis.insererElement(28);
    abis.insererElement(38);
    abis.insererElement(7);
    abis.insererElement(12);

    abis.insererElement(15);
    abis.insererElement(20);
    abis.insererElement(35);
    abis.insererElement(39);
    abis.insererElement(3);
   
   // Affichage de notre arbre
    abis.afficherARN(); // Affichage infixe en commençant par le fils droit

    cout<<endl;

    // Recherche d'élément
    abis.rechercheElem(41);

    cout<<endl;


    // Affichage Postfixe
    cout<<"Parcours Postfixe : ";
    abis.afficherParcoursPostfixe();

    // Affichage Infixe
    cout<<"Parcours Infixe : ";
    abis.afficherParcoursInfixe();

    // Affichage Prefixe
    cout<<"Parcours Prefixe : ";
    abis.afficherParcoursPrefixe();

    cout<<endl;

    // Constructeur d'arbre par copie
    cout<<"Affichage de a4 par copie:"<<endl;
    Collec a4(abis);
    a4.afficherARN();

    // Fonction vider
    cout<<"On vide l'arbre..."<<endl;
    abis.vider();

    cout<<endl;

    cout<<"Avec la fonction vider(), l'arbre est vide :"<<endl;
    abis.afficherARN();

    cout<<endl;
   
    Collec a5;
    for(int i = 0; i < 35; i++) {
        a5.insererElement(rand()%1000+1) ;
    }
    cout << "Affichage de a5 avec rand: "<< endl;
    a5.afficherARN();

    cout<<endl;
}
