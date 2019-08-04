#include <iostream>
#include <set> // c++ beepitett konyvtaraban a binaris keresofat set neven implementaltak

using namespace std;

struct vmi{
public:
    int a;
    int b;

    vmi(int _a, int _b){    // konstruktor, hogy hasznalhassuk a set emplace_back fgv-et (olyan mint a push_back, csak a parametereket a megfelelo konstruktornak atadva hozza letre a struktura peldanyat)
        a = _a;
        b = _b;
    }

    vmi(){} // 39-edik sorban hasznaljuk
};

class cmp{ // osszehasonlitast vegzo osztaly - a beepitett adatszerkezeteknel (pl: set) nem lehet fgv-t hasznalni helyette
public: // itt fontos, mivel alapbol c++-ban egy osztaly minden eleme privat
    bool operator()(const vmi& a, const vmi& b) const{  // a const-ok es &-k is fontosak
        if(a.a == b.a)  // Pelda: eloszor a-n majd azon belul b-n rendezett vectoron
            return a.b < b.b;
        else
            return a.a < b.a;
    }
};

int N;
set<vmi, cmp> bfa;

int main(){
    int a, b;
    int utasitas;
    do{
        cout<<"0 - berak, 1 - torol, 2 - keres, 3 - elemek felsorolasa, 4 - kilep\n";
        cin>>utasitas;
        set<vmi>::iterator it;
        vmi v;

        switch (utasitas)
        {
        case 0:
            cout<<"Adja meg a berakando erteket: ";
            cin>>a>>b;
            bfa.emplace(a,b);
            break;
        
        case 1:
            cout<<"Adja meg a torlendo erteket: ";
            cin>>a>>b;
            v = vmi(a,b);    //ezt az erteket keressuk majd
            bfa.erase(v);
            break;

        case 2:
            cout<<"Adja meg a keresendo erteket: ";
            cin>>a>>b;
            v = vmi(a,b);   //ezt az erteket keressuk
            it = bfa.find(v);

            if(it == bfa.end()) // altalaban az stl-ben a keresesek end() iteratorral ternek vissza ha nem talaljak meg a keresett erteket
                cout<<"nincs meg\n";
            else
                cout<<"megvan\n";
            break;
        
        case 3:
            cout<<"A fa "<<bfa.size()<<" db erteket tartalmaz:\n";
            it = bfa.begin();    // ezzel az iteratorral megyunk vegig a fa ertekein
            while (it != bfa.end())
            {
                cout<<(*it).a<<' '<<(*it).b<<" | ";   // az iterator altal mutatott erteket az iterator valtozo ele rakott *-al erhetjuk el
                it++;   // lepunk a kovetkezo ertekre
            }
            cout<<'\n';
            break;
        }
    } while(utasitas != 4);
    return 0;
}