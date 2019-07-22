#include <iostream>

#include "bunnymgr.h"
#include "variables.h"

using namespace std;

int main(){
    srand(time(NULL));
    bunnymgr *manager = new bunnymgr(5);
    manager->run();
    delete manager;
    return 0;
}
