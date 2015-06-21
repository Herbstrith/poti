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

short FindStringParam(const char* param);

short FindStringParam(const char* param)
{
  //int string_reference_id = 888;
  short counter = 0;
  if(stringList == NULL){
    stringList = malloc(sizeof(StringParamsList));
    stringList->string = strdup(param);
    stringList->string_position = counter;
    stringList->next = NULL;
    //write the string in the file with and id of 888
   // rst_event_ws(string_reference_id,counter,stringList->string);
    return counter;
  }  

  StringParamsList *actual = stringList;  
  /*int mycounter =0;
  while(actual != NULL){
      actual = actual->next;
      mycounter = mycounter + 1;
  }*/
  actual = stringList;
  while(actual != NULL){
    if(strcmp(actual->string, param) == 0){
      return actual->string_position;
      break;
    }
    if(actual->next == NULL){
      counter = counter + 1;
      break;
    }  
    actual = actual->next;
    counter = counter + 1;
  }
  StringParamsList *new_param = (StringParamsList *)malloc(sizeof(StringParamsList));
  new_param->string = strdup(param);
  new_param->string_position = counter;
  new_param->next = NULL;
  actual->next = new_param;
  //write the string in the file with and id of 888
  //rst_event_ws(string_reference_id,counter,new_param->string);
  return counter;
}

static double paje_event_timestamp(double timestamp)
{
  static double first_timestamp = -1;
  if (first_timestamp == -1) {
    first_timestamp = timestamp;
  }
  return timestamp - first_timestamp;
}

void poti_DefineContainerType(const char *alias,
                             const char *containerType,
                             const char *name)
{

  if(poti_mode & POTI_TEXT){
  fprintf(paje_file,"%d %s %s \"%s\"\n",
         PajeDefineContainerTypeEventId,
         alias,
         containerType,
         name);
  }else if(poti_mode & POTI_BINARY){
    char temp[50];
    sprintf(temp, "\"%s\"", name);
    rst_event_www(PajeDefineContainerTypeEventId,
		              FindStringParam(alias),
		              FindStringParam(containerType),
		              FindStringParam(temp));
  }
}

void poti_DefineVariableType(const char *alias,
                             const char *containerType,
                             const char *name,
                             const char *color)
{
  if(poti_mode & POTI_TEXT){
    fprintf (paje_file,"%d %s %s \"%s\" \"%s\"\n",
             PajeDefineVariableTypeEventId,
             alias,
             containerType,
             name,
             color);
  }else if(poti_mode & POTI_BINARY){
    char temp[50];
    sprintf(temp, "\"%s\"", name);
    char temp2[50];
    sprintf(temp2, "\"%s\"", color);
    rst_event_wwww( PajeDefineVariableTypeEventId,
                  FindStringParam(alias),
                  FindStringParam(containerType),
                  FindStringParam(temp),
                  FindStringParam(temp2));
  }
}

void poti_DefineStateType(const char *alias,
                         const char *containerType,
                         const char *name)
{
  if(poti_mode & POTI_TEXT){
    fprintf(paje_file,"%d %s %s \"%s\"\n",
           PajeDefineStateTypeEventId,
           alias,
           containerType,
           name);
  }else if(poti_mode & POTI_BINARY){
    char temp[50];
    sprintf(temp, "\"%s\"", name);
    rst_event_www(PajeDefineStateTypeEventId,
                  FindStringParam(alias),
                  FindStringParam(containerType),
                  FindStringParam(temp));
  }
}

void poti_DefineEventType(const char *alias,
                          const char *containerType,
                          const char *name)
{
  if(poti_mode & POTI_TEXT){
    fprintf(paje_file,"%d %s %s \"%s\"\n",
            PajeDefineEventTypeEventId,
            alias,
            containerType,
            name);
  }else if(poti_mode & POTI_BINARY){
    char temp[50];
    sprintf(temp, "\"%s\"", name);
    rst_event_www(PajeDefineEventTypeEventId,
                  FindStringParam(alias),    
                  FindStringParam(containerType),   
                  FindStringParam(temp));
  }
}

void poti_DefineLinkType(const char *alias,
                        const char *containerType,
                        const char *startContainerType,
                        const char *endContainerType,
                        const char *name)
{
  if(poti_mode & POTI_TEXT){
    fprintf(paje_file,"%d %s %s %s %s \"%s\"\n",
           PajeDefineLinkTypeEventId,
           alias,
           containerType,
           startContainerType,
           endContainerType,
           name);
  }else if(poti_mode & POTI_BINARY){
    char temp[50];
    sprintf(temp, "\"%s\"", name);
    rst_event_wwwww(PajeDefineLinkTypeEventId,
                  FindStringParam(alias),
                  FindStringParam(containerType),
                  FindStringParam(startContainerType),
                  FindStringParam(endContainerType),
                  FindStringParam(temp));
  }
}

void poti_DefineEntityValue(const char *alias,
                           const char *entityType,
                           const char *name,
                           const char *color)
{
  if(poti_mode & POTI_TEXT){
    fprintf(paje_file,"%d %s %s \"%s\" \"%s\"\n",
            PajeDefineEntityValueEventId,
            alias,
            entityType,
            name,
            color);
  }else if(poti_mode & POTI_BINARY){
    char temp[50];
    sprintf(temp, "\"%s\"", name);
    char temp2[50];
    sprintf(temp2, "\"%s\"", color);
    rst_event_wwww(PajeDefineEntityValueEventId,
                  FindStringParam(alias),
                  FindStringParam(entityType),
                  FindStringParam(temp),
		              FindStringParam(temp2));
  }
}

void poti_CreateContainer(double timestamp,
                         const char *alias,
                         const char *type,
                         const char *container,
                         const char *name)
{
    FindStringParam(name);
  if(poti_mode & POTI_TEXT){
    fprintf(paje_file,"%d %.9f %s %s %s \"%s\"\n",
           PajeCreateContainerEventId,
           paje_event_timestamp(timestamp),
           alias,
           type,
           container,
           name);
  }else if(poti_mode & POTI_BINARY){
    char temp[50];
    sprintf(temp, "\"%s\"", name);
    rst_event_dwwww(PajeCreateContainerEventId,
              paje_event_timestamp(timestamp),
              FindStringParam(alias),
              FindStringParam(type),
              FindStringParam(container),
              FindStringParam(temp));
  }
}

void poti_DestroyContainer(double timestamp,
                          const char *type,
                          const char *container)
{
  if(poti_mode & POTI_TEXT){
    fprintf(paje_file,"%d %.9f %s %s\n",
           PajeDestroyContainerEventId,
           paje_event_timestamp(timestamp),
           type,
           container);
  }else if(poti_mode & POTI_BINARY){
    rst_event_dww(PajeDestroyContainerEventId,
              paje_event_timestamp(timestamp),
              FindStringParam(type),
              FindStringParam(container));
  }

}

void poti_SetVariable (double timestamp,
                       const char *container,
                       const char *type,
                       double value)
{
  if(poti_mode & POTI_TEXT){
    fprintf(paje_file,"%d %.9f %s %s %f\n",
            PajeSetVariableEventId,
            paje_event_timestamp(timestamp),
            container,
            type,
            value);
  }else if(poti_mode & POTI_BINARY){
      rst_event_dwwd(PajeSetVariableEventId,
              paje_event_timestamp(timestamp),
              FindStringParam(container),
              FindStringParam(type),
              value);
  }
}

void poti_AddVariable (double timestamp,
                       const char *container,
                       const char *type,
                       double value)
{
  if(poti_mode & POTI_TEXT){
    fprintf(paje_file,"%d %.9f %s %s %f\n",
             PajeAddVariableEventId,
            paje_event_timestamp(timestamp),
            container,
            type,
            value);
  }else if(poti_mode & POTI_BINARY){
    rst_event_dwwd( PajeAddVariableEventId,
              paje_event_timestamp(timestamp),
              FindStringParam(container),
              FindStringParam(type),
              value);
  }
}

void poti_SubVariable (double timestamp,
                       const char *container,
                       const char *type,
                       double value)
{
  if(poti_mode & POTI_TEXT){
    fprintf(paje_file,"%d %.9f %s %s %f\n",
            PajeSubVariableEventId,
            paje_event_timestamp(timestamp),
            container,
            type,
            value);
  }else if(poti_mode & POTI_BINARY){
    rst_event_dwwd(PajeSubVariableEventId,
              paje_event_timestamp(timestamp),
              FindStringParam(container),
              FindStringParam(type),
              value);
  }
}

void poti_SetState(double timestamp,
                  const char *container,
                  const char *type,
                  const char *value)
{
  if(poti_mode & POTI_TEXT){
    fprintf(paje_file,"%d %.9f %s %s %s\n",
           PajeSetStateEventId,
           paje_event_timestamp(timestamp),
           container,
           type,
           value);
  }else if(poti_mode & POTI_BINARY){
    rst_event_dwww(PajeSetStateEventId,
             paje_event_timestamp(timestamp),
              FindStringParam(container),
            FindStringParam(type),
            FindStringParam(value));
  }
}


void poti_PushState(double timestamp,
                   const char *container,
                   const char *type,
                   const char *value)
{
  if(poti_mode & POTI_TEXT){
    fprintf(paje_file,"%d %.9f %s %s %s\n",
          PajePushStateEventId,
           paje_event_timestamp(timestamp),
           container,
           type,
           value);
  }else if(poti_mode & POTI_BINARY){
    rst_event_dwww(PajePushStateEventId,
             paje_event_timestamp(timestamp),
             FindStringParam(container),
            FindStringParam(type),
            FindStringParam(value)
    );
  }
}

void poti_PushStateMark(double timestamp,
                        const char *container,
                        const char *type,
                        const char *value,
                        const int mark)
{
  if (paje_extended){
    if(poti_mode & POTI_TEXT){
      fprintf(paje_file,"%d %.9f %s %s %s %d\n",
              PajePushStateMarkEventId,
              paje_event_timestamp(timestamp),
              container,
              type,
              value,
              mark);
    }else if(poti_mode & POTI_BINARY){
      rst_event_dwwwi(PajePushStateMarkEventId,
                  paje_event_timestamp(timestamp),
                 FindStringParam(container),
                  FindStringParam(type),
                  FindStringParam(value),
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
  if(poti_mode & POTI_TEXT){
    fprintf(paje_file,"%d %.9f %s %s\n",
           PajePopStateEventId,
           paje_event_timestamp(timestamp),
           container,
           type);
  }else if(poti_mode & POTI_BINARY){
    rst_event_dww(PajePopStateEventId,
             paje_event_timestamp(timestamp),
             FindStringParam(container),
             FindStringParam(type));
  }
}

void poti_ResetState(double timestamp,
                   const char *container,
                   const char *type)
{
  if(poti_mode & POTI_TEXT){
    fprintf(paje_file,"%d %.9f %s %s\n",
          PajeResetStateEventId,
           paje_event_timestamp(timestamp),
           container,
           type);
  }else if(poti_mode & POTI_BINARY){
    rst_event_dww(PajeResetStateEventId,
              paje_event_timestamp(timestamp),
              FindStringParam(container),
              FindStringParam(type));
  }
}

void poti_StartLink(double timestamp,
                   const char *container,
                   const char *type,
                   const char *sourceContainer,
                   const char *value,
                   const char *key)
{
  if(poti_mode & POTI_TEXT){
    fprintf(paje_file,"%d %.9f %s %s %s %s %s\n",
         PajeStartLinkEventId,
         paje_event_timestamp(timestamp),
         container,
         type,
         sourceContainer,
         value,
         key);
  }else if(poti_mode & POTI_BINARY){
    rst_event_dwwwww(PajeStartLinkEventId,
              paje_event_timestamp(timestamp),
              FindStringParam(container),
              FindStringParam(type),
              FindStringParam(sourceContainer),
              FindStringParam(value),
              FindStringParam(key));
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
    if(poti_mode & POTI_TEXT){
      fprintf(paje_file,"%d %.9f %s %s %s %s %s %d\n",
              PajeStartLinkSizeEventId,
              paje_event_timestamp(timestamp),
              container,
              type,
              sourceContainer,
              value,
              key,
              size);
    }else if(poti_mode & POTI_BINARY){
      rst_event_dwwwwwi(PajeStartLinkSizeEventId,
                  paje_event_timestamp(timestamp),
                  FindStringParam(container),
                  FindStringParam(type),
                  FindStringParam(sourceContainer),
                  FindStringParam(value),
                  FindStringParam(key),
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
    if(poti_mode & POTI_TEXT){
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
    }else if(poti_mode & POTI_BINARY){
      rst_event_dwwwwwii(PajeStartLinkSizeMarkEventId,
                paje_event_timestamp(timestamp),
                FindStringParam(container),
                FindStringParam(type),
                FindStringParam(sourceContainer),
                FindStringParam(value),
                FindStringParam(key),
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
  if(poti_mode & POTI_TEXT){
    fprintf(paje_file,"%d %.9f %s %s %s %s %s\n",
           PajeEndLinkEventId,
           paje_event_timestamp(timestamp),
           container,
           type,
           endContainer,
           value,
           key);
  }else if(poti_mode & POTI_BINARY){
    rst_event_dwwwww(PajeEndLinkEventId,
             paje_event_timestamp(timestamp),
             FindStringParam(container),
              FindStringParam(type),
              FindStringParam(endContainer),
              FindStringParam(value),
              FindStringParam(key));
  }
}

void poti_NewEvent(double timestamp,
                 const char *container,
                 const char *type,
                 const char *value )
{
  if(poti_mode & POTI_TEXT){
    fprintf(paje_file,"%d %.9f %s %s %s\n",
           PajeNewEventEventId,
           paje_event_timestamp(timestamp),
           container,
           type,
           value);
  }else if(poti_mode & POTI_BINARY){
    rst_event_dwww(PajeNewEventEventId,
             paje_event_timestamp(timestamp),
            FindStringParam(container),
            FindStringParam(type),
            FindStringParam(value));
  }
}
