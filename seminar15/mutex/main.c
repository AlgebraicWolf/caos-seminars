#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

pthread_mutex_t m;
double *elems;
int N, k;

void *thread_worker(void *arg) {
  size_t i = (size_t) arg;

  pthread_mutex_lock(&m);

  for (int j = 0; j < N; j++) {
    elems[i] += 1.0;
    elems[(i + 1) % k] += 1.01;
    if (i > 0) elems[i - 1] += 0.99;
    else elems[k - 1] += 0.99;
  }

  pthread_mutex_unlock(&m);
}

int main(int argc, const char *argv[]) {
  if (argc != 3) {
    return 1;
  }

  N = strtol(argv[1], NULL, 10);
  k = strtol(argv[2], NULL, 10);

  pthread_t *threads = calloc(k, sizeof(pthread_t));
  elems = calloc(k, sizeof(double));
  pthread_mutex_init(&m, NULL);

  for (size_t i = 0; i < k; i++) {
    pthread_create(threads + i, NULL, thread_worker, (void *)i);
  }

  for (int i = 0; i < k; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&m);

  for (int i = 0; i < k; i++) {
    printf("%.10g ", elems[i]);
  }

  printf("\n");

  free(threads);
  free(elems);

  return 0;

}
