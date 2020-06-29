#include <iostream>
#include <cmath>

using namespace std;

class enters{
public:
    double znach;
    double weight;
    enters();
    enters(double z, double w);
    enters(const enters &other);
    operator= (const enters &other){
        this->znach=other.znach;
        this->weight=other.weight;
        return this->znach && this->weight;
    }
};

enters::enters(){
    znach=0;
    weight=0;
}

enters::enters(double z, double w){
    znach=z;
    weight=w;
}
//Конструктор копирования:
enters::enters(const enters &other){
    this->znach=other.znach;
    this->weight=other.weight;
}

class neuronon{
public:
    //class enters *x;

    double y;
    neuronon(int length);
    void result();
    //neuronon(const class neuronon &a);
    //~neuronon();
    };


neuronon::neuronon(int length){
    class enters x[length];
    //double *znach;
    //double *weight;
    double h=0, buf1, buf2;
    //cout<<"length: "<<length<<"\n";
    for(int i=0; i<length; i++){
        cout<<"Vvedite znachenie "<< i+1 <<"-go vhoda i ego ves\n";
        cin >> buf1 >> buf2;
        x[i].znach=buf1;
        x[i].weight=buf2;
    }
    for (int i=0; i<length; i++){
        h=h+x[i].znach*x[i].weight;
    }
    y=1./(1.+exp(-h));
}

void neuronon::result(){
    cout<<y;
}

int show(neuronon &obj){
    obj.result();
    return 0;
}

int main()
{
    int length;
    cin >> length;
    neuronon Neuron_1(length);
    show(Neuron_1);
    return 0;
}
