// Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

class Token {
public:
    char kind;
    double value;
};

class Token_stream {
public:
    Token get();
    void putback(Token t);
private:
    bool full {false}; //is there a token in the buffer?
    Token buffer; // here is where we put a token put back using putback()
};

void Token_stream::putback(Token t) {
    if (full) error("putback() into a full buffer");
    buffer = t; //copy t to buffer
    full = true; //buffer is now full
}

Token Token_stream::get() {
    if (full) { // do we already have a Token ready?
        full = false; // remove Token from buffer
        return buffer; 
    }

    char ch;
    cin >> ch; // >> skips whitespaces

    switch (ch) {
    case ';': // ';' for print
    case 'q': // 'q' for quit
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token{ ch }; // let each character represent itself

    case '.':
    case '0':case '1': case '2': case '3': case '4': 
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch); //put digit back into the input stream;
        double val;
        cin >> val; // read a floating-point number
        return Token{ '8', val }; // let '8' represent "a number"
    }
    default:
        error("Bad token");
    }


}

Token_stream ts;

double expression();

double primary() {
    Token t = ts.get();
    while(true) {
        switch (t.kind) {
        case '(':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected!");
            return d;
        }
        case '8':
            return t.value;
        default:
            error("Primary expected!");
        }
    }
}

double term() {
    double left = primary(); //look for primary
    Token t = ts.get();

    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double primary_value = primary(); // because of this, everything is placed inside a block
            if (primary_value == 0) error("Division by 0!");
            left /= primary_value;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }

}

double expression() {
    double left = term(); //look for a term
    Token t = ts.get(); //get the next token

    while (true) {
        switch (t.kind) {
        case '+':
            left += term(); //evaluate Term and add
            t = ts.get(); // get the next token
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}

int main()
try {
    cout << "Enter some values: \n";

    double val = 0;
    
    while (cin) { //as long as we are getting input through cin
        Token t = ts.get();

        if (t.kind == 'q') break; //'q' for quit
        if (t.kind == ';') {
            cout << "= " << val << '\n';
        }
        else {
            ts.putback(t);
            val = expression();
        }
        //keep_window_open();
    }
    

    























}
catch (exception& e) {
    cerr << "Error: " << e.what() << '\n';
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Exception error\n";
    keep_window_open();
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
