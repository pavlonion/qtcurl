set(CMAKE_MODULE_PATH /usr/share/apps/cmake/modules/)
set(CMAKE_USE_SYSTEM_CURL ON)

find_package(Qt4 REQUIRED)
find_package(CURL REQUIRED)
find_package(QJSON REQUIRED)

set(CMAKE_C_FLAGS "${PLATFORM_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${PLATFORM_CXX_FLAGS} -Wall")
set(CMAKE_LINKER_FLAGS "${PLATFORM_LINKER_FLAGS} -static")

# add some useful macros and variables
# (QT_USE_FILE is a variable defined by FIND_PACKAGE( Qt4 ) that contains a
# path to CMake script)
include(${QT_USE_FILE})
include_directories(
	${QT_INCLUDE_DIR}
	${QT_QTCORE_INCLUDE_DIR}
	${QJSON_INCLUDE_DIR}
	"./"
)

message(QT_CORE_LIBRARIES =
	${QT_QTCORE}
)
message(QJSON_LIBRARIES =
	${QJSON_LIBRARIES}
)
message(CURL_LIBRARIES = 
	${CURL_LIBRARIES}
)

set(P_LIB "-qtcurl")
message(STATUS "Building library: ${P_LIB}")

set(P_LIB_SRC 
	QtCUrl.cpp
)

add_library(${P_LIB} SHARED
	${P_LIB_SRC}
)
