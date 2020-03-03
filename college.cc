//**********************************//
//  Gavin Dassatti                  //
//  CS 2401                         //
//  Project 03                      //
//  The implementation file for the //
//  college class                   //
//**********************************//

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "node.h"
#include "course.h"
#include "college.h"
using namespace std;

// Default Constructor
College::College(){

    name = " ";
    head = NULL;

}

// Deconstructor
College::~College(){

    node *rmptr;
    while(head == NULL){

        rmptr = head;
        head = head -> link();
        delete rmptr;

    }

}

// Copy Constructor
College::College(const College& other){

    if(other.head == NULL){

        head = NULL;

    } else {

        node *source;
        node *destination;
        head = new node(other.head -> data());
        source = other.head -> link();
        destination = head;
        while(source != NULL){

            destination -> set_link(new node(source -> data()));
            destination = destination -> link();
            source = source -> link();

        }

    }

}

// Assignment Operator
College& College::operator =(const College& rhs){

    if(this == &other){ return *this; }
    node *rmptr;

    while(head != NULL){

        rmptr = head;
        head = head -> link();
        delete rmptr;

    }

    if(rhs.head != NULL){

        head = new node(rhs.head -> data());
        const node *source = rhs.head -> link();
        node *destination = head;

        while(source != NULL){

            destination -> set_link(new node(source -> data()));
            destination = destination -> link();
            source = source -> link();

        }

    }

    return *this;

}

void College::add(course newCourse){

    node *prev = head;
    node *cursor = head -> link();

    if(head == NULL){

        head = new node(newCourse);

    } else if(newCourse < head -> data()){

        head = new node(newCourse, prev);

    } else {

        while(cursor != NULL){

            prev = cursor;
            cursor = cursor -> link();

        }

        prev -> set_link(new node(newCourse, cursor));

    }

}


void College::remove(string target){

    if(head == NULL){ return: }

    node *cursor = head -> link();
    node *prev = head;

    if(head -> data().get_course_number() == target){

        head = head -> link();
        delete prev;
        return;

    }

    while(cursor != NULL && (cursor -> data()).get_course_number() != target){

        prev = cursor;
        cursor = cursor -> link();

    }

    if(cursor != NULL){

        prev -> set_link(cursor -> link());
        delete cursor;

    }

}

void College::display(ostream* outs){

    if(head == NULL){ return: }
    node *cursor = head;

    while(cursor != NULL){

        outs << cursor -> data();
        cursor = cursor -> link();

    }
    
}
