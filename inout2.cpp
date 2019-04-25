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

vector<float> inr;
vector<string> f;
vector<int> sort;

vector<float> allt;

int main()
{
	cout<<setprecision(3)<<fixed;
	int i=0,j=0,N,M;
	float a,b;
	string s,t;
	int tax;
	int sor;
	
	char name[999];
	char format[]="%s %f %d";
		
	time_t rawtime;
  	struct tm * timeinfo;
  	char buffer[80];

 	time (&rawtime);
  	timeinfo = localtime(&rawtime);

  	strftime(buffer,sizeof(buffer),"%d %m %Y",timeinfo);
  	string str(buffer);
	string time;
	
	time=str;
	str=str+" 1"+".txt";
				

	int tax1,am=0,O,D=0;
		
	char name2[999];
	char format1[]="%s %f";
	float ar;
	
	ifstream g;
	ofstream nor(str.c_str());
	
	string filename;
	string textline;
	
	cout<<time<<endl;
	
					
	cout << "Enter a day mon year to read: ";
	getline(cin,filename);		
	
	filename=filename+" 1"+".txt";
							
	g.open(filename.c_str());
				
	while(getline(g,textline))
	{
		cout<<textline<<endl;
		scanf(textline.c_str(),format1,&name2,&ar);
		f.push_back(name2);
		inr.push_back(ar);
		am++;
	}
	O=am;						
	for(int i=0;i<O;i++)
	{
		cout<<f[i]<<endl;
		cout<<inr[i]<<endl;	
	}	
	
	cin.ignore();
	
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
		}
		cout<<endl;
		
		int k;
		double sum1=0,sum2=0,sum3=0,sum4=0,ttax=0,sal=0,vat=0,novat=0,others=0;
		
		cout<<"Use Tax Calculation?"<<endl<<"1 : Yes"<<endl<<"2 : No"<<endl<<endl;
		cout<<"Please enter : ";
		cin>>k;
		cout<<endl;
		if(k==1)
		{
			int taxes;
			cout<<"Which tax type do you want to use?"<<endl<<endl; 
			cout<<"1 : Vat 7%"<<"  "<<"2 : Individual income tax (Vat calculation able)"<<endl;
			cout<<"Please enter : ";
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
				
				cout<<"Total Outcome = "<<sum2<<endl;
				
				cout<<"Total Vat = "<<vat<<endl;
				
				if(sum2>sum1) 
				{
					cout<<"Difference = "<<-(sum1-sum2)<<endl;
				}
				else if(sum2<sum1) {
					cout<<"Difference = "<<sum1-sum2<<endl;
				}
			}
			else if(taxes==2)
			{
				for(int i=0;i<N-1;i++)
				{
					if(x[i]=="salary")
					{
						sal=sal+in[i];
						nor<<"Salary "<<sal<<endl;
						continue;
					}
					else if(x[i]!="salary") 
					{
						sum1=sum1+in[i];
					}
				}
				if(sum1>5000)
				{
					others=sum1*0.005;
				}
				else others=sum1;
				
				nor<<"Others "<<others<<endl;
				
				for(int j=0;j<M-1;j++)
        		{
            		if(c[j]==1)
            		{
            			vat=vat+(ou[j]*0.07);
					}
            		sum2=sum2+ou[j];
       			}
       			
				nor<<"Outcome "<<sum2<<endl;
				
				cout<<endl;
				
				int choice,taxde,tc=0;
				
				
				cout<<"Input tax deduction"<<endl;
				cout<<"Deduction list "<<"["<<tc+1<<"]"<<": ";
				cin>>taxde;
				while(taxde!=0)
				{
					cout<<"Deduction list "<<"["<<tc+1<<"]"<<": ";
					cin>>taxde;
					sum3=sum3+taxde;
				}
				
				nor<<"Taxreduce "<<sum3<<endl;
				
				cout<<endl;
				
				cout<<"Predict the total tax? (with average of income/outcome)"<<endl<<"1:Yes"<<"  "<<"2:No"<<endl;
				cout<<"Please enter : ";
				cin>>choice;
				cout<<endl;
				if(choice==1)
				{

					sum4=((sal+others)*12)-((sum2)*365)-sum3;
					
					if(sum4>=0&&sum4<=150000) ttax=0;
					else if(sum4>150000&&sum4<=300000) ttax=(sum4-150000)*0.05;
					else if(sum4>300000&&sum4<=500000) ttax=((sum4-300000)*0.1)+7500;
					else if(sum4>500000&&sum4<=750000) ttax=((sum4-500000)*0.15)+27500;
					else if(sum4>750000&&sum4<=1000000) ttax=((sum4-750000)*0.20)+65000;
					else if(sum4>1000000&&sum4<=2000000) ttax=((sum4-1000000)*0.25)+115000;
					else if(sum4>2000000&&sum4<=5000000) ttax=((sum4-2000000)*0.30)+365000;
					else if(sum4>5000000) ttax=((sum4-5000000)*0.35)+1265000;				
				
					cout<<"Total Income = "<<sum1+sal<<endl;
					cout<<"Total Outcome = "<<sum2<<endl;
					cout<<"Total Vat = "<<vat<<endl;
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
				else if(choice==2)
				{	  
					return 0;
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
			nor<<"Total Income = "<<sum1<<endl;
			
			cout<<"Total Outcome = "<<sum2<<endl;
			
			if(sum2>sum1) 
			{
				cout<<"Difference = "<<-(sum1-sum2)<<endl;
			}
			else if(sum2<sum1) 
			{
				cout<<"Difference = "<<sum1-sum2<<endl;
			}
		}
		nor.close();
	
    return 0;
}