#pragma once

#include <map>
#include <string>

using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS",   "MULT",
                             "INT",     "FIN",      "ERREUR", "EXPR"};

class Symbole {
public:
  Symbole(int i) : ident(i) {}
  virtual ~Symbole() {}
  operator int() const { return ident; }
  virtual void Affiche();
  virtual int getValue();

protected:
  int ident;
};

class Openpar : public Symbole {
public:
  Openpar() : Symbole(OPENPAR) {}
  ~Openpar() {}
  virtual void Affiche();

protected:
};

class Closepar : public Symbole {
public:
  Closepar() : Symbole(CLOSEPAR) {}
  ~Closepar() {}
  virtual void Affiche();

protected:
};

class Plus : public Symbole {
public:
  Plus() : Symbole(PLUS) {}
  ~Plus() {}
  virtual void Affiche();

protected:
};

class Mult : public Symbole {
public:
  Mult() : Symbole(MULT) {}
  ~Mult() {}
  virtual void Affiche();

protected:
};

class Entier : public Symbole {
public:
  Entier(int v) : Symbole(INT), valeur(v) {}
  ~Entier() {}
  virtual void Affiche();
  int eval() { return valeur; }
  int getValue();

protected:
  int valeur;
};

class Fin : public Symbole {
public:
  Fin() : Symbole(FIN) {}
  ~Fin() {}
  virtual void Affiche();

protected:
};

class Erreur : public Symbole {
public:
  Erreur() : Symbole(ERREUR) {}
  ~Erreur() {}
  virtual void Affiche();

protected:
};

class expression : public Symbole {
public:
  expression(int val) : Symbole(EXPR), valeur(val) {}
  ~expression() {}
  virtual void Affiche();
  int getValue();

protected:
  int valeur;
};
