#include <iostream>

using namespace std;

// int a[10];

// for (int counter = 0; counter < 10; counter++) {
//     cout << "Enter value " << counter << ": ";
//     cin >> a[counter];
// }


// Matrix

// int box[10][10];

// for (int height = 0; height < 10; height++) {
//     for (int width = 0; width < 10; width++)
//         box[height][width] = 0;
// }

// box[1][4] = 1;

// for (int height = 0; height < 10; height++) {
//     for (int width = 0; width < 10; width++)
//         cout << box[height][width];
//     cout << endl;
// }

// ASCII

// for (char element = 'a'; element < 'z' + 1; element++)
// {
//     cout << element << " - " << (int)element << endl;
// }

int main()
{
    char str[256];
    cout << "Enter string: ";
    cin.getline(str, 256);
    cout << "You entered: " << str << endl;
    int element = 0;
    while (str[element] != 0) {
        cout << str[element];
        element++;
    }
    cout << endl;
    return 0;
}

// 0000000000000000000#######
// Hello my f
