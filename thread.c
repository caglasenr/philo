#include <pthread.h>
#include <stdio.h>
pthread_mutex_t myMutex;

void *myThreadFunc(void *arg)
{
    // printf("hello from the thread\n");
    // pthread_exit(NULL); //thread i sonlandırır
    pthread_mutex_lock(&myMutex); //başka bir thread bu mutexi kitediyse bekler
    printf("thread locked");
    pthread_mutex_unlock(&myMutex);
    return NULL;
}
int main()
{
    pthread_t myThread;     //thread id,thread özellkleri,fonksiyon,fonksiyona gönderilen parametre
    int res = pthread_create(&myThread,NULL,myThreadFunc,NULL); //son parametreyi bir değişken vericeksen değişken ölmeden thread çalışır durumda olmalı
    // ya şöyle kullan ;
    // int x = 42;
    // pthread_t t;
    // pthread_create(&myThread,NULL,myThreadFunc,&x);
    // pthread_join(t, NULL);

    // ya malloc kullan böyle;
    /*
        int* x = malloc(sizeof(int));
        *x = 42;

        pthread_create(&t, NULL, myThreadFunc, x);
    */

    // ya da global değişken kullan


    if(res != 0)
    {
        printf("failed");
        return 1;
    }
                    // ilklenen mutex işaretçisi, mutex özellikleri
    pthread_mutex_init(&myMutex,NULL); //mutex oluşturur



    // res = pthread_detach(myThread); 
    // verdiğimiz threadin başka thread tarafından beklenmeden kaynaaklarını temizlemesini sağlar 
    // bir threadin sonlanması durumunda otomatik kaynaklarını temizlemesini sağlar
    // if(res != 0)
    // {
    //     printf("failed");
    //     return 1;
    // } 


    pthread_join(myThread, NULL);//threadin tamamlanmasını bekler ; beklenecek thread, threadin dönüş değeri
    
    res = pthread_mutex_destroy(&myMutex);
    if(res != 0)
    {
        printf("mutex failed");
        return 1;
    }
    return 0;
}