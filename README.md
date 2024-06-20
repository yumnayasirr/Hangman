**Hangman Game**
This repository contains a simple Hangman game implemented in C++. The game is designed for two players.
Player 1 enters the word and a hint, and Player 2 attempts to guess the word within a limited number of attempts.

**Features**
User-friendly console interface.
Allows Player 1 to input a word and a hint.
Provides feedback on correct and incorrect guesses.
Displays the hangman figure as the number of incorrect guesses increases.
Notifies the player when they win or lose.

**How to Play**

Player 1:
Enter the word to be guessed.
Provide a hint for the word.

Player 2:
Guess letters of the word.
You have 10 attempts to guess the word correctly.
The game provides feedback on the correctness of your guesses and displays the hangman figure accordingly.

**Requirements**
A C++ compiler (e.g., g++, clang).
A terminal or command prompt.

**Code Explanation**

This is the main file of the program. It contains the implementation of the Hangman game.

PrintMessage: Prints a message with optional top and bottom borders.

DrawHangman: Draws the hangman figure based on the number of incorrect guesses.

PrintLetters: Prints the available letters for guessing.

PrintAvailableLetters: Prints the available letters from A to M and N to Z.

PrintWordAndCheckWin: Prints the masked word and checks if the player has won.

playHangman: Main function for Player 2 to play the hangman game.

main: The entry point of the program where Player 1 inputs the word and hint, and Player 2 starts guessing.

**Example**
Here is a sample run of the game:

PLEASE PLAY THE GAME IN CAPITAL LETTERS 2
Player 1, Enter the word to guess: HANGMAN
Enter a hint for the word: A popular word guessing game

Player 2, It's your turn to guess!

+---------------------------------+
|            HANGMAN              |
+---------------------------------+
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
+---------------+
|               |
+---------------------------------+
|           Hint: A popular word guessing game|
|    A B C D E F G H I J K L M    |
|    N O P Q R S T U V W X Y Z    |
+---------------------------------+
_ _ _ _ _ _ _

Enter your guess: A
Correct guess! :)

+---------------------------------+
|            HANGMAN              |
+---------------------------------+
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
|                                 |
+---------------+
|               |
+---------------------------------+
|           Hint: A popular word guessing game|
|    B C D E F G H I J K L M      |
|    N O P Q R S T U V W X Y Z    |
+---------------------------------+
_ A _ _ _ A _

...
