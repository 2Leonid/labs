#include "../include/test.h"


void test_all() {
	Vertex * t_f = NULL;
	Vertex * t_s = NULL;
	Vertex * tmp = NULL;
	Vertex * res = NULL;

	FILE* t = fopen("test_sum", "r");
	if (!t) {
		fprintf(stderr, "file \"t\" no open\n");
	}

//complex
	t_f = scan_Complex(t);
	t_s = scan_Complex(t);

	//sum
	tmp = sum_Complex(t_f, t_s);
	res = scan_Complex(t);
	compare_complex(tmp, res, "complex sum");
	deleteVertex(tmp);
	deleteVertex(res);


	//scalar 
	double a, b;
    fscanf(t, "%lf%lf", &a, &b);
    double complex res_s = a + b * I;
	double complex tmp_s = scalar_Complex(t_f, t_s);
	if (creal(tmp_s) == creal(res_s) && cimag(tmp_s) == cimag(res_s)){
		printf("complex scalar is true\n");
	} else {
		printf("complex scalar is false\n");
	}

	//cross
	tmp = cross_Complex(t_f, t_s);
	res = scan_Complex(t);
	compare_complex(tmp, res, "complex cross");
	deleteVertex(tmp);
	deleteVertex(res);

	deleteVertex(t_f);
	deleteVertex(t_s);

//double
	t_f = scan_double(t);
	t_s = scan_double(t);

	//sum 
	tmp = sum_double(t_f, t_s);
	res = scan_double(t);
	compare_double(tmp, res, "double sum");
	deleteVertex(tmp);
	deleteVertex(res);

	//scalar 
	double res1 = 0;
	fscanf(t, "%lf", &res1); 
	double tmp1 = scalar_double(t_f, t_s);
	if (tmp1 == res1){
		printf("complex scalar is true\n");
	} else {
		printf("complex scalar is false\n");
	}

	//cross
	tmp = cross_double(t_f, t_s);
	res = scan_double(t);
	compare_double(tmp, res, "double cross");
	deleteVertex(tmp);
	deleteVertex(res);

	deleteVertex(t_f);
	deleteVertex(t_s);

	fclose(t);

}
