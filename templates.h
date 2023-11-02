#pragma once

#include "activities.h"
using std::unique_ptr;

//Node template class
template <typename data_type>
class node
{
    public:
        typedef unique_ptr <node<data_type>> node_ptr;   //Typedef for node_ptr
        
        node();                      //Default constructor
        ~node();                     //Destructor
        node_ptr &get_next();        //Get the next node
        node_ptr &get_prev();        //Get the previous node
        data_type get_data() const;  //Get the data in the node
    
    private:
        data_type data;   //Data in the node
        node_ptr prev;    //Previous pointer
        node_ptr next;    //Next pointer
};


//Doubly Linked List template class
template <typename data_type>
class DLL
{
    public:
        DLL();                                 //Default constructor
        DLL(const DLL &src);                   //Copy constructor
        DLL &operator =(const DLL &src);        //Overloaded assignment operator 
        ~DLL();                                //Destructor
        int add_node(data_type &to_add);       //Add a node to the DLL
        int remove_one(data_type &to_find);    //Remove a node from the DLL
        int display() const;                   //Display the DLL
        int find(string &to_find) const;       //Find a node in the DLL

        friend ostream &operator <<(ostream &out, const DLL<data_type> &dll_obj);    //Overloaded << operator to display the DLL
        friend istream &operator >>(istream &input, DLL<data_type> &dll_obj);        //Overloaded >> operator to add a node to the DLL


        friend DLL<data_type> operator +(const DLL<data_type> &dll_obj, const int step);  //Overloaded + operator to go forward x steps in the DLL if those nodes exist
        friend DLL<data_type> operator +(const int step, const DLL<data_type> &dll_obj);  //Overloaded + operator to go forward x steps in the DLL if those nodes exist

        DLL<data_type> &operator +=(const int step);                    //Overloaded += operator to go forward x steps in the DLL if those nodes exist
        DLL<data_type> &operator +=(const DLL<data_type> &dll_obj);     //Overloaded += operator to go forward x steps in the DLL if those nodes exist

        friend DLL<data_type> operator -(const DLL<data_type> &dll_obj, const int step);    //Overloaded - operator to go backward x steps in the DLL if those nodes exist
        friend DLL<data_type> operator -(const int step, const DLL<data_type> &dll_obj);    //Overloaded - operator to go backward x steps in the DLL if those nodes exist

        DLL<data_type> &operator -=(const int step);                     //Overloaded -= operator to go backward x steps in the DLL if those nodes exist
        DLL<data_type> &operator -=(const DLL<data_type> &dll_obj);      //Overloaded -= operator to go backward x steps in the DLL if those nodes exist

    private:
        unique_ptr<node<data_type>> head;    //Pointer to the first node in the DLL
        unique_ptr<node<data_type>> tail;    //Pointer to the last node in the DLL
        unique_ptr<node<data_type>> curr;    //Pointer to the current node in the DLL
};