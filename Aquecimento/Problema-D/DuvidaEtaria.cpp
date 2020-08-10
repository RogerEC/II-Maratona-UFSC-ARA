#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string nome, hoje, nasc;
    int ano_hoje, ano_nasc, idade;

    getline(cin, nome);
    cin>>hoje;
    cin>>nasc;

    ano_hoje = atoi(hoje.substr(6, 4).c_str());
    ano_nasc = atoi(nasc.substr(6, 4).c_str());

    idade = ano_hoje - ano_nasc;

    hoje = hoje.substr(3,2) + hoje.substr(0, 2);
    nasc = nasc.substr(3,2) + nasc.substr(0, 2);

    if(hoje < nasc)
        idade--;
    if(hoje == nasc)
        cout<<"Feliz aniversario!"<<endl;
    cout<<"Voce tem "<<idade<<" anos "<<nome<<"."<<endl;
    
    return 0;
}
