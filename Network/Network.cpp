#include "Network.h"
#include "../Utility/RandomNumberGenerator.h"

template<NeuronLike NeuronClass, SynapseLike SynapseClass>
Network<NeuronClass, SynapseClass>::Network(size_t excitatoryNumber, size_t inhibitoryNumber, double connectionProbability) :
    N_EXC(excitatoryNumber),
    N_INH(inhibitoryNumber),
    P_CON(connectionProbability),
    synapses(std::vector<SynapseClass>{}),
    neurons(std::vector<NeuronClass>{}){
}

template<NeuronLike NeuronClass, SynapseLike SynapseClass>
Network<NeuronClass, SynapseClass>::~Network() = default;

template<NeuronLike NeuronClass, SynapseLike SynapseClass>
size_t Network<NeuronClass, SynapseClass>::getExcitatoryCount() {return N_EXC;}

template<NeuronLike NeuronClass, SynapseLike SynapseClass>
size_t Network<NeuronClass, SynapseClass>::getInhibitoryCount() {return N_INH;}

template<NeuronLike NeuronClass, SynapseLike SynapseClass>
double Network<NeuronClass, SynapseClass>::getConnectionProbability() {return P_CON;}

template<NeuronLike NeuronClass, SynapseLike SynapseClass>
std::vector<NeuronClass>& Network<NeuronClass, SynapseClass>::getNeurons() {return neurons;}

template<NeuronLike NeuronClass, SynapseLike SynapseClass>
std::vector<SynapseClass>& Network<NeuronClass, SynapseClass>::getSynapses() {return synapses;}

template<NeuronLike NeuronClass, SynapseLike SynapseClass>
void Network<NeuronClass, SynapseClass>::initialize() {
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

template<NeuronLike NeuronClass, SynapseLike SynapseClass>
void Network<NeuronClass, SynapseClass>::print() {
    std::cout << "#Excitatory: " << N_EXC << std::endl;
    std::cout << "#Inhibitory: " << N_INH << std::endl;
    std::cout << "Connection Probability: " << P_CON << std::endl;
    std::cout << "#Synapses: " << synapses.size() << std::endl;
}

template<NeuronLike NeuronClass, SynapseLike SynapseClass>
void Network<NeuronClass, SynapseClass>::run(double currentTimeStep, const double DELTA_TIME) {}


