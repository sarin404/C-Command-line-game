#include <iostream>
#include <cstdlib>
#include <ctime>
#include<cstring>
class NumberGuess {
private:
    int guess, count, chances, number;

public:
    NumberGuess() {
        srand((time(0))); // Seed the random number generator 
        number = rand() % 100 + 1; // Generates a number between 1 and 100
    }

    void easyMode() {
        chances = 10;// initialize class member chances to 10 (for easy mode) to count the chances the user gets.
        std::cout << "You have chosen Easy difficulty!\n";
        playGame();
    }

    void mediumMode() {
        chances = 6;
        std::cout << "You have chosen Medium difficulty!\n";
        playGame();
    }

    void hardMode() {
        chances = 4;
        std::cout << "You have chosen Hard difficulty!\n";
        playGame();
    }

    void hellMode() {
        chances = 2;
        std::cout << "You have chosen Hell!!\n";
        playGame();
    }

    void playGame() {
        count = 0; // Reset count for each game
        while (count < chances) {
            std::cout << "Enter the number: ";
            std::cin >> guess;
            count++;
            if(guess==2222){ //Easter Egg
                std::cout<<"Easter Egg found!!!\t Number = "<<number<<std::endl;
            }
            else if (number == guess) {
                std::cout << "Congratulations! You have won the game in " << count << " tries!" << std::endl;
                return; // Exit the function if the user wins
            } else if (count == chances) {
                std::cout << "You lost! The number I chose was " << number << std::endl;
            }else if(guess>number){
                std::cout<<"The number is less than "<<guess<<std::endl;
                if((guess-number)<5)
                    std::cout<<"It is extremely close to the number I have chosen(within 5 integers)!!\n Keep trying!!"<<std::endl;
            }else if(guess<number){
                std::cout<<"The number is greater than "<<guess<<std::endl;
                if((number-guess)<5)
                    std::cout<<"It is extremely close to the number I have chosen(within 5 integers)!!\n Keep trying!!"<<std::endl;
            }
        }
    }

    ~NumberGuess() {}
};

int main() {
    NumberGuess obj;
    int difficulty;
    int resetGame; 
    retake: //Restart the game here
    std::cout << "\t\t Welcome to the Number Guessing game!" << std::endl;
    std::cout << "\t\t_______________________________________" << std::endl;
    std::cout << "I will be choosing a number between 1-100 and you will have to guess which number it is!"<< std::endl << std::endl;
    std::cout << "Select Difficulty:" << std::endl;
    std::cout << "1. Easy (10 chances)\n2. Medium (6 chances)\n3. Hard (4 chances)\n4. Hell (2 chances)" << std::endl;
    std::cin >> difficulty;

    switch (difficulty) {
        case 1:
            obj.easyMode();
            break;
        case 2:
            obj.mediumMode();
            break;
        case 3:
            obj.hardMode();
            break;
        case 4:
            obj.hellMode();
            break;
        default:
            std::cout << "Invalid input!!!"<< std::endl << std::endl;
            goto retake;
            break;
    }
    std::cout<<"Press 1 to play again: ";
    std::cin>>resetGame;
    if(resetGame==1)
        goto retake;
    else
        std::cout<<"Thank you for playing!";
    return 0;
}