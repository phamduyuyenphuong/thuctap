#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct ngaythang
{
	int day,month, year;
}NgayThang;
// chuyen so ra chuoi
void chuoi(const string &st,NgayThang x);
int NamNhuan(int year);
int main()
{
	ngaythang x;
	int year;
	string st;
	cout <<"nhap du lieu ";
	getline(cin,st);
	chuoi(st,x);
	cout<<endl;
	cout<<"nhap nam";
	cin>>year;
	NamNhuan(year); 
	cout<<NamNhuan;
}

void chuoi(const string &st,NgayThang x) {
	
	 x.day = atoi(st.substr(0, 2).c_str()); 
	 cout<<x.day;
	x.month = atoi(st.substr(3, 2).c_str()); 
	cout<<x.month;
     x.year = atoi(st.substr(6, 4).c_str());
   cout<<x.year ;

}
int NamNhuan(int year)
{

	if( (year%400==0) || (year%4==0 && year%100!=0))
	return 1;
	else
	 return 0;

}



