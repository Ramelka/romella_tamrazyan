#include <iostream>

using namespace std;

class Graph {
    private:
        bool **matrix;
        int _verticeCount;
        bool OutOfVerticesCount(int);
    public:
        Graph(int);
        ~Graph();
        void AddEdge(int, int);
        void RemoveEdge(int, int);
        void AddNode();
        void RemoveNode();
        bool IsEdgeExisted(int, int);
        int* GetAdjacentVertices(int);
        //void GetVerticeConnections(int);
        void PrintMatrix();
};

Graph::Graph(int verticeCount) {

    _verticeCount = verticeCount; 
    matrix = new bool *[verticeCount];
    for (int i = 0; i < verticeCount; ++i) {
        matrix[i] = new bool[verticeCount];
        for (int j = 0; j < verticeCount; ++j) {
            matrix[i][j] = false;
        }
    }
}

Graph::~Graph() {

    delete matrix;
    delete[] matrix;
}

bool Graph::OutOfVerticesCount(int index) {

    if (index >= _verticeCount || index < 0) {
        cout << "Out of vertices count\n";
        return true;
    }
    return false;
}

void Graph::AddEdge(int i, int j) {

    if (OutOfVerticesCount(i) || OutOfVerticesCount(j)) {
       return;
    } else if (matrix[i][j]) {
        cout << "Vertices are already connected\n";
    } else  {
        matrix[i][j] = true;
        matrix[j][i] = true;
    }
}

void Graph::RemoveEdge(int i, int j) {

    if (OutOfVerticesCount(i) || OutOfVerticesCount(j)) {
        return;
    } else if (!matrix[i][j]) {
        cout << "Vertices aren't connected\n";
    } else {
        matrix[i][j] = false;
        matrix[j][i] = false;
    }
}

void Graph::AddNode() {

    _verticeCount += 1;
    bool **newArr = new bool *[_verticeCount];

    for (int i = 0; i < _verticeCount; ++i) {
        newArr[i] = new bool[_verticeCount];
        for (int j = 0; j < _verticeCount; ++j) {
            if (i != _verticeCount - 1 && j != _verticeCount - 1) {
                newArr[i][j] = matrix[i][j];
            } else {
                newArr[i][j] = false;
            }
        }
    }
    delete matrix;
    matrix = newArr;
}

void Graph::RemoveNode() {

    _verticeCount -= 1;
    bool **newArr = new bool *[_verticeCount];

    for (int i = 0; i < _verticeCount; ++i) {
        newArr[i] = new bool[_verticeCount];
        for (int j = 0; j < _verticeCount; ++j) {
            newArr[i][j] = matrix[i][j];
        }
    }
    delete matrix;
    matrix = newArr;
}

bool Graph::IsEdgeExisted(int i, int j) {

    if(OutOfVerticesCount(i) || OutOfVerticesCount(j)) {
        return false;
    } else 
        return matrix[i][j];    
}

int* Graph::GetAdjacentVertices(int vertice) {

    int *arr = new int[_verticeCount];
    for (int j = 0; j < _verticeCount; ++j) {
        if (matrix[vertice][j] == 1) {
            arr[j] = j;
            cout << arr[j] << " ";
        }
    }
    return arr;
    delete arr;
}

/*void Graph::GetVerticeConnections(int vertice) {

}*/

void Graph::PrintMatrix() {

    for (int i = 0; i < _verticeCount; ++i) {
        for (int j = 0; j < _verticeCount; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}