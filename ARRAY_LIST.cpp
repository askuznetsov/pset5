#include <iostream>

using namespace std;

const int INITIONAL_ARRAY_SIZE = 10;

class arrayList{
private:
    int* arr = (int *) malloc(INITIONAL_ARRAY_SIZE * sizeof(int)) ;
    int size = 0;
    int max_length = INITIONAL_ARRAY_SIZE;

    void increase_array_length(){
        max_length *=2;
        this->arr = (int*)realloc(arr, (max_length*sizeof(int)));
    }

public:
    void add(int data){
        this->arr[size] = data;
        size++;
        if(size == max_length){
            increase_array_length();
        }
    }
    void show(){
        for( int i = 0; i < size; i++){
            cout << this->arr[i]<<endl;
        }
    }
    int get(int index){
        return this->arr[index];
    }
    void set(int index, int data){
        this->arr[index] = data;
    }
    void remove(int index){
        for(int i = index; i < size, i < 20; i++){
            int temp = this->arr[i];
            this->arr[i] = this->arr[i+1];
            this->arr[i+1] = this->arr[i];
        }
        size--;
    }
    void trim(){
        this->arr = (int*)realloc(arr, (size*sizeof(int)));
    };
};

int main(){
    arrayList list;
    for(int i = 0; i < 20; i++){
        list.add(i);
    }
    list.set(0,10);
    cout<<list.get(0)<<endl;
    list.remove(3);
    list.show();
    return 0;
}
