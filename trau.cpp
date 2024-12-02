#include <cstdlib>
#include <iostream>
#include <fstream>
#define fni "input.txt"
#define fno "ans.txt"
using namespace std;
int a[1005][1005],n,m;

bool maxduongcheo(int i, int j)
  {
      int k,h;
      for (k=i,h=j; k>=0 && h<m; k--, h++)
          if (a[k][h] > a[i][j])
              return false;

      for (k=i+1, h=j-1; k<n && h>=0; k++, h--)
          if (a[k][h] > a[i][j])
            return false;

      for (k=i-1, h =j-1; k>=0 && h>=0; k--,h--)
          if (a[k][h] > a[i][j])
              return false;

      for (k=i+1, h=j+1; k<n && h<m; k++, h++)
          if (a[k][h] > a[i][j])
              return false;

      return true;
  }
  bool maxdongcot(int i, int j)
  {
      for (int k=0; k<n; k++ )
       if (a[k][j]>a[i][j])

                   return false;


      for (int k=0; k<m; k++ )

      if (a[i][k]>a[i][j])
                 return false;
  return true;
  }
void doc()
{
    ifstream ifi(fni);
    ifi>>n;
    ifi>>m;
     for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
         ifi>>a[i][j];
    ifi.close();

}

void xuat()
{
     ofstream ofo(fno);
     int d=0;
      for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        if(maxduongcheo(i,j) && maxdongcot(i,j))
            {
                ofo << i + 1 << ' ' << j + 1 << endl;
            }
//        ofo<<d;
     ofo.close();
}


int main(int argc, char *argv[])
{
    doc();
    xuat();

    return EXIT_SUCCESS;
}
