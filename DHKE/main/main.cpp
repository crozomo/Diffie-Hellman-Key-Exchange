#include <iostream>
#include <cmath>
#include <thread>
#include <numeric>
#include <string>
#include <sstream>
#include <algorithm>
#include <signal.h>

using namespace std;

// Diffie Hellman Key Exchange

// mod should be a large prime number
// base should be a prime number (primitive root modulo n)

bool keepGoing {true};
int menuSelect {};

// signal handler for signal interactions
void sigintHandler (int sig_num) {
    signal(SIGINT, sigintHandler);
    fflush(stdout);
}


unsigned long long power(unsigned long long base, 
    unsigned long long exp, unsigned long long mod) {

    unsigned long long start = 1;
    base %= mod;
    while (exp > 0) {

        if (exp % 2 == 1) start = (__int128(start) * base) % mod;
            base = (__int128(base) * base) % mod;
            exp /= 2;
    }
    return start;
}


int main () {

    signal (SIGINT, sigintHandler);
    
    // generate shared key 1
    unsigned long long base {};
    unsigned long long mod {};
    unsigned long long exp {};
    unsigned long long shared_key {};

    // generate shared password
    unsigned long long user_2_key {};
    unsigned long long password {};

    while (keepGoing) {
        cout << "\033[2J\033[1;1H"; // clear screen
        cout << "1. Generate New Key" << "\n\n";
        cout << "2. Exit" << "\n\n";
        cout << "Select: ";
        cin >> menuSelect;

        if (cin.fail()) { 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error: Invalid Input, Please Enter a Number\n";
            cout << "Press 'Enter' to Try Again\n";
            cin.get();
            continue;
        }

        if (menuSelect == 1) {
            cout << "\033[2J\033[1;1H"; // clear screen

            cout << "Enter Public Key #1 (Only Numbers Are Valid):" << "\n";
            cin >> base;
            cout << "\n";
            
            if (cin.fail()) { 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error: Invalid Input, Please Enter a Number\n";
                cout << "Press 'Enter' to Try Again\n";
                cin.get();
                continue;
            }

            cout << "Enter Public Key #2 (Only Numbers Are Valid):" << "\n";
            cin >> mod;
            cout << "\n";

            if (cin.fail()) { 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error: Invalid Input, Please Enter a Number\n";
                cout << "Press 'Enter' to Try Again\n";
                cin.get();
                continue;
            }

            cout << "Enter Your Private Key (Only Numbers Are Valid):" << "\n";
            cin >> exp;
            cout << "\n\n";

            if (cin.fail()) { 
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error: Invalid Input, Please Enter a Number\n";
                cout << "Press 'Enter' to Try Again\n";
                cin.get();
                continue;
            }
            
            // User 1 Shared Key
            shared_key = power(base, exp, mod);
            cout << "Your Shared Key: " << shared_key << "\n\n";
            cout << "Please Send This Key To User 2" << "\n\n";

            // Enter User 2's Generated Key
            cout << "Please Enter User 2's Shared Key:" << "\n";
            cin >> user_2_key;
            cout << "\n";

            // Shared Password
            password = power(user_2_key, exp, mod);
            cout << "Your Shared Password: " << hex << password << "\n\n";
            cout << dec; // reset back to numbers


            cout << "Enter 1 to exit" << "\n";
            cin >> menuSelect;
            cout << endl;

        }

        if (menuSelect == 2) {
            keepGoing = false;
            break;
        }


    }

}