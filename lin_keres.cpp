#include <iostream>
#define MAX_N 1000000   // hasznos, hogy kesobb egy helyrol lehessen valtoztatni

using namespace std;

int N; //elemek szama
int A; //keresett elem
int arr[MAX_N];

int main(){

    cin>>N;
    for(int i = 0; i < N; ++i)
        cin>>arr[i];
    
    cin>>A;

    //Tobb fele keppen lehet, most csak az A elemig keresunk ha benne van
    int ind = 0; //aktualis index
    while(ind < N && arr[ind] != A) //fontos, hogy a tomb veget tesztelo feltetel legyen elobb
                                    //mert akkor ha az nem teljesul a szgep mar nem ertekeli ki az es (&&)
                                    //kovetkezo reszet ami hibat okozna
        ++ind;

    //ha a ciklus veget ert, ket lehetoseg van:
    if(ind < N) // a masodik feltetel miatt lepett ki (az elso meg teljesul)
        cout<<"megvan itt: "<<ind+1<<'\n';  //tehat ind helyen van A
    else
        cout<<"nincs benne\n"; // vegig ert a tombon tehat nincs benne

    return 0;
}