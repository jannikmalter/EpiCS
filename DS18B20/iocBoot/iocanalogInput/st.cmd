#!../../bin/linux-arm/analogInput

#- You may have to change analogInput to something else
#- everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/analogInput.dbd"
analogInput_registerRecordDeviceDriver pdbbase

## Load record instances
dbLoadRecords("db/analogReader.db","user=epics")

cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs
#seq sncxxx,"user=epics"
