// ____________________

#include "../ElementA.h"
#include "ARN.h"

#include <stdlib.h>
#include <iostream>
using namespace std;

/* ------------- NOEUDARN ------------- */


// ------------- Constructeur ------------- 
NoeudARN::NoeudARN() {
    elem = 0;
    fd = nullptr;
    fg = nullptr;
    couleur = true;
}

NoeudARN::NoeudARN(const NoeudARN *n) {
    elem = n->elem;
    fd = n->fd;
    fg = n->fg;
    couleur = n->couleur;
}

NoeudARN::NoeudARN(const ElementA &e) {
    elem = e;
    fd = nullptr;
    fg = nullptr;
    couleur = true;
}

void NoeudARN::vider() {
    if(fg != nullptr) {
        fg->vider();
    }
    if(fd != nullptr) {
        fd->vider();
    }
    delete this;
}


// ------------- Affichage -------------
void NoeudARN::afficherNoeud(int n) const {
    if(fd != nullptr) {
        fd->afficherNoeud(n + 1);
    }
    
    for(int i = 0; i < n; i++) {
        cout<<"------- ";
        
    }

    cout<< elem << " ";

    if (couleur) cout << "rouge" ;
    if (!couleur) cout << "noir" ;
    
    cout << endl ;
    
    if(fg != nullptr) {
        fg->afficherNoeud(n + 1);
    }
}

void NoeudARN::afficherNoeudPrefixe() {
    cout<<elem << " ";
    
    if (couleur) cout << "rouge";
    if (!couleur) cout << "noir";
    
    cout << "__ ";

    if(fg != nullptr) {
        fg->afficherNoeudPrefixe();
    }

    if(fd != nullptr) {
        fd->afficherNoeudPrefixe();
    }
}

void NoeudARN::afficherNoeudInfixe() {
    if(fd != nullptr) {
        fd->afficherNoeudInfixe();
    } 

    cout<< elem <<" ";

    if (couleur) cout << "rouge";
    if (!couleur) cout << "noir";

    cout << "__ ";

    if(fg != nullptr) {
        fg->afficherNoeudInfixe();
    }      
}

void NoeudARN::afficherNoeudPostfixe() {
    if(fd != nullptr) {
        fd->afficherNoeudPostfixe();
    }

    if(fg != nullptr) {
        fg->afficherNoeudPostfixe();
    }

    cout<< elem << " ";

    if (couleur) cout << "rouge";
    if (!couleur) cout << "noir";

    cout << "__ ";
}


// ------------- Rotation ------------- 
void ARN::rotationDroite(NoeudARN * &n) {
    NoeudARN * tmp = new NoeudARN;
    
    tmp = n ->fg;      
    n->fg = n->fg->fd;
    tmp->fd = n;
    n=tmp;

    // Racine en noir
    if (n == adRacine) n->couleur = 0;
}

void ARN::rotationGauche(NoeudARN * &n) {
    NoeudARN * tmp = new NoeudARN;

    tmp = n->fd;
    n->fd = n->fd->fg;
    tmp->fg = n;
    n=tmp;

    // Racine en noir
    if (n == adRacine) n->couleur = 0;
}

// Pour modifier la couleur quand on l'équilibre
void ARN::modifCouleur(NoeudARN * n)
{   n->couleur == 0 ? n->couleur = 1 : n->couleur = 0;
    /*if (n->couleur == 0) n->couleur = 1;
    else n->couleur = 0;*/
}

// Rotation double gauche et en même temps appel de la fonction modifCouleur
void ARN::rotationDoubleGauche(NoeudARN * &n) {

    rotationDroite(n->fd);
    rotationGauche(n);

    modifCouleur(n->fd);
    modifCouleur(n);
}

// Rotation double droite et en même temps appel de la fonction modifCouleur
void ARN::rotationDoubleDroite(NoeudARN * &n) {
    rotationGauche(n->fg);
    rotationDroite(n);

    modifCouleur(n->fg);
    modifCouleur(n);
}


/* ------------- ARN ------------- */


// ------------- Constructeur ------------- 
ARN::ARN() {
    adRacine = NULL;
}

ARN::ARN(const ARN &a) {
    adRacine = new NoeudARN(a.adRacine);
    adRacine->fg = new NoeudARN(a.adRacine->fg);
    adRacine->fd = new NoeudARN(a.adRacine->fd);
}

/* [makefile:41: runarn] Error -1073741571*/
ARN::~ARN() {
    //vider();
}

void ARN::vider() {
    viderNoeud(adRacine);
}

void ARN::viderNoeud(NoeudARN * &n) {
    if (n != nullptr) {
        viderNoeud(n->fg);
        viderNoeud(n->fd);
        delete n;
        n = nullptr;
    }
}

// Fonction appelé avec ARN::insererElement
void ARN::insererARN(const ElementA &e, NoeudARN * & n) {
    if (e < n->elem) {  // Si l'element est strictement plus petit on le met à gauche
        if (n->fg == nullptr) { // Si pas de noeudARN existant, on en créer 
            n->fg = new NoeudARN(e);
        }
        else { // Si existe, on l'insere et on verifie pour équilibrer les couleurs
            insererARN(e,n->fg);
            equilibre(n, n->fg);
            
        }
    }
    else if (e > n->elem) { // Si l'element est strictement plus grand on le met à droite
        if (n->fd == nullptr) { // Si pas de noeudARN existant, on en créer
            n->fd = new NoeudARN(e);
        }
        else { // Si existe, on l'insere et on verifie pour équilibrer les couleurs
            insererARN(e,n->fd);
            equilibre(n, n->fd);
        }
    }
}

// Si il n'y a pas de noeudARN on en crée un sinon on insere l'element qu'on veut dans notre ARN
void ARN::insererElement(ElementA e) {
    if(adRacine == nullptr) {
        adRacine = new NoeudARN(e);
        adRacine->couleur = 0 ;
    } else {
        insererARN(e, adRacine);
    }
}

// Appel rechercheArbre pour pouvoir utiliser adRacine et on return un booléen present
bool ARN::rechercheElem(const ElementA & e) const {
    bool prst = 0;
    rechercheArbre(e, adRacine, prst);
    return prst;
}

void ARN::rechercheArbre(const ElementA & e, NoeudARN * n, bool & prst) const {
    if(n != nullptr) { // Si arbre pas vide on rentre
        if(n->elem == e) { // Si on le trouve direct on met prst à 1
            prst = 1;
            cout<< e <<" est present"<<endl;
        } else if (e < n->elem) {  // Sinon on parcourt à gauche récursivement
            rechercheArbre(e, n->fg, prst);
            
        } else if (e > n->elem) { // Ou on parcourt à droite recursivement aussi
           rechercheArbre(e, n->fd, prst);
        }
    }
}

void ARN::equilibre(NoeudARN* &PP, NoeudARN* &P)  // PP est le noeudARN grand-père, P est le noeudARN père 
{
    // Cas 1 => Q possède un oncle rouge à gauche ou droite
    if(PP->fg != nullptr && PP->fd != nullptr && PP->fg->couleur == 1 && PP->fd->couleur == 1) {
        modifCouleur(PP);
        modifCouleur(PP->fg);
        modifCouleur(PP->fd);
        if (PP == adRacine) PP->couleur = 0;
    } else // Cas 2a => Fils gauche de P est fils gauche de PP
    if(P->fg != nullptr && P->fg->couleur == 1 && PP->fg == P->fg) {
        modifCouleur(PP->fg);
        modifCouleur(PP);
        rotationDroite(PP); 
    } else // Cas 2b => Fils droit de P est fils gauche de PP
    if(P->fd != nullptr && P->fd->couleur == 1 && PP->fg == P->fd) {
        rotationDoubleDroite(PP);
    } else // Cas 2c => Fils droit de P est fils droit de PP [Symetrie du cas 2a]
    if(P->fd != nullptr && P->fd->couleur == 1 && PP->fd == P->fd) {
        modifCouleur(PP->fd);
        modifCouleur(PP);   
        rotationGauche(PP);
    } else // Cas 2d => Fils gauche de P est fils droit de PP [Symetrie du cas 2b]
    if(P->fg != nullptr && P->fg->couleur == 1 && PP->fd == P->fd) {
        rotationDoubleGauche(PP);
    }
}

void ARN::afficherARN() const {
    if(adRacine != nullptr) {
        adRacine->afficherNoeud(0);
    }
}

void ARN::afficherParcoursPrefixe() {
    if(adRacine != nullptr) {
        adRacine->afficherNoeudPrefixe();
    }
    cout<<endl;
}

void ARN::afficherParcoursInfixe() {
    if(adRacine != nullptr) {
        adRacine->afficherNoeudInfixe();
    }
    cout<<endl;
}

void ARN::afficherParcoursPostfixe() {
    if(adRacine != nullptr) {
        adRacine->afficherNoeudPostfixe();
    }
    cout<<endl;
}