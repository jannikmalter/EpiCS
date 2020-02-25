#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <dbDefs.h>
#include <registryFunction.h>
#include <subRecord.h>
#include <aSubRecord.h>
#include <epicsExport.h>


static long mySubProcess(subRecord *precord)
{

	double val = 42;
	double * pvPtr;
	pvPtr = &precord->a;
	*pvPtr = val;
    return 0;
}

epicsRegisterFunction(mySubProcess);
