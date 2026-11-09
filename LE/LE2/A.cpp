#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MOD = 101;

class HashMap{
    public:
    static int hashFn(const string& s){
        int soma = 0;
        for (int i = 0; i < (int)s.size(); i++){
            soma += (int)s[i] * (i + 1);
        }
        return (19 * soma) % MOD;
    }

    static int posicao(int h, int j){
        return(h + (j * j) + 23 * j) % MOD;
    }

    static int busca(const vector<string>& tab, const string& chave){
        int h = hashFn(chave);
        for (int i = 0; i < 20; i++){
            int idx = posicao(h, i);
            if (tab[idx] == chave) {return idx;}
        }
        return -1;
    }

    static void inserir (vector<string>& tab, const string& chave){
        if (busca(tab, chave) != -1) {return;}

        int h = hashFn(chave);
        for (int i = 0; i < 20; i++){
            int idx = posicao(h, i);
            if (tab[idx].empty()){
                tab[idx] = chave;
                return;
            }
        }
    }

    static void remover(vector<string>& tab, const string& chave){
        int idx = busca(tab, chave);
        if (idx != -1) {tab[idx] = "";}
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        int qtd_acoes; cin >> qtd_acoes;

        vector<string> hmap(MOD);
        while(qtd_acoes--){
            string info; cin >> info;
            int pos = info.find(':');
            string comando = info.substr(0, pos);
            string chave = info.substr(pos + 1);

            if (comando == "ADD"){
                HashMap::inserir(hmap, chave);
            }
            else if (comando == "DEL"){
                HashMap::remover(hmap, chave);
            }
        }

        int qte = 0;

        for (int i = 0; i < MOD; i++){
            if (!hmap[i].empty()){qte++;}
        }

        cout << qte << endl;

        for (int i = 0; i < MOD; i++){
            if (!hmap[i].empty()){
                cout << i << ":" << hmap[i] << endl;
            }
        }

    }

    return 0;
}