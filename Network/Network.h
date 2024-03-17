#pragma once

#include <vector>
#include "../Utility/ContainerPrinter.h"
#include "../Neuron/Neuron.h"
#include "../Synapse/StaticSynapse.h"
#include <concepts>

template<typename T>
concept NeuronLike = std::derived_from<T, Neuron>;

template<typename T>
concept SynapseLike = std::derived_from<T, Synapse>;

template<NeuronLike NeuronClass, SynapseLike SynapseClass>
class Network {
private:
    size_t N_EXC;
    size_t N_INH;
    double P_CON;
    std::vector<SynapseClass> synapses;
    std::vector<NeuronClass> neurons;
public:
    Network(size_t excitatoryNumber, size_t inhibitoryNumber, double connectionProbability);
    ~Network();

    size_t getExcitatoryCount();

    size_t getInhibitoryCount();

    double getConnectionProbability();

    std::vector<NeuronClass>& getNeurons();

    std::vector<SynapseClass>& getSynapses();

    void initialize();

    void print();

    void run(double currentTimeStep, const double DELTA_TIME);
};

