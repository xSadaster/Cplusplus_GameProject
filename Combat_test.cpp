#include "Combat.h"
#include "Entities/Classes.h"
#include "Entities/Inventory.h"
#include <vector>
#include <ctime>
#include <cstdlib>1
using namespace std;

// Combat system function: returns true if player survived, false if defeated
bool Combat(Player& playerChar, Inventory& inv, const string& enemyName, int enemyHP, int enemyATK, const string& enemyType) {
    Entity playerEntity;
    playerEntity.name = playerChar.getName();
    playerEntity.hp = playerChar.getHP();
    playerEntity.attack = playerChar.getATK();
    playerEntity.attacks = { {"Attack", playerChar.getATK(), playerChar.getATK()} };

    // Create Enemy object locally for this fight
    Enemy enemyObj(enemyName, enemyHP, enemyATK, enemyType);
    Entity enemyEntity;
    enemyEntity.name = enemyObj.getName();
    enemyEntity.hp = enemyObj.getHP();
    enemyEntity.attack = enemyObj.getATK();
    enemyEntity.attacks = { {"Attack", enemyObj.getATK(), enemyObj.getATK()} };

    cout << "\n===== FIGHT: " << enemyEntity.name << " =====\n";
    while (playerEntity.hp > 0 && enemyEntity.hp > 0) {
        cout << "\nYour HP: " << playerEntity.hp << " | Enemy HP: " << enemyEntity.hp << "\n";
        inv.showInventory();
        cout << "Choose action: 1. Attack  2. Use Potion\n> ";
        int action;
        cin >> action;
        if (action == 2 && inv.getCount() > 0) {
            inv.useItem(0);
            playerEntity.hp += 20;
            if (playerEntity.hp > playerChar.getHP()) playerEntity.hp = playerChar.getHP();
            cout << "Healed! Current HP: " << playerEntity.hp << "\n";
            continue;
        }
        // Attack
        int dmg = playerEntity.attack;
        cout << "You attack the " << enemyEntity.name << " for " << dmg << " damage!\n";
        enemyEntity.hp -= dmg;
        if (enemyEntity.hp <= 0) {
            cout << "✅ You defeated the " << enemyEntity.name << "!\n";
            break;
        }
        // Enemy turn
        if (!enemyEntity.attacks.empty()) {
            const EnemyAttack& atk = enemyEntity.attacks[rand() % enemyEntity.attacks.size()];
            int edmg = atk.minDamage + (rand() % (atk.maxDamage - atk.minDamage + 1));
            cout << "The " << enemyEntity.name << " uses " << atk.name << " and hits you for " << edmg << " damage!\n";
            playerEntity.hp -= edmg;
        } else {
            cout << "The " << enemyEntity.name << " hits you for " << enemyEntity.attack << " damage!\n";
            playerEntity.hp -= enemyEntity.attack;
        }
        if (playerEntity.hp <= 0) {
            cout << "❌ You have been defeated!\n";
            break;
        }
    }
    if (playerEntity.hp > 0) {
        if (inv.addItem("Potion")) {
            cout << "You found a Potion!\n";
        }
        // Update player HP after combat
        playerChar.setHP(playerEntity.hp);
        return true;
    } else {
        playerChar.setHP(0);
        return false;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    // Ask for player class
    cout << "Choose your class:\n1. Warrior\n2. Tank\n3. Berserker\n> ";
    int classChoice;
    cin >> classChoice;
    cin.ignore();
    string pname;
    cout << "Enter your player name: ";
    getline(cin, pname);

    Player* playerChar = nullptr;
    if (classChoice == 2) playerChar = new Tank(pname);
    else if (classChoice == 3) playerChar = new Berserker(pname);
    else playerChar = new Warrior(pname);

    Inventory inv;
    // Give 1 potion to start
    inv.addItem("Potion");

    // Set up player entity for Combat.h
    Entity playerEntity;
    playerEntity.name = playerChar->getName();
    playerEntity.hp = playerChar->getHP();
    playerEntity.attack = playerChar->getATK();
    playerEntity.attacks = { {"Attack", playerChar->getATK(), playerChar->getATK()} };

    cout << "\nWelcome, " << playerEntity.name << "! Prepare for battle!\n";
    
    // Enemy data for each fight
    struct EnemyData { string name; int hp; int atk; string type; };
    vector<EnemyData> enemyList = {
        {"Goblin", 30, 6, "Goblin"},
        {"Skeleton", 40, 8, "Skeleton"},
        {"Orc", 55, 12, "Orc"},
        {"Dark Mage", 45, 10, "Mage"},
        {"Dragon Whelp", 70, 15, "Dragon"}
    };

    // Example: trigger a single fight (remove the for loop)
    // You can call this anywhere, e.g. after a map event or tile check
    
    
    int enemyIndex = 0; // Change this to select which enemy to fight
    if (!Combat(*playerChar, inv, enemyList[enemyIndex].name, enemyList[enemyIndex].hp, enemyList[enemyIndex].atk, enemyList[enemyIndex].type)) {
        cout << "Game Over!\n";
    } else {
        cout << "\nYou survived the fight!\n";
    }
    delete playerChar;
    return 0;
}
