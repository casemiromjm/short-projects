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

string computer_choice(void){                   // function to get computer choice
    string c_choice, choices[3] = {"Rock", "Paper", "Scissors"};
    int index;

    time_t current_time = time(NULL);           // generate a random seed
    srand(current_time);

    index = rand() % 3;                         // generate a random number between 0 to 2

    c_choice = choices[index];                  // get computer choice

    return c_choice;
}

string winner(){								// function that checks who won
	string player_played, computer_played;

    // get choices
    player_played = player_choice();
    computer_played = computer_choice();


    // check who won
    if (player_played == computer_played){
        cout << "You and the computer chose " << player_played << '.' << " It's a tie!\n";
		cout << " \n";
		return "none";
    }

    else if (player_played == "Rock"){
        if (computer_played == "Paper"){
            cout << "You picked Rock, but the computer picked Paper. You lost!\n";
			cout << " \n";
			return "computer";
        }
        else{
            cout << "You picked Rock and the computer picked Scissors. You won!\n";
			cout << " \n";
			return "player";
        }
    }
    
    else if (player_played == "Scissors"){
        if (computer_played == "Paper"){
            cout << "You picked Scissors and the computer picked Paper. You won!\n";
			cout << " \n";
			return "player";
        }
        else{
            cout << "You picked Scissors, but the computer picked Rock. You lost!\n";
			cout << " \n";
			return "computer";
        }
    }

    else if (player_played == "Paper"){
        if (computer_played == "Rock"){
            cout << "You picked Paper and the computer picked Rock. You won!\n";
			cout << " \n";
			return "player";
        }
        else{
            cout << "You picked Paper, but the computer picked Scissors. You lost!\n";
			cout << " \n";
			return "computer";
        }
    }
	return "none";
}

int main(){										// function to run the match and keep track of the score                           
    int computer_score = 0, player_score = 0;
	string game_winner;

	cout << "If you win the game, you get 1 point. If you win 5 games, you win the match!\n";
	cout << " \n";

	while (computer_score < 5 and player_score < 5){
		game_winner = winner();					// gets who won the last game
		if (game_winner == "computer"){
			computer_score = computer_score + 1;
		}
		else if (game_winner == "player"){
			player_score = player_score + 1;
		}
		
		if (player_score > computer_score){
			cout << "You are winning! The match is (PxC) " << player_score << " x " << computer_score << "\n";
		}
		else if (computer_score > player_score){
			cout << "You are losing! The match is (PxC) " << player_score << " x " << computer_score << "\n";
		}
		else if (player_score == computer_score){
			cout << "The match is tied. (PxC) " << player_score << " x " << computer_score << "\n";
		}
	}

	if (player_score == 5){
		cout << "You did win 5 games! Well done! You won the match!\n";
	}
	else if (computer_score == 5){
		cout << "The computer won 5 games! You lost the match!\n";
	}

    return 0;
}