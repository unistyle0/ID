#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <algorithm>
using namespace std;//�ϥ�std�W�٪Ŷ�
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
		cout<<"============================�����Ҧr�����;�============================\n";
		cout<<"A.�x�_��\tB.�x����\tC.�򶩥�\tD.�x�n��\tE.������\n"<<
		    "F.�s�_��(�x�_��)G.�y����\tH.��饫(��鿤)I.�Ÿq��\tJ.�s�˿�\n"<<
		    "K.�]�߿�\tL.�x����\tM.�n�뿤\tN.���ƿ�\tO.�s�˥�\n"<<
		    "P.���L��\tQ.�Ÿq��\tR.�x�n��\tS.������\tT.�̪F��\n"<<
		    "U.�Ὤ��\tV.�x�F��\tX.���\tY.�����s\tW.������\n"<<"Z.�s����\n" ;
		do {
			cout<<"�п�J�X�ͦa(��J�^��r���Y�i):";
			cin>>tittle;
			transform(tittle.begin(), tittle.end(), tittle.begin(), ::toupper);

		} while(!(isalpha(tittle[0]) && tittle.length()==1));

		do {
			cout<<"�п�J�ʧO(M(�k)/F(�k)):";
			cin>>sex;
			sex=toupper(sex);
		} while(sex!='M'&&sex!='F');
		cout<<"�����Ҧr��:";
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
		for (int m=0; m<26; m++) { //�^��r�� �Ӧ��*9+�Q���*1
			if(added[0]==number[m]) {
				a=(coin[m]%10)*9; //�Nnumber[m]������coin[m]�Ʀr��X�ӨD�l�� �̷Ө������ҳW�h �l��*9
				b=coin[m]/10;	//�Nnumber[m]/10�D��
				sum=a+b;//�l��*9+number[m]/10���ӼƬۥ[
			}

		}
		int n=8;
		for(int m=2; m<=10; m++) { //�̷Ө������ҳW�h �Ʀr�����qaddress[1]�}�l*8 address[2]*7 +�� address[8]*1
			nom=added[m]-'0'; //ASCII�X 0=48 �]����X�Ӫ��O�Ʀr�r�����O��� �ҥH�n������48
			sum+=nom*n;
			n--;
		}
		sum+=(added[10]-'0'); //�o��]���W���j����s[9]������n�w�g��0 ���ҳW�h�̫�@�X�n*1 �ҥH�n�N�̫�@�X���ȥ[�^�h

		if(sum%10==0) {
			cout<<"�����Ҧr�����T\n";
			for (int i=0; i<=10; i++) {
				cout<<added[i];
			}

		} else {
			flag=true;
		}
		cout<<"\n�~��ͦ��Ы�Y�����Ы�N:";
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

