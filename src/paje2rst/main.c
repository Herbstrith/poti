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
#include <argp.h>
#include "main.h"

static char doc[] = "Translates from textual to binary Paje file format";
static char args_doc[] = "{file.paje} {outputfilename.rst}";

static struct argp_option options[] = {
  { 0 }
};

#define MAX_INPUT_SIZE 2
struct arguments {
  char *input[MAX_INPUT_SIZE];
  int input_size;
};

static int parse_options (int key, char *arg, struct argp_state *state)
{
  struct arguments *arguments = (struct arguments*)state->input;
  switch (key){
  case ARGP_KEY_ARG:
    if (arguments->input_size == MAX_INPUT_SIZE) {
      /* Too many arguments. */
      argp_usage (state);
    }
    arguments->input[state->arg_num] = arg;
    arguments->input_size++;
    break;
  case ARGP_KEY_END:
    /* if (state->arg_num < 0) */
    /*   /\* Not enough arguments. *\/ */
    /*   argp_usage (state); */
    break;
  default: return ARGP_ERR_UNKNOWN;
  }
  return 0;
}

static struct argp argp = { options, parse_options, args_doc, doc };

extern FILE* yyin;
void yyerror (char const *s);
void yyerror (char const *s) {
  fprintf (stderr, "%d %s\n", yylineno, s);
}

int main (int argc, char **argv)
{
  struct arguments arguments;
  char* filename = (char *) malloc(sizeof(char) * (80));
  sprintf(filename, "output.rst");
  bzero (&arguments, sizeof(struct arguments));
  if (argp_parse (&argp, argc, argv, 0, 0, &arguments) == ARGP_KEY_ERROR){
    fprintf(stderr,
            "[paje2rst] at %s, "
            "error during the parsing of parameters\n",
            __FUNCTION__);
    return 1;
  }

  if (arguments.input_size > 0){
    yyin = fopen (arguments.input[0], "r");
    if (yyin == NULL){
      fprintf(stderr,
	      "[paje2rst] at %s, "
	      "cannot open file %s\n",
	      __FUNCTION__, arguments.input[0]);
      return 1;
    }
    if(arguments.input_size > 1){
        sprintf(filename, "%s",arguments.input[1]);
    }
  }
  
  poti_init(POTI_BINARY, filename, -1, -1);
  int ret = yyparse();
  poti_close();
  return ret;
}

