#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <vector>
#include <cctype>
#include <fstream>

using namespace std;

struct Date
{
    int month, day, year;
};

struct Bank
{
    float deposit;
    string inf;
    vector<string> recinfor;
    vector<int> m;
    vector<int> d;
    vector<int> y;
    vector<float> depo;
    int input;
    float sum;
    int in;
};
void firstmenu()
{
    cout << "**********************************"
         << "\n";
    cout << "MAIN MENU"
         << "\n";
    cout << "\n";
    cout << "DEPOSIT MENU [1]"
         << "\n";
    cout << "INTEREST MENU [2]"
         << "\n";
    cout << "EXIT [0]"
         << "\n";
    cout << "**********************************"
         << "\n";
    cout << "INPUT HERE : ";
}

void depositfirstmenu()
{
    cout << "**********************************"
         << "\n";
    cout << "DEPOSIT MENU"
         << "\n"
         << "\n";

    cout << "DEPOSIT,WITHDRAW [1]"
         << "\n";
    cout << "SEARCHING [2]"
         << "\n";
    cout << "BACK [0]"
         << "\n";
    cout << "**********************************"
         << "\n";
    cout << "INPUT HERE : ";
}
void interestfirstmenu()
{
    cout << "**********************************"
         << "\n";

    cout << "INTEREST MENU"
         << "\n"
         << "\n";
    cout << "ALL MONEY IN YOUR BANK [1]"
         << "\n";
    cout << "INTEREST[2]"
         << "\n";
    cout << "BACK [0]"
         << "\n";
    cout << "**********************************"
         << "\n";
    cout << "INPUT HERE : ";
}

int findingnemo(string x, vector<string> y)
{

    for (int i = 0; i < y.size(); i++)
    {
        if (x == y[i])
        {
            return i;
        }
    }
}
int findingnemoint(int x, vector<int> y)
{
    for (int i = 0; i < y.size(); i++)
    {
        if (x == y[i])
        {
            return i;
        }
        else
            return 0;
    }
}
int findingnemodeposit(float x, vector<float> y)
{
    for (int i = 0; i < y.size(); i++)
    {
        if (x == y[i])
        {
            return i;
        }
    }
}
int searchingfrominf(vector<string> inf)
{
    string searching;
    cout << "Input information of deposit: ";
    getline(cin, searching);
    for (int i = 0; i < searching.size(); i++)
    {
        searching[i] = toupper(searching[i]);
    }
    return findingnemo(searching, inf);
}
int searchingfromdate(vector<int> day)
{
    int searching;
    cout << "input day of deposit: ";
    cin >> searching;
    return findingnemoint(searching, day);
}
int searchingfromdeposit(vector<float> deposit)
{
    float searching;
    cout << "Input amount of deposit: ";
    cin >> searching;
    return findingnemodeposit(searching, deposit);
}

int menufindingdeposit()
{
    int choice;
    cout << "Do you want to find something";

    cout << "Find from inf ?  [1]"
         << "\n";

    cout << "Find from date ? [2]"
         << "\n";

    cout << "Find from deposit ? [3]"
         << "\n";

    cout << "INPUT : ";
    cin >> choice;
    cin.ignore();
    return choice;
}
int menufidingwithdraw()
{
    int choice;
    cout << "Do you want to find something";

    cout << "Find from inf ?  [1]"
         << "\n";

    cout << "Find from date ? [2]"
         << "\n";

    cout << "Find from deposit ? [3]"
         << "\n";

    cout << "INPUT : ";
    cin >> choice;
    cin.ignore();
    return choice;
}
void allmoneywithinterested(float x)
{
    float interest;
    cout << "You interest rate is : ";
    cin >> interest;
    cout << "Your interest is : " << (interest * x) / 100 << "\n";
    cout << "Your all money is : " << x + (interest * x) / 100 << "\n";
}

int main()
{
    cout<<setprecision(3)<<fixed;
    int q=0,i=0,j=0,N,M,tax,sor;
	float a,b;
	string s,t;
	char name[999];
	char format[]="%s %f %d";
	int tax1,am=0,O,D=0;
	
	vector<string> x;
	vector<string> y;

	vector<int> p;
	vector<int> c;
	
	vector<float> inc;
	vector<float> ou;
	vector<float> pr;
	vector<float> allt;
	
	
	
	
	cout<<"Basic Accounting"<<endl<<endl;
    cout<<"Please choose your usage"<<endl;
    cout<<"1 : Normal Use"<<endl<<"2 : SME/Business"<<endl<<"3 : Bank"<<endl<<endl;
    cout<<"Select : ";
    cin>>q;
    cout<<endl;
	if(q==1)
	{
		ifstream g;
		ofstream q;
		ofstream rp;
		string filename;
	
		char name2[999];
		char format1[]="%s %f";
		float ar;
		
		cout<<"Name the file: ";
		cin>>filename;
	
		filename=filename+".txt";
	
		q.open(filename.c_str());
		
		cin.ignore();
	
		cout<<endl<<"Input income"<<endl<<endl;
		while(s!="0")
		{
			cout<<"Income "<<"["<<i+1<<"] : ";
			getline(cin,s);
			sscanf(s.c_str(),format,&name,&a,&tax);
			
			x.push_back(name);
			inc.push_back(a);
			p.push_back(tax);
			i++; 
		}
		N=i;
		
		cout<<endl;
		
		for(int i=0;i<N-1;i++)
		{
			cout<<x[i]<<" : "<<inc[i]<<endl;
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
		double sum1=0,sum2=0,sum3=0,sum4=0,ttax=0,sal=0,vat=0,novat=0,others=0,fr=0;
		
		cout<<"Use Tax Calculation?"<<endl<<"1 : Yes"<<endl<<"2 : No"<<endl<<endl;
		cout<<"Please enter : ";
		cin>>k;
		cout<<endl;
		if(k==1)
		{
			int taxes;
			cout<<"Which tax type do you want to use?"<<endl<<endl; 
			cout<<"1 : Vat 7%"<<"  "<<"2 : Individual income tax"<<endl;
			cout<<"Please enter : ";
			cin>>taxes;
			if(taxes==1)
			{
				for(int i=0;i<N-1;i++)
				{
					sum1=sum1+inc[i];
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
						sal=sal+inc[i];
						q<<"Salary "<<sal<<endl;
						continue;
					}
					else if(x[i]!="salary") 
					{
						sum1=sum1+inc[i];
					}
				}
				if(sum1>5000)
				{
					others=sum1*0.005;
				}
				else others=sum1;
				
				q<<"Others "<<others<<endl;
				
				for(int j=0;j<M-1;j++)
        		{
            		sum2=sum2+ou[j];
       			}
				q<<"Outcome "<<sum2<<endl;
				
				cout<<endl;
				
				int choice,taxde,tc=0;
				
				cout<<"Input tax deduction"<<endl;
				cout<<"Deduction list "<<"["<<tc+1<<"]"<<": ";
				cin>>taxde;
				sum3=sum3+taxde;
				
				q<<"Taxreduce "<<sum3<<endl;
				
				cout<<endl;
				
				cout<<"Predict the total tax? (with average of income/outcome)"<<endl<<"1:Yes"<<"  "<<"2:No"<<"  "<<"3:With Latest file"<<endl;
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
					int chi;
					float soth=0,stax=0,ssal=0,sotc=0,ttc=0,tre=0;
					cout<<"Enter 1 : Combine data with file"<<endl;
					cout<<"Enter 2 : Exit Program"<<endl;
					cout<<"Please enter: ";
					cin>>chi;
					if(chi==1)
					{
							int j=0;
	
							float tax1;
							char ar[999];
	
							ifstream g;
						  	string filename;
							string textline;
							
							vector<string> in;
							vector<float> sort;
							
							char format1[]="%s %f";
							
						  	cout << "Please enter a file name to combine: ";
						  	cin>>filename;
						
						  	filename=filename+".txt";
							
							g.open(filename.c_str() );
							
							while(getline(g,textline))
							{
								sscanf(textline.c_str(),format1,&ar,&tax1);
								in.push_back(ar);
								sort.push_back(tax1);
								j++;
							}
							for(int i=0;i<j;i++)
							{
								if(in[i]=="Salary")
								{
									ssal=ssal+sort[i]+inc[i];
								}
								else if(in[i]=="Others")
								{
									soth=soth+sort[i];
								}
								else if(in[i]=="Outcome")
								{
									sotc=sotc+sort[i];
								}
								else if(in[i]=="Taxreduce")
								{
									stax=stax+sort[i];
								}
							}
								ttc=sotc+sum2;
								tre=stax+sum3;
								
								cout<<ssal<<endl;
								cout<<soth<<endl;
								cout<<sotc+sum2<<endl;
								cout<<stax+sum3<<endl;
								g.close();
								q.close();
								
								cout<<"Name the new file: ";
								cin>>filename;
								
								filename=filename+".txt";
								rp.open(filename.c_str());
								rp<<"Salary "<<ssal<<endl;
								rp<<"Others "<<soth<<endl;
								rp<<"Outcome "<<ttc<<endl;
								rp<<"Taxreduce "<<tre<<endl;
								
								rp.close();
					}
					else if(chi==2)
					{
						return 0;
					}
				}
				else if(choice==3)
				{
					int sat=0;
					float tp1=0,tp2=0,tp3=0,tp4=0,tt5=0,tt6=0;
	
					float tax1;
					char ar[999];
	
					ifstream g;
					string filename;
					string textline;
							
					vector<string> in;
					vector<float> sort;
							
					char format1[]="%s %f";
					cout << "Please enter a file name to calculate: ";
					cin>>filename;
						
					filename=filename+".txt";
							
					g.open(filename.c_str());
							
					while(getline(g,textline))
					{
						sscanf(textline.c_str(),format1,&ar,&tax1);
						in.push_back(ar);
						sort.push_back(tax1);
						sat++;
					}
					
					for(int i=0;i<sat;i++)
					{
						if(in[i]=="Salary")
						{
							tp1=tp1+sort[i];
						}
						else if(in[i]=="Others")
						{
							tp2=tp2+sort[i];
						}
						else if(in[i]=="Outcome")
						{
							tp3=tp3+sort[i];
						}
						else if(in[i]=="Taxreduce")
						{
							tp4=tp4+sort[i];
						}
					}
					
					tt5=(tp1+tp2)-(tp3+tp4);
					
					if(tt5>=0&&tt5<=150000) ttax=0;
					else if(tt5>150000&&tt5<=300000) tt6=(tt5-150000)*0.05;
					else if(tt5>300000&&tt5<=500000) tt6=((tt5-300000)*0.1)+7500;
					else if(tt5>500000&&tt5<=750000) tt6=((tt5-500000)*0.15)+27500;
					else if(tt5>750000&&tt5<=1000000) tt6=((tt5-750000)*0.20)+65000;
					else if(tt5>1000000&&tt5<=2000000) tt6=((tt5-1000000)*0.25)+115000;
					else if(tt5>2000000&&tt5<=5000000) tt6=((tt5-2000000)*0.30)+365000;
					else if(tt5>5000000) tt5=((tt5-5000000)*0.35)+1265000;
					
					cout<<"Total Tax = "<<tt5<<endl;
					
				}
			}
		}
		else if(k==2)
		{
			for(int i=0;i<N-1;i++)
			{
				if(x[i]!="salary")
				{
					fr=fr+inc[i];
				}
				sum1=sum1+inc[i];	
			}
			for(int i=0;i<M-1;i++)
			{
				sum2=sum2+ou[i];
			}
			cout<<"Total Income = "<<sum1<<endl;
			q<<"Salary "<<sum1<<endl;
			q<<"Others "<<fr<<endl;
			
			cout<<"Total Outcome = "<<sum2<<endl;
			q<<"Outcome "<<sum2<<endl;
			
			if(sum2>sum1) 
			{
				cout<<"Difference = "<<-(sum1-sum2)<<endl;
			}
			else if(sum2<sum1) 
			{
				cout<<"Difference = "<<sum1-sum2<<endl;
			}
		}
		q.close();
		
    return 0;
}

if(q==2)
{
	cin.ignore();
	cout<<endl<<"Input Income"<<endl<<endl;
	while(s!="0")
		{
			cout<<"Income "<<"["<<i+1<<"] : ";
			getline(cin,s);
			sscanf(s.c_str(),format,&name,&a,&tax);
			
			x.push_back(name);
			inc.push_back(a);
			p.push_back(tax);
			i++; 
		}
		N=i;
		
		cout<<endl;
		
		for(int i=0;i<N-1;i++)
		{
			cout<<x[i]<<" : "<<inc[i]<<endl;
		}
		
		cout<<endl;
		
		cout<<"Input Outcome"<<endl;
	
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
		if(k==1)
		{
			int taxes;
			cout<<"Which tax type do you want to use?"<<endl; 
			cout<<"1 : SME"<<"  "<<"2 : Normal Business"<<endl;
			cin>>taxes;
			if(taxes==1)
			{
				for(int i=0;i<N-1;i++)
				{
					sum1=sum1+inc[i];
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
				cout<<"Total Outcome = "<<sum2<<endl;
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
			else if(taxes==2)
			{
				for(int i=0;i<N-1;i++)
				{
					sum1=sum1+inc[i];
				}
				for(int i=0;i<M-1;i++)
				{
					sum2=sum2+ou[i];
				}
				ttax=(sum1-sum2)*0.20;
				
				cout<<"Total Income = "<<sum1+sal<<endl;
					
				cout<<"Total Outcome = "<<sum2<<endl;	
	
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
				sum1=sum1+inc[i];
				sum2=sum2+ou[i];
			}
			
			cout<<"Total Income = "<<sum1<<endl;
			
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
    return 0;
}
if(q==3)
{
		int finding;
    float sum = 0;
    int tariff;
    int dom;
    Date rec;
    Bank information;
    Bank searching;
    Bank menu;
    Bank withdraw;
    Bank create;
    Bank use;
    firstmenu();
    cin >> create.input;
    while (create.input != 0)
    {
        if (create.input == 1)
        {
            depositfirstmenu();
            cin >> use.input;
            if (use.input == 1)
            {
                cout << "INPUT 00 00 0000 in date to stop"
                     << "\n";
                while (true)
                {

                    cout << "Date of Record mm dd yyyy: ";
                    cin >> rec.month;
                    if (rec.month == 00 or rec.day == 00 or rec.year == 0000)
                    {
                        break;
                    }
                    cin >> rec.day >> rec.year;
                    cin.ignore();
                    cout << "\n"
                         << "information : ";
                    getline(cin, information.inf);

                    for (int i = 0; i < information.inf.size(); i++)
                    {
                        information.inf[i] = toupper(information.inf[i]);
                    }

                    cout
                        << "Amount of deposit (Bath): ";
                    cin >> information.deposit;
                    cin.ignore();
                    cout << "****************************"
                         << "\n"
                         << "Deposit[1] or Withdraw[2]"
                         << "\n"
                         << "****************************"
                         << "\n";
                    cin >> menu.input;
                    cin.ignore();

                    if (menu.input == 1)
                    {

                        cout << "\n";
                        information.recinfor.push_back(information.inf);
                        information.m.push_back(rec.month);
                        information.d.push_back(rec.day);
                        information.y.push_back(rec.year);
                        information.depo.push_back(information.deposit);
                        cout << "You deposit  " << information.deposit << " baht"
                             << "\n";
                        sum += information.deposit;
                    }
                    if (menu.input == 2)
                    {
                        cout << "\n";
                        withdraw.recinfor.push_back(information.inf);
                        withdraw.m.push_back(rec.month);
                        withdraw.d.push_back(rec.day);
                        withdraw.y.push_back(rec.year);
                        withdraw.depo.push_back(information.deposit);
                        sum -= information.deposit;
                        cout << "You withdraw  " << information.deposit << " baht"
                             << "\n";
                    }
                }
            }
            else if (use.input == 2)
            {
                int choice;

                cout << "Are you want to find the information [Yes input 0][No input 1]"
                     << "\n";
                cin >> information.input;
                if (information.input == 0)
                {

                    cout << " Find deposit  information [1]"
                         << "\n";
                    cout << " Find Withdraw information [2]"
                         << "\n";

                    cout << "INPUT";
                    cin >> finding;
                }
                else if (information.input == 1)
                {
                    firstmenu();
                }

                if (finding == 1)
                {
                    choice = menufindingdeposit();

                    if (choice == 1)
                    {

                        tariff = searchingfrominf(withdraw.recinfor);
                        if (tariff == 0)
                        {
                            cout << "Not found !";
                        }
                        cout << information.m[tariff] << "/" << information.d[tariff] << "/" << information.y[tariff] << " : " << information.recinfor[tariff] << " "
                             << information.depo[tariff] << " Baht";
                    }

                    else if (choice == 2)
                    {
                        tariff = searchingfromdate(information.d);
                        if (tariff == 0)
                        {
                            cout << "Not found !";
                        }
                        cout << information.m[tariff] << "/" << information.d[tariff] << "/" << information.y[tariff] << " : " << information.recinfor[tariff] << " "
                             << information.depo[tariff] << " Baht";
                    }
                    else if (choice == 3)
                    {
                        tariff = searchingfromdeposit(information.depo);
                        if (tariff == 0)
                        {
                            cout << "Not found !";
                        }
                        cout << information.m[tariff] << "/" << information.d[tariff] << "/" << information.y[tariff] << " : " << information.recinfor[tariff] << " "
                             << information.depo[tariff] << " Baht";
                    }
                }
                if (finding == 2)
                {
                    choice = menufidingwithdraw();

                    if (choice == 1)
                    {
                        tariff = searchingfrominf(withdraw.recinfor);
                        if (tariff == 0)
                        {
                            cout << "Not found !";
                        }
                        cout << withdraw.m[tariff] << "/" << withdraw.d[tariff] << "/" << withdraw.y[tariff] << " : " << withdraw.recinfor[tariff] << " "
                             << withdraw.depo[tariff] << " Baht";
                    }

                    else if (choice == 2)
                    {
                        tariff = searchingfromdate(withdraw.d);
                        if (tariff == 0)
                        {
                            cout << "Not found !";
                        }
                        cout << withdraw.m[tariff] << "/" << withdraw.d[tariff] << "/" << withdraw.y[tariff] << " : " << withdraw.recinfor[tariff] << " "
                             << withdraw.depo[tariff] << " Baht";
                    }
                    else if (choice == 3)
                    {
                        tariff = searchingfromdeposit(withdraw.depo);
                        if (tariff == 0)
                        {
                            cout << "Not found !";
                        }
                        cout << withdraw.m[tariff] << "/" << withdraw.d[tariff] << "/" << withdraw.y[tariff] << " : " << withdraw.recinfor[tariff] << " "
                             << withdraw.depo[tariff] << " Baht";
                    }
                }
            }
        }
        else if (create.input == 2)
        {
            interestfirstmenu();
            cin >> menu.in;
            if (menu.in == 1)
            {
                cout << "Your all money in bank now is : " << sum << "\n";
            }
            else if (menu.in == 2)
            {
                allmoneywithinterested(sum);
            }
        }
        cin.ignore();
        firstmenu();
        cin >> create.input;
    }
}
    return 0;
}