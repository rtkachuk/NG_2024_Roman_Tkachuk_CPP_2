#include <iostream>

using namespace std;    

void drawRow(int size) {
  if (size > 0) {
    drawRow(size - 1);
    cout << "*";
  }
}

void drawSquare(int rows, int columns) {
  if (rows > 0) {
    drawSquare(rows - 1, columns);
    drawRow(columns); // for (int column = 0; column < columns; column++) { cout << "*"; }
  }
  cout << endl;
}

int main() {
  drawSquare(5, 5);
}
