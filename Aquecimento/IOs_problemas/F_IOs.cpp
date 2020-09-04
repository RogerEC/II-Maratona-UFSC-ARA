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
    string base = "abcdefghij klmnopqrstuvwxyz ABCDEFGHIJKLMNOP QRSTUVWXYZ01234 56789!\"#$%&'()*+, -./:;<>=?@[]\\^_` {}|~";
    string letra= "abcdefghijklmnopqrstuvwxyz";
    string nome = "FugindoDoCelular";

    srand(time(NULL));
    fstream entrada, saida;
    int limite, N, M, pos, resp;
    string mensagem, aux;
    const int LIM1 = 3000; // limite do número de mensagens
    const int LIM2 = 990; // Limite da quantidade de caracteres exibidos na tela do celular
    const int LIM3 = 10000; // Limite da quantidade de caracteres por linha da mensagem recebido

    for(int k=24; k<25; k++){ // loop para gerar 26 arquivos com casos de teste com entradas aleatórias
        entrada.open("../Problema-F/IOs/"+nome+"-"+letra[k]+".in", fstream::out);
        saida.open("../Problema-F/IOs/"+nome+"-"+letra[k]+".sol", fstream::out);
        //Gerando um arquivo os dados de entrada gerados aleatoriamente
        if(entrada.is_open()){
            if(saida.is_open()){
                limite = rand()%LIM2+10;
                N = rand()%LIM1+2;
                entrada << limite <<endl;
                resp=0;
                for(int i=0; i<N; i++){
                    M = rand()%LIM3+1;
                    for(int j=0; j<M; j++){
                        if(j==0 || j==(M-1)){
                            do{
                                aux=base[rand()%base.size()];
                            }while(aux==" ");
                            mensagem += aux;
                        }else{
                            mensagem+=base[rand()%base.size()];
                        }
                    }
                    entrada << mensagem << endl;

                    pos=0; // calculo da solução
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
                    mensagem.clear();
                }
                saida << resp <<endl;
                saida.close();
            }else{
                cout<<"Erro ao gravar arquivo de saida letra: " << letra[k] << endl;
            }
            entrada.close();
        }else{
            cout << "Erro ao gravar arquivo de entrada letra: " << letra[k] << endl; 
        }
    }

    cout<<"Encerrado"<<endl;

    return 0;
}
