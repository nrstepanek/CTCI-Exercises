
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

void expandZero(int** matrix, const int rows, const int cols) {
    bool rowZeros[rows] = {false};
    bool colZeros[cols] = {false};
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (matrix[row][col] == 0) {
                rowZeros[row] = true;
                colZeros[col] = true;
            }
        }
    }

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            if (rowZeros[row] || colZeros[col])
                matrix[row][col] = 0;
        }
    }
}

void print(int** toPrint, int rows, int cols) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            cout << toPrint[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int** ex1;
    vector<int> ex1Ints = {5, 8, 0, 9, 1, 2, 4, 3, 7, 0, 4, 3, 2, 8, 6};
    ex1 = new int*[5];
    for (int i = 0; i < 5; i++) {
        ex1[i] = new int[3];
        for (int j = 0; j < 3; j++) {
            ex1[i][j] = ex1Ints[i * 3 + j];
        }
    }

    print(ex1, 5, 3);
    expandZero(ex1, 5, 3);
    print(ex1, 5, 3);
    
    return 0;
}
