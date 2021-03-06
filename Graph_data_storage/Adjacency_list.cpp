#include <iostream> //Список смежности
#include <algorithm>
#include <vector>
using namespace std;


void list(vector <vector<int> >& G(V), int V, int E){
    for(int i = 0; i < E; i++){
        int k,l;
        cin >> k >> l;
        G[k].push_back(l);
        G[l].push_back(k);

    }
    for(int i = 0; i < V; i++)
        sort(G[i].begin(),G[i].end());
    for(int i = 0; i < V; i++){
        for(int j = 0; j < G[i].size(); j++)
            cout << G[i][j] << ", ";
        cout << endl;
    }
}


int main()
{
    int V,E;
    cout << "Enter amount of vertices and edges: ";
    cin >> V >> E;
    vector <vector<int> > G(V);
    list(G,V,E)
    return 0;
}
