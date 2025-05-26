#pragma once
#include <iostream>
#include <string>
using namespace std;

class Inventory {
private:
    string items[3]; // Only 3 slots
    int count;
public:
    Inventory() : count(0) {
        for (int i = 0; i < 3; ++i) items[i] = "";
    }

    bool addItem(const string& item) {
        if (count < 3) {
            items[count++] = item;
            cout << "Picked up: " << item << endl;
            return true;
        } else {
            cout << "Inventory full! Cannot pick up " << item << endl;
            return false;
        }
    }

    void useItem(int idx) {
        if (idx >= 0 && idx < count && !items[idx].empty()) {
            cout << "Used: " << items[idx] << endl;
            // Shift items left
            for (int i = idx; i < count - 1; ++i)
                items[i] = items[i + 1];
            items[count - 1] = "";
            --count;
        } else {
            cout << "No item in that slot!" << endl;
        }
    }

    void showInventory() const {
        cout << "Inventory: ";
        for (int i = 0; i < 3; ++i) {
            if (!items[i].empty())
                cout << "[" << i + 1 << "] " << items[i] << "  ";
        }
        if (count == 0) cout << "Empty";
        cout << endl;
    }

    int getCount() const { return count; }
    string getItem(int idx) const { return (idx >= 0 && idx < count) ? items[idx] : ""; }
};