#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <algorithm>
using namespace std;//使用std名稱空間
void add(int[],int);
void creat();
string address;
bool flag;
int main() {
	creat();
	return 0;
}
void creat() {
	srand(time(0));
	char sex;
	string tittle;
	int sexex=0;
	int temp[8];
	do {
		flag=false;
		cout<<"============================身份證字號產生器============================\n";
		cout<<"A.台北市\tB.台中市\tC.基隆市\tD.台南市\tE.高雄市\n"<<
		    "F.新北市(台北縣)G.宜蘭縣\tH.桃園市(桃園縣)I.嘉義市\tJ.新竹縣\n"<<
		    "K.苗栗縣\tL.台中縣\tM.南投縣\tN.彰化縣\tO.新竹市\n"<<
		    "P.雲林縣\tQ.嘉義縣\tR.台南縣\tS.高雄縣\tT.屏東縣\n"<<
		    "U.花蓮縣\tV.台東縣\tX.澎湖縣\tY.陽明山\tW.金門縣\n"<<"Z.連江縣\n" ;
		do {
			cout<<"請輸入出生地(輸入英文字母即可):";
			cin>>tittle;
			transform(tittle.begin(), tittle.end(), tittle.begin(), ::toupper);

		} while(!(isalpha(tittle[0]) && tittle.length()==1));

		do {
			cout<<"請輸入性別(M(男)/F(女)):";
			cin>>sex;
			sex=toupper(sex);
		} while(sex!='M'&&sex!='F');
		cout<<"身份證字號:";
		cout<<tittle;
		if (sex!='M') {
			sexex=2;
			cout<<"2";
		} else {
			sexex=1;
			cout<<"1";
		}
		add(temp,8);
		int k=tittle[0]-'0';
		int j=sexex;
		int added[10];
		for (int i = 0; i <= 10; i++) {
			if (i == 0)
				added[i] = k;

			else if(i==1)
				added[i]=j;

			else
				added[i] = temp[i-2];

		}

		char number[26]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		int coin[26]= {10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
		int a,b,nom,sum=0;
		char s;
		flag=false;
		for (int m=0; m<26; m++) { //英文字母 個位數*9+十位數*1
			if(added[0]==number[m]) {
				a=(coin[m]%10)*9; //將number[m]對應的coin[m]數字抓出來求餘數 依照身分驗證規則 餘數*9
				b=coin[m]/10;	//將number[m]/10求商
				sum=a+b;//餘數*9+number[m]/10的商數相加
			}

		}
		int n=8;
		for(int m=2; m<=10; m++) { //依照身分驗證規則 數字部分從address[1]開始*8 address[2]*7 +到 address[8]*1
			nom=added[m]-'0'; //ASCII碼 0=48 因為抓出來的是數字字元不是整數 所以要先扣掉48
			sum+=nom*n;
			n--;
		}
		sum+=(added[10]-'0'); //這邊因為上面迴圈算到s[9]的成數n已經為0 驗證規則最後一碼要*1 所以要將最後一碼的值加回去

		if(sum%10==0) {
			cout<<"身分證字號正確\n";
			for (int i=0; i<=10; i++) {
				cout<<added[i];
			}

		} else {
			flag=true;
		}
		cout<<"\n繼續生成請按Y結束請按N:";
		cin>>s;
		s=toupper(s);
		if(s=='Y')
			flag=true;
		else
			flag=false;
	} while(flag);

}
int noadd() {
	return rand()%10;
}
void add(int temp[],int length) {
	for(int m=0; m<length; m++) {
		temp[m]=noadd();
		cout<<temp[m];
	}

}

