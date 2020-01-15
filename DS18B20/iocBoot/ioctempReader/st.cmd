#!../../bin/linux-arm/tempReader

#- You may have to change tempReader to something else
#- everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/tempReader.dbd"
tempReader_registerRecordDeviceDriver pdbbase

## Load record instances
dbLoadRecords("db/tempReader.db","user=epics")

cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs
#seq sncxxx,"user=epics"
