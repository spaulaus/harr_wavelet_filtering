#include <math.h>
#include <vector>
#include <stdio.h>
#include <complex.h>
#include <iostream>
#include <fstream>

using namespace std;

#define N 64
#define PI 3.141592654

int main()
{

  vector<double> instuff(N), ave(N), diff(N);
  double a=0, b=0, c=0;
  double alpha, beta, gamma;

  for(a=0; a < N; a++)
    {
      instuff[a] = 0;
    }

  ifstream inputFile;
  inputFile.open ("trace_start.txt");
  
  for( a=0; a < N; a++)
    inputFile >> instuff[a];

  inputFile.close();
    
  
  for (a=N; a>1; a/=2)
    {
      for (b=0; b<a/2; b++)
	{
	  ave[b] = (instuff[2*b] + instuff[2*b + 1]) / 2;
	  diff[b] = instuff[2*b] - ave[b];
	}
      
      for (b=0; b<a/2; b++)
	{
	  instuff[b] = ave[b];
	  instuff[b + a/2] = diff[b];
	}
    }
  
  for(a=0; a < N; a++)
    {
      cout << instuff[a] << endl;
    }
  
  return 0;
}
