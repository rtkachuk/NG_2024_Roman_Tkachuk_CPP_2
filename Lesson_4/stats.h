#include <iostream>

using namespace std;

class stats {
public:
  stats() {
    hp = 100;
    attack = 0;
    defence = 0;
    mana = 0;
  }
  
  void setHP(int value) {
    if (value >= 0 && value <= 100)
      hp = value;
  }
  void setAttack(int value) {
    if (value >= 0 && value <= 10)
      attack = value;
  }
  void setDefence(int value) {
    if (value >= 0 && value <= 10)
      defence = value;
  }
  virtual void setMana(int value) {
    if (value >= 0 && value <= 1000)
      mana = value;
  }
  
  int getHP() { return hp; }
  int getAttack() { return attack; }
  int getDefence() { return defence; }
  int getMana() { return mana; }

  void showStats() {
    cout << "HP: " << hp << endl
       << "Attack: " << attack << endl
       << "Defence: " << defence << endl
       << "Mana: " << mana;
  }
  
private:
  int hp;
  int attack;
  int defence;
protected:
  int mana;
};
