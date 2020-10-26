#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Checks if the path variable already contains a provided path.
Returns 1 if it does. Returns 0 if it does not.*/
int contains(char *path, char *entry) {

  char *p = strtok(path, ":\0");
  char *pathEntries[1024];
  int pathSize = 0;

  //Creates an string array of each path from the path variable
  while (p != NULL) {
    pathEntries[pathSize] = p;
    p = strtok(NULL, ":\0");
    pathSize++;
  }
  //Checks if path variable contains the path
  for (int i = 0; i < pathSize; i++) {
    if (strcmp(pathEntries[i], entry) == 0) {
      return 1;
    }
  }
  return 0;
}

/*Either adds a provided path or removes one from the
path variable and returns the updated path variable*/
char *processPath(char **tok, char *path, int tokSize){
  
  char temp[4096];
  strcpy(temp, path);

  if (tokSize != 3) {
    printf("Error: Invalid input\n");
  }

  //If user chooses to add a path
  else if (strcmp(tok[1], "+") == 0) {
    
    if (contains(temp, tok[2]) == 1) {
      printf("Error: path already in variable\n");
    }
    else {
      if (path[0] != '\0') {
        path = strcat(path, ":");
      }
      path = strcat(path, tok[2]);
    }
  }
  //If user chooses to remove a path
  else if (strcmp(tok[1], "-") == 0) {

    if (contains(temp, tok[2]) == 0) {
      printf("Error: path not in variable\n");
    }
    else {

      int len = strlen(tok[2]);
      char *p = path;
      p = strstr(p, tok[2]);
      if ((p - path) + len + 1 < strlen(path)) {
        len++;
      }
      while ((p = strstr(p, tok[2])) != NULL) {
        memmove(p, p + len, strlen(p + len) + 1);
      }
      if (path[strlen(path)-1] == ':') {
        path[strlen(path)-1] = '\0';
      }
    }
  }
  else {
    printf("Error: Invalid path flag\n");
  }
  return path;
}
