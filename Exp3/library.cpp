#include <iostream>
#include <exception>
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
    Book(string ISBN,string name,string author,Date date):
        ISBN(ISBN),name(name),author(author),date(date),lent(false){
            regex re("[0-9]+-[0-9]+-[0-9]+-[0-9A-Z]");
            if(!regex_match(ISBN,re))
                throw LibraryError("ISBN format error");
        }
    void borrow(){
        if(lent)
            throw LibraryError("Book already lent");
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


int main(){
    Book b("1-2-3-X","name1","author1",Date(2016,Date::jan,1));
    Book b2("1-2-A-X","name1","author1",Date(2016,Date::jan,1));
    return 0;
}
