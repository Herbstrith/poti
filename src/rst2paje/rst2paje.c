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
#include <argp.h>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include "poti_private.h"
#include <rastro.h>

static char doc[] = "Translates from binary to textual Paje file format";
static char args_doc[] = "{pajebinary.rst}";

static struct argp_option options[] = {
  { 0 }
};

struct arguments {
  char *input[RST_MAX_INPUT_SIZE];
  int input_size;
};


void poti_print_event(rst_event_t *event);
const char* eventidToString(u_int32_t event);
const char* fieldToString(u_int32_t event);
const char* typeToString(u_int32_t event);
static int parse_options (int key, char *arg, struct argp_state *state)
{
  struct arguments *arguments = (struct arguments*)state->input;
  switch (key){
  case ARGP_KEY_ARG:
    if (arguments->input_size == RST_MAX_INPUT_SIZE) {
      /* Too many arguments. */
      argp_usage (state);
    }
    arguments->input[state->arg_num] = arg;
    arguments->input_size++;
    break;
  case ARGP_KEY_END:
    if (state->arg_num < 1)
      /* Not enough arguments. */
      argp_usage (state);
    break;
  default: return ARGP_ERR_UNKNOWN;
  }
  return 0;
}

static struct argp argp = { options, parse_options, args_doc, doc };

int event_order[10];
int event_order_limit;
void set_event_order(int event_id);
void set_event_order(int event_id)
{

  switch (event_id)
  {
  case PajeDefineContainerTypeEventId:
    event_order[0] = PAJE_string;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order_limit = 3;
    break;
  case PajeDefineEventTypeEventId:
    event_order[0] = PAJE_string;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order_limit = 3;
    break;
  case PajeDefineStateTypeEventId:
    event_order[0] = PAJE_string;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order_limit = 3;
    break;
  case PajeDefineVariableTypeEventId:
    event_order[0] = PAJE_string;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order[3] = PAJE_color;
    event_order_limit = 4;
    break;
  case PajeDefineLinkTypeEventId:
    event_order[0] = PAJE_string;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order[3] = PAJE_string;
    event_order[4] = PAJE_string;
    event_order_limit = 5;
    break;
  case PajeDefineEntityValueEventId:
    event_order[0] = PAJE_string;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order[3] = PAJE_color;
    event_order_limit = 4;
    break;
  case PajeCreateContainerEventId:
    event_order[0] = PAJE_date;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order[3] = PAJE_string;
    event_order[4] = PAJE_string;
    event_order_limit = 5;			
    break;
  case PajeDestroyContainerEventId:
    event_order[0] = PAJE_date;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;		
    event_order_limit = 3;	
    break;
  case PajeNewEventEventId:
    event_order[0] = PAJE_date;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order[3] = PAJE_string;
    event_order_limit = 4;
    break;
  case PajeSetStateEventId:
    event_order[0] = PAJE_date;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order[3] = PAJE_double;
    event_order_limit = 4;
    break;
  case PajePushStateEventId:
    event_order[0] = PAJE_date;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order[3] = PAJE_string;
    event_order_limit = 4;
    break;	
  case PajePopStateEventId:
    event_order[0] = PAJE_date;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order_limit = 3;
    break;	
  case PajeResetStateEventId:
    event_order[0] = PAJE_date;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order_limit = 3;
    break;
  case PajeSetVariableEventId:
    event_order[0] = PAJE_date;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order[3] = PAJE_double;
    event_order_limit = 4;
    break;	
  case PajeAddVariableEventId:
    event_order[0] = PAJE_date;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order[3] = PAJE_double;
    event_order_limit = 4;
    break;		
  case PajeSubVariableEventId:
    event_order[0] = PAJE_date;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order[3] = PAJE_double;
    event_order_limit = 4;
    break;	
  case PajeStartLinkEventId:
    event_order[0] = PAJE_date;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order[3] = PAJE_string;
    event_order[4] = PAJE_string;
    event_order[5] = PAJE_string;
    event_order_limit = 6;
    break;
  case PajeEndLinkEventId:
    event_order[0] = PAJE_date;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order[3] = PAJE_string;
    event_order[4] = PAJE_string;
    event_order[5] = PAJE_string;
    event_order_limit = 6;
    break;
  case PajeEventIdCount:

    break;
    //poti extended events : TODO merge with same events
  case PajeUnknownEventId:

    break;
  case PajePushStateMarkEventId:
    event_order[0] = PAJE_date;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order[3] = PAJE_double;
    event_order[4] = PAJE_string;
    event_order_limit = 5;
    break;
  case PajeStartLinkSizeEventId:
    event_order[0] = PAJE_date;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order[3] = PAJE_string;
    event_order[4] = PAJE_double;
    event_order[5] = PAJE_string;
    event_order[6] = PAJE_double;
    event_order_limit = 7;
    break;
  case PajeStartLinkSizeMarkEventId:
    event_order[0] = PAJE_date;
    event_order[1] = PAJE_string;
    event_order[2] = PAJE_string;
    event_order[3] = PAJE_string;
    event_order[4] = PAJE_string;
    event_order[5] = PAJE_double;
    event_order[6] = PAJE_string;
    event_order_limit = 7;
    break;	
  }

}



const char* eventidToString(u_int32_t event)
{

  switch (event)
  {
  case PajeDefineContainerTypeEventId:
    return "PajeDefineContainerType";
    break;
  case PajeDefineEventTypeEventId:
    return "PajeDefineEventType";
    break;
  case PajeDefineStateTypeEventId:
    return "PajeDefineStateType";
    break;
  case PajeDefineVariableTypeEventId:
    return "PajeDefineVariableType";
    break;
  case PajeDefineLinkTypeEventId:
    return "PajeDefineLinkType";
    break;
  case PajeDefineEntityValueEventId:
    return "PajeDefineEntityValue";
    break;
  case PajeCreateContainerEventId:
    return "PajeCreateContainer";
    break;
  case PajeDestroyContainerEventId:
    return "PajeDestroyContainer";
    break;
  case PajeNewEventEventId:
    return "PajeNewEvent";
    break;
  case PajeSetStateEventId:
    return "PajeSetState";
    break;
  case PajePushStateEventId:
    return "PajePushState";
    break;	
  case PajePopStateEventId:
    return "PajePopState";
    break;	
  case PajeResetStateEventId:
    return "PajeResetState";
    break;
  case PajeSetVariableEventId:
    return "PajeSetVariable";
    break;	
  case PajeAddVariableEventId:
    return "PajeAddVariable";
    break;		
  case PajeSubVariableEventId:
    return "PajeSubVariable";
    break;	
  case PajeStartLinkEventId:
    return "PajeStartLink";
    break;
  case PajeEndLinkEventId:
    return "PajeEndLink";
    break;
  case PajeEventIdCount:
    return "PajeEventIdCount";
    break;
    //poti extended events : TODO merge with same events
  case PajeUnknownEventId:
    return "PajeUnknownEventId";
    break;
  case PajePushStateMarkEventId:
    return "PajePushState";
    break;
  case PajeStartLinkSizeEventId:
    return "PajeStartLink";
    break;
  case PajeStartLinkSizeMarkEventId:
    return "PajeStartLink";
    break;	
		
  }
  return "error on event def";
}

const char* fieldToString(u_int32_t event)
{
  switch (event)
  {
  case PAJE_Time:
    return "Time";
    break;
  case PAJE_Name:
    return "Name";
    break;
  case PAJE_Type:
    return "Type";
    break;
  case PAJE_Container:
    return "Container";
    break;
  case PAJE_StartContainerType:
    return "StartContainerType";
    break;
  case PAJE_EndContainerType:
    return "EndContainerType";
    break;
  case PAJE_StartContainer:
    return "StartContainer";
    break;
  case PAJE_EndContainer:
    return "EndContainer";
    break;
  case PAJE_Value:
    return "Value";
    break;	
  case PAJE_Key:
    return "Key";
    break;
  case PAJE_Alias:
    return "Alias";
    break;	
  case PAJE_Color:
    return "Color";
    break;

    //poti extended events
  case PAJE_Mark:
    return "Mark";
    break;
  case PAJE_Size:
    return "Size";
    break;
/*	
	case PAJE_Line:
	return "xx";
	break;
	case PAJE_File:
	return "xx";
	break;	
	case PAJE_Extra:
	return "xx";
	break;		
	case PAJE_Unknown_Field:
	return "xx";
	break;	
*/
		
  }
  return "error on field def";
}

const char* typeToString(u_int32_t event)
{
  switch (event)
  {
  case PAJE_string:
    return  "string";
    break;
  case PAJE_float:
    return "float";
    break;
  case PAJE_double:
    return "double";
    break;
  case PAJE_int:
    return "int";
    break;
  case PAJE_hex:
    return "hex";
    break;
  case PAJE_date:
    return "date";
    break;
  case PAJE_color:
    return "color";
    break;
  case PAJE_unknown_field_type:
    return "unknown_field_type";
    break;
  }
  return "error on type def";
}

//reads the binary rst events and print them in  paje  format
void poti_print_event (rst_event_t *event)
{


  //header event
  if(event->type == PajeHeaderEventId )
  {
    int i = 0;
    printf("%%EventDef %s %" PRIu32 "\n", eventidToString(event->v_uint32[i]), event->v_uint32[i]);
    i++;
    for (; i < event->ct.n_uint32; i=i+2) {
      printf("%%       %s %s\n", fieldToString(event->v_uint32[i]),typeToString(event->v_uint32[i+1]));
    }
    printf("%%EndEventDef\n");
	  	

  }
  //extended header event
  /*else if(event->type == 1)
    {
    int i = 0;
    printf("#\n");
    for (i = 0; i < event->ct.n_string; i++) {
    printf("%s ", event->v_string[i]);
    }
    printf("\n#\n");
		  

    }*/
  //poti event event
  else
  {
		
    int event_id = event->type;
    printf("%d ",event->type);
    set_event_order(event_id);
    int f;
    int double_mark=0,string_mark = 0;

    for(f = 0; f < event_order_limit;f++)
    {

      if((event_order[f] == PAJE_string || event_order[f] == PAJE_color)&& f == event_order_limit-1)
      {

	printf("%s", event->v_string[string_mark]);
	break;


      }
      if((event_order[f] == PAJE_double || event_order[f] == PAJE_date) && f== event_order_limit-1)
      {

	printf("%lf", event->v_double[double_mark]);
	break;
		
      }				

					
      if(event_order[f] == PAJE_string || event_order[f] == PAJE_color)
      {
	printf("%s ", event->v_string[string_mark]);

	string_mark = string_mark +1;
      }
      if(event_order[f] == PAJE_double || event_order[f] == PAJE_date)
      {
	printf("%lf ", event->v_double[double_mark]);

	double_mark = double_mark +1;
      }

				
				
/*


  if (event->ct.n_uint64 > 0) {
  for (i = 0; i < event->ct.n_uint64; i++) {
  if(i+1 >= event->ct.n_uint64)
  {
  printf("%" PRIu64 "", event->v_uint64[i]);
  break;
  }
  printf("%" PRIu64 " ", event->v_uint64[i]);
  }
  }
  if (event->ct.n_double > 0) {	
  for (i = 0; i < event->ct.n_double; i++) {
  if(i+1 >= event->ct.n_double)
  {
  printf("%lf", event->v_double[i]);
  break;
  }
  printf("%f ", event->v_double[i]);
  }

  }

				

  if (event->ct.n_string > 0) {
  for (i = 0; i < event->ct.n_string; i++) {
  if(i+1 >= event->ct.n_string)
  {
  printf("%s", event->v_string[i]);
  break;
  }
  printf("%s ", event->v_string[i]);
  }
  }

  if (event->ct.n_float > 0) {

  for (i = 0; i < event->ct.n_float; i++) {
  if(i+1 >= event->ct.n_float)
  {
  printf("%f", event->v_float[i]);
  break;
  }
  printf("%f ", event->v_float[i]);
  }
  }
*/
      /*
	if (event->ct.n_uint64 > 0) {
	for (i = 0; i < event->ct.n_uint64; i++) {
	if(i+1 >= event->ct.n_uint64)
	{
	printf("%" PRIu64 "", event->v_uint64[i]);
	break;
	}
	printf("%" PRIu64 " ", event->v_uint64[i]);
	}
	}

	if (event->ct.n_uint32 > 0) {

	for (i = 0; i < event->ct.n_uint32; i++) {
	if(i+1 >= event->ct.n_uint32)
	{
	printf("%d", event->v_uint32[i]);
	break;
	}
	printf("%d ", event->v_uint32[i]);
	}
	}
	if (event->ct.n_uint16 > 0) {
	for (i = 0; i < event->ct.n_uint16; i++) {
	if(i+1 >= event->ct.n_uint16)
	{
	printf("%d", event->v_uint16[i]);
	break;
	}
	printf("%d ", event->v_uint16[i]);
	}
	}
	if (event->ct.n_uint8 > 0) {
	for (i = 0; i < event->ct.n_uint8; i++) {
	if(i+1 >= event->ct.n_uint8)
	{
	printf("%c", event->v_uint8[i]);
	break;
	}
	printf("%c ", event->v_uint8[i]);
	}

	}*/
    }  
    printf("\n");

  }

	
}

int main (int argc, char *argv[])
{
  struct arguments arguments;
  bzero (&arguments, sizeof(struct arguments));
  if (argp_parse (&argp, argc, argv, 0, 0, &arguments) == ARGP_KEY_ERROR){
    fprintf(stderr,
            "[rst2paje] at %s, "
            "error during the parsing of parameters\n",
            __FUNCTION__);
    return 1;
  }

  rst_rastro_t rastro;
  bzero(&rastro, sizeof(rst_rastro_t));
  rst_event_t event;

  /* opening rst files */
  int status = rst_open_file (&rastro, 100000,
			      arguments.input[0],
			      NULL);
  if (status == RST_NOK){
    fprintf(stderr,
	    "[rst2paje] at %s, "
	    "trace file %s could not be opened\n",
	    __FUNCTION__, arguments.input[0]);
    return 1;
  }else{
    printf ("#POTI_GIT_VERSION %s\n#POTI_GIT_DATE (date of the cmake configuration) %s\n",
	    POTI_GITVERSION,
	    POTI_GITDATE);
    printf ("#This file was translated from binary using rst2paje.\n");
  }

  /* reading all the files */
  while (rst_decode_event (&rastro, &event)) {
    poti_print_event (&event);
  }

  /* closing everything */
  rst_close (&rastro);
  return 0;
}
