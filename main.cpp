#include <iostream>
#include "lexer.h"


int main(void) {

   string chaine;
   
   cout << "Entrez une expression à analyser:" << endl;
   cin >> chaine;

   Lexer l(chaine);

   Symbole * s;
   while(*(s=l.Consulter())!=FIN) {
      s->Affiche();
      cout<<endl;
      l.Avancer();
   }
   return 0;
}

