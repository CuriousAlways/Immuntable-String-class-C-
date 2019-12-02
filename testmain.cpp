#include<iostream>
#include"String.h"

using namespace std;

int main(void)
{
  String obj1("KInGis"),obj2('c'),obj3(obj1);
  cout<<"---Constructors---"<<endl;
  cout<<"object1 : "<<obj1<<endl;
  cout<<"object2 : "<<obj2<<endl;
  cout<<"object3 : "<<obj3<<endl;
  cout<<"---Methods---"<<endl;
  obj1.ToUpper();
  cout<<"object1 : "<<obj1<<endl;
  obj3.Toggle();
  cout<<"object3 : "<<obj3<<endl;
  cout<<"substring(1,3) : "<<obj3.Substring(1,3)<<endl;
  cout<<"length3 : "<<obj3.length()<<endl;
  obj3.ToLower();
  cout<<"obj3 : "<<obj3<<endl;
  cout<<"has(k) : "<<obj3.has('k')<<endl;
  cout<<"has(f) : "<<obj3.has('f')<<endl;
  cout<<"isAt(i) : "<<obj3.isAt('i')<<endl;
  cout<<"isAt(m) : "<<obj3.isAt('m')<<endl;
  cout<<"---Operators---"<<endl;
  cout<<"obj2+obj1+obj3 : "<<obj2+obj1+obj3<<endl;
  cout<<"obj1*2 : "<<obj1*2<<endl;
  cout<<"obj3[5] : "<<obj3[5]<<endl;
  String p("this");
  String q("one");
  String m("this");
  cout<<p<<" == "<<q <<" -> "<<(p==q)<<endl;
  cout<<p<<" == "<<m <<" -> "<<(p==m)<<endl;
  cout<<m<<" != "<<q <<" -> "<<(m!=q)<<endl;
  cout<<p+"Hello.."+'a'+"Test "<<endl;
  cout<<"Second "+q<<endl;
  return 0;
}

  
