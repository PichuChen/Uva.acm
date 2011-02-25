#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string input;
    while(cin >> input){
        if(input[0] == '-')return 0;
        if(input[1] == 'x'){
            stringstream s(input);
            int i;
            s >> hex >> i;
            cout << dec << i << endl;
        }else{
            stringstream s(input);
            int i;
            s >> dec >> i;
            cout << "0x" << uppercase <<hex << i <<endl;
        }

    }
    return 0;
}
