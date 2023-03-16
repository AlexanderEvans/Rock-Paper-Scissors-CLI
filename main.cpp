#include <iostream>
#include <random>
#include <string>
#include <limits>

// Namespace to wrap the game outcomes enum
namespace GameOutcomes {
    enum type { 
      Tie = 0, 
      Win,
      Lose 
    };
}

GameOutcomes::type getGameOutcome[3][3] = {
    //              Rock                Paper               Scissors
    /*Rock*/    {   GameOutcomes::Tie,  GameOutcomes::Lose, GameOutcomes::Win   },
    /*Paper*/   {   GameOutcomes::Win,  GameOutcomes::Tie,  GameOutcomes::Lose  },
    /*Scissors*/{   GameOutcomes::Lose, GameOutcomes::Win,  GameOutcomes::Tie   }
};

template<typename T>
bool readAndCheck(T& value, std::istream& input = std::cin) {
    input >> value;

    if (input.fail()) {
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    return true;
}

bool promptAndRead(unsigned& playerChoice) {
    std::cout << "Enter 0 for rock, 1 for paper, 2 for scissors, or 3 to quit: ";

    return readAndCheck(playerChoice) && playerChoice <= 3;
}

int main() {
    const char* choiceStrings[] = {"Rock", "Paper", "Scissors"};
    const char* gameOutcomeStrings[] = {"Tie", "Win", "Lose"};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);

    unsigned playerChoice;
    while (!promptAndRead(playerChoice)) {
        std::cout << "\nInvalid input. Please try again.\n" << std::endl;
    }

    while (playerChoice != 3) {
        unsigned computerChoice = dis(gen);

        std::cout << "You chose " << choiceStrings[playerChoice] << " and the computer chose "
                  << choiceStrings[computerChoice] << "." << std::endl;

        std::cout << "You " << gameOutcomeStrings[getGameOutcome[playerChoice][computerChoice]] << std::endl;

        while (!promptAndRead(playerChoice)) {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }

    return 0;
}
