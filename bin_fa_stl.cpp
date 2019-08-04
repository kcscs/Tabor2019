#include <iostream>
#include <set> // c++ beepitett konyvtaraban a binaris keresofat set neven implementaltak

using namespace std;

int N;
set<int> bfa;

int main(){
    int a;
    int utasitas;
    do{
        cout<<"0 - berak, 1 - torol, 2 - keres, 3 - ertekek felsorolasa, 4 - kilep\n";
        cin>>utasitas;
        set<int>::iterator it;

        switch (utasitas)
        {
        case 0:
            cout<<"Adja meg a berakando erteket: ";
            cin>>a;
            bfa.insert(a);
            break;
        
        case 1:
            cout<<"Adja meg a torlendo erteket: ";
            cin>>a;
            bfa.erase(a);
            break;

        case 2:
            cout<<"Adja meg a keresendo erteket: ";
            cin>>a;
            it = bfa.find(a);

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
                cout<<(*it)<<' ';   // az iterator altal mutatott erteket az iterator valtozo ele rakott *-al erhetjuk el
                it++;   // lepunk a kovetkezo ertekre
            }
            cout<<'\n';
            
            break;
        }
    } while(utasitas != 4);
    return 0;
}