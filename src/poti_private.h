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
#include <PajeEnum.h>

extern FILE* paje_file;
extern int paje_extended;
extern int poti_mode;

typedef struct StringParamsList{
  char* string;
  short string_position;
  struct  StringParamsList* next;
}StringParamsList;


extern StringParamsList *stringList;
typedef enum {
  PajeHeaderEventId=999,
  //poti extended header ids
  PajeStartLinkSizeMarkEventId = 22,
  PajeStartLinkSizeEventId = 23,
  PajePushStateMarkEventId = 25
} PotiEventsId;

typedef enum {
  PAJE_Size=35,
  PAJE_Mark=36
} PotiField;

void poti_header_PajeDefineContainerType (int old_header);
void poti_header_PajeDefineVariableType (int old_header);
void poti_header_PajeDefineStateType (int old_header);
void poti_header_PajeDefineEventType (int old_header);
void poti_header_PajeDefineLinkType (int old_header);
void poti_header_PajeDefineEntityValue (int old_header);
void poti_header_PajeCreateContainer (int old_header);
void poti_header_PajeDestroyContainer (int old_header);
void poti_header_PajeSetVariable (int old_header);
void poti_header_PajeAddVariable (int old_header);
void poti_header_PajeSubVariable (int old_header);
void poti_header_PajeSetState (int old_header);
void poti_header_PajePushState (int old_header);
void poti_header_PajePushStateMark (int old_header);
void poti_header_PajePopState (int old_header);
void poti_header_PajeResetState (int old_header);
void poti_header_PajeStartLink (int old_header);
void poti_header_PajeStartLinkSize (int old_header);
void poti_header_PajeStartLinkSizeMark (int old_header);
void poti_header_PajeEndLink (int old_header);
void poti_header_PajeNewEvent (int old_header);
void _poti_header (int basic, int old_header);

#endif
