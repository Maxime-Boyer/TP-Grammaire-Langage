#include "Etat.h"
#include "symbole.h"
#include <iostream>

/**
 * @brief Constructeurs et destructeurs de Etats
 */

Etat::Etat() {}
Etat::~Etat() {}
Etat::Etat(int num) { rang = num; }

Etat0::Etat0() : Etat(0) {}
Etat1::Etat1() : Etat(1) {}
Etat2::Etat2() : Etat(2) {}
Etat3::Etat3() : Etat(3) {}
Etat4::Etat4() : Etat(4) {}
Etat5::Etat5() : Etat(5) {}
Etat6::Etat6() : Etat(6) {}
Etat7::Etat7() : Etat(7) {}
Etat8::Etat8() : Etat(8) {}
Etat9::Etat9() : Etat(9) {}

/**
 * @brief retourne le rang de l'état (compris entre 0 et 9)
 * @return int : le rang de l'état
 */
int Etat::getRang() { return rang; }

/**
 * @brief : Implementation de la ligne 0 de la table d'analyse
 * 
 * @param automate : reference de l'automate utilisé afin de pouvoir modifier son etat
 * @param symbole  : le symbole analysé
 * 
 * @return: false si erreur, true sinon
 */
bool Etat0::transition(Automate &automate, Symbole *symbole) {

  bool toDeleteSymbole = false;
  bool retour = true;

  switch (*symbole) {
  case INT:
    automate.decalage(symbole, new Etat3);
    break;
  case OPENPAR:
    automate.decalage(symbole, new Etat2);
    break;
  case EXP:
    automate.decalage(symbole, new Etat1);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    toDeleteSymbole = true;
    retour = false;
  }

  if(toDeleteSymbole){
    if(symbole != nullptr){ 
        delete (symbole);
        symbole = nullptr;
    }
  }

  return retour;
}

/**
 * @brief : Implementation de la ligne 1 de la table d'analyse
 * 
 * @param automate : reference de l'automate utilisé afin de pouvoir modifier son etat
 * @param symbole  : le symbole analysé
 * 
 * @return: false si erreur ou fin, true sinon
 */
bool Etat1::transition(Automate &automate, Symbole *symbole) {

  bool toDeleteSymbole = false;
  bool retour = true;

  switch (*symbole) {
  case PLUS:
    automate.decalage(symbole, new Etat4);
    break;
  case MULT:
    automate.decalage(symbole, new Etat5);
    break;
  case FIN:
    retour = false;
    //TODO désalloue bien mais crée 3 erreurs
    //toDeleteSymbole = true;
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    toDeleteSymbole = true;
    retour = false;
  }

  if(toDeleteSymbole){
    if(symbole != nullptr){ 
        delete (symbole);
       symbole = nullptr;
    }
  }

  return retour;
}

/**
 * @brief : Implementation de la ligne 2 de la table d'analyse
 * 
 * @param automate : reference de l'automate utilisé afin de pouvoir modifier son etat
 * @param symbole  : le symbole analysé
 * 
 * @return: false si erreur, true sinon
 */
bool Etat2::transition(Automate &automate, Symbole *symbole) {

  bool retour = true;
  bool toDeleteSymbole = false;

  switch (*symbole) {
  case INT:
    automate.decalage(symbole, new Etat3);
    break;
  case OPENPAR:
    automate.decalage(symbole, new Etat2);
    break;
  case EXP:
    automate.decalage(symbole, new Etat6);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    toDeleteSymbole = true;
    retour = false;
  }

  if(toDeleteSymbole){
    if(symbole != nullptr){ 
        delete (symbole);
        symbole = nullptr;
    }
  }

  return retour;
}

/**
 * @brief : Implementation de la ligne 3 de la table d'analyse
 * 
 * @param automate : reference de l'automate utilisé afin de pouvoir modifier son etat
 * @param symbole  : le symbole analysé
 * 
 * @return: false si erreur, true sinon
 */
bool Etat3::transition(Automate &automate, Symbole *symbole) {

  bool retour = true;
  bool toDeleteSymbole = false;

  switch (*symbole) {
  case PLUS:
    automate.reduction(1, new Plus);
    toDeleteSymbole = true;
    break;
  case MULT:
    automate.reduction(1, new Mult);
    toDeleteSymbole = true;
    break;
  case CLOSEPAR:
    automate.reduction(1, new Closepar);
    toDeleteSymbole = true;
    break;
  case FIN:
    automate.reduction(1, new Fin);
    toDeleteSymbole = true;
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    toDeleteSymbole = true;
    retour = false;
  }

  if(toDeleteSymbole){
    if(symbole != nullptr){ 
        delete (symbole);
        symbole = nullptr;
    }
  }

  return retour;
}

/**
 * @brief : Implementation de la ligne 4 de la table d'analyse
 * 
 * @param automate : reference de l'automate utilisé afin de pouvoir modifier son etat
 * @param symbole  : le symbole analysé
 * 
 * @return: false si erreur, true sinon
 */
bool Etat4::transition(Automate &automate, Symbole *symbole) {

  bool retour = true;
   bool toDeleteSymbole = false;

  switch (*symbole) {
  case INT:
    automate.decalage(symbole, new Etat3);
    break;
  case OPENPAR:
    automate.decalage(symbole, new Etat2);
    break;
  case EXP:
    automate.decalage(symbole, new Etat7);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    toDeleteSymbole = true;
    retour = false;
  }

  if(toDeleteSymbole){
    if(symbole != nullptr){ 
        delete (symbole);
       symbole = nullptr;
    }
  }

  return retour;
}

/**
 * @brief : Implementation de la ligne 5 de la table d'analyse
 * 
 * @param automate : reference de l'automate utilisé afin de pouvoir modifier son etat
 * @param symbole  : le symbole analysé
 * 
 * @return: false si erreur, true sinon
 */
bool Etat5::transition(Automate &automate, Symbole *symbole) {

  bool retour = true;
   bool toDeleteSymbole = false;

  switch (*symbole) {
  case INT:
    automate.decalage(symbole, new Etat3);
    break;
  case OPENPAR:
    automate.decalage(symbole, new Etat2);
    break;
  case EXP:
    automate.decalage(symbole, new Etat8);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    toDeleteSymbole = true;
    retour = false;
  }

  if(toDeleteSymbole){
    if(symbole != nullptr){ 
        delete (symbole);
       symbole = nullptr;
    }
  }

  return retour;
}

/**
 * @brief : Implementation de la ligne 6 de la table d'analyse
 * 
 * @param automate : reference de l'automate utilisé afin de pouvoir modifier son etat
 * @param symbole  : le symbole analysé
 * 
 * @return: false si erreur, true sinon
 */
bool Etat6::transition(Automate &automate, Symbole *symbole) {

  bool retour = true;
  bool toDeleteSymbole = false;

  switch (*symbole) {
  case PLUS:
    automate.decalage(symbole, new Etat4);
    break;
  case MULT:
    automate.decalage(symbole, new Etat5);
    break;
  case CLOSEPAR:
    automate.decalage(symbole, new Etat9);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    toDeleteSymbole = true;
    retour = false;
  }

  if(toDeleteSymbole){
    if(symbole != nullptr){ 
        delete (symbole);
       symbole = nullptr;
    }
  }

  return retour;
}

/**
 * @brief : Implementation de la ligne 7 de la table d'analyse
 * 
 * @param automate : reference de l'automate utilisé afin de pouvoir modifier son etat
 * @param symbole  : le symbole analysé
 * 
 * @return: false si erreur, true sinon
 */
bool Etat7::transition(Automate &automate, Symbole *symbole) {

  bool retour = true;
  bool toDeleteSymbole = false;

  switch (*symbole) {
  case PLUS:
    toDeleteSymbole = true;
    automate.reduction(3, new Plus);
    break;
  case MULT:
    automate.decalage(symbole, new Etat5);
    break;
  case CLOSEPAR:
    toDeleteSymbole = true;
    automate.reduction(3, new Closepar);
    break;
  case FIN:
    toDeleteSymbole = true;
    automate.reduction(3, new Fin);
    break;
  default:
    toDeleteSymbole = true;
    automate.decalage(new Symbole(ERREUR), NULL);
    retour = false;
  }

  if(toDeleteSymbole){
    if(symbole != nullptr){ 
        delete (symbole);
       symbole = nullptr;
    }
  }

  return retour;
}

/**
 * @brief : Implementation de la ligne 8 de la table d'analyse
 * 
 * @param automate : reference de l'automate utilisé afin de pouvoir modifier son etat
 * @param symbole  : le symbole analysé
 * 
 * @return: false si erreur, true sinon
 */
bool Etat8::transition(Automate &automate, Symbole *symbole) {

  bool retour = true;
  bool toDeleteSymbole = false;

  switch (*symbole) {
  case PLUS:
    toDeleteSymbole = true;
    automate.reduction(3, new Plus);
    break;
  case MULT:
    automate.reduction(3, new Mult);
    toDeleteSymbole = true;
    break;
  case CLOSEPAR:
    automate.reduction(3, new Closepar);
    toDeleteSymbole = true;
    break;
  case FIN:
    automate.reduction(3, new Fin);
    toDeleteSymbole = true;
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    toDeleteSymbole = true;
    retour = false;
  }

  if(toDeleteSymbole){
    if(symbole != nullptr){ 
        delete (symbole);
       symbole = nullptr;
    }
  }

  return retour;
}

/**
 * @brief : Implementation de la ligne 9 de la table d'analyse
 * 
 * @param automate : reference de l'automate utilisé afin de pouvoir modifier son etat
 * @param symbole  : le symbole analysé
 * 
 * @return: false si erreur, true sinon
 */
bool Etat9::transition(Automate &automate, Symbole *symbole) {

  bool retour = true;
  bool toDeleteSymbole = false;

  switch (*symbole) {
  case PLUS:
    automate.reduction(3, new Plus);
    toDeleteSymbole = true;
    break;
  case MULT:
    automate.reduction(3, new Mult);
    toDeleteSymbole = true;
    break;
  case CLOSEPAR:
    automate.reduction(3, new Closepar);
    toDeleteSymbole = true;
    break;
  case FIN:
    automate.reduction(3, new Fin);
    toDeleteSymbole = true;
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    toDeleteSymbole = true;
    retour = false;
  }

  if(toDeleteSymbole){
    if(symbole != nullptr){ 
        delete (symbole);
       symbole = nullptr;
    }
  }

  return retour;
}
