TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================

# Use typed rset structure (see 3.16.1 release notes)
USR_CPPFLAGS += -DUSE_TYPED_RSET


# Build an IOC support library
LIBRARY_IOC += tempReaderSupport

tempReaderSupport_SRCS += tempReader.c

tempReaderSupport_LIBS += $(EPICS_BASE_IOC_LIBS)





# Build the IOC application

PROD_IOC = tempReader
# tempReader.dbd will be created and installed
DBD += tempReader.dbd

# tempReader.dbd will be made up from these files:
tempReader_DBD += base.dbd
tempReader_DBD += tempReader.dbd

# Include dbd files from all support applications:
#tempReader_DBD += xxx.dbd

# Add all the support libraries needed by this IOC
#tempReader_LIBS += xxx

# tempReader_registerRecordDeviceDriver.cpp derives from tempReader.dbd
tempReader_SRCS += tempReader_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
tempReader_SRCS_DEFAULT += tempReaderMain.cpp
tempReader_SRCS_vxWorks += -nil-

tempReader_LIBS += tempReaderSupport

# Add support from base/src/vxWorks if needed
#tempReader_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
tempReader_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

