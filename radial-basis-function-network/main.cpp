#include "Data.h"
#include "Parser.h"
#include "Net.hpp"
#include "Creator.hpp"


int main() {

    std::string file = "/run/media/dima/732F6FE51C3B609E/project/cpp/just-for-fun/radial-basis-function-network/iris.data";
    Data data = Parser<double, 4>(file).get();
    //Data trainSet = data.shuffle().part(0, 0.8);
    //Data testSet = data.part(0.8, 1);

    RBFNetBuilder builder(10,3);
    Net* net = Creator().learn( builder, data );

    int error(0);
    int answ(0);

    for (int i = 0; i < data.size(); ++i) {
        answ = net->classify(data[i]);
        if (answ != data[i].getClass()) ++error;
        std::cout << "Net answer:" << answ << ", Real answer: " << data[i].getClass() << std::endl;
    }
    std::cout << "Error: " << (double)error/data.size()*100 << "%";

}