#include <iostream>
#include <algorithm>    // FONTOS!

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

    int* ptr;   // a fgv egy pointert fog visszaadni ami A-ra mutat

    // lower_bound fgv megadja a tomb/intervallum elso olyan elemet ami nem kisebb a-nal, ha nincs ilyen, akkor a tomb vege utan mutato pointert
    // hasznalata: lower_bound(<intervallum elejere mutato pointer/iterator>,
    //                         <intervallum vege utanra mutato pointer/iterator>,
    //                         <keresett ertek>);
    ptr = lower_bound(arr, arr+N, A);

    int ind = distance(arr,ptr);    // tavolsag a tomb elejere mutato pointer (arr - a tomb maga)
                                    // esa visszaadott pointer kozott

    if(ind < N && arr[ind] == A)
        cout<<"megvan itt: "<<ind+1<<'\n';
    else
        cout<<"nincs meg\n";

    // Hasonlo fgv: upper_bound - az elso olyan elemet talalja meg, ami nagyobb A-nal
    return 0;
}