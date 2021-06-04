#include "../include/Vector3d.h"
#include "../include/test.h"

int main(){

    int c = 1;
    Vertex * C_t = NULL;
    Vertex * u = NULL;
    double a, b;
    printf("1 - complex Vector3d, 2 - double Vector3d, 3 - tests\n");
    scanf("%d", &c);
    if (c == 1){    
        do{
            printf("\n1 - scan\n2 - sum\n3 - scalar\n4 - cross\n5 - print\n0 - end\n");
            scanf("%d", &c);
            switch (c){
            case 1:
                if(C_t){
                    while(C_t){
                        deleteVertex(C_t);
                        C_t = NULL;
                    }
                }
                C_t = scan_Complex(stdin);
                print_Complex(C_t);
                break;
            case 2:
                printf("enter second Vector\n");
                u = scan_Complex(stdin);
                Vertex * tmp = sum_Complex(C_t, u);
                print_Complex(tmp);
                deleteVertex(C_t);
                deleteVertex(u);
                C_t = tmp;
                break;
            
            case 3:
                printf("enter second Vector\n");
                u = scan_Complex(stdin);
                double complex res = scalar_Complex(C_t, u);
                printf("{%lf + %lf * I}", __real__ (res), __imag__ (res));
                deleteVertex(u);
                break;
            case 4:
                printf("enter second Vector\n");
                u = scan_Complex(stdin);
                Vertex * tmp1 = cross_Complex(C_t, u);
                print_Complex(tmp1);
                deleteVertex(C_t);
                deleteVertex(u);
                C_t = tmp1;
                break;
           
            case 5:
                print_Complex(C_t);
                break;
            case 0:
                while(C_t){
                    deleteVertex(C_t);
                    C_t = NULL;
                }
                return 0;
            default:
                continue;
            }
        } 
        while (c != 0);

    }
    else if (c == 2){
        do{
            printf("\n1 - scan\n2 - sum\n3 - scalar\n4 - cross\n5 - print\n0 - end\n");
            scanf("%d", &c);
            switch (c){
            case 1:
                if(C_t){
                    while(C_t){
                        deleteVertex(C_t);
                        C_t = NULL;
                    }
                }
                C_t = scan_double(stdin);
                print_double(C_t);
                break;
            case 2:
                printf("enter second Vector\n");
                u = scan_double(stdin);
                Vertex * tmp = sum_double(C_t, u);
                print_double(tmp);
                deleteVertex(C_t);
                deleteVertex(u);
                C_t = tmp;
                break;
            
            case 3:
                printf("enter second Vector\n");
                u = scan_double(stdin);
                double res = scalar_double(C_t, u);
                printf("%lf", res);
                deleteVertex(u);
                break;
            case 4:
                printf("enter second Vector\n");
                u = scan_double(stdin);
                Vertex * tmp2 = cross_double(C_t, u);
                print_double(tmp2);
                deleteVertex(C_t);
                deleteVertex(u);
                C_t = tmp2;
                break;
           
            case 5:
                print_double(C_t);
                break;
            case 0:
                while(C_t){
                    deleteVertex(C_t);
                    C_t = NULL;
                }
                return 0;
            default:
                continue;
            }
        } while (c != 0);
    } else if (c == 3) {
        test_all();
    }

    return 0;
}
