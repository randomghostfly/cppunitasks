#include <iostream>

int main() {
    int n, m;
    std::cout << "Please enter two integers. To escape the program, please enter two negative integers" << std::endl;
    std::cin >> n >> m;
    do {
            for (int i = 0; i <= n ; i++) {
                if (i == 0) {
                    std::cout << '\t';
                    for (int r = 1; r <= n; r++) {
                        std::cout << r << '\t';
                    }
                } else {
                    for (int r = 0; r <= n; r++){
                        if (r == 0) {
                            std::cout << i;
                        }
                        if (r != 0) {
                            std::cout << '\t' << (r * i) % m;
                        }
                    }

                }
                std::cout << std::endl;
            }
        std::cout << "Please enter two integers. To escape the program, please enter two negative integers" << std::endl;
        std::cin >> n >> m;
        } while (n > -1 && m > -1);
    return 0;
}