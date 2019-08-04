#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct vmi{
public:
    int a;
    int b;

    vmi(int _a, int _b){    // konstruktor, hogy hasznalhassuk a vector emplace_back fgv-et (olyan mint a push_back, csak a parametereket a megfelelo konstruktornak atadva hozza letre a struktura peldanyat)
        a = _a;
        b = _b;
    }

    vmi(){} // csak azert h a 42. sor (vmi A;) ne legyen hibas - ott ezt a konstruktort hasznalja
};

class cmp{ // osszehasonlitast vegzo osztaly
public: // itt fontos, mivel alapbol c++-ban egy osztaly minden eleme privat
    bool operator()(const vmi& a, const vmi& b) const{  // a const-ok es &-k is fontosak
        if(a.a == b.a)  // Pelda: eloszor a-n majd azon belul b-n rendezett vectoron
            return a.b < b.b;
        else
            return a.a < b.a;
    }
};

// masik peldahoz hasonlito fgv (ez a beepitett fuggvenyek/adatszerkezetek kisebb reszen mukodik
// mint a hasonlito osztaly) (de a sort/lower_bound/upper_bound -ra mukodik)
bool hasonlitoFgv(const vmi& a, const vmi& b){  // a const-ok es &-k is fontosak
    if(a.a == b.a)  // Pelda: eloszor a-n majd azon belul b-n rendezett vectoron
        return a.b < b.b;
    else
        return a.a < b.a;
}

cmp hasonlito;  // az osszehasonlito osztaly peldanya
int N;
vector<vmi> v;
vmi A;

int main(){
    cin>>N;
    int a, b;
    for (int i = 0; i < N; ++i)
    {
        cin>>a>>b;
        v.emplace_back(a,b);    // hasznalja a konstruktort majd az azzal letrehozott vmi-t rakja a vector vegere
    }

    cin>>A.a>>A.b;
    
    sort(v.begin(), v.end(), hasonlito);    // nem szukseges, csak ha elrontanank a bemenetet

    cout<<"Pelda hasonlito osztallyal:\n";
    vector<vmi>::iterator it;   // ezt fogja megadni a kereses
    it = lower_bound(v.begin(), v.end(), A, hasonlito); // keresunk a begin() es end() iteratorok kozott
    int ind = distance(v.begin(), it);

    if(it != v.end() && v[ind].a == A.a && v[ind].b == A.b)
        cout<<"megvan itt: "<<ind+1<<'\n';
    else
        cout<<"nincs meg\n";

    cout<<"Pelda hasonlito fuggvennyel:\n";
    it = lower_bound(v.begin(), v.end(), A, hasonlitoFgv);
    ind = distance(v.begin(), it);

    if(it != v.end() && v[ind].a == A.a && v[ind].b == A.b)
        cout<<"megvan itt: "<<ind+1<<'\n';
    else
        cout<<"nincs meg\n";
    
    return 0;
}