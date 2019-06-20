#ifndef BUNNY_H
#define BUNNY_H

#include "variables.h"

class bunny
{
    public:
        bunny();
        virtual ~bunny();
        bunny(const bunny& other);
        bunny& operator=(const bunny& other);

        int Getage() { return age; }
        void Setage(int val) { age = val; }
        FurType Getfur() { return fur; }
        void Setfur(FurType val) { fur = val; }
        SexType Getsex() { return sex; }
        void Setsex(SexType val) { sex = val; }
        NameList Getname() { return name; }
        void Setname(NameList val) { name = val; }
        bool Getvampire() { return vampire; }
        void Setvampire(bool val) { vampire = val; }

    protected:

    private:
        int age;
        FurType fur;
        SexType sex;
        NameList name;
        bool vampire;
};

#endif // BUNNY_H
