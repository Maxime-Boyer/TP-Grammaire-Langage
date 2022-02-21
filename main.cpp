#include <iostream>
#include "lexer.h"
#include "Automate.h"


int main(void) {

   string chaine;
   
   cout << "Entrez une expression à analyser:" << endl;
   //cin >> chaine;
   chaine = "(3+4)*2+3*5*6";
   // creation de l'automate, initialisation a partir de l'expression entree par l'utilisateur
   Automate * automate = new Automate(chaine);
   //On lance l'analyseur
   automate->Lancer();
   //On delete l'automate après utilisation
   delete automate;
   return 0;
}

