#include "bunnymgr.h"

bunnymgr::bunnymgr(int x)
{
    initialize(x);
}

bunnymgr::~bunnymgr()
{
    while(head->next){
        node *temp = head->next;
        head->next = temp->next;
        delete temp;
    }
    delete head;
}

void bunnymgr::initialize(int x){
    for (int i = 0; i < x; i++){
        bunny b = new bunny();
        add(b);
    }
}

void bunnymgr::add(bunny *b){
    if(!head){
        head = new node(b);
    }else{
        node *curr = head;
        while(curr->next){
            curr = curr->next;
        }
        curr->next = new node(b);
    }
}

void bunnymgr::AgeBuns(){
    node *curr = head;
    while(curr){
        bunny *b = curr.Getbunny();
        if(b.Getage() == 10){
            kill(curr);
            cout << "Bunny " << b.Getname()
        }
        b.Setage(b.Getage() + 1);
        curr = curr->next;
    }
}

void bunnymgr::run(){
    while(population != 0){

        AgeBuns();
    }
}

