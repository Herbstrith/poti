/*
   main.c

   Arquivo principal do analisador sintático.
*/
#include <stdio.h>
#include <search.h>

#include <PajeEventDefinition.h>
#include <PajeTraceEvent.h>
#include <PajeException.h>
#include <poti.h>

extern "C"{
#include "parser.hh"

#include <rastro.h>

}
#include "main.h"

extern "C"
{
  extern int yylineno;
  int yylex(void);
  int yyparse ();
  extern char *yytext;
  extern int yychar;
  extern PajeEventDefinition **defsv;
  
}

int main (int argc, char **argv)
{
		printf("begin conversion");
  long long counter = 0;
	rst_init(8,6);
		//poti_init(NULL);

	  poti_header(0,0,1);

  //the global PajeDefinitions object
//  globalDefinitions = new PajeDefinitions (false);
     

    yyparse();
	 poti_close();
  		printf("end main");
  		return 1;

}

