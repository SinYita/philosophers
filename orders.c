#include <pthread.h>
#include <stdio.h>

void* print_id(void* id) {
    printf("Thread %ld is running\n", (long)id);
    return NULL;
}

int main() {
    pthread_t threads[5];
    for (long i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, print_id, (void*)i);
    }
    // 此时 5 个线程正在后台“赛跑”，顺序完全不可控
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("All threads finished.\n");
    return 0;
}