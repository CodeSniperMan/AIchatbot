#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <map>

using namespace std;

// Sample dialogues and responses
map<string, string> responses = {
    {"hi", "Hello! How can I assist you today?"},
    {"how are you", "I'm a machine, so I don't have feelings, but thanks for asking! How can I help you?"},
    {"what is your name", "I'm a chatbot created by OpenAI. You can call me ChatGPT!"},
    {"thank you", "You're welcome! If you have any more questions, feel free to ask."},
    {"bye", "Goodbye! Have a great day!"}
};

string get_response(const string &input) {
    string response = "I'm sorry, I'm not sure how to respond to that.";

    // Convert input to lowercase for case-insensitive matching
    string lower_input = input;
    transform(lower_input.begin(), lower_input.end(), lower_input.begin(), ::tolower);

    // Check if input matches any predefined patterns
    for (const auto &pair : responses) {
        if (regex_search(lower_input, regex(pair.first))) {
            response = pair.second;
            break;
        }
    }

    return response;
}

int main() {
    cout << "Welcome! How can I assist you today?\n";
    string input;
    while (true) {
        cout << "You: ";
        getline(cin, input);
        if (input == "exit") {
            cout << "Goodbye! Have a great day!\n";
            break;
        }

        // Get response based on input
        string response = get_response(input);
        cout << "ChatGPT: " << response << endl;
    }

    return 0;
}
