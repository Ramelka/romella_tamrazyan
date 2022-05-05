#include <iostream>
#include "binaryTree.cpp"

using namespace std;

void InputArray(int **arr, int size) {

    for (int i = 0; i < size; ++i) {
        arr[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            cin >> arr[i][j];
        }
    }
}

void PrintArray(int **arr, int size) {

     for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool CheckRoot(int **arr, int size) {

    int RootCount = 0;
    int CountOfZero = 0;                   // Count of zero per one column
    int CountOfOne = 0;                    // Count of one per one column
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (arr[j][i] == 0) {
                ++CountOfZero;
            }

            if (CountOfZero == size) {
                ++RootCount;
            }

            if (RootCount > 1) {
                return false;
            }

            if (arr[j][i] == 1) {
                ++CountOfOne;
            }
            if (CountOfOne > 1) {
                return false;
            }
        }
        CountOfZero = 0;
        CountOfOne = 0;
    }
    return true;
}

bool IsTree (int **arr, int size) {

    int count = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (arr[i][j] == 1 && arr[j][i] == 1) {
                return false;
            }

            if (arr[i][j] == 1) {
                ++count;
            }

            if (count > 2) {
                return false;
            }
        }
        count = 0;
    } 
    if (!CheckRoot(arr, size)) {
        return false;
    } else {
        return true;
    }
}

int GetRoot (int **arr, int size) {

    int count = 0;
    int RootIndex = 0;
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if(arr[j][i] == 0) {
                count++;
            }
                
            if (count == size) {
                RootIndex = i;
                return i;
            }   
        }
        count = 0;
    }   
    return RootIndex;
}

int main() {

    int size;
    cout << "Size of array: "; cin >> size; 
   
    int **arr = new int*[size];
    InputArray(arr, size);
    PrintArray(arr, size);

    int RootIndex;
    if (IsTree(arr, size)) {
        RootIndex = GetRoot(arr, size);
        
        int array[size];
        array[0] = RootIndex;
        int arrIndex = 1;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (arr[i][j] == 1) {
                    array[arrIndex] = j;
                    ++arrIndex;
                }  
            }
        }
        Tree t;
        for (int i = 0; i < size; ++i){
            t.insertNode(array[i]);

        }
        t.printDFS();
    } else {
        cout << "It isn't a binary tree\n";
    }
    cout << endl;
    cout << CheckRoot(arr, size) << endl;
    cout << IsTree(arr, size) << endl;
    cout << "Index = " << GetRoot(arr, size) << endl;
    
    return 0;
}