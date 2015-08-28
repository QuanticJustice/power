cmake_minimum_required(VERSION 2.8)

message( "PROJECT_SOURCE_DIR points to " ${PROJECT_SOURCE_DIR})
message( "PROJECT_BINARY_DIR points to " ${PROJECT_BINARY_DIR})

message( "power_SOURCE_DIR points to " ${power_SOURCE_DIR} )

# apparently required for CMake module that includes ExternalProject_Add functionality
include( ExternalProject )

ExternalProject_Add(
   project_prettyprint
   GIT_REPOSITORY https://github.com/QuanticJustice/prettyprint.git
   GIT_TAG master
)

# TODO: need to figure out how to pass env variable in so that GIT_TAG can point to specific version (tag)

# having INSTALL_COMMAND "" and BUILD_COMMAND "" effectively disables the BUILD and INSTALL steps

#include_directories("${PROJECT_SOURCE_DIR}/include"
#	"${PROJECT_SOURCE_DIR}/../prettyprint/include" )

#include_directories("${squareroot_SOURCE_DIR}/include"
#	"${squareroot_SOURCE_DIR}/../prettyprint/include")

ExternalProject_Get_Property( project_prettyprint install_dir )

message( "project_prettyprint install_dir retrieved as " ${install_dir} )

# just need the include, there is no linking between libraries (i.e. this is not an application)
include_directories( 
   ${PROJECT_SOURCE_DIR}/build/src/project_prettyprint-prefix/src/project_prettyprint/inc
   ${PROJECT_SOURCE_DIR}/include
)

add_library( power STATIC power.c )

target_link_libraries( power m )
# OMG, this fixed it...
add_dependencies( power project_prettyprint )

# install the targets to specific directories
install( TARGETS power DESTINATION ${PROJECT_SOURCE_DIR}/lib )
install( FILES ${PROJECT_SOURCE_DIR}/include/power.h DESTINATION ${PROJECT_SOURCE_DIR}/inc )
