#include <unistd.h>
#include <cstdlib>
#include <sys/types.h>
#include <iostream>
using namespace std;
int globval=6;
char buf[]="a write to stdout\n";
int main()
{
    int val;
    pid_t pid;
    val=88;
    if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
        cout<<"write error";
    cout<<"before fork"<<endl;
    if((pid=fork())<0)
        cout<<"fork error";
    else if(pid==0)
    {
         globval++;
         val++;
    }
    else
        sleep(2);
    cout<<"pid="<<getpid()<<"glob="<<globval<<"val="<<val<<endl;
    exit(0);
}
