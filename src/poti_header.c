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


#include "poti_private.h"
//#include "libpaje/PajeDefinitions.h"

extern FILE *paje_file;
extern int paje_extended;




/*TODO
	remove enums from the header
	and use the PajeDefinitions

*/
typedef enum {
  PajeDefineContainerTypeEventId,
  PajeDefineEventTypeEventId,
  PajeDefineStateTypeEventId,
  PajeDefineVariableTypeEventId,
  PajeDefineLinkTypeEventId,
  PajeDefineEntityValueEventId,
  PajeCreateContainerEventId,
  PajeDestroyContainerEventId,
  PajeNewEventEventId,
  PajeSetStateEventId,
  PajePushStateEventId,
  PajePopStateEventId,
  PajeResetStateEventId,
  PajeSetVariableEventId,
  PajeAddVariableEventId,
  PajeSubVariableEventId,
  PajeStartLinkEventId,
  PajeEndLinkEventId,
  PajeEventIdCount,
  PajeUnknownEventId,
} PajeEventId;

typedef enum {
  PAJE_Event,
  PAJE_Time,
  PAJE_Name,
  PAJE_Type,
  PAJE_Container,
  PAJE_StartContainerType,
  PAJE_EndContainerType,
  PAJE_StartContainer,
  PAJE_EndContainer,
  PAJE_Value,
  PAJE_Key,
  PAJE_Alias,
  PAJE_Color,
  PAJE_Line,
  PAJE_File,
  PAJE_Extra, //for user-defined fields
  PAJE_Unknown_Field
} PajeField;








static void poti_header_PajeDefineContainerType (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeDefineContainerType %d\n", PAJE_DefineContainerType);
  fprintf(paje_file, "%%       Alias string\n");
  if (old_header){
    fprintf(paje_file, "%%       ContainerType string\n");
	/*
rst_event_iiii(PajeDefineContainerTypeEventId,
		PAJE_DefineContainerType,
		PAJE_Alias,
		PAJE_Container
		PAJE_Name);
*/

  }else{
    fprintf(paje_file, "%%       Type string\n");
		/*
rst_event_iiii(PajeDefineContainerTypeEventId,
		PAJE_DefineContainerType,
		PAJE_Alias,
		PAJE_Type,
		PAJE_Name);
*/
  }
  fprintf(paje_file, "%%       Name string\n");
  fprintf(paje_file, "%%EndEventDef\n");


}

static void poti_header_PajeDefineVariableType (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeDefineVariableType %d\n", PAJE_DefineVariableType);
  fprintf(paje_file, "%%       Alias string\n");
  if (old_header){
    fprintf(paje_file, "%%       ContainerType string\n");
	/*rst_event_iiiii(PajeDefineVariableTypeEventId,
		PAJE_DefineVariableType,
		PAJE_Alias,
		PAJE_Container,
		PAJE_Name,
		PAJE_Color);


*/
  }else{
    fprintf(paje_file, "%%       Type string\n");
/*rst_event_iiiii(PajeDefineVariableTypeEventId,
		PAJE_DefineVariableType,
		PAJE_Alias,
		PAJE_Container,
		PAJE_Name,
		PAJE_Color);

*/
  }
  fprintf(paje_file, "%%       Name string\n");
  fprintf(paje_file, "%%       Color color\n");
  fprintf(paje_file, "%%EndEventDef\n");




}

static void poti_header_PajeDefineStateType (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeDefineStateType %d\n", PAJE_DefineStateType);
  fprintf(paje_file, "%%       Alias string\n");
  if (old_header){
    fprintf(paje_file, "%%       ContainerType string\n");
/*rst_event_iiii(PajeDefineStateTypeEventId,
		PAJE_DefineStateType,
		PAJE_Alias,
		PAJE_Container,
		PAJE_Name);

*/
  }else{
    fprintf(paje_file, "%%       Type string\n");
/*rst_event_iiii(PajeDefineStateTypeEventId,
		PAJE_DefineStateType,
		PAJE_Alias,
		PAJE_Type,
		PAJE_Name);

*/
  }
  fprintf(paje_file, "%%       Name string\n");
  fprintf(paje_file, "%%EndEventDef\n");


}

static void poti_header_PajeDefineEventType (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeDefineEventType %d\n", PAJE_DefineEventType);
  fprintf(paje_file, "%%       Alias string\n");
  if (old_header){
    fprintf(paje_file, "%%       ContainerType string\n");
/*rst_event_iiii(PajeDefineEventTypeEventId,
		PAJE_DefineEventType,
		PAJE_Alias,
		PAJE_Container,
		PAJE_Name);
*/
  }else{
    fprintf(paje_file, "%%       Types string\n");
/*rst_event_iiii(PajeDefineEventTypeEventId,
		PAJE_DefineEventType,
		PAJE_Alias,
		PAJE_Type,
		PAJE_Name);
*/
  }
  fprintf(paje_file, "%%       Name string\n");
  fprintf(paje_file, "%%EndEventDef\n");


}

static void poti_header_PajeDefineLinkType (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeDefineLinkType %d\n", PAJE_DefineLinkType);
  fprintf(paje_file, "%%       Alias string\n");
  if (old_header){
    fprintf(paje_file, "%%       ContainerType string\n");
    fprintf(paje_file, "%%       SourceContainerType string\n");
    fprintf(paje_file, "%%       DestContainerType string\n");

	/*rst_event_iiiiiii(PajeDefineLinkTypeEventId,
		PAJE_DefineLinkType,
		PAJE_Alias,
		PAJE_Container,
		PAJE_Container,
		PAJE_Container,
		PAJE_Name);
*/
  }else{
    fprintf(paje_file, "%%       Type string\n");
    fprintf(paje_file, "%%       StartContainerType string\n");
    fprintf(paje_file, "%%       EndContainerType string\n");

/*rst_event_iiiiiii(PajeDefineLinkTypeEventId,
		PAJE_DefineLinkType,
		PAJE_Alias,
		PAJE_Type,
		PAJE_StartContainerType,
		PAJE_EndContainerType,
		PAJE_Name);
*/
  }
  fprintf(paje_file, "%%       Name string\n");
  fprintf(paje_file, "%%EndEventDef\n");




}

static void poti_header_PajeDefineEntityValue (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeDefineEntityValue %d\n", PAJE_DefineEntityValue);
  fprintf(paje_file, "%%       Alias string\n");
  if (old_header){
    fprintf(paje_file, "%%       EntityType string\n");
	/*rst_event_iiiii(PajeDefineEntityValueEventId,
		PAJE_DefineEntityValue,
		PAJE_Alias,
		PAJE_Container,
		PAJE_Name,
		PAJE_Color);
*/
  }else{
    fprintf(paje_file, "%%       Type string\n");
	/*rst_event_iiiii(PajeDefineEntityValueEventId,
		PAJE_DefineEntityValue,
		PAJE_Alias,
		PAJE_Type,
		PAJE_Name,
		PAJE_Color);
*/
  }
  fprintf(paje_file, "%%       Name string\n");
  fprintf(paje_file, "%%       Color color\n");
  fprintf(paje_file, "%%EndEventDef\n");

 

}

static void poti_header_PajeCreateContainer (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeCreateContainer %d\n", PAJE_CreateContainer);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Alias string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Name string\n");
  fprintf(paje_file, "%%EndEventDef\n");
 /*rst_event_iiiiii(PajeCreateContainerEventId,
		PAJE_CreateContainer,
		PAJE_Time,
		PAJE_Alias,
		PAJE_Type,
		PAJE_Container,
		Paje_Name);
*/
}

static void poti_header_PajeDestroyContainer (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeDestroyContainer %d\n", PAJE_DestroyContainer);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Name string\n");
  fprintf(paje_file, "%%EndEventDef\n");
/*rst_event_iiii(PajeDestroyContainerEventId,
		PAJE_DestroyContainer,
		PAJE_Time,
		PAJE_Type,
		Paje_Name);
*/
}

static void poti_header_PajeSetVariable (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeSetVariable %d\n", PAJE_SetVariable);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Value double\n");
  fprintf(paje_file, "%%EndEventDef\n");
/*rst_event_iiiii(PajeSetVariableEventId,
		PAJE_SetVariable,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		Paje_Value);
*/
}

static void poti_header_PajeAddVariable (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeAddVariable %d\n", PAJE_AddVariable);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Value double\n");
  fprintf(paje_file, "%%EndEventDef\n");

/*rst_event_iiiii(PajeAddVariableEventId,
		PAJE_AddVariable,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		Paje_Value);
*/
}

static void poti_header_PajeSubVariable (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeSubVariable %d\n", PAJE_SubVariable);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Value double\n");
  fprintf(paje_file, "%%EndEventDef\n");
/*rst_event_iiiii(PajeSubVariableEventId,
		PAJE_SubVariable,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		Paje_Value);
*/
}


static void poti_header_PajeSetState (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeSetState %d\n", PAJE_SetState);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Value string\n");
  fprintf(paje_file, "%%EndEventDef\n");

/*rst_event_iiiii(PajeSetStateEventId,
		PAJE_SetState,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		Paje_Value);
*/
}

static void poti_header_PajePushState (int old_header)
{
  fprintf(paje_file, "%%EventDef PajePushState %d\n", PAJE_PushState);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Value string\n");
  fprintf(paje_file, "%%EndEventDef\n");
/*rst_event_iiiii(PajePushStateEventId,
		PAJE_PushState,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		Paje_Value);
*/
}

static void poti_header_PajePushStateMark (int old_header)
{
  fprintf(paje_file, "%%EventDef PajePushState %d\n", PAJE_PushStateMark);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Value string\n");
  fprintf(paje_file, "%%       Mark string\n");
  fprintf(paje_file, "%%EndEventDef\n");
/*rst_event_iiiiii(PajePushStateEventId,
		PAJE_PushState,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		Paje_Value,
		PAJE_Extra);
*/
}

static void poti_header_PajePopState (int old_header)
{
  fprintf(paje_file, "%%EventDef PajePopState %d\n", PAJE_PopState);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%EndEventDef\n");
/*rst_event_iiiii(PajePopStateEventId,
		PAJE_PopState,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type);
*/
}

static void poti_header_PajeResetState (int old_header)
{
  if (old_header) return;

  fprintf(paje_file, "%%EventDef PajeResetState %d\n", PAJE_ResetState);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%EndEventDef\n");

/*rst_event_iiii(PajeResetStateEventId,
		PAJE_ResetState,
		PAJE_Time,
		PAJE_Type,
		PAJE_Container);
*/
}

static void poti_header_PajeStartLink (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeStartLink %d\n", PAJE_StartLink);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  if (old_header){
    fprintf(paje_file, "%%       SourceContainer string\n");
  }else{
    fprintf(paje_file, "%%       StartContainer string\n");
  }
  fprintf(paje_file, "%%       Value string\n");
  fprintf(paje_file, "%%       Key string\n");
  fprintf(paje_file, "%%EndEventDef\n");

/*
	if(old_header)
{
	/*rst_event_iiiiiii(PajeStartLinkEventId,
		PAJE_StartLink,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_Container,
		PAJE_Value,
		PAJE_Key);

}
else
{
	rst_event_iiiiiii(PajeStartLinkEventId,
		PAJE_StartLink,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_StartContainer,
		PAJE_Value,
		PAJE_Key);
}
*/
}

static void poti_header_PajeStartLinkSize (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeStartLink %d\n", PAJE_StartLinkSize);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  if (old_header){
    fprintf(paje_file, "%%       SourceContainer string\n");
  }else{
    fprintf(paje_file, "%%       StartContainer string\n");
  }
  fprintf(paje_file, "%%       Value string\n");
  fprintf(paje_file, "%%       Key string\n");
  fprintf(paje_file, "%%       Size double\n");
  fprintf(paje_file, "%%EndEventDef\n");

	/*
	if(old_header)
{
	/*rst_event_iiiiiii(PajeStartLinkEventId,
		PAJE_StartLinkSize,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_Container,
		PAJE_Value,
		PAJE_Key);

}
else
{
	rst_event_iiiiiii(PajeStartLinkEventId,
		PAJE_StartLinkSize,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_StartContainer,
		PAJE_Value,
		PAJE_Key);
}
*/
}


static void poti_header_PajeStartLinkSizeMark (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeStartLink %d\n", PAJE_StartLinkSizeMark);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  if (old_header){
    fprintf(paje_file, "%%       SourceContainer string\n");
  }else{
    fprintf(paje_file, "%%       StartContainer string\n");
  }
  fprintf(paje_file, "%%       Value string\n");
  fprintf(paje_file, "%%       Key string\n");
  fprintf(paje_file, "%%       Size double\n");
  fprintf(paje_file, "%%       Mark string\n");
  fprintf(paje_file, "%%EndEventDef\n");


/*
	if(old_header)
{
	/*rst_event_iiiiiii(PajeStartLinkEventId,
		PAJE_StartLinkSizeMark,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_Container,
		PAJE_Value,
		PAJE_Key);

}
else
{
	rst_event_iiiiiii(PajeStartLinkEventId,
		PAJE_StartLinkSizeMark,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_StartContainer,
		PAJE_Value,
		PAJE_Key);
}
*/
}

static void poti_header_PajeEndLink (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeEndLink %d\n", PAJE_EndLink);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  if (old_header){
    fprintf(paje_file, "%%       DestContainer string\n");
  }else{
    fprintf(paje_file, "%%       EndContainer string\n");
  }
  fprintf(paje_file, "%%       Value string\n");
  fprintf(paje_file, "%%       Key string\n");
  fprintf(paje_file, "%%EndEventDef\n");

 /*
	if(old_header)
{
	/*rst_event_iiiiiii(PajeEndLinkEventId,
		PAJE_EndLink,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_Container,
		PAJE_Value,
		PAJE_Key);

}
else
{
	rst_event_iiiiiii(PajeEndLinkEventId,
		PAJE_EndLink,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_EndContainer,
		PAJE_Value,
		PAJE_Key);
}
*/

}

static void poti_header_PajeNewEvent (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeNewEvent %d\n", PAJE_NewEvent);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Value string\n");
  fprintf(paje_file, "%%EndEventDef\n");

/*
rst_event_iiiii(PajeNewEventEventId,
		PAJE_NewEvent,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_Value);
*/
}

/* entry point */
void _poti_header(int basic, int old_header)
{
  poti_header_PajeDefineContainerType (old_header);
  poti_header_PajeDefineVariableType (old_header);
  poti_header_PajeDefineStateType (old_header);
  poti_header_PajeDefineEventType (old_header);
  poti_header_PajeDefineLinkType (old_header);
  poti_header_PajeDefineEntityValue (old_header);
  poti_header_PajeCreateContainer (old_header);
  poti_header_PajeDestroyContainer (old_header);
  poti_header_PajeSetVariable (old_header);
  poti_header_PajeAddVariable (old_header);
  poti_header_PajeSubVariable (old_header);
  poti_header_PajeSetState (old_header);
  poti_header_PajePushState (old_header);
  poti_header_PajePopState (old_header);
  poti_header_PajeResetState (old_header);
  poti_header_PajeStartLink (old_header);
  poti_header_PajeEndLink (old_header);
  poti_header_PajeNewEvent (old_header);

  if (basic){
    paje_extended = 0;
    fprintf (paje_file,
             "#\n"
             "# Trace created without extended events\n"
             "#\n");
   //rst_event_s(21,"# Trace created without extended events");
    return;
  }else{
    paje_extended = 1;
  }

  fprintf(paje_file,
          "#\n"
          "# Extended events with additional information\n"
          "# Note that not all paje file format parsers support this\n"
          "# If you have problems parsing this file with your visualization tool\n"
          "#\n");
//rst_event_s(21,"#Extended events with additional information");

  poti_header_PajePushStateMark (old_header);
  poti_header_PajeStartLinkSize (old_header);
  poti_header_PajeStartLinkSizeMark (old_header);
}
