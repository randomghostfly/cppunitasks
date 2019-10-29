#include <iostream>
#include "my_sum.h"

int main() {

    long long int a;
    long long int b;

    std::cout << "Please enter a and b" << std::endl;
    std::cin >> a >> b;
    std::cout << "Here's the result: " << my_sum(a, b) << std::endl;

    return 0;
}