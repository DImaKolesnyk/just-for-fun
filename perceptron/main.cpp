#include <iostream>
#include "Perceptron.h"

int main() {

    std::vector <bool> signal_set;
    signal_set.push_back(0);
    signal_set.push_back(0);

    std::map < std::vector, bool> learn_set;
    learn_set[ (std::vector){1, 1} ] = 1;
    learn_set[ {1, 0} ] = 0;
    learn_set[ {0, 1} ] = 0;
    learn_set[ {0, 0} ] = 0;

    Perceptron a;
    a.learn(learn_set);
    a.signal(signal_set);

    std::cout << a.answer << std::endl;

    return 0;
}