#include <iostream>
#include "Network/Network.h"

int main() {
    auto network = Network{100, 20, 0.01};
    network.initialize();
    std::cout << network << std::endl;
    std::cout << network.getNeurons() << std::endl;
    std::cout << network.getSynapses() << std::endl;
    return 0;
}
