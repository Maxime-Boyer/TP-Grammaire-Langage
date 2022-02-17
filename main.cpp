#include <iostream>
#include "lexer.h"
#include "Automate.h"


int main(void) {

   string chaine;
   
   cout << "Entrez une expression à analyser:" << endl;
   //cin >> chaine;
   chaine = "2*(3+5)";
   // creation de l'automate, initialisation a partir de l'expression entree par l'utilisateur
   Automate * automate = new Automate(chaine);
   automate->lancer();
   delete automate;
   return 0;
}

