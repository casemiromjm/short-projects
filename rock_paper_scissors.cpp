/* this is my first attempt to make a little
project in c++. this will be a rock, paper,
sciossors game*/

#include <iostream>
using namespace std;

string player_choice(){                         // function to get player choice and validate it
    string p_choice, choices[3] = {"Rock", "Paper", "Scissors"};

    cout << "Choose between Rock, Paper or Scissors: ";
    cin >> p_choice;

    // validate input
    if (p_choice[0] == 'r'){
		p_choice[0] = 'R';
    }
    else if (p_choice[0] == 'p'){
		p_choice[0] = 'P';
    }
    else{
		p_choice[0] = 'S';
    }

    while ((p_choice != "Paper") && (p_choice != "Rock") && (p_choice != "Scissors")){
		cout << " \n";
		cout << "You wrote something other than the possible choices! Try again!\n";
        cout << "Choose between Rock, Paper or Scissors: ";
        cin >> p_choice;

        if (p_choice[0] == 'r'){
            p_choice[0] = 'R';
        }
        else if (p_choice[0] == 'p'){
            p_choice[0] = 'P';
        }
        else{
            p_choice[0] = 'S';
        }
	}
    
    return p_choice;
}

string computer_choice(void){                       // function to get computer choice
    string c_choice, choices[3] = {"Rock", "Paper", "Scissors"};
    int index;

    time_t current_time = time(NULL);           // generate a random seed
    srand(current_time);

    index = rand() % 3;                         // generate a random number between 0 to 2

    c_choice = choices[index];                  // get computer choice

    return c_choice;
}

int main(void){                                 // function that checks who won
    string player_played, computer_played;

    // get choices
    player_played = player_choice();
    computer_played = computer_choice();


    // check who won
    if (player_played == computer_played){
        cout << "You and the computer chose " << player_played << '.' << " It's a tie! Try again next time!\n";
    }

    else if (player_played == "Rock"){
        if (computer_played == "Paper"){
            cout << "You picked Rock, but the computer picked Paper. You lost!\n";
        }
        else{
            cout << "You picked Rock and the computer picked Scissors. You won!\n";
        }
    }
    
    else if (player_played == "Scissors"){
        if (computer_played == "Paper"){
            cout << "You picked Scissors and the computer picked Paper. You won!\n";
        }
        else{
            cout << "You picked Scissors, but the computer picked Rock. You lost!\n";
        }
    }

    else if (player_played == "Paper"){
        if (computer_played == "Rock"){
            cout << "You picked Paper and the computer picked Rock. You won!\n";
        }
        else{
            cout << "You picked Paper, but the computer picked Scissors. You lost!\n";
        }
    }

    return 0;
}