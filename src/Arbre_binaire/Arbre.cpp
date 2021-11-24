#include "../ElementA.h"
#include "Arbre.h"

#include <stdlib.h>
#include <iostream>
using namespace std;

/* ------------- NOEUD ------------- */

Noeud::Noeud() {
    elem = 0;
    fd = nullptr;
    fg = nullptr;
}

Noeud::Noeud(const Noeud *n) {
    elem = n->elem;
    fd = n->fd;
    fg = n->fg;
}

Noeud::Noeud(const ElementA &e) {
    elem = e;
    fd = nullptr;
    fg = nullptr;
}

Noeud::~Noeud() {
    if(fg != nullptr) delete fg;
    if(fd != nullptr) delete fd;
}

void Noeud::vider() {
    if(fg != nullptr) {
        fg->vider();
    }
    if(fd != nullptr) {
        fd->vider();
    }
    delete this;
}

void Noeud::insererElement(ElementA e) {
    if(e < elem) {
        if(fg == nullptr) {
            fg = new Noeud(e);
        } else {
            fg->insererElement(e);
        }
    }
    else if (e > elem) {
        if(fd == nullptr) {
            fd = new Noeud(e);
        } else {
            fd->insererElement(e);
        }
    } 
}

void Noeud::afficherNoeud(int n) const {
    if(fd != nullptr) {
        fd->afficherNoeud(n+1);
    }
    
    for(int i = 0; i < n; i++) {
         cout<<"------- ";
        
    }

    cout<<elem<<endl;
    
    if(fg != nullptr) {
        fg->afficherNoeud(n+1);
    }
}

void Noeud::afficherNoeudPrefixe() {
    cout<< elem <<"__ ";
    
    if(fd != nullptr) {
        fd->afficherNoeudPrefixe();
    }

    if(fg != nullptr) {
        fg->afficherNoeudPrefixe();
    }
}

void Noeud::afficherNoeudInfixe() {
    if(fd != nullptr) {
        fd->afficherNoeudInfixe();
    }
    
    cout<< elem <<"__ ";

    if(fg != nullptr) {
        fg->afficherNoeudInfixe();
    }
}

void Noeud::afficherNoeudPostfixe() {
    if(fd != nullptr) {
        fd->afficherNoeudPostfixe();
    }
    
    if(fg != nullptr) {
        fg->afficherNoeudPostfixe();
    }

    cout<< elem <<"__ ";
}

/* ------------- ARBRE ------------- */

Arbre::Arbre() {
    adRacine = NULL;
}

Arbre::Arbre(const Arbre &a) {
    adRacine = new Noeud(a.adRacine);
    adRacine->fg = new Noeud(a.adRacine->fg);
    adRacine->fd = new Noeud(a.adRacine->fd);
}

Arbre::~Arbre() {
    //if(adRacine != nullptr) adRacine->vider();
}

void Arbre::vider() {
    viderNoeud(adRacine);
}

void Arbre::viderNoeud(Noeud * &n) {
    if (n != nullptr) {
        viderNoeud(n->fg);
        viderNoeud(n->fd);
        delete n;
        n = nullptr;
    }
}

void Arbre::insererElement(ElementA e) {
    if(adRacine == nullptr) {
        adRacine = new Noeud(e);
    } else {
        adRacine->insererElement(e);
    }
}

bool Arbre::rechercheElem(const ElementA & e) const{
    bool prst = 0;
    rechercheArbre(e, adRacine, prst);
    return prst;
}

void Arbre::rechercheArbre(const ElementA & e, Noeud * n, bool & prst) const{
    if(n != nullptr) { // Si arbre pas vide on rentre
        if(n->elem == e) { // Si on le trouve direct on met prst à 1
            prst = 1;
            cout<<e<<" est present"<<endl;
        } else if (e < n->elem) {  // Sinon on parcourt à gauche récursivement
            rechercheArbre(e, n->fg, prst);
            
        } else if (e > n->elem) { // Ou on parcourt à droite recursivement aussi
           rechercheArbre(e, n->fd, prst);
        }
    }
}

void Arbre::afficherArbre() const {
    if(adRacine != nullptr) {
        adRacine->afficherNoeud(0);
    }
}

void Arbre::afficherParcoursPrefixe() {
    if(adRacine != nullptr) {
        adRacine->afficherNoeudPrefixe();
    }
    cout<<endl;
}

void Arbre::afficherParcoursInfixe() {
    if(adRacine != nullptr) {
        adRacine->afficherNoeudInfixe();
    }
    cout<<endl;
}

void Arbre::afficherParcoursPostfixe() {
    if(adRacine != nullptr) {
        adRacine->afficherNoeudPostfixe();
    }
    cout<<endl;
}