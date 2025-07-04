#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5  // Number of philosophers

pthread_mutex_t chopsticks[N];

void* philosopher(void* num) {
    int id = *(int*)num;

    while (1) {
        printf("Philosopher %d is thinking...\n", id);
        sleep(1); // Thinking

        if (id % 2 == 0) {
            // Even-numbered philosopher picks left first
            pthread_mutex_lock(&chopsticks[id]);
            pthread_mutex_lock(&chopsticks[(id + 1) % N]);
        } else {
            // Odd-numbered philosopher picks right first
            pthread_mutex_lock(&chopsticks[(id + 1) % N]);
            pthread_mutex_lock(&chopsticks[id]);
        }

        printf("Philosopher %d is eating...\n", id);
        sleep(2); // Eating

        pthread_mutex_unlock(&chopsticks[id]);
        pthread_mutex_unlock(&chopsticks[(id + 1) % N]);

        printf("Philosopher %d finished eating and is thinking again...\n", id);
    }

    return NULL;
}

int main() {
    pthread_t threads[N];
    int ids[N];

    for (int i = 0; i < N; i++) {
        pthread_mutex_init(&chopsticks[i], NULL);
    }

    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < N; i++) {
        pthread_mutex_destroy(&chopsticks[i]);
    }

    return 0;
}
