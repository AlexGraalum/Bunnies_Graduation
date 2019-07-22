#ifndef BUNNYMGR_H
#define BUNNYMGR_H

#include "bunny.h"
#include "variables.h"

class bunnymgr{
    public:
        bunnymgr(int );
        virtual ~bunnymgr();
        void run();
    protected:

    private:
        unsigned int fieldSize = 1600;
        std::list<bunny *> mgr;
        std::vector<char> field;
        int population;
        void AgeBuns();
        void BreedBuns();
        void Mate(bunny *);
        int CountVamps();
        void TurnBuns();
        bool AllVampire();
        std::list<bunny *>::const_iterator GetRand();
        std::list<bunny *>::const_iterator kill(std::list<bunny *>::const_iterator it);
        void sleep(int );
        void PrintBuns();
        void initialize(int );
        void add(bunny *);
};

#endif // BUNNYMGR_H
