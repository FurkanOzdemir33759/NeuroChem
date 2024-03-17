#include "Network.h"
#include "../Utility/RandomNumberGenerator.h"


Network::Network(size_t excitatoryNumber, size_t inhibitoryNumber, double connectionProbability) :
    N_EXC(excitatoryNumber),
    N_INH(inhibitoryNumber),
    P_CON(connectionProbability),
    synapses(std::vector<Synapse>{}),
    neurons(std::vector<Neuron>{}){
}

Network::~Network() = default;

size_t Network::getExcitatoryCount() {return N_EXC;}

size_t Network::getInhibitoryCount() {return N_INH;}

double Network::getConnectionProbability() {return P_CON;}

std::vector<Neuron>& Network::getNeurons() {return neurons;}

std::vector<Synapse>& Network::getSynapses() {return synapses;}

void Network::initialize() {
    auto rng = RandomNumberGenerator{};
    index_t synapseIndex = 0;

    //Initialize neurons
    for (auto i = 0; i < N_EXC + N_INH; i++) {
        if (i < N_EXC) {
            neurons.emplace_back( i, NEURON_TYPE::EXC);
        } else {
            neurons.emplace_back( i, NEURON_TYPE::INH);
        }
    }

    //Initialize synapses
    for (index_t i = 0; i < N_EXC + N_INH; i++) {
        for (index_t j = 0; j < N_EXC + N_INH; j++) {
            if (i != j && rng.generateReal() < P_CON) {
                synapses.push_back(Synapse{&neurons, synapseIndex, i, j});
                ++synapseIndex;
            }
        }
    }

    //Set the synapse reference of neurons
    for (auto i = 0; i < N_EXC + N_INH; i++) {
        neurons[i].setSynapses(&synapses);
    }

    //Update neurons according to the synapses
    for (auto i = 0; i < synapses.size(); i++) {
        auto& synapse = synapses[i];
        neurons[synapse.getPreNeuron()].addSynapseOut(synapse.getPostNeuron());
        neurons[synapse.getPostNeuron()].addSynapseIn(synapse.getPreNeuron());
    }
}

std::ostream &operator<<(std::ostream &os, const Network &network) {
    os << "#Excitatory: " << network.N_EXC << std::endl;
    os << "#Inhibitory: " << network.N_INH << std::endl;
    os << "Connection Probability: " << network.P_CON << std::endl;
    os << "#Synapses: " << network.synapses.size() << std::endl;
    return os;
}


