#include <iostream>
#include <regex>
#include "Chrono.h"

using namespace std;
using namespace Chrono;

class LibraryError:public exception{
    string err;
public:
    LibraryError(const string s):err(s){}
    const char* what() const noexcept{return err.c_str();}
};

class Book{
    string ISBN;
    string name;
    string author;
    Date date;
    bool lent;
public:
    Book(const string &ISBN,const string &name,const string &author,const Date &date):
        ISBN(ISBN),name(name),author(author),date(date),lent(false){
            regex re("[0-9]+-[0-9]+-[0-9]+-[0-9A-Z]");
            if(!regex_match(ISBN,re))
                throw LibraryError("ISBN format error");
        }
    void borrow(){
        if(lent)
            throw LibraryError("Book is already lent");
        lent=true;
    }
    void return_(){
        if(!lent)
            throw LibraryError("Book not lent");
        lent=false;
    }
    string get_ISBN() const {return ISBN;}
    string get_name() const {return name;}
    Date get_date() const {return date;}
    bool is_lent() const {return lent;}
};

class Patron{
    string name;
    string ID;
    double fee;
public:
    Patron(const string &name,const string &ID):name(name),ID(ID),fee(0){}
    string get_name() const {return name;}
    string get_ID() const {return ID;}
    double get_fee() const {return fee;}
    void set_fee(const double f){fee=f;}
    bool has_arrear() const {return fee>0;}
};

struct Transaction{
    Book book;
    Patron patron;
    Date date;
};

class Library{
public:
    vector<Book> books;
    vector<Patron> patrons;
    vector<Transaction> transactions;
    Book &get_book_by_ISBN(const string &ISBN){
        for(Book &b : books){
            if(b.get_ISBN()==ISBN)
                return b;
        }
        throw LibraryError("ISBN not found");
    }
    Patron &get_patron_by_ID(const string &ID){
        for(Patron &p : patrons){
            if(p.get_ID()==ID)
                return p;
        }
        throw LibraryError("ID not found");
    }
    void add_book(const Book &book){books.push_back(book);}
    void add_patron(const Patron &patron){patrons.push_back(patron);}
    void borrow_book(const string pID,const string ISBN){
        Patron &p=get_patron_by_ID(pID);
        Book &b=get_book_by_ISBN(ISBN);
        if(p.has_arrear())
            throw LibraryError("Patron has arrear");
        if(b.is_lent())
            throw LibraryError("Book is lent");
        transactions.push_back(Transaction{b,p,Date()});
        b.borrow();
    }

    vector<string> patrons_with_arrear(){
        vector<string> r;
        for(Patron &p : patrons){
            if(p.has_arrear())
                r.push_back(p.get_name());
        }
        return r;
    }
};


int main(){
    Book b("1-2-3-X","name1","author1",Date(2016,Date::jan,1));
    try{
        Book b2("1-2-A-X","name1","author1",Date(2016,Date::jan,1));
    }catch(exception &e){
        cout<<e.what()<<endl;
    }
    cout<<b.get_ISBN()<<endl;
    cout<<b.get_name()<<endl;
    cout<<b.get_date()<<endl;
    cout<<b.is_lent()<<endl;
    b.borrow();
    cout<<b.is_lent()<<endl;
    try{
        b.borrow();
    }catch(exception &e){
        cout<<e.what()<<endl;
    }
    b.return_();
    cout<<b.is_lent()<<endl;
    try{
        b.return_();
    }catch(exception &e){
        cout<<e.what()<<endl;
    }

    Patron p("Tom","A123456");
    cout<<p.get_name()<<endl;
    cout<<p.get_ID()<<endl;
    cout<<p.has_arrear()<<endl;
    p.set_fee(12.34);
    cout<<p.has_arrear()<<endl;
    cout<<p.get_fee()<<endl;

    Library l;
    l.add_book(Book("12-34-56-A","book1","author1",Date(2016,Date::jan,1)));
    l.add_book(Book("12-34-78-B","book2","author2",Date(2016,Date::jan,2)));
    l.add_book(Book("12-34-90-C","book3","author3",Date(2016,Date::jan,3)));
    l.add_patron(Patron("Alice","123456"));
    Patron Bob("Bob","123457");
    Bob.set_fee(1.2);
    l.add_patron(Bob);
    l.add_patron(Patron("CCC","123458"));
    Patron DDD("DDD","123459");
    DDD.set_fee(3.4);
    l.add_patron(DDD);
    l.borrow_book("123456","12-34-56-A");
    try{
        l.borrow_book("123458","12-34-56-A");
    }catch(exception &e){
        cout<<e.what()<<endl;
    }
    try{
        l.borrow_book("123457","12-34-78-B");
    }catch(exception &e){
        cout<<e.what()<<endl;
    }
    try{
        l.borrow_book("123458","12-34-00-0");
    }catch(exception &e){
        cout<<e.what()<<endl;
    }
    try{
        l.borrow_book("123","12-34-78-B");
    }catch(exception &e){
        cout<<e.what()<<endl;
    }
    for(string name : l.patrons_with_arrear()){
        cout<<name<<endl;
    }
    return 0;
}
