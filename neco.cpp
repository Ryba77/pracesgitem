#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Structure for the character
struct Character {
    string name;
    int maxHealth;
    int health;
    int maxMana;
    int mana;
    int gold;
    int level;
    int experience;
    int attack;
    vector<string> abilities;

    // Function to display character stats
    void displayStats() {
        cout << "Class: " << name << endl;
        cout << "Stats:" << endl;
        cout << "    Health - " << health << "/" << maxHealth << endl;
        cout << "    Attack - " << attack << endl;
        cout << "    Mana - " << mana << "/" << maxMana << endl;
        cout << "Abilities:" << endl;
        for (const string& ability : abilities) {
            cout << "    " << ability << endl;
        }
    }
};

// Structure for monsters
struct Monster {
    string name;
    int health;
    int attack;
    int gold;
};

// Function for combat with a monster
bool fight(Character& player, Monster& monster) {
    while (player.health > 0 && monster.health > 0) {
        // Player attacks first
        cout << "Player attacks " << monster.name << " for " << player.attack << " damage!" << endl;
        monster.health -= player.attack;

        if (monster.health <= 0) {
            cout << "You killed " << monster.name << "!" << endl;
            int chance = rand() % 2;
            if (chance == 0) {
                int loot = rand() % 10 + 1;
                player.gold += loot;
                cout << "You gained " << loot << " gold!" << endl;
            }
            player.experience += 10;
            if (player.experience >= 100) {
                player.level++;
                player.maxHealth += 2;
                player.maxMana += 2;
                player.attack += 1;
                cout << "New level up! You gain:" << endl;
                cout << "    Max Health: " << player.maxHealth << endl;
                cout << "    Max Mana: " << player.maxMana << endl;
                cout << "    Attack: " << player.attack << endl;
            }
            return true;
        }

        // Monster attacks
        cout << monster.name << " attacks the player for " << monster.attack << " damage!" << endl;
        player.health -= monster.attack;

        if (player.health <= 0) {
            cout << "You were defeated by " << monster.name << "!" << endl;
            return false;
        }
    }
    return false;
}

// Function for village activities
void village(Character& player) {
    int choice;
    do {
        cout << "You are in the village! What would you like to do?" << endl;
        cout << "1. Heal (20 gold)" << endl;
        cout << "2. Improve max health (50 gold)" << endl;
        cout << "3. Improve max mana (50 gold)" << endl;
        cout << "4. Improve attack (30 gold)" << endl;
        cout << "5. Leave" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (player.gold >= 20) {
                player.gold -= 20;
                player.health = player.maxHealth;
                cout << "You healed your health!" << endl;
            } else {
                cout << "You don't have enough gold!" << endl;
            }
            break;
        case 2:
            if (player.gold >= 50) {
                player.gold -= 50;
                player.maxHealth += 2;
                cout << "You improved your max health!" << endl;
            } else {
                cout << "You don't have enough gold!" << endl;
            }
            break;
        case 3:
            if (player.gold >= 50) {
                player.gold -= 50;
                player.maxMana += 2;
                cout << "You improved your max mana!" << endl;
            } else {
                cout << "You don't have enough gold!" << endl;
            }
            break;
        case 4:
            if (player.gold >= 30) {
                player.gold -= 30;
                player.attack += 1;
                cout << "You improved your attack!" << endl;
            } else {
                cout << "You don't have enough gold!" << endl;
            }
            break;
        case 5:
            cout << "Leaving the village." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);
}

// Function to choose class
Character chooseClass() {
    Character player;
    int choice;
    do {
        cout << "Choose a class:" << endl;
        cout << "1. Paladin" << endl;
        cout << "2. Hunter" << endl;
        cout << "3. Mage" << endl;
        cout << "4. Warlock" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            player.name = "Paladin";
            player.maxHealth = 5;
            player.health = 5;
            player.maxMana = 5;
            player.mana = 5;
            player.attack = 3;
            player.gold = 0;
            player.level = 1;
            player.experience = 0;
            player.abilities = {"Attack - Strike for 3 damage", "Light Strike - 1 damage to all enemies (2 mana)", "Revive - Add 1 health (1 mana)"};
            break;
        case 2:
            player.name = "Hunter";
            player.maxHealth = 6;
            player.health = 6;
            player.maxMana = 4;
            player.mana = 4;
            player.attack = 4;
            player.gold = 0;
            player.level = 1;
            player.experience = 0;
            player.abilities = {"Attack - Arrow for 4 damage", "Trap - 2 damage (3 mana)"};
            break;
        case 3:
            player.name = "Mage";
            player.maxHealth = 4;
            player.health = 4;
            player.maxMana = 6;
            player.mana = 6;
            player.attack = 2;
            player.gold = 0;
            player.level = 1;
            player.experience = 0;
            player.abilities = {"Attack - Fire spell for 2 damage", "Frost blast - 3 damage (3 mana)"};
            break;
        case 4:
            player.name = "Warlock";
            player.maxHealth = 5;
            player.health = 5;
            player.maxMana = 5;
            player.mana = 5;
            player.attack = 3;
            player.gold = 0;
            player.level = 1;
            player.experience = 0;
            player.abilities = {"Attack - Dark blast for 3 damage", "Weaken - Reduce enemy's attack (2 mana)"};
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice < 1 || choice > 4);
    return player;
}

int main() {
    srand(time(0));

    // Player chooses a class
    Character player = chooseClass();

    // Display character stats
    player.displayStats();

    // Create a monster
    Monster monster = {"Goblin", 10, 2, 5};

    // Fight with the monster
    if (fight(player, monster)) {
        cout << "You won the battle!" << endl;
    } else {
        cout << "You lost the battle!" << endl;
        return 0;
    }

    // Enter the village
    village(player);

    return 0;
}
