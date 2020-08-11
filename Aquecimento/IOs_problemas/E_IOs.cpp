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
    string LETRAS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string nome = "ExcelBugado";
    string aux;
    vector<string> codigos;
    int limite, tam;
    srand(time(NULL));
    fstream arquivo;
    int mult, resp;

    for(int k=21; k<26; k++){ // loop para gerar 26 arquivos com casos de teste com entradas aleatórias

        limite=200000;
        for(int i=0; i<limite; i++){
            tam=rand()%3+1;
            for(int j=0; j<tam; j++)
                aux+=LETRAS[rand()%LETRAS.size()];
            codigos.push_back(aux);
            aux.clear();
        }

        arquivo.open("../Problema-E/IOs/"+nome+"-"+letra[k]+".in", fstream::out);
        //Gerando um arquivo os dados de entrada gerados aleatoriamente
        if(arquivo.is_open()){
            for(int i=0; i<limite; i++)
                arquivo<<codigos[i]<<endl;
            arquivo.close();
        }else{
            //cout<<"Erro ao gravar arquivo de entrada letra: "<<letra[k]<<endl; 
        }

        arquivo.open("../Problema-E/IOs/"+nome+"-"+letra[k]+".sol", fstream::out);
        // Gerando o arquivos com as daídas do problema
        if(arquivo.is_open()){
            for(int i=0; i<limite; i++){
                if(codigos[i].size()>3){
                    arquivo<<"Essa coluna nao existe Tobias!"<<endl;
                }else{
                    if(codigos[i].size()==3 && codigos[i] > "XFD")
                        arquivo<<"Essa coluna nao existe Tobias!"<<endl;
                    else{
                        mult=1;
                        resp=0;
                        for(int j=codigos[i].size()-1; j>=0; j--){
                            resp+=(int)(codigos[i][j]-'A'+1)*mult;
                            mult*=26;
                        }
                        arquivo<<resp<<endl;
                    }
                }
            }
            arquivo.close();
        }else{
            //cout << "Erro ao gravar arquivo de saida letra: " << letra[k] << endl;
        }
        codigos.clear();
    }

    return 0;
}