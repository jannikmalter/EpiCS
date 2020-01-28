TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================

# Use typed rset structure (see 3.16.1 release notes)
USR_CPPFLAGS += -DUSE_TYPED_RSET


# Build an IOC support library
LIBRARY_IOC += temperatureReaderSupport

temperatureReaderSupport_SRCS += temperatureReader.c

temperatureReaderSupport_LIBS += $(EPICS_BASE_IOC_LIBS)





# Build the IOC application

PROD_IOC = temperatureReader
# temperatureReader.dbd will be created and installed
DBD += temperatureReader.dbd

# temperatureReader.dbd will be made up from these files:
temperatureReader_DBD += base.dbd
temperatureReader_DBD += temperatureReader.dbd

# Include dbd files from all support applications:
#temperatureReader_DBD += xxx.dbd

# Add all the support libraries needed by this IOC
#temperatureReader_LIBS += xxx

# temperatureReader_registerRecordDeviceDriver.cpp derives from temperatureReader.dbd
temperatureReader_SRCS += temperatureReader_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
temperatureReader_SRCS_DEFAULT += temperatureReaderMain.cpp
temperatureReader_SRCS_vxWorks += -nil-

temperatureReader_LIBS += temperatureReaderSupport

# Add support from base/src/vxWorks if needed
#temperatureReader_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
temperatureReader_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

