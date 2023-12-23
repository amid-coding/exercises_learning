// Exercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//BULLS AND COWS GAME.

#include "std_lib_facilities.h"

/*
    THINGS TO ACHIEVE..

    1) check through correct_answer, take individual integer and tally the value and location with those in user_input;
    2) game should continue until user gets 4 cows;
    3) make sure each input is unique;
*/

//while (cows != 4) {
//
//    while (cin && user_input.size() <= 4) {
//
//        int input;
//        cin >> input;
//        user_input.push_back(input);
//    }
//
//    if (user_input.size() < 4) {
//        cout << "you need more input: ";
//        int data;
//        cin >> data;
//        user_input.push_back(data);
//    }
//    else {
//
//        for (int i = 0; i < correct_answer.size(); ++i) {
//            int current_correct = correct_answer[i];
//            int location = i;
//
//            for (int j = 0; j < user_input.size(); ++j) {
//                if (user_input[j] == current_correct) {
//                    if (j == location) ++bulls;
//                    else ++cows;
//                    break;
//                }
//            }
//
//        }
//    }
//
//    cout << "Bulls: " << bulls << '\n';
//    cout << "Cows: " << cows << '\n';
//
//    bulls = 0;
//    cows = 0;
//}


int get_char() {
    int input;
    cin >> input;

    //if (input < 0 || input > 9) { //-1 means bad input
    //    return 'x'; 
    //}

    //else {
    //    return input;

    //}
    return input;
}



int main()
try {
    vector<int> correct_answer {1, 2, 3, 4};
    vector<int> user_input;

    int bulls = 0;
    int cows = 0;

    cout << "Oya make your 4 guess (range is between 0-9 for each)\n";

    while (bulls < 4) {//continue with game till everything's correct
        cout << ">> ";
        int input = get_char();
        //cout << "here is the input: " << input << '\n';

        if (input == 'x') { //check this out later.
            cout << "Bad input! All input must be between 0-9.\n";
            user_input.clear();
            bulls = 0;
            cows = 0;
        }

        if (user_input.size() < 1) {
            user_input.push_back(input);
        }
        else {
            if (user_input.size() < 4) {
                for (int i = 0; i < user_input.size(); ++i) { //check for uniqueness
                    if (input == user_input[i]) {
                        cout << "Duplicate input!.\n";
                        user_input.clear();
                        bulls = 0;
                        cows = 0;
                    }
                }
                user_input.push_back(input);
            }
            else {
                //once complete, now tally with the answer
                cout << "reached the end else part: " << '\n';
                for (int i = 0; i < correct_answer.size(); ++i) {
                    int answer_value = correct_answer[i];
                    int answer_location = i;

                    for (int j = 0; j < user_input.size(); ++j) {
                        //cout << "here is the comparison: " << "answer value: " << answer_value << " and user_input: " << user_input[j] << '\n';
                        //if (user_input[j] == answer_value) {
                        if (user_input[j] == correct_answer[i]) {
                            //cout << "inside the value comparison!\n";
                            if (j == answer_location) {
                                //cout << "additon to bulls!\n";
                                ++bulls;
                            } 
                            else {
                                //cout << "addition to cows!\n";
                                ++cows;
                            } 
                        }
                    }
                }

                cout << "Bulls: " << bulls << '\n';
                cout << "Cows: " << cows << '\n';

                bulls = 0;
                cows = 0;
            }
        }

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
