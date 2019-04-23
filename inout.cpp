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
			cout<<"1 : Vat 7%"<<"  "<<"2 : Individual income tax (Vat calculation able)"<<endl;
			cin>>taxes;
			if(taxes==1)
			{
				for(int i=0;i<N-1;i++)
				{
					sum1=sum1+in[i];
				}
				for(int j=0;j<M-1;j++)
        		{
            		if(c[j]==1)
            		{
            			vat=vat+(ou[j]*0.07);
					}
            		sum2=sum2+ou[j];
       			}
       			cout<<"Total Income = "<<sum1<<endl;
				inc<<"Total Income = "<<sum1<<endl;
				
				cout<<"Total Outcome = "<<sum2<<endl;
				cout<<"Total Vat = "<<vat<<endl;
				ot<<"Total Outcome = "<<sum2<<endl;
				if(sum2>sum1) 
				{
					cout<<"Difference = "<<-(sum1-sum2)<<endl;
					diff<<"Difference = "<<-(sum1-sum2)<<endl;
				}
				else if(sum2<sum1) {
					cout<<"Difference = "<<sum1-sum2<<endl;
					diff<<"Difference = "<<sum1-sum2<<endl;
				}
			}
			else if(taxes==2)
			{
				for(int i=0;i<N-1;i++)
				{
					if(x[i]=="salary")
					{
						sal=sal+in[i];
						continue;
					}
					else if(x[i]!="salary") sum1=sum1+in[i];
				}
				if(sum1>5000)
				{
					others=sum1*0.005;
				}
				else others=sum1;
				
				for(int j=0;j<M-1;j++)
        		{
            		if(c[j]==1)
            		{
            			vat=vat+(ou[j]*0.07);
					}
            		sum2=sum2+ou[j];
       			}
       			
				int choice,taxde;
				
				cout<<"Do you want to predict the total tax? (with average of outcome)"<<endl;
				cout<<"1:Yes"<<"  "<<"2:No"<<endl;
				cin>>choice;
				if(choice==1)
				{
					cout<<"Input tax deduction"<<endl;
					cin>>taxde;
					while(taxde!=0)
					{
						cin>>taxde;
						sum3=sum3+taxde;
					}
					sum4=((sal+others)*12)-(sum2-sum3);
					
					if(sum4>=0&&sum4<=150000) ttax=0;
					else if(sum4>150000&&sum4<=300000) ttax=(sum4-150000)*0.05;
					else if(sum4>300000&&sum4<=500000) ttax=((sum4-300000)*0.1)+7500;
					else if(sum4>500000&&sum4<=750000) ttax=((sum4-500000)*0.15)+27500;
					else if(sum4>750000&&sum4<=1000000) ttax=((sum4-750000)*0.20)+65000;
					else if(sum4>1000000&&sum4<=2000000) ttax=((sum4-1000000)*0.25)+115000;
					else if(sum4>2000000&&sum4<=5000000) ttax=((sum4-2000000)*0.30)+365000;
					else if(sum4>5000000) ttax=((sum4-5000000)*0.35)+1265000;				
				}
				
				cout<<"Total Income = "<<sum1+sal<<endl;
				inc<<"Total Income = "<<sum1+sal<<endl;
				
				
				cout<<"Total Outcome = "<<sum2<<endl;
				cout<<"Total Vat = "<<vat<<endl;
				
				ot<<"Total Outcome = "<<sum2<<endl;
				cout<<"Total Tax = "<<ttax<<endl;
				
				if(sum2>sum1) 
				{
					cout<<"Difference = "<<-(sum1-sum2)<<endl;
					diff<<"Difference = "<<-(sum1-sum2)<<endl;
				}
				else if(sum2<sum1) 
				{
					cout<<"Difference = "<<sum1-sum2<<endl;
					diff<<"Difference = "<<sum1-sum2<<endl;
				}
			}
			else if(taxes==0)
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
				
			}
			else if(taxes==99)
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
				diff<<"Difference = "<<-(sum1-sum2)<<endl;
			}
			else if(sum2<sum1) 
			{
				cout<<"Difference = "<<sum1-sum2<<endl;
				diff<<"Difference = "<<sum1-sum2<<endl;
			}
		}
		inc.close();
		ot.close();
		
    return 0;
}