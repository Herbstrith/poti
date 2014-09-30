#ifndef __CONVERSORSTRUCT_H
#define __CONVERSORSTRUCT_H

#include <stdio.h>
#include <poti.h>




typedef struct HeaderEvent
{
	int paje_event_type_definition;	 //PajeTypeDefinitions
	int paje_file_event_id;
	int parameters_order[10];	//PAje value definitions
	int parameters_types[10]; //PAJE type definitions
	int field_counter;

}header_event;


typedef struct HeaderEventListItem
{
	int init;
	header_event *event_define;
	struct HeaderEventListItem *next;
}header_event_list_item;

void addField(int field_name,int field_type,header_event *event)
{
	event->parameters_order[event->field_counter] = field_name;
	event->parameters_types[event->field_counter] = field_type;	
	event->field_counter= event->field_counter + 1;
} 	

void print_header_event(header_event *event)
{
	printf("eventdef is a %d \n with file id %d \n and %d fields: \n",
           event->paje_event_type_definition,
           event->paje_file_event_id,
           event->field_counter);
	int i = 0;

	while(i < event->field_counter)
  {
	  printf("field number %d name is %d and of type %d \n",i, event->parameters_order[i],event->parameters_types[i]);
	  i++;
  }

	
}

void print_list(header_event_list_item *list)
{
	printf("Printing list \n");
	header_event_list_item *actual_item;
	actual_item = list;
	while(actual_item != NULL)
	{
		print_header_event(actual_item->event_define);

		if(actual_item->next == NULL)
			break;

    actual_item = actual_item->next;

	}

}

void addEventToList(header_event_list_item *list, header_event *new_event )
{
	if(list->init == 0)
	{
		list->event_define = new_event;
		list->init =1;
		list->next = NULL;
		return;
	}
	header_event_list_item *actual_item;
	
	actual_item = list;
	
	while(actual_item != NULL)
  {
		if(actual_item->next == NULL) 
			break;

		actual_item = actual_item->next;
  }

	header_event_list_item *new_item = (header_event_list_item*)malloc(sizeof(header_event_list_item));
	new_item->event_define = new_event;
	new_item->next = NULL;
	actual_item->next = new_item;


}

int findHeaderFileId(header_event_list_item *list , int id)
{
  header_event_list_item *actual_item;
	
	actual_item = list;
	while(actual_item != NULL)
  {
    if(actual_item->event_define.paje_file_event_id == id)
    { 
      return actual_item->event_define.paje_event_type_definition;
    }
    if(actual_item->next == NULL) 
			return -1;

		actual_item = actual_item->next;
  }   
  
  return -1;
}
#endif
