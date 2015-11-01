#ifndef CONTOUR
#define CONTOUR

#include <QPoint>
#include <vector>

class Contour {
private:
    std::vector <QPoint> contour;
    bool endContour;
public:
    Contour() : endContour(false) {}
    QPoint operator[](std::size_t idx)  const      { return contour[idx]; };
    unsigned int size() const { return contour.size(); };
    bool full() const { return endContour; }
    void addDot(QPoint d) {
        contour.push_back(d);
        if (contour.size()-1 && abs(d.x() - contour[0].x() ) < 7 &&  abs(d.y() - contour[0].y() ) < 7 ) {
            endContour = true;
            contour[contour.size()-1] = contour[0];
        }
    }
};

#endif // CONTOUR
