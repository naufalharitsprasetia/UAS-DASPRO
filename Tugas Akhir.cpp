#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <string>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <fstream> // ofstream,ifstream,fstream

using namespace std;
time_t a=time(0);
string b=ctime(&a);

	// File Class fstream
	ofstream Input;
	ifstream Output;

string username_berhasil_login; // Primary Key
char LogOut,keluar;	
	
void delay(void){
	int delay;
	delay = 1;
	while(delay<2000000){
	delay++;	
	}
	
}
void gotoxy(int x,int y){
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void loading(){
	int i,j;
	char ulang;
	for (int i = 0;i<=110;i++){
		gotoxy(i,12);
//		system("color 81");
		printf("-");
		gotoxy(i,14);
		printf("-");
			delay();
			cout<<endl;
	}
	for (int i = 30;i<=100;i++){
	gotoxy(45,13);
	printf("loading  ");
	cout<<i<<" %";
	delay();	
	}
}
class Home {
	public :
	char pilih_home;
	string login_name,login_pass;
	string nama_lengkap,asal,reg_username,reg_pass,reg_pass2,reg_file;
	int jml_user=0;
	bool kondisi_user;
	string daftar_Users[50],daftar_Users_password[50];
	string user_file,password_file;
	Home() {

	}	
	void connect(){
				jml_user = 0;
				Output.open("Users/Daftar_User.txt");
				while(!Output.eof()){
				Output >> user_file;
				daftar_Users[jml_user] = user_file; // Data (username) jadi array
				jml_user++;
				}
				Output.close();
	}
	void cls(){
		system("cls");
	}
	void home(){
		cls();
		connect();
		cout << "\t\t\t\t+----------------------------+" << endl;
		cout << "\t\t\t\t|   1. LOGIN / SIGN IN       |" << endl;
		cout << "\t\t\t\t|   2. REGISTRASI / SIGN UP  |" << endl;
		cout << "\t\t\t\t|   3. ABOUT                 |" << endl;
		cout << "\t\t\t\t|   4. EXIT                  |" << endl;
		cout << "\t\t\t\t+----------------------------+" << endl;
		cout << "\t\t\t\t+------- >>> PILIH  = ";
		cin >> pilih_home;
		switch (pilih_home) {
			case '1' : 
				login();
				break;
			case '2' :
				registrasi();
				home();
				break;
			case '3':
				about();
				home();
				break;
			case '4':
//				home();
				exit();
				break;
		 	default :
		 		home();
		 		break;
		}
	}
	void login(){
		cout << "\t\t\t\t  ------------------------" << endl;
		cout << "\t\t\t\t  -------- LOGIN ---------" << endl;
		cout << "\t\t\t\t  ------------------------" << endl;
		cout << endl;
		char lupa_password;
		int salah= 0;
		int reset;
		string password_out;
		cout << "\t\t\t--------------------------" << endl;
		cout << "\t\t\tUSERNAME = ";
		cin >> login_name;
		username_berhasil_login = login_name; 
		salah_password:
//				START:
				cout << "\t\t\t--------------------------" << endl;
				cout << "\t\t\tPassword = ";
//				cout<<"\nEnter Password  : ";
			    char pass[32];//to store password.
			    int x = 0;
			    char a;//a Temp char
			    for(x=0;;)//infinite loop
			    {
			        a=getch();//stores char typed in a
			        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
			            //check if a is numeric or alphabet
			        {
			            pass[x]=a;//stores a in pass
			            ++x;
			            cout<<"*";
			        }
			        if(a=='\b'&&x>=1)//if user typed backspace
			            //i should be greater than 1.
			        {
			            cout<<"\b \b";//rub the character behind the cursor.
			            --x;
			        }
			        if(a=='\r')//if enter is pressed
			        {
			            pass[x]='\0';//null means end of string.
			            break;//break the loop
			        }
			    }

		cout << "\n\t\t\t--------------------------" << endl;
		for (int i=0;i<jml_user-1;i++){
//			cout << "Users = " << daftar_Users[i] << endl;
			if (login_name == daftar_Users[i]) {
					kondisi_user = true;
				string folder_user = "Users/"+daftar_Users[i]+"/"; // Buat Folder Tiap User Yg Daftar
				string file_password = folder_user+"User_"+daftar_Users[i]+"_Password.txt";
				Output.open(file_password.c_str());
				Output >> password_out;
				Output.close();	
				if (string(pass) != password_out){ // jika password salah
					cout << "\t\t\tPassword SALAH !!!!" << endl;
					salah++;
					if (salah > 3){
						cout << "\t\t\t--------------------------" << endl;
						cout << "\t\t\tLUPA PASSWORD ???? (y/n) = ";
						cin >> lupa_password;
						if (lupa_password == 'y'){
							START:
							cout << "\t\t\t--------------------------" << endl;
							cout << "\t\t\tRESET PASSWORD ANDA === ";
										    char pass2[32];//to store password.
										    int y = 0;
										    char b;//a Temp char
										    for(y=0;;)//infinite loop
										    {
										        b=getch();//stores char typed in a
										        if((b>='a'&&a<='z')||(b>='A'&&a<='Z')||(b>='0'&&a<='9'))
										            //check if a is numeric or alphabet
										        {
										            pass2[y]=b;//stores a in pass
										            ++y;
										            cout<<"*";
										        }
										        if(b=='\b'&&y>=1)//if user typed backspace
										            //i should be greater than 1.
										        {
										            cout<<"\b \b";//rub the character behind the cursor.
										            --y;
										        }
										        if(b=='\r')//if enter is pressed
										        {
										            pass2[y]='\0';//null means end of string.
										            break;//break the loop
										        }
										    }
											    if(y<=5)
										    {
										    	cout << "\n\t\t\t----------------------";
										        cout <<"\n\t\t\t-----Minimum 6 digits needed.-----\n\t\t\t---------Enter Again---------\n";
										        getch();//It was not pausing :p
												goto START;
										    }	
							password_out = string(pass2);
							Input.open(file_password.c_str());
							Input << password_out << endl;
							Input.close();
							cout << endl;
						} 
					}	
					goto salah_password;
				}
				cout << "\t\t\t ---- SELAMAT ANDA BERHASIL LOGIN !!! ----" << endl;
				getchar();
				getchar();
			}
		} if (!kondisi_user) { // kalo gak ada
			cout << "\t\t\t --- MAAF, USERNAME YANG ANDA MASUKKAN TIDAK TERDAFTAR --- \t\t\t" << endl;
			getchar();
			getchar();
			home();
		}   
	}
	void registrasi(){
		cout << "\t\t\t--------------------------" << endl;
		cout << "\t\t\tMASUKKAN NAMA LENGKAP ANDA = ";
		cin.ignore();
		getline(cin,nama_lengkap);
		cout << "\t\t\t--------------------------" << endl;
		cout << "\t\t\tMASUKKAN ASAL ANDA = ";
		getline(cin,asal);
		reg_name_salah:
		cout << "\t\t\t--------------------------" << endl;
		cout << "\t\t\tUsername = ";
		cin >> reg_username;
		for (int i=0;i<jml_user;i++){
			if (reg_username == daftar_Users[i]) {
				cout << "\t\t\t--------------------------" << endl;
				cout << "\t\t\tUSERNAME SUDAH ADA !!!" << endl;
				goto reg_name_salah;
			} 
		}
//		cout << "\t\t\t--------------------------" << endl;
//		cout << "\t\t\tPassword = ";
//		cin >> reg_pass;
//		cout << "\t\t\t--------------------------" << endl;
//		cout << "\t\t\tKonfirmasi password = ";
//		cin >> reg_pass2;
			    int wrong_confirm = 0,wrong_pass =0;		
				START:
				cout << "\t\t\t--------------------------" << endl;
				cout << "\t\t\tPassword = ";
//				cout<<"\nEnter Password  : ";
			    char pass[32];//to store password.
			    int x = 0;
			    char a;//a Temp char
			    for(x=0;;)//infinite loop
			    {
			        a=getch();//stores char typed in a
			        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
			            //check if a is numeric or alphabet
			        {
			            pass[x]=a;//stores a in pass
			            ++x;
			            cout<<"*";
			        }
			        if(a=='\b'&&x>=1)//if user typed backspace
			            //i should be greater than 1.
			        {
			            cout<<"\b \b";//rub the character behind the cursor.
			            --x;
			        }
			        if(a=='\r')//if enter is pressed
			        {
			            pass[x]='\0';//null means end of string.
			            break;//break the loop
			        }
			    }
//			    cout<<"\nYou entered : "<<pass;
			    //here we can even check for minimum digits needed
			    if(x<=5)
			    {
			    	cout << "\n\t\t\t----------------------";
			        cout <<"\n\t\t\t-----Minimum 6 digits needed.-----\n\t\t\t---------Enter Again---------\n";
			        getch();//It was not pausing :p
			        wrong_pass++;
					goto START;
			    }
				
				// KONFIRMASI PASSWORD
				salah_konfirmasi:
				cout << "\n\t\t\t--------------------------" << endl;
				cout << "\t\t\tKonfirmasi password = ";
//				cout<<"\nConfirm Your Password  : ";
			    char pass2[32];//to store password.
			    int y = 0;
			    char b;//a Temp char
			    for(y=0;;)//infinite loop
			    {
			        b=getch();//stores char typed in a
			        if((b>='a'&&b<='z')||(b>='A'&&b<='Z')||(b>='0'&&b<='9'))
			            //check if a is numeric or alphabet
			        {
			            pass2[y]=b;//stores a in pass
			            ++y;
			            cout<<"*";
			        }
			        if(b=='\b'&&y>=1)//if user typed backspace
			            //i should be greater than 1.
			        {
			            cout<<"\b \b";//rub the character behind the cursor.
			            --y;
			        }
			        if(b=='\r')//if enter is pressed
			        {
			            pass2[y]='\0';//null means end of string.
			            break;//break the loop
			        }
			    }
//			    cout<<"\nYou entered : "<<pass2;
			    //here we can even check for minimum digits needed
				if(string(pass)!= string(pass2))
			    {
			    	cout <<"\n\t\t\t-------------------------------";
			        cout<<"\n\t\t\t---------Your Confirm Password Is Not Same.----------\n\t\t\t---------Enter Again---------\n";
			        getch();//It was not pausing :p
			        goto salah_konfirmasi;
			        wrong_confirm++;
			    }
			    if(string(pass) == string(pass2))
			    {
//			        cout<<"\nYour Password Is Same.\n";
//			        getch();//It was not pausing :p
//			        goto salah_konfirmasi;
			    }
				
		
//		if (pass != pass2){
//			cout << "\t\t\t--------------------------" << endl;
//			cout << "\t\t\tKONFIRMASI PASSWORD ANDA SALAH" << endl;
//			goto salah_konfirmasi;
//		}

		string folder_user;
		string reg_file_profile;
		folder_user = "Users/"+reg_username+"/"; // Buat Folder Tiap User Yg Daftar
		CreateDirectory(folder_user.c_str(),NULL);
		reg_file = folder_user + "User_" + reg_username + "_Profile.txt"; // buat nama file
		// Profile = Nama Lengkap & Asal 
		Input.open(reg_file.c_str());
		Input << nama_lengkap << endl;
		Input << asal << endl;
		Input.close();
//		// Username & password 
		Input.open("Users/Daftar_User.txt",ios::app);
		Input << reg_username << endl;
		Input.close();
		string file_password = folder_user+"User_"+reg_username+"_Password.txt";
		Input.open(file_password.c_str());
		Input << pass << endl;
		Input.close();
		cout << endl;
		cout << endl;		
		cout << "\t\t\t --------------------------------------------------------------" << endl;
		cout << "\t\t\t ------- SELAMAT, ANDA TELAH BERHASIL REGISTRASI !!!! ---------" << endl;
		cout << "\t\t\t --------------------------------------------------------------" << endl;
		getchar();
		getchar();

	}
	void about(){
		cls();
		cout << "\t\t\t\t|----------------------------------|" << endl;
		cout << "\t\t\t\t|-------------- ABOUT -------------|" << endl;
		cout << "\t\t\t\t|----------------------------------|" << endl;
		cout << "\t\t\t\t| Aplikasi Hotel Mahalli Alexander |" << endl;
		cout << "\t\t\t\t|----------------------------------|" << endl;
		cout << "\t\t\t\t|    Copyright , Naufal & Rizki    |" << endl;
		cout << "\t\t\t\t|----------------------------------|" << endl;
		getchar();
		getchar();
	}
	void exit() {
		error:
		system("cls");
		cout << "\t\t\t\t---------------------------------------------" << endl;
		cout << "\t\t\t\t------------------   EXIT   -----------------" << endl;
		cout << "\t\t\t\t---------------------------------------------" << endl;
		cout << "\t\t\t\t APAKAH ANDA YAKIN INGIN KELUAR ??? (y/n) : ";
		cin >> keluar;
		if(keluar == 'y'){
			
		} else if (keluar == 'n'){
			home();
		} else {
			goto error;
		}
		
	}
	void reset() {
		username_berhasil_login = "";
		kondisi_user =false;
	}		
	void footer(){
		system("CLS");
		cout << "\t\t\t\t|------------------------------------------|" << endl;
	 	cout << "\t\t\t\t|              TERIMA KASIH ......         |" << endl;
	 	cout << "\t\t\t\t|------------------------------------------|" << endl;

	}
};
class Header {
	public :
	string namamu,asalmu;	
	void headerHotel() { 
	system("CLS"); 
	cout << "\t\t\t\t       !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                          " << endl;
    cout << "\t\t\t\t     ^~7#################################&#!!^                       " << endl; 
    cout << "\t\t\t\t     P@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@5                       " << endl;  
    cout << "\t\t\t\t     P@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@5                       " << endl; 
    cout << "\t\t\t\t     P@@@#GGGGGB@@@@@@#GGGGG#@@@@@@BGGGGG#@@@5                       " << endl;
    cout << "\t\t\t\t     P@@#:      P@@@@G.     .B@@@@5      :#@@5  :YYYYYYYYYY^         " << endl;
    cout << "\t\t\t\t     P@@B       Y@@@@P       G@@@@J       B@@5  ^B#########~         " << endl;
    cout << "\t\t\t\t     P@@B...... 5@@@@P ......G@@@@Y ......#@@G!!?BBBGBBGBBB~         " << endl;
    cout << "\t\t\t\t     P@@@#######&@@@@&#######&@@@@&#######@@@#55PBBBJ5P?BBB~         " << endl;
    cout << "\t\t\t\t     P@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@5  ^BBBYPGJBBB~         " << endl;
    cout << "\t\t\t\t     P@@@&GGGGG#@@@@@@#GGGGG#@@@@@@#GGGGG&@@@5  ^BBBBBBBBBB~         " << endl;
    cout << "\t\t\t\t     P@@#:     .P@@@@G.     .B@@@@5      ^#@@5  ^BBBPPGPBBB~         " << endl;
    cout << "\t\t\t\t     P@@B       Y@@@@P       G@@@@J       B@@5  ^BBB?GB?GBB~         " << endl;  
    cout << "\t\t\t\t     P@@B. .... 5@@@@P ....  G@@@@J   .. .#@@5  ^BBBGGGGBBB~         " << endl;
    cout << "\t\t\t\t     P@@@######B&@@@@&B######&@@@@&B####B#@@@5  ^BBBBBBBBBB~         " << endl; 
    cout << "\t\t\t\t     P@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@5  ^BBBG5YGBBB~         " << endl;
    cout << "\t\t\t\t     P@@@&BBBBB#@@@@@@#BBBBB&@@@@@@#BBBBB&@@@5  ^BBBB5Y#BBB~         " << endl; 
    cout << "\t\t\t\t     P@@#:     .P@@@@G.     :B@@@@5.     ^&@@5  ^BBBBBBBBBB~         " << endl;
    cout << "\t\t\t\t     P@@B       Y@@@@P       G@@@@J       B@@5  ^BBBBPGBBBB~         " << endl;
    cout << "\t\t\t\t     P@@B       5@@@@P       G@@@@J      .#@@5  ^BBBG7PGBBB~         " << endl; 
    cout << "\t\t\t\t     P@@&BBBBBBB&@@@@&BBBBBBB&@@@@&BBBBBBB@@@5  ^BBBGYGGBBB~         " << endl;
    cout << "\t\t\t\t     P@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@5  ^BBBB#BBBBB~         " << endl; 
    cout << "\t\t\t\t     P@@@&BBBBB#@@@@@@&BBBBB&@@@@@@#BBBBB&@@@5  ^BBBGYBBBBB~         " << endl;
    cout << "\t\t\t\t     P@@#^     .G@@@@G.     :B@@@@P.     ^&@@BYY5BBBG?BGBBB~         " << endl; 
    cout << "\t\t\t\t     P@@B       Y@@@@5       G@@@@J       B@@G77JBBBBGGGBBB~         " << endl;
    cout << "\t\t\t\t     P@@B       Y@@@@P       G@@@@J      .#@@5  :BBB###BBB#~         " << endl;
    cout << "\t\t\t\t     P@@&BBBBBBB&@@@@&BBBBBBB&@@@@#BBBBBBB@@@5  :5555555555^         " << endl;
    cout << "\t\t\t\t     P@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@5                       " << endl;
    cout << "\t\t\t\t     P@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@5                       " << endl;
    cout << "\t\t\t\t     P@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@5                       " << endl;
    cout << "\t\t\t\t     P@@@@@@@@@@@@@BY555555555YB@@@@@@@@@@@@@5                       " << endl;
    cout << "\t\t\t\t     P@@@@@@@@@@@@@B           B@@@@@@@@@@@@@5                       " << endl;
    cout << "\t\t\t\t     P@@@@@@@@@@@@@B   HOTEL   B@@@@@@@@@@@@@5                       " << endl;
    cout << "\t\t\t\t     P@@@@@@@@@@@@@B  MAHALLI  B@@@@@@@@@@@@@5                       " << endl;
    cout << "\t\t\t\t     P@@@@@@@@@@@@@B ALEXANDER B@@@@@@@@@@@@@5                       " << endl;
    cout << "\t\t\t\t     P@@@@@@@@@@@@@B           B@@@@@@@@@@@@@5                       " << endl;
    cout << "\t\t\t\t ....P@@@@@@@@@@@@@Y...........5@@@@@@@@@@@@@5....                   " << endl;
    cout << "\t\t\t\t~BBBBB#############BBBBBBBBBBBBB#############BBBBB^                  " << endl;
    cout << "\t\t\t\t:!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!. 				  " << endl;
				
	cout << endl;
	cout << "               ---------------------------------------------------------------------------------------     " << endl;
	cout << "      ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "      ||||||||||||||||||||||||||||||||||||||""+=======================+""|||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "      |||||==|||--||||++||||||||||||||||||||""[HOTEL MAHALLI ALEXANDER]""|||||||||||||||||||__|||__|||__||||||||||" << endl;
	cout << "      |||||==|||--||||++||||||||||||||||||||""+=======================+""|||||||||||||||||||  |||  |||  ||||||||||" << endl;
	cout << "      ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl<<endl;
	cout << "                                      DATE/TIME = " << b << endl<<endl;
	cout << "                                     :v  (: ---- SELAMAT DATANG ---- :)  :v                                  " << endl << endl;

}
	void Greeting(){
	cin.ignore();
	cout << " --- Nama = ";
	getline(cin,namamu);
	cout << " --- Asal = ";
	getline(cin,asalmu);	
	system("CLS");
		
                                                  
	    cout << "\t\t\t	                  ......                      " << endl;
	    cout << "\t\t\t	           :JP#&@@@@@@@@@@&#PJ:               " << endl;
	    cout << "\t\t\t	          ~@@@#G5J?7777?J5G#@@@~              " << endl;
	    cout << "\t\t\t	          Y@@J              Y@@Y              " << endl;
	    cout << "\t\t\t	          Y@@J              J@@Y              " << endl;
	    cout << "\t\t\t	          J@@@##############@@@J              " << endl;
	    cout << "\t\t\t	          7@@&BBBBBBBBBBBBBB&@@7              " << endl;
	    cout << "\t\t\t	          J@@Y              Y@@J              " << endl;
	    cout << "\t\t\t	          ^@@&              &@@^              " << endl;
	    cout << "\t\t\t	           Y@@#:          :#@@Y               " << endl;
	    cout << "\t\t\t	            ~@@@B?^....:?B@@@~                " << endl;
	    cout << "\t\t\t	          .7G@@@@@@@@@@@@@@@@G7.              " << endl;
	    cout << "\t\t\t	        ~B@@@B?:.~#@@@@G~.^?B@@@B~            " << endl;
	    cout << "\t\t\t	      ^#@@#!. .7#@@@G~.      .!#@@#^          " << endl;
	    cout << "\t\t\t	     J@@&~   7@@@G~             ~&@@J         " << endl;
	    cout << "\t\t\t	    Y@@#.    Y@@Y ?BJ            .#@@Y        " << endl;
	    cout << "\t\t\t	   ~@@&      Y@@J Y#Y              &@@~       " << endl;
	    cout << "\t\t\t	   #@@~      Y@@J ~Y~              ~@@#       " << endl;
	    cout << "\t\t\t	   @@@       J@@J P@G               @@@       " << endl;
	    cout << "\t\t\t	  .@@@?!!!!!!B@@B!!7!!!!!!!!!!!!!!!?@@@.      " << endl;
	    cout << "\t\t\t	   #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#       " << endl;
	    cout << "\t\t\t	    ..................................        " << endl;
                                                  
		cout << endl;
		cout << "     ---------------------------------------------------------------------------------------------------------------" << endl;
		cout << "                                  HAII ---> " << namamu << ", <--- SELAMAT DATANG DI HOTEL INI !!!" << endl;
		cout << "     ---------------------------------------------------------------------------------------------------------------" << endl;
		cout << "                           TERIMA KASIH TELAH DATANG DARI ---> " << asalmu  << ", <--- UNTUK MENGINAP DISINI ..."<< endl;
		cout << "     ---------------------------------------------------------------------------------------------------------------" << endl;
//		getchar();
	}
};
class Hotel { 
		
	public : 
		// PROPERTY
		
		// GREETING
		string nama,asal;
		// 
		char lanjutkan;
		// Check In & Check Out
		int bayar_kamar,total_checkIn,kembalian;
		int status_diskon; // = 0; // cek apakah diskon diambil atau tidak?
		char pilih_kamar_checkIn;
		int kode;
		int harga_diskon;
		int kamarYgDiCheckIn; // = 0; // Untuk Mengecek Apakah Udah DiCheckIN Atau Blm !
		char lanjut,konfirmasi_check_in,konfirmasi_check_out;
		float diskon;
		// ARRAY KAMAR
		string nama_checkIn[30]; // nama
		string kamar_checkIn[30]; // kamar
		int harga_checkIn[30]; //harga
		int hari_checkIn[30]; // Hari
		int total_harga[30]; // total harga
		int jml_pesanan;
		// Member Plus
		char lupa_kode;
		string no_ktp_member;
		int member_kode;
		int status_member; // = 0; // cek apakah udah ada yg terdaftar member atau blm? 
		string nama_member,asal_member;
		// Bookimg & informasi booking
		int pilih_bulan;
		string bulan[12];
 		char konfirmasi_booking;
		string nama_pembooking,kamar_booking,bulan_booking;
		char batalkan_pemesanan,pilih_kamar_booking;
		int harga_booking,brp_hari_booking,tanggal_booking,tahun_booking;
		int kamarYgDiBooking; // = 0; // Untuk Mengecek Apakah Udah Dibooking Atau Blm !
		// Informasi Hotel
		int pilih_informasi;
		// Pelayanan Extra 
		char pilih_tambahan,
		pilih_pijat,
		pilih_spa,
		pilih_cukur_rambut,
		pilih_meeting_room;
		string pelayanan[30];
		int harga_pelayanan[30];
		int tambahan;
		// Pijat
		string pijat_1,pijat_2,pijat_3,pijat_4,pijat_5,pijat_6;
		int pijat_1_harga,pijat_2_harga,pijat_3_harga,pijat_4_harga,pijat_5_harga,pijat_6_harga;
		// SPA
		string spa_1,spa_2,spa_3;
		int spa_1_harga,spa_2_harga,spa_3_harga;
		// CUKUR RAMBUT
		string cukram_1,cukram_2,cukram_3,cukram_4;
		int cukram_1_harga,cukram_2_harga,cukram_3_harga,cukram_4_harga;
		// MEETING ROOM 
		string meetroom_1,meetroom_2,meetroom_3;
		int meetroom_1_harga,meetroom_2_harga,meetroom_3_harga;
		// KAMAR
		string kamar_menu_1; //= "Deluxe Room ~ Single-bed";
		string kamar_menu_2; //= "Execuve ~ Room Twin-Bed";
		string kamar_menu_3; //= "VVIP Room ~ Single-Bed";
		string kamar_menu_4; //= "VIP Room ~ Double-Bed";
		string kamar_menu_5; //= "Normal Room ~ Twin-Bed";
		string kamar_menu_6; //= "Presidential Room ~ Single-Bed";
		string kamar_menu_7; //= "Superior Room ~ Twin-Bed";
		string kamar_menu_8; //= "Superior Room ~ Single-Bed";
		// Harga Kamar
		int harga_menu_1; // = 750000 ; // Rp.750.000 
		int harga_menu_2; // = 1150000 ; // Rp.1.150.000
		int harga_menu_3; // = 1050000 ; // Rp.1.050.000
		int harga_menu_4; // = 950000 ; // Rp.950.000
		int harga_menu_5; // = 650000 ; // Rp.65.000
		int harga_menu_6; //= 750000 ; // Rp.75.000
		int harga_menu_7; // = 700000 ; // Rp.70.000
		int harga_menu_8; //  = 550000 ; // Rp.55.000
		int jml_CO_nama = 0;
		string nama_F_CO,kamar_F_CO,hari_F_CO,harga_F_CO,total_F_CO;
		string Folder_BOOK,FileBooking,FileMember;
	
	// CONSTUCTOR
	Hotel() {
		for(int i=0; i <12;i++){
		string namabulan[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
		bulan[i] = namabulan[i];
		}
		tambahan = 0;jml_pesanan = 0;kamarYgDiCheckIn = 0;kamarYgDiBooking = 0;status_member = 0;status_diskon = 0;
		kamar_menu_1 = "Deluxe Room ~ Single-bed";
		kamar_menu_2 = "Executive Room ~ Room Twin-Bed";
		kamar_menu_3 = "VVIP Room ~ Single-Bed";
		kamar_menu_4 = "VIP Room ~ Double-Bed";
		kamar_menu_5 = "Normal Room ~ Twin-Bed";
		kamar_menu_6 = "Presidential Room ~ Single-Bed";
		kamar_menu_7 = "Superior Room ~ Twin-Bed";
		kamar_menu_8 = "Superior Room ~ Single-Bed";
		harga_menu_1 = 750000 ; // Rp.750.000 
		harga_menu_2 = 1150000 ; // Rp.1.150.000
		harga_menu_3 = 1050000 ; // Rp.1.050.000
		harga_menu_4 = 950000 ; // Rp.950.000
		harga_menu_5 = 650000 ; // Rp.65.000
		harga_menu_6 = 750000 ; // Rp.75.000
		harga_menu_7 = 700000 ; // Rp.70.000
		harga_menu_8 = 550000 ; // Rp.55.000
		// pijat		
		pijat_1 = "PIJAT RELAKSASI/REFLEKSI";
		pijat_2 = "PIJAT PEGEL-PEGEL";
		pijat_3 = "PIJAT KESELEO";
		pijat_4 = "PIJAT AROMATERAPI";
		pijat_5 = "PIJAT TRADISIONAL";
		pijat_1_harga = 20000; // Rp.20.000
		pijat_2_harga = 30000; // Rp. 30.000
		pijat_3_harga = 25000; // Rp.25.000
		pijat_4_harga = 35000; // Rp.35.000
		pijat_5_harga = 25000; // Rp.25.000
		// SPA
		spa_1 = "Medical Spa";
		spa_2 = "Destination Spa";
		spa_3 = "Resort Spa";
		spa_1_harga = 20000; //Rp.20.000
		spa_2_harga = 30000; //Rp.30.000
		spa_3_harga = 25000; //Rp.25.000
		// CUKUR RAMBUT
		cukram_1 = "CUKUR DEWASA";
		cukram_2 = "CUKUR ANAK";
		cukram_3 = "CUKUR JENGGOT & KUMIS";
		cukram_4 = "CUKUR + PIJAT";
		cukram_1_harga = 10000; //Rp.10.000
		cukram_2_harga = 7000; //Rp.7.000
		cukram_3_harga = 5000; //Rp.5.000 
		cukram_4_harga = 15000; //Rp.15.000
		// MEETING ROOM
		meetroom_1 = "STANDARD MEETING ROOM";
		meetroom_2 = "LARGE MEETING ROOM";
		meetroom_3 = "EXECUTIVE MEETING ROOM";
		meetroom_1_harga = 100000; //Rp,100.000
		meetroom_2_harga = 150000; //Rp.150.000
		meetroom_3_harga = 250000; // Rp.250.000
	}		
	// METHOD
	void jeda(){
				cout << endl;
				cout << endl;
				cout << "\t\t\t\t\t----------------------------" << endl;
				cout << "\t\t\t\t\tPRESS ANY KEY TO CONTINUE..." << endl;
				cout << "\t\t\t\t\t----------------------------" << endl;				
	} 
	void tampilan_menu() {
			string Profile = "Users/" + username_berhasil_login + "/User_"+username_berhasil_login+"_Profile.txt";
			string nama_P,asal_P;
			Output.open(Profile.c_str());
				getline(Output,nama_P);
				getline(Output,asal_P);
			Output.close();
			
			
			cout << "\tLogin At : " << b ;
			cout << "\t---------------------------------------------" << endl; 
			cout << "\tNama : " << nama_P << endl; 
			cout << "\t---------------------------------------------" << endl; 
			cout << "\tAsal : " << asal_P << endl; 
			cout << endl;
			cout << "\t\t\t\t+-------------------------------+" << endl;
			cout << "\t\t\t\t========== MENU UTAMA ==========+" << endl;
			cout << "\t\t\t\t+-------------------------------+" << endl;
			cout << "\t\t\t\t|-- 1. Check In                 |" << endl;
			cout << "\t\t\t\t|-- 2. Check Out                |" << endl;
			cout << "\t\t\t\t|-- 3. Booking                  |" << endl;
			cout << "\t\t\t\t|-- 4. Check My Booking Room    |" << endl;
			cout << "\t\t\t\t|-- 5. Daftar Member Special    |" << endl;
			cout << "\t\t\t\t|-- 6. Informasi Hotel          |" << endl;
			cout << "\t\t\t\t|-- 7. Pelayanan Tambahan       |" << endl;
			cout << "\t\t\t\t|-- 8. Ganti Tema               |" << endl;
			cout << "\t\t\t\t|-- 9. EXIT                     |" << endl;
			cout << "\t\t\t\t|-- N. LOGOUT                   |" << endl;
			cout << "\t\t\t\t+-------------------------------+" << endl;
	}
	void Utama() {
		system("CLS"); // Clear Screen
		iniHotel:
		do {
		system("CLS");
//		Greeting();
		tampilan_menu();
		cout << "\t\t\t\t  --->   PILIH   =>  " ;
		cin >> lanjut;
		system("CLS");
		switch (lanjut) {
			case 'N' :
				logout();
				goto selesai;
				break;
			case '1' :
				check_in();
				getchar();
				jeda();
				getchar();
				goto iniHotel;
				break;
			case '2' :
				check_out();
				getchar();
				jeda();
				getchar();
				goto iniHotel;
				break;
			case '3' :
				booking();
				getchar();
				jeda();
				getchar();
				goto iniHotel;
				break;
			case '4' :
				informasi_booking();
				getchar();
				jeda();
				getchar();
				goto iniHotel;
				break;
			case '5' :
				daftar_member_plus();
				getchar();
				jeda();
				getchar();
				goto iniHotel;
				break;
			case '6' :
				informasi_hotel();
				getchar();
				jeda();
				getchar();
				goto iniHotel;
				break;
			case '7' :
				pelayanan_tambahan();
				getchar();
				jeda();
				getchar();
				goto iniHotel;
				break;
			case '8' :
				Theme();
				getchar();
				jeda();
				getchar();
				goto iniHotel;
				break;
			case '9' :
				goto lanjutGak;
				break;
			default :
				cout << "\t\t\t\t----------------------------------------" << endl;
				cout << "\t\t\t\t--ERROR !! Masukkan Kode Dgn Benar !!!--" << endl;
				cout << "\t\t\t\t----------------------------------------" << endl;
				cout << endl;
				getchar();
				jeda();
				getchar();
				goto iniHotel;
			}	
		if (LogOut != 'y'){
		lanjutGak:
		cout << "\t\t\t\t-----------------------------------------------------------" <<endl;
		cout << "\t\t\t\t APAKAH ANDA YAKIN INGIN KELUAR DARI PROGRAM  (y/n) ???? = ";
		cin >> lanjutkan;
		system("CLS");
		}
		} while (lanjutkan != 'y' && lanjutkan == 'n');
		if (lanjutkan == 'y') {	
				selesai:
				footerHotel();
		} else {
			cout << "---------------------------------------" << endl;
			cout <<"ERROR !!! Masukkan Kode Dengan Benar !!!" << endl;
			cout << "---------------------------------------" << endl;
			goto lanjutGak;	
			
			}
	}		
	void check_in() { 
		cout << "\t+----------------------------+" << endl;
		cout << "\t---------- CHECK IN ----------" << endl;
		cout << "\t+----------------------------+" << endl;
		cout << endl;	

		cout << "\t----------------------------------" << endl;
		cin.ignore();
		cout << "\tCheck-In Atas Nama = " ;
		getline(cin,nama_checkIn[jml_pesanan]);
		system("CLS");
		pilihan_kamar:
		cout << "\t+------------------------------------------------+" << endl;
		cout << "\t|     Pilihan Kamar Di HOTEL MAHALLI ALEXANDER   |" << endl;
		cout << "\t|------------------------------------------------|" << endl;
		cout << "\t|1.Deluxe Room ~ Single-Bed ~ Rp.750.000,-       |" << endl;
		cout << "\t|2.Executive ~ Room Twin-Bed ~ Rp.1.150.000,-    |" << endl;
		cout << "\t|3.VVIP Room ~ Single-Bed ~ Rp.1.050.000,-       |" << endl;
		cout << "\t|4.VIP Room ~ Double-Bed ~ Rp.950.000,-          |" << endl;
		cout << "\t|5.Normal Room ~ Twin-Bed ~ Rp.650.000,-         |" << endl;
		cout << "\t|6.Presidential Room ~ Single-Bed ~ Rp.750.000,- |" << endl;
		cout << "\t|7.Superior Room ~ Twin-Bed ~ Rp.700.000,-       |" << endl;
		cout << "\t|8.Superior Room ~ Single-Bed ~ Rp.550.000,-     |" << endl;
		cout << "\t+------------------------------------------------|" << endl;
		cout << "\t  +--------- PILIH ==>>  " ;
		cin >> pilih_kamar_checkIn;
		switch (pilih_kamar_checkIn) {
			case '1' :
				kamar_checkIn[jml_pesanan]  = kamar_menu_1;
				harga_checkIn[jml_pesanan] = harga_menu_1;
				break;
			case '2' :
				kamar_checkIn[jml_pesanan]  = kamar_menu_2;
				harga_checkIn[jml_pesanan] = harga_menu_2;
				break;
			case '3' :
				kamar_checkIn[jml_pesanan]  = kamar_menu_3;
				harga_checkIn[jml_pesanan] = harga_menu_3;
				break;
			case '4' :
				kamar_checkIn[jml_pesanan]  = kamar_menu_4;
				harga_checkIn[jml_pesanan] = harga_menu_4;
				break;
			case '5' :
				kamar_checkIn[jml_pesanan]  = kamar_menu_5;
				harga_checkIn[jml_pesanan] = harga_menu_5;
				break;
			case '6' :
				kamar_checkIn[jml_pesanan]  = kamar_menu_6;
				harga_checkIn[jml_pesanan] = harga_menu_6;	
				break;
			case '7' :
				kamar_checkIn[jml_pesanan]  = kamar_menu_7;
				harga_checkIn[jml_pesanan] = harga_menu_7;
				break;
			case '8' :
				kamar_checkIn[jml_pesanan]  = kamar_menu_8;
				harga_checkIn[jml_pesanan] = harga_menu_8;		
				break;
			default :
				system("CLS");
				cout << "\t+-----------------------------+" << endl;
				cout << "\tMASUKKAN KODE DENGAN BENAR !!!!" << endl;
				cout << "\t+-----------------------------+" << endl;
				goto pilihan_kamar;
		}
		brpHariCheckIn:
		cout << "\t------------------------------------------" << endl;
		cout << "\tBerapa Hari Akan Menginap = " ;
		cin >> hari_checkIn[jml_pesanan];
		if (hari_checkIn[jml_pesanan] > 365) {
				cout << "\t---- ERROR ---" << endl;
				cout << "\tERROR, Maaf, Maximal 1 Tahun untuk menginap" << endl;
				cout << "\t--------------" << endl;
				goto brpHariCheckIn;
			}
		// KONFIRMASI CHECK IN
		system("CLS");
		konfirmasiCheckIn:		
		total_harga[jml_pesanan] = harga_checkIn[jml_pesanan]*hari_checkIn[jml_pesanan];
		cout << endl;
		cout << "\t\t\t+====================================================+" << endl;
		cout << "\t\t\t+============== KONFIRMASI CHECK-IN =================+" << endl;
		cout << "\t\t\t+====================================================+" << endl;
		cout << endl ;
		cout <<"=============================================================================================================\n";
 		cout <<"| No |    ATAS NAMA     |              KAMAR             | SELAMA (HARI) |     HARGA    |       TOTAL       |\n";
		cout <<"============================================================================s=================================\n";
		cout <<"| "<<setiosflags(ios::right)<<setw(3)<<"1"<<"|";
		cout <<" "<<setiosflags(ios::right)<<setw(17)<<nama_checkIn[jml_pesanan]<<"|";
		cout <<" "<<setiosflags(ios::right)<<setw(31)<<kamar_checkIn[jml_pesanan]<<"|";
		cout <<" "<<setiosflags(ios::right)<<setw(8)<<hari_checkIn[jml_pesanan]<<" Hari |";
		cout <<" "<<setiosflags(ios::right)<<setw(5)<<"Rp."<<harga_checkIn[jml_pesanan]<<",-|";
		cout <<" "<<setiosflags(ios::right)<<setw(8)<<"Rp."<<total_harga[jml_pesanan]<<",-|";
		cout <<"\n=============================================================================================================\n";	
		cout << "\t\t--------------------------------------------" << endl;
		cout << "\t\tApakah Anda Yakin Ingin Check-In ??? (y/n) = ";
		cin >> konfirmasi_check_in;
		if (konfirmasi_check_in == 'y') {
			cout << "\t\t+-----------------------------------------+" << endl;
			cout << "\t\t|Selamat !!! Anda Telah Berhasil Check-In |" << endl;
			cout << "\t\t+-----------------------------------------+" << endl;
			kamarYgDiCheckIn = 1;
			string Folder_CI = "Users/" + username_berhasil_login + "/Check-In"; 
			CreateDirectory(Folder_CI.c_str(),NULL); // BUAT FOLDER CHECK-IN DALAM Users/username/
			string FileCheckIn = "Users/"+username_berhasil_login+"/Users_"+username_berhasil_login+"_SemuaData_CheckIn.txt";
			// Semua Data
			Input.open(FileCheckIn.c_str(), ios::app);
			Input<<nama_checkIn[jml_pesanan] << endl;
			Input<<kamar_checkIn[jml_pesanan] << endl;
			Input<<hari_checkIn[jml_pesanan] << endl;
			Input<<harga_checkIn[jml_pesanan] << endl;
			Input<<total_harga[jml_pesanan] << endl;
			Input.close();
			// Nama.txt
			string nama_F_CI = "Users/"+username_berhasil_login+"/Check-In/Nama.txt";
			Input.open(nama_F_CI.c_str(),ios::app);
			Input << nama_checkIn[jml_pesanan] << endl;
			Input.close();
			// Kamar.txt
			string kamar_F_CI = "Users/"+username_berhasil_login+"/Check-In/Kamar.txt";
			Input.open(kamar_F_CI.c_str(),ios::app);
			Input << kamar_checkIn[jml_pesanan] << endl;
			Input.close();			
			// Hari.txt
			string hari_F_CI = "Users/"+username_berhasil_login+"/Check-In/Hari.txt";
			Input.open(hari_F_CI.c_str(),ios::app);
			Input << hari_checkIn[jml_pesanan] << endl;
			Input.close();
			// Harga.txt
			string harga_F_CI = "Users/"+username_berhasil_login+"/Check-In/Harga.txt";
			Input.open(harga_F_CI.c_str(),ios::app);
			Input << harga_checkIn[jml_pesanan] << endl;
			Input.close();
			// Total.txt
			string total_F_CI = "Users/"+username_berhasil_login+"/Check-In/Total.txt";
			Input.open(total_F_CI.c_str(),ios::app);
			Input << total_harga[jml_pesanan] << endl;
			Input.close();
//			jml_pesanan++;
		} else if (konfirmasi_check_in == 'n') {
			cout << "\t\t+-------------------------------------------+" << endl;
			cout << "\t\t|-- Check-In Dibatalkan, Terima Kasih !!! --|" << endl;
			cout << "\t\t+-------------------------------------------+" << endl;
		} else {	
			cout << "\t\t+---------------------------------+" << endl;
			cout << "\t\t|ERROR !!! masukkan kode dgn benar|" << endl;
			cout << "\t\t+---------------------------------+" << endl;	
			goto konfirmasiCheckIn;
		}
	}
	void check_out() { // 5 FIFTH
			int pT=0,hpT=0;		
			// CEK MEMBER
			FileMember = "Users/"+username_berhasil_login+"/MemberSpecial/Member.txt";
			Output.open(FileMember.c_str());
			if(Output){
			Output >> member_kode;
			status_member=1;
			Output.close();
			}		
		string cek = "Users/"+username_berhasil_login+"/Check-In/Nama.txt";
		Output.open(cek.c_str());
		if (Output) {
//			cout << "FILE EXIST....." << endl;
		Output.close();
			eror:
			cout << "\t\t----------------------------------------------------------------" << endl;
			cout << "\t\t-- Apakah Anda Member Special Hotel Mahalli Alexander ? (y/n) = " ;
			cin >> lanjut;
			cout << "\t\t----------------------------------------------------------------" << endl;
				if (lanjut == 'y') {
					if (status_member == 0) {
						cout << "\t\t----------------------------------------------------------------" << endl;
						cout << "\t\tMohon Maaf, Anda Belum Terdaftar Member !!" << endl;
						cout << "\t\t----------------------------------------------------------------" << endl;
						}else if (status_member == 1){
							balik_lagi:
							cout << "\t\t----------------------------------------------------------------" << endl;
							cout << "\t\t--- Masukkan Kode Member == " ;
							cin	 >> kode;
							if (kode == member_kode){
							system("CLS");
							cout << "\t\t+---------------------------------------------------------------+" << endl;
							cout << "\t\t| Selamat Anda Mendapatkan Potongan Harga Sebesar 25%           |" << endl;
							cout << "\t\t+---------------------------------------------------------------+" << endl;
							diskon = 0.25;
							status_diskon = 1;
							} else {
							cout << "\t\t+--------------------------------------------------------------+" << endl;
							cout << "\t\t| Maaf, kode yang anda masukkan salah                          |" << endl;
							cout << "\t\t+--------------------------------------------------------------+" << endl;
								here:
								cout << "\t\t ---- Lupa Kode ??? (y/n) : " ;
								cin >> lupa_kode; 
								if (lupa_kode == 'y') {
							cout << "\t\t----------------------------------------------------------------" << endl;
									cout << "\t\t KODE ANDA ADALAH   =====  " << member_kode << endl;
									goto balik_lagi;
								} else if (lupa_kode == 'n') {
									goto balik_lagi;
								} else {
									cout << "\t\t ---- Masukkan (y/n) dengan benar !!! Pilih 'y' atau 'n' !!" << endl;
									goto here;
								}
						}
					}	 
				} else if (lanjut == 'n') {
				
				} else {
					cout << "\t\t ERROR !!! MASUKKAN KODE DENGAN BENAR" << endl;
					goto eror;
				}
		checkOut:
			cout << endl;
			cout << "\t\t\t\t======================================" << endl;
			cout << "\t\t\t\t============= CHECK-OUT ==============" << endl;
			cout << "\t\t\t\t======================================" << endl;
		cout << endl ;
		total_checkIn = 0;
		// cek kalau ada pelayanan extra
		string pelayananFile = "Users/"+username_berhasil_login+"/Extra/Pelayanan.txt";
		Output.open(pelayananFile.c_str());
		if (Output){
		Output.close();
		Output.open(pelayananFile.c_str());
		while(!Output.eof()){
//		Output.ignore(); 		
		getline(Output,pelayanan[pT]);
		pT++;
		}
		Output.close();
		
		string hargaPelayananFile = "Users/"+username_berhasil_login+"/Extra/Harga_Pelayanan.txt";
		Output.open(hargaPelayananFile.c_str());
		while(!Output.eof()){
		Output >> harga_pelayanan[hpT];
		hpT++;
		}
		Output.close();
	
			
		}
		
		
		
		// Panggil Data.txt Dan Masukkan KE  Variabel
		
		int jml_CO_kamar = 0,jml_CO_hari = 0,jml_CO_harga = 0,jml_CO_total = 0;
		string setNama,setKamar,nama_CO[50],kamar_CO[50];
		int setHari,setHarga,setTotal,hari_CO[50],harga_CO[50],total_CO[50];							
				// Nama.txt
				nama_F_CO = "Users/"+username_berhasil_login+"/Check-In/Nama.txt";
				Output.open(nama_F_CO.c_str());
						while(!Output.eof()){
							Output >> setNama; // getline
//							nama_CO[jml_CO] = setNama; // 
							nama_checkIn[jml_CO_nama] = setNama;
							jml_CO_nama++;
							}
				Output.close();
				// Kamar.txt
				kamar_F_CO = "Users/"+username_berhasil_login+"/Check-In/Kamar.txt";
				Output.open(kamar_F_CO.c_str());
						while(!Output.eof()){
							getline(Output,setKamar); // getline 
//							kamar_CO[jml_CO] = setKamar; 
							kamar_checkIn[jml_CO_kamar] = setKamar;
							jml_CO_kamar++;
							}
				Output.close();
				// Hari
				hari_F_CO = "Users/"+username_berhasil_login+"/Check-In/Hari.txt";
				Output.open(hari_F_CO.c_str());
						while(!Output.eof()){
							Output>>setHari; // getline 
//							hari_CO[jml_CO] = setHari; 
							hari_checkIn[jml_CO_hari] = setHari;							
							jml_CO_hari++;
							}
				Output.close();
				// Harga.txt
				harga_F_CO = "Users/"+username_berhasil_login+"/Check-In/Harga.txt";
				Output.open(harga_F_CO.c_str());
						while(!Output.eof()){
							Output>>setHarga; // getline 
//							harga_CO[jml_CO] = setHarga; 
							harga_checkIn[jml_CO_harga] = setHarga;
							jml_CO_harga++;
							}
				Output.close();
				// Total.txt 
				total_F_CO = "Users/"+username_berhasil_login+"/Check-In/Total.txt";
				Output.open(total_F_CO.c_str());
						while(!Output.eof()){
							Output>>setTotal; // getline 
//							harga_CO[jml_CO] = setTotal; 
							total_harga[jml_CO_total] = setTotal;
							jml_CO_total++;
							}
				Output.close();
				
		} 				
				
		if (jml_CO_nama >= 1) {
						
		cout <<"===================================================================================================================\n";
 		cout <<"| No |    ATAS NAMA     |              KAMAR             | SELAMA (HARI) |       HARGA      |        TOTAL        |\n";
		cout <<"===================================================================================================================\n";
		for	(int i = 0; i < jml_CO_nama-1 ; i++) {
		cout <<"| "<<setiosflags(ios::right)<<setw(3)<<i+1<<"|";
		cout <<" "<<setiosflags(ios::right)<<setw(17)<<nama_checkIn[i]<<"|";
		cout <<" "<<setiosflags(ios::right)<<setw(31)<<kamar_checkIn[i]<<"|";
		cout <<" "<<setiosflags(ios::right)<<setw(8)<<hari_checkIn[i]<<" Hari |";
		cout <<" "<<setiosflags(ios::right)<<setw(8)<<"Rp."<<harga_checkIn[i]<<",-|";
		cout <<" "<<setiosflags(ios::right)<<setw(11)<<"Rp."<<total_harga[i]<<",-|";
		cout << endl;
		total_checkIn += total_harga[i];
		}
		cout <<"==================================================================================================================\n";	
		cout << endl;
		if(pT >= 1) {
				cout <<"================================================================\n";
	 			cout <<"| No |          PELAYANAN TAMBAHAN          |       HARGA       |\n";
				cout <<"================================================================\n";
				for(int i=0;i<pT-1;i++) {
				cout <<"| "<<setiosflags(ios::right)<<setw(3)<<i+1<<"|";
				cout <<" "<<setiosflags(ios::right)<<setw(37)<<pelayanan[i]<<"|";
				cout <<" "<<setiosflags(ios::right)<<setw(10)<<"Rp."<<harga_pelayanan[i]<<",-|";
				cout << endl;
				total_checkIn += harga_pelayanan[i];			
				}
				cout <<"================================================================\n";
		}
			if (status_diskon >= 1) {
				harga_diskon =  total_checkIn*diskon;
				cout <<"\n==================================================================================================================\n";	
				cout <<"|"<<setiosflags(ios::right)<<setw(91)<<"DISKON (22%) "<<"|"; // JUMLAH DISKON
				cout <<" "<<setiosflags(ios::right)<<setw(10)<<"Rp."<<harga_diskon<<",-|"<<endl;
				cout <<"|"<<setiosflags(ios::right)<<setw(91)<<"TOTAL "<<"|"; // TOTAL SEMUA
				cout <<" "<<setiosflags(ios::right)<<setw(11)<<"Rp."<<total_checkIn-harga_diskon<<",-|";
				cout <<"\n==================================================================================================================\n";	
				total_checkIn -= harga_diskon; 
			} else if (status_diskon == 0) {		
				cout <<"\n==================================================================================================================\n";
				cout <<"|"<<setiosflags(ios::right)<<setw(91)<<"TOTAL "<<"|"; // TOTAL SEMUA
				cout <<" "<<setiosflags(ios::right)<<setw(11)<<"Rp."<<total_checkIn<<",-|";
				cout <<"\n==================================================================================================================\n";
			}
		cout << "\t ---------------------------------------------------" << endl;
		// KONFIRMASI
		cout << "\t ----- Apakah Anda Yakin Ingin Check-Out ?? (y/n) = " ;
		cin >> konfirmasi_check_out;
			if (konfirmasi_check_out == 'y') {
				// PEMBAYARAN
				cout << "\t\t-------------------------" << endl;
				cout << "\t\t-------PEMBAYARAN--------" << endl;
				cout << "\t\t-------------------------" << endl;
				cout << "\t\t -- Masukkan Uang Anda = " ;
				cin >> bayar_kamar;
				if (bayar_kamar == total_checkIn) {
					// Uang Pas
					cout << endl;
					cout << "\t\t-----------------------------------" << endl;
					cout << "\t\tTERIMA KASIH !!! UANG ANDA PAS.... " << endl;
					cout << "\t\t-----------------------------------" << endl;
				} else if (bayar_kamar > total_checkIn) {
					// Kasih Kembalian
					kembalian = bayar_kamar-total_checkIn;
					cout << "\t\t+----------------------------------------------------+" << endl;
					cout << "\t\t| Terima Kasih !!! Kembalian Anda Adalah Rp." << kembalian << endl;
					cout << "\t\t+----------------------------------------------------+" << endl;
				} else if (bayar_kamar < total_checkIn) {
					// Uang Kurang  -  Check Out GAGAL
					cout << "\t\t -------------------------------------" << endl;
					cout << "\t\t -- MOHON MAAF , UANG ANDA KURANG !!!" << endl;
					cout << "\t\t -- CHECK OUT GAGAL !!!! " << endl;
					cout << "\t\t -------------------------------------" << endl;
					goto gagal_checkout; // loncat
				}
				cout << "\t\t\t+-----------------------------------------+" << endl;
				cout << "\t\t\t|Selamat Anda Telah Berhasil Check-Out !!!|" << endl;
				cout << "\t\t\t+-----------------------------------------+" << endl;
				// REMOVE  check in
				string FileCheckIn = "Users/"+username_berhasil_login+"/Users_"+username_berhasil_login+"_SemuaData_CheckIn.txt";	
				remove(FileCheckIn.c_str());

				// REMOVE KAMAR CHECK-IN
				remove(nama_F_CO.c_str());
				remove(kamar_F_CO.c_str());
				remove(hari_F_CO.c_str());
				remove(harga_F_CO.c_str());
				remove(total_F_CO.c_str());
				// REMOVE PELAYANAN TAMBAHAN
				string pelayananFile = "Users/"+username_berhasil_login+"/Extra/Pelayanan.txt";
				string hargaPelayananFile = "Users/"+username_berhasil_login+"/Extra/Harga_Pelayanan.txt";
				remove(pelayananFile.c_str());
				remove(hargaPelayananFile.c_str());
				// 
				status_diskon=0;
				harga_diskon = 0;
				total_checkIn = 0;
				jml_pesanan = 0;
				kamarYgDiCheckIn = 0;
				jml_CO_nama =0;
			} else if (konfirmasi_check_out == 'n') {
				gagal_checkout:  // kesini
				jml_CO_nama = 0;
				harga_diskon = 0;
				total_checkIn = 0;
				cout << "\t\t+-----------------------------------------+" << endl;
				cout << "\t\t| Check-Out Dibatalkan, Terima kasih !!!  |" << endl;
				cout << "\t\t+-----------------------------------------+" << endl;
			} else {
				system("CLS");
				cout << "\t\t\t\t----- + --------------------------- + -----" << endl;
				cout << "\t\t\t\t+ -- ERROR !!! masukkan kode dgn benar -- +" << endl;
				cout << "\t\t\t\t----- + --------------------------- + -----" << endl;
				harga_diskon = 0;
				total_checkIn = 0;
				jml_CO_nama = 0;
				goto checkOut;
			}
		} 	else if (jml_CO_nama == 0) {
			cout << "\t\t\t ===========================================================================" << endl;
			cout << "\t\t\t ================= Belum Ada Kamar Yg Anda Check-In !!  ====================" << endl;
			cout << "\t\t\t ===========================================================================" << endl;
		}
		else {
			cout << "FILE DOESNT EXIST....." << endl;
			jml_CO_nama =0;
		}
//		Output.close();
		
	}
	void booking() {
		FileBooking = "Users/"+username_berhasil_login+"/BOOKING/BOOKING.txt";	
		Output.open(FileBooking.c_str());
	 	if(Output){
	 	kamarYgDiBooking = 1;
		Output.close();
		 } else {
		 	
		 }
		 
		if (kamarYgDiBooking == 0) {
		tgl_brp:
		cout << "\t\t\t======================================" << endl;
		cout << "\t\t\t============== BOOKING ===============" << endl;
		cout << "\t\t\t======================================" << endl;	
		cout << "\n\t-----------------------------------" << endl;	
		cout << "\t --- Untuk Tanggal Berapa ? = " ;
		cin >> tanggal_booking;
		if (tanggal_booking > 31 ){
			cout << "\t--- ERROR !!! Tanggal 1-31 ---" << endl;
			goto tgl_brp;
		} else if (tanggal_booking < 1 ) {
			cout << "\t--- ERROR !!! Tanggal 1-31 ---" << endl;
			goto tgl_brp;
		} else {

		}
		cout << "\t-----------------------------------" << endl;	
		cout << "\t +--------------------------------------------------------------+" << endl;
		cout << "\t | 1.January | 2.February | 3.March | 4.April | 5.May | 6. June |" << endl;
		cout << "\t | 7.July | 8.August | 9.September | 10.October | 11.November | 12.December |" << endl;
		cout << "\t +---------------------------------------------------------------------------+" << endl;
		cout << "\t Pilih Bulan  = ";
		cin >> pilih_bulan ;
		switch (pilih_bulan) {
			case  1 :
				bulan_booking = bulan[0];
				break;
			case  2 :
				bulan_booking = bulan[1];
				break;
			case  3 :
				bulan_booking = bulan[2];
				break;
			case  4 :
				bulan_booking = bulan[3];
				break;
			case  5 :
				bulan_booking = bulan[4];
				break;
			case  6 :
				bulan_booking = bulan[5];
				break;
			case  7 :
				bulan_booking = bulan[6];
				break;
			case  8 :
				bulan_booking = bulan[7];
				break;
			case  9 :
				bulan_booking = bulan[8];
				break;
			case  10 :
				bulan_booking = bulan[9];
				break;
			case  11 :
				bulan_booking = bulan[10];
				break;
			case  12 :
				bulan_booking = bulan[11];
				break;
			default :
				cout << "\t --- ERROR , PILIH DENGAN BENAR !!! ---" << endl;
				break;
		}
		thn_brp:
		cout << "\t-----------------------------------" << endl;	
		cout << "\t --- Tahun = " ;
		cin >> tahun_booking;
		if (tahun_booking > 2030 ){
			cout << "\t---- ERROR !!! Tahun 2022 - 2030 -----" << endl;
			goto thn_brp;
		} else if (tahun_booking < 2022 ) {
			cout << "\t---- ERROR !!! Tahun 2022 - 2030 -----" << endl;
			goto thn_brp;
		} else {

		}
		cin.ignore();
		cout << "\t-----------------------------------" << endl;	
		cout << "\t --- Membooking Atas Nama = ";
		getline(cin,nama_pembooking);
		system("CLS");
		pilihan_booking:
		cout << "\t+------------------------------------------------+" << endl;
		cout << "\t|     Pilihan Kamar Di HOTEL MAHALLI ALEXANDER   |" << endl;
		cout << "\t|------------------------------------------------|" << endl;
		cout << "\t|1.Deluxe Room ~ Single-Bed ~ Rp.750.000,-       |" << endl;
		cout << "\t|2.Executive ~ Room Twin-Bed ~ Rp.1.150.000,-    |" << endl;
		cout << "\t|3.VVIP Room ~ Single-Bed ~ Rp.1.050.000,-       |" << endl;
		cout << "\t|4.VIP Room ~ Double-Bed ~ Rp.950.000,-          |" << endl;
		cout << "\t|5.Normal Room ~ Twin-Bed ~ Rp.650.000,-         |" << endl;
		cout << "\t|6.Presidential Room ~ Single-Bed ~ Rp.750.000,- |" << endl;
		cout << "\t|7.Superior Room ~ Twin-Bed ~ Rp.700.000,-       |" << endl;
		cout << "\t|8.Superior Room ~ Single-Bed ~ Rp.550.000,-     |" << endl;
		cout << "\t+------------------------------------------------|" << endl;
		cout << "\t  +--------- PILIH ==>>  " ;
		cin >> pilih_kamar_booking;
		switch (pilih_kamar_booking) {
			case '1' :
				kamar_booking = kamar_menu_1;
				harga_booking = harga_menu_1;
				break;
			case '2' :
				kamar_booking = kamar_menu_2;
				harga_booking = harga_menu_2;
				break;
			case '3' :
				kamar_booking = kamar_menu_3;
				harga_booking = harga_menu_3;
				break;
			case '4' :
				kamar_booking = kamar_menu_4;
				harga_booking = harga_menu_4;
				break;
			case '5' :
				kamar_booking = kamar_menu_5;
				harga_booking = harga_menu_5;
				break;
			case '6' :
				kamar_booking = kamar_menu_6;
				harga_booking = harga_menu_6;
				break;
			case '7' :
				kamar_booking = kamar_menu_7;
				harga_booking = harga_menu_7;
				break;
			case '8' :
				kamar_booking = kamar_menu_8;		
				harga_booking = harga_menu_8;
				break;
			default :
				system("CLS");
				cout << "+-----------------------------+" << endl;
				cout << "MASUKKAN KODE DENGAN BENAR !!!!" << endl;
				cout << "+-----------------------------+" << endl;
				goto pilihan_booking;
		}
		brpHariBooking :
		cout << "\t\t --- Berapa Hari Akan Menginap (Max.15 Hari) = " ;
		cin >> brp_hari_booking;
			if (brp_hari_booking > 15) {
				cout << "\t\t ---- Maaf, Maximal 15 hari untuk menginap" << endl;
				goto brpHariBooking;
			}
		kamarYgDiBooking=1;
				
		system("CLS");
		cout << endl;
		cout << "\t\t\t+============== KONFIRMASI BOOKING =================+" << endl;
		cout << endl ;
		cout <<"===========================================================================================================\n";
		cout <<"|      TANGGAL      |  " << tanggal_booking << " "<< bulan_booking <<" "<< tahun_booking <<"  |"<< endl; 
		cout <<"===========================================================================================================\n";
 		cout <<"| No |    ATAS NAMA     |              KAMAR             | SELAMA (HARI) |     HARGA    |      TOTAL      |\n";
		cout <<"===========================================================================================================\n";
		cout <<"| "<<setiosflags(ios::right)<<setw(3)<<"1"<<"|";
		cout <<" "<<setiosflags(ios::right)<<setw(17)<<nama_pembooking<<"|";
		cout <<" "<<setiosflags(ios::right)<<setw(31)<<kamar_booking<<"|";
		cout <<" "<<setiosflags(ios::right)<<setw(8)<<brp_hari_booking<<" Hari |";
		cout <<" "<<setiosflags(ios::right)<<setw(5)<<"Rp."<<harga_booking<<",-|";
		cout <<" "<<setiosflags(ios::right)<<setw(7)<<"Rp."<<harga_booking*brp_hari_booking<<",-|";
		cout <<"\n===========================================================================================================\n";	
		konfirmBook:
		cout << endl << "\t--- Apakah Anda Yakin Ingin Membooking Kamar Ini ??? (y/n) : ";
		cin >> konfirmasi_booking;
		if (konfirmasi_booking == 'y') {
			cout << "\t\t --------- SELAMAT ANDA TELAH BERHASIL MEMBOOKING KAMAR !!!! ----------- " << endl;
			kamarYgDiBooking = 1;		
			
			Folder_BOOK = "Users/" + username_berhasil_login + "/BOOKING"; 
			CreateDirectory(Folder_BOOK.c_str(),NULL);
			FileBooking = "Users/"+username_berhasil_login+"/BOOKING/BOOKING.txt";
			// Semua Data
			Input.open(FileBooking.c_str());
			Input<<tanggal_booking<< endl;
			Input<<bulan_booking<< endl;
			Input<<tahun_booking<< endl;
			Input<<brp_hari_booking<< endl;
			Input<<harga_booking<< endl;
			Input<<nama_pembooking<< endl;
			Input<<kamar_booking<< endl;
			Input.close();
						
			} else if (konfirmasi_booking == 'n') {
				kamarYgDiBooking = 0;
			} else {
				cout << "\t----- ERROR MASUKKAN KODE DENGAN BENAR !!! -----" << endl;
				goto konfirmBook;
				}
		} else if (kamarYgDiBooking == 1) {
			cout << "\t\t +-------------------------------------------------+" << endl;
			cout << "\t\t | Maaf, Anda Hanya Bisa Membooking Satu Kamar !!! |" << endl;			
			cout << "\t\t +-------------------------------------------------+" << endl;
		}
	}
	void informasi_booking() { 
		// Kalau Ada Kamar Yang Dibooking
		Folder_BOOK = "Users/" + username_berhasil_login + "/BOOKING"; 
		FileBooking = "Users/"+username_berhasil_login+"/BOOKING/BOOKING.txt";
		Output.open(FileBooking.c_str());
		if(Output){
		Output.close();	
		string blnBK,namaBK,kamarBK;
		int tglBK,thnBK,hariBK,hargaBK;
		Folder_BOOK = "Users/" + username_berhasil_login + "/BOOKING"; 
		FileBooking = "Users/"+username_berhasil_login+"/BOOKING/BOOKING.txt";
		Output.open(FileBooking.c_str());
		Output >> tglBK;
		Output >> blnBK;
		Output >> thnBK;
		Output >> hariBK;
		Output >> hargaBK;
		Output >> namaBK;
		Output.ignore();
		getline(Output,kamarBK);
//		while(!Output.eof()){
//		Output >> kamarBK;
//		KamarBOOK.append(kamarBK+" ");
//		};
		kamarYgDiBooking = 1;
		Output.close();
//		cout << blnBK << endl;
//		cout << tglBK << thnBK << hariBK  << endl;
//		cout << hargaBK << endl;
//		cout << namaBK << endl;
//		cout << KamarBK << endl;
		
		if (kamarYgDiBooking == 1){
			cout << endl ;
			cout <<"===========================================================================================================\n";
			cout <<"|      TANGGAL      |  " << tglBK << " "<< blnBK <<" "<< thnBK <<"  |"<< endl; 
			cout <<"===========================================================================================================\n";
			cout <<"| No |    ATAS NAMA     |              KAMAR             | SELAMA (HARI) |     HARGA    |      TOTAL      |\n";
			cout <<"===========================================================================================================\n";
			cout <<"| "<<setiosflags(ios::right)<<setw(3)<<"1"<<"|";
			cout <<" "<<setiosflags(ios::right)<<setw(17)<<namaBK<<"|";
			cout <<" "<<setiosflags(ios::right)<<setw(31)<<kamarBK<<"|";
			cout <<" "<<setiosflags(ios::right)<<setw(8)<<hariBK<<" Hari |";
			cout <<" "<<setiosflags(ios::right)<<setw(5)<<"Rp."<<hargaBK<<",-|";
			cout <<" "<<setiosflags(ios::right)<<setw(7)<<"Rp."<<hargaBK*hariBK<<",-|";
			cout <<"\n===========================================================================================================\n";	
			cout << endl ;
			cout << "\t\t\t---Apakah Anda Ingin Membatalkan Pemesanan ?? (y/n) --- = ";
			cin >> batalkan_pemesanan;
			if (batalkan_pemesanan == 'y') { // Batalkan Pemesanan
			remove(FileBooking.c_str());
			kamarYgDiBooking = 0;
			}
		} else if (kamarYgDiBooking == 0){ // Kalau Belum Ada Kamar Yg Dibooking
			cout << "\t\t\t-------------------------------------------------------- "  << endl;
			cout << "\t\t\t------------Blm Ada kamar Yang Anda Booking------------- "  << endl;
			cout << "\t\t\t-------------------------------------------------------- "  << endl;
			}
		} else {
//			cout << "NO FILE IN DIRECTORY" << endl;
			cout << "\t\t\t-------------------------------------------------------- "  << endl;
			cout << "\t\t\t------------Blm Ada kamar Yang Anda Booking------------- "  << endl;
			cout << "\t\t\t-------------------------------------------------------- "  << endl;
		}
		
	}	
	void daftar_member_plus() { 
	// Cek Apakah Sudah Ada yg terdaftar atau belum
	FileMember = "Users/"+username_berhasil_login+"/MemberSpecial/Member.txt";
	Output.open(FileMember.c_str());
	if(Output){
//		cout << "FILE EXIST ...." << endl;
	Output >> member_kode;
	Output >> no_ktp_member;
	Output.ignore();
	getline(Output,nama_member);
	getline(Output,asal_member);
	status_member=1;
	Output.close();
	} else {
//		cout << "File Doesn't Exist !!! " << endl;
	}
	
		if(status_member == 0) {
		cout << "\t=============================================================================" << endl;
		cout << "\t============ PENDAFTARAN MEMBER SPECIAL HOTEL MAHALI ALEXANDER  =============" << endl;
		cout << "\t=============================================================================" << endl;
		cin.ignore();
		cout << "\tMasukkan Nama Lengkap Anda = ";
		getline(cin,nama_member);
		cout << "\t========================" << endl;
		cout << "\tMasukkan Asal Anda = " ;
		getline(cin,asal_member);
		ktp:
		cout << "\t========================" << endl;
		cout << "\tNo.KTP  (16 Digits) Contoh:321xxxxxxxxxxxx1 = " ;
		cin >> no_ktp_member; 
		if (no_ktp_member.size() == 16 ) {
			 
		} else {
			cout << "\t----- ERROR, NO.KTP HARUS 16 DIGIT -----" << endl;
			goto ktp; 	
		}
		cout << "\t\t--------------------------------------------------------------------------------" << endl;
		cout << "\t\tSelamat !!!! Anda Telah Terdaftar Sebagai Member Special Hotel MAHALI ALEXANDER " << endl;
		cout << "\t\t--------------------------------------------------------------------------------" << endl;
		member_kode = (10000*nama_member.length()) +(1000*asal_member.length()) +  (nama_member.length()*12) + (asal_member.length()*6) +(1+rand() / 4);
		cout << "\t\t\t-------------------------------------------------" << endl;
		cout << "\t\t\t--- KODE MEMBER SPECIAL ANDA  = " << member_kode << endl;
		cout << "\t\t\t-------------------------------------------------" << endl;
		status_member=1;
		// Buat Folder Member
		string Folder_Member = "Users/"+username_berhasil_login+"/MemberSpecial";
		CreateDirectory(Folder_Member.c_str(), NULL);
		FileMember = "Users/"+username_berhasil_login+"/MemberSpecial/Member.txt";
		// Buat File
		Input.open(FileMember.c_str());
		Input << member_kode << endl;
		Input << no_ktp_member << endl;
		Input << nama_member << endl;
		Input << asal_member << endl;
		Input.close();
	 } else if (status_member == 1) {
	 		cout << "\t\t\t+---------------------------------------+" << endl;
			cout << "\t\t\t|Anda Sudah Terdaftar Sebagai Member !!!|" << endl;
	 		cout << "\t\t\t+---------------------------------------+" << endl;			
			cout << "=======================================" << endl;
			cout << "| Nama Member = " << nama_member << endl;
			cout << "=======================================" << endl;
			cout << "| Asal Member = " << asal_member << endl;
			cout << "=======================================" << endl;
			cout << "| NO.KTP Member = " << no_ktp_member << endl;
			cout << "=======================================" << endl;
			cout << "| Kode Member = " << member_kode << endl; 
			cout << "=======================================" << endl;
		}
	}
	void informasi_hotel() { 
		system("CLS");
		cout << "\t\t+--------------------------------------------------------------------------------------+" << endl;
		cout << "\t\t|----------------------------- HOTEL MAHALLI ALEXANDER --------------------------------|" << endl;
		cout << "\t\t+--------------------------------------------------------------------------------------+" << endl;
		cout << "\t\t| Jl. Ir. H Juanda No.19, Tonatan, Kec. Ponorogo, Kabupaten Ponorogo, Jawa Timur 63413 |" <<endl;
		cout << "\t\t| ----------------------------- No.Telp (0352) 3510388 ------------------------------- |" << endl;
		cout << "\t\t| ------------------------ Pemilik => Alexander De Mahalli --------------------------- |" << endl;
		cout << "\t\t| -------------------------------  Since 1996  --------------------------------------- |" << endl;
		cout << "\t\t| -------------------------------   7 Lantai   --------------------------------------- |" << endl;
		cout << "\t\t| ------------------------------------------------------------------------------------ |" << endl;
		cout << "\t\t| +-+-------------------------------| ULASAN |-------------------------------------+-+ |" << endl;
		cout << "\t\t| ------------------------------------------------------------------------------------ |" << endl;
		cout << "\t\t                          	"<<"|-----------------------------------------------|" << endl;
		cout << "\t\t              ~!	       	"<<"|                                               |" << endl;
		cout << "\t\t             .&&.          "<<"\t|     ------- Riski Hidayatullah -------      \t|" << endl;
		cout << "\t\t             P@@G          "<<"\t|        'Hotel ini Sangat Bagus Sekali'      \t|" << endl;
		cout << "\t\t    .::::::.?@@@@?.::::::.	"<<"|                   (7,4)                       |" << endl;
		cout << "\t\t    .7B&@@@@@@@@@@@@@@&B7.	"<<"|                                               |" << endl;
		cout << "\t\t       .7B&@@@@@@@@&B?.   	"<<"|-----------------------------------------------|" << endl;
		cout << "\t\t          Y@@@@@@@@5	  	"<<"|           ------- Amrico Putra ---------      |" << endl;
		cout << "\t\t         :@@@@BB@@@@:	   	"<<"| 'Luar biasa,kamar dan pelayanannya ok banget' |" << endl;
		cout << "\t\t         &@#J:  :?#@&.    	"<<"|           'All good' 'Hotel favorit anak2'    |" << endl;
		cout << "\t\t        7Y:        :Y7	   	"<<"|                      (7,9)                    |" << endl;
		cout << "\t\t                          	"<<"|                                               |" << endl;
		cout << "\t\t                          	"<<"|-----------------------------------------------|" << endl;
		cout << "\t\t              ~!	       	"<<"|         ------- Rafian Delon --------         |" << endl;
		cout << "\t\t             .&&.          "<<"\t|         'So far so good … nice place'       \t|" << endl;
		cout << "\t\t             P@@G          "<<"\t| 'Bantal yang bersih  kamar mandinya besar'  \t|" << endl;
		cout << "\t\t    .::::::.?@@@@?.::::::.	"<<"|                     (8,4)                     |" << endl;
		cout << "\t\t    .7B&@@@@@@@@@@@@@@&B7.	"<<"|-----------------------------------------------|" << endl;
		cout << "\t\t       .7B&@@@@@@@@&B?.   	"<<"|           ----- Rafi Rihan -----              |" << endl;
		cout << "\t\t          Y@@@@@@@@5	   	"<<"|    'Kebersihan baik, pelayanan sangat ramah'  |" << endl;
		cout << "\t\t         :@@@@BB@@@@:	   	"<<"|       'menyenangkan walau harganya mahal'     |" << endl;
		cout << "\t\t         &@#J:  :?#@&.   	"<<"|                   (8.0)                       |" << endl;
		cout << "\t\t        7Y:        :Y7	   	"<<"+-----------------------------------------------|" << endl;
		cout << "\t\t                          	"<<"												 " << endl;

	}
	void pelayanan_tambahan() {
		// Check-In
				string cek = "Users/"+username_berhasil_login+"/Check-In/Nama.txt";
		Output.open(cek.c_str());
		if (Output) {
		cout << "FILE EXIST....." << endl;
		kamarYgDiCheckIn =1;
		Output.close();
		}
		
		if (kamarYgDiCheckIn >= 1) {
			system("CLS");
			string ExtraFolder =  "Users/"+username_berhasil_login+"/Extra";
			CreateDirectory(ExtraFolder.c_str(),NULL);
			
			cout << "\t\t---------- PELAYANAN TAMBAHAN -----------" << endl;
			cout << "\t\t1.PIJAT" << endl;
			cout << "\t\t2.SPA" << endl;
			cout << "\t\t3.CUKUR RAMBUT" << endl;
			cout << "\t\t4.SEWA MEETING ROOM" << endl;
			cout << "\t\t5.KEMBALI" << endl;
			cout << "\t\t----------------" << endl;
			cout << "\t\t-- PILIH --->>>  ";
			cin >> pilih_tambahan;
				switch (pilih_tambahan) {
					case '1':
						pijat();
						tambahan++;
						break;
					case '2':
						spa();
						tambahan++;
						break;
					case '3':
						cukur_rambut();
						tambahan++;
						break;
					case '4':
						meeting_room();
						tambahan++;
						break;
					case '5':
						Utama();
						break;		
					default :
						break;		
				}
		} else if (kamarYgDiCheckIn == 0) {
			cout << "\t\t ------------------------------------------------------------------------------------------" << endl;
			cout << "\t\t ---- MAAF, ANDA HARUS MEN-CHECK-IN MINIMAL 1 KAMAR UNTUK BISA MENAMBAHKAN LAYANAN INI ----" << endl;
			cout << "\t\t ------------------------------------------------------------------------------------------" << endl;
			cout << endl;
			getchar();
			jeda();
			getchar();
			Utama();
		}
	}
	void pijat() {
		cout << "\t\t\t 1.PIJAT RELAKSASI/REFLEKSI ~ Rp.20.000" << endl;
		cout << "\t\t\t 2.PIJAT PEGEL-PEGEL ~ Rp.30.000" << endl;
		cout << "\t\t\t 3.PIJAT KESELEO ~ Rp.25.000" << endl;
		cout << "\t\t\t 4.PIJAT AROMATERAPI ~ Rp.35.000" << endl;
		cout << "\t\t\t 5.PIJAT TRADISIONAL ~ Rp.25.000" << endl;
		cout << "\t\t\t 6.Kembali" << endl;
		cout << "\t\t\t\t ----- PILIH ----:>>> ";
		cin >> pilih_pijat;
		switch (pilih_pijat) {
			case '1':
				pelayanan[tambahan] = pijat_1;
				harga_pelayanan[tambahan] = pijat_1_harga;
				break;
			case '2':
				pelayanan[tambahan] = pijat_2;
				harga_pelayanan[tambahan] = pijat_2_harga;
				break;
			case '3':
				pelayanan[tambahan] = pijat_3;
				harga_pelayanan[tambahan] = pijat_3_harga;
				break;
			case '4':
				pelayanan[tambahan] = pijat_4;
				harga_pelayanan[tambahan] = pijat_4_harga;
				break;
			case '5':
				pelayanan[tambahan] = pijat_5;
				harga_pelayanan[tambahan] = pijat_5_harga;
				break;
			case '6':
				Utama();
				break;
			default :
				cout << "------ ERROR !!!"	<< endl;	
				break;
		}
		string pelayananFile = "Users/"+username_berhasil_login+"/Extra/Pelayanan.txt";
		Input.open(pelayananFile.c_str(), ios::app);
		Input << pelayanan[tambahan] << endl;
		Input.close();
		string hargaPelayananFile = "Users/"+username_berhasil_login+"/Extra/Harga_Pelayanan.txt";
		Input.open(hargaPelayananFile.c_str(), ios::app);
		Input << harga_pelayanan[tambahan] << endl;
		Input.close();
	}
	void spa() {
		cout << "\t\t\t 1.Medical Spa  ~ Rp.20.000" << endl;
		cout << "\t\t\t 2.Destination Spa  ~ Rp.30.000" << endl;
		cout << "\t\t\t 3.Resort Spa  ~ Rp.25.000" << endl;
		cout << "\t\t\t 4.KEMBALI" << endl;
		cout << "\t\t\t\t ----- PILIH ----:>>> ";
		cin >> pilih_spa;
		switch (pilih_spa) {
			case '1' :
				pelayanan[tambahan] = spa_1;
				harga_pelayanan[tambahan] = spa_1_harga;
				break;
			case '2' :
				pelayanan[tambahan] = spa_2;
				harga_pelayanan[tambahan] = spa_2_harga;
				break;
			case '3' :
				pelayanan[tambahan] = spa_3;
				harga_pelayanan[tambahan] = spa_3_harga;
				break;
			case '4' :
				Utama();
				break;
			default :
				cout << "ERROR" << endl;
				break;
		}
		string pelayananFile = "Users/"+username_berhasil_login+"/Extra/Pelayanan.txt";
		Input.open(pelayananFile.c_str(), ios::app);
		Input << pelayanan[tambahan] << endl;
		Input.close();
		string hargaPelayananFile = "Users/"+username_berhasil_login+"/Extra/Harga_Pelayanan.txt";
		Input.open(hargaPelayananFile.c_str(), ios::app);
		Input << harga_pelayanan[tambahan] << endl;
		Input.close();
	}
	void cukur_rambut() {
		cout << "\t\t\t 1.CUKUR DEWASA ~ Rp.10.000" << endl;
		cout << "\t\t\t 2.CUKUR ANAK ~ Rp.7.000" << endl;
		cout << "\t\t\t 3.CUKUR JENGGOT & KUMIS ~ Rp.5.000" << endl;
		cout << "\t\t\t 4.CUKUR + PIJAT ~ Rp.15.000" << endl;
		cout << "\t\t\t 5.Kembali" << endl;
		cout << "\t\t\t\t ----- PILIH ----:>>> ";
		cin >> pilih_cukur_rambut;
		switch (pilih_cukur_rambut) {
			case '1' :
				pelayanan[tambahan] = cukram_1;
				harga_pelayanan[tambahan] = cukram_1_harga;
				break;
			case '2' :
				pelayanan[tambahan] = cukram_2;
				harga_pelayanan[tambahan] = cukram_2_harga;
				break;
			case '3' :
				pelayanan[tambahan] = cukram_3;
				harga_pelayanan[tambahan] = cukram_3_harga;
				break;
			case '4' :
				pelayanan[tambahan] = cukram_4;
				harga_pelayanan[tambahan] = cukram_4_harga;
				break;
			case '5' :
				Utama();
				break;
			default :
				cout << "ERROR" << endl;
				break;
		}
		string pelayananFile = "Users/"+username_berhasil_login+"/Extra/Pelayanan.txt";
		Input.open(pelayananFile.c_str(), ios::app);
		Input << pelayanan[tambahan] << endl;
		Input.close();
		string hargaPelayananFile = "Users/"+username_berhasil_login+"/Extra/Harga_Pelayanan.txt";
		Input.open(hargaPelayananFile.c_str(), ios::app);
		Input << harga_pelayanan[tambahan] << endl;
		Input.close();		
	}
	void meeting_room() {
		cout << "\t\t\t 1.STANDARD MEETING ROOM ~ Rp,100.000" << endl;
		cout << "\t\t\t 2.LARGE MEETING ROOM ~ Rp.150.000" << endl;
		cout << "\t\t\t 3.EXECUTIVE MEETING ROOM ~ Rp.250.000" << endl;
		cout << "\t\t\t 4.Kembali" << endl;
		cout << "\t\t\t\t ----- PILIH ----:>>> ";
		cin >> pilih_meeting_room;
		switch (pilih_meeting_room) {
			case '1' :
				pelayanan[tambahan] = meetroom_1;
				harga_pelayanan[tambahan] = meetroom_1_harga;
				break;
			case '2' :
				pelayanan[tambahan] = meetroom_2;
				harga_pelayanan[tambahan] = meetroom_2_harga;
				break;
			case '3' :
				pelayanan[tambahan] = meetroom_3;
				harga_pelayanan[tambahan] = meetroom_3_harga;
				break;
			case '4' :
				Utama();
				break;
			default :
				cout << "ERROR" << endl;
				break;
		}
		string pelayananFile = "Users/"+username_berhasil_login+"/Extra/Pelayanan.txt";
		Input.open(pelayananFile.c_str(), ios::app);
		Input << pelayanan[tambahan] << endl;
		Input.close();
		string hargaPelayananFile = "Users/"+username_berhasil_login+"/Extra/Harga_Pelayanan.txt";
		Input.open(hargaPelayananFile.c_str(), ios::app);
		Input << harga_pelayanan[tambahan] << endl;
		Input.close();
	}	
	void footerHotel() {
		system("CLS");
		cout << "\t\t\t\t|------------------------------------------|" << endl;
	 	cout << "\t\t\t\t|TERIMA KASIH TELAH BERKUNJUNG KE HOTEL INI|" << endl;
	 	cout << "\t\t\t\t|------------------------------------------|" << endl;
	}
	void Theme(){
		char pilih_tema;
		err:
		system("cls");
		cout << "\t\t\t\t----------------------------" << endl;
		cout << "\t\t\t\t--------CHANGE THEME--------" << endl;
		cout << "\t\t\t\t----------------------------" << endl;
		cout << "\t\t\t\t-- BACKGROUND ------ TEXT --" << endl;
		cout << "\t\t\t\t----------------------------" << endl;
		cout << "\t\t\t\t 1. DEFAULT (BLACK - WHITE)" << endl;
		cout << "\t\t\t\t 2. GREY - BLUE" << endl;
		cout << "\t\t\t\t 3. GREEN - BLACK" << endl;
		cout << "\t\t\t\t 4. GREEN - WHITE" << endl;
		cout << "\t\t\t\t 5. BLACK - LIGHT BLUE" << endl;
		cout << "\t\t\t\t 6. WHITE - BLACK" << endl;
		cout << "\t\t\t\t 7. PURPLE - LIGHT GREEN" << endl;
		cout << "\t\t\t\t----------------------------" << endl;
		cout << "\t\t\t\t------ PILIH -->  ";
		cin >> pilih_tema;
		switch (pilih_tema){
			case '1' :
				system("color 07");
				break;
			case '2' :
				system("color 81");
				break;
			case '3' :
				system("color 20");
				break;
			case '4' :
				system("color 27");
				break;
			case '5' :
				system("color 09");
				break;
			case '6' :
				system("color 70");
				break;
			case '7' :
				system("color 5A");
				break;
			default :
				goto err;
//				system("color ");
				break;
		
		}
		
		
	}
	void logout(){
		LogOut:
		system("cls");
		cout << "\t\t\t\t--------------------------------------------" << endl;
		cout << "\t\t\t\t----------------- LOG OUT ------------------" << endl;
		cout << "\t\t\t\t--------------------------------------------" << endl;
		cout << "\t\t\t\t APAKAH ANDA YAKIN INGIN LOG-OUT ??? (y/n) : " ;
		cin >> LogOut;
		if(LogOut == 'n'){
			Utama();
		} else if (LogOut == 'y'){
			
		} else {
			cout << "\t\t\t\t ERROR !!!!!" << endl;
			jeda();
			getchar();
			getchar();
			Utama();
		}
	}


}; 

int main() {
	do {
	loading();
	Home home = Home();
	home.home();
	if (keluar == 'y'){
		home.footer();
		goto selesai;
	}
//	 Instansiasi Class Header
	Header header = Header();
	header.headerHotel(); 
	// Instansiasi Class Hotel
	Hotel hotel = Hotel(); 
//	header.Greeting();
	hotel.jeda(); 
//	getchar();
	getchar();
	system("CLS");
	loading();
	hotel.Utama();
	home.reset();
	}while(LogOut == 'y');
	selesai:
	cin.get();
	return 0;
}
