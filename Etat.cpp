#include "Etat.h"
#include "symbole.h"
#include <iostream>

Etat::Etat() {}
Etat::~Etat() {}
Etat::Etat(int num) { rang = num; }
int Etat::getRang() { return rang; }
bool Etat::transition(Automate &automate, Symbole *symbole) {
    cout << " Hello " << endl;
}

Etat0::Etat0() : Etat(0) {}
Etat1::Etat1() : Etat(1) {}
Etat2::Etat2() : Etat(2) {}
Etat3::Etat3() : Etat(3) {}
Etat4::Etat4() : Etat(4) {}
Etat5::Etat5() : Etat(5) {}
Etat6::Etat6() : Etat(6) {}
Etat7::Etat7() : Etat(7) {}
Etat8::Etat8() : Etat(8) {}
Etat9::Etat9() : Etat(9) {}

bool Etat0::transition(Automate &automate, Symbole *symbole) {
  switch (*symbole) {
  case INT:
    automate.decalage(symbole, new Etat3);
    break;
  case OPENPAR:
    automate.decalage(symbole, new Etat2);
    break;
  case EXP:
    automate.decalage(symbole, new Etat1);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}