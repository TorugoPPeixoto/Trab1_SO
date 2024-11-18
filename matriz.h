#ifndef MATRIZ_H
#define MATRIZ_H
#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N 1000
#define NUM_THREADS 5

extern int A[N][N], B[N][N], Resultado[N][N];

void inicializar_matrizes();
void multiplicar_sem_threads();
void* calcular_linha(void* arg);
void multiplicar_com_threads();
void printar_matriz(int** matriz);
double tempo_em_segundos(struct timespec inicio, struct timespec fim);

#endif