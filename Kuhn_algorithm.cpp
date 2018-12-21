#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool try_kuhn (vector <vector<int> >& G,int v, vector<bool>& used, vector<int>& mt){
	if (used[v])  return false;//увеличивающая цепь есть
	used[v] = true;
	for (int i=0; i<G[v].size(); ++i) {
		int to = G[v][i];
		if (mt[to] == -1 || try_kuhn (G,mt[to],used,mt)) {//есть ли увеличивающая цепь (идем по стрелочкам)2
			mt[to] = v;
			return true; //не были в вершине 2 доли
		}
	}
	return false;
}

void list(vector <vector<int> >& G, int V, int E){

    cout  << endl << " Enter edges: ";
    for(int i = 0; i < E; i++){
        int k,l;
        cin >> k >> l;
        G[k].push_back(l);
    }
    for(int i = 0; i < V; i++)
        sort(G[i].begin(),G[i].end());
}
int main(){
    int V,E,N;
    cout << "Enter amount of vertices in 1 and 2: ";
    cin >> V >> N;
    cout << endl << "Enter amount of edges: ";
    cin >> E;
    vector <vector<int> > G(V);
    list(G,V,E);
    vector<int> mt;
    vector<bool> used;
	mt.assign (V, -1);
	int v;
	for (int v = 0; v < N; v++) {
		used.assign (N, false);//обнуляем посещенные вершины
		try_kuhn (G,v,used,mt);
	}

	for (int i=0; i<V; ++i)
		if (mt[i] != -1)
			cout << mt[i]  << " " << i << endl;
    return 0;
}
