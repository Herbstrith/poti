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
#include "main.h"

void yyerror (char const *s);
void yyerror (char const *s) {
  fprintf (stderr, "%s\n", s);
}

int main (int argc, char **argv)
{
  poti_init(POTI_BINARY, "output.rst", -1, -1);
  int ret = yyparse();
  poti_close();
  return ret;
}

