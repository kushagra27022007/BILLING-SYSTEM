#include <iostream>
using namespace std;
class Restaurant{
private:
int tableStatus[5] = {};

string items[14]={"Pesto pasta","Alfredo pasta","Arrabbiata pasta","Pink sauce pasta",
        "Nutella Shake","Kitkat Shake","Chocolate Shake",
        "Golden Corn pizza","Red Paprika pizza","Cheeseburst pizza",
        "Dim sums","Spring rolls" ,"Hakka Noodles" ,"Fried Rice" };

int prices[14] = {400, 310, 500, 320, 420, 230, 450, 250, 380, 390, 210, 330, 290, 430  };

string chefs[4] = {"Chef Rahul","Chef Aman","Chef Neha","Chef Arjun"};

int chefExperience[4] = {8, 6, 10, 5};

string chefSpecialty[4] = {"Italian & Pasta","Pizza & Fast Food","Chinese Cuisine","Shakes & Desserts"};

string chefFamousFor[4] = {"Alfredo Pasta","Cheeseburst Pizza","Hakka Noodles","Chocolate Shake"};

double chefRating[4] = {4.8, 4.7, 4.9, 4.6};

int quantities[14] = {};

string customization[5] = {"No Onion","No Garlic","No Capsicum","No Green Chilli","No Cheese"};

bool removeIngredient[5] = {};
int selectedChef = -1;

public:
// ================================ SHOW MENU ============================
void showMenu()
{
    cout<<"\n============= RESTAURANT MENU ============"<<endl;
    cout<<"1.  Pesto Pasta       - Rs. 400"<<endl;
    cout<<"2.  Alfredo Pasta     - Rs. 310"<<endl;
    cout<<"3.  Arrabbiata Pasta  - Rs. 500"<<endl;
    cout<<"4.  Pink Sauce Pasta  - Rs. 320"<<endl;
    cout<<"5.  Nutella Shake     - Rs. 420"<<endl;
    cout<<"6.  Kitkat Shake      - Rs. 230"<<endl;
    cout<<"7.  Chocolate Shake   - Rs. 450"<<endl;
    cout<<"8.  Golden Corn Pizza - Rs. 250"<<endl;
    cout<<"9.  Red Paprika Pizza - Rs. 380"<<endl;
    cout<<"10. Cheeseburst Pizza - Rs. 390"<<endl;
    cout<<"11. Dim Sums          - Rs. 210"<<endl;
    cout<<"12. Spring Rolls      - Rs. 330"<<endl;
    cout<<"13. Hakka Noodles     - Rs. 290"<<endl;
    cout<<"14. Fried Rice        - Rs. 430"<<endl;
    cout<<"15. Exit" <<endl;
    cout<<"==========================================="<<endl;
}
// ================================ TABLE STATUS =========================
int table_status(){
    int table;
    cout<<"============== TABLE STATUS ==============="<<endl;
    for (int i=0; i<5; i++)
    {
        if (tableStatus[i] == 0)
            cout<<"Table "<<i + 1<<" - Available"<<endl;
        else
            cout<<"Table "<<i + 1<<" - Occupied"<<endl;
          }
    cout<<"==========================================="<<endl;
    cout<<"Enter table number: ";
    cin>>table;
    if (table>= 1 && table <=5)
    {
        if (tableStatus[table - 1] == 0)
        {
            tableStatus[table - 1] = 1;
            cout<<"Table "<<table<<" booked successfully!"<<endl;
        }
        else
        {
            cout<<"Sorry! Table "<<table<<" is already occupied."<<endl;
            return 0;
        }
    }
    else
    {
        cout<<"Invalid table number!"<<endl;
        return 0;
    }

    cout<<"\n========== UPDATED TABLE STATUS =========="<<endl;

    for (int i = 0; i < 5; i++)
    {
        if (tableStatus[i] == 0)
            cout<<"Table "<<i + 1<<" - Available"<<endl;
        else
            cout<<"Table "<< i + 1<<" - Occupied"<<endl;
    }
    cout<<"==========================================="<<endl;
    return table;
}
// ================================ VIEW CART ===============================
void viewCart()
{
  cout<<"\n================ YOUR CART ================"<<endl;
    bool empty = true;
    int cartTotal = 0;
    for (int i = 0; i < 14; i++)
    { if (quantities[i] > 0)
        { empty = false;
          int amount = prices[i] * quantities[i];
          cout << items[i]<< "\tQty: " << quantities[i]<< "\tAmount: Rs." << amount << endl;
            cartTotal += amount;
        }
    }
    if (empty)
    {
        cout<<"Your cart is empty!" << endl;
    }
    else
    {
        cout << "-------------------------------------------" << endl;
        cout << "Cart Total = Rs." << cartTotal << endl;
    }

    cout << "===========================================" << endl;
}
// =============================== REMOVE ITEM ==============================
void removeItem(){
    int choice;
    cout << "\n========== REMOVE ITEM ==========" << endl;
    cout << "Enter item number to remove: ";
    cin >> choice;
    if (choice >= 1 && choice <= 14)
    {
        if (quantities[choice - 1] > 0)
        {
            quantities[choice - 1] = 0;
            cout << items[choice - 1]<< " removed successfully!" << endl;
        }
        else
        {
            cout << "This item is not in your cart!" << endl;
        }
    }
    else
    {
        cout << "Invalid item number!" << endl;
    }
    for (int i = 0; i < 14; i++)
    {
        if (quantities[i] > 0)
        {
            cout << i + 1 << ". "<< items[i]<< " - Quantity: "<< quantities[i] << endl;
        }
    }
    cout << "=================================" << endl;
}
// ============================== CHOOSE CHEF ==============================
  void chooseChef()
{
    int choice;
    int confirm;
    cout << "\n========== CHOOSE YOUR CHEF ==========" << endl;
    for (int i=0; i<4; i++)
    {
        cout << "\n" << i + 1 << ". " << chefs[i] << endl;
        cout << "   Experience : " << chefExperience[i] << " Years" << endl;
        cout << "   Specialty  : " << chefSpecialty[i] << endl;
        cout << "   Famous For : " << chefFamousFor[i] << endl;
        cout << "   Rating     : " << chefRating[i] << "/5" << endl;
    }
    cout << "\n5. Back" << endl;
    cout << "=======================================" << endl;
    cout << "Choose your Chef: ";
    cin >> choice;

    if (choice >=1 && choice <=4)
    {
        int index = choice - 1;
        cout << "\n=======================================" << endl;
        cout << "You selected " << chefs[index] << " 👩‍🍳" << endl;
        cout << "\nExperience : " << chefExperience[index] << " Years" << endl;
        cout << "Specialty  : " << chefSpecialty[index] << endl;
        cout << "Famous For : " << chefFamousFor[index] << endl;
        cout << "Rating     : " << chefRating[index] << "/5" << endl;

        cout << "\n" << chefs[index] << " recommends:" << endl;

        if (index == 0)
        {
            cout << " Pesto Pasta" << endl;
            cout << " Alfredo Pasta" << endl;
            cout << " Pink Sauce Pasta" << endl;
        }
        else if (index == 1)
        {
            cout << " Golden Corn Pizza" << endl;
            cout << " Red Paprika Pizza" << endl;
            cout << " Cheeseburst Pizza" << endl;
        }
        else if (index == 2)
        {
            cout << " Hakka Noodles" << endl;
            cout << " Spring Rolls" << endl;
            cout << " Fried Rice" << endl;
        }
        else if (index == 3)
        {
            cout << " Nutella Shake" << endl;
            cout << " Kitkat Shake" << endl;
            cout << " Chocolate Shake" << endl;
        }

        cout << "\nDo you want to continue with "<< chefs[index] << "?" << endl;

        cout << "1. Yes" << endl;
        cout << "2. Choose another Chef" << endl;

        cout << "Enter your choice: ";
        cin >> confirm;
        if (confirm == 1)
        {
            cout << "\n" << chefs[index]<< " has been assigned to your order! "<< endl;
        }
        else if (confirm == 2)
        {
            cout << "\nPlease choose another Chef." << endl;
            chooseChef();
        }
        else
        {
            cout << "\nInvalid choice!" << endl;
        }
    }
    else if (choice == 5)
    {
        cout << "\nReturning to Customer Menu..." << endl;
    }
    else
    {
        cout << "\nInvalid Chef choice!" << endl;
    }
}

// ============================== PLACE ORDER ==============================
void place_order(){
   int choice;
   int quantity;
   string more;

    do
      { showMenu();
        cout<<"Enter your choice: ";
        cin>>choice;
        if (choice >= 1 && choice <= 14)
        {
            cout<<"Enter quantity: ";
            cin>>quantity;
            if (quantity > 0)
            {
              quantities[choice - 1] += quantity;
              cout<<items[choice - 1]<<" added successfully!"<<endl;
            }
            else
            {
              cout<<"Invalid quantity!"<<endl;
            }
        }
        else if(choice ==15)
        {
          cout<<"Ordering completed..."<<endl;
          break;
        }
        else
        {
          cout<<"Invalid choice! Please try again."<<endl;
        }
        cout<<"Do you want to order more? (yes/no): ";
        cin>>more;

    } while (more =="yes" || more =="YES");
  }
// ============================== COUTOMIZE ORDER ==============================
void customizeOrder()
{
    int choice;
    cout << "\n========== CUSTOMIZE YOUR ORDER ==========" << endl;
    cout << "\nWhat would you like to remove?" << endl;
    cout << "1. Onion" << endl;
    cout << "2. Garlic" << endl;
    cout << "3. Capsicum" << endl;
    cout << "4. Green Chilli" << endl;
    cout << "5. Cheese" << endl;
    cout << "6. Done" << endl;
    do
    {
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 5)
        {
            removeIngredient[choice - 1] = true;

            cout << "No " ;

            if (choice == 1)
                cout << "Onion";
            else if (choice == 2)
                cout << "Garlic";
            else if (choice == 3)
                cout << "Capsicum";
            else if (choice == 4)
                cout << "Green Chilli";
            else if (choice == 5)
                cout << "Cheese";

            cout << " added to your special request." << endl;
        }
        else if (choice != 6)
        {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    cout << "\n========================================" << endl;
    cout << "       YOUR SPECIAL REQUEST" << endl;
    cout << "========================================" << endl;

    bool anyCustomization = false;

    for (int i = 0; i < 5; i++)
    {
        if (removeIngredient[i])
        {
            cout << "X " << customization[i] << endl;
            anyCustomization = true;
        }
    }

    if (!anyCustomization)
    {
        cout << "No customization selected." << endl;
    }
    cout << "========================================" << endl;
}

//================================= GENERATE BILL ==================================
  void generateBill()
{
    string name;
    string phoneNo;
    string paymentMethod;
    int payment;
    int table;
    int total = 0;
    int discount = 0;

    cout << "\n========== CUSTOMER DETAILS ==========" << endl;
    cout << "Enter Customer Name: ";
    cin >> name;
    cout << "Enter Phone Number: ";
    cin >> phoneNo;
    table = table_status();
    if (table == 0)
    {
        cout << "\nBill cannot be generated!" << endl;
        return;
    }
    cout << "\n========================================" << endl;
    cout << "             RESTAURANT BILL" << endl;
    cout << "========================================" << endl;
    cout << "Customer : " << name << endl;
    cout << "Phone No : " << phoneNo << endl;
    cout << "Table No : " << table << endl;

    if (selectedChef != -1)
    {
      cout << "Chef Assigned : "<< chefs[selectedChef] << endl;
      cout << "Specialty     : "<< chefSpecialty[selectedChef] << endl;
    }
    else
    {
      cout << "Chef Assigned : Not Selected" << endl;
    }
    cout << "----------------------------------------" << endl;
    for (int i = 0; i < 14; i++)
    {
        if (quantities[i] > 0)
        {
          int amount = prices[i] * quantities[i];
          cout << items[i]<< "  x " << quantities[i]<< "    Rs." << amount << endl;
            total += amount;
        }
    }
    if (total >= 1000)
    {
      discount = total * 10 / 100;
    }
    else if (total >= 500)
    {
      discount = total * 5 / 100;
    }
    else
    {
      discount = 0;
    }
    int finalAmount = total - discount;
    cout << "----------------------------------------" << endl;
    cout << "Total          : Rs." << total << endl;
    cout << "Discount       : Rs." << discount << endl;
    cout << "Final Amount   : Rs." << finalAmount << endl;
    cout << "----------------------------------------" << endl;

    cout << "\nSelect Payment Mode:" << endl;
    cout << "1. Cash" << endl;
    cout << "2. UPI" << endl;
    cout << "3. Card" << endl;
    cout << "Enter choice: ";
    int paymentChoice;
    cin >> paymentChoice;
    if (paymentChoice == 1)
    {
       paymentMethod = "Cash";
       cout << "Enter Cash Amount: Rs.";
       cin >> payment;

       if (payment >= finalAmount)
        {
            cout << "Payment Successful!" << endl;
            cout << "Change         : Rs."<< payment - finalAmount << endl;
        }
       else
        {
            cout << "Insufficient Payment!" << endl;
            return;
        }
    }
    else if (paymentChoice == 2)
    {
        paymentMethod = "UPI";
        cout << "UPI Payment Successful!" << endl;
    }
    else if (paymentChoice == 3)
    {
        paymentMethod = "Card";
        cout << "Card Payment Successful!" << endl;
    }
    else
    {
        cout << "Invalid Payment Method!" << endl;
        return;
    }

    cout << "Payment Mode   : "<< paymentMethod << endl;

    cout << "========================================" << endl;
    cout << "        THANK YOU FOR VISITING!" << endl;
    cout << "========================================" << endl;
}
//=============================== MAIN MENU ===================================
void mainMenu()
{
  int option;
  cout<< "*********************************************"<<endl;
  cout<< "        WELCOME TO OUR RESTAURANT"<<endl;
  cout<< "********************************************"<<endl;
    do
    {
      cout<<"\n=============== MAIN MENU ==============="<<endl;
      cout<<"1. Show Restaurant Menu"<<endl;
      cout<<"2. Choose Your Chef"<<endl;
      cout<<"3. Place Order"<<endl;
      cout<<"4. Customize Your Order" << endl;
      cout<<"5. View Cart"<<endl;
      cout<<"6. Remove Item"<<endl;
      cout<<"7. Generate Bill"<<endl;
      cout<<"8. Exit" << endl;
      cout<<"==========================================="<<endl;
      cout<<"Enter your choice: ";
      cin>> option;
      if(option == 1){
        showMenu();
      }
      else if (option == 2){
        chooseChef();
      }
      else if (option == 3){
         place_order();
      } 
      else if (option == 4){
          customizeOrder();
      } 
      else if (option == 5)
      {
          viewCart();
      }
      else if (option == 6){
         removeItem();
      } 
      else if (option == 7){
        generateBill();
      } 
      else if (option == 8){
        cout<<"\nThank you for visiting!"<<endl;
        cout<<"Have a nice day!"<<endl;
        }
      else{
        cout<<"\nInvalid choice! Try again."<<endl;
        }
    }
    while (option != 8);
}
};

int main()
{
  Restaurant r;
  r.mainMenu();
  return 0;
}