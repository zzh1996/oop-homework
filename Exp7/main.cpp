#include <iostream>

using namespace std;

template <class T>
class counted_ptr{
    T *ptr;
    int *count;
    void increase_count() const{
        ++*count;
        cout<<"Count="<<*count<<endl;
    }
    void decrease_count() const{
        --*count;
        cout<<"Count="<<*count<<endl;
        if(*count==0) {
            delete ptr;
            delete count;
        }
    }
public:
    explicit counted_ptr():ptr(new T()),count(new int(0)){
        increase_count();
    }
    ~counted_ptr(){
        decrease_count();
    }
    explicit counted_ptr(const counted_ptr& p):ptr(p.ptr),count(p.count){
        increase_count();
    }
    T &operator*() const{
        return *ptr;
    }
    T *operator->() const{
        return ptr;
    }
    T &operator[](int index){
        return ptr[index];
    }
    int get_count() const{
        return *count;
    }
    T *get_pointer() const{
        return ptr;
    }
    counted_ptr &operator=(const counted_ptr &p){
        p.increase_count();
        decrease_count();
        ptr=p.ptr;
        count=p.count;
    }
    operator bool(){
        return ptr==nullptr;
    }

    template <class U>
    friend bool operator==(const counted_ptr<U> &lhs,const counted_ptr<U> &rhs);
    template <class U>
    friend bool operator>(const counted_ptr<U> &lhs,const counted_ptr<U> &rhs);
    template <class U>
    friend bool operator>=(const counted_ptr<U> &lhs,const counted_ptr<U> &rhs);
    template <class U>
    friend bool operator<(const counted_ptr<U> &lhs,const counted_ptr<U> &rhs);
    template <class U>
    friend bool operator<=(const counted_ptr<U> &lhs,const counted_ptr<U> &rhs);
    template <class U>
    friend bool operator!=(const counted_ptr<U> &lhs,const counted_ptr<U> &rhs);
};

template <class T>
bool operator==(const counted_ptr<T> &lhs,const counted_ptr<T> &rhs){
    return lhs.ptr==rhs.ptr;
}

template <class T>
bool operator!=(const counted_ptr<T> &lhs,const counted_ptr<T> &rhs){
    return lhs.ptr!=rhs.ptr;
}

template <class T>
bool operator<(const counted_ptr<T> &lhs,const counted_ptr<T> &rhs){
    return lhs.ptr<rhs.ptr;
}

template <class T>
bool operator<=(const counted_ptr<T> &lhs,const counted_ptr<T> &rhs){
    return lhs.ptr<=rhs.ptr;
}

template <class T>
bool operator>(const counted_ptr<T> &lhs,const counted_ptr<T> &rhs){
    return lhs.ptr>rhs.ptr;
}

template <class T>
bool operator>=(const counted_ptr<T> &lhs,const counted_ptr<T> &rhs){
    return lhs.ptr>=rhs.ptr;
}

class Test{
public:
    Test():data(123){
        cout<<"Test constructor"<<endl;
    }
    ~Test(){
        cout<<"Test destructor"<<endl;
    }
    int data;
    void print() const{
        cout<<"Data is "<<data<<endl;
    }
};

int main() {
    counted_ptr<Test> t;
    t=t;
    (*t).data=10;
    counted_ptr<Test> t2(t);
    t->print();
    counted_ptr<Test> s;
    s=t;
    s->print();
    const counted_ptr<Test> c(s);
    c->data=20;
    cout<<t[0].data<<endl;
    counted_ptr<const Test> c2;
    c2->print();
    cout<<(c==s)<<endl;
    cout<<(c<=s)<<endl;
    cout<<(c!=s)<<endl;
    return 0;
}