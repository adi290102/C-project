#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct MenuItem {
    string name;
    double price;
};

struct OrderItem {
    MenuItem item;
    int quantity;
};

void displayMenu(const vector<MenuItem>& menu) {
    cout << "Menu:" << endl;
    for (int i = 0; i < menu.size(); i++) {
        cout << i + 1 << ". " << menu[i].name << " - $" << fixed << setprecision(2) << menu[i].price << endl;
    }
    cout << endl;
}

double calculateTotal(const vector<OrderItem>& orders) {
    double total = 0.0;
    for (const auto& order : orders) {
        total += order.item.price * order.quantity;
    }
    return total;
}

void generateReceipt(const vector<OrderItem>& orders, double total) {
    cout << "Receipt:" << endl;
    for (const auto& order : orders) {
        cout << order.item.name << " x " << order.quantity << " - $" << fixed << setprecision(2)
             << order.item.price * order.quantity << endl;
    }
    cout << "Total: $" << fixed << setprecision(2) << total << endl;
}

int main() {
    vector<MenuItem> menu = {
        {"Burger", 5.99},
        {"Pizza", 8.99},
        {"Salad", 4.99},
        {"Pasta", 7.99},
        {"Ice Cream", 3.99}
    };

    vector<OrderItem> orders;
    char choice;

    displayMenu(menu);

    do {
        int itemIndex;
        int quantity;

        cout << "Enter item number: ";
        cin >> itemIndex;

        if (itemIndex >= 1 && itemIndex <= menu.size()) {
            cout << "Enter quantity: ";
            cin >> quantity;

            orders.push_back({menu[itemIndex - 1], quantity});
        } else {
            cout << "Invalid item number. Please try again." << endl;
        }

        cout << "Do you want to order another item? (Y/N): ";
        cin >> choice;
        cout << endl;

    } while (choice == 'Y' || choice == 'y');

    double total = calculateTotal(orders);
    generateReceipt(orders, total);

    return 0;
}