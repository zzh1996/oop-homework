#include <iostream>
#include <std_lib_facilities.h>
#include <sstream>

using namespace std;

int main() {
    string line;
    vector<string> names;
    vector<int> scores;
    try {
        while (1) {
            getline(cin, line);
            if (line == "No more")
                break;
            stringstream ss(line);
            string name;
            int score;
            ss >> name >> score;
            for (vector<string>::iterator i = names.begin(); i != names.end(); ++i) {
                if (*i == name)
                    error("Duplicated name!");
            }
            names.push_back(name);
            scores.push_back(score);
        }
        for (int i = 0; i < names.size(); i++) {
            cout << names[i] << ':' << scores[i] << endl;
        }
    } catch (runtime_error e) {
        cout << e.what() << endl;
    }
    return 0;
}