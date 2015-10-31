#ifndef CONTOUR
#define CONTOUR

#include <QPoint>
#include <vector>

class Contour {
private:
    std::vector <QPoint> contour;
    bool endContour;
    unsigned int count;
public:
    Contour() : endContour(false), count(0) {}
    QPoint operator[](std::size_t idx)  const      { return contour[idx]; };
    unsigned int size() const { return count; };
    bool full() { return endContour; }
    void addDot(QPoint d) {
        contour.push_back(d);
        if (count != 0 && abs(d.x() - contour[0].x() ) < 7 &&  abs(d.y() - contour[0].y() ) < 7 ) {
            endContour = true;
            contour[contour.size()-1] = contour[0];
        }
        count +=1;
    }
};

#endif // CONTOUR
