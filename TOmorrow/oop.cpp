#include<iostream>
#include <fstream>
using namespace std;
int main(){
string clas;
	cout<<"give the name to the class"<<endl;
	cin>>clas;
int arg_num;
string arg[100];
	cout<<"write the number of arg"<<endl;
	cin>>arg_num;
	cout<<"give the name to the arguments"<<endl;

	for(int i=0;i<arg_num;i++){
		cin>>arg[i];	
	}


string arg_type[100];
	cout<<"give the type to the arguments char* or int or double"<<endl;

	for(int i=0;i<arg_num;i++){
		cout<<"give a type to "<<arg[i]<<endl;
		cin>>arg_type[i];	
	}
 ofstream myfile;
  myfile.open ("exam.h");
  myfile << "class "<<clas<<"{"<<endl;
  myfile << "	public:"<<endl;

  myfile << "		"<<clas<<"(";
  for(int i=0;i<arg_num;i++){
	if(arg_type[i] == "char*"){

			myfile << "const char* " <<arg[i]<<"_";
		
	}
	if(arg_type[i] == "int"){
		myfile << "int " <<arg[i]<<"_";
	
	}	
	if (i<arg_num-1){
		myfile<< ","; 
	}
  }
myfile <<");"<<endl;
myfile << "		"<<clas<<"();"<<endl;	
myfile << "		"<<clas<<"("<< "const "<<clas<<"&"<<");"<<endl;	
myfile << "		"<<clas<<" &operator =("<<"const "<<clas<<"&"<<");"<<endl;	
myfile << "		"<<"~"<<clas<<"();"<<endl;

 for(int i=0;i<arg_num;i++){
	if(arg_type[i]=="char*"){
		myfile << "		"<<"void set"<<arg[i]<<"(const char* str);"
<<endl;		
	}
if(arg_type[i]=="int"){
		myfile << "		"<<"void set"<<arg[i]<<"(const int a);"
<<endl;		
	}
  }
	
 for(int i=0;i<arg_num;i++){
	if(arg_type[i]=="char*"){
		myfile << "		"<<"char* get"<<arg[i]<<"()const;"
<<endl;		
	}
		if(arg_type[i]=="int"){
			myfile << "		"<<"int get"<<arg[i]<<"()const;"
<<endl;		
	}
  }
myfile<<"		void print()const;"<<endl;
myfile<<"	private:"<<endl;
 for(int i=0;i<arg_num;i++){
	myfile<<"		"<<arg_type[i]<<" "<<arg[i]<<";"<<endl;
	}
myfile<<"};"<<endl;
  myfile.close();










 myfile.open ("exam.cpp");

	myfile<<"#include <cstring>"<<endl;
	myfile<<"#include <cstring>"<<endl;
	myfile<<"using namespace std;"<<endl;
	myfile<<clas<<"::"<<clas<<"(){};"<<endl;

  myfile << clas<<"::"<<clas<<"(";
  for(int i=0;i<arg_num;i++){
	if(arg_type[i] == "char*"){

			myfile << "const char* " <<arg[i]<<"_";
		
	}
	if(arg_type[i] == "int"){
		myfile << "int " <<arg[i]<<"_";
	
	}	
	if (i<arg_num-1){
		myfile<< ","; 
	}
  }
	myfile<< ")"<<endl; 
	myfile<< "{"<<endl;
		for(int i=0;i<arg_num;i++){
	if(arg_type[i]=="char*"){
		myfile << "	this->"<<" set"<<arg[i]<<"("<<arg[i]<<"_);"
<<endl;		
	}
if(arg_type[i]=="int"){
		myfile << "	this->"<<" set"<<arg[i]<<"("<<arg[i]<<"_);"<<endl;		
	}
  }
	myfile<< "}"<<endl;


myfile <<clas<<"::"<<clas<<"("<< "const "<<clas<<"&"<<" other"<<")"<<endl;
myfile<< "{"<<endl;
		for(int i=0;i<arg_num;i++){
	if(arg_type[i]=="char*"){
		myfile << "	"<<"this->set"<<arg[i]<<"(other."<<arg[i]<<");"
<<endl;		
	}
if(arg_type[i]=="int"){
		myfile << "	"<<"this->set"<<arg[i]<<"(other."<<arg[i]<<");"<<endl;		
	}
  }
	myfile<< "}"<<endl;
	

myfile <<clas<<"& "<<clas<<"::operator="<<"("<< "const "<<clas<<"&"<<" other"<<")"<<endl;
myfile<< "{"<<endl;
myfile<<"if (this != &other)"<<endl;
	myfile<<"	{"<<endl;


		for(int i=0;i<arg_num;i++){
	if(arg_type[i]=="char*"){
		myfile << "	this->"<<" set"<<arg[i]<<"(other."<<arg[i]<<");"
<<endl;		
	}
if(arg_type[i]=="int"){
		myfile << "	this->"<<" set"<<arg[i]<<"(other."<<arg[i]<<");"<<endl;		
	}
  }
myfile<<"}"<<endl;
myfile<<"	return *this;"<<endl;
	myfile<< "}"<<endl;


	myfile<< clas<<"::~"<<clas<<"(){"<<endl;
	for(int i=0;i<arg_num;i++){
		if(arg_type[i]=="char*"){
			myfile<< "	delete []"<<arg[i]<<";"<<endl;
		}
	}
myfile<< "}"<<endl;




 for(int i=0;i<arg_num;i++){
	if(arg_type[i]=="char*"){
		myfile <<"void "<<clas<<":: set"<<arg[i]<<"(const char* str)"
<<endl;	
	myfile<<"{"<<endl;
	myfile<<"	if (!"<<arg[i]<<") {"<<endl;
	myfile<< "		delete [] this->"<<arg[i]<<";"<<endl;
	myfile<<"		this->"<< arg[i]<<" = 0;"<<endl;
	myfile<<"	}"<<endl;
	myfile<<"	size_t len = strlen(str) + 1;"<<endl;
	myfile<<"	this->"<<arg[i]<< "= new char[len];"<<endl;
	myfile<< "	strcpy(this->"<<arg[i]<<",  str);"<<endl;
	myfile<<"}"<<endl;
	}
if(arg_type[i]=="int"){
		myfile << "void "<<clas <<":: set"<<arg[i]<<"(const int a)"
<<endl;		
	myfile<<"{"<<endl;
	myfile<<"	this->"<<arg[i]<<" = a;"<<endl;
	myfile<<"}"<<endl;

	}
  }
 for(int i=0;i<arg_num;i++){
	if(arg_type[i]=="char*"){
		myfile <<"char* "<<clas<<":: get"<<arg[i]<<"()const{"
<<endl;	
	
	myfile<<"	return this->"<<arg[i]<<";"<<endl;
	
	myfile<<"}"<<endl;
	}
if(arg_type[i]=="int"){
			myfile <<"int "<<clas<<":: get"<<arg[i]<<"()const{"
<<endl;	
	
	myfile<<"	return this->"<<arg[i]<<";"<<endl;
	
	myfile<<"}"<<endl;

	}
  }


return 0;
}
