#include <iostream>
#include <vector>

#include "stats.h"

using namespace std;

class magician : public stats {
 public:
  magician() {
    setHP(50);
    setAttack(2);
    setDefence(2);
    mana = 1500;
  }

  void addSpell(string spellName) { m_spellbook.push_back(spellName); }

  void showSpells() {
    cout << "Spells:";
    for (string spell : m_spellbook)
      cout << "\t" << spell << endl;
  }
  virtual void setMana(int value) {
    if (value >= 0 && value <= 3000)
      mana = value;
  }
 private:
  vector<string> m_spellbook; 
};
