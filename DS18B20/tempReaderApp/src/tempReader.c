#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include <dbDefs.h>
#include <registryFunction.h>
#include <subRecord.h>
#include <aSubRecord.h>
#include <epicsExport.h>



static long mySubProcess(subRecord *precord)
{
	double * pvPtr;
	pvPtr = &precord->a;
	*pvPtr = 1337;
	pvPtr++;

    return 0;
}

epicsRegisterFunction(mySubProcess);