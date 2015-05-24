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
#include "poti_events_rastro.h"

static double paje_event_timestamp(double timestamp)
{
  static double first_timestamp = -1;
  if (first_timestamp == -1) {
    first_timestamp = timestamp;
  }
  return timestamp - first_timestamp;
}

extern FILE *paje_file;
extern int paje_extended;
extern int paje_binary;

void poti_DefineContainerType(const char *alias,
                             const char *containerType,
                             const char *name)
{

  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
  fprintf(paje_file,"%d %s %s \"%s\"\n",
         PajeDefineContainerTypeEventId,
         alias,
         containerType,
         name);
  }
  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
  char temp[50];
  sprintf(temp, "\"%s\"", name);
  rst_event_sss(PajeDefineContainerTypeEventId,
		alias,
		containerType,
		temp);
  }
 
 
}

void poti_DefineVariableType(const char *alias,
                             const char *containerType,
                             const char *name,
                             const char *color)
{
  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    fprintf (paje_file,"%d %s %s \"%s\" \"%s\"\n",
             PajeDefineVariableTypeEventId,
             alias,
             containerType,
             name,
             color);
  }
  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    char temp[50];
    sprintf(temp, "\"%s\"", name);
    char temp2[50];
    sprintf(temp2, "\"%s\"", color);
    rst_event_ssss( PajeDefineVariableTypeEventId,
		    alias,
		    containerType,
		    temp,
		    temp2);
  }
}

void poti_DefineStateType(const char *alias,
                         const char *containerType,
                         const char *name)
{
  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    fprintf(paje_file,"%d %s %s \"%s\"\n",
           PajeDefineStateTypeEventId,
           alias,
           containerType,
           name);
  }
  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    char temp[50];
    sprintf(temp, "\"%s\"", name);

    rst_event_sss(PajeDefineStateTypeEventId,
	    alias,
	    containerType,
	    temp);
  }
}

void poti_DefineEventType(const char *alias,
                          const char *containerType,
                          const char *name)
{
  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    fprintf(paje_file,"%d %s %s \"%s\"\n",
            PajeDefineEventTypeEventId,
            alias,
            containerType,
            name);
  }
  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    char temp[50];
    sprintf(temp, "\"%s\"", name);

    rst_event_sss(PajeDefineEventTypeEventId,alias,containerType,temp);
  }
}

void poti_DefineLinkType(const char *alias,
                        const char *containerType,
                        const char *startContainerType,
                        const char *endContainerType,
                        const char *name)
{
  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    fprintf(paje_file,"%d %s %s %s %s \"%s\"\n",
           PajeDefineLinkTypeEventId,
           alias,
           containerType,
           startContainerType,
           endContainerType,
           name);
  }
  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    char temp[50];
      sprintf(temp, "\"%s\"", name);
    rst_event_sssss(PajeDefineLinkTypeEventId,
        alias,
        containerType,
        startContainerType,
        endContainerType,
        temp);
  }
}

void poti_DefineEntityValue(const char *alias,
                           const char *entityType,
                           const char *name,
                           const char *color)
{
  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    fprintf(paje_file,"%d %s %s \"%s\" \"%s\"\n",
            PajeDefineEntityValueEventId,
            alias,
            entityType,
            name,
            color);
  }
  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {  
    char temp[50];
    sprintf(temp, "\"%s\"", name);
    char temp2[50];
    sprintf(temp2, "\"%s\"", color);
    rst_event_ssss(PajeDefineEntityValueEventId,
		    alias,
		    entityType,
		    temp,
		    temp2);
  }
}

void poti_CreateContainer(double timestamp,
                         const char *alias,
                         const char *type,
                         const char *container,
                         const char *name)
{
  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    fprintf(paje_file,"%d %.9f %s %s %s \"%s\"\n",
           PajeCreateContainerEventId,
           paje_event_timestamp(timestamp),
           alias,
           type,
           container,
           name);
  }
  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    char temp[50];
    sprintf(temp, "\"%s\"", name);
    rst_event_dssss(PajeCreateContainerEventId,
             paje_event_timestamp(timestamp),
             alias,
             type,
             container,
             temp);
  }
}

void poti_DestroyContainer(double timestamp,
                          const char *type,
                          const char *container)
{
  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    fprintf(paje_file,"%d %.9f %s %s\n",
           PajeDestroyContainerEventId,
           paje_event_timestamp(timestamp),
           type,
           container);
  }
  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    rst_event_dss(PajeDestroyContainerEventId,
             paje_event_timestamp(timestamp),
             type,
             container);
  }

}

void poti_SetVariable (double timestamp,
                       const char *container,
                       const char *type,
                       double value)
{
  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    fprintf(paje_file,"%d %.9f %s %s %f\n",
            PajeSetVariableEventId,
            paje_event_timestamp(timestamp),
            container,
            type,
            value);
  }
  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    rst_event_dssd(PajeSetVariableEventId,
              paje_event_timestamp(timestamp),
              container,
              type,
              value);
  }

}

void poti_AddVariable (double timestamp,
                       const char *container,
                       const char *type,
                       double value)
{
  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    fprintf(paje_file,"%d %.9f %s %s %f\n",
             PajeAddVariableEventId,
            paje_event_timestamp(timestamp),
            container,
            type,
            value);
  }
  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    rst_event_dssd( PajeAddVariableEventId,
              paje_event_timestamp(timestamp),
              container,
              type,
              value);
  }
}

void poti_SubVariable (double timestamp,
                       const char *container,
                       const char *type,
                       double value)
{
  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    fprintf(paje_file,"%d %.9f %s %s %f\n",
            PajeSubVariableEventId,
            paje_event_timestamp(timestamp),
            container,
            type,
            value);
  }
  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    rst_event_dssd(PajeSubVariableEventId,
              paje_event_timestamp(timestamp),
              container,
              type,
              value);
  }

}

void poti_SetState(double timestamp,
                  const char *container,
                  const char *type,
                  const char *value)
{
  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    fprintf(paje_file,"%d %.9f %s %s %s\n",
           PajeSetStateEventId,
           paje_event_timestamp(timestamp),
           container,
           type,
           value);
  }
  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    rst_event_dsss(PajeSetStateEventId,
             paje_event_timestamp(timestamp),
             container,
             type,
             value);
  }

}


void poti_PushState(double timestamp,
                   const char *container,
                   const char *type,
                   const char *value)
{
  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    fprintf(paje_file,"%d %.9f %s %s %s\n",
          PajePushStateEventId,
           paje_event_timestamp(timestamp),
           container,
           type,
           value);
  }
  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    rst_event_dsss(PajePushStateEventId,
             paje_event_timestamp(timestamp),
             container,
             type,
             value);
  }
}

void poti_PushStateMark(double timestamp,
                        const char *container,
                        const char *type,
                        const char *value,
                        const int mark)
{
  if (paje_extended){
    if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
    {
      fprintf(paje_file,"%d %.9f %s %s %s %d\n",
              PajePushStateMarkEventId,
              paje_event_timestamp(timestamp),
              container,
              type,
              value,
              mark);
    }
    if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
    {
      rst_event_dsssi(PajePushStateMarkEventId,
                  paje_event_timestamp(timestamp),
                  container,
                  type,
                  value,
                  mark);
    }
  }else{
    poti_PushState (timestamp, container, type, value);
  }
}

void poti_PopState(double timestamp,
                  const char *container,
                  const char *type)
{
  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    fprintf(paje_file,"%d %.9f %s %s\n",
           PajePopStateEventId,
           paje_event_timestamp(timestamp),
           container,
           type);
  }
  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    rst_event_dss(PajePopStateEventId,
             paje_event_timestamp(timestamp),
             container,
             type);
  }

}

void poti_ResetState(double timestamp,
                   const char *container,
                   const char *type)
{

  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    fprintf(paje_file,"%d %.9f %s %s\n",
          PajeResetStateEventId,
           paje_event_timestamp(timestamp),
           container,
           type);
  }
  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    rst_event_dss(PajeResetStateEventId,
             paje_event_timestamp(timestamp),
             container,
             type);
  }

}

void poti_StartLink(double timestamp,
                   const char *container,
                   const char *type,
                   const char *sourceContainer,
                   const char *value,
                   const char *key)
{
  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
  fprintf(paje_file,"%d %.9f %s %s %s %s %s\n",
         PajeStartLinkEventId,
         paje_event_timestamp(timestamp),
         container,
         type,
         sourceContainer,
         value,
         key);
  }
  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    rst_event_dsssss(PajeStartLinkEventId,
             paje_event_timestamp(timestamp),
             container,
             type,
             sourceContainer,
             value,
             key);
  }

}

void poti_StartLinkSize(double timestamp,
                        const char *container,
                        const char *type,
                        const char *sourceContainer,
                        const char *value,
                        const char *key,
                        const int size)
{
  if (paje_extended){
    if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
    {
      fprintf(paje_file,"%d %.9f %s %s %s %s %s %d\n",
              PajeStartLinkSizeEventId,
              paje_event_timestamp(timestamp),
              container,
              type,
              sourceContainer,
              value,
              key,
              size);
    }
   if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
    {   
      rst_event_dsssssi(PajeStartLinkSizeEventId,
                  paje_event_timestamp(timestamp),
                  container,
                  type,
                  sourceContainer,
                  value,
                  key,
                  size);
    }

  }else{
    poti_StartLink (timestamp, container, type, sourceContainer, value, key);
  }
}

void poti_StartLinkSizeMark(double timestamp,
                            const char *container,
                            const char *type,
                            const char *sourceContainer,
                            const char *value,
                            const char *key,
                            const int size,
                            const int mark)
{
  if (paje_extended){
    if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
    {
      fprintf(paje_file,"%d %.9f %s %s %s %s %s %d %d\n",
              PajeStartLinkSizeMarkEventId,
              paje_event_timestamp(timestamp),
              container,
              type,
              sourceContainer,
              value,
              key,
              size,
              mark);
    }
    if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
   {
    rst_event_dsssssii(PajeStartLinkSizeMarkEventId,
                paje_event_timestamp(timestamp),
                container,
                type,
                sourceContainer,
                value,
                key,
                size,
                mark);
  }

  }else{
    poti_StartLink (timestamp, container, type, sourceContainer, value, key);
  }
}

void poti_EndLink(double timestamp,
                 const char *container,
                 const char *type,
                 const char *endContainer,
                 const char *value,
                 const char *key)
{
  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    fprintf(paje_file,"%d %.9f %s %s %s %s %s\n",
           PajeEndLinkEventId,
           paje_event_timestamp(timestamp),
           container,
           type,
           endContainer,
           value,
           key);
  }

  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    rst_event_dsssss(PajeEndLinkEventId,
             paje_event_timestamp(timestamp),
             container,
             type,
             endContainer,
             value,
             key);
  }

}

void poti_NewEvent(double timestamp,
                 const char *container,
                 const char *type,
                 const char *value )
{
  if(paje_binary == POTI_TEXTUAL_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    fprintf(paje_file,"%d %.9f %s %s %s\n",
           PajeNewEventEventId,
           paje_event_timestamp(timestamp),
           container,
           type,
           value);
  }

  if(paje_binary == POTI_BINARY_OUTPUT || paje_binary == POTI_TEXTUAL_BINARY_OUTPUT)
  {
    rst_event_dsss(PajeNewEventEventId,
             paje_event_timestamp(timestamp),
             container,
             type,
             value);
  }

}
