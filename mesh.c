#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mesh.h"
#include "matrix.h"
#include "draw.h"

/*======== void parse_obj() ==========
  Inputs:   struct matrix *polygons
            char *file

  Parses .obj file for vertices and faces
  Calls add_mesh()
  ====================*/
void parse_obj(struct matrix *polygons, char *file) {

  struct matrix * vertices;
  struct matrix * faces;

  FILE *f;
  char line[255];

  char type[3];
  double values[3];

  vertices = new_matrix(3, 100);
  faces = new_matrix(3, 100);

  f = fopen(file, "r");
  while ( fgets(line, sizeof(line), f) != NULL ) {
    line[strlen(line) - 1] = '\0';
    sscanf(line, "%s %lf %lf %lf", type, values, values+1, values+2);
    //printf("%s: %lf %lf %lf\n", type, values[0], values[1], values[2]);
    //printf("%s, %lu\n", type, strlen(type));
    if (strncmp(type, "v", strlen(type)) == 0) {
      add_point_mesh(vertices, values);
    }
    else if (strncmp(type, "f", strlen(type)) == 0) {
      add_point_mesh(faces, values);
    }
  }

  add_mesh(polygons, vertices, faces);
}

/*======== void add_point_mesh() ==========
Inputs:   struct matrix * points
          double values
Returns:
adds point (x, y, z) or face (a, b, c) to points and increment points.lastcol
if points is full, should call grow on points
====================*/
void add_point_mesh(struct matrix * points, double values[3]) {

  if ( points->lastcol == points->cols )
    grow_matrix( points, points->lastcol + 100 );

  points->m[0][ points->lastcol ] = values[0];
  points->m[1][ points->lastcol ] = values[1];
  points->m[2][ points->lastcol ] = values[2];
  points->lastcol++;
} //end add_point_mesh

/*======== void add_mesh() ==========
  Inputs:   struct matrix * polygons
            struct matrix * vertices
            struct matrix * faces

  Adds vertices in correct order to polygon matrix
  ====================*/
void add_mesh(struct matrix *polygons, struct matrix *vertices, struct matrix *faces) {
  
} //end add_mesh
