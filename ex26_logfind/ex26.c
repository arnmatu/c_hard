/* WARNING:  This code is fresh and potentially isn't correct yet. */
#define NDEBUG

#include <stdio.h>
#include <glob.h>
#include <stdlib.h>
#include <string.h>
#include "dbg.h"

//globals
#define AND_CONDITION 0
#define OR_CONDITION 1
#define MAX_LINE 1024






int scan_file(const char *filename, int count, char **words, int condition){
  FILE *file = NULL;
  char *line =NULL ;
  int *res = calloc(count, sizeof(int));
  int found =0;
  line = malloc(sizeof(char)*MAX_LINE);
  file = fopen(filename, "r");
  check(file, "Could not open file %s", filename);
  if (file != NULL){
    while (fgets(line,MAX_LINE-1,file) != NULL && !found)
    {
          for (int i = 0; i < count; i++)
          {
            if( (strcasestr(line,words[i])) != NULL && (condition == OR_CONDITION)) {
              found =1;
            }
            if( (strcasestr(line,words[i])) != NULL && (condition == AND_CONDITION)) res[i]++;
          }
    }
    for(int j = 0; (j < count && (condition == AND_CONDITION));  j++)
      {
        if(res[j] >0) found++;
      }
   if((found == (count-1) && condition == AND_CONDITION) || (found && (condition == OR_CONDITION))){
       printf("WORDS FOUND IN: %s",filename);
       free(line);
       free(res);
       return 0;
   }
  }
error:
  free(res);
  free(line);
  return -1;
}


char ** init(int argc, char *argv[], char **words, int *compare_oper){
  //check if number of arguments are ok
  check((argc > 1), "Incorrect number of arguments.")
  //allocate array of pointers
  words = (char **)malloc(argc * sizeof(char *));
  //accept initial OR_CONDITION
  *compare_oper = OR_CONDITION;
  for (int i = 1; i < argc; i++){
    words[i-1] = argv[i];
    if (strcmp(words[i-1],"-o") == 0)
    {
      *compare_oper = AND_CONDITION;
    }
  }
  return words;
error:
  return NULL;
}

int list_files(glob_t *pglob)
{
    char *line = calloc(MAX_LINE, 1);
    FILE *file = fopen(".logfile", "r");
    int glob_flags = GLOB_TILDE;
    int i = 0;
    int rc = -1;

    check(pglob != NULL, "Invalid glob_t given.");
    check_mem(line);
    check(file, "Failed to open .logfind. Make that first.");

    while(fgets(line, MAX_LINE-1, file) != NULL) {
        line[strlen(line) - 1] = '\0'; // drop the \n ending
        debug("Globbing %s", line);

        rc = glob(line, glob_flags, NULL, pglob);
        check(rc == 0 || rc == GLOB_NOMATCH, "Failed to glob.");

        // dumb work around to a stupid design in glob
        if(glob_flags == GLOB_TILDE) glob_flags |= GLOB_APPEND;
    }

    for(i = 0; i < pglob->gl_pathc; i++) {
        debug("Matched file: %s", pglob->gl_pathv[i]);
    }

    rc = 0; // all good

error: // fallthrough
    if(line) free(line);
    return rc;
}



int main (int argc, char *argv[]){
  char **words = NULL;
  int compare_oper;
  glob_t files_found;


  words = init(argc,argv,words,&compare_oper);
  list_files(&files_found);

  for(int i = 0; i < files_found.gl_pathc; i++) {
       scan_file(files_found.gl_pathv[i], argc-1,words,compare_oper);
   }

free(words);
  return 0;
error:
  return 1;
}
