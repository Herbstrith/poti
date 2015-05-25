/*
    This file is part of Poti

    Poti is free software: you can redistribute it and/or modify it
    under the terms of the GNU Lesser Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Poti is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser Public License for more details.

    You should have received a copy of the GNU Lesser Public License
    along with Poti. If not, see <http://www.gnu.org/licenses/>.
*/
#include <bzlib.h>
#include "poti_private.h"
#include <poti.h>
#include <rastro.h>


FILE* paje_file = NULL;
int paje_extended = 0;
int poti_mode = 0;

int poti_init(int output, const char *filename, int header_basic, int header_old)
{
  poti_mode = output;
  if(poti_mode & POTI_BINARY) {
    rst_init_filename (filename);
  }else if(poti_mode & POTI_TEXT) {
    if (filename == NULL){
      paje_file = stdout;
    }else{
      paje_file = fopen (filename, "w");
      if (!paje_file) return 1;
      fprintf(paje_file,"#POTI_GIT_VERSION %s\n", POTI_GITVERSION);
      fprintf(paje_file,"#POTI_GIT_DATE (date of the cmake configuration) %s\n", POTI_GITDATE);
    }
  }
  if (header_basic >= 0 && header_old >= 0){
    _poti_header (header_basic, header_old);
  }
  return 0;
}

void poti_close ()
{
  if (poti_mode & POTI_BINARY) {
    rst_finalize();
  }else if(poti_mode & POTI_TEXT) {
    if (paje_file != stdout) {
      fclose(paje_file);
    }
    paje_file = NULL;
  }
  poti_mode = 0;
}

