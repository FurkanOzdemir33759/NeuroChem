#pragma once

#include <iostream>
#include "Synapse.fwd.h"
#include "../Neuron/Neuron.fwd.h"
#include "../Neuron/Neuron.h"

#define index_t int

enum class SYNAPSE_TYPE {
    EXC2EXC,
    EXC2INH,
    INH2EXC,
    INH2INH,
    UNSPECIFIED
};

std::ostream& operator<<(std::ostream& os, const SYNAPSE_TYPE& type);

class Synapse {
private:
    std::vector<Neuron>* neurons = nullptr;
    index_t index;
    SYNAPSE_TYPE type;
    index_t preNeuronIndex;
    index_t postNeuronIndex;
public:
    Synapse(std::vector<Neuron>* neurons, index_t index, index_t preNeuronIndex, index_t postNeuronIndex);
    ~Synapse();

    SYNAPSE_TYPE getType();
    void setType(SYNAPSE_TYPE type);

    index_t getIndex();
    void setIndex(index_t index);

    index_t getPreNeuron();
    void setPreNeuron(index_t preNeuron);

    index_t getPostNeuron();
    void setPostNeuron(index_t postNeuron);

    void connect(index_t _preNeuronIndex, index_t _postNeuronIndex);

    void setNeurons(std::vector<Neuron>* neurons);

    SYNAPSE_TYPE determineType();

    friend std::ostream& operator<<(std::ostream& os, const Synapse& synapse);
};

