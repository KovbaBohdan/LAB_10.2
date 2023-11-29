#include <fstream>
#include <string>
#include <Windows.h>
#include <iostream>

using namespace std;

int Count(const string& S) 
{
    string word;
    int count = 0;

    size_t start = 0, end;

    while (start < S.length()) {
        while (start < S.length() && (S[start] == ' ' || S[start] == '\t' || S[start] == '\n'))
            start++;

        if (start >= S.length())
            break;

        end = start;
        while (end < S.length() && !(S[end] == ' ' || S[end] == '\t' || S[end] == '\n'))
            end++;

        word = S.substr(start, end - start);
        if (!word.empty() && word[0] == word[word.length() - 1])
            count++;

        start = end;
    }
    return count;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename;
    cout << "Enter the file name: ";
    getline(cin, filename);

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file '" << filename << "'" << endl;
        return 1;
    }

    string fileContent;
    string temp;
    while (file >> temp)
        fileContent += temp + " ";

    cout << "File content: " << endl << fileContent << endl;

    int wordsCount = Count(fileContent);

    cout << "Number of words that start and end with the same letter: " << wordsCount << endl;

    return 0;
}

