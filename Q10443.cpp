#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class GameMap{
    int _x;
    int _y;
    int _times;
    vector<vector<char> > _map;
    friend istream & operator>>(istream&,GameMap&);
    friend ostream & operator<<(ostream&,GameMap&);
    void _step();
    ostream& _printMap(ostream& out);
public:
    void process();
};


bool isWin(const char a,const char b);

int main()
{
    int case_n;
    cin >> case_n;
    while(case_n--){
        GameMap map;
        cin >> map;
        map.process();
        cout << map;
        if(case_n!=0)cout <<endl;
    }

    return 0;
}

istream & operator>>(istream& in,GameMap& map){
    in >> map._y >> map._x >> map._times;
   // cout << map._y << ',' << map._x;
    for(int i=0;i<map._y;++i){

        vector<char> tmp;
        for(int j=0;j<map._x;++j){
            char tmpchar;
            in >> tmpchar;
            tmp.push_back(tmpchar);
            //cout << "["<< tmpchar<< "]" << j << 'd' <<map._x;
        }
        map._map.push_back(tmp);
        //cout << i;
    }
    return in;
}


ostream & operator<<(ostream& out,GameMap& map){


    return map._printMap(out);
}
ostream& GameMap::_printMap(ostream& out){
    for(int i=0;i<_y;++i){
        copy(_map[i].begin(),_map[i].end(),ostream_iterator<char>(out,""));
        out << endl;
    }

}
void GameMap::process(){
    while(_times--){
        _step();
        //_printMap(cout);
    }
}

void GameMap::_step(){
    vector<vector<char> > tmpmap(_y,vector<char>(_x,0));
    for(int i=0;i<_y;++i){
        for(int j=0;j<_x;++j){
            char _traget = _map[i][j];
            if((i!=0 && isWin(_map[i - 1][j],_traget)) ||
               (j!=0 && isWin(_map[i][j - 1],_traget)) ||
               (i!=_y - 1 && isWin(_map[i + 1][j],_traget)) ||
               (j!=_x - 1 && isWin(_map[i][j + 1],_traget)) ){tmpmap[i][j] = 1;}
        }
    }
    for(int i=0;i<_y;++i){
        for(int j=0;j<_x;++j){
            if(tmpmap[i][j] == 1){
                switch(_map[i][j]){
                case 'R':
                    _map[i][j] = 'P';
                    break;
                case 'S':
                    _map[i][j] = 'R';
                    break;
                case 'P':
                    _map[i][j] = 'S';
                    break;
                }
            }
        }
    }



}

bool isWin(const char a,const char b){
   // cout << a << "[" << b;
    if(a == 'R' && b == 'S')return true;
    if(a == 'S' && b == 'P')return true;
    if(a == 'P' && b == 'R')return true;
    return false;
}
