################################################################################
### Selecting CMake minimum version

CMAKE_MINIMUM_REQUIRED (VERSION 3.4.0)

################################################################################
### Setting Global Parameters

SET(PROJECT_NAME "DCI Sink Lib")
SET(BINARY_NAME "dcisink")

PROJECT("${PROJECT_NAME}")

SET(LIBRARY_VERSION_MAJOR 0)
SET(LIBRARY_VERSION_STRING 0.1)


INCLUDE(GNUInstallDirs)

file(GLOB_RECURSE SOURCES src/*.c)
#file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

# Include header files
include_directories(hdr)

add_library(dcisink SHARED ${SOURCES})

# Set the public header files
#file(GLOB_RECURSE HEADER hdr/*.h)
set_target_properties(dcisink PROPERTIES PUBLIC_HEADER hdr/dci_sink.h)
#set_target_properties(dcisink PROPERTIES PUBLIC_HEADER ${HEADER})

INSTALL (
	TARGETS dcisink 
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
