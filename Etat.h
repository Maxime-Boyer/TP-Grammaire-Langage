#pragma once

#include "Automate.h"
#include <string>

using namespace std;

/**
 * @brief Etats: classes stockant les procédures possibles de chaque état
 */
class Etat {

    public:
        Etat();
        Etat(int rang);
        virtual ~Etat();
        virtual bool Transition(Automate &automate, Symbole *symbole) = 0;
        int getRang();

    protected:
        int rang;
};

class Etat0 : public Etat {

    public:
        Etat0();
        bool Transition(Automate &automate, Symbole *symbole);
};

class Etat1 : public Etat {

    public:
        Etat1();
        bool Transition(Automate &automate, Symbole *symbole);
};

class Etat2 : public Etat {

    public:
        Etat2();
        bool Transition(Automate &automate, Symbole *symbole);
};

class Etat3 : public Etat {

    public:
        Etat3();
        bool Transition(Automate &automate, Symbole *symbole);
};

class Etat4 : public Etat {

    public:
        Etat4();
        bool Transition(Automate &automate, Symbole *symbole);
};

class Etat5 : public Etat {

    public:
        Etat5();
        bool Transition(Automate &automate, Symbole *symbole);
};

class Etat6 : public Etat {

    public:
        Etat6();
        bool Transition(Automate &automate, Symbole *symbole);
};

class Etat7 : public Etat {

    public:
        Etat7();
        bool Transition(Automate &automate, Symbole *symbole);
};

class Etat8 : public Etat {

    public:
        Etat8();
        bool Transition(Automate &automate, Symbole *symbole);
};

class Etat9 : public Etat {

    public:
        Etat9();
        bool Transition(Automate &automate, Symbole *symbole);
};
