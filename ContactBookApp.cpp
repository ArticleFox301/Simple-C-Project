#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contact
{
    string name;
    string phone;
    string email;
};

void addContact(vector<Contact> &contacts){
    Contact newContact;
    cout << "Enter name: ";
    cin >> newContact.name;
    cout << "Enter phone: ";
    cin >> newContact.phone;
    cout << "Enter email: ";
    cin >> newContact.email;
    contacts.push_back(newContact);
    cout << "Contact added" << endl;
}

void displayContacts(const vector<Contact> &contacts){
    for(const auto &contact : contacts){
        cout << "Name: " << contact.name << ", Phone: " << contact.phone << ", Email: " << contact.email << endl;
    }
}

void searchContact(const vector<Contact> &contacts){
    string searchTerm;
    cout << "Enter name to search: ";
    cin >> searchTerm;

    bool found = false;
    for (const auto &contact: contacts){
        if(contact.name == searchTerm){
            cout << "Name: " << contact.name << ", Phone: " << contact.phone << ", Email: " << contact.email << endl;
            found = true;
            break;
        }
    }
    if(!found){
        cout << "Contact not found." << endl;
    }
}

void deleteContact(vector<Contact> &contacts){
    string nameToDelete;
    cout << "Enter name of contact to delete: ";
    cin >> nameToDelete;

    auto it = remove_if(contacts.begin(), contacts.end(), [&](const Contact &contact)
        {return contact.name == nameToDelete;});
    if(it != contacts.end()){
        contacts.erase(it, contacts.end());
        cout << "Contact delete." << endl;
    } else {
        cout << "Contact not found." << endl;
    }
}

int main(){
    vector<Contact> contacts;
    int choice;

    do{
        cout << "\n1. Add Contact" << endl;
        cout << "2. Display Contacts" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                addContact(contacts);
                break;
            case 2:
                displayContacts(contacts);
                break;
            case 3:
                searchContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 5);

    return 0;
}
