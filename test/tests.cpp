#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

static const double PI = 3.141592653589793;
static const double EPS = 1e-5;

TEST(CircleConstructor, SetsRadius) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, EPS);
}

TEST(CircleConstructor, CalculatesFerence) {
    Circle c(5.0);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * 5.0, EPS);
}

TEST(CircleConstructor, CalculatesArea) {
    Circle c(5.0);
    EXPECT_NEAR(c.getArea(), PI * 25.0, EPS);
}

TEST(SetRadius, UpdatesRadius) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_NEAR(c.getRadius(), 10.0, EPS);
}

TEST(SetRadius, UpdatesFerence) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * 10.0, EPS);
}

TEST(SetRadius, UpdatesArea) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_NEAR(c.getArea(), PI * 100.0, EPS);
}

TEST(SetFerence, UpdatesFerence) {
    Circle c(1.0);
    double f = 2.0 * PI * 7.0;
    c.setFerence(f);
    EXPECT_NEAR(c.getFerence(), f, EPS);
}

TEST(SetFerence, UpdatesRadius) {
    Circle c(1.0);
    double f = 2.0 * PI * 7.0;
    c.setFerence(f);
    EXPECT_NEAR(c.getRadius(), 7.0, EPS);
}

TEST(SetFerence, UpdatesArea) {
    Circle c(1.0);
    double f = 2.0 * PI * 7.0;
    c.setFerence(f);
    EXPECT_NEAR(c.getArea(), PI * 49.0, EPS);
}

TEST(SetArea, UpdatesArea) {
    Circle c(1.0);
    double a = PI * 16.0;
    c.setArea(a);
    EXPECT_NEAR(c.getArea(), a, EPS);
}

TEST(SetArea, UpdatesRadius) {
    Circle c(1.0);
    c.setArea(PI * 16.0);
    EXPECT_NEAR(c.getRadius(), 4.0, EPS);
}

TEST(SetArea, UpdatesFerence) {
    Circle c(1.0);
    c.setArea(PI * 16.0);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * 4.0, EPS);
}

TEST(CircleZeroRadius, ConstructorZero) {
    Circle c(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(CircleSmall, SmallRadius) {
    Circle c(0.001);
    EXPECT_NEAR(c.getRadius(), 0.001, EPS);
    EXPECT_NEAR(c.getFerence(), 2.0 * PI * 0.001, EPS);
    EXPECT_NEAR(c.getArea(), PI * 0.001 * 0.001, 1e-9);
}

TEST(CircleConsistency, SetRadiusThenFerence) {
    Circle c(3.0);
    c.setRadius(5.0);
    c.setFerence(2.0 * PI * 3.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
    EXPECT_NEAR(c.getArea(), PI * 9.0, EPS);
}

TEST(CircleConsistency, SetAreaThenRadius) {
    Circle c(1.0);
    c.setArea(PI * 9.0);
    EXPECT_NEAR(c.getRadius(), 3.0, EPS);
    c.setRadius(6.0);
    EXPECT_NEAR(c.getArea(), PI * 36.0, EPS);
}

TEST(SetRadius, NegativeClampedToZero) {
    Circle c(5.0);
    c.setRadius(-3.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(SetFerence, NegativeClampedToZero) {
    Circle c(5.0);
    c.setFerence(-10.0);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(SetArea, NegativeClampedToZero) {
    Circle c(5.0);
    c.setArea(-25.0);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
}

TEST(CircleConstructor, NegativeRadiusClampedToZero) {
    Circle c(-1.0);
    EXPECT_NEAR(c.getRadius(), 0.0, EPS);
    EXPECT_NEAR(c.getFerence(), 0.0, EPS);
    EXPECT_NEAR(c.getArea(), 0.0, EPS);
}

TEST(EarthRopeTask, GapExactValue) {
    double gap = earthRopeTask();
    EXPECT_NEAR(gap, 1.0 / (2.0 * PI), 1e-9);
}

TEST(EarthRopeTask, GapApproximation) {
    double gap = earthRopeTask();
    EXPECT_NEAR(gap, 1.0 / (2.0 * PI), EPS);
}

TEST(EarthRopeTask, GapIsPositive) {
    double gap = earthRopeTask();
    EXPECT_GT(gap, 0.0);
}

TEST(EarthRopeTask, GapIsSmall) {
    double gap = earthRopeTask();
    EXPECT_LT(gap, 1.0);
}

TEST(PoolTask, ConcreteCost) {
    PoolCosts costs = poolTask();
    double expectedConcreteArea = PI * (4.0 * 4.0 - 3.0 * 3.0);
    EXPECT_NEAR(costs.concreteCost, expectedConcreteArea * 1000.0, 1e-2);
}

TEST(PoolTask, FenceCost) {
    PoolCosts costs = poolTask();
    double expectedFenceLength = 2.0 * PI * 4.0;
    EXPECT_NEAR(costs.fenceCost, expectedFenceLength * 2000.0, 1e-2);
}

TEST(PoolTask, ConcreteCostIsPositive) {
    PoolCosts costs = poolTask();
    EXPECT_GT(costs.concreteCost, 0.0);
}

TEST(PoolTask, FenceCostIsPositive) {
    PoolCosts costs = poolTask();
    EXPECT_GT(costs.fenceCost, 0.0);
}
