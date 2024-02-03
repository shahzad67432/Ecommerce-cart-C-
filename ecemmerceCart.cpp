#include <iostream>
#include <string>
using namespace std;

string productsNames[3] = {"laptop", "earphones", "study_Table"};
int price[3] = {100, 200, 300};
int quantity[3] = {4, 5, 2};

int cart[3] = {0};  // Initialize the cart with zero quantities

void ProductInformation() {
    cout << "Product Information:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << productsNames[i] << " $" << price[i] << " (Available: " << quantity[i] << ")" << endl;
    }
}

void AddToCart() {
    int productNumber, quantityToAdd;

    cout << "Enter the product number to add to cart: ";
    cin >> productNumber;

    if (productNumber < 1 || productNumber > 3) {
        cout << "Invalid product number.\n";
        return;
    }

    cout << "Enter the quantity to add: ";
    cin >> quantityToAdd;

    if (quantityToAdd <= 0 || quantityToAdd > quantity[productNumber - 1]) {
        cout << "Invalid quantity or not enough stock.\n";
        return;
    }

    cart[productNumber - 1] += quantityToAdd;
    quantity[productNumber - 1] -= quantityToAdd;

    cout << "Item added to the cart.\n";
}

void ViewCart() {
    cout << "Shopping Cart:" << endl;
    for (int i = 0; i < 3; i++) {
        if (cart[i] > 0) {
            cout << i + 1 << ". " << productsNames[i] << " - Quantity: " << cart[i] << " - Total Cost: $" << (cart[i] * price[i]) << endl;
        }
    }
}

void CalculateTotalCost() {
    int totalCost = 0;
    for (int i = 0; i < 3; i++) {
        totalCost += cart[i] * price[i];
    }
    cout << "Total Cost: $" << totalCost << endl;
}

int main() {
    int choice;

    cout << "Welcome to Online Shopping!\n";

    do {
        cout<< endl;
        cout << "1. View Product Information\n";
        cout << "2. Add Item to Cart\n";
        cout << "3. View Cart\n";
        cout << "4. Calculate Total Cost\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ProductInformation();
                break;
            case 2:
                AddToCart();
                break;
            case 3:
                ViewCart();
                break;
            case 4:
                CalculateTotalCost();
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
