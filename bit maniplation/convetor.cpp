#include<bits/stdc++.h>
using namespace std;

string binary(int num){
    string ans = "";
    while(num != 0){
        if(num % 2 == 0) ans += "0";
        else ans += "1";
        num = num / 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int decimal(string num){
    int ans = 0;
    int p = 0;
    for(int i = 0; i <= num.size(); i++){
        if(num[i] == '1') {
            p = pow(2,i);
            ans += p;   
    }

    return ans;
}

int main(){
    int num;
    cout << "Enter the Nummber: ";
    cin >> num;

    cout << "Binary : " << binary(num) << endl;

    string binary = "";
    cout << "Enter the Binary number: ";
    cin >> binary;

    cout << "Decimal : "<< decimal(binary);
}