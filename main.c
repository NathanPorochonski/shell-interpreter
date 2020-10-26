#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>
#include "processPath.h"
#include "runExec.h"

/*A simple shell in which the user can build a path variable and attempt to 
run a provided executable if it is located in one of the provided paths*/
int main() {
  
  char path[4096];
  path[0] = '\0';

  while (1) {

    char input[1024];
    printf("\n$ ");
    fgets(input, 1024, stdin);
    char *p = strtok(input, " \n");
    char *tok[1024];
    int size = 0;
    
    //Creates an string array from the input commands
    while (p != NULL) {
        tok[size] = p;
        p = strtok(NULL, " \n");
        size++;
    }
    tok[size] = NULL;

    //If input command is "path"
    if (strcmp(tok[0], "path") == 0) {

      if (size == 1) {
        printf("%s\n", path);
      }
      else { 
        strcpy(path, processPath(tok, path, size));
      }
    }
    //If input command is "cd"
    else if (strcmp(tok[0], "cd") == 0) {

      if (chdir(tok[1]) == 0) {
        //Gets and prints current working directory
        char cwd[PATH_MAX];
        getcwd(cwd, sizeof(cwd));
        printf("Directory changed to %s\n", cwd);
      }
      else {
        printf("Error: Directory not found\n");
      }
    }
    //If input command is "quit"
    else if (strcmp(tok[0], "quit") == 0) {
      exit(1);
    }
    //Attempts to run input command as an executable
    else {
       
      int status;
      int pid;
      if ((pid = fork()) == -1) {
        printf("\nError: Unable to fork process");
      }
      else if (pid == 0) {
        runExec(tok, path);
      } 
      else {
        wait(&status);
      }
    }
  }
  return 0;
}
