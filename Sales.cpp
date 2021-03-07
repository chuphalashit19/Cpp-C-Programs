
#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>
#include<climits>
using namespace std;
const int vals = 4;
const int  branches = 10;

void readFile(int sales[][vals]){
	ifstream inFile("sales.txt");
	string in;
	int i = 0,j = 0;
	for (i=0;i<branches;i++){
		for (j=0;j<vals;j++){
		inFile >> in;
		//cout<<in<<endl;;
		sales[i][j] = atoi(in.c_str());
		}
	}
}

bool branchCheck(int branch){	return (branch>=1 && branch<=10);	}
bool quarterCheck(int quarter){	return (quarter>=1 && quarter<=4);	}
void branchSalesQuarter(int sales[][vals]){
	cout<<"Enter Branch Number (1 to 10) : ";
	int branch,quarter;
	cin>>branch;
	if(!branchCheck(branch)){	cout<<"Invalid Branch\n";	return; }
	cout<<"Enter Quarter Number (1 to 4) : "; cin>>quarter;
	if(!quarterCheck(quarter)){	cout<<"Invalid Quarter\n";	return; }
	cout<<"\n"<<branch<<" Branch Sales for :"<<quarter<<" : Quarter = "<<sales[branch-1][quarter-1]<<endl<<endl;
}
int displayMenu(){
	int choice;
		cout<<"Choose 1 to see a branch's sales for a particular quarter\n";
		cout<<"Choose 2 to see total sales of a branch\n";
		cout<<"Choose 3 to see total branch sales for a particular quarter\n";
		cout<<"Choose 4 to see the total sales for all branches\n";
		cout<<"Choose 5 to see the sales for the highest quarter for a branch\n";
		cout<<"Choose 6 to see the sales for the lowest quarter for a branch\n";
		cout<<"Choose 7 to see the average quarterly sales for the company\n";
		cout<<"Choose 8 to see a branch's increase or decrease from a previous quarter\n";
		cout<<"Choose 9 to see a list of all quarterly sales figures\n";
		cout<<"Choose 10 to see the company's increase or decrease from the previous quarter\n";
		cout<<"Choose 11 to exit this program.\n";
		cout<<"Enter Your Choice : ";
		cin>>choice;
		return choice;
}
void branchTotalSales(int sales[][vals]){
	int branch;
	cout<<"Enter Branch Number(1 to 10) : ";
	cin>>branch;
	if(!branchCheck(branch)){	cout<<"Invalid Branch\n";	return; }
	int sum = 0;
	for (int i =0 ;i<vals;i++)	
		sum+=sales[branch-1][i];
	cout<<branch<<" Branch's Total Sales are : "<<sum<<endl;
}

void totalQuarterSales(int sales[][vals]){
	int quarter;
	cout<<"Enter Quarter Number (1 to 4) : "; cin>>quarter;
	if(!quarterCheck(quarter)){	cout<<"Invalid Quarter\n";	return; }
	int sum = 0;
	for (int i =0 ;i<branches;i++)	
		sum+=sales[i][quarter-1];
	cout<<quarter<<" Quarter's Total Sales are : "<<sum<<endl;
}

void totalSales(int sales[][vals]){
	int sum = 0;
	for (int i=0;i<branches;i++)
		for (int j=0;i<vals;j++)
			sum+=sales[i][j];
	cout<<"Total Sales are : "<<sales<<endl;
}

void highestQuarterSale(int sales[][vals]){
	int branch;
	cout<<"Enter Branch Number(1 to 10) : ";
	cin>>branch;
	if(!branchCheck(branch)){	cout<<"Invalid Branch\n";	return; }
	int max = 0,idx = 0;
	for (int i =0 ;i<vals;i++){
		if (max<sales[branch-1][i]){
			max = sales[branch-1][i];
			idx = i;
		}
	}
	cout<<branch<<"Branch's Max Sales are : "<<max<<" in the "<<idx<<" Quarter"<<endl;
}

void lowestQuarterSale(int sales[][vals]){
	int branch;
	cout<<"Enter Branch Number(1 to 10) : ";
	cin>>branch;
	if(!branchCheck(branch)){	cout<<"Invalid Branch\n";	return; }
	int max = INT_MAX,idx = 0;
	for (int i =0 ;i<vals;i++){
		if (max>sales[branch-1][i]){
			max = sales[branch-1][i];
			idx = i;
		}
	}
	cout<<branch<<"Branch's Lowest Sales are : "<<max<<" in the "<<idx<<" Quarter"<<endl;
}

void averageQuarterly(int sales[][vals]){
	int branch;
	cout<<"Enter Branch Number(1 to 10) : ";
	cin>>branch;
	if(!branchCheck(branch)){	cout<<"Invalid Branch\n";	return; }
	int min = 10000000;
	int idx = 0;
	for (int i =0 ;i<vals;i++){
		if (min > sales[branch-1][i]){
			min = sales[branch-1][i];
			idx = i;
		}
	}
	cout<<branch<<" Branch's Lowest Sales are : "<<min<<" in the "<<idx<<" Quarter"<<endl;
}
void increaseQuarter(int sales[][vals]){
	int branch;
	cout<<"Enter Branch Number(1 to 10) : ";
	cin>>branch;
	if(!branchCheck(branch)){	cout<<"Invalid Branch\n";	return; }
	cout<<"The Increase are : \n";

	for(int i = 1;i<vals;i++)
		if (sales[branch-1][vals]>sales[branch-1][vals]){
			cout<<"In Quarter "<<i+1<<" "<<sales[branch-1][vals]-sales[branch-1][vals]<<" more than quarter "<<i<<endl;
	}
}

void quarterlySales(int sales[][vals]){
	// TODO
}

void companyIncrease(int sales[][vals]){
	//	TODO
}
int main(){
	int sales[branches][vals];
	readFile(sales);
	while(1){
	int choice = displayMenu();
	switch(choice){
				case 1 : branchSalesQuarter(sales);	break;
				case 2 : branchTotalSales(sales);	break;
				case 3 : totalQuarterSales(sales); 	break;
				case 4 : totalSales(sales);	break;
				case 5 : highestQuarterSale(sales);	break;
				case 6 : lowestQuarterSale(sales);	break;
				case 7 : averageQuarterly(sales);	break; 
				case 8 : increaseQuarter(sales);	break;
				case 9 :  quarterlySales(sales);	break;
				case 10 : companyIncrease(sales);	break;
				case 11 : cout<<"EXITING...";	return 0;
				default : cout<<"\nWRONG INPUT. Try Again."<<endl;
		}
	}
  return 0;
}
