#include<iostream>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string linha;
    bool flag = false;

    while(getline(cin, linha)){

        if(linha.find("<body>") != string::npos){
            flag = true;
            continue;
        }else if(linha.find("</body>") != string::npos){
            flag = false;
        }

        if(flag)
            cout<<linha<<endl;
    }

    return 0;
}