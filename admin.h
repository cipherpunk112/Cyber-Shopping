/////////////////////////PROTOTYPES OF THE FUNCTIONS//////////////////////////
#include "header.h"



int generateOTP();//////// This for 2f layer
void Update_stock_in_bulk();/// It for the upate of the stock in bulk
void display_admin();////// This for display the screen
void display_user_role();/////// This is for the display screen of funcunctionalties of the admin
void Display_customer_list();////it will display customer.txt
void Display_employee_list();// It will display employees.txt file
void Display_admin_list(); // It will display pass_admin.txt file
void Manage_customers();////////this is for the customer
void Manage_employees();///////// This is for the employee
void Manage_admins();
int calculateTotalRevenueAndLargestItem(const char* filename, char* largestItem, int& largestRevenue);///// This is to calculate total revenue
void addPromoCode();////// for add the promo code
void Log_Activity();///// for log activity 
void Update_stock(); ///for the 1. functionality to update stock
void updateLowStock();//// IT IS FOR LOW STOCK OPTION3
void read_low_stock();
void updateLowStockFile();
bool compareStrings(const char* str1, const char* str2);// Function to compare two strings case-insensitively 
void toLowerCase(char* str);// Function to convert a string to lowercase
int converttoint(const char* str);
void trim(char* str);// Function to trim leading and trailing spaces from a string
int stringtoint(const char* str);
void customStrcpy(char* destination, const char* source);// Custom strcpy implementation
char* customStrtok(char* str, const char* delim);// Custom strtok implementation
bool contains(const char* line, const char* substring);
void copySubstring(const char* source, int start, char* target, int length);// Function to copy a substring into a target array
bool compare(const char* str1, const char* str2);// Function to compare two character arrays
bool customStrcmp(const char* str1, const char* str2);// Custom strcmp function
void auditTrail(const char* filename);///// For tehe audit trail