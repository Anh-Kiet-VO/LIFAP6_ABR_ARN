#ifndef _ARN
#define _ARN

#include "../ElementA.h"

class NoeudARN {
    friend class ARN;

    private :
    NoeudARN * fg;
    NoeudARN * fd;
    bool couleur;
    ElementA elem;

    public:
    NoeudARN();
    NoeudARN(const NoeudARN * n);
    NoeudARN(const ElementA &e);

    void vider();

    void afficherNoeud(int n) const;
    void afficherNoeudPrefixe();
    void afficherNoeudInfixe();
    void afficherNoeudPostfixe();
};

class ARN {
    private:
    NoeudARN * adRacine;

    public:
    ARN();
    ARN(const ARN &a);

    ~ARN();

    void vider();
    void viderNoeud(NoeudARN * &n);

    void insererElement(ElementA e);
    void insererARN(const ElementA & e, NoeudARN * &n);
    void equilibre(NoeudARN * &PP, NoeudARN * &P);
    
    void afficherARN() const;
    void afficherParcoursPrefixe();
    void afficherParcoursInfixe ();
    void afficherParcoursPostfixe();

    bool rechercheElem(const ElementA & e) const;
    void rechercheArbre(const ElementA & e, NoeudARN * n, bool & prst) const;

    ARN &operator=(const ARN &);

    void rotationDroite(NoeudARN * &n);
    void rotationDoubleDroite(NoeudARN * &n);
    void rotationGauche(NoeudARN * &n);
    void rotationDoubleGauche(NoeudARN * &n);

    void modifCouleur(NoeudARN * n);

    

};

#endif