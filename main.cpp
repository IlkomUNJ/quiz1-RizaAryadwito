#include <iostream>
#include <vector>
#include "bank_customer.h"
#include "buyer.h"
#include "item.h"

using namespace std;

enum PrimaryPrompt { LOGIN, REGISTER, EXIT };
enum RegisterPrompt { CREATE_BUYER, CREATE_SELLER, BACK };

int main() {
    PrimaryPrompt prompt = LOGIN;
    RegisterPrompt regPrompt = CREATE_BUYER;

    while (prompt != EXIT) {
        cout << "Select an option: " << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cin >> choice;
        prompt = static_cast<PrimaryPrompt>(choice - 1);

        switch (prompt) {
            // ============================ LOGIN ============================
            case LOGIN: {
                cout << "\n=== LOGIN ===" << endl;

                // Simulasi login sebagai Buyer
                BankCustomer bankAcc(1, "Arya", 0.0);
                Buyer buyer(100, "Arya", bankAcc);

                bool hasBankAccount = false;
                bool isSeller = false;
                bool loggedIn = true;

                vector<Item> inventory; // Seller inventory

                while (loggedIn) {
                    cout << "\n===== ACCOUNT MENU =====" << endl;
                    cout << "1. Check Account Status" << endl;
                    cout << "2. Upgrade Account to Seller" << endl;
                    cout << "3. Create Banking Account" << endl;
                    cout << "4. Banking Functions" << endl;
                    cout << "5. Browse Store" << endl;
                    cout << "6. Orders" << endl;
                    cout << "7. Payments" << endl;
                    cout << "8. Check Inventory (Seller)" << endl;
                    cout << "9. Add Item to Inventory (Seller)" << endl;
                    cout << "10. Remove Item (Seller)" << endl;
                    cout << "11. View Orders (Seller)" << endl;
                    cout << "12. Logout" << endl;
                    cout << "13. Delete Account" << endl;
                    cout << "Choose: ";

                    int subChoice;
                    cin >> subChoice;
                    cin.ignore();

                    switch (subChoice) {
                        case 1:
                            cout << "\n[Account Status]" << endl;
                            cout << "Name: " << buyer.getName() << endl;
                            cout << "Role: " << (isSeller ? "Buyer + Seller" : "Buyer") << endl;
                            cout << "Bank Linked: " << (hasBankAccount ? "Yes" : "No") << endl;
                            if (hasBankAccount)
                                cout << "Balance: $" << bankAcc.getBalance() << endl;
                            break;

                        case 2:
                            if (!hasBankAccount) {
                                cout << "You must create a bank account first.\n";
                            } else if (isSeller) {
                                cout << "You are already a Seller!\n";
                            } else {
                                string storeName, storeAddress;
                                cout << "Enter Store Name: ";
                                getline(cin, storeName);
                                cout << "Enter Store Address: ";
                                getline(cin, storeAddress);
                                cout << "\nSeller account created and linked successfully!\n";
                                cout << "Store Name: " << storeName << endl;
                                cout << "Store Address: " << storeAddress << endl;
                                isSeller = true;
                            }
                            break;

                        case 3: {
                            if (hasBankAccount) {
                                cout << "Bank account already exists.\n";
                                break;
                            }
                            double deposit;
                            cout << "Enter initial deposit: ";
                            cin >> deposit;
                            bankAcc.setBalance(deposit);
                            hasBankAccount = true;
                            cout << "Bank account created with balance $" << bankAcc.getBalance() << endl;
                            break;
                        }

                        case 4: {
                            if (!hasBankAccount) {
                                cout << "You must create a bank account first!\n";
                                break;
                            }
                            int bChoice;
                            do {
                                cout << "\n=== BANK MENU ===" << endl;
                                cout << "1. Check Balance" << endl;
                                cout << "2. Deposit" << endl;
                                cout << "3. Withdraw" << endl;
                                cout << "4. Back" << endl;
                                cout << "Choose: ";
                                cin >> bChoice;

                                if (bChoice == 1)
                                    cout << "Current balance: $" << bankAcc.getBalance() << endl;
                                else if (bChoice == 2) {
                                    double amt;
                                    cout << "Deposit amount: ";
                                    cin >> amt;
                                    bankAcc.addBalance(amt);
                                    cout << "Deposit success! Balance: $" << bankAcc.getBalance() << endl;
                                } else if (bChoice == 3) {
                                    double amt;
                                    cout << "Withdraw amount: ";
                                    cin >> amt;
                                    bankAcc.withdrawBalance(amt);
                                    cout << "Remaining balance: $" << bankAcc.getBalance() << endl;
                                }
                            } while (bChoice != 4);
                            break;
                        }

                        case 5:
                            cout << "[Browse Store]\nFeature not implemented yet.\n";
                            break;
                        case 6:
                            cout << "[Orders]\nNo orders yet.\n";
                            break;
                        case 7:
                            cout << "[Payments]\nNo invoices to pay.\n";
                            break;

                        case 8:
                            if (!isSeller) {
                                cout << "You must upgrade to Seller first!\n";
                                break;
                            }
                            cout << "\n[Inventory List]" << endl;
                            if (inventory.empty()) {
                                cout << "No items in inventory.\n";
                            } else {
                                for (auto &i : inventory) {
                                    cout << "ID: " << i.getId()
                                         << " | Name: " << i.getName()
                                         << " | Qty: " << i.getQuantity()
                                         << " | Price: $" << i.getPrice() << endl;
                                }
                            }
                            break;

                        case 9:
                            if (!isSeller) {
                                cout << "You must upgrade to Seller first!\n";
                                break;
                            } else {
                                int id, qty;
                                double price;
                                string name;
                                cout << "Enter Item ID: ";
                                cin >> id;
                                cin.ignore();
                                cout << "Enter Item Name: ";
                                getline(cin, name);
                                cout << "Enter Quantity: ";
                                cin >> qty;
                                cout << "Enter Price: ";
                                cin >> price;
                                inventory.emplace_back(id, name, qty, price);
                                cout << "Item added successfully!\n";
                            }
                            break;

                        case 10:
                            if (!isSeller) {
                                cout << "You must upgrade to Seller first!\n";
                                break;
                            } else {
                                int id;
                                cout << "Enter ID to remove: ";
                                cin >> id;
                                bool found = false;
                                for (auto it = inventory.begin(); it != inventory.end(); ++it) {
                                    if (it->getId() == id) {
                                        inventory.erase(it);
                                        cout << "Item removed.\n";
                                        found = true;
                                        break;
                                    }
                                }
                                if (!found) cout << "Item not found.\n";
                            }
                            break;

                        case 11:
                            if (!isSeller) {
                                cout << "You must upgrade to Seller first!\n";
                            } else {
                                cout << "[View Orders]\nNo orders yet.\n";
                            }
                            break;

                        case 12:
                            cout << "Logging out...\n";
                            loggedIn = false;
                            break;

                        case 13: {
                            cout << "Are you sure you want to delete your account? (y/n): ";
                            char c;
                            cin >> c;
                            if (c == 'y' || c == 'Y') {
                                cout << "Account deleted successfully!\n";
                                loggedIn = false;
                            }
                            break;
                        }

                        default:
                            cout << "Invalid choice.\n";
                    }
                }
                break;
            }

            // ============================ REGISTER ============================
            case REGISTER: {
                cout << "Register selected." << endl;
                cout << "Select an option: " << endl;
                cout << "1. Create Buyer Account" << endl;
                cout << "2. Create Seller Account" << endl;
                cout << "3. Back" << endl;
                int regChoice;
                cin >> regChoice;
                regPrompt = static_cast<RegisterPrompt>(regChoice - 1);

                switch (regPrompt) {
                    case CREATE_BUYER: {
                        cout << "Create Buyer Account Selected." << endl;
                        string name, address, phone, email;
                        cout << "Enter Name: ";
                        cin.ignore();
                        getline(cin, name);
                        cout << "Enter Home Address: ";
                        getline(cin, address);
                        cout << "Enter Phone Number: ";
                        getline(cin, phone);
                        cout << "Enter Email: ";
                        getline(cin, email);
                        cout << "\nBuyer Account Created!" << endl;
                        cout << "Name: " << name << endl;
                        cout << "Address: " << address << endl;
                        cout << "Phone: " << phone << endl;
                        cout << "Email: " << email << endl;
                        break;
                    }

                    case CREATE_SELLER: {
                        cout << "Create Seller Account Selected." << endl;
                        string storeName, storeAddress, storePhone, storeEmail;
                        cout << "Enter Store Name: ";
                        cin.ignore();
                        getline(cin, storeName);
                        cout << "Enter Store Address: ";
                        getline(cin, storeAddress);
                        cout << "Enter Store Phone Number: ";
                        getline(cin, storePhone);
                        cout << "Enter Store Email: ";
                        getline(cin, storeEmail);
                        cout << "\nSeller Account Created and linked to Buyer!" << endl;
                        cout << "Store Name: " << storeName << endl;
                        cout << "Store Address: " << storeAddress << endl;
                        cout << "Store Phone: " << storePhone << endl;
                        cout << "Store Email: " << storeEmail << endl;
                        cout << "You are now logged in as Buyer/Seller." << endl;
                        break;
                    }

                    case BACK:
                        cout << "Back Selected." << endl;
                        break;

                    default:
                        cout << "Invalid Option." << endl;
                }
                break;
            }

            // ============================ EXIT ============================
            case EXIT:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid option." << endl;
                break;
        }

        cout << endl;
    }

    return 0;
}

