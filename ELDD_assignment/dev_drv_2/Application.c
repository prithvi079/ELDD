#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int fd;
	char Ubuff[] = "This is the user buffer ==> sending data to the kernel";
	char Kbuff[100];
	fd = open("/dev/DESD_Device", O_RDWR, 0777);
	
	if(fd < 0)
	{
		perror("\nError in opening device \n");
		exit(EXIT_FAILURE);

	}

	write(fd, Ubuff, sizeof(Ubuff));  //writing to the kernel
	read(fd, Kbuff, sizeof(Kbuff));
	printf("\nThe reading data ==> %s\n", Kbuff);  //reading data from kernel
	close(fd);
}
