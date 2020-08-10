#include<iostream>
#include<cmath>
#include<queue>

using namespace std;

int main(){
    queue<int> seguidores_dia;
    int N, M, contador=0, aux;
    double soma=0.0;

    cin>>N>>M;

    for(int i=0; i<30; i++){
        cin>>aux;
        soma+=(double)aux;
        seguidores_dia.push(aux);
    }

    while(N<M){
        N+=ceil(soma/30.0);
        seguidores_dia.push(ceil(soma/30.0));
        soma+=seguidores_dia.back();
        soma-=seguidores_dia.front();
        seguidores_dia.pop();
        contador++;
    }

    cout<<contador<<endl;

    return 0;
}
