#include <iostream> //Матрица инцидентности

using namespace std;

int main()
{
    int V, E;
    cout << " Enter amount of vertexes ";
    cin >> V;
    cout << " Enter amount of edges ( <= V!) ";
    cin >> E;
    bool G[V][V];
    V = V + 1;
    E = E + 1;
    for ( int i = 1; i < V; i++)
        for ( int j = 1; j < E; j++)
            G[i][j] = false;
    cout << " Enter edges :"<< endl;
    int k,l;
    for (int i = 1; i < E; i++){
        cout << " ";
        cin >> k >> l;
        if ((k >= V) || (l >= V) || (k <= 0) || (l <= 0)){
            cout << " Error ";
            return 0;
        }
        G[k][i] = true;
        G[l][i] = true;
    }
     for ( int i = 1; i < V; i++){
        for ( int j = 1; j < E; j++){
            cout << G[i][j]<< " ";
        }
        cout << endl;
     }
    return 0;
}
