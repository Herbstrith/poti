#include <stdio.h>
#include <search.h>
#include "main.h"
#include <poti.h>
#include <poti_private.h>
#include <rastro.h>
#include <string.h>
#include <conversor_structs.h>




char* create_poti_event_poti_definitions(int identifier, paje_line line)
{
  switch (identifier)
	  {
		  case PAJE_DefineContainerType:
        poti_DefineContainerType(line.word[1],line.word[2],line.word[3]);
		  //	return "PajeDefineContainerType";
			  break;
		  case PAJE_DefineEventType:
        poti_DefineEventType(line.word[1],line.word[2],line.word[3]);
		  //	return "PajeDefineEventType";
			  break;
		  case PAJE_DefineStateType:
        poti_DefineStateType(line.word[1],line.word[2],line.word[3]);
		  //	return "PajeDefineStateType";
			  break;
		  case PAJE_DefineVariableType:
        poti_DefineVariableType(line.word[1],line.word[2],line.word[3],line.word[4]);
		  //	return "PajeDefineVariableType";
			  break;
		  case PAJE_DefineLinkType:
         poti_DefineLinkType(line.word[1],line.word[2],line.word[3],line.word[4],line.word[5]);
		  //	return "PajeDefineLinkType";
			  break;
		  case PAJE_DefineEntityValue:
        poti_DefineEntityValue(line.word[1],line.word[2],line.word[3],line.word[4]);
		  //	return "PajeDefineEntityValue";
			  break;
		  case PAJE_CreateContainer:
        poti_CreateContainer(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5]);
		  //	return "PajeCreateContainer";
			  break;
		  case PAJE_DestroyContainer:
        poti_DestroyContainer(strtod(line.word[1],NULL),line.word[2],line.word[3]);
		  //	return "PajeDestroyContainer";
			  break;
		  case PAJE_NewEvent:
        poti_NewEvent(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4]);
			  //return "PajeNewEvent";
			  break;
		  case PAJE_SetState:
        poti_SetState(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4]);
		  //	return "PajeSetState";
			  break;
		  case  PAJE_PushState:
        poti_PushState(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4]);
			  //return "PajePushState";
			  break;	
		  case PAJE_PopState:
        poti_PopState(strtod(line.word[1],NULL),line.word[2],line.word[3]);
			  //return "PajePopState";
			  break;	
		  case PAJE_ResetState:
        poti_ResetState(strtod(line.word[1],NULL),line.word[2],line.word[3]);
			  //return "PajeResetState";
			  break;
		  case PAJE_SetVariable:
        poti_SetVariable (strtod(line.word[1],NULL),line.word[2],line.word[3],strtod(line.word[4],NULL));
			  //return "PajeSetVariable";
			  break;	
		  case  PAJE_AddVariable:
        poti_AddVariable(strtod(line.word[1],NULL),line.word[2],line.word[3],strtod(line.word[4],NULL));
			  //return "PajeAddVariable";
			  break;		
		  case PAJE_SubVariable:
        poti_SubVariable(strtod(line.word[1],NULL),line.word[2],line.word[3],strtod(line.word[4],NULL));
		  //	return "PajeSubVariable";
			  break;	
		  case PAJE_StartLink:
        poti_StartLink(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5],line.word[6]);
			  //return "PajeStartLink";
			  break;
		  case PAJE_EndLink:
        poti_EndLink(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5],line.word[6]);
		  //	return "PajeEndLink";
			  break;
		  case PAJE_PushStateMark:
        poti_PushStateMark(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4], atoi(line.word[5]) );
		  //	return "PajePushState";
			  break;
		  case PAJE_StartLinkSize:
        poti_StartLinkSize(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5],line.word[6],atoi(line.word[7]));
			  //return "PajeStartLink";
			  break;
		  case PAJE_StartLinkSizeMark:
        poti_StartLinkSizeMark(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5],line.word[6],
                                atoi(line.word[7]),atoi(line.word[8]) );
		  //	return "PajeStartLink";
			  break;	
		
	  }
      return "ERROR:event definition not found";
}






char* create_poti_event(int identifier,paje_line line)
{
  switch (identifier)
	  {
		  case PajeDefineContainerTypeEventId:
        poti_DefineContainerType(line.word[1],line.word[2],line.word[3]);
		  //	return "PajeDefineContainerType";
			  break;
		  case PajeDefineEventTypeEventId:
        poti_DefineEventType(line.word[1],line.word[2],line.word[3]);
		  //	return "PajeDefineEventType";
			  break;
		  case PajeDefineStateTypeEventId:
        poti_DefineStateType(line.word[1],line.word[2],line.word[3]);
		  //	return "PajeDefineStateType";
			  break;
		  case PajeDefineVariableTypeEventId:
        poti_DefineVariableType(line.word[1],line.word[2],line.word[3],line.word[4]);
		  //	return "PajeDefineVariableType";
			  break;
		  case PajeDefineLinkTypeEventId:
         poti_DefineLinkType(line.word[1],line.word[2],line.word[3],line.word[4],line.word[5]);
		  //	return "PajeDefineLinkType";
			  break;
		  case PajeDefineEntityValueEventId:
        poti_DefineEntityValue(line.word[1],line.word[2],line.word[3],line.word[4]);
		  //	return "PajeDefineEntityValue";
			  break;
		  case PajeCreateContainerEventId:
        poti_CreateContainer(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5]);
		  //	return "PajeCreateContainer";
			  break;
		  case PajeDestroyContainerEventId:
        poti_DestroyContainer(strtod(line.word[1],NULL),line.word[2],line.word[3]);
		  //	return "PajeDestroyContainer";
			  break;
		  case PajeNewEventEventId:
        poti_NewEvent(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4]);
			  //return "PajeNewEvent";
			  break;
		  case PajeSetStateEventId:
        poti_SetState(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4]);
		  //	return "PajeSetState";
			  break;
		  case PajePushStateEventId:
        poti_PushState(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4]);
			  //return "PajePushState";
			  break;	
		  case PajePopStateEventId:
        poti_PopState(strtod(line.word[1],NULL),line.word[2],line.word[3]);
			  //return "PajePopState";
			  break;	
		  case PajeResetStateEventId:
        poti_ResetState(strtod(line.word[1],NULL),line.word[2],line.word[3]);
			  //return "PajeResetState";
			  break;
		  case PajeSetVariableEventId:
        poti_SetVariable (strtod(line.word[1],NULL),line.word[2],line.word[3],strtod(line.word[4],NULL));
			  //return "PajeSetVariable";
			  break;	
		  case PajeAddVariableEventId:
        poti_AddVariable(strtod(line.word[1],NULL),line.word[2],line.word[3],strtod(line.word[4],NULL));
			  //return "PajeAddVariable";
			  break;		
		  case PajeSubVariableEventId:
        poti_SubVariable(strtod(line.word[1],NULL),line.word[2],line.word[3],strtod(line.word[4],NULL));
		  //	return "PajeSubVariable";
			  break;	
		  case PajeStartLinkEventId:
        poti_StartLink(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5],line.word[6]);
			  //return "PajeStartLink";
			  break;
		  case PajeEndLinkEventId:
        poti_EndLink(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5],line.word[6]);
		  //	return "PajeEndLink";
			  break;
		  case PajeEventIdCount:
        poti_EndLink(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5],line.word[6]);
		  //	return "PajeEventIdCount";
			  break;
		  case PajeUnknownEventId:
			  //return "PajeUnknownEventId";
			  break;
		  case PajePushStateMarkEventId:
        poti_PushStateMark(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4], atoi(line.word[5]) );
		  //	return "PajePushState";
			  break;
		  case PajeStartLinkSizeEventId:
        poti_StartLinkSize(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5],line.word[6],atoi(line.word[7]));
			  //return "PajeStartLink";
			  break;
		  case PajeStartLinkSizeMarkEventId:
        poti_StartLinkSizeMark(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5],line.word[6],
                                atoi(line.word[7]),atoi(line.word[8]) );
		  //	return "PajeStartLink";
			  break;	
		
	  }
      return "ERROR:event definition not found";
}

