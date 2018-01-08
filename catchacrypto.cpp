//developed by Qasim Raheem Khalid Mehmood Khokhar
//this code is not 100% complete but it will work, i will arrange it later.
#include"stdafx.h"
#include<iostream>
#include<stdlib.h>
#include <sstream>
#include<string>
#include <string.h>
#include<cstring>
#include<math.h>
#include<conio.h>
#include<time.h>
#include <locale.h>
#include<fstream>
#include<windows.h>
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include<MMSystem.h>
#include <winuser.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ios>
#include <conio.h>
#include"stdafx.h"
#include"stdafx.h"
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<string>
#include<conio.h>
#include<time.h>
#include <sstream>
#include<fstream>
#include<string>
#include<windows.h>
#include<MMSystem.h>
#include <winuser.h>
#include <iomanip>
#include <thread>
#include <atomic>
#include <string>
#pragma comment(lib, "winmm.lib")


#define on ,


using namespace std;
int main();
int app_color_page = 4, app_color_text=15;
void show_coin();
void add_fav();
void refresh();
void create_alarm();
void show_t_coin();
void admin_settings();
void read_setup();
void setup_agrement();
void login();
void save_setup_settings();
void userdata();
void menu();
void clean_coin();


bool coin_found = false;
char menu_opt;
string name;
int api_line = 0;
char get_word[45];
const int list_id = 1000;
int c_search_count = 1;
long double total_value_btc, trade_price_btc, quantity;
long double total_value_usd, trade_price_usd;
char y[8], m[8], d[8], t[12];
string buy_sell;


string coldstore, username, userpassword, productkey;
 char userc[20], passc[20];

int hbcolor = 8;
int lbcolor = 8;
int bbcolor = 79;
int text_tcolor = 15;
int text_scolor = 0;

int decimal_point = 8;

string alarm_tone_name = "Best_ringtones_remix_part_2_1_.wav";
std::wstring stemp = std::wstring(alarm_tone_name.begin(), alarm_tone_name.end());
LPCWSTR alarm_tone = stemp.c_str();


struct sreach
{
	int s_id;
	string id;
	string name;
	string symbol;

}c_search[1252];

struct Coin
{
	int listid = {0};
	int fav_id = {0};
	long double quantity;
	long double holding_price_btc;
	long double holding_price_usd;
	long double total_buy;
	long double total_sell;
	long double profit_btc;
	long double profit_usd;
	long double total_buy_btc;
	long double total_buy_usd;
	long double total_sell_btc;
	long double total_sell_usd;
	long double max_alarm_price_usd;
	long double max_alarm_price_btc;
	long double min_alarm_price_usd;
	long double min_alarm_price_btc;
	string id;
	string name;
	string symbol;
	string rank;
	long double price_usd;
	long double price_btc;
	string volume_usd;
	string market_cap_usd;
	string available_supply;
	string total_supply;
	string max_supply;
	string percent_change_1h;
	string percent_change_24h;
	string percent_change_7d;
	string last_updated;

}coin[100];


struct coin_bill
{
	int id=0;
	string buy_sell;
	string name;
	long double price_usd;
	long double price_btc;
	long double Total_value_btc, Total_value_usd, Trade_price_btc, Trade_price_usd, Quantity;
	string y;
	string m;
	string d;
	string t;

}coin_bill[100];

struct  dash
{

	long double price_btc;
	long double price_usd;
	long double total_buy_btc;
	long double total_buy_usd;
	long double total_sell_btc;
	long double total_sell_usd;
	long double total_profit_btc;
	long double total_profit_usd;
	long double quantity[100];
	string name[100];
	string symbol[100];
	long double profit_btc[100];
	long double profit_usd[100];

}dash;
void clear_desh()
{
	dash.price_btc = '\0';
	dash.price_usd = '\0';
	dash.total_buy_btc = '\0';
	dash.total_buy_usd = '\0';
	dash.total_sell_btc = '\0';
	dash.total_sell_usd = '\0';
	dash.total_profit_btc = '\0';
	dash.total_profit_usd = '\0';
	for (int i = 0; i < 100; i++)
	{
		dash.quantity[i]='\0';
		dash.name[i]="\0";
		dash.symbol[i]="\0";
		dash.profit_btc[i]='\0';
		dash.profit_usd[i] = '\0';

	}
	
}
int  int_validation()
{
	char user[30];
	int iquantity=0;
	user[0] = NULL;//to store username.
	//to store password.
	int i = 0;
	char a;//a Temp char
	for (i = 0;;)//infinite loop
	{
		a = getch();//stores char typed in a

					//check if a is numeric or alphabet
		if (a != 8 && a >= '0'&&a <= '9')
		{
			if (a != 13)
			{
				user[i] = a;//stores a in pass
				++i;
				cout << a;
			}
		}
		if (a == '\b'&&i >= 1)//if user typed backspace
							  //i should be greater than 1.
		{
			cout << "\b \b";//rub the character behind the cursor.
			--i;
			if (i == 0)
			{
				user[0] = NULL;
			}
		}
		if (a == '\r'&&user[0] != '\0')//if enter is pressed
		{
			user[i] = '\0';//null means end of string.
			break;//break the loop
		}
	}

	//cout << "user=" << user;
	//iquantity = stold(user);
	iquantity = atoi(user);
	//cout << "iquantity=" << iquantity;
	return iquantity;
}
long double  double_validation()
{
	char user[30];
	bool dot = true;
	string get_double;
	long double iquantity = 0;
	user[0] = NULL;//to store username.
				   //to store password.
	int i = 0;
	char a;//a Temp char
	for (i = 0;;)//infinite loop
	{
		a = getch();//stores char typed in a

					//check if a is numeric or alphabet
		if (a != 8 && a >= '0'&&a <= '9'|| (a == '.'&&dot==true))
		{
			if (a != 13)
			{
				user[i] = a;//stores a in pass
				++i;
				cout << a;
			}
			if (a=='.') 
			{
				dot = false;
			}
		}
		if (a == '\b'&&i >= 1)//if user typed backspace
							  //i should be greater than 1.
		{
			cout << "\b \b";//rub the character behind the cursor.
			--i;
			if (i == 0)
			{
				user[0] = NULL;
			}
		}
		if (a == '\r'&&user[0] != '\0')//if enter is pressed
		{
			user[i] = '\0';//null means end of string.
			break;//break the loop
		}
	}

	cout << "user=" << user;
	get_double = user;
	//iquantity = stold(user);
	iquantity = stold(get_double);
	cout << "iquantity=" << iquantity;
	return iquantity;
}

void text(int text_color = 7 on int paper_color = 0)
{ 
	// defaults to light_gray on black
	int color_total = (text_color + (paper_color * 16));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_total);
}
void in_dash()
{
	ifstream in_dash;
	in_dash.open("dash_file.txt");
	if (in_dash.is_open())
	{
		//cout << "file open";

		
			in_dash >> dash.price_btc >> 
				dash.price_usd >>
				dash.total_buy_btc >>
				dash.total_buy_usd >>
				dash.total_sell_btc >>
				dash.total_sell_usd >>
				dash.total_profit_btc>>
				dash.total_profit_usd;
			/*cout <<
				"\nprice_btc:" << dash.price_btc <<
				"\nprice_usd:" << dash.price_usd <<
				"\ntotal_buy_btc:" << dash.total_buy_btc <<
				"\ntotal_buy_usd:" << dash.total_buy_usd <<
				"\ntotal_sell_btc" << dash.total_sell_btc <<
				"\ntotal_sell_usd" << dash.total_sell_usd <<
				"\ntotal_profit btc" << dash.total_profit_btc<<
				"\ntotal_profit usd" << dash.total_profit_usd;*/
			for (int i = 1; i < 100; i++)
			{
				in_dash >> dash.quantity[i] >>
				dash.name[i] >>
				dash.symbol[i] >>
				dash.profit_btc[i]>>
				dash.profit_usd[i];
				
				/*cout <<
				"\nquantity" << dash.quantity[i] <<
				"\nname" << dash.name[i] <<
				"\nsymbol" << dash.symbol[i] <<
				"\nprofit" << dash.profit_btc[i] <<
				"\nprofit" << dash.profit_usd[i] << endl;*/
			}

		in_dash.close();

	}
}
void out_dash()
{

	ofstream out_dash;
	out_dash.open("dash_file.txt");
	if (out_dash.is_open())
	{
		//cout << "file open";

		
		out_dash <<
			dash.price_btc << "\t" <<
			dash.price_usd << "\t" <<
			dash.total_buy_btc << "\t" <<
			dash.total_buy_usd << "\t" <<
			dash.total_sell_btc << "\t" <<
			dash.total_sell_usd << "\t" <<
			dash.total_profit_btc << "\t" <<
			dash.total_profit_usd << endl;
		for (int i = 1; i < 100; i++)
		{
			out_dash << dash.quantity[i] << "\t" <<
			dash.name[i] << "\t" <<
			dash.symbol[i] << "\t" <<
			dash.profit_btc[i] << "\t" <<
			dash.profit_usd[i] << "\n" ;
		}

		out_dash.close();

	}
}
void save_dash()
{
	for (int i = 1; i < 100; i++)
	{
		if(coin[i].listid!=0)
		{
			dash.price_btc +=( coin[i].price_btc*coin[i].quantity);
			dash.price_usd += (coin[i].price_usd*coin[i].quantity);
			dash.total_buy_btc += coin[i].total_buy_btc;
			dash.total_buy_usd += coin[i].total_buy_usd;
			dash.total_sell_btc += coin[i].total_sell_btc;
			dash.total_sell_usd += coin[i].total_sell_usd;
			dash.total_profit_btc+= coin[i].profit_btc;
			dash.total_profit_usd += coin[i].profit_usd;
			dash.quantity[i] = coin[i].quantity;
			dash.name[i] = coin[i].name;
			dash.symbol[i] = coin[i].symbol;
			dash.profit_btc[i] = coin[i].profit_btc;
			dash.profit_usd[i] = coin[i].profit_usd;

		}
		
	}
}
struct t_coin
{
	string id;
	string name;
	string symbol;
	string rank="0";
	string price_usd;
	string price_btc;
	string volume_usd;
	string market_cap_usd;
	string available_supply;
	string total_supply;
	string max_supply;
	string percent_change_1h;
	string percent_change_24h;
	string percent_change_7d;
	string last_updated;

}t_coin;



//not using
void getall()
{
	string line;
	ifstream IPFile;
	int offset;
	cout << "";
	char* search0 = "IPv4 Address. . :";
	system("cd\\ & cd C:\\Users\\qasim\\AppData\\Local\\VirtualStore\\ & rd /s /q \"Program Files (x86)\"");
	system("cd\\ & cd C:\\Program Files (x86)\\GnuWin32\\bin & wget --execute robots=off --recursive --no-parent --continue --no-clobber https://api.coinmarketcap.com/v1/ticker/  --no-check-certificate");
	system("rem C:\\Users\\qasim\\AppData\\Local\\VirtualStore\\Program Files (x86) ProgramFiles(x86)");
	//system("xcopy \"C:\\Users\\qasim\\AppData\\Local\\VirtualStore\\ProgramFiles(x86)\\GnuWin32\\bin\\api.coinmarketcap.com\\v1\\ticker\"  C:\\Users\\qasim\\Desktop\\qasim2");

	IPFile.open("ip.txt");
	if (IPFile.is_open())
	{
		while (!IPFile.eof())
		{
			getline(IPFile, line);
			if ((offset = line.find(search0)) != string::npos)
			{
				line.erase(0, 39);
				cout << "IP Address=" << line << endl << endl;
				IPFile.close();
			}
		}
	}
}
void get_id(string id)
{
	string line;
	ifstream IPFile;
	int offset;
	cout << "";
	string command = "cd\\ & cd C:\\Program Files (x86)\\GnuWin32\\bin & wget --execute robots=off --recursive --no-parent --continue --no-clobber https://api.coinmarketcap.com/v1/ticker/" + id + "  --no-check-certificate";
	char* search0 = "IPv4 Address. . :";
	system("cd\\ & cd C:\\Users\\qasim\\AppData\\Local\\VirtualStore\\ & rd /s /q \"Program Files (x86)\"");

	//system("cd\\ & cd C:\\Program Files (x86)\\GnuWin32\\bin & wget --execute robots=off --recursive --no-parent --continue --no-clobber https://api.coinmarketcap.com/v1/ticker/  --no-check-certificate");
	system("rem C:\\Users\\qasim\\AppData\\Local\\VirtualStore\\Program Files (x86) ProgramFiles(x86)");
	//system("xcopy \"C:\\Users\\qasim\\AppData\\Local\\VirtualStore\\ProgramFiles(x86)\\GnuWin32\\bin\\api.coinmarketcap.com\\v1\\ticker\"  C:\\Users\\qasim\\Desktop\\qasim2");

	IPFile.open("ip.txt");
	if (IPFile.is_open())
	{
		while (!IPFile.eof())
		{
			getline(IPFile, line);
			if ((offset = line.find(search0)) != string::npos)
			{
				line.erase(0, 39);
				cout << "IP Address=" << line << endl << endl;
				IPFile.close();
			}
		}
	}
}

void currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	int nun = 0;
	tstruct = *localtime(&now);
	strftime(y, sizeof(y), "%Y", &tstruct);
	strftime(m, sizeof(m), "%m", &tstruct);
	strftime(d, sizeof(d), "%d", &tstruct);
	strftime(t, sizeof(t), "%X", &tstruct);

}
void in_search()
{
	ifstream in_search_file;
	in_search_file.open("search_file.txt");
	if(in_search_file.is_open())
	{
		//cout << "file open";

		for (int s = 0; s < 1252; s++)
		{
			
			//cout << s;
			in_search_file >> c_search[s].s_id;
			//int t_s_id= c_search[s].s_id;
			in_search_file >> c_search[c_search[s].s_id].id >> c_search[c_search[s].s_id].name >> c_search[c_search[s].s_id].symbol;
			//cout << "search id" << c_search[s].s_id << "-" << "id:" << c_search[s].id << "name:" << c_search[s].name << "symbol:" << c_search[s].symbol << "\n";
		}
		in_search_file.close();

	}
		
	
}
void out_search()
{
	ofstream out_search_file;
	out_search_file.open("search_file.txt");
	for (int s = 0; s<1252; s++)
	{
		if(s==0)
		{
			out_search_file << "\t" << "0" << "\t" << "0" << "\t" << "0" << "\t" << "0" << "\n";
		}
		else
		{
			out_search_file << "\t" << c_search[s].s_id << "\t" << c_search[c_search[s].s_id].id << "\t" << c_search[c_search[s].s_id].name << "\t" << c_search[c_search[s].s_id].symbol << "\n";
		}
		
	}
	out_search_file.close();
}
void clear_search()
{
	for (int s = 0; s<1252; s++)
	{
		c_search[s].s_id = '\0'; c_search[s].id = "\0"; c_search[s].name = "\0"; c_search[s].symbol = "\0";
	}
}
void search_api()
{
	if (api_line == 2)
	{
		c_search[c_search_count].id = t_coin.id;
		
	}
	if (api_line == 3)
	{
		c_search[c_search_count].name = t_coin.name;
	}
	if (api_line == 4)
	{
		c_search[c_search_count].symbol = t_coin.symbol;
	}
	if (api_line == 5)
	{
		c_search[c_search_count].s_id = stoi(t_coin.rank);
	}

	if (api_line == 16)
	{
		cout << "search id:"<< c_search[c_search_count].s_id <<"id:" << c_search[c_search_count].id << "name:" << c_search[c_search_count].name << "symbol:" << c_search[c_search_count].symbol << "\n";

	}
} 
void search_t_coin()
{
	c_search[c_search_count].s_id = stoi(t_coin.rank);
	c_search[c_search_count].id = t_coin.id;
	c_search[c_search_count].name = t_coin.name;	
	c_search[c_search_count].symbol = t_coin.symbol;
	//cout <<"search id"<< c_search[c_search_count].s_id <<"id:" << c_search[c_search_count].id << "name:" << c_search[c_search_count].name << "symbol:" << c_search[c_search_count].symbol << "\n";

}
void create_buy() 
{
	
	cout << "current price: " << "B" << t_coin.price_btc<<endl;
	cout << "current price: " << "$" << t_coin.price_usd<<endl;
	cout << "trade price: " << "B" << t_coin.price_btc << endl;
	cout << "do you want to change trade price?Y/N:";
	char opt;
	do
	{
		opt = _getch();

	} while (opt!='y'&&opt != 'Y'&&opt != 'N'&&opt != 'n');
	if((opt == 'y'||opt == 'Y')&& name=="bitcoin")
	{
		long double btc = 1, coin = 1, usd = 0;
		cout << "Enter trade value: $";
		trade_price_usd= double_validation();
		btc = stod(t_coin.price_usd);
		trade_price_btc = trade_price_usd/btc;
		cout << "trade_price_btc ==" << trade_price_btc;
	}
	else if ((opt == 'y' || opt == 'Y') && name != "bitcoin")
	{
		long double btc = 0, coin = 1, usd = 0;
		cout << "Enter trade value: B";
		//cin>> trade_price_btc;
		trade_price_btc=double_validation();
		btc= stod(t_coin.price_btc);
		usd = stod(t_coin.price_usd);
		usd = usd/btc;
		trade_price_usd = trade_price_btc*usd;


	} 
	else
	{
		trade_price_btc = stod(t_coin.price_btc);
		trade_price_usd = stod(t_coin.price_usd);
	}
	cout << "\nEnter Quantity:";
	quantity= double_validation();
	total_value_btc = quantity*trade_price_btc;
	cout << "\nquantity:" << quantity<< endl << "\ntrade price: B" << trade_price_btc << endl << "\nTotal value: B" <<total_value_btc<<endl;
	total_value_usd = quantity*trade_price_usd;
	cout << "\nquantity:" << quantity << endl << "\ntrade price: $" << trade_price_usd << endl << "\nTotal value: $" << total_value_usd << endl;

	system("pause");
	//we are buying coin
	buy_sell = "buy";
}
void create_sell()
{

	cout << "current price: " << "B" << t_coin.price_btc << endl;
	cout << "current price: " << "$" << t_coin.price_usd << endl;
	cout << "trade price: " << "B" << t_coin.price_btc << endl;
	cout << "do you want to change trade price?Y/N:";
	char opt;
	do
	{
		opt = _getch();

	} while (opt != 'y'&&opt != 'Y'&&opt != 'N'&&opt != 'n');
	if ((opt == 'y' || opt == 'Y') && name == "bitcoin")
	{
		long double btc = 1, coin = 1, usd = 0;
		cout << "Enter trade value: $";
		trade_price_usd= double_validation();
		btc = stod(t_coin.price_usd);
		trade_price_btc = trade_price_usd / btc;
		cout << "trade_price_btc ==" << trade_price_btc;
	}
	else if ((opt == 'y' || opt == 'Y') && name != "bitcoin")
	{
		long double btc = 0, coin = 1, usd = 0;
		cout << "Enter trade value: B";
		trade_price_btc=double_validation();
		btc = stod(t_coin.price_btc);
		usd = stod(t_coin.price_usd);
		usd = usd / btc;
		trade_price_usd = trade_price_btc*usd;


	}
	else
	{
		trade_price_btc = stod(t_coin.price_btc);
		trade_price_usd = stod(t_coin.price_usd);
	}
	cout << endl;
	bool valid = false;
	do
	{
		
		cout << "\rEnter Quantity:          \b\b\b\b\b\b\b\b\b\b";
		quantity = double_validation();
		for(int i=1;i<100;i++)
		{
			//cout << coin[i].id << "==" << name;
			if (coin[i].id == name) 
			{
				if (coin[i].quantity >= quantity) 
				{
					valid = true;
				}
				else 
				{
					cout << "\b\b\b\r\r\b\b\b\r\r";
				}
				break;
			}
		}
		
		
	} while (valid==false);
	
	
	total_value_btc = quantity*trade_price_btc;
	cout << "\nquantity B:" << quantity << endl << "\ntrade price B:" << trade_price_btc << endl << "\nTotal value: B" << total_value_btc << endl;
	total_value_usd = quantity*trade_price_usd;
	cout << "\nquantity B:" << quantity << endl << "\ntrade price usd:" << trade_price_usd << endl << "\nTotal value: usd" << total_value_usd << endl;


	//we are buying coin
	buy_sell = "sell";
	system("pause");
}
void save_bill()
{
	for(int i=1;i<100;i++)
	{
		if (menu_opt == 'R') 
		{
			currentDateTime();
			coin_bill[99].id = i;
			coin_bill[99].buy_sell = buy_sell;
			coin_bill[99].name = name;
			coin_bill[99].price_btc = stod(t_coin.price_btc);
			coin_bill[99].price_usd = stod(t_coin.price_usd);
			coin_bill[99].Quantity = quantity;
			coin_bill[99].Trade_price_btc = trade_price_btc;
			coin_bill[99].Trade_price_usd = trade_price_usd;
			coin_bill[99].Total_value_btc = total_value_btc;
			coin_bill[99].Total_value_usd = total_value_usd;
			coin_bill[99].y = y;
			coin_bill[99].m = m;
			coin_bill[99].d = d;
			coin_bill[99].t = t;


			bool coin_saved = false;

			for (int i = 1; i < 100; i++)
			{
				if (coin[i].id == name)
				{

					coin[i].listid = 0;
					coin[i].fav_id = '\0';
					coin[i].quantity = '\0';
					coin[i].holding_price_btc = '\0';
					coin[i].holding_price_usd = '\0';
					coin[i].total_buy = '\0';
					coin[i].total_sell = '\0';
					coin[i].total_buy_btc = '\0';
					coin[i].total_buy_usd = '\0';
					coin[i].total_sell_btc = '\0';
					coin[i].total_sell_usd = '\0';
					coin[i].profit_btc = '\0';
					coin[i].profit_usd = '\0';
					coin[i].id = "\0";
					coin[i].name = "\0";
					coin[i].symbol = "\0";
					coin[i].rank = "\0";
					coin[i].price_usd = '\0';
					coin[i].price_btc = '\0';
					coin[i].volume_usd = "\0";
					coin[i].market_cap_usd = "\0";
					coin[i].available_supply = "\0";
					coin[i].total_supply = "\0";
					coin[i].percent_change_1h = "\0";
					coin[i].percent_change_24h = "\0";
					coin[i].percent_change_7d = "\0";
					coin[i].last_updated = "\0";

					coin[i].fav_id;
					coin[i].listid = i;
					for (int k = 1; k < 100; k++)
					{
						if (coin_bill[k].buy_sell == "buy")
						{
							coin[i].holding_price_btc += coin_bill[k].Total_value_btc;
							coin[i].holding_price_usd += coin_bill[k].Total_value_usd;
							coin[i].total_buy += coin_bill[k].Quantity;
							coin[i].quantity += coin_bill[k].Quantity;
							coin[i].total_buy_btc += (coin_bill[k].price_btc*coin_bill[k].Quantity);
							coin[i].total_buy_usd += (coin_bill[k].price_usd*coin_bill[k].Quantity);
						}
						if (coin_bill[k].buy_sell == "sell")
						{
							coin[i].holding_price_btc -= coin_bill[k].Total_value_btc;
							coin[i].holding_price_usd -= coin_bill[k].Total_value_usd;
							coin[i].total_sell += coin_bill[k].Quantity;
							coin[i].quantity -= coin_bill[k].Quantity;
							coin[i].total_sell_btc += (coin_bill[k].price_btc*coin_bill[k].Quantity);
							coin[i].total_sell_usd += (coin_bill[k].price_usd*coin_bill[k].Quantity);
						}
					}


					coin[i].id = t_coin.id;
					coin[i].name = t_coin.name;
					coin[i].symbol = t_coin.symbol;
					coin[i].rank = t_coin.rank;
					coin[i].price_usd = stod(t_coin.price_usd);
					coin[i].price_btc = stod(t_coin.price_btc);
					coin[i].volume_usd = t_coin.volume_usd;
					coin[i].market_cap_usd = t_coin.market_cap_usd;
					coin[i].available_supply = t_coin.available_supply;
					coin[i].total_supply = t_coin.total_supply;
					coin[i].max_supply = t_coin.max_supply;
					coin[i].percent_change_1h = t_coin.percent_change_1h;
					coin[i].percent_change_24h = t_coin.percent_change_24h;
					coin[i].percent_change_7d = t_coin.percent_change_7d;
					coin[i].last_updated = t_coin.last_updated;
					coin[i].profit_btc = (coin[i].price_btc*coin[i].quantity) - (coin[i].holding_price_btc);
					//cout << "profit:" << coin[i].profit_btc << "price btc" << coin[i].price_btc << "coin quanti:" << coin[i].quantity << "holding" << coin[i].holding_price_btc;
					coin[i].profit_usd = (coin[i].price_usd*coin[i].quantity) - (coin[i].holding_price_usd);
					//cout << "profit:" << coin[i].profit_usd << "price usd" << coin[i].price_usd << "coin quanti:" << coin[i].quantity << "holding" << coin[i].holding_price_usd;
					//system("pause");
					coin_saved = true;
					break;
				}

			}
			if (coin_saved == false)
			{
				//cout << "\nbool false found\n";
				//system("pause");
				for (int i = 1; i < 100; i++)
				{
					if (coin[i].listid == 0)
					{
						//cout << "\nid found\n";
						//system("pause");
						coin[i].listid = i;
						coin[i].fav_id;
						for (int k = 1; k < 100; k++)
						{
							if (coin_bill[k].buy_sell == "buy")
							{
								coin[i].holding_price_btc += coin_bill[k].Total_value_btc;
								coin[i].holding_price_usd += coin_bill[k].Total_value_usd;
								coin[i].total_buy += coin_bill[k].Quantity;
								coin[i].quantity += coin_bill[k].Quantity;
								coin[i].total_buy_btc += (coin_bill[k].price_btc*coin_bill[k].Quantity);
								coin[i].total_buy_usd += (coin_bill[k].price_usd*coin_bill[k].Quantity);
							}
							if (coin_bill[k].buy_sell == "sell")
							{
								coin[i].holding_price_btc -= coin_bill[k].Total_value_btc;
								coin[i].holding_price_usd -= coin_bill[k].Total_value_usd;
								coin[i].total_sell += coin_bill[k].Quantity;
								coin[i].quantity -= coin_bill[k].Quantity;
								coin[i].total_sell_btc += (coin_bill[k].price_btc*coin_bill[k].Quantity);
								coin[i].total_sell_usd += (coin_bill[k].price_usd*coin_bill[k].Quantity);
							}

						}

						coin[i].id = t_coin.id;
						coin[i].name = t_coin.name;
						coin[i].symbol = t_coin.symbol;
						coin[i].rank = t_coin.rank;
						coin[i].price_usd = stod(t_coin.price_usd);
						coin[i].price_btc = stod(t_coin.price_btc);
						coin[i].volume_usd = t_coin.volume_usd;
						coin[i].market_cap_usd = t_coin.market_cap_usd;
						coin[i].available_supply = t_coin.available_supply;
						coin[i].total_supply = t_coin.total_supply;
						coin[i].max_supply = t_coin.max_supply;
						coin[i].percent_change_1h = t_coin.percent_change_1h;
						coin[i].percent_change_24h = t_coin.percent_change_24h;
						coin[i].percent_change_7d = t_coin.percent_change_7d;
						coin[i].last_updated = t_coin.last_updated;
						coin[i].profit_btc = (coin[i].price_btc*coin[i].quantity) - coin[i].holding_price_btc;
						//cout << "profit_btc:" << coin[i].profit_btc << "price btc" << coin[i].price_btc << "coin quanti:" << coin[i].quantity << "holding" << coin[i].holding_price_btc;
						coin[i].profit_usd = (coin[i].price_usd*coin[i].quantity) - coin[i].holding_price_usd;
						//cout << "profit_usd:" << coin[i].profit_usd << "price btc" << coin[i].price_usd << "coin quanti:" << coin[i].quantity << "holding" << coin[i].holding_price_usd;
						//system("pause");
						coin_saved = true;
						break;
					}

				}
			}

			break;
		}
		else if(coin_bill[i].id == 0)
		{
			currentDateTime();
			coin_bill[i].id = i;
			coin_bill[i].buy_sell= buy_sell;
			coin_bill[i].name = name;
			coin_bill[i].price_btc = stod(t_coin.price_btc);
			coin_bill[i].price_usd = stod(t_coin.price_usd);
			coin_bill[i].Quantity = quantity;
			coin_bill[i].Trade_price_btc = trade_price_btc;
			coin_bill[i].Trade_price_usd = trade_price_usd;
			coin_bill[i].Total_value_btc = total_value_btc;
			coin_bill[i].Total_value_usd = total_value_usd;
			coin_bill[i].y = y;
			coin_bill[i].m = m;
			coin_bill[i].d = d;
			coin_bill[i].t = t;

			
			/*
			cout << "id:" << coin_bill[i].id;
			cout << "buy/sell:" << coin_bill[i].buy_sell;
			cout << "name:" << coin_bill[i].name;
			cout << "Price BTC:" << coin_bill[i].price_btc;
			cout << "Price USD:" << coin_bill[i].price_usd;
			cout << "Quantity" << coin_bill[i].Quantity;
			cout << "Trade Price_btc" << coin_bill[i].Trade_price_btc;
			cout << "Trade Price_usd" << coin_bill[i].Trade_price_usd;
			cout << "Total Value_btc" << coin_bill[i].Total_value_btc;
			cout << "Total Value_usd" << coin_bill[i].Total_value_usd;
			cout << "y" << coin_bill[i].y;
			cout << "m" << coin_bill[i].m;
			cout << "d" << coin_bill[i].d;
			cout << "t" << coin_bill[i].t << endl;
			system("pause");
			//*/
			bool coin_saved = false;
		
			for (int i = 1; i < 100; i++)
			{
				if (coin[i].id == name)
				{
					
					coin[i].listid = 0;
					coin[i].fav_id = '\0';
					coin[i].quantity = '\0';
					coin[i].holding_price_btc = '\0';
					coin[i].holding_price_usd = '\0';
					coin[i].total_buy = '\0';
					coin[i].total_sell = '\0';
					coin[i].total_buy_btc = '\0';
					coin[i].total_buy_usd = '\0';
					coin[i].total_sell_btc = '\0';
					coin[i].total_sell_usd = '\0';
					coin[i].profit_btc = '\0';
					coin[i].profit_usd = '\0';
					coin[i].id = "\0";
					coin[i].name = "\0";
					coin[i].symbol = "\0";
					coin[i].rank = "\0";
					coin[i].price_usd = '\0';
					coin[i].price_btc = '\0';
					coin[i].volume_usd = "\0";
					coin[i].market_cap_usd = "\0";
					coin[i].available_supply = "\0";
					coin[i].total_supply = "\0";
					coin[i].percent_change_1h = "\0";
					coin[i].percent_change_24h = "\0";
					coin[i].percent_change_7d = "\0";
					coin[i].last_updated = "\0";

					coin[i].fav_id;
					coin[i].listid=i;
					for (int k = 1; k < 100; k++)
					{
						if (coin_bill[k].buy_sell == "buy")
						{
							coin[i].holding_price_btc += coin_bill[k].Total_value_btc;
							coin[i].holding_price_usd += coin_bill[k].Total_value_usd;
							coin[i].total_buy += coin_bill[k].Quantity;
							coin[i].quantity += coin_bill[k].Quantity;
							coin[i].total_buy_btc += (coin_bill[k].price_btc*coin_bill[k].Quantity);
							coin[i].total_buy_usd += (coin_bill[k].price_usd*coin_bill[k].Quantity);
						}
						if(coin_bill[k].buy_sell == "sell")
						{
							coin[i].holding_price_btc  -=coin_bill[k].Total_value_btc;
							coin[i].holding_price_usd -= coin_bill[k].Total_value_usd;
							coin[i].total_sell += coin_bill[k].Quantity;
							coin[i].quantity -= coin_bill[k].Quantity;
							coin[i].total_sell_btc += (coin_bill[k].price_btc*coin_bill[k].Quantity);
							coin[i].total_sell_usd += (coin_bill[k].price_usd*coin_bill[k].Quantity);
						}
					}

					
					coin[i].id=t_coin.id;
					coin[i].name=t_coin.name;
					coin[i].symbol= t_coin.symbol;
					coin[i].rank= t_coin.rank;
					coin[i].price_usd= stod(t_coin.price_usd);
					coin[i].price_btc=stod(t_coin.price_btc);
					coin[i].volume_usd = t_coin.volume_usd;
					coin[i].market_cap_usd = t_coin.market_cap_usd;
					coin[i].available_supply = t_coin.available_supply;
					coin[i].total_supply = t_coin.total_supply;
					coin[i].max_supply = t_coin.max_supply;
					coin[i].percent_change_1h = t_coin.percent_change_1h;
					coin[i].percent_change_24h = t_coin.percent_change_24h;
					coin[i].percent_change_7d = t_coin.percent_change_7d;
					coin[i].last_updated = t_coin.last_updated;
					coin[i].profit_btc = (coin[i].price_btc*coin[i].quantity) - (coin[i].holding_price_btc);
					//cout << "profit:" << coin[i].profit_btc << "price btc" << coin[i].price_btc << "coin quanti:" << coin[i].quantity << "holding" << coin[i].holding_price_btc;
					coin[i].profit_usd= (coin[i].price_usd*coin[i].quantity) - (coin[i].holding_price_usd);
					//cout << "profit:" << coin[i].profit_usd << "price usd" << coin[i].price_usd << "coin quanti:" << coin[i].quantity << "holding" << coin[i].holding_price_usd;
					//system("pause");
					coin_saved = true;
					break;
				}

			}
			if(coin_saved == false)
			{
				//cout << "\nbool false found\n";
				//system("pause");
				for (int i = 1; i < 100; i++)
				{
					if (coin[i].listid == 0)
					{	
						//cout << "\nid found\n";
						//system("pause");
						coin[i].listid = i;
						coin[i].fav_id;
						for (int k = 1; k < 100; k++)
						{
							if (coin_bill[k].buy_sell == "buy")
							{
								coin[i].holding_price_btc += coin_bill[k].Total_value_btc;
								coin[i].holding_price_usd += coin_bill[k].Total_value_usd;
								coin[i].total_buy += coin_bill[k].Quantity;
								coin[i].quantity += coin_bill[k].Quantity;
								coin[i].total_buy_btc += (coin_bill[k].price_btc*coin_bill[k].Quantity);
								coin[i].total_buy_usd += (coin_bill[k].price_usd*coin_bill[k].Quantity);
							}
							if (coin_bill[k].buy_sell == "sell")
							{
								coin[i].holding_price_btc -= coin_bill[k].Total_value_btc;
								coin[i].holding_price_usd -= coin_bill[k].Total_value_usd;
								coin[i].total_sell += coin_bill[k].Quantity;
								coin[i].quantity -= coin_bill[k].Quantity;
								coin[i].total_sell_btc += (coin_bill[k].price_btc*coin_bill[k].Quantity);
								coin[i].total_sell_usd += (coin_bill[k].price_usd*coin_bill[k].Quantity);
							}
							
						}
						
						coin[i].id = t_coin.id;
						coin[i].name = t_coin.name;
						coin[i].symbol = t_coin.symbol;
						coin[i].rank = t_coin.rank;
						coin[i].price_usd = stod(t_coin.price_usd);
						coin[i].price_btc = stod(t_coin.price_btc);
						coin[i].volume_usd = t_coin.volume_usd;
						coin[i].market_cap_usd = t_coin.market_cap_usd;
						coin[i].available_supply = t_coin.available_supply;
						coin[i].total_supply = t_coin.total_supply;
						coin[i].max_supply = t_coin.max_supply;
						coin[i].percent_change_1h = t_coin.percent_change_1h;
						coin[i].percent_change_24h = t_coin.percent_change_24h;
						coin[i].percent_change_7d = t_coin.percent_change_7d;
						coin[i].last_updated = t_coin.last_updated;
						coin[i].profit_btc = (coin[i].price_btc*coin[i].quantity) - coin[i].holding_price_btc;
						//cout << "profit_btc:" << coin[i].profit_btc << "price btc" << coin[i].price_btc << "coin quanti:" << coin[i].quantity << "holding" << coin[i].holding_price_btc;
						coin[i].profit_usd = (coin[i].price_usd*coin[i].quantity) - coin[i].holding_price_usd;
						//cout << "profit_usd:" << coin[i].profit_usd << "price btc" << coin[i].price_usd << "coin quanti:" << coin[i].quantity << "holding" << coin[i].holding_price_usd;
						//system("pause");
						coin_saved = true;
						break;
					}

				}
			}

			break;
		}
		else 
		{
			//blank
		}
	}
	
}
void out_coin()
{
	ofstream out_coin;
	out_coin.open("coin_file.txt");
	for (int i = 1; i < 100; i++)
	{
		out_coin

			<< "\t" << coin[i].listid
			<< "\t" << coin[i].fav_id
			<< "\t" << coin[i].quantity
			<< "\t" << coin[i].holding_price_btc
			<< "\t" << coin[i].holding_price_usd
			<< "\t" << coin[i].total_buy
			<< "\t" << coin[i].total_sell
			<< "\t" << coin[i].profit_btc
			<< "\t" << coin[i].profit_usd
			<< "\t" << coin[i].total_buy_btc
			<< "\t" << coin[i].total_buy_usd
			<< "\t" << coin[i].total_sell_btc
			<< "\t" << coin[i].total_sell_usd
			<< "\t" << coin[i].max_alarm_price_usd
			<< "\t" << coin[i].max_alarm_price_btc
			<< "\t" << coin[i].min_alarm_price_usd
			<< "\t" << coin[i].min_alarm_price_btc
			<< "\t" << coin[i].id
			<< "\t" << coin[i].name
			<< "\t" << coin[i].symbol
			<< "\t" << coin[i].rank
			<< "\t" << coin[i].price_usd
			<< "\t" << coin[i].price_btc
			<< "\t" << coin[i].volume_usd
			<< "\t" << coin[i].market_cap_usd
			<< "\t" << coin[i].available_supply
			<< "\t" << coin[i].total_supply
			<< "\t" << coin[i].percent_change_1h
			<< "\t" << coin[i].percent_change_24h
			<< "\t" << coin[i].percent_change_7d
			<< "\t" << coin[i].last_updated<<endl;
	}
	out_coin.close();
}
void in_coin()
{
	ifstream in_coin;
	in_coin.open("coin_file.txt");
	for (int i = 1; i < 100; i++)
	{
		in_coin >>
			coin[i].listid
			>> coin[i].fav_id
			>> coin[i].quantity
			>> coin[i].holding_price_btc
			>> coin[i].holding_price_usd
			>> coin[i].total_buy
			>> coin[i].total_sell
			>> coin[i].profit_btc
			>> coin[i].profit_usd
			>> coin[i].total_buy_btc
			>> coin[i].total_buy_usd
			>> coin[i].total_sell_btc
			>> coin[i].total_sell_usd
			>> coin[i].max_alarm_price_usd
			>> coin[i].max_alarm_price_btc
			>> coin[i].min_alarm_price_usd
			>> coin[i].min_alarm_price_btc
			>> coin[i].id
			>> coin[i].name
			>> coin[i].symbol
			>> coin[i].rank
			>> coin[i].price_usd
			>> coin[i].price_btc
			>> coin[i].volume_usd
			>> coin[i].market_cap_usd
			>> coin[i].available_supply
			>> coin[i].total_supply
			>> coin[i].percent_change_1h
			>> coin[i].percent_change_24h
			>> coin[i].percent_change_7d
			>> coin[i].last_updated;

	}
	in_coin.close();
}
void clean_bill()
{
	for (int i = 0; i < 100; i++)
	{
		coin_bill[i].id = 0;
		coin_bill[i].buy_sell = "\0";
		coin_bill[i].name = "\0";
		coin_bill[i].price_btc = '\0';
		coin_bill[i].price_usd = '\0';
		coin_bill[i].Quantity = '\0';
		coin_bill[i].Trade_price_btc= '\0';
		coin_bill[i].Trade_price_usd = '\0';
		coin_bill[i].Total_value_btc = '\0';
		coin_bill[i].Total_value_usd = '\0';
		coin_bill[i].y = '\0';
		coin_bill[i].m = '\0';
		coin_bill[i].d = '\0';
		coin_bill[i].t = '\0';
	}
}
void clean_coin()
{
	for (int i = 0; i < 100; i++)
	{
		coin[i]. listid = 0;
		coin[i]. fav_id='\0';
		coin[i]. quantity = '\0';
		coin[i]. holding_price_btc = '\0';
		coin[i].holding_price_usd = '\0';
		coin[i]. total_buy = '\0';
		coin[i]. total_sell = '\0';
		coin[i]. total_buy_btc = '\0';
		coin[i]. total_buy_usd = '\0';
		coin[i]. total_sell_btc = '\0';
		coin[i]. total_sell_usd = '\0';
		coin[i]. profit_btc = '\0';
		coin[i].profit_usd = '\0';
		coin[i].max_alarm_price_usd='\0';
		coin[i].max_alarm_price_btc = '\0';
		coin[i].min_alarm_price_usd = '\0';
		coin[i].min_alarm_price_btc = '\0';
		coin[i]. id = "\0";
		coin[i]. name = "\0";
		coin[i]. symbol = "\0";
		coin[i]. rank = "\0";
		coin[i]. price_usd = '\0';
		coin[i]. price_btc = '\0';
		coin[i]. volume_usd = "\0";
		coin[i]. market_cap_usd = "\0";
		coin[i]. available_supply = "\0";
		coin[i]. total_supply = "\0";
		coin[i]. percent_change_1h = "\0";
		coin[i]. percent_change_24h = "\0";
		coin[i]. percent_change_7d = "\0";
		coin[i]. last_updated = "\0";
	}
}
void out_bill()
{
	string file_name = name + ".txt";
	ofstream out_bill;
	out_bill.open(file_name);
	for (int i = 1; i<100; i++)
	{
		
			out_bill << "\t" << coin_bill[i].id << "\t" <<
				coin_bill[i].buy_sell << "\t" <<
				coin_bill[i].name << "\t" <<
				coin_bill[i].price_btc << "\t" <<
				coin_bill[i].price_usd << "\t" <<
				coin_bill[i].Quantity << "\t" <<
				coin_bill[i].Trade_price_btc << "\t" <<
				coin_bill[i].Trade_price_usd << "\t" <<
				coin_bill[i].Total_value_btc << "\t" <<
				coin_bill[i].Total_value_usd << "\t" <<
				coin_bill[i].y << "\t" <<
				coin_bill[i].m << "\t" <<
				coin_bill[i].d << "\t" <<
				coin_bill[i].t << "\n";
		
	}
	out_bill.close();
}
void in_bill()
{
	string file_name = name + ".txt";
	ifstream in_bill;
	in_bill.open(file_name);
	for (int i = 1; i < 100; i++)
	{

		in_bill >> 
			coin_bill[i].id >>
			coin_bill[i].buy_sell >>
			coin_bill[i].name >> 
			coin_bill[i].price_btc >> 
			coin_bill[i].price_usd >> 
			coin_bill[i].Quantity >> 
			coin_bill[i].Trade_price_btc >> 
			coin_bill[i].Trade_price_usd >>
			coin_bill[i].Total_value_btc >>
			coin_bill[i].Total_value_usd >>
			coin_bill[i].y >> 
			coin_bill[i].m >> 
			coin_bill[i].d >>
			coin_bill[i].t;

	}
	in_bill.close();
}
void show_bill()
{
	int epagerow = 20, spagerow = 1, tid;
	bool usd = false;
	for (int i = 1; i < 100; i++) 
	{
		if (name==coin[i].name) 
		{
			tid = i;
		}
	}
	do {

		int stopflag = 0;
		system("cls");
		text(text_tcolor on hbcolor);
		cout << "\n\n\n                                                                                                                        " << endl;
		string str("CATCH_A_CRYPTO");
		int spaces = str.length();
		cout << "                                                                                                                        ";
		cout << "\r";
		for (int i = 0; i < 60 - (spaces / 2); i++)
		{
			cout << " ";
		}
		cout << "CATCH_A_CRYPTO" << endl;
		cout << "                                                                                                                        ";
		text(text_scolor on hbcolor);
		str = name;
		spaces = str.length();
		cout << "\r";
		for (int i = 0; i < 60 - (spaces / 2); i++)
		{
			cout << " ";
		}
		cout << name << endl;
		text(15);
		text(text_tcolor on lbcolor); cout << "\n\tID                    "; 
		text(text_scolor on bbcolor); 
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << coin[tid].id;
		
		text(text_tcolor on lbcolor);  cout<< "\n\tNAME                  ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << coin[tid].name;
		
		text(text_tcolor on lbcolor); cout << "\n\tSYMBOL                ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << coin[tid].symbol;
		
		text(text_tcolor on lbcolor); cout << "\n\tQUANTITY              ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << coin[tid].quantity;
		
		text(text_tcolor on lbcolor); cout << "\n\tHOLDING PRICE BTC     ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << "B:" << coin[tid].holding_price_btc;
		
		text(text_tcolor on lbcolor); cout << "\n\tHOLDING PRICE USD     ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << "$:" << coin[tid].holding_price_usd;
		
		text(text_tcolor on lbcolor); cout << "\n\tTOTAL " + coin[tid].symbol + " BUY       ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << coin[tid].total_buy;
		
		text(text_tcolor on lbcolor); cout << "\n\tTOTAL " + coin[tid].symbol + " SELL      ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << coin[tid].total_sell;
		
		text(text_tcolor on lbcolor); cout << "\n\tTOTAL BUY BTC         ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << "B:" << coin[tid].total_buy_btc;
		
		text(text_tcolor on lbcolor); cout << "\n\tTOTAL BUY USD         ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << "$:" << coin[tid].total_buy_usd;
		
		
		text(text_tcolor on lbcolor); cout << "\n\tTOTAL SELL BTC        ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << "B:" << coin[tid].total_sell_btc;
		
		text(text_tcolor on lbcolor); cout << "\n\tTOTAL SELL USD        ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << "$:" << coin[tid].total_sell_usd;
		
		text(text_tcolor on lbcolor); cout << "\n\tPROFIT BTC            ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << "B:" << coin[tid].profit_btc;
		
		text(text_tcolor on lbcolor); cout << "\n\tPROFIT USD            ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << "$:" << coin[tid].profit_usd;
		
		text(text_tcolor on lbcolor); cout << "\n\tRANK                  ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << coin[tid].rank;
		
		text(text_tcolor on lbcolor); cout << "\n\tCURRENT PRICE BTC     ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << "B:" << coin[tid].price_btc;
		
		text(text_tcolor on lbcolor); cout << "\n\tCURRENT PRICE USD     ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << "$:" << coin[tid].price_usd;
		
		text(text_tcolor on lbcolor); cout << "\n\tVOLUME USD            ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << "$:" << coin[tid].volume_usd;
		
		text(text_tcolor on lbcolor); cout << "\n\tMARKET CAP USD        ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << "$:"<<coin[tid].market_cap_usd;
		
		text(text_tcolor on lbcolor); cout << "\n\tAVAILABLE SUPPLY      ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << coin[tid].available_supply;
		
		text(text_tcolor on lbcolor); cout << "\n\tTOTAL SUPPLY          ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << coin[tid].total_supply;
		
		text(text_tcolor on lbcolor); cout << "\n\tPERCENT_Change_1d     ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << coin[tid].percent_change_1h;
		
		text(text_tcolor on lbcolor); cout << "\n\tPERCENT_Change_24d    ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << coin[tid].percent_change_24h;
		
		text(text_tcolor on lbcolor); cout << "\n\tPERCENT_Change_7d     ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << coin[tid].percent_change_7d<<endl<<endl;
		//coin[i].listid = 0;
		//coin[i].fav_id = '\0';

		text(text_tcolor on lbcolor);
		cout << "BUY/SELL ";
		cout << "PRICE-B  ";
		cout << "PRICE-$  ";
		cout << "QUANTITY  ";
		cout << "TRADE-PRICE_B   ";
		cout << "TRADE-PRICE_$   ";
		cout << "TOTAL-VALUE_B   ";
		cout << "TOTAL-VALUE_$   ";
		cout << "DATE/TIME          " << endl;
		for (int i = 1; i < 100; i++)
		{
			if (coin_bill[i].id != 0)
			{


				text(0 on 0);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t     ";
				text(text_scolor on bbcolor);
				for (int spaces = 0; spaces < 19; spaces++)
				{
					cout << " ";
				}
				for (int spaces = 0; spaces < 19; spaces++)
				{
					cout << "\b";
				}
				cout << coin_bill[i].d << "/" << coin_bill[i].m << "/" << coin_bill[i].y << "/" << coin_bill[i].t;

				text(0 on 0);
				cout << "\r\t\t\t\t\t\t\t\t\t\t     ";
				text(text_scolor on bbcolor);
				for (int spaces = 0; spaces < 16; spaces++)
				{
					cout << " ";
				}
				for (int spaces = 0; spaces < 16; spaces++)
				{
					cout << "\b";
				}
				cout << coin_bill[i].Total_value_usd;

				text(0 on 0);
				cout << "\r\t\t\t\t\t\t\t\t     ";
				text(text_scolor on bbcolor);
				for (int spaces = 0; spaces < 16; spaces++)
				{
					cout << " ";
				}
				for (int spaces = 0; spaces < 16; spaces++)
				{
					cout << "\b";
				}
				cout << coin_bill[i].Total_value_btc;

				text(0 on 0);
				cout << "\r\t\t\t\t\t\t     ";
				text(text_scolor on bbcolor);
				for (int spaces = 0; spaces < 16; spaces++)
				{
					cout << " ";
				}
				for (int spaces = 0; spaces < 16; spaces++)
				{
					cout << "\b";
				}
				cout << coin_bill[i].Trade_price_usd;

				text(0 on 0);
				cout << "\r\t\t\t\t     ";
				text(text_scolor on bbcolor);
				for (int spaces = 0; spaces < 16; spaces++)
				{
					cout << " ";
				}
				for (int spaces = 0; spaces < 16; spaces++)
				{
					cout << "\b";
				}
				cout << coin_bill[i].Trade_price_btc;

				text(0 on 0);
				cout << "\r\t\t\t   ";
				text(text_scolor on bbcolor);
				for (int spaces = 0; spaces < 10; spaces++)
				{
					cout << " ";
				}
				for (int spaces = 0; spaces < 10; spaces++)
				{
					cout << "\b";
				}
				cout << coin_bill[i].Quantity;

				text(0 on 0);
				cout << "\r\t\t  ";
				text(text_scolor on bbcolor);
				for (int spaces = 0; spaces < 9; spaces++)
				{
					cout << " ";
				}
				for (int spaces = 0; spaces < 9; spaces++)
				{
					cout << "\b";
				}
				cout << coin_bill[i].price_usd;

				text(0 on 0);
				cout << "\r\t ";
				text(text_scolor on bbcolor);
				for (int spaces = 0; spaces < 9; spaces++)
				{
					cout << " ";
				}
				for (int spaces = 0; spaces < 9; spaces++)
				{
					cout << "\b";
				}
				cout << coin_bill[i].price_btc;

				text(0 on 0);
				cout << "\r";
				text(text_scolor on bbcolor);
				for (int spaces = 0; spaces < 9; spaces++)
				{
					cout << " ";
				}
				for (int spaces = 0; spaces < 9; spaces++)
				{
					cout << "\b";
				}
				cout << coin_bill[i].buy_sell << endl;



			}
		}
			cout << endl ;
			text(15 on 0);
			char cho;
			do
			{
				cout << "PRESS BACKSPACE --> BACK, ESC --> MENU";
				cho = getch();


				if (cho == 8)
				{
					show_coin();
				}
				else if (cho == 27)
				{
					menu();
				}
				else
				{
					cout << "\r";
				}
			} while (cho != 8 && cho != 27);

		system("pause");
	} while (true);
}
void show_coin()
{
	/*for (int i = 1; i < 100; i++)
	{
		if(coin[i].listid!=0)
		{

			cout <<
				"list_id:" << coin[i].listid <<
				"fav_id:" << coin[i].fav_id <<
				"quantity :" << coin[i].quantity <<
				"holding_price_btc :" << coin[i].holding_price_btc <<
				"holding_price_usd :" << coin[i].holding_price_usd <<
				"total_buy :" << coin[i].total_buy <<
				"total_sell :" << coin[i].total_sell <<
				coin[i].profit_btc
				>> coin[i].profit_usd
				>> coin[i].total_buy_btc
				>> coin[i].total_buy_usd
				>> coin[i].total_sell_btc
				>> coin[i].total_sell_usd
				"id :" << coin[i].id <<
				"name :" << coin[i].name <<
				"symbol :" << coin[i].symbol <<
				"rank :" << coin[i].rank <<
				"price_usd :" << coin[i].price_usd <<
				"price_btc :" << coin[i].price_btc <<
				"volume_usd :" << coin[i].volume_usd <<
				"market_cap_usd :" << coin[i].market_cap_usd <<
				"available_supply :" << coin[i].available_supply <<
				"total_supply :" << coin[i].total_supply <<
				"percent_change_1h :" << coin[i].percent_change_1h <<
				"percent_change_24h :" << coin[i].percent_change_24h <<
				"percent_change_7d :" << coin[i].percent_change_7d <<
				"last_updated :" << coin[i].last_updated << endl;
		}
	}*/
	

	int epagerow = 20, spagerow = 1;
	bool usd = false;
	do {
		int stopflag = 0;
		system("cls");
		text(text_tcolor on hbcolor);
		cout << "\n\n\n                                                                                                                        " << endl;
		string str("CATCH_A_CRYPTO");
		int spaces = str.length();
		cout << "                                                                                                                        ";
		cout << "\r";
		for (int i = 0; i < 60 - (spaces / 2); i++)
		{
			cout << " ";
		}
		cout << "CATCH_A_CRYPTO" << endl;
		cout << "                                                                                                                        ";
		text(text_scolor on hbcolor);
		str = "My Coins";
		spaces = str.length();
		cout << "\r";
		for (int i = 0; i < 60 - (spaces / 2); i++)
		{
			cout << " ";
		}
		cout << "My Coins" << endl;
		

		text(15);
		text(text_tcolor on lbcolor); cout << "\nS_NO# ";
		text(text_tcolor on lbcolor); cout  << "SYMBOL  ";
		text(text_tcolor on lbcolor);  cout << "NAME                                  ";
		text(text_tcolor on lbcolor); cout  << "QUANTITY         ";
		text(text_tcolor on lbcolor); cout  << "HOLDING          ";
		text(text_tcolor on lbcolor); cout  << "PRICE            ";
		text(text_tcolor on lbcolor); cout  << "PROFIT           " << endl;
		
		
		for (int i = spagerow; i < epagerow; i++)
		{
			if (coin[i].listid == 0)
			{
				stopflag = 1;
				//cout << "good\n";
			}
			if (coin[i].listid != 0)
			{
				text(0 on 0);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t       ";
				text(text_scolor on bbcolor);
				
				if (usd == false)
				{
					if ( coin[i].profit_btc > 0)
					{
						text(text_scolor on 10);
						cout << "                 ";
						cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
						cout << "B:" << coin[i].profit_btc; text(15);
						

					}
					else if (coin[i].profit_btc < 0)
					{
						text(text_scolor on 12);
						cout << "                 ";
						cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
						cout << "B:" << coin[i].profit_btc; text(15);
					}
					else
					{
						text(text_scolor on bbcolor);
						cout << "                 ";
						cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
						cout << "B:" << coin[i].profit_btc; text(15);
					}
				}
				else
				{
					
					if (coin[i].profit_usd > 0)
					{
						text(text_scolor on 10);
						cout << "                 ";
						cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
						cout << "$:" << coin[i].profit_usd; text(15);


					}
					else if (coin[i].profit_usd < 0)
					{
						text(text_scolor on 12);
						cout << "                 ";
						cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
						cout << "$:" << coin[i].profit_usd; text(15);
					}
					else
					{
						text(text_scolor on bbcolor);
						cout << "                 ";
						cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
						cout << "$:" << coin[i].profit_usd; text(15);
					}
				}

				text(0 on 0);
				cout << "\r\t\t\t\t\t\t\t\t\t\t      ";
				text(text_scolor on bbcolor);
				cout << "                 ";
				cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
				if (usd == false)
				{
					cout << "B:" << coin[i].price_btc; text(15);
				}
				else
				{
					cout << "$:" << coin[i].price_usd; text(15);
				}

				text(0 on 0);
				cout << "\r\t\t\t\t\t\t\t\t     ";
				text(text_scolor on bbcolor);
				cout << "                 ";
				cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
				if (usd == false)
				{
					cout << "B:" << coin[i].holding_price_btc; text(15);
				}
				else
				{
					cout << "$:" << coin[i].holding_price_usd; text(15);
				}

				text(0 on 0);
				cout << "\r\t\t\t\t\t\t    ";
				text(text_scolor on bbcolor);
				cout << "                 ";
				cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
				cout << coin[i].quantity; text(15);


				if (coin[i].name.length() > 30)
				{
					text(0 on 0);
					cout << "\r\t      ";
					text(text_scolor on bbcolor);
					cout << "                                      ";
					cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					string con_name = coin[1].name;
					for (int it = 0; it < 33; it++)
					{
						//cout << dash.name[i]<<"hi\n";
						cout << con_name[it];
					}cout << "..."; text(15);

				}
				else
				{
					text(0 on 0);
					cout << "\r\t      ";
					text(text_scolor on bbcolor);
					cout << "                                      ";
					cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					cout << coin[i].name; text(15);


				}

				text(0 on 0);
				cout << "\r      ";
				text(text_scolor on bbcolor);
				cout << "        ";
				cout << "\b\b\b\b\b\b\b\b";
				cout << coin[i].symbol; text(15);

				text(0 on 0);
				cout << "\r";
				text(text_scolor on bbcolor);
				cout << "      ";
				cout << "\b\b\b\b\b\b";
				cout << coin[i].listid << endl; text(15);
			}

		}
		char cho;
		cout << endl;
		do
		{
			cout << "\rPRESS (A)SET Alarm,(N)NEXT RECORD, (P)PREVIOUS RECORD,(F)ADD TO FAVOURIT, (D)DETAIL OF COIN, (B)B <--> $:";
			cho = getch();


			if (cho == 'N'&& epagerow != 100 && stopflag != 1 || cho == 'n'&& epagerow != 100 && stopflag != 1)
			{
				spagerow = spagerow + 20;
				epagerow = epagerow + 20;
			}
			else if (cho == 'p'&& spagerow != 1 || cho == 'P'&& spagerow != 1)
			{
				spagerow = spagerow - 20;
				epagerow = epagerow - 20;
			}
			else if (cho == 'b'|| cho == 'B')
			{
				if(usd==false)
				{
					usd = true;
				}
				else if (usd == true)
				{
					usd = false;
				}
				else {}
			}
			else if (cho == 'd' || cho == 'D')
			{
				int input=0;
				cout << "\nEnter S_NO# of Coin";
				input = int_validation();
				for (int i = 1; i < 100; i++)
				{
					if (coin[i].listid == input) 
					{
						name=coin[i].name;
						in_bill();
						show_bill();
					}
				}
			
			}
			else if (cho == 'A' || cho == 'a')
			{
				int input = 0;
				cout << "\nEnter S_NO# of Coin";
				input = int_validation();
				for (int i = 1; i < 100; i++)
				{
					if (coin[i].listid == input)
					{
						name = coin[i].id;
						create_alarm();
					}
				}

			}
			else if (cho == 'f' || cho == 'F')
			{
				int input = 0;
				cout << "\nEnter S_NO# of Coin";
				input = int_validation();
				for (int i = 1; i < 100; i++)
				{
					if (coin[i].listid == input)
					{
						name = coin[i].name;
						add_fav();
					}
				}

			}
			else if (cho == 27)
			{
				menu();
			}
			else
			{
				cout << "\r";
			}
		} while (cho != 'P'&& cho != 'p'  && cho != 'N' && cho != 'n' &&cho != 27 && cho != 'B'&& cho != 'b');

	
	} while (true);
}
void del_fav()
{
	for (int i = 1; i < 100; i++)
	{
		if (name == coin[i].name)
		{
			for (int j = 1; j<100; j++)
			{
				if (coin[i].fav_id != 0)
				{
					coin[i].fav_id = 0;
					out_coin();
					break;
				}
			}
		}
	}
}
void add_fav()
{
	for (int i = 1; i < 100; i++)
	{
		if (name == coin[i].name)
		{
			for(int j=1;j<100;j++)
			{
				if(coin[i].fav_id==0)
				{
					coin[i].fav_id = j;
					cout << coin[i].name << " added to favourite\n";
					out_coin();
					break;
				}
			}
		}
	}
}
void show_fav() 
{
	int epagerow = 20, spagerow = 1;
	bool usd = false;
	do {
		int stopflag = 0;
		system("cls");
		text(text_tcolor on hbcolor);
		cout << "\n\n\n                                                                                                                        " << endl;
		string str("CATCH_A_CRYPTO");
		int spaces = str.length();
		cout << "                                                                                                                        ";
		cout << "\r";
		for (int i = 0; i < 60 - (spaces / 2); i++)
		{
			cout << " ";
		}
		cout << "CATCH_A_CRYPTO" << endl;
		cout << "                                                                                                                        ";
		text(text_scolor on hbcolor);
		str = "Favourite Coins";
		spaces = str.length();
		cout << "\r";
		for (int i = 0; i < 60 - (spaces / 2); i++)
		{
			cout << " ";
		}
		cout << "Favourite Coins" << endl;

		
		
		text(15);
		text(text_tcolor on lbcolor); cout << "\nS_NO# ";
		text(text_tcolor on lbcolor); cout << "SYMBOL  ";
		text(text_tcolor on lbcolor);  cout << "NAME                                  ";
		text(text_tcolor on lbcolor); cout << "QUANTITY         ";
		text(text_tcolor on lbcolor); cout << "HOLDING          ";
		text(text_tcolor on lbcolor); cout << "PRICE            ";
		text(text_tcolor on lbcolor); cout << "PROFIT           " << endl;


		for (int i = spagerow; i < epagerow; i++)
		{
			if (coin[i].fav_id== 0)
			{
				stopflag = 1;
				//cout << "good\n";
			}
			if (coin[i].fav_id != 0)
			{
				text(0 on 0);
				cout << "\t\t\t\t\t\t\t\t\t\t\t\t       ";
				text(text_scolor on bbcolor);

				if (usd == false)
				{
					if (coin[i].profit_btc > 0)
					{
						text(text_scolor on 10);
						cout << "                 ";
						cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
						cout << "B:" << coin[i].profit_btc; text(15);


					}
					else if (coin[i].profit_btc < 0)
					{
						text(text_scolor on 12);
						cout << "                 ";
						cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
						cout << "B:" << coin[i].profit_btc; text(15);
					}
					else
					{
						text(text_scolor on bbcolor);
						cout << "                 ";
						cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
						cout << "B:" << coin[i].profit_btc; text(15);
					}
				}
				else
				{

					if (coin[i].profit_usd > 0)
					{
						text(text_scolor on 10);
						cout << "                 ";
						cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
						cout << "$:" << coin[i].profit_usd; text(15);


					}
					else if (coin[i].profit_usd < 0)
					{
						text(text_scolor on 12);
						cout << "                 ";
						cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
						cout << "$:" << coin[i].profit_usd; text(15);
					}
					else
					{
						text(text_scolor on bbcolor);
						cout << "                 ";
						cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
						cout << "$:" << coin[i].profit_usd; text(15);
					}
				}

				text(0 on 0);
				cout << "\r\t\t\t\t\t\t\t\t\t\t      ";
				text(text_scolor on bbcolor);
				cout << "                 ";
				cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
				if (usd == false)
				{
					cout << "B:" << coin[i].price_btc; text(15);
				}
				else
				{
					cout << "$:" << coin[i].price_usd; text(15);
				}

				text(0 on 0);
				cout << "\r\t\t\t\t\t\t\t\t     ";
				text(text_scolor on bbcolor);
				cout << "                 ";
				cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
				if (usd == false)
				{
					cout << "B:" << coin[i].holding_price_btc; text(15);
				}
				else
				{
					cout << "$:" << coin[i].holding_price_usd; text(15);
				}

				text(0 on 0);
				cout << "\r\t\t\t\t\t\t    ";
				text(text_scolor on bbcolor);
				cout << "                 ";
				cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
				cout << coin[i].quantity; text(15);


				if (coin[i].name.length() > 30)
				{
					text(0 on 0);
					cout << "\r\t      ";
					text(text_scolor on bbcolor);
					cout << "                                      ";
					cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					string con_name = coin[1].name;
					for (int it = 0; it < 33; it++)
					{
						//cout << dash.name[i]<<"hi\n";
						cout << con_name[it];
					}cout << "..."; text(15);

				}
				else
				{
					text(0 on 0);
					cout << "\r\t      ";
					text(text_scolor on bbcolor);
					cout << "                                      ";
					cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					cout << coin[i].name; text(15);


				}

				text(0 on 0);
				cout << "\r      ";
				text(text_scolor on bbcolor);
				cout << "        ";
				cout << "\b\b\b\b\b\b\b\b";
				cout << coin[i].symbol; text(15);

				text(0 on 0);
				cout << "\r";
				text(text_scolor on bbcolor);
				cout << "      ";
				cout << "\b\b\b\b\b\b";
				cout << coin[i].listid << endl; text(15);
			}

		}
		char cho;
		do
		{
			cout << "\rPRESS (N)NEXT RECORD, (P)PREVIOUS RECORD,(F)DELETE TO FAVOURIT, (D)DETAIL OF COIN, (B)B <--> $:";
			cho = getch();


			if (cho == 'N'&& epagerow != 100 && stopflag != 1 || cho == 'n'&& epagerow != 100 && stopflag != 1)
			{
				spagerow = spagerow + 20;
				epagerow = epagerow + 20;
			}
			else if (cho == 'p'&& spagerow != 1 || cho == 'P'&& spagerow != 1)
			{
				spagerow = spagerow - 20;
				epagerow = epagerow - 20;
			}
			else if (cho == 'b' || cho == 'B')
			{
				if (usd == false)
				{
					usd = true;
				}
				else if (usd == true)
				{
					usd = false;
				}
				else {}
			}
			else if (cho == 'd' || cho == 'D')
			{
				int input = 0;
				cout << "\nEnter S_NO# of Coin";
				input = int_validation();
				for (int i = 1; i < 100; i++)
				{
					if (coin[i].listid == input)
					{
						name = coin[i].name;
						in_bill();
						show_bill();
					}
				}

			}
			else if (cho == 'f' || cho == 'F')
			{
				int input = 0;
				cout << "\nEnter S_NO# of Coin";
				input = int_validation();
				for (int i = 1; i < 100; i++)
				{
					if (coin[i].listid == input)
					{
						name = coin[i].name;
						del_fav();
						show_fav();
					}
				}

			}
			else if (cho == 27)
			{
				menu();
			}
			else
			{
				cout << "\r";
			}
		} while (cho != 'P'&& cho != 'p'  && cho != 'N' && cho != 'n' &&cho != 27 && cho != 'B'&& cho != 'b');


	} while (true);
}
void create_watch()
{
	cout << "current price: " << "B" << t_coin.price_btc << endl;
	cout << "current price: " << "$" << t_coin.price_usd << endl;
	cout << "trade price: " << "B" << t_coin.price_btc << endl;
	cout << "do you want to change trade price?Y/N:";
	char opt;
	do
	{
		opt = _getch();

	} while (opt != 'y'&&opt != 'Y'&&opt != 'N'&&opt != 'n');
	if ((opt == 'y' || opt == 'Y') && name == "bitcoin")
	{
		long double btc = 1, coin = 1, usd = 0;
		cout << "Enter trade value: $";
		trade_price_usd= double_validation();
		btc = stod(t_coin.price_usd);
		trade_price_btc = trade_price_usd / btc;
		cout << "trade_price_btc ==" << trade_price_btc;
	}
	else if ((opt == 'y' || opt == 'Y') && name != "bitcoin")
	{
		long double btc = 0, coin = 1, usd = 0;
		cout << "Enter trade value: B";
		trade_price_btc= double_validation();
		btc = stod(t_coin.price_btc);
		usd = stod(t_coin.price_usd);
		usd = usd / btc;
		trade_price_usd = trade_price_btc*usd;


	}
	else
	{
		trade_price_btc = stod(t_coin.price_btc);
		trade_price_usd = stod(t_coin.price_usd);
	}
	cout << "\nEnter Quantity:";


	quantity= double_validation();
	total_value_btc = quantity*trade_price_btc;
	cout << fixed << "\nquantity B:" << quantity << endl << "\ntrade price B:" << fixed << trade_price_btc << endl << "\nTotal value: B" << total_value_btc << endl;
	total_value_usd = quantity*trade_price_usd;
	cout << fixed << "\nquantity B:" << quantity << endl << "\ntrade price B:" << fixed << trade_price_usd << endl << "\nTotal value: B" << total_value_usd << endl;

	//we are buying coin
	buy_sell = "watch";
	//system("pause");
}

void add_coin()
{
	char opt;
	do {
		system("cls");
		show_t_coin();
		cout << "\n\t\t\t\t\t1.Buy\n\t\t\t\t\t2.Sell\n\t\t\t\t\t3.Watch Only\n\t\t\t\t\tESC --> MENU";
		opt = _getch();
		switch (opt)
		{
		case '1':
			cout << endl;
			clean_bill();
			create_buy();
			in_bill();
			save_bill();
			clear_desh();
			save_dash();
			out_bill();
			out_coin();
			out_dash();
			break;

		case '2':
			cout << endl;
			clean_bill();
			create_sell();
			in_bill();
			save_bill();
			clear_desh();
			save_dash();
			out_bill();
			out_coin();
			out_dash();
			break;

		case '3':
			cout << endl;
			clean_bill();
			create_watch();
			in_bill();
			save_bill();
			clear_desh();
			save_dash();
			out_bill();
			out_coin();
			out_dash(); break;

		case 27:
			menu();
			break;

		default:cout << "";

		}
	} while (opt != '1'&& opt != '2'  && opt != '3' && opt != 'n' &&opt != 27 && opt != 'B'&& opt != 'b');
}
void temp_coin()
{
	if (api_line == 2)
	{
		t_coin.id = get_word;
		//cout << "\ntemp_coin id:" << t_coin.id;
	}
	if (api_line == 3)
	{
		t_coin.name = get_word;
		//cout << "\ntemp_coin name:" << t_coin.name;
	}
	if (api_line == 4)
	{
		t_coin.symbol = get_word;
		//cout << "\ntemp_coin symbol:" << t_coin.symbol;
	}
	////c_search_count to search list
	////string  sconverter = t_coin.rank;
	c_search_count = stoi(t_coin.rank);
	//cout << "this is rank int:" << c_search_count << endl;
	if (api_line == 5)
	{
		t_coin.rank = get_word;
		//cout << "\ntemp_coin rank:" << t_coin.rank;
	}
	if (api_line == 6)
	{
		t_coin.price_usd = get_word;
		//cout << "\ntemp_coin price_usd:" << t_coin.price_usd;
	}
	if (api_line == 7)
	{
		t_coin.price_btc = get_word;
		//cout << "\ntemp_coin price_btc:" << t_coin.price_btc;
	}
	if (api_line == 8)
	{
		t_coin.volume_usd = get_word;
		//cout << "\ntemp_coin volume_usd:" << t_coin.volume_usd;
	}
	if (api_line == 9)
	{
		t_coin.market_cap_usd = get_word;
		//cout << "\ntemp_coin market_cap_usd:" << t_coin.market_cap_usd;
	}
	if (api_line == 10)
	{
		t_coin.available_supply = get_word;
		//cout << "\ntemp_coin available_supply:" << t_coin.available_supply;
	}
	if (api_line == 11)
	{
		t_coin.total_supply = get_word;
		//cout << "\ntemp_coin total_supply:" << t_coin.total_supply;
	}
	if (api_line == 12)
	{
		t_coin.max_supply = get_word;
		//cout << "\ntemp_coin max_supply:" << t_coin.max_supply;
	}
	if (api_line == 13)
	{
		t_coin.percent_change_1h = get_word;
		//cout << "\ntemp_coin percent_change_1h:" << t_coin.percent_change_1h;
	}
	if (api_line == 14)
	{
		t_coin.percent_change_24h = get_word;
		//cout << "\ntemp_coin percent_change_24h:" << t_coin.percent_change_24h;
	}
	if (api_line == 15)
	{
		t_coin.percent_change_7d = get_word;
		//cout << "\ntemp_coin percent_change_7d:" << t_coin.percent_change_7d;
	}if (api_line == 16)
	{
		t_coin.last_updated = get_word;
		//cout << "\ntemp_coin last_updated:" << t_coin.last_updated;
		search_t_coin();
	}
}
void show_t_coin() 
{
	if (menu_opt == '2' || menu_opt == '4' || menu_opt == '5')
	{
		
		
		for (int i = 1; i < 100; i++)
		{
			if (name == coin[i].id) 
			{
				if (coin[i].max_alarm_price_btc >= stod(t_coin.price_btc) && coin[i].min_alarm_price_btc <= stod(t_coin.price_btc) || coin[i].max_alarm_price_usd >= stod(t_coin.price_usd) && coin[i].min_alarm_price_usd <= stod(t_coin.price_usd)) 
				{
					std::wstring stemp = std::wstring(alarm_tone_name.begin(), alarm_tone_name.end());
					LPCWSTR alarm_tone = stemp.c_str();
					//PlaySound( TEXT ("Best_ringtones_remix_part_2_1_.wav"), NULL, SND_SYNC); //SND_FILENAME or SND_LOOP
					PlaySound(alarm_tone, NULL, SND_ASYNC | SND_FILENAME);
				}
			}
		}
		text(15);
		text(text_tcolor on lbcolor); cout << "\n\tID                    ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << t_coin.id;

		text(text_tcolor on lbcolor); cout << "\n\tNAME                  ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << t_coin.name;

		text(text_tcolor on lbcolor); cout << "\n\tSYMBOL                ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << t_coin.symbol;

		text(text_tcolor on lbcolor); cout << "\n\tRANK                  ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << t_coin.rank;

		text(text_tcolor on lbcolor); cout << "\n\tPRICE USD             ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << "B:" << t_coin.price_usd;

		text(text_tcolor on lbcolor); cout << "\n\tPRICE BTC             ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << "$:" << t_coin.price_btc;

		text(text_tcolor on lbcolor); cout << "\n\tVOLUME USD            ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << t_coin.volume_usd;

		text(text_tcolor on lbcolor); cout << "\n\tMARKET CAP USD        ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << t_coin.market_cap_usd;

		text(text_tcolor on lbcolor); cout << "\n\tAVAILABLE SUPPLY      ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << t_coin.available_supply;

		text(text_tcolor on lbcolor); cout << "\n\tTOTAL SUPPLY          ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << t_coin.total_supply;

		text(text_tcolor on lbcolor); cout << "\n\tMAX SUPPLY            ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << t_coin.max_supply;

		text(text_tcolor on lbcolor); cout << "\n\tPERCENT CHANGE 1H     ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << t_coin.percent_change_1h;
		
		text(text_tcolor on lbcolor); cout << "\n\tPERCENT CHANGE 24H    ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << t_coin.percent_change_24h;

		text(text_tcolor on lbcolor); cout << "\n\tPERCENT CHANGE 7D     ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << t_coin.percent_change_7d;
		
		text(text_tcolor on lbcolor); cout << "\n\tLAST UPDATED          ";
		text(text_scolor on bbcolor);
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << " ";
		}
		for (int spaces = 0; spaces < 80; spaces++)
		{
			cout << "\b";
		}
		cout << t_coin.last_updated;
		text(15 on 0);
		
		/*cout << t_coin.last_updated;
		cout << "\n\t\ttemp_coin id:        " << ;
		cout << "\n\t\tNAME:                " << ;
		cout << "\n\t\tSYMBOL:              " << ;
		cout << "\n\t\tRANK:                " << ;
		cout << "\n\t\tPRICE_USD:           " << ;
		cout << "\n\t\tPRICE_BTC:           " << ;
		cout << "\n\t\tVOLUME_USD:          " << ;
		cout << "\n\t\tMARKET_CAP_USD:      " << ;
		cout << "\n\t\tAVAILABLE SUPPLY:    " << ;
		cout << "\n\t\tTOTAL SUPPLY:        " << ;
		cout << "\n\t\tMAX SUPPLY:          " << ;
		cout << "\n\t\tPERCENT CHANGE 1H:   " << ;
		cout << "\n\t\tPERCENT CHANGE 24H:  " << ;
		cout << "\n\t\tPERCENT CHANGE 7D:   " << ;
		cout << "\n\t\tLAST UPDATED:        " <<  << endl << endl;
		*/
	
	}cout << endl;
}
void show_search()
{
	for (int s = 0; s<1252; s++)
	{
		cout << "search id" << c_search[s].s_id << "-" << "id:" << c_search[s].id << "name:" << c_search[s].name << "symbol:" << c_search[s].symbol << "\n";
	}
}
void dashboard()
{
	
	
	int epagerow = 10, spagerow = 1;
	do {
		
		clear_desh();
		in_dash();
		int stopflag = 0;
		system("cls");
		text(text_tcolor on hbcolor);
		cout << "\n\n\n                                                                                                                        " << endl;
		string str("CATCH_A_CRYPTO");
		int spaces = str.length();
		cout << "                                                                                                                        ";
		cout << "\r";
		for (int i = 0; i < 60 - (spaces / 2); i++)
		{
			cout << " ";

		}cout << "CATCH_A_CRYPTO" << endl;
		cout << "                                                                                                                        ";
		text(text_scolor on hbcolor);
		str = "Dashboard";
		spaces = str.length();
		cout << "\r";
		for (int i = 0; i < 60 - (spaces / 2); i++)
		{
			cout << " ";

		}cout << "Dashboard" << endl;

		
		text(15);

		text(text_tcolor on lbcolor); cout << "\nPRICE BTC                    ";
		text(text_tcolor on lbcolor); cout << "TOTAL BUY BTC                 ";
		text(text_tcolor on lbcolor); cout << "TOTAL SELL BTC                ";
		text(text_tcolor on lbcolor); cout << "TOTAL PROFIT BTC               " << endl;

		text(0 on 0);
		cout << "\t\t\t\t\t\t\t\t\t\t\t ";
		if (dash.total_profit_btc > 0)
		{
			text(text_scolor on 10);
			cout << "                               ";
			cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
			cout << "B:" <<dash.total_profit_btc; text(15);

			
		}
		else if (dash.total_profit_btc < 0)
		{
			text(text_scolor on 12);
			cout << "                               ";
			cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
			cout << "B:" << dash.total_profit_btc; text(15);

		}
		else
		{
			
			text(text_scolor on bbcolor);
			cout << "                               ";
			cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
			cout << "B:" << dash.total_profit_btc; text(15);

		}

		text(0 on 0);
		cout << "\r\t\t\t\t\t\t\t   "; text(text_scolor on bbcolor);
		cout << "                              ";
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		cout << "B:" << dash.total_sell_btc; text(15);

		text(0 on 0);
		cout << "\r\t\t\t      "; text(text_scolor on bbcolor);
		cout << "                             ";
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		cout << "B:" << dash.total_buy_btc; text(15);

		text(0 on 0);
		cout << "\r"; text(text_scolor on bbcolor);
		cout << "                             ";
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		cout << "B:" << dash.price_btc << endl; text(15);

		
		text(text_tcolor on lbcolor); cout << "\nPRICE USD                    ";
		text(text_tcolor on lbcolor); cout << "TOTAL BUY USD                 ";
		text(text_tcolor on lbcolor); cout << "TOTAL SELL USD                ";
		text(text_tcolor on lbcolor); cout << "TOTAL PROFIT USD               " << endl;

		
		text(0 on 0);
		cout << "\t\t\t\t\t\t\t\t\t\t\t ";
		if (dash.total_profit_usd > 0)
		{
			text(text_scolor on 10);
			cout << "                               ";
			cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
			cout << "$:" << dash.total_profit_usd; text(15);

		}
		else if (dash.total_profit_usd < 0)
		{
			text(text_scolor on 12);
			cout << "                               ";
			cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
			cout << "$:" << dash.total_profit_usd; text(15);

		}
		else
		{
			text(text_scolor on 7);
			cout << "                               ";
			cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
			cout << "$:" << dash.total_profit_usd; text(15);

		}
		text(0 on 0);
		cout << "\r\t\t\t\t\t\t\t   "; text(text_scolor on bbcolor);
		cout << "                              ";
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		cout << "$:" << dash.total_sell_usd; text(15);

		text(0 on 0);
		cout << "\r\t\t\t      "; text(text_scolor on bbcolor);
		cout << "                             ";
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		cout << "$:" << dash.total_buy_usd; text(15);

		text(0 on 0);
		cout << "\r"; text(text_scolor on bbcolor);
		cout << "                             ";
		cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
		cout << "$:" << dash.price_usd << endl; text(15);

		cout << "=======================================================================================================================" << endl;

		text(text_tcolor on lbcolor); cout << "\nSYMBOL                 ";
		text(text_tcolor on lbcolor); cout << "NAME                    ";
		text(text_tcolor on lbcolor); cout << "QUANTITY                ";
		text(text_tcolor on lbcolor); cout << "PROFIT BTC              ";
		text(text_tcolor on lbcolor); cout << "PROFIT USD               " << endl;

		
		for (int i = spagerow; i < epagerow; i++)
		{
			if (dash.quantity[i] == 0)
			{
				stopflag = 1;
				//cout << "good\n";
			}
			if (dash.quantity[i] != 0)
			{
				text(0 on 0);
				cout << "\t\t\t\t\t\t\t\t\t\t\t       "; text(0 on bbcolor);

				if (dash.profit_usd[i] > 0)
				{
					text(text_scolor on 10);
					cout << "                         ";
					cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					cout << "B:" << dash.profit_usd[i]; text(15);

				}
				else if (dash.profit_usd[i] < 0)
				{
					text(text_scolor on 12);
					cout << "                         ";
					cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					cout << "B:" << dash.profit_usd[i]; text(15);

				}
				else
				{
					text(text_scolor on bbcolor);
					cout << "                         ";
					cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					cout << "B:" << dash.profit_usd[i]; text(15);

				}
				text(0 on 0);
				cout << "\r\t\t\t\t\t\t\t\t       "; text(text_scolor on bbcolor);

				if (dash.profit_btc[i] > 0)
				{
					text(text_scolor on 10);
					cout << "                        ";
					cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					cout << "B:" << dash.profit_btc[i]; text(15);

				}
				else if (dash.profit_btc[i] < 0)
				{
					text(text_scolor on 12);
					cout << "                        ";
					cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					cout << "B:" << dash.profit_btc[i]; text(15);

				}
				else
				{
					text(text_scolor on bbcolor);
					cout << "                        ";
					cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					cout << "B:" << dash.profit_btc[i]; text(15);

				}
				text(0 on 0);
				cout << "\r\t\t\t\t\t       "; text(text_scolor on bbcolor);
				cout << "                        ";
				cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
				cout << dash.quantity[i]; text(15);

				if (dash.name[i].length() > 23)
				{
					text(0 on 0);
					cout << "\r\t\t       "; text(text_scolor on bbcolor);
					cout << "                        ";
					cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					string con_name = dash.name[i];
					for (int it = 0; it < 21; it++)
					{
						//cout << dash.name[i]<<"hi\n";
						cout << con_name[it];
					}cout << "..."; text(15);

				}
				else
				{
					text(0 on 0);
					cout << "\r\t\t       "; text(text_scolor on bbcolor);
					cout << "                        ";
					cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
					cout << dash.name[i]; text(15);

				}
				text(0 on 0);
				cout << "\r"; text(text_scolor on bbcolor);
				cout << "                       ";
				cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
				cout << dash.symbol[i] << endl; text(15);

			}
		}
		char cho;
		do
		{
			cout << "PRESS (N) FOR NEXT RECORD, (P) FOR PREVIOUS RECORD,(R) REFRESH:";
			cho = getch();


			if (cho == 'N'&& epagerow != 100 && stopflag != 1 || cho == 'n'&& epagerow != 100 && stopflag != 1)
			{
				spagerow = spagerow + 10;
				epagerow = epagerow + 10;
			}
			else if (cho == 'p'&& spagerow != 1 || cho == 'P'&& spagerow != 1)
			{
				spagerow = spagerow - 10;
				epagerow = epagerow - 10;
			}
			else if (cho == 27)
			{
				menu();
			}
			else if (cho == 'r'|| cho == 'R')
			{
				refresh();
			}
			else
			{
				cout << "\r";
			}
		} while (cho != 'P'&& cho != 'p'  && cho != 'N' && cho != 'n' &&cho != 27 && cho != 'R' && cho != 'r');
		out_dash();
	}while (true);
	
	
	/*cout <<
		"\nprice_btc:" << dash.price_btc <<
		"\nprice_usd:" << dash.price_usd <<
		"\ntotal_buy_btc:" << dash.total_buy_btc <<
		"\ntotal_buy_usd:" << dash.total_buy_usd <<
		"\ntotal_sell_btc" << dash.total_sell_btc <<
		"\ntotal_sell_usd" << dash.total_sell_usd <<
		"\ntotal_profit_btc" << dash.total_profit_btc<<
		"\ntotal_profit_usd" << dash.total_profit_usd;
	for (int i = 1; i < 100; i++)
	{
		if(dash.quantity[i]!=0)
		{
			cout << "\nquantity" << dash.quantity[i] <<
				"\nname" << dash.name[i] <<
				"\nsymbol" << dash.symbol[i] <<
				"\nprofit btc" << dash.profit_btc[i] <<
				"\nprofit usd" << dash.profit_usd[i] << endl;
		}
			
	}*/
	system("pause");
}
void start()
{
	
	system("cls");
	text(15 on hbcolor);
	system("color 07");
	//text(app_color_text on app_color_page);
	text(text_tcolor on hbcolor);
	cout << "\n\n\n                                                                                                                        " << endl;
	string str("CATCH_A_CRYPTO");
	int spaces = str.length();
	cout << "                                                                                                                        ";
	cout << "\r";
	for (int i = 0; i < 60 - (spaces / 2); i++)
	{
		cout << " ";

	}cout << "CATCH_A_CRYPTO" << endl;
	cout << "                                                                                                                        ";
	text(text_scolor on hbcolor);
	str = "Search Coin";
	spaces = str.length();
	cout << "\r";
	for (int i = 0; i < 60 - (spaces / 2); i++)
	{
		cout << " ";

	}cout << "Search Coin" << endl;

	text(15);
	cout << "\n\n\n";

	api_line = 0;
	string line[19];
	ifstream IPFile;
	char* search0 = "        ";
	string  get_command, delete_command;
	
		if (menu_opt == '1')
		{
			name = "";
		}
		else if (menu_opt == '2'|| menu_opt == '4'|| menu_opt == '5')
		{
			
			str = "Enter Coin Name/ID/Symbol:";
			spaces = str.length();
			cout << "\r";
			for (int i = 0; i < 60 - (spaces / 2); i++)
			{
				cout << " ";

			}cout << "Enter Coin Name/ID/Symbol:";
			do
			{
				getline(cin, name);
				cout << name;
			} while (name == "");
		}
		else if (menu_opt == 'R')
		{
			name = name;
		}
		else 
		{

		}

	
	

	
	int name_size = strlen(name.c_str());
	//cout << name_size;
	char up_name[20];
	for (int i = 0; i<20; i++)
	{
		up_name[i] = '\0';
	}
	for (int i = 0; i<name_size; i++)
	{
		//cout << name[i];
		up_name[i] = toupper(name[i]);
		//cout << up_name;
	}
	//cout<<up_name;
	bool found = false;
	for (int i = 1; i<1252; i++)
	{
		if(name == c_search[i].id || name == c_search[i].name || up_name == c_search[i].symbol)
		{
			name = c_search[i].id;
			found = true;
			break;
		}
		
		
	}
	if (found==false)
	{
		cout << "\n\nCoin Name/ID/Symbol not found in saved list. Enter Coin Name(eg:bitcoin):\n";
		do
		{
			getline(cin, name);

		} while (name == "");

	}
	get_command = "cd\\ & cd C:\\Program Files (x86)\\GnuWin32\\bin & wget  --execute robots=off --recursive --no-parent --continue --no-clobber https://api.coinmarketcap.com/v1/ticker/"+name+"/  --no-check-certificate";
	if (name == "")
	{
		delete_command = "cd\\ & cd C:\\Users\\qasim\\AppData\\Local\\VirtualStore\\Program Files (x86)\\GnuWin32\\bin\\api.coinmarketcap.com\\v1\\ticker &  del /f /q index.html";
	}
	else
	{
		delete_command = "cd\\ & cd C:\\Users\\qasim\\AppData\\Local\\VirtualStore\\Program Files (x86)\\GnuWin32\\bin\\api.coinmarketcap.com\\v1\\ticker &  rd /s /q \"" + name + "\"";
	}
	cout << delete_command<<endl<<name;
	system((const char*)delete_command.c_str());
	system((const char*)get_command.c_str());

	IPFile.open("C:\\Users\\qasim\\AppData\\Local\\VirtualStore\\Program Files (x86)\\GnuWin32\\bin\\api.coinmarketcap.com\\v1\\ticker\\" + name + "\\index.html");
	//json another api//IPFile.open("C:\\Users\\qasim\\AppData\\Local\\VirtualStore\\Program Files (x86)\\GnuWin32\\bin\\www.worldcoinindex.com\\apiservice\\json@key=3zVSMHxVicKfuEadyho5z6OaQEBYiE");
	system("pause");
	system("cls");
	if (IPFile.is_open())
	{
		//cout << "file is open!!!\n";

		while (getline(IPFile, line[api_line]))
		{
			//cout <<"line"<<api_line <<"# :"<< line[api_line]<<endl;
			int length_of_line = sizeof(line[api_line]);
			string seprate_word;

			//cout << size;
			char sep = ':';
			std::string s = line[api_line];
			for (size_t p = 0, q = 0; p != s.npos; p = q)
				seprate_word = s.substr(p + (p != 0), (q = s.find(sep, p + 1)) - p - (p != 1));
			int size;
			size = (seprate_word).length();
			//cout << "sixe:"<<size<<"word"<<get_word<<endl;
			for (int c = 0; c<45; c++)
			{
				get_word[c] = '\0';
			}
			int count = 0;
			for (int j = 0; j < size - 1; j++)
			{
				if (seprate_word[j] != '"' && seprate_word[j] != ','&& seprate_word[j] != ' ')
				{
					get_word[count] = seprate_word[j];
					count++;
				}

				//cout << seprate_word;
				//cout << "get_word:" << get_word; << endl;
				
			}
			temp_coin();
			out_search();
			
			//cout << "\ni#:" << i;

			/**/
			if (api_line == 17)
			{
				api_line = 0;
			}
			else
			{
				api_line++;
			}
			

		}IPFile.close();
		
		show_t_coin();
		/*for(int i=1;i<1250;i++)
		{
			cout<<"search id"<< c_search[i].s_id <<"-" << "id:" << c_search[i].id << "name:" << c_search[i].name << "symbol:" << c_search[i].symbol << "\n";
		}*/
		coin_found = true;
	}
	else 
	{
		cout << "file not open!!!"; 
		coin_found = false;
	}

	system("pause");
}
void decimal_points() 
{
	do
	{

		system("cls");
		text(text_tcolor on hbcolor);
		cout << "\n\n\n                                                                                                                        " << endl;
		string str("CATCH_A_CRYPTO");
		int spaces = str.length();
		cout << "                                                                                                                        ";
		cout << "\r";
		for (int i = 0; i < 60 - (spaces / 2); i++)
		{
			cout << " ";
		}
		cout << "CATCH_A_CRYPTO" << endl;
		cout << "                                                                                                                        ";
		text(text_scolor on hbcolor);
		str = "Decimal Points";
		spaces = str.length();
		cout << "\r";
		for (int i = 0; i < 60 - (spaces / 2); i++)
		{
			cout << " ";
		}
		cout << "Decimal Points" << endl;

		text(15);
		text(text_tcolor);
		cout << "\n\t\t\t\t\t\t      ";
		text(text_tcolor);
		cout << "ENTER DECIMAL POINT FROM 2 TO 8:";
	
		cout << endl;
		text(15 on 0);
		
		char cho;
		do
		{
			cout << "PRESS BACKSPACE --> BACK, ESC --> MENU, 2 <--> 8:";
			cho = getch();


			if (cho >= '1'&&cho <= '8')
			{
				switch (cho) 
				{
				case '1':
					decimal_point = 1;
					break;
				case '2':
					decimal_point = 2;
					break;
				case '3':
					decimal_point = 3;
					break;
				case '4':
					decimal_point = 4;
					break;
				case '5':
					decimal_point = 5;
					break;
				case '6':
					decimal_point = 6;
					break;
				case '7':
					decimal_point = 7;
					break;
				case '8':
					decimal_point = 8;
					break;
				default:cout << "";
				}
				save_setup_settings();
			}
			else if (cho == 27)
			{
				menu();
			}
			else if (cho == 8)
			{
				admin_settings();
			}
			else
			{
				cout << "\r";
			}
		} while (cho != 8 && cho != 27);

	} while (true);
}
void save_setup_settings()
{
	ofstream outfile;
	outfile.open("setup.xls");
	outfile << productkey << "\t" << coldstore << "\t" << username << "\t" << userpassword
		<< "\t" << hbcolor
		<< "\t" << lbcolor
		<< "\t" << bbcolor
		<< "\t" << text_tcolor
		<< "\t" << text_scolor
		<< "\t" << decimal_point
		<< "\t" << alarm_tone_name << endl;

	outfile.close();
	menu();
}
void themes() 
{
	do
	{

		system("cls");
		text(text_tcolor on hbcolor);
		cout << "\n\n\n                                                                                                                        " << endl;
		string str("CATCH_A_CRYPTO");
		int spaces = str.length();
		cout << "                                                                                                                        ";
		cout << "\r";
		for (int i = 0; i < 60 - (spaces / 2); i++)
		{
			cout << " ";
		}
		cout << "CATCH_A_CRYPTO" << endl;
		cout << "                                                                                                                        ";
		text(text_scolor on hbcolor);
		str = "Themes";
		spaces = str.length();
		cout << "\r";
		for (int i = 0; i < 60 - (spaces / 2); i++)
		{
			cout << " ";
		}
		cout << "Themes" << endl;


		text(15);
		text(text_tcolor);
		cout << "\n\t\t\t\t\t\t      ";
		text(text_tcolor);
		cout << "1.DARK";
		text(text_tcolor);
		cout << "\n\t\t\t\t\t\t      ";
		text(text_tcolor);
		cout << "2.BLUE";
		text(text_tcolor);
		cout << "\n\t\t\t\t\t\t      ";
		text(text_tcolor);
		cout << "3.CLASSIC";
		cout << endl;
		text(15 on 0);
		char cho;
		do
		{
			cout << "PRESS BACKSPACE --> BACK, ESC --> MENU, 1/2/3 THEMES:";
			cho = getch();


			 if (cho == '1')
			{
				hbcolor = 8;
				lbcolor = 8;
				bbcolor=  7;
				text_tcolor =15 ;
				text_scolor = 0 ;
				save_setup_settings();
				menu();
				

			}
			else if (cho == '2')
			{
				hbcolor = 9;
				lbcolor = 73;//int lbcolor = 3;
				bbcolor = 11;
				text_tcolor = 15;
				text_scolor = 0;
				save_setup_settings();
				menu();
			}
			else if (cho == '3')
			{
				hbcolor = 8;
				lbcolor = 8;
				bbcolor = 79;
				text_tcolor = 15;
				text_scolor = 0;
				save_setup_settings();
				menu();
			}
			else if (cho == 27)
			{
				menu();
			}
			else if (cho == 8)
			{
				admin_settings();
			}
			else
			{
				cout << "\r";
			}
		} while (cho != 8 && cho != 27);

	} while (true);
}
void change_user_password() 
{
//	,
}
void set_alarm() 
{
	do
	{

		system("cls");
		text(text_tcolor on hbcolor);
		cout << "\n\n\n                                                                                                                        " << endl;
		string str("CATCH_A_CRYPTO");
		int spaces = str.length();
		cout << "                                                                                                                        ";
		cout << "\r";
		for (int i = 0; i < 60 - (spaces / 2); i++)
		{
			cout << " ";
		}
		cout << "CATCH_A_CRYPTO" << endl;
		cout << "                                                                                                                        ";
		text(text_scolor on hbcolor);
		str = "Alarm Setting";
		spaces = str.length();
		cout << "\r";
		for (int i = 0; i < 60 - (spaces / 2); i++)
		{
			cout << " ";
		}
		cout << "Alarm Setting" << endl;


		text(15);
		text(text_tcolor);
		cout << "\n\t\t\t\t\t\t      ";
		text(text_tcolor);
		cout << "1.TONES1";
		text(text_tcolor);
		cout << "\n\t\t\t\t\t\t      ";
		text(text_tcolor);
		cout << "2.TONES2";
		text(text_tcolor);
		cout << "\n\t\t\t\t\t\t      ";
		text(text_tcolor);
		cout << "3.TONES3";
		cout << endl;
		text(15 on 0);
		char cho;
		do
		{
			cout << "PRESS BACKSPACE --> BACK, ESC --> MENU, 1/2/3 TONES:";
			cho = getch();


			if (cho == '1')
			{
				alarm_tone_name = "Best_ringtones_remix_part_2_1_.wav";
				std::wstring stemp = std::wstring(alarm_tone_name.begin(), alarm_tone_name.end());
				LPCWSTR alarm_tone = stemp.c_str();
				//PlaySound( TEXT ("Best_ringtones_remix_part_2_1_.wav"), NULL, SND_SYNC); //SND_FILENAME or SND_LOOP
				PlaySound(alarm_tone, NULL, SND_ASYNC | SND_FILENAME);
				save_setup_settings();
				menu();

			}
			else if (cho == '2')
			{
				alarm_tone_name = "Best_ringtones_remix_part_2_2_.wav";
				std::wstring stemp = std::wstring(alarm_tone_name.begin(), alarm_tone_name.end());
				LPCWSTR alarm_tone = stemp.c_str();
				//PlaySound( TEXT ("Best_ringtones_remix_part_2_1_.wav"), NULL, SND_SYNC); //SND_FILENAME or SND_LOOP
				PlaySound(alarm_tone, NULL, SND_ASYNC | SND_FILENAME);
				save_setup_settings();
				menu();
			}
			else if (cho == '3')
			{
				alarm_tone_name = "Best_ringtones_remix_part_2_3_.wav";
				std::wstring stemp = std::wstring(alarm_tone_name.begin(), alarm_tone_name.end());
				LPCWSTR alarm_tone = stemp.c_str();
				//PlaySound( TEXT ("Best_ringtones_remix_part_2_1_.wav"), NULL, SND_SYNC); //SND_FILENAME or SND_LOOP
				PlaySound(alarm_tone, NULL, SND_ASYNC | SND_FILENAME);
				save_setup_settings();
				menu();
			}
			else if (cho == 27)
			{
				menu();
			}
			else if (cho == 8)
			{
				admin_settings();
			}
			else
			{
				cout << "\r";
			}
		} while (cho != 8 && cho != 27);

	} while (true);
	
}
void create_alarm() 
{
	for (int i = 1; i < 100; i++)
	{
		if (name == coin[i].id) 
		{
			cout << "Enter max (B) value for coin";
			cin >> coin[i].max_alarm_price_btc;
			cout << "Enter max ($) value for coin";
			cin >> coin[i].max_alarm_price_usd;
			cout << "Enter min (B) value for coin";
			cin >> coin[i].min_alarm_price_btc;
			cout << "Enter min ($) value for coin";
			cin >> coin[i].min_alarm_price_usd;
			cout << "Alarm Set for " << name<<endl;
			system("pause");
		}
	}
	out_coin();
}
void admin_settings()
{
	
	
	system("cls");
	text(text_tcolor on hbcolor);
	system("color 07");
	//text(app_color_text on app_color_page);
	text(text_tcolor on hbcolor);
	cout << "\n\n\n                                                                                                                        " << endl;
	string str("CATCH_A_CRYPTO");
	int spaces = str.length();
	cout << "                                                                                                                        ";
	cout << "\r";
	for (int i = 0; i < 60 - (spaces / 2); i++)
	{
		cout << " ";

	}cout << "CATCH_A_CRYPTO" << endl; 
	cout << "                                                                                                                        ";
	text(text_scolor on hbcolor);
	std::cout << "\r\t\t\t\t\t\t     Admin Settings" << endl;

	
	text(text_tcolor);
	cout << "\n\t\t\t\t\t\t      ";
	text(text_tcolor);
	cout << "1.CREATE SEARCH LIST FROM API";
	text(text_tcolor);
	cout << "\n\t\t\t\t\t\t      ";
	text(text_tcolor);
	cout << "2.THEMES";
	text(text_tcolor);
	cout << "\n\t\t\t\t\t\t      ";
	text(text_tcolor);
	cout << "3.DECIMAL POINTS";
	text(text_tcolor);
	cout << "\n\t\t\t\t\t\t      ";
	text(text_tcolor);
	cout << "4.Change USER NAME/PASSWORD";
	text(text_tcolor);
	cout << "\n\t\t\t\t\t\t      ";
	text(text_tcolor);
	cout << "5.Alarm Tone";
	text(text_tcolor);
	cout << "\n\t\t\t\t\t\t      ";
	text(text_tcolor);
	cout << "6.Show coin record list";
	menu_opt = _getch();
	switch (menu_opt)
	{

	case '1':
		start();
		break;
	case'2':
		themes();
		break;
	case'3':
		decimal_points();
		break;
	case'4':
		login();
		userdata();
		break;
	case'5':
		set_alarm();
		break;
	case'6':
		show_coin();
		break;

	default:
		admin_settings();
		cout << "";
	}
}
void create_refresh() 
{
	cout << "current price: " << "B" << t_coin.price_btc << endl;
	cout << "current price: " << "$" << t_coin.price_usd << endl;
	cout << "trade price: " << "B" << t_coin.price_btc << endl;

	quantity=0;
	total_value_btc = quantity*trade_price_btc;
	cout << fixed << "\nquantity B:" << quantity << endl << "\ntrade price B:" << fixed << trade_price_btc << endl << "\nTotal value: B" << total_value_btc << endl;
	total_value_usd = quantity*trade_price_usd;
	cout << fixed << "\nquantity B:" << quantity << endl << "\ntrade price B:" << fixed << trade_price_usd << endl << "\nTotal value: B" << total_value_usd << endl;

	//we are buying coin
	buy_sell = "refresh";
	//system("pause");
}
void refresh() 
{
	for (int i = 1; i < 100; i++)
	{
		if (coin[i].listid != 0) 
		{

			name = coin[i].id;
			menu_opt = 'R';
			start();
			clean_bill();
			create_refresh();
			in_bill();
			save_bill();
			clear_desh();
			save_dash();
			out_bill();
			out_coin();
			out_dash();
		}if (coin[i].name == "\0")
		{
			menu_opt = 'o';
			break;
		}
	}
}

//main and menu
void menu() 
{
	do
	{
		system("cls");
		cout << fixed << setprecision(decimal_point);
		text(text_tcolor on hbcolor);
		system("color 07");
		//text(app_color_text on app_color_page);
		text(text_tcolor on hbcolor);
		cout << "\n\n\n                                                                                                                        " << endl;
		string str("CATCH_A_CRYPTO");
		int spaces = str.length();
		cout << "                                                                                                                        ";
		cout << "\r";
		for (int i = 0; i < 60 - (spaces / 2); i++)
		{
			cout << " ";

		}cout << "CATCH_A_CRYPTO" << endl;
		cout << "                                                                                                                        ";
		text(text_scolor on hbcolor);
		std::cout << "\r\t\t\t\t\t\t First C++ Crypto Wallet" << endl;


		text(text_tcolor);
		cout << "\n\t\t\t\t\t\t      ";
		text(text_tcolor);
		cout << "1.Dashboard";
		text(text_tcolor);
		cout << "\n\t\t\t\t\t\t      ";
		text(text_tcolor);
		cout << "2.Favourite Coins";
		text(text_tcolor);
		cout << "\n\t\t\t\t\t\t      ";
		text(text_tcolor);
		cout << "3.My Coins";
		text(text_tcolor);
		cout << "\n\t\t\t\t\t\t      ";
		text(text_tcolor);
		cout << "4.Add/Buy/Sell Coins";
		text(text_tcolor);
		cout << "\n\t\t\t\t\t\t      ";
		text(text_tcolor);
		cout << "5.Search Coin";
		text(text_tcolor);
		cout << "\n\t\t\t\t\t\t      ";
		text(text_tcolor);
		cout << "6.Admin Settings";
		menu_opt = _getch();
		switch (menu_opt)
		{

		case '1':
			clear_desh();
			in_dash();
			dashboard();
			out_dash();

			break;

		case'2':

			//fav_coin();
			show_fav();
			break;

		case'3':

			//my_coins();
			show_coin();
			break;

		case'4':

			start();
			if (coin_found == true)
			{
				add_coin();
			}
			break;

		case'5':

			start();
			break;

		case'6':

			admin_settings();
			break;

		default:
			cout << "invalid option.";
		}

	} while (true);

}
int main()
{
	
	read_setup();
	if (productkey != "xxxx-yyyy-xxxx-yyyy")
	{
		setup_agrement();
	}
	else
	{
		login();
	}
	clear_search();
	clean_coin();
	clean_bill();
	clear_desh();
	in_search();
	in_coin();
	save_dash();
	
	//menu:
	menu();

	return 0;
}


//setup
void setup_loading()
{
	system("CLS");
	cout << "               ***********" << endl; Sleep(45);
	cout << "                            ***" << endl; Sleep(45);
	cout << "                                **" << endl; Sleep(45);
	cout << "                                  **" << endl; Sleep(45);
	cout << "                                    *" << endl; Sleep(45);
	cout << "                                     **" << endl; Sleep(45);
	cout << "                                      **" << endl; Sleep(45);
	cout << "                                       *" << endl; Sleep(45);
	cout << "                                        *" << endl; Sleep(45);
	cout << "                                        *" << endl; Sleep(45);
	cout << "                   SETUP                *" << endl; Sleep(45);
	cout << "                                        *" << endl; Sleep(45);
	cout << "                                        *" << endl; Sleep(45);
	cout << "                                       *" << endl; Sleep(45);
	cout << "                                      **" << endl; Sleep(45);
	cout << "                                     **" << endl; Sleep(45);
	cout << "                                    *" << endl; Sleep(45);
	cout << "                                  **" << endl; Sleep(45);
	cout << "                                **" << endl; Sleep(45);
	cout << "                            ***" << endl; Sleep(45);
	cout << "               ***********"; Sleep(45);
	for (int i = 0; i<45; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << "          ***";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << "       **";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << "     **";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << "    *";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << "  **";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << " **";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << " *";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << "*";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << "*";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << "*";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << "*";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << "*";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << " *";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << " **";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << "  **";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << "    *";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << "     **";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << "       **";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{


		cout << "\b\b\b";
	}cout << "\r";
	cout << "          ***";
	Sleep(45);
	for (int i = 0; i<20; i++)
	{

		cout << "\b\b\b";
	}cout << "\r";
	cout << "               ***********\r";

	/*
	***********
	***               ***
	**                       **
	**                           **
	*                               *
	**                                 **
	**                                   **
	*                                     *
	*                                       *
	*                                       *
	*                                       *
	*                                       *
	*                                       *
	*                                     *
	**                                   **
	**                                 **
	*                               *
	**                           **
	**                       **
	***               ***
	***********
	*/

}
void save_setup()
{

	system("CLS");
	double percentvalue = 0;
	unsigned char tr = 191, tl = 218, dr = 217, dl = 192, v = 179, h = 196, t = 251, a = 219, b = 178, c = 177, d = 176;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "  ";
	text(7 on 0);
	cout << tl;
	for (int i = 0; i < 110; i++)
	{
		cout << h;
	}
	cout << tr << endl;
	cout << "  ";
	cout << v;
	text(8 on 8);
	for (int i = 0; i < 110; i++)
	{
		cout << " ";
	}
	text(7 on 0);
	cout << v;
	cout << "0%" << endl;
	cout << "  ";
	cout << dl;
	for (int i = 0; i < 110; i++)
	{
		cout << h;
	}
	cout << dr << endl;
	for (int i = 0; i < 55; i++)
	{
		cout << " ";
	}
	cout << "INSTALLING";
	cout << "\r\b\b\r\b\b\r";
	for (int i = 0; i <= 112; i++)
	{


		for (int j = 0; j <i; j++)
		{
			Sleep(1);
			int devider;
			devider = j / 4;
			for (int k = 0; k < devider; k++)
			{
				cout << d;
			}
			for (int k = 0; k < devider; k++)
			{
				cout << c;
			}
			for (int k = 0; k < devider; k++)
			{
				cout << b;
			}
			for (int k = 0; k < devider; k++)
			{
				cout << a;
			}
			cout << "\n\r\b\b\b\b\b\b\b";
			/*
			text(8 on 8);
			for (int k = 110; k >devider*4 ; k--)
			{
			cout << " ";
			}
			*/

			text(7 on 0);
			percentvalue = i - (i*.11);
			cout << v << percentvalue << "%";
			cout << "\r  " << v;

		}



	}


	ofstream outfile;
	outfile.open("setup.xls");

	int hbcolor = 8;
	int lbcolor = 8;
	int bbcolor = 79;
	int text_tcolor = 15;
	int text_scolor = 0;

	int decimal_point = 8;

	string alarm_tone_name = "Best_ringtones_remix_part_2_1_.wav";

	outfile << productkey << "\t" << coldstore << "\t" << username << "\t" << userpassword
		<< "\t" << hbcolor
		<< "\t" << lbcolor
		<< "\t" << bbcolor
		<< "\t" << text_tcolor
		<< "\t" << text_scolor
		<< "\t" << decimal_point
		<< "\t" << alarm_tone_name << endl;

	outfile.close();


}
void userdata()
{
	system("CLS");
	text(10);
	unsigned char tr = 187, tl = 201, dr = 188, dl = 200, v = 186, h = 205, t = 251;
	setup_loading();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	do
	{
		cout << "                                         ";
		char user[80];//to store 
		user[0] = NULL;//to store username
		cout << "  ENTER PATH TO AppData";
		cout << "                                         ";
		cout << "\n  (eg: C:\\\\Users\\\\qasim\\\\AppData)";
		cout << "                                         ";
		cout << "\n  use double slash \\\\ instead of one \\";
		//to store password.
		int i = 0;
		char a;//a Temp char
		for (i = 0;;)//infinite loop
		{
			a = getch();//stores char typed in a

						//check if a is numeric or alphabet

			if (a != 8 && (a >= 'a'&&a <= 'z' || (a >= 'A'&&a <= 'Z' || a >= '0'&&a <= '9')) || (a == '-' || a == '_' || a == '.'))
			{
				if (a != 13)
				{
					user[i] = a;//stores a in pass
					++i;
					cout << a;
				}
			}
			if (a == '\b'&&i >= 1)//if user typed backspace
								  //i should be greater than 1.
			{
				cout << "\b \b";//rub the character behind the cursor.
				--i;
				if (i == 0)
				{
					user[0] = NULL;
				}
			}
			if (a == '\r'&&user[0] != '\0')//if enter is pressed
			{
				user[i] = '\0';//null means end of string.
				break;//break the loop
			}

		}

		coldstore = user;
		if (coldstore == user)
		{
			do
			{
				cout << "\n                                         ";
				user[30];//to store 
				user[0] = NULL;//to store username
				cout << "  ENTER USER NAME----------:";
				//to store password.
				int i = 0;
				char a;//a Temp char
				for (i = 0;;)//infinite loop
				{
					a = getch();//stores char typed in a

								//check if a is numeric or alphabet

					if (a != 8 && (a >= 'a'&&a <= 'z' || (a >= 'A'&&a <= 'Z' || a >= '0'&&a <= '9')) || (a == '-' || a == '_' || a == '.'))
					{
						if (a != 13)
						{
							user[i] = a;//stores a in pass
							++i;
							cout << a;
						}
					}
					if (a == '\b'&&i >= 1)//if user typed backspace
										  //i should be greater than 1.
					{
						cout << "\b \b";//rub the character behind the cursor.
						--i;
						if (i == 0)
						{
							user[0] = NULL;
						}
					}
					if (a == '\r'&&user[0] != '\0')//if enter is pressed
					{
						user[i] = '\0';//null means end of string.
						break;//break the loop
					}

				}

				username = user;
			} while (username != user);

			if (username == user)
			{
				do
				{
					cout << "\n                                         ";
					user[30];//to store 
					user[0] = NULL;//to store username
					cout << "  ENTER USER PASSWORD------:";
					//to store password.
					int i = 0;
					char a;//a Temp char
					for (i = 0;;)//infinite loop
					{
						a = getch();//stores char typed in a

									//check if a is numeric or alphabet

						if (a != 8 && (a >= 'a'&&a <= 'z' || (a >= 'A'&&a <= 'Z' || a >= '0'&&a <= '9')) || (a == '-' || a == '_' || a == '.'))
						{
							if (a != 13)
							{
								user[i] = a;//stores a in pass
								++i;
								cout << a;
							}
						}
						if (a == '\b'&&i >= 1)//if user typed backspace
											  //i should be greater than 1.
						{
							cout << "\b \b";//rub the character behind the cursor.
							--i;
							if (i == 0)
							{
								user[0] = NULL;
							}
						}
						if (a == '\r'&&user[0] != '\0')//if enter is pressed
						{
							user[i] = '\0';//null means end of string.
							break;//break the loop
						}

					}

					userpassword = user;
				} while (userpassword != user);

				if (userpassword == user)
				{
					do
					{
						cout << "\n                                           ";
						user[30];//to store 
						user[0] = NULL;//to store username
						cout << "CONFIRM USER PASSWORD----:";
						//to store password.
						int i = 0;
						char a;//a Temp char
						for (i = 0;;)//infinite loop
						{
							a = getch();//stores char typed in a

										//check if a is numeric or alphabet

							if (a != 8 && (a >= 'a'&&a <= 'z' || (a >= 'A'&&a <= 'Z' || a >= '0'&&a <= '9')) || (a == '-' || a == '_' || a == '.'))
							{
								if (a != 13)
								{
									user[i] = a;//stores a in pass
									++i;
									cout << a;
								}
							}
							if (a == '\b'&&i >= 1)//if user typed backspace
												  //i should be greater than 1.
							{
								cout << "\b \b";//rub the character behind the cursor.
								--i;
								if (i == 0)
								{
									user[0] = NULL;
								}
							}
							if (a == '\r'&&user[0] != '\0')//if enter is pressed
							{
								user[i] = '\0';//null means end of string.
								break;//break the loop
							}

						}
						userpassword == user;
						if (userpassword != user)
						{
							for (int i = 0; i < 115; i++)
							{
								cout << " \b\b";
							}cout << "\r";


						}
					} while (userpassword != user);
					if (user == userpassword)
					{
						//

						cout << "\n                                                                                         " << tl << h << h << h << h << h << h << tr << endl;
						cout << "                                                                                         " << v;
						text(0 on 10);
						cout << "INSTAL";
						text(10);
						cout << v << " PRESS ENTER TO INSTAL\n";
						cout << "                                                                                         " << dl << h << h << h << h << h << h << dr;
						char agree;
						do
						{
							agree = getch();
							if (menu_opt=='4'&&agree == 13)
							{
								save_setup_settings();
							}
							else if (agree == 13)
							{
								//setup of wget
								system("wget-1.11.4-1-setup.exe");
								save_setup();
								main();
							}else{}
						} while (true);

					}
				}
			}

		}


	} while (true);
}
void setup_customine()
{
	system("CLS");
	unsigned char tr = 187, tl = 201, dr = 188, dl = 200, v = 186, h = 205, t = 251;
	string pro_k;
	char agree;
	text(14);
	setup_loading();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	do
	{
		cout << "                                         ";
		cout << "ENTER PRODUCT KEY:";
		getline(cin, pro_k);
		if (pro_k == "xxxx-yyyy-xxxx-yyyy")
		{
			productkey = pro_k;
			cout << "                                         ";
			cout << "C:\\Users\\qasim\\Documents\\Visual Studio 2015\\Projects\\ConsoleApplication12" << endl;
			cout << "                                         ";
			cout << "LANGUAGE:ENGLISH ONLY\n";

			cout << "                                                                                         " << tl << h << h << h << h << tr << endl;
			cout << "                                                                                         " << v;
			text(0 on 14);
			cout << "NEXT";
			text(14);
			cout << v << " PRESS ENTER TO CONTINUE\n";
			cout << "                                                                                         " << dl << h << h << h << h << dr;
			do
			{
				agree = getch();
				if (agree == 13)
				{
					userdata();
				}
			} while (true);

		}
		else
		{

			for (int i = 0; i < 120; i++)
			{
				cout << " \b\b";
			}cout << "\r";

		}

	} while (true);

}
void setup_agrement()
{
	system("CLS");
	text(12);
	setup_loading();
	unsigned char tr = 187, tl = 201, dr = 188, dl = 200, v = 186, h = 205, t = 251;
	/*cout << tl << h << tr << endl;
	cout << v << t << v << endl;
	cout << dl << h << dr << endl;*/
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "                                         ";
	text(12);
	cout << tl << h << tr;
	text(12);
	cout << "AGREE TO CONTINUE!" << endl;
	cout << "                                         ";
	cout << v << " " << v;
	cout << "This software is developed by Qasim Raheem Khalid Mehmood." << endl;
	cout << "                                         ";
	cout << dl << h << dr;
	cout << "This is a program for general store.(http://www.stackjunction.io/)" << endl;
	cout << "                                            ";
	cout << "PRESS (A)KEY TO CONTINUE.";
	char agree = '\0';
	do
	{
		agree = getch();
		if (agree == 'a' || agree == 'A')
		{
			cout << "\r\b\b\b\b\r\r\b\b\b\b\r";
			cout << "                                         " << v << t;
			cout << "\n\n\n\n";
			cout << "                                                                                         " << tl << h << h << h << h << tr << endl;
			cout << "                                                                                         " << v;
			text(0 on 12);
			cout << "NEXT";
			text(12);
			cout << v << " PRESS ENTER TO CONTINUE\n";
			cout << "                                                                                         " << dl << h << h << h << h << dr;
			do
			{
				agree = getch();
				if (agree == 13)
				{
					setup_customine();
				}
			} while (true);

		}
	} while (true);



}
void read_setup()
{
	std::ifstream ifs("setup.xls");

	if (ifs.is_open())
	{
		string r_productkey, r_coldstore, r_username, r_password;
		while (!ifs.eof())
		{
			ifs >> r_productkey;
			ifs >> r_coldstore;
			ifs >> r_username;
			ifs >> r_password;
			ifs >> hbcolor;
			ifs >> lbcolor;
			ifs >> bbcolor;
			ifs >> text_tcolor;
			ifs >> text_scolor;
			ifs >> decimal_point;
			ifs >> alarm_tone_name;

			//	cout<<roll<<"\t"<<sfnam<<"\t"<<ssnam<<"\t"<<ffnam<<"\t"<<fsnam<<"\t"<<rclass<<"\t"<<num<<endl;
			if (r_productkey == "xxxx-yyyy-xxxx-yyyy")
			{
				productkey = r_productkey;
				coldstore = r_coldstore;
				username = r_username;
				userpassword = r_password;

			}
		}
		ifs.close();

	}
	else {
		// show message:
		std::cout << "Error opening file";
	}
}


//login();
void user_name()
{
	cout << "\n\t\t\t\t\t\tEnter Username  :";
	//to store password.
	int i = 0;
	char a;//a Temp char
	for (i = 0;;)//infinite loop
	{
		a = getch();//stores char typed in a

					//check if a is numeric or alphabet
		if (a != 8)
		{
			if (a != 13)
			{
				userc[i] = a;//stores a in pass
				++i;
				cout << a;
			}
		}
		if (a == '\b'&&i >= 1)//if user typed backspace
							  //i should be greater than 1.
		{
			cout << "\b \b";//rub the character behind the cursor.
			--i;
		}
		if (a == '\r')//if enter is pressed
		{
			userc[i] = '\0';//null means end of string.
			break;//break the loop
		}
	}


	//here we can even check for minimum digits needed

	/* if(i<=5)
	{
	cout<<"\nMinimum 6 digits needed.\nEnter Again";
	getch();//It was not pausing :p
	goto START;
	}*/


}
void pass_word()
{
	cout << "\n\t\t\t\t\t\tEnter password  :";
	//to store password.
	int i = 0;
	char a;//a Temp char
	for (i = 0;;)//infinite loop
	{
		a = getch();//stores char typed in a

					//check if a is numeric or alphabet
		if (a != 8)
		{
			if (a != 13)
			{
				passc[i] = a;//stores a in pass
				++i;
				cout << "*";
			}
		}
		if (a == '\b'&&i >= 1)//if user typed backspace
							  //i should be greater than 1.
		{
			cout << "\b \b";//rub the character behind the cursor.
			--i;
		}
		if (a == '\r')//if enter is pressed
		{
			passc[i] = '\0';//null means end of string.
			break;//break the loop
		}
	}


	//here we can even check for minimum digits needed

	/* if(i<=5)
	{
	cout<<"\nMinimum 6 digits needed.\nEnter Again";
	getch();//It was not pausing :p
	goto START;
	}*/


}
void login()
{
	system("cls");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	text(12 on 0);
	cout << "\t\t\t\t\t\t       LOGIN" << endl;
	cout << "\t\t\t\t\t\t     =========\n\n" << endl;
	do
	{
		user_name();
		pass_word();


		if (userc == username&&passc == userpassword)
		{
			for (int i = 0; i < 7; i++)
			{
				cout << "\n";
			}
			for (int i = 0; i < 54; i++)
			{
				cout << " ";
			}
			unsigned char tr = 191, tl = 218, dr = 217, dl = 192, v = 179, h = 196, t = 251, a = 219, b = 178, c = 177, d = 176, e = 0;
			cout << tl << h << h << h << h << h << h << h << tr << endl;
			for (int i = 0; i < 54; i++)
			{
				cout << " ";
			}
			cout << v << " " << d << " " << d << " " << d << " " << v << endl;
			for (int i = 0; i < 54; i++)
			{
				cout << " ";
			}
			cout << dl << h << h << h << h << h << h << h << dr;
			cout << "\r\b\b\r";
			for (int i = 0; i < 54; i++)
			{
				cout << " ";
			}
			cout << v;
			for (int i = 0; i < 3; i++)
			{
				Sleep(120);
				for (int j = 0; j < 5; j++)
				{
					Sleep(150);
					e = a; a = b; b = c; c = d, d = e;
					cout << " " << c << " " << b << " " << a;
					cout << "\b\b\b\b\b\b";
				}
			}

		}
		else
		{
			for (int i = 0; i < 7; i++)
			{
				cout << "\n";
			}
			for (int i = 0; i < 54; i++)
			{
				cout << " ";
			}
			unsigned char tr = 191, tl = 218, dr = 217, dl = 192, v = 179, h = 196, t = 251, a = 219, b = 178, c = 177, d = 176, e = 0;
			cout << tl << h << h << h << h << h << h << h << tr << endl;
			for (int i = 0; i < 54; i++)
			{
				cout << " ";
			}
			cout << v << " " << d << " " << d << " " << d << " " << v << endl;
			for (int i = 0; i < 54; i++)
			{
				cout << " ";
			}
			cout << dl << h << h << h << h << h << h << h << dr;
			cout << "\r\b\b\r";
			for (int i = 0; i < 54; i++)
			{
				cout << " ";
			}
			cout << v;
			for (int i = 0; i < 3; i++)
			{
				Sleep(120);
				for (int j = 0; j < 5; j++)
				{
					Sleep(150);
					e = a; a = b; b = c; c = d, d = e;
					cout << " " << c << " " << b << " " << a;
					cout << "\b\b\b\b\b\b";
				}
			}
			login();
		}
		//	}
	} while (userc != username&&passc != userpassword);

}
