#include "bunnymgr.h"

bunnymgr::bunnymgr(int x){
    mgr = {};
    field.assign(fieldSize, '*');
    population = 0;
    std::cout << "Year : 0\n";
    initialize(x);
    PrintBuns();
}

bunnymgr::~bunnymgr(){
    mgr.clear();
}

void bunnymgr::initialize(int x){
    for (int i = 0; i < x; i++){
        bunny *b = new bunny();
        add(b);
    }
}

void bunnymgr::add(bunny *b){
    if(population <= MAX_POP){
        population++;
        mgr.push_back(b);
        if(b->Getvampire()){
            std::cout << "Radioactive Mutant Vampire Bunny " << b->Getname() << " was born!\n";
            sleep(1);
        }else{
            std::cout << "Bunny " << b->Getname() << " was born!\n";
            sleep(1);
        }
    }else{
        std::cout << "Food shortage! 500 random bunnies to the cosmic slaughter!\n";
        for(int x = 0; x < 500; x++){

        }
        sleep(1);
    }
}

void bunnymgr::AgeBuns(){
    std::list<bunny *>::const_iterator it = mgr.begin();
    while(it != mgr.cend()){
        bunny *b = *it;
        if(b->Getvampire()){
            if(b->Getage() == 50){
                it = kill(it);
            }else{
                b->AgePlus();
                it++;
            }
        }else{
            if(b->Getage() == 10){
                it = kill(it);
            }else{
                b->AgePlus();
                it++;
            }
        }
    }
}

void bunnymgr::BreedBuns(){
    std::list<bunny *>::const_iterator it = mgr.begin();
    while(it != mgr.cend()){
        bunny *b = *it;
        if(!b->Getvampire()){
            if(b->Getsex() == MALE){
                if(b->Getage() >= 2){
                    Mate(b);
                }
            }
        }
        ++it;
    }
}

void bunnymgr::Mate(bunny *d){
    std::list<bunny *>::const_iterator it = mgr.begin();
    while(it != mgr.cend()){
        bunny *m = *it;
        if(!m->Getvampire()){
            if(m->Getsex() == FEMALE){
                if(m->Getage() >= 2){
                    bunny *n = new bunny();
                    n->Setfur(m->Getfur());
                    add(n);
                }
            }
        }
        ++it;
    }
}

int bunnymgr::CountVamps(){
    int x = 0;
    std::list<bunny *>::const_iterator it = mgr.begin();
    while(it != mgr.cend()){
        bunny *m = *it;
        if(m->Getvampire()){
            ++x;
        }
        ++it;
    }
    return x;
}

void bunnymgr::TurnBuns(){
    int x = CountVamps();
    while(x > 0){
        if(AllVampire() == false){
            bunny *t = *GetRand();
            while(t->Getvampire()){
                t = *GetRand();
            }
            t->Setvampire(true);
        }
        --x;
    }
}

bool bunnymgr::AllVampire(){
    bool check = true;
    std::list<bunny *>::const_iterator it = mgr.begin();
    while(it != mgr.cend()){
        bunny *b = *it;
        if(b->Getvampire() == false){
            check = false;
        }
        ++it;
    }
    return check;
}

std::list<bunny *>::const_iterator bunnymgr::GetRand(){
    size_t i = rand()%mgr.size();
    std::list<bunny *>::const_iterator it = mgr.begin();
    std::advance(it, i);
    return it;
}

std::list<bunny *>::const_iterator bunnymgr::kill(std::list<bunny *>::const_iterator it){
    --population;
    bunny *b = *it;
    if(b->Getvampire()){
        std::cout << "Radioactive Mutant Vampire Bunny " << b->Getname() << " has died!\n";
        return mgr.erase(it);
    }else{
        std::cout << "Bunny " << b->Getname() << " has died!\n";
        return mgr.erase(it);
    }
}

void bunnymgr::PrintBuns(){
    std::list<bunny *>::const_iterator it = mgr.begin();

    while(it != mgr.cend()){
        bunny *b = *it;
        std::cout << std::left << std::setfill(' ') << std::setw(21);
        if(b->Getvampire()){
            std::cout << "Mutant Vampire Bunny " << std::setw(7) << std::right << b->Getname();
        }else{
            std::cout << "Bunny " << std::setw(7) << std::right << b->Getname();
        }
        std::cout << std::setw(7) << "| Age: " << std::right << std::setw(2) << b->Getage();
        std::cout << std::setw(7) << "| Fur: " << std::right << b->Printfur() << std::endl;
        sleep(.5);
        ++it;
    }
}

void bunnymgr::run(){
    int x = 1;
    while(population != 0){
        std::cout << "Year: " << x << std::endl;
        AgeBuns();
        BreedBuns();
        TurnBuns();
        sleep(1);
        PrintBuns();
        sleep(0);
        x++;
    }
    std::cout << "The bunny population is diminished.\n";
}

void bunnymgr::sleep(int x){
    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::seconds(x));
}
