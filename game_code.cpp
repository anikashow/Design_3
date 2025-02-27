#include <iostream>
#include <string>

using namespace std;

void prompt1(string &currentLocation) {
    string input;
    cout << "You find yourself at a crossroads in a dark forest.\n";
    cout << "Where would you like to go? (north, south, east, west): ";
    
    while (true) {
        getline(cin, input);

        if (input == "north" || input == "south") {
            cout << "You walk " << input << " and find a peaceful area. Nothing else happens.\n";
            currentLocation = "other";  // A generic location
            break;
        } else if (input == "east") {
            cout << "You walk east and enter a dark cave...\n";
            currentLocation = "cave";  // Going to the cave with the dragon
            break;
        } else if (input == "west") {
            cout << "You walk west and discover a treasure chest! You win!\n";
            currentLocation = "treasure";  // Finding treasure
            break;
        } else {
            cout << "Invalid input! Please choose between north, south, east, or west.\n";
        }
    }
}

void prompt2(const string &currentLocation) {
    string input;

    if (currentLocation == "cave") {
        // If the user entered the cave
        cout << "You've entered the cave and are face-to-face with a dragon!\n";
        cout << "Do you want to fight or flee? (fight, flee): ";

        while (true) {
            getline(cin, input);

            if (input == "fight") {
                cout << "You courageously fight the dragon, but alas, it was too powerful. Game over.\n";
                break;
            } else if (input == "flee") {
                cout << "You flee from the dragon and safely exit the cave. You live to fight another day.\n";
                break;
            } else {
                cout << "Invalid input! Please choose between fight or flee.\n";
            }
        }
    } else if (currentLocation == "treasure") {
        // If the user found the treasure
        cout << "You have already found the treasure chest and won! Congratulations!\n";
    } else {
        cout << "You are in an unknown area. Please make a valid decision.\n";
    }
}

void prompt3(const string &currentLocation) {
    string input;

    if (currentLocation == "other") {
        // If the user went to a peaceful area (north/south)
        cout << "You are in a peaceful area and nothing significant happens.\n";
    } else {
        // For all other locations, like finding treasure or dragon outcomes
        cout << "The adventure continues...\n";
    }
}

int main() {
    cout << "Welcome to the Adventure Game!\n";
    string startInput;

    cout << "Do you want to start the adventure? (yes or no): ";
    getline(cin, startInput);

    if (startInput == "yes") {
        string currentLocation = "";

        // Prompt 1: The user chooses a direction
        prompt1(currentLocation);

        // Prompt 2: The user’s next action depends on their location
        prompt2(currentLocation);

        // Prompt 3: Additional storyline progression
        prompt3(currentLocation);
        cout << "Congratulations! You've completed the adventure!\n";
    } else {
        cout << "Maybe next time! Goodbye!\n";
    }

    return 0;
}
