#ifndef __SHADER__
#define __SHADER__

#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>

unsigned int vertexShader, fragmentShader, programId;

const char *fload(const char *);
unsigned long get_flen(FILE *);
int shader(const char *, const char *);
void shaderUse();

#endif
