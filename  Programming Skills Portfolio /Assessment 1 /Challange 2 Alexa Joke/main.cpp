
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
using namespace std;

int main() {
    ifstream file("randomJokes.txt");

    if (!file) {
        cout << "Error: Could not open randomJokes.txt" << endl;
        return 1;
    }

    vector<string> jokes;
    string line;

    while (getline(file, line)) {
        if (line.find('?') != string::npos) {
            jokes.push_back(line);
        }
    }

    file.close();

    if (jokes.empty()) {
        cout << "No valid jokes found." << endl;
        return 1;
    }

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> randomIndex(0, jokes.size() - 1);

    cout << "Alexa Joke Program" << endl;
    cout << "Type: Alexa, tell me a joke" << endl;
    cout << "Type: quit to exit" << endl;

    string command;

    while (true) {
        cout << "\nEnter command: ";
        getline(cin, command);

        if (command == "quit") {
            cout << "Goodbye!" << endl;
            break;
        }

        if (command == "Alexa, tell me a joke") {
            string joke = jokes[randomIndex(generator)];
            size_t position = joke.find('?');

            string setup = joke.substr(0, position + 1);
            string punchline = joke.substr(position + 1);

            cout << "\nAlexa: " << setup << endl;
            cout << "Press Enter for the punchline...";
            string wait;
            getline(cin, wait);

            cout << "Alexa: " << punchline << endl;
        }
        else {
            cout << "Unknown command. Try again." << endl;
        }
    }

    return 0;
}
