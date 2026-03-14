#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

struct PoolCosts {
    double concreteCost;
    double fenceCost;
};

double earthRopeTask();
PoolCosts poolTask();

#endif
