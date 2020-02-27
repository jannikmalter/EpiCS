#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h>

#include <dbDefs.h>
#include <registryFunction.h>
#include <subRecord.h>
#include <aSubRecord.h>
#include <epicsExport.h>

#define BUFSIZE 1024


static long mySubProcess(subRecord *precord)
{
    double * pvPtr;
	pvPtr = &precord->a;

    int input_fd;
    char buffer[BUFSIZE]; 
    char* eptr;

    double temperature;
    
    input_fd = open("/sys/bus/w1/devices/28-01144e834aaa/w1_slave", O_RDONLY);      
    read(input_fd, &buffer, BUFSIZE);
    
    char* loc = strstr(buffer,"t=");
    temperature = (double)strtol(loc+2, &eptr, 10) / 1000;
    
    close(input_fd);	
	*pvPtr = temperature;
    return 0;
}

epicsRegisterFunction(mySubProcess);
