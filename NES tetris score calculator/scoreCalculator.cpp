#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int score;
vector<int> lines; //index 0 is prev lines, index 1 is current lines
int level;

const int lvl0Scores[] = {40, 100, 300, 1200};

int getInput(string promptText) {
    string input;
    while (true) {
        cout << promptText;
        getline(cin, input);
        try {
            return stoi(input);
        }
        catch(...) {
            cout << "Enter an integer\n";
        }
    }
}

int main() {
    score = getInput("Starting score: ");
    lines.push_back(getInput("Starting lines: "));
    while (true) {
        lines.push_back(getInput("Next lines: "));
        int linesCleared = lines[1] - lines[0];
        if (linesCleared < 1) {
            cout << "Enter a lines greater than the previous lines\n";
            lines.pop_back();
        }
        else if (linesCleared > 4) {
            cout << "Enter a lines which actually makes sense\n";
            lines.pop_back();
        }
        else {
            if (lines[1] < 130) {
                level = 18;
            }
            else {
                level = 19 + ((lines[1]-130)/10);
            }
            score += lvl0Scores[linesCleared-1]*(level+1);
            cout << "Score: " << score << endl;
            lines.erase(lines.begin());
        }
    }
    return 0;
}