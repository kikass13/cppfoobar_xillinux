
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>    /* For O_RDWR */
#include <unistd.h>   /* For open(), creat() */

#define GPIO_0_BASE_ADDR    0x50003000
#define GPIO_ADDR_RANGE     0x4000



int main()
{
	int fd;
	unsigned int value = 0x01;

	void *gpio0; 	//pointers to the virtual memory

    /* Open /dev/mem file */
    fd = open ("/dev/mem", O_RDWR);
    if (fd < 1) {
        printf("***error opening dev file");
        return -1;
    }

    /* mmap the devices into memory */
    gpio0 = mmap(NULL, GPIO_ADDR_RANGE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, GPIO_0_BASE_ADDR);
    if (&gpio0 == MAP_FAILED){
        printf("map failed\n");
    }   else {
        printf("device mapped to user space, %d\n", gpio0);
    }

	printf("Starting with: %u\n", value);
	/*read and write to register*/
	while(true){
		*((unsigned *)(gpio0)) = value;
		value =  *((unsigned *)(gpio0)) << 1;
		if(value > 0x0f) value = 1;
		printf("%u\n", value);
		usleep(250000); //250ms
	}

    /*free virtual memory*/
    munmap(gpio0, GPIO_ADDR_RANGE);         



	return 0;
}



