#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
        int fd;
        int ubuff[2]={10,20};

// char ubuff1[100]= "This MESSAGE FROM USER..\n";
        char a[100];

        fd=open("dev/mydevice10",O_RDWR,0777);
        if(fd,0)
        {
                printf("ERROR IN OPENING\n");
                exit(1);
        }

        write(fd,ubuff,sizeof(ubuff));
        read(fd,a,sizeof(a));
        printf("OUTPUT ..%S..\n",a);

        close(fd);
        return 0;
}
