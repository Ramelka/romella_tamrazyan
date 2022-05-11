#include <iostream>
#include <limits>

using namespace std;

class Graph {
    public:
        Graph(int);
        int **matrix;
        int verticeCount;
        bool OutOfVerticesCount(int);
        void AddEdge(int, int,int);
        bool IsEdgeExisted(int, int);
        void PrintMatrix();
        void PrintPath(int *);
        int FindMinDistance(int *, bool *);
        void GetShortestPath(int **, int);
        ~Graph();
};

Graph::Graph(int verticeCount) {
    
    this->verticeCount = verticeCount;
    matrix = new int *[verticeCount];
    for (int i = 0; i < verticeCount; ++i) {
        matrix[i] = new int[verticeCount];
        for (int j = 0; j < verticeCount; ++j) {
            matrix[i][j] = INT8_MAX;
        }
    }
}

bool Graph::OutOfVerticesCount(int index) {

    if (index >= verticeCount || index < 0) {
        cout << "Out of vertices count\n";
        return true;
    }
    return false;
}

void Graph::AddEdge(int i, int j ,int value) {

    matrix[i][j] = value;
    matrix[j][i] = value;
}

bool Graph::IsEdgeExisted(int i, int j) {

    if(OutOfVerticesCount(i) || OutOfVerticesCount(j)) {
        return false;
    } else 
        return matrix[i][j];    
}

void Graph::PrintMatrix() {
    
    for (int i = 0; i < verticeCount; ++i) {
        for (int j = 0; j < verticeCount; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void Graph::PrintPath(int *arr) {

    cout << "Shortest pathes from source vertice\n";
    for (int i = 0; i < verticeCount; ++i) {
        cout << i << "\t" << arr[i] << endl;
    }
}

int Graph::FindMinDistance(int *dist, bool *IsVisited) {
    
    int index;
    int min = INT8_MAX;
    
    for (int i = 0; i < verticeCount; ++i) {
        if(IsVisited[i] == false && dist[i] <= min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void Graph::GetShortestPath(int **matrix, int source) {
    
    int distance[verticeCount];
    bool isVisited[verticeCount];

    for (int i = 0; i < verticeCount; ++i) {
        distance[i] = INT8_MAX;
        isVisited[verticeCount] = false;
    }
    
    distance[source] = 0;
    int index;
    for (int i = 0; i < verticeCount; ++i) {
        index = FindMinDistance(distance, isVisited);
        isVisited[index] = true;

        for (int j = 0; j < verticeCount; ++j) {
            if (!isVisited[j] && IsEdgeExisted(i, j) && distance[i] != __INT8_MAX__ && distance[i] + matrix[i][j] < distance[j]) {
                distance[j] = distance[i] + matrix[i][j];
            }
        }
    }
    PrintPath(distance);
}

Graph::~Graph() {
    
    delete[] matrix;
}