#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <i2c/smbus.h>
#include <time.h>

#include <dbDefs.h>
#include <registryFunction.h>
#include <subRecord.h>
#include <aSubRecord.h>
#include <epicsExport.h>

#define I2C_ADDR 0x04
#define ADC_CHAN_NUM 8
#define N 10

static long mySubProcess(subRecord *precord)
{
	unsigned char read_buf[2];	
	unsigned char reg_buf[2];
	__uint16_t reg;
	double val = 0;
	double * pvPtr;
	pvPtr = &precord->a;
	
	int busfd = open("/dev/i2c-1", O_RDWR);
	ioctl(busfd, I2C_SLAVE, I2C_ADDR);	
	
	for (int c = 0; c < ADC_CHAN_NUM; c++)
	{		
		reg = 0x20 + c;
		reg_buf[0] = (reg >> 0) & 0xFF;
		reg_buf[1] = (reg >> 8) & 0xFF;

		write(busfd, reg_buf, 2);
		
		for (int i = 0; i < N; i++)
		{
			read(busfd, read_buf, 2);	
			val = ((double)i*val + (double)(read_buf[1] << 8 | read_buf[0])/1000)/((double) i+1);
		}
		
		*pvPtr = val;
		pvPtr++;
	}
	
	close(busfd);
    return 0;
}

epicsRegisterFunction(mySubProcess);