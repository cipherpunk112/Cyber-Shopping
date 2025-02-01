#include"header.h"

int main(){
    char role;///for role like admin and customer
    char option1;///for the options of customers
    main_display:
cout << "\033[1;34m"; // Set text color to blue
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#           WELCOME TO CYBER SHOPPING                   #\n"
     << "\t\t\t\t#         *** Assalam-u-Alaikum ***                     #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#  Your one-stop shop for everything you need in the    #\n"
     << "\t\t\t\t#               cyber world!                            #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#              Enter Your Role Below:                   #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#         1. ADMIN                                      #\n"
     << "\t\t\t\t#         2. EMPLOYEE                                   #\n"
     << "\t\t\t\t#         3. CUSTOMER                                   #\n"
     << "\t\t\t\t#         4. GAMES                                      #\n" 
     << "\t\t\t\t#         5. EXIT                                       #\n" 
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";



          cout << "\033[0m"; // Reset color


         cout<<endl;
         cout<<"IDENTIFY HERE WHO U ARE:";
         cin>>role;//for the role which u are         



         if(role>='1' && role<='5'){

 
         
        
        
if(role=='1'){//////////////////////for admin
     char option3;
    
     
//////////////////////////login sysytem  
   { cout << "\033[1;33m"; // Set text color to yellow
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#      YOU HAVE 3 TRIES TO VERIFY AS AN ADMIN!         #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";


      cout << "\033[0m"; // Reset color

    char f_username[50], f_pass[50];
    ifstream file("pass_admin.txt");
    file >> f_username >> f_pass;
    file.close();

    char username[50], pass[50];

    for (int i = 0; i < 3; i++) {/////// This is for generating random otp
        int otp = generateOTP();
        int OTP;
        

        cout << "\033[1;36m"; // Set text color to cyan
        cout << "Username:";
        cin >> username;
        cout << "\033[0m"; // Reset color

         cout << "\033[1;36m"; // Set text color to cyan
            cout << "Password: ";

             

            int passIndex = 0;
            char ch;
            while ((ch = getch()) != '\r') { 
                if (ch == '\b') { 
                    if (passIndex > 0) {
                        passIndex--;
                        cout << "\b \b";
                    }
                } else {
                    pass[passIndex++] = ch; 
                    cout << '*'; 
                }
            }
            pass[passIndex] = '\0'; 
            cout << "\033[0m"; 
            cout<<endl;

            cout << "\033[1;31m"; // Set text color to red
        cout<<"\nPop up:"<<"OTP="<<otp<<endl<<endl;
        cout << "\033[0m"; // Reset color

        cout << "\033[1;36m"; // Set text color to cyan
        cout << "OTP:";
        cin>>OTP;
        cout << "\033[0m"; // Reset color



        if (compareStrings(username, f_username) && compareStrings(pass, f_pass) && otp == OTP) { 

          display_loading_screen();////for the loading screen

 cout << "\033[1;32m"; // Set text color to green
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#             WELCOME BACK, SIR!                       #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";


                  cout << "\033[0m"; // Reset color
           break;
        } 
        
        else {

          if (i<2)
          {   cout << "\033[1;31m"; // Set text color to red
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#     WARNING: WRONG USERNAME OR PASSWORD!             #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";


                  cout << "\033[0m"; // Reset color
                  }
        
    
    else{ cout << "\033[1;31m"; // Set text color to red
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#         FAILED TO VERIFY!                            #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";


         cout << "\033[0m"; // Reset color
         return 0;
         }}}}

          

      main_display_admin:
      display_admin();
     cin>>option3;

     

     if(option3=='1'){//// This is foir the bulk stock update
         Update_stock_in_bulk();///it will update the stock
      goto main_display_admin;
     }
     

     if(option3=='2'){///for discount and promo code 
     addPromoCode();
     goto main_display_admin;
     }


     if(option3=='3'){ /// This is for the audit trail option 3
      char e1;
     const char* filename = "critical.txt"; 

    auditTrail(filename);

    cout<<"\nWhen u want to return just press E:";
            cin>>e1;
            if(e1=='E'||e1=='e'){
               goto main_display_admin;
            }



     }



    if(option3=='4'){////this is for low stock list
          char E1;
            updateLowStock();///this twon function is for updating the stock
            updateLowStockFile();  
            cout<<"\nWhen u want to return just press E:";
            cin>>E1;
            if(E1=='E'||E1=='e'){
               goto main_display_admin;
            }
     }



     if(option3=='5'){
          char E8;
     Log_Activity();

     cout<<"\nWhen u want to return just press E:";
            cin>>E8;
            if(E8=='E'||E8=='e'){
               goto main_display_admin;
            }
     }

     


     if(option3=='6'){////its for sale report
     char E2;
             const char* filename = "cart.txt";
    char largestItem[100];
    int largestRevenue;

    displayFileContents(filename);
    int totalRevenue = calculateTotalRevenueAndLargestItem(filename, largestItem, largestRevenue);

    if (totalRevenue >= 0) {
     cout << "\033[1;32m"; // Set text color to green
        cout << "\nTotal revenue: " << totalRevenue << endl;
        cout << "Item with the largest revenue: " << largestItem << " (" << largestRevenue << ")" << endl;
        cout << "\033[0m"; // Reset color
    }
     else {
           cout << "\033[1;31m"; // Set text color to red
        cout << "An error occurred while calculating the revenue." << endl;
        cout << "\033[0m"; // Reset color
    }
    cout<<"\nWhen u want to return just press E:";
            cin>>E2;
    if(E2=='E'||E2=='e'){
               goto main_display_admin;
            }
     }


    


     if(option3=='7'){////this is for user role management
          char choice1;
          Display_User:
          display_user_role();////display the screen if the edit file
          cin>>choice1;

          if(choice1=='4'){////this is for exit and then go to admin page
               goto main_display_admin;
          }

          if(choice1=='1'){////this is for the customer file
            
             Manage_customers();///its to manage customer file
             goto Display_User;

          }
          
          if(choice1=='2'){////this is for the customer file
            
             Manage_employees();///its to manage customer file
             goto Display_User;
          }

          if(choice1=='3'){////this is for the customer file
            
             Manage_admins();///its to manage customer file
             goto Display_User;
          }


     


     
     if(option3=='8'){///this is for exit
          goto main_display;
     }}

     
     

     


     

}



if(role=='2'){////////////////////////for employee
char option2;
char option3;
    {
    char username[50], pass[50];
    char f_username[50], f_pass[50];
    bool isAuthenticated = false;
     cout << "\033[1;33m"; // Set text color to yellow
cout << "\n";
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#     REMEMBER, YOU HAVE 3 TRIES FOR THE VERIFICATION!  #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";


          cout << "\033[0m"; // Reset color

    for (int i = 0; i < 3; i++) {
     cout << "\033[1;36m"; // Set text color to cyan
        cout << "Username:";
        cin >> username;
        cout << "\033[0m"; // Reset color

         cout << "\033[1;36m"; // Set text color to cyan
            cout << "Password: ";
            int passIndex = 0;
            char ch;
            while ((ch = getch()) != '\r') { 
                if (ch == '\b') { 
                    if (passIndex > 0) {
                        passIndex--;
                        cout << "\b \b";
                    }
                } else {
                    pass[passIndex++] = ch; 
                    cout << '*'; 
                }
            }
            pass[passIndex] = '\0'; 
            cout << "\033[0m"; 
            cout<<endl;

        ifstream file1("employees.txt", ios::in);

        while (file1 >> f_username >> f_pass) {
            if (compareStrings(username, f_username) && compareStrings(pass, f_pass)) {
                isAuthenticated = true;
                break;
            }
        }
        file1.close();

        if (isAuthenticated) {

          display_loading_screen();////for the loading screen
          
 cout << "\033[1;32m"; // Set text color to green
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#       GOOD TO HAVE YOU, SIR! HOW MAY I HELP YOU?     #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";


                 cout << "\033[0m"; // Reset color
            break;
        } 
        
        else {
          if (i<2){
               cout << "\033[1;31m"; // Set text color to red
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#     WARNING: WRONG USERNAME OR PASSWORD!             #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";


                 }
        
    else {
cout << "\033[1;31m"; // Set text color to red
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#         FAILED TO VERIFY!                            #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";


         cout << "\033[0m"; // Reset color

         LogFailedLogin(username);
         return 0;
         }}
}}


     

     main_display_employee:
     display_employee();///for the display of options 
     cin>>option2;

     if(option2>='1' && option2<='5'){


     if(option2=='1'){
      Update_stock();///it will update the stock
      goto main_display_employee;
     }


      if(option2=='2'){
          char E5;
          viewRequests();

          cout<<"\nWhen u want to return just press E:";
            cin>>E5;
            if(E5=='E'||E5=='e'){
               goto main_display_employee;
            }


     }



     if(option2=='3'){////for low stock
          char E1;
            updateLowStock();///this twon function is for updating the stock
            updateLowStockFile();  
            cout<<"\nWhen u want to return just press E:";
            cin>>E1;
            if(E1=='E'||E1=='e'){
               goto main_display_employee;
            }
        
     }


     if(option2=='4'){//////////its for total sales and revenue
     char E6;
     const char* filename = "cart.txt"; 


    cout << "Displaying file contents:\n";
    displayFileContents(filename);

   
    int totalRevenue = calculateTotalRevenue(filename);
    if (totalRevenue >= 0) {
        cout << "\nTotal revenue: " << totalRevenue << endl;
    } 
    
    cout<<"\nWhen u want to return just press E:";
            cin>>E6;
            if(E6=='E'||E6=='e'){
               goto main_display_employee;
            }
    

    
}



     if(option2=='5'){
          goto main_display;
     }

     

     }
    

    else{
     cout<<"Invalid choice!";
      goto main_display_employee;

    } 


     }



if (role=='3'){/////////////////for customer

   {char f_username[50], f_pass[50];
    char username[50], pass[50];
    bool isAuthenticated = false;

    char choice;
   cout << "\033[1;33m"; // Set text color to yellow
cout << "\n"
     << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#                 HELLO SIR                             #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#       DO YOU WANT TO SIGN IN OR LOG IN?               #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#         ENTER 'S' FOR SIGN IN                         #\n"
     << "\t\t\t\t#         ENTER 'L' FOR LOG IN                          #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";



         cout << "\033[0m"; // Reset color to default

    cin >> choice;
    switch (choice) {
         case 's':
        case 'S':
            cout << "\033[1;33m"; // Set text color to yellow
     cout << "\nCreating a New Account\n";
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#         ENTER USERNAME FOR YOUR ACCOUNT:             #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";

cout << "\033[0m"; // Reset color

            cin >> username;

   cout << "\033[1;33m"; // Set text color to yellow
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#         ENTER PASSWORD FOR YOUR ACCOUNT:             #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";

cout << "\033[0m"; // Reset color

            cin >> pass;

            {
                ofstream file("customers.txt", ios::out | ios::app);
                file << username << " ";
                file << pass << endl;
                file.close();
            }
            break;

        case 'l':
        case 'L':
         cout << "\033[1;33m"; // Set text color to yellow
    cout << "\n";
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#     REMEMBER, YOU HAVE 3 TRIES FOR THE VERIFICATION!  #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";


                 cout << "\033[0m"; // Reset color

            for (int i = 0; i < 3; i++) {
               cout << "\033[1;36m"; // Set text color to cyan
                cout << "Username:";
                cin >> username;
                cout << "\033[0m"; // Reset color

          cout << "\033[1;36m"; // Set text color to cyan
            cout << "Password: ";
            int passIndex = 0;
            char ch;
            while ((ch = getch()) != '\r') { 
                if (ch == '\b') { 
                    if (passIndex > 0) {
                        passIndex--;
                        cout << "\b \b";
                    }
                } else {
                    pass[passIndex++] = ch; 
                    cout << '*'; 
                }
            }
            pass[passIndex] = '\0'; 
            cout << "\033[0m"; 
            cout<<endl;


                ifstream file1("customers.txt", ios::in);

                while (file1 >> f_username >> f_pass) {
                    if (compareStrings(username, f_username) && compareStrings(pass, f_pass)) {
                        isAuthenticated = true;
                        break;
                    }
                }
                file1.close();

                if (isAuthenticated) {

                    display_loading_screen();////for the loading screen
cout << "\033[1;32m"; // Set text color to green
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#       GOOD TO HAVE YOU, SIR! HOW MAY I HELP YOU?     #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";


                         cout << "\033[0m"; // Reset color
                    break;
                } 
                
                else if (!(isAuthenticated)) {

                     
                     
                    if(i<2){ cout << "\033[1;31m"; // Set text color to red
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#     WARNING: WRONG USERNAME OR PASSWORD!             #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";


                         cout << "\033[0m"; // Reset color
                         }
                
            else{   cout << "\033[1;31m"; // Set text color to red
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#         FAILED TO VERIFY!                            #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";


                  cout << "\033[0m"; // Reset color

                 logFailedLogin(username);///// This is for log activity
                 return 0;}
                 }
                 }}}
  

cout<<endl;
cout << "\033[1;31m"; // Set text color to red
cout<<"###############\n";
cout<<"Notifications:#\n";/////FOR THE NOTIFICATION

cout << "\033[0m"; // Reset color

 cout << "\033[1;31m"; // Set text color to red
cout<<"###############################################\n";
displayPromos("promo.txt");
cout<<"###############################################\n";
cout << "\033[0m"; // Reset color
cout<<endl;



main_display_customer:
display_screen_customer();///for the display of option
cout<<endl;
cin>>option1;



if(option1=='1'){////for the product list
     char choice;

Display_stock_list();////this is for list of item

display_according();///this is going to dispaly list according to intrest

 int id[100], stockQuantity[100], price[100], count;
    char name[100][100], category[100][100];

   
    
     loadStock(id, stockQuantity, price, name, category, count);
    cartSystem(id, stockQuantity, price, name, category, count);

    cout<<"\nPress E to exit:";
     cin>>choice;
     if(choice=='E'||choice=='e'){
          goto main_display_customer;
     }

}




if(option1=='2'){///this is for purchase history
char E4;
char username[50], password[50];
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    const char* filename = "cart.txt"; 
    displayPurchases(filename, username, password);

    ///////Feedback 
    cout<<"\nThis is for Feedback\n";
    
    const char* feedbackFile = "feedback.txt";
    int itemID;

    cout << "Enter your username: ";
    cin >> username;

    cout << "Enter the Item ID for which you want to add feedback: ";
    cin >> itemID;

    // Add feedback
    cout<<"\nFor Feedback:";
    addFeedback(feedbackFile, username, itemID);


     cout<<"\nPress E to exit:";
     cin>>E4;
     if(E4=='E'||E4=='e'){
          goto main_display_customer;
     }

}

if(option1=='3'){///////////this is for help and support
     submitRequest();
     char E2;
     cout<<"\nPress E to exit:";
     cin>>E2;
     if(E2=='E'||E2=='e'){
          goto main_display_customer;
     } 

}


if(option1=='4'){
     goto main_display;///exit to main display
}



}

if(role=='4'){//// For games

     Play_Games();
       goto main_display;

}


if(role=='5'){////for exit

       exit();

}}


else{
     cout<<"Invalid Choice!";
     goto main_display;

}

  

}


void exit(){
cout << "\033[1;32m"; // Set text color to green
cout << "\t\t\t\t#########################################################\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#                  Have a nice day, Sir!                #\n"
     << "\t\t\t\t#                                                       #\n"
     << "\t\t\t\t#########################################################\n";

cout << "\033[0m"; // Reset color
     return ;

}

void display_loading_screen() {
  cout << "\033[1;34m"; // Set text color to blue
  cout << "#########################################################\n"
         << "#                  Loading, please wait...              #\n"
         << "#########################################################\n";
         cout << "\033[0m"; // Reset color
    Sleep(1000);

     cout << "\033[1;36m"; // Set text color to cyan
    cout << "\n#########################################################\n"
         << "#                      Progress: 25%                    #\n"
         << "#########################################################\n";
         cout << "\033[0m";
    Sleep(1000);

     cout << "\033[1;36m"; // Set text color to cyan
    cout << "\n#########################################################\n"
         << "#                      Progress: 50%                    #\n"
         << "#########################################################\n";
         cout << "\033[0m";
    Sleep(1000);
    
    cout << "\033[1;33m";
    cout << "\n#########################################################\n"
         << "#                      Progress: 75%                    #\n"
         << "#########################################################\n";
         cout << "\033[0m";
    Sleep(1000);

    cout << "\033[1;32m";
    cout << "\n#########################################################\n"
         << "#                      Progress: 100%                   #\n"
         << "#########################################################\n";
         cout << "\033[0m";
    Sleep(1000);
     
    cout << "\033[1;32m"; 
    cout << "\n#########################################################\n"
         << "#                    Loading complete                   #\n"
         << "#########################################################\n";
        cout << "\033[0m"; 
}




















