#pragma once

#include <iostream>
#include <vector>
#include "Neuron.fwd.h"
#include "../Synapse/Synapse.fwd.h"

#define index_t int

enum class NEURON_TYPE {
    EXC,
    INH,
    UNSPECIFIED
};

std::ostream& operator<<(std::ostream& os, const NEURON_TYPE& type);

class Neuron {
private:
    std::vector<Synapse>* synapses = nullptr;
    NEURON_TYPE type;
    index_t index;
    std::vector<index_t> synapsesIn;
    std::vector<index_t> synapsesOut;
public:
    Neuron(index_t index, NEURON_TYPE type);
    ~Neuron();

    NEURON_TYPE getType();
    void setType(NEURON_TYPE type);

    index_t getIndex();
    void setIndex(index_t index);

    void addSynapseIn(index_t synapseInIndex);
    std::vector<index_t>& getIncomingSynapses();

    void addSynapseOut(index_t synapseOutIndex);
    std::vector<index_t>& getOutgoingSynapses();

    void setSynapses(std::vector<Synapse>* synapses);

    friend std::ostream& operator<<(std::ostream& os, const Neuron& neuron);

};

