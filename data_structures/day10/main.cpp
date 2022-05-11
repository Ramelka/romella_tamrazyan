#include "shortestPath.hpp"

int main() {
    
    Graph g(4);
    g.AddEdge(0,2,4);
    g.AddEdge(0,3,1);
    g.AddEdge(1,2,3);
    g.AddEdge(1,3,9);
    g.AddEdge(2,3,8);
    g.PrintMatrix();
    g.GetShortestPath(g.matrix, 0);

    return 0;
}