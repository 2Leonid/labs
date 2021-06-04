//#define DEBUG

#include <fstream>
#include <iostream>
#include <math.h>
#include "Array.hpp"
#include "LinkedList.hpp"
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "TriangularMatrix.hpp"
#include "DiagonalMatrix.hpp"
#include "unit.hpp"

int dynamictestcreate(){ // test for debug memory error and memleak
    DynamicArray<int> a; // first construction
    DynamicArray<int> b(10); // second
    int * array;
    array = new int[10];
    for(int i = 0;i < 10;i++){
        array[i] = i;
    }
    DynamicArray<int> c(array, 10); // firdth
    DynamicArray<int> d = c; // copy
    delete[] array;
    return 0;
}

int dynamictestget(){
    int * array;
    int p = 0;
    array = new int[10];
    for(int i = 0; i < 10; i++){
        array[i] = i;
    }
    DynamicArray<int> a(array, 10);
    try{
        std::cout << a.Get(0) << std::endl;
    }catch(char const * s){
        std::cerr << s << std::endl;
        p = -1;
    }
    delete[] array;
    return p;
}


int concatsequencetest(){
    std::ifstream in("test/concatsequence");
    if(!in.is_open()){
        std::cerr << "FILE NOT OPEN" << std::endl;
        return -2;
    }
    int count = 0;
    in >> count;
    for(int n = 0; n < count; n++){
        int size1 = 0, size2 = 0, size3 = 0;
        in >> size1;
        int* data1, *data2, *data3;
        data1 = read<int>(in, size1);
        in >> size2;
        data2 = read<int>(in, size2);
        in >> size3;
        data3 = read<int>(in, size3);
        ArraySequence<int> a1(data1,size1);
        ArraySequence<int> a2(data2,size2);
        ArraySequence<int> * a3 = a1.Concat(&a2);
        std::cerr << "Concat in ArraySequence" << std::endl;
        comparedata<int>(a3, data3, size3);

        LinkedListSequence<int> l1(data1,size1);
        LinkedListSequence<int> l2(data2,size2);
        LinkedListSequence<int> * l3 = l1.Concat(&l2);
        std::cerr << "Concat in LinkedListSequence" << std::endl;
        comparedata<int>(l3, data3, size3);

        clear<int>(data1, size1);
        clear<int>(data2, size2);
        clear<int>(data3, size3);
    }
    return 0;
}

int subsequencetest(){
    std::ifstream in("test/subsequence");
    if(!in.is_open()){
        std::cerr << "FILE NOT OPEN" << std::endl;
        return -2;
    }
    int count = 0;
    in >> count;
    for(int n = 0; n < count; n++){
        int size1 = 0, start = 0, end = 0;
        in >> size1;
        int* data1, *data2;
        data1 = read<int>(in, size1);
        in >> start >> end;
        data2 = read<int>(in, end - start);
        ArraySequence<int> a1(data1, size1);
        ArraySequence<int> * a3 = a1.GetSubsequence(start, end);
        std::cerr << "SubSequence in ArraySequence" << std::endl;
        comparedata<int>(a3, data2, end - start);

        LinkedListSequence<int> l1(data1,size1);
        LinkedListSequence<int> * l3 = l1.GetSubsequence(start, end);
        std::cerr << "SubSequence in LinkedListSequence" << std::endl;
        comparedata<int>(l3, data2, end - start);

        clear<int>(data1, size1);
        clear<int>(data2, end - start + 1);
    }
    return 0;
}

int mattestsum(){
    std::ifstream in("test/tmatsum");
    if(!in.is_open()){
        std::cerr << "FILE NOT OPEN" << std::endl;
        return -2;
    }
    int count = 0;
    in >> count;
    for(int n = 0; n < count; n++){
        int size = 0;
        in >> size;
        int * data3;
        TriangularMatrix<int> v1(size, in);
        TriangularMatrix<int> v2(size, in);
        data3 = read<int>(in, size*(size + 1)/2);
        TriangularMatrix<int> * v3 = v1.Sum(&v2);
        std::cerr << "MatrixSum test:" << std::endl;
        comparedatatm<int>(v3, data3, size);
        clear<int>(data3,size);
        delete v3;
    }
    return 0;
}

int mattestnorm(){
    std::ifstream in("test/tmatnorm");
    if(!in.is_open()){
        std::cerr << "FILE NOT OPEN" << std::endl;
        return -2;
    }
    int count = 0;
    in >> count;
    for(int n = 0; n < count; n++){
        int size = 0;
        double res = 0;
        in >> size;
        TriangularMatrix<double> v1(size, in);
        double maybe = v1.calculating_the_norm_of_a_matrix();
        in >> res;
        std::cerr << "MatrixNorm test:" << std::endl;
        if(std::abs(maybe - res) > 0.00001){
            std::cerr << "Error in TrangularMatrixNorm test" << maybe << " " << res << std::endl;
        }
    }
    return 0;
}

int mattestscalar(){
    std::ifstream in("test/tmatscalar");
    if(!in.is_open()){
        std::cerr << "FILE NOT OPEN" << std::endl;
        return -2;
    }
    int count = 0;
    in >> count;
    for(int n = 0; n < count; n++){
        int size = 0, scal = 0;
        in >> size;
        int* data2;
        TriangularMatrix<int> v1(size,in);
        in >> scal;
        v1.multiplication_of_a_triangular_matrix_by_a_scalar(scal);
        data2 = read<int>(in, size*size);
        std::cerr << "MatrixScalar test:" << std::endl;
        comparedatatm<int>(&v1, data2, size);
        
        clear<int>(data2, size);
    }
    return 0;
}

int main(int argc,  char ** argv){
    std::cout << "\\\\\\\\\\\\BENCHMAKER2000\\\\\\\\\\\\" << std::endl;
    dynamictestcreate();
    dynamictestget();
    mattestscalar();
    mattestnorm();
    mattestsum();
    subsequencetest();
    concatsequencetest();
    return 0;
}

