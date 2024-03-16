#include <iostream>
using namespace std;

int main() {
    
    int arr[5] = {2 + 3, 4 * 5, 10 - 6, 20 / 2, 7 * 3};

    std::cout << "Addresses (results) of each element in the array:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Result of equation in arr[" << i << "]: " << (arr + i) << std::endl;
    }

    std::cout << "\nValues in the array:" << std::endl;
    int* p = arr; 
    for (int i = 0; i < 5; ++i) {
        std::cout << "Value at position " << i << ": " << *p << std::endl;
        ++p; 
    }

    return 0;
}
