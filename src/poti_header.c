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
#include "poti_header_rastro.h"
#include "poti_events_rastro.h"
//#include "libpaje/PajeDefinitions.h"

extern FILE *paje_file;
extern int paje_extended;




/*TODO
	remove enums from the header
	and use the PajeDefinitions

*/







static void poti_header_PajeDefineContainerType (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeDefineContainerType %d\n", PajeDefineContainerTypeEventId);
  fprintf(paje_file, "%%       Alias string\n");
  if (old_header){
    fprintf(paje_file, "%%       ContainerType string\n");


  }else{
    fprintf(paje_file, "%%       Type string\n");
  }
  fprintf(paje_file, "%%       Name string\n");
  fprintf(paje_file, "%%EndEventDef\n");

  rst_event_iiii(PajeHeaderEventId,
		PajeDefineContainerTypeEventId,
		PAJE_Alias,
		PAJE_Type,
		PAJE_Name);

}

static void poti_header_PajeDefineVariableType (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeDefineVariableType %d\n", PajeDefineVariableTypeEventId);
  fprintf(paje_file, "%%       Alias string\n");
  if (old_header){
    fprintf(paje_file, "%%       ContainerType string\n");
  }else{
    fprintf(paje_file, "%%       Type string\n");
  }
  fprintf(paje_file, "%%       Name string\n");
  fprintf(paje_file, "%%       Color color\n");
  fprintf(paje_file, "%%EndEventDef\n");

  rst_event_iiiii(PajeHeaderEventId,
		PajeDefineVariableTypeEventId,
		PAJE_Alias,
		PAJE_Container,
		PAJE_Name,
		PAJE_Color);


}

static void poti_header_PajeDefineStateType (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeDefineStateType %d\n", PajeDefineStateTypeEventId);
  fprintf(paje_file, "%%       Alias string\n");
  if (old_header){
    fprintf(paje_file, "%%       ContainerType string\n");
  }else{
    fprintf(paje_file, "%%       Type string\n");
  }
  fprintf(paje_file, "%%       Name string\n");
  fprintf(paje_file, "%%EndEventDef\n");

  rst_event_iiii(PajeDefineStateTypeEventId,
		PajeDefineStateTypeEventId,
		PAJE_Alias,
		PAJE_Type,
		PAJE_Name);


}

static void poti_header_PajeDefineEventType (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeDefineEventType %d\n", PajeDefineEventTypeEventId);
  fprintf(paje_file, "%%       Alias string\n");
  if (old_header){
    fprintf(paje_file, "%%       ContainerType string\n");
  }else{
    fprintf(paje_file, "%%       Types string\n");
  }
  fprintf(paje_file, "%%       Name string\n");
  fprintf(paje_file, "%%EndEventDef\n");
  
  rst_event_iiii(PajeHeaderEventId,
		PajeDefineEventTypeEventId,
		PAJE_Alias,
		PAJE_Type,
		PAJE_Name);


}

static void poti_header_PajeDefineLinkType (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeDefineLinkType %d\n", PajeDefineLinkTypeEventId);
  fprintf(paje_file, "%%       Alias string\n");
  if (old_header){
    fprintf(paje_file, "%%       ContainerType string\n");
    fprintf(paje_file, "%%       SourceContainerType string\n");
    fprintf(paje_file, "%%       DestContainerType string\n");
  }else{
    fprintf(paje_file, "%%       Type string\n");
    fprintf(paje_file, "%%       StartContainerType string\n");
    fprintf(paje_file, "%%       EndContainerType string\n");
  }
  fprintf(paje_file, "%%       Name string\n");
  fprintf(paje_file, "%%EndEventDef\n");

  rst_event_iiiiii(PajeHeaderEventId,
			PajeDefineLinkTypeEventId,
			PAJE_Alias,
			PAJE_Type,
			PAJE_StartContainerType,
			PAJE_EndContainerType,
			PAJE_Name);





}

static void poti_header_PajeDefineEntityValue (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeDefineEntityValue %d\n", PajeDefineEntityValueEventId);
  fprintf(paje_file, "%%       Alias string\n");
  if (old_header){
    fprintf(paje_file, "%%       EntityType string\n");
  }else{
    fprintf(paje_file, "%%       Type string\n");
  }
  fprintf(paje_file, "%%       Name string\n");
  fprintf(paje_file, "%%       Color color\n");
  fprintf(paje_file, "%%EndEventDef\n");

  rst_event_iiiii(PajeHeaderEventId,
		PajeDefineEntityValueEventId,
		PAJE_Alias,
		PAJE_Type,
		PAJE_Name,
		PAJE_Color);

 

}

static void poti_header_PajeCreateContainer (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeCreateContainer %d\n", PajeCreateContainerEventId);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Alias string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Name string\n");
  fprintf(paje_file, "%%EndEventDef\n");
  rst_event_iiiiii(PajeHeaderEventId,
		PajeCreateContainerEventId,
		PAJE_Time,
		PAJE_Alias,
		PAJE_Type,
		PAJE_Container,
		PAJE_Name);

}

static void poti_header_PajeDestroyContainer (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeDestroyContainer %d\n", PajeDestroyContainerEventId);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Name string\n");
  fprintf(paje_file, "%%EndEventDef\n");
  rst_event_iiii(PajeHeaderEventId,
		PajeDestroyContainerEventId,
		PAJE_Time,
		PAJE_Type,
		PAJE_Name);

}

static void poti_header_PajeSetVariable (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeSetVariable %d\n", PajeSetVariableEventId);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Value double\n");
  fprintf(paje_file, "%%EndEventDef\n");
  rst_event_iiiii(PajeHeaderEventId,
		PajeSetVariableEventId,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_Value);

}

static void poti_header_PajeAddVariable (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeAddVariable %d\n", PajeAddVariableEventId);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Value double\n");
  fprintf(paje_file, "%%EndEventDef\n");

  rst_event_iiiii(PajeHeaderEventId,
		PajeAddVariableEventId,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_Value);

}

static void poti_header_PajeSubVariable (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeSubVariable %d\n", PajeSubVariableEventId);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Value double\n");
  fprintf(paje_file, "%%EndEventDef\n");

  rst_event_iiiii(PajeHeaderEventId,
		PajeSubVariableEventId,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_Value);

}


static void poti_header_PajeSetState (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeSetState %d\n", PajeSetStateEventId);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Value string\n");
  fprintf(paje_file, "%%EndEventDef\n");

  rst_event_iiiii(PajeHeaderEventId,
		PajeSetStateEventId,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_Value);

}

static void poti_header_PajePushState (int old_header)
{
  fprintf(paje_file, "%%EventDef PajePushState %d\n", PajePushStateEventId);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Value string\n");
  fprintf(paje_file, "%%EndEventDef\n");
  rst_event_iiiii(PajeHeaderEventId,
		PajePushStateEventId,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_Value);

}

static void poti_header_PajePushStateMark (int old_header)
{
  fprintf(paje_file, "%%EventDef PajePushState %d\n", PajePushStateEventId);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Value string\n");
  fprintf(paje_file, "%%       Mark string\n");
  fprintf(paje_file, "%%EndEventDef\n");
  rst_event_iiiiii(PajeHeaderEventId,
		PajePushStateEventId,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_Value,
		PAJE_Extra);

}

static void poti_header_PajePopState (int old_header)
{
  fprintf(paje_file, "%%EventDef PajePopState %d\n", PajePopStateEventId);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%EndEventDef\n");
  rst_event_iiii(PajeHeaderEventId,
		PajePopStateEventId,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type);

}

static void poti_header_PajeResetState (int old_header)
{
  if (old_header) return;

  fprintf(paje_file, "%%EventDef PajeResetState %d\n", PajeResetStateEventId);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%EndEventDef\n");

  rst_event_iiii(PajeHeaderEventId,
		PajeResetStateEventId,
		PAJE_Time,
		PAJE_Type,
		PAJE_Container);

}

static void poti_header_PajeStartLink (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeStartLink %d\n", PajeStartLinkEventId);
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

  rst_event_iiiiiii(PajeHeaderEventId,
		PajeStartLinkEventId,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_StartContainer,
		PAJE_Value,
		PAJE_Key);


}

static void poti_header_PajeStartLinkSize (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeStartLink %d\n", PajeStartLinkEventId);
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


  rst_event_iiiiiii(PajeHeaderEventId,
		PajeStartLinkEventId,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_StartContainer,
		PAJE_Value,
		PAJE_Key);


}


static void poti_header_PajeStartLinkSizeMark (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeStartLink %d\n", PajeStartLinkEventId);
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



  rst_event_iiiiiii(PajeHeaderEventId,
		PajeStartLinkEventId,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_StartContainer,
		PAJE_Value,
		PAJE_Key);


}

static void poti_header_PajeEndLink (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeEndLink %d\n", PajeEndLinkEventId);
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

  rst_event_iiiiiii(PajeHeaderEventId,
		PajeEndLinkEventId,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_EndContainer,
		PAJE_Value,
		PAJE_Key);



}

static void poti_header_PajeNewEvent (int old_header)
{
  fprintf(paje_file, "%%EventDef PajeNewEvent %d\n", PajeNewEventEventId);
  fprintf(paje_file, "%%       Time date\n");
  fprintf(paje_file, "%%       Container string\n");
  fprintf(paje_file, "%%       Type string\n");
  fprintf(paje_file, "%%       Value string\n");
  fprintf(paje_file, "%%EndEventDef\n");


  rst_event_iiiii(PajeHeaderEventId,
		PajeNewEventEventId,
		PAJE_Time,
		PAJE_Container,
		PAJE_Type,
		PAJE_Value);

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
   rst_event_s(21,"# Trace created without extended events");
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
rst_event_s(21,"#Extended events with additional information");

  poti_header_PajePushStateMark (old_header);
  poti_header_PajeStartLinkSize (old_header);
  poti_header_PajeStartLinkSizeMark (old_header);
}
