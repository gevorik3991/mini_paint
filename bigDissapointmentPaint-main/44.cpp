#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n , kap;
	cin >> n >> kap;
	int m[n][2];

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			m[j][i] = a;
		}
	}
	int imin = 0, jmax = 1, jbest = 1, ibest = 0, j = 0;
	bool f = 0;
   for(int j = 0; j < n - 1; j++)
   {
       if(m[j-1][0] < m[imin][0])
       {
           imin = j-1;
       }
       if(m[j][1] > m[jmax][1])
       {
           jmax = j;
       }
       int kolak, kolbest;
       kolak = kap / m[imin][0];
       kolbest = kap / m[ibest][0];
       if((jmax > imin) && (m[jmax][1] > m[imin][0]) && (kolak*m[jmax][1] >= kolbest*m[jbest][1]))
       {
           jbest = jmax;
           ibest = imin;
           f = 1;
       }
   }
   if(f == 0)
   {
       cout << kap << endl;
       cout << -1 << " " << -1;
   }
   else
    {
       int kolak;
       kolak = kap / m[ibest][0];
        if(kolak == 0){
            cout << kap << endl;
            cout << -1 << " " << -1;
        }
       else{
            int prib;
            prib = kolak * m[jbest][1];
            cout << prib << endl;
            cout << ibest + 1<< " " << jbest + 1;

       }

    }

}
