#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Nhap vao so nguyen to: " ;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=i; j--){
            cout << " ";
        }
        for(int k=0; k<=i; k++){
            cout << " ";
            cout << static_cast<char>(i+65);
        }
        cout << "\n";
    }
    return 0;
}