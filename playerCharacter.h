#pragma once
#include <cstdint>
#include "statblock.h"
#include "pointWell.h"
#include <memory>
#include <string>

typedef std::uint64_t expType;
typedef std::uint16_t levelType;

class playerCharacterDelegate : public statBlock{

    public:

        void distFromGod(levelType c){
            distanceFromGod = c;
        }

        void startingLevel(expType l){
            levelStart = l;
        }

        playerCharacterDelegate() : statBlock((statType)0u,(statType)0u){
            currentLevel = 1u;
            currentExp = 0u;
            distanceFromGod = 3u;
            expToLevel = distanceFromGod+currentLevel; // clean this up later, this is an artifact of a late change
            HP = std::make_unique<pointWell>();
        }


        void gainExp(expType gainedExp){
            currentExp += gainedExp;
            while(check_if_level()){};
        }


levelType getCurrentLevel(){
    return currentLevel;
}

expType getCurrentExp(){
    return currentExp;
}

expType getExpToLevel(){
    return expToLevel;
}

virtual void levelUP()=0;
virtual std::string getClassName() = 0;

std::unique_ptr<pointWell>HP;

    protected: 
    
        levelType currentLevel;
        expType currentExp;
        expType levelStart;
        levelType distanceFromGod;
        expType expToLevel;

        bool check_if_level(){
            if(currentExp >= expToLevel){
                currentExp = 0;
                expToLevel = distanceFromGod+currentLevel;
                currentLevel++;
                levelUP();
                return true;
            }
            return false;
        }

};



class playerCharacter {
    public:
        playerCharacter() = delete;
        playerCharacter(playerCharacterDelegate* pc) : pcClass(pc){   }
        ~playerCharacter() { delete pcClass; pcClass = nullptr; }

        std::string getClassName() { return pcClass->getClassName(); }
        levelType getCurrentLevel() { return pcClass->getCurrentLevel(); }
        expType getCurrentExp() { return pcClass->getCurrentExp(); }
        expType getExpToLevel() { return pcClass->getExpToLevel(); }
        wellType getCurrentHP() { return pcClass->HP->getCurrent(); }
        wellType getMaxHP() { return pcClass->HP->getMax(); }
        statType getStrength() { return pcClass->getStrength(); }
        statType getIntellect() { return pcClass->getIntellect(); }

        void gainExp(expType amt) { pcClass->gainExp(amt); }
        void takeDamage(wellType amt) { pcClass->HP->reduce(amt); }
        void heal(wellType amt) { pcClass->HP->increase(amt); }

    private:
        playerCharacterDelegate* pcClass;

};

// -----------------CLASSES------------------------ //


// JACKAL
class jackal : public playerCharacterDelegate{
  
public:
    static const wellType baseHP = (wellType)5u;
    static const statType baseStrength = (statType)3u;
    static const statType baseIntellect = (statType)3u;

    static const wellType growthHP = (wellType)5u;
    static const statType growthStrength = (statType)3u;
    static const statType growthIntellect = (statType)3u;

    
    jackal() : playerCharacterDelegate() {
        HP->setMax(baseHP);
        HP->increase(baseHP);

        increaseStats(baseStrength, baseIntellect);

    }

std::string getClassName() override {return std::string("Jackal");}
private:
    void levelUP() override{
        HP->setMax((wellType)growthHP + HP->getMax());
        increaseStats(growthStrength, growthIntellect);
    }
};


// ZEALOT
class zealot : public playerCharacterDelegate {
   
public:
    static const wellType baseHP = (wellType)7u;
    static const statType baseStrength = (statType)5u;
    static const statType baseIntellect = (statType)1u;

    static const wellType growthHP = (wellType)3u;
    static const statType growthStrength = (statType)2u;
    static const statType growthIntellect = (statType)1u;

    
    zealot(): playerCharacterDelegate() {
        HP->setMax(baseHP);
        HP->increase(baseHP);
        increaseStats(baseStrength, baseIntellect);

    }

private:
    void levelUP() override {
        HP->setMax((wellType)growthHP + HP->getMax());
        increaseStats(growthStrength, growthIntellect);
    }
};