#include <iostream>

using namespace std;

double calc(double a,double b,char oper){
    if(a<0||b<0)
        throw runtime_error("Below zero!");
    switch(oper){
        int x,y;
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            if(b==0)
                throw runtime_error("Divided by zero!");
            return a/b;
        case '%':
            x=a,y=b;
            if(x!=a||y!=b)
                throw runtime_error("Not integers!");
            if(y==0)
                throw runtime_error("Divided by zero!");
            return x%y;
        default:
            throw runtime_error("Bad operator!");
    }
}

int main() {
    double a,b;
    char oper;
    while(cin>>a>>oper>>b){
        try{
            double result=calc(a,b,oper);
            cout<<a<<oper<<b<<"="<<result<<endl;
        }catch(exception &e){
            cout<<e.what()<<endl;
        }
    }
    return 0;
}