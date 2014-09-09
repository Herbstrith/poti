# This file is part of Poti
#
# Poti is free software: you can redistribute it and/or modify it
# under the terms of the GNU Lesser Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Poti is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser Public License for more details.
#
# You should have received a copy of the GNU Lesser Public License
# along with Poti. If not, see <http://www.gnu.org/licenses/>.
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(poti)
SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")



EXEC_PROGRAM("git --git-dir=${PROJECT_SOURCE_DIR}/.git log --oneline -1" OUTPUT_VARIABLE "POTI_GITVERSION")
EXEC_PROGRAM("git --git-dir=${PROJECT_SOURCE_DIR}/.git log -n 1 --format=%ai" OUTPUT_VARIABLE "POTI_GITDATE")


SET_SOURCE_FILES_PROPERTIES( src/poti_private.h src/poti.c src/poti_header.c src/poti_events.c src/poti_reader.c librastro/ PROPERTIES LANGUAGE CXX )

SET(CMAKE_C_FLAGS "-Wall -Wunused -Wmissing-prototypes -Wmissing-declarations -Wpointer-arith -Wchar-subscripts -Wcomment -Wformat -Wwrite-strings -Wno-unused-function -Wno-unused-parameter -Wno-strict-aliasing -Wno-format-nonliteral -Werror ")

# poti_config.h.in file
CONFIGURE_FILE("${poti_SOURCE_DIR}/include/poti_config.h.in" "${CMAKE_BINARY_DIR}/include/poti_config.h" ESCAPE_QUOTES @ONLY IMMEDIATE)


SET(POTI_SRC src/poti.c src/poti_header.c src/poti_events.c src/poti_events_rastro.c src/poti_header_rastro.c )
SET(POTI_HEADERS include/poti.h include/poti_events_rastro.h include/poti_header_rastro.h ${CMAKE_BINARY_DIR}/include/poti_config.h)


FIND_PACKAGE(Boost REQUIRED)
INCLUDE_DIRECTORIES(paje_library ${Boost_INCLUDE_DIR})

ADD_SUBDIRECTORY(librastro)
#ADD_SUBDIRECTORY(pajeng)
#add_subdirectory (${CMAKE_HOME_DIRECTORY}/pajeng/src/libpaje/)

INCLUDE_DIRECTORIES(${poti_SOURCE_DIR}/include/)
INCLUDE_DIRECTORIES(${poti_SOURCE_DIR}/src/)
INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/include/)

INCLUDE_DIRECTORIES(${rastro_SOURCE_DIR}/include/)
INCLUDE_DIRECTORIES(${rastro_SOURCE_DIR}/src/)

INCLUDE_DIRECTORIES(${CMAKE_HOME_DIRECTORY}/pajeng/src/libpaje/)


TARGET_LINK_LIBRARIES(rastro)
ADD_LIBRARY(poti SHARED ${POTI_SRC})

SET_TARGET_PROPERTIES(
  poti
PROPERTIES
# bump when new function are added in the library
  VERSION 4.2
# bump when ABI is broken (symbols removed or parameters changed)
  SOVERSION 4
)
# bump when the API change (new functions in the header file)
SET(POTI_APIVERSION 2)

# The poti binary reader
ADD_EXECUTABLE(poti_reader src/poti_reader.c)
TARGET_LINK_LIBRARIES(poti_reader poti rastro)

INSTALL(TARGETS poti
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
INSTALL(FILES include/poti.h
  DESTINATION include)

ADD_SUBDIRECTORY(examples)
ADD_SUBDIRECTORY(pkgconfig)



# Include directories (shared by everyone)



INSTALL(TARGETS poti DESTINATION lib)
INSTALL(FILES ${POTI_HEADERS} DESTINATION include)

