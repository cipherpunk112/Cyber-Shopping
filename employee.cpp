#include"header.h"


/////////////////////////////////////////////////LOG ACTIVITY OF THE ADMIN///////////////////////////////
void LogFailedLogin(const char* username) {
    ofstream activityFile("activity.txt", ios::app); // Open file in append mode
    
        activityFile << "Username:" << username << " an employee" << endl;
        activityFile.close();
    }




/////////////////////////////////////////////////////FOR EMPLOYEES////////////////////////////////////////////////////////////

void display_employee(){///display screen
cout << "\033[1;32m"; // Set text color to green
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#    PLEASE CHOOSE AN OPTION BELOW:                     #\n"
     << "\t\t\t\t#    1. Update Stock                                    #\n"
     << "\t\t\t\t#    2. Check Support Message                           #\n"
     << "\t\t\t\t#    3. Low Stock List                                  #\n"
     << "\t\t\t\t#    4. Sales and Revenue                               #\n"
     << "\t\t\t\t#    5. Exit                                            #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";

     cout << "\033[0m"; // Reset color
}





/// //////////////////////////////////IT FOR UPDATE STOCK OPTION1/////////////////////////////////////////////

void Display_stock_list() {
    char fileHeader[100];
    char name[100];
    char category[100];
    int id, price, stock_quantity;

    ifstream file("stock.txt", ios::in);

    // Check if file opened successfully
    if (!file) {
        cerr << "Error: Unable to open file!" << endl;
        return;
    }

    file.getline(fileHeader, 100); // Ignore the file's header

    // Display your own header
    cout << left << setw(5) << "ID"
         << setw(30) << "Item Name"
         << setw(10) << "Price"
         << setw(15) << "Stock Qty"
         << "Category" << endl;

    // Display line separator for better alignment
    for (int i = 0; i < 65; i++) {
        cout << '-';
    }
    cout << endl;

    while (file >> id) { //It will read the id and name and so on

        file.ignore(); ///Ignore the spaces and |

        file.getline(name, 100, '|'); //Read the item name
        file >> price; //Read the price
        file.ignore(); ///Ignore the | and spaces after the price
        file >> stock_quantity; ///Read stock quantity
        file.ignore(); ///Again do the same thing as above

        file.getline(category, 100); ///Now read the categories because it's a string

        ////Now time for display
        cout << left << setw(5) << id
             << setw(30) << name
             << setw(10) << price
             << setw(15) << stock_quantity
             << category << endl;
    }

    file.close();
}





void logStockUpdate(const char *username, int updateID) {/////// This is for admin functionality
    ofstream logFile("critical.txt", ios::app); // Open in append mode to add new entries

    if (logFile.is_open()) {
        logFile << "User " << username << " updated item of ID " << updateID << endl;
        logFile.close();
    } 
}




void Update_stock() { ///for the 1. functionality to update stock
    char *line = new char[256];
    char *name = new char[100];
    char *category = new char[100];
    char *updatedLine = new char[256];
    int id, price, stock_quantity, updateID;
    bool itemFound = false;
    char username[100]; // For storing the username

    
    cout << "Enter your username: ";
    cin.ignore(); 
    cin.getline(username, 100);

    Display_stock_list();

    cout << "Enter the ID of the item you want to update: ";
    cin >> updateID;

    ifstream file("stock.txt");
    ofstream tempFile("temp.txt"); // temp file to make an update

    file.getline(line, 256); ///Read header
    tempFile << line << endl;

    while (file >> id) {
        file.ignore(); // Ignore the |

        file.getline(name, 100, '|');
        file >> price;
        file.ignore();
        file >> stock_quantity;
        file.ignore();
        file.getline(category, 100);

        if (id == updateID) {
            itemFound = true;

            
            cin.ignore();
            cout << "Enter new name: ";
            cin.getline(name, 100);

            cout << "Enter new price: ";
            cin >> price;

            cout << "Enter new stock quantity: ";
            cin >> stock_quantity;

            cin.ignore(); // Ignore the newline character from previous input
            cout << "Enter new category: ";
            cin.getline(category, 100);

            // Update line preparing
            tempFile << id << "|" << name << "|" << price << "|" << stock_quantity << "|" << category << endl;
        } 
        else {
            // Write original line from the temp file
            tempFile << id << "|" << name << "|" << price << "|" << stock_quantity << "|" << category << endl;
        }
    }

    file.close();
    tempFile.close();

    ////Here comes the replacement of the data
    if (itemFound) {
        remove("stock.txt");
        rename("temp.txt", "stock.txt");
        cout << "Stock updated successfully." << endl;

        // Log the update to critical.txt
        logStockUpdate(username, updateID); // Logs the update action
    } else {
        remove("temp.txt");
        cout << "Item with ID " << updateID << " not found." << endl;
    }

    delete[] line;
    delete[] name;
    delete[] category;
    delete[] updatedLine;
}








////////////////////////IT IS FOR LOW STOCK OPTION3//////////////////


void updateLowStock() {
    ifstream stockFile("stock.txt");
    ofstream lowStockFile("low_stock.txt", ios::trunc);

    char *line = new char[256];
    char *id = new char[20];
    char *name = new char[100];
    char *priceStr = new char[20];
    char *quantityStr = new char[20];
    char *category = new char[100];

    lowStockFile << left << setw(10) << "ID"
                 << "|" << left << setw(25) << "Item Name"
                 << "|" << left << setw(8) << "Price"
                 << "|" << left << setw(15) << "Stock Quantity"
                 << "|" << "Status" << endl;
    lowStockFile << string(80, '-') << endl;

    stockFile.getline(line, 256);

    while (stockFile.getline(line, 256)) {
        char* token = customStrtok(line, "|");
        if (token == nullptr) continue;
        customStrcpy(id, token);

        token = customStrtok(nullptr, "|");
        if (token == nullptr) continue;
        customStrcpy(name, token);

        token = customStrtok(nullptr, "|");
        if (token == nullptr) continue;
        customStrcpy(priceStr, token);

        token = customStrtok(nullptr, "|");
        if (token == nullptr) continue;
        customStrcpy(quantityStr, token);

        token = customStrtok(nullptr, "|");
        if (token == nullptr) continue;
        customStrcpy(category, token);

        int stockQuantity = stringtoint(quantityStr);

        if (stockQuantity <= 5) {
            lowStockFile << left << setw(10) << id
                         << "|" << left << setw(25) << name
                         << "|" << left << setw(8) << priceStr
                         << "|" << left << setw(15) << stockQuantity
                         << "|LOW STOCK" << endl;
        }
    }

    stockFile.close();
    lowStockFile.close();

    // Free dynamically allocated memory
    delete[] line;
    delete[] id;
    delete[] name;
    delete[] priceStr;
    delete[] quantityStr;
    delete[] category;
}




void read_low_stock() {
    ifstream file("low_stock.txt");

    if (!file) {
        cerr << "Unable to open file low_stock.txt" << endl;
        return;
    }

    char *line = new char[256];
    char *id = new char[20];
    char *name = new char[100];
    char *price = new char[20];
    char *quantityStr = new char[20];
    char *status = new char[20];

    if (file.getline(line, 256)) {
        cout << line << endl;
    }

    if (file.getline(line, 256)) {
        cout << line << endl;
    }

    while (file.getline(line, 256)) {
        char* token = customStrtok(line, "|");

        if (token != nullptr) {
            customStrcpy(id, token);
        }
        token = customStrtok(nullptr, "|");

        if (token != nullptr) {
            customStrcpy(name, token);
        }
        token = customStrtok(nullptr, "|");

        if (token != nullptr) {
            customStrcpy(price, token);
        }
        token = customStrtok(nullptr, "|");

        if (token != nullptr) {
            customStrcpy(quantityStr, token);
        }
        token = customStrtok(nullptr, "|");

        if (token != nullptr) {
            customStrcpy(status, token);
        }

        cout << id << " | " << name << " | " << price << " | " << quantityStr << " | " << status << endl;
    }

    file.close();

    delete[] line;
    delete[] id;
    delete[] name;
    delete[] price;
    delete[] quantityStr;
    delete[] status;
}




void updateLowStockFile() {
    ifstream stockFile("stock.txt");
    ofstream updatedLowStockFile("low_stock_temp.txt", ios::trunc);

    char *stockLine = new char[256];
    char *id = new char[20];
    char *name = new char[100];
    char *price = new char[20];
    char *stockQuantityStr = new char[20];

    while (stockFile.getline(stockLine, 256)) {
        char* token = customStrtok(stockLine, "|");

        if (!token) continue;
        customStrcpy(id, token);
        token = customStrtok(nullptr, "|");

        if (!token) continue;
        customStrcpy(name, token);
        token = customStrtok(nullptr, "|");

        if (!token) continue;
        customStrcpy(price, token);
        token = customStrtok(nullptr, "|");

        if (!token) continue;
        customStrcpy(stockQuantityStr, token);

        int stockQuantity = stringtoint(stockQuantityStr);

        if (stockQuantity <= 5) {
            updatedLowStockFile << left << setw(10) << id << "|"
                                << left << setw(25) << name << "|"
                                << left << setw(8) << price << "|"
                                << left << setw(15) << stockQuantity
                                << "|LOW STOCK" << endl;
        }
    }

    stockFile.close();
    updatedLowStockFile.close();

    delete[] stockLine;
    delete[] id;
    delete[] name;
    delete[] price;
    delete[] stockQuantityStr;

    read_low_stock();
}








/////////////////////////////////////////////////////////////////////////////IT FOR REVENUE OPTION 4//////////////////////////////

// Function to display the contents of the file
void displayFileContents(const char* filename) {
    ifstream file(filename);
   

     cout << "ID | Product Name | Price | Quantity | Category" << endl;
    cout << "--------------------------------------------------------------------" << endl;

    char line[500];
    while (file.getline(line, 500)) {
        cout << line << endl;
    }

    file.close();
}




// Function to calculate total revenue
int calculateTotalRevenue(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file!" << endl;
        return -1;
    }

    char line[500];
    int totalRevenue = 0;

    // Process each line in the file
    while (file.getline(line, 500)) {
        char id[10], name[100], priceStr[20], quantityStr[20], category[50];
        int fieldCount = 0;
        int index = 0;
        int length = 0;

        // Parse the line and extract fields
        for (int i = 0; line[i] != '\0'; ++i) {
            if (line[i] == '|') {
                
                if (fieldCount == 0) {
                    id[index] = '\0';
                } 
                
                else if (fieldCount == 1) {
                    name[index] = '\0';
                } 
                
                else if (fieldCount == 2) {
                    priceStr[index] = '\0';
                } 
                
                else if (fieldCount == 3) {
                    quantityStr[index] = '\0';
                } 
                
                else if (fieldCount == 4) {
                    category[index] = '\0';
                }
                fieldCount++;
                index = 0; 
            } 
            
            else {
                
                if (fieldCount == 0) {
                    id[index++] = line[i];
                } 
                
                else if (fieldCount == 1) {
                    name[index++] = line[i];
                } 
                
                else if (fieldCount == 2) {
                    priceStr[index++] = line[i];
                } 
                
                else if (fieldCount == 3) {
                    quantityStr[index++] = line[i];
                } 
                
                else if (fieldCount == 4) {
                    category[index++] = line[i];
                }
            }
        }
       
        if (fieldCount == 2) {
            priceStr[index] = '\0';
        } 
        
        else if (fieldCount == 3) {
            quantityStr[index] = '\0';
        }

        // Convert price and quantity to integers
        int price = converttoint(priceStr);
        int quantity = converttoint(quantityStr);

        
        if (price >= 0 && quantity >= 0) {
            totalRevenue += price * quantity; // Add to total revenue
        } 
        
       
    }

    file.close();
    return totalRevenue;
}







/////////////////////CHECK SUPPORTVMESSAGE OPTION2////////////////////////////////
void viewRequests() {
    ifstream file("Support.txt");
    if (!file.is_open()) {
        cout << "Error: Could not open the file for reading." << endl;
        return;
    }

    char *line = new char[500];  

    cout << "Existing Support Requests:" << endl;
    while (file.getline(line, 500)) {
        cout << line << endl;
    }

    delete[] line;

    file.close();
}






