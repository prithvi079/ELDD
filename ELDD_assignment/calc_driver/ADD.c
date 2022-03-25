#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	int fd;
	int ubuff[2] = {10,20};
	int kbuff[2];

// char ubuff1[100]= "This MESSAGE FROM USER..\n";

	fd=open("dev/ADD_Device",O_RDWR,0777);
	if(fd < 0)
	{
 		printf("ERROR IN OPENING\n");
 		exit(EXIT_FAILURE);
	}

	write(fd,ubuff,sizeof(ubuff));
	read(fd,a,sizeof(kbuff));
	printf("The reading data from kernel space ==> %d\n",kbuff);   //Reading data from kernel

	close(fd);
	return 0;
}
