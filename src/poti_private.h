/*
    This file is part of Poti

    Poti is free software: you can redistribute it and/or modify it
    under the terms of the GNU Lesser Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Poti is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser Public License for more details.

    You should have received a copy of the GNU Lesser Public License
    along with Poti. If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef __POTI_PRIVATE_H__
#define __POTI_PRIVATE_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <poti.h>
#include <poti_config.h>
#include <PajeDefinitions.h>



typedef enum {
  PajeHeaderEventId=999,
  //poti extender header ids
  PajeStartLinkSizeMarkEventId = 22,
  PajeStartLinkSizeEventId = 23,
  PajePushStateMarkEventId = 25
} PotiEventsId;

typedef enum {
  PAJE_Size=35,
  PAJE_Mark=36
} PotiField;

void _poti_header (int basic, int old_header,int output_mode);

#endif
