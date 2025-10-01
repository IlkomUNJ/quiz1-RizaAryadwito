#include <iostream>
#include "bank_customer.h"
#include "buyer.h"

enum PrimaryPrompt{LOGIN, REGISTER, EXIT};
enum RegisterPrompt{CREATE_BUYER, CREATE_SELLER, BACK};
using namespace std;

int main() {

    //create a loop prompt 
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
            case LOGIN:
                cout << "Login selected." << endl;
                cout << "Select an option: " << endl;
                cout << "1. Check Account Status" << endl;
                cout << "2. Upgrade Account to Seller" << endl;
                cout << "3. Create Banking Account" << endl;
                cout << "4. Browse Store" << endl;
                cout << "5. Order" << endl;
                cout << "6. Payment" << endl;
                cout << "7. Logout" << endl;
                cout << "8. Delete Account" << endl;
                cout << "9. Check Inventory" << endl;
                cout << "10. Add Item to inventory" << endl;
                cout << "11. Back" << endl;
                cout << "12. Remove Item from Inventory" << endl;
                cout << "13. Exit to Main Menu" << endl;
                cout << "14. Exit Program" << endl;
                int regChoice;
                cin >> regChoice;
                /* if Login is selected, based on authority then provide options:
                assume user is logged in as Buyer for now
                1. Chek Account Status (will display if user is Buyer or Seller or both and linked banking account status)
                Will display Buyer, Seller and Banking Account details
                2. Upgrade Account to Seller
                Will prompt user to enter Seller details and create a Seller account linked to Buyer account
                Will reject if a user dont have a banking account linked
                3. Create Banking Account (if not already linked), will be replaced with banking functions
                Must provides: initial deposit amount, Address, Phone number, Email
                Banking functions will provides: Balance checking, Transaction History, Deposit, Withdraw
                4. Browse Store Functionality
                Will display all stores initially
                Need to select a store to browse each store inventory
                Will display all items in the store inventory
                After selecting an item, will display item details and option to add to cart
                After adding to cart, will notify user item is added to cart
                5. Order Functionality
                Will display all items in cart
                Will provide option to remove item from cart
                Will provide option to checkout
                After checkout invoide will be generated (will go to payment functionality)
                6. Payment Functionality
                Will display all listed invoices
                Pick an invoice to pay
                Will display invoice details and total amount
                Will provide option to pay invoice
                Payment is done through confirmation dialogue
                In confirmation dialogue, will display account balance as precursor
                User will need to manually enter invoice id to pay
                After paying balance will be redacted from buyer and added to the responding seller account
                After payment, order status will be changed to paid
                7. Logout (return to main menu)
                Display confirmation dialogue
                If confirmed, return to main menu
                If not, return to Buyer menu
                8. Delete Account (remove both Buyer and Seller account and relevant banking account)
                Display confirmation dialogue
                If confirmed, delete account and return to main menu
                If not, return to Buyer menu
                assume user is logged in as Seller for now
                9. Check Inventory
                10. Add Item to Inventory
                11. Remove Item from Inventory
                12. View Orders (will display all orders placed to this seller
                Only orders with paid status will be listed
                Order details will listing items, quantity, total amount, buyer details, order status (paid, cancelled, completed)
                extra functions
                9. Exit to main Menu
                10. Exit Program
                **/
                break;
            case REGISTER:
                cout << "Register selected." << endl;
                cout << "Select an option: " << endl;
                cout << "1. Create Buyer Account" << endl;
                cout << "2. Create Seller Account" << endl;
                cout << "3. Back" << endl;
                int regChoice;
                cin >> regChoice;
                regPrompt = static_cast<RegisterPrompt>(regChoice - 1);
                switch (regPrompt){
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
                        // For demonstration, just print the info
                        cout << "\nBuyer Account Created!" << endl;
                        cout << "Name: " << name << endl;
                        cout << "Address: " << address << endl;
                        cout << "Phone: " << phone << endl;
                        cout << "Email: " << email << endl;
                        // TODO: Create Buyer and BankCustomer objects and store them
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
            case EXIT:
                cout << "Exiting." << std::endl;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
        cout << endl;
    }

    //BankCustomer customer1(1, "Alice", 1000.0);
    //Buyer buyer1(1, customer1.getName(), customer1);
    return 1;
}
