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
void Automate::Decalage(Symbole *symbole, Etat *etat) {
   pileSymboles.push(symbole);
   pileEtats.push(etat);
}

/**
 * @brief Implemente la fonction de réduction:
 *    - dépile le bon nombre d'état et de symboles sur les piles respective
 *    - replace le tampon sur le symbole "lu" mais non consommé
 * 
 * @param n 
 * @param s 
 */
void Automate::Reduction(int n, Symbole *s) {

   stack<Symbole *> aEnlever;
   stack<Symbole *> aEnleverMemoire;

  //Depiler le bon nombre d'état et de symbole 
   for (int i = 0; i < n; i++) {
      if(pileEtats.top() != nullptr){ 
         delete (pileEtats.top());
         pileEtats.top() == nullptr;
      }
      pileEtats.pop();
      
      //On empile les symboles à dépiler de la pile de l'automate afin de faire les opérations 
      //et de détruire les allocations de symboles
      aEnlever.push(pileSymboles.top());
      aEnleverMemoire.push(pileSymboles.top());
      pileSymboles.pop();
   }

   int val;

   //Premier cas regle 5
   if (n == 1) {
      val = aEnlever.top()->ObtenirValeur();
   } else if (n == 3) {
      //Regle 4
      if (*aEnlever.top() == OPENPAR) {
         aEnlever.pop();
         val = aEnlever.top()->ObtenirValeur();
      } else {
         val = aEnlever.top()->ObtenirValeur();
         aEnlever.pop();
         //Regle 3
         if (*aEnlever.top() == MULT) {
         aEnlever.pop();
         val = val * aEnlever.top()->ObtenirValeur();
         } else {
         //Regle 2
         aEnlever.pop();
         val = val + aEnlever.top()->ObtenirValeur();
         }
      }
   }

   //On détruit les symboles pop de la pile
   while (!aEnleverMemoire.empty()){
      if(aEnleverMemoire.top() != nullptr){ 
         delete (aEnleverMemoire.top());
         aEnleverMemoire.top() = nullptr;
      }
      aEnleverMemoire.pop();
   }
    
   //On appelle la prochaine transition avec cette nouvelle expression
   pileEtats.top()->Transition(*this, new Expression(val));

   //On replace enfin le tampon sur le symbole non consommé et à (re)lire
   lexer->ReplacerTamponLecture(s);
}

/**
 * @brief Effectue l'analyse de l'expression, gère les transitions entre les états jusqu'à la fin de l'analyse
 */
void Automate::Lancer(){

   pileEtats.push(new Etat0());

   // tant qu'il reste des operations à traiter et qu'il n'y a pas d'erreur, on gere les transitions
   Symbole *symbole = nullptr;
   do{
      cout << "rang:" << pileEtats.top()->getRang() << endl;
      //On lit le charactère suivant dans la chaine à lire
      symbole = lexer->Consulter();
      
      //On remet le tampon au "point mort"
      lexer->Avancer(); 
   }while(pileEtats.top()->Transition(*this, symbole));

   if (*pileSymboles.top() != ERREUR) {
      delete symbole; //On supprime le symbole FIN
      int resultat = pileSymboles.top()->ObtenirValeur();
      cout << "Syntaxe valide" << endl << "Résultat : " << resultat << endl;
   } else {
      cout << "Syntaxe incorrect: caractère invalide" << endl;
   }
}

/**
 * @brief Detruit un objet automate
 */
Automate::~Automate(){

   //Détruit les symbole résiduels dans la pile de symbole
   while(!pileSymboles.empty()){
      if(pileSymboles.top() != nullptr){ 
         delete (pileSymboles.top());
         pileSymboles.top() == nullptr;
      }
      pileSymboles.pop();
   }

   //Détruit les états résiduels dans la pile de symbole
   while(!pileEtats.empty()){
      if(pileEtats.top() != nullptr){ 
         delete (pileEtats.top());
         pileEtats.top() == nullptr;
      }
      pileEtats.pop();
   }

   //Détruit le lexer
   delete lexer;
}