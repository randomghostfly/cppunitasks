#include <iostream>

int custom_strlen (const char string[])
{
    int count = 0;
    while(*string!=0){
        string++;
        count++;
    }
    return count;
}

int main() {

    std::cout << custom_strlen("Hello world") << std::endl;

    return 0;
}