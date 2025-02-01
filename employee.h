#include"header.h"

void LogFailedLogin(const char* username);///// This is for the log activity of the admin
void display_employee();///display screen
void Display_stock_list();///// IT FOR UPDATE STOCK OPTION1
void logStockUpdate(const char *username, int updateID);/////// This is for admin functionality
void Update_stock(); ///for the 1. functionality to update stock
void updateLowStock();//// IT IS FOR LOW STOCK OPTION3
void read_low_stock();
void updateLowStockFile();
void displayFileContents(const char* filename);// Function to display the contents of the file
int calculateTotalRevenue(const char* filename);// Function to calculate total revenue
void viewRequests();//////////CHECK SUPPORTVMESSAGE OPTION2

