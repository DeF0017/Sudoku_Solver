#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
class SudokuGrid{
    char a[9][9];
    public:SudokuGrid(){
        optionMenu();
    }
    public:void optionMenu(){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                a[i][j]='.';
            }
        }
        int choice;
        cout<<"1. Generate the Puzzle"<<"\n";
        cout<<"2. Manually Input the Puzzle"<<"\n";
        cin>>choice;
        if(choice==1){
            SudokuGenerator();
        }
        else if(choice==2){
            char ch;
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    cout<<"Enter Value for Cell ["<<i+1<<"]["<<j+1<<"]"<<"\n";
                    cin>>ch;
                    a[i][j]=ch;
                }
            }
        }
    }
    public:void setCellValue(int row, int col,char key){
		a[row][col]=key;
	}
	public:int getCellValue(int row, int col){
		int cellValue=a[row][col];
		return cellValue;
	}
    public:void DisplayGrid(){
        cout<<"-------------------------\n";
        for(int i=0;i<9;i++){
            cout<<"| ";
            for(int j=0;j<9;j++){
                cout<<a[i][j]<<" ";
                if(j%3==2){
                    cout<<"| ";
                }
            }
            if(i%3==2){
                cout<<"\n";
                cout<<"-------------------------";
            }
            cout<<"\n";
        }
    }
    // Returns false if given 3 x 3 block contains num.
    bool unUsedInBox(int row, int col, int num)
    {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (a[i+row][j+col]==num+'0') {
                    return false;
                }
            }
        }
        return true;
    }
    // Random generator
    int randomGenerator(int num){
        return (int)floor(
            (float)(rand() / double(RAND_MAX) * num + 1));
    }
    // Fill a 3 x 3 matrix.
    void fillBox(int row, int col){
        int num;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                do {
                    num = randomGenerator(9);
                } while (!unUsedInBox(row, col, num));
                a[row+i][col+j]=num+'0';
            }
        }
    }
    // Fill the diagonal SRN number of SRN x SRN matrices
    void fillDiagonal(){
        for (int i = 0; i < 9; i = i + 3){
        // for diagonal box, start coordinates->i==j
        fillBox(i,i);
        }
    }
    void SudokuGenerator(){
        fillDiagonal();
        SSolver();
        ll k=0;
        while(k<55){
            ll x=rand()%9;
            ll y=rand()%9;
            if(a[x][y]!='.'){
                a[x][y]='.';
            k++;
            }
        }
    }
    private:bool Check(int i,int j,char x){
    // Check Row
    for(int k=0;k<9;k++){
        if(a[i][k]==x){
            return false;
        }
    }
    // Check Column
    for(int k=0;k<9;k++){
        if(a[k][j]==x){
            return false;
        }
    }
    // Check Individual Square
    ll i1=i/3;
    ll j1=j/3;
    for(int k=i1*3;k<i1+3;k++){
        for(int l=j1*3;l<j1+3;l++){
            if(a[k][l]==x){
                return false;
            }
        }
    }
    return true;
    }
    private:bool SSolver(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(a[i][j]=='.'){
                for(int k='1';k<='9';k++){
                    if(Check(i,j,k)){
                        a[i][j]=k;
                        if(SSolver()){
                            return true;
                        }
                        else{
                            a[i][j]='.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
    }
};


class SudokuSolver{
    SudokuGrid a;
    public: SudokuSolver(){
        a.DisplayGrid();
        cout<<"\n\nCalculating possibilities...\n";
		cout<<"Backtracking across puzzle....\n";
		cout<<"Validating cells and values...\n\n";
        SolveCheck();
    }
    private:bool Check(int i,int j,char x){
    // Check Row
    for(int k=0;k<9;k++){
        if(a.getCellValue(i,k)==x){
            return false;
        }
    }
    // Check Column
    for(int k=0;k<9;k++){
        if(a.getCellValue(k,j)==x){
            return false;
        }
    }
    // Check Individual Square
    ll i1=i/3;
    ll j1=j/3;
    for(int k=i1*3;k<i1+3;k++){
        for(int l=j1*3;l<j1+3;l++){
            if(a.getCellValue(k,l)==x){
                return false;
            }
        }
    }
    return true;
    }
    private:bool SSolver(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(a.getCellValue(i,j)=='.'){
                for(int k='1';k<='9';k++){
                    if(Check(i,j,k)){
                        a.setCellValue(i,j,k);
                        if(SSolver()){
                            return true;
                        }
                        else{
                            a.setCellValue(i,j,'.');
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
    }
    private: void SolveCheck(){
        if(SSolver()){
            cout<<"Successfully Solved!!! :)"<<"\n";
            a.DisplayGrid();
        }
        else{
            cout<<"Unsolvable Sudoku!!! :("<<"\n";
        }
    }
};
int main(){
    SudokuSolver s1;
    return 0;
}