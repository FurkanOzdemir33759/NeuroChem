#pragma once

#include <vector>
#include "../Utility/ContainerPrinter.h"
#include "../Neuron/Neuron.h"
#include "../Synapse/Synapse.h"

class Network {
private:
    size_t N_EXC;
    size_t N_INH;
    double P_CON;
    std::vector<Synapse> synapses;
    std::vector<Neuron> neurons;
public:
    Network(size_t excitatoryNumber, size_t inhibitoryNumber, double connectionProbability);
    ~Network();

    size_t getExcitatoryCount();

    size_t getInhibitoryCount();

    double getConnectionProbability();

    std::vector<Neuron>& getNeurons();

    std::vector<Synapse>& getSynapses();

    void initialize();

    friend std::ostream& operator<<(std::ostream& os, const Network& network);
};

