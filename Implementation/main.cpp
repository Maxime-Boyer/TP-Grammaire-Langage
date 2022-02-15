#include "Automate.h"
#include "lexer.h"
#include <iostream>

int main(void) {

  string chaine;

  cout << "Indiquez la phrase à analyser :" << endl;
  cin >> chaine;
  Automate *a = new Automate(chaine);
  a->run();

  return 0;
}
