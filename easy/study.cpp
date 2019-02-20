//
// Created by jyh on 1/5/2019.
//

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <numeric>
#include <memory>

using namespace std;

class AA {
public:
    explicit AA(int i) : m_i(i) {}

    AA() {};
    int m_i;
};

class A {
public:
    int aa;
    int a = 100;

    A(int g) : a(100) {
        cout << "construct" << endl;
    }

    ~A() {
        cout << "delete" << endl;
    }

//    A(const A &) {
//        cout << "shallow copy" << endl;
//    }

    A &operator=(const A &a) {
        cout << "===========" << endl;
        return *this;
    }

    int b() {
        return a;
    }

    int c() const {
        return a;
    }

    void d() {
        cout << "method d()" << endl;
    }

    void f() {
        cout << "method f()" << endl;
        e();
    }

private:
    void e();
};

void A::e() {
    A::d();
    d();
}

//int const A::a=10;
class B {
public:

    A a;
    const A &aaa;
//    int b = 0;
//    B(int b):aaa(b){
//
//       a.d();
//    }
//    A c() {
//        A a = A();
//        A c;
//        c = a;
////        a->c();
//        return a;
//    }

};

class C {
    const int a;
    A &aa;
    B b;
    A c;

    C(int a, A &aa, B &b, A &c) : a(a), aa(aa), b(b), c(c) {
        cout << "C constructor" << endl;
    };

};

enum week {
    mon = 1, tus = 2, thu = 4, wed = 3, fri = 5, sat = 6, sun = 7
};
week day = mon;


class D {
public:
    virtual void abf() = 0;

    int a;


    D &operator=(const D &d) {
//        cout << "copy: father" << endl;
        abf();//no error but no effective.
        return *this;

    };

    int returnB() {
        return b;
    }

    void callF() {
        normalF();
    }

private:
    int b;

    D() {
        cout << "constructor: father1" << endl;
        //abf();//error
    }

    D(int a, int b = 0) {
        this->a = a;
        this->b = b;
        cout << "constructor: father2" << endl;
        //abf();//error
    }

    D(D &d) {
        cout << "copy constructor: father" << endl;
//    abf();//error
    }

    virtual void normalF() { cout << "normal function implementation: father" << endl; }
};
//
//class E : public D {
//public:
//    E(int a){
//       this->a=a;
//    }
//    E(){}
//    void abf() override {
//        cout << "abstract function implementation" << endl;
//    }
//
//    void normalF() { cout << "normal function implementation:child" << endl; }
////    E &operator=(const E &d){
//////        D::operator=(d);
////        cout << "copy: child" << endl;
////        abf();//error
////        return *this;
////
////    };
////    E(E &e):D(e){cout << "copy constructor: child" << endl;}
//
////private:
////    ~E(){}//just only can be constructed in heap(can not inited in stack)
//};


void process_value(AA &A) {
    std::cout << "LValue processed: " << A.m_i << std::endl;
}

void process_value(AA &&A) {
    std::cout << "RValue processed: " << A.m_i << std::endl;
}

void forward_value(AA &&A) {
    process_value(A);
}

template <typename T>
T sum(T a,T b){
    return a+b;
}

int main() {
    cout<<sum<int>(1,2)<<endl;
char argv11[]={'1','v'};
char *argv1=argv11;
cout<<&argv1[0+1]<<&argv11<<endl;
char b='1';
char *ar=&b;

//    vector<int>a{1,2,3,4,5,6,7};
//    int c=0;
//    int minV=4;
//    int b=accumulate(begin(a),end(a),c,
//    [minV](int accV,int curV){return curV<minV?accV:accV+curV;});
//    cout<<b<<endl;

//    map<string,string>m;
//    m.insert(make_pair<string,string>("1","2"));
//    cout<<m.at("1")<<endl;

//   AA a(1);
//   AA & b=a;
//   cout<<&b<<endl;
//   b=AA(10);
//   cout<<&b<<endl;
//   AA c(2);
//   b= move(c);
//    cout<<&b<<endl;
// AA a(1);
// process_value(a);
// process_value(AA(2));
// forward_value(AA(2));
}
//int main() {
//    int a[]={1,2,3,4,5};
//    cout<<accumulate(begin(a),end(a),0)<<endl;
//    unique_ptr<string> p(new string("sadasdas"));
//    shared_ptr<string> pp(new string("sadasdas"));
//    shared_ptr<string>ppp(pp);
//    cout<<*pp<<endl;
//    pp->append("tttttt");
//    cout<<*ppp<<endl;

//    E e(10);
//    e.callF();
////    e.abf();
////    e.normalF(10);
////    e.D::normalF();
//cout<<e.a<<" "<<e.D::a<<e.D::returnB()<<endl;
//    E ee;
//    ee=e;
////    E eee=e;
////    C c;
//    AA a=AA(10);
//    AA *b=&a;
//    AA b(1);
//    AA c();
//    A a;
//    a.d();
//    a.f();
//    string a="asadsfadas";
////    cout<<a[20]<<endl;//output error:@
////    cout<<a.at(20)<<endl;//throw exception: out_of_range
//
//    cout<<a.capacity()<<endl;
//    a+="sssss";
//    cout<<a.capacity()<<endl;
//    a+="s";
//    cout<<a.capacity()<<endl;
//
//    cout<<a.max_size()<<endl;
//    cout<<a.size()<<endl;
//    cout<<a.length()<<endl;
