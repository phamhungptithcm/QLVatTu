#include<iostream>
#include <string>
#include <string.h>
#include <mylib.h>
#include <fstream>
#include <ctime>
#include <cmath>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include<windows.h>
#include <sstream>
#include <iomanip>
#define MAXNV 500
#define MAXTK 100

using namespace std;
							// BAT DAU KHAI BAO
struct Date{
	int ngay;
	int thang;
	int nam;
};
struct CT_HOADON{
	char MaVT[11];
	int soluong;
	int dongia;
	double VAT;
};
struct NODECT_HOADON{
	CT_HOADON Data;
	NODECT_HOADON *pNext;
};
struct HOADON{
	char SoHD[21];
	Date date;
	char loai;
	NODECT_HOADON* fisrtCT;
};
struct NODE_HOADON{
	HOADON data;
	NODE_HOADON *pNext;
};

typedef struct DS_HOADON DSHD;
struct NHANVIEN{
	char MaNV[11];
	char Ho[21];
	char Ten[21];
	char Phai[3];
	NODE_HOADON* fisrtHD;
};
struct DSNV
{
	NHANVIEN *nv= new NHANVIEN[MAXNV];
	int soLuongNV=0;
};
DSNV dsnv;
struct VATTU{
	char MaVT[11];
	char TenVT[21];
	char DVT[10];
	int SoLuongTon;
};
struct NODE_VATTU{
	VATTU Data;
	NODE_VATTU *pLeft;
	NODE_VATTU *pRight;
};
typedef NODE_VATTU* Tree;
Tree t;
struct THONGKE
{
	char SoHD[21];
	Date date;
	char Loai;
	string HoTenNV;
	int donGia;
};
struct DS_THONGKE
{
	THONGKE *tk = new THONGKE[MAXTK];
	int soTK;
};
DS_THONGKE dstk;
							// KET THUC KHAI BAO
                            // BAT DAU HAM GIAO DIEN
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
// Bien cuc bo cho phan giao dien
int setMauChon = 32;
int yMap = 3; // vi tri cho cac thanh phan trong bang thong ke va bang chi tiet
int xMap = 20;
void xoakhungtongtien(int y)
{
	gotoxy(17,y);
	cout <<"                                                                                      ";
	gotoxy(17,y+1);
	cout <<"                                                                                      ";
	gotoxy(17,y+2);
	cout <<"                                                                                      ";
}
void veKhungTongGiaTien(int y)
{
	textcolor(10);
	gotoxy(18, y+1);
	cout << char(179);
	gotoxy(18,y);
	for(int i = 0; i < 67; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	gotoxy(43, y+1);
	cout << char(179);
	gotoxy(43, y);
	cout << char(194);
	gotoxy(18, y+2);
	cout << char(192);
	for(int i = 0; i < 66; i++)
	{
		cout << char(196);
	}
	gotoxy(43, y+2);
	cout << char(193);
	gotoxy(85, y+1);
	cout << char(179);
	gotoxy(85, y+2);
	cout << char(217);
	gotoxy(18, y);
	cout << char(218);
	gotoxy(20,y+1);
	cout << "Tong Gia Tien: ";
	textcolor(7);
}
void VeNVVT(int x, int y)
{
	gotoxy(18, y-1);
	cout << char(195);
	gotoxy(18, y);
	cout << char(179);
	for(int i = 0; i < 3; i++)
	{
		gotoxy(x + 15 + i*22, y);
		cout << char(179);
	}
	gotoxy(85, y);
	cout << char(179);
	gotoxy(x, y + 1);
	cout << char(195);
	for(int i = 0; i < 66; i++)
		cout << char(196);
	cout << char(180);
	gotoxy(85,y-1);
	cout << char(180);
	for(int i = 0; i < 3; i++)
	{
		gotoxy(x + 15 + i*22, y + 1);
		cout << char(197);
	}
	for(int i = 0; i < 3; i++)
	{
		gotoxy(x + 15 + i*22, y-1);
		cout << char(197);
	}
}
void VeNVVT2(int x, int y)
{
	for(int i = 0; i < 3; i++)
	{
		gotoxy(x + 15 + i*22, y);
		cout << char(179);
	}
	gotoxy(85, y);
	cout << char(179);
	gotoxy(18, y);
	cout << char(179);
	gotoxy(x, y + 1);
	cout << char(192);
	for(int i = 0; i < 66; i++)
		cout << char(196);
	cout << char(217);
	for(int i = 0; i < 3; i++)
	{
		gotoxy(x + 15 + i*22, y + 1);
		cout << char(193);
	}
}

void hcn(int x, int y,string name, bool choose = false)
{
	if(choose)
	{
	gotoxy(x,y);
	textcolor(14);
	for(int i=0;i<31;i++)
	{
		if(i==0)
			cout<<char(218);
		else if(i==30)
			cout<<char(191);
		else cout<<char(196);
	}
	gotoxy(x,y+1);
	cout<<char(179);
	gotoxy(x+30,y+1);
	cout<<char(179);
	gotoxy(x,y+2);
	for(int i=0;i<31;i++)
	{
		if(i==0)
			cout<<char(192);
		else if(i==30)
			cout<<char(217);
		else cout<<char(196);
	}
	
	}
	else
	{
		gotoxy(x,y);
	for(int i=0;i<31;i++)
	{
		if(i==0)
			cout<<char(218);
		else if(i==30)
			cout<<char(191);
		else cout<<char(196);
	}
	gotoxy(x,y+1);
	cout<<char(179);
	gotoxy(x+30,y+1);
	cout<<char(179);
	gotoxy(x,y+2);
	for(int i=0;i<31;i++)
	{
		if(i==0)
			cout<<char(192);
		else if(i==30)
			cout<<char(217);
		else cout<<char(196);
	}	
	}
	textcolor(7);
	gotoxy(x + 1 + (30 - name.length()) / 2, y + 1);
	if (choose)
	{
		textcolor(setMauChon);
		cout << name;
	}
	else
	{
		textcolor(7);
		cout << name;
	}
	textcolor(7);
//	gotoxy(x+1,y+1);
}
// ham in button menu
int arrMenuVT[8] ={7,11,15,19,23,27,31};
int yMapMN = 40;
void vemenu(int *arr, string *arrTuKhoa, int n) //n: so chuc nang can show ra man hinh
{

	for (int i = 0; i < n; i++)
	{
		hcn(yMapMN, arr[i], arrTuKhoa[i]);
	}
}
int ytk = -4;
int arrToaDoBangThongKeHD[6] ={ 2,24,44,54,81,105};
void veBangThongKeHD()
{
	string arrTuKhoa[] = { "So HD","Ngay Lap","Loai","Ho ten NV Lap","Don Gia" };
	for (int i = 0; i < 5; i++)
	{
		gotoxy(arrToaDoBangThongKeHD[i] + 1 + ((arrToaDoBangThongKeHD[i + 1] - arrToaDoBangThongKeHD[i] - arrTuKhoa[i].length()) / 2), ytk + 11);
		textcolor(10);
		cout << arrTuKhoa[i];
		textcolor(7);

	}
	for (int j = ytk + 10; j <= ytk + 40; j++)
	{
		gotoxy(arrToaDoBangThongKeHD[0], j);
		cout << char(179);
		gotoxy(arrToaDoBangThongKeHD[5], j);
		cout << char(179);
		gotoxy(arrToaDoBangThongKeHD[1], j);
		cout << char(179);
		gotoxy(arrToaDoBangThongKeHD[2], j);
		cout << char(179);
		gotoxy(arrToaDoBangThongKeHD[3], j);
		cout << char(179);
		gotoxy(arrToaDoBangThongKeHD[4], j);
		cout << char(179);
	}
	for (int i = arrToaDoBangThongKeHD[0]; i <= arrToaDoBangThongKeHD[5]; i++)
	{
		gotoxy(i, ytk + 10);
		if (i == arrToaDoBangThongKeHD[1] || i == arrToaDoBangThongKeHD[2] || i == arrToaDoBangThongKeHD[3] || i == arrToaDoBangThongKeHD[4])
			cout << char(194);
		else if (i == arrToaDoBangThongKeHD[0])
		{
			cout << char(218);
		}
		else if (i == arrToaDoBangThongKeHD[5])
		{
			cout << char(191);
		}

		else
		{
			cout << char(196);
		}
		gotoxy(i, ytk + 12);
		if (i == arrToaDoBangThongKeHD[1] || i == arrToaDoBangThongKeHD[2] || i == arrToaDoBangThongKeHD[3] || i == arrToaDoBangThongKeHD[4])
			cout << char(197);
		else if (i == arrToaDoBangThongKeHD[0])
		{
			cout << char(195);
		}
		else if (i == arrToaDoBangThongKeHD[5])
		{
			cout << char(180);
		}
		else
		{
			cout << char(196);
		}
		gotoxy(i, ytk + 40);
		if (i == arrToaDoBangThongKeHD[1] || i == arrToaDoBangThongKeHD[2] || i == arrToaDoBangThongKeHD[3] || i == arrToaDoBangThongKeHD[4])
			cout << char(193);
		else if (i == arrToaDoBangThongKeHD[0])
			cout << char(192);
		else if (i == arrToaDoBangThongKeHD[5])
		{
			cout << char(217);
		}
		else
		{
			cout << char(196);
		}
	}
}
void SuaYesNo(int x, int y, int ht)
{
	if(ht == 0)
	{
		textcolor(42);
		gotoxy(x, y);
		cout << "Yes";
		textcolor(11);
		gotoxy(x + 20, y);
		cout << "No";
	}
	else
	{
		textcolor(11);
		gotoxy(x, y);
		cout << "Yes";
		textcolor(42);
		gotoxy(x + 20, y);
		cout << "No";
	}
}
int YesNo(int x, int y)
{
	Nocursortype();
	textcolor(42);
	gotoxy(x, y);
	cout << "Yes";
	textcolor(11);
	gotoxy(x + 20, y);
	cout << "No";
	int i = 0;
	int c;
	while(int(c) != 13)
	{
		c = getch();
		if(c == 224)
		{
			c = getch();
			if(c == 75)
			{
				if(i == 0)
					i = 1;
				else i--;
				SuaYesNo(44, 14, i);
			}else
			if(c == 77)
			{
				if(i == 0)
					i = 1;
				else i--;
				SuaYesNo(44, 14, i);
			}
		}
	}
	textcolor(7);
	return (!i);
}
int veKhungYesNo(string str, int tt)
{
	textcolor(14);
	gotoxy(38, 9);
	cout << char(218);
	for(int i = 0; i < 33; i++)
		cout << char(196);
//--------------------		
	gotoxy(39, 10);
	for(int i = 0; i < 32; i++)
		cout << " ";
	gotoxy(39, 11);
	for(int i = 0; i < 32; i++)
		cout << " ";
	gotoxy(39, 12);
	for(int i = 0; i < 32; i++)
		cout << " ";
	gotoxy(39, 13);
	for(int i = 0; i < 32; i++)
		cout << " ";
	gotoxy(39, 14);
	for(int i = 0; i < 32; i++)
		cout << " ";

	for(int i = 0; i < 5; i++)
	{
		gotoxy(38, 10 + i);
		cout << char(179);
		gotoxy(71, 10 + i);
		cout << char(179);
	}
	gotoxy(38, 15);
	cout << char(192);
	for(int i = 0; i < 32; i++)
		cout << char(196);
	cout << char(217);
	gotoxy(38, 9);
	cout << char(218);
	gotoxy(71, 9);
	cout << char(191);
	textcolor(7);
	gotoxy(39, 10);
	cout << str;
	if(tt)
	{
		gotoxy(51, 11);
		cout << "Tiep tuc?";
	}
	return YesNo(44, 14);
}
void xoaKhungYN()
{
	for(int i = 0; i < 7; i++)
	{
		gotoxy(38, 9+i);
		cout << "                                  ";
	}
}
void XoaKhungTB()
{
	for(int i = 0; i < 7; i++)
	{
		gotoxy(39, 10+i);
		cout << "                                  ";
	}
}
void veKhungTB(string str)
{
	textcolor(14);
	for(int i = 0; i < 7; i++)
	{
		gotoxy(39, 10+i);
		cout << "                                 ";
	}
	gotoxy(39, 10);
	cout << char(218);
	for(int i = 0; i < 32; i++)
		cout << char(196);
	cout << char(191);
	for(int i = 0; i < 5; i++)
	{
		gotoxy(39, 11 + i);
		cout << char(179);
		gotoxy(72, 11 + i);
		cout << char(179);
	}
	gotoxy(39, 16);
	cout << char(192);
	for(int i = 0; i < 32; i++)
		cout << char(196);
	cout << char(217);
	textcolor(7);
	gotoxy(40, 12);
	cout << str;
	gotoxy(55, 15);
	textcolor(42);
	cout << "OK";
	textcolor(7);
	getch();
}
void Ve1(int x, int y)
{
	gotoxy(10, y-1);
	cout << char(195);
	gotoxy(10, y);
	cout << char(179);
	for(int i = 0; i < 4; i++)
	{
		if(i==0)
		{
			gotoxy(25, y);
			cout << char(179);
			gotoxy(x + 15 + i*22, y + 1);
			cout << char(197);
		}
		else
		{
			gotoxy(x + 10 + i*22, y);
			cout << char(179);
		}
		
	}
	gotoxy(95, y);
	cout << char(179);
	gotoxy(x, y + 1);
	cout << char(195);
	for(int i = 0; i < 84; i++)
		cout << char(196);
	cout << char(180);
	gotoxy(95,y-1);
	cout << char(180);
	for(int i = 0; i < 4; i++)
	{
		if(i==0)
		{
			gotoxy(x + 15 + i*22, y + 1);
			cout << char(197);
		}
		else
		{
			gotoxy(x + 10 + i*22, y + 1);
			cout << char(197);
			gotoxy(x + 10 + i*22, y -1);
			cout << char(197);
		}
		
	}
}
void Ve2(int x, int y)
{
	for(int i = 0; i < 4; i++)
	{
		if(i==0)
		{
			gotoxy(x +15 + i*22, y);
			cout << char(179);
		}
		else
		{
			
			gotoxy(x + 10 + i*22, y);
			cout << char(179);
		}
		
	}
	gotoxy(95, y);
	cout << char(179);
	gotoxy(10, y);
	cout << char(179);
	gotoxy(x, y + 1);
	cout << char(192);
	for(int i = 0; i < 84; i++)
		cout << char(196);
	cout << char(217);
	for(int i = 0; i < 4; i++)
	{
		if(i==0)
		{
			gotoxy(x + 15 + i*22, y + 1);
			cout << char(193);
		}
		else
		{
			gotoxy(x + 10 + i*22, y + 1);
			cout << char(193);
		}
		
	}
}
void veHTSearch(string name1,string name2,string name3,string name4)
{
	gotoxy(18, 5);
	cout << char(179);
	gotoxy(18, 4);
	cout << char(218);
	
	for(int i = 0; i < 66; i++)
		cout << char(196);
	cout << char(191);
	gotoxy(33, 5);
	cout << char(179);
	gotoxy(33, 4);
	cout << char(194);
	gotoxy(18, 6);
	cout << char(195);
	
	for(int i = 0; i < 66; i++)
		cout << char(196);
		for(int i = 1; i < 3; i++)
		{
			gotoxy(33 + i*22, 4);
			cout << char(194);
			gotoxy(33 + i*22, 5);
			cout << char(179);
			gotoxy(33 + i*22, 6);
			cout << char(197);
		}
	gotoxy(33, 6);
	cout << char(197);
	gotoxy(85, 5);
	cout << char(179);
	gotoxy(85, 6);
	cout << char(180);
	int i = 0;
	textcolor(10);
	gotoxy(20, 5);
	cout << name1;
	gotoxy(42, 5);
	cout << name2;
	gotoxy(63, 5);
	cout << name3;
	gotoxy(79, 5);
	cout << name4;
	textcolor(7);
}
void ve1()
{
	gotoxy(10, 6);
	cout << char(179);
	gotoxy(10, 5);
	cout << char(218);
	
	for(int i = 0; i < 84; i++)
		cout << char(196);
	cout << char(191);
	gotoxy(25, 6);
	cout << char(179);
	gotoxy(25, 5);
	cout << char(194);
	gotoxy(10, 7);
	cout << char(195);
	
	for(int i = 0; i < 84; i++)
		cout << char(196);
		for(int i = 1; i < 4; i++)
		{
			gotoxy(20 + i*22, 5);
			cout << char(194);
			gotoxy(20 + i*22, 6);
			cout << char(179);
			gotoxy(20 + i*22, 7);
			cout << char(197);
		}
	gotoxy(25, 7);
	cout << char(197);
	gotoxy(95, 6);
	cout << char(179);
	gotoxy(95, 7);
	cout << char(180);
	int i = 0;
	textcolor(10);
	gotoxy(12, 6);
	cout << "Ma Vat Tu";
	gotoxy(29, 6);
	cout << "Ten Vat Tu";
	gotoxy(50, 6);
	cout << "So luong";
	gotoxy(71, 6);
	cout << "Don Gia";
	gotoxy(89,6);
	cout << "VAT(%)";
	textcolor(7);
}
// Ham ve bang hien thi detail dung cho vat tu nhan vien
int arrToaDoBangChiTet[5] = { 15,35,56,82,94 };
void veBangChiTiet(string *arrTenCot, int x =0)
{ 
	
	yMap = yMap + x;
	// in ten cot
	for(int i =0; i<4;i++)
	{
		gotoxy(arrToaDoBangChiTet[i]+1 +((arrToaDoBangChiTet[i+1] - arrToaDoBangChiTet[i] -arrTenCot[i].length())/2),yMap +1);
		textcolor(10);
		cout << arrTenCot[i];
		textcolor(7);
	}
	// ket thuc in ten cot
	
	// int thanh doc
	for(int j = yMap; j <=yMap+32;j++)
	{
		gotoxy(arrToaDoBangChiTet[0],j);
		cout << (char)179;
		gotoxy(arrToaDoBangChiTet[4],j);
		cout << (char)179;
		if(j<yMap+30)
		{
			gotoxy(arrToaDoBangChiTet[1], j);
			cout << (char)179;
			gotoxy(arrToaDoBangChiTet[2], j);
			cout << (char)179;
			gotoxy(arrToaDoBangChiTet[3], j);
			cout << (char)179;
		}
	}
	// ket thuc in thanh doc
	for(int i = arrToaDoBangChiTet[0]; i <= arrToaDoBangChiTet[4];i++)
	{
		// in cac khop noi giua thnah ngang va doc
		gotoxy(i,yMap);
		if(i==arrToaDoBangChiTet[1] || i == arrToaDoBangChiTet[2] || i == arrToaDoBangChiTet[3])
			cout << (char)194; 
		
		else if(i == arrToaDoBangChiTet[0])
			cout << (char)218; 
		
		else if(i == arrToaDoBangChiTet[4])
			cout << (char)191; 
		
		else cout << (char)196;
		
		// ket thuc
		
		// in thanh ngang tren
		gotoxy(i,yMap+2);
		if(i == arrToaDoBangChiTet[1] || i == arrToaDoBangChiTet[2] || i ==arrToaDoBangChiTet[3])
			cout << (char)197;
	
		else if(i == arrToaDoBangChiTet[0])
			cout << (char)195;
			
		else if(i == arrToaDoBangChiTet[4])
			cout << (char)180;
		else
			cout << (char)196;
		// in thanh ngang duoi
		gotoxy(i,yMap + 30);
		if (i == arrToaDoBangChiTet[1] || i == arrToaDoBangChiTet[2] || i == arrToaDoBangChiTet[3])
			cout << (char)193;
		else if (i == arrToaDoBangChiTet[0])
			cout << (char)195;

		else if (i == arrToaDoBangChiTet[4])
		{
			cout << char(180);
		}
		else
		{
			cout << (char)196;
		}
		gotoxy(i, yMap + 32);

		if (i == arrToaDoBangChiTet[0])
		{
			cout << (char)192;
		}
		else if (i == arrToaDoBangChiTet[4])
		{
			cout << (char)217;
		}
		else
		{
			cout << (char)196;
		}
		gotoxy(arrToaDoBangChiTet[0] + 1, yMap + 31);
		cout << " <--Truoc                                                              Sau-->";
		Nocursortype();
	}
}
                            // KET THUC HAM GIAO DIEN
							// BAT DAU HAM PHU
int soSanhNgay(Date a, Date b)
{
	if(a.nam > b.nam)
	{
		return 1;
	}
	else if(a.nam < b.nam)
	{
		return -1;
	}
	else
	{
		if(a.thang > b.thang)
		{
			return 1;
		}
		else if(a.thang < b.thang)
		{
			return -1;
		}
		else
		{
			if(a.ngay > b.ngay)
			{
				return 1;
			}
			else if(a.ngay < b.ngay)
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}
	}
}
string to_String(int num)
{
	string kq;
	ostringstream convert;
	convert << num;
	kq = convert.str();
	return kq;
}
bool kiemTraChuoi(string s,int doDaiChuoi)
{
	if(s[0]==32 || s.size() ==0)
		return false;
	return true;
}
bool kiemTraDoDaiMaVT(string s)
{
	if(s.size()==10)
		return true;
	return false;
}
void Canhbao(string s,int xMap,int yMap)
{
    do
    {
       textcolor(12);
        gotoxy(xMap,yMap);
       	cout<<s;//hien thi 1 chuoi ki tu
        Sleep(500);
        gotoxy(xMap,yMap);
        for(int i=0;i<s.size();i++) cout<<" ";
        Sleep(200);
        textcolor(0);
    }
    while(!kbhit());
    gotoxy(xMap,yMap);
	for(int i=0;i<s.size();i++) cout<<" ";
	textcolor(7);
}
int chiChoNhapSo(char so[])
{
	int i =0;
	while(so[i]!=NULL)
	{
		if('0'>so[i]||so[i]>'9')
			return false;
		i++;
	}
	return true;
}
// Ham lay nam hien tai
int layNamHienTai(){
	time_t now = time(0); // lay thoi gian dua tren he thong hien tai
	
	tm *laytime = localtime(&now); 
	return 1900+laytime->tm_year;
}
void layNgayThangHienTai(int &ngay, int &thang,int &nam){
	time_t hienTai = time(0);
	tm *ltm = localtime(&hienTai);
	ngay = ltm->tm_mday;
	thang = ltm->tm_mon +1;
	nam = ltm->tm_year +1900;
}
//int lenghSo(int n){
//	return (int)log10(n) +1;
//}


								// KET THUC HAM PHU
								// BAT DAU VAT TU
void InitVT(Tree &root)
{
	root = NULL;
}
bool Empty(Tree root)
{
	return root == NULL ? true : false;
}
int soSanh2Chuoi(string a, string b) // dung de so sanh mavt khi them moi vao
{
	if(a.length() == b.length())
	{
		if(a>b)
		{
			return 1;
		}
		else if(a <b)
		{
			return -1;
		}
		else if(a == b)
		{
			return -1;
		}
	}
	else
	{
		if(a.length() > b.length())
		{
			return 1;
		}
		else if(a.length() < b.length())
		{
			return -1;
		}
	}
}
Tree taoNodeVT(VATTU data)
{
	NODE_VATTU* p = new NODE_VATTU;
	p->Data =data;
	p->pLeft = p->pRight =NULL;
	return p;
}
void Insert(Tree &t, VATTU data)
{
	if(t == NULL)
	{
		t = taoNodeVT(data);
	}
	else
	{
		if(soSanh2Chuoi(data.MaVT,t->Data.MaVT) == -1)
		{
			Insert(t->pLeft,data);
		}
		else if(soSanh2Chuoi(data.MaVT,t->Data.MaVT) == 1)
		{
			Insert(t->pRight,data);
		}
	}
}
NODE_VATTU* Search(Tree t, string x)
{
	if(t == NULL)
	{
		return NULL;
	}
	while(t->Data.MaVT !=x)
	{
		if(soSanh2Chuoi(t->Data.MaVT,x) == 1)
		{
			t = t->pLeft;
		}
		else
		{
			t = t->pRight;
		}
	}
    return t;
}
NODE_VATTU* kiemTraTrungMaVT(Tree t,string maVT)
{
	if(t != NULL)
	{
		if(strcmp(t->Data.MaVT, maVT.c_str()) == 0)
		{
			NODE_VATTU *p = new NODE_VATTU;
			p  = t;
			return p;
		}
		if(strcmp(t->Data.MaVT, maVT.c_str()) == 1)
			return kiemTraTrungMaVT(t->pLeft, maVT);
		if(strcmp(t->Data.MaVT, maVT.c_str()) == -1)
			return kiemTraTrungMaVT(t->pRight, maVT);
	}
	return NULL;
}
int kiemTraTrungMNV(string MNV)
{
	for(int i=0;i<dsnv.soLuongNV+1;i++)
	{
		if(strcmp(dsnv.nv[i].MaNV,MNV.c_str())==0)
		{
			return false;
		}
	}
	return true;
}
void timPhanTuTheMang(Tree &t1, Tree &t2)
{
	if(t2->pLeft !=NULL)
	{
		timPhanTuTheMang(t1,t2->pLeft);
	}
	else 
	{
		t1->Data = t2->Data;
		t1 =t2;
		t2 = t2->pRight;
	}
}
int countNode(Tree &t)
{
	if(t == NULL)
	{
		return 0;
	}
	else 
	{
		return 1+countNode(t->pLeft) + countNode(t->pRight);
	}
}
string arrMVT[500];
int nVT;
void LNR(Tree t)
{
	if (t != NULL)
	{
		LNR(t->pLeft);
		arrMVT[nVT++]=t->Data.MaVT;
		LNR(t->pRight);
	}
}
void nhapVatTu()
{
	system("cls");
	VATTU data;
	textcolor(10);
	gotoxy(40,2);
	cout << "THEM VAT TU CO THE NHAP VAO KHO";
	gotoxy(40,3);
	cout << "Tong so vat tu hien tai: "<< countNode(t);
	textcolor(7);
	veHTSearch("Ma Vat Tu","Ten Vat Tu","So luong ton","DVT");
	string maVT="", tenVT="",dvt="";
	bool ischeck=false;
	int vitri, key;
	int flag =0;
	int loop=0;
	int y;
	int slt=0;
	
	VeNVVT(18,7);
	VeNVVT2(18,7);
	gotoxy(20,7);
	int dong=0;
	while(loop ==0)
	{
		while(!kbhit())
		{
			y=7+2*dong;
			if(flag ==0) vitri = 20+maVT.length();
			else if(flag == 1) vitri = 35+tenVT.length();
			else if(flag ==2) vitri = 79+dvt.length();
			key =getch();
			if(key == 0)
			{
				key == getch();
			}
			else if(key == 27)
			{
				if(veKhungYesNo("       Ban co muon thoat?",0))
				{
					system("cls");
					return;
				}
				else
				{
					xoaKhungYN();
					continue;
				}
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90) || key == 32)
			{
				if(flag == 0 && maVT.size()<10 && key !=32)
				{
					gotoxy(vitri,y);
					if(key >=97 && key <=122)
						key = key -32;
					cout << (char)key;
					maVT.insert(maVT.end(),1,(char)key);
				}
				else if(flag ==1 && tenVT.size() < 20)
				{
					gotoxy(vitri,y);
					if(vitri == vitri -tenVT.size())
					{
						if(key == 32)
						{
							flag=1;
							continue;
						}
						if((key >=97 && key <=122))
							key = key -32;
					}
					
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << (char)key;
					tenVT.insert(tenVT.end(),1,(char)key);
						
				}
				else if(flag ==2 && dvt.size() < 8 && key !=32)
				{
					gotoxy(vitri,y);
					if(vitri == vitri -dvt.size())
					{
						if(key == 32)
						{
							flag=2;
							continue;
						}
						if((key >=97 && key <=122))
							key = key -32;
					}
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << (char)key;
					dvt.insert(dvt.end(),1,(char)key);	
				}
			}
			else if(key ==13 || key ==9)
			{
				if(flag ==0)
				{
					if(maVT.size() ==0)
					{
						while(!kbhit())
							Canhbao("Khong duoc de trong.Xin nhap lai!!",30,1);
						do{
							int key1 = getch();
							
						}while(key!=13&&key!=27);
						gotoxy(vitri,y);
					}
					else if(kiemTraDoDaiMaVT(maVT) == false)
					{
						while(!kbhit())
						{
							Canhbao("Do dai ma vat tu phai la 10 ky tu.Xin nhap lai",30,1);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=27);
						gotoxy(vitri,y);
					}
					else if(kiemTraTrungMaVT(t,maVT) !=NULL)
					{
							while(!kbhit())
						{
							Canhbao("Ma "+maVT+" da ton tai trong he thong.Xin nhap lai",30,1);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=27);
						gotoxy(vitri,y);
					}
					else
					{
						gotoxy(35,y);
						flag =1;
					}
				}
				else if(flag ==1)
				{
					if(tenVT.size() ==0)
					{
						while(!kbhit())
							Canhbao("Khong duoc de trong.Xin nhap lai!!",30,1);
						do{
							int key1 = getch();
							
						}while(key!=13&&key!=27);
						gotoxy(vitri,y);
					}
					else
					{
						gotoxy(60,y);
						cout << "     "<<slt;
						gotoxy(79,y);
						flag =2;
					}
				}
				else if(flag ==2)
				{
					if(dvt.size() ==0)
					{
						while(!kbhit())
							Canhbao("Khong duoc de trong.Xin nhap lai!!",30,1);
						do{
							int key1 = getch();
							
						}while(key!=13&&key!=27);
						gotoxy(vitri,y);
					}
					else
					{
						strcpy(data.MaVT,maVT.c_str());
						strcpy(data.TenVT,tenVT.c_str());
						strcpy(data.DVT,dvt.c_str());
						data.SoLuongTon =slt;
						Insert(t,data);
						textcolor(10);
						gotoxy(65,3);
						cout << countNode(t);
						textcolor(7);
						dong++;
						maVT="";
						tenVT="";
						dvt="";
						VeNVVT(18,7+dong*2);
						VeNVVT2(18,7+dong*2);
						gotoxy(20,7+dong*2);
						flag =0;
					}
				}
				
			}
			else if(key ==8)
			{
				if(flag ==0 && maVT.size() > 0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout << " ";
					gotoxy(vitri,y);
					maVT.erase(maVT.end()-1);
				}
				else if(flag ==1 && tenVT.size() >=0)
				{
					if(vitri==vitri-tenVT.size())
					{
						gotoxy(20+maVT.size(),y);
						flag=0;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout << " ";
						gotoxy(vitri,y);
						tenVT.erase(tenVT.end()-1);
					}
					
				}
				else if(flag ==2&&dvt.size()>=0)
				{
					if(vitri==vitri-dvt.size())
					{
						gotoxy(35+tenVT.size(),y);
						flag=1;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout << " ";
						gotoxy(vitri,y);
						dvt.erase(dvt.end()-1);
					}
					
					
				}
			}
		}
	}
}

void xuatVattu(VATTU data,int stt)
{
	gotoxy(20,3+yMap +stt*2);
	cout << data.MaVT;
	gotoxy(36+((21-strlen(data.TenVT))/2),3+yMap +stt*2);
	cout << data.TenVT;
	gotoxy(57+((26-to_String(data.SoLuongTon).size())/2),3+yMap +stt*2);
	cout << data.SoLuongTon;
	gotoxy(75+((27-strlen(data.DVT))/2),3+yMap +stt*2);
	cout << data.DVT;
}
void xoaNodeVT(Tree &t, string maVT)
{
	if(t == NULL)
	{
		veKhungTB("         Khong co vat tu");
		system("cls");
		return;
	}
   if(strcmp(t->Data.MaVT,maVT.c_str())== 1)
	{
		xoaNodeVT(t->pLeft,maVT);
	}
	else if(strcmp(t->Data.MaVT,maVT.c_str())== -1)
	{
		xoaNodeVT(t->pRight,maVT);
	}
	else
	{
		NODE_VATTU *p =t;
		if(t->pLeft == NULL)
		{
			t =t->pRight;
		}
		else if(t->pRight == NULL)
		{
			t =t->pLeft;
		}
		else
		{
			timPhanTuTheMang(p,t->pRight);
		}
		delete p;
		return;
	}
}
void xuatDanhSachVT(int page)
{
	system("cls");
	Nocursortype();
	gotoxy(38,2);
	cout << "BANG DANH SACH VAT TU CO TRONG KHO";
	string arr[4] ={"Ma vat tu", "Ten vat tu", "So luong ton","DVT"};
	veBangChiTiet(arr,3);
	int k =0;
	LNR(t);
	for(int i = page * 14; i < (nVT > (page + 1) * 14 ? 14 : nVT) ;i++)
	{
		NODE_VATTU *p = new NODE_VATTU;
		p = Search(t,arrMVT[i]);
		xuatVattu(p->Data,k++);
	}
	
}
void quanLysangTrangVT()
{
	if(t == NULL)
	{
		veKhungTB("         Khong co vat tu");
		system("cls");
		return;
	}
	int page =0,i=0,vitri=0;
	int key;
	if(t !=NULL)
		xuatDanhSachVT(page);
	while(true)
	{
			
		while(!kbhit())
		{
			key = getch();
			if(key == 0)
			{
				key = getch();
			}
			else if(key == 224)
			{
				key =  getch();
				if(key == 77 && page >0)
				{
					page--;
					i = page*14;
					vitri =0;
					break;
				}
				else if(key == 77 && page < (nVT%14 ==0? (nVT /14) : (nVT / 14) +1) -1)
				{
					page++;
					vitri =0;
					i = page *14;
					break;
				}
			}
			else if(key == 27)
			{
				system("cls");
				return;
			}
		}	
		nVT =0;
		LNR(t);
		xuatDanhSachVT(page);
		if(nVT !=0&& nVT%14==0)
		{
			page++;
		}
	}
}
void xoaVatTu()
{
	if(t==NULL)
	{
		veKhungTB("         Khong co vat tu");
		system("cls");
		return;
	}
	system("cls");
     gotoxy(36,2);
    cout << "Ma vat tu: ";
	string mavt;
	int loop =1;
	int key,vitri;	
	int y=2;
		while(loop ==1)
		{
			while(!kbhit())
			{
				vitri = 47+mavt.size();
				key =getch();
				if(key ==27)
				{
					loop =0;
					break;
				}
				else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
				{
					if(mavt.length()  <10)
					{
		 				gotoxy(vitri,y);
						if(key >=97 && key <=122)
							key = key -32;
						cout << (char)key;
						mavt.insert(mavt.end(),1,(char)key);
				   }
				}
				else if(key ==13)
				{
					if(kiemTraTrungMaVT(t,mavt) == NULL)
					{
						while(!kbhit())
							Canhbao("Khong tim thay ma vat tu "+mavt+".Xin kiem tra lai!!",30,1);
						do{
							int key1 = getch();
						}while(key!=13);
						gotoxy(vitri,y);
					}
					else
					{
						system("cls");
						NODE_VATTU* p = Search(t,mavt);
						veHTSearch("Ma Vat Tu","Ten Vat Tu","So Luong Ton","DVT");
						gotoxy(36,2);
						cout << "Ma Vat Tu: "<<mavt;
						VeNVVT(18,7);
						VeNVVT2(18,7);
						gotoxy(20,7);
						cout << p->Data.MaVT;
						gotoxy(36+((18-strlen(p->Data.TenVT)))/2,7);
						cout << p->Data.TenVT;
						gotoxy(68,7);
						cout << p->Data.SoLuongTon;
						gotoxy(79+((6-strlen(p->Data.DVT)))/2,7);
						cout << p->Data.DVT;
						if(veKhungYesNo("Ban co muon xoa "+mavt+"?",0))
						{
							xoaNodeVT(t,mavt);
							system("cls");
							veKhungTB(" Xoa thanh cong "+mavt+"");
							system("cls");
							return;
						}
						else
						{
							NODE_VATTU* p = Search(t,mavt);
							system("cls");
							gotoxy(36,2);
							cout << "Ma Vat Tu: "<<mavt;
							veHTSearch("Ma Vat Tu","Ten Vat Tu","So Luong Ton","DVT");
							VeNVVT(18,7);
							VeNVVT2(18,7);
							gotoxy(20,7);
							cout << p->Data.MaVT;
							gotoxy(36+((18-strlen(p->Data.TenVT)))/2,7);
							cout << p->Data.TenVT;
							gotoxy(68,7);
							cout << p->Data.SoLuongTon;
							gotoxy(79+((6-strlen(p->Data.DVT)))/2,7);
							cout << p->Data.DVT;
							veKhungTB("         Da huy xoa ");
							system("cls");
							return;
						}
						return;
					}
				}
				else if(key == 8 && mavt.length() >0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout << " ";
					gotoxy(vitri,y);
					mavt.erase(mavt.end()-1);
				}
			}
		}
}
void timKiemVT()
{
	if(t==NULL)
	{
		veKhungTB("         Khong co vat tu");
		system("cls");
		return;
	}
	system("cls");
		gotoxy(36,2);
		cout << "Ma Vat tu: ";
		string mavt;
		int loop =1;
		int key,vitri;
		int y =2;
		while(loop ==1)
		{
			while(!kbhit())
			{
				vitri = 47+mavt.size();
				key =getch();
				if(key ==27)
				{
					system("cls");
					loop =0;
					break;
				}
				else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
				{
					if(mavt.length()  <10)
					{
		 				gotoxy(vitri,y);
						if(key >=97 && key <=122)
							key = key -32;
						cout << (char)key;
						mavt.insert(mavt.end(),1,(char)key);
				   }
				}
				else if(key ==13)
				{
					if(kiemTraTrungMaVT(t,mavt) == NULL)
					{
						while(!kbhit())
							Canhbao("Khong tim thay ma vat tu "+mavt+".Xin kiem tra lai!!",30,1);
						do{
							int key1 = getch();
						}while(key!=13);
						gotoxy(vitri,y);
					}
					else
					{
						system("cls");
						NODE_VATTU* p = Search(t,mavt);
						veHTSearch("Ma Vat Tu","Ten Vat Tu","So Luong Ton","DVT");
						VeNVVT(18,7);
						VeNVVT2(18,7);
						gotoxy(20,7);
						cout << p->Data.MaVT;
						gotoxy(36+((18-strlen(p->Data.TenVT))/2),7);
						cout << p->Data.TenVT;
						gotoxy(68,7);
						cout << p->Data.SoLuongTon;
						gotoxy(79+((6-strlen(p->Data.DVT))/2),7);
						cout << p->Data.DVT;
					}
				}
				else if(key == 8 && mavt.length() >0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout << " ";
					gotoxy(vitri,y);
					mavt.erase(mavt.end()-1);
				}
			}
		}
}
void hieuChinhVatTu()
{
	if(t==NULL)
	{
		veKhungTB("         Khong co vat tu");
		system("cls");
		return;
	}
	system("cls");
	gotoxy(36,2);
	cout << "Ma Vat Tu: ";
	string mavt;
	int loop =0;
	int key1,vitri1;
	NODE_VATTU * q;
	while(loop ==0)
	{
		while(!kbhit())
		{
			vitri1 = 48+mavt.size();
			key1 =getch();
			if(key1 ==27)
			{
				system("cls");
				loop =2;
				break;
			}
			else if((key1 >= 48&& key1 <=57) || (key1 >=97 && key1 <=122) || (key1 >=65 && key1 <=90))
			{
				if(mavt.length()  <10)
				{
		 			gotoxy(vitri1,2);
					if(key1 >=97 && key1 <=122)
						key1 = key1 -32;
					cout << (char)key1;
					mavt.insert(mavt.end(),1,(char)key1);
				}
			}
			else if(key1 ==13)
			{
				if(kiemTraTrungMaVT(t,mavt) == NULL)
				{
					while(!kbhit())
						Canhbao("Khong tim thay ma vat tu "+mavt+".Xin kiem tra lai!!",30,1);
					do{
						int key2 = getch();
					}while(key1!=13);
					gotoxy(vitri1,2);
				}
				else
				{
					q = Search(t,mavt);
					veHTSearch("Ma Vat Tu","Ten Vat Tu","So Luong Ton","DVT");
					VeNVVT(18,7);
					VeNVVT2(18,7);
					gotoxy(20,7);
					cout << q->Data.MaVT;
					gotoxy(35,7);
					cout << q->Data.TenVT;
					gotoxy(57,7);
					cout << q->Data.SoLuongTon;
					gotoxy(79,7);
					cout << q->Data.DVT;
					loop =1;
					break;
				}
			}
			else if(key1 == 8 && mavt.length() >0)
			{
				vitri1--;
				gotoxy(vitri1,2);
				cout << " ";
				gotoxy(vitri1,2);
				mavt.erase(mavt.end()-1);
			}
		}
	}
	int exit =0;
	int key,vtr;
	string tam1 = q->Data.MaVT,tam2=q->Data.TenVT,tam3=q->Data.DVT;
	int slt = q->Data.SoLuongTon;
	int th=3;
	gotoxy(79+tam3.size(),7);
	while(exit ==0)
	{
		while(!kbhit())
		{
			if(th==1)
			{
				vtr = 20+tam1.size();
			}
			else if(th==2)
			{
				vtr = 35+tam2.size();
			}
			else if(th ==3)
			{
				vtr = 79+tam3.size();
			}
			key = getch();
			if(key == 0)
			{
				key == getch();
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90) || key ==32)
			{
				if(th==1 && tam1.size() <10&& key !=32)
				{
					gotoxy(vtr,7);
					if(key >=97 && key <=122)
						key = key -32;
					cout << (char)key;
					tam1.insert(tam1.end(),1,(char)key);
				}
				else if(th==2 && tam2.size() < 20)
				{
					gotoxy(vtr,7);
					if((key >=97 && key <=122)&& (vtr==vtr-tam2.size()))
						key = key -32;
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << char(key);
					tam2.insert(tam2.end(),1,(char)key);
				}
				else if(th==3 && tam3.size() <5)
				{
					gotoxy(vtr,7);
					if((key >=97 && key <=122)&& (vtr==vtr-tam3.size()))
						key = key -32;
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << char(key);
					tam3.insert(tam3.end(),1,(char)key);
				}
			}
			else if(key ==13||key ==9)
			{
				if(th==1)
				{
					if(tam1.size()==0)
					{
						tam1=q->Data.MaVT;
						gotoxy(20,7);
						cout << tam1;
						gotoxy(35+tam2.size(),7);
						th=2;
					}
					else if(tam1.size() <10)
					{
						while(!kbhit())
							Canhbao("Ma vat tu la 10 ky tu.Xin nhap lai lai!!",30,1);
						do{
							int key2 = getch();
						}while(key!=13);
						gotoxy(vtr,7);
					}
					if(strcmp(tam1.c_str(),q->Data.MaVT)==0)
					{
						tam1=q->Data.MaVT;
						gotoxy(20,7);
						cout << tam1;
						gotoxy(35+tam2.size(),7);
						th=2;
					}
					else if(kiemTraTrungMaVT(t,tam1)!=NULL)
					{
						while(!kbhit())
							Canhbao("Trung ma vat tu.Xin kiem tra lai!!",30,1);
						do{
							int key2 = getch();
						}while(key!=13);
						gotoxy(vtr,7);
					}
					else
					{
						gotoxy(35+tam2.size(),7);
						th=2;
					}
				}
				else if(th==2)
				{
					if(tam2.size()==0)
					{
						tam2=q->Data.TenVT;
						gotoxy(35,7);
						cout << tam2;
					}
					else{
						gotoxy(79+tam3.size(),7);
						th=3;
					}
				}
				else if(th==3)
				{
					if(tam3.size()==0)
					{
						tam3=q->Data.DVT;
						gotoxy(79,7);
						cout << tam3;
					}
					else{
						
						if(veKhungYesNo("    Ban co muon thay doi khong ?",0))
						{
							
							
							strcpy(q->Data.MaVT,tam1.c_str());
							strcpy(q->Data.TenVT,tam2.c_str());
							q->Data.SoLuongTon = slt;
							strcpy(q->Data.DVT,tam3.c_str());
							system("cls");
							gotoxy(36,2);
							cout << "Ma Vat Tu: " << q->Data.MaVT;
							veHTSearch("Ma Vat Tu","Ten Vat Tu","So Luong Ton","DVT");
							VeNVVT(18,7);
							VeNVVT2(18,7);
							gotoxy(20,7);
							cout << q->Data.MaVT;
							gotoxy(35,7);
							cout << q->Data.TenVT;
							gotoxy(57,7);
							cout << q->Data.SoLuongTon;
							gotoxy(79,7);
							cout << q->Data.DVT;
							veKhungTB("        Da sua thanh cong");
							system("cls");
							return;
						}
						else
						{
							system("cls");
							gotoxy(36,2);
							cout << "Ma Vat Tu: " << q->Data.MaVT;
							veHTSearch("Ma Vat Tu","Ten Vat Tu","So Luong Ton","DVT");
							VeNVVT(18,7);
							VeNVVT2(18,7);
							gotoxy(20,7);
							cout << q->Data.MaVT;
							gotoxy(35,7);
							cout << q->Data.TenVT;
							gotoxy(57,7);
							cout << q->Data.SoLuongTon;
							gotoxy(79,7);
							cout << q->Data.DVT;
							veKhungTB("        Da huy tac vu sua");
							system("cls");
							return;
						}
					}
				}
			}
			else if(key ==8)
			{
				if(th==1 && tam1.size() > 0)
				{
					vtr--;
					gotoxy(vtr,7);
					cout << " ";
					gotoxy(vtr,7);
					tam1.erase(tam1.end()-1);
				}
				else if(th ==2 && tam2.size() >=0)
				{
					if(vtr==vtr-tam2.size())
					{
						gotoxy(20+tam1.size(),7);
						th=1;
					}
					else
					{
						vtr--;
					gotoxy(vtr,7);
					cout << " ";
					gotoxy(vtr,7);
					tam2.erase(tam2.end()-1);
					}
				}
				else if(th ==3 && tam3.size() >=0)
				{
					if(vtr==vtr-tam3.size())
					{
						gotoxy(35+tam2.size(),7);
						th=2;
					}
					else
					{
					vtr--;
					gotoxy(vtr,7);
					cout << " ";
					gotoxy(vtr,7);
					tam3.erase(tam3.end()-1);
					}
				}
			}
		}
	}
}
void doiCho2So(int &a, int &b)
{
	int temp =a;
	a =b;
	b =temp;
}



								// KET THUC VAT TU
								// NHAN VIEN
void themNV(string MNV,string TNV,string HNV,string Phai)
{
	dsnv.soLuongNV++;
	strcpy(dsnv.nv[dsnv.soLuongNV].MaNV,MNV.c_str());
	strcpy(dsnv.nv[dsnv.soLuongNV].Ho,HNV.c_str());
	strcpy(dsnv.nv[dsnv.soLuongNV].Ten,TNV.c_str());
	strcpy(dsnv.nv[dsnv.soLuongNV].Phai,Phai.c_str());
	dsnv.nv[dsnv.soLuongNV].fisrtHD =NULL;
}
void nhapNhanVien()
{
	system("cls");
	Yescursortype();
	gotoxy(18, 5);
	cout << char(179);
	gotoxy(18, 4);
	cout << char(218);
	for(int i = 0; i < 66; i++)
		cout << char(196);
	cout << char(191);
	gotoxy(33, 5);
	cout << char(179);
	gotoxy(33, 4);
	cout << char(194);
	gotoxy(18, 6);
	cout << char(195);
	
	for(int i = 0; i < 66; i++)
		cout << char(196);
		for(int i = 1; i < 3; i++)
		{
			gotoxy(33 + i*22, 4);
			cout << char(194);
			gotoxy(33 + i*22, 5);
			cout << char(179);
			gotoxy(33 + i*22, 6);
			cout << char(197);
		}
	gotoxy(33, 6);
	cout << char(197);
	gotoxy(85, 5);
	cout << char(179);
	gotoxy(85, 6);
	cout << char(180);
	int i = 0;
	textcolor(10);
	gotoxy(40,2);
	cout << "THEM NHAN VIEN VAO HE THONG";
	gotoxy(20, 5);
	cout << "Ma Nhan Vien";
	gotoxy(44, 5);
	cout << "Ho";
	gotoxy(65, 5);
	cout << "Ten";
	gotoxy(79, 5);
	cout << "Phai";
	textcolor(7);
	string MaNV ="";
	string Ho="";
	string Ten="";
	string Phai="";
	int flag=1;
	int loop =0;
	int vitri,key;
	int dong=0;
	int y;
	int dem =dsnv.soLuongNV;
	
	VeNVVT(18, 7);
	VeNVVT2(18,7);
	gotoxy(20,7);
	while(loop ==0)
	{
		while(!kbhit())
		{
			y = 7+dong*2;
			
			if(flag ==1)
			{	
				vitri=20+MaNV.size();
			}
			else if(flag ==2)
			{	
				vitri=35+Ho.size();
			}
			else if(flag ==3)
			{	
				vitri=57+Ten.size();
			}
			else if(flag ==4)
			{	
				vitri=79+Phai.size();
			}
			key = getch();
			if(key == 27)
			{
				if(veKhungYesNo("       Ban co muon thoat?",0))
				{
					system("cls");
					return;
				}
				else
				{
					xoaKhungYN();
					continue;
				}
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90) || key == 32)
			{
				if(flag == 1 && MaNV.size()<10 && key !=32)
				{
					gotoxy(vitri,y);
					if(key >=97 && key <=122)
						key = key -32;
					cout << (char)key;
					MaNV.insert(MaNV.end(),1,(char)key);
				}
				else if(flag ==2 && Ho.size() < 20)
				{
					gotoxy(vitri,y);
					if((key >=97 && key <=122)&& ((vitri==vitri-Ho.size())))
						key = key -32;
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << (char)key;
					Ho.insert(Ho.end(),1,(char)key);	
				}
				else if(flag ==3 && Ten.size() < 20)
				{
					gotoxy(vitri,y);
					if((key >=97 && key <=122)&& (vitri==vitri-Ten.size()))
						key = key -32;
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << (char)key;
					Ten.insert(Ten.end(),1,(char)key);	
				}
				else if(flag ==4 && Phai.size() < 3)
				{
					gotoxy(vitri,y);
					if((key >=97 && key <=122)&& (vitri==vitri-Phai.size()))
						key = key -32;
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << (char)key;
					Phai.insert(Phai.end(),1,(char)key);
				}
			}
			else if(key ==13||key ==9)
			{
				if(flag ==1)
				{
					if(MaNV.size()<10)
					{
						while(!kbhit())
						{
							Canhbao("Do dai ma nhan vien pham la 10 ki tu",30,1);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,y);
					}
					else if(kiemTraTrungMNV(MaNV)==false)
					{
						while(!kbhit())
						{
							Canhbao("Ma "+MaNV+" da ton tai.Xin nhap lai!",30,1);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,y);
					}
					else
					{
						gotoxy(35,y);
						flag =2;
					}
				}
				else if(flag ==2)
				{
					if(Ho.size()==0)
					{
						while(!kbhit())
						{
							Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,y);
					}
					else
					{
						gotoxy(57,y);
						flag =3;
					}
				}
				else if(flag ==3)
				{
					if(Ten.size()==0)
					{
						while(!kbhit())
						{
							Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,y);
					}
					else
					{
						gotoxy(79,y);
						flag =4;
					}
					
				}
				else if(flag ==4)
				{
					if(Phai.size()==0)
					{
						while(!kbhit())
						{
							Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,y);
					}
//					else if(Phai != "Nam" || Phai !="nam"|| Phai !="nu" || Phai !="Nu")
//					{
//						while(!kbhit())
//						{
//							Canhbao("Nhap sai phai : Nam/Nu.Xin nhap lai!",30,1);
//						}
//						do{
//							int key1 =getch();
//						}while(key !=13&&key!=27);
//						gotoxy(vitri,y);
//					}
					else
					{
						themNV(MaNV,Ten,Ho,Phai);
						MaNV ="";
						Ten ="";
						Ho ="";
						Phai= "";
						dong++;
						VeNVVT(18, 7+dong*2);
						VeNVVT2(18,7+dong*2);
						gotoxy(20,7+dong*2);
						flag =1;
					}
				}
			}
			else if(key ==8)
			{
				if(flag ==1 && MaNV.size() > 0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout << " ";
					gotoxy(vitri,y);
					MaNV.erase(MaNV.end()-1);
				}
				else if(flag ==2 && Ho.size() >=0)
				{
					if(vitri==vitri-Ho.size())
					{
						gotoxy(12+MaNV.size(),y);
						flag=1;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout << " ";
						gotoxy(vitri,y);
						Ho.erase(Ho.end()-1);
					}
					
				}
				else if(flag ==3&&Ten.size()>=0)
				{
					if(vitri==vitri-Ten.size())
					{
						gotoxy(27+MaNV.size(),y);
						flag=2;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout << " ";
						gotoxy(vitri,y);
						Ten.erase(Ten.end()-1);
					}
					
				}
				else if(flag ==4&&Phai.size()>=0)
				{
					if(vitri==vitri-Phai.size())
					{
						gotoxy(49+MaNV.size(),y);
						flag=3;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout << " ";
						gotoxy(vitri,y);
						Phai.erase(Phai.end()-1);
					}
					
				}
			}
			
		}
	}
	if(loop ==1)
	{
		return;
	}
}
	
void doicho2chuoi(char a[31],char b[31])
{
	char temp[31];
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b,temp);
}
void sortTheoTen()
{
	string temp1,temp2,temph1,temph2;
	for(int i =0;i<dsnv.soLuongNV;i++)
	{
		for(int j =i+1;j<dsnv.soLuongNV+1;j++)
		{
			temp1 =dsnv.nv[i].Ten;
			temp2 = dsnv.nv[j].Ten;
			temph1 =dsnv.nv[i].Ho;
			temph2=dsnv.nv[j].Ho;
			if(temp1 == temp2)
			{
				if(temph1 > temph2)
				{
					doicho2chuoi(dsnv.nv[i].MaNV,dsnv.nv[j].MaNV);
					doicho2chuoi(dsnv.nv[i].Ho,dsnv.nv[j].Ho);
					doicho2chuoi(dsnv.nv[i].Ten,dsnv.nv[j].Ten);
					doicho2chuoi(dsnv.nv[i].Phai,dsnv.nv[j].Phai);
				}
			}
			else if(temp1 > temp2)
			{
				doicho2chuoi(dsnv.nv[i].MaNV,dsnv.nv[j].MaNV);
				doicho2chuoi(dsnv.nv[i].Ho,dsnv.nv[j].Ho);
				doicho2chuoi(dsnv.nv[i].Ten,dsnv.nv[j].Ten);
				doicho2chuoi(dsnv.nv[i].Phai,dsnv.nv[j].Phai);
			}
		}
	}
}
void xuatNhanVien(NHANVIEN data,int stt)
{
	gotoxy(20,3+yMap +stt*2);
	cout << data.MaNV;
	gotoxy(36+((21-strlen(data.Ho))/2),3+yMap +stt*2);
	cout << data.Ho;
	gotoxy(57+((26-strlen(data.Ten))/2),3+yMap +stt*2);
	cout << data.Ten;
	gotoxy(82+((12-strlen(data.Phai))/2),3+yMap +stt*2);
	cout << data.Phai;
}
void XuatDanhSachNV(int page, int vitri=0)
{
	system("cls");
	Nocursortype();
	string arr[]={"Ma NV","Ho","Ten","Phai"};
	gotoxy(45,2);
	cout << "DANH SACH NHAN VIEN";
	veBangChiTiet(arr,3);
	sortTheoTen();
	int k=0;
	for(int i =1;i< dsnv.soLuongNV+1;i++)
	{
		xuatNhanVien(dsnv.nv[i],k);
		k++;
	}
}
void quanLyXuatNV()
{
	if(dsnv.soLuongNV==0)
	{
		veKhungTB("       Khong co nhan vien");
		system("cls");
		return;
	}
	else
	{
		int key;
	int page =0,i=0,vitri=0;
	XuatDanhSachNV(page);
	while(true)
	{
		while(!kbhit())
		{
			key = getch();
			if(key == 0)
			{
				key = getch();
			}
			else if (key == 224)
			{
				key = _getch();
				if (key == 81 && page > 0)
				{
					page--;
					i = page * 14;
					vitri = 0;
					break;
				}
				else if (key == 73 && page < (dsnv.soLuongNV % 14 == 0 ? (dsnv.soLuongNV / 14) : (dsnv.soLuongNV / 14) + 1) - 1)
				{
					page++;
					i = page * 14;
					vitri = 0;
					break;
				}
			}
			else if (key == 27) // esc
			{
				system("cls");
				return;
			}
		}
		XuatDanhSachNV(page);
		if (dsnv.soLuongNV != 0 && dsnv.soLuongNV % 14 == 0)
		{
			page++;
		}
	}
	}
	
}
void TimKiemNV()
{
	if(dsnv.soLuongNV==0)
	{
		veKhungTB("       Khong co nhan vien");
		system("cls");
		return;
	}
	system("cls");
	gotoxy(36,2);
	cout << "Ma Nhan Vien: ";
	string manv;
	int loop =1;
	int key,vitri;
	int y=2;
	while(loop ==1)
	{
		while(!kbhit())
		{
			vitri = 50+manv.size();
			key =getch();
			if(key ==27)
			{
				loop =0;
				system("cls");
				break;
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
			{
				if(manv.length()  <10)
				{
		 			gotoxy(vitri,y);
					if(key >=97 && key <=122)
						key = key -32;
					cout << (char)key;
					manv.insert(manv.end(),1,(char)key);
			   }
			}
			else if(key ==13)
			{
				if(manv.size() <10)
				{
					while(!kbhit())
						Canhbao("Do dai ma nhan vine phai 10 ki tu.Xin kiem tra lai!!",30,1);
					do{
						int key1 = getch();
					}while(key!=13);
					gotoxy(vitri,y);
				}
				if(kiemTraTrungMNV(manv))
					{
						while(!kbhit())
							Canhbao("Khong tim thay ma nhan vien "+manv+".Xin kiem tra lai!!",30,1);
						do{
							int key1 = getch();
						}while(key!=13);
						gotoxy(vitri,y);
					}
				else
				{
					int vtr;
					for(int i =0;i<dsnv.soLuongNV+1;i++)
					{
						if(dsnv.nv[i].MaNV==manv) 
						{
							vtr=i;
							break;
						}
					}
					veHTSearch("Ma Nhan Vien","Ho","Ten","Phai");
					VeNVVT(18,7);
					VeNVVT2(18,7);
					gotoxy(20,7);
					cout << dsnv.nv[vtr].MaNV;
					gotoxy(36+((18-strlen(dsnv.nv[vtr].Ho))/2),7);
					cout << dsnv.nv[vtr].Ho;
					gotoxy(58+((18-strlen(dsnv.nv[vtr].Ten))/2),7);
					cout << dsnv.nv[vtr].Ten;
					gotoxy(79+((6-strlen(dsnv.nv[vtr].Phai))/2),7);
					cout << dsnv.nv[vtr].Phai;
						
					
				}
			}
			else if(key == 8 && manv.length() >0)
			{
				vitri--;
				gotoxy(vitri,y);
				cout << " ";
				gotoxy(vitri,y);
				manv.erase(manv.end()-1);
			}
		}
	}
}

void deleteNV(int i)
{
	for(int j=i;j<dsnv.soLuongNV-1;j++)
	{
		dsnv.nv[j]=dsnv.nv[j+1];
	}
	dsnv.soLuongNV-=1;
}
void XoaNhanVien()
{
	if(dsnv.soLuongNV==0)
	{
		veKhungTB("       Khong co nhan vien");
		system("cls");
		return;
	}
	system("cls");
	Yescursortype();
	gotoxy(36,2);
	cout << "Ma Nhan Vien: ";
	string manv;
	int loop =1;
	int key,vitri;
	int y=2;
	while(loop ==1)
	{
		while(!kbhit())
		{
			vitri = 50+manv.size();
			key =getch();
			if(key ==27)
			{
				system("cls");
				loop =0;
				break;
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
			{
				if(manv.length()  <10)
				{
		 			gotoxy(vitri,y);
					if(key >=97 && key <=122)
						key = key -32;
					cout << (char)key;
					manv.insert(manv.end(),1,(char)key);
			   }
			}
			else if(key ==13)
			{
				if(manv.size() <10)
				{
					while(!kbhit())
						Canhbao("Do dai ma nhan vine phai 10 ki tu.Xin kiem tra lai!!",30,1);
					do{
						int key1 = getch();
					}while(key!=13);
					gotoxy(vitri,y);
				}
				if(kiemTraTrungMNV(manv)==true)
				{
						while(!kbhit())
							Canhbao("Khong tim thay ma nhan vien "+manv+".Xin kiem tra lai!!",30,1);
						do{
							int key1 = getch();
						}while(key!=13);
						gotoxy(vitri,y);
				}
					int vtr;
					for(int i =0;i<dsnv.soLuongNV+1;i++)
					{
						if(dsnv.nv[i].MaNV==manv)
						{
							vtr=i;
							 break;
						 } 
					}
					veHTSearch("Ma Nhan Vien","Ho","Ten","Phai");
					VeNVVT(18,7);
					VeNVVT2(18,7);
					gotoxy(20,7);
					cout << dsnv.nv[vtr].MaNV;
					gotoxy(36+((18-strlen(dsnv.nv[vtr].Ho))/2),7);
					cout << dsnv.nv[vtr].Ho;
					gotoxy(58+((18-strlen(dsnv.nv[vtr].Ten))/2),7);
					cout << dsnv.nv[vtr].Ten;
					gotoxy(79+((6-strlen(dsnv.nv[vtr].Phai))/2),7);
					cout << dsnv.nv[vtr].Phai;
					if(veKhungYesNo("     Ban co muon xoa khong?",0))
					{
						deleteNV(vtr);
						system("cls");
						veKhungTB(" Xoa thanh cong "+manv+"");
						system("cls");
						return;
					}
					else
					{
						system("cls");
						gotoxy(36,2);
						cout << "Ma Nhan Vien: "+manv+"";
						veHTSearch("Ma Nhan Vien","Ho","Ten","Phai");
						VeNVVT(18,7);
						VeNVVT2(18,7);
						gotoxy(20,7);
						cout << dsnv.nv[vtr].MaNV;
						gotoxy(36+((18-strlen(dsnv.nv[vtr].Ho))/2),7);
						cout << dsnv.nv[vtr].Ho;
						gotoxy(58+((18-strlen(dsnv.nv[vtr].Ten))/2),7);
						cout << dsnv.nv[vtr].Ten;
						gotoxy(79+((6-strlen(dsnv.nv[vtr].Phai))/2),7);
						cout << dsnv.nv[vtr].Phai;
						veKhungTB("       Da huy xoa "+manv+"");
						system("cls");
						return;
					}
			}
			else if(key == 8 && manv.length() >0)
			{
				vitri--;
				gotoxy(vitri,y);
				cout << " ";
				gotoxy(vitri,y);
				manv.erase(manv.end()-1);
			}
		}
	}
}
void ghiNhanVien()
{
	ofstream ofs("NHANVIEN",ios::out);
	for(int i =0;i<dsnv.soLuongNV;i++)
	{
		ofs << dsnv.nv[i].MaNV <<endl << dsnv.nv[i].Ho << endl<< dsnv.nv[i].Ten <<endl<< dsnv.nv[i].Phai << endl;
	}
	ofs.close();
}
void docNhanVien()
{
//	ifstream ifs("NHANVIEN",ios::in);
//	while((getline(ifs,dsnv.nv[dsnv.soLuongNV].MaNV))!=false)
//	{
//		fflush(stdin);
//		getline(ifs,dsnv.nv[dsnv.soLuongNV].Ho);
//		getline(ifs,dsnv.nv[dsnv.soLuongNV].Ten);
//		getline(ifs,dsnv.nv[dsnv.soLuongNV].Phai);
//		int flag=0;
//		for(int i=0;i<dsnv.soLuongNV;i++)
//			if(dsnv.nv[i].MaNV== dsnv.nv[dsnv.soLuongNV].MaNV)
//			{
//				flag=1;
//				break;
//			}
//		if(flag==0)
//			dsnv.soLuongNV++;
//	}
//	ifs.close();
}
								// END
								// BAT DAU CHI TIET HOA DON
NODECT_HOADON* GetNodeCT(CT_HOADON data)
{
	
	NODECT_HOADON* p = new NODECT_HOADON;
	p->pNext = NULL;
	p->Data = data;
	return p;
}
NODECT_HOADON *AddTailCT(NODECT_HOADON *dsct,NODECT_HOADON* p)
{
	if(dsct == NULL)
	{
		p->pNext = NULL;
		return p;
	}
	else
	{
		dsct->pNext = AddTailCT(dsct->pNext, p);
	}
}
void NhapCT_HDNhap(NODE_HOADON *q)
{ 
	int vitri,key;
	string maVT,sl,VAT,dongia;
	int sls,dg;
	double vat;
	int y;
	int flag =1;
	int exit =0;
	int dong =0;
	int vtr;
	string mangKiemtra[MAXTK];
	int nArr =0;
	NODE_VATTU *p;
	gotoxy(12,8);
	while(exit ==0)
	{
		while(!kbhit())
		{
			key =getch();
			if(flag ==1)
			{
				vitri =12+maVT.size();
			}
			else if(flag ==2)
			{
				vitri=50+sl.size();
			}
			else if(flag ==3)
			{
				vitri = 67+dongia.size();
			}
			else if(flag ==4)
			{
				vitri =88+VAT.size();
			}
			
			y=8+dong*2;
			if(key ==0)
			{
				key =getch();
			}
			else if(key ==27)
			{
				if(veKhungYesNo("       Ban co muon thoat?",0))
				{
					if(q->data.fisrtCT == NULL)
					{
						delete q;
					}
					system("cls");
					return;
				}
				else
				{
					xoaKhungYN();
					continue;
				}
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
			{
				if(flag ==1&&maVT.size() <10)
				{
					gotoxy(vitri,y);
					if(key >=97 && key <=122)
						key = key -32;
					cout << (char)key;
					maVT.insert(maVT.end(),1,char(key));
				}
				else if(flag == 2&&(key >= 48&& key <=57) &&sl.size()<3)
				{
					gotoxy(vitri,y);
					cout << char(key);
					sl.insert(sl.end(),1,char(key));
					sls = atoi(sl.c_str());
				}
				else if(flag == 3&&(key >= 48&& key <=57)&&dongia.size()<10)
				{
					gotoxy(vitri,y);
					cout << (char)key;
					dongia.insert(dongia.end(),1,char(key));
					dg = atoi(dongia.c_str());
				}
				else if(flag == 4&&(key >= 48&& key <=57))
				{
					gotoxy(vitri,y);
					cout << (char)key;
					VAT.insert(VAT.end(),1,char(key));
					vat = atoi(VAT.c_str());
				}
			}
			else if(key == 13||key ==9)
			{
				 if(flag ==1)
				{
					if(kiemTraTrungMaVT(t,maVT) == NULL)
					{
						while(!kbhit())
						{
							Canhbao("Ma vat tu khong ton tai.Xin nhap lai!!",34,1);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(maVT.size() ==0)
					{
						while(!kbhit())
						{
							Canhbao("Chua nhap ma vat tu",40,1);
						}
						do
						{
							int key1 =getch();
						}while(key!=13||key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						bool ktrtrung = false;
						for(int j =0; j <nArr+1;j++)
						{
							if(mangKiemtra[j]==maVT)
							{
								ktrtrung = true;
								break;
							}
						}
						if(ktrtrung == true)
						{
							while(!kbhit())
								{
									Canhbao("Trong mot hoa don khong duoc nhap trung vat tu.Xin nhap lai!!",34,1);
								}
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(12+maVT.size(),y);
						}
						else
						{
							p = Search(t,maVT);
							gotoxy(27,y);
							cout << p->Data.TenVT;
							gotoxy(50,y);
							flag=2;
						}
						
					}
				}
				else if(flag ==2)
				{
					if(sl.size() == 0)
					{
						while(!kbhit())
						{
							Canhbao("Chua nhap so luong cho hoa don",40,1);
						}
						do
						{
							int key1 =getch();
						}while(key!=13||key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						gotoxy(67,y);
						flag=3;
					}
				}
				else if(flag==3)
				{
					if(dongia.size()==0)
					{
						while(!kbhit())
						{
							Canhbao("Chua nhap so luong cho hoa don",40,1);
						}
						do
						{
							int key1 =getch();
						}while(key!=13||key!=9);
						gotoxy(vitri,y);	
					}
					else
					{
						gotoxy(88,y);
						flag=4;
					}
				}
				else if(flag ==4)
				{
					int tong=0;
					if(VAT.size()==0)
					{
						vat=0;
						p->Data.SoLuongTon+=sls;
						CT_HOADON cthd;
						if(nArr < MAXTK)
						{
							mangKiemtra[nArr++] = maVT;
						}
						strcpy(cthd.MaVT,maVT.c_str());
						cthd.soluong = sls;
						cthd.dongia = dg;
						cthd.VAT =vat;
						tong+=sls*dg+(vat/100)*dg;
						q->data.fisrtCT=AddTailCT(q->data.fisrtCT,GetNodeCT(cthd));
						sl="";
						maVT="";
						dongia ="";
						VAT="";
						dong++;
						xoakhungtongtien(12+(dong-1)*2);
						veKhungTongGiaTien(12+dong*2);
						textcolor(10);
						gotoxy(55,13+dong*2);
						cout << tong << "  VND";
						textcolor(7);
						Ve1(10,8+dong*2);
						Ve2(10,8+dong*2);
					}
					else
					{
						p->Data.SoLuongTon+=sls;
						CT_HOADON cthd;
						strcpy(cthd.MaVT,maVT.c_str());
						cthd.soluong = sls;
						cthd.dongia = dg;
						cthd.VAT =vat;
						if(nArr < MAXTK)
						{
							mangKiemtra[nArr++] = maVT;
						}
						tong+=sls*dg+(vat/100)*dg;
						q->data.fisrtCT=AddTailCT(q->data.fisrtCT,GetNodeCT(cthd));
						sl="";
						maVT="";
						dongia ="";
						VAT="";
						dong++;
						xoakhungtongtien(12+(dong-1)*2);
						veKhungTongGiaTien(12+dong*2);
						textcolor(10);
						gotoxy(55,13+dong*2);
						cout << tong << "  VND";
						textcolor(7);
						Ve1(10,8+dong*2);
						Ve2(10,8+dong*2);
						gotoxy(12,8+dong*2);
						flag=1;
					}
				}
			}
			else if(key ==8)
			{
				if(flag==1 && maVT.size() >0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout <<" ";
					gotoxy(vitri,y);
					maVT.erase(maVT.end()-1);
				}
				else if(flag ==2 && sl.size() >=0)
				{
					if(sl.size()==0)
					{
						gotoxy(27,y);
						cout << "           ";
						gotoxy(12+maVT.size(),y);
						flag=1;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						sl.erase(sl.end()-1);
						sls =atoi(sl.c_str());
					}
				}
				else if(flag ==3 && dongia.size() >=0)
				{
					if(dongia.size() ==0)
					{
						gotoxy(50+sl.size(),y);
						flag=2;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						dongia.erase(dongia.end()-1);
						dg=atoi(dongia.c_str());
					}
				}
				else if(flag ==4 && VAT.size()>=0)
				{
					if(VAT.size()==0)
					{
						gotoxy(67+dongia.size(),y);
						flag=3;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						VAT.erase(VAT.end()-1);
						vat=atoi(VAT.c_str());
					}
				}
			}
		}
	}
}
int timdongianhap(string mavt);
void NhapCT_HDXuat(NODE_HOADON *q)
{ 
	int vitri,key;
	string maVT="",sl="",dongia="";
	int sls,vat,dg;
	int y;
	int flag =1;
	int exit =0;
	int dong =0;
	int vtr;
	NODE_VATTU *p;
	int gianhap;
	NODECT_HOADON *k;
	gotoxy(12,8);
	while(exit ==0)
	{
		while(!kbhit())
		{
			
			if(flag ==1)
			{
				vitri =12+maVT.size();
			}
			else if(flag ==2)
			{
				vitri=50+sl.size();
			}
			else if(flag ==3)
			{
				vitri = 67+dongia.size();
			}
			y=8+dong*2;
			key =getch();
			if(key ==0)
			{
				key =getch();
			}
			else if(key ==27)
			{
				if(veKhungYesNo("       Ban co muon thoat?",0))
				{
					if(q->data.fisrtCT == NULL)
					{
						delete q;
					}
					system("cls");
					return;
				}
				else
				{
					xoaKhungYN();
					continue;
				}
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
			{
				if(flag ==1&&maVT.size() <10)
				{
					gotoxy(vitri,y);
					if(key >=97 && key <=122)
						key = key -32;
					cout << (char)key;
					maVT.insert(maVT.end(),1,char(key));
				}
				else if(flag == 2&&(key >= 48&& key <=57))
				{
					gotoxy(vitri,y);
					cout << (char)key;
					sl.insert(sl.end(),1,char(key));
					sls = atoi(sl.c_str());
				}
				else if(flag == 3&&(key >= 48&& key <=57))
				{
					gotoxy(vitri,y);
					cout << (char)key;
					dongia.insert(dongia.end(),1,char(key));
					dg = atoi(dongia.c_str());
				}
			}
			else if(key == 13||key ==9)
			{
				 if(flag ==1)
				{
					if(kiemTraTrungMaVT(t,maVT) == NULL)
					{
						while(!kbhit())
						{
							Canhbao("Ma vat tu khong ton tai.Xin nhap lai!!",34,1);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(maVT.size() ==0)
					{
						while(!kbhit())
						{
							Canhbao("Khong duoc de trong.Xin nhap lai!!",34,1);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						// bi loi tim kiem
				//		gianhap = timdongianhap(maVT);
						p = Search(t,maVT);
						gotoxy(27,y);
						cout << p->Data.TenVT;
						gotoxy(50,y);
						flag=2;
					}
				}
				else if(flag ==2)
				{
					if(sl.size() ==0)
					{
						while(!kbhit())
						{
							Canhbao("Khong duoc de trong.Xin nhap lai!!",34,1);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(p->Data.SoLuongTon < sls)
					{
						while(!kbhit())
						{
							Canhbao("So luong trong kho khong du de xuat < "+to_String(p->Data.SoLuongTon)+" >",34,1);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						gotoxy(67,y);
						flag=3;
					}
				}
				else if(flag==3)
				{   
					if(dongia.size()==0)
					{
						while(!kbhit())
						{
							Canhbao("Chua nhap so luong cho hoa don",40,1);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);	
					}
					
//					else if(gianhap > dg)
//					{
//						while(!kbhit())
//						{
//							Canhbao("Gia xuat phai lon hon gia nhap < "+to_String(gianhap)+" >",40,1);
//						}
//						do{
//							int key1 = getch();
//						}while(key!=13&&key!=9);
//						gotoxy(vitri,y);
//					}
					else
					{
						int tong =0;
						vat =k->Data.VAT;
						gotoxy(90,y);
						cout << vat;
						p->Data.SoLuongTon-=sls;
						CT_HOADON cthd;
						strcpy(cthd.MaVT,maVT.c_str());
						cthd.soluong = sls;
						cthd.dongia = dg;
						cthd.VAT =vat;
						tong+=sls*dg+(vat/100)*dg;
						q->data.fisrtCT=AddTailCT(q->data.fisrtCT,GetNodeCT(cthd));
						sl="";
						maVT="";
						dongia ="";
						dong++;
						xoakhungtongtien(12+(dong-1)*2);
						veKhungTongGiaTien(12+dong*2);
						textcolor(10);
						gotoxy(55,13+dong*2);
						cout << tong << "  VND";
						textcolor(7);
						Ve1(10,8+dong*2);
						Ve2(10,8+dong*2);
						gotoxy(12,8+dong*2);
						flag=1;
					}
				}
				
			}
			else if(key ==8)
			{
				if(flag==1 && maVT.size() >0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout <<" ";
					gotoxy(vitri,y);
					maVT.erase(maVT.end()-1);
				}
				else if(flag ==2 && sl.size() >=0)
				{
					if(sl.size()==0)
					{
						gotoxy(12+maVT.size(),y);
						flag=1;
						gotoxy(27,y);
						cout << "           ";
						
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						sl.erase(sl.end()-1);
						sls =atoi(sl.c_str());
					}
				}
				else if(flag ==3 && dongia.size() >=0)
				{
					if(dongia.size()==0)
					{
						gotoxy(50+sl.size(),y);
						flag=2;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						dongia.erase(dongia.end()-1);
						dg=atoi(dongia.c_str());
					}
				}
			}
		}
	}
}
void xuatCT_HD(CT_HOADON data,int stt)
{
	gotoxy(20,3+yMap +stt*2);
	cout << data.MaVT;
	gotoxy(36+((21-to_String(data.soluong).size())/2),3+yMap +stt*2);
	cout << data.soluong;
	gotoxy(57+((26-to_String(data.dongia).size())/2),3+yMap +stt*2);
	cout << data.dongia;
	gotoxy(74+((26-to_String(data.VAT).size())/2),3+yMap +stt*2);
	cout << data.VAT;
}
								// KET THUC CHI TIET HOA DON
								// BAT DAU HOA DON
NODE_HOADON * pHead =NULL;NODE_HOADON *pTail=NULL;
NODE_HOADON* Getnode(HOADON data)
{
	NODE_HOADON* p = new NODE_HOADON;
	if(p==NULL)
		return NULL;
	p->data = data;
	p->pNext = NULL;
   
	return p;
}
void AddTailHD(NODE_HOADON* p)
{
	if(pHead ==NULL)
		pHead=pTail=p;
	else
	{
		pTail->pNext = p;
		pTail = p;
		p->pNext = NULL;
	}
}
NODE_HOADON *ThemDSHDNV(NODE_HOADON *dshd,NODE_HOADON *p)
{
	if(dshd == NULL)
	{
		p->pNext = NULL;
		return p;
	}
	else
		dshd->pNext = ThemDSHDNV(dshd->pNext, p);
}
NODE_HOADON* SearchHD(string soHD)
{
	NODE_HOADON *q;
	for(int i = 0; i < dsnv.soLuongNV+1; i++)
	{
		NODE_HOADON *p = dsnv.nv[i].fisrtHD;
		while(p != NULL)
		{
			if(strcmp(p->data.SoHD, soHD.c_str()) == 0)
			{
				q = p;
				return q;
			}
			p = p->pNext;
		}
	}
	return NULL;
}
void nhapNgayHD(Date &date,int &exit)
{
	string sngay=to_String(date.ngay) ;
	string sthang=to_String(date.thang);
	string snam =to_String(date.nam);
	int key, check =0,vitri;
	int flag =3;
	int y =3;
	while(check ==0)
	{
		while(!kbhit())
		{
			key = getch();
			if(flag==1)
			{
				vitri = 47+sngay.length();
			}
			else if(flag==2)
			{
				vitri = 56+sthang.length();
			}
			else if(flag==3)
			{
				vitri = 63+snam.length();
			}
			if(key ==27)
			{
				check=2;
				exit =1;
				break;
			}
			else if(key >= 48 && key <=57)
			{
				if(flag ==1 && sngay.length() <2)
				{
					gotoxy(vitri,y);
					cout << char(key);
					sngay.insert(sngay.end(),1,char(key));
					date.ngay = atoi(sngay.c_str());
				}
				else if(flag ==2&&sthang.length() <2)
				{
					gotoxy(vitri,y);
					cout << char(key);
					sthang.insert(sthang.end(),1,char(key));
					date.thang = atoi(sthang.c_str());
				}
				else if(flag ==3 &&snam.length() <4)
				{
					gotoxy(vitri,y);
					cout << char(key);
					snam.insert(snam.end(),1,char(key));
					date.nam = atoi(snam.c_str());
				}
			}
			else if(key ==13 || key ==9)
			{
				if(flag ==1)
				{
					if(date.ngay < 0 || date.ngay > 31)
					{
						while(!kbhit())
						 Canhbao("Nhap sai ngay.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
						
					}
					else if(date.ngay ==0)
					{
						
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else{
						
						gotoxy(56+sthang.length(),y);
						flag =2;
					}
				}
				else if(flag ==2)
				{
					if(date.thang < 0 || date.thang >12)
					{
						
						while(!kbhit())
						 Canhbao("Nhap sai thang.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(date.thang == 0)
					{
						
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						
						if(date.thang ==2)
						{
							if(date.ngay >28 )
							{
								while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",30,1);
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(47+sngay.length(),y);
								flag =1;
							}
							else
							{
								gotoxy(63+snam.length(),y);
								flag =3;
							}
						}
						else if(date.thang ==4 || date.thang ==6 || date.thang ==9 || date.thang ==11)
						{
							if(date.ngay >30)
							{
								while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",30,1);
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(47+sngay.length(),y);
								flag =1;
							}
							else
							{
								gotoxy(56,y);
								flag =3;
							}
						}
						else 
						{
							gotoxy(63+snam.length(),y);
							flag =3;
						}
						
					}
				}
				else if(flag ==3)
				{
					if(date.nam == 0)
					{
						
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						
						if(date.nam%4==0)
						{
							if(date.thang ==2)
							{
								if(date.ngay >29)
								{
									while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",30,1);
									do{
										int key1 = getch();
									}while(key!=13&&key!=9);
									gotoxy(47+sngay.length(),y);
									flag =1;
								}
								else
								{
									check =1;
									break;
								}
							}
							else
							{
								check =1;
								break;
							}
						}
						else
						{
							check =1;
							break;
						}
						
					}
				}
			}
			else if(key == 8)
			{
				if(flag ==1 && sngay.size() >0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout <<" ";
					gotoxy(vitri,y);
					sngay.erase(sngay.end()-1);
					date.ngay = atoi(sngay.c_str());
				}
				else if(flag ==2 && sthang.size() >=0)
				{
					if(vitri ==vitri-sthang.size())
					{
						gotoxy(47+sngay.size(),y);
						flag =1;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						sthang.erase(sthang.end()-1);
						date.thang = atoi(sthang.c_str());
					}
					
				}
				else if(flag == 3&& snam.size() >=0)
				{
					if(vitri ==vitri-snam.size())
					{				
						gotoxy(56+sthang.size(),y);
						flag =2;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						snam.erase(snam.size()-1);
						date.nam = atoi(snam.c_str());
					}
				}
			}
		}
	}
	if(check ==1) return;
}
int timdongianhap(string mavt)
{
	Date arr[MAXTK];
	int nArr=0;
	for(int j =0;j<dsnv.soLuongNV +1;j++)
	{
		NODE_HOADON *l = dsnv.nv[j].fisrtHD;
		while(l!=NULL)
		{
			if(l->data.loai =='N')
			{
				for(NODECT_HOADON *k = l->data.fisrtCT;k!=NULL;k=k->pNext)
				{
					if(strcmp(k->Data.MaVT,mavt.c_str())==0)
					{
						arr[nArr++] = l->data.date;
					}
				}
			}
			l =l->pNext;
		}
	}
	int maxNam = arr[0].nam;
	int maxThang = arr[0].thang;
	int maxNgay = arr[0].ngay;
	int tam1,tam2,tam3;;
	for(int i =1;i <=nArr;i++)
	{
		if(maxNam < arr[i].nam)
		{
			tam1 = maxNam ;
			tam2 = maxThang;
			tam3 = maxNgay;
			maxNam = arr[i].nam;
			maxNgay = arr[i].ngay;
			maxThang = arr[i].thang;
		}
		if(tam1 == maxNam)
		{
			if(tam2 > maxThang)
			{
				maxNam =tam1;
				maxThang =tam2;
				maxNgay =tam3;
			}
			else if( tam2 == maxThang)
			{
				if(tam3 > maxNgay)
				{
					maxNam =tam1;
					maxNgay =tam3;
					maxThang = tam2;
				}
			}
		}
	}
	for(int i =0;i<dsnv.soLuongNV +1;i++)
	{
		NODE_HOADON *p = dsnv.nv[i].fisrtHD;
		while(p!=NULL)
		{
			if(p->data.loai =='N')
			{
				for(NODECT_HOADON *q = p->data.fisrtCT;q!=NULL;p=p->pNext)
				{
					if(strcmp(q->Data.MaVT,mavt.c_str())==0)
					{
						return q->Data.dongia;
					}
				}
			}
			p =p->pNext;
		}
	}
}
void nhapHoaDon(int tinhieu)
{
	system("cls");
	textcolor(10);
	gotoxy(44, 2);
	if(tinhieu ==0)
	{
		cout << "HOA DON NHAP VAT TU";
	}
	else
	{
		cout << "HOA DON XUAT VAT TU";
	}
	textcolor(7);
	gotoxy(60, 4);
	cout << "So Hoa Don: ";
	gotoxy(26,4);
	cout << "Ma Nhan Vien: ";
	textcolor(7);
	HOADON hd;
	int vtr;
	ve1();
	Ve1(10,8);
	Ve2(10,8);
	Date date;
	layNgayThangHienTai(date.ngay, date.thang,date.nam);
	string MSHD, MaNV;
	int key,flag=1;
	bool loop =0;
	gotoxy(42, 3);
	cout << "Ngay   "<< " Thang   "<< " Nam     ";
	
	gotoxy(47,3);
	cout << date.ngay;
	gotoxy(56,3);
	cout << date.thang;
	gotoxy(63,3);
	cout << date.nam;
Nhaplaingay:
	int exit =0;
	nhapNgayHD(date,exit);
	if(exit ==1)
	{
		system("cls");
		return;
	}
	gotoxy(40,4);
		while(loop==0)
		{
			while(!kbhit())
			{
				int vitri;
				key = getch();
				if(flag==1) vitri =40+MaNV.length();
				else if(flag == 2) vitri = 72 +MSHD.length();
				if(key == 0)
				{
					key = getch();
				}
				else if(key  == 27)
				{
					if(veKhungYesNo("       Ban co muon thoat?",0))
					{
						system("cls");
						return;
					}
					else
					{
						xoaKhungYN();
						continue;
					}
				}
				if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
				{
					if(flag == 1 && MaNV.size()<10)
					{
						gotoxy(vitri,4);
						if(key >=97 && key <=122)
							key = key -32;
						cout << (char)key;
						MaNV.insert(MaNV.end(),1,(char)key);
					}
					else if(flag ==2 && MSHD.size() < 20)
					{
						gotoxy(vitri,4);
						if(key >=97 && key <=122)
							key = key -32;
						cout << (char)key;
						MSHD.insert(MSHD.end(),1,(char)key);
						
					}	
				}
				else if(key ==13 || key ==9)
				{
					if(flag==1)
					{
						if(MaNV.size() ==0)
						{
							while(!kbhit())
							{
								Canhbao("Khong duoc de trong!.Xin nhap lai!!",30,1);
							}
							do{
								int key1 = getch();
							}while(key!=13&&key!=9);
							gotoxy(vitri,8);
						}
						else if(kiemTraTrungMNV(MaNV)==true)
						{
							while(!kbhit())
								{
									Canhbao("Ma "+MaNV+" Khong ton tai!.Xin nhap lai!!",30,1);
								}
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(vitri,4);
						}
						else
						{
							gotoxy(72,4);
							flag =2;
						}
						
					}
					else if(flag == 2)
					{
						if(MSHD.length() <20)
						{
							while(!kbhit())
							{
								Canhbao("So hop dong phai la 20 ki tu!.Xin nhap lai!!",30,1);
							}
							do{
								int key1 = getch();
							}while(key!=13&&key!=9);
							gotoxy(vitri,4);
						}
						else if(SearchHD(MSHD) != NULL)
						{
							while(!kbhit())
							{
								Canhbao("So hop dong "+MSHD+" da ton tai!.Xin nhap lai!!",30,1);
							}
							do{
								int key1 = getch();
							}while(key!=13&&key!=9);
							gotoxy(vitri,4);						
						}
						
						else
						{
							strcpy(hd.SoHD,MSHD.c_str());
							if(tinhieu ==0)
							{
								hd.loai='N';
							}
							else
							{
								hd.loai='X';
							}
							hd.fisrtCT=NULL;
							hd.date = date;
							for(int i =1;i<dsnv.soLuongNV+1;i++)
							{
								if(strcmp(dsnv.nv[i].MaNV,MaNV.c_str())==0)
								{
									vtr =i;
									break;
								}
							}
							loop =1;
							break;
						}	
						}
					}
				else if(key == 8)
				{
						if(flag == 1&& MaNV.size() >0)
						{
							vitri--;
							gotoxy(vitri,4);
							cout << " ";
							gotoxy(vitri,4);
							MaNV.erase(MaNV.end()-1);
						}
						else if(flag == 2&&MSHD.size()>0)
						{
							vitri--;
							gotoxy(vitri,4);
							cout << " ";
							gotoxy(vitri,4);
							MSHD.erase(MSHD.end()-1);
						}		
				}
			}
	}
	dsnv.nv[vtr].fisrtHD=ThemDSHDNV(dsnv.nv[vtr].fisrtHD,Getnode(hd));
	if(tinhieu ==0)
	{
		NhapCT_HDNhap(dsnv.nv[vtr].fisrtHD);
	}
	else
	{
		NhapCT_HDXuat(dsnv.nv[vtr].fisrtHD);
	}
}
	
void ThemHoaDon(int tinhieu)
{
	if(dsnv.soLuongNV == 0)
	{
		veKhungTB("       Khong co nhan vien");
		system("cls");
		return;
	}
	if(t == NULL)
	{
		veKhungTB("         Khong co vat tu");
		system("cls");
		return;
	}
	system("cls");
	nhapHoaDon(tinhieu);
	
}
// xUat thong tin hoa don theo so hoa don nhap vao
int kiemtraTonTaiHD()
{
	for(int i = 0; i < dsnv.soLuongNV+1; i++)
	{
		if(dsnv.nv[i].fisrtHD != NULL)
		{
			return 1;
		}
	}
	return 0;
}
void XuatthongTinHoaDon()
{
	string SoHD;
	string arrTukhoa[]={"So HD","Ngay Lap","Loai"};
	int key,vitri,check =0,stt=0;
	if(kiemtraTonTaiHD()== 0)
	{
		veKhungTB("         Khong co hoa don");
		system("cls");
		return;
	}
		system("cls");
		gotoxy(36,3);
		cout <<"So Hoa Don: ";
		int y =3;
		NODE_HOADON *q;
		gotoxy(48,y);
		while(check ==0)
		{
			while(!kbhit())
			{
				vitri = 48+SoHD.length();
				key =getch();
				if(key ==27)
				{
					system("cls");
					return;
				}
				else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
				{
					if(SoHD.length()  <20)
					{
						gotoxy(vitri,y);
						if(key >=97 && key <=122)
							key = key -32;
						cout << (char)key;
						SoHD.insert(SoHD.end(),1,(char)key);
				   }
				}
				else if(key == 13 || key ==9)
				{
					if(SearchHD(SoHD)==NULL)
					{
						while(!kbhit())
							Canhbao("Khong tim thay so hoa don"+SoHD+".Xin kiem tra lai!!",30,1);
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						q=SearchHD(SoHD);
						gotoxy(36,3);
						cout <<"                                                          ";
						gotoxy(20,3);
						cout<<"So Hoa Don: ";
						gotoxy(32,3);
						cout << q->data.SoHD;
						gotoxy(56,3);
						cout << "Ngay Lap: ";
						gotoxy(66,3);
						cout << q->data.date.ngay << " / " << q->data.date.thang << " / " << q->data.date.nam;
						gotoxy(82,3);
						cout << "Loai: ";
						gotoxy(88,3);
						if(q->data.loai ='N')
						{
							cout << "Nhap";
						}
						else
						{
							cout << "Xuat";
						}
						NODECT_HOADON *p;
						string arr[] ={"Ma Vat Tu","So Luong","Don Gia","%VAT"};
						veBangChiTiet(arr,4);
						for(p = q->data.fisrtCT;p!=NULL;p=p->pNext)
						{
							xuatCT_HD(p->Data,stt);
							stt++;
						}
					}
				}
				else if(key == 8 && SoHD.length() >0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout << " ";
					gotoxy(vitri,y);
					SoHD.erase(SoHD.end()-1);
				}
			}
		}
}								// THONG KE HOA DON
void xuatThongKe(THONGKE tk, int stt)
{
	int y =9+stt;
	gotoxy(arrToaDoBangThongKeHD[0]+1,y);
	cout << tk.SoHD;
	gotoxy(arrToaDoBangThongKeHD[1]+1,y);
	cout << tk.date.ngay << "/"<<tk.date.thang << "/" <<tk.date.nam;
	gotoxy(arrToaDoBangThongKeHD[2]+1,y);
	cout << tk.Loai;
	gotoxy(arrToaDoBangThongKeHD[3]+1,y);
	cout << tk.HoTenNV;
	gotoxy(arrToaDoBangThongKeHD[4]+1,y);
	cout << tk.donGia;
}
void xuatDSTK(DS_THONGKE &l, int page)
{
	Nocursortype();
	veBangThongKeHD();
	int stt=0;
	for(int i =page*1;i < (l.soTK >(page+1)*14 ? 14 : l.soTK-page*14);i++)
	{
		xuatThongKe(l.tk[i],stt++);
	}
}
void xulyDSTK(NHANVIEN nv, Date first, Date final)
{
	int checkDate1,checkDate2;
	int donGia =0,kq;
	for(NODE_HOADON* p = nv.fisrtHD; p!= NULL; p= p->pNext)
	{
		string name ="";
		checkDate1 = soSanhNgay(p->data.date,first);
		checkDate1 = soSanhNgay(p->data.date,final);
		if((checkDate1 ==1|| checkDate1 ==0) && (checkDate2 == -1|| checkDate2 == 0) )
		{
			name +=nv.Ho;
			name+=" ";
			name+=nv.Ten;
			strcpy(dstk.tk[dstk.soTK].SoHD, p->data.SoHD);
			dstk.tk[dstk.soTK].date = p->data.date;
			dstk.tk[dstk.soTK].Loai=p->data.loai;
			dstk.tk[dstk.soTK].HoTenNV = name;
			for(NODECT_HOADON* q =p->data.fisrtCT; q!=NULL; q=q->pNext)
			{
				kq = q->Data.soluong*q->Data.dongia+(q->Data.VAT/100)*q->Data.dongia;
				donGia +=kq;
			}
			dstk.tk[dstk.soTK++].donGia = donGia;
		}
	}
}
void nhapNgay(Date &first, Date &final,int exit)
{
	int xMapNgay =43,xMapThang =48,xMapNam=53;
	int xMapNgay2 = 77,xMapThang2=83,xMapNam2=88;
	
nhaplai:
	int flag =1;
	int check =0;
	int y=3;
	int vitri;
	int key,lengh,kq;
	string sngay,sthang,snam,sngay2,sthang2,snam2;
	gotoxy(43,y);
	while(check == 0)
	{
		
		while(!kbhit())
		{
			if(flag ==1){
				vitri =xMapNgay+ sngay.length();
			}
			else if(flag ==2)
			{
				vitri =xMapThang+sthang.length();
			}
			else if(flag ==3)
			{
				vitri=xMapNam+snam.length();
			}
			if(flag ==4){
				vitri =xMapNgay2+ sngay2.length();
			}
			else if(flag ==5)
			{
				vitri =xMapThang2+sthang2.length();
			}
			else if(flag ==6)
			{
				vitri=xMapNam2+snam2.length();
			}
			key = getch();
			if(key == 27)
			{
				exit =1;
				check =1;
				break;
			}
			else if(key >= 48 && key <= 57)
			{
				if(flag ==1 && sngay.length() <2)
				{
					gotoxy(vitri,y);
					cout << char(key);
					sngay.insert(sngay.end(),1,char(key));
					first.ngay = atoi(sngay.c_str());
				}
				else if(flag == 2&& sthang.length() <2)
				{
					gotoxy(vitri,y);
					cout << char(key);
					sthang.insert(sthang.end(),1,char(key));
					first.thang = atoi(sthang.c_str());
				}
				else if(flag ==3 && snam.length() <4)
				{
						gotoxy(vitri,y);
					cout << char(key);
					snam.insert(snam.end(),1,char(key));
					first.nam = atoi(snam.c_str());
				}
				else if(flag ==4&&sngay2.length() <2)
				{
					gotoxy(vitri,y);
					cout << char(key);
					sngay2.insert(sngay2.end(),1,char(key));
					final.ngay = atoi(sngay2.c_str());
				}
				else if(flag == 5&&sthang2.length() <2)
				{
						gotoxy(vitri,y);
					cout << char(key);
					sthang2.insert(sthang2.end(),1,char(key));
					final.thang = atoi(sthang2.c_str());
				}
				else if(flag ==6&&snam2.length() <4)
				{
					gotoxy(vitri,y);
					cout << char(key);
					snam2.insert(snam2.end(),1,char(key));
					final.nam = atoi(snam2.c_str());
				}
			}
			else if(key == 13 || key ==9)
			{
				if(flag ==1)
				{
					if(first.ngay < 0 || first.ngay > 31)
					{
						while(!kbhit())
						 Canhbao("Nhap sai ngay.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
						
					}
					else if(first.ngay ==0)
					{
						
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else{
						gotoxy(xMapThang,y);
						flag =2;
					}
				}
				else if(flag ==2)
				{
					if(first.thang == 0)
					{
						
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(first.thang < 0 || first.thang >12)
					{
						
						while(!kbhit())
						 Canhbao("Nhap sai thang.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					
					else
					{
						
						if(first.thang ==2)
						{
							if(first.ngay >28 )
							{
								while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",30,1);
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(xMapNgay+sngay.length(),y);
								flag =1;
							}
							else
							{
								gotoxy(xMapNam,y);
								flag =3;
							}
						}
						else if(first.thang ==4 || first.thang ==6 || first.thang ==9 || first.thang ==11)
						{
							if(first.ngay >30)
							{
								while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",30,1);
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(xMapNgay+sngay.length(),y);
								flag =1;
							}
							else
							{
								gotoxy(xMapNam,y);
								flag =3;
							}
						}
						else 
						{
							gotoxy(xMapNam,y);
							flag =3;
						}
						
					}
				}
				else if(flag ==3)
				{
					if(first.nam < 2000 || first.nam > layNamHienTai())
					{
						
						while(!kbhit())
						 Canhbao("Nhap sai nam, nam phai be hon "+to_String(layNamHienTai())+".Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						
						if(first.nam%4==0)
						{
							if(first.thang ==2)
							{
								if(first.ngay >29)
								{
									while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",30,1);
									do{
										int key1 = getch();
									}while(key!=13&&key!=9);
									gotoxy(xMapNgay+sngay.length(),y);
									flag =1;
								}
								else
								{
									gotoxy(xMapNgay2,y);
									flag =4;
								}
							}
							else
							{
								gotoxy(xMapNgay2,y);
								flag =4;
							}
						}
						else
						{
							gotoxy(xMapNgay2,y);
							flag =4;
						}
						
					}
				}
				else if(flag ==6)
				{
						
					if(final.nam == 0)
					{
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(final.nam < first.nam || final.nam > layNamHienTai())
					{
						while(!kbhit())
						 Canhbao("Nhap sai nam,nam phai be hon "+to_String(layNamHienTai())+".Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						check =1;
						break;
					}
				}
				else if(flag ==4)
				{
					if(final.ngay == 0)
					{
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(final.ngay < 0 || final.ngay >31)
					{
						while(!kbhit())
						 Canhbao("Nhap sai ngay.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
						
					}
					 
					else{
						gotoxy(xMapThang2,y);
						flag =5;
					}
				}
				else if(flag =5)
				{
					 if(final.thang ==0)
					{
						
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(final.thang <0 || final.thang >12)
					{
						while(!kbhit())
						 Canhbao("Nhap sai thang.Xin nhap lai!",30,1);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					
					else
					{
						if(final.thang == 2)
						{
							if(final.ngay >28 )
							{
								while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",30,1);
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(xMapNgay2+sngay2.length(),y);
								flag =4;
							}
							else
							{
								gotoxy(xMapNam2,y);
								flag =6;
							}
						}
						else if(final.thang ==4 || final.thang ==6 || final.thang ==9 || final.thang ==11)
						{
							if(final.ngay >30)
							{
								while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",30,1);
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(xMapNgay2+sngay2.length(),y);
								flag =4;
							}
							else
							{
								gotoxy(xMapNam2,y);
								flag =6;
							}
						}
						else
						{
							gotoxy(xMapNam2,y);
							flag =6;
						}
					}
				}
			}
			else if(key == 8)
			{
				if(flag ==1 && sngay.size() >0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout <<" ";
					gotoxy(vitri,y);
					sngay.erase(sngay.end()-1);
					first.ngay = atoi(sngay.c_str());
				}
				else if(flag ==2 && sthang.size() >0)
				{
					if(sthang.size() == 0)
					{
						gotoxy(43+sngay.size(),y);
						flag=1;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						sthang.erase(sthang.end()-1);
						first.thang = atoi(sthang.c_str());
					}
					
				}
				else if(flag == 3&& snam.size() >0)
				{
					if(snam.size()==0)
					{
						gotoxy(48+sthang.size(),y);
						flag =2;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						snam.erase(snam.size()-1);
						first.nam = atoi(snam.c_str());
					}
					
				}
				if(flag ==4 && sngay2.size() >0)
				{
					if(sngay2.size() ==0)
					{
						gotoxy(53+snam.size(),y);
						flag =3;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						sngay2.erase(sngay2.end()-1);
						final.ngay = atoi(sngay2.c_str());
					}
				
				}
				else if(flag ==5 && sthang2.size() >0)
				{
					if(sthang2.size() ==0)
					{
						gotoxy(76+sngay2.size(),y);
						flag =4;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						sthang2.erase(sthang2.end()-1);
						final.thang = atoi(sthang2.c_str());
					}
					
				}
				else if(flag == 6&& snam2.size() >0)
				{
					if(snam2.size() ==0)
					{
						gotoxy(82+sthang2.size(),y);
						flag =5;
					}
					else
					{
						vitri--;
						gotoxy(vitri,y);
						cout <<" ";
						gotoxy(vitri,y);
						snam2.erase(snam2.size()-1);
						final.nam = atoi(snam2.c_str());
					}
					
				}
			}
		
		}
	}
}
void thongKeHD()
{
	dstk.soTK =0;
	Date first, final;
	int page =0, key, dem = dstk.soTK;
	string name = "BANG LIET KE HOA DON TRONG KHOANG THOI GIAN";
	string name2 = "TU NGAY :    /    /     \t DEN NGAY :    /    /     ";
	
	if(kiemtraTonTaiHD()== 0)
	{
		veKhungTB("         Khong co hoa don");
		system("cls");
		return;
	}
	system("cls");
	textcolor(10);
		gotoxy(40, 2);
		cout << name;
		gotoxy(33, 3);
		textcolor(7);
		cout << name2;
		int exit =0;
		nhapNgay(first,final,exit);
		if(exit ==1)
		{
			system("cls");
			return;
		}
		for(int i = 1; i <dsnv.soLuongNV+1;i++)
		{
			xulyDSTK(dsnv.nv[i],first,final);
		}
		while(true)
		{
			xuatDSTK(dstk,page);
			while(!kbhit())
			{
				key = getch();
				if(key == 224)
				{
					key = getch();
					if(key == 81 && page >0)
					{
						page--;
						break;
					}
					else if(key ==73 && page <(dem % 12 ==0 ?(dem / 12) : (dem / 12) + 1) - 1)
					{
						page++;
						break;
					}
				
				}
				else if(key == 27)
				{
					system("cls");
					return;
				}
		 } 
	}
	
}
									// KET THUC
									// MENU
void MenuVT()
{
	system("cls");
	string arrVT[6] ={"         Nhap vat tu         ","        Tim kiem vat tu      ","      Hieu chinh vat tu      ","          Xoa Vat tu         ","    10 VT co tan suat cao    ","    Danh sach VT trong kho   "};
	vemenu(arrMenuVT,arrVT,6);
	int vitri=0;
	int key;
	while(true)
	{
			Nocursortype();
			hcn(yMapMN,arrMenuVT[vitri],arrVT[vitri],true);
			key = getch();
			if(key ==224)
			{
				key = getch();
				if(key == 80)
				{
					hcn(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
					vitri++;
					if(vitri==6)
					{
						vitri=0;
					}
				}
				else if(key == 72 && vitri >0)
				{
					hcn(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
					vitri--;
				}
			}
			else if(key == 0)
			{
				key =getch();
			}
			else if(key == 13)
			{
				hcn(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
				Yescursortype();
				switch(vitri)
				{
					case 0:
						nhapVatTu();
						break;
					case 1:
						timKiemVT();
						break;
					case 2:
						hieuChinhVatTu();
						break;
					case 3:
						xoaVatTu();
						break;
					case 4:
						
						break;
					case 5:
						quanLysangTrangVT();
						break;
				}
				vemenu(arrMenuVT,arrVT,6);
			}
			else if(key == 27)
			{
				system("cls");
				return;
			}
		}
}
void MenuNV()
{
//	docNhanVien();
	system("cls");
	string arrVT[5] ={"        Nhap nhan vien       ","    In danh sach nhan vien   ","       Tim kiem nhan vien    ","         Xoa nhan vien       ","         Save nhan vien      "};
	vemenu(arrMenuVT,arrVT,5);
	int vitri=0;
	int key;
	while(true)
	{

			Nocursortype();
			hcn(yMapMN,arrMenuVT[vitri],arrVT[vitri],true);
			key = getch();
			if(key ==224)
			{
				key = getch();
				if(key == 80)
				{
					hcn(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
					vitri++;
					if(vitri==5)
					{
						vitri=0;
					}
				}
				else if(key == 72 && vitri >0)
				{
					hcn(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
					vitri--;
				}
			}
			else if(key == 0)
			{
				key =getch();
			}
			else if(key == 13)
			{
				hcn(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
				Yescursortype();
				switch(vitri)
				{
					case 0:
						nhapNhanVien();
						break;
					case 1:
						quanLyXuatNV();
						break;
					case 2:
						TimKiemNV();
						break;
					case 3:
						XoaNhanVien();
						break;
					case 4:
						ghiNhanVien();
						break;
				}
				vemenu(arrMenuVT,arrVT,5);
			}
			else if(key == 27)
			{
				system("cls");
				return;
			}
		}

}
void menuHD()
{
	system("cls");
	string arrNameHD[6] ={"       Lap Hoa Don Nhap      ","       Lap Hoa Don Xuat      ","     In Hoa Don Theo SoHD    ","       Thong Ke Hoa Don      ","        Save Hoa Don         "};
	vemenu(arrMenuVT,arrNameHD,5);
	int vitri=0;
	int key;
	while(true)
	{
			Nocursortype();
			hcn(yMapMN,arrMenuVT[vitri],arrNameHD[vitri],true);
			key = getch();
			if(key ==224)
			{
				key = getch();
				if(key == 80)
				{
					hcn(yMapMN,arrMenuVT[vitri],arrNameHD[vitri]);
					vitri++;
					if(vitri==5)
					{
						vitri=0;
					}
				}
				else if(key == 72 && vitri >0)
				{	
					
					hcn(yMapMN,arrMenuVT[vitri],arrNameHD[vitri]);
					vitri--;
				}
			}
			else if(key == 0)
			{
				key =getch();
			}
			else if(key == 13)
			{
				hcn(yMapMN,arrMenuVT[vitri],arrNameHD[vitri]);
				Yescursortype();
				switch(vitri)
				{
					case 0:
						ThemHoaDon(0);
						break;
					case 1:
						ThemHoaDon(1);
						break;
					case 2:
						XuatthongTinHoaDon();
						break;
					case 3:
						thongKeHD();
						break;
					case 4:
						break;	
				}
				vemenu(arrMenuVT,arrNameHD,5);
			}
			else if(key == 27)
			{
				system("cls");
				return;
			}
		}
}
void MenuChinh()
{ 
	system("cls");
	string arrTuKhoa[4] = { "            Vat Tu           " ,"           Nhan vien         ","            Hoa don          ","     Luu toan bo du lieu     "};
	vemenu(arrMenuVT,arrTuKhoa,4);
	int vitri =0;
	int key;
	int check =0;
	while(check ==0)
	{
			Nocursortype();
			hcn(yMapMN,arrMenuVT[vitri],arrTuKhoa[vitri],true);
			key = getch();
			if(key ==224)
			{
				key = getch();
				if(key == 80)
				{
					hcn(yMapMN,arrMenuVT[vitri],arrTuKhoa[vitri]);
					vitri++;
					if(vitri==4)
					{
						vitri=0;
					}
				}
				else if(key == 72&& vitri >0)
				{
					hcn(yMapMN,arrMenuVT[vitri],arrTuKhoa[vitri]);
					vitri--;
					
				}
			}
			else if(key == 0)
			{
				key =getch();
			}
			else if(key == 13)
			{
				hcn(yMapMN,arrMenuVT[vitri],arrTuKhoa[vitri]);
				Yescursortype();
				switch(vitri)
				{
					case 0:
						MenuVT();
						break;
					case 1:
						MenuNV();
						break;
					case 2:
						menuHD();
						break;
					case 3:
						break;
				}
				vemenu(arrMenuVT,arrTuKhoa,4);
			}
			else if(key == 27)
			{
				if(veKhungYesNo("       Ban co muon thoat?",0))
				{
					system("cls");
					return;
				}
				else
				{
					system("cls");
					vemenu(arrMenuVT,arrTuKhoa,4);
					continue;
				}
			}
		}
}


									// KET THUC
int main(){
	resizeConsole(800,700);
	InitVT(t);
	MenuChinh();
	getch();
}
