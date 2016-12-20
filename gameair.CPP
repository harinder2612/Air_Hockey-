#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<fstream.h>
#include<process.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int s=0,q=2,zz=0,rr=0,status=0;
double slope=0;
float sine=0,cosine=0;
long tm=0;

class user{
	char name[30];
	char gender;
	char tem[2];
	char uname[11];
	char pass[50];
	char mobile[10];
	int gtotal;
	int gwon;

public:
user(){
name[0]=gender=tem[0]=uname[0]=pass[0]=mobile[0]='\0';
gtotal=gwon=0;
}
void signup();
char* getuname(){
return uname;
}
char* getpass(){
return pass;
}
void update(){
gtotal++;
}
void won(){
gwon++;
}
};

void user::signup(){
	int loop=1;
	setcolor(0);
	rectangle(274,57,475,85);
	int k=0,l=0,m=0,n=0,o=0;
	while(loop){
		char j=getch();

		//Name
		if(k<30){
			if(j==8){
				k--;
				setfillstyle(1,12);
				bar(275,58,474,84);
				name[k]='\0';
				settextstyle(3,0,1);
				setcolor(0);
				outtextxy(277,60,name);
				continue;
			}
			if(j==13&&name[0]!='\0'){
				setcolor(15);
				rectangle(274,57,475,85);
				setcolor(0);
				rectangle(274,97,475,125);
				k=30;
				continue;
			}
			else{
				name[k]=j;
				k++;
				name[k]='\0';
				settextstyle(3,0,1);
				setcolor(0);
				outtextxy(277,60,name);
			}
		}
		else{
			//User Name
			if(m<11){
				if(j==8){
					m--;
					if(m<0)
					m=0;
					setfillstyle(1,12);
					bar(275,98,474,124);
					uname[l]='\0';
					settextstyle(3,0,1);
					setcolor(0);
					outtextxy(277,100,uname);
					continue;
				}
				if(j==13&&uname[0]!='\0'){
					setcolor(15);
					rectangle(274,97,475,125);
					setcolor(0);
					rectangle(274,137,475,165);
					m=11;
					continue;
				}
				else{
					uname[m]=j;
					m++;
					uname[m]='\0';
					settextstyle(3,0,1);
					setcolor(0);
					outtextxy(277,100,uname);
				}
			}
			//Password
			else{
				if(l<48){
					if(j==8){
						l--;
						setfillstyle(1,12);
						bar(275,138,474,164);
						pass[l]='\0';
						settextstyle(3,0,1);
						setcolor(0);
						for(int i=0;i<l&&i<10;i++)
							outtextxy(277+m*10,140,"*");
						continue;
					}
					if(j==13&&pass[0]!='\0'){
						setcolor(15);
						rectangle(274,137,475,165);
						setcolor(0);
						rectangle(274,177,475,205);
						l=48;
						continue;
					}
					else{
						pass[l]=j;
						l++;
						pass[l]='\0';
						settextstyle(3,0,1);
						setcolor(0);
						for(int i=0;i<l&&i<10;i++)
							outtextxy(277+i*10,140,"*");
						}
				}
		//Gender
				else {
					if(n>=0){
						if(j==8){
							n--;
							setfillstyle(1,12);
							bar(275,178,474,204);
							uname[l]='\0';
							settextstyle(3,0,1);
							setcolor(0);
							tem[0]=(char)gender;
							tem[1]='\0';
							outtextxy(277,180,tem);
							continue;
						}
						if(j==13&&gender!='\0'){
							setcolor(15);
							rectangle(274,177,475,205);
							setcolor(0);
							rectangle(274,217,475,245);
							n=-1;
							continue;
						}
						else{
							if(n==0)
							gender=j;
							n++;
							settextstyle(3,0,1);
							setcolor(0);
							tem[0]=(char)gender;
							tem[1]='\0';
							outtextxy(277,180,tem);
						}
					}
		//Mobile
					else{
						if(o<11){
							if(j==8){
								o--;
								setfillstyle(1,12);
								bar(275,218,474,244);
								mobile[o]='\0';
								settextstyle(3,0,1);
								setcolor(0);
								outtextxy(277,220,mobile);
								continue;
							}
							if(j==13){
								setcolor(15);
								rectangle(274,97,475,245);
								return;
							}
							else{
								mobile[o]=j;
								o++;
								mobile[o]='\0';
								settextstyle(3,0,1);
								setcolor(0);
								outtextxy(277,220,mobile);
							}
						}
					}
				}
			}
		}
	}
	ofstream f("data1.txt",ios::app|ios::binary);
	if(!f){   closegraph();
		cout<<"File Error";
		delay(3000);
		return;
	}
	f.close();
	user a;
	ifstream f1("data1.txt",ios::in|ios::binary);
	if(!f1){
		cout<<"File Error";
		return;
	}
	while(f1.read((char*)&a,sizeof(a))){
		if(strcmpi(a.getuname(),name)==0){
			bar(0,0,639,479);
			settextstyle(1,0,4);
			outtextxy(100,180,"PLEASE CHOOSE ANOTHER USERNAME");
			signup();
		}
	}
	f1.close();
	f.open("data1.txt",ios::app|ios::binary);
	f.write((char*)this,sizeof(a));
	f.close();
}


void login(){
	int gdriver=9,gmode=2;
	initgraph(&gdriver,&gmode,"C:\\tc\\BGI");
	char s[10],s2[100];
	setfillstyle(1,15);
	bar(0,0,639,479);

	setfillstyle(1,7);
	for(int i=0;i<1140;){
		setcolor(0);
		for(int j=0;j<8;j++,i++)
		line(0,i,i,0);
		setcolor(YELLOW);
		for(j=0;j<8;j++,i++)
		line(0,i,i,0);
	}

	setfillstyle(1,0);
	bar(161,0,479,479);

	setfillstyle(1,7);
	bar(180,20,460,80);
	setfillstyle(1,8);
	bar(181,21,459,79);
	setfillstyle(1,0);
	bar(183,23,457,77);
	setcolor(15);
	settextstyle(1,0,4);
	outtextxy(185,28,"RESTRICTED AREA");

	setcolor(7);
	setfillstyle(1,6);
	bar(213,270,427,475);
	setfillstyle(1,7);
	bar(213,230,233,269);
	bar(407,230,427,269);
	sector(320,230,0,180,107,107);
	setcolor(0);
	setfillstyle(1,0);
	sector(320,230,0,180,86,86);
	setfillstyle(1,7);
	bar(210,280,430,330);
	setfillstyle(1,8);
	bar(213,283,427,327);
	setcolor(15);
	settextstyle(1,0,5);
	outtextxy(265,280,"LOGIN");
	setfillstyle(1,15);
	settextstyle(3,0,1);
	outtextxy(215,350,"Username:");
	outtextxy(215,420,"Password:");
	bar(305,350,420,380);
	bar(305,420,420,450);
	setcolor(0);
	for(i=0;i<3;i++)
		rectangle(302+i,347+i,421+i,381+i);
	int y=347;
	int k=0,l=0,m=0;
	for(i=0;i>=0;i++){
		settextstyle(1,0,4);
		if(i%2)
		setcolor(RED);
		else
		setcolor(YELLOW);
		outtextxy(185,28,"RESTRICTED AREA");
		if(kbhit()){
			char j=getch();
			if(y==347&&(k<11||j==8)){
				if(j==8){
					k--;
					setfillstyle(1,15);
					bar(305,350,420,380);
					s[k]='\0';
					settextstyle(3,0,1);
					setcolor(0);
					outtextxy(310,352,s);
					continue;
				}
				if(j==13){
					y=417;
					setcolor(6);
					for(i=0;i<3;i++)
						rectangle(302+i,347+i,421+i,381+i);
					setcolor(0);
					for(i=0;i<3;i++)
						rectangle(302+i,417+i,421+i,451+i);
					continue;
				}
				s[k]=j;
				k++;
				s[k]='\0';
				settextstyle(3,0,1);
				setcolor(0);
				outtextxy(310,352,s);
			}
			else	if(y==417&&(l<48||j==8)){
					if(j==8){
					l--;
					setfillstyle(1,15);
					bar(305,420,420,450);
					s2[l]='\0';
					settextstyle(3,0,1);
					setcolor(0);
					for(m=0;m<l&&m<10;m++)
						outtextxy(310+m*10,422,"*");
					continue;
					}
					if(j==13){
/*					     ifstream f("data.dat",ios::binary|ios::in);
					     user a;
					     if(!f){
						cout<<"File Error";
						return;
					     }
					     while(f.read((char*)&a,sizeof(a)))
						if((strcmp(s,a.getuname()))==0&&(strcmp(s2,a.getpass())==0)){
						a.update();
						*/
						if(strcmp(s,"lakshay")==0&&strcmp(s2,"abc")==0){
	setcolor(7);
	for(int i=0;i<20;i++){
	setfillstyle(1,0);
	bar(213,123,427,240);
	setfillstyle(1,7);
	bar(213,230-i,233,269-i);
	bar(407,230-i,427,269);
	sector(320,230-i,0,180,107,107);
	setcolor(0);
	setfillstyle(1,0);
	sector(320,230-i,0,180,86,86);
	setfillstyle(1,0);
	bar(213,269-i,233,269-i);
	setcolor(7);
	delay(100);
	}
       //	f.close();
	}
	else{
		k=l=0;
		y=347;
		setfillstyle(1,15);
		bar(305,350,420,380);
		bar(305,420,420,450);
		setcolor(RED);
		settextstyle(1,0,2);
		outtextxy(250,220,"INVALID LOGIN");
		setcolor(0);
		for(i=0;i<3;i++)
		rectangle(302+i,347+i,421+i,381+i);
		setcolor(6);
		for(i=0;i<3;i++)
		rectangle(302+i,417+i,421+i,451+i);
		continue;
	}
						return;
					}
					s2[l]=j;
					l++;
					s2[l]='\0';
					settextstyle(3,0,1);
					setcolor(0);
					for(m=0;m<l&&m<10;m++)
						outtextxy(310+m*10,422,"*");
				}
			}

		delay(10);
	}
	getch();
	closegraph();
}

void sign(){
	int gdriver=9,gmode=2;
	initgraph(&gdriver,&gmode,"C:\\tc\\BGI");
	setfillstyle(1,4);
	bar(0,0,639,479);
	setfillstyle(1,12);
	bar(0,0,69,479);
	bar(569,0,639,479);
	setcolor(0);
	setfillstyle(1,7);
	for(int i=0;i<300;i++){
	setfillstyle(1,4);
	bar(130,0,510,i-1);
	setfillstyle(1,7);
	bar(130,i,510,i+169);
	line(130,i,510,i+169);
	line(130,i+169,510,i);
	delay(20);
	}
	settextstyle(1,0,2);
	outtextxy(245,320,"Press Any Key...");
	if(getch()==0)
		getch();
	setfillstyle(1,8);
	int a[8]={130,300,320,384,510,300,320,383};
	for(i=1;i<=190;i++){
		fillpoly(4,a);
		a[7]--;
	delay(10);
	}
	setfillstyle(1,15);
	int p[10]={140,300,140,305,320,384,500,305,500,300};
	for(i=1;i<=290;i++){
		fillpoly(5,p);
		p[1]--;
		p[9]--;
		delay(10);
	}

	setcolor(0);
	outtextxy(150,60,"NAME");
	outtextxy(150,100,"USERNAME");
	outtextxy(150,140,"PASSWORD");
	outtextxy(150,180,"GENDER(M/F)");
	outtextxy(150,220,"MOBILE NO.");

	setcolor(12);
	for(i=0;i<200;i++){
		rectangle(275+i,58,275+i,84);
		rectangle(275+i,98,275+i,124);
		rectangle(275+i,138,275+i,164);
		rectangle(275+i,178,275+i,204);
		rectangle(275+i,218,275+i,244);
		delay(5);
	}
	user v;
	v.signup();
	closegraph();
}

void check(int&,int&,int&,int&,int&,int&);

void move(int&,int&);

void table(){
	//Table
	setfillstyle(1,1);
	bar(150,0,253,15);
	bar(387,0,489,15);
	bar(150,465,253,479);
	bar(387,465,489,479);
	bar(476,0,489,479);
	//Table Inner Border
	setfillstyle(1,9);
	bar(166,16,473,20);
	bar(166,460,473,464);
	bar(166,16,170,464);
	bar(471,16,475,464);
	//Middle Line
	bar(170,237,470,242);
	setcolor(9);
	//Arcs
	for(int i=0;i<6;i++){
		arc(319,17,180,360,80+i);
		arc(319,462,0,180,80+i);
	}
	setcolor(8);
	bar(254,0,386,15);
	bar(254,461,386,479);
	setcolor(0);
}

//Function to Make Disc
void disc(int &x,int &y, int a=8, int b=7){
	//x-coordinates limitations
	if((x<191)||(x>455)){
		for(int i=0;i<10;i++){
			sound(700+10*i);
			delay(4);
		}
		nosound();
		cosine*=-1;
		x+=30*cosine;
	}
	//y-coordinates limitations
	if((y<40)||(y>440)){
			//Goal Conditions
			if(x>254&&x<386){
				if(y<40){
					zz=1;
					rr=1;
					return;
					}
				else{
					zz=1;
					rr=2;
					return;
				}
			}
			else{
				//Striking Sound
				for(int i=0;i<10;i++){
					sound(700+10*i);
					delay(4);
				}
				nosound();
				sine*=-1;
				y+=30*sine;
			}
	}
	setcolor(a);
	setfillstyle(1,b);
	//Making Disc
	for(int i=1;i<4;i++)
		fillellipse(x,y-i,20,20);
}

//Making the puck of Upper Player
void puckc(int &x,int &y, int a=7,int b=8,int c=0){
	//x-coordinates limitations
	if((x<191)||(x>451)){
		if(x<191)
			x+=20;
		else
			x-=20;
		}
	else{
		//y-coordinates limitations
		if((y<45)||(y>216))
			if(y<45)
				y+=20;
			else
				y-=20;
	}
	//Making Puck
	setfillstyle(1,a);
	for(int i=1;i<4;i++){
		fillellipse(x,y-i,20,20);
		setcolor(b);
		}
	setfillstyle(1,c);
	for(i=0;i<6;i++)
		fillellipse(x,y-i,5+c,5+c);
}

//Making Puck of Below Player
void pucku(int &x,int &y, int a=7, int b=8, int c=0){
	//x-coordinates limitations
	if((x<191)||(x>451)){
		if(x<191)
			x+=20;
		else
			x-=20;
		}
	else{
		//y-coordinates limitations
		if((y<262)||(y>440))
			if(y<262)
				y+=20;
			else
				y-=20;
	}
	//Making Puck
	setfillstyle(1,a);
	for(int i=1;i<4;i++){
		fillellipse(x,y-i,20,20);
		setcolor(b);
	}
	setfillstyle(1,c);
	for(i=0;i<6;i++)
		fillellipse(x,y-i,5+c,5+c);
}

void game(int &xu,int &yu,int &xc, int &yc, int &xd, int &yd, int d, int u){
	cosine=0;
	sine=0;
	long tm2=time(NULL);

	//Table make after goal
	for(int i=0;i<225;i++){
		delay(10);
		setcolor(1);
		line(150,240-i,165,240-i);
		line(489,240-i,474,240-i);
		line(150,239+i,165,239+i);
		line(489,239+i,474,239+i);
		setcolor(15);
		line(166,240-i,473,240-i);
		line(166,239+i,473,239+i);
	}          //Table
	//Table Top & Bottom
	setcolor(1);
	while(i<=240){
		line(150,240-i,489,240-i);
		line(150,239+i,489,239+i);
		i++;
		delay(10);
	}             
	//Table Inner Border
	setfillstyle(1,9);
	bar(166,16,473,20);
	bar(166,460,473,464);
	bar(166,16,170,464);
	bar(471,16,475,464);	
	//Middle Line
	bar(170,237,470,242);
	//Arcs
	setcolor(9);
	for(i=0;i<6;i++){
		arc(319,15,180,360,80+i);
		arc(319,464,0,180,80+i);
		delay(50);
	}                  

	//Display the scorecard of the players
	{
	char *s=new char;
	char *t=new char;
	//Player 1
	setfillstyle(SOLID_FILL,7);
	bar(20,40,130,140);
	setfillstyle(SOLID_FILL,0);
	bar(30,50,120,130);
	settextstyle(1,0,1);
	setcolor(15);
	outtextxy(35,45,"PLAYER 1");
	setcolor(RED);
	itoa(u,s,10);
	settextstyle(1,0,4);
	outtextxy(65,80,s);

	//Player 2
	setfillstyle(SOLID_FILL,7);
	bar(20,200,130,300);
	setfillstyle(SOLID_FILL,0);
	bar(30,210,120,290);
	settextstyle(1,0,1);
	setcolor(15);
	outtextxy(35,210,"PLAYER 2");
	setcolor(RED);
	itoa(d,t,10);
	settextstyle(1,0,4);
	outtextxy(65,240,t);
	}

	//Exit and Escape Buttons Board
	setfillstyle(SOLID_FILL,7);
	bar(500,400,620,380);
	setfillstyle(SOLID_FILL,0);
	bar(510,410,610,370);
	settextstyle(1,0,1);
	setcolor(15);
	outtextxy(515,370,"Exit : ESC");
	outtextxy(515,390,"Pause: P");

	delay(500);
	xc=xu=xd=319;
	yc=60;
	yu=422;
	yd=239;

	//Initial Assignment of disc to the players
	if(status==1)
		yd+=100;
	else if(status==2)
			yd-=100;

	//Initial calling of the functions of disc and pucks
	puckc(xc,yc);
	pucku(xu,yu);
	disc(xd,yd);

	//Variables for time
	tm2-=time(NULL);
	tm-=tm2;
	
	//Infinite Loop
	for(i=0;i>-1;i++){
	if(kbhit()){
		int j=getch();
		//j=0 to check whether an arrow key is pressed or not
		//Down Player
		if(j==0){
			j=getch();
			switch(j){
			
			//75 for left key
			case 75:pucku(xu,yu,15,15,15);	
				xu-=20;
				pucku(xu,yu);
				break;

			//77 for right key
			case 77:pucku(xu,yu,15,15,15);
				xu+=20;
				pucku(xu,yu);
				break;
				
			//72 for up key
			case 72:pucku(xu,yu,15,15,15);
				yu-=20;
				pucku(xu,yu);
				break;
				
			//80 for down key
			case 80:pucku(xu,yu,15,15,15);
				yu+=20;
				pucku(xu,yu);
				break;
			
			//To display puck at the same position as it was earlier if there is no movement.
			default:pucku(xu,yu);
			}
		}
		else
			//Up Player
			switch(j){
			
			//w for up key
			case 'w':
			case 'W':       puckc(xc,yc,15,15,15);
					yc-=20;
					puckc(xc,yc);
					break;
					
			//a for left key
			case 'a':
			case 'A':       puckc(xc,yc,15,15,15);
					xc-=20;
					puckc(xc,yc);
					break;

			//S for down key
			case 's':
			case 'S':       puckc(xc,yc,15,15,15);
					yc+=20;
					puckc(xc,yc);
					break;
					
			//d for right key
			case 'd':
			case 'D':       puckc(xc,yc,15,15,15);
					xc+=20;
					puckc(xc,yc);
					break;
					
			//Case for pause
			case 112:	for(long l=0;l<=3600000;l++){
						if(kbhit()){
							int ch=getch();
							if(ch=='p')
								break;
						}
						delay(1);
						if(l==3600000){
							cout<<"Timeout.";
							_cexit();
							}
					}
					break;
			
			//Exit case when P is pressed
			case 27 :       exit(0);
			
			//To display puck at the same position as it was earlier if there is no movement.
		    default :       puckc(xc,yc);
			}
	}
	
	//Check if the disc has collided with the puck
	check(xu,yu,xc,yc,xd,yd);

	//Change the slope of the disc to move it in required direction
	move(xd,yd);
	
	//Make the disc
	disc(xd,yd);
	
	//Make the Table
	table();
	
	delay(10);
	
	if(zz==1){
		zz=0;
		return;
		}
	}
	
}

//Function for the design of the disc in the menu of the game
void discmen(int x,int y, int a=8, int b=7){
	setcolor(a);
	setfillstyle(1,b);
	for(int i=1;i<4;i++)
		fillellipse(x,y-i,25,25);
}

//Function to clear out any variables pressed by the user at any time
void mem(){
	
	//This loop can clear upto 100 keys pressed by user unnecessarily
	for(int i=0;i<100;i++)	
		if(kbhit())
			getch();
}

//Fuction to be called when the game ends
void gmover(){

	int gdriver = 9,gmode=2;
	initgraph(&gdriver,&gmode,"C:\\tc\\BGI");
	
	setcolor(15);
	
	for(int i=1;i<=640;i++){
		rectangle(i,0,i,80);
		rectangle(640-i,80,640-i,160);
		rectangle(i,160,i,240);
		rectangle(640-i,240,640-i,320);
		rectangle(i,320,i,400);
		rectangle(640-i,400,640-i,480);
		delay(10);
	}
	
	setcolor(BLUE);

	line(0,480,640,0);
	delay(1000);

	for(i=0;i<=200;i++){
		line(0,480-i,640-i,0);
		line(i,480,640,i);
		delay(10);
	}

	setcolor(15);

	for(i=150;i<500;i+=20){
		circle(320,240,i);
		delay(20);
	}
	setcolor(15);
	settextstyle(1,0,5);
	outtextxy(210,220,"GAME OVER");
	getch();
	closegraph();
}

//Fuction to be called from menu to tell the user how to play
void howtoplay(){
	int gdriver = 9,gmode=2;
	initgraph(&gdriver,&gmode,"C:\\tc\\BGI");
	setfillstyle(SOLID_FILL,BROWN);
	bar(0,0,639,479);	//Background

	setfillstyle(1,2);
	bar(200,20,440,100);
	settextstyle(7,0,4);
	outtextxy(208,40,"HOW TO PLAY");

	setfillstyle(1,4);
	bar(80,120,260,180);
	bar(320,120,500,180);

	outtextxy(90,130,"PLAYER 1");
	outtextxy(330,130,"PLAYER 2");

	setcolor(0);
	setfillstyle(1,8);

	bar3d(80,200,120,240,5,3);
	bar3d(80,260,120,300,5,3);
	bar3d(80,320,120,360,5,3);
	bar3d(80,380,120,420,5,3);

	setfillstyle(1,7);
	bar(85,195,125,235);
	bar(85,255,125,295);
	bar(85,315,125,355);
	bar(85,375,125,415);

	settextstyle(7,0,2);
	outtextxy(100,200,"W");
	outtextxy(160,200,"UP");
	outtextxy(100,260,"A");
	outtextxy(160,260,"LEFT");
	outtextxy(100,320,"S");
	outtextxy(160,320,"DOWN");
	outtextxy(100,380,"D");
	outtextxy(160,380,"RIGHT");

	setfillstyle(1,8);
	bar3d(320,200,360,240,5,3);
	bar3d(320,260,360,300,5,3);
	bar3d(320,320,360,360,5,3);
	bar3d(320,380,360,420,5,3);

	setfillstyle(1,7);
	bar(325,195,365,235);
	bar(325,255,365,295);
	bar(325,315,365,355);
	bar(325,375,365,415);

	settextstyle(7,0,2);
	setfillstyle(1,BLACK);

	bar(343,200,343,230);

	line(343,200,330,215);

	line(343,200,356,215);

	outtextxy(400,200,"UP");
	outtextxy(340,260,"<-");
	outtextxy(400,260,"LEFT");

	bar(343,320,343,350);

	line(343,352,330,335);

	line(343,350,356,333);

	outtextxy(400,320,"DOWN");
	outtextxy(340,380,"->");
	outtextxy(400,380,"RIGHT");

	getch();
	getch();
	closegraph();
}

//Fuction which makes the menu
void menu(){
	int gdriver = 9,gmode=2;
	initgraph(&gdriver,&gmode,"C:\\tc\\BGI");
	
	setfillstyle(SOLID_FILL,2);
	bar(0,0,639,479);	//Background

	for(int i=0;i<320;i++){
		setcolor(RED);
		rectangle(i,20,i,120);
		setcolor(15);
		rectangle(640-i,20,640-i,120);
		if(i>279){
			setcolor(GREEN);//bkcolor
			rectangle(i-279,20,i-279,120);
			rectangle(918-i,20,918-i,120);
			}
		delay(5);
	}
	//Starting Animation
	for(i=0;i<280;i++){
		setcolor(GREEN);
		rectangle(40+i,20,40+i,120);
		rectangle(600-i,20,600-i,120);
		delay(5);
	}
	
	//Starting Animation
	for(i=0;i<280;i++){
		setcolor(15);
		rectangle(320-i,20,320-i,120);
		setcolor(4);
		rectangle(320+i,20,320+i,120);
		delay(5);
	}
	
	//Displat Air Hockey
	settextstyle(1,0,6);
	setcolor(4);
	outtextxy(130,40,"AIR");
	setcolor(15);
	outtextxy(360,40,"HOCKEY");

	//Starting Animation of the discs
	for(int k=0;k<=213;k++){
		for(int h=1;h<=5;h++)
			discmen(426-k,90+h*70);
		delay(2);
	}

	//Display all the items of the menu
	setcolor(15);
	settextstyle(8,0,2);
	outtextxy(250,150,"PLAY");
	outtextxy(250,220,"HOW TO PLAY");
	outtextxy(250,290,"HIGH SCORES");
	outtextxy(250,360,"FEEDBACK");
	outtextxy(250,430,"EXIT");

	//h is the pressed key
	//l is the y-positon of the currently selected element
	int h=0,l=160;
	
	//Current selected menu item
	discmen(213,l,8,14);
	
	//Check that the current selected element works properly
	while(h!=13){
		h=getch();
		if(h==0){
			h=getch();
			switch(h){
			case 72:
					discmen(213,l);
					l-=70;
					
					if(l<160)
						l=440;
					break;
			case 80:
					discmen(213,l);
					l+=70;
					
					if(l>440)
						l=160;
			}
			discmen(213,l,8,14);
		}
	}

	switch(l){
		case 160:	break;
		case 230:
					howtoplay();
					menu();
					break;
		case 300:
					break;
		case 370:
					gmover();
					break;
		case 440:	exit(0);
	}

	closegraph();
}

void start(){
/*	setbkcolor(WHITE);
	int i;

	setcolor(BLUE);

	for(i=0;i<640;i++){
		line(20,i,50,i);

		if(i%2==0)
			line(i+1,20,i+1,50);

		line(i,20,i,50);
		delay(10);
	}

	int j;

	for(i=0,j=5;i<140;i++){
		if(i>20&&i<40||i>60&&i<80||i>100&&i<120)
			setcolor(WHITE);
		else
			setcolor(j);
		rectangle(80+i,80+i,610-i,450-i);
		delay(20);
		if(i%20==0)
			j++;
	}

	for(i=0;i<40;i++){
		setcolor(5);
		rectangle(340-i,265-i,340+i,265+i);
		delay(10);
	}

	setcolor(WHITE);
	settextstyle(1,0,8);
	outtextxy(325,217,"3");
	delay(500);

	for(i=0;i<40;i++){
		setcolor(6);
		rectangle(340-i,265-i,340+i,265+i);
		delay(10);
	}

	setcolor(WHITE);
	settextstyle(1,0,8);
	outtextxy(325,217,"2");
	delay(400);

	for(i=0;i<40;i++){
		setcolor(7);
		rectangle(340-i,265-i,340+i,265+i);
		delay(10);
	}

	setcolor(WHITE);
	settextstyle(1,0,8);
	outtextxy(325,217,"1");
	delay(300);

	for(i=0;i<40;i++){
		setcolor(8);
		rectangle(340-i,265-i,340+i,265+i);
		delay(10);
	}

	setcolor(WHITE);
	settextstyle(1,0,8);
	outtextxy(325,217,"0");
	delay(200);

	for(i=0;i<40;i++){
		setcolor(9);
		rectangle(340-i,265-i,340+i,265+i);
		delay(10);
	}

	setcolor(WHITE);
	settextstyle(3,0,6);
	outtextxy(310,229,"GO");

	//exit first page:
	setcolor(WHITE);

	for(i=0;i<640;i++){
		rectangle(0,0,20+i+i,20+i+i);
		delay(10);
	}

	for(i=0;i<640;i++){
		rectangle(0,0,20+i,20+i);
	}

	//2nd page
	setcolor(4);

	for(i=0;i<60;i++){
		rectangle(0,0,0+i,0+i);
		rectangle(0,480,0+i,480-i);
		rectangle(640,0,640-i,0+i);
		rectangle(640,480,640-i,480-i);
		delay(25);
	}

	int k,p;

	for(k=10,p=9;k<80;k=k+20){

		setcolor(p++);

		for(i=0;i<181;i+=3){
			arc(320,240,0,2+i,200-k);
			arc(320,240,0,2+i,199-k);
			arc(320,240,0,2+i,198-k);
			arc(320,240,0,2+i,197-k);
			arc(320,240,0,2+i,196-k);
			arc(320,240,0,2+i,195-k);
			arc(320,240,0,2+i,194-k);
			arc(320,240,0,2+i,193-k);
			arc(320,240,0,2+i,192-k);
			arc(320,240,0,2+i,191-k);
			arc(320,240,0,2+i,190-k);
			arc(320,240,180,182+i,200-k);
			arc(320,240,180,182+i,199-k);
			arc(320,240,180,182+i,198-k);
			arc(320,240,180,182+i,197-k);
			arc(320,240,180,182+i,196-k);
			arc(320,240,180,182+i,195-k);
			arc(320,240,180,182+i,194-k);
			arc(320,240,180,182+i,193-k);
			arc(320,240,180,182+i,192-k);
			arc(320,240,180,182+i,191-k);
			arc(320,240,180,182+i,190-k);
			delay(1);
		}

	}

	setcolor(9);

	for(i=0;i<=100;i++){
		line(230,290,230,290-i);
		delay(10);
	}

	for(i=0;i<180;i++){
		rectangle(230,290,230+i,190);
		delay(10);
	}

	setcolor(WHITE);
	settextstyle(1,0,4);
	setusercharsize(130,190,290,190);

	for(i=0;i<30;i++){
		int flag1,flag2;

		if(i%2==0){
			flag1=12;
			flag2=14;
		}

		else{
			flag1=14;
			flag2=12;
		}

		setcolor(flag1);
		outtextxy(295,180,"A I R");
		setcolor(flag2);
		outtextxy(255,230,"H O C K E Y");

		delay(150);
	}

	setcolor(4);

	for(i=0;i<100;i++){
		line(410,290,410,290-i);
		delay(10);
	}

	for(i=0;i<=180;i++){
		setcolor(4);
		rectangle(410-i,290,410-i,190);
		setcolor(WHITE);
		rectangle(411-i,290,411-i,190);
		delay(4);
	}

	setcolor(WHITE);
	for(i=0;i<=100;i++){
		line(230,290,230,290-i);
		delay(10);
	}

	for(k=70;k>0;k=k-20){
		setcolor(WHITE);

		for(i=0;i<181;i+=3){
			arc(320,240,0,2+i,200-k);
			arc(320,240,0,2+i,199-k);
			arc(320,240,0,2+i,198-k);
			arc(320,240,0,2+i,197-k);
			arc(320,240,0,2+i,196-k);
			arc(320,240,0,2+i,195-k);
			arc(320,240,0,2+i,194-k);
			arc(320,240,0,2+i,193-k);
			arc(320,240,0,2+i,192-k);
			arc(320,240,0,2+i,191-k);
			arc(320,240,0,2+i,190-k);
			arc(320,240,180,182+i,200-k);
			arc(320,240,180,182+i,199-k);
			arc(320,240,180,182+i,198-k);
			arc(320,240,180,182+i,197-k);
			arc(320,240,180,182+i,196-k);
			arc(320,240,180,182+i,195-k);
			arc(320,240,180,182+i,194-k);
			arc(320,240,180,182+i,193-k);
			arc(320,240,180,182+i,192-k);
			arc(320,240,180,182+i,191-k);
			arc(320,240,180,182+i,190-k);

			delay(1);
		}
	}

	setcolor(WHITE);

	for(i=60;i>0;i--){
		rectangle(0,0,0+i,0+i);
		rectangle(0,480,0+i,480-i);
		rectangle(640,0,640-i,0+i);
		rectangle(640,480,640-i,480-i);
		delay(50);
	}

	//2nd page
	setcolor(BLUE);

	for(i=0;i<640;i++){
		line(0,0,0+i,480);
		line(640,480,640-i,0);
		delay(5);
	}

	setcolor(WHITE);
	settextstyle(1,0,5);
	delay(1000);
	outtextxy(270,100,"THIS");
	delay(1000);
	outtextxy(265,140,"GAME");
	delay(1000);
	outtextxy(300,180,"IS");
	delay(1000);
	outtextxy(150,220,"BROUGHT TO YOU");
	delay(1000);
	outtextxy(300,260,"BY");
	delay(500);

	setcolor(LIGHTRED);

	for(i=0;i<150;i++){
		rectangle(0+i,40,0+i,70);
		delay(10);
	}

	setcolor(10);
	settextstyle(1,0,2);
	outtextxy(2,40,"L A K S H A Y");

	delay(1000);
	settextstyle(1,0,5);
	setcolor(WHITE);
	outtextxy(280,300,"AND");

	delay(1000);

	for(i=0;i<150;i++){
		setcolor(LIGHTRED);
		rectangle(640-i,380,640-i,410);
		delay(5);
	}

	setcolor(10);
	settextstyle(1,0,3);
	outtextxy(510,380,"HARINDER");

	for(i=0;i<20;i++){
		setcolor(i+2);
		settextstyle(1,0,2);
		outtextxy(2,40,"L A K S H A Y");
		settextstyle(1,0,3);
		outtextxy(510,380,"HARINDER");
		delay(200);
	}
*/
	//3rd page:
 /*	setcolor(12);

	for(i=0;i<640;i++){
		line(0+i,0,0+i,480);
		delay(1);
	}

	setcolor(WHITE);

	for(i=0;i<80;i++){
		rectangle(0+i,210,0+i,230);
		rectangle(0+i,240,0+i,260);
		delay(15);
	}

	setcolor(8);
	setlinestyle(0,0,3);

	circle(100,37,35);
	circle(100,37,36);
	line(100,72,100,2);
	line(65,37,135,37);

	circle(540,37,35);
	circle(540,37,36);
	line(540,72,540,2);
	line(505,37,575,37);

	circle(100,435,35);
	circle(100,435,36);
	line(100,400,100,470);
	line(65,435,135,435);

	circle(540,435,35);
	circle(540,435,36);
	line(540,400,540,470);
	line(505,435,575,435);

	for(i=0;i<133;i++){
		setcolor(WHITE);
		line(0,210-i,80,210-i);
		line(0,260+i,80,260+i);
		setcolor(12);
		line(0,230-i,80,230-i);
		line(0,240+i,80,240+i);
		delay(50);
	}

	for(i=0;i<500;i++){
		setcolor(WHITE);
		rectangle(0+i,239,0+i,241);

		if(i>300){
			setcolor(12);
			rectangle(i-300,239,i-300,241);
		}

		delay(2);
	}

	setcolor(WHITE);

	for(i=0;i<50;i++){
		line(200,239-i,500,239-i);
		line(200,241+i,500,241+i);
		delay(15);
	}

	settextstyle(1,0,5);
	setcolor(12);
	outtextxy(210,200,"LOADING>>>...");
	delay(1000);


	int flag2,n,x;

	for(i=0,x=0;i<70;i++,x=x+10){
		setcolor(WHITE);
		rectangle(0+x,78,80+x,98);
		floodfill(1+x,79,12);
		rectangle(0+x,372,80+x,392);
		floodfill(1+x,373,12);

		if(i%2==0){
			flag2=12;
			n=8;
		}

		else{
			n=12;
			flag2=8;
		}

		setcolor(flag2);
		line(100,72,100,2);
		line(65,37,135,37);
		line(540,72,540,2);
		line(505,37,575,37);
		line(100,400,100,470);
		line(65,435,135,435);
		line(540,400,540,470);
		line(505,435,575,435);

		setcolor(n);

		line(76,11,122,62);
		line(76,62,122,11);
		line(440+76,11,440+122,62);
		line(440+76,62,440+122,11);
		line(76,410,122,460);
		line(76,460,122,410);
		line(440+76,410,440+122,460);
		line(440+76,460,440+122,410);

		if(i>20)
			delay(120);
		else
			delay(200);
	}
*/
	  int i,j;

	setcolor(14);

	for(i=0;i<600;i++){
		line(0,0+i,0+i,0);
		line(640,480-i,640-i,480);
		delay(10);
	}

	setcolor(10);

	for(i=0;i<100;i++){
		circle(320,240,400-(3*i));
		delay(100);
	}
	setfillstyle(1,8);
	bar(250,180,390,230);
	bar(250,250,390,300);
	setfillstyle(1,RED);
	bar(255,185,385,225);
	bar(255,255,385,295);
	setcolor(YELLOW);
	settextstyle(1,0,3);
	outtextxy(290,190,"LOGIN");
	outtextxy(265,260,"NEW USER");
	int yl=178;
	j=1;
	setcolor(7);
	rectangle(248,yl,392,yl+54);
	rectangle(249,yl+1,391,yl+53);
	while(j){
		if(kbhit()){
			char j=getch();
			if(j==0){
				setcolor(14);
				rectangle(248,yl,392,yl+54);
				rectangle(249,yl+1,391,yl+53);
				if(yl==178)
					yl+=70;
				else
					yl-=70;
				setcolor(7);
				rectangle(248,yl,392,yl+54);
				rectangle(249,yl+1,391,yl+53);
				j=getch();
			}
			else	if(j==13){
					if(yl==178){
						login();
						return;
						}
					else{
						sign();
						return;
						}

				}
		}
	}
	getch();
	cleardevice();
}

void main(){
	int gdriver = DETECT,gmode=2,i,xc,xu,xd,yc,yu,yd,j,u=0,d=0;

	initgraph(&gdriver,&gmode,"C:\\tc\\BGI");
	//Call the fuction of starting animations
	start();
	closegraph();

	//Call the fuction of the menu
	menu();

	//Actual starting of the game
	initgraph(&gdriver,&gmode,"C:\\tc\\BGI");

	setfillstyle(SOLID_FILL,2);

	bar(0,0,639,479);	//Background

	//Time elapsed in the game
	tm=time(NULL);

	while((d<7&&u<7)&&((time(NULL)-tm)<420)){
		//Call the fuction of starting of the game
		game(xu,yu,xc,yc,xd,yd,d,u);

		if(rr==1){
	//	      	cout<<"Down Wins.";
			d++;
			status=1;
			rr=0;
			mem();

			for(i=0;i<150;i++){
				setcolor(10);
				rectangle(319-i,240-i,322+i,240+i);
				delay(5);
			}

			for(i=0;i<300;i++){
				setcolor(LIGHTBLUE);
				line(169,89+i,189,89+i);
				line(169+i,389,169+i,369);
				line(469-i,89,469-i,109);
				line(471,389-i,449,389-i);
				 delay(5);
			}
			outtextxy(240,220,"Goal By Player 2");
			settextstyle(2,0,5);
			setcolor(WHITE);
			getch();
			}
		else{
	//		cout<<"Up Wins";
			status=2;
			rr=0;
			u++;
			mem();

			for(i=0;i<150;i++){
				setcolor(10);
				rectangle(319-i,240-i,322+i,240+i);
				delay(5);
			}

			for(i=0;i<300;i++){
				setcolor(LIGHTBLUE);
				line(169,89+i,189,89+i);
				line(169+i,389,169+i,369);
				line(469-i,89,469-i,109);
				line(471,389-i,449,389-i);
				 delay(5);
			}
			outtextxy(240,220,"Goal By Player 1");
			settextstyle(2,0,5);
			setcolor(WHITE);
			getch();
			}
	}
	//Call the function of ending of the game
	gmover();

	getch();
	closegraph();
}

//Call the function of starting of the game
void check(int &xu,int &yu,int &xc,int &yc,int &xd,int &yd){

	long a,b,c,d;
	a=xd-xu;
	b=yd-yu;
	a*=a;
	b*=b;
	a+=b;
	
	if((sqrt(a))<=50){
		
		for(int i=0;i<10;i++){
			sound(700+10*i);
			delay(4);
		}
		
		nosound();
		
		if((xd-xu)==0){
			if(yu>yd)
				s=1;
			else if(yu<yd)
				s=2;
			}

		else{   
			s=3;
			a=xd-xu;
			b=yd-yu;
			c=a*a;
			d=b*b;
			c+=d;
			c=sqrt(c);
			cosine=float(a)/float(c);
			sine=float(b)/float(c);
			pucku(xu,yu);
			puckc(xc,yc);
		}
	}
	
	c=xd-xc;
	d=yd-yc;
	c*=c;
	d*=d;
	c+=d;
	c=sqrt(c);
	
	if(c<=50){
	
		for(int i=0;i<10;i++){
			sound(700+10*i);
			delay(4);
		}

		nosound();
		
		if((xd-xc)==0){
			if(yc>yd)
				s=4;
			else if(yc<yd)
				s=5;
			}
		
		else{
			s=6;
			a=xd-xc;
			b=yd-yc;
			c=a*a;
			d=b*b;
			c+=d;
			c=sqrt(c);
			cosine=float(a)/float(c);
			sine=float(b)/float(c);
			pucku(xu,yu);
			puckc(xc,yc);
		}
	}
}

void move(int &xd,int &yd){

	switch(s){
	
	case 1: disc(xd,yd,15,15);
		yd-=10;
		break;
	
	case 2: disc(xd,yd,15,15);
		yd+=10;
		break;
	
	case 3: disc(xd,yd,15,15);
		xd+=25*cosine;
		yd+=25*sine;
		disc(xd,yd);
		delay(45);   //prev 50
		break;
	
	case 4: disc(xd,yd,15,15);
		yd-=10;
		break;
	
	case 5: disc(xd,yd,15,15);
		yd+=10;
		break;
	
	case 6: disc(xd,yd,15,15);
		xd+=25*cosine;
		yd+=25*sine;
		disc(xd,yd);
		delay(45);   //prev 50
		
	}
}