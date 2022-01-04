#include <iostream>
using namespace std;

/**
 * @brief Declaring a free function
 */
void printHello();

int main() {
    printHello();
}

/**
 * @brief Defining a free function
 *
 * @param player passed by constant reference
 */
void printHello() {
    cout << "Hello" << endl;
}
