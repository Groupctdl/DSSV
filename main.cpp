#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include "display.h"



void findStudent(char* text){
	
	// tao lai menu duoc chon o day 
	
	drawFindStudent(text); // ve giao dien 
	
	char idStudent[15];
	int len = 0, finded = 0;
	while(true){
		char key;
		key = getch();
		if(key == ET){
			// khong co du lieu thi thong bao
			if(!createNotice("khong tim thay du lieu", "")){ // thong bao tra ve 0 thi thoat chuong trinh
				return;
			}
			// chuong trinh tiep tuc, reset lai muc nhap
			len = 0;
			for(int i = 0; i < 15; i++) idStudent[i] = '\0';
			createMenu(2);
			drawFindStudent(text);
		}
		else if(('a' <= key && key <= 'z') || ('A' <= key && key <= 'Z') || ('0' <= key && key <= '9')){
			// luu tru input, xuat input, timkiem, xuat danh sach
			if(len < 15){
				idStudent[len] = key;
                idStudent[len + 1] = '\0'; //
                len++;
				outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, idStudent);
			}
		}
	}
}

int main(){
	initwindow(LPOINTX, LPOINTY);
	char flistStudent[50] = "D:\\listStudent";
	getch();
	int selected = 1;
	createMenu(selected);
	while(1){
		char key = getch();
		switch(key){
			case ET: 	
				switch(selected){
//					case 1: 
	
					case 2:
						findStudent("Quan ly sinh vien");
						getch();
						closegraph();	
//						node* listStudent;
//						openOnFile(listStudent, flistStudent);
//						
//						studentManagment(listStudent);
						
						
//						break;
//					case 3:
//						if(createNotice("Da chon Danh sach mon hoc", "")){
//							drawMenu(selected);
//						}
//						else{
//							cleardevice();
//							closegraph();
//						}
//						break;
//					case 4:
//						if(createNotice("Da chon Danh sach dang ky lop hoc", "")){
//							drawMenu(selected);
//						}
//						else{
//							cleardevice();
//							closegraph();
//						}
//						break;
				}
				break;
			case UP:
				if(selected > 1){
					selected--;
					createMenu(selected);
				}
				break;
			case DOWN:
				if(selected < 4){
					selected++;
					createMenu(selected);
				}
				break;
		}
	}
	getch();
	closegraph();
}

