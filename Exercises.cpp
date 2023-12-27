// Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

//void swap_v(int a, int b) { 
//    int temp; 
//    temp = a;
//    a = b; 
//    b = temp; 
//}
//void swap_r(int& a, int& b) { int temp; temp = a; a = b; b = temp; }
//void swap_cr(const int& a, const int& b) { int temp; temp = a; a = b; b = temp; }


namespace X {
    int var = 0;
    void print() {
        cout << "X's var: " << var << '\n';
    }
}
namespace Y {
    int var = 0;
    void print() {
        cout << "Y's var: " << var << '\n';
    }
}
namespace Z {
    int var= 0;
    void print() {
        cout << "Z's var: " << var << '\n';
    }
}


int main()
try {
    X::var = 7;
    X::print();

    using namespace Y;
    var = 9;
    print();

    {
        using Z::var;
        using Z::print;

        var = 11;
        print();
    }

    print();
    X::print();


    






















    //int x = 7;
    //int y = 9;
    //swap_r(7, 9);
    //cout << "x: " << x << " & y: " << y << '\n';
}
catch (exception& e) {
    cerr << "Error: " << e.what() << '\n';
    keep_window_open("~~");
    //for (char ch; cin >> ch; ) { //keep reading until we find a ~
    //    if (ch == '~') return 1;
    //}

    return 1;
}
catch (...) {
    cerr << "Exception error\n";
    keep_window_open("~~");
    return 2;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
