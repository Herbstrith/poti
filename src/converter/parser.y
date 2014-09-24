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

paje: declarations events { return 4;};

declarations: declaration declarations | ;
declaration: TK_EVENT_DEF_BEGIN event_name event_id TK_BREAK
             {
               //def = new PajeEventDefinition($2, $3, yylineno, globalDefinitions);
             }
             fields TK_EVENT_DEF_END TK_BREAK
             {
              // defsv = (PajeEventDefinition**)realloc (defsv, (def->uniqueIdentifier+1)*sizeof(PajeEventDefinition*));
              // defsv[def->uniqueIdentifier] = def;
              // def = NULL;
             };
event_name:
        TK_PAJE_DEFINE_CONTAINER_TYPE { } |
	TK_PAJE_DEFINE_VARIABLE_TYPE { } |
	TK_PAJE_DEFINE_STATE_TYPE { } |
	TK_PAJE_DEFINE_EVENT_TYPE { } |
	TK_PAJE_DEFINE_LINK_TYPE { } |
	TK_PAJE_DEFINE_ENTITY_VALUE { } |
	TK_PAJE_CREATE_CONTAINER { } |
	TK_PAJE_DESTROY_CONTAINER { } |
	TK_PAJE_SET_VARIABLE { } |
	TK_PAJE_ADD_VARIABLE { } |
	TK_PAJE_SUB_VARIABLE { } |
	TK_PAJE_SET_STATE { } |
	TK_PAJE_PUSH_STATE { } |
	TK_PAJE_POP_STATE {} |
	TK_PAJE_RESET_STATE { } |
	TK_PAJE_START_LINK { } |
	TK_PAJE_END_LINK { } |
	TK_PAJE_NEW_EVENT {};
event_id: TK_INT { };
fields: field fields | ;
field: TK_EVENT_DEF field_name field_type {
             /* if ($2.fieldId == PAJE_Extra){
		def->addField($2.fieldId, $3, yylineno, std::string($2.fieldName));
              }else{
		def->addField($2.fieldId, $3, yylineno);
	      }*/
	} TK_BREAK;
field_name:
        TK_EVENT_DEF_ALIAS { } |
	TK_EVENT_DEF_TYPE {  } |
	TK_EVENT_DEF_NAME {} |
	TK_EVENT_DEF_COLOR { } |
	TK_EVENT_DEF_START_CONTAINER_TYPE {  } |
	TK_EVENT_DEF_END_CONTAINER_TYPE {  } |
	TK_EVENT_DEF_CONTAINER {  } |
	TK_EVENT_DEF_TIME {  } |
	TK_EVENT_DEF_START_CONTAINER {  } |
	TK_EVENT_DEF_END_CONTAINER {  } |
	TK_EVENT_DEF_VALUE {  } |
	TK_EVENT_DEF_KEY {  } |
        TK_EVENT_DEF_LINE { } |
        TK_EVENT_DEF_FILE {  } |
	TK_STRING {  };
field_type:
TK_EVENT_DEF_FIELD_TYPE_STRING { } |
TK_EVENT_DEF_FIELD_TYPE_FLOAT {  } |
TK_EVENT_DEF_FIELD_TYPE_DOUBLE { } |
TK_EVENT_DEF_FIELD_TYPE_INT { } |
TK_EVENT_DEF_FIELD_TYPE_HEX {  } |
TK_EVENT_DEF_FIELD_TYPE_DATE { } |
TK_EVENT_DEF_FIELD_TYPE_COLOR {  };

events: events event | ;
event: non_empty_event | empty_event;
non_empty_event:  { lineReset(); }  TK_INT  { lineAdd($2.str); } arguments TK_BREAK { lineSend (); };
empty_event: TK_BREAK; //empty event
arguments: arguments argument { lineAdd($2.str); } | ;
argument: TK_STRING { $$ = $1; } | TK_FLOAT { $$ = $1; } | TK_INT { $$ = $1; };

%%

char* create_poti_event(int identifier, paje_line line)
{
switch (identifier)
	{
		case PajeDefineContainerTypeEventId:
      poti_DefineContainerType(line.word[1],line.word[2],line.word[3]);
			return "PajeDefineContainerType";
			break;
		case PajeDefineEventTypeEventId:
      poti_DefineEventType(line.word[1],line.word[2],line.word[3]);
			return "PajeDefineEventType";
			break;
		case PajeDefineStateTypeEventId:
      poti_DefineStateType(line.word[1],line.word[2],line.word[3]);
			return "PajeDefineStateType";
			break;
		case PajeDefineVariableTypeEventId:
      poti_DefineVariableType(line.word[1],line.word[2],line.word[3],line.word[4]);
			return "PajeDefineVariableType";
			break;
		case PajeDefineLinkTypeEventId:
       poti_DefineLinkType(line.word[1],line.word[2],line.word[3],line.word[4],line.word[5]);
			return "PajeDefineLinkType";
			break;
		case PajeDefineEntityValueEventId:
      poti_DefineEntityValue(line.word[1],line.word[2],line.word[3],line.word[4]);
			return "PajeDefineEntityValue";
			break;
		case PajeCreateContainerEventId:
      poti_CreateContainer(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5]);
			return "PajeCreateContainer";
			break;
		case PajeDestroyContainerEventId:
      poti_DestroyContainer(strtod(line.word[1],NULL),line.word[2],line.word[3]);
			return "PajeDestroyContainer";
			break;
		case PajeNewEventEventId:
      poti_NewEvent(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4]);
			return "PajeNewEvent";
			break;
		case PajeSetStateEventId:
      poti_SetState(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4]);
			return "PajeSetState";
			break;
		case PajePushStateEventId:
      poti_PushState(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4]);
			return "PajePushState";
			break;	
		case PajePopStateEventId:
      poti_PopState(strtod(line.word[1],NULL),line.word[2],line.word[3]);
			return "PajePopState";
			break;	
		case PajeResetStateEventId:
      poti_ResetState(strtod(line.word[1],NULL),line.word[2],line.word[3]);
			return "PajeResetState";
			break;
		case PajeSetVariableEventId:
      poti_SetVariable (strtod(line.word[1],NULL),line.word[2],line.word[3],strtod(line.word[4],NULL));
			return "PajeSetVariable";
			break;	
		case PajeAddVariableEventId:
      poti_AddVariable(strtod(line.word[1],NULL),line.word[2],line.word[3],strtod(line.word[4],NULL));
			return "PajeAddVariable";
			break;		
		case PajeSubVariableEventId:
      poti_SubVariable(strtod(line.word[1],NULL),line.word[2],line.word[3],strtod(line.word[4],NULL));
			return "PajeSubVariable";
			break;	
		case PajeStartLinkEventId:
      poti_StartLink(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5],line.word[6]);
			return "PajeStartLink";
			break;
		case PajeEndLinkEventId:
      poti_EndLink(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5],line.word[6]);
			return "PajeEndLink";
			break;
		case PajeEventIdCount:
      poti_EndLink(strtod(line.word[1],NULL),line.word[2],line.word[3],line.word[4],line.word[5],line.word[6]);
			return "PajeEventIdCount";
			break;
		//poti extended events : TODO merge with same events
		case PajeUnknownEventId:
			return "PajeUnknownEventId";
			break;
		/*case PajePushStateMarkEventId:
			return "PajePushState";
			break;
		case PajeStartLinkSizeEventId:
			return "PajeStartLink";
			break;
		case PajeStartLinkSizeMarkEventId:
			return "PajeStartLink";
			break;	*/
		
	}
    return "ERROR:event definition not found";
}



void lineReset ()
{
  line.lineNumber = yylineno;
  line.word_count = 0;
}

void lineAdd (char *str)
{
  line.word[line.word_count++] = strdup(str);
  /*atoi(str);
    printf("str %d \n", atoi(str));*/
}

void lineSend ()
{

  
  int identifier = atoi(line.word[0]); 
  int i;
  for(i = 0; i <line.word_count;i++)
  {
    if(line.word[i][0] == '"')
    {
      // printf("we gotta a ''");
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

  //printf("id %s\n",create_poti_event(identifier));
  create_poti_event(identifier,line);
 /* for(int i =0; i < line.word_count ; i++)
{
  printf("%s \n", line.word[i]);

}
  PajeTraceEvent *event = new PajeTraceEvent (defsv[identifier], &line);
  flexReader->outputEntity (event);
  delete event; */

  
}


