#include "symbole.h"
#include <iostream>

void Symbole::Affiche() { cout << Etiquettes[ident]; }

void Entier::Affiche() {
  Symbole::Affiche();
  cout << "(" << valeur << ")";
}

void Plus::Affiche() { Symbole::Affiche(); }

void Mult::Affiche() { Symbole::Affiche(); }

void Openpar::Affiche() { Symbole::Affiche(); }

void Closepar::Affiche() { Symbole::Affiche(); }

void Fin::Affiche() { Symbole::Affiche(); }

void Erreur::Affiche() { Symbole::Affiche(); }

void expression::Affiche() { Symbole::Affiche(); }

int Symbole::getValue() { return -1; }

int Entier::getValue() { return valeur; }

int expression::getValue() { return valeur; }
