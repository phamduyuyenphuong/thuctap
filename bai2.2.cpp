#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct ngaythang
{
	int day,month, year;
}NgayThang;
// chuyen so ra chuoi
void chuoi( string st,NgayThang &x);
int NamNhuan(int year);
int stt(NgayThang x);
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int NgayTuSTT(int stt, int year);
int congNgayThang(NgayThang x, int a);

int main()
{
	ngaythang x;
	int year;
	string st;
	int a;
	cout <<"nhap du lieu ";
	getline(cin,st);
	chuoi(st,x);
	cout<<endl;
		NamNhuan(year); 
	cout<<NamNhuan(x.year)<<endl;
	cout<<stt(x)<<endl;
	cout<<"nhap a";
	cin>>a;
	 cout<<congNgayThang(x,a);
}

void chuoi(string st,NgayThang &x) {
	
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
int stt(NgayThang x)
{
	int stt=0;
	for(int i =0; i< x.month; i++)
	stt+=month[i];
	stt += x.day;
	if(NamNhuan==0 && x.month>2) stt+=1;
	return stt;

}

int NgayTuSTT(int stt, int year){
	int i=1;
	int ngay = stt;
	int kt = NamNhuan(year);
	while(stt > 0){
		if((kt == 1) && (i==2))// neu nam nhuan va thang 2
			stt = stt - 29; //stt se tru cho 29 ngay 
		else 
			stt = stt - month[i];// stt tru cho so ngay trong thang i
				if(stt > 0)
				{
					ngay = stt;
					i++;
				}	
	
	
				
	}
	
}
int congNgayThang(NgayThang x, int a)// a<=365
{
	int kq= a + stt(x);
	int year=x.year;
	if(kq <= 365)
		return NgayTuSTT(kq,year);
	else
		if(NamNhuan(year)==1)
			if(kq == 366)
				return NgayTuSTT(kq,year);
			else
				return NgayTuSTT(kq-366,year+1);
		else
			return 	NgayTuSTT(kq-365,year+1);
	// a> 365
		int KQ = a + stt(x);	
		NgayThang t;
	t.year = x.year;
	t.month = 1;
	t.day = 0;
	while(a > 365)
		for(KQ; KQ >= 366; KQ=366)
		{
			if(NamNhuan(t) == 0)
				KQ++;
			t.year++; 
		}
	
						
}



