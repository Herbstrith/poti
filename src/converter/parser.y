%{
  #include <stdio.h>
  #include <search.h>
  #include "main.h"
  #include <poti.h>
  #include <rastro.h>
  #include <string.h>

  PajeEventDefinition *eventBeingDefined;
  PajeDefinitions *globalDefinitions;
  
  extern "C"
  {
    #include "conversor_structs.h"
    #include "poti_converter.c"
    
    
    extern FILE *yyin;
    extern int yylineno;
    int yylex(void);
    void yyerror (char const *mensagem);
    int yyparse ();

    void lineReset ();
    void lineAdd (char *str);
    void lineSend ();
  }

  PajeEventDefinition **defsv;
  PajeEventDefinition *def;
  PajeFlexReader *flexReader;


  paje_line line; //the current line being read
	header_event_list_item *events_def=(header_event_list_item*)malloc(sizeof(header_event_list_item));
	header_event *actual_event ;

%}

%union {
  PajeEventId eventId;
  PajeField fieldId;
  struct Field_Name_Info {
    PajeField fieldId;
    char *fieldName;
  } field_data;
  PajeFieldType fieldType;
  int eventCode;
  struct Argument_Info {
    union {
      float floatValue;
      int intValue;
    };
    char *str;
  } argument_data;
}

%token TK_EVENT_DEF_BEGIN
%token TK_EVENT_DEF
%token TK_EVENT_DEF_END
%token TK_EVENT_DEF_ALIAS
%token TK_EVENT_DEF_TYPE
%token TK_EVENT_DEF_NAME
%token TK_EVENT_DEF_COLOR
%token TK_EVENT_DEF_START_CONTAINER_TYPE
%token TK_EVENT_DEF_END_CONTAINER_TYPE
%token TK_EVENT_DEF_CONTAINER
%token TK_EVENT_DEF_TIME
%token TK_EVENT_DEF_START_CONTAINER
%token TK_EVENT_DEF_END_CONTAINER
%token TK_EVENT_DEF_VALUE
%token TK_EVENT_DEF_KEY
%token TK_EVENT_DEF_LINE
%token TK_EVENT_DEF_FILE
%token TK_EVENT_DEF_FIELD_TYPE_STRING
%token TK_EVENT_DEF_FIELD_TYPE_FLOAT
%token TK_EVENT_DEF_FIELD_TYPE_DOUBLE
%token TK_EVENT_DEF_FIELD_TYPE_INT
%token TK_EVENT_DEF_FIELD_TYPE_HEX
%token TK_EVENT_DEF_FIELD_TYPE_DATE
%token TK_EVENT_DEF_FIELD_TYPE_COLOR
%token TK_PAJE_DEFINE_CONTAINER_TYPE
%token TK_PAJE_DEFINE_VARIABLE_TYPE
%token TK_PAJE_DEFINE_STATE_TYPE
%token TK_PAJE_DEFINE_EVENT_TYPE
%token TK_PAJE_DEFINE_LINK_TYPE
%token TK_PAJE_DEFINE_ENTITY_VALUE
%token TK_PAJE_CREATE_CONTAINER
%token TK_PAJE_DESTROY_CONTAINER
%token TK_PAJE_SET_VARIABLE
%token TK_PAJE_ADD_VARIABLE
%token TK_PAJE_SUB_VARIABLE
%token TK_PAJE_SET_STATE
%token TK_PAJE_PUSH_STATE
%token TK_PAJE_POP_STATE
%token TK_PAJE_RESET_STATE
%token TK_PAJE_START_LINK
%token TK_PAJE_END_LINK
%token TK_PAJE_NEW_EVENT
%token<argument_data> TK_FLOAT
%token<argument_data> TK_INT
%token<argument_data> TK_STRING
%token TK_BREAK

%type<eventId> event_name;
%type<field_data> field_name;
%type<fieldType> field_type;
%type<eventCode> event_id;
%type<argument_data> argument;

%error-verbose
%right TK_INT

%%

paje: declarations{create_header(events_def);} events { return 4;};

declarations: declaration declarations | ;
declaration: TK_EVENT_DEF_BEGIN event_name event_id TK_BREAK
             {
								actual_event = (header_event*)malloc(sizeof(header_event));
             		actual_event->field_counter = 0;	
							  actual_event->paje_event_type_definition = $2;
							  actual_event->paje_file_event_id = $3;
                //def = new HeaderDefine($2, $3, yylineno, globalDefinitions);
             }
             fields TK_EVENT_DEF_END TK_BREAK
             {
								addEventToList(events_def, actual_event);
								//print_list(events_def);
             };
event_name:
          TK_PAJE_DEFINE_CONTAINER_TYPE { $$ = PajeDefineContainerTypeEventId;} |
          TK_PAJE_DEFINE_VARIABLE_TYPE { $$ = PajeDefineVariableTypeEventId;} |
          TK_PAJE_DEFINE_STATE_TYPE { $$ = PajeDefineStateTypeEventId;} |
          TK_PAJE_DEFINE_EVENT_TYPE { $$ = PajeDefineEventTypeEventId;} |
          TK_PAJE_DEFINE_LINK_TYPE { $$ = PajeDefineLinkTypeEventId;} |
          TK_PAJE_DEFINE_ENTITY_VALUE { $$ = PajeDefineEntityValueEventId;} |
          TK_PAJE_CREATE_CONTAINER { $$ = PajeCreateContainerEventId;} |
          TK_PAJE_DESTROY_CONTAINER { $$ = PajeDestroyContainerEventId;} |
          TK_PAJE_SET_VARIABLE { $$ = PajeSetVariableEventId;} |
          TK_PAJE_ADD_VARIABLE { $$ = PajeAddVariableEventId;} |
          TK_PAJE_SUB_VARIABLE { $$ = PajeSubVariableEventId;} |
          TK_PAJE_SET_STATE { $$ = PajeSetStateEventId;} |
          TK_PAJE_PUSH_STATE { $$ = PajePushStateEventId;} |
          TK_PAJE_POP_STATE { $$ = PajePopStateEventId;} |
          TK_PAJE_RESET_STATE { $$ = PajeResetStateEventId;} |
          TK_PAJE_START_LINK { $$ = PajeStartLinkEventId;} |
          TK_PAJE_END_LINK { $$ = PajeEndLinkEventId;} |
          TK_PAJE_NEW_EVENT { $$ = PajeNewEventEventId;};
event_id: TK_INT { };
fields: field fields | ;
field: TK_EVENT_DEF field_name field_type {
					addField($2.fieldId, $3, actual_event);
             /* if ($2.fieldId == PAJE_Extra){
		actual->addField($2.fieldId, $3, yylineno, std::string($2.fieldName));
              }else{
		def->addField($2.fieldId, $3, yylineno);
	      }*/
	} TK_BREAK;
field_name:
          TK_EVENT_DEF_ALIAS { $$.fieldId = PAJE_Alias; } |
	        TK_EVENT_DEF_TYPE { $$.fieldId = PAJE_Type; } |
	        TK_EVENT_DEF_NAME { $$.fieldId = PAJE_Name; } |
	        TK_EVENT_DEF_COLOR { $$.fieldId = PAJE_Color; } |
	        TK_EVENT_DEF_START_CONTAINER_TYPE { $$.fieldId = PAJE_StartContainerType; } |
	        TK_EVENT_DEF_END_CONTAINER_TYPE { $$.fieldId = PAJE_EndContainerType; } |
	        TK_EVENT_DEF_CONTAINER { $$.fieldId = PAJE_Container; } |
	        TK_EVENT_DEF_TIME { $$.fieldId = PAJE_Time; } |
	        TK_EVENT_DEF_START_CONTAINER { $$.fieldId = PAJE_StartContainer; } |
	        TK_EVENT_DEF_END_CONTAINER { $$.fieldId = PAJE_EndContainer; } |
	        TK_EVENT_DEF_VALUE { $$.fieldId = PAJE_Value; } |
	        TK_EVENT_DEF_KEY { $$.fieldId = PAJE_Key; } |
          TK_EVENT_DEF_LINE { $$.fieldId = PAJE_Line; } |
          TK_EVENT_DEF_FILE { $$.fieldId = PAJE_File; } |
	        TK_STRING { $$.fieldId = PAJE_Extra; $$.fieldName = $1.str; };
field_type:
          TK_EVENT_DEF_FIELD_TYPE_STRING { $$ = PAJE_string; } |
          TK_EVENT_DEF_FIELD_TYPE_FLOAT { $$ = PAJE_float; } |
          TK_EVENT_DEF_FIELD_TYPE_DOUBLE { $$ = PAJE_double; } |
          TK_EVENT_DEF_FIELD_TYPE_INT { $$ = PAJE_int; } |
          TK_EVENT_DEF_FIELD_TYPE_HEX { $$ = PAJE_hex; } |
          TK_EVENT_DEF_FIELD_TYPE_DATE { $$ = PAJE_date; } |
          TK_EVENT_DEF_FIELD_TYPE_COLOR { $$ = PAJE_color; };

events: events event | ;
event: non_empty_event | empty_event;
non_empty_event:  { lineReset(); }  TK_INT  { lineAdd($2.str); } arguments TK_BREAK { lineSend (); };
empty_event: TK_BREAK; //empty event
arguments: arguments argument { lineAdd($2.str); } | ;
argument: TK_STRING { $$ = $1; } | TK_FLOAT { $$ = $1; } | TK_INT { $$ = $1; };

%%



void lineReset ()
{
  line.lineNumber = yylineno;
  int i;
  for(i = 0; i <line.word_count;i++)
  {
    free(line.word[i]);
  }
  line.word_count = 0; 
}

void lineAdd (char *str)
{
  line.word[line.word_count++] = strdup(str); 
}

void lineSend ()
{
  int identifier = atoi(line.word[0]); 
  int i;
  for(i = 0; i <line.word_count;i++)
  {
    if(line.word[i][0] == '"')
    {
      int len = strlen(line.word[i]);
      int f = 0;
      int k = 0;
      for ( f = 0; f <= len; f++ )
      {
        if (line.word[i][f] != '"')
        {
          line.word[i][k]=line.word[i][f];
          k++;
        } 
      }
      
    }
  }

  create_poti_event(identifier,line, events_def);
/*TODO:
   Sort events ids with respective header ids
*/

  
}


