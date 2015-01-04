#ifndef __CONVERSOR_STRUCT_H__
#define __CONVERSOR_STRUCT_H__

#include <stdio.h>
#include <poti.h>

typedef struct HeaderEvent
{
	int paje_event_type_definition;	 //PajeTypeDefinitions
	int paje_file_event_id;
	int parameters_order[20];	//PAje value definitions
	int parameters_types[20]; //PAJE type definitions
	int field_counter;

}header_event;

typedef struct HeaderEventListItem
{
	int init;
	header_event *event_define;
	struct HeaderEventListItem *next;
}header_event_list_item;

void addField(int field_name,int field_type,header_event *event);
void print_list(header_event_list_item *list);
void print_header_event(header_event *event);
void addEventToList(header_event_list_item *list, header_event *new_event );
header_event* findHeaderFileId(header_event_list_item *list , int id);
int getPajeFieldPosition(header_event *event, int pajeField);

#endif
