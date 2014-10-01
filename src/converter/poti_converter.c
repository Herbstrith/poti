#include <stdio.h>
#include <search.h>
#include "main.h"
#include <poti.h>
#include <poti_private.h>
#include <poti_header.c>
#include <rastro.h>
#include <string.h>
#include <conversor_structs.h>

void create_header_event(header_event *event)
{
  switch (event->paje_event_type_definition)
	{
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
		//poti extended events : TODO merge with same events
		case PajePushStateMarkEventId:
      poti_header_PajePushStateMark(0);
			break;
		case PajeStartLinkSizeEventId:
      poti_header_PajeStartLinkSize(0);
			break;
		case PajeStartLinkSizeMarkEventId:
      poti_header_PajeStartLinkSizeMark(0);
			break;	
		
	}



}



void create_header(header_event_list_item *list)
{
  header_event_list_item *actual_item;
  actual_item = list;

  while(actual_item != NULL)
  {
    
    create_header_event(actual_item->event_define);
    if(actual_item->next == NULL)
      break;

    actual_item= actual_item->next;
    

  }

}


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
     // return "ERROR:event definition not found";
}




/*

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
     // return "ERROR:event definition not found";
}
*/


void create_poti_event(int identifier,paje_line line, header_event_list_item *list)
{

  header_event *event_to_create = findHeaderFileId(list, identifier);
  
  switch (event_to_create->paje_event_type_definition)
	  {
		  case PajeDefineContainerTypeEventId:
        poti_DefineContainerType(line.word[getPajeFieldPosition(event_to_create,PAJE_Alias)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)],line.word[getPajeFieldPosition(event_to_create,PAJE_Name)]);
		  //	return "PajeDefineContainerType";
			  break;
		  case PajeDefineEventTypeEventId:
        poti_DefineEventType(line.word[getPajeFieldPosition(event_to_create,PAJE_Alias)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)],line.word[getPajeFieldPosition(event_to_create,PAJE_Name)]);
		  //	return "PajeDefineEventType";
			  break;
		  case PajeDefineStateTypeEventId:
        poti_DefineStateType(line.word[getPajeFieldPosition(event_to_create,PAJE_Alias)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)],line.word[getPajeFieldPosition(event_to_create,PAJE_Name)]);
		  //	return "PajeDefineStateType";
			  break;
		  case PajeDefineVariableTypeEventId:
        poti_DefineVariableType(line.word[getPajeFieldPosition(event_to_create,PAJE_Alias)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)],line.word[getPajeFieldPosition(event_to_create,PAJE_Name)],line.word[getPajeFieldPosition(event_to_create,PAJE_Color)]);
		  //	return "PajeDefineVariableType";
			  break;
		  case PajeDefineLinkTypeEventId:
         poti_DefineLinkType(line.word[getPajeFieldPosition(event_to_create,PAJE_Alias)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)],line.word[getPajeFieldPosition(event_to_create,PAJE_StartContainerType)],line.word[getPajeFieldPosition(event_to_create,PAJE_EndContainerType)],line.word[getPajeFieldPosition(event_to_create,PAJE_Name)]);
		  //	return "PajeDefineLinkType";
			  break;
		  case PajeDefineEntityValueEventId:
        poti_DefineEntityValue(line.word[getPajeFieldPosition(event_to_create,PAJE_Alias)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)],line.word[getPajeFieldPosition(event_to_create,PAJE_Name)],line.word[getPajeFieldPosition(event_to_create,PAJE_Color)]);
		  //	return "PajeDefineEntityValue";
			  break;
		  case PajeCreateContainerEventId:
        poti_CreateContainer(strtod(line.word[getPajeFieldPosition(event_to_create,PAJE_Time)],NULL),line.word[getPajeFieldPosition(event_to_create,PAJE_Alias)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)],line.word[getPajeFieldPosition(event_to_create,PAJE_Container)],line.word[getPajeFieldPosition(event_to_create,PAJE_Name)]);
		  //	return "PajeCreateContainer";
			  break;
		  case PajeDestroyContainerEventId:
        poti_DestroyContainer(strtod(line.word[getPajeFieldPosition(event_to_create,PAJE_Time)],NULL),line.word[getPajeFieldPosition(event_to_create,PAJE_Type)],line.word[getPajeFieldPosition(event_to_create,PAJE_Container)]);
		  //	return "PajeDestroyContainer";
			  break;
		  case PajeNewEventEventId:
        poti_NewEvent(strtod(line.word[getPajeFieldPosition(event_to_create,PAJE_Time)],NULL),line.word[getPajeFieldPosition(event_to_create,PAJE_Container)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)],line.word[getPajeFieldPosition(event_to_create,PAJE_Value)]);
			  //return "PajeNewEvent";
			  break;
		  case PajeSetStateEventId:
        poti_SetState(strtod(line.word[getPajeFieldPosition(event_to_create,PAJE_Time)],NULL),line.word[getPajeFieldPosition(event_to_create,PAJE_Container)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)],line.word[getPajeFieldPosition(event_to_create,PAJE_Value)]);
		  //	return "PajeSetState";
			  break;
		  case PajePushStateEventId:
        poti_PushState(strtod(line.word[getPajeFieldPosition(event_to_create,PAJE_Time)],NULL),line.word[getPajeFieldPosition(event_to_create,PAJE_Container)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)],line.word[getPajeFieldPosition(event_to_create,PAJE_Value)]);
			  //return "PajePushState";
			  break;	
		  case PajePopStateEventId:
        poti_PopState(strtod(line.word[getPajeFieldPosition(event_to_create,PAJE_Time)],NULL),line.word[getPajeFieldPosition(event_to_create,PAJE_Container)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)]);
			  //return "PajePopState";
			  break;	
		  case PajeResetStateEventId:
        poti_ResetState(strtod(line.word[getPajeFieldPosition(event_to_create,PAJE_Time)],NULL),line.word[getPajeFieldPosition(event_to_create,PAJE_Container)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)]);
			  //return "PajeResetState";
			  break;
		  case PajeSetVariableEventId:
        poti_SetVariable (strtod(line.word[getPajeFieldPosition(event_to_create,PAJE_Time)],NULL),line.word[getPajeFieldPosition(event_to_create,PAJE_Container)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)],strtod(line.word[getPajeFieldPosition(event_to_create,PAJE_Value)],NULL));
			  //return "PajeSetVariable";
			  break;	
		  case PajeAddVariableEventId:
        poti_AddVariable(strtod(line.word[1],NULL),line.word[2],line.word[3],strtod(line.word[4],NULL));
			  //return "PajeAddVariable";
			  break;		
		  case PajeSubVariableEventId:
        poti_SubVariable(strtod(line.word[getPajeFieldPosition(event_to_create,PAJE_Time)],NULL),line.word[getPajeFieldPosition(event_to_create,PAJE_Container)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)],strtod(line.word[getPajeFieldPosition(event_to_create,PAJE_Value)],NULL));
		  //	return "PajeSubVariable";
			  break;	
		  case PajeStartLinkEventId:
        poti_StartLink(strtod(line.word[getPajeFieldPosition(event_to_create,PAJE_Time)],NULL),line.word[getPajeFieldPosition(event_to_create,PAJE_Container)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)],line.word[getPajeFieldPosition(event_to_create,PAJE_StartContainer)],line.word[getPajeFieldPosition(event_to_create,PAJE_Value)],line.word[getPajeFieldPosition(event_to_create,PAJE_Key)]);
			  //return "PajeStartLink";
			  break;
		  case PajeEndLinkEventId:
        poti_EndLinkstrtod(line.word[getPajeFieldPosition(event_to_create,PAJE_Time)],NULL),line.word[getPajeFieldPosition(event_to_create,PAJE_Container)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)],line.word[getPajeFieldPosition(event_to_create,PAJE_EndContainer)],line.word[getPajeFieldPosition(event_to_create,PAJE_Value)],line.word[getPajeFieldPosition(event_to_create,PAJE_Key)]);
		  //	return "PajeEndLink";
			  break;
		  /*case PajeEventIdCount:
        poti_EndLink(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5],line.word[6]);
		  //	return "PajeEventIdCount";
			  break;*/
		  case PajeUnknownEventId:
			  //return "PajeUnknownEventId";
			  break;
		  case PajePushStateMarkEventId:
        poti_PushStateMark(strtod(line.word[getPajeFieldPosition(event_to_create,PAJE_Time)],NULL),line.word[getPajeFieldPosition(event_to_create,PAJE_Container)],line.word[getPajeFieldPosition(event_to_create,PAJE_Type)],line.word[getPajeFieldPosition(event_to_create,PAJE_Value)], atoi(line.word[getPajeFieldPosition(event_to_create,PAJE_Mark)]) );
		  //	return "PajePushState";
			  break;
		  /*case PajeStartLinkSizeEventId:
        poti_StartLinkSize(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5],line.word[6],atoi(line.word[7]));
			  //return "PajeStartLink";
			  break;
		  case PajeStartLinkSizeMarkEventId:
        poti_StartLinkSizeMark(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5],line.word[6],
                                atoi(line.word[7]),atoi(line.word[8]) );
		  //	return "PajeStartLink";
			  break;	*/
		
	  }

}

