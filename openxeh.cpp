#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

int M = 8;
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

void pout(people x){
    out << setw(10) << left << x.surname;
    out << setw(16) << left << x.post;
    out << setw(11) << left << x.date << " ";
    out << setw(3) << left << x.exp;
    out << x.salary;
}

struct list {
    people inf;
    list *next;
    list *prev;
};

void push_end(list *&h, list *&t, people x){
    list *r = new list;
    r->inf = x;
    r->next = nullptr;
    if (!h && !t){
        r->prev = nullptr;
        h = r;
    }
    else{
        t->next = r;
        r->prev = t;
    }
    t = r;
}

void print(list *h, list *t, int i){
    list *r = h;
    out << i << ' ' << '\n';
    while (r){
        pout(r->inf);
        out << '\n';
        r = r->next;
    }
    out << '\n';
}

void del(list *&h, list *&t, list *r){
    if (r == h && r == t)
        h = t = nullptr;
    else if (r == h){
        h = h->next;
        h->prev = nullptr;
    }
    else if (r == t){
        t = t->prev;
        t->next = nullptr;
    }
    else{
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    delete r;
}

vector<pair<list *, list *>> create_ox(vector<people> x){
    vector<pair<list *, list *>> xtab (M);
    for (int i = 0; i < M; i++){
        xtab[i].first = nullptr;
        xtab[i].second = nullptr;
    }
    for (int i = 0; i < x.size(); i++){
        int cur = x[i].exp;
        int k = int((cur * A - int(cur * A)) * M);
        push_end(xtab[k].first, xtab[k].second, x[i]);
    }
    return xtab;
}

void print1(people x){
    cout << setw(10) << left << x.surname;
    cout << setw(16) << left << x.post;
    cout << setw(11) << left << x.date << " ";
    cout << setw(3) << left << x.exp;
    cout << x.salary << '\n';
}

list *d = nullptr;
int k;
people res;

bool find(vector<pair<list *, list *>> xtab, int el){
    bool fl = false;
    k = int((el * A - int(el * A)) * M);
    list *r = xtab[k].first;
    while(r){
        if (r->inf.exp == el){
            d = r;
            res = r->inf;
            fl =  true;
            print1(res);
        }
        r = r->next;
    }
    return fl;
}




int main(){
    vector<people> x;
    x = create_p();
    vector<pair<list *, list *>> xtab;
    xtab = create_ox(x);
    cout << "Enter the item you want to find: ";
    int el; cin >> el;
    cout << '\n';
    if (find(xtab, el)){  
        cout << '\n' << "Delete it? (Yes/No): ";
        string ans; cin >> ans;
        if (ans == "Yes")
            del(xtab[k].first, xtab[k].second, d);
    }
    else cout << "Did not find" << '\n';
    for (int i = 0; i < xtab.size(); i++){
        print(xtab[i].first, xtab[i].second, i);
    }
}