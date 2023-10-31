################################################################################
### Selecting CMake minimum version

CMAKE_MINIMUM_REQUIRED (VERSION 3.4.0)

################################################################################
### Setting Global Parameters

SET(PROJECT_NAME "Examples of DCI SINK LIB")
PROJECT("${PROJECT_NAME}")

add_executable(server remote_server.c)
add_executable(client remote_client.c)


#find_package(dcisink)
target_link_libraries(server dcisink pthread)
target_link_libraries(client dcisink pthread)
