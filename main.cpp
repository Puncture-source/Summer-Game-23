#include <iostream>
#include "playerCharacter.h"


int main(){
    playerCharacter p1(new jackal());


for (int i = 0; i < 10; i++) {
		std::cout 
			<< p1.getClassName()
			<< " Level " << p1.getCurrentLevel() << '\n'
			<< "-EXP: " << p1.getCurrentExp() << "/" << p1.getExpToLevel() << '\n'
			<< "-HP: " << p1.getCurrentHP() <<'/'<<p1.getMaxHP() <<'\n'
			<< "-Strength: " << p1.getStrength() << '\n'
			<< "-Intellect: " << p1.getIntellect() << '\n'
			<< "-Agility: " << p1.getAgility() << '\n'
			<< "-Resistance: " << p1.getResistance() << '\n'
			<< "-Armour: " << p1.getArmour() << '\n';
		//if (i < 1) 
			p1.gainExp(1u);
            	std::cout << "------------\n\n\n";
	}

	std::cout << "------------\n";
	system("pause");
    return 0;
}