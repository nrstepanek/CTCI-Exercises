
#include <iostream>

using namespace std;

void rotate(int** toRotate, int size) {
    for (int layer = 0; layer < size / 2; layer++) {
        for (int rot = 0; rot < size - 1 - (2 * layer); rot++) {
            int temp1 = toRotate[layer][layer + rot];
            int temp2 = toRotate[layer + rot][size - layer - 1];
            int temp3 = toRotate[size - layer - 1][size - layer - rot - 1];
            int temp4 = toRotate[size - layer - rot - 1][layer];
            toRotate[layer][layer + rot] = temp4;
            toRotate[layer + rot][size - layer - 1] = temp1;
            toRotate[size - layer - 1][size - layer - rot - 1] = temp2;
            toRotate[size - layer - rot - 1][layer] = temp3;
        }
    }
}

void print(int** toPrint, int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            cout << toPrint[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int** ex1;
    ex1 = new int*[5];
    for (int i = 0; i < 5; i++) {
        ex1[i] = new int[5];
        for (int j = 0; j < 5; j++) {
            ex1[i][j] = i + j;
        }
    }

    int** ex2;
    ex2 = new int*[4];
    for (int i = 0; i < 4; i++) {
        ex2[i] = new int[4];
        for (int j = 0; j < 4; j++) {
            ex2[i][j] = i + j;
        }
    }

    print(ex1, 5);
    rotate(ex1, 5);
    print(ex1, 5);

    print(ex2, 4);
    rotate(ex2, 4);
    print(ex2, 4);

    return 0;
}
