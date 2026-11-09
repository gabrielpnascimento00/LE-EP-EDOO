#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()

template <typename tip_chav, typename tip_val>
class Dicionario{
    int tamanho;

    vector<vector<pair<tip_chav, tip_val>>> tabela;

    int indice(const tip_chav& chave){
        hash<tip_chav> h;
        return h(chave) % tamanho;
    }

    public:
        Dicionario(int n = 10) : tamanho(n), tabela(n) {}

        void inserir (const tip_chav& chave, const tip_val& valor){
            auto& gaveta = tabela[indice(chave)];
            for (auto& par : gaveta){
                if (par.first == chave){
                    par.second = valor;
                    return;
                }
            }
            gaveta.push_back({chave, valor});
        }

        bool buscar(const tip_chav& chave, tip_val& valor){
            for (auto& par : tabela[indice(chave)]){
                if (par.first == chave){
                    valor = par.second;
                    return true;
                }
            }
            return false;
        }

        void remover(const tip_chav& chave){
            auto& gaveta = tabela[indice(chave)];

            for (int i = 0; i < (int)gaveta.size(); i++){
                if (gaveta[i].first == chave){
                    gaveta.erase(gaveta.begin() + i);
                    return;
                }
            }
        }

        vector<pair<tip_chav, tip_val>> itens(){
            vector<pair<tip_chav, tip_val>> ans;
            for (auto& gaveta : tabela){
                for (auto& par : gaveta){
                    ans.push_back(par);
                }
            }
            return ans;
        }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Dicionario<int, int> dicio(100001);

    int tam; cin >> tam;

    for (int i = 0; i < tam; i++){
        int num; cin >> num;
        int x = 0;
        if (dicio.buscar(num, x)) {dicio.inserir(num, x + 1);}
        else {
            dicio.inserir(num, 1);
        }
    }

    vector<pair<int, int>> arr_ans = dicio.itens();

    int ans = 0;

    for (auto [chav, valor] : arr_ans){
        if (valor == chav){continue;}

        if (valor > chav){
            ans += valor - chav;
        }
        else if (valor < chav){
            ans += valor;
        }
    }

    cout << ans;

    return 0;
}