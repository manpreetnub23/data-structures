#include<iostream>
using namespace std;

template <typename T> class Matrix
{
	T* b;
	int n;
	public:
		Matrix();
		~Matrix();
		void in();
		void outT();
		void outTD();
		void outD();
		void diagonal();
		void tridiagonal();
		void lTriangle();
		void uTriangle();
		void symmetric();
};
template <typename T> Matrix<T>::~Matrix()
{
	for(int i=0;i<n;i++)
	delete [] b;
}
template <typename T> Matrix<T>::Matrix()
{
	cout<<"Enter the size of matrix(square)\n";
	cin>>n;
	if(n<1)
	throw n;
}
template <typename T> void Matrix<T>::in()
{
}
template <typename T> void Matrix<T>:: lTriangle()
{
	b = new T[n*(n+1)/2];
	cout<<"Enter the elements\n";
	T Val;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>Val;
			if(j>i&& Val!=0) throw long();
			if(i>=j)
			{
				b[i*(i+1)/2+j] = Val;
			} 
		}
	}
	outT();
	cout<<"Matrix in 2D :-\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j>i)
			cout<<0<<" ";
			if(i>=j)
			cout<<b[i*(i+1)/2+j]<<" ";
		}
		cout<<endl;
	}

}
template <typename T> void Matrix<T>:: tridiagonal()
{
	b = new T[3*n-2];
	cout<<"Enter the elements\n";
	T Val;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>Val;
			if((i-j>1||j-i>1)&& Val!=0) throw float();
			else
			{
				if(i==j+1) b[i-1] = Val;
				else if(i==j) b[n+i-1] = Val;
				else if(j==i+1) b[2*n+i-1] = Val;
			}
		}
	}
	outT();
	cout<<"Matrix in 2D :-\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) cout<<b[n+i-1]<<" ";
			else if(i==j+1) cout<<b[i-1]<<" ";
			else if(j==i+1)cout<<b[2*n+i-1]<<" ";
			else cout<<0<<" ";
	    }
		cout<<endl;
	}

}
template <typename T> void Matrix<T>:: uTriangle()
{
	b = new T[n*(n+1)/2];
	int k =0;
	cout<<"Enter the elements\n";
	T Val;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>Val;
			if(i>j&& Val!=0) throw char();
			if(j>=i)
			{
				b[k] = Val;
				k++;
			} 
		}
	}
	outT();
	cout<<"Matrix in 2D :-\n";
	for(int i=0,k=1;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i>j)
			cout<<0<<" ";
			if(j>=i)
			{
				int x=0;
				for(int k=1;k<=i;k++)
				x += (n-k+1);
				cout<<b[x + j-i]<<" ";
			}
		}
		cout<<endl;
	}

}
template <typename T> void Matrix<T>:: symmetric()
{
	b = new T[n*(n+1)/2];
	cout<<"Enter the elements\n";
	T Val;
	int k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>Val;
			if(j>=i){
			b[k] = Val;
			k++;
		    }
			if(i>j)
			{
				int x=0;
				for(int k=1;k<=j;k++)
				x += (n-k+1);
				if(b[x+i-j]!=Val) throw double();
			}
			
		}
	}
	outT();
	cout<<"Matrix in 2D :-\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i<=j)
			{
				int x=0;
				for(int k=1;k<=i;k++)
				x += (n-k+1);
				cout<<b[x + j-i]<<" ";
				
			}
			else
			{
				int x=0;
				for(int k=1;k<=j;k++)
				x += (n-k+1);
				cout<<b[x + i-j]<<" ";
			}
		}
		cout<<endl;
	}

}
template <typename T> void Matrix<T>:: diagonal()
{
	b = new T[n];
	cout<<"Enter the elements\n";
	T Val;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>Val;
			if(i!=j&&Val!=0)
			throw short();
			if(i==j) b[i] = Val;
		}
	}
	outD();
	cout<<"Matrix in 2D :-\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) cout<<b[i]<<" ";
			else cout<<0<<" ";
		}
		cout<<endl;
	}
}
template <typename T> void Matrix<T>::outT()
{
	cout<<"The matrix in 1-Dimension is :-\n";
	for(int i=0;i<n*(n+1)/2;i++)
	cout<<b[i]<<" ";
	cout<<endl;
}
template <typename T> void Matrix<T>::outTD()
{
	cout<<"The matrix in 1-Dimension is :-\n";
	for(int i=0;i<3*n-2;i++)
	cout<<b[i]<<" ";
	cout<<endl;
}
template <typename T> void Matrix<T>::outD()
{
	cout<<"The matrix in 1-Dimension is :-\n";
	for(int i=0;i<n;i++)
	cout<<b[i]<<" ";
	cout<<endl;
}
int main()
{
	char c;
	try
	{
		Matrix<int> m = Matrix<int>();
		//m.in();
		//m.diagonal();
		m.symmetric();
		//m.ltriangle();
		//m.tridiagonal();
		//m.uTriangle();
		//m.outT();
	}
	catch(short err)
	{
		cout<<"Not a diagonal matrix\n";
	}
	catch(int err)
	{
		cout<<"Sie can't be less than 1\n";
	}
	catch(long err)
	{
		cout<<"Not a Lower Triangular matrix\n";
	}
	catch(char err)
	{
		cout<<"Not a Upper Triangular matrix\n:";
	}
	catch(float err)
	{
		cout<<"Not a tridiagonal matrix\n";
	}
	catch(double err)
	{
		cout<<"Not a Symmetric matrix\n";
	}
	cin>>c;
}

