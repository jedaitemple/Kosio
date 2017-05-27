#include <iostream>
#include <fstream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring>
using namespace std;





//pisane v dvoichen fail
void write_to_text(){
	ofstream out_file ("myfile.txt");
	char str []="Kosio";
	for (int i = 0; i < 3; i ++){
		out_file << str
	
		<< endl;
	}
	out_file.close();

}

//pisane v binary fail

	void write_to_binary(){
	char s[] = "Hello"; 
		ofstream out (" stundets .bin ", ios :: binary | ios :: app );
		for (int i = 0; i < 3; i ++)
			out . write (( char *)& s, sizeof ( 12));//char* i broq na baitovete kadeto e 12
	}

//chetene ot bainary fail

	void read_to_binary(){

		  streampos size;
  char * memblock;

  ifstream file ("students.bin", ios::in|ios::binary|ios::ate);
  if (file.is_open())
  {
    size = file.tellg();
    memblock = new char [size];
    file.seekg (0, ios::beg);
    file.read (memblock, size);
    file.close();

    cout << "the entire file content is in memory";

    delete[] memblock;
  }
  else cout << "Unable to open file";

	}


//chetene ot text fail
void read_to_text(){
  string line;
   string token;

  ifstream myfile ("myfile.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
   stringstream ss(line);


while (getline(ss,token, ','))
{
    cout<< token <<endl; 
}

      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
}






int main(){
write_to_text();
read_to_text();

return 0;
}
