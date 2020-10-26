#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

/*Searches for a provided executable in each directory
of the path variable and attempts to run it if found*/
void runExec(char **tok, char *path) {

  char *p = strtok(path, ":\0");
  char *pathEntries[1024];
  int size = 0;
  
  //Creates an string array of each path from the path variable
  while (p != NULL) {
    pathEntries[size] = p;
    p = strtok(NULL, ":\0");
    size++;
  }
  
  int found = 0;

  /*Creates a directory pointer to search for the executable in each
  directory of the path variable and attempts to run it if found*/
  for (int i = 0; i < size; i++) {

    DIR *dirp;
    struct dirent *direntp;

    dirp = opendir(pathEntries[i]);
    while ((direntp = readdir(dirp)) != NULL) {

      if (strcmp(tok[0], direntp -> d_name) == 0) {

        char *execPath = pathEntries[i];
        strcat(execPath, "/");
        strcat(execPath, tok[0]);

        if (execv(execPath, tok) < 0) {
          printf("Error: unable to run executable");
          exit(1);
        }
        found = 1;
      }
    }
    closedir(dirp);
  }

  if (found == 0) {
    printf("Error: Executable not found\n");
    exit(1);
  }
}
