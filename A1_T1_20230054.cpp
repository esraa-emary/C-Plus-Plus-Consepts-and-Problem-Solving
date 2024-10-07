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
#include <locale>
#include <io.h>   // For _setmode
#include <fcntl.h> // For _O_U16TEXT
#include <codecvt>
#include <sstream>

using namespace std;

//======================================================================================================================

string enterProblem(vector<string> problems) {
    _setmode(_fileno(stdout), _O_TEXT);
    _setmode(_fileno(stdin), _O_TEXT);
    string choiceProblems;
    cout << "\nWhich problem you want to solve ?\n";
    for (int i = 0; i < problems.size(); ++i) {
        cout << i + 1 << " - " << problems[i] << endl;
    }
    cout << "Enter your answer :";
    getline(cin, choiceProblems);
    return choiceProblems;
}

string continueOrLeave(vector<string> stay) {
    _setmode(_fileno(stdout), _O_TEXT);
    _setmode(_fileno(stdin), _O_TEXT);
    string starOrOut;
    cout << "\nDo you want to continue or exit ?\n";
    for (int i = 0; i < stay.size(); ++i) {
        cout << i + 1 << " - " << stay[i] << endl;
    }
    cout << "Enter your answer :";
    getline(cin, starOrOut);
    return starOrOut;
}

string continueOrBack(vector<string> back) {
    _setmode(_fileno(stdout), _O_TEXT);
    _setmode(_fileno(stdin), _O_TEXT);
    string starOrBack;
    cout << "\nDo you want to continue or back ?\n";
    for (int i = 0; i < back.size(); ++i) {
        cout << i + 1 << " - " << back[i] << endl;
    }
    cout << "Enter your answer :";
    getline(cin, starOrBack);
    return starOrBack;
}

//======================================================================================================================

void correctSentence() {
    _setmode(_fileno(stdout), _O_TEXT);
    _setmode(_fileno(stdin), _O_TEXT);
    string corrected, sentence, holeSentence = "";
    bool found = false;

    cout << "\n=====>This part gets a sentence and correct is.<=====\n";
    cout << "\nEnter the sentence you want to correct :";
    cout << endl;

    while (true) {
        getline(cin, sentence);
        for (int i = 0; i < sentence.size(); ++i) {
            if (sentence[i] == '.') {
                found = true;
                sentence.erase(i + 1, sentence.size() - i - 1);
                holeSentence += sentence;
            }
        }
        if (found) break;
        else {
            holeSentence += sentence;
            holeSentence += ' ';
        }
    }

    found = false;
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
    cout << "\nThe corrected sentence is : " << corrected << endl;
}

//======================================================================================================================

void getPrimes() {
    _setmode(_fileno(stdout), _O_TEXT);
    _setmode(_fileno(stdin), _O_TEXT);
    string number;
    long long num;
    vector<long long> numbers;
    vector<long long> crossed;
    bool notInteger = true, change;
    cout << "\n=====>This part gets an positive integer number and print primes from 2 to it.<=====\n\n";
    cout << "Please enter a positive integer number to get primes from 2 to it :";
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
        if (number.empty()) notInteger = true;
        if (!notInteger) {
            num = stoll(number);
            if (num < 2) notInteger = true;
        }
        if (notInteger) {
            cout << "\nPlease enter a correct positive integer number :";
            getline(cin, number);
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
    _setmode(_fileno(stdout), _O_TEXT);
    _setmode(_fileno(stdin), _O_TEXT);
    static int start = 0, odd = 0, first, last;
    static vector<int> fi, la, fi2, la2;
    static deque<int> arrange;
    map<int, int> freq;
    vector<int> odds;
    vector<pair<int, int>> recoFirst, recoSecond;

    if (start == 0) {
        for (int i = 0; i < dominos.size(); ++i) {
            fi.push_back(dominos[i].leftDots);
            la.push_back(dominos[i].rightDots);
            fi2.push_back(dominos[i].leftDots);
            la2.push_back(dominos[i].rightDots);
            freq[dominos[i].leftDots]++;
            freq[dominos[i].rightDots]++;
        }
        for (auto it: freq) {
            if (it.second % 2 != 0) {
                odd++;
                odds.push_back(it.first);
            }
        }
        if (odd > 2) return false;
        if (odd == 0) arrange.push_back(0);
        else {
            auto it = find(fi.begin(), fi.end(), odds[0]);
            if (it != fi.end()) {
                first = it - fi.begin();
                auto it2 = find(la.begin(), la.end(), odds[1]);
                if (it2 != la.end()) last = it2 - la.begin();
                else return false;
                for (int i = 0; i < fi2.size(); ++i) {
                    if (fi2[i] == odds[0]) {
                        fi[i] = -1;
                        la[i] = -1;
                        auto r = find(fi.begin(), fi.end(), la2[i]);
                        if (r != fi.end()) {
                            first = r - fi.begin();
                            break;
                        }
                        else{
                            for (int j = 0; j < fi.size(); ++j) {
                                fi[j]=fi2[j];
                                la[j]=la2[j];
                            }
                        }
                    }
                }
                for (int i = 0; i < fi.size(); ++i) {
                    fi[i]=fi2[i];
                    la[i]=la2[i];
                }
                for (int i = 0; i < la2.size(); ++i) {
                    if (la2[i] == odds[1]) {
                        fi[i] = -1;
                        la[i] = -1;
                        auto r = find(la.begin(), la.end(), fi2[i]);
                        if (r != la.end()) {
                            last = r - la.begin();
                            break;
                        }
                        else{
                            for (int j = 0; j < fi.size(); ++j) {
                                fi[j]=fi2[j];
                                la[j]=la2[j];
                            }
                        }
                    }
                }
                for (int i = 0; i < fi.size(); ++i) {
                    fi[i]=fi2[i];
                    la[i]=la2[i];
                }
                fi[first] = -1;
                la[first] = -1;
                fi[last] = -1;
                la[last] = -1;
                arrange.push_back(first);
            } else {
                last = it - fi.begin();
                auto it2 = find(la.begin(), la.end(), odds[1]);
                if (it2 != la.end()) first = odds[1];
                else return false;
                for (int i = 0; i < fi2.size(); ++i) {
                    if (fi2[i] == odds[0]) {
                        fi[i] = -1;
                        la[i] = -1;
                        auto r = find(fi.begin(), fi.end(), la2[i]);
                        if (r != fi.end()) {
                            first = r - fi.begin();
                            break;
                        }
                        else{
                            for (int j = 0; j < fi.size(); ++j) {
                                fi[j]=fi2[j];
                                la[j]=la2[j];
                            }
                        }
                    }
                }
                for (int i = 0; i < fi.size(); ++i) {
                    fi[i]=fi2[i];
                    la[i]=la2[i];
                }
                for (int i = 0; i < la2.size(); ++i) {
                    if (la2[i] == odds[1]) {
                        fi[i] = -1;
                        la[i] = -1;
                        auto r = find(la.begin(), la.end(), fi2[i]);
                        if (r != la.end()) {
                            last = r - la.begin();
                            break;
                        }
                        else{
                            for (int j = 0; j < fi.size(); ++j) {
                                fi[j]=fi2[j];
                                la[j]=la2[j];
                            }
                        }
                    }
                }
                for (int i = 0; i < fi.size(); ++i) {
                    fi[i]=fi2[i];
                    la[i]=la2[i];
                }
                fi[first] = -1;
                la[first] = -1;
                fi[last] = -1;
                la[last] = -1;
                arrange.push_back(it2 - la.begin());
            }
        }
    } else if ((start == dominos.size() && odd == 0) || (start == dominos.size() - 1 && odd != 0)) {
        if (odd != 0) arrange.push_back(last);
        int y = 0;
        for (auto &it: dominos) {
            it.leftDots = fi2[arrange[y]];
            it.rightDots = la2[arrange[y]];
            y++;
        }
        return true;
    } else {
        auto it = find(fi.begin(), fi.end(), la2[arrange[start - 1]]);
        if (it != fi.end()) {
            arrange.push_back(it - fi.begin());
            fi[it - fi.begin()] = -1;
            la[it - fi.begin()] = -1;
        } else return false;
    }
    start++;
    return FormsDominoChain(dominos);
}

void gameOfDominos() {
    _setmode(_fileno(stdout), _O_TEXT);
    _setmode(_fileno(stdin), _O_TEXT);
    string number, element;
    long long num;
    bool notInteger = true;
    int ele;

    cout << "\n=====>This part gets number of dominos and if possible to form a chain.<=====\n";
    cout << "\nPlease enter number of dominos :";
    getline(cin, number);
    while (notInteger) {
        notInteger = false;
        for (int i = 0; i < number.size(); ++i) {
            if ((number[i] != '0' && number[i] != '1' && number[i] != '2' && number[i] != '3' && number[i] != '4' &&
                 number[i] != '5' && number[i] != '6' && number[i] != '7' && number[i] != '8' && number[i] != '9')) {
                notInteger = true;
                break;
            }
        }
        if (number.empty()) notInteger = true;
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
        cout << "\nPlease enter the Left Dots in " << i + 1 << " dominos :";
        getline(cin, element);
        while (element != "0" && element != "1" && element != "2" && element != "3" && element != "4" &&
               element != "5" && element != "6") {
            cout << "\nPlease enter a valid Left Dots number in " << i + 1 << " dominos :";
            getline(cin, element);
        }
        ele = stoi(element);
        dominos[i].leftDots = ele;

        cout << "\nPlease enter the Right Dots in " << i + 1 << " dominos :";
        getline(cin, element);
        while (element != "0" && element != "1" && element != "2" && element != "3" && element != "4" &&
               element != "5" && element != "6") {
            cout << "\nPlease enter a valid Right Dots number in " << i + 1 << " dominos :";
            getline(cin, element);
        }
        ele = stoi(element);
        dominos[i].rightDots = ele;
    }
    if (FormsDominoChain(dominos)) {
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
    _setmode(_fileno(stdout), _O_U16TEXT);  // Enable UTF-16 output
    _setmode(_fileno(stdin), _O_U16TEXT);   // Enable UTF-16 input
    wstring corrected;
    bool found = false;

    for (int i = 0; i < message.size(); ++i) {
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
        if ((i == 0 && !isspace(corrected[i]))) {
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
    return corrected;
}

void messageAlteringToAvoidCensorship() {
    _setmode(_fileno(stdout), _O_U16TEXT);  // Enable UTF-16 output
    _setmode(_fileno(stdin), _O_U16TEXT);   // Enable UTF-16 input
    locale::global(locale(""));

    std::wstringstream content;
    wstring edited = L"", message = L"", word = L"", enterOrRead, wfileName;
    string fileName;
    bool found = true;
    vector<wstring> words;
    vector<wstring> bias = {L"ثورة", L"احتجاج", L"اعتقال", L"حكومة", L"سجن", L"معارضة", L"ارهاب", L"حرب", L"انقلاب",
                            L"شهيد", L"مظاهرة", L"ديكتاتور", L"اغتيال", L"العقوبات", L"انفجار", L"تنظيم", L"تعذيب",
                            L"عدو", L"حظر", L"فساد", L"عصيان", L"نفي", L"اعتداء", L"ارهاب"};

    vector<wstring> alternative = {L"تغيير جذري", L"تعبير عن الرأي", L"احتجاز", L"السلطة التنفيذية", L"مركز إصلاح",
                                   L"تيار مختلف", L"العتف المنظم", L"نزاع مسلح", L"تغيير غير دستوري", L"ضحية النزاع",
                                   L"تجمع سلمي", L"حاكم مستبد", L"تصفية مستهدفة", L"قيود اقتصادية", L"حادث مدمر",
                                   L"مجموعة منظمة", L"إساءة المعاملة", L"طرف مخالف", L"قيود", L"سوء الإدارة",
                                   L"عدم الامتثال", L"إبعاد قسري", L"تجاوز جسدي", L"معارضة مسلحة"};

    wcout << L"\n=====>This part gets a message and replace some words (if exist) with another ones.<=====\n";
    wcout << L"\nThe file name should be like this ----> (file name).txt\n";
    wcout << L"Enter file name :";
    while (found) {
        fileName = "";
        getline(wcin, wfileName);
        if (wfileName.substr(wfileName.size() - 4, 4) != L".txt") {
            wcout << L"\nThe file name should be like this ----> (file name).txt\n";
            wcout << L"Please enter a valid file name :";
            wcin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        for (int i = 0; i < wfileName.size(); ++i) {
            fileName += wfileName[i];
        }
        wifstream file(fileName);
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
    message = content.str();
    message = editMessage(message);

    for (int i = 0; i < message.size(); ++i) {
        if (isspace(message[i]) || message[i] == '.' || message[i] == ',') {
            words.push_back(word);
            word = L"";
            if (message[i] == '.') words.push_back(L".");
            else if (message[i] == ',') words.push_back(L",");
        } else word += message[i];
    }
    if (!word.empty()) words.push_back(word);

    for (int i = 0; i < words.size(); ++i) {
        for (int j = 0; j < bias.size(); ++j) {
            if (words[i] == bias[j]) {
                words[i] = alternative[j];
                break;
            }
        }
    }
    for (const auto &w: words) {
        edited += w + L" ";
    }
    wofstream outFile(fileName, std::ios::out | std::ios::trunc);
    outFile.imbue(std::locale(outFile.getloc(), new std::codecvt_utf8_utf16<wchar_t>));
    outFile << edited;
    outFile.close();
    wcout << L"File edited successfully!\n";
    wcin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//======================================================================================================================

int main() {
    _setmode(_fileno(stdout), _O_TEXT);
    _setmode(_fileno(stdin), _O_TEXT);
    bool firstTime = false;
    cout << "Welcome To My Program, This Program Includes\n" << "Solutions For Some Problems.\n";

    vector<string> stay = {"Continue", "Exit"};
    vector<string> back = {"Continue", "Back"};
    vector<string> problems = {"Correct A Sentence.", "generate A List Of Primes.", "The Game Of Dominos.",
                               "Message Altering to Avoid Censorship.", "Exit"};
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
                messageAlteringToAvoidCensorship();
            }
        } else if (choiceProblems == "5") {
            break;
        }
        firstTime = true;
    }
    cout << "\nThanks for using my program !";
}
