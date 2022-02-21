#pragma once

#include <string>
#include "symbole.h"
#include <stack>
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
      void ReplacerTamponLecture(Symbole *s);

   protected:
      string flux;
      int tete;
      stack<Symbole *> pileSymbolesLu;
      Symbole * tampon;
};
