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
   stack<Symbole *> aEnleverMemoire;

   cout << "reduction" << endl;

  //Depiler le bon nombre d'état et de symbole 
   for (int i = 0; i < n; i++) {
      if(pileEtats.top() != nullptr){ 
         delete (pileEtats.top());
         pileEtats.top() == nullptr;
      }
      pileEtats.pop();
      
      aEnlever.push(pileSymboles.top());
      aEnleverMemoire.push(pileSymboles.top());
      pileSymboles.pop();
   }

   int val;

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

   while (!aEnleverMemoire.empty()){
      if(aEnleverMemoire.top() != nullptr){ 
         delete (aEnleverMemoire.top());
         aEnleverMemoire.top() = nullptr;
      }
      aEnleverMemoire.pop();
   }
    
   pileEtats.top()->transition(*this, new Expression(val));
   //TODO: pourquoi c'est utile ca?? (Aussi un TODO dans lexer.cpp)

   lexer->putSymbol(s);
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
      delete symbole;
      int resultat = pileSymboles.top()->getVal();
      cout << "Syntaxe valide" << endl << "Résultat : " << resultat << endl;
   } else {
      cout << "Syntaxe incorrect: caractère invalide" << endl;
   }
}

Automate::~Automate(){

   while(!pileSymboles.empty()){
      if(pileSymboles.top() != nullptr){ 
         delete (pileSymboles.top());
         pileSymboles.top() == nullptr;
      }
      pileSymboles.pop();
   }

   while(!pileEtats.empty()){
      if(pileEtats.top() != nullptr){ 
         delete (pileEtats.top());
         pileEtats.top() == nullptr;
      }
      pileEtats.pop();
   }

   delete lexer;
}