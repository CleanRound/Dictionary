#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

string removePunctuation(const string& word) {
    string result;
    for (char ch : word) {
        if (isalpha(ch) || ch == '\'') {
            result += tolower(ch);
        }
    }
    return result;
}

int main() {
    string filename;
    cout << "Enter the name of the input file: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error: Unable to open input file.\n";
        return 1;
    }

    map<string, int> wordFreq;

    string word;
    while (inputFile >> word) {
        word = removePunctuation(word);
        if (!word.empty()) {
            wordFreq[word]++;
        }
    }

    cout << "Information about all words:\n";
    for (const auto& pair : wordFreq) {
        cout << pair.first << ": " << pair.second << " occurrences\n";
    }

    string mostFrequentWord;
    int maxFrequency = 0;
    for (const auto& pair : wordFreq) {
        if (pair.second > maxFrequency) {
            mostFrequentWord = pair.first;
            maxFrequency = pair.second;
        }
    }

    cout << "Most frequently used word: " << mostFrequentWord << " ("
        << maxFrequency << " occurrences)\n";

    ofstream outputFile("word_freq_result.txt");
    if (!outputFile) {
        cerr << "Error: Unable to open output file.\n";
        return 1;
    }
    for (const auto& pair : wordFreq) {
        outputFile << pair.first << ": " << pair.second << " occurrences\n";
    }

    cout << "Result written to word_freq_result.txt\n";

    return 0;
}
