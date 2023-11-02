#pragma once

#include <iostream>
#include <memory>
#include <list>
#include <vector>
using std::string;
using std::array;
using std::list;
using std::vector;
using std::ostream;
using std::istream;


//Constants
const int L_SIZE {2000};
const int S_SIZE {100};


//Classes
class activities
{
    public:
        activities();                                                               //Default constructor
        activities(const char *name, const string &new_info,                        //Constructor
                   const list <string> &new_participants, const double a_rating, 
                   const int nums_rating);    
        activities(const activities &to_copy);                                      //Copy constructor
        activities &operator=(const activities &src);                               //Overloaded assignment operator
        ~activities();                                                              //Destructor
        //int display() const;                                                        //Display the activity
        int disp_participants(ostream &out) const;                                        //Wrapper function for disp_participants
        int input_activ_name();                                                     //Input the activity
        int input_info();                                                           //Input the information
        int input_participants();                                                   //Input the participants

        friend ostream &operator <<(ostream &out, const activities &act_obj);               //Overloaded << operator to display the activity
        friend istream &operator >>(istream &input, activities &act_obj);                   //Overloaded >> operator to input the activity

        friend bool operator ==(const activities &act_obj1, const activities &act_obj2);    //Overloaded == operator to compare two activities
        friend bool operator ==(const activities &act_obj, const string &name);               //Overloaded == operator to compare an activity and a name
        friend bool operator ==(const string &name, const activities &act_obj);               //Overloaded == operator to compare an activity and a name

        friend bool operator !=(const activities &act_obj1, const activities &act_obj2);    //Overloaded != operator to compare two activities
        friend bool operator !=(const activities &act_obj, const string &name);               //Overloaded != operator to compare an activity and a name
        friend bool operator !=(const string &name, const activities &act_obj);               //Overloaded != operator to compare an activity and a name

        friend bool operator <(const activities &act_obj1, const activities &act_obj2);     //Overloaded < operator to compare two activities
        friend bool operator <(const activities &act_obj, const int a_rating);              //Overloaded < operator to compare an activity and a rating
        friend bool operator <(const int a_rating, const activities &act_obj);              //Overloaded < operator to compare an activity and a rating

        friend bool operator >(const activities &act_obj1, const activities &act_obj2);     //Overloaded > operator to compare two activities
        friend bool operator >(const activities &act_obj, const int a_rating);              //Overloaded > operator to compare an activity and a rating
        friend bool operator >(const int a_rating, const activities &act_obj);              //Overloaded > operator to compare an activity and a rating

        friend activities operator +(const activities &act_obj, const string &to_add);      //Overloaded + operator to add a participant
        friend activities operator +(const string &to_add, const activities &act_obj);      //Overloaded + operator to add a participant

        activities &operator +=(const activities &act_obj);                                 //Overloaded += operator to add a participant
        activities &operator +=(const string &to_add);                                      //Overloaded += operator to add a participant

        friend activities operator -(const activities &act_obj, const string &to_remove);   //Overloaded - operator to remove a participant
        friend activities operator -(const string &to_remove, const activities &act_obj);   //Overloaded - operator to remove a participant

        activities &operator -=(const activities &act_obj);                                 //Overloaded -= operator to remove a participant
        activities &operator -=(const string &to_remove);                                   //Overloaded -= operator to remove a participant

    protected:
        char *activ_name;              //Name of activity
        string info;                   //Information about activity
        list <string> participants;    //Participant(s) of activity or player(s) of game
        double rating;                    //Average rating of activity
        int num_ratings;               //Number of ratings

        int copy_name(const char *to_copy);    //Deep copy the name
        int disp_participants(list<string>::const_iterator it, ostream &out) const;  //Recursively print the participants
        
};

class tour : public activities
{
    public:
        tour();                                                                              //Default constructor
        tour(const activities &to_add, const string &an_address, const string &weathr,       //Constructor
             const double price);  
        ~tour();                                                                             //Destructor
        int display() const;                                                                 //Display the tour
        int input_address();                                                                 //Input the address
        int input_weather();                                                                 //Input the weather
        int input_cost();                                                                    //Input the cost
        
        friend ostream &operator <<(ostream &out, const tour &tour_obj);          //Overloaded << operator to display the tour
        friend istream &operator >>(istream &input, tour &tour_obj);              //Overloaded >> operator to input the tour

        friend bool operator ==(const tour &tour_obj1, const tour &tour_obj2);    //Overloaded == operator to compare two tours
        friend bool operator ==(const tour &tour_obj, const string &address);     //Overloaded == operator to compare a tour and an address
        friend bool operator ==(const string &address, const tour &tour_obj);     //Overloaded == operator to compare a tour and an address

        friend bool operator !=(const tour &tour_obj1, const tour &tour_obj2);    //Overloaded != operator to compare two tours
        friend bool operator !=(const tour &tour_obj, const string &address);     //Overloaded != operator to compare a tour and an address
        friend bool operator !=(const string &address, const tour &tour_obj);     //Overloaded != operator to compare a tour and an address

        friend bool operator <(const tour &tour_obj1, const tour &tour_obj2);     //Overloaded < operator to compare two tours
        friend bool operator <(const tour &tour_obj, const double price);         //Overloaded < operator to compare a tour and a price
        friend bool operator <(const double price, const tour &tour_obj);         //Overloaded < operator to compare a tour and a price

        friend bool operator <=(const tour &tour_obj1, const tour &tour_obj2);    //Overloaded <= operator to compare two tours
        friend bool operator <=(const tour &tour_obj, const double price);        //Overloaded <= operator to compare a tour and a price
        friend bool operator <=(const double price, const tour &tour_obj);        //Overloaded <= operator to compare a tour and a price

        friend bool operator >(const tour &tour_obj1, const tour &tour_obj2);     //Overloaded > operator to compare two tours
        friend bool operator >(const tour &tour_obj, const double price);         //Overloaded > operator to compare a tour and a price
        friend bool operator >(const double price, const tour &tour_obj);         //Overloaded > operator to compare a tour and a price

        friend tour operator +(const tour &tour_obj1, const tour &tour_obj2);     //Overloaded + operator to add a cost
        friend tour operator +(const tour &tour_obj, const double a_cost);        //Overloaded + operator to add a cost
        friend tour operator +(const double a_cost, const tour &tour_obj);        //Overloaded + operator to add a cost

        tour &operator +=(const tour &tour_obj);                                   //Overloaded += operator to add a cost
        tour &operator +=(const double a_cost);                                    //Overloaded += operator to add a cost

        friend tour operator -(const tour &tour_obj1, const tour &tour_obj2);      //Overloaded - operator to subtract a cost
        friend tour operator -(const tour &tour_obj, const double a_cost);         //Overloaded - operator to subtract a cost
        friend tour operator -(const double a_cost, const tour &tour_obj);         //Overloaded - operator to subtract a cost

        tour &operator -=(const tour &tour_obj);                                   //Overloaded -= operator to subtract a cost
        tour &operator -=(const double a_cost);                                    //Overloaded -= operator to subtract a cost

    private: 
        string address;    //Address of tour
        string weather;    //Weather conditions
        double cost;       //Cost of tour
};

class game : public activities
{
    public:
        game();                                                                                 //Default constructor            
        game(const activities &to_add, const string &name, const int pos,                                   //Constructor
             const int a_score, const array<int, 5> &lst_effects);     
        ~game();                                                                                //Destructor
        int display() const;                                                                    //Display the game
        int input_name();                                                                       //Input the name
        int input_pos();                                                                        //Input the position
        int input_score();                                                                      //Input the score
        int input_effects();                                                                    //Input the effects

        friend ostream &operator <<(ostream &out, const game &game_obj);          //Overloaded << operator to display the game
        friend istream &operator >>(istream &input, game &game_obj);              //Overloaded >> operator to input the game

        friend bool operator ==(const game &game_obj1, const game &game_obj2);    //Overloaded == operator to compare two games. This is the only argument list that makes sense for this operator.

        friend bool operator !=(const game &game_obj1, const game &game_obj2);    //Overloaded != operator to compare two games. This is the only argument list that makes sense for this operator.

        friend bool operator <(const game &game_obj1, const game &game_obj2);     //Overloaded < operator to compare two games. 
        friend bool operator <(const game &game_obj, const int a_score);          //Overloaded < operator to compare a game and a score
        friend bool operator <(const int a_score, const game &game_obj);          //Overloaded < operator to compare a game and a score

        friend bool operator <=(const game &game_obj1, const game &game_obj2);    //Overloaded <= operator to compare two games.
        friend bool operator <=(const game &game_obj, const int a_score);         //Overloaded <= operator to compare a game and a score
        friend bool operator <=(const int a_score, const game &game_obj);         //Overloaded <= operator to compare a game and a score

        friend bool operator >(const game &game_obj1, const game &game_obj2);     //Overloaded > operator to compare two games.
        friend bool operator >(const game &game_obj, const int a_score);          //Overloaded > operator to compare a game and a score
        friend bool operator >(const int a_score, const game &game_obj);          //Overloaded > operator to compare a game and a score

        friend bool operator >=(const game &game_obj1, const game &game_obj2);    //Overloaded >= operator to compare two games.
        friend bool operator >=(const game &game_obj, const int a_score);         //Overloaded >= operator to compare a game and a score
        friend bool operator >=(const int a_score, const game &game_obj);         //Overloaded >= operator to compare a game and a score

        friend game operator +(const game &game_obj1, const game &game_obj2);     //Overloaded + operator to add a score
        friend game operator +(const game &game_obj, const int a_score);          //Overloaded + operator to add a score
        friend game operator +(const int a_score, const game &game_obj);          //Overloaded + operator to add a score

        game &operator +=(const game &game_obj);                                  //Overloaded += operator to add a score
        game &operator +=(const int a_score);                                     //Overloaded += operator to add a score

        friend game operator -(const game &game_obj1, const game &game_obj2);     //Overloaded - operator to subtract a score
        friend game operator -(const game &game_obj, const int a_score);          //Overloaded - operator to subtract a score
        friend game operator -(const int a_score, const game &game_obj);          //Overloaded - operator to subtract a score

        game &operator -=(const game &game_obj);                                  //Overloaded -= operator to subtract a score
        game &operator -=(const int a_score);                                     //Overloaded -= operator to subtract a score
    
    private:
        string session_name;       //Name of session
        int curr_pos;              //Type of current position/segment
        int score;                 //Current score
        array <int, 5> effects;    //Effects of current position

        

};

class food : public activities
{
    public: 
        food();                                                                              //Default constructor
        food(const activities &to_add, const int a_rating, char *top, const double price,    //Constructor  
        const string &type, const string &an_address, const vector <string> &recs);    
        food(const food &to_copy);                //Copy constructor
        food &operator=(const food &src);         //Overloaded assignment operator
        ~food();                                  //Destructor
        int display() const;                      //Display the food
        int input_top_item();                     //Input the top item
        int input_food_type();                    //Input the food type
        int input_address();                      //Input the address
        int input_other_recs();                   //Input the other recommendations

        friend ostream &operator <<(ostream &out, const food &food_obj);          //Overloaded << operator to display the food
        friend istream &operator >>(istream &input, food &food_obj);              //Overloaded >> operator to input the food

        friend bool operator ==(const food &food_obj1, const food &food_obj2);    //Overloaded == operator to compare two foods
        friend bool operator ==(const food &food_obj, const string &address);     //Overloaded == operator to compare a food and an address
        friend bool operator ==(const string &address, const food &food_obj);     //Overloaded == operator to compare a food and an address

        friend bool operator !=(const food &food_obj1, const food &food_obj2);    //Overloaded != operator to compare two foods
        friend bool operator !=(const food &food_obj, const string &address);     //Overloaded != operator to compare a food and an address
        friend bool operator !=(const string &address, const food &food_obj);     //Overloaded != operator to compare a food and an address

        friend bool operator <(const food &food_obj1, const food &food_obj2);     //Overloaded < operator to compare two foods
        friend bool operator <(const food &food_obj, const int a_rating);         //Overloaded < operator to compare a food and a rating
        friend bool operator <(const int a_rating, const food &food_obj);         //Overloaded < operator to compare a food and a rating

        friend bool operator <=(const food &food_obj1, const food &food_obj2);    //Overloaded <= operator to compare two foods
        friend bool operator <=(const food &food_obj, const int a_rating);        //Overloaded <= operator to compare a food and a rating
        friend bool operator <=(const int a_rating, const food &food_obj);        //Overloaded <= operator to compare a food and a rating

        friend bool operator >(const food &food_obj1, const food &food_obj2);     //Overloaded > operator to compare two foods
        friend bool operator >(const food &food_obj, const int a_rating);         //Overloaded > operator to compare a food and a rating
        friend bool operator >(const int a_rating, const food &food_obj);         //Overloaded > operator to compare a food and a rating

        friend bool operator >=(const food &food_obj1, const food &food_obj2);    //Overloaded >= operator to compare two foods
        friend bool operator >=(const food &food_obj, const int a_rating);        //Overloaded >= operator to compare a food and a rating
        friend bool operator >=(const int a_rating, const food &food_obj);        //Overloaded >= operator to compare a food and a rating

        friend food operator +(const food &food_obj1, const food &food_obj2);     //Overloaded + operator to add a price of top item
        friend food operator +(const food &food_obj, const double a_price);       //Overloaded + operator to add a price of top item
        friend food operator +(const double a_price, const food &food_obj);       //Overloaded + operator to add a price of top item

        food &operator +=(const food &food_obj);                                  //Overloaded += operator to add a price of top item
        food &operator +=(const double a_price);                                  //Overloaded += operator to add a price of top item

        friend food operator -(const food &food_obj1, const food &food_obj2);     //Overloaded - operator to subtract a price of top item
        friend food operator -(const food &food_obj, const double a_price);       //Overloaded - operator to subtract a price of top item
        friend food operator -(const double a_price, const food &food_obj);       //Overloaded - operator to subtract a price of top item

        food &operator -=(const food &food_obj);                                  //Overloaded -= operator to subtract a price of top item
        food &operator -=(const double a_price);                                  //Overloaded -= operator to subtract a price of top item

    private: 
        int rating;                    //Online rating out of 5
        char *top_item;                //Top item on the menu
        double price_top_item;         //Price of top item 
        string food_type;              //Type of food
        string address;                //Address of restaurant
        vector <string> other_recs;    //Other recommendations
};