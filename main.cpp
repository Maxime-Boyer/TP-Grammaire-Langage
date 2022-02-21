#include <iostream>
#include "lexer.h"
#include "Automate.h"


int main(void) {

   string chaine;
   cout << "************************************" << endl;
   cout << endl;
   cout << "Entrez une expression à analyser:" << endl;
   cin >> chaine;
   // creation de l'automate, initialisation a partir de l'expression entree par l'utilisateur
   Automate * automate = new Automate(chaine);
   //On lance l'analyseur
   automate->Lancer();
   cout << endl;
   cout << "************************************" << endl;
   //On delete l'automate après utilisation
   delete automate;
   return 0;
}

