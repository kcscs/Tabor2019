#include <iostream>
#define MAX_N 1000000

using namespace std;

int N; //elemek szama
int A; //keresett elem
int arr[MAX_N]; // FONTOS: arr elemei novekvo sorban vannak

int main(){

    cin>>N;
    for(int i = 0; i < N; ++i)
        cin>>arr[i];    // FONTOS: arr elemei novekvo serban vannak
    
    cin>>A;

    // aktualis keresesi tartomany: [bal;jobb[ intervallum
    int bal = 0; // az aktualis keresesi tartomany bal szele
    int jobb = N; // az aktualis keresesi tartomany jobb szele (kivulrol)
    int ind = N/2; // az aktualis vizsgalt index

    bool megvan = false;    // ezzel jelezzuk majd h a ciklus miert ert veget

    while (bal < jobb)  // ha bal == jobb, akkor a keresesi intervallum uresre szukult tehat biztosan nem lehet benne A
    {
        if(arr[ind] == A){  // megtalaltuk
            megvan = true;
            bal = jobb; // hogy a ciklus befejezodjon
        } else {
            if(A < arr[ind])  // mivel arr elemei novekvo sorban vannak ezert biztosan nem lehet A ind utan
                jobb = ind; // az intervallum bal felet tartjuk meg
            else
                bal = ind + 1; // az intervallum jobb felet tartjuk meg (ind+1 mert arr[ind] != A)
            
            ind = (bal+jobb)/2; // a kovetkezo vizsgalt elem az uj intervallum kozepen van
        }
    }
    
    // ha megtalaltuk, akkor megvan-t igazra allitottuk  -  egyebkent hamis maradt
    if(megvan)
        cout<<"megvan itt: "<<ind+1<<'\n';
    else
        cout<<"nincs benne\n";

    /*
    Erdemes meggondolni:
    - Hogyan modositsuk a programot, hogy csokkeno tombon mukodjon?
    - Ha a tomb A-t nem tartalmazza, a ciklus mindig a legkisebb, A-nal nagyobb elem indexenel er veget  -  Miert?
    - Hogyan modositsuk, hogy a legnagyobb A-nal kisebb elemnel erjen veget? (2 fele keppen is lehet)
    - Mi tortenik, ha tobb A is szerepel a tombben?
    - Hogyan erjuk el, hogy ekkor ezek kozul az elsot/utolsot talalja meg?
     */
}