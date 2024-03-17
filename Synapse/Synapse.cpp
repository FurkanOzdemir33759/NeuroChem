#include "Synapse.h"

std::ostream& operator<<(std::ostream& os, const SYNAPSE_TYPE& type) {
    if (type == SYNAPSE_TYPE::EXC2EXC) {
        os << "EXCITATORY -> EXCITATORY" << std::endl;
    } else if (type == SYNAPSE_TYPE::EXC2INH) {
        os << "EXCITATORY -> INHIBITORY" << std::endl;
    } else if (type == SYNAPSE_TYPE::INH2EXC) {
        os << "INHIBITORY -> EXCITATORY" << std::endl;
    } else if (type == SYNAPSE_TYPE::INH2INH) {
        os << "INHIBITORY -> INHIBITORY" << std::endl;
    } else {
        os << "UNKNOWN" << std::endl;
    }
    return os;
}

Synapse::Synapse(std::vector<Neuron>* neurons, index_t index, index_t preNeuronIndex, index_t postNeuronIndex) : index(index), preNeuronIndex(preNeuronIndex), postNeuronIndex(postNeuronIndex), neurons(neurons), type(determineType()) {}

Synapse::~Synapse() = default;

void Synapse::setType(SYNAPSE_TYPE _type) {type = _type;}

SYNAPSE_TYPE Synapse::getType() {return type;}

void Synapse::setIndex(index_t _index) {index = _index;}

index_t Synapse::getIndex() {return index;}

void Synapse::setPreNeuron(index_t _preNeuronIndex) {preNeuronIndex = _preNeuronIndex;}

index_t Synapse::getPreNeuron() {return preNeuronIndex;}

void Synapse::setPostNeuron(index_t _postNeuronIndex) {postNeuronIndex = _postNeuronIndex;}

index_t Synapse::getPostNeuron() {return postNeuronIndex;}

void Synapse::connect(index_t _preNeuronIndex, index_t _postNeuronIndex) {
    setPreNeuron(_preNeuronIndex);
    setPostNeuron(_postNeuronIndex);
}

SYNAPSE_TYPE Synapse::determineType() {
    if ((*neurons)[preNeuronIndex].getType() == NEURON_TYPE::EXC) {
        if ((*neurons)[postNeuronIndex].getType() == NEURON_TYPE::EXC) {
            return SYNAPSE_TYPE::EXC2EXC;
        } else {
            return SYNAPSE_TYPE::EXC2INH;
        }
    } else {
        if ((*neurons)[postNeuronIndex].getType() == NEURON_TYPE::EXC) {
            return SYNAPSE_TYPE::INH2EXC;
        } else {
            return SYNAPSE_TYPE::INH2INH;
        }
    }
}

void Synapse::setNeurons(std::vector<Neuron>* _neurons) {
    neurons = _neurons;
}

std::ostream &operator<<(std::ostream &os, const Synapse &synapse) {
    os << "Synapse " << synapse.index << std::endl;
    os << synapse.type;
    os << "PreNeuron: " << synapse.preNeuronIndex << std::endl;
    os << "PostNeuron: " << synapse.postNeuronIndex << std::endl;
    return os;
}

