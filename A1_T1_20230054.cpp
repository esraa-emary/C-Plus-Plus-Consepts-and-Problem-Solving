// File: A1_T1_20230054.cpp
// Purpose: A program to perform several tasks.
// Author: Esraa Emary Abd-El Salam.
// Section: .....................
// ID: 20230054
// TA: ...................
// Date: 8 Oct 2024
// Detailed explanation of the file and how program works ...

//======================================================================================================================

#include <bits/stdc++.h>
#include <fstream>

using namespace std;

//======================================================================================================================

string enterProblem(vector<string> problems) {
    string choiceProblems;
    cout << "\nWhich problem you want to solve ?\n";
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

void correctSentence() {
    string corrected, sentence;
    bool found = false;

    cout << "\nThis part of my program gets a sentence and correct is.\n";
    cout << "\nEnter the sentence you want to correct :";
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, sentence);

    for (int i = 0; i < sentence.size(); ++i) {
        if ((isspace(sentence[i]) && !found && i != 0) ||
            (isspace(sentence[i]) && !found && i != 0 && sentence[i - 1] == '.') ||
            (isspace(sentence[i]) && !found && i != 0 && sentence[i - 1] == ',')) {
            corrected += " ";
            found = true;
        } else if ((isspace(sentence[i]) && found) || (isspace(sentence[i]) && !found && i == 0)) continue;
        else {
            found = false;
            corrected += sentence[i];
        }
    }

    for (int i = 0; i < corrected.size(); ++i) {
        if ((i == 0 && !isspace(corrected[i])) || (i > 2 && isspace(corrected[i - 1]) && corrected[i - 2] == '.')) {
            if (isalpha(corrected[i])) corrected[i] = toupper(corrected[i]);
        } else {
            if (isalpha(corrected[i])) corrected[i] = tolower(corrected[i]);
        }
        if ((isspace(corrected[i]) && corrected[i + 1] == '.') ||
            (isspace(corrected[i]) && corrected[i + 1] == ','))
            corrected.erase(i, 1);
    }
    if (corrected[corrected.size() - 1] != '.') corrected += '.';
    cout << "The corrected sentence is : " << corrected << endl;
}

//======================================================================================================================

int main() {
    bool firstTime = false;
    cout << "Welcome to my program, This program includes\n" << "solutions for some problems.\n";

    vector<string> stay = {"Continue", "Exit"};
    vector<string> back = {"Continue", "Back"};
    vector<string> problems = {"Correct a Sentence.", "generate a list of primes.", "", "", "Exit"};
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
               choiceProblems != "4" && choiceProblems != "5") {
            cout << "Please enter a correct choice !\n";
            choiceProblems = enterProblem(problems);
        }

        if (choiceProblems == "1") {
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            } else if (starOrBack == "1") {
                correctSentence();
            }
        } else if (choiceProblems == "2") {
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            } else if (starOrBack == "1") {

            }
        } else if (choiceProblems == "3") {
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            } else if (starOrBack == "1") {

            }
        } else if (choiceProblems == "4") {
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            } else if (starOrBack == "1") {

            }
        } else if (choiceProblems == "5") {
            break;
        }
        firstTime = true;
    }
    cout << "\nThanks for using my program !";
}
