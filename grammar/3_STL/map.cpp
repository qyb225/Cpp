#include <iostream>
#include <map>
using namespace std;

template <class T>
class myLess {
public:
    bool operator()(const T &, const T &);
};
template <class STL>
void print_map(STL &);
template <class Key, class Val>
ostream& operator<<(ostream &, const pair<Key, Val>);

int main() {
    typedef map<int, double, myLess<int> > MMAP1;
    typedef map<int, double> MMAP2;
    MMAP1 a;
    MMAP2 b;
    for (int i = 0; i < 5; ++i) {
        a.insert(make_pair(i + 1, i * 3.0));
        b.insert(make_pair(i + 1, i * 1.5));
    }
    print_map(a);
    print_map(b);
    a.insert(make_pair(3, 250.0)); //ignore

    print_map(a);

    a[3] = 250;
    cout << a[3] << endl; // map[Key]
    print_map(a);

    return 0;
}

template<class T>
bool myLess<T>::operator()(const T& v1, const T& v2) {
    return v1 > v2;
}
template<class STL>
void print_map(STL & a) {
    typename STL::iterator i;
    for (i = a.begin(); i != a.end(); ++i)
        cout << *i << " ";
    cout << endl;
}
template <class Key, class Val>
ostream& operator<<(ostream & os, const pair<Key, Val> p) {
    os << "(" << p.first << ", " << p.second << ")";
}