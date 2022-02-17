#include "Etat.h"
#include <iostream>

/**
   Constructeur de la classe automate
      chaine: expression entree par l'utilisateur
**/
Automate::Automate(string chaine){
   
   // initialisation du lexer: init le flux, la tete et le tampon
   this->lexer = new Lexer(chaine);
}

/**
   Implemente la fonction de décalage: 
   - ajoute la valeur lue à la pile des symboles
   - ajoute le nouvel etat à la pile des états
**/
void Automate::decalage(Symbole *symbole, Etat *etat) {
   pileSymboles.push(symbole);
   pileEtats.push(etat);
}

void Automate::reduction(int n, Symbole *symbole) {
   
}

/**
   Effectue l'analyse de l'expression, gère les transitions entre les états jusqu'à la fin de l'analyse
**/
void Automate::lancer(){

   pileEtats.push(new Etat0());

   // TO DELETE
   int i = 0;

   // tant qu'il reste des operations à traiter et qu'il n'y a pas d'erreur, on gere les transitions
   Symbole *symbole = nullptr;
   do{
      cout << "rang:" << pileEtats.top()->getRang() << endl;
      //On lit le charactère suivant dans la chaine à lire
      symbole = lexer->Consulter();
      
      //On remet le tampon au "point mort"
      lexer->Avancer(); 
      
      // TO DELETE
      i++;
      if(i>=3){
         break;
      }
   }while(pileEtats.top()->transition(*this, symbole));
}


//Ajouter une pile de symbole et une pile d'état
