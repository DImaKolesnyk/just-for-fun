#include "LearnPerceptron.h"
#include <QApplication>
#include "Visualizer.h"
#include "Parser.h"



int main(int argc, char** argv) {

    QApplication app(argc, argv);
    Parser pars("/run/media/dima/732F6FE51C3B609E/project/cpp/just-for-fun/perceptron/data04.csv");
    std::vector < std::vector <double> > data = pars.getData();

    LearnPerceptron lp;
    Perceptron smartp = lp.learn( data );


    unsigned int fail = 0;
    for (int j = 80; j < 100; ++j) {
        std::cout << "Real answer: " << data[j][2] << ' ' << "My perceptron answer: " << smartp.classification(data[j]);
        if ( data[j][2] != smartp.classification(data[j])) { fail+=1; std::cout << " Fail!" << std::endl; } else { std::cout << std::endl; }
    }

    std::cout << "Number of perceptron falis: " << fail << std::endl;
    if ( fail == 0 ) {
        std::vector <double> bestw = smartp.getWeightAndThreshold();
        std::cout << "The best weight: " << bestw[0] << ", " << bestw[1] << ";" << std::endl << "Threshold: " << bestw[2] << std::endl;
    }


    Visualizer visualizer(data, smartp.getWeightAndThreshold());
    visualizer.show();

    return app.exec();
}