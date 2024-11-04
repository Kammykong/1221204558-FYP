#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struct to represent an item for sale
struct Item {
    int id;
    string title;
    string description;
    double price;
};

// Class to represent a buyer
class Buyer {
private:
    vector<Item> cart;
public:
    // Display available items (simulate fetching from a database)
    void viewItems(const vector<Item>& items) {
        cout << "Available items:\n";
        for (const auto& item : items) {
            cout << "ID: " << item.id << ", Title: " << item.title
                 << ", Description: " << item.description
                 << ", Price: $" << item.price << endl;
        }
    }

    // Add item to cart by ID
    void addToCart(int itemId, const vector<Item>& items) {
        for (const auto& item : items) {
            if (item.id == itemId) {
                cart.push_back(item);
                cout << "Added \"" << item.title << "\" to cart.\n";
                return;
            }
        }
        cout << "Item not found!\n";
    }

    // View items in cart
    void viewCart() {
        if (cart.empty()) {
            cout << "Your cart is empty.\n";
            return;
        }
        cout << "Items in your cart:\n";
        for (const auto& item : cart) {
            cout << "Title: " << item.title << ", Price: $" << item.price << endl;
        }
    }

    // Proceed to checkout (simple calculation of total)
    void checkout() {
        if (cart.empty()) {
            cout << "Cart is empty. Add items before checkout.\n";
            return;
        }
        double total = 0.0;
        for (const auto& item : cart) {
            total += item.price;
        }
        cout << "Total amount due: $" << total << "\nThank you for your purchase!\n";
        cart.clear(); // Clear the cart after purchase
    }
};

int main() {
    // Simulate a database of items
    vector<Item> items = {
        {1, "Textbook", "Calculus textbook, 2nd edition", 30.0},
        {2, "Laptop", "Lightweight laptop for students", 500.0},
        {3, "Headphones", "Noise-canceling headphones", 100.0}
    };

    Buyer buyer;
    int choice, itemId;

    while (true) {
        cout << "\nCampus Marketplace - Buyer Menu:\n";
        cout << "1. View Items\n2. Add Item to Cart\n3. View Cart\n4. Checkout\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                buyer.viewItems(items);
                break;
            case 2:
                cout << "Enter the Item ID to add to cart: ";
                cin >> itemId;
                buyer.addToCart(itemId, items);
                break;
            case 3:
                buyer.viewCart();
                break;
            case 4:
                buyer.checkout();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
