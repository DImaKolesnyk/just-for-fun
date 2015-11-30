//
// Created by dima on 29.11.15.
//

#ifndef GAME_OF_LIFE_CELL_HPP
#define GAME_OF_LIFE_CELL_HPP

enum class Status {DEAD, LIVE};

class Cell{
private:
    Status status_;
    unsigned int x_;
    unsigned int y_;
public:
    Cell() {}
    Cell(unsigned int x, unsigned int y, Status s) : x_(x), y_(y), status_(s) {}
    unsigned int x() const { return x_; }
    unsigned int y() const { return y_; }
    Status status() const { return status_; }

    void setStatus(Status s) {
        status_ = s;
    }
    void setCoord(unsigned int x, unsigned int y) {
        x_ = x;
        y_ = y;
    }

    bool operator==(const Cell& lhs) const {

        return (lhs.x() == x_ &&
                lhs.y() == y_ &&
                lhs.status() == status_
        );
    }
};

#endif //GAME_OF_LIFE_CELL_HPP
