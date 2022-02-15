#include "State.h"
#include <iostream>
#include <stdio.h>

Automate::Automate(string flux) {
  this->lexer = new Lexer(flux);
  State0 *depart = new State0();
  statestack.push(depart);
}

void Automate::run() {
  bool prochainEtat = true;

  while (prochainEtat) {
    Symbole *s = lexer->Consulter();
    lexer->Avancer();
    prochainEtat = statestack.top()->transition(*this, s);
  }
  if (*symbolstack.top() != ERREUR) {

    int resultat = symbolstack.top()->getValue();
    cout << "Syntaxe correct" << endl << "Résultat : " << resultat << endl;
  } else {
    cout << "Syntaxe non reconnu : caractere invalide" << endl;
  }
}

void Automate::decalage(Symbole *s, State *e) {
  symbolstack.push(s);
  statestack.push(e);
}

void Automate::reduction(int n, Symbole *s) {
  stack<Symbole *> aEnlever;

  for (int i = 0; i < n; i++) {
    delete (statestack.top());
    statestack.pop();
    aEnlever.push(symbolstack.top());
    symbolstack.pop();
  }

  int val;

  if (n == 1) {
    val = aEnlever.top()->getValue();
  } else if (n == 3) {
    if (*aEnlever.top() == OPENPAR) {
      aEnlever.pop();
      val = aEnlever.top()->getValue();
    } else {
      val = aEnlever.top()->getValue();
      aEnlever.pop();
      if (*aEnlever.top() == MULT) {
        aEnlever.pop();
        val = val * aEnlever.top()->getValue();
      } else {
        aEnlever.pop();
        val = val + aEnlever.top()->getValue();
      }
    }
  }

  statestack.top()->transition(*this, new expression(val));
  lexer->putSymbol(s);
}
