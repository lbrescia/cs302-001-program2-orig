#include "activities.h"
#include <cstring>
using namespace std;

activities::activities() : activ_name(nullptr), info(""), rating(-1.0), num_ratings(0) {}

//Constructor that takes in arguments for all the data members
activities::activities(const char *name, const string &new_info,          
                       const list <string> &new_participants, const double a_rating, 
                       const int nums_rating) : info(new_info), participants(new_participants), rating(a_rating), num_ratings(nums_rating)
{
    if(copy_name(name) == 0) 
    {
        activ_name = nullptr;       
        throw -1;    //Throw an error if no name is given
    }
}   


activities::activities(const activities &to_copy) : info(to_copy.info), participants(to_copy.participants), rating(to_copy.rating), num_ratings(to_copy.num_ratings)
{
    if(copy_name(to_copy.activ_name) == 0)
    {
        activ_name = nullptr;
        throw -1;    //Throw an error if no name is given
    }    
}


//Overloaded assignment operator
activities &::activities::operator=(const activities &to_copy)
{
    if(this == &to_copy) return *this;  //Return the object if it is the same as the one being copied

    if(to_copy.activ_name == nullptr) throw -1; //Throw an error if no name is given

    if(activ_name) delete [] activ_name; //Deallocate memory for the name

    if(copy_name(to_copy.activ_name) == 0)
    {
        activ_name = nullptr;
        throw -2;    //Throw an error if no name is given
    }

    info = to_copy.info;    //Copy the info
    participants = to_copy.participants;    //Copy the participants
    rating = to_copy.rating;    //Copy the rating
    num_ratings = to_copy.num_ratings;    //Copy the number of ratings

    return *this;   //Return the object
}


//Deep copies the name
int activities::copy_name(const char *name)
{
    if(!name) return 0;    //Return 0 if no name is given

    activ_name = new char[strlen(name) + 1];    //Allocate memory for the name
    strcpy(activ_name, name);                   //Copy the name into the object
    return 1;                                   //Return 1 if the name was copied
}

activities::~activities()
{
    if(activ_name)
    {
        delete [] activ_name;  //Deallocate memory for the name
        activ_name = nullptr;  //Set the pointer to null
    }
        
}


//Display the activity
/*int activities::display() const
{
    if(!activ_name) return -1;                                  //Return an error if no name is given
    cout << "Activity name: " << activ_name << endl << endl;    //Display the name

    if(info == "") return -2;                //Return an error if no info is given
    cout << "Info: " << info << endl;        //Display the info

    if(participants.empty()) return -3;                            //Return an error if no participants are given
    cout << "Participants: " << endl;                              //Display the participants
    if(disp_participants(participants.begin()) == 0) return -3;    //Return an error if no participants are given
   
    if(rating == -1 || num_ratings == 0) return -4;                  //Return an error if no rating is given
    cout << "Rating: " << rating << endl;                            //Display the rating
    cout << "Number of ratings: " << num_ratings << endl << endl;    //Display the number of ratings

    return 1;    //Return 1 if the object was displayed
}*/


//Wrapper function for the recursive display function
int activities::disp_participants(ostream &out) const
{
    if(participants.empty()) return 0;    //Return 0 if no participants are given

    return disp_participants(participants.begin(), out);    //Return the number of participants displayed
}

//Displays the participants recursively
int activities::disp_participants(list<string>::const_iterator it, ostream &out) const
{
    if(it == participants.end()) return 0;      //Return 0 if the iterator is at the end of the list

    out << *it << endl;                         //Display the participant    

    return 1 + disp_participants(++it, out);    //Return 1 and call the function again with the next iterator
}


//Input an activity name
int activities::input_activ_name()
{
    char temp [S_SIZE];                         //Temporary array to hold the name

    cout << "Enter the name of the activity: ";    //Prompt the user for the name
    cin.get(temp, S_SIZE, '\n');                      //Input the name
    cin.ignore(100, '\n');

    if(temp[0] == '\0') return 0;    //If nothing was entered, return an error
    
    if(activ_name) 
    {
        delete [] activ_name;    //Deallocate memory for the name
        activ_name = nullptr;
    }

    activ_name = new char[strlen(temp) + 1];    //Allocate a new char array the size of the input + 1 for /0
    strcpy(activ_name, temp);    //Copy temp into activ_name

    return 1;    //Input successful
} 


//Input info about an activity
int activities::input_info() 
{
    cout << "Enter in information about the activity: ";    //Prompt to enter activity
    getline(cin, info);                                     //Get the info

    if(info.empty()) return 0;                              //If the string is empty, return an error
    
    return 1;                                               //Successful input
}                                                           


//Input participants in the activity
int activities::input_participants() 
{
    string temp;                                     //Temp string

    cout << "Enter name of participant/player: ";    //Prompt to enter participant 
    getline(cin, temp);                              //Get the participant

    if(temp.empty()) return 0;                       //If nothing was entered, return an error

    participants.push_back(temp);                    //Push the string entered to the list of participants

    return 1;                                        //Successful input
}                                                   


//Overloaded << operator to display the activity
ostream &operator <<(ostream &out, const activities &act_obj)              
{
    //THROW EXCEPTION IF ANY OF THE DATA MEMBERS ARE EMPTY

    out << "Activity name: " << act_obj.activ_name << endl << endl;                    //Display the name
    out << "Info: " << act_obj.info << endl << endl;                                   //Display the info
    out << "Participants: " << endl;                                                   //Display the participants
    if(act_obj.disp_participants(out) == 0) //THROW EXCEPTION HERE    //Display the participants
    out << "\nRating: " << (act_obj.rating/act_obj.num_ratings) << endl;               //Display the rating
    out << "Number of ratings: " << act_obj.num_ratings << endl;                       //Display the number of ratings

    return out;    //Return the ostream object
}


//Overloaded >> operator to input the activity
istream &operator >>(istream &input, activities &act_obj)   
{
    return input;    //Return the istream object
}                


//Overloaded == operator to compare two activities
bool operator ==(const activities &act_obj1, const activities &act_obj2)
{
    return (strcmp(act_obj1.activ_name, act_obj2.activ_name) == 0);    //Return true if the names are the same
}


//Overloaded == operator to compare an activity and a name
bool operator ==(const activities &act_obj, const string &name)
{
    return (strcmp(act_obj.activ_name, name.c_str()) == 0);    //Return true if the names are the same
}   


//Overloaded == operator to compare an activity and a name
bool operator ==(const string &name, const activities &act_obj)
{
    return (strcmp(name.c_str(), act_obj.activ_name) == 0);    //Return true if the names are the same
}


//Overloaded != operator to compare two activities
bool operator !=(const activities &act_obj1, const activities &act_obj2)
{
    return (strcmp(act_obj1.activ_name, act_obj2.activ_name) != 0);    //Return true if the names are not the same
}


//Overloaded != operator to compare an activity and a name
bool operator !=(const activities &act_obj, const string &name)
{
    return (strcmp(act_obj.activ_name, name.c_str()) != 0);    //Return true if the names are not the same
}


//Overloaded != operator to compare an activity and a name
bool operator !=(const string &name, const activities &act_obj)
{
    return (strcmp(name.c_str(), act_obj.activ_name) != 0);    //Return true if the names are not the same
}


//Overloaded < operator to compare two activities
bool operator <(const activities &act_obj1, const activities &act_obj2)
{
    return (act_obj1.rating < act_obj2.rating);    //Return true if the first activity's rating is less than the second activity's rating
}


//Overloaded < operator to compare an activity and a name
bool operator <(const activities &act_obj, const int a_rating)
{
    return (act_obj.rating < a_rating);    //Return true if the activity's rating is less than the rating
}


//Overloaded < operator to compare an activity and a rating
bool operator <(const int a_rating, const activities &act_obj)
{
    return (a_rating < act_obj.rating);    //Return true if the rating is less than the activity's rating
}


//Overloaded > operator to compare two activities
bool operator >(const activities &act_obj1, const activities &act_obj2)
{
    return (act_obj1.rating > act_obj2.rating);    //Return true if the first activity's rating is greater than the second activity's rating
}


//Overloaded > operator to compare an activity and a rating
bool operator >(const activities &act_obj, const int a_rating)
{
    return (act_obj.rating > a_rating);    //Return true if the activity's rating is greater than the rating
}              


//Overloaded > operator to compare an activity and a rating
bool operator >(const int a_rating, const activities &act_obj)
{
    return (a_rating > act_obj.rating);    //Return true if the rating is greater than the activity's rating
}             


//Overloaded + operator to add a participant
activities operator +(const activities &act_obj, const string &to_add)
{
    activities temp;

    return temp;
}


//Overloaded + operator to add a participant
activities operator +(const string &to_add, const activities &act_obj)
{
    activities temp;

    return temp;
}


//Overloaded += operator to add a participant
activities &activities::operator +=(const activities &act_obj)
{
    return *this;
}


//Overloaded += operator to add a participant
activities &activities::operator +=(const string &to_add)
{
    return *this;
}

//Overloaded - operator to remove a participant
activities operator -(const activities &act_obj, const string &to_remove)
{
    activities temp;


    return temp;
}   


//Overloaded - operator to remove a participant
activities operator -(const string &to_remove, const activities &act_obj)
{
    activities temp;

    return temp;
}


//Overloaded -= operator to remove a participant
activities &activities::operator -=(const activities &act_obj)
{
    return *this;
}                                 


//Overloaded -= operator to remove a participant
activities &activities::operator -=(const string &to_remove)
{
    return *this;
}                       