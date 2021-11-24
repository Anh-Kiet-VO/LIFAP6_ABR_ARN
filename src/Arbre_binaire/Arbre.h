#ifndef _ARBRE
#define _ARBRE

#include "../ElementA.h"

class Noeud {
    friend class Arbre;

    private :
    ElementA elem;
    Noeud * fg;
    Noeud * fd;

    public:
    Noeud();
    Noeud(const Noeud * n);
    Noeud(const ElementA &e);

    ~Noeud();
    void vider();
    
    void insererElement(ElementA e);

    void afficherNoeud(int n) const;
    void afficherNoeudPrefixe();
    void afficherNoeudInfixe();
    void afficherNoeudPostfixe();
};

class Arbre {
    private:
    Noeud * adRacine;

    public:
    Arbre();
    Arbre(const Arbre &a);

    ~Arbre();
    void vider();
    void viderNoeud(Noeud * &n);

    void insererElement(ElementA e);

    void afficherArbre() const;
    void afficherParcoursPrefixe();
    void afficherParcoursInfixe();
    void afficherParcoursPostfixe();

    bool rechercheElem(const ElementA & e) const;
    void rechercheArbre(const ElementA & e, Noeud * n, bool & prst) const;

    Arbre &operator=(const Arbre &);
};

#endif