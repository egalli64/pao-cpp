#include <iostream>
#include <string>
#include <thread>

using namespace std;

void hello() {
    cout << "hello!" << endl;
}

int main() {
    thread t1([]() {cout << "welcome!" << endl;});
    thread t2(hello);

    t1.join();
    t2.join();

    cout << "Done!" << endl;
}
