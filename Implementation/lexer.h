#pragma once

#include "symbole.h"
#include <string>

using namespace std;

class Lexer {

public:
  Lexer(string s) : flux(s), tete(0), tampon(nullptr) {}
  ~Lexer() {}

  Symbole *Consulter();
  void Avancer();
  void putSymbol(Symbole *s);
  bool finDuFlux();

protected:
  string flux;
  int tete;
  Symbole *tampon;
};