#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t wrt;
pthread_mutex_t mutex;
int readcount = 0;

void* reader(void* arg) {
    int id = *((int*)arg);

    pthread_mutex_lock(&mutex);
    readcount++;
    if (readcount == 1)
        sem_wait(&wrt);  // First reader locks writer
    pthread_mutex_unlock(&mutex);

    // Reading section
    printf("Reader %d is reading\n", id);
    sleep(1); // Simulate reading
    printf("Reader %d finished reading\n", id);

    pthread_mutex_lock(&mutex);
    readcount--;
    if (readcount == 0)
        sem_post(&wrt);  // Last reader unlocks writer
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* writer(void* arg) {
    int id = *((int*)arg);

    sem_wait(&wrt);  // Writer locks
    // Writing section
    printf("Writer %d is writing\n", id);
    sleep(2); // Simulate writing
    printf("Writer %d finished writing\n", id);
    sem_post(&wrt);  // Writer unlocks

    return NULL;
}

int main() {
    pthread_t rtid[5], wtid[2];
    int rids[5] = {1, 2, 3, 4, 5};
    int wids[2] = {1, 2};

    sem_init(&wrt, 0, 1);
    pthread_mutex_init(&mutex, NULL);

    // Create writer threads
    for (int i = 0; i < 2; i++)
        pthread_create(&wtid[i], NULL, writer, &wids[i]);

    // Create reader threads
    for (int i = 0; i < 5; i++)
        pthread_create(&rtid[i], NULL, reader, &rids[i]);

    for (int i = 0; i < 2; i++)
        pthread_join(wtid[i], NULL);

    for (int i = 0; i < 5; i++)
        pthread_join(rtid[i], NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
