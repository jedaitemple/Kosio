#include <iostream>
#include <fstream>


using namespace std;

char *strcpy(char *target, const char *source)
{
        int i;

        for(i = 0; source[i] != '\0'; ++i)
                target[i] = source[i];
        target[i] = source[i];

        return target;
}



struct Product{
    char description[32];
    int partNum;
    double cost;
};



int main(){
  struct Product st1;
  struct Product st2;
     strcpy( st1.description, "screw driver");
       st1.partNum=456;
      st1.cost=5.50;

       strcpy( st2.description, "hammer");
       st2.partNum=324;
      st2.cost=8.2-0;

      cout<<st1.description<<" "<<st1.partNum<<" "<<st1.cost<<endl;
       cout<<st2.description<<" "<<st2.partNum<<" "<<st2.cost<<endl;

        Product Products[5];
    for(int i=0;i<=4;i++){
             strcpy( Products[i].description, "\0");
       Products[i].partNum=0.0;
      Products[i].cost=0.0;

    }
     strcpy( Products[0].description, "screw driver");
       Products[0].partNum=456;
      Products[0].cost=5.50;

     strcpy( Products[1].description, "hammer");
       Products[1].partNum=324;
      Products[1].cost=8.20;

     strcpy( Products[2].description, "socket");
       Products[2].partNum=777;
      Products[2].cost=6.80;

       strcpy( Products[3].description, "plier");
       Products[3].partNum=123;
      Products[3].cost=10.80;

      strcpy( Products[4].description, "hand-saw");
       Products[4].partNum=555;
      Products[4].cost=12.80;

    cout<<  Products[0].description<<" "<<  Products[0].partNum<<" "<<  Products[0].cost<<endl;
       cout<<  Products[1].description<<" "<<  Products[1].partNum<<" "<<  Products[1].cost<<endl;
cout<<  Products[2].description<<" "<<  Products[2].partNum<<" "<<  Products[2].cost<<endl;
cout<<  Products[3].description<<" "<<  Products[3].partNum<<" "<<  Products[3].cost<<endl;
cout<<  Products[4].description<<" "<<  Products[4].partNum<<" "<<  Products[4].cost<<endl;


ofstream myfile;
  myfile.open ("example.txt");
   myfile <<  Products[0].description<<" "<<  Products[0].partNum<<" "<<  Products[0].cost<<endl;
       myfile<<  Products[1].description<<" "<<  Products[1].partNum<<" "<<  Products[1].cost<<endl;
myfile<<  Products[2].description<<" "<<  Products[2].partNum<<" "<<  Products[2].cost<<endl;
myfile<<  Products[3].description<<" "<<  Products[3].partNum<<" "<<  Products[3].cost<<endl;
myfile<<  Products[4].description<<" "<<  Products[4].partNum<<" "<<  Products[4].cost<<endl;

        Product Products1[5];
   ifstream infile;
   infile.open("example.txt");
   char data[100];
   infile >> data;
   cout << data << endl;
 infile >> data;
   cout << data << endl;

    return 0;
}
