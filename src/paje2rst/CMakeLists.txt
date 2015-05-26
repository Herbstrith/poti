# This file is part of Poti
#
# Poti is free software: you can redistribute it and/or modify it
# under the terms of the GNU Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Poti is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Public License for more details.
#
# You should have received a copy of the GNU Public License
# along with Poti. If not, see <http://www.gnu.org/licenses/>.
CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

FIND_PACKAGE(FLEX REQUIRED)
FIND_PACKAGE(BISON REQUIRED)
INCLUDE_DIRECTORIES(${PAJENG_INCLUDE_PATH})
INCLUDE_DIRECTORIES(${LIBRASTRO_INCLUDE_PATH})
LINK_DIRECTORIES (${LIBRASTRO_LIBRARY_PATH})
LINK_DIRECTORIES (${LIBRASTRO_LIBRARY_PATH})

FLEX_TARGET(scanner scanner.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.c COMPILE_FLAGS "-F")
BISON_TARGET(parser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.c VERBOSE parser.output)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${CMAKE_HOME_DIRECTORY}/src/paje2rst)
INCLUDE_DIRECTORIES(${CMAKE_HOME_DIRECTORY}/include)
INCLUDE_DIRECTORIES(${PAJENG_INCLUDE_PATH})

ADD_EXECUTABLE(paje2rst
  main.c
  ${FLEX_scanner_OUTPUTS}
  ${BISON_parser_OUTPUTS}
  poti_converter.c
  conversor_structs.c
  )
TARGET_LINK_LIBRARIES(paje2rst poti rastro ${FLEX_LIBRARIES})
