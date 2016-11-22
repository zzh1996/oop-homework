#include <iostream>
#include <std_lib_facilities.h>

int main() {
    std::cout << "Hello, World!" << std::endl;
    try {
        error("This is an error");
    } catch (runtime_error e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}