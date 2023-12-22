// Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

string get_string() {
    string input;
    cin >> input;
    return input;
}

//bool noun(string str) {
//    vector<string> nouns_list {"birds", "fish", "C++"};
//    bool present = false;
//
//    for (int i = 0; i < nouns_list.size(); ++i) {
//        if (str == nouns_list[i]) {
//            present = true;
//            break;
//        }
//    }
//    return present;
//}


//bool verb(string str) {
//    vector<string> verbs_list {"rules", "fly", "swim"};
//
//    bool present = false;
//
//    for (int i = 0; i < verbs_list.size(); ++i) {
//        if (str == verbs_list[i]) {
//            present = true;
//            break;
//        }
//    }
//    return present;
//}

bool noun() {
    vector<string> nouns_list {"birds", "fish", "C++"};

    string first_word = get_string();

    for (int i = 0; i < nouns_list.size(); ++i) {
        if (first_word == nouns_list[i]) {
            return true;
            break;
        }
    }
    return false;
}

bool verb() {
    vector<string> verbs_list {"rules", "fly", "swim"};

    string word = get_string();

    for (int i = 0; i < verbs_list.size(); ++i) {
        if (word == verbs_list[i]) {
            return true;
            break;
        }
    }
    return false;
}


bool conjuction(string str) {
    vector<string> conjuctions_list {"rules", "fly", "swim"};

    bool present = false;

    for (int i = 0; i < conjuctions_list.size(); ++i) {
        if (str == conjuctions_list[i]) {
            present = true;
            break;
        }
    }
    return present;
}

void sentence() {
    bool first_word_okay = noun();

    if (first_word_okay == false) {
        cout << "not OK!\n";
        cout << "a noun is needed here!\n";
        return;
    }
    else {
        bool second_word_okay = verb();

        if (second_word_okay == false) {
            cout << "not OK!\n";
            cout << "a verb is needed here!\n";
            return;
        }
        else {
            cout << "We are okay for now. Noun and verb seen\n";
            return;
        }
    }
}



//void check_text(string input) {
//
//    vector<string> input_parts;
//
//    bool sentence_complete = false;
//
//    //loop through the input and get the individual parts in a vector
//    string part = "";
//    if (input.size() > 0) {
//        for (int i = 0; i < input.size(); ++i) {
//            if (input[i] == '.') {
//                if (input[i - 1] == ' ') { 
//                    sentence_complete = true; 
//                    break; 
//                }
//                else {
//                    cout << "Sentence contains premature full-stop!\n";
//                    return;
//                }
//            }
//
//            if (input[i] == ' ') {
//                input_parts.push_back(part);
//                part = "";
//            }
//            else {
//                part.push_back(input[i]);
//            }
//        }
//
//        if (sentence_complete == 1) {
//            cout << "Yes, sentence complete\n";
//
//            //look for Noun first
//            bool noun_present = noun(input_parts[0]);
//            if (noun_present == true) {
//                //continue next test
//
//            }
//            else {
//                cout << "not OK!";
//            }
//
//            for (int i = 0; i < input_parts.size(); ++i) {
//                
//            }
//
//
//            //the a verb
//
//            /*then a full-stop (preceeded by ' '),
//                else look for a conjuction*/
//
//
//        }
//        else {
//            cout << "No, sentence not complete\n";
//        }
//
//    }
//    else {
//        cout << "You did not input any text\n";
//    }
//
//   /* for (string part : input_parts) {
//        cout << part << ", ";
//    }*/
//
//
//   
//
//
//}


int main()
try {
    /*
    vector<string> verbs_list {"rules", "fly", "swim"};
    vector<string> nouns_list {"birds", "fish", "C++"};
    vector<string> conjuction_list {"and", "or", "but"};*/

    cout << "Enter the text you want to test: \n";
    cout << ">> ";

    sentence();

    


    //string input_text;
    //getline(cin, input_text);

    //check_text(input_text);

    

    







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
