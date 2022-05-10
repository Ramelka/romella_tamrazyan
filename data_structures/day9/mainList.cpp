#include "graphList.hpp"

int main(){

    Graph g(3);
    
    g.AddEdge(0, 1);
    g.AddEdge(1, 2);
    g.AddVertice();
    g.AddVertice();
    g.AddEdge(0, 4);
    g.AddEdge(4, 2);
    g.PrintList();
    g.RemoveVertice();
    g.PrintList();
    cout << g.IsEdgeExisted(2, 1) << endl;
    cout << g.IsEdgeExisted(3, 2) << endl;
    g.FindAdjacentVertices(1);

    return 0;
}