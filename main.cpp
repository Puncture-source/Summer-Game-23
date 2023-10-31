#include <iostream>
#include "allCharacters.h"


int main(){
    jackal jack1;
for (int i = 0; i < 10; i++) {
		std::cout 
			<< "Jackal Level " << jack1.getCurrentLevel() << '\n'
			<< "-EXP: " << jack1.getCurrentExp() << "/" << jack1.getExpToLevel() << '\n'
			<< "-MaxHP: " << jack1.getMaxHP() << '\n'
			<< "-Stength: " << jack1.getStrength() << '\n'
			<< "-Intellect: " << jack1.getIntellect() << '\n';
		//if (i < 1) 
			jack1.gainExp(1u);
            	std::cout << "------------\n\n\n";
	}

	std::cout << "------------\n";
    return 0;
}