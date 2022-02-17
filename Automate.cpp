#include "Etat.h"
#include <iostream>

/**
 * @brief Construct a new Automate:: Automate object
 * 
 * @param chaine : expression entree par l'utilisateur
 */
Automate::Automate(string chaine){
   
   // initialisation du lexer: init le flux, la tete et le tampon
   this->lexer = new Lexer(chaine);
}

/**
 * @brief Implemente la fonction de décalage: 
   - ajoute la valeur lue à la pile des symboles
   - ajoute le nouvel etat à la pile des états
 * 
 * @param symbole : symbole a traiter
 * @param etat : etat a traiter
 */
void Automate::decalage(Symbole *symbole, Etat *etat) {
   pileSymboles.push(symbole);
   pileEtats.push(etat);
}

/**
 * @brief TODO version du pack parrain, à reprendre
 * 
 * @param n 
 * @param s 
 */
void Automate::reduction(int n, Symbole *s) {

  stack<Symbole *> aEnlever;

  //Depiler le bon nombre d'état et de symbole 
   for (int i = 0; i < n; i++) {
      delete (pileEtats.top());
      pileEtats.pop();
      //Comprend pas cette ligne
      aEnlever.push(pileSymboles.top());
      pileSymboles.pop();
   }

   int val;

   //Si n = 1, facile on récupère la valeur dépilée 
   if (n == 1) {
      val = aEnlever.top()->getVal();
   } else if (n == 3) {
      if (*aEnlever.top() == OPENPAR) {
         aEnlever.pop();
         val = aEnlever.top()->getVal();
      } else {
         val = aEnlever.top()->getVal();
         aEnlever.pop();
         if (*aEnlever.top() == MULT) {
         aEnlever.pop();
         val = val * aEnlever.top()->getVal();
         } else {
         aEnlever.pop();
         val = val + aEnlever.top()->getVal();
         }
      }
   }

   pileEtats.top()->transition(*this, new Expression(val));
   lexer->putSymbol(s);    //TODO: pourquoi c'est utile ca?? (Aussi un TODO dans lexer.cpp)
}

/**
 * @brief Effectue l'analyse de l'expression, gère les transitions entre les états jusqu'à la fin de l'analyse
 */
void Automate::lancer(){

   pileEtats.push(new Etat0());

   // tant qu'il reste des operations à traiter et qu'il n'y a pas d'erreur, on gere les transitions
   Symbole *symbole = nullptr;
   do{
      cout << "rang:" << pileEtats.top()->getRang() << endl;
      //On lit le charactère suivant dans la chaine à lire
      symbole = lexer->Consulter();
      
      //On remet le tampon au "point mort"
      lexer->Avancer(); 
   }while(pileEtats.top()->transition(*this, symbole));

   if (*pileSymboles.top() != ERREUR) {
      int resultat = pileSymboles.top()->getVal();
      cout << "Syntaxe valise" << endl << "Résultat : " << resultat << endl;
   } else {
      cout << "Syntaxe incorrect: caractère invalide" << endl;
   }
}
