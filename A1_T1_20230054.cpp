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

//======================================================================================================================

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
        if ((!isspace(corrected[i + 1]) && corrected[i] == ',') ||
            (!isspace(corrected[i + 1]) && corrected[i] == '.'))
            corrected.insert(i + 1, 1, ' ');
    }
    if (corrected[corrected.size() - 1] != '.') corrected += '.';
    cout << "The corrected sentence is : " << corrected << endl;
}

//======================================================================================================================

void getPrimes() {
    string number;
    long long num;
    vector<long long> numbers;
    vector<long long> crossed;
    bool notInteger = false, change = false;
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Please enter a positive integer number to get primes from 2 to it :";
    getline(cin, number);
    for (int i = 0; i < number.size(); ++i) {
        if (number[i] != '0' && number[i] != '1' && number[i] != '2' && number[i] != '3' && number[i] != '4' &&
            number[i] != '5' && number[i] != '6' && number[i] != '7' && number[i] != '8' && number[i] != '9') {
            notInteger = true;
            break;
        }
    }
    if (!notInteger) {
        num = stoll(number);
        if (num < 2) notInteger = true;
    }
    while (notInteger) {
        notInteger = false;
        cout << endl;
        cout << "Please enter a correct positive integer number :";
        getline(cin, number);
        for (int i = 0; i < number.size(); ++i) {
            if (number[i] != '0' && number[i] != '1' && number[i] != '2' && number[i] != '3' && number[i] != '4' &&
                number[i] != '5' && number[i] != '6' && number[i] != '7' && number[i] != '8' && number[i] != '9') {
                notInteger = true;
                break;
            }
        }
        if (!notInteger) {
            num = stoll(number);
            if (num < 2) notInteger = true;
        }
    }
    num = stoll(number);

    for (int i = 2; i <= num; ++i) numbers.push_back(i);

    for (int i = 0; i < numbers.size(); ++i) {
        change = false;
        for (int j = 0; j < numbers.size(); ++j) {
            if (numbers[j] % numbers[i] == 0 && numbers[i] < numbers[j]) {
                numbers.erase(numbers.begin() + j);
                change = true;
            }
        }
        if (change) {
            for (int j = 2; j <= num; ++j) {
                auto it = find(numbers.begin(), numbers.end(), j);
                if (it != numbers.end()) continue;
                else crossed.push_back(j);
            }

            cout << "\nThe circled numbers(primes) in " << i + 1 << " are : ";
            for (int j = 0; j < numbers.size(); ++j) {
                if (j != numbers.size() - 1) cout << numbers[j] << ',';
                else cout << numbers[j];
            }

            cout << "\n\nThe crossed-out numbers(not prime) in " << i + 1 << " are : ";
            for (int j = 0; j < crossed.size(); ++j) {
                if (j != crossed.size() - 1) cout << crossed[j] << ',';
                else cout << crossed[j];
            }
            cout << "\n\n===========================================================================================\n";
            crossed.clear();
        }
    }

    for (int i = 2; i <= num; ++i) {
        auto it = find(numbers.begin(), numbers.end(), i);
        if (it != numbers.end()) continue;
        else crossed.push_back(i);
    }

    cout << "\nThe final circled numbers(primes) are : ";
    for (int i = 0; i < numbers.size(); ++i) {
        if (i != numbers.size() - 1) cout << numbers[i] << ',';
        else cout << numbers[i];
    }

    cout << "\n\nThe final crossed-out numbers(not prime) are : ";
    for (int i = 0; i < crossed.size(); ++i) {
        if (i != crossed.size() - 1) cout << crossed[i] << ',';
        else cout << crossed[i];
    }
    cout << endl;
}

//======================================================================================================================

struct dominoT {
    int leftDots;
    int rightDots;
};

bool FormsDominoChain(vector<dominoT> &dominos) {
    static int start = 0;
//    vector<int> first,second;
    deque<int> arrange;
    if (start == 0) arrange.push_back(0);
    if (start == dominos.size() - 1) {

    }


    start++;
    return FormsDominoChain(dominos);


//    for (int i = 0; i < dominos.size(); ++i) {
//        first.push_back(dominos[i].leftDots) ;
//        second.push_back(dominos[i].rightDots);
//    }

//    for (int i = 0; i < elements.size(); ++i) {
//        found = false;
//        for (int j = 0; j < elements.size(); ++j) {
//            if (i != j) {
//                if (elements[i].first == elements[j].second) {
//                    found = true;
//                    break;
//                }
//            }
//        }
//        if (!found) {
//            sum++;
//            dominos[0].leftDots = elements[i].first;
//            dominos[0].rightDots = elements[i].second;
//
//            elements.erase(elements.begin() + i);
//        }
//        if (sum > 1) return false;
//    }
//    for (int i = 1; i < dominos.size(); ++i) {
//        int prev = dominos[i - 1].rightDots;
////        if (freq[prev] == 1)
//    }


//    if (first){
//        for (int i = 1; i < dominos.size(); ++i) {
//            for (int j = 0; j < elements.size(); ++j) {
//                if (elements[j].first == dominos[i-1].rightDots){
//                    dominos[i].leftDots = elements[j].first;
//                    dominos[i].rightDots = elements[j].second;
//                    elements.erase(elements.begin()+i);
//                }
//            }
//        }
//    }
//    else{
//
//    }

//    for (int i = 0; i < elements.size(); ++i) {
//        found = false;
//        for (int j = 0; j < elements.size(); ++j) {
//            if (i != j) {
//                if (elements[i].second == elements[j].first) {
//                    found = true;
//                    break;
//                }
//            }
//        }
//        if (!found) {
//            sum++;
//            dominos[dominos.size() - 1].leftDots = elements[i].first;
//            dominos[dominos.size() - 1].rightDots = elements[i].second;
//            last = true;
//            elements.erase(elements.begin()+i);
//        }
//        if (sum > 1) return false;
//    }
}

void gameOfDominos() {
    vector<dominoT> dominos;
    string number, element;
    map<long long, long long> freq;
    long long num, odd = 0;
    bool notInteger = false;
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Please enter number of dominos :";
    getline(cin, number);
    for (int i = 0; i < number.size(); ++i) {
        if (number[i] != '0' && number[i] != '1' && number[i] != '2' && number[i] != '3' && number[i] != '4' &&
            number[i] != '5' && number[i] != '6' && number[i] != '7' && number[i] != '8' && number[i] != '9') {
            notInteger = true;
            break;
        }
    }
    if (!notInteger) {
        num = stoll(number);
        if (num < 1) notInteger = true;
    }
    while (notInteger) {
        notInteger = false;
        cout << endl;
        cout << "Please enter a correct number of dominos :";
        getline(cin, number);
        for (int i = 0; i < number.size(); ++i) {
            if (number[i] != '0' && number[i] != '1' && number[i] != '2' && number[i] != '3' && number[i] != '4' &&
                number[i] != '5' && number[i] != '6' && number[i] != '7' && number[i] != '8' && number[i] != '9') {
                notInteger = true;
                break;
            }
        }
        if (!notInteger) {
            num = stoll(number);
            if (num < 1) notInteger = true;
        }
    }
    num = stoll(number);

    for (int i = 0; i < num; ++i) {
        notInteger = true;
        cout << "\nPlease enter the Left Dots in " << i+1 << " dominos :";
        getline(cin, element);
        while (notInteger) {
            notInteger = false;
            if (element != "0" && element != "1" && element != "2" && element != "3" && element != "4" &&
                element != "5" && element != "6") {
                notInteger = true;
            }
            if (stoi(element) > 6) {
                notInteger = true;
            }
            if (notInteger) {
                cout << "Please enter a valid Left Dots in " << i+1 << " dominos :";
                getline(cin, element);
            }
        }
        dominos[i].leftDots = stoi(element);
        freq[dominos[i].leftDots]++;

        notInteger = true;
        cout << "Please enter the Right Dots in " << i+1 << " dominos :";
        getline(cin, element);
        while (notInteger) {
            notInteger = false;
            if (element != "0" && element != "1" && element != "2" && element != "3" && element != "4" &&
                element != "5" && element != "6") {
                notInteger = true;
            }
            if (stoi(element) > 6) {
                notInteger = true;
            }
            if (notInteger) {
                cout << "Please enter a valid Left Dots in " << i+1 << " dominos :";
                getline(cin, element);
            }
        }
        dominos[i].rightDots = stoi(element);
        freq[dominos[i].rightDots]++;
    }

    for (auto it: freq) {
        if (it.second % 2 != 0) odd++;
    }

    if (odd % 2 != 0) cout << "No, it is not possible to build a chain consisting of every domino in the vector.\n";
    else {
        if (FormsDominoChain(dominos)) {
            cout << "Yes, it is possible to build a chain consisting of every domino in the vector.\n";
            for (int i = 0; i < dominos.size(); ++i) {
                if (i == dominos.size() - 1) cout << dominos[i].leftDots << " | " << dominos[i].rightDots;
                else cout << dominos[i].leftDots << " | " << dominos[i].rightDots << " - ";
            }
        } else cout << "No, it is not possible to build a chain consisting of every domino in the vector.\n";
    }
}

//======================================================================================================================



//======================================================================================================================

int main() {
    bool firstTime = false;
    cout << "Welcome to my program, This program includes\n" << "solutions for some problems.\n";

    vector<string> stay = {"Continue", "Exit"};
    vector<string> back = {"Continue", "Back"};
    vector<string> problems = {"Correct a Sentence.", "generate a list of primes.", "The game of dominos.", "", "Exit"};
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
                getPrimes();
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
                gameOfDominos();
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
