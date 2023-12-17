#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void get_random_matrix(int ***mat, int n) {
    srand(time(NULL));

    // Allocate memory for the matrix
    *mat = (int **)malloc(n * sizeof(int *));
    if (*mat == NULL) {
        fprintf(stderr, "Memory allocation failed for rows\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        (*mat)[i] = (int *)malloc(n * sizeof(int));
        if ((*mat)[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for columns in row %d\n", i);
            exit(1);
        }
    }

    // Populate the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (*mat)[i][j] = rand() % 19 - 9;
        }
    }
}


void print_matrix(int **mat, int n) {
    for (int i = 0; i < n; i++)
    {
    	printf("|");
        for (int j = 0; j < n; j++)
        {
            printf("%d\t|", mat[i][j]);
        }
        printf("\n");
    }
}



int trace_matrice(int **mat, int n){
	int res = 0;
	for (int i = 0; i < n; i++){
		res += mat[i][i];
	}

	return res;
}

void conv2(int **A, int **B, int ***C, int a, int b){
	for (int i = 0; i < a; i++){
		for (int j = 0; j < a; j++){
			int S = 0;
			for (int k = 0; k < b; k++){
				for (int l = 0; l < b; l++){
					if(i >= b/2 - k && j >= b/2 - l && j - b/2 + l < a && i - b/2 + k < a)
						S += A[i - b/2 + k][j - b/2 + l] * B[k][l];
				}				
			}
			(*C)[i][j] = S;
		}
	}
}


int main() {
    int **A = NULL;
    int **B = NULL;
    int **C = NULL;
    int sizeA, sizeB;
    int traceB;

    // A
    printf("Saisir la taille de A: ");
    scanf("%d", &sizeA);
    get_random_matrix(&A, sizeA);
    print_matrix(A, sizeA);
    printf("Trace A = %d\n", trace_matrice(A, sizeA));

    // B
    printf("Saisir la taille de B impair entre 1 et %d: ", sizeA/2);
    scanf("%d", &sizeB);
    get_random_matrix(&B, sizeB);
    print_matrix(B, sizeB);
    printf("Trace B = %d\n", trace_matrice(B, sizeB));

	// Allocate memory for C
    C = (int **)malloc(sizeA * sizeof(int *));
    for (int i = 0; i < sizeA; i++) {
        C[i] = (int *)malloc(sizeA * sizeof(int));
    }
    // C
    conv2(A,B, &C, sizeA, sizeB);
    print_matrix(C, sizeA);

    for (int i = 0; i < sizeA; i++) {
        free(A[i]);
    }
    free(A);

    for (int i = 0; i < sizeB; i++) {
        free(B[i]);
    }
    free(B);

    for (int i = 0; i < sizeA; i++) {
        free(C[i]);
    }
    free(C);
    return 0;
}
