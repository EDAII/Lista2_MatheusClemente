//
//  main.c
//  lista2eda2
//
//  Matheus Clemente Carvalho de Azevedo - 15/0042817


#include <stdio.h>
#include <time.h>

int* generateRandomVector(int lenght, int maxValue) {
    int *vector;
    
    vector = malloc(lenght * sizeof(int));
    
    for (int i=0; i < lenght; i++) {
        vector[i] = rand() % maxValue+1;
    }
    
    return vector;
}

int* copyVector(int *copiedVector, int lenght) {
    int *finalVector;
    
    finalVector = malloc(lenght * sizeof(int));
    
    for (int i=0; i < lenght; i++) {
        finalVector[i] = copiedVector[i];
    }
    
    return finalVector;
}

void selectionSort(int vector[], int lenght) {
    int menorIndex;
    int aux;
    double duration;
    
    clock_t start = clock();
    for (int i = 0; i < lenght; i++) {
        menorIndex = i;
        for (int j = i+1; j < lenght; j++) {
            if (vector[j] < vector[menorIndex]) {
                menorIndex = j;
            }
        }
        if (menorIndex != i) {
            aux = vector[i];
            vector[i] = vector[menorIndex];
            vector[menorIndex] = aux;
        }
    }
    clock_t end = clock();
    
    duration = end-start;
    printf("Duracao selection sort: %lf segundos\n", duration/ CLOCKS_PER_SEC);
}

void insertionSort(int vector[], int lenght) {
    int aux;
    int j;
    double duration;
    
    clock_t start = clock();
    for (int i = 0; i < lenght; i++) {
        j = i;
        while (j > 0 && (vector[j] < vector[j-1])) {
            aux = vector[j];
            vector[j] = vector[j-1];
            vector[j-1] = aux;
            j--;
        }
    }
    clock_t end = clock();
    
    duration = end-start;
    printf("Duracao insertion sort: %lf segundos\n", duration/ CLOCKS_PER_SEC);
}

#define vectorLenght 50
#define vectorRange 100
int main() {
    
    int *vector1, *vector2;
    
    vector1 = generateRandomVector(vectorLenght, vectorRange);
    vector2 = copyVector(vector1, vectorLenght);
    
    printf("Vetor gerado: ");
    for (int i=0; i < vectorLenght; i++) {
        printf("%d ", vector1[i]);
    }
    printf("\n");
    
    //SelectionSort
    selectionSort(vector1, vectorLenght);
    for (int i=0; i < vectorLenght; i++) {
        printf("%d ", vector1[i]);
    }
    printf("\n");
    
    //InsertionSort
    insertionSort(vector2, vectorLenght);
    for (int i=0; i < vectorLenght; i++) {
        printf("%d ", vector2[i]);
    }
    printf("\n");
    
    int *vector;
    
    vector = generateRandomVector(vectorLenght, vectorRange);
    
    printf("Vetor gerado: ");
    for (int i=0; i < 50; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    
    selectionSort(vector, 50);
    
    for (int i=0; i < 50; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    
    return 0;
}
