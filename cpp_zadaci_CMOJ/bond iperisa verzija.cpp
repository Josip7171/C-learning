#include <cstdio>
#include<iostream>

using namespace std;
int a[6];
char op[6]; 


	
void rek( int dubina, int rez )
{
	if( dubina == 5 )
	{
		if( rez == a[5] )
		{
			for( int i = 0; i < 5; ++i )
			if (i==4){
				cout<<a[i]<<"=";
			}else if(i!=4){
				cout<<a[i]<<op[i+1];
			}
			cout<<a[5]<<endl;
		}
		return;
	}
	for( int i = 0; i < 4; ++i )
		if( i == 0 ) 
		{ 
			op[dubina] = '+'; rek( dubina+1, rez + a[dubina] ); 
		}
		else if( i == 1 ) 
		{	
			op[dubina] = '-'; rek( dubina+1, rez - a[dubina] ); 
		}
		else if( i == 2 ) 
		{ 
			op[dubina] = '*'; rek( dubina+1, rez * a[dubina] ); 
		}
		else if( i == 3 )
		{
			op[dubina] = '/'; rek( dubina+1, rez / a[dubina] );
		}
}

int main( )
{
	for( int i = 0; i < 6; ++i )
		cin>>a[i];
		
	rek( 1, a[0] );

	return 0;
}