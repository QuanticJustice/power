cmake_minimum_required(VERSION 2.8)

message( "PROJECT_SOURCE_DIR points to " ${PROJECT_SOURCE_DIR})
message( "PROJECT_BINARY_DIR points to " ${PROJECT_BINARY_DIR})

message( "power_SOURCE_DIR points to " ${power_SOURCE_DIR} )

include_directories("${power_SOURCE_DIR}/include"
	"${power_SOURCE_DIR}/../prettyprint/include")

add_library(power STATIC power.c)

install(TARGETS power DESTINATION ${PROJECT_SOURCE_DIR}/lib)
