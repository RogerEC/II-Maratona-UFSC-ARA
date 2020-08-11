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
    string nome = "CopiandoEColandoCodigo";
    srand(time(NULL));
    fstream arquivo, saida;
    string linha;
    bool flag;

    for(int k=0; k<26; k++){ // loop para gerar 26 arquivos com casos de teste com entradas aleatórias
        cout<<k<<endl;
        arquivo.open("../Problema-C/IOs/"+nome+"-"+letra[k]+".in", fstream::in);
        saida.open("../Problema-C/IOs/"+nome+"-"+letra[k]+".sol", fstream::out);
        //Gerando um arquivo os dados de entrada gerados aleatoriamente
        if(arquivo.is_open()){
            if(saida.is_open()){
                flag=false;
                while(getline(arquivo, linha)){

                    if(!flag && linha.find("<body>") != string::npos){
                        flag = true;
                        continue;
                    }else if(linha.find("</body>") != string::npos){
                        flag = false;
                    }

                    if(flag)
                        saida<<linha<<endl;
                }
                saida.close();
            }else{
                cout<<"Erro ao gravar arquivo de saida letra: "<<letra[k]<<endl; 
            }
            arquivo.close();
        }else{
            cout<<"Erro ao ler arquivo de entrada letra: "<<letra[k]<<endl; 
        }

        /*arquivo.open("../Problema-C/IOs/"+nome+"-"+letra[k]+".sol", fstream::out);
        // Gerando o arquivos com as daídas do problema
        if(arquivo.is_open()){
            arquivo << endl;
            arquivo.close();
        }else{
            cout << "Erro ao gravar arquivo de saida letra: " << letra[k] << endl;
        }*/
    }

    cout<<"Encerrado"<<endl;

    return 0;
}
