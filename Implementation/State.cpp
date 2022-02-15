#include "State.h"
#include "symbole.h"
#include <iostream>
#include <stdio.h>

State::State() {}
State::~State() {}
State::State(string s) { name = s; }

State0::State0() : State("E0") {}

State1::State1() : State("E1") {}

State2::State2() : State("E2") {}

State3::State3() : State("E3") {}

State4::State4() : State("E4") {}

State5::State5() : State("E5") {}

State6::State6() : State("E6") {}

State7::State7() : State("E7") {}

State8::State8() : State("E8") {}

State9::State9() : State("E9") {}

bool State0::transition(Automate &automate, Symbole *s) {
  switch (*s) {
  case INT:
    automate.decalage(s, new State3);
    break;
  case OPENPAR:
    automate.decalage(s, new State2);
    break;
  case EXPR:
    automate.decalage(s, new State1);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }
  return true;
}

bool State1::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case PLUS:
    automate.decalage(s, new State4);
    break;
  case MULT:
    automate.decalage(s, new State5);
    break;
  case FIN:
    return false;
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }

  return true;
}

bool State2::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case INT:
    automate.decalage(s, new State3);
    break;
  case OPENPAR:
    automate.decalage(s, new State2);
    break;
  case EXPR:
    automate.decalage(s, new State6);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }

  return true;
}

bool State3::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case PLUS:
    automate.reduction(1, new Plus);
    break;
  case MULT:
    automate.reduction(1, new Mult);
    break;
  case CLOSEPAR:
    automate.reduction(1, new Closepar);
    break;
  case FIN:
    automate.reduction(1, new Fin);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }

  return true;
}

bool State4::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case INT:
    automate.decalage(s, new State3);
    break;
  case OPENPAR:
    automate.decalage(s, new State2);
    break;
  case EXPR:
    automate.decalage(s, new State7);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }

  return true;
}

bool State5::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case INT:
    automate.decalage(s, new State3);
    break;
  case OPENPAR:
    automate.decalage(s, new State2);
    break;
  case EXPR:
    automate.decalage(s, new State8);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }

  return true;
}

bool State6::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case PLUS:
    automate.decalage(s, new State4);
    break;
  case MULT:
    automate.decalage(s, new State5);
    break;
  case CLOSEPAR:
    automate.decalage(s, new State9);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }

  return true;
}

bool State7::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case PLUS:
    automate.reduction(3, new Plus);
    break;
  case MULT:
    automate.decalage(s, new State5);
    break;
  case CLOSEPAR:
    automate.reduction(3, new Closepar);
    break;
  case FIN:
    automate.reduction(3, new Fin);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }

  return true;
}

bool State8::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case PLUS:
    automate.reduction(3, new Plus);
    break;
  case MULT:
    automate.reduction(3, new Mult);
    break;
  case CLOSEPAR:
    automate.reduction(3, new Closepar);
    break;
  case FIN:
    automate.reduction(3, new Fin);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }

  return true;
}

bool State9::transition(Automate &automate, Symbole *s) {

  switch (*s) {
  case PLUS:
    automate.reduction(3, new Plus);
    break;
  case MULT:
    automate.reduction(3, new Mult);
    break;
  case CLOSEPAR:
    automate.reduction(3, new Closepar);
    break;
  case FIN:
    automate.reduction(3, new Fin);
    break;
  default:
    automate.decalage(new Symbole(ERREUR), NULL);
    return false;
  }

  return true;
}

int State::state() { return -1; }

int State0::state() { return 0; }

int State1::state() { return 1; }

int State2::state() { return 2; }

int State3::state() { return 3; }

int State4::state() { return 4; }

int State5::state() { return 5; }

int State6::state() { return 6; }

int State7::state() { return 7; }

int State8::state() { return 8; }

int State9::state() { return 9; }
