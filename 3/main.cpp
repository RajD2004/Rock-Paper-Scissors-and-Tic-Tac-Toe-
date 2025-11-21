//Tic-tax-toe validator 
#include <iostream>
#include <string>
using std::cout, std::cin, std::endl, std::string;

string ValidateConfig(int config){
    string config_str = std::to_string(config);
    string winner_str; 

    int x_count = 0;
    int o_count = 0;

    bool valid_config = true;
    int num_zeros = 0;

    if (config_str.length() < 9){
        num_zeros = 9 - config_str.length();
    }
    
    string leading_zeros (num_zeros, '0');
    config_str = leading_zeros + config_str;

    //check for invalid config
    for(auto ch: config_str){
        if (ch == '1'){
            x_count += 1; //counts all occurances of X
        }
        else if (ch == '0'){
            o_count += 1; //counts all occurances of O
        }
        else{
            continue; //when there might be a 2 (empty space)
        }
    }

    if (x_count > 5 || o_count > 5){ //invalid configuration of X or O occur more than 5 times
        valid_config = false;
    }

    //Ensures one player does not have an unfair number of turns
    if (x_count > (o_count + 1) || o_count > (x_count + 1)){
        valid_config = false;
    }

    if (valid_config == false || config_str.length() > 9){ //invalid configuration if lenght > 9
        winner_str += "Invalid configuration!";
    }

    else if (valid_config = true){ //if valid configuration, checks who won (X or O) or if it's a draw
        if (config_str[0] == config_str[1] && config_str[1] == config_str[2]){//there is a winner if a player occupies all spots in 1st row
            if(config_str[0] == '1'){ //checks who fills the row (X:1 or O:0) and assigns them as winner 
                winner_str += "X wins!"; 
            }
            else if(config_str[0] == '0'){
                winner_str += "O wins!";
            }
        }
        
        else if (config_str[3] == config_str[4] && config_str[4] == config_str[5]){ //if a player occupies all spots in second row
            if(config_str[3] == '1'){
                winner_str += "X wins!";
            }
            else if(config_str[3] == '0'){
                winner_str += "O wins!";
            }
        }

        else if (config_str[6] == config_str[7] && config_str[7] == config_str[8]){ //if a player occupies all spots in 3rd row
            if(config_str[3] == '1'){
                winner_str += "X wins!";
            }
            else if(config_str[3] == '0'){
                winner_str += "O wins!";
            }
        }

        else if (config_str[0] == config_str[3] && config_str[3] == config_str[6]){ //if a player occupies all spots in 1st column
            if(config_str[0] == '1'){
                winner_str += "X wins!";
            }
            else if(config_str[0] == '0'){
                winner_str += "O wins!";
            }
        }    

        else if (config_str[1] == config_str[4] && config_str[4] == config_str[7]){ //if a player occupies all spots in second column
            if(config_str[1] == '1'){
                winner_str += "X wins!";
            }
            else if(config_str[1] == '0'){
                winner_str += "O wins!";
            }
        }

        else if (config_str[2] == config_str[5] && config_str[5] == config_str[8]){ //if a player occupies all spots in 3rd column
            if(config_str[2] == '1'){
                winner_str += "X wins!";
            }
            else if(config_str[2] == '0'){
                winner_str += "O wins!";
            }
        }

        else if (config_str[0] == config_str[4] && config_str[4] == config_str[8]){ //if a player occupies all spots in the positions (0,4,8) diagonal
            if(config_str[0] == '1'){
                winner_str += "X wins!";
            }
            else if(config_str[0] == '0'){
                winner_str += "O wins!";
            }
        }

        else if (config_str[2] == config_str[4] && config_str[4] == config_str[6]){ //if a player occupies all spots in position (2,4,6) diagonal
            if(config_str[2] == '1'){
                winner_str += "X wins!";
            }
            else if(config_str[2] == '0'){
                winner_str += "O wins!";
            }
        }

        else{ //if no player fills any row, column or diagonal 
            winner_str += "It's a draw!";
        }
    }

    return winner_str;
}

int main(){
    int config{0};
    cout << "Enter configuration: ";
    cin >> config;
    cout << "Result: " << ValidateConfig(config) << endl;
    return 0;
}