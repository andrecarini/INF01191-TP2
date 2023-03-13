#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include "papito.h"

using namespace std;

extern vector<string> papiEvents;
extern int eventset;

void custom_papito_end(int n) {
    int t;
    long_long values[papiEvents.size()]; // Cada thread registra seu contadores aqui.

    // Parar a contagem dos eventos
    if (PAPI_stop(eventset, values) != PAPI_OK) handle_error(4);
    if (PAPI_cleanup_eventset(eventset) != PAPI_OK) handle_error(20);
    if (PAPI_destroy_eventset(&eventset) != PAPI_OK) handle_error(21);

    /*cout << "Matrix_Size" << ",";
    for (int i = 0; i < papiEvents.size(); i++)
    {
      if (i == papiEvents.size() - 1) {
        cout << string(papiEvents[i]).substr(5, string(papiEvents[i]).size());
      } else {
        cout << string(papiEvents[i]).substr(5, string(papiEvents[i]).size()) << ",";
      }
    }
    cout << endl;*/

    // Tamanho da matriz testada
    cout << n << ",";
    
    // Totalizando os eventos
    for (int i = 0; i < papiEvents.size(); i++)
    {
      if (i == papiEvents.size() - 1) {
        cout << values[i];
      }
      else { 
        cout << values[i] << ",";
      }
    }
    cout << endl << endl;
}

// standard matrix multiplication algorithm
void matrix_multiply_standard(int n, double *A, double *B, double *C) {
    papito_start();
		for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0.0;
            for (int k = 0; k < n; k++) {
                sum += A[i*n+k] * B[k*n+j];
            }
            C[i*n+j] = sum;
        }
    }
		custom_papito_end(n);
}

// transposed matrix multiplication algorithm
void matrix_multiply_transposed(int n, double *A, double *B, double *C) {
    // transpose B matrix
    double *B_transpose = (double*)malloc(n*n*sizeof(double));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B_transpose[j*n+i] = B[i*n+j];
        }
    }
		
		papito_start();
    // perform matrix multiplication
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double sum = 0.0;
            for (int k = 0; k < n; k++) {
                sum += A[i*n+k] * B_transpose[j*n+k];
            }
            C[i*n+j] = sum;
        }
    }
		custom_papito_end(n);

    // free memory allocated for B transpose
    free(B_transpose);
}

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " positive_integer" << endl;
        return 1;
    }

    // matrix size
    int n = atoi(argv[1]);

    if (n <= 0) {
        cerr << "Error: The argument must be a positive integer." << endl;
        return 1;
    }
    
    papito_init();

    // seed random number generator
    srand(time(NULL));

    // allocate memory for matrices
    double *A = (double*)malloc(n*n*sizeof(double));
    double *B = (double*)malloc(n*n*sizeof(double));
    double *C_standard = (double*)malloc(n*n*sizeof(double));
    double *C_transposed = (double*)malloc(n*n*sizeof(double));

    // initialize matrices A and B with random values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i*n+j] = (double)rand() / RAND_MAX;
            B[i*n+j] = (double)rand() / RAND_MAX;
        }
    }

    // perform matrix multiplication using standard algorithm
    matrix_multiply_standard(n, A, B, C_standard);

    // perform matrix multiplication using transposed algorithm
    //matrix_multiply_transposed(n, A, B, C_transposed);

    // print results
    /*printf("Matrix A (showing first 5 rows and columns):\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%f ", A[i*n+j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Matrix B (showing first 5 rows and columns):\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%f ", B[i*n+j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Standard multiplication (showing first 5 rows and columns):\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%f ", C_standard[i*n+j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Transposed multiplication (showing first 5 rows and columns):\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%f ", C_transposed[i*n+j]);
        }
        printf("\n");
    }
    printf("\n");*/

    // free memory allocated for matrices
    free(A);
    free(B);
    free(C_standard);
    free(C_transposed);

    return 0;
}