#include <stdio.h>
#include <argp.h>
#include "poti_private.h"

extern "C"
{
  #include <rastro.h>

}

static char doc[] = "Reads the poti binary trace";
static char args_doc[] = "{rastro-0-0.rst rastro-1-0.rst ...}";

static struct argp_option options[] = {
  {"sync", 's', "SYNC_FILE", 0, "Synchronization file (from rastro_timesync)"},
  { 0 }
};

struct arguments {
  char *input[RST_MAX_INPUT_SIZE];
  int input_size;
  char *synchronization_file;
};


void poti_print_event(rst_event_t *event);
const char* eventidToString(u_int32_t event);
const char* fieldToString(u_int32_t event);
const char* typeToString(u_int32_t event);
static int parse_options (int key, char *arg, struct argp_state *state)
{
  struct arguments *arguments = (struct arguments*)state->input;
  switch (key){
  case 's': arguments->synchronization_file = arg; break;
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
	if(event->type == 0 )
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
	  int i;
	  if (event->file->resolution > RST_MICROSECONDS){
	    	printf("%d ",event->type);
	  }else{
	    	printf("%d ",event->type);
	  }

	  if (event->ct.n_double > 0) {	
	    for (i = 0; i < event->ct.n_double; i++) {
		/*if(i+1 >= event->ct.n_double)
		{
	  		printf("%f", event->v_double[i]);
			break;
		}*/
	      printf("%f ", event->v_double[i]);
	    }

	  }

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
            "[rastro_read] at %s, "
            "error during the parsing of parameters\n",
            __FUNCTION__);
    return 1;
  }

  rst_rastro_t rastro;
  bzero(&rastro, sizeof(rst_rastro_t));
  rst_event_t event;
  int i;

  /* opening rst files */
  for (i = 0; i < arguments.input_size; i++){
    int status = rst_open_file (&rastro, 100000,
                                arguments.input[i],
                                arguments.synchronization_file);
    if (status == RST_NOK){
      fprintf(stderr,
              "[rastro_read] at %s, "
              "trace file %s could not be opened\n",
              __FUNCTION__, arguments.input[i]);
      return 1;
    }else{
      printf ("#POTI_GIT_VERSION %s\n#POTI_GIT_DATE (date of the cmake configuration) %s\n",
              POTI_GITVERSION,
              POTI_GITDATE);
    }
  }

  /* reading all the files */
  while (rst_decode_event (&rastro, &event)) {
    poti_print_event (&event);
  }

  /* closing everything */
  rst_close (&rastro);
  return 0;
}
