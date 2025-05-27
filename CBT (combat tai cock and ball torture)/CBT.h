#ifndef COMBAT_H_INCLUDED
#define COMBAT_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <conio.h> // For _getch()

struct EnemyAttack {
    std::string name;
    int minDamage;
    int maxDamage;
};

struct Entity {
    std::string name;
    int hp;
    int attack;
    std::vector<EnemyAttack> attacks;
};

void combat(Entity& player, Entity enemy) {
    std::cout << "\n💥 Enemy encountered: " << enemy.name << " (HP: " << enemy.hp << ")\n";

    while (player.hp > 0 && enemy.hp > 0) {
        std::cout << "\n--- Player Turn ---\n";
        std::cout << "Choose an attack:\n";
        for (size_t i = 0; i < player.attacks.size(); ++i) {
            std::cout << i + 1 << ". " << player.attacks[i].name << "\n";
        }

        int choice;
        std::cin >> choice;
        if (choice < 1 || choice > static_cast<int>(player.attacks.size())) {
            std::cout << "Invalid choice. Using default attack.\n";
            int dmg = player.attack;
            std::cout << "You attack the " << enemy.name << " for " << dmg << " damage!\n";
            enemy.hp -= dmg;
        } else {
            EnemyAttack selectedAttack = player.attacks[choice - 1];
            int dmg = selectedAttack.minDamage + (std::rand() % (selectedAttack.maxDamage - selectedAttack.minDamage + 1));
            std::cout << "You use " << selectedAttack.name << " and deal " << dmg << " damage!\n";
            enemy.hp -= dmg;
        }

        if (enemy.hp <= 0) {
            std::cout << "✅ You defeated the " << enemy.name << "!\n";
            break;
        }

        std::cout << "--- Enemy Turn ---\n";
        if (!enemy.attacks.empty()) {
            const EnemyAttack& atk = enemy.attacks[std::rand() % enemy.attacks.size()];
            int dmg = atk.minDamage + (std::rand() % (atk.maxDamage - atk.minDamage + 1));
            std::cout << "The " << enemy.name << " uses " << atk.name << " and hits you for " << dmg << " damage!\n";
            player.hp -= dmg;
        } else {
            std::cout << "The " << enemy.name << " hits you for " << enemy.attack << " damage!\n";
            player.hp -= enemy.attack;
        }

        if (player.hp <= 0) {
            std::cout << "❌ You have been defeated!\n";
            break;
        }

        std::cout << "Your HP: " << player.hp << " | Enemy HP: " << enemy.hp << "\n";
        std::cout << "Press any key for next turn...\n";
        _getch();
    }

    std::cout << "\nPress any key to continue...\n";
    _getch();
}
#endif // COMBAT_H_INCLUDED
