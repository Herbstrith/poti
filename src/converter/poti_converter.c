/*
    This file is part of Poti

    Poti is free software: you can redistribute it and/or modify
    it under the terms of the GNU Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Poti is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Public License for more details.

    You should have received a copy of the GNU Public License
    along with Poti. If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdio.h>
#include <PajeEnum.h>
#include "poti_private.h"
#include "conversor_structs.h"

void create_header_event(PajeEventId eventId);
void create_poti_event (paje_line line);


void create_header_event(PajeEventId eventId)
{
  switch (eventId) {
  case PajeDefineContainerTypeEventId:
    poti_header_PajeDefineContainerType(0);
    break;
  case PajeDefineEventTypeEventId:
    poti_header_PajeDefineEventType(0);
    break;
  case PajeDefineStateTypeEventId:
    poti_header_PajeDefineStateType(0);
    break;
  case PajeDefineVariableTypeEventId:
    poti_header_PajeDefineVariableType(0);
    break;
  case PajeDefineLinkTypeEventId:
    poti_header_PajeDefineLinkType(0);
    break;
  case PajeDefineEntityValueEventId:
    poti_header_PajeDefineEntityValue(0);
    break;
  case PajeCreateContainerEventId:
    poti_header_PajeCreateContainer(0);
    break;
  case PajeDestroyContainerEventId:
    poti_header_PajeDestroyContainer(0);
    break;
  case PajeNewEventEventId:
    poti_header_PajeNewEvent(0);
    break;
  case PajeSetStateEventId:
    poti_header_PajeSetState(0);
    break;
  case PajePushStateEventId:
    poti_header_PajePushState(0);
    break;
  case PajePopStateEventId:
    poti_header_PajePopState(0);
    break;
  case PajeResetStateEventId:
    poti_header_PajeResetState(0);
    break;
  case PajeSetVariableEventId:
    poti_header_PajeSetVariable(0);
    break;
  case PajeAddVariableEventId:
    poti_header_PajeAddVariable(0);
    break;
  case PajeSubVariableEventId:
    poti_header_PajeSubVariable(0);
    break;
  case PajeStartLinkEventId:
    poti_header_PajeStartLink(0);
    break;
  case PajeEndLinkEventId:
    poti_header_PajeEndLink(0);
    break;

  case PajeTraceFileEventId:
  case PajeEventIdCount:
  case PajeUnknownEventId:
    //TODO
    break;
  }
}

static void print_paje_line (paje_line line)
{
  int i;
  for (i = 0; i < line.word_count; i++){
    printf ("%s", line.word[i]);
    if (i <= line.word_count){
      printf(" ");
    }
  }
  printf("\n");
}

void create_poti_event (paje_line line)
{
  int identifier = atoi(line.word[0]); 
  PajeEventId eventId = getPajeEventId (identifier);
  switch (eventId) {
  case PajeDefineContainerTypeEventId:
    poti_DefineContainerType(line.word[getPajeFieldPosition(identifier,PAJE_Alias)],
			     line.word[getPajeFieldPosition(identifier,PAJE_Type)],
			     line.word[getPajeFieldPosition(identifier,PAJE_Name)]);
    break;
  case PajeDefineEventTypeEventId:
    poti_DefineEventType(line.word[getPajeFieldPosition(identifier,PAJE_Alias)],
			 line.word[getPajeFieldPosition(identifier,PAJE_Type)],
			 line.word[getPajeFieldPosition(identifier,PAJE_Name)]);
    break;
  case PajeDefineStateTypeEventId:
    poti_DefineStateType(line.word[getPajeFieldPosition(identifier,PAJE_Alias)],
			 line.word[getPajeFieldPosition(identifier,PAJE_Type)],
			 line.word[getPajeFieldPosition(identifier,PAJE_Name)]);
    break;
  case PajeDefineVariableTypeEventId:
    poti_DefineVariableType(line.word[getPajeFieldPosition(identifier,PAJE_Alias)],
			    line.word[getPajeFieldPosition(identifier,PAJE_Type)],
			    line.word[getPajeFieldPosition(identifier,PAJE_Name)],
			    line.word[getPajeFieldPosition(identifier,PAJE_Color)]);
    break;
  case PajeDefineLinkTypeEventId:
    poti_DefineLinkType(line.word[getPajeFieldPosition(identifier,PAJE_Alias)],
			line.word[getPajeFieldPosition(identifier,PAJE_Type)],
			line.word[getPajeFieldPosition(identifier,PAJE_StartContainerType)],
			line.word[getPajeFieldPosition(identifier,PAJE_EndContainerType)],
			line.word[getPajeFieldPosition(identifier,PAJE_Name)]);
    break;
  case PajeDefineEntityValueEventId:
    poti_DefineEntityValue(line.word[getPajeFieldPosition(identifier,PAJE_Alias)],
			   line.word[getPajeFieldPosition(identifier,PAJE_Type)],
			   line.word[getPajeFieldPosition(identifier,PAJE_Name)],
			   line.word[getPajeFieldPosition(identifier,PAJE_Color)]);
    break;
  case PajeCreateContainerEventId:
    poti_CreateContainer(strtod(line.word[getPajeFieldPosition(identifier,PAJE_Time)],NULL),
			 line.word[getPajeFieldPosition(identifier,PAJE_Alias)],
			 line.word[getPajeFieldPosition(identifier,PAJE_Type)],
			 line.word[getPajeFieldPosition(identifier,PAJE_Container)],
			 line.word[getPajeFieldPosition(identifier,PAJE_Name)]);
    break;
  case PajeDestroyContainerEventId:
    poti_DestroyContainer(strtod(line.word[getPajeFieldPosition(identifier,PAJE_Time)],NULL),
			  line.word[getPajeFieldPosition(identifier,PAJE_Type)],
			  line.word[getPajeFieldPosition(identifier,PAJE_Name)]);
    break;
  case PajeNewEventEventId:
    poti_NewEvent(strtod(line.word[getPajeFieldPosition(identifier,PAJE_Time)],NULL),
		  line.word[getPajeFieldPosition(identifier,PAJE_Container)],
		  line.word[getPajeFieldPosition(identifier,PAJE_Type)],
		  line.word[getPajeFieldPosition(identifier,PAJE_Value)]);
    break;
  case PajeSetStateEventId:
    poti_SetState(strtod(line.word[getPajeFieldPosition(identifier,PAJE_Time)],NULL),
		  line.word[getPajeFieldPosition(identifier,PAJE_Container)],
		  line.word[getPajeFieldPosition(identifier,PAJE_Type)],
		  line.word[getPajeFieldPosition(identifier,PAJE_Value)]);
    break;
  case PajePushStateEventId:
    poti_PushState(strtod(line.word[getPajeFieldPosition(identifier,PAJE_Time)],NULL),
		   line.word[getPajeFieldPosition(identifier,PAJE_Container)],
		   line.word[getPajeFieldPosition(identifier,PAJE_Type)],
		   line.word[getPajeFieldPosition(identifier,PAJE_Value)]);
    break;
  case PajePopStateEventId:
    poti_PopState(strtod(line.word[getPajeFieldPosition(identifier,PAJE_Time)],NULL),
		  line.word[getPajeFieldPosition(identifier,PAJE_Container)],
		  line.word[getPajeFieldPosition(identifier,PAJE_Type)]);
    break;
  case PajeResetStateEventId:
    poti_ResetState(strtod(line.word[getPajeFieldPosition(identifier,PAJE_Time)],NULL),
		    line.word[getPajeFieldPosition(identifier,PAJE_Container)],
		    line.word[getPajeFieldPosition(identifier,PAJE_Type)]);
    break;
  case PajeSetVariableEventId:
    poti_SetVariable(strtod(line.word[getPajeFieldPosition(identifier,PAJE_Time)],NULL),
		     line.word[getPajeFieldPosition(identifier,PAJE_Container)],
		     line.word[getPajeFieldPosition(identifier,PAJE_Type)],
		     strtod(line.word[getPajeFieldPosition(identifier,PAJE_Value)],NULL));
    break;
  case PajeAddVariableEventId:
    poti_AddVariable(strtod(line.word[getPajeFieldPosition(identifier,PAJE_Time)],NULL),
		     line.word[getPajeFieldPosition(identifier,PAJE_Container)],
		     line.word[getPajeFieldPosition(identifier,PAJE_Type)],
		     strtod(line.word[getPajeFieldPosition(identifier,PAJE_Value)],NULL));
    break;
  case PajeSubVariableEventId:
    poti_SubVariable(strtod(line.word[getPajeFieldPosition(identifier,PAJE_Time)],NULL),
		     line.word[getPajeFieldPosition(identifier,PAJE_Container)],
		     line.word[getPajeFieldPosition(identifier,PAJE_Type)],
		     strtod(line.word[getPajeFieldPosition(identifier,PAJE_Value)],NULL));
    break;
  case PajeStartLinkEventId:
    poti_StartLink(strtod(line.word[getPajeFieldPosition(identifier,PAJE_Time)],NULL),
		   line.word[getPajeFieldPosition(identifier,PAJE_Container)],
		   line.word[getPajeFieldPosition(identifier,PAJE_Type)],
		   line.word[getPajeFieldPosition(identifier,PAJE_StartContainer)],
		   line.word[getPajeFieldPosition(identifier,PAJE_Value)],
		   line.word[getPajeFieldPosition(identifier,PAJE_Key)]);
    break;
  case PajeEndLinkEventId:
    poti_EndLink(strtod(line.word[getPajeFieldPosition(identifier,PAJE_Time)],NULL),
		 line.word[getPajeFieldPosition(identifier,PAJE_Container)],
		 line.word[getPajeFieldPosition(identifier,PAJE_Type)],
		 line.word[getPajeFieldPosition(identifier,PAJE_EndContainer)],
		 line.word[getPajeFieldPosition(identifier,PAJE_Value)],
		 line.word[getPajeFieldPosition(identifier,PAJE_Key)]);
    break;
  default:
    break;
  }
}
