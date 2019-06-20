#ifndef BUNNYMGR_H
#define BUNNYMGR_H

#include "bunny.h"

struct node{
    bunny *bun;
    node *next;
    node(bunny *b){
        bun = b;
        next = nullptr;
    };
    bunny *Getbunny(){
        return &bun;
    };
};

class bunnymgr{
    public:
        bunnymgr(int );
        virtual ~bunnymgr();
        void initialize(int );
        void add(bunny *);
        void run();

    protected:

    private:
        unsigned int population;
        node *head = nullptr;
};

#endif // BUNNYMGR_H
