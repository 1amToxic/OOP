#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int mas = 10000;
class Nguoi{
	private:
		string hoten,diachi,sodt;
	public:
		void sethoten(string a){
			this->hoten = a;
		}
		void setdiachi(string b){
			this->diachi = b;
		}
		void setsodt(string c){
			this->sodt = c;
		}
		string gethoten(){
			return hoten;
		}
		string getdiachi(){
			return diachi;
		}
		string getsodt(){
			return sodt;
		}
};

class Bandoc:public Nguoi{
	private:
		string loaibandoc;
		int mathedoc;
};

class Sach{
	string tensach,tacgia,chuyennganh;
	int namxb,masach;
	public:
		void nhapthongtin(){
			cout<<"Nhap thong tin sach\n";
			cout<<"Nhap ten sach: ";
			getline(cin,tensach);
			cout<<"Nhap ten tac gia: ";
			getline(cin,tacgia);
			cout<<"Nhap chuyen nganh: ";
			cout<<"\n1. Khoa hoc tu nhien\n2.Van hoc nghe thuat\n3.Dien tu vien thong\n4.CNTT\n";
			cout<<"Nhap lua chon\n";
			int k;
			cin >> k;
			switch(k){
				case 1:{
					this->chuyennganh = "Khoa hoc tu nhien";
					break;
				}
				case 2:{
					this->chuyennganh = "Van hoc nghe thuat";
					break;
				}
				case 3:{
					this->chuyennganh = "Dien tu vien thong";
					break;
				}
				default:{
					this->chuyennganh = "CNTT";
					break;
				}
			}
			cout<<"Nhap nam xuat ban: ";
			cin >> namxb;
			masach = mas ++;
		}
		void ghithongtin(){
			fstream ofs("SACH.txt",ios::app);
			ofs << this->tensach<<endl;
			ofs << this->tacgia<<endl;
			ofs << this->chuyennganh<<endl;
			ofs << this->namxb<<endl;
			ofs << this->masach<<endl;
		}
		void inthongtin(){
			cout<<"Ten sach: "<<this->tensach<<endl;
			cout<<"Tac gia: "<<this->tacgia<<endl;
			cout<<"Chuyen nganh: "<<this->chuyennganh<<endl;
			cout<<"Nam xb: "<<this->namxb<<endl;
			cout<<"Ma sach: "<<this->masach<<endl;
		}
		friend vector<Sach> docSach();
		friend void yeucau1();
};
vector <Sach> sa;
vector <Sach> docSach();

vector <Sach> docSach(){
	fstream ifs("SACH.txt",ios::in);
	vector <Sach> res;
	while(!ifs.eof()){
		Sach m;
		getline(ifs,m.tensach);
		getline(ifs,m.tacgia);
		getline(ifs,m.chuyennganh);
		ifs >> m.namxb;
		ifs >> m.masach;
		ifs.ignore();
		if(ifs.eof()) break;
		res.push_back(m);
		
	}
	return res;
}

void yeucau1(){
	fstream ifs("SACH.txt",ios::in);
	string a;
	int b,c = 0;
	while(!ifs.eof()){
		getline(ifs,a);
		getline(ifs,a);
		getline(ifs,a);
		ifs >> b;
		ifs >> c;
		ifs.ignore();
	}
	if(c==0)	mas = 10000;
	else mas = c+1;
	Sach *sac = new Sach;
	sac->nhapthongtin();
	sac->ghithongtin();
	sa = docSach();
	for(int i = 0; i < sa.size(); i++)
		sa[i].inthongtin();
}

int main(){
	yeucau1();
}
