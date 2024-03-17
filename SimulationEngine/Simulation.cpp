#include "Simulation.h"

template<class NeuronClass, class SynapseClass>
Simulation<NeuronClass, SynapseClass>::Simulation(Network<NeuronClass, SynapseClass> &network, const double DELTA_TIME) : network(network), DELTA_TIME(DELTA_TIME) {}

template<class NeuronClass, class SynapseClass>
Simulation<NeuronClass, SynapseClass>::~Simulation() = default;

template<class NeuronClass, class SynapseClass>
void Simulation<NeuronClass, SynapseClass>::run(double startTime, double duration) {
    for (auto i = startTime + DELTA_TIME; i < startTime + duration; i += DELTA_TIME) {
        network.run(i, DELTA_TIME);
    }
}