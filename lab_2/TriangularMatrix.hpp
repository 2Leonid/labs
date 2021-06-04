#ifndef TriangularMatrix_hpp
#define TriangularMatrix_hpp


template<typename T>
class TriangularMatrix{
private:
    DynamicArray<DynamicArray<T>> data;//здесь хранятся все значения матрицы
    int m;//размерность матрицы
public:
    TriangularMatrix(){
        m = 0;
    }

    TriangularMatrix(TriangularMatrix<T>* example){//копирующий конструктор
        m = example->GetSize();
        data.Resize(m);

        for (int i = 0; i < m; ++i) {
            data[i].Resize(i+1);
            for (int j = 0; j < i + 1; ++j) {
                data[i].Set(j,example->Get(i,j));
            }
        }
    }

    TriangularMatrix(int size, std::istream & in){//конструктор с вводом элементов с консоли

        m = size;
        data.Resize(m);

        for (int i = 0; i < m; ++i) {
            data[i].Resize(i+1);
            //std::cout << "Enter " << i + 1 << " values for " << i <<" matrix string\n";
            for (int j = 0; j < i + 1; ++j) {
                T value;
                if(in >> value)
                    data[i].Set(j,value);
                else{
                    //std::cout << "Invalid value ! ! !\n";
                    m = 0;
                    return;
                }
            }
        }
    }

    TriangularMatrix(int size){//конструктор с вводом элементов с консоли

        m = size;
        data.Resize(m);

        for (int i = 0; i < m; ++i) {
            data[i].Resize(i+1);
            std::cout << "Enter " << i + 1 << " values for " << i <<" matrix string\n";
            for (int j = 0; j < i + 1; ++j) {
                T value;
                if(std::cin >> value)
                    data[i].Set(j,value);
                else{
                    std::cout << "Invalid value ! ! !\n";
                    m = 0;
                    return;
                }
            }
        }
    }

    //методы для получения и записи характеристик матрицы
    int GetSize(){
        return m;
    }
    T Get(int i,int j) {
        return data[i].Get(j);
    }
    void Set(int i,int j,T value){
        data[i].Set(j,value);
    }

    TriangularMatrix<T>* Sum(TriangularMatrix<T>* example){//сумма матрицы,переданной в качестве параметра,и данной матрицы
        if(m == example->GetSize()){
            TriangularMatrix<T>* result = new TriangularMatrix<T>(example);//создание результирующей матрицы как копии переданной в качестве параметра
                                                                    //для последующего сложения с той матрицей,у которой этот метод вызван
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < i + 1; ++j) {
                    result->Set(i,j,data[i].Get(j) + result->Get(i,j));
                }
            }
            return result;
        }else{
            return nullptr;
        }
    }

    void multiplication_of_a_triangular_matrix_by_a_scalar(T scalar){//умножение данной матрицы на скаляр
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < i + 1; ++j) {
                this->Set(i,j,this->Get(i,j) * scalar);
            }
        }
    }

    T calculating_the_norm_of_a_matrix(){//вычисление нормы данной матрицы
        if(this != nullptr && m != 0){
            T result = this->Get(0,0);//в качестве начального значения результата берем элемент с индексами i = 0 и j = 0
            for (int i = 0; i < m; ++i) {
                T tmp = 0;
                for (int j = 0; j < i + 1; ++j) {
                    tmp += this->Get(i,j);
                }
                if(tmp >= result)
                    result = tmp;
            }
            return result;
        }else{
            std::cout << "Error of calculations ! ! !\n";
            return -1;//возвращаем -1 так как нужно вернуть какое то число
        }

    }

    void Print(){
        if(this != nullptr && m != 0){
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < i + 1; ++j) {
                    std::cout << data[i].Get(j) << " ";
                }
                std::cout << std::endl;
            }
        }else{
            std::cout << "Can't print ! ! !\n";
        }
    }

};

#endif