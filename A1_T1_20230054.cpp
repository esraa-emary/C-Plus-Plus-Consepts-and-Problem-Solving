// File: A1_T1_20230054.cpp
// Purpose: A program to perform several tasks.
// Author: Esraa Emary Abd-El Salam.
// ID: 20230054
// Date: 8 Oct 2024

//==============================================Program details=========================================================

// The program start with a menu to choose a problem to solve then in each problem it asks you if you want to
// continue or back.

// If you choose first problem it will ask you to enter a sentence to handle its spaces.

// If you choose second problem it will ask you to enter a positive integer number and print
// prime numbers from 2 to this number.

// If you choose third problem it will ask you to enter number of dominos then enter left and
// right number for each domino then (if it is possible) to make a chain with dominos it makes it
// and print it otherwise it print no.

// If you choose fourth problem it will ask you to enter file name then it will replace some
// words in it (if exist) with other words then return them in the file.

//======================================================================================================================

#include <bits/stdc++.h>
#include <fstream>
#include <locale>
#include <io.h>   // For _setmode
#include <fcntl.h> // For _O_U16TEXT
#include <codecvt>
#include <sstream>

using namespace std;

//======================================================================================================================

string enterProblem(vector<string> problems) {
    _setmode(_fileno(stdout), _O_TEXT);         // for handle using just ascii.
    _setmode(_fileno(stdin), _O_TEXT);          // for handle using just ascii.
    string choiceProblems;
    cout << "\nWhich problem you want to solve ?\n";
    for (int i = 0; i < problems.size(); ++i) {
        cout << i + 1 << " - " << problems[i] << endl;               // print choices for problem to choose and solve.
    }
    cout << "Enter your answer :";
    getline(cin, choiceProblems);
    return choiceProblems;
}

string continueOrLeave(vector<string> stay) {
    _setmode(_fileno(stdout), _O_TEXT);         // for handle using just ascii.
    _setmode(_fileno(stdin), _O_TEXT);          // for handle using just ascii.
    string starOrOut;
    cout << "\nDo you want to continue or exit ?\n";
    for (int i = 0; i < stay.size(); ++i) {
        cout << i + 1 << " - " << stay[i] << endl;                   // print choices for continue or exit program.
    }
    cout << "Enter your answer :";
    getline(cin, starOrOut);
    return starOrOut;
}

string continueOrBack(vector<string> back) {
    _setmode(_fileno(stdout), _O_TEXT);         // for handle using just ascii.
    _setmode(_fileno(stdin), _O_TEXT);          // for handle using just ascii.
    string starOrBack;
    cout << "\nDo you want to continue or back ?\n";
    for (int i = 0; i < back.size(); ++i) {
        cout << i + 1 << " - " << back[i] << endl;                   // print choices for continue or back to main menu.
    }
    cout << "Enter your answer :";
    getline(cin, starOrBack);
    return starOrBack;
}

//======================================================================================================================

void correctSentence() {
    _setmode(_fileno(stdout), _O_TEXT);         // for handle using just ascii .
    _setmode(_fileno(stdin), _O_TEXT);          // for handle using just ascii .
    string corrected, sentence, holeSentence = "";
    bool found = false;

    cout << "\n=====>This part gets a sentence and correct is.<=====\n";
    cout << "\nEnter the sentence you want to correct :";
    cout << endl;

    while (true) {
        getline(cin, sentence);
        for (int i = 0; i <
                        sentence.size(); ++i) {                   // keep taking lines until it find "." and ignore every thing after it.
            if (sentence[i] == '.') {
                found = true;
                sentence.erase(i + 1, sentence.size() - i - 1);
                holeSentence += sentence;
            }
        }
        if (found) break;
        else {
            holeSentence += sentence;                                 // put all lines in a new variable and handle it as a sentence.
            holeSentence += ' ';
        }
    }

    found = false;
    for (int i = 0;
         i < holeSentence.size(); ++i) {                   // handle spaces by remove all of them and leave just one.
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
        if ((i == 0 && !isspace(
                corrected[i]))) {                 // handle start of a sentence and make it uber case and others lower case.
            if (isalpha(corrected[i])) corrected[i] = toupper(corrected[i]);
        } else {
            if (isalpha(corrected[i])) corrected[i] = tolower(corrected[i]);
        }
        if ((isspace(corrected[i]) && corrected[i + 1] == '.') ||
            (isspace(corrected[i]) && corrected[i + 1] == ','))
            corrected.erase(i, 1);                           // if there is a space before "." or "," remove it.
        if ((!isspace(corrected[i + 1]) && corrected[i] == ',')) corrected.insert(i + 1, 1, ' ');
    }
    cout << "\nThe corrected sentence is : " << corrected << endl;
}

//======================================================================================================================

void getPrimes() {
    _setmode(_fileno(stdout), _O_TEXT);         // for handle using just ascii .
    _setmode(_fileno(stdin), _O_TEXT);          // for handle using just ascii .
    string number;
    long long num;
    vector<long long> numbers;
    vector<long long> crossed;
    bool notInteger = true, change;

    cout << "\n=====>This part gets an positive integer number and print primes from 2 to it.<=====\n\n";
    cout << "Please enter a positive integer number to get primes from 2 to it :";
    getline(cin, number);
    while (notInteger) {
        notInteger = false;                                         // get a number and check the validity of it.
        for (int i = 0; i < number.size(); ++i) {
            if (number[i] != '0' && number[i] != '1' && number[i] != '2' && number[i] != '3' && number[i] != '4' &&
                number[i] != '5' && number[i] != '6' && number[i] != '7' && number[i] != '8' && number[i] != '9') {
                notInteger = true;
                break;
            }
        }
        if (number.empty()) notInteger = true;
        if (!notInteger) {
            num = stoll(number);                                // check if the number is greater than 2.
            if (num < 2) notInteger = true;
        }
        if (notInteger) {
            cout << "\nPlease enter a correct positive integer number :";
            getline(cin, number);
        }
    }
    num = stoll(number);
    for (int i = 2; i <= num; ++i)
        numbers.push_back(i);            // put all numbers from 2 to the entered number in a vector.
    // then put primes in a vector and others in another vector.
    for (int i = 0; i < numbers.size(); ++i) {
        change = false;
        for (int j = 0; j < numbers.size(); ++j) {
            if (numbers[j] % numbers[i] == 0 && numbers[i] < numbers[j]) {
                numbers.erase(
                        numbers.begin() + j);         // check if any number is a multiple to first number and so on.
                change = true;
            }
        }
        if (change) {
            for (int j = 2; j <= num; ++j) {                        // add deleted numbers in crossed vector.
                auto it = find(numbers.begin(), numbers.end(), j);
                if (it != numbers.end()) continue;
                else crossed.push_back(j);
            }
            // print circled numbers(primes) every step.
            cout << "\nThe circled numbers(primes) in " << i + 1 << " are : ";
            for (int j = 0; j < numbers.size(); ++j) {
                if (j != numbers.size() - 1) cout << numbers[j] << ',';
                else cout << numbers[j];
            }
            // print crossed-out numbers(not prime) every step.
            cout << "\n\nThe crossed-out numbers(not prime) in " << i + 1 << " are : ";
            for (int j = 0; j < crossed.size(); ++j) {
                if (j != crossed.size() - 1) cout << crossed[j] << ',';
                else cout << crossed[j];
            }
            cout << "\n\n===========================================================================================\n";
            crossed.clear();
        }
    }

    for (int i = 2; i <= num; ++i) {                                // add deleted numbers in crossed vector.
        auto it = find(numbers.begin(), numbers.end(), i);
        if (it != numbers.end()) continue;
        else crossed.push_back(i);
    }

    cout << "\nThe final circled numbers(primes) are : ";            // print circled numbers(primes).
    for (int i = 0; i < numbers.size(); ++i) {
        if (i != numbers.size() - 1) cout << numbers[i] << ',';
        else cout << numbers[i];
    }

    cout << "\n\nThe final crossed-out numbers(not prime) are : ";  // print crossed-out numbers(not prime).
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
    _setmode(_fileno(stdout), _O_TEXT);         // for handle using just ascii .
    _setmode(_fileno(stdin), _O_TEXT);          // for handle using just ascii .
    static int start = 0, odd = 0, first, last;
    static vector<int> fi, la, fi2, la2;
    static deque<int> arrange;
    static unordered_map<int, int> freq;
    vector<int> odds;
    vector<pair<int, int>> recoFirst, recoSecond;
    vector<pair<int, int>> sorted;

    if (start == 0) {
        for (int i = 0;
             i < dominos.size(); ++i) {                   // make 4 vectors fi,fi2,la,la2 and put dominos in it.
            fi.push_back(dominos[i].leftDots);
            la.push_back(dominos[i].rightDots);
            fi2.push_back(dominos[i].leftDots);
            la2.push_back(dominos[i].rightDots);
            freq[dominos[i].leftDots]++;
            freq[dominos[i].rightDots]++;
        }
        for (auto it: freq) {            // get frequency for every element in dominos and calculate number of odds.
            if (it.second % 2 != 0) {
                odd++;
                odds.push_back(it.first);
            }
        }
        for(auto it : freq){
            sorted.push_back(make_pair(it.second,it.first));
        }
        sort(sorted.begin(), sorted.end(),greater<>());
        freq.clear();
        for (const auto& it : sorted) {
           freq[it.second] = it.first ;
        }
        if (odd > 2)
            return false;                                  //  if odd > 2 this mean that its impossible to make a chain.
        if (odd == 0)
            arrange.push_back(0);           // if odd = 0 there is no need to check anything just start with any one.
        else {                     // if odd = 2 i have to know which domino will be at first and which at end of chain.
            auto it = find(fi.begin(), fi.end(), odds[0]);
            if (it != fi.end()) {
                bool z = false;
                auto it2 = find(la.begin(), la.end(), odds[1]);
                if (it2 == la.end())
                    return false;                 // if both odd numbers at the same side its impossible to make a chain.
                for (int i = 0; i < fi2.size(); ++i) {           // loop to know which domino will be at start of chain.
                    if (fi2[i] == odds[0] && freq[la2[i]] == 2) {
                        first = i;
                        z = true;
                        arrange.push_back(first);
                        break;
                    }
                }
                if (!z){
                    for (int i = 0; i < fi2.size(); ++i) {       // loop to know which domino will be at start of chain.
                        if (fi2[i] == odds[0]) {
                            auto r = find(fi.begin(), fi.end(), la2[i]);
                            if (r != fi.end()) {
                                first = i;
                                arrange.push_back(first);
                                break;
                            }
                        }
                    }
                }
                fi[first] = -1;                                 // change these vales to avoid take it again.
                la[first] = -1;
            } else {
                bool z = false;
                auto it2 = find(la.begin(), la.end(), odds[1]);
                if (it2 == la.end())
                    return false;                 // if both odd numbers at the same side its impossible to make a chain.
                for (int i = 0; i < fi2.size(); ++i) {           // loop to know which domino will be at start of chain.
                    if (fi2[i] == odds[0] && freq[la2[i]] == 2) {
                        first = i;
                        z = true;
                        arrange.push_back(first);
                        break;
                    }
                }
                if (!z){
                    for (int i = 0; i < fi2.size(); ++i) {       // loop to know which domino will be at start of chain.
                        if (fi2[i] == odds[0]) {
                            auto r = find(fi.begin(), fi.end(), la2[i]);
                            if (r != fi.end()) {
                                first = i;
                                arrange.push_back(first);
                                break;
                            }
                        }
                    }
                }
                fi[first] = -1;                                 // change these vales to avoid take it again.
                la[first] = -1;
            }
        }                                                       // put base case.
    } else if (start == dominos.size()) {
        int y = 0;
        for (auto &it: dominos) {
            it.leftDots = fi2[arrange[y]];                     // rearrange domains to make chain.
            it.rightDots = la2[arrange[y]];
            y++;
        }
        return true;
    } else {
        bool found = false;
        auto it = find(fi.begin(), fi.end(), la2[arrange[start - 1]]);
        if (it !=
            fi.end()) {                                   // check if there is a value in right of domino and equal to left of last one.
            for (int i = 0; i < fi.size(); ++i) {
                if (fi[i] == la[i] && fi[i] == la2[arrange[start - 1]]) {
                    fi[i] = -1;
                    la[i] = -1;
                    arrange.push_back(i);
                    found = true;
                    break;
                }
            }
            if (!found) {
                arrange.push_back(it - fi.begin());
                fi[it - fi.begin()] = -1;
                la[it - fi.begin()] = -1;
            }
        } else {                                                // if there is no value it might be related to last.
            fi[arrange[arrange.size() - 1]] = fi2[arrange[arrange.size() - 1]];
            la[arrange[arrange.size() - 1]] = la2[arrange[arrange.size() - 1]];
            int x = arrange[arrange.size() - 1];
            arrange.pop_back();                                 // try taking another value instead of which depend on last.
            auto f = find((x + 1 + fi.begin()), fi.end(), la2[arrange[start - 2]]);
            if (f != fi.end()) {
                start--;
                arrange.push_back(f - fi.begin());
                fi[f - fi.begin()] = -1;
                la[f - fi.begin()] = -1;
            } else return false;
        }
    }
    start++;
    return FormsDominoChain(dominos);
}

void gameOfDominos() {
    _setmode(_fileno(stdout), _O_TEXT);         // for handle using just ascii .
    _setmode(_fileno(stdin), _O_TEXT);          // for handle using just ascii .
    string number, element;
    long long num;
    bool notInteger = true;
    int ele;

    cout << "\n=====>This part gets number of dominos and if possible to form a chain.<=====\n";
    cout << "\nPlease enter number of dominos :";
    getline(cin, number);
    while (notInteger) {
        notInteger = false;
        for (int i = 0; i < number.size(); ++i) {                     // get a number and check the validity of it.
            if ((number[i] != '0' && number[i] != '1' && number[i] != '2' && number[i] != '3' && number[i] != '4' &&
                 number[i] != '5' && number[i] != '6' && number[i] != '7' && number[i] != '8' && number[i] != '9')) {
                notInteger = true;
                break;
            }
        }
        if (number.empty()) notInteger = true;
        if (!notInteger) {
            num = stoll(number);
            if (num < 1) notInteger = true;                           // check the range of the number.
        }
        if (notInteger) {
            cout << "\nPlease enter a correct number of dominos :";
            getline(cin, number);
        }
    }
    num = stoll(number);
    vector<dominoT> dominos(num);

    for (long long i = 0; i < num; ++i) {
        cout << "\nPlease enter the Left Dots in " << i + 1 << " dominos :";
        getline(cin, element);                              // get left number of each domino.
        while (element != "0" && element != "1" && element != "2" && element != "3" && element != "4" &&
               element != "5" && element != "6") {
            cout << "\nPlease enter a valid Left Dots number in " << i + 1 << " dominos :";
            getline(cin, element);
        }
        ele = stoi(element);
        dominos[i].leftDots = ele;

        cout << "\nPlease enter the Right Dots in " << i + 1 << " dominos :";
        getline(cin, element);                              // get left number of each domino.
        while (element != "0" && element != "1" && element != "2" && element != "3" && element != "4" &&
               element != "5" && element != "6") {
            cout << "\nPlease enter a valid Right Dots number in " << i + 1 << " dominos :";
            getline(cin, element);
        }
        ele = stoi(element);
        dominos[i].rightDots = ele;
    }
    if (FormsDominoChain(dominos)) {                            // check if the function return yes or no.
        cout << "\nYes, it is possible to build a chain consisting of every domino in the vector.\n";
        for (int i = 0; i < dominos.size(); ++i) {
            if (i == dominos.size() - 1) cout << dominos[i].leftDots << " | " << dominos[i].rightDots;
            else cout << dominos[i].leftDots << " | " << dominos[i].rightDots << "  -  ";
        }
        cout << endl;
    } else cout << "\nNo, it is not possible to build a chain consisting of every domino in the vector.\n";
}

//======================================================================================================================

wstring editMessage(wstring &message) {
    _setmode(_fileno(stdout), _O_U16TEXT);          // Enable UTF-16 output .
    _setmode(_fileno(stdin), _O_U16TEXT);           // Enable UTF-16 input .
    wstring corrected;
    bool found = false;

    for (int i = 0; i < message.size(); ++i) {                            // handle spaces and leave only one.
        if ((isspace(message[i]) && !found && i != 0) ||
            (isspace(message[i]) && !found && i != 0 && message[i - 1] == '.') ||
            (isspace(message[i]) && !found && i != 0 && message[i - 1] == ',')) {
            corrected += L" ";
            found = true;
        } else if ((isspace(message[i]) && found) || (isspace(message[i]) && !found && i == 0)) continue;
        else {
            found = false;
            corrected += message[i];
        }
    }

    for (int i = 0; i < corrected.size(); ++i) {
        if ((i == 0 && !isspace(corrected[i]))) {                       // handle uber and lower case letters.
            if (isalpha(corrected[i])) corrected[i] = toupper(corrected[i]);
        } else {
            if (isalpha(corrected[i])) corrected[i] = tolower(corrected[i]);
        }
        if ((isspace(corrected[i]) && corrected[i + 1] == '.') ||
            (isspace(corrected[i]) && corrected[i + 1] == ','))
            corrected.erase(i, 1);                                // handle spaces before and after "." and ",".
        if ((!isspace(corrected[i + 1]) && corrected[i] == ',') ||
            (!isspace(corrected[i + 1]) && corrected[i] == '.'))
            corrected.insert(i + 1, 1, ' ');
    }
    return corrected;
}

void messageAlteringToAvoidCensorship() {
    _setmode(_fileno(stdout), _O_U16TEXT);       // Enable UTF-16 output .
    _setmode(_fileno(stdin), _O_U16TEXT);        // Enable UTF-16 input .
    locale::global(locale(""));

    std::wstringstream content;
    wstring edited = L"", message = L"", word = L"", enterOrRead, wfileName;
    string fileName;
    bool found = true;
    vector<wstring> words;                                            // words we want to replace it.
    vector<wstring> bias = {L"ثورة", L"احتجاج", L"اعتقال", L"حكومة", L"سجن", L"معارضة", L"ارهاب", L"حرب", L"انقلاب",
                            L"شهيد", L"مظاهرة", L"ديكتاتور", L"اغتيال", L"العقوبات", L"انفجار", L"تنظيم", L"تعذيب",
                            L"عدو", L"حظر", L"فساد", L"عصيان", L"نفي", L"اعتداء", L"ارهاب"};

    // replacement words.
    vector<wstring> alternative = {L"تغيير جذري", L"تعبير عن الرأي", L"احتجاز", L"السلطة التنفيذية", L"مركز إصلاح",
                                   L"تيار مختلف", L"العنف المنظم", L"نزاع مسلح", L"تغيير غير دستوري", L"ضحية النزاع",
                                   L"تجمع سلمي", L"حاكم مستبد", L"تصفية مستهدفة", L"قيود اقتصادية", L"حادث مدمر",
                                   L"مجموعة منظمة", L"إساءة المعاملة", L"طرف مخالف", L"قيود", L"سوء الإدارة",
                                   L"عدم الامتثال", L"إبعاد قسري", L"تجاوز جسدي", L"معارضة مسلحة"};

    wcout << L"\n=====>This part gets a message and replace some words (if exist) with another ones.<=====\n";
    wcout << L"\nThe file name should be like this ----> (file name).txt\n";
    wcout << L"Enter file name :";
    while (found) {
        fileName = "";
        getline(wcin, wfileName);                               // get file name and check the validity of format.
        if (wfileName.substr(wfileName.size() - 4, 4) != L".txt") {
            wcout << L"\nThe file name should be like this ----> (file name).txt\n";
            wcout << L"Please enter a valid file name :";
            wcin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        for (int i = 0; i < wfileName.size(); ++i) {
            fileName += wfileName[i];
        }
        wifstream file(fileName);                                   // check that the file is exist.
        if (!file.good()) {
            wcout << L"\nThis file does not exist.\n";
            wcout << L"\nThe file name should be like this ----> (file name).txt\n";
            wcout << L"Please enter a valid file name :";
            wcin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        file.imbue(std::locale(file.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
        content << file.rdbuf();
        found = false;
    }
    message = content.str();                                           // put file content in a variable.
    message = editMessage(message);

    for (int i = 0; i < message.size(); ++i) {
        if (isspace(message[i]) || message[i] == '.' || message[i] == ',') {
            words.push_back(word);
            word = L"";                                                 // put every word in a vector to make it easy for checking and replacement.
            if (message[i] == '.') words.push_back(L".");
            else if (message[i] == ',') words.push_back(L",");
        } else word += message[i];
    }
    if (!word.empty()) words.push_back(word);

    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < bias.size(); ++j) {                         // check if there are words i have to replace.
            if (words[i] == bias[j]) {
                words[i] = alternative[j];
                break;
            }
        }
    }
    for (const auto &w: words) {                         // put replaced words in a new variable.
        edited += w + L" ";
    }
    edited = editMessage(edited);                                   // handle file message after replacement.
    wofstream outFile(fileName, std::ios::out | std::ios::trunc);
    outFile.imbue(std::locale(outFile.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
    outFile << edited;                                                  // return the message in the file.
    outFile.close();
    wcout << L"File edited successfully!\n";
    wcin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//======================================================================================================================

int main() {
    _setmode(_fileno(stdout), _O_TEXT);         // for handle using just ascii .
    _setmode(_fileno(stdin), _O_TEXT);          // for handle using just ascii .
    bool firstTime = false;
    cout << "Welcome To My Program, This Program Includes\n" << "Solutions For Some Problems.\n";

    vector<string> stay = {"Continue", "Exit"};
    vector<string> back = {"Continue", "Back"};
    vector<string> problems = {"Correct A Sentence.", "generate A List Of Primes.", "The Game Of Dominos.",
                               "Message Altering to Avoid Censorship.", "Exit"};
    while (true) {
        if (firstTime) {
            string starOrOut = continueOrLeave(
                    stay);                   // check if it is the first time to enter a function  (to handle menu).
            while (starOrOut != "1" && starOrOut != "2") {
                cout << "Please enter a correct choice !\n";
                starOrOut = continueOrLeave(stay);
            }
            if (starOrOut == "2") break;
        }
        string choiceProblems = enterProblem(
                problems);                 // get number of problems and check its validity.
        while (choiceProblems != "1" && choiceProblems != "2" && choiceProblems != "3" && choiceProblems != "1" &&
               choiceProblems != "4" && choiceProblems != "5") {
            cout << "Please enter a correct choice !\n";
            choiceProblems = enterProblem(problems);
        }

        if (choiceProblems == "1") {                                    // Correct Sentence.
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
        } else if (choiceProblems == "2") {                             // Get Primes.
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
        } else if (choiceProblems == "3") {                             // Game Of Dominos.
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
        } else if (choiceProblems == "4") {                             // Message Altering To Avoid Censorship.
            string starOrBack = continueOrBack(back);
            while (starOrBack != "1" && starOrBack != "2") {
                cout << "Please enter a correct choice !\n";
                starOrBack = continueOrBack(back);
            }
            if (starOrBack == "2") {
                firstTime = true;
                continue;
            } else if (starOrBack == "1") {
                messageAlteringToAvoidCensorship();
            }
        } else if (choiceProblems == "5") {                             // exit program.
            break;
        }
        firstTime = true;
    }
    cout << "\nThanks for using my program !";
}
