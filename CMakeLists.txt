set(CMAKE_MODULE_PATH /usr/share/apps/cmake/modules/)
set(CMAKE_USE_SYSTEM_CURL ON)

find_package(Qt4 REQUIRED)
find_package(CURL REQUIRED)
find_package(QJSON REQUIRED)

# set(QT_USE_QTDBUS ON)
# set(QT_USE_QTSCRIPT ON)
# set(QT_DONT_USE_QTGUI ON)

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
# 	${QT_QTGUI_INCLUDE_DIR}
# 	${QT_QTDBUS_INCLUDE_DIR}
# 	${QT_QTSQL_INCLUDE_DIR}
# 	${QT_QTXML_INCLUDE_DIR}
# 	${QT_QTSCRIPT_INCLUDE_DIR}
	${QJSON_INCLUDE_DIR}
# 	"lib"
# 	"lib/log"
# 	"lib/qtcurl"
# 	"lib/entity"
# 	"lib/database"
# 	"lib/functions"
# 	"module"
# 	"entities"
# 	"common"
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

set(P_LIB "${P}-qtcurl")
message(STATUS "Сборка библиотеки: ${P_LIB}")

set(P_LIB_SRC 
	QtCUrl.cpp
)

add_library(${P_LIB} SHARED
	${P_LIB_SRC}
)
