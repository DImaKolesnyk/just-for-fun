#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Data.h"
#include "RBFNetCreator.h"

int main() {

    typedef mlt::Data<double, 4> DataType;
    DataType::TParser parser("/run/media/dima/732F6FE51C3B609E/project/cpp/just-for-fun/radial-basis-function-network/iris.data");
    DataType data = parser.get();
    std::cout << data;

//    KMeansClustering<double,2> kMClust;
//
//    DataType centr = kMClust.toCluster(3,data);
//
//    cv::Mat img = cv::Mat(800,800, CV_8UC3, cvScalar(255, 255, 255));
//    for (int i = 0; i < data.size(); ++i) {
//        circle( img, cv::Point(data[i][0]*500, data[i][1]*500), 2.0, cv::Scalar( 0, 0, 255 ), -1, 5 );
//    }
//    cv::namedWindow("drawing", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
//    for (int j = 0; j < centr.size(); ++j) {
//        circle( img, cv::Point(centr[j][0]*500, centr[j][1]*500), 30.0, cv::Scalar( 0, 200, 255 ), 0, 5 );
//    }
//
//    cv::imshow("drawing", img);
//    cv::waitKey(0);

    RBFNetCreator<double, 4> creator(10, 3);
    creator.learn(data);
    RBFNetCreator::TNet net = creator.get();

    for (int i = 0; i < data.size(); ++i) {
        std::cout << "Net answer:" << net.classify(data[i]) << ", Real answer: " << data[i].getClass() << std::endl;
    }
}
