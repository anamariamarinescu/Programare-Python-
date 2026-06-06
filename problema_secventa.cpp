// Se citesc din fișierul de intrare in.txt n numere naturale nenule, separate prin spații.
//  Să se tipărească într-un fişier out.txt cea mai lungă secvenţă de elemente din şir cu
// proprietatea că oricare două valori consecutive în secvenţă au parităţi diferite.
#include <bits/stdc++.h>
using namespace std;
ifstream fin("in.txt");
ofstream fout("out.txt");
int main()
{
    int v[100];
    int n, st=0, dr=0, st_m = 0, dr_m = 0, ct=1, ct_m = 0;
    fin >> n;
    fin >> v[0];
    for (int i = 1; i < n; i++)
    {
        fin >> v[i];
        if (v[i] % 2 != v[i - 1] % 2)
        {
            dr = i;
            ct++;
        }
        else
        {
            st=i;
            dr=i;
            ct=1;
        }
        
         if (ct > ct_m)
        {
            st_m = st;
            dr_m = dr;
            ct_m = ct;
        }
    }
   fout <<"Lungimea Maxima este:"<<ct_m<<"\n";
    for (int i = st_m; i <= dr_m; i++)
    {
        fout << v[i] << " ";
    }

    fin.close();
    fout.close();
}