// Purpose: C++ Consepts and Problem Solving

// Student 1: Esraa Emary Abd-El Salam          (20230054)
// Student 2: 	Mohammed Atef Abd El-Kader      (20231143)
// Student 3: Nagham Wael                       (20231189)

// TA:
// Section:

//======================================================================================

#include <bits/stdc++.h>
#include <fstream>

using namespace std;

//======================================================================================

string enterProblem(vector<string> problems) {
    string choiceProblems;
    cout << "Which problem you want to solve ?\n";
    for (int i = 0; i < problems.size(); ++i) {
        cout << i + 1 << " - " << problems[i] << endl;
    }
    cout << "Enter your answer :";
    cin >> choiceProblems;
    return choiceProblems;
}

string continueOrLeave(vector<string> stay) {
    string starOrOut;
    cout << "\nDo you want to continue or exit ?\n";
    for (int i = 0; i < stay.size(); ++i) {
        cout << i + 1 << " - " << stay[i] << endl;
    }
    cout << "Enter your answer :";
    cin >> starOrOut;
    return starOrOut;
}

string continueOrBack(vector<string> back) {
    string starOrBack;
    cout << "\nDo you want to continue or back ?\n";
    for (int i = 0; i < back.size(); ++i) {
        cout << i + 1 << " - " << back[i] << endl;
    }
    cout << "Enter your answer :";
    cin >> starOrBack;
    return starOrBack;
}

//======================================================================================

int main() {
    bool firstTime = false;
    cout << "Welcome to our program, This program includes\n" <<
         "solutions for some problems.\n\n";

    vector<string> stay = {"Continue", "Exit"};
    vector<string> back = {"Continue", "Back"};
    vector<string> problems = {"Correct a Sentence.", "Make speech includes both male and female.", "Split Vector.",
                               "generate a list of primes.",
                               "Manages a list of up to 10 players and their high scores.",
                               "", "", "", "", "", "", "", "Exit"};
    while (true) {
        if (firstTime) {
            string starOrOut = continueOrLeave(stay);
            while (starOrOut != "1" && starOrOut != "2") {
                cout << "Please enter a correct choice !\n\n";
                starOrOut = continueOrLeave(stay);
            }
            if (starOrOut == "2") break;
        }

        string choiceProblems = enterProblem(problems);

        while (choiceProblems != "1" && choiceProblems != "2" && choiceProblems != "3" && choiceProblems != "1" &&
               choiceProblems != "4" && choiceProblems != "5" && choiceProblems != "6" && choiceProblems != "7" &&
               choiceProblems != "8" && choiceProblems != "9" && choiceProblems != "10" && choiceProblems != "11" &&
               choiceProblems != "12" && choiceProblems != "13") {
            cout << "Please enter a correct choice !\n\n";
            choiceProblems = enterProblem(problems);
        }

        if (choiceProblems == "1") {
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            }
            else if (starOrBack == "1") {

            }
        }
        else if (choiceProblems == "2") {
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            }
            else if (starOrBack == "1") {

            }
        }
        else if (choiceProblems == "3") {
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            }
            else if (starOrBack == "1") {

            }
        }
        else if (choiceProblems == "4") {
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            }
            else if (starOrBack == "1") {

            }
        }
        else if (choiceProblems == "5") {
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            }
            else if (starOrBack == "1") {

            }
        }
        else if (choiceProblems == "6") {
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            }
            else if (starOrBack == "1") {

            }
        }
        else if (choiceProblems == "7") {
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            }
            else if (starOrBack == "1") {

            }
        }
        else if (choiceProblems == "8") {
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            }
            else if (starOrBack == "1") {

            }
        }
        else if (choiceProblems == "9") {
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            }
            else if (starOrBack == "1") {

            }
        }
        else if (choiceProblems == "10") {
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            }
            else if (starOrBack == "1") {

            }
        }
        else if (choiceProblems == "11") {
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            }
            else if (starOrBack == "1") {

            }
        }
        else if (choiceProblems == "12") {
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            }
            else if (starOrBack == "1") {

            }
        }
        else if (choiceProblems == "13") {
            break;
        }
        firstTime = true;
    }
    cout << "\nThanks for using our program !";
}