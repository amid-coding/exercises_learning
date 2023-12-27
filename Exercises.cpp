// Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

void print(const vector<int>& v, string s) {
    cout << s << ": " << "{ ";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) cout << ", ";

    }

    cout << " }\n";
}

void fibonacci(int x, int y, vector<int>& v, int n){
    for (int i = 0; i < n; ++i) {
        if (i == 0) v.push_back(x);
        else if (i == 1) v.push_back(y);
        else {
            int a = i - 2;
            int b = i - 1;
            int next_val = v[a] + v[b];

            v.push_back(next_val);
        }
    }

    print(v, "Output");
}



int main()
try {
    
    //vector<int> vec{2, 4, 6, 8, 1, 3, 5, 7, 9};
    vector<int> fib;

    //print(vec, "Output");
    fibonacci(1, 2, fib, 7);
    






















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
