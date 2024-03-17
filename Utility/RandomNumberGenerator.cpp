#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator(size_t seed) : seed(seed),
    randomNumberEngine(std::mt19937(seed)),
    uniformRealDistribution(std::uniform_real_distribution<>(0.0, 1.0)),
    uniformIntDistribution(std::uniform_int_distribution<>(0, 100)) {
}

RandomNumberGenerator::RandomNumberGenerator() : RandomNumberGenerator(time(nullptr)) {}

RandomNumberGenerator::~RandomNumberGenerator() = default;

void RandomNumberGenerator::setSeed(size_t seed) {
    this->seed = seed;
    randomNumberEngine = std::mt19937(seed);
}

void RandomNumberGenerator::setUniformRealDistribution(double start, double end) {
    uniformRealDistribution = std::uniform_real_distribution<>(start, end);
}

void RandomNumberGenerator::setUniformIntDistribution(int start, int end) {
    uniformIntDistribution = std::uniform_int_distribution<>(start, end);
}

double RandomNumberGenerator::generateReal() {
    return uniformRealDistribution(randomNumberEngine);
}

int RandomNumberGenerator::generateInt() {
    return uniformIntDistribution(randomNumberEngine);
}