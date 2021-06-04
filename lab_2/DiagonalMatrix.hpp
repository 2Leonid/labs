#ifndef DiagonalMatrix_hpp
#define DiagonalMatrix_hpp


template<typename T>
class DiagonalMatrix{
private:
    DynamicArray<T> data;//здесь хранятся все значения матрицы
    int m;//размерность матрицы
public:
    DiagonalMatrix(){//конструктор по умолчанию
        m = 0;
    }
    DiagonalMatrix(T* items,int count){//конструктор по массиву
        m = count;
        data.Resize(count);
        for (int i = 0; i < m; ++i) {
            data.Set(i,items[i]);
        }
    }
    DiagonalMatrix(DiagonalMatrix<T>* example){//копиконструктор
        m = example->GetSize();
        data.Resize(m);
        for (int i = 0; i < m; ++i) {
            data.Set(i,example->Get(i));
        }
    }

    //в геттере и сеттере единственный индекс в качестве параметра,так как мы работаем только с диагональю
    int GetSize(){
        return m;
    }
    T Get(int i){
        return data.Get(i);
    }
    void Set(int i,T value){
        data.Set(i,value);
    }

    DiagonalMatrix<T>* Sum(DiagonalMatrix<T>* example){
        if(m == example->GetSize()){
            DiagonalMatrix<T>* result = new DiagonalMatrix<T>(this);
            for (int i = 0; i < m; ++i) {
                result->Set(i,result->Get(i) + example->Get(i));
            }
            return result;
        }else{
            std::cout << "Can't sum ! ! !\n";
            return nullptr;
        }
    }
    void multiplying_a_diagonal_matrix_by_a_scalar(T scalar){
        if(this != nullptr){
            for (int i = 0; i < m; ++i) {
                data.Set(i,data.Get(i) * scalar);
            }
        }
    }
    T calculating_the_norm_of_a_matrix(){//вычисление нормы данной матрицы
        if(this != nullptr && m != 0){
            T result = data.Get(0);//в качестве начального результата берем первый элемент на главной диагонали
            for (int i = 0; i < m; ++i) {
                if(data.Get(i) >= result)
                    result = data.Get(i);
            }
            return result;
        }else{
            std::cout << "Error of calculations ! ! !\n";
            return -1;//возвращаем -1 так как нужно вернуть какое то число
        }
    }

    void Print(){
        if(this != nullptr){
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    if(i == j)
                        std::cout << data.Get(i) << "\t";
                    else
                        std::cout << "0" << "\t";
                }
                std::cout << std::endl;
            }
        }else{
            std::cout << "Can't print ! ! !\n";
        }

    }

};

#endif