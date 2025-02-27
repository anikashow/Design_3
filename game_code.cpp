#include <iostream>
#include <string>

using namespace std;

void prompt1(string &currentFate) {
    string input;
    cout << "You find yourself in a lawn chair at a folding table, sitting across from your Benton county commissioners: "
         << "Nancy Wyse, Pat Malone, and Gabe Shepherd. The light is dim. You cannot remember how you got there. "
         << "Can you guess what day of the week it is? Choose carefully. The commissioners are listening.\n";
    cout << "What day of the week is it? For better odds, we have narrowed it down to four options for you: "
         << "(Monday, Tuesday, Wednesday, Friday): ";
    
    while (true) {
        getline(cin, input);

        if (input == "Monday" || input == "Friday") {
            cout << "Oh... you think it's " << input << "?... You chose incorrectly, BUT luckily for you, Nancy has a sweet spot for " 
                 << input << ".\n";
            currentFate = "peace";  
            break;
        } else if (input == "Tuesday") {
            cout << "Congratulations, you guessed the correct day of the week! Unfortunately, the commissioners have begun to suspect that "
                 << "you know too much. The room appears less dim, and you catch a whiff of what smells like exhaust...\n";
            currentFate = "truth";  
            break;
        } else if (input == "Wednesday") {
            cout << "Yeah, I wish it was Wednesday. The commissioners look at each other, and a slow smile creeps across their faces. "
                 << "Pat laughs, and tells you it's time to pay the piper.\n";
            currentFate = "death";  // Finding treasure
            break;
        } else {
            cout << "Invalid input! Please check your spelling, and remember you can only enter one of the days listed. "
                 << "May the odds forever be in your favor.\n";
        }
    }
}

void prompt2(const string &currentFate) {
    string input;

    if (currentFate == "truth") {
        cout << "The commissioners pull out their weapons.\n";
        cout << "Do you try to remember where you are, or flee from the room? (remember, flee): ";

        while (true) {
            getline(cin, input);

            if (input == "remember") {
                cout << "You take in the smell of exhaust, the lawn chairs, and the ever-brightening room, and suddenly wake up. "
                     << "You are on the ground at a gas station. You passed out from inhaling too many fumes. A newspaper is scattered "
                     << "on the ground next to a toppled lawn chair. Election results just in. Maybe you should find somewhere else to take "
                     << "your break. You quit your job at Chevron. Game over.\n";
                break;
            } else if (input == "flee") {
                cout << "You stand up, throw your lawn chair at the table and run. Everything moves in slow motion. Your feet become heavy. "
                     << "You feel yourself drift off... You ran off the edge of the subconscious world and reality as you know it"
                      << "has bmelted. You die. \n";
                break;
            } else {
                cout << "Invalid input! Please choose between remember or flee.\n";
            }
        }
    } else if (currentFate == "death") {
        cout << "You are becoming more unsettled. The commissioners craft and hand you a document to sign. Your hand raises against your "
             << "will and drags a pen across the dotted line, as if guided by something supernatural. You lost the game.\n";
    } else {
        cout << "You are in an unknown area. Please make a valid decision.\n";
    }
}

void prompt3(const string &currentFate) {
    string input;

    if (currentFate == "peace") {
        cout << "Nancy leans over and kisses you on the forehead, and then asks if you are ready to wake up. \n";
         cout << "Are you ready? (yes or no): ";
 while (true) {
            getline(cin, input);

            if (input == "yes") {
                cout << "You have chosen to awaken from blissful disacociative slumber and will now be forced to continue to endure"
                     << "the existentially complex and tormentful experience that is humantiy searching for the true moral good. \n";
                break;
            } else if (input == "no") {
                cout << "Your eyelids become heavy. You feel yourself drift into peaceful slumber. Nothingness. No dark, no light. "
                     << "Nothing is, and yet everything is. Nothing and something are asynchronous. You have chosen Nirvana.\n";
                break;
            } else {
                cout << "Invalid input! You must chose between the fate of slumber and whatever waits in wake.\n";
            }
        }
    } else {
        cout << "The adventure continues...\n";
    }
}

int main() {
    cout << "Welcome.\n";
    string startInput;

    cout << "Would you like to begin? (yes or no): ";
    getline(cin, startInput);

    if (startInput == "yes") {
        string currentFate = "";

        // Prompt 1: The user chooses a direction
        prompt1(currentFate);

        
        prompt2(currentFate);

        // Prompt 3: Additional storyline progression
        prompt3(currentFate);

        cout << "Congratulations! You've completed the adventure!\n";
    } else {
        cout << "Maybe next time! Goodbye!\n";
    }

    return 0;
}
