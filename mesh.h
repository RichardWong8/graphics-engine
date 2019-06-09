#ifndef MESH_H
#define MESH_H

#include "mesh.h"
#include "matrix.h"
#include "draw.h"

char ** parse_args(char *line);
void parse_obj(char *file);
void add_mesh(struct matrix *vertices, struct matrix *faces);

#endif
