/*
   main.c

   Arquivo principal do analisador sintático.
*/
#include <stdio.h>
#include <search.h>

#include <poti.h>

#include "main.h"

#include "parser.hh"
#include <rastro.h>

  extern int yylineno;
  int yylex(void);
  int yyparse ();
  extern char *yytext;
  extern int yychar;

int main (int argc, char **argv)
{
  printf("Begin conversion");
  long long counter = 0;
  poti_init(NULL,POTI_BINARY_OUTPUT);
  //	  poti_header(1,0,POTI_BINARY_OUTPUT);
  //the global PajeDefinitions object
  //  globalDefinitions = new PajeDefinitions (false);
  yyparse();
  rst_finalize();
  printf("End convesion -- output to rastro-5-5.rst");
  return 1;

}

