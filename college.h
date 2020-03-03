//**********************************//
//  Gavin Dassatti                  //
//  CS 2401                         //
//  Project 03                      //
//  The header file for the         //
//  college class                   //
//**********************************//

#include <iostream>
#include <string>
#include <fstream>
#include "node.h"
#include "course.h"
#ifndef COLLEGE_H
#define COLLEGE_H
using namespace std;

class College{

    public:

        // Default Constructor
        College();


        /*****************
         *   The Big 3   *
         * **************/
        // Deconstructor
        ~College();
        // Copy constructor
        College(const College& other);
        // Assignment operator
        College& operator =(const College& rhs);


        /**********
         * Setter *
         * *******/
        void set_name(std::string newName){ name = newName; }


        /********************
         * Helper Functions *
         * *****************/
        void add(course newCourse);
        void remove(string target);
        void display(ostream& outs);
        void load(istream& ins);
        void save(ostream& outs);
        int hours();
        double gpa();



    private:

        string name;
        node *head;


};

#endif
