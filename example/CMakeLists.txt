################################################################################
### Selecting CMake minimum version

CMAKE_MINIMUM_REQUIRED (VERSION 3.4.0)

################################################################################
### Setting Global Parameters

SET(PROJECT_NAME "DCISINKAPP")
PROJECT("${PROJECT_NAME}")

INCLUDE(GNUInstallDirs)
add_executable(server remote_server.c dci_sink_serv.c)
add_executable(client remote_client.c dci_sink_client.c)

set(CMAKE_PREFIX_PATH "/usr/local/lib/" ${CMAKE_PREFIX_PATH})

LINK_DIRECTORIES(
	"/usr/local/lib/"
)


find_package(Threads REQUIRED)

#find_package(dcisink)
target_link_libraries(server dcisink pthread)
target_link_libraries(client dcisink pthread)
