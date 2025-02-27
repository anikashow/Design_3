#include <iostream>
#include <string>

using namespace std;

void prompt1(string &currentLocation) {
    string input;
    cout << "You find yourself in a lawn chair at a folding table, sitting across from your Benton county comissioners: Nancy Wyse, Pat Malone, and Gabe Sheperd. 
        The light is dim. You cannot remember how you got there. Can you guess what day of the week it is? Choose carefully. The comissioners are listening.\n";
    cout << "What day of the week is it? For better odds, we have narrowed it down to four options for you: (Monday, Tuesday, Wednesday, Friday): ";
    
    while (true) {
        getline(cin, input);

        if (input == "Monday" || input == "Friday") {
            cout << "Oh... you think it's " << input << "?... You chose incorrectly, BUT luckily for you, Nancy has a sweet spot for " <<input<< ". Nothing else happens.\n";
            currentFate = "peace";  // A generic location
            break;
        } else if (input == "Tuesday") {
            cout << "Congratulations, you guessed the correct day of the week! Unfortunately, the commisioners have begun to suspect that you know too much. 
                The room appears less dim, and you catch a whiff of what smells like exhaust...\n";
            currentFate = "truth";  // Going to the cave with the dragon
            break;
        } else if (input == "Wednesday") {
            cout << "Yeah, I wish it was Wednesday. The comissioners look at eachother, and a slow smile creeps across their faces. 
                Pat laughs, and tells you it's time to pay the piper.\n";
            currentFate = "death";  // Finding treasure
            break;
        } else {
            cout << "Invalid input! Please check your spelling, and remember you can only enter one of the days listed. May the odds forever be in your favor.\n";
        }
    }
}

void prompt2(const string &currentFate) {
    string input;

    if (currentFate == "truth") 
       
        cout << "The commisioners pull out their weapons.\n";
        cout << "Do you try to remember where you are, or flee from the room? (remember, flee): ";

        while (true) {
            getline(cin, input);

            if (input == "remember") {
                cout << "You take in the smell of exhaust, the lawn chairs and the ever-brightening room, and suddenly wake up. You are on the ground at a gas station.
                    You passed out from inhaling too many fumes. A newspaper is scattered on the ground next to a toppled lawn chair. Election results just in.
                    Maybe you should find somewhere else to take your break. You quit your job at Chevron. Game over.\n";
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
