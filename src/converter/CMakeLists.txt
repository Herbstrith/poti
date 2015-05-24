# This file is part of PajeNG
#
# PajeNG is free software: you can redistribute it and/or modify it
# under the terms of the GNU Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# PajeNG is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Public License for more details.
#
# You should have received a copy of the GNU Public License
# along with PajeNG. If not, see <http://www.gnu.org/licenses/>.
CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

FIND_PACKAGE(FLEX REQUIRED)
FIND_PACKAGE(BISON REQUIRED)

FLEX_TARGET(scanner scanner.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.cc COMPILE_FLAGS "-F")
BISON_TARGET(parser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cc VERBOSE parser.output)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${CMAKE_HOME_DIRECTORY}/src/converter)
INCLUDE_DIRECTORIES(${CMAKE_HOME_DIRECTORY}/include)
INCLUDE_DIRECTORIES(${PAJENG_INCLUDE_PATH})
INCLUDE_DIRECTORIES(${poti_SOURCE_DIR}/include)

ADD_LIBRARY(conversor_library
  ${FLEX_scanner_OUTPUTS}
  ${BISON_parser_OUTPUTS}
  ${${poti_SOURCE_DIR}/include}
  ${${CMAKE_HOME_DIRECTORY}/src/converter}
  ${CMAKE_HOME_DIRECTORY}/src/converter/conversor_structs.h
  ${CMAKE_HOME_DIRECTORY}/src/converter/PajeFlexReader.cc
  ${CMAKE_HOME_DIRECTORY}/src/converter/conversor_structs.c
  )
TARGET_LINK_LIBRARIES(conversor_library poti)
TARGET_LINK_LIBRARIES(conversor_library rastro)
ADD_EXECUTABLE(conversor main.cc)
SET_PROPERTY(TARGET conversor PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#INCLUDE_DIRECTORIES(${PAJENG_INCLUDE_PATH})
#LINK_DIRECTORIES (${PAJENG_LIBRARY_PATH})
TARGET_LINK_LIBRARIES(conversor_library ${FLEX_LIBRARIES})
TARGET_LINK_LIBRARIES(conversor_library ${PAJENG_LIBRARY_PATH}/libpaje.so)
TARGET_LINK_LIBRARIES(conversor poti)
TARGET_LINK_LIBRARIES(conversor rastro)
TARGET_LINK_LIBRARIES(conversor conversor_library)
TARGET_LINK_LIBRARIES(conversor ${PAJENG_LIBRARY_PATH}/libpaje.so)


