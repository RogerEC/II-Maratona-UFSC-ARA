#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    string letra= "abcdefghijklmnopqrstuvwxyz";
    string nome = "AniversarioDoTobias";
    vector<string> cores = {"azul", "vermelho", "cinza", "preto", "verde", "branco", "amarelo", "rosa", "roxo", "laranjado", "marrom", "anil","turquesa","dourado","prata","bege","vinho","bordo","purpura", "violeta"};
    srand(time(NULL));
    fstream arquivo;
    vector<long long int> fatorial;
    map<string, int> baloes;
    int N, B, soma, soma_max, B_aux;
    long long int aux;
    string cor, cor_aux;
    bool flag = false;
    vector<pair<string, int>> entradas;

    fatorial.push_back(1); // Calculando previamente o fatorial até 20!
    for(int i=1; i<=20; i++){
        fatorial.push_back(fatorial[i-1]*i);
    }

    for(int k=0; k<26; k++){ // loop para gerar 26 arquivos com casos de teste com entradas aleatórias

        soma_max=0;
        flag = false; // Essa flag garante que o arquivo tenha pelo menos 1 entrada
        while(true){
            if(flag && rand()%5==0) // condição para gerar alguns arquivos com menos entradas que o limite máximo
                break;

            if(soma_max>=20) // condição que para o loop se atingido o limite máximo for atingido
                break;

            B_aux = rand()%3+1;

            if(B_aux+soma_max>=20){
                B_aux =20-soma_max;
                soma_max=20;
            }else{
                soma_max+=B_aux;
            }

            cor_aux = cores[rand()%cores.size()];
            flag=true;
            entradas.push_back(make_pair(cor_aux, B_aux)); 

            if(baloes.find(cor_aux)!=baloes.end()){ // carregando os dados gerados aleatóriamente na estrutura original do programa
                baloes[cor_aux]+=B_aux;
            }else{
                baloes.insert(make_pair(cor_aux, B_aux));
            }
        }

        soma=soma_max;
        cout<<soma<<endl;//

        arquivo.open("../Problema-A/IOs/"+nome+"-"+letra[k]+".in", fstream::out);
        //Gerando um arquivo os dados de entrada gerados aleatoriamente
        if(arquivo.is_open()){
            arquivo<<entradas.size()<<endl;

            for(int i=0; i<entradas.size(); i++)
                arquivo << entradas[i].first << ' ' << entradas[i].second << endl;

            arquivo.close();
        }else{
            cout<<"Erro ao gravar arquivo de entrada letra: "<<letra[k]<<endl; 
        }

        aux=1; // realizando o calculo da saída com os dados aleatórios gerados
        for(map<string, int>::iterator it=baloes.begin(); it!=baloes.end(); it++){
            aux*=fatorial[it->second];
        }

        arquivo.open("../Problema-A/IOs/"+nome+"-"+letra[k]+".sol", fstream::out);
        // Gerando o arquivos com as daídas do problema
        if(arquivo.is_open()){
            arquivo << "Feliz aniversario Tobias!" << endl;
            arquivo << fatorial[soma]/aux << endl;
            arquivo.close();
        }else{
            cout << "Erro ao gravar arquivo de saida letra: " << letra[k] << endl;
        }
        baloes.clear();
        entradas.clear();
    }

    cout<<"Encerrado"<<endl;

    return 0;
}
