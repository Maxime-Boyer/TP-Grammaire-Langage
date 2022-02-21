#include "lexer.h"
#include <iostream>

/**
 * @brief parser de l'entrée utilisateur
 * 
 * @return Symbole* : le symbole lu
 */
Symbole * Lexer::Consulter() {

   if (!tampon) {

      if (tete==flux.length()){
         tampon = new Symbole(FIN);
      }else
      {

         switch (flux[tete]) {
            case '(':
               tampon = new Symbole(OPENPAR);
               tete++;
               break;
            case ')':
               tampon = new Symbole(CLOSEPAR);
               tete++;
               break;
            case '*':
               tampon = new Symbole(MULT);
               tete++;
               break;
            case '+':
               tampon = new Symbole(PLUS);
               tete++;
               break;
            default:
               if (flux[tete]<='9' && flux[tete]>='0') {
                  int resultat = flux[tete]-'0';
                  int i=1;
                  while (flux[tete+i]<='9' && flux[tete+i]>='0') {
                     resultat = resultat*10+(flux[tete+i]-'0');
                     i++;
                  }
                  tete = tete+i;
                  tampon = new Entier(resultat);
               }
               else {
                  tampon = new Symbole(ERREUR);
               }
         }
      }
   }
   return tampon;
}

/**
 * @brief Avance la tete de lecture
 */
void Lexer::Avancer() {
   tampon = nullptr;
}

/**
 * @brief Dans le cas d'une reduction replace le tampon sur le symbole courant car il n'a pas été consommé
 * 
 * @param s symbole à replacer sur le tampon 
 */
void Lexer::ReplacerTamponLecture(Symbole *s) {

   switch (*s) {
   case PLUS:
   case MULT:
   case OPENPAR:
   case CLOSEPAR:
      tampon = s;
      break;
   case FIN:
      delete s;
      break;
   }
}

/**
 * @brief Detruit un objet lexer
 */
Lexer::~Lexer(){

   //Détruit le tampon
   delete tampon;

}