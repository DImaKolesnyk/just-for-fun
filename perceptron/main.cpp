#include "LearnPerceptron.h"
#include <fstream>
#include <QApplication>
#include "Visualizer.h"



int main(int argc, char** argv) {

    QApplication app(argc, argv);

    std::ifstream F("/run/media/dima/732F6FE51C3B609E/project/cpp/just-for-fun/perceptron/data04.csv");
    double a;
    std::vector <double > buff;
    int i = 0;
    std::vector < std::vector <double> > data;

   while (!F.eof())
    {
        F>>a;
        buff.push_back(a);
        i+=1;

        if ( i%3 == 0 ) {
            data.push_back(buff);
            buff.clear();
        }
    }

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