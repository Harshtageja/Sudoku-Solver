#include<iostream>
using namespace std;
bool check(int grid[9][9],int r,int c,int n){
	int i;
	for(i=0;i<9;i++){
		if(grid[i][c]==n){
			return false;
		}
		if(grid[r][i]==n){
			return false;
		}
	}
	int j=r/3;
	j*=3;
	 i=c/3;
	 i*=3;
	int k,h;
	k=i+3;
	h=j+3;
	for(;i<k;i++){
		j=r/3;
		j*=3;
		h=j+3;
		for(;j<h;j++){
			if(grid[j][i]==n){
				return false;
			}
		}
	}
	return true;
}
bool put(int grid[9][9],int r,int c){
	int i;
	int s;
	for(i=grid[r][c]+1;i<10;i++){
		if(check(grid,r,c,i)){
			
		grid[r][c]=i;
		break;
		}
	}
	if(i==10){
		grid[r][c]=0;
		return false;
	}
	
}
bool sudokusolver(int grid[9][9],int r,int c,int f){
	if(r==9){
		return true;
	}
	int nr,nc;
	if(c==8){
		nc=0;
		nr=1+r;
	}
	else{
		nc=c+1;
		nr=r;
	}
	if(f==0&&grid[r][c]!=0){
		sudokusolver(grid,nr,nc,0);
	}
	else if(put(grid,r,c)){
		if(sudokusolver(grid,nr,nc,0)){
			return true;
		}
		else{
			sudokusolver(grid,r,c,1);
		}
	}
	else{
		return false;
		
	}
}


int main(){
	int grid[9][9]={
		0
	};
	int i,j;
	sudokusolver(grid,0,0,0);
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cout<<grid[i][j];
		}
		cout<<"\n";
	}
	return 0;
}