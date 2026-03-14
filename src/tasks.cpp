// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"

double earthRopeTask() {
    const double earthRadiusMeters = 6378100.0;
    Circle earth(earthRadiusMeters);
    double originalFerence = earth.getFerence();
    Circle newEarth(0.0);
    newEarth.setFerence(originalFerence + 1.0);
    return newEarth.getRadius() - earthRadiusMeters;
}

PoolCosts poolTask() {
    const double poolRadius = 3.0;
    const double pathWidth = 1.0;
    const double concretePricePerSqM = 1000.0;
    const double fencePricePerLinM = 2000.0;

    Circle pool(poolRadius);
    Circle outer(poolRadius + pathWidth);

    double concreteArea = outer.getArea() - pool.getArea();
    double fenceLength = outer.getFerence();

    PoolCosts costs;
    costs.concreteCost = concreteArea * concretePricePerSqM;
    costs.fenceCost = fenceLength * fencePricePerLinM;
    return costs;
}
