#include "graph.hpp"

int main() {

    Graph g(3);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.PrintMatrix();
    cout << g.IsEdgeExisted(2, 1);
    cout << g.IsEdgeExisted(2, 2);
    g.AddEdge(0, 1);
    g.RemoveEdge(0, 0);
    g.PrintMatrix();
    g.AddNode();
    g.AddEdge(3, 3);
    g.PrintMatrix(); 
    g.RemoveNode();
    g.PrintMatrix();
    
    return 0;
}