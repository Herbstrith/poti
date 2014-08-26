#include <stdio.h>
#include <argp.h>
#include <rastro.h>
#include "poti_private.h"

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
static int parse_options (int key, char *arg, struct argp_state *state)
{
  struct arguments *arguments = state->input;
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
			return "PajeNewEventEvent";
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
		case PajeUnknownEventId:
			return "PajeUnknownEventId";
			break;	
		
	}
	return "error on event def";
}

const char* fieldToString(u_int32_t event)
{
	switch (event)
	{
		case PAJE_Time:
			return  "Time date";
			break;
		case PAJE_Name:
			return "Name string";
			break;
		case PAJE_Type:
			return "Type string";
			break;
		case PAJE_Container:
			return "Container string";
			break;
		case PAJE_StartContainerType:
			return "StartContainerType string";
			break;
		case PAJE_EndContainerType:
			return "EndContainerType string";
			break;
		case PAJE_StartContainer:
			return "StartContainer string";
			break;
		case PAJE_EndContainer:
			return "EndContainer string";
			break;
		case PAJE_Value:
			return "Value string";
			break;
		case PAJE_Key:
			return "Key string";
			break;
		case PAJE_Alias:
			return "Alias string";
			break;	
		case PAJE_Color:
			return "Color color";
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

//reads the binary rst events and print them in  paje  format
void poti_print_event (rst_event_t *event)
{


	//header event
	if(event->type == 0 )
	{
		int i = 0;
		printf("%%EventDef %s %" PRIu32 "\n", eventidToString(event->v_uint32[i]), event->v_uint32[i]);
		i++;
		for (i = 0; i < event->ct.n_uint32; i++) {
			printf("%%       %s\n", fieldToString(event->v_uint32[i]));
		}
		printf("%%EndEventDef\n");
	  	

	}
	//extended header event
	else if(event->type == 1)
	{
		int i = 0;
		printf("#\n");
		for (i = 0; i < event->ct.n_string; i++) {
		printf("%s ", event->v_string[i]);
		}
		printf("\n#\n");
		  

	}
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
	      printf("%f ", event->v_double[i]);
	    }

	  }
	  if (event->ct.n_uint64 > 0) {
	    for (i = 0; i < event->ct.n_uint64; i++) {
	      printf("%" PRIu64 " ", event->v_uint64[i]);
	    }
	  }
	  if (event->ct.n_string > 0) {
	    for (i = 0; i < event->ct.n_string; i++) {
	      printf("%s ", event->v_string[i]);
	    }
	  }
	  if (event->ct.n_float > 0) {

	    for (i = 0; i < event->ct.n_float; i++) {
	      printf("%f ", event->v_float[i]);
	    }
	  }
	  if (event->ct.n_uint32 > 0) {

	    for (i = 0; i < event->ct.n_uint32; i++) {
	      printf("%d ", event->v_uint32[i]);
	    }
	  }
	  if (event->ct.n_uint16 > 0) {
	    for (i = 0; i < event->ct.n_uint16; i++) {
	      printf("%d ", event->v_uint16[i]);
	    }
	  }
	  if (event->ct.n_uint8 > 0) {
	    for (i = 0; i < event->ct.n_uint8; i++) {
	      printf("%c ", event->v_uint8[i]);
	    }

	  }
	  
	printf("\n");

	}

	

/*
	  int i;
	  if (event->file->resolution > RST_MICROSECONDS){
	    printf("%d type: %d ts: %.9f (id1=%"PRIu64",id2=%"PRIu64")\n", event->file->id,
		   event->type, event->timestamp, event->id1, event->id2);
	  }else{
	    printf("%d type: %d ts: %f (id1=%"PRIu64",id2=%"PRIu64")\n", event->file->id,
		   event->type, event->timestamp, event->id1, event->id2);
	  }
	  if (event->ct.n_uint64 > 0) {
	    printf("\tu_int64_ts-> ");
	    for (i = 0; i < event->ct.n_uint64; i++) {
	      printf("(%" PRIu64 ") ", event->v_uint64[i]);
	    }
	    printf("\n");
	  }
	  if (event->ct.n_string > 0) {
	    printf("\tstrings-> ");
	    for (i = 0; i < event->ct.n_string; i++) {
	      printf("(%s) ", event->v_string[i]);
	    }
	    printf("\n");
	  }
	  if (event->ct.n_float > 0) {
	    printf("\tfloats-> ");
	    for (i = 0; i < event->ct.n_float; i++) {
	      printf("(%f) ", event->v_float[i]);
	    }
	    printf("\n");
	  }
	  if (event->ct.n_uint32 > 0) {
	    printf("\tu_int32_ts-> ");
	    for (i = 0; i < event->ct.n_uint32; i++) {
	      printf("(%d) ", event->v_uint32[i]);
	    }
	    printf("\n");
	  }
	  if (event->ct.n_uint16 > 0) {
	    printf("\tu_int16_ts-> ");
	    for (i = 0; i < event->ct.n_uint16; i++) {
	      printf("(%d) ", event->v_uint16[i]);
	    }
	    printf("\n");
	  }
	  if (event->ct.n_uint8 > 0) {
	    printf("\tu_int8_ts-> ");
	    for (i = 0; i < event->ct.n_uint8; i++) {
	      printf("(%c) ", event->v_uint8[i]);
	    }
	    printf("\n");
	  }
	  if (event->ct.n_double > 0) {
	    printf("\tdoubles-> ");
	    for (i = 0; i < event->ct.n_double; i++) {
	      printf("(%f) ", event->v_double[i]);
	    }
	    printf("\n");
	  }
*/
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
      printf ("file %s, id %d\n",
              rastro.files[i]->filename,
              rastro.files[i]->id);
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
