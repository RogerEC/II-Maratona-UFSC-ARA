#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<long long int> fatorial;
    map<string, int> baloes;
    int N, B, soma=0;
    long long int aux=1;
    string cor;

    fatorial.push_back(1);
    for(int i=1; i<=20; i++){
        fatorial.push_back(fatorial[i-1]*i);
    }

    cin>>N;

    for(int i=0; i<N; i++){
        cin>>cor>>B;
        soma+=B;
        if(baloes.find(cor)!=baloes.end()){
            baloes[cor]+=B;
        }else{
            baloes.insert(make_pair(cor, B));
        }
    }

    for(map<string, int>::iterator it=baloes.begin(); it!=baloes.end(); it++){
        aux*=fatorial[it->second];
    }

    cout<<"Feliz aniversario Tobias!"<<endl;
    cout<<fatorial[soma]/aux<<endl;

    return 0;
}
