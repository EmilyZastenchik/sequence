/*
 *Program Name: Programming Assignment 1
 *Programmer Name:Emily Zastenchik
 * Date Submitted: 2/6/2017
 */
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cassert>
#include "sequence2.h"

using namespace std;
namespace DSProject01
{
  sequence::sequence(size_type initial_capacity)
  /**DEFAULT CONSTRUCTOR
   * initializes private data fields
   * 
   * @param initial_capacity
   */
  {
      capacity = initial_capacity;
      data = new value_type[capacity];  //allocates array in HEAP
      used = 0;
      current_index = 0;
  }
  sequence::sequence(const sequence& source)
  /**COPY CONSTRUCTOR
   * assigns source information to data
   * @param source
   */
  {
      data = new value_type[source.capacity];   //assigns data to new array
      //assigning source sequence information to data sequence
      capacity = source.capacity;   
      used = source.used;
      current_index = source.current_index;
      copy(source.data, source.data + used, data);  
      //copy function(pointer to sequence array, sequence data to copy, location of first sequence to copy)
      
  }
  sequence::~sequence( )
 /**DESTRUCTOR
  * removes data from dynamic memory (HEAP) using keyword DELETE
  */
  {
      delete [] data;
  }
  void sequence::resize(size_type new_capacity)
 /**
  * resizes the sequence by increasing or decreasing the capacity to new_capacity
  * @param new_capacity
  */
  {
      value_type* temp; 
     
      capacity = new_capacity;
      temp = new value_type[capacity];  //temporary pointer to resized array in HEAP
      //copies sequence from source to data
      copy(data, data + capacity, temp);   
      delete [] data;
      data = temp;  //data now points to temp array (resized array)
  }
  void sequence::start()
  /**
   * sets current_index to 0 which is the beginning of the array
   */
  {
      current_index = 0;
  }
  void sequence::advance( )
  /**
   * increments current_index by 1
   */
  {
         ++current_index;
  }
  void sequence::insert(const value_type& entry)
  /**
   * inserts entry BEFORE current_index
   * @param entry
   */
  {
      if(used == capacity)  //resize sequence by 10% if filled to capacity
          resize(capacity + (capacity * .1)); 
      
      if(!is_item())    //adds entry to beginning of sequence
          current_index = 0;
      
      for(size_type i = used; i > current_index; --i)   //start at back of sequence and copies sequence data
        data[i] = data[i-1];
     
        data[current_index] = entry;     //assigns entry value to current index 
  
        ++used; //increments used by 1 to accommodate for new entry value
    
      
   }
  void sequence::append(const value_type& entry)
  /**
   * inserts entry AFTER current_index
   * @param entry
   */
  { 
      if(!is_item())    //adds entry to end of sequence
          current_index = used - 1;
      
      if(used == capacity)  //resize sequence of filled to capacity
          resize(capacity+(capacity* .1));
          
      for(size_type i = used; i > current_index + 1; --i)   //using a reverse looping statement to copy sequence values in data array
        data[i] = data[i-1];

        ++current_index; //adjusts current_index since entry is added after current_index
        
         data[current_index] = entry; //assigns entry value to current index
     
        ++used; //increments used by 1 to accommodate for new entry value
  }
  void sequence::remove_current( )
  /**
   * deletes sequence element at current index
   */
  {
      assert(is_item());    //checks if item is valid (already in sequence)
      
       for(size_type i = current_index +  1; i < used; ++i) //
           data[i-1] = data[i];
      
       --used;
  }
  void sequence::operator =(const sequence& source)
  /**ASSIGNMENT OPERATOR
   * 
   * @param source
   */
  {
      value_type *new_data;
      if(this == &source)   //checks for self assignment
          return;
      if(capacity != source.capacity)   //only resize function if needed
      {
          //assigns the values of source sequence to data sequence
          new_data = new value_type[source.capacity];
          delete [] data;
          data = new_data;
          capacity = source.capacity;
          current_index = source.current_index;
      }
      
      used = source.used;
      copy(source.data, source.data + used, data);
  }
  sequence::size_type sequence::size( ) const
  /**
   */
  {
      return used;  //used is the sequence items that are in the array
  }
  bool sequence::is_item( ) const
  /**
   * sequence item is valid(TRUE) only if current_index is between 0 and used
   * else, the sequence item is not valid
   */
  {
    if(current_index >= used)
            return false;
    else
        return true;
        
  }
  sequence::value_type sequence::current() const
  /**
   * 
   * @returns current sequence item
   */
  {
      return data[current_index];
  }

}

