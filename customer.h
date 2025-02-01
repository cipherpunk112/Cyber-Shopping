#include"header.h"


void logFailedLogin(const char* username);////////// ADMIN LOD FUNCTIONALITY
void displayPromos(const char* filename);/////////////////////THIS IS FOR NOTIFIACTIONS OF PROMOCODE
void display_screen_customer();/////////////CUSTOMERS OPTION LIST
void display_according();////////////CHANGE THE LIST BY INTERST
void loadStock(int id[], int stockQuantity[], int price[], char name[][100], char category[][100], int& count);// This will display stock.txt
void displayItems(int id[], int stockQuantity[], int price[], char name[][100], char category[][100], int count);// This will display items
void updateStock(int id[], int stockQuantity[], int price[], char name[][100], char category[][100], int count);// This will update stock in stock.txt
void cartDisplay();// This will cart display
void addItemToCart(int id[], int stockQuantity[], int price[], char name[][100], char category[][100], int count,
                   int cartId[], int cartQuantity[], int& cartCount);// This will add an item to the cart
void removeItemFromCart(int cartId[], int cartQuantity[], int& cartCount);
int applyPromoCode();// This will apply promo code and discount
void finalizePurchase(int cartId[], int cartQuantity[], int cartCount, int id[], int stockQuantity[], int price[],
                      char name[][100], char category[][100], int stockCount);
void cartSystem(int id[], int stockQuantity[], int price[], char name[][100], char category[][100], int count); 
 
void displayPurchases(const char* filename, const char* username, const char* password);// Function to display purchases for a specific user
void submitRequest();////FOR SUPPORT AND HELP OPTION 4
void addFeedback(const char* feedbackFile, const char* username, int itemID);// Function to add feedback to the feedback.txt file

