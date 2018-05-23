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
	int VAT;
};
struct NODECT_HOADON{
	CT_HOADON Data;
	NODECT_HOADON *pNext;
};
struct DSCT_HOADON{
	NODECT_HOADON * pHead;
	NODECT_HOADON* pTail;
};
typedef struct DSCT_HOADON DSCT;

struct HOADON{
	char SoHD[21];
	Date date;
	char loai[1];
	char MaNV[11];
	DSCT l;
};
struct NODE_HOADON{
	HOADON data;
	NODE_HOADON *pNext;
};
struct DS_HOADON{
	NODE_HOADON* pHead;
	NODE_HOADON* pTail;
};
typedef struct DS_HOADON DSHD;
struct NHANVIEN{
	string MaNV;
	string Ho;
	string Ten;
	string Phai;
	DSHD l;
};
struct DSNV
{
	NHANVIEN *nv= new NHANVIEN[MAXNV];
	int soLuongNV;
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
struct THONGKE
{
	char SoHD[21];
	Date date;
	char Loai[2];
	string HoTenNV;
	long donGia;
};
struct DS_THONGKE
{
	THONGKE *tk = new THONGKE[100];
	int soTK;
};
DS_THONGKE ds;
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
int yMapTh = 40; // 34 vi tri bang them hoac sua
int xMapTh = 3; //3 vi vi tri bang them hoac sua
//int xMapCN = 46;
//int yMapCN = 6;
int xMapTimKiem=68;
int yMapTimKiem=8;
// Ham ve giao dien chia vung
int arrGiaoDienChinh[4] ={1,40,100,145};
void veKhungGiaoDienChinh()
{
	int y = 2;
	
	gotoxy(arrGiaoDienChinh[0]+17,y+1);
	textcolor(10);
	cout << "MENU";
	gotoxy(arrGiaoDienChinh[3]-30,y+1);
	cout << "QUAN LY VAT TU";
	textcolor(7);
	textcolor(11);
	for(int j =y; j <= y+50;j++)
	{
		gotoxy(arrGiaoDienChinh[0],j);
		cout << (char)186;
		gotoxy(arrGiaoDienChinh[1],j);
		cout << char(186);
		gotoxy(arrGiaoDienChinh[3],j);
		cout << char(186);
		if(j < y +3)
		{
			gotoxy(arrGiaoDienChinh[2],j);
			cout << char(186);
		}
	}
	for(int i = arrGiaoDienChinh[0];i<=arrGiaoDienChinh[3];i++)
	{
		gotoxy(i,y);
		if(i == arrGiaoDienChinh[1] || i == arrGiaoDienChinh[2])
		{
			cout <<  (char)203;
		}
		else if (i == arrGiaoDienChinh[3])
		{
			cout << (char)187;
		}
		else if(i== arrGiaoDienChinh[0])
		{
			cout << (char)201;
		}
		else cout << (char)205;
		
		gotoxy(i,y+3);
		if(i ==arrGiaoDienChinh[1])
			cout << (char)206;
		else if(i == arrGiaoDienChinh[0])
			cout << (char)204;
		else if(i == arrGiaoDienChinh[2])
		cout << (char)202;
		else if(i == arrGiaoDienChinh[3])
			cout << (char)185;
		else 
			cout << (char)205;
		if(i <arrGiaoDienChinh[1])
		{
			gotoxy(i,y+30);
			if(i == arrGiaoDienChinh[0])
				cout << (char)204;
			else if(i == arrGiaoDienChinh[1])
				cout << (char)185;
				
			else cout << (char)205;
		}
			
		
		gotoxy(i, y + 50);
		if(i==arrGiaoDienChinh[1])
			cout << (char)202;
		else if(i == arrGiaoDienChinh[0])
			cout << (char)200;
		else if(i == arrGiaoDienChinh[3])
			cout << (char)188;
		else 
			cout << (char)205;
	}
	textcolor(7);
}
// ham ve bang xoa
void veOTimKiem(string name)
{
	for (int i = xMapTimKiem; i < xMapTimKiem + 50; i++)
	{
		for (int j = 0; j <= 2; j += 2)
		{
			gotoxy(i, yMapTimKiem + j);
			cout << char(205);
		}
	}
	for (int k = yMapTimKiem; k <= yMapTimKiem + 2; k++)
	{
		gotoxy(xMapTimKiem, k);
		if (k == yMapTimKiem)
		{
			cout << char(201);
		}
		else if (k == yMapTimKiem + 2)
		{
			cout << char(200);
		}
		else if (k % 2 == 0)
		{
			cout << char(204);
		}
		else
		{
			cout << char(186);
		}

		gotoxy(xMapTimKiem + 50, k);
		if (k == yMapTimKiem)
		{
			cout << char(187);
		}
		else if (k == yMapTimKiem + 2)
		{
			cout << char(188);
		}
		else if (k % 2 == 0)
		{
			cout << char(185);
		}
		else
		{
			cout << char(186);
		}

		gotoxy(xMapTimKiem + 20, k);
		if (k == yMapTimKiem)
		{
			cout << char(203);
		}
		else if (k == yMapTimKiem + 2)
		{
			cout << char(202);
		}
		else if (k % 2 == 0)
		{
			cout << char(206);
		}
		else
		{
			cout << char(186);
		}

	}
	gotoxy(xMapTimKiem + 2, yMapTimKiem + 1);
	textcolor(10);
	cout << name;
	textcolor(7);

}
// ham ve bang them hoac sua
void vebangThemMoi(string *arrTen,int n)
{
	for(int i = xMapTh; i < xMapTh + 35;i++)
	{
		for(int j =0;j <= n*2; j+=2)
		{
			gotoxy(i,yMapTh + j);
			cout << (char)205;
		}
	}
	for(int k = yMapTh;k <= yMapTh + n*2; k++)
	{
		gotoxy(xMapTh,k);
		if(k == yMapTh)
			cout << (char)201;
		else if(k== yMapTh +n*2)
			cout << (char)200;
		else if(k %2==0)
			cout << (char)204;
		else
			cout << (char)186;
		
		gotoxy(xMapTh + 34,k);
		if(k==yMapTh)
			cout << (char)187;
		else if(k== yMapTh + n*2)
			cout << (char)188;
		else if(k%2 ==0 )
			cout << (char)185;
		else 
			cout << (char)186;
			
		gotoxy(xMapTh+10,k);
		if(k == yMapTh)
			cout << (char)203;
		else if(k == yMapTh +n*2)
			cout << (char)202;
		else if(k%2 == 0)
			cout << (char)206;
		else
			cout << (char)186;
	}
	for(int i=0; i <=n;i++)
	{
		gotoxy(xMapTh+1,i*2+yMapTh+1);
		textcolor(10);
		cout << arrTen[i];
		textcolor(7);

	}
}
// ham ve button 
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
void vemenu(int *arr, string *arrTuKhoa, int n) //n: so chuc nang can show ra man hinh
{

	for (int i = 0; i < n; i++)
	{
		hcn(5, arr[i], arrTuKhoa[i]);
	}
}
int arrToaDoBangThongKeHD[6] ={ 45,63,83,90,120,140};
void veBangThongKeHD()
{
	string arrTuKhoa[] = { "So HD","Ngay Lap","Loai","Ho ten NV Lap","Don Gia" };
	for (int i = 0; i < 5; i++)
	{
		gotoxy(arrToaDoBangThongKeHD[i] + 1 + ((arrToaDoBangThongKeHD[i + 1] - arrToaDoBangThongKeHD[i] - arrTuKhoa[i].length()) / 2), yMap + 11);
		textcolor(10);
		cout << arrTuKhoa[i];
		textcolor(7);

	}
	for (int j = yMap + 10; j <= yMap + 40; j++)
	{
		gotoxy(arrToaDoBangThongKeHD[0], j);
		cout << char(186);
		gotoxy(arrToaDoBangThongKeHD[5], j);
		cout << char(186);
		gotoxy(arrToaDoBangThongKeHD[1], j);
		cout << char(186);
		gotoxy(arrToaDoBangThongKeHD[2], j);
		cout << char(186);
		gotoxy(arrToaDoBangThongKeHD[3], j);
		cout << char(186);
		gotoxy(arrToaDoBangThongKeHD[4], j);
		cout << char(186);
	}
	for (int i = arrToaDoBangThongKeHD[0]; i <= arrToaDoBangThongKeHD[5]; i++)
	{
		gotoxy(i, yMap + 10);
		if (i == arrToaDoBangThongKeHD[1] || i == arrToaDoBangThongKeHD[2] || i == arrToaDoBangThongKeHD[3] || i == arrToaDoBangThongKeHD[4])
			cout << char(203);
		else if (i == arrToaDoBangThongKeHD[0])
		{
			cout << char(201);
		}
		else if (i == arrToaDoBangThongKeHD[5])
		{
			cout << char(187);
		}

		else
		{
			cout << char(205);
		}
		gotoxy(i, yMap + 12);
		if (i == arrToaDoBangThongKeHD[1] || i == arrToaDoBangThongKeHD[2] || i == arrToaDoBangThongKeHD[3] || i == arrToaDoBangThongKeHD[4])
			cout << char(206);
		else if (i == arrToaDoBangThongKeHD[0])
		{
			cout << char(204);
		}
		else if (i == arrToaDoBangThongKeHD[5])
		{
			cout << char(185);
		}
		else
		{
			cout << char(205);
		}
		gotoxy(i, yMap + 40);
		if (i == arrToaDoBangThongKeHD[1] || i == arrToaDoBangThongKeHD[2] || i == arrToaDoBangThongKeHD[3] || i == arrToaDoBangThongKeHD[4])
			cout << char(202);
		else if (i == arrToaDoBangThongKeHD[0])
			cout << char(200);
		else if (i == arrToaDoBangThongKeHD[5])
		{
			cout << char(188);
		}
		else
		{
			cout << char(205);
		}
	}
}
int arrDSHD[]={56,64,90,116,129,142};
void veBangDSHD()
{
	string arrTuKhoa[] = { "STT","So HD","Ngay Lap","Loai"};
	for (int i = 0; i < 4; i++)
	{
		gotoxy(arrDSHD[i] + 1 + ((arrDSHD[i + 1] - arrDSHD[i] - arrTuKhoa[i].length()) / 2), yMap + 11);
		textcolor(10);
		cout << arrTuKhoa[i];
		textcolor(7);

	}
	for (int j = yMap + 10; j <= yMap + 45; j++)
	{
		gotoxy(arrDSHD[0], j);
		cout << char(186);
		gotoxy(arrDSHD[1], j);
		cout << char(186);
		gotoxy(arrDSHD[2], j);
		cout << char(186);
		gotoxy(arrDSHD[3], j);
		cout << char(186);
		gotoxy(arrDSHD[4], j);
		cout << char(186);
	}
	for (int i = arrDSHD[0]; i <= arrDSHD[4]; i++)
	{
		gotoxy(i, yMap + 10);
		if (i == arrDSHD[1] || i == arrDSHD[2] || i == arrDSHD[3])
			cout << char(203);
		else if (i == arrDSHD[0])
		{
			cout << char(201);
		}
		else if (i == arrDSHD[4])
		{
			cout << char(187);
		}

		else
		{
			cout << char(205);
		}
		gotoxy(i, yMap + 12);
		if (i == arrDSHD[1] || i == arrDSHD[2] || i == arrDSHD[3])
			cout << char(206);
		else if (i == arrDSHD[0])
		{
			cout << char(204);
		}
		else if (i == arrDSHD[4])
		{
			cout << char(185);
		}
		else
		{
			cout << char(205);
		}
		gotoxy(i, yMap + 45);
		if (i == arrDSHD[1] || i == arrDSHD[2] || i == arrDSHD[3])
			cout << char(202);
		else if (i == arrDSHD[0])
			cout << char(200);
		else if (i == arrDSHD[4])
		{
			cout << char(188);
		}
		else
		{
			cout << char(205);
		}
	}
}
int arrToaDoBangNhapCTHD[8] ={ 44,50,68,90,100,110,130,140};
void veBangNhapCT_HD()
{
	string arrTuKhoa[] = { "STT","Ma VT","Ten VT","DVT","So luong","Don gia","VAT" };
	for (int i = 0; i < 7; i++)
	{
		gotoxy(arrToaDoBangNhapCTHD[i] + 1 + ((arrToaDoBangNhapCTHD[i + 1] - arrToaDoBangNhapCTHD[i] - arrTuKhoa[i].length()) / 2), yMap + 11);
		textcolor(10);
		cout << arrTuKhoa[i];
		textcolor(7);
	}
	for (int j = yMap + 10; j <= yMap + 40; j++)
	{
		gotoxy(arrToaDoBangNhapCTHD[0], j);
		cout << char(186);
		gotoxy(arrToaDoBangNhapCTHD[6], j);
		cout << char(186);
		gotoxy(arrToaDoBangNhapCTHD[7], j);
		cout << char(186);
		gotoxy(arrToaDoBangNhapCTHD[5], j);
		cout << char(186);
		gotoxy(arrToaDoBangNhapCTHD[1], j);
		cout << char(186);
		gotoxy(arrToaDoBangNhapCTHD[2], j);
		cout << char(186);
		gotoxy(arrToaDoBangNhapCTHD[3], j);
		cout << char(186);
		gotoxy(arrToaDoBangNhapCTHD[4], j);
		cout << char(186);
	}
	for (int i = arrToaDoBangNhapCTHD[0]; i <= arrToaDoBangNhapCTHD[7]; i++)
	{
		gotoxy(i, yMap + 10);
		if (i == arrToaDoBangNhapCTHD[1] || i == arrToaDoBangNhapCTHD[2] || i == arrToaDoBangNhapCTHD[3] || i == arrToaDoBangNhapCTHD[4] || i == arrToaDoBangNhapCTHD[5]|| i == arrToaDoBangNhapCTHD[6])
			cout << char(203);
		else if (i == arrToaDoBangNhapCTHD[0])
		{
			cout << char(201);
		}
		else if (i == arrToaDoBangNhapCTHD[7])
		{
			cout << char(187);
		}

		else
		{
			cout << char(205);
		}
		gotoxy(i, yMap + 12);
		if (i == arrToaDoBangNhapCTHD[1] || i == arrToaDoBangNhapCTHD[2] || i == arrToaDoBangNhapCTHD[3] || i == arrToaDoBangNhapCTHD[4] || i == arrToaDoBangNhapCTHD[5]|| i == arrToaDoBangNhapCTHD[6])
			cout << char(206);
		else if (i == arrToaDoBangNhapCTHD[0])
		{
			cout << char(204);
		}
		else if (i == arrToaDoBangNhapCTHD[7])
		{
			cout << char(185);
		}
		else
		{
			cout << char(205);
		}
		gotoxy(i, yMap + 40);
		if (i == arrToaDoBangNhapCTHD[1] || i == arrToaDoBangNhapCTHD[2] || i == arrToaDoBangNhapCTHD[3] || i == arrToaDoBangNhapCTHD[4] || i == arrToaDoBangNhapCTHD[5]|| i == arrToaDoBangNhapCTHD[6])
			cout << char(202);
		else if (i == arrToaDoBangNhapCTHD[0])
			cout << char(200);
		else if (i == arrToaDoBangNhapCTHD[7])
		{
			cout << char(188);
		}
		else
		{
			cout << char(205);
		}
	}
}
// ham ve o hien thi ngay
void vegiaodienngay(int x, int y)
{
	for (int i = 0; i < 25; i++)
	{
		gotoxy(x + i, y);
		if (i == 0)
		{
			cout << (char)201;
		}
		else if (i == 24)
		{
			cout << (char)187;
		}
		else
		{
			cout << (char)205;
		}
		gotoxy(x + i, y + 2);
		if (i == 0)
		{
			cout << (char)200;
		}
		else if (i == 24)
		{
			cout << (char)188;
		}
		else
		{
			cout << (char)205;
		}
	}
	textcolor(10);
	string name="Ngay:    /    /";	
	textcolor(7);
	gotoxy(x, y + 1);
	cout << (char)186;
	gotoxy(x + 24, y + 1);
	cout << (char)186;
	gotoxy(x+2, y + 1);
	cout << name;
}
void KhungThongBaoXN(string str) //xac nhan
{
	for(int i = 0; i < 7; i++)
	{
		gotoxy(34, 7+i);
		cout << "                                 ";
	}
	gotoxy(34, 7);
	cout << char(218);
	for(int i = 0; i < 32; i++)
		cout << char(196);
	cout << char(191);
	for(int i = 0; i < 5; i++)
	{
		gotoxy(34, 8 + i);
		cout << char(179);
		gotoxy(67, 8 + i);
		cout << char(179);
	}
	gotoxy(34, 13);
	cout << char(192);
	for(int i = 0; i < 32; i++)
		cout << char(196);
	cout << char(217);
	
	gotoxy(35, 9);
	cout << str;
	gotoxy(50, 11);
	textcolor(42);
	cout << "OK";
	textcolor(10);
	getch();
}
// Ham ve bang hien thi detail dung cho vat tu nhan vien
int arrToaDoBangChiTet[5] = { 50,72,100,114,134 };
void veBangChiTiet(string *arrTenCot, string tenBang, int x =0)
{ 
	
	yMap = yMap + x;
	gotoxy(arrToaDoBangChiTet[2] -22,yMap -3);
	cout << tenBang; // in ten bang
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
		cout << (char)186;
		gotoxy(arrToaDoBangChiTet[4],j);
		cout << (char)186;
		if(j<yMap+30)
		{
			gotoxy(arrToaDoBangChiTet[1], j);
			cout << (char)186;
			gotoxy(arrToaDoBangChiTet[2], j);
			cout << (char)186;
			gotoxy(arrToaDoBangChiTet[3], j);
			cout << (char)186;
		}
	}
	// ket thuc in thanh doc
	for(int i = arrToaDoBangChiTet[0]; i <= arrToaDoBangChiTet[4];i++)
	{
		// in cac khop noi giua thnah ngang va doc
		gotoxy(i,yMap);
		if(i==arrToaDoBangChiTet[1] || i == arrToaDoBangChiTet[2] || i == arrToaDoBangChiTet[3])
			cout << (char)203; 
		
		else if(i == arrToaDoBangChiTet[0])
			cout << (char)201; 
		
		else if(i == arrToaDoBangChiTet[4])
			cout << (char)187; 
		
		else cout << (char)205;
		
		// ket thuc
		
		// in thanh ngang tren
		gotoxy(i,yMap+2);
		if(i == arrToaDoBangChiTet[1] || i == arrToaDoBangChiTet[2] || i ==arrToaDoBangChiTet[3])
			cout << (char)206;
	
		else if(i == arrToaDoBangChiTet[0])
			cout << (char)204;
			
		else if(i == arrToaDoBangChiTet[4])
			cout << (char)185;
		else
			cout << (char)205;
		// in thanh ngang duoi
		gotoxy(i,yMap + 30);
		if (i == arrToaDoBangChiTet[1] || i == arrToaDoBangChiTet[2] || i == arrToaDoBangChiTet[3])
			cout << (char)202;
		else if (i == arrToaDoBangChiTet[0])
			cout << (char)204;

		else if (i == arrToaDoBangChiTet[4])
		{
			cout << (char)185;
		}
		else
		{
			cout << (char)205;
		}
		gotoxy(i, yMap + 32);

		if (i == arrToaDoBangChiTet[0])
		{
			cout << (char)200;
		}
		else if (i == arrToaDoBangChiTet[4])
		{
			cout << (char)188;
		}
		else
		{
			cout << (char)205;
		}
		gotoxy(arrToaDoBangChiTet[0] + 1, yMap + 31);
		cout << " <--Truoc                                                                   Sau-->";
		Nocursortype();
	}
}
// Xoa
string xoa="                                    ";
void xoaNoiDungTrongKhungThem()
{
	for(int i = 0;i<15;i++)
	{
		gotoxy(xMapTh,yMapTh-5+i);
		cout << xoa;
	}
}
void xoaMenu()
{
	int ytam =6;
	for(int i =0;i<24;i++)
	{
		gotoxy(3,ytam+i);
		cout << xoa;
	}
}
string xoa1="                                                                                                  ";
void XoaOMain()
{
	int y =6;
	for(int i =0;i<44;i++)
	{
		gotoxy(42,y+i);
		cout << xoa1;
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
int Ktra_Trung_MaNV(int i)
{
	for(int j=0;dsnv.nv[j].MaNV!="";j++)
		if(dsnv.nv[j].MaNV==dsnv.nv[i].MaNV && j!=i)
			return false;
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
int lenghSo(int n){
	return (int)log10(n) +1;
}

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
	Tree p = new NODE_VATTU;
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
string  arrMaVT[500]; // chua ma vat tu tam de so kiem tra trung ma
int soVT =0;
void LNR(Tree &t)
{
	if(t != NULL)
	{
		LNR(t->pLeft);
		arrMaVT[soVT++] = t->Data.MaVT;
		LNR(t->pRight);
	}
}
int kiemTraTrungMaVT(string maVT)
{
	for(int i =0;i< soVT;i++)
	{
		if(arrMaVT[i] == maVT)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
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
void nhapVatTu(VATTU &data)
{
	string maVT, tenVT,dvt;
	BOOL ischeck=false;
	int vitri, key;
	int flag =0;
	int loop=0,i=1;
	gotoxy(xMapTh+12,yMapTh+i);
	while(loop ==0)
	{
		while(!kbhit())
		{
			
			if(flag ==0) vitri = xMapTh+12+maVT.length();
			else if(flag == 1) vitri = xMapTh +12+tenVT.length();
			else if(flag ==2) vitri = xMapTh +12+dvt.length();
			key =getch();
			if(key == 0)
			{
				key == getch();
			}
			else if(key == 27)
			{
				loop =1;
				break;
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90) || key == 32)
			{
				if(flag == 0 && maVT.size()<10 && key !=32)
				{
					gotoxy(vitri,yMapTh+i);
					if(key >=97 && key <=122)
						key = key -32;
					cout << (char)key;
					maVT.insert(maVT.end(),1,(char)key);
				}
				else if(flag ==1 && tenVT.size() < 20)
				{
					gotoxy(vitri,yMapTh+i);
					if((key >=97 && key <=122)&& (vitri-(xMapTh+12) ==0))
						key = key -32;
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
					gotoxy(vitri,yMapTh+i);
					if((key >=97 && key <=122)&& (vitri-(xMapTh+12) ==0))
						key = key -32;
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
							Canhbao("Khong duoc de trong.Xin nhap lai!!",46,3);
						do{
							int key1 = getch();
							
						}while(key!=13&&key!=27);
						gotoxy(vitri,yMapTh+i);
					}
					else if(kiemTraDoDaiMaVT(maVT) == false)
					{
						while(!kbhit())
						{
							Canhbao("Do dai ma vat tu phai la 10 ky tu.Xin nhap lai",46,3);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=27);
						gotoxy(vitri,yMapTh+i);
					}
					else if(kiemTraTrungMaVT(maVT) == true)
					{
							while(!kbhit())
						{
							Canhbao("Ma "+maVT+" da ton tai trong he thong.Xin nhap lai",46,3);
						}
						do{
							int key1 = getch();
						}while(key!=13&&key!=27);
						gotoxy(vitri,yMapTh+i);
					}
					else
					{
						i=3;
						gotoxy(xMapTh+12,yMapTh+i);
						flag =1;
					}
				}
				else if(flag ==1)
				{
					if(tenVT.size() ==0)
					{
						while(!kbhit())
							Canhbao("Khong duoc de trong.Xin nhap lai!!",46,3);
						do{
							int key1 = getch();
							
						}while(key!=13&&key!=27);
						gotoxy(vitri,yMapTh+i);
					}
					else
					{
						
						i=5;
						gotoxy(xMapTh+12,yMapTh+i);
						flag =2;
					}
				}
				else if(flag ==2)
				{
					if(dvt.size() ==0)
					{
						while(!kbhit())
							Canhbao("Khong duoc de trong.Xin nhap lai!!",46,3);
						do{
							int key1 = getch();
							
						}while(key!=13&&key!=27);
						gotoxy(vitri,yMapTh+i);
					}
					else
					{
						strcpy(data.MaVT,maVT.c_str());
						strcpy(data.TenVT,tenVT.c_str());
						strcpy(data.DVT,dvt.c_str());
						data.SoLuongTon =0;
						loop =1;
						break;	   
					}
				}
				
			}
			else if(key ==8)
			{
				if(flag ==0 && maVT.size() > 0)
				{
					vitri--;
					gotoxy(vitri,yMapTh+i);
					cout << " ";
					gotoxy(vitri,yMapTh+i);
					maVT.erase(maVT.end()-1);
				}
				else if(flag ==1 && tenVT.size() >0)
				{
					vitri--;
					gotoxy(vitri,yMapTh+i);
					cout << " ";
					gotoxy(vitri,yMapTh+i);
					tenVT.erase(tenVT.end()-1);
				}
				else if(flag ==2&&dvt.size()>0)
				{
					vitri--;
					gotoxy(vitri,yMapTh+i);
					cout << " ";
					gotoxy(vitri,yMapTh+i);
					dvt.erase(dvt.end()-1);
				}
			}
		}
	}
	if(loop == 1) return;
}
void themVatTu(Tree &t)
{
	string arr[4] ={"Ma VT", "Ten VT", "DVT"};
	vebangThemMoi(arr,3);
	LNR(t);
	VATTU data;
	nhapVatTu(data);
	Insert(t,data);
}

void xuatVattu(VATTU data,int stt)
{
	gotoxy(57,3+yMap +stt*2);
	cout << data.MaVT;
	gotoxy(72+1+((28-string(data.TenVT).size())/2),3+yMap +stt*2);
	cout << data.TenVT;
	gotoxy(100+1+((14-string(data.DVT).size())/2),3+yMap +stt*2);
	cout << data.DVT;
	gotoxy(114+1+((20-to_String(data.SoLuongTon).size())/2),3+yMap +stt*2);
	cout << data.SoLuongTon;
}
void xoaNodeVT(Tree &t, string maVT, int &dem)
{
	if(t == NULL)
	{
		Canhbao("Khong co vat tu nao trong kho!!!!",46,3);
		getch();
		system("Pause");
        return ;
	}
   if(strcmp(t->Data.MaVT,maVT.c_str())== 1)
	{
		xoaNodeVT(t->pLeft,maVT,dem);
	}
	else if(strcmp(t->Data.MaVT,maVT.c_str())== -1)
	{
		xoaNodeVT(t->pRight,maVT,dem);
	}
	else
	{
		gotoxy(xMapTimKiem,yMapTimKiem+5);
		cout << "Ban Co chac cha muon xoa vat tu co ma so " << t->Data.MaVT << " khong? (Y/N)";
		while(!kbhit())
		{
			int key = getch();
			if(key == 81 || key ==121)
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
				dem--;
				delete p;
				return;
			}
			else if(key == 78 || key == 110)
			{
				return;
			}
		}
	}
}
void xuatDanhSachVT(Tree t,int page)
{
	if(t == NULL)
	{
		Canhbao("Khong co vat tu nao trong kho",46,3);
		//KhungThongBaoXN("          Kho vat tu trong");
		system("Pause");
        return ;
	}
	Nocursortype();
	string arr[4] ={"Ma vat tu", "Ten vat tu", "Don vi tinh","So luong ton"};
	string name ="BANG DANH SACH VAT TU CO TRONG KHO";
	veBangChiTiet(arr,name,10);
	int k =0;
	for(int i = page * 14; i < (soVT > (page + 1) * 14 ? 14 : soVT) ;i++)
	{
		NODE_VATTU *p = new NODE_VATTU;
		p = Search(t,arrMaVT[i]);
		xuatVattu(p->Data,k++);
	}
}
void quanLysangTrangVT(Tree t)
{
	int page =0,i=0,vitri;
	int key;
	xuatDanhSachVT(t,page);
	while(true)
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
					i = page*12;
					vitri =0;
					break;
				}
				else if(key == 77 && page < (soVT%14 ==0? (soVT /14) : (soVT / 14) +1) -1)
				{
					page++;
					vitri =0;
					i = page *12;
					break;
				}
			}
			else if(key == 27)
			{
				return;
			}

	}
}
void xoaVatTu(Tree &t,int &dem)
{
	if(t==NULL)
	{
		Canhbao("Khong co vat tu nao trong kho!",46,3);
		system("Pause");
        return ;
	}

     veOTimKiem("Ma Vat tu");
     LNR(t);
		string mavt;
		int loop =1;
		int key,vitri;
		while(loop ==1)
		{
			while(!kbhit())
			{
				vitri = xMapTimKiem+23+mavt.size();
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
		 				gotoxy(vitri,yMapTimKiem+1);
						if(key >=97 && key <=122)
							key = key -32;
						cout << (char)key;
						mavt.insert(mavt.end(),1,(char)key);
				   }
				}
				else if(key ==13)
				{
					if(kiemTraTrungMaVT(mavt) == false)
					{
						while(!kbhit())
							Canhbao("Khong tim thay ma vat tu "+mavt+".Xin kiem tra lai!!",45,3);
						do{
							int key1 = getch();
						}while(key!=13);
						gotoxy(vitri,yMapTimKiem+1);
					}
					else
					{
						loop =0;
						break;
					}
				}
				else if(key == 8 && mavt.length() >0)
				{
					vitri--;
					gotoxy(vitri,yMapTimKiem+1);
					cout << " ";
					gotoxy(vitri,yMapTimKiem+1);
					mavt.erase(mavt.end()-1);
				}
			}
		}
		xoaNodeVT(t,mavt,dem);
}
void timKiemVT(Tree &t,int &dem)
{
	if(t==NULL)
	{
		Canhbao("Khong co vat tu nao trong kho!",46,3);
		system("Pause");
        return;
	}
		veOTimKiem("Ma Vat tu");
		LNR(t);
		string mavt;
		int loop =1;
		int key,vitri;
		while(loop ==1)
		{
			while(!kbhit())
			{
				vitri = xMapTimKiem+23+mavt.size();
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
		 				gotoxy(vitri,yMapTimKiem+1);
						if(key >=97 && key <=122)
							key = key -32;
						cout << (char)key;
						mavt.insert(mavt.end(),1,(char)key);
				   }
				}
				else if(key ==13)
				{
					if(kiemTraTrungMaVT(mavt) == false)
					{
						while(!kbhit())
							Canhbao("Khong tim thay ma vat tu "+mavt+".Xin kiem tra lai!!",45,3);
						do{
							int key1 = getch();
						}while(key!=13);
						gotoxy(vitri,yMapTimKiem+1);
					}
					else
					{
						loop =0;
						break;
					}
				}
				else if(key == 8 && mavt.length() >0)
				{
					vitri--;
					gotoxy(vitri,yMapTimKiem+1);
					cout << " ";
					gotoxy(vitri,yMapTimKiem+1);
					mavt.erase(mavt.end()-1);
				}
			}
		}
		if(loop==0)
		{
			NODE_VATTU* p = Search(t,mavt);
			string arr[]={"Ma VT","Ten VT","DVT","So luong ton"};
			
			veBangChiTiet(arr,"THONG TIN CHI TIET VAT TU VUA TIM",12);
			gotoxy(arrToaDoBangChiTet[0]+1,3+yMap);
			cout << p->Data.MaVT;
			gotoxy(arrToaDoBangChiTet[1]+1,3+yMap);
			cout << p->Data.TenVT;
			gotoxy(arrToaDoBangChiTet[2]+1,3+yMap);
			cout << p->Data.DVT;
			gotoxy(arrToaDoBangChiTet[3]+1,3+yMap);
			cout << p->Data.SoLuongTon;
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
void hieuChinhVatTu(Tree &t)
{
	if(t==NULL)
	{
		Canhbao("Khong co vat tu nao trong kho!",46,3);
		system("Pause");
        return ;
	}
	veOTimKiem("Ma Vat tu");
	string mavt;
	LNR(t);
	int loop =0;
	int key,vitri;
	while(loop ==0)
	{
		while(!kbhit())
		{
			vitri = xMapTimKiem+23+mavt.size();
			key =getch();
			if(key ==27)
			{
				loop =2;
				break;
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
			{
				if(mavt.length()  <10)
				{
		 			gotoxy(vitri,yMapTimKiem+1);
					if(key >=97 && key <=122)
						key = key -32;
					cout << (char)key;
					mavt.insert(mavt.end(),1,(char)key);
				}
			}
			else if(key ==13)
			{
				if(kiemTraTrungMaVT(mavt) == false)
				{
					while(!kbhit())
						Canhbao("Khong tim thay ma vat tu "+mavt+".Xin kiem tra lai!!",45,3);
					do{
						int key1 = getch();
					}while(key!=13);
					gotoxy(vitri,yMapTimKiem+1);
				}
				else
				{
					loop =1;
					break;
				}
			}
			else if(key == 8 && mavt.length() >0)
			{
				vitri--;
				gotoxy(vitri,yMapTimKiem+1);
				cout << " ";
				gotoxy(vitri,yMapTimKiem+1);
				mavt.erase(mavt.end()-1);
			}
		}
	}
	if(loop ==2) return;
	else if(loop==1)
		{
			
			NODE_VATTU* p = Search(t,mavt);
			string tenvt= p->Data.TenVT,dvt=p->Data.DVT;
			string arr[]={"Ma VT","Ten VT","DVT"};
			vebangThemMoi(arr,3);
			gotoxy(xMapTh+12,1+yMapTh);
			cout << mavt;
			gotoxy(xMapTh+12,3+yMapTh);
			cout << tenvt;
			gotoxy(xMapTh+12,5+yMapTh);
			cout << dvt;
			int key, vitri;
			int flag =1;
			int loop =0;
			int i =1;
			while(loop ==0)
			{
				while(!kbhit())
				{
					if(flag ==1) vitri =xMapTh +12+mavt.size();
					else if(flag ==2) vitri = xMapTh+12+tenvt.size();
					else if(flag ==3) vitri = xMapTh +12+dvt.size();
					if(key == 0)
					{
						key = getch();
					}
					if(key == 27)
					{
						loop =1;
						return;
					}
					else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
					{
						if(flag == 1 && mavt.size()<10)
						{
							gotoxy(vitri,yMapTh+i);
							if(key >=97 && key <=122)
								key = key -32;
							cout << (char)key;
							mavt.insert(mavt.end(),1,(char)key);
						}
						else if(flag ==2 && tenvt.size() < 30)
						{
							gotoxy(vitri,yMapTh+i);
							if((key >=97 && key <=122)&& (vitri-(xMapTh+12) ==1))
								key = key -32;
							else
							{
								if(key >=65 && key <=90)
								{
									key = key +32;
								}
							}
							cout << (char)key;
							tenvt.insert(tenvt.end(),1,(char)key);
						}
						else if(flag ==3 && dvt.size() <8)
						{
							gotoxy(vitri,yMapTh+i);
							if((key >=97 && key <=122)&& (vitri-(xMapTh+12) ==1))
								key = key -32;
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
					else if(key ==8)
					{
						if(flag ==1 && mavt.size() > 0)
						{
							vitri--;
							gotoxy(vitri,yMapTh+i);
							cout << " ";
							gotoxy(vitri,yMapTh+i);
							mavt.erase(mavt.end()-1);
						}
						else if(flag ==2 && tenvt.size() >0)
						{
							vitri--;
							gotoxy(vitri,yMapTh+i);
							cout << " ";
							gotoxy(vitri,yMapTh+i);
							tenvt.erase(tenvt.end()-1);
						}
						else if(flag ==3&&dvt.size()>0)
						{
							vitri--;
							gotoxy(vitri,yMapTh+i);
							cout << " ";
							gotoxy(vitri,yMapTh+i);
							dvt.erase(dvt.end()-1);
						}
					}
					else if(key ==13 || key ==9)
					{
						if(flag ==1)
						{
							if(mavt.size() ==0)
							{
								mavt = p->Data.MaVT;
							}
							else if(kiemTraDoDaiMaVT(mavt) == false)
							{
								while(!kbhit())
								{
									Canhbao("Do dai ma vat tu phai la 10 ky tu.Xin nhap lai",46,3);
								}
								do{
									int key1 = getch();
								}while(key!=13&&key!=27);
								gotoxy(vitri,yMapTh+i);
							}
							else if(kiemTraTrungMaVT(mavt) == true)
							{
								while(!kbhit())
								{
									Canhbao("Ma "+mavt+" da ton tai trong he thong.Xin nhap lai",46,3);
								}
								do{
									int key1 = getch();
								}while(key!=13&&key!=27);
								gotoxy(vitri,yMapTh+i);
							}
							else
							{
								i=3;
								gotoxy(xMapTh+12,yMapTh+i);
								flag =1;
							}
						}
						else if(flag ==2)
						{
							if(tenvt.size() ==0)
							{
								tenvt= p->Data.TenVT;
							}
							else
							{
								i=5;
								gotoxy(xMapTh+12,yMapTh+i);
								flag =2;
							}
						}
						else if(flag ==3)
						{
							if(dvt.size() ==0)
							{
								dvt = p->Data.DVT;
							}
							else
							{
								strcpy(p->Data.MaVT,mavt.c_str());
								strcpy(p->Data.TenVT,tenvt.c_str());
								strcpy(p->Data.DVT,dvt.c_str());
								p->Data.SoLuongTon =0;
								loop =1;
								break;	   
							}
						}
					}
				}
			}
			if(loop ==1) return;
		}
	}

void XuatDanhSach10VT(Tree t)
{
	if(t == NULL)
	{
		Canhbao("Khong co vat tu nao trong kho.",46,3);
		system("PAUSE");
		return;
	}
	string maVT[500];
	string arr[]={"Ma VT","Ten VT","DVT","So luong ton"};
	veBangChiTiet(arr,"DANH SACH 10 VAT TU CO TAN SUAT CAO",10);
	int vitri, dem = 0,max;
	int tham[500] ={0};
	while(dem < countNode(t))
	{
		for(int i =0;i<countNode(t);i++)
		{
			if(tham[i]==0)
			{
					
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
void nhapNhanVien()
{
	string arr[5]={"Ma NV","Ho","Ten","Phai"};
	vebangThemMoi(arr,4);
	Yescursortype();
	int i =dsnv.soLuongNV;
	dsnv.nv[i].MaNV ="";
	dsnv.nv[i].Ho="";
	dsnv.nv[i].Ten="";
	dsnv.nv[i].Phai="";
	int flag=1;
	int loop =0;
	int vitri,key;
	gotoxy(xMapTh+12,yMapTh+1);
	while(loop ==0)
	{
		while(!kbhit())
		{
			if(flag ==1)
			{	
				vitri=xMapTh+12+dsnv.nv[i].MaNV.size();
			}
			else if(flag ==2)
			{	
				vitri=xMapTh+12+dsnv.nv[i].Ho.size();
			}
			else if(flag ==3)
			{	
				vitri=xMapTh+12+dsnv.nv[i].Ten.size();
			}
			else if(flag ==4)
			{	
				vitri=xMapTh+12+dsnv.nv[i].Phai.size();
			}
			key = getch();
			if(key == 27)
			{
				loop =1;
				break;
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90) || key == 32)
			{
				if(flag == 1 && dsnv.nv[i].MaNV.size()<10 && key !=32)
				{
					gotoxy(vitri,yMapTh+1);
					if(key >=97 && key <=122)
						key = key -32;
					cout << (char)key;
					dsnv.nv[i].MaNV.insert(dsnv.nv[i].MaNV.end(),1,(char)key);
				}
				else if(flag ==2 && dsnv.nv[i].Ho.size() < 20)
				{
					gotoxy(vitri,yMapTh+3);
					if((key >=97 && key <=122)&& (vitri-(xMapTh+12) ==0))
						key = key -32;
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << (char)key;
					dsnv.nv[i].Ho.insert(dsnv.nv[i].Ho.end(),1,(char)key);	
				}
				else if(flag ==3 && dsnv.nv[i].Ten.size() < 20)
				{
					gotoxy(vitri,yMapTh+5);
					if((key >=97 && key <=122)&& (vitri-(xMapTh+12) ==0))
						key = key -32;
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << (char)key;
					dsnv.nv[i].Ten.insert(dsnv.nv[i].Ten.end(),1,(char)key);	
				}
				else if(flag ==4 && dsnv.nv[i].Phai.size() < 3)
				{
					gotoxy(vitri,yMapTh+7);
					if((key >=97 && key <=122)&& (vitri-(xMapTh+12) ==0))
						key = key -32;
					else
					{
						if(key >=65 && key <=90)
						{
							key = key +32;
						}
					}
					cout << (char)key;
					dsnv.nv[i].Phai.insert(dsnv.nv[i].Phai.end(),1,(char)key);
				}
			}
			else if(key ==13||key ==9)
			{
				if(flag ==1)
				{
					if(dsnv.nv[i].MaNV.size()<10)
					{
						while(!kbhit())
						{
							Canhbao("Do dai ma nhan vien pham la 10 ki tu",46,3);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,xMapTh+1);
					}
					else if(Ktra_Trung_MaNV(i)==false)
					{
						while(!kbhit())
						{
							Canhbao("Ma "+string(dsnv.nv[i].MaNV)+" da ton tai.Xin nhap lai!",46,3);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,xMapTh+1);
					}
					else
					{
						gotoxy(xMapTh+12,yMapTh+3);
						flag =2;
					}
				}
				else if(flag ==2)
				{
					if(dsnv.nv[i].Ho.size()==0)
					{
						while(!kbhit())
						{
							Canhbao("Khong duoc de trong.Xin nhap lai!",46,3);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,xMapTh+3);
					}
					else
					{
						gotoxy(xMapTh+12,yMapTh+5);
						flag =3;
					}
				}
				else if(flag ==3)
				{
					if(dsnv.nv[i].Ten.size()==0)
					{
						while(!kbhit())
						{
							Canhbao("Khong duoc de trong.Xin nhap lai!",46,3);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,xMapTh+5);
					}
					else
					{
						gotoxy(xMapTh+12,yMapTh+7);
						flag =4;
					}
					
				}
				else if(flag ==4)
				{
					if(dsnv.nv[i].Phai.size()==0)
					{
						while(!kbhit())
						{
							Canhbao("Khong duoc de trong.Xin nhap lai!",46,3);
						}
						do{
							int key1 =getch();
						}while(key !=13&&key!=27);
						gotoxy(vitri,xMapTh+7);
					}
					else
					{
						loop=1;
						int dem =0;
						for(int m=0;dsnv.nv[m].MaNV!="";m++) // Kiem tra SLNV, neu da nhap du thong tin thi SLNV se dc cap nhat lai sau moi lan nhap
            				dem++;
            			dsnv.soLuongNV=dem;
            			dsnv.nv[i].l.pHead=NULL;
						break;
					}
				}
			}
			else if(key ==8)
			{
				if(flag ==1 && dsnv.nv[i].MaNV.size() > 0)
				{
					vitri--;
					gotoxy(vitri,yMapTh+1);
					cout << " ";
					gotoxy(vitri,yMapTh+1);
					dsnv.nv[i].MaNV.erase(dsnv.nv[i].MaNV.end()-1);
				}
				else if(flag ==2 && dsnv.nv[i].Ho.size() >0)
				{
					vitri--;
					gotoxy(vitri,yMapTh+3);
					cout << " ";
					gotoxy(vitri,yMapTh+3);
					dsnv.nv[i].Ho.erase(dsnv.nv[i].Ho.end()-1);
				}
				else if(flag ==3&&dsnv.nv[i].Ten.size()>0)
				{
					vitri--;
					gotoxy(vitri,yMapTh+5);
					cout << " ";
					gotoxy(vitri,yMapTh+5);
					dsnv.nv[i].Ten.erase(dsnv.nv[i].Ten.end()-1);
				}
				else if(flag ==4&&dsnv.nv[i].Phai.size()>0)
				{
					vitri--;
					gotoxy(vitri,yMapTh+7);
					cout << " ";
					gotoxy(vitri,yMapTh+7);
					dsnv.nv[i].Phai.erase(dsnv.nv[i].Phai.end()-1);
				}
			}
			
		}
	}
	if(loop ==1)
	{
		return;
	}
}
	
void doicho2chuoi(string &a,string &b)
{
	string temp;
	temp =a;
	a=b;
	b=temp;;
}
void sortTheoTen()
{
	string temp1,temp2,temph1,temph2;
	for(int i =0;i<dsnv.soLuongNV-1;i++)
	{
		for(int j =i+1;j<dsnv.soLuongNV;j++)
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
	gotoxy(57,3+yMap +stt*2);
	cout << data.MaNV;
	gotoxy(72+1+((28-data.Ten.size())/2),3+yMap +stt*2);
	cout << data.Ten;
	gotoxy(100+1+((14-data.Ho.size())/2),3+yMap +stt*2);
	cout << data.Ho;
	gotoxy(114+1+((20-data.Phai.size())/2),3+yMap +stt*2);
	cout << data.Phai;
}
void XuatDanhSachNV(int page, int vitri=0)
{
	Nocursortype();
	string arr[]={"Ma NV","Ten","Ho","Phai"};
	veBangChiTiet(arr,"DANH SACH NHAN VIEN",10);
	sortTheoTen();
	int k=0;
	for(int i =page*14;i< ((dsnv.soLuongNV > (page+1)*14)?14 : dsnv.soLuongNV);i++)
	{
		xuatNhanVien(dsnv.nv[i],k);
		k++;
	}
}
void quanLyXuatNV()
{
	if(dsnv.soLuongNV==0)
	{
		Canhbao("khong co nhan vien nao trong he thong.",46,3);
		system("PAUSE");
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
		Canhbao("Khong co nhan vien nao trong he thong!!",46,3);
		system("Pause");
        return;
	}
	veOTimKiem("Ma Nhan Vien");
	string manv;
	int loop =1;
	int key,vitri;
	while(loop ==1)
	{
		while(!kbhit())
		{
			vitri = xMapTimKiem+23+manv.size();
			key =getch();
			if(key ==27)
			{
				loop =0;
				break;
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
			{
				if(manv.length()  <10)
				{
		 			gotoxy(vitri,yMapTimKiem+1);
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
						Canhbao("Do dai ma nhan vine phai 10 ki tu.Xin kiem tra lai!!",45,3);
					do{
						int key1 = getch();
					}while(key!=13);
					gotoxy(vitri,yMapTimKiem+1);
				}
				else
				{
					int i;
					for(i =0;i<dsnv.soLuongNV;i++)
						if(dsnv.nv[i].MaNV==manv) break;
						
					if(i == dsnv.soLuongNV)
					{
						while(!kbhit())
							Canhbao("Khong tim thay ma nhan vien "+manv+".Xin kiem tra lai!!",44,3);
						do{
							int key1 = getch();
						}while(key!=13);
						gotoxy(vitri,yMapTimKiem+1);
					}
					else{
						string arr[]={"Ma NV","Ho","Ten","Phai"};
			
						veBangChiTiet(arr,"THONG TIN CHI TIET NHAN VIEN VUA TIM",12);
						gotoxy(57,3+yMap);
						cout << dsnv.nv[i].MaNV;
						gotoxy(72+1+((28-dsnv.nv[i].Ten.size())/2),3+yMap);
						cout << dsnv.nv[i].Ten;
						gotoxy(100+1+((14-dsnv.nv[i].Ho.size())/2),3+yMap);
						cout << dsnv.nv[i].Ho;
						gotoxy(114+1+((20-dsnv.nv[i].Phai.size())/2),3+yMap);
						cout << dsnv.nv[i].Phai;
					}
					
				}
			}
			else if(key == 8 && manv.length() >0)
			{
				vitri--;
				gotoxy(vitri,yMapTimKiem+1);
				cout << " ";
				gotoxy(vitri,yMapTimKiem+1);
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
		Canhbao("Khong co nhan vien nao trong he thong!!",46,3);
		system("Pause");
        return;
	}
	Yescursortype();
veOTimKiem("Ma Nhan Vien");
	string manv;
	int loop =1;
	int key,vitri;
	while(loop ==1)
	{
		while(!kbhit())
		{
			vitri = xMapTimKiem+23+manv.size();
			key =getch();
			if(key ==27)
			{
				loop =0;
				break;
			}
			else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
			{
				if(manv.length()  <10)
				{
		 			gotoxy(vitri,yMapTimKiem+1);
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
						Canhbao("Do dai ma nhan vine phai 10 ki tu.Xin kiem tra lai!!",45,3);
					do{
						int key1 = getch();
					}while(key!=13);
					gotoxy(vitri,yMapTimKiem+1);
				}
				else
				{
					int i;
					for(i =0;i<dsnv.soLuongNV;i++)
						if(dsnv.nv[i].MaNV==manv) break;
						
					if(i == dsnv.soLuongNV)
					{
						while(!kbhit())
							Canhbao("Khong tim thay ma nhan vien "+manv+".Xin kiem tra lai!!",44,3);
						do{
							int key1 = getch();
						}while(key!=13);
						gotoxy(vitri,yMapTimKiem+1);
					}
					else{
						deleteNV(i);
						while(!kbhit())
							Canhbao("Xoa thanh cong ma nhan vien "+manv+"!!",46,3);
						do{
							int key1 = getch();
						}while(key!=13);
						gotoxy(vitri,yMapTimKiem+1);
					}
					
				}
			}
			else if(key == 8 && manv.length() >0)
			{
				vitri--;
				gotoxy(vitri,yMapTimKiem+1);
				cout << " ";
				gotoxy(vitri,yMapTimKiem+1);
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
	ifstream ifs("NHANVIEN",ios::in);
	while((getline(ifs,dsnv.nv[dsnv.soLuongNV].MaNV))!=false)
	{
		fflush(stdin);
		getline(ifs,dsnv.nv[dsnv.soLuongNV].Ho);
		getline(ifs,dsnv.nv[dsnv.soLuongNV].Ten);
		getline(ifs,dsnv.nv[dsnv.soLuongNV].Phai);
		int flag=0;
		for(int i=0;i<dsnv.soLuongNV;i++)
			if(dsnv.nv[i].MaNV== dsnv.nv[dsnv.soLuongNV].MaNV)
			{
				flag=1;
				break;
			}
		if(flag==0)
			dsnv.soLuongNV++;
	}
	ifs.close();
}
								// END
								// BAT DAU CHI TIET HOA DON

void InitCT_HD(DSCT &l)
{
	l.pHead = l.pTail =NULL;
}
NODECT_HOADON* GetNode(CT_HOADON data)
{
	NODECT_HOADON* p = new NODECT_HOADON;
	if(p == NULL)
		return NULL;
	p->Data = data;
	p->pNext = NULL;
	return p;
}
void AddTailCT(DSCT&l, NODECT_HOADON* p)
{
	if(l.pHead == NULL)
	 	l.pHead = l.pTail =NULL;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}	
}
void NhapCT_HD(Tree&vt, CT_HOADON &hd, string loai)
{ 
	
	int cot1 = 47, cot2=52,cot3=70,cot4=92,cot5=102,cot6=112, cot7=132,y =16;
	int vitri;
	string MaVT;
	long dongia;
	int soluong;
	long vat;
	int i =0,flag =1;
	int key;
	LNR(vt);
	NODE_VATTU* node;
	while(true)
	{
		if(kbhit())
		{
			key = getch();
			if(key == 27) return;
		}
		if(flag ==1)
		{
			i++; // tang so thu tu
			gotoxy(cot1,y);
			cout << i;
			gotoxy(cot2,y);
			flag =2;
		}
		while(flag ==2)
		{
		while(kbhit())
		{
			vitri = cot2 + MaVT.size();
			key = getch();
			if(key == 27)
			{
				return;
			}
			else if(key == 13 || key==9)
			{
				if(kiemTraDoDaiMaVT(MaVT)==false)
				{
					while(!kbhit())
						Canhbao("Do dai ma vat tu la 10 ki tu!. Xin nhap lai!!",46,3);
					do
					{
						int key1 = getch();
						
					}while(key!=13&&key!=27);
					gotoxy(vitri,y);
				}
				else if(kiemTraTrungMaVT(MaVT) == false)
				{
					while(!kbhit())
						Canhbao("Ma vat tu "+MaVT+" khong ton tai. Xin nhap lai!",46,3);
					do
					{
						int key1= getch();
					}while(key !=13&& key !=9);
					gotoxy(vitri,y);
				}
				else if(kiemTraTrungMaVT(MaVT)==true)
				{
					node =Search(vt,MaVT);
					gotoxy(cot3,y);
					cout << node->Data.TenVT;
					gotoxy(cot4,y);
					cout << node->Data.DVT;
					flag = 5;
					break;
				}
			}
			// nhap ma vat tu
			else if((key >=48 && key <=57) || (key >=97 && key <=122) || (key  >=65 && key <= 90))
			{
				if(MaVT.size() <10) // vi tri - cot2 <10;
				{
					gotoxy(vitri,y);
					if(key >=97 && key <=122)
						key = key -32;
					cout << char(key);
					MaVT.insert(MaVT.end(),1,char(key));
				}
			}
			else if(key ==8)
			{
				if(MaVT.size() >0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout << " ";
					gotoxy(vitri,y);
					MaVT.erase(MaVT.end()-1);
				}
			}
			
			}
		}	
		if(flag == 5) // nhap so luong
		{
			char so[5]; // su dung mang de de kiem tra tung chu so nhap vao
		NhapLaiSoLuong:
			gotoxy(cot5+1,y);
			cin >> so;
			if(chiChoNhapSo(so))
			{
				soluong = atoi(so);
			}
			else
			{
				gotoxy(cot5,y);
				cout << "          ";
				Canhbao("Nhap sai so luong.Xin nhap lai!",46,3);
				getch();
				goto NhapLaiSoLuong;
			}
			if(node !=NULL)
			{
				if(loai == "N")
				{
						node->Data.SoLuongTon +=soluong;
				}
				else if(loai == "X")
				{
					if(soluong <= node->Data.SoLuongTon)
					{
						node->Data.SoLuongTon -= soluong;
					}
					else
					{
						Canhbao("So luong trong kho khong du  (Trong kho con "+to_String(node->Data.SoLuongTon)+"). Xin Nhap lai!!",46,3);
						getch();
						textcolor(7);
						gotoxy(cot5,y);
						cout << "          ";
						goto NhapLaiSoLuong;
					}
				}				
			}
			flag =6;
		}
		else if(flag ==6) // nhap don gia
		{
			gotoxy(cot6,y);
			if(loai == "N") //neu la hoa don nhap
			{
				char gia[10];
			NhapLaiGia:
				gotoxy(cot6,y);
				cin >>gia;
				if(chiChoNhapSo(gia))
				{
					dongia = atoi(gia);
				}
				else
				{
					gotoxy(cot6,y);
					cout <<"            ";
					Canhbao("Don gia chi nhan ki tu so.Xin nhap lai!",46,3);
					getch();
					goto NhapLaiGia;
				}
			}
			else if(loai =="X")
			{
				NODE_HOADON *p;
				DSHD ds;
				int dem =0;
				for(p = ds.pHead; p!=NULL;p = p->pNext);
				{
					if(p->data.loai == "N") // Tim den cac hoa don nhap
					{
						for(NODECT_HOADON *q = q->pNext;q!=NULL;q=q->pNext) // tim vat trong hoa don nhap
						{
							if(q->Data.MaVT==MaVT)
							{
								dongia = soluong*q->Data.dongia;
								cout << dongia;
								dem++;
								break;
							}
							if(dem!=0) break; // neu khong co thi thoat vong lap
						}
					}
				}
			}
			flag =7;
		}
		else if(flag ==7)
		{
			char so[3]; // su dung mang de de kiem tra tung chu so nhap vao
		NhapLaiVAT:
			gotoxy(cot7,y);
			cin >> so;
			if(chiChoNhapSo(so))
			{
				vat = atoi(so);
			}
			else if(!chiChoNhapSo(so))
			{
				gotoxy(cot7,y);
				cout << "     ";
				Canhbao("Nhap sai VAT.Xin nhap lai!",46,3);
				getch();
				goto NhapLaiVAT;
			}
			else if(vat <0 || vat > 100)
			{
				gotoxy(cot7,y);
				cout << "    ";
				Canhbao("Nhap sai VAT.Xin nhap lai!",46,3);
				getch();
				goto NhapLaiVAT;
			}
			else
			{
				flag =1;
				strcpy(hd.MaVT,MaVT.c_str());
				hd.soluong = soluong;
				hd.dongia = dongia;
				hd.VAT = vat;
				y++; 
				MaVT =""; 
			}
								
		}
	}
}
void ThemCT_HoaDon(Tree &vt,DSCT &l,string loai)
{
	CT_HOADON hd;
	veBangNhapCT_HD();
	NhapCT_HD(vt,hd,loai);
	AddTailCT(l,GetNode(hd));
}
void XuatCT_HD(CT_HOADON data,int stt)
{
	gotoxy(57,3+yMap +stt*2);
	cout << data.MaVT;
	gotoxy(72+1+((28-to_String(data.dongia).size())/2),3+yMap +stt*2);
	cout << data.dongia;
	gotoxy(100+1+((14-to_String(data.soluong).size())/2),3+yMap +stt*2);
	cout << data.soluong;
	gotoxy(114+1+((20-to_String(data.VAT).size())/2),3+yMap +stt*2);
	cout << data.VAT;
}
void XuatDanhSachCT_HD(DSCT &l,int page,int vitri=0)
{
	string arr[]={"Ma VT", "Don gia","So luong","%VAT"};
	veBangChiTiet(arr,"DANH SACH CHI TIEN HOA DON",10);
	int stt =0;
	int dem =0;
	for(NODECT_HOADON *p=l.pHead;p!=NULL;p=p->pNext)
	{
		if(dem >= page*14 && dem < (page+1)*14)
		{
			XuatCT_HD(p->Data,stt);
			stt++;
		}
		dem++;
	}
}
								// KET THUC CHI TIET HOA DON
								// BAT DAU HOA DON
void InitHD(DSHD &l)
{
	l.pHead = l.pTail =NULL;
}
NODE_HOADON* Getnode(HOADON data)
{
	NODE_HOADON* p = new NODE_HOADON;
	if(p==NULL)
		return NULL;
	p->data = data;
	p->pNext = NULL;
	return p;
}
void AddTailHD(DSHD &l, NODE_HOADON* p)
{
	if(l.pHead ==NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail =p;
	}
}
NODE_HOADON* SearchHD(DSHD l, string soHD)
{
	NODE_HOADON *p;
	for(p=l.pHead;p!=NULL;p=p->pNext)
	{
		if(strcmp(p->data.SoHD,soHD.c_str())==0)
		{
			return p;
		}
	}
	return NULL;
}
void nhapNgayHD(Date &date)
{
	string sngay=to_String(date.ngay) ;
	string sthang=to_String(date.thang);
	string snam =to_String(date.nam);
	int key, check =0,vitri;
	int flag =3;
	int y =yMapTh-4;
	while(check ==0)
	{
		while(!kbhit())
		{
			key = getch();
			if(flag==1)
			{
				vitri = xMapTh+13+sngay.length();
			}
			else if(flag==2)
			{
				vitri = xMapTh+18+sthang.length();
			}
			else if(flag==3)
			{
				vitri = xMapTh+23+snam.length();
			}
			if(key ==27)
			{
				check =2;
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
						 Canhbao("Nhap sai ngay.Xin nhap lai!",46,3);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
						
					}
					else if(date.ngay ==0)
					{
						
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",46,3);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else{
						
						gotoxy(xMapTh+18+sthang.length(),y);
						flag =2;
					}
				}
				else if(flag ==2)
				{
					if(date.thang < 0 || date.thang >12)
					{
						
						while(!kbhit())
						 Canhbao("Nhap sai thang.Xin nhap lai!",46,3);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(date.thang == 0)
					{
						
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",46,3);
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
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",46,3);
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(xMapTh+13+sngay.length(),y);
								flag =1;
							}
							else
							{
								gotoxy(xMapTh+23+snam.length(),y);
								flag =3;
							}
						}
						else if(date.thang ==4 || date.thang ==6 || date.thang ==9 || date.thang ==11)
						{
							if(date.ngay >30)
							{
								while(!kbhit())
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",46,3);
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(xMapTh+13+sngay.length(),y);
								flag =1;
							}
							else
							{
								gotoxy(xMapTh+23,y);
								flag =3;
							}
						}
						else 
						{
							gotoxy(xMapTh+23+snam.length(),y);
							flag =3;
						}
						
					}
				}
				else if(flag ==3)
				{
					if(date.nam == 0)
					{
						
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",46,3);
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
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",46,3);
									do{
										int key1 = getch();
									}while(key!=13&&key!=9);
									gotoxy(xMapTh+13+sngay.length(),y);
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
						gotoxy(xMapTh+13+sngay.size(),y);
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
						gotoxy(xMapTh+18+sthang.size(),y);
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
void nhapHoaDon(Tree &vt,DSHD &l)
{
	HOADON hd;
	CT_HOADON ct_hd;
	Date date;
	layNgayThangHienTai(date.ngay, date.thang,date.nam);
	string MSHD, MaNV,Loai;
	int key,flag=1;
	bool loop =0;
		vegiaodienngay(xMapTh+5,yMapTh-5);
		gotoxy(xMapTh+13,yMapTh-4);
		cout << date.ngay;
		gotoxy(xMapTh+18,yMapTh-4);
		cout << date.thang;
		gotoxy(xMapTh+23,yMapTh-4);
		cout << date.nam;
		nhapNgayHD(date);
		hd.date = date;
		gotoxy(xMapTh+12,yMapTh+1);
		while(loop==0)
		{
			while(!kbhit())
			{
				int vitri;
				key = getch();
				if(flag==1) vitri =xMapTh+12 +MaNV.length();
				else if(flag == 2) vitri = xMapTh+12 +MSHD.length();
				else if(flag ==3) vitri = xMapTh+12 +Loai.length();
				if(key == 0)
				{
					key = getch();
				}
				else if(key  == 27)
				{
					loop = 1;
					break;
				}
				if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
				{
					if(flag == 1 && MaNV.size()<10)
					{
						gotoxy(vitri,yMapTh+1);
						if(key >=97 && key <=122)
							key = key -32;
						cout << (char)key;
						MaNV.insert(MaNV.end(),1,(char)key);
					}
					else if(flag ==2 && MSHD.size() < 20)
					{
						gotoxy(vitri,yMapTh+3);
						if(key >=97 && key <=122)
							key = key -32;
						cout << (char)key;
						MSHD.insert(MSHD.end(),1,(char)key);
						
					}
					else if(flag ==3){
						if(vitri-(xMapTh+12) <1 && (key == 110 || key == 78 || key == 120 ||key ==88))
						{
							gotoxy(vitri,yMapTh+5);
							if(key == 110 || key == 120)
								key = key -32;
							Loai =(char)key;
							cout << (char)key;
						}
						
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
								Canhbao("Khong duoc de trong!.Xin nhap lai!!",46,3);
							}
							do{
								int key1 = getch();
							}while(key!=13&&key!=9);
							gotoxy(vitri,yMapTh+1);
						}
						else
						{
							int i;
							for(i=0;i<dsnv.soLuongNV;i++)
								if(dsnv.nv[i].MaNV==MaNV) break;
							if(i ==dsnv.soLuongNV)
							{
								while(!kbhit())
								{
									Canhbao("Ma "+MaNV+" Khong ton tai!.Xin nhap lai!!",46,3);
								}
								do{
									int key1 = getch();
								}while(key!=13&&key!=9);
								gotoxy(vitri,yMapTh+1);
							}
							
							else{
								gotoxy(xMapTh+12,yMapTh+3);
								flag =2;
							}
						}
						
					}
					else if(flag == 2)
					{
						if(MSHD.length() <20)
						{
							while(!kbhit())
							{
								Canhbao("So hop dong phai la 20 ki tu!.Xin nhap lai!!",46,3);
							}
							do{
								int key1 = getch();
							}while(key!=13&&key!=9);
							gotoxy(vitri,yMapTh+3);
						}
						else if(SearchHD(l,MSHD) != NULL)
						{
							while(!kbhit())
							{
								Canhbao("So hop dong "+MSHD+" da ton tai!.Xin nhap lai!!",46,3);
							}
							do{
								int key1 = getch();
							}while(key!=13&&key!=9);
							gotoxy(vitri,yMapTh+3);						
						}
						
						else
						{
							gotoxy(xMapTh+12,yMapTh+5);
							flag =3;
						}
					}
					else if(flag == 3)
					{
						if(Loai.size() ==0)
						{
							while(!kbhit())
							{
								Canhbao("Khong duoc de trong!.Xin nhap lai!!",46,3);
							}
							do{
								int key1 = getch();
							}while(key!=13&&key!=27);
							gotoxy(vitri,yMapTh+5);
						}
						else
						{
							strcpy(hd.SoHD,MSHD.c_str());
							strcpy(hd.MaNV,MaNV.c_str());
							strcpy(hd.loai,Loai.c_str());
							loop =1;
							
						}
					}
					if(loop == 1)
					{
						InitCT_HD(hd.l);
						ThemCT_HoaDon(vt,hd.l,Loai);
						AddTailHD(l,Getnode(hd));
						break;
					}
				}
				else if(key == 8)
				{
						if(flag == 1&& MaNV.size() >0)
						{
							vitri--;
							gotoxy(vitri,yMapTh+1);
							cout << " ";
							gotoxy(vitri,yMapTh+1);
							MaNV.erase(MaNV.end()-1);
						}
						else if(flag == 2&&MSHD.size()>0)
						{
							vitri--;
							gotoxy(vitri,yMapTh+3);
							cout << " ";
							gotoxy(vitri,yMapTh+3);
							MSHD.erase(MSHD.end()-1);
						}
						else if(flag ==3&& Loai.size() >0)
						{
							vitri--;
							gotoxy(vitri,yMapTh+5);
							cout << " ";
							gotoxy(vitri,yMapTh+5);
							Loai.erase(Loai.end()-1);
						}			
				}
			}
		}
		if(loop == 1) return;
}
	
void ThemHoaDon(Tree &vt, DSHD &l)
{
	if(vt == NULL)
	{
		Canhbao("Hien trong kho khong con vat tu nao!!",46,3);
		system("Pause");
		return;
	}
	if(dsnv.soLuongNV == 0)
	{
		Canhbao("Hien chua co nhan vien nao trong he thong!!",46,3);
		system("Pause");
		return;
	}
		string arrten[4] = {"MaNV","SoHD","Loai"};
		vebangThemMoi(arrten,3);
		nhapHoaDon(vt,l);
	
}
void XuatHD(HOADON hd, int stt)
{
	int y =16+stt;
	gotoxy(arrDSHD[0]+1 +((arrDSHD[1] - arrDSHD[0] -to_String(stt+1).length())/2),y+stt);
	cout << stt+1;
	gotoxy(arrDSHD[1]+1 +(arrDSHD[2] - arrDSHD[1] -strlen(hd.SoHD)/2),y+stt);
	cout << hd.SoHD;
	gotoxy(arrDSHD[3]+3,y);
	cout << hd.date.ngay << "/" <<hd.date.thang << "/" << hd.date.nam;
	gotoxy(arrDSHD[4]+1 +(arrDSHD[5] - arrDSHD[4] -2),y+stt);
	if(strcmp(hd.loai,"N") == 0 || strcmp(hd.loai,"n") == 0)
	{
		cout << "Nhap";	
	}
	else{
		cout << "Xuat";
	}
}
// xUat thong tin hoa don theo so hoa don nhap vao
void XuatthongTinHoaDon(Tree vt,DSHD l)
{
	string SoHD;
	string arrTukhoa[]={"So HD","Ngay Lap","Loai"};
	int key,vitri,check =0,stt =0;
	int y=16+stt;;
	if(l.pHead == NULL)
	{
		Canhbao("Khong co hoa don nao trong he thong.Xin kiem tra lai!!",45,3);
		system("Pause");
        return ;
	}

		veOTimKiem("So Hoa Don");
		gotoxy(xMapTimKiem+23,yMapTimKiem+1);
		while(check ==0)
		{
			while(!kbhit())
			{
				vitri = xMapTimKiem+23+SoHD.length();
				key =getch();
				if(key ==27)
				{
					check =2;
					break;
				}
				else if((key >= 48&& key <=57) || (key >=97 && key <=122) || (key >=65 && key <=90))
				{
					if(SoHD.length()  <20)
					{
						gotoxy(vitri,yMapTimKiem+1);
						if(key >=97 && key <=122)
							key = key -32;
						cout << (char)key;
						SoHD.insert(SoHD.end(),1,(char)key);
				   }
				}
				else if(key == 13 || key ==9)
				{
					if(SearchHD(l,SoHD)==NULL)
					{
						while(!kbhit())
							Canhbao("Khong tim thay so hoa don"+SoHD+".Xin kiem tra lai!!",45,3);
						do{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,yMapTimKiem+1);
					}
					else
					{
						NODE_HOADON *q;
						veBangNhapCT_HD();
						NODECT_HOADON *p;
						for(p = q->data.l.pHead;p!=NULL;p=p->pNext)
						{
							XuatCT_HD(p->Data,stt);
							stt++;
						}
						check=1;
					}
				}
				else if(key == 8 && SoHD.length() >0)
				{
					vitri--;
					gotoxy(vitri,yMapTimKiem+1);
					cout << " ";
					gotoxy(vitri,yMapTimKiem+1);
					SoHD.erase(SoHD.end()-1);
				}
			}
		}
	}								// THONG KE HOA DON
void xuatThongKe(THONGKE tk, int stt)
{
	int y =16+stt;
	gotoxy(arrToaDoBangThongKeHD[0]+2,y);
	cout << tk.SoHD;
	gotoxy(arrToaDoBangThongKeHD[1]+2,y);
	cout << tk.date.ngay << "/"<<tk.date.thang << "/" <<tk.date.nam;
	gotoxy(arrToaDoBangThongKeHD[2]+2,y);
	cout << tk.Loai;
	gotoxy(arrToaDoBangThongKeHD[3]+2,y);
	cout << tk.HoTenNV;
	gotoxy(arrToaDoBangThongKeHD[4]+2,y);
	cout << tk.donGia;
}
void xuatDSTK(DS_THONGKE &l, int page)
{
	veBangThongKeHD();
	int stt=0;
	for(int i =page*12;i < (l.soTK >(page+1)*12 ? 12 : l.soTK-page*12);i++)
	{
		xuatThongKe(l.tk[i],stt++);
	}
}
void xulyDSTK(DS_THONGKE &l,NHANVIEN nv, Date first, Date final)
{
	int checkDate1,checkDate2;
	int donGia =0,kq;
	for(NODE_HOADON* p = nv.l.pHead; p!= NULL; p= p->pNext)
	{
		string name =" ";
		checkDate1 = soSanhNgay(p->data.date,first);
		checkDate1 = soSanhNgay(p->data.date,final);
		if((checkDate1 ==1|| checkDate1 ==0) && (checkDate2 == -1|| checkDate2 == 0) )
		{
			name +=nv.Ho;
			name+=" ";
			name+=nv.Ten;
			strcpy(l.tk[l.soTK].SoHD, p->data.SoHD);
			l.tk[l.soTK].date = p->data.date;
			strcpy(l.tk[l.soTK].Loai,p->data.loai);
			l.tk[l.soTK].HoTenNV = name;
			for(NODECT_HOADON* q =p->data.l.pHead; q!=NULL; q=q->pNext)
			{
				kq = q->Data.soluong*q->Data.dongia;
				donGia +=kq+(q->Data.VAT*kq)/100;
			}
			l.tk[l.soTK++].donGia = donGia;
		}
	}
}
void nhapNgay(Date &first, Date &final)
{
	int xMapNgay =77,xMapThang =82,xMapNam=87;
	int xMapNgay2 = 109,xMapThang2=114,xMapNam2=119;
	
nhaplai:
	int flag =1;
	int check =0;
	int y=9;
	int vitri;
	int key,lengh,kq;
	string sngay,sthang,snam,sngay2,sthang2,snam2;
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
						 Canhbao("Nhap sai ngay.Xin nhap lai!",46,3);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
						
					}
					else if(first.ngay ==0)
					{
						
						while(!kbhit())
						 Canhbao("Khong duoc de trong.Xin nhap lai!",46,3);
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
						 Canhbao("Khong duoc de trong.Xin nhap lai!",46,3);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(first.thang < 0 || first.thang >12)
					{
						
						while(!kbhit())
						 Canhbao("Nhap sai thang.Xin nhap lai!",46,3);
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
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",46,3);
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
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",46,3);
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
						 Canhbao("Nhap sai nam, nam phai be hon "+to_String(layNamHienTai())+".Xin nhap lai!",46,3);
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
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",46,3);
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
						 Canhbao("Khong duoc de trong.Xin nhap lai!",46,3);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(final.nam < first.nam || final.nam > layNamHienTai())
					{
						while(!kbhit())
						 Canhbao("Nhap sai nam,nam phai be hon "+to_String(layNamHienTai())+".Xin nhap lai!",46,3);
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
						 Canhbao("Khong duoc de trong.Xin nhap lai!",46,3);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(final.ngay < 0 || final.ngay >31)
					{
						while(!kbhit())
						 Canhbao("Nhap sai ngay.Xin nhap lai!",46,3);
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
						 Canhbao("Khong duoc de trong.Xin nhap lai!",46,3);
						do
						{
							int key1 = getch();
						}while(key!=13&&key!=9);
						gotoxy(vitri,y);
					}
					else if(final.thang <0 || final.thang >12)
					{
						while(!kbhit())
						 Canhbao("Nhap sai thang.Xin nhap lai!",46,3);
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
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",46,3);
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
									Canhbao("Ngay cua thang khong hop le.Xin nhap Lai!",46,3);
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
					vitri--;
					gotoxy(vitri,y);
					cout <<" ";
					gotoxy(vitri,y);
					sthang.erase(sthang.end()-1);
					first.thang = atoi(sthang.c_str());
				}
				else if(flag == 3&& snam.size() >0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout <<" ";
					gotoxy(vitri,y);
					snam.erase(snam.size()-1);
					first.nam = atoi(snam.c_str());
				}
				if(flag ==4 && sngay2.size() >0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout <<" ";
					gotoxy(vitri,y);
					sngay2.erase(sngay2.end()-1);
					final.ngay = atoi(sngay2.c_str());
				}
				else if(flag ==5 && sthang2.size() >0)
				{
					vitri--;
					gotoxy(vitri,y);
					cout <<" ";
					gotoxy(vitri,y);
					sthang2.erase(sthang2.end()-1);
					final.thang = atoi(sthang2.c_str());
				}
				else if(flag == 6&& snam2.size() >0)
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
	if(check ==1) return;
}
void thongKeHD(DS_THONGKE &l,DSHD dshd)
{
	l.soTK =0;
	Date first, final;
	int page =0, key, dem = l.soTK;
	string name = "BANG LIET KE HOA DON TRONG KHOANG THOI GIAN";
	string name2 = "TU NGAY :    /    /     \t DEN NGAY :    /    /     ";
	
	if(dshd.pHead== NULL)
	{
		Canhbao("Hien tai khong co hoa don nao trong he thong.!!",46,3);
		system("PAUSE");
		getch();
		return;
	}
		gotoxy(70, 7);
		cout << name;
		gotoxy(67, 9);
		cout << name2;
		nhapNgay(first,final);
		for(int i = 0; i <dsnv.soLuongNV;i++)
		{
			xulyDSTK(l,dsnv.nv[i],first,final);
		}
		gotoxy(0,0);
		while(true)
		{
			xuatDSTK(l,page);
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
					clrscr();
					return;
				}
		 } 
	}
	
}
									// KET THUC
									// MENU
void MenuVT(Tree &t)
{
	InitVT(t);
	xoaMenu();
	string arrVT[6] ={"         Nhap vat tu         ","        Tim kiem vat tu      ","      Hieu chinh vat tu      ","          Xoa Vat tu         ","    10 VT co tan suat cao    ","    Danh sach VT trong kho   "};
	vemenu(arrMenuVT,arrVT,6);
	int vitri=0;
	int key;
	while(true)
	{
			Nocursortype();
			hcn(5,arrMenuVT[vitri],arrVT[vitri],true);
			key = getch();
			if(key ==224)
			{
				key = getch();
				if(key == 80)
				{
					hcn(5,arrMenuVT[vitri],arrVT[vitri]);
					vitri++;
					if(vitri==6)
					{
						vitri=0;
					}
				}
				else if(key == 72 && vitri >0)
				{
					hcn(5,arrMenuVT[vitri],arrVT[vitri]);
					vitri--;
				}
			}
			else if(key == 0)
			{
				key =getch();
			}
			else if(key == 13)
			{
				hcn(5,arrMenuVT[vitri],arrVT[vitri]);
				Yescursortype();
				switch(vitri)
				{
					case 0:
						themVatTu(t);
						break;
					case 1:
						timKiemVT(t,soVT);
						break;
					case 2:
						hieuChinhVatTu(t);
						break;
					case 3:
						xoaVatTu(t,soVT);
						break;
					case 4:
						
						break;
					case 5:
						quanLysangTrangVT(t);
						break;
				}
				if(vitri ==0)
				{
					xoaNoiDungTrongKhungThem();
				}
				vemenu(arrMenuVT,arrVT,6);
			}
			else if(key == 27)
			{
				xoaMenu();
				xoaNoiDungTrongKhungThem();
				XoaOMain();
				return;
			}
		}
}
void MenuNV()
{
	docNhanVien();
	xoaMenu();
	string arrVT[5] ={"        Nhap nhan vien       ","    In danh sach nhan vien   ","       Tim kiem nhan vien    ","         Xoa nhan vien       ","         Save nhan vien      "};
	vemenu(arrMenuVT,arrVT,5);
	int vitri=0;
	int key;
	while(true)
	{

			Nocursortype();
			hcn(5,arrMenuVT[vitri],arrVT[vitri],true);
			key = getch();
			if(key ==224)
			{
				key = getch();
				if(key == 80)
				{
					hcn(5,arrMenuVT[vitri],arrVT[vitri]);
					vitri++;
					if(vitri==5)
					{
						vitri=0;
					}
				}
				else if(key == 72 && vitri >0)
				{
					hcn(5,arrMenuVT[vitri],arrVT[vitri]);
					vitri--;
				}
			}
			else if(key == 0)
			{
				key =getch();
			}
			else if(key == 13)
			{
				hcn(5,arrMenuVT[vitri],arrVT[vitri]);
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
				if(vitri ==0)
				{
					xoaNoiDungTrongKhungThem();
				}
				vemenu(arrMenuVT,arrVT,5);
			}
			else if(key == 27)
			{
				xoaMenu();
				xoaNoiDungTrongKhungThem();
				XoaOMain();
				return;
			}
		}

}
void menuHD(Tree &vt,DSHD &l,DS_THONGKE &ds)
{
	InitHD(l);
	xoaMenu();
	string arrNameHD[5] ={"    Lap Hoa Don Nhap/Xuat    ","     In Hoa Don Theo SoHD    ","       Thong Ke Hoa Don      ","        Save Hoa Don         "};
	vemenu(arrMenuVT,arrNameHD,4);
	int vitri=0;
	int key;
	while(true)
	{
			Nocursortype();
			hcn(5,arrMenuVT[vitri],arrNameHD[vitri],true);
			key = getch();
			if(key ==224)
			{
				key = getch();
				if(key == 80)
				{
					hcn(5,arrMenuVT[vitri],arrNameHD[vitri]);
					vitri++;
					if(vitri==4)
					{
						vitri=0;
					}
				}
				else if(key == 72 && vitri >0)
				{	
					
					hcn(5,arrMenuVT[vitri],arrNameHD[vitri]);
					vitri--;
				}
			}
			else if(key == 0)
			{
				key =getch();
			}
			else if(key == 13)
			{
				hcn(5,arrMenuVT[vitri],arrNameHD[vitri]);
				Yescursortype();
				switch(vitri)
				{
					case 0:
						ThemHoaDon(vt,l);
						break;
					case 1:
						XuatthongTinHoaDon(vt,l);
						break;
					case 2:
						thongKeHD(ds,l);
						break;
					case 3:
						break;	
				}
				if(vitri ==0)
				{
					xoaNoiDungTrongKhungThem();
				}
				vemenu(arrMenuVT,arrNameHD,4);
			}
			else if(key == 27)
			{
				xoaMenu();
				xoaNoiDungTrongKhungThem();
				XoaOMain();
				return;
			}
		}
}
void MenuChinh(Tree &vt,DSHD &l,DS_THONGKE &ds)
{ 
    veKhungGiaoDienChinh();
	string arrTuKhoa[4] = { "            Vat Tu           " ,"           Nhan vien         ","            Hoa don          ","     Luu toan bo du lieu     "};
	vemenu(arrMenuVT,arrTuKhoa,4);
	int vitri =0;
	int key;
	int check =0;
	while(check ==0)
	{
			Nocursortype();
			hcn(5,arrMenuVT[vitri],arrTuKhoa[vitri],true);
			key = getch();
			if(key ==224)
			{
				key = getch();
				if(key == 80)
				{
					hcn(5,arrMenuVT[vitri],arrTuKhoa[vitri]);
					vitri++;
					if(vitri==4)
					{
						vitri=0;
					}
				}
				else if(key == 72&& vitri >0)
				{
					hcn(5,arrMenuVT[vitri],arrTuKhoa[vitri]);
					vitri--;
					
				}
			}
			else if(key == 0)
			{
				key =getch();
			}
			else if(key == 13)
			{
				hcn(5,arrMenuVT[vitri],arrTuKhoa[vitri]);
				Yescursortype();
				switch(vitri)
				{
					case 0:
						MenuVT(vt);
						break;
					case 1:
						MenuNV();
						break;
					case 2:
						menuHD(vt,l,ds);
						break;
					case 3:
						break;
				}
				xoaMenu();
				xoaNoiDungTrongKhungThem();
				XoaOMain();
				vemenu(arrMenuVT,arrTuKhoa,4);
			}
			else if(key == 27)
			{
				xoaMenu();
				xoaNoiDungTrongKhungThem();
				XoaOMain();
				return;
			}
		}
}

									// KET THUC
int main(){
	resizeConsole(1100,860);
	Tree t;
	DSHD l;
	DS_THONGKE ds;
	
	MenuChinh(t,l,ds);

	getch();
}
# QLVatTu
