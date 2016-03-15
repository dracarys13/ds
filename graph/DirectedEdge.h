#ifndef DIRECTEDEDGE_H
#define DIRECTEDEDGE_H
class DirectedEdge {
private:
    int from_;
    int to_;
    double weight_;
public:
    DirectedEdge();
    DirectedEdge(int from, int to, double weight);
    void toString();
    int from();
    int to();
    double weight();
};
#endif
