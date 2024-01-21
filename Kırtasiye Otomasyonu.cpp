#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <fstream> 
#include <string.h>
#include <conio.h>
#include <iomanip>


/*KIRTASÝYE OTOMASYONU*/
//FAZLI FATÝH BULUT
//2312729007

using namespace std;



struct kirtasiye
{
	float fiyat;
	int stok;
	
};
struct kalem
{
  kirtasiye urunbilgileri;
  string kalemrengi;
  string kalemturu;
  
};
struct defter
{
	kirtasiye urunbilgileri;
	string defterboyut;
	string defterrengi;
	string defterturu;
};
struct silgi
{
 string silgiBoyutu;
 kirtasiye urunbilgileri;
};
struct kagit
{
	kirtasiye urunbilgileri;
	string boyut;
};
struct cikti
{
string renktur;
int sayfasayisi;
kirtasiye urunbilgileri;	
};
void silgiEkle()
{
	char terciih;
	do
	{
	terciih==' ';
	ofstream silgiBilgileri("silgi.txt", ios::app);
	silgi silgidetaylari;
	cout<<"Silgi Boyutunu Girin (Küçük-Orta-Büyük) :";
	cin>>silgidetaylari.silgiBoyutu;
	cout<<"Silgi Stoðunu Girin :";
	cin>>silgidetaylari.urunbilgileri.stok;
	cout<<"Silgi FÝyatýný Girin :";
	cin>>silgidetaylari.urunbilgileri.fiyat;
	silgiBilgileri<<endl<<silgidetaylari.silgiBoyutu<<setw(10)<<silgidetaylari.urunbilgileri.stok<<setw(10)<<silgidetaylari.urunbilgileri.fiyat;
	
	silgiBilgileri.close();
	cout<<"Tekrar Silgi Eklemek Ýster misiniz? (e/h) :";
	cin>>terciih;
}while(terciih=='e');
}
void kalemEkle()
{
	char soruu;
	do
	{
	
	soruu==' ';
	ofstream kalemBilgileri("kalem.txt", ios::app);
	kalem kalemBilgiler;
	cout<<"Kalem Türünü Girin :";
	cin>>kalemBilgiler.kalemturu;
	cout<<"Kalem Rengini Girin :";
	cin>>kalemBilgiler.kalemrengi;
	cout<<"Kalem Stoðunu Girin :";
	cin>>kalemBilgiler.urunbilgileri.stok;
	cout<<"Kalem Fiyatýný Girin : ";
	cin>>kalemBilgiler.urunbilgileri.fiyat;
	kalemBilgileri<<endl<<kalemBilgiler.kalemturu<<setw(10)<<kalemBilgiler.kalemrengi<<setw(10)<<kalemBilgiler.urunbilgileri.stok<<setw(10)<<kalemBilgiler.urunbilgileri.fiyat;
	kalemBilgileri.close();
    cout<<"Tekrar Kalem Eklemek Ýster misiniz ?(e/h) :";
    cin>>soruu;
   }while(soruu=='e');
   
}
void defterEkle()
{
	char tercih;
	do
	{
	tercih==' ';
	ofstream defterBilgiler("defter.txt", ios::app);
	defter defterBilgileri;
	cout<<"Defter Türünü Girin :";
	cin>>defterBilgileri.defterturu;
	cout<<"Defter Boyutunu Girin :";
	cin>>defterBilgileri.defterboyut;
	cout<<"Defter Rengini Girin :";
	cin>>defterBilgileri.defterrengi;
	cout<<"Defter Stoðunu Girin :";
	cin>>defterBilgileri.urunbilgileri.stok;
	cout<<"Defter Fiyatý :";
	cin>>defterBilgileri.urunbilgileri.fiyat;
	defterBilgiler<<endl<<defterBilgileri.defterturu<<setw(10)<<defterBilgileri.defterboyut<<setw(10)<<defterBilgileri.defterrengi<<setw(10)<<defterBilgileri.urunbilgileri.stok<<setw(10)<<defterBilgileri.urunbilgileri.fiyat;
	defterBilgiler.close();
	cout<<"Yeniden Defter Eklemek Ýster misiniz ? (e/h) :";
	cin>>tercih;
	}while(tercih=='e');
}
void ciktial()
{
	char secim;
	do
	{
	secim==' ';
	ofstream yazdir("Çýktý.txt", ios::app);
	
	cikti ciktiyazdir;
	cout<<"Sayfa Sayýsý Giriniz :";
	cin>>ciktiyazdir.sayfasayisi;
	

	cout<<"Çýktý Türünü Girin (Renkli-Renksiz):";
	cin>>ciktiyazdir.renktur;
	if(ciktiyazdir.renktur=="Renkli" || ciktiyazdir.renktur=="renkli")
	{
	ciktiyazdir.urunbilgileri.fiyat=ciktiyazdir.sayfasayisi*3;	
    cout<<"Toplam Fiyat ="<<ciktiyazdir.urunbilgileri.fiyat<<endl;

	}
	 else if(ciktiyazdir.renktur=="Renksiz" || ciktiyazdir.renktur=="renksiz")
	 {
	 	
	ciktiyazdir.urunbilgileri.fiyat=ciktiyazdir.sayfasayisi*1;	
	cout<<"Toplam Fiyat ="<<ciktiyazdir.urunbilgileri.fiyat<<endl;

	}
	 	
	 
	 else
	 {
	 	cout<<"Yanlýþ Girdiniz "<<endl;
		ciktiyazdir.urunbilgileri.fiyat=ciktiyazdir.sayfasayisi*3;	
	 }
	 cout<<"Tekrar Çýktý Almak Ýster misiniz? (e/h)";
	 cin>>secim;
}while(secim=='e');

}
void satis()
{

	int toplam=0;
	char fatih;
	string secim;
	do
	{
	cout<<"Ne Satmak istersiniz ? (kalem-silgi-defter-çýktý) "<<endl;
	cin>>secim;
	if(secim=="kalem" || secim=="Kalem")
	{
	
	kalem kalemSatis;
	ifstream okuma("kalem.txt");
	ofstream yedek("yedek.txt", ios::app);
	cout << "Kalem Listesi" << endl;
	while(!(okuma.eof()))
	{
		okuma >> kalemSatis.kalemturu >> kalemSatis.kalemrengi >> kalemSatis.urunbilgileri.stok>> kalemSatis.urunbilgileri.fiyat ;

		cout <<  kalemSatis.kalemturu << endl;
	}
	
	string isim;
	cout << "hangi Kalemi satmak istiyorsunuz" << endl;
	cin >> isim;
	
	int sayi;
	cout << "Kaç tane satmak istiyorsunuz" << endl;
	cin >> sayi;
		
	ifstream okuma2("kalem.txt");
	while(!(okuma2.eof()))
	{
		okuma2 >> kalemSatis.kalemturu >> kalemSatis.kalemrengi >> kalemSatis.urunbilgileri.stok>> kalemSatis.urunbilgileri.fiyat ;
		if(isim==kalemSatis.kalemturu)
		{
		toplam=sayi*kalemSatis.urunbilgileri.fiyat;
		kalemSatis.urunbilgileri.stok-=sayi;
		yedek <<endl<<kalemSatis.kalemturu<<setw(10)<<kalemSatis.kalemrengi<<setw(10)<<kalemSatis.urunbilgileri.stok<<setw(10)<<kalemSatis.urunbilgileri.fiyat;
		}
		else
		{
		yedek <<endl<<kalemSatis.kalemturu<<setw(10)<<kalemSatis.kalemrengi<<setw(10)<<kalemSatis.urunbilgileri.stok<<setw(10)<<kalemSatis.urunbilgileri.fiyat;
		}
	}
	yedek.close();
	okuma2.close();
	okuma.close();
	remove("kalem.txt");
	rename("yedek.txt", "kalem.txt");	
	}
	
	else if(secim=="defter"||secim=="Defter")
	{
	defter deftersatis;
	ifstream okuma("defter.txt");

	ofstream yedek("yedek.txt", ios::app);
	cout<<"Defter Listesi "<<endl;
	while(!(okuma.eof()))
	{
		okuma >> deftersatis.defterturu >>deftersatis.defterboyut >>deftersatis.defterrengi>>deftersatis.urunbilgileri.stok>>deftersatis.urunbilgileri.fiyat;
		cout<<deftersatis.defterturu<<endl;
	}
	string isim;
	cout << "Hangi Defteri Satmak istiyorsunuz :";
	cin >> isim;
	int sayi;
	cout << "Kaç tane satmak istiyorsunuz :";
	cin >> sayi;
	ifstream okuma2("defter.txt");
	while(!okuma2.eof())
	{
		okuma2 >> deftersatis.defterturu >>deftersatis.defterboyut >>deftersatis.defterrengi>>deftersatis.urunbilgileri.stok>>deftersatis.urunbilgileri.fiyat;
		if(isim==deftersatis.defterturu)
		{
		toplam=sayi*deftersatis.urunbilgileri.fiyat;
		deftersatis.urunbilgileri.stok-=sayi;
	    yedek<<endl<<deftersatis.defterturu<<setw(10)<<deftersatis.defterboyut<<setw(10)<<deftersatis.defterrengi<<setw(10)<<deftersatis.urunbilgileri.stok<<setw(10)<<deftersatis.urunbilgileri.fiyat;
		}
		else
		{
		yedek<<endl<<deftersatis.defterturu<<setw(10)<<deftersatis.defterboyut<<setw(10)<<deftersatis.defterrengi<<setw(10)<<deftersatis.urunbilgileri.stok<<setw(10)<<deftersatis.urunbilgileri.fiyat;
		}	
		
	}
	okuma.close();
		yedek.close();
		okuma2.close();
		remove("defter.txt");
		rename("yedek.txt", "defter.txt");
	}


else if(secim=="silgi"|| secim=="Silgi")
{

	silgi silgiSatis;
	ifstream okuma("silgi.txt");
	ofstream yedek("yedek.txt", ios::app);
	cout << "Silgi Listesi" << endl;
	while(!(okuma.eof()))
	{
		okuma >> silgiSatis.silgiBoyutu >>  silgiSatis.urunbilgileri.stok>> silgiSatis.urunbilgileri.fiyat ;

		cout <<  silgiSatis.silgiBoyutu << endl;
	}
	
	string isim;
	cout << "Hangi silgi boyutunu satmak istiyorsunuz" << endl;
	cin >> isim;
	
	int sayi;
	cout << "Kaç tane satmak istiyorsunuz" << endl;
	cin >> sayi;
		ifstream okuma2("silgi.txt");

	while(!(okuma2.eof()))
	{
		okuma2 >> silgiSatis.silgiBoyutu >> silgiSatis.urunbilgileri.stok>> silgiSatis.urunbilgileri.fiyat ;
		if(isim==silgiSatis.silgiBoyutu)
		{
			toplam=sayi*silgiSatis.urunbilgileri.fiyat;
		silgiSatis.urunbilgileri.stok-=sayi;
		yedek <<endl<<silgiSatis.silgiBoyutu<<setw(10)<<silgiSatis.urunbilgileri.stok<<setw(10)<<silgiSatis.urunbilgileri.fiyat;
		}
		else
		{
		yedek <<endl<<silgiSatis.silgiBoyutu<<setw(10)<<silgiSatis.urunbilgileri.stok<<setw(10)<<silgiSatis.urunbilgileri.fiyat;
		}
	}
	okuma.close();
	yedek.close();
	okuma2.close();
	remove("silgi.txt");
	rename("yedek.txt", "silgi.txt");	

	
	}
	else if(secim=="Çýktý"||secim=="çýktý"||secim=="cikti"||secim=="Cikti")
	{

	
	ofstream yazdir("Çýktý.txt", ios::app);
	
	cikti ciktiyazdir;
	cout<<"Sayfa Sayýsý Giriniz :";
	cin>>ciktiyazdir.sayfasayisi;
	

	cout<<"Çýktý Türünü Girin (Renkli-Renksiz):";
	cin>>ciktiyazdir.renktur;
	if(ciktiyazdir.renktur=="Renkli" || ciktiyazdir.renktur=="renkli")
	{
		
	ciktiyazdir.urunbilgileri.fiyat=ciktiyazdir.sayfasayisi*3;	
    cout<<"Toplam Fiyat ="<<ciktiyazdir.urunbilgileri.fiyat<<endl;

	}
	 else if(ciktiyazdir.renktur=="Renksiz" || ciktiyazdir.renktur=="renksiz")
	 {
	 	
	ciktiyazdir.urunbilgileri.fiyat=ciktiyazdir.sayfasayisi*1;	
	cout<<"Toplam Fiyat ="<<ciktiyazdir.urunbilgileri.fiyat<<endl;

	}
	 	
	 
	 else
	 {
	 	cout<<"Yanlýþ Girdiniz "<<endl;
		ciktiyazdir.urunbilgileri.fiyat=ciktiyazdir.sayfasayisi*3;	
	 }
    toplam+=ciktiyazdir.urunbilgileri.fiyat;
	}

		
		cout<<"Baþka bir þey almak ister misiniz? (e/h)  ";
		cin>>fatih;
		 
	}while(fatih=='e');
	
	cout<<"Toplam Fiyat: "<<toplam<<endl;
}
void defterSatis()
{


	defter deftersatis;
	ofstream yedek("yedek.txt", ios::app);
	ifstream okuma("defter.txt");
	cout<<"Defter Listesi "<<endl;
	while(!(okuma.eof()))
	{
		okuma >> deftersatis.defterturu >>deftersatis.defterboyut >>deftersatis.defterrengi>>deftersatis.urunbilgileri.stok>>deftersatis.urunbilgileri.fiyat;
		cout<< deftersatis.defterturu <<endl;
	}
		string isim;
	cout << "Hangi Defteri Düzenleme istiyorsunuz :";
	cin >> isim;
	
	int sayi;
	cout << "Kaç tane düzenlemek istiyorsunuz :";
	cin >> sayi;
	ifstream okuma2("defter.txt");
	while(!okuma2.eof())
	{
		okuma2 >> deftersatis.defterturu >>deftersatis.defterboyut >>deftersatis.defterrengi>>deftersatis.urunbilgileri.stok>>deftersatis.urunbilgileri.fiyat;
		if(isim==deftersatis.defterturu)
		{
				deftersatis.urunbilgileri.stok-=sayi;
	    yedek<<deftersatis.defterturu<<setw(10)<<deftersatis.defterboyut<<setw(10)<<deftersatis.defterrengi<<setw(10)<<deftersatis.urunbilgileri.stok<<setw(10)<<deftersatis.urunbilgileri.fiyat<<endl;
		}
		else
		{
		yedek<<deftersatis.defterturu<<setw(10)<<deftersatis.defterboyut<<setw(10)<<deftersatis.defterrengi<<setw(10)<<deftersatis.urunbilgileri.stok<<setw(10)<<deftersatis.urunbilgileri.fiyat<<endl;

		}	

	}
	okuma.close();
	yedek.close();
	okuma2.close();
	remove("defter.txt");
	rename("yedek.txt", "defter.txt");
}
void kalemGuncelleme()
{ 

	kalem kalemGuncelleme;
	ifstream okuma("kalem.txt");

	ofstream yedek("yedek.txt", ios::app);
	cout << "Kalem Listesi" << endl;
	while(!(okuma.eof()))
	{
		okuma >> kalemGuncelleme.kalemturu >> kalemGuncelleme.kalemrengi >> kalemGuncelleme.urunbilgileri.stok>> kalemGuncelleme.urunbilgileri.fiyat ;

		cout <<  kalemGuncelleme.kalemturu << endl;
	}
	
	string isim;
	cout << "Hangi Kalemi düzenlemek istiyorsunuz ?" << endl;
	cin >> isim;
	
	ifstream okuma2("kalem.txt");
	while(!(okuma2.eof()))
	{
		okuma2 >> kalemGuncelleme.kalemturu >> kalemGuncelleme.kalemrengi >> kalemGuncelleme.urunbilgileri.stok>> kalemGuncelleme.urunbilgileri.fiyat ;
		if(isim==kalemGuncelleme.kalemturu)
		{
			cout<<"Kalem Türünü Girin :";
			cin>>kalemGuncelleme.kalemturu;
			cout<<"Kalem Rengini Girin :";
			cin>>kalemGuncelleme.kalemrengi;
			cout<<"Kalem Stoðunu Girin :";
			cin>>kalemGuncelleme.urunbilgileri.stok;
			cout<<"Kalem Fiyatýný Girin : ";
			cin>>kalemGuncelleme.urunbilgileri.fiyat;	
			yedek <<endl<<kalemGuncelleme.kalemturu<<setw(10)<<kalemGuncelleme.kalemrengi<<setw(10)<<kalemGuncelleme.urunbilgileri.stok<<setw(10)<<kalemGuncelleme.urunbilgileri.fiyat;
		}
		else
		{
		yedek <<endl<<kalemGuncelleme.kalemturu<<setw(10)<<kalemGuncelleme.kalemrengi<<setw(10)<<kalemGuncelleme.urunbilgileri.stok<<setw(10)<<kalemGuncelleme.urunbilgileri.fiyat;
		}
	}
	yedek.close();
	okuma2.close();
	okuma.close();
	remove("kalem.txt");
	rename("yedek.txt", "kalem.txt");
	
	
	
}
void defterGuncelleme()
{
	defter defterGuncelleme;
	ifstream okuma("defter.txt");

	ofstream yedek("yedek.txt", ios::app);
	cout<<"Defter Listesi "<<endl;
	while(!(okuma.eof()))
	{
		okuma >> defterGuncelleme.defterturu >>defterGuncelleme.defterboyut >>defterGuncelleme.defterrengi>>defterGuncelleme.urunbilgileri.stok>>defterGuncelleme.urunbilgileri.fiyat;
		cout<<defterGuncelleme.defterturu<<endl;
	}
	string isim;
	cout << "Hangi Defteri Güncellemek istiyorsunuz :";
	cin >> isim;
	
	ifstream okuma2("defter.txt");
	while(!okuma2.eof())
	{
		okuma >> defterGuncelleme.defterturu >>defterGuncelleme.defterboyut >>defterGuncelleme.defterrengi>>defterGuncelleme.urunbilgileri.stok>>defterGuncelleme.urunbilgileri.fiyat;
		if(isim==defterGuncelleme.defterturu)
		{
			cout<<"Defter Türünü Girin :";
			cin>>defterGuncelleme.defterturu;
				cout<<"Defter Boyutunu Girin :";
			cin>>defterGuncelleme.defterboyut;
			cout<<"Defter Rengini Girin :";
			cin>>defterGuncelleme.defterrengi;
			cout<<"Defter Stoðunu Girin :";
			cin>>defterGuncelleme.urunbilgileri.stok;
			cout<<"Defter Fiyatý :";
			cin>>defterGuncelleme.urunbilgileri.fiyat;	   
			 yedek<<defterGuncelleme.defterturu<<setw(10)<<defterGuncelleme.defterboyut<<setw(10)<<defterGuncelleme.defterrengi<<setw(10)<<defterGuncelleme.urunbilgileri.stok<<setw(10)<<defterGuncelleme.urunbilgileri.fiyat<<endl;
		}
		else
		{
		yedek<<defterGuncelleme.defterturu<<setw(10)<<defterGuncelleme.defterboyut<<setw(10)<<defterGuncelleme.defterrengi<<setw(10)<<defterGuncelleme.urunbilgileri.stok<<setw(10)<<defterGuncelleme.urunbilgileri.fiyat<<endl;
		}	
		}
	yedek.close();
	okuma2.close();
	okuma.close();
	remove("defter.txt");
	rename("yedek.txt", "defter.txt");
	
	

	
}
void silgiGuncelleme()
{
	silgi silgiGuncelleme;
	ifstream okuma("silgi.txt");
	ofstream yedek("yedek.txt", ios::app);
	cout << "Silgi Listesi" << endl;
	while(!(okuma.eof()))
	{
		okuma >> silgiGuncelleme.silgiBoyutu >>  silgiGuncelleme.urunbilgileri.stok>> silgiGuncelleme.urunbilgileri.fiyat ;

		cout <<  silgiGuncelleme.silgiBoyutu << endl;
	}
	
	string isim;
	cout << "Hangi silgiyi düzenlemek istiyorsunuz" << endl;
	cin >> isim;
	
	
	ifstream okuma2("silgi.txt");
	while(!(okuma2.eof()))
	{
		okuma2 >> silgiGuncelleme.silgiBoyutu >> silgiGuncelleme.urunbilgileri.stok>> silgiGuncelleme.urunbilgileri.fiyat ;
		if(isim==silgiGuncelleme.silgiBoyutu)
		{
		cout<<"Silgi Boyutunu Girin (Küçük-Orta-Büyük) :";
		cin>>silgiGuncelleme.silgiBoyutu;
		cout<<"Silgi Stoðunu Girin :";
		cin>>silgiGuncelleme.urunbilgileri.stok;
		cout<<"Silgi FÝyatýný Girin :";
		cin>>silgiGuncelleme.urunbilgileri.fiyat;
		yedek <<endl<<silgiGuncelleme.silgiBoyutu<<setw(10)<<silgiGuncelleme.urunbilgileri.stok<<setw(10)<<silgiGuncelleme.urunbilgileri.fiyat;
		}
		else
		{
		yedek <<endl<<silgiGuncelleme.silgiBoyutu<<setw(10)<<silgiGuncelleme.urunbilgileri.stok<<setw(10)<<silgiGuncelleme.urunbilgileri.fiyat;
		}
	}
	okuma.close();
	yedek.close();
	okuma2.close();
	remove("silgi.txt");
	rename("yedek.txt", "silgi.txt");

	
		
}
void silgiSatiss()
{
	silgi silgiSatis;
	ofstream yedek("yedek.txt", ios::app);
	ifstream okuma("silgi.txt");
	cout << "Silgi Listesi" << endl;
	while(!(okuma.eof()))
	{
		okuma >> silgiSatis.silgiBoyutu >>  silgiSatis.urunbilgileri.stok>> silgiSatis.urunbilgileri.fiyat ;

		cout <<  silgiSatis.silgiBoyutu << endl;
	}
	
	string isim;
	cout << "Hangi silgi boyutunu satmak istiyorsunuz" << endl;
	cin >> isim;
	
	int sayi;
	cout << "Kaç tane satmak istiyorsunuz" << endl;
	cin >> sayi;
		ifstream okuma2("silgi.txt");

	while(!(okuma2.eof()))
	{
		okuma2 >> silgiSatis.silgiBoyutu >> silgiSatis.urunbilgileri.stok>> silgiSatis.urunbilgileri.fiyat ;
		if(isim==silgiSatis.silgiBoyutu)
		{
		silgiSatis.urunbilgileri.stok-=sayi;
		yedek <<endl<<silgiSatis.silgiBoyutu<<setw(10)<<silgiSatis.urunbilgileri.stok<<setw(10)<<silgiSatis.urunbilgileri.fiyat;
		}
		else
		{
		yedek <<endl<<silgiSatis.silgiBoyutu<<setw(10)<<silgiSatis.urunbilgileri.stok<<setw(10)<<silgiSatis.urunbilgileri.fiyat;
		}
	}
	okuma.close();
	yedek.close();
	okuma2.close();
	remove("silgi.txt");
	rename("yedek.txt", "silgi.txt");	
}
void kalemListele()
{
	kalem kalemBilgileri;
	ifstream okuma("kalem.txt");
	
	cout<<"*******KALEM*******"<<endl;
	cout<<endl;

	cout<<"Tür   Renk   Stok   Fiyat"<<endl;
	cout<<" ---   ----   ----   -----"<<endl;
	while(!(okuma.eof()))
	{
		okuma >>kalemBilgileri.kalemturu>>kalemBilgileri.kalemrengi>>kalemBilgileri.urunbilgileri.stok>>kalemBilgileri.urunbilgileri.fiyat;
		cout<<kalemBilgileri.kalemturu<<" "<<kalemBilgileri.kalemrengi<<" "<<kalemBilgileri.urunbilgileri.stok<<" "<<kalemBilgileri.urunbilgileri.fiyat<<endl;
	
	}

		cout<<endl;
	cout<<endl;
	
	
	
	
}
void defterListele()
{
	defter defterBilgileri;
	ifstream okuma("defter.txt");

	
	cout<<"*******DEFTER*******"<<endl;
	cout<<endl;
	cout<<"Tür    Boyut   Renk   Stok   Fiyat"<<endl;
	cout<<"---    -----   ----   ----   -----"<<endl;
	while(!(okuma.eof()))
	{
		okuma >>defterBilgileri.defterturu>>defterBilgileri.defterboyut>>defterBilgileri.defterrengi>>defterBilgileri.urunbilgileri.stok>>defterBilgileri.urunbilgileri.fiyat;
        cout<<defterBilgileri.defterturu<<" "<<defterBilgileri.defterboyut<<" "<<defterBilgileri.defterrengi<<" "<<defterBilgileri.urunbilgileri.stok<<" "<<defterBilgileri.urunbilgileri.fiyat<<endl;		
	

	}
cout<<endl;
	cout<<endl;
}
void silgiListele()
{
	silgi silgiBilgileri;
	ifstream okuma("silgi.txt");

	cout<<"*******SÝLGÝ*******"<<endl;
	cout<<endl;

	cout<<"Boyut   Stok   Fiyat"<<endl;
	cout<<"-----   ----   -----"<<endl;
	while(!(okuma.eof()))
	{
		okuma>>silgiBilgileri.silgiBoyutu>>silgiBilgileri.urunbilgileri.stok>>silgiBilgileri.urunbilgileri.fiyat;
		cout<<silgiBilgileri.silgiBoyutu<<" "<<silgiBilgileri.urunbilgileri.stok<<" "<<silgiBilgileri.urunbilgileri.fiyat<<endl;
	 
	}


	   	cout<<endl;
	cout<<endl;
}
void kalemAra()
{
	kalem kalemBilgileri;
	string isim;
	
	char secim;
	
	int sayac=0;
	do
	{
		sayac=0;
	ifstream okuma("kalem.txt");
		cout<<"Aranacak Kalem Türünü Giriniz :";
	    cin>>isim;
	while(!(okuma.eof()))
	{
	
		okuma >>kalemBilgileri.kalemturu>>kalemBilgileri.kalemrengi>>kalemBilgileri.urunbilgileri.stok>>kalemBilgileri.urunbilgileri.fiyat;
		
		if(isim==kalemBilgileri.kalemturu)
		{		

		cout<<kalemBilgileri.kalemturu<<" "<<kalemBilgileri.kalemrengi<<" "<<kalemBilgileri.urunbilgileri.stok<<" "<<kalemBilgileri.urunbilgileri.fiyat<<endl;
      sayac++;
		}
		
	
		
	}
	if(sayac==0)
	{
		cout<<"Aradýðýnýz Türde Kalem Bulunamadý! "<<endl;
		cout<<"Tekrar Kalem Aramak Ýster misiniz? (e/h)"<<endl;
		cin>>secim;
		
	}
	else
	{
		cout<<"Tekrar Kalem Aramak Ýster misiniz? (e/h)"<<endl;
		cin>>secim;
	}
	 okuma.close();
	
}while(secim=='e');
}
void defterAra()
{
	defter defterBilgileri;
	string isim;
	
	char secim;
	
	int sayac=0;
	do
	{
		sayac=0;
	ifstream okuma("defter.txt");
		cout<<"Aranacak Defter Türünü Giriniz :";
	    cin>>isim;
	while(!(okuma.eof()))
	{
	
		okuma >>defterBilgileri.defterturu>>defterBilgileri.defterboyut>>defterBilgileri.defterrengi>>defterBilgileri.urunbilgileri.stok>>defterBilgileri.urunbilgileri.fiyat;
		
		if(isim==defterBilgileri.defterturu)
		{		

        cout<<defterBilgileri.defterturu<<" "<<defterBilgileri.defterboyut<<" "<<defterBilgileri.defterrengi<<" "<<defterBilgileri.urunbilgileri.stok<<" "<<defterBilgileri.urunbilgileri.fiyat<<endl;		
      sayac++;
		}
		
	
		
	}
	if(sayac==0)
	{
		cout<<"Aradýðýnýz Türde Defter Bulunamadý! "<<endl;
		cout<<"Tekrar Defter Aramak Ýster misiniz? (e/h)"<<endl;
		cin>>secim;
	}
	 okuma.close();
	
}while(secim=='e');

}
void silgiAra()
{
	silgi silgiBilgileri;
	string isim;
	
	char secim;
	
	int sayac=0;
	do
	{
		sayac=0;
	ifstream okuma("defter.txt");
		cout<<"Aranacak Silgi Boyutunu Giriniz :";
	    cin>>isim;
	while(!(okuma.eof()))
	{
	
		okuma>>silgiBilgileri.silgiBoyutu>>silgiBilgileri.urunbilgileri.stok>>silgiBilgileri.urunbilgileri.fiyat;
		
		if(isim==silgiBilgileri.silgiBoyutu)
		{		

		cout<<silgiBilgileri.silgiBoyutu<<" "<<silgiBilgileri.urunbilgileri.stok<<" "<<silgiBilgileri.urunbilgileri.fiyat<<endl;
      sayac++;
		}
		
	
		
	}
	if(sayac==0)
	{
		cout<<"Aradýðýnýz Boyutta Silgi Bulunamadý! "<<endl;
		cout<<"Tekrar Silgi Aramak Ýster misiniz? (e/h)"<<endl;
		cin>>secim;
	}
	 okuma.close();
	
}while(secim=='e');
   
	
	
	
}


int main() {
    setlocale(LC_ALL, "Turkish");

    char secim;
    do{

    system("cls");
    cout << "/%½       KIRTASÝYE OTOMASYONU      ½%\""  << endl;
	cout << " /*              Ana Menü            *\\ " << endl;
	cout << " \\*           1.Ürün Giriþi          */ " << endl;               
	cout << " /*            2.Stok Listesi        *\\ " << endl;
	cout << " \\*           3.Ürün Arama           */ " << endl;
	cout << " /*            4.Ürün Düzeltme       *\\ " << endl;
	cout << " \\*           5.Ürün Satýþý          */ " << endl;
	cout << " \\*           6.Çýkýþ                */ " << endl;
    cout << endl; 
    cout << "Yapmak Ýstediðiniz Ýþlemin Numarasýný Giriniz: " ;
    secim = getche();
			cout<<endl;
    switch (secim) {
        case '1': {
            system("cls");
            cout << "|---------ÜRÜN MENÜSÜ-----------|" << endl;
            cout << "|---------Secim Yapýnýz---------|" << endl;
            cout << "|---------1-Kalem Ekleme--------|" << endl;
            cout << "|---------2-Defter Ekleme-------|" << endl;
            cout << "|---------3-Silgi Ekleme--------|" << endl;
            cout << "|-------------------------------|" << endl;
            char tercih;
            tercih = getche();
						cout<<endl;

            switch (tercih) {
                case '1': {
                    kalemEkle();
                    break;
                }
                case '2': {
                    defterEkle();
                    break;
                }
                case '3': {
                    silgiEkle();
                    break;
                }
            }
            break;
        }

        case '2': {
            system("cls");
            cout << "|-------STOK BÝLGÝ MENÜSÜ-------|" << endl;
            cout << "|---------Secim Yapýnýz---------|" << endl;
            cout << "|---------1-Kalem Stoðu---------|" << endl;
            cout << "|---------2-Defter Stoðu--------|" << endl;
            cout << "|---------3-Silgi Stoðu---------|" << endl;
            cout << "|-----4-Tüm Ürünlerin Stoðu-----|" << endl;
            cout << "|-------------------------------|" << endl;
            char tercih;
            tercih = getche();
			cout<<endl;
            switch (tercih) {
                case '1': {
                    kalemListele();
                    break;
                }
                case '2': {
                    defterListele();
                    break;
                }
                case '3': {
                    silgiListele();
                    break;
                }
                case '4': {
                    kalemListele();
                    defterListele();
                    silgiListele();
                    break;
                }
            }
            break;
        }

        case '3': {
            system("cls");
            cout << "|--------ÜRÜN ARAMA MENU--------|" << endl;
            cout << "|---------Secim Yapýnýz---------|" << endl;
            cout << "|---------1-Kalem---------------|" << endl;
            cout << "|---------2-Defter--------------|" << endl;
            cout << "|---------3-Silgi---------------|" << endl;
            cout << "|-------------------------------|" << endl;
            cout << "Secim giriniz: ";
            secim = getche();
						cout<<endl;
            switch (secim) {
                case '1': {
                    kalemAra();
                    break;
                }
                case '2': {
                    defterAra();
                    break;
                }
                case '3': {
                    silgiAra();
                    break;
                }
            }
            break;
        }

        case '4': {
            system("cls");
            cout << "|-------DÜZENLEME MENÜSÜ--------|" << endl;
            cout << "|---------Seçim Yapýnýz---------|" << endl;
            cout << "|---------1-Kalem Düzenle-------|" << endl;
            cout << "|---------2-Defter Düzenle------|" << endl;
            cout << "|---------3-Silgi Düzenle-------|" << endl;
            cout << "|-------------------------------|" << endl;
            char tercih;
            cout << "Lütfen Düzenlemek Ýstediðiniz Ürünü Seçiniz :";
            tercih = getche();
			cout<<endl;
            switch (tercih) {
                case '1': {
                    kalemGuncelleme();
                    break;
                }
                case '2': {
                    defterGuncelleme();
                    break;
                }
                case '3': {
                    silgiGuncelleme();
                    break;
                }
            }
            break;
        }
        case '5':{
			satis();		
		break;
		}
		case '6':
			{
				break;
			}
    }
   if(secim!='6')
   {
   	cout << "Ana menuye donmek ister misin?(E/H)" << endl;
	secim=getche();
   }
   
    
}while(secim=='e' || secim=='E');

cout<<"Programdan Çýktýnýz..."<<endl
;
    system("pause");
    return 0;
}
