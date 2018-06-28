#include<iostream>
#include "mylib.h"
#include <cstring>
#include <fstream>
#include <ctime>
#include <cmath>
#include <ctype.h>
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include<windows.h>
#include <sstream>
#include <iomanip>
#include <queue>
#define MAXNV 500
#define MAXTK 100
#define RH 1
#define EH 0
#define LH -1

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
	char Phai[4];
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
	char CSCB;
};
typedef NODE_VATTU* Tree;
Tree t;
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
int setMauTiTle =10;
int setMauWarning =14;
int yMap = 3; // vi tri cho cac thanh phan trong bang thong ke va bang chi tiet
int xMap = 20;
void XoaKhungtongtien(int y)
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
void veKhungKhuyet1(int x, int y)
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
void veKhungKhuyet2(int x, int y)
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

void veKhungHCN(int x, int y,string name, bool choose = false)
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
}
// ham in button menu
int arrMenuVT[8] ={7,11,15,19,23,27,31};
int yMapMN = 40;
void veMenu(int *arr, string *arrTuKhoa, int n) //n: so chuc nang can show ra man hinh
{

	for (int i = 0; i < n; i++)
	{
		veKhungHCN(yMapMN, arr[i], arrTuKhoa[i]);
	}
}
int ytk = 0;
int arrToaDoBangThongKeHD[6] ={ 2,24,44,54,81,105};
void veKhungThongKeHD(string *arrTuKhoa)
{
	for (int i = 0; i < 5; i++)
	{
		gotoxy(arrToaDoBangThongKeHD[i] + 1 + ((arrToaDoBangThongKeHD[i + 1] - arrToaDoBangThongKeHD[i] - arrTuKhoa[i].length()) / 2), ytk + 7);
		textcolor(10);
		cout << arrTuKhoa[i];
		textcolor(7);

	}
	for (int j = ytk + 6; j <= 36; j++)
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
		gotoxy(i, ytk + 6);
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
		gotoxy(i, ytk + 8);
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
		gotoxy(i, ytk + 36);
		if (i == arrToaDoBangThongKeHD[1] || i == arrToaDoBangThongKeHD[2] || i == arrToaDoBangThongKeHD[3] || i == arrToaDoBangThongKeHD[4])
			cout << char(193);
		if (i == arrToaDoBangThongKeHD[0])
			cout << char(195);
		else if (i == arrToaDoBangThongKeHD[5])
		{
			cout << char(180);
		}
		else
		{
			cout << char(196);
		}
		gotoxy(i, ytk+ 38);

		if (i == arrToaDoBangThongKeHD[0])
		{
			cout << (char)192;
		}
		else if (i == arrToaDoBangThongKeHD[5])
		{
			cout << (char)217;
		}
		else
		{
			cout << (char)196;
		}
		gotoxy(arrToaDoBangThongKeHD[0], 37);
		cout << char(179);
		gotoxy(arrToaDoBangThongKeHD[5], 37);
		cout << char(179);
		gotoxy(arrToaDoBangThongKeHD[0] + 2, ytk + 37);
		cout << "<--Truoc ";
		gotoxy(arrToaDoBangThongKeHD[5] -7, ytk + 37);
		cout << "Sau-->";
	}
}
void YesNoSua(int x, int y, int ht)
{
	if(ht == 0)
	{
		textcolor(42);
		gotoxy(x-2, y);
		cout << " Co ";
		textcolor(11);
		gotoxy(x + 20, y);
		cout << "Khong";
	}
	else
	{
		textcolor(11);
		gotoxy(x-2, y);
		cout << " Co ";
		textcolor(42);
		gotoxy(x + 20, y);
		cout << "Khong";
	}
}
int YesNo(int x, int y)
{
	Nocursortype();
	textcolor(42);
	gotoxy(x-2, y);
	cout << " Co ";
	textcolor(11);
	gotoxy(x + 20, y);
	cout << "Khong";
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
				YesNoSua(44, 14, i);
			}
			else if(c == 77)
			{
				if(i == 0)
					i = 1;
				else i--;
				YesNoSua(44, 14, i);
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
	return YesNo(44, 14);
}
void XoaKhungYN()
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
	Nocursortype();
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
void veKhungCTKhuyet1(int x, int y)
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
			gotoxy(x + 15 + i*22, y +1);
			cout << char(197);
			gotoxy(x + 15 + i*22, y -1);
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
void veKhungCTKhuyet2(int x, int y)
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
void veKhungKQTimKiem(string name1,string name2,string name3,string name4)
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
void veKhungCT()
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
	textcolor(setMauTiTle);
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
void veKhungChiTiet(string *arrTenCot, int x =0)
{ 
	
	yMap = yMap + x;
	// in ten cot
	for(int i =0; i<4;i++)
	{
		gotoxy(arrToaDoBangChiTet[i]+1 +((arrToaDoBangChiTet[i+1] - arrToaDoBangChiTet[i] -arrTenCot[i].length())/2),yMap +1);
		textcolor(setMauTiTle);
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
	}
}
                            // KET THUC HAM GIAO DIEN
							// BAT DAU HAM PHU

string to_String(int num)
{
	string kq;
	ostringstream convert;
	convert << num;
	kq = convert.str();
	return kq;
}
string to_Currency(int num)
{
	int x;
	int A[20];
	int nArr=0;
	while(num!=0)
	{
		x =num%10;
		num =num/10;
		A[nArr++] = x;
	}
	string str="";
	for(int i =0; i<nArr; i++)
	{
		if(i%3==0&&i != 0)
		{
			str+=",";	
		}
		str+=to_String(A[i]);
	}
	string str1;
	for(int j = str.length()-1; j >=0 ; j--)
	{
			str1+=str.at(j);
	}
	return str1;
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
// Ham lay nam hien tai
int LayThoiGianNam(){
	time_t now = time(0); // lay thoi gian dua tren he thong hien tai
	
	tm *laytime = localtime(&now); 
	return 1900+laytime->tm_year;
}
void LayThoiGian(int &ngay, int &thang,int &nam){
	time_t hienTai = time(0);
	tm *ltm = localtime(&hienTai);
	ngay = ltm->tm_mday;
	thang = ltm->tm_mon +1;
	nam = ltm->tm_year +1900;
}
void ContentRemoveCT()
{
	gotoxy(19,7);
	cout << "            ";
	gotoxy(34,7);
	cout << "                    ";
	gotoxy(56,7);
	cout << "                  ";
	gotoxy(77,7);
	cout << "       ";
}

								// KET THUC HAM PHU
								// BAT DAU VAT TU
void VatTuInit(Tree &root)
{
	root = NULL;
}
NODE_VATTU* VatTuCreateNode(VATTU data)
{
	NODE_VATTU* p = new NODE_VATTU;
	if(p == NULL)
	{
		exit(1);
	}
	p->CSCB = EH;
	p->Data = data;
	p->pLeft = NULL;
	p->pRight = NULL;	
	return p;
}
// cay con trai lech trai
void VatTuRotateLeftLeft(Tree &root)
{
	NODE_VATTU *p;
	p = root->pLeft;
	root->pLeft = p->pRight;
	p->pRight = root;
	switch(p->CSCB)
	{
		case LH:
			root->CSCB = EH;
			p->CSCB = EH;
			break;
		case EH:
			p->CSCB =RH;
			root->CSCB =LH;
			break;
	}
	root = p;
}
// cay con phai lech phai
void VatTuRotateRightRight(Tree &root)
{
	NODE_VATTU *p;
	p = root->pRight;
	root->pRight = p->pLeft;
	p->pLeft =root;
	switch(p->CSCB)
	{
		case EH:
			root->CSCB =RH;
			p->CSCB = EH;
			break;
		case RH:
			p->CSCB = EH;
			root->CSCB = EH;
			break;
	}
	root = p;
}
// cay con phai lech trai
void VatTuRotateRightLeft(Tree &root)
{
	NODE_VATTU *p, *q;
	p = root->pRight;
	q = p->pLeft;
	root->pRight = q->pLeft;
	p->pLeft = q->pRight;
	q->pLeft =root;
	q->pRight = p;
	switch(q->CSCB)
	{
		case LH:
			root->CSCB = EH;
			p->CSCB =RH;
			break;
		case EH:
			root->CSCB = EH;
			p->CSCB =EH;
			break;
		case RH:
			root->CSCB = LH;
			p->CSCB = EH;
			break;
	}
	q->CSCB = EH;
	root = q;
}
//cay con trai lech phai
void VatTuRotateLeftRight(Tree &root)
{
	NODE_VATTU *p, *q;
	p = root->pLeft;
	q=p->pRight;
	root->pLeft = q->pRight;
	p->pRight = q->pLeft;
	q->pRight =root;
	q->pLeft = p;
	switch(q->CSCB)
	{
		case LH:
			p->CSCB = EH;
			root->CSCB = RH;
			break;
		case EH:
			root->CSCB = EH;
			p->CSCB = EH;
			break;
		case RH:
			root->CSCB =EH;
			p->CSCB = LH;
			break;
	}
	q->CSCB =EH;
	root = q;
}
// Can bang cay bi lech trai
int VatTuBalanceLeft(Tree &root)
{
	NODE_VATTU *p;
	p = root->pLeft;
	switch(p->CSCB)
	{
		case LH:
			VatTuRotateLeftLeft(root);
			return 2;
		case EH:
			VatTuRotateLeftLeft(root);
			return 1;
		case RH:
			VatTuRotateLeftRight(root);
			return 2;
	}
}
// can bang cay khi lech phai
int VatTuBalanceRight(Tree &root)
{
	NODE_VATTU *p;
	p = root->pRight;
	switch(p->CSCB)
	{
		case RH:
			VatTuRotateRightRight(root);
			return 2;
		case EH:
			VatTuRotateRightRight(root);
			return 1;
		case LH:
			VatTuRotateRightLeft(root);
			return 2;
	}
}
int VatTuInsertNode(Tree &root, VATTU data)
{
	int res;
	if(root)
	{
//		if(strcmp(root->Data.MaVT,data.MaVT) == 0)
//		{
//			return 0;
//		}
		// chen trai
		if(strcmp(root->Data.MaVT,data.MaVT) == 1)
		{
			res = VatTuInsertNode(root->pLeft,data);
			if(res < 2) return res;
			switch(root->CSCB)
			{
				case RH:
					root->CSCB = EH;
					return 1;
				case EH:
					root->CSCB = LH;
					return 2;
				case LH:
					VatTuBalanceLeft(root);
					return 1;
			}
		}
		// chen phai
		else if(strcmp(root->Data.MaVT,data.MaVT) == -1)
		{
			res = VatTuInsertNode(root->pRight,data);
			if(res <2) return res;
			switch(root->CSCB)
			{
				case LH:
					root->CSCB = EH;
					return 1;
				case EH:
					root->CSCB = RH;
					return 2;
				case RH:
					VatTuBalanceRight(root);
					return 1;
			}
		}
	}
	root = VatTuCreateNode(data);
	return 2;
}
// tim node the mang
int VatTuSearchStandFor(Tree &root, NODE_VATTU* &p)
{
	int res;
	if(p->pLeft)
	{
		res = VatTuSearchStandFor(root,p->pLeft);
		if(res < 2) return res;
		switch(p->CSCB)
		{
			case LH:
				p->CSCB = EH;
				return 1;
			case EH:
				p->CSCB = RH;
				return 2;
			case RH:
				return VatTuBalanceRight(root);
		}
	}
	root->Data = p->Data;
	root = p;
	p = p->pRight;
	return 2;
}
NODE_VATTU* VatTuSearch(Tree t, string x)
{
	if(t == NULL)
	{
		return NULL;
	}
	while(t->Data.MaVT !=x)
	{
		if(strcmp(t->Data.MaVT,x.c_str()) == 1)
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
NODE_VATTU* VatTukiemTraTrungMa(Tree t,string maVT)
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
			return VatTukiemTraTrungMa(t->pLeft, maVT);
		if(strcmp(t->Data.MaVT, maVT.c_str()) == -1)
			return VatTukiemTraTrungMa(t->pRight, maVT);
	}
	return NULL;
}
int NhanVienKiemTraTrungMa(string MNV)
{
	for(int i=0;i<dsnv.soLuongNV;i++)
	{
		if(strcmp(dsnv.nv[i].MaNV,MNV.c_str())==0)
		{
			return false;
		}
	}
	return true;
}
int VatTuCountNode(Tree &t)
{
	if(t == NULL)
	{
		return 0;
	}
	else 
	{
		return 1+VatTuCountNode(t->pLeft) + VatTuCountNode(t->pRight);
	}
}

void VatTuLNR(Tree t,string arrMVT[] ,int &nVT)
{
	if (t != NULL)
	{
		VatTuLNR(t->pLeft,arrMVT,nVT);
		arrMVT[nVT++]=t->Data.MaVT;
		VatTuLNR(t->pRight,arrMVT,nVT);
	}
}
void VatTuwriteToFile(Tree Root)
{
        queue<Tree> q;
        Tree p;
 	const char *path ="VATTU.TXT";
	ofstream ofs(path, ios::binary|ios::out);
        if (Root == NULL) return;
 
        p = Root;
        q.push(p);
 
        while (!q.empty())
        {
                p = q.front();
                q.pop();
                ofs.write(reinterpret_cast<char*>(&p->Data),sizeof(VATTU));
                if (p->pLeft) q.push(p->pLeft);
                if (p->pRight) q.push(p->pRight);
        }
}
void VatTureadFromFile()
{
	const char *path ="VATTU.TXT";
	
	ifstream ifs(path, ios::binary|ios::in);
	VATTU data;
	if(ifs.fail())
	{
		return;
	}
	while(!ifs.eof())
	{
		ifs.read(reinterpret_cast<char*>(&data),sizeof(VATTU));
		VatTuInsertNode(t,data);
	}
	ifs.close();
}
void VatTuNhap()
{
	system("cls");
	VATTU data;
	textcolor(setMauTiTle);
	gotoxy(40,2);
	cout << "THEM VAT TU CO THE NHAP VAO KHO";
	textcolor(7);
	gotoxy(42,3);
	cout << "Tong so vat tu hien tai: "<< VatTuCountNode(t);
	
	
	string maVT="", tenVT="",dvt="";
	bool ischeck=false;
	int vitri, key;
	int flag =0;
	int loop=0;
	int y;
	int slt=0;
	veKhungKQTimKiem("Ma Vat Tu","Ten Vat Tu","So luong ton","DVT");
	veKhungKhuyet1(18,7);
	veKhungKhuyet2(18,7);
	gotoxy(20,7);
	int dong=0;
	char space;
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
					VatTuwriteToFile(t);
					if(dong!=0)
					{
						XoaKhungYN();
						veKhungTB("   Da luu toan bo vat tu");
					}
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
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
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (tenVT.size() ==0 || space == ' ') )
					{
						space='a';
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
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (dvt.size() ==0 || space == ' ') )
					{
						space='a';
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
					else if(maVT.size() < 10)
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
					else if(VatTukiemTraTrungMa(t,maVT) !=NULL)
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
						data.SoLuongTon = slt;
						VatTuInsertNode(t,data);
						gotoxy(67,3);
						cout << VatTuCountNode(t);
						dong++;
						maVT="";
						tenVT="";
						dvt="";
						veKhungKhuyet1(18,7+dong*2);
						veKhungKhuyet2(18,7+dong*2);
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
void ContentRemove()
{
	for(int stt = 0;stt< 14;stt++)
	{
		gotoxy(arrToaDoBangChiTet[0]+1,3+yMap +stt*2);
		cout << "              ";
		gotoxy(arrToaDoBangChiTet[1]+1,3+yMap +stt*2);
		cout <<"                    ";
		gotoxy(arrToaDoBangChiTet[2]+1,3+yMap +stt*2);
		cout << "                ";
		gotoxy(arrToaDoBangChiTet[3]+1,3+yMap +stt*2);
		cout << "          ";
	}
}
void VatTuXuat(VATTU data,int stt)
{
	gotoxy(20,3+yMap +stt*2);
	cout << data.MaVT;
	gotoxy(40,3+yMap +stt*2);
	cout << data.TenVT;
	gotoxy(57+((26-to_String(data.SoLuongTon).size())/2),3+yMap +stt*2);
	cout << data.SoLuongTon;
	gotoxy(87,3+yMap +stt*2);
	cout << data.DVT;
}
void HoanDoiString(string &a, string &b)
{
	string temp;
	temp =a;
	a = b;
	b =temp;
}
void Sort(string *&arrMVT,int trai,int phai)
{
	int i =trai;
	int j =phai;
	string pivot = arrMVT[(trai+phai)/2];
	while(i <= j)
	{
		while(arrMVT[i] < pivot)
			i++;
		while(arrMVT[j] > pivot)
			j--;
		if(i <= j)
		{
			HoanDoiString(arrMVT[i],arrMVT[j]);
			i++;
			j--;
		}
	}
	if(trai < j)
	{
		Sort(arrMVT,trai,j);
	}
	if(i < phai)
	{
		Sort(arrMVT,i,phai);
	}
}
void VatTuSort(string arrMVT[],int &nVT)
{
	Sort(arrMVT,0,nVT-1);
}
void VatTuXuatDS(string MVT[],int &nArr, int vitri =0)
{
	int k =0;
	NODE_VATTU *p ;
	VatTuSort(MVT,nArr);
	for(int i =vitri; i < nArr; i++)
	{
		p= new NODE_VATTU;
		p = VatTuSearch(t,MVT[i]);
		VatTuXuat(p->Data,k++);
		if(k == 14)
		{
			break;
		}
	}
}
void VatTuQuanLyXuat()
{
	if(t == NULL)
	{
		veKhungTB("         Khong co vat tu");
		system("cls");
		return;
	}
	system("cls");
	Nocursortype();
	gotoxy(40,2);
	textcolor(setMauTiTle);
	cout << "DANH SACH VAT TU CO TRONG KHO";
	textcolor(7);
	string arr[4] ={"Ma vat tu", "Ten vat tu", "So luong ton","DVT"};
	veKhungChiTiet(arr,0);
	int page =0,i=0,vitri=0;
	
	int key;
	int n = VatTuCountNode(t);
	string MVT[n+1];
	int nArr;
	VatTuLNR(t,MVT,nArr);
	int total = (n%14 ==0) ? n /14 : n/14+1;
	gotoxy(54,34);
	textcolor(setMauTiTle);
	cout << page+1 <<" / " << total;
	textcolor(7);
	VatTuXuatDS(MVT,nArr,vitri);
	while(true)
	{
		while(!kbhit())
		{
			gotoxy(54,34);
			textcolor(setMauTiTle);
			cout << page+1;
			textcolor(7);
			key = getch();
			if(key == 0)
			{
				key = getch();
			}
			else if(key == 224)
			{
				key =  getch();
				if(key == 75 && page >0)
				{
					page--;
					vitri-=14;
					ContentRemove();
					VatTuXuatDS(MVT,nArr,vitri);
				}
				else if(key == 77 && page <total-1)
				{
					page++;
					vitri+=14;
					ContentRemove();
					VatTuXuatDS(MVT,nArr,vitri);
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
int VatTuDelete(Tree &root, string MVT)
{
	int res;
	// Khong ton tai node
	if(!root) return 0;
	if(strcmp(root->Data.MaVT,MVT.c_str()) == 1)
	{
		res = VatTuDelete(root->pLeft,MVT);
		// Neu co xoa thi tra ve res =1 or 2. 2 tu la thay doi chieu cao cay
		if(res < 2) return res;
		// chieu cao bi thay doi
		switch(root->CSCB)
		{
			case LH:
				root->CSCB = EH;
				return 2;
			case EH:
				root->CSCB = RH;
				return 1;
			case RH:
				return VatTuBalanceRight(root);
		}
	}
	else if(strcmp(root->Data.MaVT,MVT.c_str()) == -1)
	{
		res = VatTuDelete(root->pRight,MVT);
		if(res < 2) return res;
		switch(root->CSCB)
		{
			case LH:
				return VatTuBalanceLeft(root);
			case EH:
				root->CSCB = LH;
				return 1;
			case RH:
				root->CSCB = EH;
				return 2;
		}
	}
	else
	{
		NODE_VATTU *q = root;
		if(root->pLeft == NULL)
		{
			root = root->pRight;
			res =2;
		}
		else
		{
			if(root->pRight == NULL)
			{
				res = 2;
			}
			else
			{
				res = VatTuSearchStandFor(q,root->pRight);
				if(res < 2) return res;
				switch(root->CSCB)
				{
					case RH:
						root->CSCB = EH;
						return 2;
					case EH:
						root->CSCB = LH;
						return 1;
					case LH:
						return VatTuBalanceRight(root);
				}
				delete q;
				return res;
			}
		}
	}
}
int VatTuKiemTraXoa(string MaVT)
{
	int MAX = VatTuCountNode(t)+1;
	string MVT[MAX];
	int nArr;
	VatTuLNR(t,MVT,nArr);
	NODE_VATTU *p ;
	for(int i =0; i < nArr; i++)
	{
		if(MVT[i]==MaVT)
		{
			p = VatTuSearch(t,MaVT);
			if(p->Data.SoLuongTon > 0)
			{
				return 1;
			}
		}
	}
	return 0;
}
void VatTuXoa()
{
	if(t==NULL)
	{
		veKhungTB("         Khong co vat tu");
		system("cls");
		return;
	}
	system("cls");
	textcolor(setMauWarning);
    gotoxy(40,2);
    cout << "Ma vat tu: ";
    textcolor(7);
	string mavt;
	int key,vitri;	
	int y=2;
		while(true)
		{
			while(!kbhit())
			{
				vitri = 51+mavt.size();
				key =getch();
				if(key ==27)
				{
					if(veKhungYesNo("      Ban co muon thoat khong?",0))
					{
						VatTuwriteToFile(t);
						system("cls");
						return;
					}
					else
					{
						XoaKhungYN();
						continue;
					}
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
					if(VatTukiemTraTrungMa(t,mavt) == NULL)
					{
						while(!kbhit())
							Canhbao("Khong tim thay ma vat tu "+mavt+".Xin kiem tra lai!!",30,1);
						do{
							int key1 = getch();
						}while(key!=13);
						gotoxy(vitri,y);
					}
					else if(VatTuKiemTraXoa(mavt)==1)
					{
						while(!kbhit())
							Canhbao("Khong xoa duoc ma vat tu "+mavt+".Xin kiem tra lai!!",30,1);
						do{
							int key1 = getch();
						}while(key!=13);
						gotoxy(vitri,y);
					}
					else
					{
						system("cls");
						NODE_VATTU* p = VatTuSearch(t,mavt);
						gotoxy(40,2);
						cout << "Ma Vat Tu: "<<mavt;
						veKhungKQTimKiem("Ma Vat Tu","Ten Vat Tu","So Luong Ton","DVT");
						gotoxy(40,2);
						cout << "Ma Vat Tu: "<<mavt;
						veKhungKhuyet1(18,7);
						veKhungKhuyet2(18,7);
						gotoxy(20,7);
						cout << p->Data.MaVT;
						gotoxy(36+((18-strlen(p->Data.TenVT)))/2,7);
						cout << p->Data.TenVT;
						gotoxy(68,7);
						cout << p->Data.SoLuongTon;
						gotoxy(79+((6-strlen(p->Data.DVT)))/2,7);
						cout << p->Data.DVT;
						if(veKhungYesNo("    Ban co muon xoa "+mavt+"?",0))
						{
							VatTuDelete(t,mavt);
							system("cls");
							veKhungTB(" Xoa thanh cong "+mavt+"");
							system("cls");
							return;
						}
						else
						{
							NODE_VATTU* p = VatTuSearch(t,mavt);
							gotoxy(40,2);
							cout << "Ma Vat Tu: "<<mavt;
							ContentRemoveCT();
							gotoxy(20,7);
							cout << p->Data.MaVT;
							gotoxy(36+((18-strlen(p->Data.TenVT)))/2,7);
							cout << p->Data.TenVT;
							gotoxy(68,7);
							cout << p->Data.SoLuongTon;
							gotoxy(79+((6-strlen(p->Data.DVT)))/2,7);
							cout << p->Data.DVT;
							veKhungTB("           Da huy xoa ");
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
void VatTuTimKiem()
{
	if(t==NULL)
	{
		veKhungTB("         Khong co vat tu");
		system("cls");
		return;
	}
	system("cls");
	textcolor(setMauWarning);
		gotoxy(40,2);
		cout << "Ma Vat tu: ";
		textcolor(7);
		string mavt;
		int key,vitri;
		int y =2;
		while(true)
		{
			while(!kbhit())
			{
				vitri = 51+mavt.size();
				key =getch();
				if(key ==27)
				{
					if(veKhungYesNo("      Ban co muon thoat khong?",0))
					{
						system("cls");
						return;
					}
					else
					{
						XoaKhungTB();
						continue;
					}
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
					if(VatTukiemTraTrungMa(t,mavt) == NULL)
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
						NODE_VATTU* p = VatTuSearch(t,mavt);
						gotoxy(40,2);
						cout << "Ma Vat tu: " << mavt;
						veKhungKQTimKiem("Ma Vat Tu","Ten Vat Tu","So Luong Ton","DVT");
						veKhungKhuyet1(18,7);
						veKhungKhuyet2(18,7);
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
void VatTuHieuChinh()
{
	if(t==NULL)
	{
		veKhungTB("         Khong co vat tu");
		system("cls");
		return;
	}
	system("cls");
	textcolor(setMauWarning);
	gotoxy(40,2);
	cout << "Ma Vat Tu: ";
	textcolor(7);
	string mavt;
	int loop =0;
	int key1,vitri1;
	NODE_VATTU *q;
	while(loop ==0)
	{
		while(!kbhit())
		{
			vitri1 = 51+mavt.size();
			key1 =getch();
			if(key1 ==27)
			{
				if(veKhungYesNo("      Ban co muon thoat khong?",0))
				{
					VatTuwriteToFile(t);
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
					continue;
				}
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
				if(VatTukiemTraTrungMa(t,mavt) == NULL)
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
					q = VatTuSearch(t,mavt);
					gotoxy(40,2);
					cout << "Ma Vat Tu: " << mavt ;
					veKhungKQTimKiem("Ma Vat Tu","Ten Vat Tu","So Luong Ton","DVT");
					veKhungKhuyet1(18,7);
					veKhungKhuyet2(18,7);
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
	string tam2=q->Data.TenVT,tam3=q->Data.DVT;
	int slt = q->Data.SoLuongTon;
	int th=2;
	gotoxy(79+tam3.size(),7);
	char space;
	VATTU data;
	while(exit ==0)
	{
		while(!kbhit())
		{
			if(th==1)
			{
				vtr = 35+tam2.size();
			}
			else if(th ==2)
			{
				vtr = 79+tam3.size();
			}
			key = getch();
			if(key == 0)
			{
				key == getch();
			}
			else if(key ==27)
			{
				if(veKhungYesNo("      Ban co muon thoat khong?",0))
				{
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
					continue;
				}
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90) || key ==32)
			{
				if(th==1 && tam2.size() < 20)
				{
					gotoxy(vtr,7);
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (tam2.size() ==0 || space == ' ') )
					{
						space='a';
						key = key -32;
					}
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
				else if(th==2 && tam3.size() <5)
				{
					gotoxy(vtr,7);
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (tam3.size() ==0 || space == ' ') )
					{
						space='a';
						key = key -32;
					}
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
					if(tam2.size()==0)
					{
						tam2=q->Data.TenVT;
						gotoxy(35,7);
						cout << tam2;
					}
					else{
						gotoxy(79+tam3.size(),7);
						th=2;
					}
				}
				else if(th==2)
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
							
							strcpy(q->Data.TenVT,tam2.c_str());
							strcpy(q->Data.DVT,tam3.c_str());
							ContentRemoveCT();
							gotoxy(20,7);
							cout << q->Data.MaVT;
							gotoxy(35,7);
							cout << q->Data.TenVT;
							gotoxy(57,7);
							cout << slt;
							gotoxy(79,7);
							cout << q->Data.DVT;
							XoaKhungYN();
							veKhungTB("        Da sua thanh cong");
							system("cls");
							return;
						}
						else
						{
							gotoxy(20,7);
							cout << q->Data.MaVT;
							gotoxy(35,7);
							cout << q->Data.TenVT;
							gotoxy(57,7);
							cout << q->Data.SoLuongTon;
							gotoxy(79,7);
							cout << q->Data.DVT;
							XoaKhungYN();
							veKhungTB("        Da huy tac vu sua");
							system("cls");
							return;
						}
					}
				}
			}
			else if(key ==8)
			{
				if(th ==1 && tam2.size() >0)
				{
					vtr--;
					gotoxy(vtr,7);
					cout << " ";
					gotoxy(vtr,7);
					tam2.erase(tam2.end()-1);
				
				}
				else if(th ==2 && tam3.size() >=0)
				{
					if(vtr==vtr-tam3.size())
					{
						gotoxy(35+tam2.size(),7);
						th=1;
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
								// KET THUC VAT TU
								// NHAN VIEN
void NhanVienAddTail(string MaNV, string Ho, string Ten, string Phai)
{
	
	strcpy(dsnv.nv[dsnv.soLuongNV].MaNV,MaNV.c_str());
	strcpy(dsnv.nv[dsnv.soLuongNV].Ho,Ho.c_str());
	strcpy(dsnv.nv[dsnv.soLuongNV].Ten,Ten.c_str());
	strcpy(dsnv.nv[dsnv.soLuongNV].Phai,Phai.c_str());
	dsnv.nv[dsnv.soLuongNV].fisrtHD =NULL;
	dsnv.soLuongNV++;
}
void NhanVienwritetoFile()
{
	const char* path ="NHANVIEN.txt";
	ofstream ofs(path,ios::out);
	ofs << dsnv.soLuongNV << endl;
	for(int i =0; i < dsnv.soLuongNV;i++)
	{
		ofs << dsnv.nv[i].MaNV << '@' << dsnv.nv[i].Ho << '@' << dsnv.nv[i].Ten << '@'  << dsnv.nv[i].Phai<< endl;
	}
	ofs.close();
}
void NhanVienreadFromFile()
{
	const char* path ="NHANVIEN.txt";
	ifstream ifs(path,ios::in);
	string MNV,Ho,Ten,Phai;
	int x;
	int n;
	if(ifs.fail())
	{
		return;
	}
	ifs >> n;
	ifs.ignore();
	for(int i =0; i < n;i++)
	{
		getline(ifs,MNV,'@');
		getline(ifs,Ho,'@');
		getline(ifs,Ten,'@');
		getline(ifs,Phai);
		NhanVienAddTail(MNV,Ho,Ten,Phai);
	}
	ifs.close();
}
void NhanVienNhap()
{
	system("cls");
	Yescursortype();
	veKhungKQTimKiem("Ma Nhan Vien","Ho","Ten","Phai");
	textcolor(setMauTiTle);
	gotoxy(40,2);
	cout << "THEM NHAN VIEN VAO HE THONG";
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
	gotoxy(36,3);
	cout << "So nhan vien hien co trong he thong: " << dsnv.soLuongNV;
	veKhungKhuyet1(18, 7);
	veKhungKhuyet2(18,7);
	gotoxy(20,7);
	char space;
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
					NhanVienwritetoFile();
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
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
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (Ho.size() ==0  || space == ' ' ))
					{
						space='a';
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
					Ho.insert(Ho.end(),1,(char)key);
				}
				else if(flag ==3 && Ten.size() < 20)
				{
					gotoxy(vitri,y);
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (Ten.size() ==0 || space == ' ') )
					{
						space='a';
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
					Ten.insert(Ten.end(),1,(char)key);	
				}
				else if(flag ==4 && Phai.size() < 3)
				{
					gotoxy(vitri,y);
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (Phai.size() ==0  || space == ' ' ))
					{
						space='a';
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
					else if(NhanVienKiemTraTrungMa(MaNV)==false)
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
					else if(Phai != "Nam" && Phai !="Nu")
					{
						while(!kbhit())
						{
							Canhbao("Nhap sai phai : Nam/Nu.Xin nhap lai!",36,1);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,y);
					}
					else
					{
						NhanVienAddTail(MaNV,Ho,Ten,Phai);
						gotoxy(73,3);
						cout << dsnv.soLuongNV;
						MaNV ="";
						Ten ="";
						Ho ="";
						Phai= "";
						dong++;
						veKhungKhuyet1(18, 7+dong*2);
						veKhungKhuyet2(18,7+dong*2);
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
					if(Ho.size() == 0)
					{
						gotoxy(20+MaNV.size(),y);
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
					if(Ten.size()==0)
					{
						gotoxy(35+Ho.size(),y);
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
					if(Phai.size()==0)
					{
						gotoxy(57+Ten.size(),y);
						flag=3;
					}
					else
						vitri--;
						gotoxy(vitri,y);			{
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
	
void HoanDoiChar(char a[21],char b[21])
{
	char temp[31];
	strcpy(temp,a);
	strcpy(a,b);
	strcpy(b,temp);
}
void NhanVienSort()
{
	for(int i =0;i<dsnv.soLuongNV;i++)
	{
		for(int j =dsnv.soLuongNV-1;j >i;j--)
		{
			if(strcmp(dsnv.nv[i].Ten,dsnv.nv[j].Ten) ==1)
			{
				HoanDoiChar(dsnv.nv[i].MaNV,dsnv.nv[j].MaNV);
				HoanDoiChar(dsnv.nv[i].Ho,dsnv.nv[j].Ho);
				HoanDoiChar(dsnv.nv[i].Ten,dsnv.nv[j].Ten);
				HoanDoiChar(dsnv.nv[i].Phai,dsnv.nv[j].Phai);
			}
			else if(strcmp(dsnv.nv[i].Ten,dsnv.nv[j].Ten)==0)
			{
				if(strcmp(dsnv.nv[i].Ho,dsnv.nv[j].Ho) == 1)
				{
					HoanDoiChar(dsnv.nv[i].MaNV,dsnv.nv[j].MaNV);
					HoanDoiChar(dsnv.nv[i].Ho,dsnv.nv[j].Ho);
					HoanDoiChar(dsnv.nv[i].Ten,dsnv.nv[j].Ten);
					HoanDoiChar(dsnv.nv[i].Phai,dsnv.nv[j].Phai);
				}
			}
			
		}
	}
}
void NhanVienXuat(NHANVIEN data,int stt)
{
	gotoxy(20,3+yMap +stt*2);
	cout << data.MaNV;
	gotoxy(39,3+yMap +stt*2);
	cout << data.Ho;
	gotoxy(63,3+yMap +stt*2);
	cout << data.Ten;
	gotoxy(87,3+yMap +stt*2);
	cout << data.Phai;
}
void NhanVienXuatDS(int vitri=0)
{
	Nocursortype();
	
	int k=0;
	for(int i =vitri;i< dsnv.soLuongNV;i++)
	{
		NhanVienXuat(dsnv.nv[i],k);
		k++;
		if(k == 14)
		{
			break;
		}
	}
}
void NhanVienQuanLyXuat()
{
	if(dsnv.soLuongNV==0)
	{
		veKhungTB("       Khong co nhan vien");
		system("cls");
		return;
	}
	system("cls");
	NhanVienSort();
	string arr[]={"Ma NV","Ho","Ten","Phai"};
	gotoxy(45,2);
	textcolor(setMauTiTle);
	cout << "DANH SACH NHAN VIEN";
	textcolor(7);
	Nocursortype();
	veKhungChiTiet(arr,0);
	int key;
	int page =0,i=0,vitri=0;
	int total = (dsnv.soLuongNV%14 ==0) ? dsnv.soLuongNV /14 : dsnv.soLuongNV/14+1;
	gotoxy(54,34);
	textcolor(setMauTiTle);
	cout << page+1 <<" / " << total;
	textcolor(7);
	NhanVienXuatDS(vitri);
	while(true)
	{
		while(!kbhit())
		{
			gotoxy(54,34);
			textcolor(setMauTiTle);
			cout << page+1;
			textcolor(7);
			key = getch();
			if(key == 0)
			{
				key = getch();
			}
			else if (key == 224)
			{
				key = _getch();
				if (key == 75 && page > 0)
				{
					page--;
					vitri-=14;
					ContentRemove();
					NhanVienXuatDS(vitri);
				}
				else if (key == 77 && page < total-1)
				{
					page++;
					vitri += 14;
					ContentRemove();
					NhanVienXuatDS(vitri);
				}
			}
			else if (key == 27) // esc
			{
				system("cls");
				return;
			}
		}
	}
}
void NhanVienTimKiem()
{
	if(dsnv.soLuongNV==0)
	{
		veKhungTB("       Khong co nhan vien");
		system("cls");
		return;
	}
	system("cls");
	textcolor(setMauWarning);
	gotoxy(40,2);
	cout << "Ma Nhan Vien: ";
	textcolor(7);
	string manv;
	int key,vitri;
	int y=2;
	while(true)
	{
		while(!kbhit())
		{
			vitri = 54+manv.size();
			key =getch();
			if(key ==27)
			{
				if(veKhungYesNo("     Ban co muon thoat khong?",0))
				{
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
					continue;
				}
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
				if(NhanVienKiemTraTrungMa(manv))
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
					for(int i =0;i<dsnv.soLuongNV;i++)
					{
						if(dsnv.nv[i].MaNV==manv) 
						{
							vtr=i;
							break;
						}
					}
					gotoxy(40,2);
					cout << "Ma Nhan Vien: " << manv;
					veKhungKQTimKiem("Ma Nhan Vien","Ho","Ten","Phai");
					veKhungKhuyet1(18,7);
					veKhungKhuyet2(18,7);
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
void NhanVienHieuChinh()
{
	if(dsnv.soLuongNV==0)
	{
		veKhungTB("       Khong co nhan vien");
		system("cls");
		return;
	}
		system("cls");
	Yescursortype();
	textcolor(setMauWarning);
	gotoxy(40,2);
	cout << "Ma Nhan Vien: ";
	textcolor(7);
	string manv;
	int key1,vitri;
	int vtr;
	int y=2;
	int loop = 0;
	while(loop ==0)
	{
		while(!kbhit())
		{
			vitri = 54+manv.size();
			key1 =getch();
			if(key1 ==27)
			{
				if(veKhungYesNo("     Ban co muon thoat khong?",0))
				{
					NhanVienwritetoFile();
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
					continue;
				}
			}
			else if((key1 >= 48&& key1 <=57) || (key1 >=97 && key1<=122) || (key1 >=65 && key1 <=90))
			{
				if(manv.length()  <10)
				{
		 			gotoxy(vitri,y);
					if(key1 >=97 && key1 <=122)
						key1 = key1 -32;
					cout << (char)key1;
					manv.insert(manv.end(),1,(char)key1);
			   }
			}
			else if(key1 ==13)
			{
				if(manv.size() <10)
				{
					while(!kbhit())
						Canhbao("Do dai ma nhan vine phai 10 ki tu.Xin kiem tra lai!!",30,1);
					do{
						int key2 = getch();
					}while(key1!=13);
					gotoxy(vitri,y);
				}
				if(NhanVienKiemTraTrungMa(manv)==true)
				{
						while(!kbhit())
							Canhbao("Khong tim thay ma nhan vien "+manv+".Xin kiem tra lai!!",30,1);
						do{
							int key2 = getch();
						}while(key1!=13);
						gotoxy(vitri,y);
				}
					for(int i =0;i<dsnv.soLuongNV+1;i++)
					{
						if(dsnv.nv[i].MaNV==manv)
						{
							vtr=i;
							 break;
						 } 
					}
					veKhungKQTimKiem("Ma Nhan Vien","Ho","Ten","Phai");
					gotoxy(40,2);
					cout << "Ma Nhan Vien: "+manv+"";
					veKhungKhuyet1(18,7);
					veKhungKhuyet2(18,7);
					gotoxy(20,7);
					cout << dsnv.nv[vtr].MaNV;
					gotoxy(35,7);
					cout << dsnv.nv[vtr].Ho;
					gotoxy(57,7);
					cout << dsnv.nv[vtr].Ten;
					gotoxy(79,7);
					cout << dsnv.nv[vtr].Phai;
					loop =1;
					break;
			}
			else if(key1 == 8 && manv.length() >0)
			{
				vitri--;
				gotoxy(vitri,y);
				cout << " ";
				gotoxy(vitri,y);
				manv.erase(manv.end()-1);
			}
		}
	}
	int exit =0;
	int key,vtri;
	string MaNV =dsnv.nv[vtr].MaNV;
	string Ho=dsnv.nv[vtr].Ho;
	string Ten=dsnv.nv[vtr].Ten;
	string Phai=dsnv.nv[vtr].Phai;
	int th=3;
	gotoxy(79+Phai.size(),7);
	char space;
	VATTU data;
	while(exit ==0)
	{
		while(!kbhit())
		{
			if(th==1)
			{
				vtri = 35+Ho.size();
			}
			else if(th ==2)
			{
				vtri = 57+Ten.size();
			}
			else if(th==3)
			{
				vtri = 79+Phai.size();
			}
			key = getch();
			if(key == 0)
			{
				key == getch();
			}
			else if(key ==27)
			{
				if(veKhungYesNo("      Ban co muon thoat khong?",0))
				{
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
					continue;
				}
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90) || key ==32)
			{
				if(th==1 && Ho.size() < 20)
				{
					gotoxy(vtri,7);
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (Ho.size() ==0 || space == ' ') )
					{
						space='a';
						key = key -32;
					}
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << char(key);
					Ho.insert(Ho.end(),1,(char)key);
				}
				else if(th==2 && Ten.size() <20)
				{
					gotoxy(vtri,7);
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (Ten.size() ==0 || space == ' ') )
					{
						space='a';
						key = key -32;
					}
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << char(key);
					Ten.insert(Ten.end(),1,(char)key);
				}
				else if(th==3 && Phai.size() <3&& key !=32)
				{
					gotoxy(vtri,7);
					if(key ==32)
					{
						space = char(32);
					}
					if((key >=97 && key <=122)&& (Phai.size() ==0 || space == ' ') )
					{
						space='a';
						key = key -32;
					}
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << char(key);
					Phai.insert(Phai.end(),1,(char)key);
				}
			}
			else if(key ==13||key ==9)
			{
				if(th==1)
				{
					if(Ho.size()==0)
					{
						Ho=dsnv.nv[vtr].Ho;
						gotoxy(35,7);
						cout << Ho;
						gotoxy(57+Ten.size(),7);
						th=3;
					}
					else{
						gotoxy(57+Ten.size(),7);
						th=2;
					}
				}
				else if(th==2)
				{
					if(Ten.size()==0)
					{
						Ten = dsnv.nv[vtr].Ten;
						gotoxy(57,7);
						cout << Ten;
						gotoxy(79+Phai.size(),7);
						th=3;
					}
					else{
						gotoxy(79+Phai.size(),7);
						th=3;
					}
				}
				else if(th ==3)
				{
					if(Phai.size()==0)
					{
						Phai = dsnv.nv[vtr].Phai;
						gotoxy(57,7);
						cout << Phai;
					}
					else{
						if(veKhungYesNo("    Ban co muon thay doi khong ?",0))
						{
							strcpy(dsnv.nv[vtr].MaNV,MaNV.c_str());
							strcpy(dsnv.nv[vtr].Ho,Ho.c_str());
							strcpy(dsnv.nv[vtr].Ten,Ten.c_str());
							strcpy(dsnv.nv[vtr].Phai,Phai.c_str());
							system("cls");
							gotoxy(36,2);
							cout << "Ma Vat Tu: " << dsnv.nv[vtr].MaNV;
							veKhungKQTimKiem("Ma Vat Tu","Ten Vat Tu","So Luong Ton","DVT");
							veKhungKhuyet1(18,7);
							veKhungKhuyet2(18,7);
							gotoxy(20,7);
							cout << dsnv.nv[vtr].MaNV;
							gotoxy(35,7);
							cout << dsnv.nv[vtr].Ho;
							gotoxy(57,7);
							cout << dsnv.nv[vtr].Ten;
							gotoxy(79,7);
							cout << dsnv.nv[vtr].Phai;
							XoaKhungYN();
							veKhungTB("        Da sua thanh cong");
							system("cls");
							return;
						}
						else
						{
							system("cls");
							gotoxy(36,2);
							cout << "Ma Vat Tu: " << dsnv.nv[vtr].MaNV;
							veKhungKQTimKiem("Ma Vat Tu","Ten Vat Tu","So Luong Ton","DVT");
							veKhungKhuyet1(18,7);
							veKhungKhuyet2(18,7);
							gotoxy(20,7);
							cout << dsnv.nv[vtr].MaNV;
							gotoxy(35,7);
							cout << dsnv.nv[vtr].Ho;
							gotoxy(57,7);
							cout << dsnv.nv[vtr].Ten;
							gotoxy(79,7);
							cout << dsnv.nv[vtr].Phai;
							XoaKhungYN();
							veKhungTB("        Da huy tac vu sua");
							system("cls");
							return;
						}
					}
				}
			}
			else if(key ==8)
			{
				if(th ==1 && Ho.size() >0)
				{
					vtri--;
					gotoxy(vtri,7);
					cout << " ";
					gotoxy(vtri,7);
					Ho.erase(Ho.end()-1);
					
				}
				else if(th ==2 && Ten.size() >=0)
				{
					if(Ten.size()==0)
					{
						gotoxy(35+Ho.size(),7);
						th=1;
					}
					else
					{
					vtri--;
					gotoxy(vtri,7);
					cout << " ";
					gotoxy(vtri,7);
					Ten.erase(Ten.end()-1);
					}
				}
				else if(th ==3 && Phai.size() >=0)
				{
					if(Phai.size()==0)
					{
						gotoxy(57+Ten.size(),7);
						th=2;
					}
					else
					{
					vtri--;
					gotoxy(vtri,7);
					cout << " ";
					gotoxy(vtri,7);
					Phai.erase(Phai.end()-1);
					}
				}
			}
		}
	}
}
void NhanVienDel(int i)
{
	for(int j=i;j<dsnv.soLuongNV-1;j++)
	{
		dsnv.nv[j]=dsnv.nv[j+1];
	}
	dsnv.soLuongNV-=1;
}
int NhanVienkiemtraXoa(string MNV);
void NhanVienXoa()
{
	if(dsnv.soLuongNV==0)
	{
		veKhungTB("       Khong co nhan vien");
		system("cls");
		return;
	}
	system("cls");
	Yescursortype();
	textcolor(setMauWarning);
	gotoxy(40,2);
	cout << "Ma Nhan Vien: ";
	textcolor(7);
	string manv;
	int key,vitri;
	int y=2;
	while(true)
	{
		while(!kbhit())
		{
			vitri = 54+manv.size();
			key =getch();
			if(key ==27)
			{
				if(veKhungYesNo("     Ban co muon thoat khong?",0))
				{
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
					continue;
				}
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
				if(NhanVienKiemTraTrungMa(manv)==true)
				{
					while(!kbhit())
						Canhbao("Khong tim thay ma nhan vien "+manv+".Xin kiem tra lai!!",30,1);
					do{
						int key1 = getch();
					}while(key!=13);
					gotoxy(vitri,y);
				}
				if(NhanVienkiemtraXoa(manv) == 1)
				{
					while(!kbhit())
						Canhbao("Khong xoa duoc ma nhan vien "+manv+".Xin kiem tra lai!!",30,1);
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
					veKhungKQTimKiem("Ma Nhan Vien","Ho","Ten","Phai");
					gotoxy(40,2);
					cout << "Ma Nhan Vien: "+manv+"";
					veKhungKhuyet1(18,7);
					veKhungKhuyet2(18,7);
					gotoxy(20,7);
					cout << dsnv.nv[vtr].MaNV;
					gotoxy(36+((18-strlen(dsnv.nv[vtr].Ho))/2),7);
					cout << dsnv.nv[vtr].Ho;
					gotoxy(58+((18-strlen(dsnv.nv[vtr].Ten))/2),7);
					cout << dsnv.nv[vtr].Ten;
					gotoxy(79+((6-strlen(dsnv.nv[vtr].Phai))/2),7);
					cout << dsnv.nv[vtr].Phai;
					HOADON data;
					if(veKhungYesNo("     Ban co muon xoa khong?",0))
					{
						NhanVienDel(vtr);
						NhanVienwritetoFile();
						XoaKhungYN();
						veKhungTB("   Xoa thanh cong "+manv+"");
						system("cls");
						return;
					}
					else
					{
						gotoxy(40,2);
						cout << "Ma Nhan Vien: "+manv+"";
						ContentRemoveCT();
						gotoxy(20,7);
						cout << dsnv.nv[vtr].MaNV;
						gotoxy(36+((18-strlen(dsnv.nv[vtr].Ho))/2),7);
						cout << dsnv.nv[vtr].Ho;
						gotoxy(58+((18-strlen(dsnv.nv[vtr].Ten))/2),7);
						cout << dsnv.nv[vtr].Ten;
						gotoxy(79+((6-strlen(dsnv.nv[vtr].Phai))/2),7);
						cout << dsnv.nv[vtr].Phai;
						XoaKhungYN();
						veKhungTB("       Da huy xoa "+manv+"");
						system("cls");
						return;
					}
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
								// END
								// BAT DAU CHI TIET HOA DON
void HoaDonwritetoFile();
NODE_HOADON * HoaDonSearch(string soHD);
NODECT_HOADON* CT_HoaDonGetNode(CT_HOADON data)
{
	
	NODECT_HOADON* p = new NODECT_HOADON;
	p->pNext = NULL;
	p->Data = data;
	return p;
}
NODECT_HOADON *CT_HoaDonAddTail(NODECT_HOADON *dsct,NODECT_HOADON* p)
{
	if(dsct == NULL)
	{
		p->pNext = NULL;
		return p;
	}
	else
	{
		dsct->pNext = CT_HoaDonAddTail(dsct->pNext, p);
	}
}
void CT_HoaDOnNhapNhap(string MSHD)
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
	int tong=0;
	NODE_HOADON *q = HoaDonSearch(MSHD);
	NODE_VATTU *p;
	veKhungCT();
	veKhungCTKhuyet1(10,8);
	veKhungCTKhuyet2(10,8);
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
				vitri=45+sl.size();
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
					else
					{
						HoaDonwritetoFile();
					}
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
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
					if(VatTukiemTraTrungMa(t,maVT) == NULL)
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
							p = VatTuSearch(t,maVT);
							gotoxy(31,y);
							cout << p->Data.TenVT;
							gotoxy(58,y);
							cout << p->Data.DVT;
							gotoxy(45,y);
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
					if(VAT.size()==0)
					{
						vat=0;
						gotoxy(88,y);
						cout << vat;
						p->Data.SoLuongTon+=sls;
						VatTuwriteToFile(t);
						CT_HOADON cthd;
						if(nArr < MAXTK)
						{
							mangKiemtra[nArr++] = maVT;
						}
						strcpy(cthd.MaVT,maVT.c_str());
						cthd.soluong = sls;
						cthd.dongia = dg;
						cthd.VAT =vat;
						int kq = sls*dg+(vat/100)*dg;
						tong+=kq;
						q->data.fisrtCT=CT_HoaDonAddTail(q->data.fisrtCT,CT_HoaDonGetNode(cthd));
						sl="";
						maVT="";
						dongia ="";
						VAT="";
						dong++;
						XoaKhungtongtien(12+(dong-1)*2);
						veKhungTongGiaTien(12+dong*2);
						textcolor(setMauWarning);
						gotoxy(55,13+dong*2);
						cout << to_Currency(tong);
						gotoxy(80,13+dong*2);
						cout << "VND";
						textcolor(7);
						veKhungCTKhuyet1(10,8+dong*2);
						veKhungCTKhuyet2(10,8+dong*2);
					}
					else
					{
						p->Data.SoLuongTon+=sls;
						VatTuwriteToFile(t);
						CT_HOADON cthd;
						strcpy(cthd.MaVT,maVT.c_str());
						cthd.soluong = sls;
						cthd.dongia = dg;
						cthd.VAT =vat;
						if(nArr < MAXTK)
						{
							mangKiemtra[nArr++] = maVT;
						}
						int kq = sls*dg+(vat/100)*dg;
						tong+=kq;
						q->data.fisrtCT=CT_HoaDonAddTail(q->data.fisrtCT,CT_HoaDonGetNode(cthd));
						sl="";
						maVT="";
						dongia ="";
						VAT="";
						dong++;
						XoaKhungtongtien(12+(dong-1)*2);
						veKhungTongGiaTien(12+dong*2);
						textcolor(setMauWarning);
						gotoxy(55,13+dong*2);
						cout << to_Currency(tong);
						gotoxy(80,13+dong*2);
						cout << "VND";
						textcolor(7);
						veKhungCTKhuyet1(10,8+dong*2);
						veKhungCTKhuyet2(10,8+dong*2);
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
						gotoxy(31,y);
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
						gotoxy(57,y);
						cout << "      ";
						gotoxy(45+sl.size(),y);
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
NODECT_HOADON *CT_HoaDonSearch(string maVT);
void CT_HoaDonXuatNhap(string MSHD)
{ 
	int vitri,key;
	string maVT="",sl="",dongia="";
	int sls,vat,dg;
	int y;
	int flag =1;
	int exit =0;
	int dong =0;
	int vtr;
	int tong =0;
	NODE_VATTU *p;
	int gianhap;
	NODE_HOADON* q = HoaDonSearch(MSHD);
	NODECT_HOADON *k;
	veKhungCT();
	veKhungCTKhuyet1(10,8);
	veKhungCTKhuyet2(10,8);
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
				vitri=45+sl.size();
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
					else
					{
						HoaDonwritetoFile();
					}
					system("cls");
					return;
				}
				else
				{
					XoaKhungYN();
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
					if(VatTukiemTraTrungMa(t,maVT) == NULL)
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
						
						k = CT_HoaDonSearch(maVT);
						p = VatTuSearch(t,maVT);
						gotoxy(31,y);
						cout << p->Data.TenVT;
						gotoxy(58,y);
						cout << p->Data.DVT;
						gotoxy(45,y);
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
					
					else if(k->Data.dongia > dg)
					{
						while(!kbhit())
						{
							Canhbao("Gia xuat phai lon hon gia nhap < "+to_String(k->Data.dongia)+" >",40,1);
						} 
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else
					{
						vat =k->Data.VAT;
						gotoxy(90,y);
						cout << vat;
						p->Data.SoLuongTon-=sls;
						VatTuwriteToFile(t);
						CT_HOADON cthd;
						strcpy(cthd.MaVT,maVT.c_str());
						cthd.soluong = sls;
						cthd.dongia = dg;
						cthd.VAT =vat;
						int kq = sls*dg+(vat/100)*dg;
						tong+=kq;
						q->data.fisrtCT=CT_HoaDonAddTail(q->data.fisrtCT,CT_HoaDonGetNode(cthd));
						sl="";
						maVT="";
						dongia ="";
						dong++;
						XoaKhungtongtien(12+(dong-1)*2);
						veKhungTongGiaTien(12+dong*2);
						textcolor(setMauWarning);
						gotoxy(55,13+dong*2);
						cout << tong;
						gotoxy(80,13+dong*2);
						cout << "VND";
						textcolor(7);
						veKhungCTKhuyet1(10,8+dong*2);
						veKhungCTKhuyet2(10,8+dong*2);
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
						gotoxy(31,y);
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
					if(dongia.size()==0)
					{
						gotoxy(45+sl.size(),y);
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
void CT_HoaDonXuat(CT_HOADON data,int stt)
{
	gotoxy(20,3+yMap +stt*2);
	cout << data.MaVT;
	gotoxy(36+((21-to_String(data.soluong).size())/2),3+yMap +stt*2);
	cout << data.soluong;
	gotoxy(60,3+yMap +stt*2);
	cout << to_Currency(data.dongia);
	gotoxy(77,3+yMap + stt*2);
	cout << "VND";
	gotoxy(74+((26-to_String(data.VAT).size())/2),3+yMap +stt*2);
	cout << data.VAT;
}
								// KET THUC CHI TIET HOA DON
								// BAT DAU HOA DON
								
NODE_HOADON* HoaDonGetnode(HOADON data)
{
	NODE_HOADON* p = new NODE_HOADON;
	if(p==NULL)
		return NULL;
	p->data = data;
	p->pNext = NULL;
   
	return p;
}
NODE_HOADON *HoaDonAddTail(NODE_HOADON *dshd,NODE_HOADON *p)
{
	if(dshd == NULL)
	{
		p->pNext = NULL;
		return p;
	}
	else
		dshd->pNext = HoaDonAddTail(dshd->pNext, p);
}
NODE_HOADON* HoaDonSearch(string soHD)
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
int LayThoiGianSoSanh(Date &a, Date &b)
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
void HoaDonNhapNgay(Date &date,int &exit)
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
								gotoxy(63,y);
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
NODECT_HOADON *CT_HoaDonSearch(string maVT)
{
	for(int i =0;i < dsnv.soLuongNV+1; i++)
	{
		for(NODE_HOADON *p=dsnv.nv[i].fisrtHD;p!=NULL;p=p->pNext)
		{
			if(p->data.loai == 'N')
			{
				for(NODECT_HOADON *q = p->data.fisrtCT;q!=NULL;q=q->pNext)
				{
					if(strcmp(q->Data.MaVT,maVT.c_str())==0)
					{
						return q;
					}
				}	
			}	
		}	
	}	
}
void HoaDonNhap(int tinhieu)
{
	system("cls");
	textcolor(setMauTiTle);
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
	Date date;
	LayThoiGian(date.ngay, date.thang,date.nam);
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
	int exit =0;
	HoaDonNhapNgay(date,exit);
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
						XoaKhungYN();
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
						else if(NhanVienKiemTraTrungMa(MaNV)==true)
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
						else if(HoaDonSearch(MSHD) != NULL)
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
							else if(tinhieu == 1)
							{
								hd.loai='X';
							}
							hd.fisrtCT=NULL;
							hd.date = date;
							for(int i =1;i<dsnv.soLuongNV;i++)
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
						else if(flag == 2&&MSHD.size()>=0)
						{
							if(MSHD.size() == 0)
							{
								gotoxy(40+MaNV.size(),4);
								flag =1;
							}
							else
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
	}
	dsnv.nv[vtr].fisrtHD=HoaDonAddTail(dsnv.nv[vtr].fisrtHD,HoaDonGetnode(hd));
	if(tinhieu ==0)
	{
		CT_HoaDOnNhapNhap(MSHD);
	}
	else if(tinhieu == 1)
	{
		CT_HoaDonXuatNhap(MSHD);
	}
}
	
void HoaDonThem(int tinhieu)
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
	HoaDonNhap(tinhieu);
	
}
int NhanVienkiemtraXoa(string MNV)
{
	for(int i = 0; i < dsnv.soLuongNV+1; i++)
	{
		if(strcmp(dsnv.nv[i].MaNV,MNV.c_str())==0)
		{
			if(dsnv.nv[i].fisrtHD != NULL)
			{
				return 1;
			}
		}
		
	}
	return 0;
}
// xUat thong tin hoa don theo so hoa don nhap vao
int HoaDonKiemtraTonTai()
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
void HoaDonXuatThongTin()
{
	string SoHD;
	string arrTukhoa[]={"So HD","Ngay Lap","Loai"};
	int key,vitri,check =0,stt=0;
	if(HoaDonKiemtraTonTai()== 0)
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
					if(veKhungYesNo("      Ban co muon thoat khong?",0))
					{
						system("cls");
						return;
					}
					else
					{
						XoaKhungYN();
						continue;
					}
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
					if(HoaDonSearch(SoHD)==NULL)
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
						q= HoaDonSearch(SoHD);
						textcolor(setMauTiTle);
						gotoxy(46,2);
						cout << "THONG TIN HOA DON";
						textcolor(7);
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
						if(q->data.loai =='N')
						{
							cout << "Nhap";
						}
						else if(q->data.loai=='X')
						{
							cout << "Xuat";
						}
						NODECT_HOADON *p;
						string arr[] ={"Ma Vat Tu","So Luong","Don Gia","%VAT"};
						veKhungChiTiet(arr,1);
						for(p = q->data.fisrtCT;p!=NULL;p=p->pNext)
						{
							Nocursortype();
							CT_HoaDonXuat(p->Data,stt);
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
}
int CT_HoaDonDem(char soHD[21])
{
	int dem;
	for(int i =0; i < dsnv.soLuongNV+1;i++)
	{
		for(NODE_HOADON *p = dsnv.nv[i].fisrtHD; p!=NULL; p = p->pNext)
		{
			for(NODECT_HOADON *q = p->data.fisrtCT; q!=NULL; q = q->pNext)
			{
				if(strcmp(p->data.SoHD,soHD)==0)
				{
					dem++;
				}
			}
		}
	}
	return dem;
}
void HoaDonwritetoFile()
{
	const char* path ="HOADON.txt";
	ofstream ofs(path,ios::out);
	for(int i =0; i < dsnv.soLuongNV;i++)
	{
		if(dsnv.nv[i].fisrtHD != NULL)
		{
			for(NODE_HOADON *p = dsnv.nv[i].fisrtHD; p!=NULL; p = p->pNext)
			{
				ofs << dsnv.nv[i].MaNV << endl;
				ofs << p->data.SoHD << ',' << p->data.date.ngay << ',' << p->data.date.thang << ',' << p->data.date.nam << ',' << p->data.loai << endl;
				ofs << CT_HoaDonDem(p->data.SoHD) << endl;
				for(NODECT_HOADON *q = p->data.fisrtCT; q!=NULL; q = q->pNext)
				{	
					ofs << q->Data.MaVT << '-' << q->Data.soluong << '-' << q->Data.dongia << '-' << q->Data.VAT << endl;
				}
			}
		}
	}
	ofs.close();
}
void HoaDonreadFromFile()
{
	const char* path ="HOADON.txt";
	ifstream ifs(path,ios::in);
	string MNV,Ho,Ten,Phai,soHD,MVT;
	char loai;
	string ngay,thang,nam,soluong,dongia,vat;
	int vtr;
	HOADON hd;
	NODE_HOADON *q;
	CT_HOADON cthd;
	int n;
	if(ifs.fail())
	{
		return;
	}
	while(!ifs.eof())
	{
		getline(ifs,MNV);
		for(int i =0;i<dsnv.soLuongNV;i++)
		{
			if(strcmp(dsnv.nv[i].MaNV,MNV.c_str())==0)
			{
				vtr =i;
				break;
			}
		}
		getline(ifs,soHD,',');
		getline(ifs,ngay,',');
		getline(ifs,thang,',');
		getline(ifs,nam,',');
		ifs.get(loai);
		strcpy(hd.SoHD,soHD.c_str());
		hd.loai = loai;
		hd.date.ngay = atoi(ngay.c_str());
		hd.date.thang = atoi(thang.c_str());
		hd.date.nam = atoi(nam.c_str());
		hd.fisrtCT = NULL;
		dsnv.nv[vtr].fisrtHD = HoaDonAddTail(dsnv.nv[vtr].fisrtHD,HoaDonGetnode(hd));
		q = HoaDonSearch(soHD);
		ifs >> n;
		ifs.ignore();
		for(int i = 0;i<n;i++)
		{
			getline(ifs,MVT,'-');
			getline(ifs,soluong,'-');
			getline(ifs,dongia,'-');
			getline(ifs,vat);
			strcpy(cthd.MaVT,MVT.c_str());
			cthd.soluong = atoi(soluong.c_str());
			cthd.dongia = atoi(dongia.c_str());
			cthd.VAT = atoi(vat.c_str());
			q->data.fisrtCT = CT_HoaDonAddTail(q->data.fisrtCT,CT_HoaDonGetNode(cthd));
		}
	}
	ifs.close(); 
}
								// END
								// THONG KE HOA DON
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
	int soTK=0;
};
void TKHDXuat(THONGKE tk, int stt)
{
	int y =9+stt*2;
	gotoxy(arrToaDoBangThongKeHD[0]+2,y);
	cout << tk.SoHD;
	gotoxy(arrToaDoBangThongKeHD[1]+3,y);
	cout << tk.date.ngay << "/"<<tk.date.thang << "/" <<tk.date.nam;
	gotoxy(arrToaDoBangThongKeHD[2]+3,y);
	if(tk.Loai=='N')
	{
		cout << "Nhap";
	}
	else if(tk.Loai=='X')
	{
		cout <<"Xuat";
	}
	gotoxy(arrToaDoBangThongKeHD[3]+2,y);
	cout << tk.HoTenNV;
	gotoxy(arrToaDoBangThongKeHD[4]+2,y);
	cout << to_Currency(tk.donGia);
	gotoxy(arrToaDoBangThongKeHD[5]-4,y);
	cout << "VND";
}

void TKHDXuatDS(DS_THONGKE &l, int vitri=0)
{
	Nocursortype();
	int stt=0;
	for(int i = vitri;i < l.soTK;i++)
	{
		TKHDXuat(l.tk[i],stt);
		stt++;
		if(stt==14)
		{
			break;
		}
	}
}
void ContentRemoveTK()
{
	int y;
	for(int i =0; i< 14;i++)
	{
		y =9+i*2;
		gotoxy(arrToaDoBangThongKeHD[0]+1,y);
		cout << "                     ";
		gotoxy(arrToaDoBangThongKeHD[1]+1,y);
		cout << "                   ";
		gotoxy(arrToaDoBangThongKeHD[2]+1,y);
		cout << "         ";
		gotoxy(arrToaDoBangThongKeHD[3]+1,y);
		cout << "                         ";
		gotoxy(arrToaDoBangThongKeHD[4]+1,y);
		cout << "                       ";
	}
}
void TKHDXuLyDS(DS_THONGKE &dstk,Date &first, Date &final)
{
	int checkDate1,checkDate2;
	int donGia =0,kq;
	string name;
	for(int i =0;i < dsnv.soLuongNV;i++)
	{
		for(NODE_HOADON* p = dsnv.nv[i].fisrtHD; p!= NULL; p= p->pNext)
		{
			name ="";
			checkDate1 = LayThoiGianSoSanh(p->data.date,first);
			checkDate2 = LayThoiGianSoSanh(p->data.date,final);
			if((checkDate1 ==1|| checkDate1 ==0) && (checkDate2 == -1|| checkDate2 == 0))
			{
				name +=dsnv.nv[i].Ho;
				name+=" ";
				name+=dsnv.nv[i].Ten;
				strcpy(dstk.tk[dstk.soTK].SoHD, p->data.SoHD);
				dstk.tk[dstk.soTK].date = p->data.date;
				dstk.tk[dstk.soTK].Loai=p->data.loai;
				dstk.tk[dstk.soTK].HoTenNV = name;
				for(NODECT_HOADON* q =p->data.fisrtCT; q!=NULL; q=q->pNext)
				{
					kq = q->Data.soluong*q->Data.dongia+(q->Data.VAT/100)*q->Data.dongia;
					donGia +=kq;
				}
				dstk.tk[dstk.soTK].donGia = donGia;
				dstk.soTK++;
			}
		}
	}
}
void TKHDNgayNhap(Date &first, Date &final,int& exit)
{
	int xMapNgay =36,xMapThang =41,xMapNam=46;
	int xMapNgay2 = 69,xMapThang2=74,xMapNam2=79;
nhaplai:
	int flag =1;
	int check =0;
	int y=3;
	int vitri;
	int key,lengh,kq;
	string sngay,sthang,snam,sngay2,sthang2,snam2;
	gotoxy(36,y);
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
					if(first.nam < 2000 || first.nam > LayThoiGianNam())
					{
						
						while(!kbhit())
						 Canhbao("Nhap sai nam, nam phai be hon "+to_String(LayThoiGianNam())+".Xin nhap lai!",30,1);
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
					else if(final.nam < first.nam || final.nam > LayThoiGianNam())
					{
						while(!kbhit())
						 Canhbao("Nhap sai nam,nam phai be hon "+to_String(LayThoiGianNam())+".Xin nhap lai!",30,1);
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
				else if(flag ==2 && sthang.size() >=0)
				{
					if(sthang.size() == 0)
					{
						gotoxy(36+sngay.size(),y);
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
				else if(flag == 3&& snam.size() >=0)
				{
					if(snam.size()==0)
					{
						gotoxy(41+sthang.size(),y);
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
				if(flag ==4 && sngay2.size() >=0)
				{
					if(sngay2.size() ==0)
					{
						gotoxy(46+snam.size(),y);
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
				else if(flag ==5 && sthang2.size() >=0)
				{
					if(sthang2.size() ==0)
					{
						gotoxy(69+sngay2.size(),y);
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
				else if(flag == 6&& snam2.size() >=0)
				{
					if(snam2.size() ==0)
					{
						gotoxy(74+sthang2.size(),y);
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
void TKHDQuanLyXuat()
{
	DS_THONGKE dstk;
	string arrTuKhoa[] = { "So HD","Ngay Lap","Loai","Ho ten NV Lap","Don Gia" };
	dstk.soTK =0;
	Date first, final;
	int vitri =0,page=0, key;
	string name = "BANG LIET KE HOA DON TRONG KHOANG THOI GIAN";
	string name2 = "TU NGAY :    /    /     \t DEN NGAY :    /    /     ";
	if(HoaDonKiemtraTonTai()== 0)
	{
		veKhungTB("         Khong co hoa don");
		system("cls");
		return;
	}
	system("cls");
	textcolor(setMauTiTle);
	gotoxy(32, 2);
	cout << name;	
	gotoxy(26, 3);
	textcolor(7);
	cout << name2;
	int exit =0;
	TKHDNgayNhap(first,final,exit);
	if(exit ==1)
	{
		system("cls");
		return;
	}
	TKHDXuLyDS(dstk,first,final);
	if(dstk.soTK ==0)
	{
		veKhungTB("         Khong co du lieu");
		system("cls");
		return;
	}
	int total = (dstk.soTK%14==0 ? dstk.soTK/14 : dstk.soTK/14+1);
	textcolor(setMauTiTle);
	gotoxy(50,37);
	cout << page+1 << "/" <<  total;
	textcolor(7);
		veKhungThongKeHD(arrTuKhoa);
		TKHDXuatDS(dstk,vitri);
		while(true)
		{
			while(!kbhit())
			{
				textcolor(setMauTiTle);
				gotoxy(50,37);
				cout << page+1;
				textcolor(7);
				key = getch();
				if(key == 224)
				{
					key = getch();
					if(key == 75 && page >0)
					{
						page--;
						vitri-=14;
						ContentRemoveTK();
						TKHDXuatDS(dstk,vitri);
					}
					else if(key ==77 && page < total - 1)
					{
						page++;
						vitri+=14;
						ContentRemoveTK();
						TKHDXuatDS(dstk,vitri);
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
int HoaDonkiemtraXuat()
{
	for(int i = 0; i < dsnv.soLuongNV+1; i++)
	{
		for(NODE_HOADON* p= dsnv.nv[i].fisrtHD; p!=NULL; p = p->pNext)
		{
			if(p->data.loai=='X')
			{
				return 1;
			}
		}
	}
	return 0;
}
void DS10VTDoanhThu(Date &first, Date &final, int DT[][2],string MVT[],int &nArr)
{
	int dem = VatTuCountNode(t)+1;
	int dt[dem][2];
	string mvt[dem];
	int n;
	VatTuLNR(t,mvt,n);
	for(int a = 0; a < n; a++)
	{
		dt[a][0] = 0;
		dt[a][1] = 0;
	}
	int checkDate1,checkDate2;
	for(int i =0;i < dsnv.soLuongNV;i++)
	{
		for(NODE_HOADON* p = dsnv.nv[i].fisrtHD; p!= NULL; p= p->pNext)
		{
			checkDate1 = LayThoiGianSoSanh(p->data.date,first);
			checkDate2 = LayThoiGianSoSanh(p->data.date,final);
			if((checkDate1 ==1|| checkDate1 ==0) && (checkDate2 == -1|| checkDate2 == 0) && p->data.loai =='X')
			{
				for(NODECT_HOADON* q =p->data.fisrtCT; q!=NULL; q=q->pNext)
				{
					for(int j = 0; j < n; j++)
					{
						if( strcmp(q->Data.MaVT,mvt[j].c_str()) == 0)
						{
							dt[j][0] += q->Data.dongia*q->Data.soluong+q->Data.VAT/100*q->Data.dongia;
							dt[j][1] += q->Data.soluong;
						}
					}
				}
			}
		}
	}
	for(int i =0; i < dem;i++)
	{
		if(dt[i][0] > 0)
		{
			DT[nArr][0]=dt[i][0];
			DT[nArr][1]=dt[i][1];
			MVT[nArr] = mvt[i];
			nArr++;
		}
	}
}
int HoanDoiInt(int &a, int &b)
{
	int temp;
	temp =a;
	a = b;
	b = temp;
}
void DS10VTSort(int DT[][2], string MVT[], int &nArr)
{
	for(int i =0; i < nArr;i++)
	{
		for(int j = nArr-1; j > i; j--)
		{
			if((DT[j-1][0]) < (DT[j][0]))
			{
				HoanDoiString(MVT[j-1],MVT[j]);
				HoanDoiInt(DT[j-1][0],DT[j][0]);
				HoanDoiInt(DT[j-1][1],DT[j][1]);
			}
		}
	}
}
void DS10VTXuat(int DT[][2], string MVT[],int nArr)
{
	Nocursortype();
	int stt =0;
	int y;
	DS10VTSort(DT,MVT,nArr);
	for(int i = 0; i < nArr; i++)
	{
		if(i==10)
		{
			break;
		}
		y = 7+stt*2;
		veKhungKhuyet1(18,7+stt*2);
		veKhungKhuyet2(18,7+stt*2);
		gotoxy(20,7+stt*2);
		cout << MVT[i];
		gotoxy(35,y);
		cout << VatTuSearch(t,MVT[i])->Data.TenVT;
		gotoxy(57,y);
		cout << to_Currency(DT[i][0]);
		gotoxy(72,y);
		cout << "VND";
		gotoxy(79,y);
		cout << DT[i][1];
		stt++;
	}
}
void DS10VTQuanLyXuat()
{
	const int MAX = VatTuCountNode(t);
	int nArr=0;
	int DT[MAX][2];
	string MVT[MAX];
	if(HoaDonkiemtraXuat()== 0)
	{
		veKhungTB("      Chua xuat vat tu nao");
		system("cls");
		return;
	}
	Date first, final;
	string name = "BANG LIET KE VAT TU CO DOANH THU CAO TRONG KHOANG THOI GIAN";
	string name2 = "TU NGAY :    /    /     \t DEN NGAY :    /    /     ";
	system("cls");
	textcolor(setMauTiTle);
	gotoxy(26, 2);
	cout << name;
	gotoxy(26, 3);
	textcolor(7);
	cout << name2;
	int exit =0;
	TKHDNgayNhap(first,final,exit);
	if(exit ==1)
	{
		system("cls");
		return;
	}
	DS10VTDoanhThu(first,final,DT,MVT,nArr);
	if(nArr == 0)
	{
		veKhungTB("         Khong co du lieu");
		system("cls");
		return;
	}
	veKhungKQTimKiem("Ma Vat Tu","Ten Vat Tu","Doanh Thu","   SL");
	veKhungKhuyet1(18,7);
	veKhungKhuyet2(18,7);
	DS10VTXuat(DT,MVT,nArr);
	int key;
	while(true)
	{
		while(!kbhit())
		{
			key = getch();
			if(key == 27)
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
	string arrVT[6] ={"         Nhap vat tu         ","        Tim kiem vat tu      ","      Hieu chinh vat tu      ","          Xoa Vat tu         ","      In Danh Sach Vat Tu    "};
	veMenu(arrMenuVT,arrVT,5);
	int vitri=0;
	int key;
	while(true)
	{
			Nocursortype();
			veKhungHCN(yMapMN,arrMenuVT[vitri],arrVT[vitri],true);
			key = getch();
			if(key ==224)
			{
				key = getch();
				if(key == 80)
				{
					veKhungHCN(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
					vitri++;
					if(vitri==5)
					{
						vitri=0;
					}
				}
				else if(key == 72 && vitri >0)
				{
					veKhungHCN(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
					vitri--;
				}
			}
			else if(key == 0)
			{
				key =getch();
			}
			else if(key == 13)
			{
				veKhungHCN(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
				Yescursortype();
				switch(vitri)
				{
					case 0:
						VatTuNhap();
						break;
					case 1:
						VatTuTimKiem();
						break;
					case 2:
						VatTuHieuChinh();
						break;
					case 3:
						VatTuXoa();
						break;
					case 4:
						VatTuQuanLyXuat();
						break;
				}
				veMenu(arrMenuVT,arrVT,5);
			}
			else if(key == 27)
			{
				VatTuwriteToFile(t);
				system("cls");
				return;
			}
		}
}
void MenuNV()
{
	system("cls");
	string arrVT[6] ={"        Nhap nhan vien       ","       Tim kiem nhan vien    ","    Hieu Chinh Nhan Vien    ","         Xoa nhan vien       ","    In danh sach nhan vien   "};
	veMenu(arrMenuVT,arrVT,5);
	int vitri=0;
	int key;
	while(true)
	{

			Nocursortype();
			veKhungHCN(yMapMN,arrMenuVT[vitri],arrVT[vitri],true);
			key = getch();
			if(key ==224)
			{
				key = getch();
				if(key == 80)
				{
					veKhungHCN(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
					vitri++;
					if(vitri==5)
					{
						vitri=0;
					}
				}
				else if(key == 72 && vitri >0)
				{
					veKhungHCN(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
					vitri--;
				}
			}
			else if(key == 0)
			{
				key =getch();
			}
			else if(key == 13)
			{
				veKhungHCN(yMapMN,arrMenuVT[vitri],arrVT[vitri]);
				Yescursortype();
				switch(vitri)
				{
					case 0:
						NhanVienNhap();
						break;
					case 1:
						NhanVienTimKiem();
						break;
					case 2:
						NhanVienHieuChinh();
						break;
					case 3:
						NhanVienXoa();
						break;
					case 4:
						NhanVienQuanLyXuat();
						break;
				}
				veMenu(arrMenuVT,arrVT,5);
			}
			else if(key == 27)
			{
				system("cls");
				return;
			}
		}

}
void MenuHD()
{
	system("cls");
	string arrNameHD[6] ={"       Lap Hoa Don Nhap      ","       Lap Hoa Don Xuat      ","     In Hoa Don Theo SoHD    ","       Thong Ke Hoa Don      ","   10 VT Co Doanh Thu Nhat   ",};
	veMenu(arrMenuVT,arrNameHD,5);
	int vitri=0;
	int key;
	while(true)
	{
			Nocursortype();
			veKhungHCN(yMapMN,arrMenuVT[vitri],arrNameHD[vitri],true);
			key = getch();
			if(key ==224)
			{
				key = getch();
				if(key == 80)
				{
					veKhungHCN(yMapMN,arrMenuVT[vitri],arrNameHD[vitri]);
					vitri++;
					if(vitri==5)
					{
						vitri=0;
					}
				}
				else if(key == 72 && vitri >0)
				{	
					
					veKhungHCN(yMapMN,arrMenuVT[vitri],arrNameHD[vitri]);
					vitri--;
				}
			}
			else if(key == 0)
			{
				key =getch();
			}
			else if(key == 13)
			{
				veKhungHCN(yMapMN,arrMenuVT[vitri],arrNameHD[vitri]);
				Yescursortype();
				switch(vitri)
				{
					case 0:
						HoaDonThem(0);
						break;
					case 1:
						HoaDonThem(1);
						break;
					case 2:
						HoaDonXuatThongTin();
						break;
					case 3:
						TKHDQuanLyXuat();
						break;
					case 4:
						DS10VTQuanLyXuat();
				}
				veMenu(arrMenuVT,arrNameHD,5);
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
	string arrTuKhoa[4] = { "            Vat Tu           " ,"           Nhan vien         ","            Hoa don          ","             Thoat           "};
	veMenu(arrMenuVT,arrTuKhoa,4);
	int vitri =0;
	int key;
	int check =0;
	while(check ==0)
	{
			Nocursortype();
			veKhungHCN(yMapMN,arrMenuVT[vitri],arrTuKhoa[vitri],true);
			key = getch();
			if(key ==224)
			{
				key = getch();
				if(key == 80)
				{
					veKhungHCN(yMapMN,arrMenuVT[vitri],arrTuKhoa[vitri]);
					vitri++;
					if(vitri==4)
					{
						vitri=0;
					}
				}
				else if(key == 72&& vitri >0)
				{
					veKhungHCN(yMapMN,arrMenuVT[vitri],arrTuKhoa[vitri]);
					vitri--;
					
				}
			}
			else if(key == 0)
			{
				key =getch();
			}
			else if(key == 13)
			{
				veKhungHCN(yMapMN,arrMenuVT[vitri],arrTuKhoa[vitri]);
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
						MenuHD();
						break;
					case 3:
						if(veKhungYesNo("       Ban co muon thoat?",0))
						{
							system("cls");
							return;
						}
						else
						{
							system("cls");
							veMenu(arrMenuVT,arrTuKhoa,4);
							continue;
						}
						break;
				}
				veMenu(arrMenuVT,arrTuKhoa,4);
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
					veMenu(arrMenuVT,arrTuKhoa,4);
					continue;
				}
			}
		}
}
									// KET THUC
int main(){
	resizeConsole(800,700);
	VatTuInit(t);
	VatTureadFromFile();
	NhanVienreadFromFile();
	HoaDonreadFromFile();
	MenuChinh();
	getch();
}
