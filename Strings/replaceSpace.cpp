#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void TraverseString(string &str, int N)
{ 
    for (int i = 0; i < N; i++) {
        if(str[i] == ' ') str.replace(i, 1, "@40");
    }
    cout<<str<<endl;
}

int main() {
    string str = "hello world hiii";
    int N = str.length();
    cout<<str.length()<<endl;
    TraverseString(str, N);
    cout<<str.size()<<endl;
    cout<<str[5];
    return 0;
}