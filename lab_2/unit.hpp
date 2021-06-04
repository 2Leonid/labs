#ifndef UNIT_HPP
#define UNIT_HPP
#include <iostream>

template<class T>
T * read(std::istream & in, int size){
    T * res = new T[size];
    for(int i = 0; i < size; i++) {
        in >> res[i];
    }
    #ifdef DEBUG 
        std::cerr << "Read Object type T**" << res << " " << size << std::endl;
    #endif
    return res;
}


template<class T>
void clear(T* masivblackhole, int size){
    #ifdef DEBUG 
        std::cerr << "Destroy Object type T**" << masivblackhole << " " << size <<std::endl;
    #endif
    
    delete [] masivblackhole;
}


template<class T>
int comparedata(Sequence<T> * ptr, T* data, int count){
    try{
        for(int i = 0; i < count ; i++){
            if(ptr->Get(i) != data[i]){
                std::cerr << "error in :" << ptr->Get(i) << "!=" << data[i] << std::endl;
            }
        }
    }catch(const char * s){
        std::cerr << s << std::endl;
        return -1;
    }
    return 0;
}

template<class T>
int comparedatatm(TriangularMatrix<T> * ptr, T* data, int count){
    try{
        for(int i = 0; i < count ; i++){
            for(int j = 0; j  < i + 1; j++){
                if(std::abs(ptr->Get(i, j) - data[((i+1)*i)/2 + j])> 0.0001){
                    std::cerr << "error in :" << ptr->Get(i , j) << "!=" << data[(i*(i+1))/2] << std::endl;
                }
            }
        }
    }catch(const char * s){
        std::cerr << s << std::endl;
        return -1;
    }
    return 0;
}

#endif