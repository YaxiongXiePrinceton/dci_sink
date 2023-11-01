cmake_minimum_required(VERSION 3.12)

project(dcisink)

# include PUBLIC directories
set(EDV_PUBLIC_INCLUDE_DIRECTORIES      hdr/ )

INCLUDE(GNUInstallDirs)

# Edv source files list
file(GLOB_RECURSE EDV_SOURCE_FILES "src/*.c")

file(GLOB_RECURSE EDV_INCLUDE_FILES "hdr/*.h")

# build the library
add_library(${PROJECT_NAME} SHARED ${EDV_INCLUDE_FILES} ${EDV_SOURCE_FILES} )

target_include_directories(${PROJECT_NAME} PUBLIC ${EDV_PUBLIC_INCLUDE_DIRECTORIES})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    PUBLIC_HEADER "${EDV_INCLUDE_FILES}"
)

INSTALL (
    TARGETS dcisink 
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
