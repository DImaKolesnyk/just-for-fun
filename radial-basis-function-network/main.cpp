#include "Data.h"
#include "Parser.h"
#include "RBFNetBuilder.h"
#include "Creator.hpp"


int main() {

    std::string file = "/run/media/dima/732F6FE51C3B609E/project/cpp/just-for-fun/radial-basis-function-network/iris.data";
    Data data = Parser<double, 4>(file).get();
    Data trainSet = data.part(0, 0.8);
    Data testSet = data.part(0.8, 1);

    Net * net = Creator().learn( RBFNetBuilder(10, 3), trainSet );

    for (int i = 0; i < testSet.size(); ++i) {
        std::cout << "Net answer:" << net->classify(testSet[i]) << ", Real answer: " << testSet[i].getClass() << std::endl;
    }

}