#pragma once

#include "../Network/Network.h"

template<class NeuronClass, class SynapseClass>
class Simulation {
private:
    Network<NeuronClass, SynapseClass>& network;
    const double DELTA_TIME;
public:
    Simulation(Network<NeuronClass, SynapseClass>& network, const double DELTA_TIME);
    ~Simulation();

    void run(double startTime, double duration);
};

