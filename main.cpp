#include <iostream>
#include <vector>
#include <string>
#include"sample.h"
#include"Mismatch.h"
using namespace std;

class PartA{

public:
    string X,Y;
    vector<int> indices_x, indices_y;
    string final_x, final_y;

    PartA(string X, string Y, vector<int> indices_x, vector<int> indices_y);

    // Generate the final stirng from str
    string input_string_generator(string str, vector<int> indices);

    // Check whether the final string is 2^j*str.length
    bool validate_string(string str);
};

PartA::PartA(string X, string Y, vector<int> indices_x, vector<int> indices_y){
    this->X = X; this->Y = Y;
    this->indices_x = indices_x; this->indices_y = indices_y;
}

string PartA::input_string_generator(string str, vector<int> indices){

    string final(str), cummulative(str);

    for(auto i: indices){
        string s = str.substr(0, i+1);

        s += cummulative;
        s += str.substr(i+1, (int)str.size());
        //cout << s << endl;
        str = s;cummulative = s;
    }

    return str;
}

int main(){

    string X,Y;
    vector<int> indices_x, indices_y;

    cin >> X;

    int j = 3;
    while(j--){
        int temp;
        cin >> temp;
        indices_x.push_back(temp);
    }

    cin >> Y;

    int k = 3;
    while(k--){
        int temp;
        cin >> temp;
        indices_y.push_back(temp);
    }

    PartA p(X, Y, indices_x, indices_y);

    p.final_x = p.input_string_generator(p.X, p.indices_x);
    p.final_y = p.input_string_generator(p.Y, p.indices_y);

    cout << p.final_x << endl << p.final_y ;

    Dynamic *s= new Dynamic();
    Mismatch *m = new Mismatch();

    int gapPenality ;
    cin >> gapPenality;
    s->getminimum(p.final_x,p.final_y,m->values,)
    return 0;
}