#include <iostream>

using namespace std;

void showMessage(char msg[]) {
  cout << msg << endl;
}

void showMessage(char msg[], int result) {
  cout << msg << result << endl;
}

int askValue(char position[]) {
  int value;
  cout << "Enter " << position << " number: ";
  cin >> value;
  return value;
}

void miniCalculator() {
  showMessage("Hello! Please write two values to get sum!");
  showMessage("Your summ: ", askValue("first") + askValue("second"));
}

int main() {
  miniCalculator();
}
