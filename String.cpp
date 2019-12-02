#include<iomanip>
#include<cassert>
#include"String.h"


//constructor definition
String::String()
{
  len = 0;
  str = NULL;
}

String::String(char c)
{
  len = 1;
  str = new char[len];
  str[0] = c;
}


String::String(const char* st)
{
  int j=0;
  while(st[j] != '\0')
    j++;

  len = j;
  str = new char[len];

  for(int i=0;i<len;i++)
    str[i] = st[i];
}

String::String(const String& ostring)
{
  len = ostring.len;
  str = new char[len];

  for(int i=0;i<len;i++)
    str[i] = ostring.str[i];
}


//Destructor

String::~String(void)
{
  delete[] str;
}

//Methods

void String::ToUpper(void)
{
  for(int i=0;i<len;i++)
    {
      if(str[i]>='a' && str[i]<='z')
	str[i] +='A' - 'a';
    }
}

void String::ToLower(void)
{
  for(int i=0;i<len;i++)
    {
      if(str[i]>='A' && str[i]<='Z')
	str[i] += 'a' - 'A';
    }
}

void String::Toggle(void)
{
  for(int i=0;i<len;i++)
    {
      if(str[i]>='a' && str[i]<='z')
	str[i] += 'A' - 'a';
      else if(str[i]>='A' && str[i]<='Z')
	str[i] += 'a' - 'A';
    }
}

int String::length(void)
{
  return len;
}

bool String::has(char ch)
{
  for(int i=0;i<len;i++)
    if(ch == str[i])
      return true;
  return false;
}

int String::isAt(char ch)
{
  for(int i=0;i<len;i++)
    if(ch == str[i])
      return i;
  return -1;
}

String String::Substring(int start,int end)
{
  int c1 = (start >=0 && start < len);
  int c2 = (end > start && end < len);

  assert(c1 && c2);

  String newobj;
  newobj.len = end - start;
  newobj.str = new char[newobj.len];

  for(int i=0;i<newobj.len;i++)
    newobj.str[i] = str[i+start];

  return newobj;
}


String String::reverse(void)
{
  String temp(*this);
  int i=0,j=len-1;

  while(i<j)
    {
      char t = temp.str[i];
      temp.str[i] = temp.str[j];
      temp.str[j] = t;
      i++;
      j--;
    }

  return temp;
}
  

//operator functions

String String::operator+(const String& otherstring) const
{
  String newstring;
  newstring.len = len + otherstring.len;
  newstring.str = new char[newstring.len];

  for(int i=0;i<len;i++)
    newstring.str[i] = str[i];

  for(int j=0;j<otherstring.len;j++)
    newstring.str[j+len] = otherstring.str[j];

  return newstring;
}

String String::operator+(const char* cstr)const
{
  /*int i=0;
  while(cstr[i] !='\0')
    i++;

  String temp ;

  temp.len = len + i ;

  temp.str = new char[temp.len];
  for(int j=0;j<len;j++)
    temp.str[j] = str[j];

  for(int j=0;cstr[j] != '\0';j++)
    temp.str[len+j] = cstr[j];

    return temp;*/
  String tempstr(cstr);
  
  return (*this + tempstr);
}


String String::operator+(char ch)const
{
  String testr(ch);
  return (*this)+testr;
}


String operator+(const char* ch ,const String& str)
{
  return str + ch;
}


String operator+(char ch,const String& str)
{
  return str + ch;
}


String& String::operator+=(const String& otherstring) 
{
  int templen = len + otherstring.len;
  char* tempch = new char[templen];

  for(int i=0;i<len;i++)
    tempch[i] = str[i];

  for(int j=0;j<otherstring.len;j++)
    tempch[j+len] = otherstring.str[j];

  delete[] str; //deleting presently reference memory
  str = tempch;
  len = templen;

  return *this;
}

String& String::operator+=(const char* tch)
{
  String tstring(tch);
  (*this) += tstring;
  return *this;
}

String String::operator*(int times) const
{
  String newstring;
  if(times < 0)
    {
      std::cout<<"Invalid argument"<<std::endl;
      return newstring;

    }

  for(int i=0;i<times;i++)
    newstring += (*this);

  return newstring;
}

String& String::operator*=(int times)
{
  if(times < 0)
    {
      std::cout<<"Inalid arument"<<std::endl;
      return *this;
    }

  String newstring(*this);
  for(int i=0;i<times;i++)
    *this += newstring;


  return *this;
}

String& String::operator=(String& otherstring)
{
  delete[] str;
  len = otherstring.len;

  for(int i=0;i<len;i++)
    str[i] = otherstring.str[i];

  return *this;
}

char String::operator[](int index)
{
  assert(index>=0 && index< len);
  return str[index];
}
  
bool String::operator==(String& otherstring)
{
  if(len != otherstring.len)
    return false;

  for(int i=0;i<len;i++)
    if(str[i] != otherstring.str[i])
      return false;

  return true;
}

bool String::operator!=(String& otherstring)
{
  return !(*this == otherstring);
}


//friend operator function

std::ostream& operator<<(std::ostream& os,const String& mystring)
{
  os<<mystring.str;
  return os;
}

std::istream& operator>>(std::istream& is,String& mystring)
{
  char* input = new char[1000];
  is>>std::setw(1000)>>input;

  delete[] mystring.str;

  int i ;
  for(i=0;input[i]!='\0';i++);

  mystring.len = i;
  mystring.str = new char[mystring.len];
  for(int j=0;j<mystring.len;j++)
    mystring.str[j] = input[j];

  return is;
}


  
