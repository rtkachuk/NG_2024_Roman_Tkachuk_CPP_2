#include <iostream>

using namespace std;

struct player {
  int x;
  int y;
  int health;
  
  player operator+(int changes) {
    return {x, y, health + changes};
  }
  player operator-(int changes) {
    return {x, y, health - changes};
  }
};

player damage(player pl, int damage){
  return pl - damage;
}

int main() {
  player newbie;
  newbie.x = 5;
  newbie.y = 10;
  newbie.health = 100;
  newbie = damage(newbie, 45);
  cout << "Health: " << newbie.health;
}
