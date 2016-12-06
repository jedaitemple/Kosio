#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    int n;
    int a[1000];

        cin>>n;
  int c=0;
  int i=2;
        while(c<=500){
            i++;
        for (int j=2; j*j<=i; j++)
        {
            if (i % j == 0)
                break;
            else if (j+1 > sqrt(i)) {

                a[c++]=i;
            }

        }
        }
        i=0;
while(n>0){
    if(a[i]==a[i+1]-2){
        cout<<a[i]<<" "<<a[i+1]<<"\n";
        n=n-1;

    }
    i++;
}
    return 0;
}
