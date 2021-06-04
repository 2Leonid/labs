#ifndef Vertex_H
#define Vertex_H

#pragma once

#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <stdlib.h>


#define gc(a, x) *(double _Complex *)((*a).x)
#define gd(a, x) *(double *)((*a).x)
#define grc(a, x) *(_C_double_complex *)((*a).x)

#define func_Complex(name)  name->sum = sum_Complex; \
                            name->cross = cross_Complex; \
                            name->scan = scan_Complex

#define func_double(name)  name->sum = sum_double; \
                            name->cross = cross_double; \
                            name->scan = scan_double   

typedef struct Vertex
{
    void *x;
    void *y;
    void *z;
    struct Vertex *(*sum)(struct Vertex *,struct Vertex *);
    struct Vertex *(*cross)(struct Vertex *,struct Vertex *);
    struct Vertex *(*scan)();
} Vertex;

Vertex *create_Complex();
Vertex *create_double();
Vertex *sum_Complex(Vertex *a, Vertex *b);
Vertex *sum_double(Vertex *a, Vertex *b);
double complex scalar_Complex(Vertex *a, Vertex *b);
double scalar_double(Vertex *a, Vertex *b);
Vertex *cross_Complex(Vertex *a, Vertex *b);
Vertex *cross_double(Vertex * a, Vertex * b);
void print_Complex(Vertex *a);
void print_double(Vertex *a);
Vertex *scan_Complex();
Vertex *scan_double();
void deleteVertex(Vertex*);
void compare_complex (Vertex * f, Vertex * s, const char* p);
void compare_double (Vertex * f, Vertex * s, const char* p);
#endif //Vertex_H
