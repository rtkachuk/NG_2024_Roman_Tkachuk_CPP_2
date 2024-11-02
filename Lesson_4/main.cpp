#include <iostream>
#include "magician.h"

using namespace std;

int main() {
  magician player;

  player.setMana(1700);
  
  player.addSpell("Healochka");
  player.addSpell("Fireball");

  player.showSpells();
  
  player.showStats();
  return 0;
}
