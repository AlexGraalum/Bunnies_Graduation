#include "bunny.h"

bunny::bunny(){
    Setage(0);
    Setfur(static_cast<FurType>(rand()%(int)FurType::SPOTTED));
    if(rand()%2 < 1){
        Setsex(SexType::FEMALE);
    }else{
        Setsex(SexType::MALE);
    }
    if(sex == MALE){
        name = "male";
    }else{
        name = "female";
    }
    if(rand()%100 < 2){
        Setvampire(true);
    }else{
        Setvampire(false);
    }
}

bunny::~bunny()
{
    //dtor
}

bunny::bunny(const bunny& other)
{
    Setage(other.age);
    Setname(other.name);
    Setfur(other.fur);
    Setsex(other.sex);
    Setvampire(other.vampire);
}

bunny& bunny::operator=(const bunny& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
        this->Setage(rhs.age);
        this->Setfur(rhs.fur);
        this->Setname(rhs.name);
        this->Setsex(rhs.sex);
        this->Setvampire(rhs.vampire);
    return *this;
}

std::string bunny::Printfur(){
    switch(fur){
        case 0:
            return "White";
            break;
        case 1:
            return "Brown";
            break;
        case 2:
            return "Black";
            break;
        case 3:
            return "Spotted";
            break;
        default:
            return "null";
            break;
    }
}
