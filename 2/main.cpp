//No Strings Attached
#include <iostream>
#include <random>
using std::cout, std::cin, std::endl;

std::random_device rd;
std::mt19937 gen(rd());

int RandNumGen(){
    std::uniform_int_distribution<> rng(1,3);
    return rng(gen);
}

int main(){
    int user_input; 
    cout << "Enter 1 (Rock), 2 (Paper), or 3 (Scissors): ";
    cin >> user_input; 
    
    //Message to display user input
    if (user_input == 1){
        cout << "You picked: Rock" << endl;
    }

    else if(user_input == 2){
        cout << "You picked: Paper" << endl;
    }

    else if(user_input == 3){
        cout << "You picked: Scissors" << endl;
    }
    
    int computer_input = RandNumGen();

    //Message to display computer input
    if (computer_input == 1){
        cout << "The computer picked: Rock" << endl;
    }

    else if (computer_input == 2){
        cout << "The computer picked: Paper" << endl;
    }

    else if (computer_input == 3){
        cout << "The computer picked: Scissors" << endl;
    }

    //Rules of game
    if (user_input == computer_input) // same value for user and computer results in a draw
    {
        cout << "It is a draw!" << endl;
    }

    //possibilities when user wins
    else if (user_input == 2 && computer_input == 1) // user = paper, computer = rock
    {
        cout << "You Win!" << endl;
    }

    else if (user_input == 3 && computer_input == 2) // user = scissors, computer = paper
    {
        cout << "You Win!" << endl;
    } 

    else if (user_input == 1 && computer_input == 3) // user = Rock, computer = scissors
    {
        cout << "You Win!" << endl;
    }
    
    //Possibilites when user loses
    else{
        cout << "You lose!" << endl;
    }
    return 0;
}