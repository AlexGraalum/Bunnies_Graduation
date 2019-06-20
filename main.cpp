#include <iostream>

#include "bunnymgr.h"

using namespace std;

int main()
{
    srand(time(NULL));
    bunnymgr mgr(5);
    mgr.run();
    return 0;
}
