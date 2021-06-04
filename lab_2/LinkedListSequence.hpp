#ifndef LinkedListSequence_hpp
#define LinkedListSequence_hpp


template<typename T>
class LinkedListSequence : public Sequence<T>{
public://информация о размере хранится в поле DATA
    LinkedListSequence(){//конструктор по умолчанию
        LinkedList<T>* tmp = new LinkedList<T>();
        DATA = *tmp;
    }
    LinkedListSequence(T* items,int count){//конструктор по массиву
        LinkedList<T>* tmp = new LinkedList<T>(items,count);
        DATA = *tmp;

    }

    //переопределение не охватывает соответствующую функцию из LinkedList,
    // так как требуется общность первого параметра,вследствие чего нет возможности получить данные
    LinkedListSequence<T>* Concat(Sequence<T>* list){
        for (int i = 0; i < list->GetLength(); ++i) {//добавляю в DATA все элементы из list,её Size увеличивается
            DATA.Append(list->Get(i));
        }
        T* items;
        items = (T*)malloc(sizeof(T*)*(DATA.GetLength()+list->GetLength()));
        for (int i = 0; i < DATA.GetLength(); ++i) {//записываю все элементы из DATA  в массив
            items[i] = DATA.Get(i);
        }

        LinkedListSequence<T>* result = new LinkedListSequence<T>(items,DATA.GetLength());//создание нового экземпляра
        return result;
    }

    LinkedListSequence(const LinkedList<T>& list){//конструктор по объекту
        LinkedList<T>* tmp = new LinkedList<T>(list);
        std::cout<< "Constructor by object . . .\n";
        DATA = *tmp;
    }
    LinkedListSequence<T>* GetSubsequence(int startIndex,int endIndex){//вернуть Sequence<T>*
        LinkedList<T>* tmp = DATA.GetSubLinkedList(startIndex,endIndex);//создаем экземляр с указанными индексами
        T* items;
        items = (T*)malloc(sizeof(T*)*(endIndex-startIndex));
        for (int i = 0; i < endIndex-startIndex; ++i) {
            items[i] = tmp->Get(i);
        }

        LinkedListSequence<T>* result = new LinkedListSequence<T>(items,endIndex-startIndex);

        return result;
    }

    ~ LinkedListSequence () {
        DATA.~ LinkedList();
    }

    int GetLength(){
        return DATA.GetLength();
    }
    T GetFirst(){
       return  DATA.GetFirst();
    }
    T GetLast(){
        return DATA.GetLast();
    }
    T Get(int index){
       return DATA.Get(index);
    }

    void Append(T item){
        DATA.Append(item);
    }
    void Prepend(T item){
        DATA.Prepend(item);
    }
    void InsertAt(T item,int index){
        DATA.InsertAt(item,index);
    }
    void removeAt(int index){
        DATA.removeAt(index);
    }
    void Print(){
        DATA.PrintFromBegin();
    }
private:
    LinkedList<T> DATA;
};

#endif