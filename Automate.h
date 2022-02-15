#pragma once

 #include "lexer.h"
 #include "symbole.h"
 #include <stack>
 using namespace std;

class Etat;

class Automate {

public:
   Automate(string flux);
   void decalage(Symbole *symbole, Etat *etat);
   void reduction(int n, Symbole *symbole);
   void lancer();

protected:
   stack<Symbole *> pileSymboles;
   stack<Etat *> pileEtats;
   Lexer *lexer;
 };