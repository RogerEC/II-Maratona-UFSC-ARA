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
    string let = "ABCDEF GHIJKLMNOPQRSTU VWXYZabcdefghijk lmnopqrstuvw xyz";
    string nome = "DuvidaEtaria", let_aux, nome2;
    srand(time(NULL));
    fstream arquivo;
    vector<string> nomes = {"Ritcheli Daniel", "Lucas Guedes", "Calinca", "Davi", "Jose Carlos", "Maria", "Ana", "Lola"};
    int mes, dia, ano1, ano2;
    int ano_hoje, ano_nasc, idade;
    string nasc, hoje;

    for(int k=2; k<10; k++){ // loop para gerar 26 arquivos com casos de teste com entradas aleatórias

        mes=rand()%12+1;
        dia=rand()%30+1;
        if(mes==2 && dia>28)
            dia=28;
        ano1=rand()%9999+1;
        ano2=ano1+rand()%50+1;
        if(ano1==ano2 && ano1!=1)
            ano1--;
        else{
            ano1++;
        }
        nasc=to_string(min(ano1, ano2));
        while(nasc.size()<4) nasc="0"+nasc;
        hoje=to_string(max(ano1, ano2));
        while(hoje.size()<4) hoje="0"+hoje;

        nasc=to_string(mes)+"/"+nasc;
        nasc = (nasc.size()!=7)? nasc = "/0"+nasc:"/"+nasc;
        mes=rand()%12+1;
        hoje=to_string(mes)+"/"+hoje;
        hoje = (hoje.size()!=7)? hoje = "/0"+hoje:"/"+hoje;

        nasc = to_string(dia)+nasc;
        nasc = (nasc.size()!=10)? nasc = "0"+nasc:nasc;
        dia=rand()%28+1;
        hoje = to_string(dia)+hoje;
        hoje = (hoje.size()!=10)? hoje = "0"+hoje:hoje;
        
        dia=rand()%48+3;
        nome2=nomes[k-2];

        arquivo.open("../Problema-D/IOs/"+nome+"-"+letra[k]+".in", fstream::out);
        if(arquivo.is_open()){
            arquivo<<nome2<<endl;
            arquivo<<hoje<<endl;
            arquivo<<nasc<<endl;
            arquivo.close();
        }else{
            cout<<"Erro ao gravar arquivo de entrada letra: "<<letra[k]<<endl; 
        }

        ano_hoje = atoi(hoje.substr(6, 4).c_str());
        ano_nasc = atoi(nasc.substr(6, 4).c_str());

        idade = ano_hoje - ano_nasc;

        hoje = hoje.substr(3,2) + hoje.substr(0, 2);
        nasc = nasc.substr(3,2) + nasc.substr(0, 2);

        arquivo.open("../Problema-D/IOs/"+nome+"-"+letra[k]+".sol", fstream::out);
        // Gerando o arquivos com as daídas do problema
        if(arquivo.is_open()){
            if(hoje < nasc)
                idade--;
            if(hoje == nasc)
                arquivo<<"Feliz aniversario!"<<endl;
            arquivo<<"Voce tem "<<idade<<" anos "<<nome2<<"."<<endl;
            arquivo.close();
        }else{
            cout << "Erro ao gravar arquivo de saida letra: " << letra[k] << endl;
        }
        nome2.clear();
    }

    cout<<"Encerrado"<<endl;

    return 0;
}
