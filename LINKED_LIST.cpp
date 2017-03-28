#include <iostream>

using namespace std;

class Node {
private:
    Node* next;
    int* data;
public:
    Node(){
        this->next = NULL;
        this->data = new int(0);
    }
    ~Node(){
        delete( this->data );
    }
    int get_data(){
        return *(this->data);
    }
    void set_data(int input_data){
        *(this->data) = input_data;
    }
    Node* get_next(){
        return this->next;
    }
    void set_next(Node* address){
        this->next = address;
    }
};

class LinkedList{
private:
    Node* root;
    int* size;

    Node* get_node_by_index(int index){
        Node* node = root;
        for (int i = 0; i < index; i++){
            node = node->get_next();
        }
        return node;

    }
    Node* get_last_node(){
        return get_node_by_index(*size);
    }
public:
    LinkedList(){
        this->root = new Node;
        this->size = new int(0);
    }
    ~LinkedList(){
        delete(this->root);
        delete(this->size);
    }

    void add(int data){
        Node* node = get_last_node();
        node->set_next(new Node);
        node->get_next()->set_data(data);
        (*size)++;
    }

    void set(int index, int data){
        Node* node = get_node_by_index(index);
        node->set_data(data);
    }

    int get(int index){
        Node* node = get_node_by_index(index);
        return node->get_data();
    }
    void remove(int index){
        Node* prev_node = get_node_by_index(index-1);
        Node* node = get_node_by_index(index);
        prev_node->set_next(node->get_next());
        delete(node);
        *size -= 1;
    }

    void show(){
        Node* node = root;
        for (int i = 0; i < *size; i++){
            node = node->get_next();
            cout<<node->get_data()<<endl;
        }
    }
};

int main() {
    LinkedList list;
    for( int i = 0; i < 5; i++)
        list.add(i);
    list.remove(3);
    list.show();
    return 0;
}
