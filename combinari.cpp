#include<iostream>
using namespace std;
long long factorial(int n){
    long long fact = 1;
    for(int  i = 1; i<=n; i++ ){
        fact*=i;
    }
    return fact;

}
void combinari(){
    int n,k;
    cout<<"Introduceti n si k pentru combinari C(n,k):";
    cin>>n>>k;
    if(k>n||n<0||k<0){
        cout<<"Valori invalide.Trebuie sa fie n >=k>=0"<<endl;
    }else{
        cout<<"C("<<n<<","<<k<<")="<<factorial(n)/(factorial(k)*factorial(n-k))<<endl;
    }
}
int main(){
    combinari();
    return 0;
}