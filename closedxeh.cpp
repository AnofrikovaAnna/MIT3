#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

int M = 25;
double A = (sqrt(5) - 1) / 2;

ifstream in("file.txt");
ofstream out("file1.txt");

struct people{
    string surname, post, date;
    int exp, salary;
};

vector<people> create_p(){
    vector<people> x;
    people tmp;
    while (in.peek() != EOF){
        in >> tmp.surname;
        in >> tmp.post;
        in >> tmp.date;
        in >> tmp.exp;
        in >> tmp.salary;
        x.push_back(tmp);
    }
    x.pop_back();
    return x;
}

void print1(people x){
    cout << setw(10) << left << x.surname;
    cout << setw(16) << left << x.post;
    cout << setw(11) << left << x.date << " ";
    cout << setw(3) << left << x.exp;
    cout << x.salary << '\n';
}


void pout(people x){
    out << setw(10) << left << x.surname;
    out << setw(16) << left << x.post;
    out << setw(11) << left << x.date << " ";
    out << setw(3) << left << x.exp;
    out << x.salary << '\n';
}

vector<people> create_ox(vector<people> x){
    vector<people> xtab(M);
    for (auto y : xtab){
        y.exp = 0;
    }
    for (auto y : x){
        int cur = y.exp;
        int k = int((cur * A - int(cur * A)) * M);
        int j = 0;
        while (j < M){
            int p = (k + 1 * j + 3 * j * j) % M;
            if (xtab[p].exp == 0){
                xtab[p] = y;
                break;
            }
            else{
                j++;
            }
        }
    }
    return xtab;
}

int k;
people res;

bool find(vector<people> xtab, int el){
    bool fl = false;
    k = int((el * A - int(el * A)) * M);
    int j = 0;
    vector<int> t;
    while (j < M){
        int p = (k + 1 * j + 3 * j * j) % M;
        t.push_back(p);
        if (xtab[p].exp == el && count(t.begin(), t.end(), p) == 1){
            fl =  true;
            print1(xtab[p]);
        }
        j++;
    }
    return fl;
}

int main(){
    vector<people> x;
    x = create_p();
    vector<people> xtab;
    xtab = create_ox(x);
    for (int i = 0; i < M; i++){
        if (xtab[i].exp == 0){
            out << i << '\n';
        }
        else{
            out << i << '\n';
            pout(xtab[i]);
        }
        out << '\n';
    }
    cout << "Enter the item you want to find: ";
    int el; cin >> el;
    cout << '\n';
    if (!find(xtab, el))
        cout << "Did not find" << '\n';
}