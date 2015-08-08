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
  int string_reference_id = 888;
  short counter = 0;
  if(stringList == NULL){
    stringList = malloc(sizeof(StringParamsList));
    stringList->string = strdup(param);
    stringList->string_position = counter;
    stringList->next = NULL;
    //write the string in the file with and id of 888
    rst_event_s(string_reference_id,stringList->string);
    return counter;
  }  

  StringParamsList *actual = stringList;  

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
  rst_event_s(string_reference_id,new_param->string);
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
    #ifdef STRING_REFERENCE
      rst_event_www(PajeDefineContainerTypeEventId,
		                FindStringParam(alias),
		                FindStringParam(containerType),
		                FindStringParam(temp));
    #else
      rst_event_sss(PajeDefineContainerTypeEventId,
		                alias,
		                containerType,
		                temp);
    #endif
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
    
    #ifdef STRING_REFERENCE
      rst_event_wwww( PajeDefineVariableTypeEventId,
                    FindStringParam(alias),
                    FindStringParam(containerType),
                    FindStringParam(temp),
                    FindStringParam(temp2));
    #else
     rst_event_ssss( PajeDefineVariableTypeEventId,
		                alias,
		                containerType,
		                temp,
		                temp2);
    #endif
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
    #ifdef STRING_REFERENCE
      rst_event_www(PajeDefineStateTypeEventId,
                    FindStringParam(alias),
                    FindStringParam(containerType),
                    FindStringParam(temp));
    #else
      rst_event_sss(PajeDefineStateTypeEventId,
	                  alias,
	                  containerType,
	                  temp);
    #endif
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
    #ifdef STRING_REFERENCE
      rst_event_www(PajeDefineEventTypeEventId,
                    FindStringParam(alias),    
                    FindStringParam(containerType),   
                    FindStringParam(temp));
    #else
      rst_event_sss(PajeDefineEventTypeEventId,
                    alias,
                    containerType,
                    temp);
    #endif
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
    #ifdef STRING_REFERENCE
      rst_event_wwwww(PajeDefineLinkTypeEventId,
                      FindStringParam(alias),
                      FindStringParam(containerType),
                      FindStringParam(startContainerType),
                      FindStringParam(endContainerType),
                      FindStringParam(temp));
    #else
      rst_event_sssss(PajeDefineLinkTypeEventId,
                      alias,
                      containerType,
                      startContainerType,
                      endContainerType,
                      temp);
    #endif
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
    #ifdef STRING_REFERENCE
      rst_event_wwww(PajeDefineEntityValueEventId,
                    FindStringParam(alias),
                    FindStringParam(entityType),
                    FindStringParam(temp),
		                FindStringParam(temp2));
    #else
      rst_event_ssss(PajeDefineEntityValueEventId,
		                alias,
		                entityType,
		                temp,
		                temp2);
    #endif
  }
}

void poti_CreateContainer(double timestamp,
                         const char *alias,
                         const char *type,
                         const char *container,
                         const char *name)
{
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
    #ifdef STRING_REFERENCE
      rst_event_dwwww(PajeCreateContainerEventId,
                      paje_event_timestamp(timestamp),
                      FindStringParam(alias),
                      FindStringParam(type),
                      FindStringParam(container),
                      FindStringParam(temp));
    #else
      rst_event_dssss(PajeCreateContainerEventId,
                     paje_event_timestamp(timestamp),
                     alias,
                     type,
                     container,
                     temp);
    #endif
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
    #ifdef STRING_REFERENCE
      rst_event_dww(PajeDestroyContainerEventId,
                    paje_event_timestamp(timestamp),
                    FindStringParam(type),
                    FindStringParam(container));
    #else
      rst_event_dss(PajeDestroyContainerEventId,
                   paje_event_timestamp(timestamp),
                   type,
                   container);
    #endif
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
    #ifdef STRING_REFERENCE
      rst_event_dwwd(PajeSetVariableEventId,
                    paje_event_timestamp(timestamp),
                    FindStringParam(container),
                    FindStringParam(type),
                    value);
    #else
      rst_event_dssd(PajeSetVariableEventId,
                    paje_event_timestamp(timestamp),
                    container,
                    type,
                    value);
    #endif   
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
    #ifdef STRING_REFERENCE
      rst_event_dwwd( PajeAddVariableEventId,
                      paje_event_timestamp(timestamp),
                      FindStringParam(container),
                      FindStringParam(type),
                      value);
    #else
      rst_event_dssd( PajeAddVariableEventId,
                      paje_event_timestamp(timestamp),
                      container,
                      type,
                      value);
    #endif
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
    #ifdef STRING_REFERENCE
      rst_event_dwwd(PajeSubVariableEventId,
                    paje_event_timestamp(timestamp),
                    FindStringParam(container),
                    FindStringParam(type),
                    value);
    #else
      rst_event_dssd(PajeSubVariableEventId,
                    paje_event_timestamp(timestamp),
                    container,
                    type,
                    value);
    #endif
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
    #ifdef STRING_REFERENCE
      rst_event_dwww(PajeSetStateEventId,
                    paje_event_timestamp(timestamp),
                    FindStringParam(container),
                    FindStringParam(type),
                    FindStringParam(value));
    #else
      rst_event_dsss(PajeSetStateEventId,
                     paje_event_timestamp(timestamp),
                     container,
                     type,
                     value);
    #endif
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
    #ifdef STRING_REFERENCE
      rst_event_dwww(PajePushStateEventId,
                     paje_event_timestamp(timestamp),
                     FindStringParam(container),
                     FindStringParam(type),
                     FindStringParam(value));
    #else
      rst_event_dsss(PajePushStateEventId,
                     paje_event_timestamp(timestamp),
                     container,
                     type,
                     value);
    #endif
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
      #ifdef STRING_REFERENCE
        rst_event_dwwwi(PajePushStateMarkEventId,
                    paje_event_timestamp(timestamp),
                   FindStringParam(container),
                    FindStringParam(type),
                    FindStringParam(value),
                    mark);
      #else
        rst_event_dsssi(PajePushStateMarkEventId,
                        paje_event_timestamp(timestamp),
                        container,
                        type,
                        value,
                        mark);  
      #endif
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
    #ifdef STRING_REFERENCE
      rst_event_dww(PajePopStateEventId,
               paje_event_timestamp(timestamp),
               FindStringParam(container),
               FindStringParam(type));
    #else
      rst_event_dss(PajePopStateEventId,
                   paje_event_timestamp(timestamp),
                   container,
                   type);
    #endif
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
    #ifdef STRING_REFERENCE
      rst_event_dww(PajeResetStateEventId,
                paje_event_timestamp(timestamp),
                FindStringParam(container),
                FindStringParam(type));
    #else
      rst_event_dss(PajeResetStateEventId,
                   paje_event_timestamp(timestamp),
                   container,
                   type);
   #endif
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
    #ifdef STRING_REFERENCE
      rst_event_dwwwww(PajeStartLinkEventId,
                      paje_event_timestamp(timestamp),
                      FindStringParam(container),
                      FindStringParam(type),
                      FindStringParam(sourceContainer),
                      FindStringParam(value),
                      FindStringParam(key));
    #else
      rst_event_dsssss(PajeStartLinkEventId,
                       paje_event_timestamp(timestamp),
                       container,
                       type,
                       sourceContainer,
                       value,
                       key);
    #endif
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
      #ifdef STRING_REFERENCE
        rst_event_dwwwwwi(PajeStartLinkSizeEventId,
                          paje_event_timestamp(timestamp),
                          FindStringParam(container),
                          FindStringParam(type),
                          FindStringParam(sourceContainer),
                          FindStringParam(value),
                          FindStringParam(key),
                          size);
      #else
        rst_event_dsssssi(PajeStartLinkSizeEventId,
                          paje_event_timestamp(timestamp),
                          container,
                          type,
                          sourceContainer,
                          value,
                          key,
                          size);
      #endif
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
      #ifdef STRING_REFERENCE
        rst_event_dwwwwwii(PajeStartLinkSizeMarkEventId,
                          paje_event_timestamp(timestamp),
                          FindStringParam(container),
                          FindStringParam(type),
                          FindStringParam(sourceContainer),
                          FindStringParam(value),
                          FindStringParam(key),
                          size,
                          mark);
      #else
        rst_event_dsssssii(PajeStartLinkSizeMarkEventId,
                          paje_event_timestamp(timestamp),
                          container,
                          type,
                          sourceContainer,
                          value,
                          key,
                          size,
                          mark);
      #endif
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
    #ifdef STRING_REFERENCE
      rst_event_dwwwww(PajeEndLinkEventId,
                       paje_event_timestamp(timestamp),
                       FindStringParam(container),
                       FindStringParam(type),
                       FindStringParam(endContainer),
                       FindStringParam(value),
                       FindStringParam(key));
    #else
      rst_event_dsssss(PajeEndLinkEventId,
                       paje_event_timestamp(timestamp),
                       container,
                       type,
                       endContainer,
                       value,
                       key);
    #endif
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
    #ifdef STRING_REFERENCE
      rst_event_dwww(PajeNewEventEventId,
                     paje_event_timestamp(timestamp),
                     FindStringParam(container),
                     FindStringParam(type),
                     FindStringParam(value));
   #else
    rst_event_dsss(PajeNewEventEventId,
                   paje_event_timestamp(timestamp),
                   container,
                   type,
                   value);
   #endif
  }
}
