#ifndef list_v0_hpp
#define list_v0_hpp

template<typename T>
struct Node {
    T data;
    Node<T>* next;
};

template<typename T>
class List {
private:
    Node<T>* p_begin;
    Node<T>* p_end;
    int size;
public:
    List(){
        p_begin = nullptr;
        p_end = nullptr;
        size = 0;
    }
    List(const List<T>& L) {
        Node<T>* p = L.p_begin;
        p_begin = nullptr;
        p_end = nullptr;
        size = 0;
        while (p) {
            this->push_back(p->data);
            p = p->next;
        }
    }
    ~List(){
        clear();
    }

    Node<T>* insert_node(const T value) {
        Node<T>* p = new Node<T>;
        p->next = p_begin;
        p->data = value;
        return p;
    }

    void push_front(const T value) {
        p_begin = insert_node(value);
        size++;
        if (size == 1)
            p_end = p_begin;
    }

    void printer(){
        Node<T>* p = p_begin;
        while (p) {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

    void push_back(const T value) {
        Node<T>* p = new Node<T>;
        p->data = value;
        p->next = nullptr;
        if (size == 0) {
            p_begin = p_end = p;
        }
        else {
            p_end->next = p;
            p_end = p;
        }
        size++;
    }

    void clear(){
        Node<T>* prev;
        while (p_begin) {
            prev = p_begin;
            p_begin = p_begin->next;
            delete prev;
        }
        p_begin = nullptr;
        size = 0;
    }

    T& back() {
        return p_end->data;
    }

    Node<T>* begin() {
        return p_begin;
    }

    Node<T>* end() {
        return p_end;
    }

    int get_size() {
        return size;
    }

};

template<typename T>
class ListIterator : List<T> {
    Node<T>* current;

public:
    ListIterator(List<T>& L){
        current = L.begin();
    }

    bool has_next() {
        return current->next != nullptr;
    }

    bool check() {
        return current != nullptr;
    }

    T* get(){
        return &(current->data);
    }

    void next() {
        if (current) {
            current = current->next;
        }
    }
};

#endif //list_v0_hpp
