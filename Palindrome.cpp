/* ---- TASK 1: PALINDROME ---- */
// User: madmath #1528

// I think there are errors in this one

#include <stdio.h>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
void PromptPlayAgain(); // forward declaration

bool CheckPalindrome(string input) {
   int i = 0;
   int inputEnd = static_cast<int>(input.length()-1);

   while ( (i < input.size()) && (inputEnd > 0) ) {
      // check if left most char is not alphanumeric
      if ( (!isalpha(input.at(i))) || (!isdigit(input.at(i))) ) {
         i++;
      }

      // check if right most char is not alphanumeric
      if ( (!isalpha(input.at(inputEnd))) || (!isdigit(input.at(inputEnd))) ) {
         inputEnd--;
      }

      // accounting for single letters/digits or three-lettered phrases
      // i.e.: "oho", "lol", "owo"
      if (i == inputEnd) {
         return true;
      }

      if (input.at(i) != input.at(inputEnd)) {
         return false;
      }
      i++;
      inputEnd--;
   }

   return true;
}

string GetUserInput() {
   string userInput;

   cout << "Type a phrase: " << endl;
   getline(cin, userInput);

   return userInput;
}

void PrintPalindromeResult(bool result) {
   string strResult;

   if (!result) {
      strResult = "Not a palindrome.\n";
   }
   else {
      strResult = "Palindrome.\n";
   }

   cout << "Result: " << strResult << endl;
   PromptPlayAgain();

}

void PromptPlayAgain() {
   char c;

   cout << "Would you like to try another phrase?" << endl;
   cout << "Use y/n to answer:" << endl;
   cin >> c;

   switch (c) {
      case 'n': // Quit
         cout << "Thanks for trying my palindrome code out!" << endl;
         exit(0);
      case 'y':
         cout << endl;
         cin.clear();
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         PrintPalindromeResult(CheckPalindrome(GetUserInput()));
      default:
         cout << "Invalid input. Asking again:\n" << endl;
         PromptPlayAgain();
   }
}

int main() {
   PrintPalindromeResult(CheckPalindrome(GetUserInput()));
   return 0;
}


