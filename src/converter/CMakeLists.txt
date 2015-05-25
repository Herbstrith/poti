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
FIND_PACKAGE(PajeNG REQUIRED)
FIND_PACKAGE(librastro REQUIRED)
INCLUDE_DIRECTORIES(${PAJENG_INCLUDE_PATH})
INCLUDE_DIRECTORIES(${LIBRASTRO_INCLUDE_PATH})
LINK_DIRECTORIES (${LIBRASTRO_LIBRARY_PATH})
LINK_DIRECTORIES (${LIBRASTRO_LIBRARY_PATH})

FLEX_TARGET(scanner scanner.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.c COMPILE_FLAGS "-F")
BISON_TARGET(parser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.c VERBOSE parser.output)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${CMAKE_HOME_DIRECTORY}/src/converter)
INCLUDE_DIRECTORIES(${CMAKE_HOME_DIRECTORY}/include)
INCLUDE_DIRECTORIES(${PAJENG_INCLUDE_PATH})

ADD_EXECUTABLE(conversor
  main.c
  ${FLEX_scanner_OUTPUTS}
  ${BISON_parser_OUTPUTS}
  poti_converter.c
  conversor_structs.c
  )
TARGET_LINK_LIBRARIES(conversor poti rastro ${FLEX_LIBRARIES})
