const int UP = 72; 
const int DOWN = 80;
const int ET = 13;
const int SPACE = 32;
const int BP = 8; // backspace
const int SPOINTX = 0;
const int SPOINTY = 0;
const int LPOINTX = 1600;
const int LPOINTY = 800;

const int HEADSPOINTX = 0;
const int HEADSPOINTY = 0;
const int HEADLPOINTX = 1600;
const int HEADLPOINTY = 60; // chinh sua

const int MENUSPOINTX = 0;
const int MENUSPOINTY = 70;
const int MENULPOINTX = 400;
const int MENULPOINTY = 280;

const int BOTTSPOINTX = 0;
const int BOTTSPOINTY = 700;
const int BOTTLPOINTX = 1600;
const int BOTTLPOINTY = 700;

const int NOTISPOINTX = 500; // notice
const int NOTISPOINTY = 200;
const int NOTILPOINTX = 1110;
const int NOTILPOINTY = 400;

const int LISTSPOINTX = 420;
const int LISTSPOINTY = 70;
const int LISTLPOINTX = 1600;
const int LISTLPOINTY = 700;

const int TABLSPOINTX = 422;
const int TABLSPOINTY = 190;
const int TABLLPOINTX = 1598;
const int TABLLPOINTY = 480;

const int BOXSPOINTX = LISTSPOINTX + 250;
const int BOXSPOINTY = LISTSPOINTY + 70;
const int BOXLPOINTX = LISTSPOINTX + 450;
const int BOXLPOINTY = LISTSPOINTY + 100;

void setDefault(){
	setbkcolor(15); // mac dinh nen la mau trang
	setcolor(0); // mac dinh van ban la mau den
	setfillstyle(SOLID_FILL, WHITE); // mac dinh to khung hinh la mau trang
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1); // mac dinh font complex, co chu la 1
	setlinestyle(0, 1, 1);
}

void createHeader(){
	setfillstyle(SOLID_FILL, LIGHTBLUE); // tao trang head 
	bar(HEADSPOINTX, HEADSPOINTY, HEADLPOINTX, HEADLPOINTY); // tao hinh chu nhat to san mau nen
	
	setcolor(BLACK);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 4); // tao trang head
	outtextxy(40, 10, "TRANG CHU");
	
	setDefault();
}

void createBottom(){
	setlinestyle(0, 0, 2); // tao trang bottom
	line(BOTTSPOINTX, BOTTSPOINTY, BOTTLPOINTX, BOTTLPOINTY); // tao duong ke 
	outtextxy(10, 710, "Thong tin them : "); 
	
	setDefault();
}

int createNotice(char *text1, char* text2){
	cleardevice();
	createHeader();
	
	setcolor(LIGHTRED); // thiet lap mau chu
	outtextxy(750, 205, "Thong bao!");
	setcolor(BLACK);
	rectangle(NOTISPOINTX, NOTISPOINTY, NOTILPOINTX, NOTILPOINTY); // tao hop thong bao to khung theo mau chu k to mau nen
	
	outtextxy(530, 250, text1);
	outtextxy(530, 280, text2);
	outtextxy(530, 310, "Nhan Enter de tiep tuc/ Esc de thoat chuong trinh");
	
	setDefault;
	
	char key;
	key = getch();
	cleardevice();
	if(key == ET){
		return 1;
	}
	return 0;
}

void createMenu(int selected){
	
	// tao menu 1
	
	cleardevice();
	setbkcolor(WHITE);
	cleardevice(); // xoa man hinh va to mau nen

	createHeader(); // tao header 
	setcolor(BLACK);
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);

	if(selected == 1){
		setbkcolor(LIGHTBLUE);
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		bar(MENUSPOINTX, MENUSPOINTY, MENUSPOINTX + 400, MENUSPOINTY + 40);
		outtextxy(10, MENUSPOINTY + 10, "Danh sach lop tin chi");
	}
	else{
		setbkcolor(WHITE);
		setfillstyle(SOLID_FILL, WHITE);
		bar(MENUSPOINTX, MENUSPOINTY, MENUSPOINTX + 400, MENUSPOINTY + 40);
		outtextxy(10, MENUSPOINTY + 10, "Danh sach lop tin chi");
	}
	setcolor(LIGHTGRAY);
	rectangle(MENUSPOINTX, MENUSPOINTY, MENUSPOINTX + 400, MENUSPOINTY + 40);
	
	// tao menu 2
	
	setcolor(BLACK);
	if(selected == 2){
		setbkcolor(LIGHTBLUE);
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		bar(MENUSPOINTX, MENUSPOINTY + 40, MENUSPOINTX + 400, MENUSPOINTY + 80);
		outtextxy(10, MENUSPOINTY + 50 , "Danh sach sinh vien");
	}
	else{
		setbkcolor(WHITE);
		setfillstyle(SOLID_FILL, WHITE);
		bar(MENUSPOINTX, MENUSPOINTY + 40, MENUSPOINTX + 400, MENUSPOINTY + 80);
		outtextxy(10, MENUSPOINTY + 50 , "Danh sach sinh vien");
	}
	setcolor(LIGHTGRAY);
	rectangle(MENUSPOINTX, MENUSPOINTY + 40, MENUSPOINTX + 400, MENUSPOINTY + 80);
	
	// tao menu 3
	setcolor(BLACK);
	if(selected == 3){
		setbkcolor(LIGHTBLUE);
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		bar(MENUSPOINTX,  MENUSPOINTY + 80, MENUSPOINTX + 400, MENUSPOINTY + 120);
		outtextxy(10, MENUSPOINTY + 90, "Danh sach mon hoc");
	}
	else{
		setbkcolor(WHITE);
		setfillstyle(SOLID_FILL, WHITE);
		bar(MENUSPOINTX,  MENUSPOINTY + 80, MENUSPOINTX + 400, MENUSPOINTY + 120);
		outtextxy(10, MENUSPOINTY + 90, "Danh sach mon hoc");
	}
	setcolor(LIGHTGRAY);
	rectangle(MENUSPOINTX,  MENUSPOINTY + 80, MENUSPOINTX + 400, MENUSPOINTY + 120);

	
	// tao menu 4
	setcolor(BLACK);
	if(selected == 4){
		setbkcolor(LIGHTBLUE);
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		bar(MENUSPOINTX, MENUSPOINTY + 120, MENUSPOINTX + 400, MENUSPOINTY + 160);
		outtextxy(10, MENUSPOINTY + 130, "Danh sach dang ky lop hoc");
	}
	else{
		setbkcolor(WHITE);
		setfillstyle(SOLID_FILL, WHITE);
		bar(MENUSPOINTX, MENUSPOINTY + 120, MENUSPOINTX + 400, MENUSPOINTY + 160);
		outtextxy(10, MENUSPOINTY + 130, "Danh sach dang ky lop hoc");
	}
	setcolor(LIGHTGRAY);
	rectangle(MENUSPOINTX, MENUSPOINTY + 120, MENUSPOINTX + 400, MENUSPOINTY + 160);

	setDefault();
	createBottom();
	
}

void createTable(char *text){ // tao khung lon ben ngoai
	
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY + 60); // ve khung list
	outtextxy(LISTSPOINTX + 10, LISTSPOINTY + 10, text);
	
	setlinestyle(0, 0, 1);
	setcolor(LIGHTGRAY);
	line(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY);
	line(LISTSPOINTX, LISTSPOINTY, LISTSPOINTX, LISTLPOINTY); // can le
	
	setDefault();
}

void createList(){ // tao khung nho ben trong
	
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	setlinestyle(0, 0, 1);
	setcolor(LIGHTGRAY);
	
	bar(TABLSPOINTX, TABLSPOINTY, TABLLPOINTX, TABLSPOINTY + 40 ); // tao table
	rectangle(TABLSPOINTX, TABLSPOINTY, TABLLPOINTX, TABLLPOINTY);
	line(TABLSPOINTX, TABLSPOINTY + 40, TABLLPOINTX, TABLSPOINTY + 40);
	line(TABLSPOINTX, TABLSPOINTY + 90, TABLLPOINTX, TABLSPOINTY + 90);
	line(TABLSPOINTX, TABLSPOINTY + 140, TABLLPOINTX, TABLSPOINTY + 140);
	line(TABLSPOINTX, TABLSPOINTY + 190, TABLLPOINTX, TABLSPOINTY + 190);
	line(TABLSPOINTX, TABLSPOINTY + 240, TABLLPOINTX, TABLSPOINTY + 240);
	
	line(TABLSPOINTX + 130, TABLSPOINTY, TABLSPOINTX + 130, TABLLPOINTY);
	line(TABLSPOINTX + 330, TABLSPOINTY, TABLSPOINTX + 330, TABLLPOINTY);	
	line(TABLSPOINTX + 500, TABLSPOINTY, TABLSPOINTX + 500, TABLLPOINTY);	
	line(TABLSPOINTX + 670, TABLSPOINTY, TABLSPOINTX + 670, TABLLPOINTY);	
	line(TABLSPOINTX + 840, TABLSPOINTY, TABLSPOINTX + 840, TABLLPOINTY);	
	line(TABLSPOINTX + 1010, TABLSPOINTY, TABLSPOINTX + 1010, TABLLPOINTY);	
	
	
	setDefault();
}


void drawFindStudent(char *text){
	createTable(text);
	createList();
	
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 2); // tao khung nhap mssv
	outtextxy(LISTSPOINTX + 10, LISTSPOINTY + 80, "Vui long nhap MSSV:");
	rectangle(BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY); 

	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1); // tieu de tren bang danh sach
	setbkcolor(LIGHTBLUE);
	setcolor(WHITE);
	outtextxy(TABLSPOINTX + 10, TABLSPOINTY + 10, "MSSV");
	outtextxy(TABLSPOINTX + 140, TABLSPOINTY + 10, "HO");
	outtextxy(TABLSPOINTX + 340, TABLSPOINTY + 10, "TEN");
	outtextxy(TABLSPOINTX + 510, TABLSPOINTY + 10, "PHAI");
	outtextxy(TABLSPOINTX + 680, TABLSPOINTY + 10, "SDT");
	outtextxy(TABLSPOINTX + 850, TABLSPOINTY + 10, "MA LOP");
	outtextxy(TABLSPOINTX + 1020, TABLSPOINTY + 10, "KHOA");
	
	setDefault();
}
