# Hangman Game

## Description

This is a simple command-line Hangman game implemented in C++. The game selects a random word from a file (`words.txt`) and gives the player a hint by revealing one letter. The player must guess the word one letter at a time before the hangman is fully drawn. This project includes input validation and allows the player to continue playing or exit after each game.

## Features

- **Random Word Selection**: Words are picked from an external file (`words.txt`).
- **Graphical Hangman**: ASCII art is used to display the hangman at various stages of the game.
- **Hint Feature**: One letter from the word is revealed at the start of the game.
- **Input Validation**: Ensures the player inputs valid and new letters.
- **Replay Option**: The player can choose to play multiple rounds without restarting the program.

## Requirements

- C++ Compiler (e.g., g++)

## Setup and Installation

1. **Clone the repository**:
    ```sh
    git clone https://github.com/your-username/hangman-game.git
    cd hangman-game
    ```

2. **Prepare the words file**:
    Ensure you have a `words.txt` file in the same directory as the program. This file should contain one word per line. For example:
    ```plaintext
    hangman
    programming
    challenge
    example
    ```

## Compilation and Execution

1. **Compile the program**:
    ```sh
    g++ hangman.cpp -o hangman
    ```

2. **Run the program**:
    ```sh
    ./hangman
    ```

## How to Play

1. The game will display a hint by revealing one letter from the word.
2. You will guess one letter at a time.
3. If you guess a correct letter, it will be revealed in the word.
4. If you guess an incorrect letter, a part of the hangman will be drawn.
5. The game ends when you guess the word correctly or the hangman is fully drawn.
6. After each game, you can choose to play again or exit.

## Example

```plaintext
Welcome to Hangman!
Here is your hint, the word contains the letter 'a'.

  +---+
      |
      |
      |
      |
      |
========= 

Current state: _ a _ _ _ _ _ _ _ _ _ 
Guess a letter: p
Incorrect guess. You have 5 guesses left.

  +---+
  O   |
      |
      |
      |
      |
========= 

Current state: _ a _ _ _ _ _ _ _ _ _ 
Guess a letter: r
