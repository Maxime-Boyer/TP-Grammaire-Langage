#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

void Plus::Affiche() { Symbole::Affiche(); }

void Mult::Affiche() { Symbole::Affiche(); }

void Openpar::Affiche() { Symbole::Affiche(); }

void Closepar::Affiche() { Symbole::Affiche(); }

void Fin::Affiche() { Symbole::Affiche(); }

void Erreur::Affiche() { Symbole::Affiche(); }

void Expression::Affiche() { Symbole::Affiche(); }

int Symbole::ObtenirValeur() { return -1; }

int Entier::ObtenirValeur() { return valeur; }

int Expression::ObtenirValeur() { return valeur; }