#include "Neuron.h"

std::ostream& operator<<(std::ostream& os, const NEURON_TYPE& type) {
    if (type == NEURON_TYPE::EXC) {
        os << "EXCITATORY" << std::endl;
    } else if (type == NEURON_TYPE::INH) {
        os << "INHIBITORY" << std::endl;
    } else {
        os << "UNKNOWN" << std::endl;
    }
    return os;
}

Neuron::Neuron(index_t index, NEURON_TYPE type) :
    index(index),
    type(type),
    synapsesIn(std::vector<index_t>{}),
    synapsesOut(std::vector<index_t>{}) {
}

Neuron::~Neuron() = default;

NEURON_TYPE Neuron::getType() {return type;}

void Neuron::setType(NEURON_TYPE _type) { type = _type;}

index_t Neuron::getIndex() {return index;}

void Neuron::setIndex(index_t _index) {index = _index;}

std::vector<index_t>& Neuron::getIncomingSynapses() {return synapsesIn;}

void Neuron::addSynapseIn(index_t synapseIn) {synapsesIn.push_back(synapseIn);}

std::vector<index_t>& Neuron::getOutgoingSynapses() {return synapsesOut;}

void Neuron::addSynapseOut(index_t synapseOut) {synapsesOut.push_back(synapseOut);}

void Neuron::setSynapses(std::vector<Synapse>* _synapses) {synapses = _synapses;}

std::ostream &operator<<(std::ostream &os, const Neuron &neuron) {
    os << "Neuron " << neuron.index << std::endl;
    os << neuron.type;
    os << "SynapsesIn: ";
    for (auto i = neuron.synapsesIn.begin(); i != neuron.synapsesIn.end(); i++) {
        os << *i;
        if (i + 1 != neuron.synapsesIn.end()) {
            os << ", ";
        }

    }
    os << std::endl;
    os << "SynapsesOut: ";
    for (auto i = neuron.synapsesOut.begin(); i != neuron.synapsesOut.end(); i++) {
        os << *i;
        if (i + 1 != neuron.synapsesOut.end()) {
            os << ", ";
        }
    }
    os << std::endl;
    return os;
}



