#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include "Inventory.h"

int main() {
    // Test Product construction and fields
    Product p("Apple", "Fruit", 15, 2.5, "2026-12-31");
    assert(p.name == "Apple");
    assert(p.type == "Fruit");
    assert(p.Quantity == 15);
    assert(p.Prize == 2.5);
    assert(p.ExpDate == "2026-12-31");

    // Test Inventory addProduct and removeProduct behavior
    Inventory inv;

    // Ensure clean state
    std::remove("Inventory.txt");
    std::remove("temp.txt");

    std::fstream storage;
    inv.addProduct(p, storage);

    {
        std::ifstream in("Inventory.txt");
        assert(in.is_open());
        std::string line;
        bool found = false;
        while (std::getline(in, line)) {
            if (line.find("Apple") != std::string::npos) {
                found = true;
                break;
            }
        }
        assert(found && "Added product is not present in file");
    }

    inv.removeProduct("Apple");

    {
        std::ifstream in("Inventory.txt");
        if (in.is_open()) {
            std::string line;
            bool empty = true;
            while (std::getline(in, line)) {
                if (!line.empty()) {
                    empty = false;
                    break;
                }
            }
            assert(empty && "Product was not removed from inventory file");
        }
    }

    std::remove("Inventory.txt");
    std::remove("temp.txt");

    std::cout << "All unit tests passed.\n";
    return 0;
}
