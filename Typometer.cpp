#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

int calculateWPM(int wordsTyped, double seconds)
{
    return (wordsTyped / seconds) * 60;
}

int calculateAccuracy(const string& original, const string& typed)
{
    int correctChars = 0;
    int length = original.length();

    for (int i = 0; i < length; i++)
    {
        if (i < typed.length() && original[i] == typed[i])
        {
            correctChars++;
        }
    }

    return (correctChars * 100) / length;
}

int main()
{
    string sentences[] = {
        "The quick brown fox jumps over the lazy dog.",
        "Hello world, welcome to the typing speed test.",
        "C++ programming is both powerful and complex.",
        "Keep practicing to improve your typing speed and accuracy.",
        "Consistency is the key to mastering anything in life."
    };

    srand(time(0));
    string sentence = sentences[rand() % 5];

    cout << "Typing Speed Test\n";
    cout << "-----------------\n";
    cout << "Type the following sentence as fast as you can:\n\n";
    cout << "\"" << sentence << "\"\n\n";

    cout << "Press Enter when you're ready to start..." << endl;
    cin.ignore();

    auto start = high_resolution_clock::now();

    string userInput;
    cout << "Start typing: ";
    getline(cin, userInput);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start).count();

    int accuracy = calculateAccuracy(sentence, userInput);

    int wordCount = 1;
    for (int i = 0; i < userInput.length(); i++)
    {
        if (userInput[i] == ' ' && i + 1 < userInput.length() && userInput[i + 1] != ' ')
        {
            wordCount++;
        }
    }

    int wpm = calculateWPM(wordCount, duration);

    cout << "\nTime: " << duration << " seconds\n";
    cout << "Words per minute (WPM): " << wpm << endl;
    cout << "Accuracy: " << accuracy << "%\n";

    return 0;
}
