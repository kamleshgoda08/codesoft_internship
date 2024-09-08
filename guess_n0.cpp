#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); 
    int number = rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    cout << "Guess the number (between 1 and 100): ";

    while (guess != number) {
        cin >> guess;
        attempts++;

        if (guess > number) {
            cout << "Too high! Try again: ";
        } else if (guess < number) {
            cout << "Too low! Try again: ";
        } else {
            cout << "Correct! You guessed the number in " << attempts << " attempts.\n";
        }
    }

    return 0;
}
