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

int Symbole::getVal() { return -1; }

int Entier::getVal() { return valeur; }

int Expression::getVal() { return valeur; }