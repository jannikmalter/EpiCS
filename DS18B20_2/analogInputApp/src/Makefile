TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================

# Use typed rset structure (see 3.16.1 release notes)
USR_CPPFLAGS += -DUSE_TYPED_RSET


# Build an IOC support library
LIBRARY_IOC += analogInputSupport

analogInputSupport_SRCS += analogReader.c

analogInputSupport_LIBS += $(EPICS_BASE_IOC_LIBS)





# Build the IOC application

PROD_IOC = analogInput
# analogInput.dbd will be created and installed
DBD += analogInput.dbd

# analogInput.dbd will be made up from these files:
analogInput_DBD += base.dbd
analogInput_DBD += analogReader.dbd

# Include dbd files from all support applications:
#analogInput_DBD += xxx.dbd

# Add all the support libraries needed by this IOC
#analogInput_LIBS += xxx

# analogInput_registerRecordDeviceDriver.cpp derives from analogInput.dbd
analogInput_SRCS += analogInput_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
analogInput_SRCS_DEFAULT += analogInputMain.cpp
analogInput_SRCS_vxWorks += -nil-

analogInput_LIBS += analogInputSupport

# Add support from base/src/vxWorks if needed
#analogInput_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
analogInput_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

