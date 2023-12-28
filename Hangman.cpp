// Include necessary header files
#include <iostream> // For input/output operations
#include <string>   // For working with strings
#include <windows.h> // For Windows-specific functions

using namespace std;

// Function to print a message with optional top and bottom borders
void PrintMessage(string message, bool printTop = true, bool printBottom = true)
{
    if (printTop) // For the top
    {
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }
    else
    {
        cout << "|";
    }
    
    bool front = true; //For the front
    // This loop is to center allign the text in the box
    for (int i = message.length(); i < 33; i++)
    {
        if (front)
        {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        front = !front;
    }
    cout << message;

    if (printBottom) // For the bottom
    {
        cout << "|" << endl;
        cout << "+---------------------------------+" << endl;
    }
    else
    {
        cout << "|" << endl;
    }
}

// Function to draw the hangman figure based on the number of incorrect guesses
void DrawHangman(int guessCount = 0)
{
	// Draw the corresponding parts of the hangman figure based on guessCount
	if (guessCount >= 1)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);
	
	if (guessCount >= 2)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);
    
	if (guessCount >= 3)
        PrintMessage("O", false, false);
    else
        PrintMessage("", false, false);
        
    if (guessCount == 4)
        PrintMessage("  |  ", false, false); 
        
    if (guessCount == 5)
        PrintMessage("/|  ", false, false); 
		
	if (guessCount >= 6)
        PrintMessage("/|\\", false, false);
    else
        PrintMessage("", false, false);   

    if (guessCount >= 7)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);

    if (guessCount == 8)
        PrintMessage("/  ", false, false);

    if (guessCount >= 9)
        PrintMessage("/ \\", false, false);
    else
        PrintMessage("", false, false);

    PrintMessage(" ", false, false);
    PrintMessage("+---------------+", false, false);
    PrintMessage("|               |", false, false);
}

// Function to print the available letters for guessing
void PrintLetters(string input, char from, char to)
{
    string s;
    for (char i = from; i <= to; i++)
    {
        if (input.find(i) == string::npos)
        // If the character 'i' is not found in the 'input' string,execute the following code block
        {
            s += i;
            s += " ";
        }
        else
            s += "  ";
    }
    PrintMessage(s, false, false);
}

// Function to print the available letters from A to M and N to Z
void PrintAvailableLetters(string taken)
{
    PrintLetters(taken, 'A', 'M');
    PrintLetters(taken, 'N', 'Z');
}

// Function to print the masked word and check if the player has won
bool PrintWordAndCheckWin(const string& word, const string& guessed)
// Returns true if all letters have been guessed correctly, false otherwise
{
    bool won = true;
    string s;
    for (int i = 0; i < word.length(); i++)
    {
        if (guessed.find(word[i]) == string::npos) 
    	// If the current letter from the word is not found in the guessed string,execute the following code block
        {
            won = false;
            s += "_ ";
        }
        else
        {
            s += word[i];
            s += " ";
        }
    }
    PrintMessage(s, false, true);
    return won;
}

// Function for player 2 to play the hangman game
void playHangman(const string& word, const string& hint)
{
    string maskedWord(word.length(), '-');
    int remainingAttempts = 10;
    string guessedLetters;
	
	while (remainingAttempts > 0 && maskedWord != word)
    {
    	PrintMessage("HANGMAN");
        DrawHangman(10 - remainingAttempts);
        PrintMessage("Hint: " + hint);
        PrintAvailableLetters(guessedLetters);
        PrintWordAndCheckWin(maskedWord, guessedLetters);
		
        char guess;
        cout << "Enter your guess: ";
        cin >> guess;
        guess = toupper(guess); // To convert the guess letters into upper case

		// Check if the guessed letter has already been guessed before
        if (guessedLetters.find(guess) != string::npos)
        // If the guessed letter is found in the string guessedLetters,execute the following code block
        {
        	system("cls");
            remainingAttempts--;
            cout << "You have already guessed that letter :D \nRemaining attempts: " << remainingAttempts << endl;
            continue;
		}
        
		guessedLetters += guess;

        bool letterFound = false;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == guess)
            {
                if (maskedWord[i] != '-')
                {
                    letterFound = true;
                    break;
                }
                maskedWord[i] = guess;
                letterFound = true;
            }
        }
		
        if (!letterFound)
        {
        	system("cls");
            remainingAttempts--;
            cout << "Incorrect guess :( \nRemaining attempts: " << remainingAttempts << endl;
        }
        else
        {
            system("cls");
			cout << "Correct guess! :) " << endl;
        }
    }    
    
    // Check if the player won or lost and print the corresponding message
    if (maskedWord == word)
    {
        cout << "CONGRATULATIONS! You guessed the word ^_^ : " << word << endl;
    }
    else
    {
        cout << "GAME OVER! x_x \nYou ran out of attempts.The word was: " << word << endl;
    }
    
}

int main()
{
    char ch=2;
    // Player 1 enters the word and hint
    cout << "PLEASE PLAY THE GAME IN CAPTIAL LETTERS "<< ch << endl;
    cout << "Player 1, Enter the word to guess: ";
	
	string word;
    getline(cin, word);
    
	// Player 1 provides a hint for the word
    cout << "Enter a hint for the word: ";
    string hint;
    getline(cin, hint);

	// Clear the console screen before starting the game
    system("cls"); // Change to "cls" if you're on Windows
    
    // Player 2 plays the game
    cout << "Player 2, It's your turn to guess!" << endl << endl;
 
	playHangman(word, hint);
    
    
	return 0;
	
}
