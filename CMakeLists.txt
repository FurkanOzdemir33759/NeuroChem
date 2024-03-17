cmake_minimum_required(VERSION 3.27)
project(NeuroChemSim)

set(CMAKE_CXX_STANDARD 23)

add_executable(NeuroChemSim main.cpp
        Neuron/Neuron.cpp
        Neuron/Neuron.h
        Synapse/Synapse.cpp
        Synapse/Synapse.h
        Network/Network.cpp
        Network/Network.h
        Utility/RandomNumberGenerator.cpp
        Utility/RandomNumberGenerator.h
        Neuron/Neuron.fwd.h
        Synapse/Synapse.fwd.h
        Utility/ContainerPrinter.h
        SimulationEngine/Simulation.cpp
        SimulationEngine/Simulation.h
        Synapse/StaticSynapse.cpp
        Synapse/StaticSynapse.h
        Synapse/StaticSynapse.h
)
