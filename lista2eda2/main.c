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
    printf("Selection sort: %lf segundos\n", duration/ CLOCKS_PER_SEC);
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
    printf("Insertion sort: %lf segundos\n", duration/ CLOCKS_PER_SEC);
}

void bubbleSort(int vector[], int lenght) {
    int aux;
    int trocou;
    double duration;
    
    clock_t start = clock();
    do {
        trocou = 0;
        for (int i = 0; i < lenght-1; i++) {
            if (vector[i]>vector[i+1]) {
                trocou = 1;
                aux = vector[i];
                vector[i] = vector[i+1];
                vector[i+1] = aux;
            }
        }
        
    } while (trocou);
    clock_t end = clock();

    duration = end-start;
    printf("Bubble sort: %lf segundos\n", duration/ CLOCKS_PER_SEC);
}

void menu() {
    int lenght;
    int range;
    
    printf("Selecione o tamanho do vetor a ser gerado: ");
    scanf("%d", &lenght);
    
    printf("Defina o valor máximo para os inteiros do vetor");
    scanf("%d", &range);
    
}

#define vectorLenght 500
#define vectorRange 1000
int main() {
    
    int *vector1, *vector2, *vector3;
    int lenght;
    int range;
    
    printf("Selecione o tamanho do vetor a ser gerado: ");
    scanf("%d", &lenght);
    
    printf("Defina o valor máximo para os inteiros do vetor: ");
    scanf("%d", &range);
    
    vector1 = generateRandomVector(lenght, range);
    vector2 = copyVector(vector1, lenght);
    vector3 = copyVector(vector1, lenght);
    
    printf("Vetor gerado: ");
    for (int i=0; i < lenght; i++) {
        printf("%d ", vector1[i]);
    }
    printf("\n\n - Tempo de execução de cada algorítmo -\n");
    
    //Chamada dos algoritmos
    selectionSort(vector1, lenght);
    insertionSort(vector2, lenght);
    bubbleSort(vector3, lenght);
    
    printf("\nVetor ordenado: ");
    for (int i=0; i < lenght; i++) {
        printf("%d ", vector3[i]);
    }
    printf("\n");
    
    return 0;
}
