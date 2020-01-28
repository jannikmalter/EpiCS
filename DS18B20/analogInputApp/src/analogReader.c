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

	double val = 0;
	double * pvPtr;
	pvPtr = &precord->a;
	
	
	val = 1337;		
	*pvPtr = val;
	
    return 0;
}

epicsRegisterFunction(mySubProcess);