#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main() {
    vector<string> a, b;
    string s;

    ifstream file_a("a.txt");
    copy(istream_iterator<string>(file_a), istream_iterator<string>(), back_inserter(a));
    file_a.close();

    ifstream file_b("b.txt");
    copy(istream_iterator<string>(file_b), istream_iterator<string>(), back_inserter(b));
    file_b.close();

    auto cmp = [](string a, string b) {
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        return a < b;
    };

    sort(a.begin(), a.end(), cmp);
    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());

    ofstream file_a1("a1.txt");
    copy(a.begin(), a.end(), ostream_iterator<string>(file_a1, " "));
    file_a1.close();

    sort(b.begin(), b.end(), cmp);
    last = unique(b.begin(), b.end());
    b.erase(last, b.end());

    ofstream file_b1("b1.txt");
    copy(b.begin(), b.end(), ostream_iterator<string>(file_b1, " "));
    file_b1.close();

    vector<string> m;
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(m));
    last = unique(m.begin(), m.end());
    m.erase(last, m.end());

    ofstream file_m("m.txt");
    copy(m.begin(), m.end(), ostream_iterator<string>(file_m, " "));
    file_m.close();

    return 0;
}