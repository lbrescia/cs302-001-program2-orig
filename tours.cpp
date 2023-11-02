#include "activities.h"
#include <cstring>
using namespace std;

//Default constructor
tour::tour() : address(""), weather(""), cost(-1.0) {} 


//Constructor with arguments
tour::tour(const activities &to_add, const string &an_address, const string &weathr,      
           const double price) : activities(to_add), address(an_address), weather(weathr),
                                 cost(price) {}


//Destructor                                            
tour::~tour()
{
    //Reset the data members to their 0 equivalent values
    address = "";       
    weather = "";
    cost = -1.0;
}                                                                             


//int display() const;                                                                 


//Input the address of the tour location
int tour::input_address()
{
    cout << "Enter the address: ";    //Prompt to enter address
    getline(cin, address);           //Input address

    if(address.empty()) return 0;     //If the address is empty, return an error

    return 1;                         //Successful input
}                                              


//Input the weather of the tour location
int tour::input_weather()
{
    cout << "Enter the weather: ";    //Prompt to enter weather
    getline(cin, weather);            //Input weather

    if(weather.empty()) return 0;     //If the weather is empty, return an error

    return 1;                         //Successful input
}                                                              


int tour::input_cost()
{
    cout << "Enter the cost: ";       //Prompt to enter cost
    cin >> cost;                      //Input cost
    cin.ignore(100, '\n');            //Clear the buffer

    if(cost < 0) return 0;            //If the cost is negative, return an error

    return 1;                         //Successful input
}