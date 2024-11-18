#include "matriz.h"

int A[N][N], B[N][N], Resultado[N][N];

void inicializar_matrizes(){

    srand(time(NULL));

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){

            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;

        }
    }
}

void multiplicar_sem_threads(){

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){

            Resultado[i][j] = 0;

            for (int k = 0; k < N; k++){

                Resultado[i][j] += A[i][k] * B[k][j];

            }
        }
    }
}

void* calcular_linha(void* arg){

    int linha_start = *(int*)arg;
    free(arg);

    int linha_p_thread = N / NUM_THREADS;

    for (int i = linha_start; i < linha_start + linha_p_thread; i++){
        for (int j = 0; j < N; j++){

            Resultado[i][j] = 0;

            for (int k = 0; k < N; k++){

                Resultado[i][j] += A[i][k] * B[k][j];

            }
        }
    }

    pthread_exit(0);
}

void multiplicar_com_threads(){

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++){

        int* linha_start = malloc(sizeof(int));
        *linha_start = i * (N / NUM_THREADS);
        pthread_create(&threads[i], NULL, calcular_linha, linha_start);

    }

    for (int i = 0; i < NUM_THREADS; i++){

        pthread_join(threads[i], NULL);

    }
}

void printar_matriz(){

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){

            printf("%4d ", Resultado[i][j]);

        }
        printf("\n");
    }
    printf("\n");
}

double tempo_em_segundos(struct timespec inicio, struct timespec fim){

    return (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;

}
