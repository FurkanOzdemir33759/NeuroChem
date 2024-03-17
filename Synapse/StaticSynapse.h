#pragma once

#include "Synapse.h"

class StaticSynapse : public Synapse {
private:
    const double W;
public:
    StaticSynapse(double W, std::vector<Neuron>* neurons, index_t index, index_t preNeuronIndex, index_t postNeuronIndex);

    friend std::ostream& operator<<(std::ostream& os, const StaticSynapse& staticSynapse);

    void run(double currentTimeStep, double DELTA_TIME);
};
