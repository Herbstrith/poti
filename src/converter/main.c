/*
   main.c

   Arquivo principal do analisador sintático.
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

