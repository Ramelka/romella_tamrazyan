#include "graph.hpp"

int main() {

    Graph g(3);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.PrintMatrix();
    g.IsEdgeExisted(4, 1);
    cout << g.IsEdgeExisted(2, 2) << endl;
    cout << g.IsEdgeExisted(1, 2) << endl;
    g.RemoveEdge(4, 1);
    g.PrintMatrix();
    g.AddNode();
    g.AddEdge(3, 3);
    g.PrintMatrix(); 
    g.RemoveNode();
    g.PrintMatrix();
    g.GetAdjacentVertices(0);
  
    return 0;
}