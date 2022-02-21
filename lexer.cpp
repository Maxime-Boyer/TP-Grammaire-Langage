#include "lexer.h"
#include <iostream>

/**
 * @brief parser de l'entrée utilisateur
 * 
 * @return Symbole* : le symbole lu
 */
Symbole * Lexer::Consulter() {
   bool isNew = false;
   if (!tampon) {

      if (tete==flux.length()){
         tampon = new Symbole(FIN);
         isNew = true;
      }else
      {

         switch (flux[tete]) {
            case '(':
               tampon = new Symbole(OPENPAR);
               isNew = true;
               tete++;
               break;
            case ')':
               tampon = new Symbole(CLOSEPAR);
               isNew = true;
               tete++;
               break;
            case '*':
               tampon = new Symbole(MULT);
               isNew = true;
               tete++;
               break;
            case '+':
               tampon = new Symbole(PLUS);
               isNew = true;
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
                  isNew = true;
               }
               else {
                  tampon = new Symbole(ERREUR);
                  isNew = true;
               }
         }
      }
   }
   if(isNew){pileSymbolesLu.push(tampon);}
   return tampon;
}

/**
 * @brief Avance la tete de lecture
 */
void Lexer::Avancer() {
   tampon = nullptr;
}

/**
 * @brief TODO retravailler, extrait du pask parrain
 * 
 * @param s 
 */
void Lexer::putSymbol(Symbole *s) {

   switch (*s) {
   case PLUS:
   case MULT:
   case OPENPAR:
   case CLOSEPAR:
      tampon = s;
      break;
   }
}

Lexer::~Lexer(){
   delete tampon;

   while(!pileSymbolesLu.empty()){
      if(pileSymbolesLu.top() != nullptr){ 
         //delete (pileSymbolesLu.top()); 
         //pileSymbolesLu.top() = nullptr;
         cout << "symbole lu : " << pileSymbolesLu.top() << endl;
      }
      pileSymbolesLu.pop();
   }

}