#include <iostream>
#include "circle.h"
#include "tasks.h"

int main() {
    double gap = earthRopeTask();
    std::cout << "Earth-rope gap: " << gap << " m" << std::endl;

    PoolCosts costs = poolTask();
    std::cout << "Pool concrete cost: " << costs.concreteCost << " rub" << std::endl;
    std::cout << "Pool fence cost:    " << costs.fenceCost << " rub" << std::endl;

    return 0;
}
