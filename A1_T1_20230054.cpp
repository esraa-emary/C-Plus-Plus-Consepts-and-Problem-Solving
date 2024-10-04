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
    string corrected, sentence, holeSentence = "";
    bool found = false;

    cout << "\nThis part of my program gets a sentence and correct is.\n";
    cout << "\nEnter the sentence you want to correct :";
    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (true) {
        getline(cin, sentence);
        holeSentence += sentence;
        if (sentence[sentence.size() - 1] == '.') break;
        else holeSentence += ' ';
    }

    for (int i = 0; i < holeSentence.size(); ++i) {
        if ((isspace(holeSentence[i]) && !found && i != 0) ||
            (isspace(holeSentence[i]) && !found && i != 0 && holeSentence[i - 1] == '.') ||
            (isspace(holeSentence[i]) && !found && i != 0 && holeSentence[i - 1] == ',')) {
            corrected += " ";
            found = true;
        } else if ((isspace(holeSentence[i]) && found) || (isspace(holeSentence[i]) && !found && i == 0)) continue;
        else {
            found = false;
            corrected += holeSentence[i];
        }
    }

    for (int i = 0; i < corrected.size(); ++i) {
        if ((i == 0 && !isspace(corrected[i]))) {
            if (isalpha(corrected[i])) corrected[i] = toupper(corrected[i]);
        } else {
            if (isalpha(corrected[i])) corrected[i] = tolower(corrected[i]);
        }
        if ((isspace(corrected[i]) && corrected[i + 1] == '.') ||
            (isspace(corrected[i]) && corrected[i + 1] == ','))
            corrected.erase(i, 1);
        if ((!isspace(corrected[i + 1]) && corrected[i] == ',')) corrected.insert(i + 1, 1, ' ');
    }
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
    vector<int> fi, la;
    int first, second;
    deque<int> arrange;

    for (int i = 0; i < dominos.size() && start == 1; ++i) {
        fi.push_back(dominos[i].leftDots);
        la.push_back(dominos[i].rightDots);
    }

    if (start == 0) arrange.push_back(0);
    else if (start == dominos.size() - 1) {
        first = dominos[start - 1].rightDots;
        auto it = find(fi.begin(), fi.end(), first);
        if (it != fi.end()) arrange.push_back(it - fi.begin());
        for (int i = 0; i < dominos.size(); ++i) {
            dominos[i].leftDots = fi[arrange[i]];
            dominos[i].rightDots = la[arrange[i]];
        }
    } else {
        first = dominos[start - 1].rightDots;
        auto it = find(fi.begin(), fi.end(), first);
        if (it != fi.end()) arrange.push_back(it - fi.begin());
    }
    start++;
    return FormsDominoChain(dominos);
}

void gameOfDominos() {
    string number, element;
    map<long long, long long> freq;
    long long num, odd = 0;
    bool notInteger = true;
    int ele;

    cout << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Please enter number of dominos :";
    getline(cin, number);
    while (notInteger) {
        notInteger = false;
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
        if (notInteger) {
            cout << "\nPlease enter a correct number of dominos :";
            getline(cin, number);
        }
    }
    num = stoll(number);
    vector<dominoT> dominos(num);

    for (long long i = 0; i < num; ++i) {
        notInteger = true;
        cout << "\nPlease enter the Left Dots in " << i + 1 << " dominos :";
        getline(cin, element);
        while (notInteger) {
            notInteger = false;
            for (int j = 0; j < element.size(); ++j) {
                if (element[j] != '0' && element[j] != '1' && element[j] != '2' && element[j] != '3' &&
                    element[j] != '4' && element[j] != '5' && element[j] != '6') {
                    notInteger = true;
                    break;
                }
            }
            if (!notInteger) {
                ele = stoi(element);
                if (ele > 6) notInteger = true;
            }
            if (notInteger) {
                cout << "\nPlease enter a valid Left Dots number in " << i + 1 << " dominos :";
                getline(cin, element);
            }
        }
        ele = stoi(element);
        dominos[i].leftDots = ele;
        freq[ele]++;

        notInteger = true;
        cout << "\nPlease enter the Right Dots in " << i + 1 << " dominos :";
        getline(cin, element);
        while (notInteger) {
            notInteger = false;
            for (int j = 0; j < element.size(); ++j) {
                if (element[j] != '0' && element[j] != '1' && element[j] != '2' && element[j] != '3' &&
                    element[j] != '4' && element[j] != '5' && element[j] != '6') {
                    notInteger = true;
                    break;
                }
            }
            if (!notInteger) {
                ele = stoi(element);
                if (ele > 6) notInteger = true;
            }
            if (notInteger) {
                cout << "\nPlease enter a valid Right Dots number in " << i + 1 << " dominos :";
                getline(cin, element);
            }
        }
        ele = stoi(element);
        dominos[i].rightDots = ele;
        freq[ele]++;
    }

    for (auto it: freq) {
        if (it.second % 2 != 0) odd++;
    }

    if (odd > 2) cout << "\nNo, it is not possible to build a chain consisting of every domino in the vector.\n";
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
