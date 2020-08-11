#include<iostream>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int resp=0, limite, pos;
    string mensagem;

    cin>>limite;
    while(getline(cin, mensagem)){
        pos=0;
        while(pos<mensagem.size()){
            resp++;
            if(pos+limite >= mensagem.size()){
                break;
            }else{
                pos+=limite;
                while(mensagem[pos]==' ')
                    pos++;
            }
        }
    }

    cout<<resp<<endl;
    
    return 0;
}
