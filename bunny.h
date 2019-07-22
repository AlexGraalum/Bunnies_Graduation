#ifndef BUNNY_H
#define BUNNY_H

#include <string.h>

#include "variables.h"

class bunny
{
    public:
        bunny();
        ~bunny();
        bunny(const bunny& other);
        bunny& operator=(const bunny& other);

        int Getage() { return age; }
        void Setage(int val) { age = val; }
        FurType Getfur() { return fur; }
        std::string Printfur();
        void Setfur(FurType val) { fur = val; }
        SexType Getsex() { return sex; }
        void Setsex(SexType val) { sex = val; }
        std::string Getname() { return name; }
        void Setname(std::string val) { name = val; }
        bool Getvampire() { return vampire; }
        void Setvampire(bool val) { vampire = val; }

        void AgePlus(){age++;}

    protected:

    private:
        int age;
        FurType fur;
        SexType sex;
        std::string name;
        bool vampire;
};

#endif // BUNNY_H
