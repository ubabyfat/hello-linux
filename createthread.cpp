#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
using namespace std;
void *thread1(void *)
{
     cout<<"thread1"<<endl;
     return 0;
}
void *thread2(void *)
{
     cout<<"thread2"<<endl;
     return 0;
}
int main()
{
     pthread_t id1,id2;
    int ret1= pthread_create(&id1,NULL,thread1,NULL);
    if(ret1)
        cout<<"error1"<<endl;
    int ret2= pthread_create(&id2,NULL,thread2,NULL);
    if(ret2)
        cout<<"error2"<<endl;
    pthread_join(id1,NULL);
    pthread_join(id2,NULL);
     return 0;
}
