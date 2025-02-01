#include"header.h"



///////////////////////////////ADMIN LOD FUNCTIONALITY//////////////////////////////////
void logFailedLogin(const char* username) {
    ofstream activityFile("activity.txt", ios::app); 
    
        activityFile << "Username:" << username << " a customer " << endl;
        activityFile.close();
    }


//////////////////////////////////////////////THIS IS FOR NOTIFIACTIONS OF PROMOCODE//////////////////////////////////////////



void displayPromos(const char* filename) {
    ifstream file(filename);
    

    char line[100];
    cout << "Promo code | Discount percentage" << endl;  // Print the header

    while (file.getline(line, sizeof(line))) {
        char* code = strtok(line, "|");
        char* percentStr = strtok(nullptr, "|");

        if (code && percentStr) {
            int tempPercent = 0;
            bool valid = true;
            for (int i = 0; percentStr[i] != '\0'; ++i) {
                if (percentStr[i] >= '0' && percentStr[i] <= '9') {
                    tempPercent = tempPercent * 10 + (percentStr[i] - '0');
                }
                 else {
                    cerr << "Error: Invalid percentage format on line: " << line << endl;
                    valid = false;
                    break;
                }
            }

            if (valid) {
                cout << code << " | " << tempPercent << "%" << endl;
            }
        } 
    }

    file.close();
}





/////////////////////////////CUSTOMERS OPTION LIST////////////////////////////////

void display_screen_customer(){
cout << "\033[1;32m"; // Set text color to green
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#                  OPTIONS                              #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#                  1. PRODUCT LIST                      #\n"
     << "\t\t\t\t#                  2. PURCHASE HISTORY And Feedback     #\n"
     << "\t\t\t\t#                  3. SUPPORT AND HELP                  #\n"
     << "\t\t\t\t#                  4. EXIT                              #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";

     cout << "\033[0m"; // Reset color

}





//////////////////////////////////////CHANGE THE LIST BY INTERST OPTION1////////////////////////////////////////////

void display_according() {
    char *header = new char[100];
    char *name = new char[100];
    char *category = new char[100];
    char *item_name = new char[100];
    char *user_cate = new char[100];
    int id, price, stock_quantity, minprice, maxprice;

    ifstream file("stock.txt", ios::in);

    file.getline(header, 100);
    cout << header << endl; /// this displays the header like id tag and all

    cout << "Enter Category that u like:";
    cin.ignore(); /// to ignore new line character
    cin.getline(user_cate, 100);

    cout << "Enter minimum price:";
    cin >> minprice;
    cout << "Enter maximum price:";
    cin >> maxprice;

    while (file >> id) { // it will read the id and name and so on

        file.ignore(); /// ignore the spaces and |

        file.getline(name, 100, '|');
        file >> price; // read the price
        file.ignore(); /// ignore the | and spaces after the price
        file >> stock_quantity; /// read stock
        file.ignore(); /// again do the same thing as above

        file.getline(category, 100); /// now read the categories because it's a string

        //// now time for display
        if (compareStrings(category, user_cate) && price >= minprice && price <= maxprice) {
            cout << id << " | " << name << " | " << price << " | " << stock_quantity << " | " << category << endl;
        }
    }
    file.close();

    delete[] header;
    delete[] name;
    delete[] category;
    delete[] item_name;
    delete[] user_cate;
}





 //////////////////////////////////////CART FUNTIONALITY////////////////////////////////////////////   





// This will display stock.txt
void loadStock(int id[], int stockQuantity[], int price[], char name[][100], char category[][100], int& count) {
    ifstream file("stock.txt");
    count = 0;
    char line[200];

    while (file.getline(line, 200)) {
        int fieldIndex = 0, start = 0;
        char temp[50];

        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == '|') {
                for (int j = start; j < i; ++j) {
                    temp[j - start] = line[j];
                }
                temp[i - start] = '\0';
                start = i + 1;

                switch (fieldIndex) {
                case 0:
                    id[count] = stringtoint(temp);
                    break;

                case 1:
                    strcpy(name[count], temp);
                    break;

                case 2:
                    price[count] = stringtoint(temp);
                    break;

                case 3:
                    stockQuantity[count] = stringtoint(temp);
                    break;
                }
                fieldIndex++;
            }
        }
        strcpy(category[count], line + start);
        count++;
    }
    file.close();
}




// This will display items
void displayItems(int id[], int stockQuantity[], int price[], char name[][100], char category[][100], int count) {
    cout << "ID | Item Name                          | Price | Stock Quantity | Category" << endl;
    cout << "-----------------------------------------------------------------------" << endl;

    for (int i = 0; i < count; i++) {
        if (id[i] != 0) {
            cout << id[i] << " | "
                 << name[i] << " | "
                 << price[i] << " | "
                 << stockQuantity[i] << " | "
                 << category[i] << endl;
        }
    }
}

// This will update stock in stock.txt
void updateStock(int id[], int stockQuantity[], int price[], char name[][100], char category[][100], int count) {
    ofstream file("stock.txt");

    for (int i = 0; i < count; i++) {
        file << id[i] << "|"
             << name[i] << "|"
             << price[i] << "|"
             << stockQuantity[i] << "|"
             << category[i] << endl;
    }
    file.close();
}



// This will cart display
void cartDisplay() {
    cout << "\033[1;36m"; // Set text color to cyan
cout << "#########################################################\n"
     << "#                                                       #\n"
     << "#    OPTIONS:                                           #\n"
     << "#    1. ADD ITEMS TO THE CART                           #\n"
     << "#    2. REMOVE ITEMS                                    #\n"
     << "#    3. FINALIZE PURCHASE                               #\n"
     << "#                                                       #\n"
     << "#########################################################\n";
     cout << "\033[0m"; // Reset color
}



// This will add an item to the cart
void addItemToCart(int id[], int stockQuantity[], int price[], char name[][100], char category[][100], int count,
                   int cartId[], int cartQuantity[], int& cartCount) {
    char input[50];
    int itemID, quantity;

    cout << "Enter the item ID to add to cart: ";
    cin >> input;
    itemID = stringtoint(input);

    if (itemID == -1) {
        cout << "Invalid item ID. Please try again." << endl;
        return;
    }

    bool itemFound = false;

    for (int i = 0; i < count; i++) {
        if (id[i] == itemID) {
            itemFound = true;

            cout << "Enter the quantity: ";
            cin >> input;
            quantity = stringtoint(input);

            if (quantity == -1 || quantity <= 0) {
                cout << "Invalid quantity. Please try again." << endl;
                return;
            }

            if (quantity > stockQuantity[i]) {
                cout << "Insufficient stock available." << endl;
            } 
            else {
                stockQuantity[i] -= quantity;

                cartId[cartCount] = id[i];
                cartQuantity[cartCount] = quantity;
                cartCount++;

                cout << "Item added to cart successfully!" << endl;
            }
            break;
        }
    }

    if (!itemFound) {
        cout << "Item not found." << endl;
    }
}



void removeItemFromCart(int cartId[], int cartQuantity[], int& cartCount) {

    int removeId;
    cout << "Enter the item ID to remove from the cart: ";
    cin >> removeId;

    bool itemFound = false;

    // Open a temporary file for writing
    ofstream tempFile("temp_cart.txt", ios::app);
    ifstream cartFile("cart.txt");

    char line[200];
    while (cartFile.getline(line, 200)) {
        if (line[0] >= '0' && line[0] <= '9') { // Identify item lines
            int currentId;
            sscanf(line, "%d|", &currentId);

            if (currentId == removeId) {
                itemFound = true;
                cout << "Item ID " << removeId << " removed from the cart.\n";
                continue; // Skip this line to remove the item
            }
        }
        // Write the line to the temporary file
        tempFile << line << "\n";
    }

    if (!itemFound) {
        cout << "Item not found in the cart.\n";
    }

    cartFile.close();
    tempFile.close();

    // Replace the original file with the updated file
    remove("cart.txt");
    rename("temp_cart.txt", "cart.txt");

    // Remove item from memory cart arrays
    for (int i = 0; i < cartCount; i++) {
        if (cartId[i] == removeId) {
            for (int j = i; j < cartCount - 1; j++) {
                cartId[j] = cartId[j + 1];
                cartQuantity[j] = cartQuantity[j + 1];
            }
            cartCount--;
            break;
        }
    }
}



// This will apply promo code and discount
int applyPromoCode() {
    char inputPromo[50];
    char promoCode[50];
    int discountPercentage;
    bool promoFound = false;

    cout << "Enter promo code (or type 'NO' if you don't have one): ";
    cin >> inputPromo;

    if (compareStrings(inputPromo, "NO") || compareStrings(inputPromo, "No") || compareStrings(inputPromo, "no")) {
        cout << "No promo code applied. Proceeding with the original price." << endl;
        return 0; 
    }

    ifstream promoFile("promo.txt");
    if (promoFile.is_open()) {
        while (promoFile.getline(promoCode, 50, '|')) {
            promoFile >> discountPercentage;
            promoFile.ignore();

            if (compareStrings(inputPromo, promoCode)){
                cout << "Promo code applied successfully! Discount: " << discountPercentage << "%" << endl;
                promoFound = true;
                return discountPercentage;
            }
        }
        promoFile.close();
    }

    if (!promoFound) {
        cout << "Invalid promo code. No discount applied." << endl;
    }
  
}






void finalizePurchase(int cartId[], int cartQuantity[], int cartCount, int id[], int stockQuantity[], int price[],
                      char name[][100], char category[][100], int stockCount) {
    char username[100], password[100];

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    display_loading_screen();

    ofstream cartFile("cart.txt", ios::app); 

    int totalCost = 0;
    int discountPercentage = applyPromoCode(); 

    cout << "Your purchase details:\n";
    cout << "ID | Item Name                          | Price | Quantity | Total\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < cartCount; i++) {
        int itemTotal = price[cartId[i]] * cartQuantity[i];
        totalCost += itemTotal;

        cout << cartId[i] << " | "
             << name[cartId[i]] << " | "
             << price[cartId[i]] << " | "
             << cartQuantity[i] << " | "
             << itemTotal << endl;

        cartFile << cartId[i] << "|"
                 << name[cartId[i]] << "|"
                 << price[cartId[i]] << "|"
                 << cartQuantity[i] << "|"
                 << category[cartId[i]] << "\n";
    }

    // Get current time and format it to display only hours, minutes, and seconds
    time_t now = time(0);
    struct tm* timeStruct = localtime(&now);
    char timeStr[9]; // To store the time string in HH:MM:SS format
    strftime(timeStr, sizeof(timeStr), "%H:%M:%S", timeStruct);

    // Write user and formatted time to the file
    cartFile << "User:" << username << "|Password:" << password << "|Time:" << timeStr << "\n";

    totalCost = totalCost * (1 - discountPercentage / 100.0);
    cout << "Final Total (after discount): " << totalCost << endl;

    cartFile.close();

    updateStock(id, stockQuantity, price, name, category, stockCount);

    cout << "Purchase completed successfully!\n";
}





void cartSystem(int id[], int stockQuantity[], int price[], char name[][100], char category[][100], int count) {
    int cartId[100], cartQuantity[100];
    int cartCount = 0;

    while (true) {
        cartDisplay();
        cout << "\nEnter your choice: ";
        char choice;
        cin >> choice;

        if (choice == '1') {
            displayItems(id, stockQuantity, price, name, category, count);
            addItemToCart(id, stockQuantity, price, name, category, count, cartId, cartQuantity, cartCount);
        } else if (choice == '2') {
            
            removeItemFromCart(cartId, cartQuantity, cartCount);
        } else if (choice == '3') {
            finalizePurchase(cartId, cartQuantity, cartCount, id, stockQuantity, price, name, category, count);
            return;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}






//////////////////////////////////////////////Purchase History//////////////////////////////////////////////////////

// Function to display purchases for a specific user
void displayPurchases(const char* filename, const char* username, const char* password) {
    ifstream file(filename);
    

    char line[256];
    char currentUsername[50], currentPassword[50];
    bool isUserValid = false;
    char purchaseLines[100][256]; // Array to store purchase lines
    int purchaseCount = 0; // Counter for the number of purchases stored

    cout << "Purchases for user '" << username << "':" << endl;

    while (file.getline(line, 256)) {
        // Check if the line contains user information
        if (strncmp(line, "User:", 5) == 0) {
            // Extract username and password
            char* userPos = strstr(line, "User:") + 5;
            char* passPos = strstr(line, "Password:") + 9;

            copySubstring(userPos, 0, currentUsername, 50);
            copySubstring(passPos, 0, currentPassword, 50);

            // Check if the extracted username and password match the provided ones
            if (customStrcmp(currentUsername, username) && customStrcmp(currentPassword, password)) {
                isUserValid = true;
                // Display all stored purchase lines for this user
                for (int i = 0; i < purchaseCount; i++) {
                    cout << purchaseLines[i] << endl;
                }
                purchaseCount = 0; // Reset after displaying purchases
            } else {
                // Reset when a new user line is found that doesn't match
                isUserValid = false;
                purchaseCount = 0; // Clear stored purchases
            }
        }
        // If the line is a purchase line, add it to the array
        else if (!strncmp(line, "User:", 5) == 0) {
            if (isUserValid) {
                // Store purchase line in the array
                strncpy(purchaseLines[purchaseCount], line, 256);
                purchaseCount++;
            }
        }
    }

    if (!isUserValid) {
        cout << "No purchases found for user: " << username << endl;
    }

    file.close();
}






   


//////////////////////////////////FOR SUPPORT AND HELP OPTION 4///////////////////////////////



void submitRequest() {
    char* username = new char[50];
    char* password = new char[50];
    char* request = new char[500];

    cout << "Enter your username: ";
    cin.ignore();
    cin.getline(username, 50);

    cout << "Enter your password: ";
    cin.getline(password, 50);

    cout << "Enter your support request: ";
    cin.getline(request, 500);

    ofstream file("Support.txt", ios::app);
    
    file << "Customer Username: " << username << endl;
    file << "Password: " << password << endl;
    file << "Support Request: " << request << endl;
    file << "----------------------------------------" << endl;
    file.close();
    
    cout << "Your request has been submitted successfully!" << endl;

 
    delete[] username;
    delete[] password;
    delete[] request;
}




/////////////////////////////FEEDBACK//////////////////////////////

// Function to add feedback to the feedback.txt file
void addFeedback(const char* feedbackFile, const char* username, int itemID) {
    ofstream file(feedbackFile, ios::app); // Open the file in append mode
    if (!file) {
        cout << "Error: Cannot open the file for writing!" << endl;
        return;
    }

  
    char* feedback = new char[256];

    cout << "Enter your feedback for item ID " << itemID << ": ";
    cin.ignore(); // Clear the input buffer
    cin.getline(feedback, 256); // Get feedback input

    // Write the username before the item ID and feedback
    file << "User: ";
    for (int i = 0; username[i] != '\0'; i++) {
        file.put(username[i]);
    }
    file << endl;

    // Write the item ID
    file << "Item ID: ";
    char itemIDStr[10];
    int itemIDLength = 0;
    int tempItemID = itemID;
    while (tempItemID > 0) {
        itemIDStr[itemIDLength++] = (tempItemID % 10) + '0';
        tempItemID /= 10;
    }
    for (int i = itemIDLength - 1; i >= 0; i--) {
        file.put(itemIDStr[i]);
    }
    file << endl;

    // Write the feedback
    file << "Feedback: ";
    for (int i = 0; feedback[i] != '\0'; i++) {
        file.put(feedback[i]);
    }
    file << endl;
    file << "----------------------------------------" << endl;

    file.close();
    cout << "Feedback added successfully!" << endl;

 
    delete[] feedback;
}








