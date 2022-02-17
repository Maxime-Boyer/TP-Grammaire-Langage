#pragma once

#include <string>
#include "symbole.h"
using namespace std;

/**
 * @brief parser de l'entrée utilisateur
 */
class Lexer {

   public:
      Lexer(string s) : flux(s), tete(0), tampon(nullptr) { }
      ~Lexer();

      Symbole * Consulter();
      void Avancer();
      void putSymbol(Symbole *s);

   protected:
      string flux;
      int tete;
      Symbole * tampon;
};
