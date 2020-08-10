#include<iostream>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int resp=0, limite;
    string mensagem;

    cin>>limite;
    while(getline(cin, mensagem)){
        if(mensagem.size()<=limite){
            resp++;
            continue;
        }else{
            for(int pos=0; pos<mensagem.size(); pos+=limite){
                while(mensagem[pos]==' ')
                    pos++;
                resp++;
            }
        }
        cout<<resp<<endl;
    }

    cout<<resp<<endl;
    
    return 0;
}
