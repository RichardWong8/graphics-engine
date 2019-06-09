#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mesh.h"
#include "matrix.h"
#include "draw.h"

/*======== void parse_obj() ==========
  Inputs:   char *file

  Parses .obj file for vertices and faces
  ====================*/
void parse_obj(char *file) {

  struct matrix * vertices;
  struct matrix * faces;

  FILE *f;
  char line[255];

  char type[3];
  double values[3];

  f = fopen(file, "r");
  while ( fgets(line, sizeof(line), f) != NULL ) {
    line[strlen(line) - 1] = '\0';
    sscanf(line, "%s %lf %lf %lf", type, values, values+1, values+2);
    //printf("%s: %lf %lf %lf\n", type, values[0], values[1], values[2]);
  }

}

/*======== void add_mesh() ==========
  Inputs:   struct matrix * vertices
            struct matrix * faces

  Adds vertices in correct order to polygon matrix
  ====================*/
void add_mesh(struct matrix *vertices, struct matrix *faces) {

}
