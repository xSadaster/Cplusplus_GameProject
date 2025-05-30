#ifndef COMBAT_H_INCLUDED
#define COMBAT_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <conio.h>
using namespace std;

struct EnemyAttack {
    string name;
    int minDamage, maxDamage;
};
struct Entity {
    string name;
    int hp, attack;
    vector<EnemyAttack> attacks;
};

void combat(Entity& player, Entity enemy) {
    cout << "\n💥 Enemy encountered: " << enemy.name << " (HP: " << enemy.hp << ")\n";
    while (player.hp > 0 && enemy.hp > 0) {
        cout << "\n--- Player Turn ---\n";
        cout << "Choose an attack:\n";
        for (size_t i = 0; i < player.attacks.size(); ++i)
            cout << i + 1 << ". " << player.attacks[i].name << "\n";
        int choice;
        cin >> choice;
        if (choice < 1 || choice > static_cast<int>(player.attacks.size())) {
            cout << "Invalid choice. Using default attack.\n";
            int dmg = player.attack;
            cout << "You attack the " << enemy.name << " for " << dmg << " damage!\n";
            enemy.hp -= dmg;
        } else {
            EnemyAttack selectedAttack = player.attacks[choice - 1];
            int dmg = selectedAttack.minDamage + (rand() % (selectedAttack.maxDamage - selectedAttack.minDamage + 1));
            cout << "You use " << selectedAttack.name << " and deal " << dmg << " damage!\n";
            enemy.hp -= dmg;
        }
        if (enemy.hp <= 0) {
            cout << "✅ You defeated the " << enemy.name << "!\n";
            break;
        }
        cout << "--- Enemy Turn ---\n";
        if (!enemy.attacks.empty()) {
            const EnemyAttack& atk = enemy.attacks[rand() % enemy.attacks.size()];
            int dmg = atk.minDamage + (rand() % (atk.maxDamage - atk.minDamage + 1));
            cout << "The " << enemy.name << " uses " << atk.name << " and hits you for " << dmg << " damage!\n";
            player.hp -= dmg;
        } else {
            cout << "The " << enemy.name << " hits you for " << enemy.attack << " damage!\n";
            player.hp -= enemy.attack;
        }
        if (player.hp <= 0) {
            cout << "❌ You have been defeated!\n";
            break;
        }
        cout << "Your HP: " << player.hp << " | Enemy HP: " << enemy.hp << "\n";
        cout << "Press any key for next turn...\n";
        _getch();
    }
    cout << "\nPress any key to continue...\n";
    _getch();
}
#endif // COMBAT_H_INCLUDED
