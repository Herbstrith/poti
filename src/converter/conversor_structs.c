#include "conversor_structs.h"

void create_header_event(PajeEventId eventId);

static struct paje_def *def = NULL; //the current def being read
static struct paje_def **defs = NULL;
static int ndefs;

void clear_paje_def (){
  def = malloc(sizeof(struct paje_def));
  bzero(def, sizeof(struct paje_def));
}

void identifier_paje_def (PajeEventId eventId, int identifier)
{
  def->eventId = eventId;
  def->identifier = identifier;
}

void add_field_paje_def (PajeField name, PajeFieldType type){
  def->names = realloc(def->names, sizeof(PajeField*)*(def->nfields+1));
  def->types = realloc(def->types, sizeof(PajeFieldType*)*(def->nfields+1));
  def->names[def->nfields] = name;
  def->types[def->nfields] = type;
  def->nfields++;
}

void save_paje_def (){
  printf("name:%d identifier:%d with %d fields\n", def->eventId, def->identifier, def->nfields);
  int i;
  for (i = 0; i < def->nfields; i++){
    printf("  %d %d\n", def->names[i], def->types[i]);
  }

  create_header_event(def->eventId);

  defs = realloc(defs, (ndefs+1)*sizeof(struct paje_def*));
  defs[ndefs] = def;
  ndefs++;
}

void init_paje_defs (void){
  def = NULL;
  ndefs = 0;
  defs = NULL;
}

PajeEventId getPajeEventId (int identifier)
{
  int i;
  for (i = 0; i < ndefs; i++){
    if (defs[i]->identifier == identifier){
      return defs[i]->eventId;
    }
  }
  return -1;
}

int getPajeFieldPosition(int identifier, PajeField pajeField)
{
  int i;
  for (i = 0; i < ndefs; i++){
    if (defs[i]->identifier == identifier){
      int j;
      for (j = 0; j < defs[i]->nfields; j++){
	if (defs[i]->names[j] == pajeField){
	  return j+1;
	}
      }
    }
  }
  return -1;
}
