#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function Prototypes
void printFoodMenu();
int formatMenu();
bool checkMenu();
void determineChoice();
void askUpdate();
void readFood();
void creatFood();
void deleteFood();

// Global Variables
int formatOpt;

struct Food {

  string name;
  double price;
  double rating;
  string cuisine;
  string description;
};

// Vector of foods which includes - name, price, rating, cuisine and description.
vector<Food> foods = {
  {"Chicken Teriyaki", 14.50, 4.3, "Japanese","grilled chicken with homemade teriyaki sauce on top, serve with rice and soup."},
  {"LaMian", 8.75, 4.0, "Chinese","an aromatic beef soup made with smooth and slightly elastic noodle." },
  {"Biryani ", 8.95, 4.2, "Indian","long-grained rice flovered with exotic spices, and layered with lamb, chicken or veggie with tick gravy."},
  {"Bibimbap", 12.00, 4.1, "Korean","is served as a bowl of warm rice topped with namul and gochujang, soy sauce and fried egg and sliced meat."},
  {"Pho", 10.95, 3.9, "Vietnamese", "traditionally made with beef or chicken broth that is flovered with various spices and topped with various herbs."},
  {"Pad Krapow Moo",9.95, 4.6, "Thailand","ground pork is stir-fried with aromatic ingredients and served over fluffy rice."},
  {"Mohinga", 8.99, 4.1, "Myanmar","chickpea flour and crushed toasted rice, galic, onion, lemongress, banana tree stems, ginger, fish paste, fish sauce in rice broth."},
};

int main() {
  checkMenu();
  determineChoice();
  
    return 0;
}

/* Display the database and ask the user to choose which categories 
   he/she wants to create, read, update, delete or shows the food menu. */
int formatMenu(){
    cout << " -----------------------------------------" << endl;
    cout << "            Asia Foods Database           " << endl;
    cout << " -----------------------------------------" << endl;
    cout << " 1. Create and add a new food."             << endl;
    cout << " 2. Read information about a food."         << endl;
    cout << " 3. Update an existing food."               << endl;
    cout << " 4. Delete an existing food from history."  << endl;
    cout << " 5. Show all foods."                        << endl;
    cout << " 6. Exist."                                 << endl;
    int choice;
    cout << " Please Enter Your Choice (#): " << endl;
    cin >> choice;
    return choice;
}

// Check to see if valid menu options were enterd.
bool checkMenu(){
    int choice = formatMenu();

    while (!(choice > 0 && choice < 7)){
        cout << "Please Try again." << endl;
        choice = formatMenu();
    }
    formatOpt = choice;
    return true;
}

// Determine the user choice and display it.
void determineChoice(){
    switch(formatOpt) {
        case 1: 
        cout << " 1 " << endl;
        creatFood();
        break;
        case 2: 
        cout << " 2 " << endl;
        readFood();
        break;
        case 3: 
        cout << " 3 " << endl;
        askUpdate();
        break;
        case 4: 
        cout << " 4 " << endl;
        deleteFood();
        break;
        case 5: 
        cout << " 5 " << endl;
        printFoodMenu();
        break;
        case 6: 
        cout << " 6 " << endl;
        cout << "Thank you ~ See You Soon !" << endl;
        break;
    }
}

string padFoodName(string name, int maxSize){
    string newName = name;
    int charsLeft = maxSize - name.size();
    for(int i = 0; i < charsLeft; i++){
        newName+= " ";
    }
    return newName;
}

void printFoodMenu(){
    // FIND MAX SIZE
    int s = 0; // number of chars in the longest food name
    for (int i = 0; i < foods.size(); i++) {
        if (foods.at(i).name.size() > s) {
            s = foods.at(i).name.size();
        }
    }

     for (int i= 0; i < foods.size();i++){
        cout << i << " " << "\t" << padFoodName(foods.at(i).name, s) << " \t ";
        cout << "\t" << foods.at(i).price << "\t";
        cout << "\t" << foods.at(i).rating << "\t";
        cout << "\t" << foods.at(i).cuisine << "\t";
        cout << endl;
    }
}

/* Ask the user to enter the food name, price, rating, cuisine and description 
     that he/she wants to creat and display it in the food menu. */
void creatFood(){
   cin.ignore();
   string cname;
   cout << " Enter the food name: " << endl;
   getline(cin,cname);

   double cprice;
   cout << " Enter the price: " << endl;
   cin >> cprice;

   double crating;
   cout << " Enter the rating (1 to 5): " << endl;
   cin >> crating;

   cin.ignore();
   string ccuisine;
   cout << " Enter the country of cuisine: " << endl;
   getline(cin,ccuisine);

   string cdescription;
   cout << " Please write it's description: " << endl;
   getline(cin,cdescription);
   
   /* Push back the new food (name, price, rating, cuisine and description) 
       that the user had entered in to the vector and print it in the food menu.*/
   Food newFood;
   newFood.name = cname;
   newFood.price = cprice;
   newFood.rating = crating;
   newFood.cuisine = ccuisine;
   newFood.description = cdescription;

   foods.push_back(newFood);
   printFoodMenu();
}

/* Ask the user to enter the food name that he/she wants to read more detail from the food menu. */
void readFood(){
    cin.ignore();
    string fname;
    cout << "Enter a food: " ;
    getline(cin,fname);
    bool exist = false; // Check to see if valid food name were enterd.

    for(int i=0; i < foods.size(); i++){
        if (fname == foods.at(i).name){
        exist = true;
        Food f = foods.at(i); 
        cout << f.name << "\t";
        cout << f.price << "\t";
        cout << f.rating << "\t";
        cout << f.cuisine << "\t";
        cout << f.description << endl;
        }
    }
    if (exist == false){
    cout << fname << " does not exist." << endl;
    }
}

/* Ask the user to enter the food name, price, rating, cuisine or description 
     that he/she wants to update and display it in the food menu. */
void askUpdate(){
    printFoodMenu();
    int choice;
    cout << "Which food would you like to update (Enter #):" << endl;
    cin >> choice;

    Food toUpdate = foods.at(choice);

    cout << endl;
    cout << "1. Name"        << endl;
    cout << "2. Price"       << endl;
    cout << "3. Rating"      << endl;
    cout << "4. Cuisine"     << endl;
    cout << "5. Description" << endl;
    int num;
    cout << "Which attribute would you like to change? (Enter #):" << endl;
    cin >> num;
    cout << endl;

    string newName;
    cin.ignore();
    cout << "What is the update?" << endl;
    getline(cin,newName);

    switch(num){
        case 1:
        cout << "1" << endl;
        toUpdate.name = newName;
        break;
        case 2:
        cout << "2" << endl;
        toUpdate.price = stod(newName);
        break;
        case 3:
        cout << "3" << endl;
        toUpdate.rating = stod(newName);
        break;
        case 4:
        cout << "4" << endl;
        toUpdate.cuisine = newName;
        break;
        case 5:
        cout << "5" << endl;
        toUpdate.description = newName;
        break;
    }
    foods.at(choice) = toUpdate;
    printFoodMenu();
 }

/* Ask the user to enter the food name that he/she wants to delete and display it in the food menu. */
void deleteFood(){
printFoodMenu();

int choice;
cout << "Which food do you want to delete?" << endl;
cin >> choice;
char c;
cout << "Are you sure you want to delete?" << foods.at(choice).name << " Y/N " << endl;  
cin >> c;
if ( c == 'Y'){
    foods.erase(foods.begin() + choice);
}
printFoodMenu();
}