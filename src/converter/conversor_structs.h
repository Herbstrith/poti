#ifndef __CONVERSOR_STRUCT_H__
#define __CONVERSOR_STRUCT_H__
#include <stdio.h>
#include <poti.h>
#include <PajeEnum.h>

struct paje_def {
  PajeEventId eventId;
  int identifier;
  PajeField *names;
  PajeFieldType *types;
  int nfields;
};

void clear_paje_def (void);
void identifier_paje_def (PajeEventId eventId, int identifier);
void add_field_paje_def (PajeField name, PajeFieldType type);
void save_paje_def (void);

void init_paje_defs (void);

PajeEventId getPajeEventId (int identifier);
int getPajeFieldPosition(int identifier, PajeField pajeField);

#endif
