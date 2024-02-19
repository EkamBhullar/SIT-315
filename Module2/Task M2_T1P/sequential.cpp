#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;
using namespace std::chrono;

#define N 500

int resultMatrix[N][N] = {0};

void mulMatrix(int matrix1[][N], int matrix2[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void fillWithRandomValues(int mat[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            mat[i][j] = rand() % 100;
        }
    }
}

int main() {
    int matrix1[N][N];
    int matrix2[N][N];
    fillWithRandomValues(matrix1);
    fillWithRandomValues(matrix2);

    auto start = high_resolution_clock::now();

    // Function call
    mulMatrix(matrix1, matrix2);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    // Writing output to a file
    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                outputFile << resultMatrix[i][j] << " ";
            }
            outputFile << endl;
        }
        outputFile.close();
        cout << "Output written to output.txt" << endl;
    } else {
        cout << "Unable to open file" << endl;
    }

    return 0;
}
