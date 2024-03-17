#pragma once

#include <random>
#include <ctime>

class RandomNumberGenerator {
private:
    size_t seed;
    std::mt19937 randomNumberEngine;
    std::uniform_int_distribution<> uniformIntDistribution;
    std::uniform_real_distribution<> uniformRealDistribution;
public:
    RandomNumberGenerator();
    RandomNumberGenerator(size_t seed);
    ~RandomNumberGenerator();

    void setSeed(size_t seed);

    void setUniformRealDistribution(double start, double end);

    void setUniformIntDistribution(int start, int end);

    double generateReal();

    int generateInt();

};
