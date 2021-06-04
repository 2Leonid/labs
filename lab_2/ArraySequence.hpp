#ifndef ArraySequence_hpp
#define ArraySequence_hpp


template<typename T>
class ArraySequence : public Sequence<T>{
public:

    ~ArraySequence () {
        DATA.~ DynamicArray();
    }

    ArraySequence(){
        DynamicArray<T>* tmp = new DynamicArray<T>();
        DATA = *tmp;
    }

    ArraySequence(T* item,int count){

        DynamicArray<T>* tmp = new DynamicArray<T>(item,count);
        DATA = *tmp;

    }

    ArraySequence(ArraySequence<T>& array){//копиконструктор для параметра ArraySequence

        DynamicArray<T>* tmp = new DynamicArray<T>(array.DATA);//конструктор копирует соответствующее поле
        DATA = *tmp;
    }

    ArraySequence(LinkedList<T>& list){//копиконструктор для параметра LinkedList
        T* items;
        items = (T*)malloc(sizeof(T)*(list.GetLength()));
        for (int i = 0; i < list.GetLength(); ++i) {
            items[i] = list.Get(i);
        }

        DynamicArray<T>* tmp = new DynamicArray<T>(items,list.GetLength());
        DATA = *tmp;
    }
    int GetLength(){
        return DATA.GetSize();
    }
    T Get(int index){
        return DATA.Get(index);
    }
    T GetFirst(){
        return DATA.Get(0);
    }
    T GetLast(){
        return DATA.Get(DATA.GetSize()-1);
    }

    void Append(T item){
        DATA.Append(item);
    }
    void Prepend(T item){
        DATA.Prepend(item);
    }
    void InsertAt(T item,int index){//void Set(int index,T value)
        if(index >= DATA.GetSize() || index < 0)
            throw "\nInsertAt Message : Index Out Of Range";
        DATA.Resize(DATA.GetSize()+1);
        for (int i = DATA.GetSize()-2; i >= index ; --i) {
            DATA.Set(i+1,DATA.Get(i));
        }
        DATA.Set(index,item);
    }
    void Print(){
        DATA.Print();
    }

    ArraySequence<T>* GetSubsequence(int startIndex,int endIndex){
        T* items = (T*)malloc(sizeof(T)*(endIndex-startIndex));
        for (int i = startIndex; i < endIndex; ++i) {
            items[i-startIndex] = DATA.Get(i);
        }
        ArraySequence<T>* result = new ArraySequence<T>(items,endIndex-startIndex);
        return result;
    }

    ArraySequence<T>* Concat(Sequence<T>* list){
        if(list->GetLength() != 0){
            T* items = (T*)malloc(sizeof(T)*(DATA.GetSize()+list->GetLength()));
            for (int i = 0; i < DATA.GetSize(); ++i) {
                items[i] = DATA.Get(i);
            }
            for (int i = 0; i < list->GetLength(); ++i) {
                items[i+DATA.GetSize()] = list->Get(i);
            }
            ArraySequence<T>* result = new ArraySequence<T>(items,DATA.GetSize()+list->GetLength());

            return result;
        }else{
            ArraySequence<T>* result = new ArraySequence<T>(*this);
            return result;
        }

    }
private:
    DynamicArray<T> DATA;
};

#endif