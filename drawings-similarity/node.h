#ifndef NODE_H
#define NODE_H

class Node {
private:
    int id;
    int fatherId;

public:
    Node();
    Node(int fid, int _id) : fatherId(fid), id(_id) {};
    int getId() { return id; }
    int getFatherId() { return fatherId; }

};


#endif // NODE_H

