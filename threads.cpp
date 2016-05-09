#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
using namespace std;
void *thread(void *ptr)
{
    for(int i=0;i<3;i++)
    {
        sleep(1);
        cout<<"this is a thread."<<endl;
    }
    return 0;
}
int main()
{
     pthread_t id;
     int ret=pthread_create(&id,NULL,thread,NULL);
     if(ret)
     {
          cout<<"create pthread error!"<<endl;
          return 1;
     }
     for(int i=0;i<3;i++)
     {
          cout<<"this is a main process"<<endl;
          sleep(1);
     }
     pthread_join(id,NULL);
     return 0;
}
