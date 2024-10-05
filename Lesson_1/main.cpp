#include <iostream> // Header files

using namespace std;

// cout - output to terminal
// int a - Create variable a
// cin - ask for input from user

// int age;
// cout << "Skolko tebe let: ";
// cin >> age;
// if (age < 6) {
//     cout << "Rano v shkolu";
// } else {
//     cout << "Bistro v shkolu";
// }
// cout << ", no ti molodec!";
//
//
// int stars = 0;
// cout << "Enter amount of stars: ";
// cin >> stars;
// int count = 0;
// while ( count < stars ) {
//     cout << "*";
//     count++;
// }

int main()
{
    int stars = 0;
    cout << "Enter amount of stars: ";
    cin >> stars;
    for ( int height = 0; height < stars; height++ ) {
        for ( int width = 0; width < stars - (stars - height); width++ )
            cout << "* ";
        cout << endl;
    }
}
