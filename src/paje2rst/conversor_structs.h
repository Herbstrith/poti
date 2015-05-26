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
