#include <iostream>
using namespace std;
 
void Reverse(char *s,int n){
    for(int i=0,j=n-1;i<j;i++,j--){
        char c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}
 
int main()
{

    pair<int,int> p;

    char s[]="helloworld";
 
    Reverse(s,10);
 
    cout<<s<<endl;
 
    return 0;
}