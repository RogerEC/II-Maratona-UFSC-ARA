#include<iostream>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int resp, mult;
    string codigo;

    while(cin>>codigo){
        if(codigo.size()>3){
            cout<<"Essa coluna nao existe Tobias!"<<endl;
        }else{
            if(codigo.size()==3 && codigo > "XFD")
                cout<<"Essa coluna nao existe Tobias!"<<endl;
            else{
                mult=1;
                resp=0;
                for(int i=codigo.size()-1; i>=0; i--){
                    resp+=(int)(codigo[i]-'A'+1)*mult;
                    mult*=26;
                }
                cout<<resp<<endl;
            }
        }
    }
    
    return 0;
}
