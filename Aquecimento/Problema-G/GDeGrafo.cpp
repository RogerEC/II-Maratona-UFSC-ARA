#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

#define w first
#define u second.first
#define v second.second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
vector<int> conjunto;

void criar_conjunto(int TAM){
    if(!conjunto.empty())
        conjunto.clear();
    for(int i=0; i<TAM; i++)
        conjunto.push_back(INT_MAX);
}

int buscaConjunto(int el){
    if(conjunto[el]!=INT_MAX){
        conjunto[el]=buscaConjunto(conjunto[el]);
        return conjunto[el];
    }
    return el;
}

bool uniao(int el1, int el2){
    if(buscaConjunto(el1)!=buscaConjunto(el2)){
        conjunto[buscaConjunto(el1)]=buscaConjunto(el2);
        return true;
    }
    return false;
}

bool menor(pair<int, pii> a, pair<int, pii> b) {return a.w<b.w;}

int main()
{
    vector<pair<int, pii>> aresta;
    int N, M, U, V, W, aux;

    cin>>N>>M;
    cin>>aux;
    for(int i=0; i<M; i++){
        cin>>U>>V>>W;
        U--; V--;
        aresta.pb(mp(W, mp(U, V)));
    }

    criar_conjunto(N);

    sort(aresta.begin(), aresta.end(), menor);

    int soma=0;
    for(int i=0; i<M; i++){
        if(uniao(aresta[i].u, aresta[i].v))
            soma+=aresta[i].w;
    }

    cout<<soma*2<<endl;

    return 0;
}
