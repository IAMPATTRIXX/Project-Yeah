#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

vector<string> x;
vector<string> y;
vector<int> p;
vector<int> c;
vector<float> in;
vector<float> ou;
vector<float> pr;

int main()
{
	cout<<setprecision(3)<<fixed;
	int i=0,j=0,N,M;
	float a,b;
	string s,t;
	int tax;
	
	char name[999];
	char format[]="%s %f %d";
		
	time_t rawtime;
  	struct tm * timeinfo;
  	char buffer[80];

 	time (&rawtime);
  	timeinfo = localtime(&rawtime);

  	strftime(buffer,sizeof(buffer),"%d %m %Y",timeinfo);
  	string str(buffer);
	
	ofstream inc("income.txt");
	ofstream ot("outcome.txt");
	ofstream diff("difference.txt");
	
	cout<<str<<endl;
	inc<<str<<endl;
	ot<<str<<endl;
	
	cout<<endl<<"Input income"<<endl<<endl;
	while(s!="0")
		{
			cout<<"Income "<<"["<<i+1<<"] : ";
			getline(cin,s);
			sscanf(s.c_str(),format,&name,&a,&tax);
			
			x.push_back(name);
			in.push_back(a);
			p.push_back(tax);
			i++; 
		}
		N=i;
		
		cout<<endl;
		
		for(int i=0;i<N-1;i++)
		{
			cout<<x[i]<<" : "<<in[i]<<endl;
			inc<<x[i]<<" : "<<in[i]<<endl;
		}
		
		
		cout<<endl;
		
		cout<<"Input outcome"<<endl;
	
		while(t!="0")
		{
			cout<<"Outcome "<<"["<<j+1<<"] : ";
			getline(cin,t);
			
			sscanf(t.c_str(),format,&name,&b,&tax);
			
			y.push_back(name);
			ou.push_back(b);
			c.push_back(tax);
			j++; 
		}
		M=j;
		
		cout<<endl;
		
		for(int j=0;j<M-1;j++)
		{
			cout<<y[j]<<" : "<<ou[j]<<endl;
			ot<<y[j]<<" : "<<ou[j]<<endl;
		}
	
		cout<<endl;
		
		int k;
		int sum1=0,sum2=0,sum3=0,sum4=0,ttax=0,sal=0,vat=0,novat=0,others=0;
		
		cout<<"Use Tax Calculation?"<<endl<<"1 : Yes"<<endl<<"2 : No"<<endl;
		cout<<"Your Choice : ";
		cin>>k;
		if(k==1)
		{
			int taxes;
			cout<<"Which tax type do you want to use?"<<endl; 
			cout<<"1 : For SME"<<"  "<<"2 : Normal Business"<<endl;
			cin>>taxes;
			if(taxes==1)
			{
				for(int i=0;i<N-1;i++)
				{
					sum1=sum1+in[i];
				}
				for(int i=0;i<M-1;i++)
				{
					sum2=sum2+ou[i];
				}
				
				sum3=sum1-sum2;
				
				if(sum3<0&&sum3<=300000)
				{
					ttax=0;
				}
				else if(sum3>300000&&sum3<=3000000)
				{
					ttax=sum3*0.15;
				}
				else if(sum3>3000000)
				{
					ttax=sum3*0.20;
				}
       			
				cout<<"Total Income = "<<sum1<<endl;
				inc<<"Total Income = "<<sum1<<endl;
				
				cout<<"Total Outcome = "<<sum2<<endl;
				ot<<"Total Outcome = "<<sum2<<endl;
				
				if(sum2>sum1) 
				{
					cout<<"Difference = "<<-(sum1-sum2)<<endl;
				}
				else if(sum2<sum1) 
				{
					cout<<"Difference = "<<sum1-sum2<<endl;
				}
			}
			else if(taxes==2)
			{
				for(int i=0;i<N-1;i++)
				{
					sum1=sum1+in[i];
				}
				for(int i=0;i<M-1;i++)
				{
					sum2=sum2+ou[i];
				}
				ttax=(sum1-sum2)*0.20;
				
				cout<<"Total Income = "<<sum1+sal<<endl;
				inc<<"Total Income = "<<sum1+sal<<endl;
				
				
				cout<<"Total Outcome = "<<sum2<<endl;	
				ot<<"Total Outcome = "<<sum2<<endl;
				
				cout<<"Total Tax = "<<ttax<<endl;
				
				if(sum2>sum1) 
				{
					cout<<"Difference = "<<-(sum1-sum2)<<endl;	
				}
				else if(sum2<sum1) 
				{
					cout<<"Difference = "<<sum1-sum2<<endl;
				}
			}
		}
		else if(k==2)
		{
			for(int i=0;i<N-1;i++)
			{
				sum1=sum1+in[i];
				sum2=sum2+ou[i];
			}
			
			cout<<"Total Income = "<<sum1<<endl;
			inc<<"Total Income = "<<sum1<<endl;
			
			cout<<"Total Outcome = "<<sum2<<endl;
			ot<<"Total Outcome = "<<sum2<<endl;
			
			if(sum2>sum1) 
			{
				cout<<"Difference = "<<-(sum1-sum2)<<endl;
			}
			else if(sum2<sum1) 
			{
				cout<<"Difference = "<<sum1-sum2<<endl;
			}
		}
		inc.close();
		ot.close();
		
    return 0;
}