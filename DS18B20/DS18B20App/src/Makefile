TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================


# Use typed rset structure (see 3.16.1 release notes)
USR_CPPFLAGS += -DUSE_TYPED_RSET


# Build an IOC support library
LIBRARY_IOC += DS18B20Support

DS18B20Support_SRCS += tempReader.c

DS18B20Support_LIBS += $(EPICS_BASE_IOC_LIBS)


# Build the IOC application

PROD_IOC = DS18B20
# DS18B20.dbd will be created and installed
DBD += DS18B20.dbd

# DS18B20.dbd will be made up from these files:
DS18B20_DBD += base.dbd
DS18B20_DBD += tempReader.dbd

# Include dbd files from all support applications:
#DS18B20_DBD += xxx.dbd

# Add all the support libraries needed by this IOC
#DS18B20_LIBS += xxx

# DS18B20_registerRecordDeviceDriver.cpp derives from DS18B20.dbd
DS18B20_SRCS += DS18B20_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
DS18B20_SRCS_DEFAULT += DS18B20Main.cpp
DS18B20_SRCS_vxWorks += -nil-

DS18B20_LIBS += DS18B20Support

# Add support from base/src/vxWorks if needed
#DS18B20_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
DS18B20_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

