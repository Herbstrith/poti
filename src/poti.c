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
#include "poti_private.h"
#include <poti.h>
extern "C"
{
  #include <rastro.h>

}

FILE* paje_file = 0;
int paje_extended = 0;
//0 for textual,1 for binary,2 for both
int paje_binary = 0;

int poti_open (const char* filename)
{
  FILE* fout = fopen(filename,"w");
  if (fout ==0) return -1;
  paje_file = fout;
  return 0;
}

int poti_init(FILE *file, int output_mode)
{
  paje_binary = output_mode;
  if(paje_binary == POTI_BINARY_OUTPUT || POTI_TEXTUAL_BINARY_OUTPUT == 2)
  {
    rst_init(5,5);
    return 0;
  }
  if (file){
    paje_file = file;
    return 0;
  }else{
    return -1;
  }
}


void poti_close ()
{
  rst_finalize();
  if (paje_file != stdout)
  {
    fclose( paje_file );
  }
  paje_file = 0;

}

void poti_header (int basic, int old_header, int output_mode)
{


  if (paje_file ==0)
    paje_file = stdout;

  fprintf(paje_file,"#POTI_GIT_VERSION %s\n", POTI_GITVERSION);
  fprintf(paje_file,"#POTI_GIT_DATE (date of the cmake configuration) %s\n", POTI_GITDATE);


  _poti_header (basic, old_header,output_mode);
}
