#include <iostream>
#include <chrono>
#include <cstdlib>
#include <omp.h>

using namespace std;
using namespace std::chrono;

#define N 500
#define NUM_THREADS 4

int matrix1[N][N];
int matrix2[N][N];
int resultMatrix[N][N] = {0}; // Initialize result matrix globally

void fillWithRandomValues(int mat[N][N]) {
    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            mat[i][j] = rand() % 100;
        }
    }
}

int main() {
    fillWithRandomValues(matrix1);
    fillWithRandomValues(matrix2);

    auto start = high_resolution_clock::now();

    #pragma omp parallel for num_threads(NUM_THREADS)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}
