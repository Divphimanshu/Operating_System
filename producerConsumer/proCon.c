#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5 // Buffer size

int buffer[SIZE];
int in = 0, out = 0;

sem_t empty, full;
pthread_mutex_t mutex;

// Producer function
void* producer(void* arg) {
    int item;
    for (int i = 0; i < 10; i++) {
        item = i + 1;

        sem_wait(&empty);              // Wait if buffer is full
        pthread_mutex_lock(&mutex);    // Lock buffer

        buffer[in] = item;
        printf("Producer produced: %d\n", item);
        in = (in + 1) % SIZE;

        pthread_mutex_unlock(&mutex);  // Unlock buffer
        sem_post(&full);               // Increment full count

        sleep(1); // Simulate time
    }
    return NULL;
}

// Consumer function
void* consumer(void* arg) {
    int item;
    for (int i = 0; i < 10; i++) {
        sem_wait(&full);               // Wait if buffer is empty
        pthread_mutex_lock(&mutex);    // Lock buffer

        item = buffer[out];
        printf("Consumer consumed: %d\n", item);
        out = (out + 1) % SIZE;

        pthread_mutex_unlock(&mutex);  // Unlock buffer
        sem_post(&empty);              // Increment empty count

        sleep(2); // Simulate time
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;

    sem_init(&empty, 0, SIZE);   // Initially, buffer is empty
    sem_init(&full, 0, 0);       // No items to consume
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
