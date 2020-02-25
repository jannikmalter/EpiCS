#!../../bin/linux-arm/DS18B20

#- You may have to change DS18B20 to something else
#- everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/DS18B20.dbd"
DS18B20_registerRecordDeviceDriver pdbbase

## Load record instances
dbLoadRecords("db/tempReader.db","user=epics")

cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs
#seq sncxxx,"user=epics"
