#include "../include/Vector3d.h"                        

Vertex *create_Complex()
{
    Vertex *vec = (Vertex *)malloc(sizeof(Vertex));
    (*vec).x = malloc(sizeof(double _Complex));
    (*vec).y = malloc(sizeof(double _Complex));
    (*vec).z = malloc(sizeof(double _Complex));
    func_Complex(vec);
    return vec;
}

Vertex *create_double()
{
    Vertex *vec = (Vertex *)malloc(sizeof(Vertex));
    (*vec).x = malloc(sizeof(double));
    (*vec).y = malloc(sizeof(double));
    (*vec).z = malloc(sizeof(double));
    func_double(vec);
    return vec;
}

/// сумма векторов
Vertex *sum_Complex(Vertex *a, Vertex *b)
{
    Vertex *vec = create_Complex();           
    *(double _Complex *)vec->x = (*(double _Complex *)((*a).x) + *(double _Complex *)((*b).x));
    *(double _Complex *)vec->y = (*(double _Complex *)((*a).y) + *(double _Complex *)((*b).y));
    *(double _Complex *)vec->z = (*(double _Complex *)((*a).z) + *(double _Complex *)((*b).z));
    return vec;
}

/// сумма векторов
Vertex *sum_double(Vertex *a, Vertex *b)
{
    Vertex *vec = create_double();               
    *(double *)vec->x = (*(double *)((*a).x) + *(double *)((*b).x));
    *(double *)vec->y = (*(double *)((*a).y) + *(double *)((*b).y));
    *(double *)vec->z = (*(double *)((*a).z) + *(double *)((*b).z));
    return vec;
}

/// скалярное произведение
double complex scalar_Complex(Vertex *a, Vertex *b)
{              
    double complex res =  gc(a, x) * gc(b, x) + gc(a, y) * gc(b, y) + gc(a, z) * gc(b, z);
    return res;
}

/// скалярное произведение
double scalar_double(Vertex *a, Vertex *b)
{               
    double res = gd(a, x) * gd(b, x) + gd(a, y) * gd(b, y) + gd(a, z) * gd(b, z);
    return res;
}

/// векторное произведение
Vertex *cross_Complex(Vertex *a, Vertex *b)
{
    Vertex *vec = create_Complex();                 
    gc(vec, x) = gc(a, y) * gc(b, z) - gc(a, z) * gc(b, y);
    gc(vec, y) = -gc(a, x) * gc(b, z) + gc(a, z) * gc(b, x);
    gc(vec, z) = gc(a, x) * gc(b, y) - gc(a, y) * gc(a, x);
    return vec;
}

/// векторное произведение
Vertex *cross_double(Vertex * a, Vertex * b)
{
    Vertex *vec = create_double();                 
    gd(vec, x) = gd(a, y) * gd(b, z) - gd(a, z) * gd(b, y);
    gd(vec, y) = -gd(a, x) * gd(b, z) + gd(a, z) * gd(b, x);
    gd(vec, z) = gd(a, x) * gd(b, y) - gd(a, y) * gd(a, x);
    return vec;
}

/// вывод вектора
void print_Complex(Vertex *a)
{
    printf("{%.3lf %+.3lfi, %.3lf %+.3lfi, %.3lf %+.3lfi}\n", creal(gc(a, x)), cimag(gc(a, x)), creal(gc(a, y)), cimag(gc(a, y)), creal(gc(a, z)), cimag(gc(a, z)));
}

void print_double(Vertex *a)
{
    printf("{%.3f, %.3f, %.3f}\n", gd(a,x), gd(a,y), gd(a,z));
}

/// ввод вектора
Vertex *scan_Complex(FILE* f){
    Vertex *t = create_Complex();
    double a, b;
    fscanf(f, "%lf%lf", &a, &b);
    gc(t, x) = a + b * I;
    fscanf(f, "%lf%lf", &a, &b);
    gc(t, y) = a + b * I;
    fscanf(f, "%lf%lf", &a, &b);
    gc(t, z) = a + b * I;
    return t;
}

/// ввод вектора
Vertex *scan_double(FILE* f)
{
    Vertex *t = create_double();
    double a, b, c;
    fscanf(f, "%lf%lf%lf", &a, &b, &c);
    gd(t, x) = a;
    gd(t, y) = b;
    gd(t, z) = c;
    return t;
}

void deleteVertex(Vertex * a) {
    free(a->x);
    free(a->y);
    free(a->z);
    free(a);
}

void compare_complex (Vertex * f, Vertex * s, const char* p) {
    if ( creal(gc(f, x)) == creal(gc(s, x)) &&  creal(gc(f, y)) == creal(gc(s, y)) && creal(gc(f, z)) == creal(gc(s, z)) && cimag(gc(f, x)) == cimag(gc(s, x)) && cimag(gc(f, y)) == cimag(gc(s, y)) && cimag(gc(f, z)) == cimag(gc(s, z)) ) {
        printf("%s is true\n", p);
    } else {
        printf("%s is false\n", p);
    }
}

void compare_double (Vertex * f, Vertex * s, const char* p) {
    if ( gd(f,x) == gd(s,x) && gd(f,y) == gd(s,y) && gd(f,z) == gd(s,z) ) {
        printf("%s is true\n", p);
    } else {
        printf("%s is false\n", p);
    }
}



