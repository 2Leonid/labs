#include <iostream>
#include <math.h>
#include "Array.hpp"
#include "LinkedList.hpp"
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "TriangularMatrix.hpp"
#include "DiagonalMatrix.hpp"

int main(){
    int flag;
    std::cout << "Enter 1 to work with triangular matrices, 2 - to work with diagonal matrices :\n";
    std::cin >> flag;
    if(flag == 1){

        int m;
        std::cout << "Enter size of matrix :\n";
        std::cin >> m;
        TriangularMatrix<int>* test1 = new TriangularMatrix<int>(m);
        
        test1->Print();

        std::cout << "Enter size of matrix :\n";
        std::cin >> m;
        TriangularMatrix<int>* test2 = new TriangularMatrix<int>(m);
        test2->Print();

        std::cout << " \n Sum :\n";        
        TriangularMatrix<int>* sum = test1->Sum(test2);
        sum->Print();

        std::cout << "Enter scalar for multiplication on a first matrix :\n";
        int scalar;
        std::cin >> scalar;
        test1->multiplication_of_a_triangular_matrix_by_a_scalar(scalar);
        std::cout << "Result of scalar multiplication :\n";
        test1->Print();

        std::cout << "The norm of first matrix : " << test1->calculating_the_norm_of_a_matrix() << std::endl;//вычисление нормы для матрицы test1
    }else{
        if(flag == 2){
            int m;
            std::cout << "Enter size of matrix :\n";
            std::cin >> m;
            int* items = new int[m];
            int tmp;
            std::cout << "Enter " << m << " elements for diagonal:\n";
            for (int i = 0; i < m; ++i) {
                std::cin >> tmp;
                items[i] = tmp;
            }
            DiagonalMatrix<int>* test1 = new DiagonalMatrix<int>(items,m);
            test1->Print();

            std::cout << "Enter size of matrix :\n";
            std::cin >> m;
            items = new int[m];
            std::cout << "Enter " << m << " elements for diagonal:\n";
            for (int i = 0; i < m; ++i) {
                std::cin >> tmp;
                items[i] = tmp;
            }
            DiagonalMatrix<int>* test2 = new DiagonalMatrix<int>(items,m);
            test2->Print();

            DiagonalMatrix<int>* sum = test1->Sum(test2);
            std::cout << "Sum of first and second matrix :\n";
            sum->Print();

            int scalar;
            std::cout << "Enter scalar for multiplication on a first matrix :\n";
            std::cin >> scalar;
            std::cout << "Multiplication of the first matrix by a scalar = " << scalar << ":\n";
            test1->multiplying_a_diagonal_matrix_by_a_scalar(scalar);
            std::cout << "Result of scalar multiplication :\n";
            test1->Print();

            std::cout << "The norm of the first matrix : " << test1->calculating_the_norm_of_a_matrix() << std::endl;
        }
    }

    return 0;
}