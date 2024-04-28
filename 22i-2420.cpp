//22I-2420 ASHHAR AMIR NUCES ISB SE-B OOP PROJECT

//LIBRARIES
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <cctype>
#include <ctime>
#include <Windows.h>
#include <cstdlib>
#include <fstream>

using namespace std;

//DEFS
#define MAX_USER 100
#define MAX_PLANES_AT_AIRPORT 10
#define SEATING_CAPACITY_ECONOMY 50
#define SEATING_CAPACITY_BUSINESS 10
#define ADMIN_USERNAME "admin"
#define ADMIN_PASSWORD "admin"



//VALIDATION FUNCTIONS
string validateString(const string& userPrompt) { // Validates a string input
    string input;
    bool isValidInput = false;
    while (!isValidInput) {
        cout << userPrompt;
        getline(cin >> ws, input);
        bool isAllLetters = true;
        for (char c : input) {
            if (!isalpha(c)) {
                isAllLetters = false;
                break;
            }
        }
        if (isAllLetters) {
            isValidInput = true;
        } else {
            cout << "Please enter string characters only!\n";
        }
    }
    return input;
}


bool validateIfAllIntegers(string &input){ // Validates if a string contains all integers
    for(char c: input){
        if(!isdigit(c)){
            return false;
        }
    }
    return true;
}

bool validateIfAllIntegers(int input){ // Validates if an integer contains all integers
    string inpStr = to_string(input);
    for(char c: inpStr){
        if(!isdigit(c)){
            return false;
        }
    }
    return true;
}

struct FlightData{ // Flight data structure
    //list vars
    string departure;
    string destination;
    int date;
    int departureTime;
    int arrivalTime;
    int duration;
    string flightNumber;
    int seatsAvailable;
    bool isInternational;
    bool isRunning;
    double ticketPrice;
    bool isNorthAirport;
    //extra vars
    string seatNumber;
    bool isConfirmed = true;
};

class Airport{ // Airport class
    bool isNorth;
    FlightData flightDataObj[100]; // Flight data object
};

struct AirplaneStruct{ // Airplane structure
    int planeID;
    string planeTitle;
    int localFlightCount;
    int internationalFlightCount;
    int totalFlightTime;
    int totalSeats;
    //
    FlightData currentFlight[35]; // Current flight object
    int planeFlightCount = 0;

    bool isInternational = false;
    void addFlight(FlightData *flightObj){ // Adds a flight to the current flight object
        if(planeFlightCount == 0){
            if(flightObj[planeFlightCount].isInternational){
                isInternational = true;
        }
        if(isInternational){ // If the flight is international
            if(flightObj[planeFlightCount].isInternational){
                if(flightObj[planeFlightCount - 1].date == flightObj[planeFlightCount].date){
                    if(flightObj[planeFlightCount - 1].arrivalTime + 2 < flightObj[planeFlightCount].departureTime){
                        currentFlight[planeFlightCount++] = flightObj[planeFlightCount];
                    }else{
                        cout << "\nFlight cannot be added!\n";
                    }
        }else{ // If no conflicts
            currentFlight[planeFlightCount++] = flightObj[planeFlightCount];
        }
            }else{
                cout << "A plane can either travel locally or internationally!\n";
            }
        }else if(!isInternational){ // If the flight is local
            if(!(flightObj[planeFlightCount].isInternational)){
                if(flightObj[planeFlightCount - 1].date == flightObj[planeFlightCount].date){
                    if(flightObj[planeFlightCount - 1].arrivalTime + 2 < flightObj[planeFlightCount].departureTime){
                        currentFlight[planeFlightCount++] = flightObj[planeFlightCount];
                    }else{
                        cout << "\nFlight cannot be added!\n";
                    }
        }else{ // If no conflicts
            currentFlight[planeFlightCount++] = flightObj[planeFlightCount];
        }
        }else{
                cout << "A plane can either travel locally or internationally!\n";
            }
        }
        }
    }
    void displayAircraftFlights(){ // Displays the current flight object
        cout << "+-------------------------------------+\n";
        cout << "Flights for plane " << planeID  << " " << planeTitle << endl;
        for(int i = 0; i < planeFlightCount; i++){
            cout << "Flight # " << i + 1 << endl;
            cout << "Departure: " << currentFlight[i].departure << endl;
            cout << "Destination: " << currentFlight[i].destination << endl;
            cout << "Date: " << currentFlight[i].date << endl;
            cout << "Departure Time: " << currentFlight[i].departureTime << endl;
            cout << "Arrival Time: " << currentFlight[i].arrivalTime << endl;
            cout << "Duration: " << currentFlight[i].duration << endl;
            cout << "Flight Number: " << currentFlight[i].flightNumber << endl;
            cout << "Seats Available: " << currentFlight[i].seatsAvailable << endl;
            cout << "Is International: " << currentFlight[i].isInternational << endl;
            cout << "Is Running: " << currentFlight[i].isRunning << endl;
            cout << "Ticket Price: " << currentFlight[i].ticketPrice << endl;
            cout << "+-------------------------------------+\n";
            cout << endl;
            
        }
    }
    
};


class Flight{
    private:
    int flightsCount;
    FlightData flightDataObj[100]; // Flight data object
    AirplaneStruct airplaneObj[35]; // Airplane object
    public:
    Flight(){
        flightsCount = 0;
    }
    Flight(int flightsCount){
        this->flightsCount = flightsCount; 
    }
    //adding the flights to the structure using the addFlight function
    void addFlight(string departure, string destination, int date, int departureTime, int arrivalTime, int duration, string flightNumber, int seatsAvailable, bool isInternational, bool isRunning, double ticketPrice, string planeName, int planeID, bool isNorth){
        flightDataObj[flightsCount++] = {departure, destination, date, departureTime, arrivalTime, duration, flightNumber, seatsAvailable, isInternational, isRunning, ticketPrice, isNorth};

        airplaneObj[planeID].planeID = planeID;
        airplaneObj[planeID].planeTitle = planeName;
        airplaneObj[planeID].addFlight(flightDataObj);
        //airplaneObj[planeID].displayAircraftFlights();

    }
    void displayPlaneFlights(int planeID){ // Displays the flights of a plane
        airplaneObj[planeID].displayAircraftFlights();
    }
    void displayFlights() { // Displays all flights
    cout << "+---------------------------------------------------------+\n";
    cout << "|                  List of all flights                    |\n";
    cout << "+---------------------------------------------------------+\n";

    for (int i = 0; i < flightsCount; i++) {
        cout << "Flight " << i + 1 << ":\n";
        cout << "+-----------------------------------------------------------------------------+\n";
        cout << "Departure: " << flightDataObj[i].departure << "\n";
        cout << "Airport: " << (flightDataObj[i].isNorthAirport ? "North" : "South") << "\n";
        cout << "Destination: " << flightDataObj[i].destination << "\n";
        cout << "Departure Time: " << flightDataObj[i].departureTime << ":00\n";
        cout << "Arrival Time: " << flightDataObj[i].arrivalTime << ":00\n";
        cout << "Duration: " << flightDataObj[i].duration << " hrs\n";
        cout << "Flight Number: " << flightDataObj[i].flightNumber << "\n";
        cout << "Seats Available: " << flightDataObj[i].seatsAvailable << "\n";
        cout << "Is International: " << flightDataObj[i].isInternational << "\n";
        cout << "Ticket Price: PKR" << flightDataObj[i].ticketPrice << "\n";
        cout << "Date: " << flightDataObj[i].date << "\n";
        cout << "+-----------------------------------------------------------------------------+\n";
        cout << endl;
    }
}

    bool getIsRunning(string FN){ // Gets if a flight is running
        for(int i = 0; i < flightsCount; i++){
            if(flightDataObj[i].flightNumber == FN){
                return flightDataObj[i].isRunning;
            }
        }
        return false;
    }
    string getDeparture(string FN){ // Gets the departure of a flight
        for(int i = 0; i < flightsCount; i++){
            if(flightDataObj[i].flightNumber == FN){
                return flightDataObj[i].departure;
            }
        }
    }
    string getDestination(string FN){ // Gets the destination of a flight
        for(int i = 0; i < flightsCount; i++){
            if(flightDataObj[i].flightNumber == FN){
                return flightDataObj[i].destination;
            }
        }
    }
    int getDepartureTime(string FN){ // Gets the departure time of a flight
        for(int i = 0; i < flightsCount; i++){
            if(flightDataObj[i].flightNumber == FN){
                return flightDataObj[i].departureTime;
            }
        }
    }
    int getArrivalTime(string FN){ // Gets the arrival time of a flight
        for(int i = 0; i < flightsCount; i++){
            if(flightDataObj[i].flightNumber == FN){
                return flightDataObj[i].arrivalTime;
            }
        }
    }
    int getDuration(string FN){ // Gets the duration of a flight
        for(int i = 0; i < flightsCount; i++){
            if(flightDataObj[i].flightNumber == FN){
                return flightDataObj[i].duration;
            }
        }
    }
    int getSeatsAvailable(string FN){ // Gets the seats available of a flight
        for(int i = 0; i < flightsCount; i++){
            if(flightDataObj[i].flightNumber == FN){
                return flightDataObj[i].seatsAvailable;
            }
        }
        return 0;
    }
    int getIsInternational(string FN){ // Gets if a flight is international
        for(int i = 0; i < flightsCount; i++){
            if(flightDataObj[i].flightNumber == FN){
                return flightDataObj[i].isInternational;
            }
        }
        return false;
    }
    void haltFlight(string FN){ // Halts a flight
        for(int i = 0; i < flightsCount; i++){
            if(flightDataObj[i].flightNumber == FN){
                flightDataObj[i].isRunning = false;
            }
        }
    }
    void resumeFlight(string FN){ // Resumes a flight
        for(int i = 0; i < flightsCount; i++){
            if(flightDataObj[i].flightNumber == FN){
                flightDataObj[i].isRunning = true;
            }
        }
    }
    void deleteFlight(string FN){ // Deletes a flight
        for(int i = 0; i < flightsCount; i++){
            if(flightDataObj[i].flightNumber == FN){
                //sets the vals to NULL
                flightDataObj[i].arrivalTime = 0;
                flightDataObj[i].departureTime = 0;
                flightDataObj[i].departure = "";
                flightDataObj[i].destination = "";
                flightDataObj[i].duration = 0;
                flightDataObj[i].flightNumber = "";
                flightDataObj[i].isInternational = false;
                flightDataObj[i].isRunning = false;
                //flightDataObj[i].seatsAvailable = 0;
                flightDataObj[i].ticketPrice = 0;
                flightDataObj[i].isNorthAirport = false;
                flightsCount--;
            }
        }
    }
    int getDate(string FN){ // Gets the date of a flight
        for(int i = 0; i < flightsCount; i++){
            if(flightDataObj[i].flightNumber == FN){
                return flightDataObj[i].date;
            }
        }
    }
    int getFlightCount(){ // Gets the flight count
        return flightsCount;
    }
    string searchFlight(string destination, string departure, int date){ // Searches for a flight
        for(int i = 0; i < flightsCount; i++){
            if(flightDataObj[i].destination == destination && flightDataObj[i].departure == departure && flightDataObj[i].date == date){
                return flightDataObj[i].flightNumber;
            }
        }
        return "NOT FOUND";
    }
    void updateSeats(string FN, int seats){ // Updates the seats of a flight
        for(int i = 0; i < flightsCount; i++){
            if(flightDataObj[i].flightNumber == FN){
                flightDataObj[i].seatsAvailable = seats;
            }
        }
    }
    
    double getTicketPrice(string FN){ // Gets the ticket price of a flight
        for(int i = 0; i < flightsCount; i++){ 
            if(flightDataObj[i].flightNumber == FN){
                return flightDataObj[i].ticketPrice;
            }
        }
        return 0;
    }

    void displayFlightInfo(string FN) { // Displays the flight info of a flight
    for (int i = 0; i < flightsCount; i++) {
        if (flightDataObj[i].flightNumber == FN) {
            cout << "Flight " << i + 1 << ":\n";
        cout << "+-----------------------------------------------------------------------------+\n";
        cout << "Departure: " << flightDataObj[i].departure << "\n";
        cout << "Airport: " << (flightDataObj[i].isNorthAirport ? "North" : "South") << "\n";
        cout << "Destination: " << flightDataObj[i].destination << "\n";
        cout << "Departure Time: " << flightDataObj[i].departureTime << ":00\n";
        cout << "Arrival Time: " << flightDataObj[i].arrivalTime << ":00\n";
        cout << "Duration: " << flightDataObj[i].duration << " hrs\n";
        cout << "Flight Number: " << flightDataObj[i].flightNumber << "\n";
        cout << "Seats Available: " << flightDataObj[i].seatsAvailable << "\n";
        cout << "Is International: " << flightDataObj[i].isInternational << "\n";
        cout << "Ticket Price: PKR" << flightDataObj[i].ticketPrice << "\n";
        cout << "Date: " << flightDataObj[i].date << "\n";
        cout << "+-----------------------------------------------------------------------------+\n";
        cout << endl;
        }
    }
}

};


struct user{ // User structure
    string username;
    string password;
    string cnic;
    int age;
    string contactNumber;
    Flight flights[10]; // Flight object
    int flightCount = 0;
    //loginReg loginRegObj;
    FlightData flightDataObj;
    string passportNumber;
    bool isVisa;
    string cardNumber;
    string cvv;
    string expiryDate;
    string expiryMonth;
    long balance = 500000; // Balance
};

int globalUserIndex = 0; // Global user index for adding flights

//function for displaying * stars in place of password
string takePassword(){
    string firstPassInput = "";
        char inputChar;
        while(true){
            inputChar = getch(); //gets the char (_getch())
            if(inputChar < 32){
                cout << endl;
                return firstPassInput;
            }
            cout << "*";
            firstPassInput.push_back(inputChar); //pushes the char to the string
        }
}

class loginReg{
    private:
    //Flight *flightObj;
    int globalCount;
    public:
    loginReg(){}
    loginReg(int globalCount){
        this->globalCount = globalCount;
    }
    void addUser(user* &usersObj, int &userCount){ // Adds a user
    //taking pointer reference of the usersObj and userCount because we want to change the values of the original variables
        user newUser; bool isValidInput = false;
        while(!isValidInput){ // Validating the CNIC and asking again if incorrect
            cout << "+-------------------------------------+\n";
            cout << "Input the CNIC: \n";
            cout << "+-------------------------------------+\n";
            getline(cin, newUser.cnic);
            if(!validateIfAllIntegers(newUser.cnic) || newUser.cnic.length() != 13){
                cout << "Invalid CNIC, make sure you're entering 13 numerical digits!\n";
            }else{
                isValidInput = true;
            }
        }
        for(int i = 0; i < userCount; i++){ // Checking if the user already exists
            if(usersObj[i].cnic == newUser.cnic){
                cout << "User already exists!\n";
                return;
            }
        }
        //cout << "Input the username: \n";
        cout << "+-------------------------------------+\n";
        newUser.username = validateString("Input your username: ");
        cout << "+-------------------------------------+\n";
       //getline(cin, newUser.username);
        for(int i = 0; i < userCount; i++){
            if(usersObj[i].username == newUser.username){
                cout << "Username already exists!\n";
                return;
            }
        }
        cout << "+-------------------------------------+\n";
        cout << "Input the password: \n";
        cout << "+-------------------------------------+\n";
        string passA = takePassword();
        newUser.password = passA;
        bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecialChar = false; // Checking if the password has an uppercase, lowercase, digit and a special character
        for(int i = 0; i < newUser.password.length(); i++){
            if(isupper(newUser.password[i])){
                hasUpper = true;
            }else if(islower(newUser.password[i])){
                hasLower = true;
            }else if(isdigit(newUser.password[i])){
                hasDigit = true;
            }else if(!isspace(newUser.password[i])){
                hasSpecialChar = true;
            }
        }
        if(!hasUpper || !hasLower || !hasDigit || !hasSpecialChar){ // If not, return
            cout << "Password must contain at least one uppercase, lowercase, digit and a special character!\n";
            return;
        }
        cout << "+-------------------------------------+\n";
        cout << "Input the password again: \n";
        cout << "+-------------------------------------+\n";
        string confirmPassword;
        confirmPassword = takePassword();
        if(newUser.password != confirmPassword){
            cout << "Passwords do not match!\n";
            return;
        }
        if(newUser.password.length() < 8){ // Checking if the password is at least 8 characters long
            cout << "Password must be at least 8 characters long!\n";
            return;
        }
        newUser.password = passA;
        cout << "+-------------------------------------+\n";
        cout << "Input the age: \n";
        cout << "+-------------------------------------+\n";
        cin >> newUser.age;
        if(newUser.age < 18){
            cout << "Adding as a dependant!\n";
        }
        isValidInput = false;
        while(!isValidInput){ // Validating the passport number and asking again if incorrect
            cout << "+-------------------------------------+\n";
            cout << "Input your 10 digit contact number: \n";
            cout << "+-------------------------------------+\n";
            cin >> newUser.contactNumber;
            if(!validateIfAllIntegers(newUser.contactNumber) || newUser.contactNumber.length() != 10){
                cout << "Invalid number, make sure you're entering 10 numerical digits!\n";
            }else{
                isValidInput = true;
            }
        }
        cout << "+-------------------------------------+\n";
        cout << "Do you have a valid passport & visa? (Y/N)\n";
        cout << "+-------------------------------------+\n";
        char choice;
        cin >> choice;
        if(choice == 'Y' || choice == 'y'){
            newUser.isVisa = true;
        }       
        isValidInput = false;
        while(!isValidInput){ // Validating the passport number and asking again if incorrect
            cout << "+-------------------------------------+\n";
            cout << "Input your card number (16 digits): \n";
            cout << "+-------------------------------------+\n";
            cin >> newUser.cardNumber;
            if(!validateIfAllIntegers(newUser.cardNumber) || newUser.cardNumber.length() != 16){
                cout << "Invalid Card Number, make sure you're entering all 16 numerical digits!\n";
            }else{
                isValidInput = true;
            }
        }
        isValidInput = false;
        while(!isValidInput){ // Validating the CVV and asking again if incorrect
            cout << "+-------------------------------------+\n";
            cout << "Input your CVV: \n";
            cout << "+-------------------------------------+\n";
            cin >> newUser.cvv;
            if(!validateIfAllIntegers(newUser.cvv) || newUser.cvv.length() != 3){
                cout << "Invalid CVV!\n";
            }else{
                isValidInput = true;
            }
        }
        isValidInput = false;
        while(!isValidInput){ // Validating the expiry date and asking again if incorrect
            cout << "+-------------------------------------+\n";
            cout << "Input your card expiry date: \n";
            cout << "+-------------------------------------+\n";
            cin >> newUser.expiryDate;
            if(!validateIfAllIntegers(newUser.expiryDate) || stoi(newUser.expiryDate) > 31 || stoi(newUser.expiryDate) < 1){
                cout << "Invalid expiry date!\n";
            }else{
                isValidInput = true;
            }
        }
        isValidInput = false;
        while(!isValidInput){ // Validating the expiry month and asking again if incorrect
            cout << "+-------------------------------------+\n";
            cout << "Input your card expiry month: \n";
            cout << "+-------------------------------------+\n";
            cin >> newUser.expiryMonth;
            if(!validateIfAllIntegers(newUser.expiryMonth) || stoi(newUser.expiryMonth) > 12 || stoi(newUser.expiryMonth) < 1){
                cout << "Invalid expiry month!\n";
            }else{
                isValidInput = true;
            }
        }
        user *newUserArray = new user[userCount + 1]; // Creating a new user array
        for(int i = 0; i < userCount; i++){ // Copying the old user array to the new one
            newUserArray[i] = usersObj[i];
        }
        newUserArray[userCount] = newUser; // Adding the new user to the new user array
        userCount++; // Incrementing the user count
        delete[] usersObj;
        usersObj = newUserArray;
        cout << "User added successfully!\n";
        cout << "+-------------------------------------+\n";
        cout << "Your balance is: " << newUser.balance << endl;
        cout << "Payment Method Approved!\n";
        cout << "+-------------------------------------+\n";
        Sleep(2000);
    }
    bool isLoggedin; 
    bool loginUser(string username, string password, int &userCount, user* &usersObj){ // Logs in a user
        for(int i = 0; i < userCount; i++){
            if((usersObj[i].username == username && usersObj[i].password == password)){
                cout << "Login successful!\n";
                cout << "Welcome " << usersObj[i].username << "!\n";
                isLoggedin = true;
                globalUserIndex = i;
                return true;
            }
        }
        return false;
        isLoggedin = false;
        cout << "Invalid username or password!\n";
    }
    void logoutUser(){
        isLoggedin = false;
        cout << "Logged out successfully!\n";
    }

    void userProfile(user* &usersObj, int &userCount, int userID){ // Displays the user profile
        cout << "+-------------------------------------+\n";
        cout << "Username: " << usersObj[userID].username << endl;
        cout << "CNIC: " << usersObj[userID].cnic << endl;
        cout << "Age: " << usersObj[userID].age << endl;
        cout << "Contact Number: " << usersObj[userID].contactNumber << endl;
        cout << "Passport Number: " << usersObj[userID].passportNumber << endl;
        cout << "Visa Status: " << usersObj[userID].isVisa << endl;
        cout << "+-------------------------------------+\n";
        cout << endl << endl;
        cout << "1. Edit Username\n";
        cout << "2. Edit Password\n";
        cout << "3. Go Back\n";
        int choice;
        cin >> choice;
        string passA, confirmPassword;
        switch(choice){
            case 1:
                cout << "Enter new username: \n";
                cin >> usersObj[userID].username;
                cout << "Username changed successfully!\n";
                break;
            case 2:
                cout << "Input the password: \n";
                passA = takePassword();
                usersObj[userID].password = passA;
                bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecialChar = false;
                for(int i = 0; i < usersObj[userID].password.length(); i++){
                    if(isupper(usersObj[userID].password[i])){
                        hasUpper = true;
                    }else if(islower(usersObj[userID].password[i])){
                        hasLower = true;
                    }else if(isdigit(usersObj[userID].password[i])){
                        hasDigit = true;
                    }else if(!isspace(usersObj[userID].password[i])){
                        hasSpecialChar = true;
                    }
                }
                if(!hasUpper || !hasLower || !hasDigit || !hasSpecialChar){
                    cout << "Password must contain at least one uppercase, lowercase, digit and a special character!\n";
                    return;
                }
                cout << "Input the password again: \n";
                confirmPassword = takePassword();
                if(usersObj[userID].password != confirmPassword){
                    cout << "Passwords do not match!\n";
                    return;
                }
                if(usersObj[userID].password.length() < 8){
                    cout << "Password must be at least 8 characters long!\n";
                    return;
                }
                usersObj[userID].password = passA;
                cout << "Password changed successfully!\n";
                    break;
            // case 3:
            //     return;
        }
    }
    
    
    void bookFlight(user* &usersObj, int &userCount, Flight* &flightObj, int userID){ // Books a flight
        string userDest, userDept;
        
        int userDate;
        cout << "Available places of departure: \n";
        cout << "+-------------------------------------+\n";
        cout << "1. Karachi\n";
        cout << "2. Lahore\n";
        cout << "3. Islamabad\n";
        cout << "4. Peshawar\n";
        cout << "5. Quetta\n";
        cout << endl;
        int deptChoice;
        bool isValidInput = false;
        while(!isValidInput){
        cout << "+-------------------------------------+\n";
        cout << "Input a selection to enter a place of departure: \n";
        cout << "+-------------------------------------+\n";  
            cin >> deptChoice;
            if(!validateIfAllIntegers(deptChoice) || deptChoice > 5 || deptChoice < 1){
                cout << "Invalid entry!\n";
            }else{
                isValidInput = true;
            }
        }
        switch (deptChoice)
        {
        case 1:
            userDept = "Karachi";
            break;
        case 2:
            userDept = "Lahore";
            break;
        case 3:
            userDept = "Islamabad";
            break;  
        case 4:
            userDept = "Peshawar";
            break;  
        case 5:
            userDept = "Quetta";
            break;
        default:
            break;
        }
        cout << "Available destinations: \n";
        cout << "+-------------------------------------+\n";
        cout << "1. London\n";
        cout << "2. Paris\n";
        cout << "3. New York\n";
        cout << "4. Jeddah\n";
        cout << "5. Tokyo\n";
        cout << "6. Sydney\n";
        cout << "7. Cairo\n";
        cout << "8. Singapore\n";
        cout << "9. Istanbul\n";
        cout << "10. Amsterdam\n";
        cout << "11. Riyadh\n";
        cout << "12. Dubai\n";
        cout << "13. Kuala Lumpur\n";
        cout << "14. Buenos Aires\n";
        cout << "15. Toronto\n";
        cout << "16. Karachi\n";
        cout << "17. Lahore\n";
        cout << "18. Islamabad\n";
        cout << "19. Peshawar\n";
        cout << "20. Quetta\n";
        isValidInput = false;
        int destChoice;
        while(!isValidInput){
            cout << "+-------------------------------------+\n";
            cout << "Input a selection to enter a destination: \n";
            cout << "+-------------------------------------+\n";    
            cin >> destChoice;
            if(!validateIfAllIntegers(destChoice) || destChoice > 20 || destChoice < 1){
                cout << "Invalid entry!\n";
            }else{
                isValidInput = true;
            }
        }
        switch (destChoice)
        {
        case 1:
            userDest = "London";
            break;
        case 2:
            userDest = "Paris";
            break;
        case 3:
            userDest = "New York";
            break;
        case 4:
            userDest = "Jeddah";
            break;
        case 5:
            userDest = "Tokyo";
            break;
        case 6:
            userDest = "Sydney";
            break;
        case 7:
            userDest = "Cairo";
            break;
        case 8:
            userDest = "Singapore";
            break;
        case 9:
            userDest = "Istanbul";
            break;
        case 10:
            userDest = "Amsterdam";
            break;
        case 11:
            userDest = "Riyadh";
            break;
        case 12:
            userDest = "Dubai";
            break;
        case 13:
            userDest = "Kuala Lumpur";
            break;
        case 14:
            userDest = "Buenos Aires";
            break;
        case 15:
            userDest = "Toronto";
            break;
        case 16:
            userDest = "Karachi";
            break;
        case 17:
            userDest = "Lahore";
            break;
        case 18:
            userDest = "Islamabad";
            break;
        case 19:
            userDest = "Peshawar";
            break;
        case 20:
            userDest = "Quetta";
            break;
        default:
            cout << "Invalid selection. Please try again.\n";
        break;
        }
        cout << "+-------------------------------------+\n";
        cout << "Enter the date of departure: \n";
        cout << "+-------------------------------------+\n";
        cin >> userDate;
        string targetFN = "";
        targetFN = flightObj->searchFlight(userDest, userDept, userDate);
        if(targetFN == "NOT FOUND"){
            cout << "No flights found!\n";
            return;
        }else{
            cout << "Search Results: " << targetFN << endl;
            flightObj->displayFlightInfo(targetFN);
            cout << "Do you want to book this flight? (Y/N)\n";
            char choice;
            cin >> choice;
            if(choice == 'Y' || choice == 'y'){
                    if(0 == flightObj->getSeatsAvailable(targetFN)){
                    cout << "No seats available!\n";
                    return;
                    }
                    if(!(usersObj->isVisa) && flightObj->getIsInternational(targetFN)){
                        cout << "You need a visa to book this flight!\n";
                        return;
                    }
                    if(flightObj->getIsRunning(targetFN) == false){
                        cout << "Flight is not running due to COVID protocols!\n";
                        return;
                    }
                    // double ticketPrice = flightObj->getTicketPrice(targetFN);
                    
                    if(usersObj[userID].balance - flightObj->getTicketPrice(targetFN) < 0){
                        cout << "Insufficient balance!\n";
                        cout << "User balance: " << usersObj[userID].balance << endl;
                        cout << "Flight price: " << flightObj->getTicketPrice(targetFN) << endl;
                        return;
                    }else{
                        
                        double totalAmount = flightObj->getTicketPrice(targetFN);
                        if(flightObj->getIsInternational(targetFN)){
                            //10% tax
                            totalAmount += totalAmount * 0.1;
                        }else{
                            //5% tax
                            totalAmount += totalAmount * 0.05;
                        }
                        usersObj[userID].balance -= totalAmount;
                        cout << "-------------------------------------------------" << endl;
                        cout << "Payment successful!\n";
                        cout << "Billed PKR" << totalAmount << endl;
                        cout << "-------------------------------------------------" << endl;
                        cout << "Flight charges: PKR" << flightObj->getTicketPrice(targetFN) << endl;
                        cout << "Tax: PKR" << totalAmount - flightObj->getTicketPrice(targetFN) << endl;
                        cout << "-------------------------------------------------" << endl;
                    }


                    flightObj->updateSeats(targetFN, flightObj->getSeatsAvailable(targetFN) - 1); // Updating the seats of the flight
                    const int ROWS = 10;
                    const int COLUMNS = 6;
                    char seats[ROWS][COLUMNS];

                    for (int i = 0; i < ROWS; i++) {
                        for (int j = 0; j < COLUMNS; j++) {
                            seats[i][j] = 'O';
                        }
                    }

                for(int i = 0; i < 1; i++){
                    // Display seat map
                    cout << "+------------------------------------------------------------------+\n";
                    cout << "Please select your seat from the following available options:" << endl;
                    cout << "    A B C D E F" << endl;
                    for (int i = 0; i < ROWS; i++) {
                        cout << setw(2) << i + 1 << "  ";
                        for (int j = 0; j < COLUMNS; j++) {
                            cout << seats[i][j] << " ";
                        }
                        cout << endl;
                    }

                    // Prompt user to select a seat
                    seatSelection:
                    int rowSelection;
                    char columnSelection;
                    cout << "Enter the column number of the seat you would like to select (1-10): ";
                    cout << "+------------------------------------------------------------------+\n";
                    cin >> rowSelection;
                    cout << "Enter the row letter of the seat you would like to select (A-F): ";
                    cout << "+------------------------------------------------------------------+\n";
                    cin >> columnSelection;

                    // Convert column letter to index
                    int columnSelectionIndex = columnSelection - 'A';

                    // Check if seat is available
                    if (seats[rowSelection-1][columnSelectionIndex] == 'X') {
                        cout << "Sorry, that seat is already taken. Please select another seat." << endl;
                        goto seatSelection;
                    } else {
                        seats[rowSelection-1][columnSelectionIndex] = 'X';
                        cout << "Seat has been reserved! Here is the updated seat map:" << endl;
                        cout << "+------------------------------------------------------------------+\n";
                        usersObj[userID].flightDataObj.seatNumber = to_string(rowSelection) + columnSelection;
                        cout << "    A B C   D E F" << endl;
                        for (int i = 0; i < ROWS; i++) {
                            cout << setw(2) << i + 1 << "  ";
                            for (int j = 0; j < COLUMNS; j++) {
                                cout << seats[i][j] << " ";
                            }
                            cout << endl;
                        }
                    }
                } 
                    usersObj[userID].flightDataObj.departure = userDept; // Updating the flight data of the user
                    usersObj[userID].flightDataObj.destination = userDest; 
                    usersObj[userID].flightDataObj.flightNumber = targetFN;  
                    cout << endl;
                    cout << "+-----------------------------+\n";
                    cout << "Flight booked successfully!\n";
                    cout << "+-----------------------------+\n";
                    cout << endl;
                    cout << "+--------------------------------------------------------------------------------+\n";
                    cout << "                User #" << userID + 1 << " flight data                   \n";
                    cout << "+-------------------------------------------------------------------------------+\n";
                    cout << "   Passenger Info                                     \n";
                    cout << "+-------------------+----------------------------------+------------------------+\n";
                    cout << "  Username:          " << usersObj[userID].username << "\n";
                    cout << "  Contact:           " << usersObj[userID].contactNumber << "\n";
                    cout << "  CNIC:              " << usersObj[userID].cnic << "\n";
                    cout << "+-------------------+----------------------------------+------------------------+\n";
                    cout << "   Flight Itinerary:                                                 \n";
                    cout << "+-----------------------------------+----------------------------------+\n";
                    cout << "  Departure:          " << usersObj[userID].flightDataObj.departure << "\n";
                    cout << "  Airport:            " << (usersObj[userID].flightDataObj.isNorthAirport ? "North" : "South") << "\n";
                    cout << "  Destination:        " << usersObj[userID].flightDataObj.destination << "\n";
                    cout << "+-----------------------------------+----------------------------------+\n";
                    cout << "  Flight number:      " << usersObj[userID].flightDataObj.flightNumber << "\n";
                    cout << "  Seat No.:           " << usersObj[userID].flightDataObj.seatNumber << "\n";
                    cout << "  Status:             " << usersObj[userID].flightDataObj.isConfirmed << "\n";
                    cout << "+-----------------------------------+----------------------------------+\n";
                    cout << endl;

                    ofstream writeOutput("userTickets.txt", ios::app); // Writing the user ticket to a file
                    writeOutput << "+--------------------------------------------------------------------------------+\n";
                    writeOutput << "                User #" << userID + 1 << " flight data                   \n";
                    writeOutput << "+-------------------------------------------------------------------------------+\n";
                    writeOutput << "   Passenger Info                                     \n";
                    writeOutput << "+-------------------+----------------------------------+------------------------+\n";
                    writeOutput << "  Username:          " << usersObj[userID].username << "\n";
                    writeOutput << "  Contact:           " << usersObj[userID].contactNumber << "\n";
                    writeOutput << "  CNIC:              " << usersObj[userID].cnic << "\n";
                    writeOutput << "+-------------------+----------------------------------+------------------------+\n";
                    writeOutput << "   Flight Itinerary:                                                 \n";
                    writeOutput << "+-----------------------------------+----------------------------------+\n";
                    writeOutput << "  Departure:          " << usersObj[userID].flightDataObj.departure << "\n";
                    writeOutput << "  Airport:            " << (usersObj[userID].flightDataObj.isNorthAirport ? "North" : "South") << "\n";
                    writeOutput << "  Destination:        " << usersObj[userID].flightDataObj.destination << "\n";
                    writeOutput << "+-----------------------------------+----------------------------------+\n";
                    writeOutput << "  Flight number:      " << usersObj[userID].flightDataObj.flightNumber << "\n";
                    writeOutput << "  Seat No.:           " << usersObj[userID].flightDataObj.seatNumber << "\n";
                    writeOutput << "  Status:             " << usersObj[userID].flightDataObj.isConfirmed << "\n";
                    writeOutput << "+-----------------------------------+----------------------------------+\n";
                    writeOutput << endl << endl;
                    writeOutput.close();
                }else{
                    cout << "Flight not booked!\n";
                    return;
                }
        }
    }
    
};



int main(){
    user *users = nullptr; // User array nullptr because we don't know the size yet
    int userCount = 0, flightCount = 0;
    string usernameInput; string passwordInput; bool userLoggedIn = false;
    Flight f;
    Flight *flightObj = &f;  // Flight object

    // //flightObj->addFlight(departure, destination, date, dept time, arr time, duration, flightnum, seatsavailable, isInternational, isrunning, price, planeName, planeID);
    flightObj->addFlight("Islamabad", "London", 1, 10, 14, 4, "SV101", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 4, "Boeing 747", 1, true);
    flightObj->addFlight("Lahore", "Paris", 1, 12, 16, 4, "SV102", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 4, "Airbus A380", 2, true);
    flightObj->addFlight("Quetta", "New York", 1, 14, 20, 6, "SV103", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 6, "Boeing 777", 3, false);
    flightObj->addFlight("Peshawar", "Jeddah", 1, 16, 18, 2, "SV104", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 2, "Airbus A320", 4, false);
    flightObj->addFlight("Karachi", "Tokyo", 1, 18, 23, 5, "SV105", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 5, "Boeing 787", 5, false);

    flightObj->addFlight("Islamabad", "Sydney", 1, 9, 20, 11, "SV106", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 11, "Airbus A350", 6, true);
    flightObj->addFlight("Lahore", "Cairo", 1, 11, 13, 2, "SV107", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 2, "Boeing 737", 7, true);
    flightObj->addFlight("Quetta", "Singapore", 1, 13, 18, 5, "SV108", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 5, "Airbus A330", 8, false);
    flightObj->addFlight("Peshawar", "Istanbul", 1, 15, 19, 4, "SV109", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 4, "Boeing 767", 9, true);
    flightObj->addFlight("Karachi", "Amsterdam", 1, 17, 22, 5, "SV110", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 5, "Airbus A380", 10, false);

    flightObj->addFlight("Islamabad", "Lahore", 1, 8, 11, 3, "SV111", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, false, true, 30000, "Boeing 737", 11, true);
    flightObj->addFlight("Lahore", "Islamabad", 1, 10, 13, 3, "SV112", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, false, true, 30000, "Airbus A320", 12, true);
    flightObj->addFlight("Quetta", "Peshawar", 1, 12, 14, 2, "SV113", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, false, true, 20000, "Boeing 787", 13, false);
    flightObj->addFlight("Peshawar", "Karachi", 1, 14, 16, 2, "SV114", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, false, true, 20000, "Airbus A350", 14, false);
    flightObj->addFlight("Karachi", "Islamabad", 1, 16, 19, 3, "SV115", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, false, true, 30000, "Boeing 777", 15, false);
    
    flightObj->addFlight("Islamabad", "London", 2, 10, 14, 4, "SV116", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 4, "Boeing 747", 16, true);
    flightObj->addFlight("Lahore", "Paris", 2, 12, 16, 4, "SV117", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 4, "Airbus A380", 17, true);
    flightObj->addFlight("Quetta", "New York", 2, 14, 20, 6, "SV118", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 6, "Boeing 777", 18, false);
    flightObj->addFlight("Peshawar", "Jeddah", 2, 16, 18, 2, "SV119", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 2, "Airbus A320", 19, false);
    flightObj->addFlight("Karachi", "Tokyo", 2, 18, 23, 5, "SV120", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 5, "Boeing 787", 20, false);

    flightObj->addFlight("Islamabad", "Sydney", 2, 9, 20, 11, "SV121", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 11, "Airbus A350", 21, true);
    flightObj->addFlight("Lahore", "Cairo", 2, 11, 13, 2, "SV122", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 2, "Boeing 737", 22, true);
    flightObj->addFlight("Quetta", "Singapore", 2, 13, 18, 5, "SV123", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 5, "Airbus A330", 23, false);
    flightObj->addFlight("Peshawar", "Istanbul", 2, 15, 19, 4, "SV124", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 4, "Boeing 767", 24, true);
    flightObj->addFlight("Karachi", "Amsterdam", 2, 17, 22, 5, "SV125", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 5, "Airbus A380", 25, false);

    flightObj->addFlight("Islamabad", "Lahore", 2, 8, 11, 3, "SV126", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, false, true, 30000, "Boeing 737", 26, true);
    flightObj->addFlight("Lahore", "Islamabad", 2, 10, 13, 3, "SV127", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, false, true, 30000, "Airbus A320", 27, true);
    flightObj->addFlight("Quetta", "Peshawar", 2, 12, 14, 2, "SV128", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, false, true, 20000, "Boeing 787", 28, false);
    flightObj->addFlight("Peshawar", "Karachi", 2, 14, 16, 2, "SV129", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, false, true, 20000, "Airbus A350", 29, false);
    flightObj->addFlight("Karachi", "Islamabad", 2, 16, 19, 3, "SV130", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, false, true, 30000, "Boeing 777", 30, false);
    
    // flightObj->addFlight("Islamabad", "London", 3, 10, 14, 4, "SV131", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 4, "Boeing 747", 31, true);
    // flightObj->addFlight("Lahore", "Paris", 3, 12, 16, 4, "SV132", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 4, "Airbus A380", 32, true);
    // flightObj->addFlight("Quetta", "New York", 3, 14, 20, 6, "SV133", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 6, "Boeing 777", 33, false);
    // flightObj->addFlight("Peshawar", "Jeddah", 3, 16, 18, 2, "SV134", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 2, "Airbus A320", 34, false);
    // flightObj->addFlight("Karachi", "Tokyo", 3, 18, 23, 5, "SV135", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 5, "Boeing 787", 35, false);

    // flightObj->addFlight("Islamabad", "Sydney", 3, 9, 20, 11, "SV136", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 11, "Airbus A350", 36, true);
    // flightObj->addFlight("Lahore", "Cairo", 3, 11, 13, 2, "SV137", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 2, "Boeing 737", 37, true);
    // flightObj->addFlight("Quetta", "Singapore", 3, 13, 18, 5, "SV138", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 5, "Airbus A330", 38, false);
    // flightObj->addFlight("Peshawar", "Istanbul", 3, 15, 19, 4, "SV139", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 4, "Boeing 767", 39, true);
    // flightObj->addFlight("Karachi", "Amsterdam", 3, 17, 22, 5, "SV140", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, true, true, 20000 * 5, "Airbus A380", 40, false);

    // flightObj->addFlight("Islamabad", "Lahore", 3, 8, 11, 3, "SV141", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, false, true, 30000, "Boeing 737", 41, true);
    // flightObj->addFlight("Lahore", "Islamabad", 3, 10, 13, 3, "SV142", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, false, true, 30000, "Airbus A320", 42, true);
    // flightObj->addFlight("Quetta", "Peshawar", 3, 12, 14, 2, "SV143", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, false, true, 20000, "Boeing 787", 43, false);
    // flightObj->addFlight("Peshawar", "Karachi", 3, 14, 16, 2, "SV144", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, false, true, 20000, "Airbus A350", 44, false);
    // flightObj->addFlight("Karachi", "Islamabad", 3, 16, 19, 3, "SV145", SEATING_CAPACITY_BUSINESS + SEATING_CAPACITY_ECONOMY, false, true, 30000, "Boeing 777", 45, false);
    


    // //flightObj->displayFlights();
    loginReg loginRegObj;




    // loginRegObj.bookFlight(users, userCount, flightObj, 1);
    
    //flightObj->displayFlights();

    //loginRegObj.bookFlight(users, userCount, flightCount);
    
    mainMenuLogin:
    cout << "---------------------------------------\n";
    cout << "Welcome to the flight booking system!\n";
    cout << "---------------------------------------\n";
    cout << "Please choose one of the following options:\n";
    cout << "---------------------------------------\n";
    cout << "1" << "  " << "Admin login\n";
    cout << "2" << "  " << "Customer login\n";
    cout << "3" << "  " << "Browse Flights\n";
    cout << "---------------------------------------\n";


    int menuChoice;
    cin >> menuChoice;
    string input_admin_username, input_admin_password;
    string adminDept, adminDest, adminFlightNumber, planeName; int adminFlightDate, adminFlightTime, adminLandTime, adminFlightDuration, planeID;
    string adminFlightNumberToDelete;
    bool isFlightRunning, isInternational, isNorth;
    double ticketPrice; string adminInputPassword;

    switch(menuChoice){
    case 1:
        // Admin login screen
        
        cout << "Please enter admin credentials.\n";
        
        cout << "Username: ";
        cin >> input_admin_username;
        cout << "Password: ";
        input_admin_password = takePassword();

        // Check if admin credentials are correct
        if (input_admin_username == ADMIN_USERNAME && input_admin_password == ADMIN_PASSWORD) {
            // Admin panel
            adminScreen:
            cout << setw(40) << setfill('-') << "" << endl;
            cout << setfill(' ') << setw(6) << "" << "Welcome Admin" << setw(17) << "" << endl;
            cout << setw(40) << setfill('-') << "" << endl;
            cout << left << setw(2) << "1. " << "Add a new flight" << endl;
            cout << left << setw(2) << "2. " << "Delete a flight" << endl;
            cout << left << setw(2) << "3. " << "View all flights" << endl;
            cout << left << setw(2) << "4. " << "View all users" << endl;
            cout << left << setw(2) << "5. " << "View all bookings" << endl;
            cout << left << setw(2) << "6. " << "Halt a flight" << endl;
            cout << left << setw(2) << "7. " << "Resume a flight" << endl;
            cout << left << setw(2) << "8. " << "Logout" << endl;
            cout << setw(40) << setfill('-') << "" << endl;
            int adminChoice; bool isValidInput = false; string haltFN; string adminFlightNumberToDelete, resumeFN;
            cin >> adminChoice;
            switch(adminChoice){
                case 1:
                    
                    cout << "Welcome to the flight addition system!\n";
                    adminDept = validateString("Input departure: ");
                    adminDest = validateString("Input destination: ");
                    cout << "Input flight number:\n";
                    cin >> adminFlightNumber;
                    while(!isValidInput){
                    cout << "Input date:\n";
                    cin >> adminFlightDate;
                    if(!validateIfAllIntegers(adminFlightDate) || adminFlightDate > 31 || adminFlightDate < 1){
                        cout << "Invalid flight date!\n";
                    }else{
                        isValidInput = true;
                    }
                    }
                    isValidInput = false;
                    while(!isValidInput){
                    cout << "Input flight time:\n";
                    cin >> adminFlightTime;
                    if(!validateIfAllIntegers(adminFlightTime) || adminFlightTime > 24 || adminFlightTime < 1){
                        cout << "Invalid flight time!\n";
                    }else{
                        isValidInput = true;
                    }
                    }
                    isValidInput = false;
                    while(!isValidInput){
                    cout << "Input landing time:\n";
                    cin >> adminLandTime;
                    if(!validateIfAllIntegers(adminLandTime) || adminLandTime > 24 || adminLandTime < 1){
                        cout << "Invalid flight time!\n";
                    }else{
                        isValidInput = true;
                    }
                    }
                    isValidInput = false;

                    while(!isValidInput){
                    cout << "Input flight duration:\n";
                    cin >> adminFlightDuration;
                    if(!validateIfAllIntegers(adminFlightDuration) || adminFlightDuration > 24 || adminFlightDuration < 1){
                        cout << "Invalid duration time!\n";
                    }else{
                        isValidInput = true;
                    }
                    }
                    isValidInput = false;
                    cout << "Is the flight international? (1 for yes, 0 for no)\n";
                    cin >> isInternational;
                    cout << "Is the flight running? (1 for yes, 0 for no)\n";
                    cin >> isFlightRunning;
                    while(!isValidInput){
                    cout << "Input ticket price:\n";
                    cin >> ticketPrice;
                    if(!validateIfAllIntegers(ticketPrice) || ticketPrice < 1){
                        cout << "Invalid value!\n";
                    }else{
                        isValidInput = true;
                    }
                    }
                    isValidInput = false;
                    planeName = validateString("Input the plane name: ");
                    while(!isValidInput){
                    cout << "Input the plane ID:\n";
                    cin >> planeID;
                    if(!validateIfAllIntegers(planeID) || planeID < 1){
                        cout << "Invalid value!\n";
                    }else{
                        isValidInput = true;
                    }
                    }
                    isValidInput = false;
                    cout << "Is the flight from the Northern Airport? (1 for yes, 0 for no):\n";
                    cin >> isNorth;
                    flightObj->addFlight(adminDept, adminDest, adminFlightDate, adminFlightTime, adminLandTime, adminFlightDuration, adminFlightNumber, SEATING_CAPACITY_ECONOMY + SEATING_CAPACITY_BUSINESS, isInternational, isFlightRunning, ticketPrice, planeName, planeID, isNorth);
                    cout << "Flight Added!\n\n";
                    flightObj->displayFlightInfo(adminFlightNumber);
                    goto adminScreen;
                    break;
                case 2:
                    
                    cout << "Welcome to the flight deletion system!\n";
                    cout << "Input flight number to delete:\n";
                    cin >> adminFlightNumberToDelete;
                    flightObj->deleteFlight(adminFlightNumberToDelete);
                    cout << "Flight deleted!\n";
                    goto adminScreen;
                    break;
                case 3:
                    
                    cout << "Welcome to the flight viewing system!\n";
                    flightObj->displayFlights();
                    goto adminScreen;
                    break;
                case 4:
                    
                    cout << "Welcome to the user viewing system!\n";
                    cout << "List of all registered users:\n";
                    cout << "+----------------------------------+\n";
                    cout << "|      List of registered users     |\n";
                    cout << "+----------------------------------+\n\n";
                    for (int i = 0; i < userCount; i++) {
                        cout << "+------------------------+\n";
                        cout << "| User " << setw(2) << right << i + 1 << "                  |\n";
                        cout << "+------------------------+\n";
                        cout << "| CNIC: " << setw(17) << left << users[i].cnic << "|\n";
                        cout << "| Username: " << setw(13) << left << users[i].username << "|\n";
                        cout << "| Age: " << setw(19) << left << users[i].age << "|\n";
                        cout << "+------------------------+\n";
                        cout << "\n";
                    }
                    cout << "+----------------------------------+\n";
                    goto adminScreen;
                    break;
                case 5:
                    cout << "+----------------------------------+\n";
                for (int i = 0; i < userCount; i++) {
                    cout << endl;
                    cout << "+--------------------------------------------------------------------------------+\n";
                    cout << "                User #" << i + 1 << " flight data                   \n";
                    cout << "+--------------------------------------------------------------------------------+\n";
                    cout << "   Passenger Info                                     \n";
                    cout << "+--------------------------------------------------------------------------------+\n";
                    cout << "  Username:          " << users[i].username << "\n";
                    cout << "  Contact:           " << users[i].contactNumber << "\n";
                    cout << "  CNIC:              " << users[i].cnic << "\n";
                    cout << "+--------------------------------------------------------------------------------+\n";
                    cout << "   Flight Itinerary:                                                 \n";
                    cout << "+--------------------------------------------------------------------------------+\n";
                    cout << "  Departure:          " << users[i].flightDataObj.departure << "\n";
                    cout << "  Airport:            " << (users[i].flightDataObj.isNorthAirport ? "North" : "South") << "\n";
                    cout << "  Destination:        " << users[i].flightDataObj.destination << "\n";
                    cout << "+--------------------------------------------------------------------------------+\n";
                    cout << "  Flight number:      " << users[i].flightDataObj.flightNumber << "\n";
                    cout << "  Seat No.:           " << users[i].flightDataObj.seatNumber << "\n";
                    cout << "  Status:             " << users[i].flightDataObj.isConfirmed << "\n";
                    cout << "+--------------------------------------------------------------------------------+\n";
                    cout << endl;
                    goto adminScreen;
                }
                    break;
                case 6:
                    cout << "Welcome to the flight halting system!\n";
                    cout << "Input flight number to halt:\n";
                    cin >> haltFN;
                    flightObj->haltFlight(haltFN);
                    cout << "Flight halted!\n";
                    goto adminScreen;
                case 7:
                    cout << "Welcome to the flight resuming system!\n";
                    cout << "Input flight number to resume:\n";
                    cin >> resumeFN;
                    flightObj->resumeFlight(resumeFN);
                    cout << "Flight resumed!\n";
                    goto adminScreen;
                case 8:
                    cout << "Logging out!\n";
                    goto mainMenuLogin;
                    break;
            }
        }
        else {
            cout << "Incorrect admin credentials. Please try again.\n";
        }
        break;

    case 2:
        // Customer login/registration screen
        while (true) {
        loginScreen:
        cout << setw(40) << setfill('-') << "" << endl;
        cout << setfill(' ') << setw(6) << "" << "Welcome to the registration system" << setw(17) << "" << endl;
        cout << setw(40) << setfill('-') << "" << endl;
        cout << left << setw(2) << "1. " << "Register a new user" << endl;
        cout << left << setw(2) << "2. " << "Login" << endl;
        cout << left << setw(2) << "3. " << "Back" << endl;
        cout << setw(40) << setfill('-') << "" << endl;
        int ifLoginOrRegChoice;
        cin >> ifLoginOrRegChoice;
        switch(ifLoginOrRegChoice){
            case 1:
                while (true) {
                    
                    cout << setw(40) << setfill('-') << "" << endl;
                    cout << setfill(' ') << setw(6) << "" << "Welcome to the registration system" << setw(17) << "" << endl;
                    cout << setw(40) << setfill('-') << "" << endl;
                    cout << left << setw(2) << "1. " << "Add a new user" << endl;
                    cout << left << setw(2) << "2. " << "Back" << endl;
                    cout << setw(40) << setfill('-') << "" << endl;
                    int loginRegChoice;
                    cin >> loginRegChoice;
                    cin.ignore();
                    switch(loginRegChoice){
                        case 1:
                            system("cls");
                            loginRegObj.addUser(users, userCount);
                            break;
                        case 2:
                            cout << "Going back!\n";
                            goto loginScreen; // Jump back to the login screen
                        default:
                            cout << "Invalid choice!\n";
                    }
                }
                break;
            case 2:
                while (true) {
                    
                    cout << setw(40) << setfill('-') << "" << endl;
                    cout << setfill(' ') << setw(6) << "" << "Welcome to the Login System" << setw(17) << "" << endl;
                    cout << setw(40) << setfill('-') << "" << endl;
                    cout << left << setw(2) << "1. " << "Login" << endl;
                    cout << left << setw(2) << "2. " << "Logout" << endl;
                    cout << setw(40) << setfill('-') << "" << endl;
                    int loginRegChoice;
                    int cancelFlightChoice;
                    loginReg loginRegObj;
                    cin >> loginRegChoice;
                    cin.ignore();
                    switch(loginRegChoice){
                        case 1:
                            system("cls");
                            
                            cout << "Enter your username: ";
                            cin >> usernameInput;
                            cout << "Enter your password: ";
                            passwordInput = takePassword();
                            //cout << usernameInput << " " << passwordInput << endl;
                            if (loginRegObj.loginUser(usernameInput, passwordInput, userCount, users)) {
                                userLoggedIn = true;
                                
                                cout << setw(40) << setfill('-') << "" << endl;
                                cout << setfill(' ') << setw(6) << "" << "User Panel" << setw(17) << "" << endl;
                                cout << setw(40) << setfill('-') << "" << endl;
                                cout << left << setw(2) << "1. " << "Book a flight" << endl;
                                cout << left << setw(2) << "2. " << "View user profile" << endl;
                                cout << left << setw(2) << "3. " << "Cancel a flight" << endl;
                                cout << left << setw(2) << "4. " << "Logout!" << endl;
                                cout << setw(40) << setfill('-') << "" << endl;
                                int userBookFlightChoice;
                                cin >> userBookFlightChoice;
                                switch(userBookFlightChoice){
                                    case 1:
                                        system("cls");
                                        loginRegObj.bookFlight(users, userCount, flightObj, globalUserIndex);
                                        break;
                                    case 2:
                                        system("cls");
                                        loginRegObj.userProfile(users, userCount, globalUserIndex);
                                        break;
                                    case 3:
                                        system("cls");
                                        cout << "Bookings for user: " << users[globalUserIndex].username << endl;
                                        cout << "Flight Number: " << users[globalUserIndex].flightDataObj.flightNumber << endl;
                                        cout << "Press 1 to cancel this flight: \nYou'll be refunded 25% only!\n";
                                        
                                        cin >> cancelFlightChoice;
                                        if(cancelFlightChoice == 1){
                                            flightObj->updateSeats(users[globalUserIndex].flightDataObj.flightNumber, flightObj->getSeatsAvailable(users[globalUserIndex].flightDataObj.flightNumber) + 1);
                                            users[globalUserIndex].flightDataObj.flightNumber = "";
                                            users[globalUserIndex].flightDataObj.departure = "";
                                            users[globalUserIndex].flightDataObj.destination = "";
                                            users[globalUserIndex].flightDataObj.seatNumber = "";
                                            users[globalUserIndex].flightDataObj.isConfirmed = false;
                                            cout << "Flight cancelled successfully!\n";
                                            users[globalUserIndex].balance += (flightObj->getTicketPrice(users[globalUserIndex].flightDataObj.flightNumber) * 0.25); 
                                        }
                                    case 4:
                                        
                                        cout << "Logging Out!\n";
                                        userLoggedIn = false;
                                        goto loginScreen; // Jump back to the login screen
                                }
                                break;                                                        
                            }else{
                                cout << "Login failed!\n";
                            }
                            break;
                        case 2:
                            cout << "Going back!\n";
                            userLoggedIn = false;
                            goto loginScreen; // Jump back to the login screen
                            break;
                        default:
                            cout << "Invalid choice!\n";
                    }
                    break;
                }
                break;
            case 3:
                cout << "Going back!\n";
                goto mainMenuLogin;
                break;
            default:
                cout << "Invalid choice!\n";
                break;
            }       
        }
    case 3:
        
        cout << setw(40) << setfill('*') << "" << endl;
        cout << "Flight Browser" << endl;
        cout << setw(40) << setfill('*') << "" << endl;
        cout << "1. " << "Search for a flight" << endl;
        cout << "2. " << "View all flights" << endl;
        cout << "3. " << "Trending destinations!" << endl;
        cout << "4. " << "Back" << endl;
        cout << setw(40) << setfill('*') << "" << endl;
        int flightBrowserChoice;
        cin >> flightBrowserChoice;
        string targetFN = ""; string userDest, userDept; int userDate; int deptChoice, destChoice;
        bool isValidInput = false;
        char bookchoice; char choice;
        switch (flightBrowserChoice) {
    case 1:
                cout << "Available places of departure: \n";
                cout << "+-------------------------------------+\n";
                cout << "1. Karachi\n";
                cout << "2. Lahore\n";
                cout << "3. Islamabad\n";
                cout << "4. Peshawar\n";
                cout << "5. Quetta\n";
                cout << endl;
                
                while(!isValidInput){
                cout << "+-------------------------------------+\n";
                cout << "Input a selection to enter a place of departure: \n";
                cout << "+-------------------------------------+\n";  
                    cin >> deptChoice;
                    if(!validateIfAllIntegers(deptChoice) || deptChoice > 5 || deptChoice < 1){
                        cout << "Invalid entry!\n";
                    }else{
                        isValidInput = true;
                    }
                }
                switch (deptChoice)
                {
                case 1:
                    userDept = "Karachi";
                    break;
                case 2:
                    userDept = "Lahore";
                    break;
                case 3:
                    userDept = "Islamabad";
                    break;  
                case 4:
                    userDept = "Peshawar";
                    break;  
                case 5:
                    userDept = "Quetta";
                    break;
                default:
                    break;
                }
                cout << "Available destinations: \n";
                cout << "+-------------------------------------+\n";
                cout << "1. London\n";
                cout << "2. Paris\n";
                cout << "3. New York\n";
                cout << "4. Jeddah\n";
                cout << "5. Tokyo\n";
                cout << "6. Sydney\n";
                cout << "7. Cairo\n";
                cout << "8. Singapore\n";
                cout << "9. Istanbul\n";
                cout << "10. Amsterdam\n";
                cout << "11. Riyadh\n";
                cout << "12. Dubai\n";
                cout << "13. Kuala Lumpur\n";
                cout << "14. Buenos Aires\n";
                cout << "15. Toronto\n";
                cout << "16. Karachi\n";
                cout << "17. Lahore\n";
                cout << "18. Islamabad\n";
                cout << "19. Peshawar\n";
                cout << "20. Quetta\n";
                isValidInput = false;
                while(!isValidInput){
                    cout << "+-------------------------------------+\n";
                    cout << "Input a selection to enter a destination: \n";
                    cout << "+-------------------------------------+\n";    
                    cin >> destChoice;
                    if(!validateIfAllIntegers(destChoice) || destChoice > 20 || destChoice < 1){
                        cout << "Invalid entry!\n";
                    }else{
                        isValidInput = true;
                    }
                }
                switch (destChoice)
                {
                case 1:
                    userDest = "London";
                    break;
                case 2:
                    userDest = "Paris";
                    break;
                case 3:
                    userDest = "New York";
                    break;
                case 4:
                    userDest = "Jeddah";
                    break;
                case 5:
                    userDest = "Tokyo";
                    break;
                case 6:
                    userDest = "Sydney";
                    break;
                case 7:
                    userDest = "Cairo";
                    break;
                case 8:
                    userDest = "Singapore";
                    break;
                case 9:
                    userDest = "Istanbul";
                    break;
                case 10:
                    userDest = "Amsterdam";
                    break;
                case 11:
                    userDest = "Riyadh";
                    break;
                case 12:
                    userDest = "Dubai";
                    break;
                case 13:
                    userDest = "Kuala Lumpur";
                    break;
                case 14:
                    userDest = "Buenos Aires";
                    break;
                case 15:
                    userDest = "Toronto";
                    break;
                case 16:
                    userDest = "Karachi";
                    break;
                case 17:
                    userDest = "Lahore";
                    break;
                case 18:
                    userDest = "Islamabad";
                    break;
                case 19:
                    userDest = "Peshawar";
                    break;
                case 20:
                    userDest = "Quetta";
                    break;
                default:
                    cout << "Invalid selection. Please try again.\n";
                break;
                }
                cout << "+-------------------------------------+\n";
                cout << "Enter the date of departure: \n";
                cout << "+-------------------------------------+\n";
                cin >> userDate;
                targetFN = flightObj->searchFlight(userDest, userDept, userDate);
                if(targetFN == "NOT FOUND"){
                    cout << "No flights found!\n";
                }else{
                    cout << "Search Results: " << targetFN << endl;
                    flightObj->displayFlightInfo(targetFN);
                    cout << "Do you want to book this flight? (Y/N)\n";
                        cin >> choice;
                        if(choice == 'Y' || choice == 'y'){
                            if(userLoggedIn == false){
                                cout << "You need to login first!\n";
                                goto loginScreen;
                            }else{
                                loginRegObj.bookFlight(users, userCount, flightObj, globalUserIndex);
                            }
                        }else{
                            cout << "Flight not booked!\n";
                            goto loginScreen;
                            return 0;
                        }             
                    }
        break;
    case 2:
        flightObj->displayFlights();
        goto loginScreen;
        break;
    case 3:
        flightObj->displayFlightInfo("SV101");
        flightObj->displayFlightInfo("SV102");
        flightObj->displayFlightInfo("SV108");
        flightObj->displayFlightInfo("SV109");
        flightObj->displayFlightInfo("SV113");
        cout << "Do you want to book any of these flights? (Y/N)\n";
        cin >> bookchoice;
        if (bookchoice == 'Y' || bookchoice == 'y') {
            if (userLoggedIn == false) {
                cout << "You need to login first!\n";
                goto loginScreen;
            } else {
                // Code for booking flight
            }
        }
        goto loginScreen;
        break;
    default:
        break;
}

}
}