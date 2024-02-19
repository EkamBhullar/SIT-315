#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <pthread.h>
using namespace std;
using namespace std::chrono;

#define N 500
#define NUM_THREADS 4

int matrix1[N][N];
int matrix2[N][N];
int resultMatrix[N][N] = {0}; // Initialize result matrix globally

// Thread function to perform matrix multiplication
void *multiply(void *arg) {
    long long thread_id = (long long)arg;
    int rows_per_thread = N / NUM_THREADS;
    int start_row = thread_id * rows_per_thread;
    int end_row = (thread_id + 1) * rows_per_thread;

    for (int i = start_row; i < end_row; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    pthread_exit(NULL);
}

void fillWithRandomValues(int mat[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            mat[i][j] = rand() % 100;
        }
    }
}

int main() {
    fillWithRandomValues(matrix1);
    fillWithRandomValues(matrix2);

    pthread_t threads[NUM_THREADS];

    auto start = high_resolution_clock::now();

    // Creating threads
    for (long long i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, multiply, (void *)i);
    }

    // Joining threads
    for (long long i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}
