//
// Created by jyh on 1/5/2019.
//

#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <numeric>
#include <memory>
#include <cstring>
#include <cmath>
#include <random>

using namespace std;
//
//class AA {
//public:
//    explicit AA(int i) : m_i(i) {}
//
//    AA() {};
//    int m_i;
//};
//
//class A {
//public:
//    int aa;
//    int a = 100;
//
//    A(int g) : a(100) {
//        cout << "construct" << endl;
//    }
//
//    ~A() {
//        cout << "delete" << endl;
//    }
//
////    A(const A &) {
////        cout << "shallow copy" << endl;
////    }
//
//    A &operator=(const A &a) {
//        cout << "===========" << endl;
//        return *this;
//    }
//
//    int b() {
//        return a;
//    }
//
//    int c() const {
//        return a;
//    }
//
//    void d() {
//        cout << "method d()" << endl;
//    }
//
//    void f() {
//        cout << "method f()" << endl;
//        e();
//    }
//
//private:
//    void e();
//};
//
//void A::e() {
//    A::d();
//    d();
//}
//
////int const A::a=10;
//class B {
//public:
//
//    A a;
//    const A &aaa;
////    int b = 0;
////    B(int b):aaa(b){
////
////       a.d();
////    }
////    A c() {
////        A a = A();
////        A c;
////        c = a;
//////        a->c();
////        return a;
////    }
//
//};
//
//class C {
//    const int a;
//    A &aa;
//    B b;
//    A c;
//
//    C(int a, A &aa, B &b, A &c) : a(a), aa(aa), b(b), c(c) {
//        cout << "C constructor" << endl;
//    };
//
//};
//
//enum week {
//    mon = 1, tus = 2, thu = 4, wed = 3, fri = 5, sat = 6, sun = 7
//};
//week day = mon;
//
//
//class D {
//public:
//    virtual void abf() = 0;
//
//    int a;
//
//
//    D &operator=(const D &d) {
////        cout << "copy: father" << endl;
//        abf();//no error but no effective.
//        return *this;
//
//    };
//
//    int returnB() {
//        return b;
//    }
//
//    void callF() {
//        normalF();
//    }
//
//private:
//    int b;
//
//    D() {
//        cout << "constructor: father1" << endl;
//        //abf();//error
//    }
//
//    D(int a, int b = 0) {
//        this->a = a;
//        this->b = b;
//        cout << "constructor: father2" << endl;
//        //abf();//error
//    }
//
//    D(D &d) {
//        cout << "copy constructor: father" << endl;
////    abf();//error
//    }
//
//    virtual void normalF() { cout << "normal function implementation: father" << endl; }
//};
////
////class E : public D {
////public:
////    E(int a){
////       this->a=a;
////    }
////    E(){}
////    void abf() override {
////        cout << "abstract function implementation" << endl;
////    }
////
////    void normalF() { cout << "normal function implementation:child" << endl; }
//////    E &operator=(const E &d){
////////        D::operator=(d);
//////        cout << "copy: child" << endl;
//////        abf();//error
//////        return *this;
//////
//////    };
//////    E(E &e):D(e){cout << "copy constructor: child" << endl;}
////
//////private:
//////    ~E(){}//just only can be constructed in heap(can not inited in stack)
////};
//
//
//void process_value(AA &A) {
//    std::cout << "LValue processed: " << A.m_i << std::endl;
//}
//
//void process_value(AA &&A) {
//    std::cout << "RValue processed: " << A.m_i << std::endl;
//}
//
//void forward_value(AA &&A) {
//    process_value(A);
//}
//
//template<typename T>
//T sum(T a, T b) {
//    return a + b;
//}

class A {
public:
    int a = 10;

    A &operator=(const A &a) {
        this->a = a.a;
        cout << "operator=" << this->a << endl;
        return *this;
    }

    explicit A(int a) {
        this->a = a;
        cout << "con" << this->a << endl;
    }

    A(A &a) {
        this->a = a.a;
        cout << "copy con" << this->a << endl;
    }

    void foo() {
        printf("1\n");
    }

    void foo(int a) {
        printf("1\n");
    }

    virtual void fun() {
        printf("2\n");
    }
};

//class B : public A
//{
//public:
//    void foo()  //隐藏：派生类的函数屏蔽了与其同名的基类函数
//    {
//        printf("3\n");
//    }
//    void fun()  //多态、覆盖
//    {
//        printf("4\n");
//    }
//};
int *func(int *a) {
    cout << a[0] << endl;
    return a + 1;
}

int f(int h, int co = 0) {
    if (h == 3)
        return 2 + co;
    else if (h == 1 || h == 2)
        return 1 + co;
    int co1 = f(h - 1, co);
    int co2 = f(h - 3, co);
    co = co1 + co2;
    return co;
}

#define n0 5
#define limit 10
struct Pttype {
    int t;
    int x[n0];
    int sw, sv, bound;

};


int accumulate(int n, int i, int **mask) {//accumalte how much number in this row of mask !=0
    int sum = 0;
    for (int j = 0; j < n; j++)
        sum += *((int *) mask + n * i + j) ? 1 : 0;
    return sum;


}

void eightqueen(int const n, int i, int **chess, int **mask, int *total) {
    /* the way of calling:
    int chess[n][n], mask[n][n];
    memset(chess, 0, sizeof(chess));
    memset(mask, 0, sizeof(mask));
    int to = 0;
    int *total = &to;
    eightqueen(n, 0, (int **) chess, (int **) mask, total);
    cout << *total << endl;
     */
    if (i == n) {//find out a solution
        for (int l = 0; l < n; l++) {
            for (int m = 0; m < n; m++) {
                if (*((int *) chess + n * l + m) == 1) {
                    cout << m;
                    break;
                }
            }

        }
        cout << endl;
        (*total) += 1;
        return;
    }
    //n is chess size and queen's number
    int t1 = 0, t2 = 0;
    for (int j = 0; j < n; j++) {
        if (*((int *) mask + n * i + j) == 0) {//0 represents this position can set a queen
            *((int *) chess + n * i + j) = 1;
            for (int k = 0; k < n; k++) {//mask writing
                *((int *) mask + n * i + k) += 1;
                *((int *) mask + n * k + j) += 1;
                t1 = i + k;
                t2 = j + k;
                if (t1 < n && t2 < n) {
                    *((int *) mask + n * t1 + t2) += 1;
                }
                t1 = i + k;
                t2 = j - k;
                if (t1 < n && t2 >= 0) {
                    *((int *) mask + n * t1 + t2) += 1;
                }
                t1 = i - k;
                t2 = j + k;
                if (t1 >= 0 && t2 < n) {
                    *((int *) mask + n * t1 + t2) += 1;
                }
                t1 = i - k;
                t2 = j - k;
                if (t1 >= 0 && t2 >= 0) {
                    *((int *) mask + n * t1 + t2) += 1;
                }
            }
            if (n > accumulate(n, i + 1, mask)) //this queen is safe
                eightqueen(n, i + 1, chess, mask, total);
            //roll back,in spaide of right or false solution
            *((int *) chess + n * i + j) = 0;
            for (int k = 0; k < n; k++) {//mask writing
                *((int *) mask + n * i + k) -= 1;
                *((int *) mask + n * k + j) -= 1;
                t1 = i + k;
                t2 = j + k;
                if (t1 < n && t2 < n) {
                    *((int *) mask + n * t1 + t2) -= 1;
                }
                t1 = i + k;
                t2 = j - k;
                if (t1 < n && t2 >= 0) {
                    *((int *) mask + n * t1 + t2) -= 1;
                }
                t1 = i - k;
                t2 = j + k;
                if (t1 >= 0 && t2 < n) {
                    *((int *) mask + n * t1 + t2) -= 1;
                }
                t1 = i - k;
                t2 = j - k;
                if (t1 >= 0 && t2 >= 0) {
                    *((int *) mask + n * t1 + t2) -= 1;
                }
            }

        }
    }
//    if (endColumn and back){//back the second time
//        int j=n;
//        *((int *) chess + n * i + j) = 0;
//                for (int k = 0; k < n; k++) {//mask writing
//                    *((int *) mask + n * i + k) = 0;
//                    *((int *) mask + n * k + j) = 0;
//                    t1 = i + k;
//                    t2 = j + k;
//                    if (t1 < n && t2 < n) {
//                        *((int *) mask + n * t1 + t2) = 0;
//                    }
//                    t1 = i + k;
//                    t2 = j - k;
//                    if (t1 < n && t2 >= 0) {
//                        *((int *) mask + n * t1 + t2) = 0;
//                    }
//                    t1 = i - k;
//                    t2 = j + k;
//                    if (t1 >= 0 && t2 < n) {
//                        *((int *) mask + n * t1 + t2) = 0;
//                    }
//                    t1 = i - k;
//                    t2 = j - k;
//                    if (t1 >= 0 && t2 >= 0) {
//                        *((int *) mask + n * t1 + t2) = 0;
//                    }
//                }
//
//
//    }
}


struct Coordinate {
    int x, y;

    Coordinate() : x(0), y(0) {}

    Coordinate(int x, int y) : x(x), y(y) {}
};

void knight(Coordinate currntP, int **chess, int len, int *a, int *b, int &total) {
/*  calling:
    int a[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int b[] = {1, -1, 1, -1, 2, -2, 2, -2};
    int len = 6;
    int chess[len][len];
    memset(chess, 0, sizeof(chess));
    int t = 1;//init 1,cause the first point is init point
    int &total = t;
    knight(Coordinate(3, 1), (int **) chess, len, a, b, total);
    */
    *((int *) chess + len * currntP.x + currntP.y) = total;
    for (int i = 0; i < 8; i++) {
        Coordinate nextP(currntP.x + a[i], currntP.y + b[i]);
        if (*((int *) chess + len * nextP.x + nextP.y) == 0 && nextP.x >= 0 && nextP.x < len && nextP.y >= 0 &&
            nextP.y < len) {
            total = total + 1;
            knight(nextP, chess, len, a, b, total);
        }

    }

    if (total == pow(len, 2)) {//this is right solution,output it
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < len; k++) {
                cout << *((int *) chess + len * j + k) << " ";
            }
            cout << "\n";
        }
        exit(1);
    } else if (total == 1) {//no solution
        cout << "no solution" << endl;
    } else {//do not compute to the last position,so roll back
        *((int *) chess + len * currntP.x + currntP.y) = 0;
        total--;
    }
}


void shellSort(int a[], int n) {//n is length of a
    /*
    calling:
    int const len=100;
    int a[len] ;
    for (int i=0;i<len;i++)
        a[i]=(int)random()%len;
    shellSort(a, len);
    copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
    */
    int increment = n;
    int tmp = 0;
    do {
        increment = increment / 3 + 1;
        for (int j = 0; j < increment; j++) {//each sub-sequence
            for (int i = j + increment; i < n; i += increment) {
                //insert sort in a sub-sequnce,first element is a[j],so insert sort begin with the second element a[j+increment]
                tmp = a[i];
                int k = i - increment;
                for (; k >= j && a[k] > tmp; k -= increment) {
                    a[k + increment] = a[k];
                }
                a[k + increment] = tmp;
            }
        }
    } while (increment > 1);
}


void merge(const int a[], Coordinate left, Coordinate right) {
    //this method also can be Recursive
    int count = 0;
    int b[right.y - left.x + 1] = {0};
    int i = left.x;
    int j = right.x;
    while (count != right.y - left.x + 1) {
        if (a[i] >= a[j]) {
            b[count] = a[j];
            count += 1;
            j++;
        } else {
            b[count] = a[i];
            count += 1;
            i++;
        }

        if (i > left.y && j <= right.y)//append the last portion of right to b
            for (int k = j; k <= right.y; k++) {
                b[count] = a[k];
                count++;
            }
        else if (i <= left.y && j > right.y)//append the last portion of left to b
            for (int k = i; k <= left.y; k++) {
                b[count] = a[k];
                count++;
            }
    }
    for (i = left.x; i <= right.y; i++)
        a[i] = b[i - left.x];

}


Coordinate mergeSort(int a[], Coordinate ind) {//Coordinate.x:start Coordinate.y:end
    /*
    calling:
    int const len = 100;
    int a[len];
    for (int i = 0; i < len; i++)
        a[i] = (int) random() % len;
    mergeSort(a, Coordinate(0, len - 1));
    copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
    */
    if (ind.x == ind.y) {//has only one element
        return ind;
    }
    Coordinate left = mergeSort(a, Coordinate(ind.x, (ind.y - ind.x) / 2 + ind.x));
    Coordinate right = mergeSort(a, Coordinate((ind.y - ind.x) / 2 + ind.x + 1, ind.y));
    //merge
    merge(a, left, right);
    return {left.x, right.y};

}

void swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void quickSort(int a[], Coordinate ind) {//baseInd:index of base element
    /*
    calling:
    int const len = 100;
    int a[len];
    for (int i = 0; i < len; i++)
        a[i] = (int) random() % len;
    quickSort(a, Coordinate(0, len - 1));
    copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
    */
    if (ind.y - ind.x < 1)//only 1 or zero element, do not need sort,this is end of program
        return;
    int base = ind.x, i = ind.x, j = ind.y + 1;
    while (i != j) {
        while (a[--j] > a[base] && i < j);
        while (i < j && a[++i] < a[base]);//note i<j is the first condition
        if (i != j) {
            // the break condition is always: i==j,in fact,this if can not use,because if i==j,it means swap the same element
            swap(a, i, j);
        }
    }
    swap(a, base, j);//swap base and the middle position,now is i==j.
    quickSort(a, Coordinate(ind.x, j - 1));
    quickSort(a, Coordinate(j + 1, ind.y));
}

void bigTopHeap(int a[], int p, int n) {//p is the last node of a tree
    if (p == 0)//adjust finished
        return;
    if ((p - 1) % 2 == 0) {//the last tree may has only left child,in this case,a[p] is left child
        if (a[(p - 1) / 2] < a[p])
            swap(a, (p - 1) / 2, p);
        bigTopHeap(a, p - 1, n);//the tree before current tree
    } else {//the tree has two children, a[p] is right child,and a[p-1] is left child
        if (a[(p - 1) / 2] < a[p] && a[p] >= a[p - 1]) {
            //swap with right child,it may cause the right tree is disordered,so sort the right child once again
            swap(a, (p - 1) / 2, p);
            if (p * 2 + 2 <= n)//p is not leaf node with two leaf child
                bigTopHeap(a, p * 2 + 2, n);
            else if (p * 2 + 1 <= n)//p is not leaf nodew ith one leaf child
                bigTopHeap(a, p * 2 + 1, n);

        } else if (a[(p - 1) / 2] < a[p - 1] && a[p] < a[p - 1]) {
            //swap with left child,it may cause the left tree is disordered,so sort the left child once again
            swap(a, (p - 1) / 2, p - 1);
            if ((p - 1) * 2 + 2 <= n)//p is not leaf node with two leaf child
                bigTopHeap(a, (p - 1) * 2 + 2, n);
            else if ((p - 1) * 2 + 1 <= n)//p is not leaf node with one leaf child
                bigTopHeap(a, (p - 1) * 2 + 1, n);
        }
        bigTopHeap(a, p - 2, n);//the tree before current tree
    }

}

void heapSort(int a[], int n) {//n is the last element index of heap
    /*
    calling:
    int const len = 100;
    int a[len];
    for (int i = 0; i < len; i++)
        a[i] = (int) random() % len;
    heapSort(a, len - 1);
    copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
     */
    //init the big top heap
    bigTopHeap(a, n, n);
    int lastNode = n;
    while (lastNode != 0) {//equal to 0 present there is only the root node,so ,it is finished.
        swap(a, 0, lastNode);
        lastNode--;
        int p = 0;
        while (p * 2 + 1 <= lastNode) {//p is not a leaf node
            if (p * 2 + 1 == lastNode && a[p] < a[p * 2 + 1]) {//p has only left node, i.e.,the last tree
                swap(a, p, p * 2 + 1);
                break;
            } else {//p has two leaf node
                if (a[p * 2 + 1] > a[p] && a[p * 2 + 1] >= a[p * 2 + 2]) {//swap with left leaf
                    swap(a, p, p * 2 + 1);
                    p = p * 2 + 1;
                } else if (a[p * 2 + 2] > a[p] && a[p * 2 + 2] > a[p * 2 + 1]) {//swap with right leaf
                    if (p * 2 + 2 <= lastNode) {
                        //cause while loop only limit p * 2 + 1 <= lastNode,so maybe p * 2 + 2 > lastNode,this is the last leaf
                        // in this case,it can not do swap(a, p, p * 2 + 2)
                        swap(a, p, p * 2 + 2);
                        p = p * 2 + 2;
                    } else break;
                } else break;
            }
        }

    }

}

int maxValue(const int a[], int n) {
    int maxV = a[0];
    for (int i = 1; i < n; i++)
        if (maxV < a[i])
            maxV = a[i];
    return maxV;

}

void bucketSort(int a[], int n) {//n is length of a
    /*
    calling:
    int const len = 100;
    int a[len];
    for (int i = 0; i < len; i++)
        a[i] = (int) random() % len;
    bucketSort(a, len);
    copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
     */
    //find the max value
    int maxV = maxValue(a, n);
    int const numBucket = 10;
    int subNum = maxV / numBucket + 1;//divide to 10 sub-sets
    int *bucket[numBucket] = {nullptr};
    int num[numBucket] = {0};
    for (int i = 0; i < n; i++) {//throw into buckets
        if (bucket[a[i] / subNum] == nullptr)
            bucket[a[i] / subNum] = new int(0);//ptr must be init before used
        bucket[a[i] / subNum][num[a[i] / subNum]++] = a[i];
    }
    int len = 0;
    for (int i = 0; i < numBucket; i++) {//sort in each bucket
        quickSort(bucket[i], Coordinate(0, num[i] - 1));
        for (int j = 0; j < num[i]; j++)
            a[len + j] = bucket[i][j];
        len += num[i];
    }
}


void babbelSort(int a[], int n) {
    /*
    calling:
    int const len=100;
    int a[len] ;
    for (int i=0;i<len;i++)
        a[i]=(int)random()%len;
    babbelSort(a, len);
    copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
    */

//version 1
//    int tmp=0;
//    for(int i =0;i<n;i++){
//        for(int j =i+1;j<n;j++){
//            if (a[j]<a[i]){
//             tmp=a[i];
//             a[i]=a[j];
//             a[j]=tmp;
//            }
//        }
//    }

    //version 2
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
            }
        }
    }

}

class AA {
public:
    AA() {
        a = 10;
        std::cout << "construct" << std::endl;
    }

    AA &operator=(const AA &a) {
        std::cout << "operator=" << std::endl;
        return *this;
    }

    ~AA() { std::cout << "delete" << std::endl; }

    AA(const AA &a) {
        std::cout << "copy" << std::endl;
        this->a = a.a;
    }

    static const int b;//can init,if init here,it can not be assign other value again
    static int c;//cannot init
    int a;
};

const AA aaa() { return AA(); }

AA &bbb() {
    AA a = AA();
    AA &b = a;
    return b;
}

AA ab(const AA &a) {
    return a;
}

int AA::c = 10;
const int AA::b = 10000;

int main(int argv, char **args) {
    int const len = 100;
    int a[len];
    for (int i = 0; i < len; i++)
        a[i] = (int) random() % len;
    bucketSort(a, len);
    copy(begin(a), end(a), ostream_iterator<int>(cout, " "));
//int *b=new int(0), len = 0,*c=b;
//cout << &b << endl<<*b << endl<<*c << endl<<&c<< endl << endl<<b << endl<<c <<endl;
//    int *t=new int(1);
//    AA a = aaa();
//    std::cout << a.a << std::endl;
//    a.a=1100;
//    std::cout << a.a << std::endl;
//    const AA &b = bbb();
//    std::cout << b.a << std::endl;

//
//    int a[3][3]={0};
//    cout<<a[2][2]<<endl;
//    int a[]={1,2,3,4};
//    int *b=a;
//    for(int i=0;i<4;i++)
//        b=func(b);
//    cout << f(50) << endl;
//    branchknap();
//    A a(1);
//    A b(a);
//    A c = a;
//    A d(2),f(3),g(4);
//    d=f=g;
//    const int a=1;
//    int b(a);
//    b=10;
//    int *a;
//    int b=0;
//    a=&b;
//    cout<<*a<<endl;
//    *a=b;
//    cout<<*a<<endl;
//    cout<<a<<endl;
}

//    A a;
//    B b;
//
//    const int f=0;
//    const int *ff=&f;
//    const int &fff=0;
//    const int *ffff=&fff;
//
//    A *p = &a;
//    p->foo();  //输出1
//    p->fun();  //输出2
//    p = &b;
//    p->foo();  //取决于指针类型，输出1
//    p->fun();  //取决于对象类型，输出4，体现了多态
//    p->foo(1);
//    return 0;
//
//int main() {
//    char (*s)[2];//ptr array,it is equal to char s[2][2]
//    char b[2][2]={{'a','v'},{'a','v'}};
//    s=b;
//    int *p[3];//array ptr,it also is equal to s[2][2]
//    int a=1;
//    p[0]=&a;
//    p[1]=&a;
//    int *const c=&a;
//    int aa=10;
//    const int *d=&a;
//    d=&aa;
//    cout<<a<<endl;


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
