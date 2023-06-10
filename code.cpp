#include <iostream>
#include <ctime>
void drawboard(char *spaces);
void playermove(char *spaces, char player);
void computermove(char *spaces, char computer);
bool checkwiner(char *spaces, char player, char computer);
bool checkdraw(char *spaces );

int main(){
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}; 
    char player = 'x';
    char computer = 'o';
    bool running = true;
    drawboard(spaces);
    while(running){
        playermove(spaces,player);
        drawboard(spaces);
        if(checkwiner(spaces,player,computer)){
            running = false;
            break;
        }
        else if(checkdraw(spaces)){
            running = false;
            break;
        }
        
        computermove(spaces,computer);
        drawboard(spaces);
        if(checkwiner(spaces,player,computer)){
            running = false;
            break;
        }
        else if(checkdraw(spaces)){
            running = false;
            break;
        }
  
    }
}
void drawboard(char *spaces){
    std:: cout << "     |     |     " << '\n';
    std:: cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |   " << spaces[2] << "  " << '\n';
    std:: cout << "_____|_____|_____" << '\n';
    std:: cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |   " << spaces[5] << "  " << '\n';
    std:: cout << "_____|_____|_____" << '\n';
    std:: cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |   " << spaces[8] << "  " << '\n';
    std:: cout << "     |     |     " << '\n';


}
void playermove(char *spaces, char player){
    int number;
    do{
        std::cout << "Enter a number between 1-9: ";
        std::cin >> number;
        number--;
        if(spaces[number] == ' '){
            spaces[number] = player;
            break;
        }
    }while(!number > 0 || !number < 8);
}
void computermove(char *spaces, char computer){
    int numcs;
    srand(time(0));
    while(true){
        numcs = rand() % 9 ;
        if(spaces[numcs] == ' '){
            spaces[numcs] = computer;
            break;
        }
    }
  
}
bool checkwiner(char *spaces, char player, char computer){
    int checkDraw = 0;
    if((spaces[0] != ' ') && (spaces[0] == spaces[1] && spaces[1] == spaces[2])){
        spaces[0] == player ? std:: cout << "YOU WIN!\n" : std:: cout << "COMPUTER WINS!\n";
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4] && spaces[4] == spaces[5])){
        spaces[3] == player ? std:: cout << "YOU WIN!\n" : std:: cout << "COMPUTER WINS!\n";
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7] && spaces[7] == spaces[8])){
        spaces[6] == player ? std:: cout << "YOU WIN!\n" : std:: cout << "COMPUTER WINS!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4] && spaces[4] == spaces[8])){
        spaces[0] == player ? std:: cout << "YOU WIN!\n" : std:: cout << "COMPUTER WINS!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4] && spaces[4] == spaces[6])){
        spaces[2] == player ? std:: cout << "YOU WIN!\n" : std:: cout << "COMPUTER WINS!\n";
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3] && spaces[3] == spaces[6])){
        spaces[0] == player ? std:: cout << "YOU WIN!\n" : std:: cout << "COMPUTER WINS!\n";
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4] && spaces[4] == spaces[7])){
        spaces[1] == player ? std:: cout << "YOU WIN!\n" : std:: cout << "COMPUTER WINS!\n";
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5] && spaces[5] == spaces[8])){
        spaces[2] == player ? std:: cout << "YOU WIN!\n" : std:: cout << "COMPUTER WINS!\n";
    }
    else{
        return false;
    }
    return true;
}
bool checkdraw(char *spaces ){
    int ctr=0;
    for(int i = 0; i < 9; i++){
        if(spaces[i]!= ' '){
            return false;
        }
    }
    std:: cout << "The game is a draw!\n";
    return true;
}
