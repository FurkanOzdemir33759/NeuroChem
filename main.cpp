#include <iostream>
#include "SimulationEngine/Simulation.h"
#include "Neuron/Neuron.h"
#include "Synapse/StaticSynapse.h"

int main() {
    auto network = Network<Neuron, StaticSynapse>{100, 20, 0.01};
    network.initialize();
    network.print();
    std::cout << network.getNeurons() << std::endl;
    std::cout << network.getSynapses() << std::endl;
    return 0;
}
