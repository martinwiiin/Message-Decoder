#include <iostream>
using namespace std;

string Replace(string in, char a, char b){
    string out = in;
    for(int i=0; i<out.length();i++){
        if(out[i] == a){
            out[i] = b;
        }
    }

    return out;
}

string add(string in, char a, char b){
    string out = in;
    for(int i=0; i<out.length();i++){
        if(out[i] == a){
            out.insert(i+1, 1, b);
        }
    }
    return out;
}

string Remove(string in, char a){
    string out = in;
    for(int i=0; i<out.length();i++){
        if(out[i] == a){
            out.erase(i, 1);
        }
    }
    return out;
}

string Swap(string in, char a, char b){
    string out = in;
    for(int i=0; i<out.length();i++){
        if(out[i] == a){
            out[i] = b;
        }
        else if(out[i] == b){
            out[i] = a;
        }
    }
    return out;
}