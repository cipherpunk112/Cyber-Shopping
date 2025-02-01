#include "header.h"
 
 ////////////LOGIN////////////////////////

int generateOTP() {
    srand(time(0));
    return 100000 + rand() % 900000;
}





////////////////DISPLAY THE ADMIN OPTIONS////////////////////

void display_admin(){
cout << "\033[1;32m"; // Set text color to green
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#    PLEASE CHOOSE AN OPTION BELOW:                     #\n"
     << "\t\t\t\t#    1. Update Stocks                                   #\n"
     << "\t\t\t\t#    2. Discount and Promo                              #\n"
     << "\t\t\t\t#    3. Audit Trail                                     #\n"
     << "\t\t\t\t#    4. Low Stock                                       #\n"
     << "\t\t\t\t#    5. Log Activity                                    #\n"
     << "\t\t\t\t#    6. Sales Report                                    #\n"
     << "\t\t\t\t#    7. User Role Management                            #\n"
     << "\t\t\t\t#    8. Exit                                            #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";

     cout << "\033[0m"; // Reset color


}




//////////////////////////////////FOR UPDATE STOCK OPTION1/////////////////////////////////////

void Update_stock_in_bulk() { ///for the 1. functionality to update stock
    char *line = new char[256];
    char *name = new char[100];
    char *category = new char[100];
    int id, price, stock_quantity, updateID;
    bool itemFound = false;
    char continueUpdate;
    char operationChoice;
    int count = 0;
   

    do {
         cout << "\033[1;36m"; // Set text color to cyan
        cout << "\t\t\t\t#########################################################\n"
             << "\t\t\t\t#                                                       #\n"
             << "\t\t\t\t#    PLEASE CHOOSE AN OPTION BELOW:                     #\n"
             << "\t\t\t\t#    1. Add a New Item                                  #\n"
             << "\t\t\t\t#    2. Edit an Existing Item                           #\n"
             << "\t\t\t\t#    3. Exit                                            #\n"
             << "\t\t\t\t#                                                       #\n"
             << "\t\t\t\t#########################################################\n";
        cin >> operationChoice;
        cout << "\033[0m"; // Reset color

        if (operationChoice == '1') {


             Display_stock_list();


            // Add a new item
            ifstream file("stock.txt");
            ofstream tempFile("temp.txt");

            while(!file.eof()){
                file>>count;
                file.getline(line,99,'\n');
                count++;
            }
            file.close();
             file.open("stock.txt");
            file.getline(line, 256); ///Read header
            tempFile << line << endl;

            cin.ignore();
            cout << "Enter new ID: ";
            cin >> id;

            cin.ignore(); // Ignore newline character

            cout << "Enter new name: ";
            cin.getline(name, 100);

            cout << "Enter new price: ";
            cin >> price;

            cout << "Enter new stock quantity: ";
            cin >> stock_quantity;

            cin.ignore(); // Ignore newline character
            cout << "Enter new category: ";
            cin.getline(category, 100);

            // Write the new item to the temp file
            tempFile <<  count << "|" << name << "|" << price << "|" << stock_quantity << "|" << category << endl;

            // Copy remaining lines from the original file
            while (file.getline(line, 256)) {
                tempFile << line << endl;
            }

            file.close();
            tempFile.close();

            remove("stock.txt");
            rename("temp.txt", "stock.txt");

            cout << "Item added successfully." << endl;

        } 
        else if (operationChoice == '2') {

             Display_stock_list();


            // Update an existing item
            cout << "Enter the ID of the item you want to update: ";
            cin >> updateID;

            ifstream file("stock.txt");
            ofstream tempFile("temp.txt");

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
                } else {
                    // Write original line from the temp file
                    tempFile << id << "|" << name << "|" << price << "|" << stock_quantity << "|" << category << endl;
                }
            }

            file.close();
            tempFile.close();

            if (itemFound) {
                remove("stock.txt");
                rename("temp.txt", "stock.txt");
                cout << "Stock updated successfully." << endl;
            } else {
                remove("temp.txt");
                cout << "Item with ID " << updateID << " not found." << endl;
            }

        } 
      else if (operationChoice == '3'){
                    return;
      }
        else {
            cout << "Invalid choice. Please enter '1' to add or '2' to edit." << endl;
            continue;
        }

        cout << "Do you want to perform another operation? (y/n): ";
        cin >> continueUpdate;
        cin.ignore(); // Ignore any leftover newline

    } while (continueUpdate == 'y' || continueUpdate == 'Y');

    delete[] line;
    delete[] name;
    delete[] category;
}






/////////////////////////////////////USER ROLE MANAGEMENT OPTION7//////////////////////////////

void display_user_role(){
cout << "\033[1;36m"; // Set text color to cyan
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#    WHICH FILE DO YOU WANT TO EDIT?                    #\n"
     << "\t\t\t\t#    1. Customer                                        #\n"
     << "\t\t\t\t#    2. Employee                                        #\n"
     << "\t\t\t\t#    3. Admin                                           #\n"
     << "\t\t\t\t#    4. Exit                                            #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";

     cout << "\033[0m"; // Reset color


}

///////////////////////////////////////////////FOR CUSTOMER FILE UPDATE////////////////////////////////////////////////


void Display_customer_list() {////it will display customer.txt
    char* username = new char[100];
    char* password = new char[100];

    ifstream file("customers.txt", ios::in); 

    cout << "Username | Password" << endl;
    cout << "-------------------" << endl;

    while (file >> username >> password) { 
        cout << username << " | " << password << endl; 
    }

    file.close(); 

    delete[] username;
    delete[] password;
}




void Display_employee_list() { // It will display employees.txt file
    char* username = new char[50];
    char* password = new char[50]; 

    ifstream file("employees.txt", ios::in); 
  
    cout << "Username | Password" << endl;
    cout << "-------------------" << endl;

    while (file >> username >> password) { 
        cout << username << " | " << password << endl; 
    }

    file.close();

    delete[] username;
    delete[] password;
}



void Display_admin_list() { // It will display pass_admin.txt file
    char* username = new char[50];
    char* password = new char[50];

    ifstream file("pass_admin.txt", ios::in);

    cout << "Username | Password" << endl;
    cout << "-------------------" << endl;

    while (file >> username >> password) {
        cout << username << " | " << password << endl;
    }

    file.close();

    delete[] username;
    delete[] password;
}






void Manage_customers() {////////this is for the customer
    char* name = new char[100];
    char* password = new char[100];
    char* targetName = new char[100];
    char* newName = new char[100];
    char* newPassword = new char[100];
    bool userFound = false;

    ifstream file("customers.txt");
    int choice;
    Main_Display_customer:
    cout << "\033[1;32m"; // Set text color to green
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#    1. Update an existing customer                     #\n"
     << "\t\t\t\t#    2. Add a new customer                             #\n"
     << "\t\t\t\t#    3. Remove an existing customer                     #\n"
     << "\t\t\t\t#    4. Exit                                            #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";

         cout << "\033[0m"; // Reset color

    cin >> choice;
    cin.ignore();

    if (choice == 4) {
        
        delete[] name;
        delete[] password;
        delete[] targetName;
        delete[] newName;
        delete[] newPassword;
        return;
    }

    ofstream tempFile("temp2.txt"); 

    if (choice == 1) { 
        Display_customer_list();
        cout << "Enter the username you want to update: ";
        cin.getline(targetName, 100); 

        file.clear();//// This is for the error handling 
        file.seekg(0, ios::beg); /// This is for move again to the begining of the file 

        while (file >> name >> password) {
            if (compareStrings(name, targetName)) {
                userFound = true;

                cout << "Enter new username: ";
                cin.getline(newName, 100);
                cout << "Enter new password: ";
                cin.getline(newPassword, 100);

                tempFile << newName << " " << newPassword << endl;
            } else {
                tempFile << name << " " << password << endl;
            }
        }
    }
    


    else if (choice == 2) { 
        Display_customer_list();
        char user[30], pass[40];
        bool same;
       while(true){
            cout << "Enter new username: ";
            cin.getline(newName, 100);
            fstream fl("customers.txt", ios::in);
            while(!fl.eof()){
                fl>>user>>pass;
                if(compareStrings(user, newName)){
                    same= true;
                    break;
                }
            }
            fl.close();
            if(!same){
                break;
            }
            cout<<"Please select a unique username\n";
       }


        cout << "Enter new password: ";
        cin.getline(newPassword, 100);

        tempFile << newName << " " << newPassword << endl;
        userFound = true;

        file.clear();//// This is for the error handling 
        file.seekg(0, ios::beg); /// This is for move again to the begining of the file 

        while (file >> name >> password) {
            tempFile << name << " " << password << endl;
        } 

    }
    
    else if (choice == 3) { 
        Display_customer_list();
        cout << "Enter the username you want to remove: ";
        cin.getline(targetName, 100);

       file.clear();//// This is for the error handling 
        file.seekg(0, ios::beg); /// This is for move again to the begining of the file 


        while (file >> name >> password) {
            if (!compareStrings(name, targetName)) {
                tempFile << name << " " << password << endl;
            }
            
             else {
                userFound = true;
            }
        }
    }

    file.close();
    tempFile.close();

    if (userFound) {
        remove("customers.txt");
        rename("temp2.txt", "customers.txt");

        if (choice == 1) {
            cout << "Customer information updated successfully." << endl;
           
        } 
        
        else if (choice == 2) {
            cout << "New customer added successfully." << endl;
            
        } else if (choice == 3) {
            cout << "Customer removed successfully." << endl;
            
        }
    } 
    else {
        remove("temp2.txt");
        cout << "Customer not found." << endl;
    }

    delete[] name;
    delete[] password;
    delete[] targetName;
    delete[] newName;
    delete[] newPassword;
}




void Manage_employees() {///////// This is for the employee
    char* name = new char[100];
    char* password = new char[100];
    char* targetName = new char[100];
    char* newName = new char[100];
    char* newPassword = new char[100];
    bool userFound = false;

    ifstream file("employees.txt");
    int choice;
    Main_Display_employee:
    cout << "\033[1;32m"; // Set text color to green
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#    1. Update an existing employee                     #\n"
     << "\t\t\t\t#    2. Add a new employee                              #\n"
     << "\t\t\t\t#    3. Remove an existing employee                     #\n"
     << "\t\t\t\t#    4. Exit                                            #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";

         cout << "\033[0m"; // Reset color

    cin >> choice;
    cin.ignore();

    if (choice == 4) {
      
        delete[] name;
        delete[] password;
        delete[] targetName;
        delete[] newName;
        delete[] newPassword;
        return;
    }

    ofstream tempFile("temp2.txt"); 

    if (choice == 1) { 
        Display_employee_list();
        cout << "Enter the username you want to update: ";
        cin.getline(targetName, 100); 

        file.clear();
        file.seekg(0, ios::beg); 

        while (file >> name >> password) {
            if (compareStrings(name, targetName)) {
                userFound = true;

                cout << "Enter new username: ";
                cin.getline(newName, 100);

                
                cout << "Enter new password: ";
                cin.getline(newPassword, 100);

                tempFile << newName << " " << newPassword << endl;
            } 
            else {
                tempFile << name << " " << password << endl;
            }
        }
    } 
    else if (choice == 2) { 
        Display_employee_list();
        char user[30] , pass[30];
        bool same = false;
        do{
            cout << "Enter new username: ";
            cin.getline(newName, 100);
            fstream fl("customers.txt", ios::in);
                while(!fl.eof()){
                    fl>>user>>pass;
                    if(compareStrings(user, newName)){
                        same= true;
                        break;
                    }
                }
                fl.close();
                if(!same){
                    break;
                }
                cout<<"Please select a unique username\n";
        }while(true);
    

        cout << "Enter new password: ";
        cin.getline(newPassword, 100);

        tempFile << newName << " " << newPassword << endl;
        userFound = true;

        file.clear();
        file.seekg(0, ios::beg);
        while (file >> name >> password) {
            tempFile << name << " " << password << endl;
        }
    }
    else if (choice == 3) { 
        Display_employee_list();
        cout << "Enter the username you want to remove: ";
        cin.getline(targetName, 100);

        file.clear();
        file.seekg(0, ios::beg);

        while (file >> name >> password) {
            if (!compareStrings(name, targetName)) {
                tempFile << name << " " << password << endl;
            } else {
                userFound = true;
            }
        }
    }

    file.close();
    tempFile.close();

    if (userFound) {
        remove("employees.txt");
        rename("temp2.txt", "employees.txt");

        if (choice == 1) {
            cout << "Employee information updated successfully." << endl;
           
        } 
        else if (choice == 2) {
            cout << "New employee added successfully." << endl;
            
        }
        else if (choice == 3) {
            cout << "Employee removed successfully." << endl;
            
        }
    } 
    else {
        remove("temp2.txt");
        cout << "Employee not found." << endl;
    }

    delete[] name;
    delete[] password;
    delete[] targetName;
    delete[] newName;
    delete[] newPassword;

}




void Manage_admins() {
    char* name = new char[100];
    char* password = new char[100];
    char* targetName = new char[100];
    char* newName = new char[100];
    char* newPassword = new char[100];
    bool userFound = false;

    ifstream file("pass_admin.txt");
    int choice;
    Main_Display_admin:
    cout << "\033[1;32m"; // Set text color to green
   cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#    1. Update an existing admin                        #\n"
     << "\t\t\t\t#    2. Add a new admin                                 #\n"
     << "\t\t\t\t#    3. Remove an existing admin                        #\n"
     << "\t\t\t\t#    4. Exit                                            #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";

         cout << "\033[0m"; // Reset color

    cin >> choice;
    cin.ignore();

    if (choice == 4) {
       
        delete[] name;
        delete[] password;
        delete[] targetName;
        delete[] newName;
        delete[] newPassword;
        return;
    }

    ofstream tempFile("temp2.txt");

    if (choice == 1) {
        Display_admin_list();
        cout << "Enter the username you want to update: ";
        cin.getline(targetName, 100);

        file.clear();
        file.seekg(0, ios::beg); 

        while (file >> name >> password) {
            if (compareStrings(name, targetName)) {
                userFound = true;

                cout << "Enter new username: ";
                cin.getline(newName, 100);
                cout << "Enter new password: ";
                cin.getline(newPassword, 100);

                tempFile << newName << " " << newPassword << endl;
            } 
            else {
                tempFile << name << " " << password << endl;
            }
        }
    }
    else if (choice == 2) {
        Display_admin_list();

        char user[30] , pass[30];
        bool same = false;
        do{
            cout << "Enter new username: ";
            cin.getline(newName, 100);
            fstream fl("customers.txt", ios::in);
                while(!fl.eof()){
                    fl>>user>>pass;
                    if(compareStrings(user, newName)){
                        same= true;
                        break;
                    }
                }
                fl.close();
                if(!same){
                    break;
                }
                cout<<"Please select a unique username\n";
        }while(true);
        cout << "Enter new password: ";
        cin.getline(newPassword, 100);

        tempFile << newName << " " << newPassword << endl;
        userFound = true;

        file.clear();
        file.seekg(0, ios::beg);
        while (file >> name >> password) {
            tempFile << name << " " << password << endl;
        }
    }
    else if (choice == 3) { // Remove an admin
        Display_admin_list();
        cout << "Enter the username you want to remove: ";
        cin.getline(targetName, 100);

        file.clear();
        file.seekg(0, ios::beg);

        while (file >> name >> password) {
            if (!compareStrings(name, targetName)) {
                tempFile << name << " " << password << endl;
            } else {
                userFound = true;
            }
        }
    }

    file.close();
    tempFile.close();

    if (userFound) {
        remove("pass_admin.txt");
        rename("temp2.txt", "pass_admin.txt");

        if (choice == 1) {
            cout << "Admin information updated successfully." << endl;
            
        } 
        else if (choice == 2) {
            cout << "New admin added successfully." << endl;
           
        } 
        else if (choice == 3) {
            cout << "Admin removed successfully." << endl;
           
        }
    } 
    else {
        remove("temp2.txt");
        cout << "Admin not found." << endl;
    }

    delete[] name;
    delete[] password;
    delete[] targetName;
    delete[] newName;
    delete[] newPassword;
}









/////////////////////////////////////FOR SALES REPORT OPTION 6////////////////////////////////


int calculateTotalRevenueAndLargestItem(const char* filename, char* largestItem, int& largestRevenue) {
    ifstream file(filename);


    char line[5000];
    int totalRevenue = 0;
    largestRevenue = 0; 

    
    while (file.getline(line, 5000)) {
        char id[10], name[100], priceStr[20], quantityStr[20], category[50];
        int fieldCount = 0;
        int index = 0;

       
        for (int i = 0; line[i] != '\0'; ++i) {
            if (line[i] == '|') {
               
                if (fieldCount == 0) id[index] = '\0';
                else if (fieldCount == 1) name[index] = '\0';
                else if (fieldCount == 2) priceStr[index] = '\0';
                else if (fieldCount == 3) quantityStr[index] = '\0';
                else if (fieldCount == 4) category[index] = '\0';
                
                fieldCount++;
                index = 0; 
            } 
            
            else {
                
                if (fieldCount == 0) id[index++] = line[i];
                else if (fieldCount == 1) name[index++] = line[i];
                else if (fieldCount == 2) priceStr[index++] = line[i];
                else if (fieldCount == 3) quantityStr[index++] = line[i];
                else if (fieldCount == 4) category[index++] = line[i];
            }
        }

       
        if (fieldCount == 2){
             priceStr[index] = '\0';}
        
        else if (fieldCount == 3){
             quantityStr[index] = '\0';}

        
        int price = converttoint(priceStr);
        int quantity = converttoint(quantityStr);

       
        if (price >= 0 && quantity >= 0) {
            int revenue = price * quantity; 
            totalRevenue += revenue;       

           
            if (revenue > largestRevenue) {
                largestRevenue = revenue;
                
                int j = 0;
                for (j = 0; name[j] != '\0'; ++j) {
                    largestItem[j] = name[j];
                }
                largestItem[j] = '\0'; 
            }
        } 
        
        
    }

    file.close();
    return totalRevenue;
}




///////////////////////////////////OPTION2 FOR DISCOUNT AND PROMO CODE//////////////////////////////////////////////////////
void addPromoCode() {
    char* promoCode = new char[50];
    int discountPercentage;

    cout << "Enter the promo code: ";
    cin >> promoCode;
    cout << "Enter the discount percentage: ";
    cin >> discountPercentage;

    if(discountPercentage<=90 && discountPercentage>0){

    ofstream promoFile("promo.txt", ios::app);
    if (promoFile.is_open()) {
        promoFile << promoCode << "|" << discountPercentage << endl;
        promoFile.close();
        cout << "Promo code added successfully!" << endl;
    }}
    else{
        cout<<"Invalid percentage";
    }

    delete[] promoCode;
}






//////////////////////////////////////////////LOG ACITIVITY OPTION5//////////////////

void Log_Activity() {
    const char fileName[] = "activity.txt";
    ifstream inputFile(fileName);

    char* line = new char[256];

    while (inputFile.getline(line, 256)) {
        cout << line << endl;
    }

    inputFile.close();

    delete[] line;
}






/////////////////////SOME BULID IN FUNCTIONS/////////////////////////


// Function to compare two strings case-insensitively 
bool compareStrings(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        char ch1 = str1[i];
        char ch2 = str2[i];

        if (ch1 >= 'A' && ch1 <= 'Z') {
            ch1 = ch1 + ('a' - 'A');
        }
        
        if (ch2 >= 'A' && ch2 <= 'Z') {
            ch2 = ch2 + ('a' - 'A');
        }

        
        if (ch1 != ch2) {
            return false;  
        }
        i++;
    }

    return str1[i] == str2[i];
}


// Function to convert a string to lowercase
void toLowerCase(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
        i++;
    }
}


int converttoint(const char* str) {
    int result = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            return -1;
        }
    }
    return result;
}


// Function to trim leading and trailing spaces from a string
void trim(char* str) {
    int start = 0;
    while (str[start] == ' ' || str[start] == '\t') {  
        start++;
    }

    int end = 0;
    while (str[end] != '\0') {  
        end++;
    }
    end--;  

    while (end >= start && (str[end] == ' ' || str[end] == '\t')) {
        end--;
    }

    int i = 0;
    while (start <= end) {
        str[i++] = str[start++];
    }

    str[i] = '\0'; 
}



int stringtoint(const char* str) {
    int result = 0;
    int sign = 1;
    int start = 0;

    if (str[0] == '-') {
        sign = -1;
        start = 1;
    }

    for (int i = start; str[i] != '\0'; ++i) {
        if (str[i] < '0' || str[i] > '9') {
            return 0; /////Return 0 if invalid character is encountered
        }
        result = result * 10 + (str[i] - '0');
    }

    return sign * result;
}



// Custom strcpy implementation
void customStrcpy(char* destination, const char* source) {
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0'; // Null terminator
}

// Custom strtok implementation
char* customStrtok(char* str, const char* delim) {
    static char* current;
    if (str != nullptr) {
        current = str;
    }

    if (current == nullptr || *current == '\0') {
        return nullptr;
    }

    char* tokenStart = current;

    while (*current != '\0') {
        const char* d = delim;
        while (*d != '\0') {
            if (*current == *d) {
                *current = '\0';
                current++;
                return tokenStart;
            }
            d++;
        }
        current++;
    }

    current = nullptr;
    return tokenStart;
}
 


bool contains(const char* line, const char* substring) {
    int i = 0, j = 0;
    while (line[i] != '\0') {
        if (line[i] == substring[j]) {
            int temp = i;
            while (line[temp] != '\0' && substring[j] != '\0' && line[temp] == substring[j]) {
                temp++;
                j++;
            }
            if (substring[j] == '\0') {
                return true;
            }
            j = 0; 
        }
        i++;
    }
    return false;
}



// Function to copy a substring into a target array
void copySubstring(const char* source, int start, char* target, int length) {
    int i = 0;
    while (source[start] != '\0' && source[start] != '|' && i < length - 1) {
        target[i++] = source[start++];
    }
    target[i] = '\0';
}


// Function to compare two character arrays
bool compare(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}


// Custom strcmp function
bool customStrcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
    }
    return (*str1 == *str2);
}





/////////////////////////////////// AUDIT TRAIL OPTION3///////////////////////////////
void auditTrail(const char* filename) {
    ifstream file(filename);

    

    const int MAX_LINE_LENGTH = 1024; // Maximum length of a line
    char* line = new char[MAX_LINE_LENGTH]; // Dynamically allocate memory for line

    while (file.getline(line, MAX_LINE_LENGTH)) {
        // Print each line read from the file
        cout << line << endl;
    }

    delete[] line; 
    file.close();
}