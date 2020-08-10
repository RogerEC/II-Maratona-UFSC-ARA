#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    string letra= "abcdefghijklmnopqrstuvwxyz";
    string nome = "BuscandoNovosSeguidores";
    srand(time(NULL));
    fstream arquivo;
    
    queue<int> seguidores_dia;
    int N, M, contador;
    double soma;

    for(int k=23; k<26; k++){ // loop para gerar 26 arquivos com casos de teste com entradas aleatórias
        N=(rand()%1000+1);
        M=(rand()%1000+1)*(rand()%1000+1)+N;

        arquivo.open("../Problema-B/IOs/"+nome+"-"+letra[k]+".in", fstream::out);
        //Gerando um arquivo os dados de entrada gerados aleatoriamente
        if(arquivo.is_open()){

            arquivo << N << ' ' << M <<endl;

            soma=0.0;
            for(int i=0; i<30; i++){

                seguidores_dia.push(rand()%1000+1);
                soma+=(double)seguidores_dia.back();

                if(i!=29){
                    arquivo << seguidores_dia.back() << ' ';
                }else{
                    arquivo << seguidores_dia.back() << endl;
                }
            }
            arquivo.close();
        }else{
            cout<<"Erro ao gravar arquivo de entrada letra: "<<letra[k]<<endl; 
        }

        contador = 0;
        while(N<M){ // Calculo da resposta do problema
            N+=ceil(soma/30.0);
            seguidores_dia.push(ceil(soma/30.0));
            soma+=(double)seguidores_dia.back();
            soma-=(double)seguidores_dia.front();
            seguidores_dia.pop();
            contador++;
        }
        cout<<contador<<endl;

        arquivo.open("../Problema-B/IOs/"+nome+"-"+letra[k]+".sol", fstream::out);
        // Gerando o arquivos com as saídas do problema
        if(arquivo.is_open()){
            arquivo << contador << endl;
            arquivo.close();
        }else{
            cout << "Erro ao gravar arquivo de saida letra: " << letra[k] << endl;
        }

        while(!seguidores_dia.empty())
            seguidores_dia.pop();
    }

    cout<<"Encerrado"<<endl;

    return 0;
}
