#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int main() {
    ifstream file_a("a.txt");
    ifstream file_b("b.txt");
    ofstream file_out("out1.txt");
    stringstream ss;
    ss << file_a.rdbuf();
    ss << ",";
    ss << file_b.rdbuf();
    file_out << ss.str();
    file_a.close();
    file_b.close();
    file_out.close();
}
