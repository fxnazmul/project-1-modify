#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>

using namespace std;

// User credentials storage (In a real system, this should be stored securely)
map<string, string> users = {{"admin", "1234"}};

// Function to handle user login
bool login(string &username) {
    string password;
    cout << "Enter username: ";
    cin >> username;
    cout<<"password:";
    cin >> password;

    if (users.find(username) != users.end() && users[username] == password) {
        cout << "Login successful!\n";
        return true;
    } else {
        cout << "Invalid credentials. Try again.\n";
        return false;
    }
}

// Function to get the computer's choice
string getComputerChoice() {
    string choices[3] = {"rock", "paper", "scissors"};
    return choices[rand() % 3];
}

// Function to determine the winner
string determineWinner(string userChoice, string computerChoice) {
    if (userChoice == computerChoice) {
        return "draw";
    } else if ((userChoice == "rock" && computerChoice == "scissors") ||
               (userChoice == "paper" && computerChoice == "rock") ||
               (userChoice == "scissors" && computerChoice == "paper")) {
        return "user";
    } else {
        return "computer";
    }
}

int main() {
    srand(time(0));  // Seed for random number generator

    string username;
    while (!login(username)) {}

    int userScore = 0, computerScore = 0;
    int highestUserScore = 0, highestComputerScore = 0;
    string userChoice;

    while (true) {
        cout << "\nEnter rock, paper, or scissors (or 'exit' to quit): ";
        cin >> userChoice;

        if (userChoice == "exit") {
            cout << "\nFinal Scores - " << username << " : " << userScore << " | Computer: " << computerScore << "\n";
            cout << "Highest Scores - " << username << " : " << highestUserScore << " | Computer: " << highestComputerScore << "\n";
            break;
        }

        if (userChoice != "rock" && userChoice != "paper" && userChoice != "scissors") {
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        string computerChoice = getComputerChoice();
        cout << "Computer chose: " << computerChoice << "\n";

        string result = determineWinner(userChoice, computerChoice);
        if (result == "user") {
            userScore++;
            highestUserScore = max(highestUserScore, userScore);
            cout << "You win this round!\n";
        } else if (result == "computer") {
            computerScore++;
            highestComputerScore = max(highestComputerScore, computerScore);
            cout << "Computer wins this round!\n";
        } else {
            cout << "It's a draw!\n";
        }

        cout << "Current Score - " << username << ": " << userScore << " | Computer: " << computerScore << "\n";
    }

    return 0;
}

