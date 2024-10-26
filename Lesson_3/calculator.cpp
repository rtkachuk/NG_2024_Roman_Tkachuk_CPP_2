#include <iostream>

using namespace std;

char askUserAction() {
  char buffer;
  cout << "Please enter action (+,-): ";
  cin >> buffer;
  return buffer;
}
  
double askUserNumber(char ask[]) {
  double buffer;
  cout << "Enter " << ask << ": ";
  cin >> buffer;
  return buffer;
}

double calculate(double value1, double value2, char action) {
  switch(action) {
    case '+': return value1 + value2; break;
    case '-': return value1 - value2; break;
    default:  return 0;
  }
}

void calculator() {
  double value1 = askUserNumber("first value");
  double value2 = askUserNumber("second value");
  char action = askUserAction();
  
  double result = calculate(value1, value2, action);
  cout << "Result "
       << value1 << action << value2
       << "=" << result;
}

int main() {
  calculator();
}
