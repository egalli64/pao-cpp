#include <iostream>
using namespace std;

/**
 * @brief Declaring a free function
 */
void printHello();

/**
 * @brief Defining a minimal free function
 */
void empty() {}

/**
 * @brief Defining the main function
 * 
 * @return int resulting status of the program, zero for success
 */
int main() {
    // invoking functions
    printHello();
    empty();
}

/**
 * @brief Defining a free function
 *
 * @param player passed by constant reference
 */
void printHello() {
    cout << "Hello" << endl;
}
