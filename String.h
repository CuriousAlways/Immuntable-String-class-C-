#include<iostream>

#ifndef _String_
#define _String_

class String
{
 private :

  char* str;  
  int len ; //stores length of string

 public :

  //Constructors
  String();
  String(char);
  String(const char*);
  String(const String&); //copy constructor

  //Destructors
  ~String(void);

  //Methods

  void ToUpper(void); //Make each character of this object upper case
  void ToLower(void); //Make each character of this object lower case
  void Toggle(void);  //Toggle case i.e. lowers to upper and vice-versa for this object
  int length(void); //gives length of string object
  int isAt(char ); //returns index at which character is present else -1
  String Substring(int,int); //returns new string object b/w given start and last(excluding) index  
  bool has(char); //returns true if given character argument is in the string
  String reverse(void); //returns new reversed String of this String

  //overloaded operators

  String operator+(const String&)const; //returns concatenated string
  String operator+(const char*)const; //returns concatenated string
  String operator+(const char)const;
  friend String operator+(const char*,const String&);
  friend String operator+(char,const String&);
  String& operator+=(const String&); //concatenates this and given string
  String& operator+=(const char*); //concatenates this and given c-string
  String operator*(int)const; //returns newstring concatenated to itself given number of times
  String& operator*=(int); //concatenates this string to itself given number of times
  String& operator=(String&); //copies one string to another
  bool operator==(String&); //tests if this string and given string same
  bool operator!=(String&); //tests if this string and given string are different
  char operator[](int); //returns character at given index
  friend std::ostream& operator<<(std::ostream&,const String&);
  friend std::istream& operator>>(std::istream&,String&);

};

#endif

  
  
  

  
  
  
