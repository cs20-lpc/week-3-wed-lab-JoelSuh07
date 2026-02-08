// TO DO: Implement the driver main() function to test your code.
#include "LinkedList.hpp"
#include <iostream>
using namespace std;


    void printMenu() {
    cout << "\n--- LinkedList Menu ---" << endl;
    cout << "1. Append" << endl;
    cout << "2. Insert" << endl;
    cout << "3. Replace" << endl;
    cout << "4. Get Element" << endl;
    cout << "5. Get Length" << endl;
    cout << "6. Clear List" << endl;
    cout << "7. Check if Empty" << endl;
    cout << "8. Remove a Position" << endl;
    cout << "9. Exit" << endl;
    cout << "Choice (1-9): ";
}


int main(){

    LinkedList<int> myList;
    //preinserting values into LinkedList
    myList.insert(1, 0);
    myList.insert(2, 10);
    myList.insert(3, 20);
    myList.insert(4, 30);

    int choice, pos, val;
    bool running = true;

    while (running) {
        printMenu();
        if (running) cout << "Current List: " << myList << endl;

        if (!(cin >> choice)){
            cout << "Invalid input. Please use an Integer value." << endl;

            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        try {
            switch (choice) {
                case 1: // Append
                    cout << "Enter value to append: ";
                    cin >> val;
                    myList.append(val);
                    cout << "Appended " << val << endl;
                    break;

                case 2: // Insert
                    cout << "Enter position and value: ";
                    cin >> pos >> val;
                    myList.insert(pos, val);
                    cout << "Inserted " << val << " at " << pos << endl;
                    break;

                case 3: // Replace
                    cout << "Enter position and new value: ";
                    cin >> pos >> val;
                    myList.replace(pos, val);
                    cout << "Replaced element at " << pos << " with " << val << endl;
                    break;

                case 4: // Get Element
                    cout << "Enter position: ";
                    cin >> pos;
                    cout << "Element at " << pos << ": " << myList.getElement(pos) << endl;
                    break;

                case 5: // Get Length
                    cout << "Current length: " << myList.getLength() << endl;
                    break;

                case 6: // Clear
                    myList.clear();
                    cout << "List cleared." << endl;
                    break;

                case 7: // Is Empty
                    cout << (myList.isEmpty() ? "List is empty." : "List is not empty.") << endl;
                    break;

                case 8: //To Remove
                    cout << "Enter a position to remove: ";
                    cin >> pos;
                    myList.remove(pos);
                    cout << "Removed element at " << pos << endl;
                    break;

                case 9: // Exit
                    running = false;
                    break;

                default:
                    cout << "Invalid choice. Try again." << endl;
            }
            
        }catch (const out_of_range& e){
            cerr << "Caught error: " << e.what() << endl;
    }
            // Show the list after every successful operation
            if (running) cout << "Current List: " << myList << endl;

}

    return 0;
}