#include "matriz.h"

int main() {

    struct timespec inicio_real, fim_real, inicio_cpu, fim_cpu;

    inicializar_matrizes();

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio_cpu);
    clock_gettime(CLOCK_MONOTONIC, &inicio_real);

    multiplicar_sem_threads();
    //printar_matriz(c);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fim_cpu);
    clock_gettime(CLOCK_MONOTONIC, &fim_real);

    double tempo_cpu = tempo_em_segundos(inicio_cpu, fim_cpu);
    double tempo_real = tempo_em_segundos(inicio_real, fim_real);

    printf("Tempo de CPU (sem threads): %.3f segundos\n", tempo_cpu);
    printf("Tempo real (sem threads): %.3f segundos\n", tempo_real);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio_cpu);
    clock_gettime(CLOCK_MONOTONIC, &inicio_real);

    multiplicar_com_threads();

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fim_cpu);
    clock_gettime(CLOCK_MONOTONIC, &fim_real);

    tempo_cpu = tempo_em_segundos(inicio_cpu, fim_cpu);
    tempo_real = tempo_em_segundos(inicio_real, fim_real);

    printf("Tempo de CPU (com threads): %.3f segundos\n", tempo_cpu);
    printf("Tempo real (com threads): %.3f segundos\n", tempo_real);

    return 0;
}
