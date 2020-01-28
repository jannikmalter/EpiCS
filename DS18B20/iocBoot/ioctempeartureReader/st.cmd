#!../../bin/linux-arm/temperatureReader

#- You may have to change temperatureReader to something else
#- everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/temperatureReader.dbd"
temperatureReader_registerRecordDeviceDriver pdbbase

## Load record instances
dbLoadRecords("db/temperatureReader.db","user=epics")

cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs
#seq sncxxx,"user=epics"
