#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <unordered_set>
#include <fstream>

// Function to read words from a file
std::vector<std::string> readWordsFromFile(const std::string &filename) {
    std::vector<std::string> words;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file " << filename << std::endl;
        return words;
    }

    std::string word;
    while (std::getline(file, word)) {
        if (!word.empty()) {
            words.push_back(word);
        }
    }

    file.close();
    return words;
}

void displayCurrentState(const std::string &word, const std::vector<bool> &guessed) {
    for (size_t i = 0; i < word.size(); ++i) {
        if (guessed[i]) {
            std::cout << word[i] << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

void displayHangman(int incorrectGuesses) {
    const std::vector<std::string> hangmanStates = {
        "  +---+\n      |\n      |\n      |\n      |\n      |\n========= \n",
        "  +---+\n  O   |\n      |\n      |\n      |\n      |\n========= \n",
        "  +---+\n  O   |\n  |   |\n      |\n      |\n      |\n========= \n",
        "  +---+\n  O   |\n /|   |\n      |\n      |\n      |\n========= \n",
        "  +---+\n  O   |\n /|\\  |\n      |\n      |\n      |\n========= \n",
        "  +---+\n  O   |\n /|\\  |\n /    |\n      |\n      |\n========= \n",
        "  +---+\n  O   |\n /|\\  |\n / \\  |\n      |\n      |\n========= \n"
    };

    std::cout << hangmanStates[incorrectGuesses] << std::endl;
}

bool isWordGuessed(const std::vector<bool> &guessed) {
    for (bool b : guessed) {
        if (!b) return false;
    }
    return true;
}

int main() {
    std::vector<std::string> words = readWordsFromFile("words.txt");
    if (words.empty()) {
        std::cerr << "No words to guess. Exiting." << std::endl;
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    bool continuePlaying = true;
    while (continuePlaying) {
        std::string word = words[std::rand() % words.size()];

        std::vector<bool> guessed(word.size(), false);
        int incorrectGuesses = 0;
        const int maxIncorrectGuesses = 6;
        std::unordered_set<char> guessedLetters;

        // Provide one hint by revealing a random letter
        int hintIndex = std::rand() % word.size();
        guessed[hintIndex] = true;

        std::cout << "Welcome to Hangman!" << std::endl;
        std::cout << "Here is your hint, the word contains the letter '" << word[hintIndex] << "'." << std::endl;

        while (incorrectGuesses < maxIncorrectGuesses && !isWordGuessed(guessed)) {
            displayHangman(incorrectGuesses);
            std::cout << "Current state: ";
            displayCurrentState(word, guessed);

            std::cout << "Guess a letter: ";
            char guess;
            std::cin >> guess;
            guess = std::tolower(guess);

            if (!std::isalpha(guess)) {
                std::cout << "Invalid input. Please enter a letter." << std::endl;
                continue;
            }

            if (guessedLetters.find(guess) != guessedLetters.end()) {
                std::cout << "You have already guessed that letter. Try again." << std::endl;
                continue;
            }

            guessedLetters.insert(guess);

            bool correctGuess = false;
            for (size_t i = 0; i < word.size(); ++i) {
                if (word[i] == guess) {
                    guessed[i] = true;
                    correctGuess = true;
                }
            }

            if (!correctGuess) {
                ++incorrectGuesses;
                std::cout << "Incorrect guess. You have " << (maxIncorrectGuesses - incorrectGuesses) << " guesses left." << std::endl;
            }
        }

        displayHangman(incorrectGuesses);

        if (isWordGuessed(guessed)) {
            std::cout << "Congratulations! You guessed the word: " << word << std::endl;
        } else {
            std::cout << "Game over! The word was: " << word << std::endl;
        }

        // Ask the user if they want to play again
        char playAgain;
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
        playAgain = std::tolower(playAgain);
        if (playAgain != 'y') {
            continuePlaying = false;
        }
    }

    std::cout << "Thank you for playing Hangman!" << std::endl;

    return 0;
}
