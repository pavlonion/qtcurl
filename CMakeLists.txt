cmake_minimum_required(VERSION 2.8)
set(CMAKE_MODULE_PATH /usr/share/apps/cmake/modules/)
set(CMAKE_USE_SYSTEM_CURL ON)

find_package(Qt4 REQUIRED)
find_package(CURL REQUIRED)
find_package(QJSON REQUIRED)

# add some useful macros and variables
# (QT_USE_FILE is a variable defined by FIND_PACKAGE( Qt4 ) that contains a
# path to CMake script)
include(${QT_USE_FILE})
include_directories(
	${QT_INCLUDE_DIR}
	${QT_QTCORE_INCLUDE_DIR}
	"./"
)

IF (NOT DEFINED QTCURL_DEBUG)
	SET(QTCURL_DEBUG "off")
ENDIF()

IF (QTCURL_DEBUG STREQUAL "on")
	ADD_DEFINITIONS(-DQTCURL_DEBUG)
ELSEIF (QTCURL_DEBUG STREQUAL "off")
	REMOVE_DEFINITIONS(-DQTCURL_DEBUG)
ELSE()
	message(WARNING
		"QTCURL_DEBUG=${QTCURL_DEBUG} is wrong value. Expected \"on\" or \"off\"."
	)
	SET(QTCURL_DEBUG "off")
	REMOVE_DEFINITIONS(-DQTCURL_DEBUG)
ENDIF()

message(QTCURL_DEBUG = ${QTCURL_DEBUG})
message(QT_QTCORE_LIBRARY = ${QT_QTCORE_LIBRARY})
message(CURL_LIBRARIES = ${CURL_LIBRARIES})

set(P_LIB "-qtcurl")
message(STATUS "Building library: ${P_LIB}")

set(P_LIB_SRC 
	QtCUrl.cpp
)

add_library(${P_LIB} SHARED
	${P_LIB_SRC}
)
