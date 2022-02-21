#pragma once

 #include "lexer.h"
 #include "symbole.h"
 //#include <stack>
 using namespace std;

class Etat;

/**
 * @brief Automate a états fini de l'analyseur ascendant
 */
class Automate {

public:
   Automate(string flux);
   ~Automate();
   void Decalage(Symbole *symbole, Etat *etat);
   void Reduction(int n, Symbole *symbole);
   void Lancer();

protected:
   stack<Symbole *> pileSymboles;
   stack<Etat *> pileEtats;
   Lexer *lexer;
};