/* ---- TASK 1: PALINDROME (NO STRING LIBRARY) ---- */
// User: madmath #1528

#include <stdio.h>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

// Forward declarations
int GetStringSize(string input);
int GetArraySize(char* inputArray);
void ParseUserInput(char* inputArray, string input);


bool CheckPalindrome(string input) {
   char inputArray[GetStringSize(input)];
   ParseUserInput(inputArray, input);

   int arraySize = GetArraySize(inputArray);
   int inputEnd = arraySize - 1;
   int i = 0;

   while ( (i < arraySize) && (inputEnd > 0) ) {
      if (inputArray[i] != inputArray[inputEnd]) {
         return false;
      }
   }

   return true;
}

void ParseUserInput(char* inputArray, string input) {
   int stringSize = GetStringSize(input);
   char parsedInput[stringSize];

   for (int i = 0; i < stringSize; i++) {
      if (isalpha(input[i])) {
         cout << "Added i = " << i << endl; // FIXME
         cout << "parsedInput[i] = " << parsedInput[i] << endl; // FIXME
         parsedInput[i] = input[i];
      }
   }
}

int GetStringSize(string input) {
   int count = 0;

   while (input[count]) {
      count++;
   }
   return count;
}

int GetArraySize(char* inputArray) {
   int count = 0;

   while (inputArray[count]) {
      count++;
   }

   return count;
}


int main() {
   string userInput;
   string result;

   cout << "Please type in a phrase: " << endl;
   getline(cin, userInput);

   if (CheckPalindrome(userInput)) {
      result = "Palindrome";
   }
   else {
      result = "Not palindrome";
   }

   cout << "Result: " << result << endl;

   return 0;
}
