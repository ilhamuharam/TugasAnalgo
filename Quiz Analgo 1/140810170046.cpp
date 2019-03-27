/*********************
Nama		: Ilham Muharam
NPM			: 140810170046
Kelas		: B
Deskripsi	: Quiz Analisis Algoritma (Merge Sort)
**********************/

#include <iostream>
#include <time.h>
using namespace std;

void merge(int low, int mid, int up);
void mergeSort(int low, int up);

int a[50];

int main()
{
    clock_t t1,t2;
    t1=clock();
    
    {	
		int jumlahBil,i;
		
		cout<<"Merge Sort"<< endl;
		cout<<"-----------------------------"<< endl;
		cout<<" "<<endl;
		cout<<"Masukkan Jumlah element Array"<< endl;
		cin>>jumlahBil;
		cout<<endl;
		
		for(int i=0; i<jumlahBil;i++)
		{
			cout<<"Bilangan ke-"<< i+1 << endl;
			cin>>a[i];
		}
	
		cout<<endl;
		cout<<"Hasil Merge Sort"<< endl;
		mergeSort(1,jumlahBil);
	
		for(i=1;i<=jumlahBil;i++)
		cout<<a[i]<<"    ";
		cout<<endl<<endl;
	}
    
    t2=clock();
    float diff ((float)t2-(float)t1);
    float second=diff/CLOCKS_PER_SEC;
    cout<<"Runtime = "<<second;
    cout<<endl;
    
    system ("pause");
    return 0;
    
}

void merge(int low, int mid, int up)
{
	int h, i,j,k;
	int b[50];
	h = low;
	i = low;
	j = mid+1;
	
	while((h<=mid)&&(j<=up))
	{
		if(a[h] < a[j])
		{
			b[i]=a[h];
			h++;
		}
		
		else
		{
			b[i]=a[j];
			j++;
		}

		i++;
	}

	if(h>mid)
	{
		for(k=j;k<=up;k++)
		{
			b[i]=a[k];
			i++;
		}
	}

	else
	{
		for(k=h;k<=mid;k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	
	for(k=low;k<=up;k++) a[k]=b[k];
}

void mergeSort(int low, int up)
{
	int mid;
	if(low<up)
	{
		mid=(low+up)/2;
		mergeSort(low,mid);
		mergeSort(mid+1,up);
		merge(low,mid,up);
	}
}
