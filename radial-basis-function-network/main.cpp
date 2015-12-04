#include "Data.h"
#include "RBFNetCreator.h"

int main() {

    typedef mlt::Data<double, 4> DataType;
    DataType::TParser parser("/run/media/dima/732F6FE51C3B609E/project/cpp/just-for-fun/radial-basis-function-network/iris.data");
    DataType data = parser.get();

    RBFNetCreator<double, 4> creator(10, 3);
    creator.learn(data);
    RBFNet<double,4> net = creator.get();
    //RBFNetCreator::Net net = creator.get();

    for (int i = 0; i < data.size(); ++i) {
        std::cout << "Net answer:" << net.classify(data[i]) << ", Real answer: " << data[i].getClass() << std::endl;
    }
}
