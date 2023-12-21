// Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

//for (int i = 0; i < names.size(); ++i) {
//    if (name == names[i]) {
//        string errorMsg = name + " exists already!";
//        error(errorMsg);
//        //error("Duplicate name");
//    }
//    names.push_back(name);
//    cin >> score;
//    scores.push_back(score);
//}

//void add_input(string name, int score) {
//    vector<string> names;
//    vector<int> scores;
//
//    int score;
//
//    for (string name; cin >> name; ) {
//        if (name == "noname") break;
//        if (names.size() < 1) {
//            names.push_back(name);
//            cin >> score;
//            scores.push_back(score);
//        }
//        else {
//
//            for (int i = 0; i < names.size(); ++i) {
//                if (name == names[i]) {
//                    string errMsg = name + " already exists!";
//                    error(errMsg);
//                }
//            }
//
//            names.push_back(name);
//            cin >> score;
//            scores.push_back(score);
//
//        }
//
//    }
//}


int main()
try {

    vector<string> names;
    vector<int> scores;

    string input;

    cout << "Please enter name and score in succession: \n";

    int score;

    for (string name; cin >> name; ) {
        if (name == "noname") {
            if (cin) cin >> score;
            break;
        };
        if (names.size() < 1) {
            names.push_back(name);
            cin >> score;
            scores.push_back(score);  
        }
        else {

            for (int i = 0; i < names.size(); ++i) {
                if (name == names[i]) {
                    string errMsg = name + " already exists!";
                    error(errMsg);
                }
            }
       
            names.push_back(name);
            cin >> score;
            scores.push_back(score);

        }
   
    }

    for (int i=0; i < names.size(); ++i) {
        cout << names[i] << ": " << scores[i] << '\n';
    }

    cout << '\n';
    cout << "===================================" << '\n';
    cout << '\n';

    
    cout << "You can now look up anything from your input\n";
    cout << "What are you looking for?: ";


    cin >> input;
    while (cin) {
        if (input == "quit") break;

        cout << "output: " << input << '\n';
        bool input_is_integer = true;
        //check whether the input is integer or not
        if (input.length()) {
            for (int i = 0; i < input.length(); ++i) {
                //cout << "input[" << i << "]: " << input[i] << '\n';
                char current = input[i];

                switch (current) {
                case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                    break;
                default:
                    input_is_integer = false;
                }
            }
        }
        //cout << "is the input an integer?: " << input_is_integer << '\n';

        if (input_is_integer) {
            //output names with score === integer

            vector<int> list;
            for (int i = 0; i < scores.size(); ++i) {
                string sample_num = to_string(scores[i]);
                if (sample_num == input) {
                    list.push_back(i);
                }
            }

            if (list.size() > 0) {
                for (int i = 0; i < list.size(); ++i) {
                    cout << names[list[i]] << '\n';
                }
            }
            else {
                cout << "Score not found!\n";
            }
        }
        else {
            //output score with corresponding name
            int result = -1;
            for (int i = 0; i < names.size(); ++i) {
                if (names[i] == input) {
                    result = scores[i];
                    break;
                }
            }
            if (result == -1) {
                cout << "Name not found!\n";
            }
            else {
                cout << input << ": " << result << '\n';
            }

        }

        cin >> input;
    }



    return 0;

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
