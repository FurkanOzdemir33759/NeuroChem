#include "StaticSynapse.h"

StaticSynapse::StaticSynapse(double W, std::vector<Neuron> *neurons, int index, int preNeuronIndex, int postNeuronIndex) : Synapse(neurons, index, preNeuronIndex, postNeuronIndex), W(W) {}

std::ostream &operator<<(std::ostream &os, const StaticSynapse &staticSynapse) {
    os << static_cast<const Synapse&>(staticSynapse);
    os << "Weight: " << staticSynapse.W << std::endl;
    return os;
}

void StaticSynapse::run(double currentTimeStep, double DELTA_TIME) {}
