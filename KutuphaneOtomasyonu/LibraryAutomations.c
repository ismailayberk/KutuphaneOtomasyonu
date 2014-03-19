//Library Automations version 1.1

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <ctype.h>

struct kullanıcı {

	char tckimlik[11];
	char no[11];
	char adı[20];
	char soyad[20];
	char statü[20];
	char adres[100];
	char tel[11];
	char email[40];
	char sifre[15];	

}ögrenciüye,personelüye,üyesildir[BUFSIZ],üyegüncelleme[BUFSIZ]; 

struct infobook {

	char isbnno[25];
	char kitapad[25];
	char yazarad[20];
	char tür[15];
	char yayıntarihi[8];
	char yayınevi[20];

}kitap,kitapsildir[BUFSIZ],kitapgüncelleme[BUFSIZ],kitapödünc[BUFSIZ],kitaprezerve[BUFSIZ];

struct ödünc{

	int ö_no;
	char ö_isbnno[25];
	char ö_tckimlik[11];
	char ö_alma[8];
	char ö_teslim[8];

}ö;

struct rezerve{

	int r_no;
	char r_isbnno[25];
	char r_tckimlik[11];
	char r_alma[8];
	char r_teslim[8];

}r;

void üyeekle();  
void üyesil();
void üyegüncelle();
void kitapekle();
void kitapsil();
void kitapgüncelle();
void kitapiade();
void ödünckitap();
void rezervekitap();
void kitaparama();
void kitapkatalogu();
void osifredegistir(char []);
void psifredegistir(char []);
int perüyemi(char [],char [],FILE*);
int ogrüyemi(char[],char[],FILE*);
void perüyeol();
void ogrüyeol();
int menü1();
int menü2();
int menü3();
int sorgulama(char []);
FILE *Kitap;
FILE *Uye;
int sayac=0;
int sayac1=0;
int sayac2=0;

int main()
{
	char oyedek[15];
	char pyedek[15];
	char cevap;
	int x;
	char tc[11];
	char sifre[5];
	int secim1,secim2,secim3;
	system("color 4F"); 
	secim1=menü1();	 
	if (secim1==1)
	{
		if(sayac==0)
		{
			//kütüphane personelinin Tc Kimlik Numarasi:12345678911 şifresi:12345
			for(;;)
			{
				system("cls");
				printf("\nTC Kimlik Numarasi: ");
				scanf("%s",&tc);
				x=sorgulama(tc);
				if (x==1)
				{
					printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
					Sleep(3000);
				}
				if (x==0)
				{
					break;
				}
			}
			printf("\nSifreniz:");
			scanf("%s",&sifre);
			if ((strcmp(tc, "12345678911")==0) && (strcmp(sifre, "12345")==0))
			{
				secim2=menü2();
				switch (secim2)
				{
				case 1:
					int secim;
					system("cls");
					printf("Hangi statude uye kaydi yapacaksiniz?");
					printf("\n\n1) Ogrenci\n2) Personel\n");
					printf("Seciminiz : ");
					scanf_s("%d",&secim);
					if (secim==1)
					{
						ogrüyeol();
					}
					else if(secim==2)
					{
						perüyeol();
					}
					break;
				case 2:
					üyesil();
					break;
				case 3:
					üyegüncelle();
					break;
				case 4:
					kitapekle();
					break;
				case 5:
					kitapsil();
					break;
				case 6 :
					kitapgüncelle();
					break;
				case 7:
					ödünckitap();
					break;
				case 8:
					rezervekitap();
					break;
				case 9:
					kitaparama();
					break;
				case 0:
					exit(1);
					break;
				case 11:
					kitapkatalogu();
					break;
				default:
					break;
				}
			}
		}
		else if (sayac!=0)
		{
			secim2=menü2();
			switch (secim2)
			{
			case 1:
				int secim;
				system("cls");
				printf("Hangi statude uye kaydi yapacaksiniz?");
				printf("\n\n1) Ogrenci\n2) Personel\n");
				printf("Seciminiz : ");
				scanf_s("%d",&secim);
				if (secim==1)
				{
					ogrüyeol();
				}
				else if(secim==2)
				{
					perüyeol();
				}
				break;
			case 2:
				üyesil();
				break;
			case 3:
				üyegüncelle();
				break;
			case 4:
				kitapekle();
				break;
			case 5:
				kitapsil();
				break;
			case 6 :
				kitapgüncelle();
				break;
			case 7:
				ödünckitap();
				break;
			case 8:
				rezervekitap();
				break;
			case 9:
				kitaparama();
				break;
			case 0:
				exit(1);
				break;
			case 11:
				kitapkatalogu();
				break;
			default:
				break;
			}
		}		
	}

	if (secim1==2)
	{
		if(sayac1==0)
		{
			for(;;)
		{
			system("cls");
			printf("\nTC Kimlik Numarasi: ");
			scanf("%s",&tc);
			x=sorgulama(tc);
			if (x==1)
			{
				printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
				Sleep(3000);
			}
			if (x==0)
			{
				break;
			}
		}
		printf("\nSifreniz:");
		scanf("%s",&sifre);
		x=ogrüyemi(tc,sifre,Uye);
		if (x==1)
		{
			secim3=menü3();
			switch (secim3)
			{
			case 1:
				sayac1++;
				system("cls");
				printf("Eski sifrenizi giriniz : ");
				scanf("%s",&oyedek);
				osifredegistir(oyedek);
				break;
			case 2:
				sayac1++;
				ödünckitap();
				break;
			case 3:
				sayac1++;
				rezervekitap();
				break;
			case 4:
				sayac1++;
				kitaparama();				
				break;
			case 5:				
				sayac1++;
				kitapkatalogu();
				break;
			case 6:
				system("cls");
				printf("\n\n\t\tGule Gule");
				Sleep(2000);
				exit(1);
				break;
			default:
				break;
			}
		}
		if (x==0)
		{
			system("cls");
			printf("Uye degilsiniz. Uye olmak istermisin?(e/h)");
			scanf("%s",&cevap);
			if (cevap=='e')
			{
				sayac1++;
				ogrüyeol();
			}
			else if (cevap=='h')
			{
				main();
			}
			else
			{
				printf("Yanlis secim...");
				exit(1);
			}
		}
		}
		else if(sayac1!=0)
		{
			secim3=menü3();
			switch (secim3)
			{
			case 1:				
				sayac1++;
				system("cls");
				printf("Eski sifrenizi giriniz : ");
				scanf("%s",&oyedek);
				osifredegistir(oyedek);
				break;
			case 2:
				sayac1++;
				ödünckitap();
				break;
			case 3:
				sayac1++;
				rezervekitap();
				break;
			case 4:
				sayac1++;
				kitaparama();
				break;
			case 5:
				sayac1++;
				kitapkatalogu();
				break;
			case 6:
				system("cls");
				printf("\n\n\t\tGule Gule");
				Sleep(2000);
				exit(1);
				break;
			default:
				break;
			}
		}		
	}
	if (secim1==3)
	{
		if(sayac2==0)
		{
			for(;;)
		{
			system("cls");
			printf("\nTC Kimlik Numarasi: ");
			scanf("%s",&tc);
			x=sorgulama(tc);
			if (x==1)
			{
				printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
				Sleep(3000);
			}
			if (x==0)
			{
				break;
			}
		}
		printf("\nSifreniz:");
		scanf("%s",&sifre);
		x=perüyemi(tc,sifre,Uye);
		if (x==1)
		{
			secim3=menü3();
			switch (secim3)
			{
			case 1:
				sayac2++;
				system("cls");
				printf("Eski sifrenizi giriniz : ");
				scanf("%s",&pyedek);
				osifredegistir(pyedek);
				break;
			case 2:
				sayac2++;
				ödünckitap();
				break;
			case 3:
				sayac2++;
				rezervekitap();
				break;
			case 4:
				sayac2++;
				kitaparama();
				break;
			case 5:
				sayac2++;
				kitapkatalogu();
				break;
			case 6:
				system("cls");
				printf("\n\n\t\tGule Gule");
				Sleep(2000);
				exit(1);
				break;
			default:
				break;
			}
		}
		if (x==0)
		{
			system("cls");
			printf("Uye degilsiniz. Uye olmak istermisin?(e/h)");
			scanf("%s",&cevap);
			if (cevap=='e')
			{
				sayac2++;
				perüyeol();
			}
			else if (cevap=='h')
			{
				main();
			}
			else
			{
				printf("Yanlis secim...");
				exit(1);
			}
		}
		}
		else if(sayac2!=0)
		{
			secim3=menü3();
			switch (secim3)
			{
			case 1:
				sayac2++;
				system("cls");
				printf("Eski sifrenizi giriniz : ");
				scanf("%s",&pyedek);
				osifredegistir(pyedek);
				break;
			case 2:
				sayac2++;
				ödünckitap();
				break;
			case 3:
				sayac2++;
				rezervekitap();
				break;
			case 4:
				sayac2++;
				kitaparama();
				break;
			case 5:
				sayac2++;
				kitapkatalogu();
				break;
			case 6:
				system("cls");
				printf("\n\n\t\tGule Gule");
				Sleep(2000);
				exit(1);
				break;
			default:
				break;
			}
		}

	}
	if (secim1==4)
	{
		system("cls");
		printf("\n\t\t\t\n\nGule Gule");
		Sleep(2000);
		exit(1);
	}
}

int menü1()
{
	system("cls");
	int secim1;
	printf("Sisteme hangi statu ile erisimde bulunacaksiniz?\n\n");
	printf("1) Kutuphane Personeli\n\n2) Universite Ogrencisi\n\n3) Universite Personeli\n\n4) Cikis\n\n");
	printf("\tSeciminiz : ");
	scanf_s("%d",&secim1);
	return secim1;
}

int menü2()
{
	system("cls");
	int secim2;
	printf("\n1-Uye Ekle\n2-Uye Sil\n3-Uye Guncelle\n4-Kitap Ekle\n5-Kitap Sil\n6-Kitap Guncelle\n7-Odunc kitap al\n8-Kitap rezerve et\n9-Kitap arama\n0-Cikis\n11-Kitap Katalogu\n\n");
	printf("Seciminiz : ");
	scanf_s("%d",&secim2);
	return secim2;
}

int menü3()
{
	system("cls");
	int secim3;
	printf("\n1-Sifre degistir\n");
	printf("\n2-Kitap odunc al\n");
	printf("\n3-Kitap rezerve et\n");
	printf("\n4-Kitap arama\n");
	printf("\n5-Kitap katalogu\n");
	printf("\n6-Cikis\n\n");
	printf("Seciminiz : ");
	scanf_s("%d",&secim3);
	return secim3;
}

void üyesil()
{
	system("cls");
	int secim;
	char cevap;
	printf("Hangi statüde silme islemi yapacaksiniz?");
	printf("\n\n1) Ogrenci\n2) Personel\n");
	printf("Seciminiz : ");
	scanf_s("%d",&secim);
	if (secim==1)
	{
		char sil_tc[11];
		int denetleyici=0;
		char cevap;
		printf("Silinecek kisinin TC Kimlik Numarasini giriniz: ");
		scanf("%s",&sil_tc);
		Uye=fopen("ogrenci uyeler.dat","r+");
		int i=0;
		if (Uye == NULL)
		{
			printf("Dosya veya sunucu bulunamadi!\n");
		}
		else
		{
			system("cls");
			printf("********************************************************************************************************");
			printf("\n\t\t\t\t  UYE KAYDI SILME\n");
			printf("********************************************************************************************************\n\n");
			while(fscanf(Uye, "%s%s%s%s%s%s%s%s", &ögrenciüye.adı, &ögrenciüye.soyad, &ögrenciüye.tckimlik, &ögrenciüye.email, &ögrenciüye.tel, &ögrenciüye.adres, &ögrenciüye.statü, &ögrenciüye.sifre) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
			{
				if(strcmp(ögrenciüye.tckimlik,sil_tc)==0)
				{	
					denetleyici=1;
					strcpy(üyesildir[i].adı," ");		
					strcpy(üyesildir[i].soyad," ");	
					strcpy(üyesildir[i].tckimlik," ");	
					strcpy(üyesildir[i].email," ");	
					strcpy(üyesildir[i].tel," ");	
					strcpy(üyesildir[i].adres," ");	
					strcpy(üyesildir[i].statü," ");	
					strcpy(üyesildir[i].sifre," ");	
				}
				else 
				{		
					strcpy(üyesildir[i].adı,ögrenciüye.adı);				//
					strcpy(üyesildir[i].soyad,ögrenciüye.soyad);		//
					strcpy(üyesildir[i].tckimlik,ögrenciüye.tckimlik);		//
					strcpy(üyesildir[i].email,ögrenciüye.email);		//Eğer isim yoksa o i değerine göre direk ismi üyesildir struct değişkenine kopyalar.
					strcpy(üyesildir[i].tel,ögrenciüye.tel);		//
					strcpy(üyesildir[i].adres,ögrenciüye.adres);		//
					strcpy(üyesildir[i].statü,ögrenciüye.statü);		//	
					strcpy(üyesildir[i].sifre,ögrenciüye.sifre);
				}
				i++;
			}
			fclose(Uye);
			if (denetleyici==0)
			{
				printf("Rehberde %s TC Kimlik numarali bir uye bulunamadi.",sil_tc);
				Sleep(1500);
				üyesil();
			}
			Uye=fopen("ogrenci uyeler.dat","w");
			for(int j=0 ; j<i ; j++)
			{
				fprintf(Uye, "%s  %s  %s  %s  %s  %s  %s  %s  \n",üyesildir[j].adı, üyesildir[j].soyad, üyesildir[j].tckimlik, üyesildir[j].email, üyesildir[j].tel, üyesildir[j].adres, üyesildir[j].statü, üyesildir[j].sifre);
			}
			fclose(Uye);
			printf("%s TC Kimlik Numarali kisi basariyla silinmistir",sil_tc);
			Sleep(2500);
			system("cls");
		}
	}
	else if (secim==2)
	{
		char sil2_tc[11];
		int denetleyici1=0;
		char cevap1;
		printf("Silinecek kisinin TC Kimlik Numarasini giriniz: ");
		scanf("%s",&sil2_tc);
		Uye=fopen("personel uyeler.dat","r+");
		int i=0;
		if (Uye == NULL)
		{
			printf("Dosya veya sunucu bulunamadi!\n");
		}
		else
		{
			system("cls");
			printf("********************************************************************************************************");
			printf("\n\t\t\t\t  UYE KAYDI SILME\n");
			printf("********************************************************************************************************\n\n");
			while(fscanf(Uye, "%s%s%s%s%s%s%s%s", &personelüye.adı, &personelüye.soyad, &personelüye.tckimlik, &personelüye.email, &personelüye.tel, &personelüye.adres, &personelüye.statü, &personelüye.sifre) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
			{
				if(strcmp(personelüye.tckimlik,sil2_tc)==0)
				{	
					denetleyici1=1;
					strcpy(üyesildir[i].adı," ");		
					strcpy(üyesildir[i].soyad," ");	
					strcpy(üyesildir[i].tckimlik," ");	
					strcpy(üyesildir[i].email," ");	// belirtilen tc kimlik numaradaki kişi yerine boşluk yazar
					strcpy(üyesildir[i].tel," ");	
					strcpy(üyesildir[i].adres," ");	
					strcpy(üyesildir[i].statü," ");	
					strcpy(üyesildir[i].sifre," ");	
				}
				else 
				{		
					strcpy(üyesildir[i].adı,personelüye.adı);				//
					strcpy(üyesildir[i].soyad,personelüye.soyad);		//
					strcpy(üyesildir[i].tckimlik,personelüye.tckimlik);		//
					strcpy(üyesildir[i].email,personelüye.email);		//Eğer isim yoksa o i değerine göre direk ismi üyesildir struct değişkenine kopyalar.
					strcpy(üyesildir[i].tel,personelüye.tel);		//
					strcpy(üyesildir[i].adres,personelüye.adres);		//
					strcpy(üyesildir[i].statü,personelüye.statü);		//	
					strcpy(üyesildir[i].sifre,personelüye.sifre);
				}
				i++;
			}
			fclose(Uye);
			if (denetleyici1==0)
			{
				printf("Rehberde %s TC Kimlik numarali bir uye bulunamadi.",sil2_tc);
				Sleep(1500);
				üyesil();
			}
			Uye=fopen("personel uyeler.dat","w");
			for(int j=0 ; j<i ; j++)
			{
				fprintf(Uye, "%s  %s  %s  %s  %s  %s  %s  %s  \n",üyesildir[j].adı, üyesildir[j].soyad, üyesildir[j].tckimlik, üyesildir[j].email, üyesildir[j].tel, üyesildir[j].adres, üyesildir[j].statü, üyesildir[j].sifre);
			}
			fclose(Uye);
			printf("%s TC Kimlik Numarali kisi basariyla silinmistir",sil2_tc);
			Sleep(2500);
			system("cls");
			sayac++;
		}
	}
	else
	{
		printf("Yanlis secim");
		exit(1);
	}
	system("cls");
	printf("\n\n     Yeni bir kisi daha silmek istiyor musunuz(e/h) : "); // başka ekleme yapıp yapmayacağımız sorulur
	scanf("%s",&cevap);
	if(cevap=='h')	
	{
		sayac++;
		main();				
	}
	if (cevap=='e')
	{
		üyesil();				
	}
	else
	{
		system("cls");
		printf("Yanlis bir secim girdiniz");
		Sleep(1500);				
		exit(1);
	}
}

void üyegüncelle()
{
	int x;
	system("cls");
	int denetleyici=0;
	int k=0,denetleyici2=0;
	char cevap;
	char guncelle_tc[11];
	char guncelle2_tc[11];
	int secim;
	printf("Hangi statüde guncelleme islemi yapacaksiniz?");
	printf("\n\n1) Ogrenci\n2) Personel\n");
	printf("Seciminiz : ");
	scanf_s("%d",&secim);
	if (secim==1)
	{		
		for(;;)
		{
			printf("\nGuncellenicek kisinin TC Kimlik numarasini giriniz:");
			scanf("%s",&guncelle_tc);
			x=sorgulama(guncelle_tc);
			if (x==1)
			{
				printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
				Sleep(3000);
			}
			if (x==0)
			{
				break;
			}
		}
		system("cls");
		Uye = fopen("ogrenci uyeler.dat", "r+");//Dosyayı okuma+yazma modunda açıyoruz...
		if (Uye == NULL)//Dosya açılmassa(daha önce açılmış ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
		{
			printf("Dosya veya sunucu bulunamadi!\n");
		}
		else//Dosya daha önce varsa güncelleme işlemi yapılabilir.
		{
			system("cls");
			printf("********************************************************************************************************");
			printf("\n\t\t\t\t  KAYIT GUNCELLEME\n");
			printf("********************************************************************************************************\n\n");
			while (fscanf(Uye, "%s%s%s%s%s%s%s%s", &ögrenciüye.adı, &ögrenciüye.soyad, &ögrenciüye.tckimlik, &ögrenciüye.email, &ögrenciüye.tel, &ögrenciüye.adres, &ögrenciüye.statü, &ögrenciüye.sifre) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
			{
				if (strcmp(ögrenciüye.tckimlik, guncelle_tc)==0)//Aranan isimle karşılaştırma yaptırıp doğruysa bilgileri değiştiriyoruz
				{	
					//kişi bilgileri değiştirilerek k değerine göre olan struct değişkenine bilgilerimizi kaydediyoruz
					denetleyici2=1;
					printf("\n%s TC Kimlik Numarali kisi hakkinda yeni bilgileri giriniz.\n",guncelle_tc);
					printf(" Adi:");
					scanf("%s",&üyegüncelleme[k].adı);	
					printf("\n Soyadi:");
					scanf("%s",&üyegüncelleme[k].soyad);				
					for(;;)
					{
						printf("\n TC Kimlik Numarasi: ");
						scanf("%s",&üyegüncelleme[k].tckimlik);	
						x=sorgulama(üyegüncelleme[k].tckimlik);
						if (x==1)
						{
							printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
							Sleep(3000);
						}
						if (x==0)
						{
							break;
						}
					}			
					printf("\n E-mail Adresi: ");
					scanf("%s",&üyegüncelleme[k].email);
					for(;;)
					{				

						printf("\n Telefon Numarasi:");
						scanf("%s",&üyegüncelleme[k].tel);
						x=sorgulama(üyegüncelleme[k].tel);
						if (x==1)
						{
							printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
							Sleep(3000);
						}
						if (x==0)
						{
							break;
						}
					}				
					printf("\n Adresi:");
					_flushall();
					gets(üyegüncelleme[k].adres);					
					printf("\n Statusu:");
					_flushall();
					gets(üyegüncelleme[k].statü);
					printf("\n Uyelik Sifresi:");
					scanf("%s",&üyegüncelleme[k].sifre);
					printf("\nKisi guncellenmistir.\n\n");
					Sleep(2500);
					system("cls");
				}
				else
				{
					strcpy(üyegüncelleme[k].adı,ögrenciüye.adı);			
					strcpy(üyegüncelleme[k].soyad,ögrenciüye.soyad);		
					strcpy(üyegüncelleme[k].tckimlik,ögrenciüye.tckimlik);
					strcpy(üyegüncelleme[k].email,ögrenciüye.email);	
					strcpy(üyegüncelleme[k].tel,ögrenciüye.tel);		
					strcpy(üyegüncelleme[k].adres,ögrenciüye.adres);		
					strcpy(üyegüncelleme[k].statü,ögrenciüye.statü);	
					strcpy(üyegüncelleme[k].sifre,ögrenciüye.sifre);
				}
				k++;
			}
			fclose(Uye);
		}
		if(denetleyici2==0)
		{
			printf("Kayitlar arasinda %s TC Kimlik Numarali biri bulunmamaktadir.",guncelle_tc);
			Sleep(1500);
			üyegüncelle();
		}
		Uye=fopen("ogrenci uyeler.dat","w");//dosyayı sıfırdan açıp tekrar yazdırmak için yazma modunda açıyoruz.
		for(int j=0 ; j<k ; j++)
		{			
			fprintf(Uye, "%s  %s  %s  %s  %s  %s  %s  %s\n",üyegüncelleme[j].adı, üyegüncelleme[j].soyad, üyegüncelleme[j].tckimlik, üyegüncelleme[j].email, üyegüncelleme[j].tel, üyegüncelleme[j].adres, üyegüncelleme[j].statü, üyegüncelleme[j].sifre);
		}
		fclose(Uye);
	}
	else if (secim==2)
	{
		for(;;)
		{
			printf("\nGuncellenicek kisinin TC Kimlik numarasini giriniz:");
			scanf("%s",&guncelle2_tc);
			x=sorgulama(guncelle2_tc);
			if (x==1)
			{
				printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
				Sleep(3000);
			}
			if (x==0)
			{
				break;
			}
		}
		system("cls");
		Uye = fopen("personel uyeler.dat", "r+");//Dosyayı okuma+yazma modunda açıyoruz...
		if (Uye == NULL)//Dosya açılmassa(daha önce açılmış ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
		{
			printf("Dosya veya sunucu bulunamadi!\n");
		}
		else//Dosya daha önce varsa güncelleme işlemi yapılabilir.
		{
			system("cls");
			printf("********************************************************************************************************");
			printf("\n\t\t\t\t  KAYIT GUNCELLEME\n");
			printf("********************************************************************************************************\n\n");
			while (fscanf(Uye, "%s%s%s%s%s%s%s%s", &personelüye.adı, &personelüye.soyad, &personelüye.tckimlik, &personelüye.email, &personelüye.tel, &personelüye.adres, &personelüye.statü, &personelüye.sifre) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
			{
				if (strcmp(personelüye.tckimlik, guncelle2_tc)==0)//Aranan isimle karşılaştırma yaptırıp doğruysa bilgileri değiştiriyoruz
				{	
					//kişi bilgileri değiştirilerek k değerine göre olan struct değişkenine bilgilerimizi kaydediyoruz
					denetleyici2=1;
					printf("\n%s TC Kimlik Numarali kisi hakkinda yeni bilgileri giriniz.\n",guncelle_tc);
					printf(" Adi:");
					scanf("%s",&üyegüncelleme[k].adı);	
					printf("\n Soyadi:");
					scanf("%s",&üyegüncelleme[k].soyad);
					for(;;)
					{
						printf("\n TC Kimlik Numarasi: ");
						scanf("%s",&üyegüncelleme[k].tckimlik);	
						x=sorgulama(üyegüncelleme[k].tckimlik);
						if (x==1)
						{
							printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
							Sleep(3000);
						}
						if (x==0)
						{
							break;
						}
					}			
					printf("\n E-mail Adresi: ");
					scanf("%s",&üyegüncelleme[k].email);				
					for(;;)
					{				

						printf("\n Telefon Numarasi:");
						scanf("%s",&üyegüncelleme[k].tel);
						x=sorgulama(üyegüncelleme[k].tel);
						if (x==1)
						{
							printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
							Sleep(3000);
						}
						if (x==0)
						{
							break;
						}
					}					
					printf("\n Adresi:");
					_flushall();
					gets(üyegüncelleme[k].adres);				
					printf("\n Statusu:");
					_flushall();
					gets(üyegüncelleme[k].statü);
					printf("\n Statusu:");
					scanf("%s",&üyegüncelleme[k].sifre);
					printf("\nKisi guncellenmistir.\n\n");
					Sleep(2500);
					system("cls");
				}
				else
				{
					strcpy(üyegüncelleme[k].adı,personelüye.adı);			
					strcpy(üyegüncelleme[k].soyad,personelüye.soyad);		
					strcpy(üyegüncelleme[k].tckimlik,personelüye.tckimlik);
					strcpy(üyegüncelleme[k].email,personelüye.email);	
					strcpy(üyegüncelleme[k].tel,personelüye.tel);		
					strcpy(üyegüncelleme[k].adres,personelüye.adres);		
					strcpy(üyegüncelleme[k].statü,personelüye.statü);
					strcpy(üyegüncelleme[k].sifre,personelüye.sifre);
				}
				k++;
			}
			fclose(Uye);
		}
		if(denetleyici2==0)
		{
			printf("Kayitlar arasinda %s TC Kimlik Numarali biri bulunmamaktadir.",guncelle2_tc);
			Sleep(1500);
			üyegüncelle();
		}
		Uye=fopen("personel uyeler.dat","w");//dosyayı sıfırdan açıp tekrar yazdırmak için yazma modunda açıyoruz.
		for(int j=0 ; j<k ; j++)
		{			
			fprintf(Uye, "%s  %s  %s  %s  %s  %s  %s  %s  \n",üyegüncelleme[j].adı, üyegüncelleme[j].soyad, üyegüncelleme[j].tckimlik, üyegüncelleme[j].email, üyegüncelleme[j].tel, üyegüncelleme[j].adres, üyegüncelleme[j].statü, üyegüncelleme[j].sifre);
		}
		fclose(Uye);
	}
	system("cls");
	printf("\n\n     Yeni bir kisi daha guncellemek istiyor musunuz(e/h) : "); // başka ekleme yapıp yapmayacağımız sorulur
	scanf("%s",&cevap);
	if(cevap=='h')	
	{
		sayac++;
		main();				
	}
	if (cevap=='e')
	{
		üyegüncelle();				
	}
	else
	{
		system("cls");
		printf("Yanlis bir secim girdiniz");
		Sleep(1500);				
		exit(1);
	}


}

void kitapekle()
{
	system("cls");
	int denetleyici = 0;
	char cevap;
	Kitap=fopen("kitaplar.dat","a");
	if(Kitap==NULL)
		printf("Dosyaya erisilemiyor.");
	else 
	{
		rewind(Kitap);
		system("cls");
		printf("********************************************************************************************************");
		printf("\n\t\t\t\tKITAP EKLE\n");
		printf("********************************************************************************************************\n\n");
		printf("Kayit edilecek kitabin bilgilerini giriniz...\n\n");
		printf(" ISBN No:");
		scanf("%s",&kitap.isbnno);
		fprintf(Kitap,"%s	",kitap.isbnno);
		printf("\n Adi:");
		_flushall();
		gets(kitap.kitapad);
		fprintf(Kitap,"%s	",kitap.kitapad);
		printf("\n Yazarin Adi-Soyadi:");
		_flushall();
		gets(kitap.yazarad);	
		fprintf(Kitap,"%s	",kitap.yazarad);
		printf("\n Kitabin Turu:");
		_flushall();
		gets(kitap.tür);
		fprintf(Kitap,"%s	",kitap.tür);
		printf("\n Yayinlama Tarihi:");
		scanf("%s",&kitap.yayıntarihi);
		fprintf(Kitap,"%s	",kitap.yayıntarihi);
		printf("\n Yayinevi:");
		_flushall();
		gets(kitap.yayınevi);			
		fprintf(Kitap,"%s	\n",kitap.yayınevi);
		fclose(Kitap);
		printf("\n Girilen bilgiler dosyaya kaydediliyor...");
		Sleep(2500);
		system("cls");
		printf("\n\n     Yeni bir kitap daha eklemek istiyor musunuz(e/h) : "); // başka ekleme yapıp yapmayacağımız sorulur
		scanf("%s",&cevap);
		if(cevap=='h')	
		{
			sayac++;
			main();				
		}
		if (cevap=='e')
		{
			kitapekle();				
		}
		else
		{
			system("cls");
			printf("Yanlis bir secim girdiniz");
			Sleep(1500);				
			exit(1);
		}
	}
}

void kitapsil()
{
	system("cls");
	char sil_isbn[25];
	int denetleyici=0;
	char cevap;
	printf("Silinecek kitabin ISBN Numarasini giriniz: ");
	scanf("%s",&sil_isbn);
	Kitap=fopen("kitaplar.dat","r+");
	int i=0;
	if (Kitap == NULL)
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else
	{
		system("cls");
		printf("********************************************************************************************************");
		printf("\n\t\t\t\tKITAP KAYDI SILME\n");
		printf("********************************************************************************************************\n\n");
		while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tür, &kitap.yayıntarihi, &kitap.yayınevi) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
		{
			if(strcmp(kitap.isbnno,sil_isbn)==0)
			{	
				denetleyici=1;
				strcpy(kitapsildir[i].isbnno," ");		
				strcpy(kitapsildir[i].kitapad," ");	
				strcpy(kitapsildir[i].yazarad," ");	
				strcpy(kitapsildir[i].tür," ");	
				strcpy(kitapsildir[i].yayıntarihi," ");	
				strcpy(kitapsildir[i].yayınevi," ");	
			}
			else 
			{		
				strcpy(kitapsildir[i].isbnno,kitap.isbnno);				//
				strcpy(kitapsildir[i].kitapad,kitap.kitapad);		//
				strcpy(kitapsildir[i].yazarad,kitap.yazarad);		//
				strcpy(kitapsildir[i].tür,kitap.tür);		//Eğer isim yoksa o i değerine göre direk ismi kitapsildir struct değişkenine kopyalar.
				strcpy(kitapsildir[i].yayıntarihi,kitap.yayıntarihi);		//
				strcpy(kitapsildir[i].yayınevi,kitap.yayınevi);	
			}
			i++;
		}
		fclose(Kitap);
		if (denetleyici==0)
		{
			printf("Kutuphanede %s ISBN numarali bir kitap bulunamadi.",sil_isbn);
			Sleep(1500);
			system("cls");
			kitapsil();
		}
		Kitap=fopen("kitaplar.dat","w");
		for(int j=0 ; j<i ; j++)
		{
			fprintf(Kitap, "%s  %s  %s  %s  %s  %s  \n",kitapsildir[j].isbnno, kitapsildir[j].kitapad, kitapsildir[j].yazarad, kitapsildir[j].tür, kitapsildir[j].yayıntarihi, kitapsildir[j].yayınevi);
		}
		fclose(Kitap);
		printf("%s ISBN Numarali kitap basariyla silinmistir",sil_isbn);
		Sleep(2500);
		system("cls");
		printf("\n\n     Yeni bir kitap daha silmek istiyor musunuz(e/h) : "); // başka ekleme yapıp yapmayacağımız sorulur
		scanf("%s",&cevap);
		if(cevap=='h')	
		{
			sayac++;
			main();				
		}
		if (cevap=='e')
		{
			kitapsil();				
		}
		else
		{
			system("cls");
			printf("Yanlis bir secim girdiniz");
			Sleep(1500);				
			exit(1);
		}
	}
}

void kitapgüncelle()
{
	system("cls");
	int denetleyici=0;
	int k=0,denetleyici2=0;
	char cevap;
	char guncelle_isbn[25];
	printf("\nGuncellenicek kitabin ISBN numarasini giriniz:");
	scanf("%s",&guncelle_isbn);
	system("cls");
	Kitap = fopen("kitaplar.dat", "r+");
	if (Kitap == NULL)
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else//Dosya daha önce varsa güncelleme işlemi yapılabilir.
	{
		system("cls");
		printf("********************************************************************************************************");
		printf("\n\t\t\t\t  KITAP BILGISI GUNCELLEME\n");
		printf("********************************************************************************************************\n\n");
		while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tür, &kitap.yayıntarihi, &kitap.yayınevi) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
		{
			if (strcmp(kitap.isbnno, guncelle_isbn)==0)//Aranan isimle karşılaştırma yaptırıp doğruysa bilgileri değiştiriyoruz
			{	
				//kişi bilgileri değiştirilerek k değerine göre olan struct değişkenine bilgilerimizi kaydediyoruz
				denetleyici2=1;
				printf("\n%s ISBN Numarali kitap hakkinda yeni bilgileri giriniz.\n",guncelle_isbn);
				printf("Kayit edilecek kitabin bilgilerini giriniz...\n\n");
				printf(" ISBN No:");
				scanf("%s",&kitapgüncelleme[k].isbnno);
				printf("\n Adi:");
				_flushall();
				gets(kitapgüncelleme[k].kitapad);
				printf("\n Yazarin Adi-Soyadi:");
				_flushall();
				gets(kitapgüncelleme[k].yazarad);
				printf("\n Kitabin Turu:");
				_flushall();
				gets(kitapgüncelleme[k].tür);
				printf("\n Yayinlama Tarihi:");
				scanf("%s",&kitapgüncelleme[k].yayıntarihi);
				printf("\n Yayinevi:");
				_flushall();
				gets(kitapgüncelleme[k].yayınevi);			
				printf("\nKitap guncellenmistir.\n\n");
				Sleep(2500);
				system("cls");
			}
			else
			{
				strcpy(kitapgüncelleme[k].isbnno,kitap.isbnno);				//
				strcpy(kitapgüncelleme[k].kitapad,kitap.kitapad);		//
				strcpy(kitapgüncelleme[k].yazarad,kitap.yazarad);		//
				strcpy(kitapgüncelleme[k].tür,kitap.tür);		//Eğer isim yoksa o i değerine göre direk ismi kitapsildir struct değişkenine kopyalar.
				strcpy(kitapgüncelleme[k].yayıntarihi,kitap.yayıntarihi);		//
				strcpy(kitapgüncelleme[k].yayınevi,kitap.yayınevi);			
			}
			k++;
		}
		fclose(Kitap);
	}
	if(denetleyici2==0)
	{
		printf("Kayitlar arasinda %s ISBN Numarali kitap bulunmamaktadir.",guncelle_isbn);
		Sleep(1500);
		kitapgüncelle();
	}
	Kitap=fopen("kitaplar.dat","w");//dosyayı sıfırdan açıp tekrar yazdırmak için yazma modunda açıyoruz.
	for(int j=0 ; j<k ; j++)
	{			
		fprintf(Kitap, "%s  %s  %s  %s  %s  %s  \n",kitapgüncelleme[j].isbnno, kitapgüncelleme[j].kitapad, kitapgüncelleme[j].yazarad, kitapgüncelleme[j].tür, kitapgüncelleme[j].yayıntarihi, kitapgüncelleme[j].yayınevi);
	}
	fclose(Kitap);
	system("cls");
	printf("\n\n     Yeni bir kitap daha eklemek istiyor musunuz(e/h) : "); // başka ekleme yapıp yapmayacağımız sorulur
	scanf("%s",&cevap);
	if(cevap=='h')	
	{
		sayac++;
		main();				
	}
	if (cevap=='e')
	{
		kitapgüncelle();				
	}
	else
	{
		system("cls");
		printf("Yanlis bir secim girdiniz");
		Sleep(1500);				
		exit(1);
	}
}

void ödünckitap()
{

	system("cls");
	printf("********************************************************************************************************");
	printf("\n\t\t\t\tODUNC KITAP\n");
	printf("********************************************************************************************************\n\n");
	char ödünc_isbn[25];
	char kisitc[11];
	int denetleyici=0;
	char cevap;
	char cevap2;
	int k=0;
	int m=0;
	printf("Odunc alacaginiz kitabin ISBN Numarasini giriniz: ");
	scanf("%s",&ödünc_isbn);
	printf("TC Kimlik Numaranizi giriniz:");
	scanf("%s",&kisitc);
	Kitap=fopen("odunckitap.dat","r+");
	while(fscanf(Kitap, "%s%s%s%s%s%s%s", &kitapödünc[k].isbnno, &kitapödünc[k].kitapad, &kitapödünc[k].yazarad, &kitapödünc[k].tür, &kitapödünc[k].yayıntarihi, &kitapödünc[k].yayınevi, &ö.ö_tckimlik) != EOF)
	{
		if (strcmp(kitapödünc[k].isbnno,ödünc_isbn)==0)
		{
			printf("Aradiginiz kitap zaten ödünc alinmis...");
			Sleep(1500);
			ödünckitap();
		}
		if(strcmp(ö.ö_tckimlik,kisitc)==0)
		{
			printf("Daha once kitap almissiniz. Yeni kitap almak icin diger kitabi iade ediniz...");
			Sleep(2000);
			main();
		}
		k++;
	}
	Kitap=fopen("rezervekitap.dat","r+");
	while(fscanf(Kitap, "%s%s%s%s%s%s%s", &kitaprezerve[m].isbnno, &kitaprezerve[m].kitapad, &kitaprezerve[m].yazarad, &kitaprezerve[m].tür, &kitaprezerve[m].yayıntarihi, &kitaprezerve[m].yayınevi, &r.r_tckimlik) != EOF)
	{
		if (strcmp(kitaprezerve[m].isbnno,ödünc_isbn)==0)
		{

			if(strcmp(r.r_tckimlik,kisitc)==0)
			{
				printf("Daha once kitap rezerve etmissiniz.\n");
				printf("\Bu kitabi almak istermisiniz?(e/h):");
				scanf("%s",&cevap2);
				if (cevap2=='e')
				{
					ödünckitap();
				}
				else if (cevap2=='h')
				{
					main();
				}
				else
				{
					printf("\nYanlis secim yaptiniz...");
					Sleep(2000);
					exit(1);
				}
			}
			else
			{
				printf("\nAradiginiz kitap baskasi tarafindan rezerve edilmis...");
				printf("\nKitap aramak icin (a) tusuna basiniz...");
				printf("\nMenuye donmek icin (m) tusuna basiniz...");
				printf("\nCikis yapmak icin (c) tusuna basiniz...");
				printf("Seciminiz:");
				scanf("%s",&cevap);
				if (cevap=='a')
				{
					kitaparama();
				}
				else if (cevap=='m')
				{
					main();
				}
				else if (cevap=='c')
				{
					exit(1);
				}
				else
				{
					printf("Yanlis secim...");
					exit(1);
				}
			}
		}			
		m++;
	}
	Kitap=fopen("kitaplar.dat","r+");
	int i=0;
	if (Kitap == NULL)
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else
	{
		rewind(Kitap);
		while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tür, &kitap.yayıntarihi, &kitap.yayınevi) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
		{				
			if(strcmp(kitap.isbnno,ödünc_isbn)==0)
			{
				denetleyici=1;
				strcpy(kitapödünc[i].isbnno,kitap.isbnno);				//
				strcpy(kitapödünc[i].kitapad,kitap.kitapad);		//
				strcpy(kitapödünc[i].yazarad,kitap.yazarad);		//
				strcpy(kitapödünc[i].tür,kitap.tür);		//Eğer isim yoksa o i değerine göre direk ismi kitapsildir struct değişkenine kopyalar.
				strcpy(kitapödünc[i].yayıntarihi,kitap.yayıntarihi);		//
				strcpy(kitapödünc[i].yayınevi,kitap.yayınevi);
				printf("Tekrar TC Kimlik Numaranizi giriniz:");
				scanf("%s",&ö.ö_tckimlik);
			}
		}
		fclose(Kitap);
		if (denetleyici==0)
		{
			printf("Kutuphanede %s ISBN numarali bir kitap bulunamadi.",ödünc_isbn);
			Sleep(1500);
			system("cls");
			ödünckitap();
		}
		Kitap=fopen("odunckitap.dat","a+");
		rewind(Kitap);
		fprintf(Kitap, "%s  %s  %s  %s  %s  %s  %s  \n",kitapödünc[i].isbnno, kitapödünc[i].kitapad, kitapödünc[i].yazarad, kitapödünc[i].tür, kitapödünc[i].yayıntarihi, kitapödünc[i].yayınevi,ö.ö_tckimlik);
		fclose(Kitap);
		printf("%s ISBN Numarali kitabiniz hayirli olsun...",ödünc_isbn);
		Sleep(2500);
		system("cls");
		sayac++;
		main();
	}
}

void rezervekitap() // kitap ödünç alınmış mı onuda denetle
{
	system("cls");
	printf("********************************************************************************************************");
	printf("\n\t\t\t\tODUNC KITAP\n");
	printf("********************************************************************************************************\n\n");
	char rezerve_isbn[25];
	char kisitc[11];
	int denetleyici=0;
	char cevap;
	int k=0;
	printf("Rezerv edeceginiz kitabin ISBN Numarasini giriniz: ");
	scanf("%s",&rezerve_isbn);
	printf("TC Kimlik Numaranizi giriniz:");
	scanf("%s",&kisitc);
	Kitap=fopen("rezervekitap.dat","a+");
	while(fscanf(Kitap, "%s%s%s%s%s%s%s", &kitapödünc[k].isbnno, &kitapödünc[k].kitapad, &kitapödünc[k].yazarad, &kitapödünc[k].tür, &kitapödünc[k].yayıntarihi, &kitapödünc[k].yayınevi, &r.r_tckimlik) != EOF)
	{
		if (strcmp(kitapödünc[k].isbnno,rezerve_isbn)==0)
		{
			printf("Aradiginiz kitap zaten ödünc alinmis...");
			Sleep(1500);
			ödünckitap();
		}
		if(strcmp(r.r_tckimlik,kisitc)==0)
		{
			printf("Daha onca kitap almissiniz. Yeni kitap almak icin diger kitabi iade ediniz...");
			Sleep(2000);
			main();
		}
		k++;  
	}
	Kitap=fopen("kitaplar.dat","r+");
	int i=0;
	if (Kitap == NULL)
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else
	{
		rewind(Kitap);
		while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tür, &kitap.yayıntarihi, &kitap.yayınevi) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
		{				
			if(strcmp(kitap.isbnno,rezerve_isbn)==0)
			{
				denetleyici=1;
				strcpy(kitaprezerve[i].isbnno,kitap.isbnno);				//
				strcpy(kitaprezerve[i].kitapad,kitap.kitapad);		//
				strcpy(kitaprezerve[i].yazarad,kitap.yazarad);		//
				strcpy(kitaprezerve[i].tür,kitap.tür);		//Eğer isim yoksa o i değerine göre direk ismi kitapsildir struct değişkenine kopyalar.
				strcpy(kitaprezerve[i].yayıntarihi,kitap.yayıntarihi);		//
				strcpy(kitaprezerve[i].yayınevi,kitap.yayınevi);
				printf("Tekrar TC Kimlik Numaranizi giriniz:");
				scanf("%s",&r.r_tckimlik);
			}
		}
		fclose(Kitap);
		if (denetleyici==0)
		{
			printf("Kutuphanede %s ISBN numarali bir kitap bulunamadi.",rezerve_isbn);
			Sleep(1500);
			system("cls");
			rezervekitap();
		}
		Kitap=fopen("rezervekitap.dat","a+");
		rewind(Kitap);
		fprintf(Kitap, "%s  %s  %s  %s  %s  %s  %s  \n",kitapödünc[i].isbnno, kitapödünc[i].kitapad, kitapödünc[i].yazarad, kitapödünc[i].tür, kitapödünc[i].yayıntarihi, kitapödünc[i].yayınevi,r.r_tckimlik);
		fclose(Kitap);
		printf("%s ISBN Numarali kitabiniz hayirli olsun...",rezerve_isbn);
		Sleep(2500);
		system("cls");
		sayac++;
		main();
	}
}

int ogrüyemi(char x[],char y[],FILE *fptr)
{
	int flag = 0;
	fptr=fopen("ogrenci uyeler.dat","r+");
	if(fptr==NULL)
	{
		printf("Dosyaya erisilemiyor.");
	}
	else 
	{
		while (fscanf(fptr, "%s%s%s%s%s%s%s%s", &ögrenciüye.adı, &ögrenciüye.soyad, &ögrenciüye.tckimlik, &ögrenciüye.email, &ögrenciüye.tel, &ögrenciüye.adres, &ögrenciüye.statü, &ögrenciüye.sifre) != EOF)
		{
			if ((strcmp(ögrenciüye.tckimlik, x)==0) && (strcmp(ögrenciüye.sifre, y)==0))
			{
				flag=1;
			}
		}
	}
	fclose(fptr);
	return flag;
}

int perüyemi(char x[],char y[],FILE *fptr)
{
	int flag = 0;
	fptr=fopen("personel uyeler.dat","r+");
	if(fptr==NULL)
	{
		printf("Dosyaya erisilemiyor.");
	}
	else 
	{
		while (fscanf(fptr, "%s%s%s%s%s%s%s%s", &personelüye.adı, &personelüye.soyad, &personelüye.tckimlik, &personelüye.email, &personelüye.tel, &personelüye.adres, &personelüye.statü, &personelüye.sifre) != EOF)
		{
			if ((strcmp(personelüye.tckimlik, x)==0) && (strcmp(personelüye.sifre, y)==0))
			{
				flag=1;
			}
		}
	}
	fclose(fptr);
	return flag;
}

void ogrüyeol()
{
	int x;
	Uye=fopen("ogrenci uyeler.dat","a");
	if(Uye==NULL)
		printf("Dosyaya erisilemiyor.");
	else 
	{
		system("cls");
		printf("********************************************************************************************************");
		printf("\n\t\t\t\t UYE OL\n");
		printf("********************************************************************************************************\n\n");
		printf("Lutfen belirtilen sira ile bilgileri giriniz...\n\n");
		printf(" Adiniz:");
		scanf("%s",&ögrenciüye.adı);
		fprintf(Uye,"%s  ",ögrenciüye.adı);
		printf("\n Soyadiniz:");
		scanf("%s",&ögrenciüye.soyad);
		fprintf(Uye,"%s  ",ögrenciüye.soyad);
		for(;;)
		{
			printf("\n TC Kimlik Numaraniz: ");
			scanf("%s",&ögrenciüye.tckimlik);
			x=sorgulama(ögrenciüye.tckimlik);
			if (x==1)
			{
				printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
				Sleep(3000);
			}
			if (x==0)
			{
				break;
			}
		}		
		fprintf(Uye,"%s  ",ögrenciüye.tckimlik);
		printf("\n E-mail Adresiniz: ");
		scanf("%s",&ögrenciüye.email);
		fprintf(Uye,"%s  ",ögrenciüye.email);
		printf("\n Telefon Numaraniz:");
		scanf("%s",&ögrenciüye.tel);
		fprintf(Uye,"%s  ",ögrenciüye.tel);
		printf("\n Adresiniz:");
		_flushall();
		gets(ögrenciüye.adres);		
		fprintf(Uye,"%s  ",ögrenciüye.adres);
		printf("\n Statunuz:");
		_flushall();
		gets(ögrenciüye.statü);	
		fprintf(Uye,"%s  ",ögrenciüye.statü);
		printf("\n Uyelik Sifreniz:");
		scanf("%s",&ögrenciüye.sifre);
		fprintf(Uye,"%s  \n",ögrenciüye.sifre);
		fclose(Uye);
		printf("\n Sisteme basariyla uye oldunuz...");
		Sleep(2500);
		system("cls");
		sayac++;
		main();
	}
}

void perüyeol()
{
	int x;
	Uye=fopen("personel uyeler.dat","a");
	if(Uye==NULL)
		printf("Dosyaya erisilemiyor.");
	else 
	{
		system("cls");
		printf("********************************************************************************************************");
		printf("\n\t\t\t\t  UYE OL\n");
		printf("********************************************************************************************************\n\n");
		printf("Lutfen belirtilen sira ile bilgileri giriniz...\n\n");
		printf(" Adiniz:");
		scanf("%s",&personelüye.adı);
		fprintf(Uye,"%s	",personelüye.adı);
		printf("\n Soyadiniz:");
		scanf("%s",&personelüye.soyad);
		fprintf(Uye,"%s	",personelüye.soyad);
		for(;;)
		{
			printf("\n TC Kimlik Numaraniz: ");
			scanf("%s",&personelüye.tckimlik);
			x=sorgulama(personelüye.tckimlik);
			if (x==1)
			{
				printf("\nLutfen 11 basamakli numara giriniz veya harf kullanmayiniz");
				Sleep(3000);
			}
			if (x==0)
			{
				break;
			}
		}
		fprintf(Uye,"%s	",personelüye.tckimlik);
		printf("\n E-mail Adresiniz: ");
		scanf("%s",&personelüye.email);
		fprintf(Uye,"%s	",personelüye.email);
		printf("\n Telefon Numaraniz:");
		scanf("%s",&personelüye.tel);
		fprintf(Uye,"%s	",personelüye.tel);
		printf("\n Adresiniz:");
		_flushall();
		gets(personelüye.adres);		
		fprintf(Uye,"%s	",personelüye.adres);
		printf("\n Statunuz:");
		_flushall();
		gets(ögrenciüye.statü);	
		fprintf(Uye,"%s  ",personelüye.statü);
		printf("\n Uyelik Sifreniz");
		scanf("%s",&personelüye.sifre);
		fprintf(Uye,"%s  \n",personelüye.sifre);
		fclose(Uye);
		printf("\n Girilen bilgiler dosyaya kaydediliyor...");
		Sleep(2500);
		system("cls");
		sayac++;
		main();
	}
}

void kitapiade()
{
	system("cls");
	char sil_isbn[25];
	int denetleyici=0;
	char cevap;
	printf("Iade edilecek kitabin ISBN Numarasini giriniz: ");
	scanf("%s",&sil_isbn);
	Kitap=fopen("odunckitap.dat","r+");
	int i=0;
	if (Kitap == NULL)
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else
	{
		system("cls");
		printf("********************************************************************************************************");
		printf("\n\t\t\t\tKITAP IADE\n");
		printf("********************************************************************************************************\n\n");
		while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tür, &kitap.yayıntarihi, &kitap.yayınevi) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
		{
			if(strcmp(kitap.isbnno,sil_isbn)==0)
			{	
				denetleyici=1;
				strcpy(kitapsildir[i].isbnno," ");		
				strcpy(kitapsildir[i].kitapad," ");	
				strcpy(kitapsildir[i].yazarad," ");	
				strcpy(kitapsildir[i].tür," ");	
				strcpy(kitapsildir[i].yayıntarihi," ");	
				strcpy(kitapsildir[i].yayınevi," ");	
			}
			else 
			{		
				strcpy(kitapsildir[i].isbnno,kitap.isbnno);				//
				strcpy(kitapsildir[i].kitapad,kitap.kitapad);		//
				strcpy(kitapsildir[i].yazarad,kitap.yazarad);		//
				strcpy(kitapsildir[i].tür,kitap.tür);		//Eğer isim yoksa o i değerine göre direk ismi kitapsildir struct değişkenine kopyalar.
				strcpy(kitapsildir[i].yayıntarihi,kitap.yayıntarihi);		//
				strcpy(kitapsildir[i].yayınevi,kitap.yayınevi);	
			}
			i++;
		}
		fclose(Kitap);
		if (denetleyici==0)
		{
			printf("Kutuphanede %s ISBN numarali bir kitap bulunamadi.",sil_isbn);
			Sleep(1500);
			system("cls");
			kitapsil();
		}
		Kitap=fopen("odunckitap.dat","w");
		for(int j=0 ; j<i ; j++)
		{
			fprintf(Kitap, "%s  %s  %s  %s  %s  %s  \n",kitapsildir[j].isbnno, kitapsildir[j].kitapad, kitapsildir[j].yazarad, kitapsildir[j].tür, kitapsildir[j].yayıntarihi, kitapsildir[j].yayınevi);
		}
		fclose(Kitap);
		printf("%s ISBN Numarali kitap iade edilmistir",sil_isbn);
		Sleep(2500);
		system("cls");
		printf("\n\n     Yeni bir kitap daha almak istiyor musunuz(e/h) : "); // başka ekleme yapıp yapmayacağımız sorulur
		scanf("%s",&cevap);
		if(cevap=='h')	
		{
			sayac++;
			main();				
		}
		if (cevap=='e')
		{
			ödünckitap();				
		}
		else
		{
			system("cls");
			printf("Yanlis bir secim girdiniz");
			Sleep(1500);				
			exit(1);
		}
	}
}

void kitaparama()
{
	char kitapisim[25];
	char isbn[25];
	char türü[15];
	char yazarisim[20];
	int Secim, denetleyici = 0;
	char Secim2;
	Kitap=fopen("kitaplar.dat","r");
	if (Kitap == NULL)//Dosya açılmassa(daha önce açılmış ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else//Dosya daha önce varsa arama işlemi yapılabilir.
	{
		system("cls");
		printf("********************************************************************************************************");
		printf("\n\t\t\t\t  KITAP ARAMA\n");
		printf("********************************************************************************************************\n\n");
		printf(" 1-Ad ile arama\n");
		printf(" 2-ISBN No ile arama\n");
		printf(" 3-Yazar ismi ile arama\n");
		printf(" 4-Kitap turuna gore arama\n\n");
		printf("Seciminiz : ");
		scanf("%d", &Secim);
		switch (Secim)
		{
		case 1:
			{
				system("cls");
				printf("Aradiginiz kitabin adini giriniz:");
				_flushall();
				gets(kitapisim); // scanf ile almıyor burda gets ile alıyor 
				printf("\n");
				rewind(Kitap);
				while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tür, &kitap.yayıntarihi, &kitap.yayınevi) != EOF)
				{
					if (strcmp(kitap.kitapad, kitapisim)==0)//Aranan isimle karşılaştırma yaptırıp doğruysa ekrana yazıdırıyoruz. 
					{
						printf("Kitap Bilgileri\n");
						printf("--------------\n");
						printf("ISBN NO:  %s\nKitabin Adi:  %s\nYazar Adi:  %s\nKitabin Turu:  %s\nKitabin Yayin Tarihi:  %s\nKitabin Yayinevi:  %s\n\n", kitap.isbnno, kitap.kitapad, kitap.yazarad, kitap.tür, kitap.yayıntarihi, kitap.yayınevi);
						denetleyici = 1;
					}
				}
				if (denetleyici == 0)
				{
					printf("\nBu isimde bir kitap kutuphanede kayitli degil!\n\n");
				}
				break;
			}
		case 2:
			{
				system("cls");
				printf("Aradiginiz kitabin ISBN Numarasini giriniz:");
				_flushall();
				gets(isbn); // scanf ile almıyor burda gets ile alıyor
				rewind(Kitap);
				while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tür, &kitap.yayıntarihi, &kitap.yayınevi) != EOF)
				{
					if (strcmp(kitap.isbnno, isbn)==0)//Aranan isimle karşılaştırma yaptırıp doğruysa ekrana yazıdırıyoruz. 
					{
						printf("Kitap Bilgileri\n");
						printf("--------------\n");
						printf("ISBN NO:  %s\nKitabin Adi:  %s\nYazar Adi:  %s\nKitabin Turu:  %s\nKitabin Yayin Tarihi:  %s\nKitabin Yayinevi:  %s\n\n", kitap.isbnno, kitap.kitapad, kitap.yazarad, kitap.tür, kitap.yayıntarihi, kitap.yayınevi);
						denetleyici = 1;
					}
				}
				if (denetleyici == 0)
				{
					printf("\nBu ISBN No ile kayitli bir kitap mevcut değildir.\n\n");
				}
				break;
			}
		case 3:
			{
				system("cls");
				printf("Aradiginiz kitabin yazar ismini giriniz:");
				_flushall();
				gets(yazarisim); // scanf ile almıyor burda gets ile alıyor
				rewind(Kitap);
				while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tür, &kitap.yayıntarihi, &kitap.yayınevi) != EOF)
				{
					if (strcmp(kitap.yazarad, yazarisim)==0)//Aranan isimle karşılaştırma yaptırıp doğruysa ekrana yazıdırıyoruz. 
					{
						printf("Kitap Bilgileri\n");
						printf("--------------\n");
						printf("ISBN NO:  %s\nKitabin Adi:  %s\nYazar Adi:  %s\nKitabin Turu:  %s\nKitabin Yayin Tarihi:  %s\nKitabin Yayinevi:  %s\n\n", kitap.isbnno, kitap.kitapad, kitap.yazarad, kitap.tür, kitap.yayıntarihi, kitap.yayınevi);
						denetleyici = 1;
					}
				}
				if (denetleyici == 0)
				{
					printf("\nBu isimde bir yazarin kitabi kutuphanede kayitli degil!\n\n");
				}
				break;
			}
		case 4:
			{
				system("cls");
				printf("Aradiginiz kitabin türünü giriniz:");
				_flushall();
				gets(türü); // scanf ile almıyor burda gets ile alıyor
				rewind(Kitap);
				while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tür, &kitap.yayıntarihi, &kitap.yayınevi) != EOF)
				{
					if (strcmp(kitap.tür, türü)==0)//Aranan isimle karşılaştırma yaptırıp doğruysa ekrana yazıdırıyoruz. 
					{
						printf("Kitap Bilgileri\n");
						printf("--------------\n");
						printf("ISBN NO:  %s\nKitabin Adi:  %s\nYazar Adi:  %s\nKitabin Turu:  %s\nKitabin Yayin Tarihi:  %s\nKitabin Yayinevi:  %s\n\n", kitap.isbnno, kitap.kitapad, kitap.yazarad, kitap.tür, kitap.yayıntarihi, kitap.yayınevi);
						denetleyici = 1;
					}
				}
				if (denetleyici == 0)
				{
					printf("\nBu türe ait kitap mevcut değildir.\n\n");
				}
				break;			
			}
		}
	}	
	printf("\n");//İşleme devam edip etmeyeceği sorgulandmıştır.
	printf("Arama islemine devam etmek icin (A/a) tusuna basiniz\n");
	printf("Menuye donmek icin (M/m) tusuna basiniz \n");
	printf("Cikis  yapmak icin (C/c) tusuna basiniz\n\n");
	printf("Tercihiniz: ");
	scanf("%c", &Secim2); system("cls");
	if (Secim2 == 'a' || Secim2== 'A')
	{
		kitaparama();
	}
	else if (Secim2 == 'm' || Secim2 == 'M')
	{
		sayac++;
		main();
	}
	else if (Secim2 == 'c' || Secim2 == 'C')
	{
		exit(1);
	}
	else
	{
		printf("\nYanlis secim yaptiniz!Lutfen belirtilen tuslari kullaniniz\n");
		Sleep(2500);
		exit(1);
	}	
}

int sorgulama(char x[30])
{
	int a=0;
	for (int i = 0; i < 11; i++) //Girilen numaranın 11 haneli olduğunu ve harf girilip girilmediğini kontrol eden kısım
	{
		if (isdigit(x[i])==0)
		{
			a=1;
		}
	}
	return a;
}

void kitapkatalogu()
{
	Kitap = fopen("kitaplar.dat", "r");	//Okuma modunda açıyoruz
	int Secim;
	if (Kitap == NULL)//Dosya açılmassa(daha önce açılmış ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
	{
		printf("Dosya veya sunucu bulunamadi!\n");
	}
	else // Dosya önceden varsa kisi eklenebilir
	{
		system("cls");
		printf("********************************************************************************************************");
		printf("\n\t\t\t\tKITAP KATALOGU\n");
		printf("********************************************************************************************************\n\n");
		printf("Kitap listemizde ekli olan tum kitaplari goruntuluyorsunuz \n\n");
		while(fscanf(Kitap, "%s%s%s%s%s%s", &kitap.isbnno, &kitap.kitapad, &kitap.yazarad, &kitap.tür, &kitap.yayıntarihi, &kitap.yayınevi) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
		{	
			printf("ISBN NO:  %s\nKitabin Adi:  %s\nYazar Adi:  %s\nKitabin Turu:  %s\nKitabin Yayin Tarihi:  %s\nKitabin Yayinevi:  %s\n\n", kitap.isbnno, kitap.kitapad, kitap.yazarad, kitap.tür, kitap.yayıntarihi, kitap.yayınevi);
		}
		fclose(Kitap);//Dosyayı kapatıyoruz		
		//İşleme devam edip etmeyeceği sorgulanmıştır.
		printf("\n");
		printf("Menuye donmek icin (M/m) tusuna basin \n");
		printf("Cikis  yapmak icin (C/c) tusuna basin \n\n");
		printf("Tercihiniz: ");
		scanf("%s",&Secim);
		system("cls");
		if (Secim == 'm' || Secim == 'M')
		{
			sayac++;
			main(); //Ana fonksiyona gönderilir				
		}
		else if (Secim == 'c' || Secim == 'C')
		{
			exit(1);//proje sonlandirilir
		}
		else 
			printf("\n");
		printf("\nYanlis secim yaptiniz!Lutfen belirtilen tuslari kullaniniz\n");
	}
}

void osifredegistir(char x[15])
{
		int k=0;
		int denetleyici = 0;
		char yenisifre[15];
		Uye = fopen("ogrenci uyeler.dat", "r+");//Dosyayı okuma+yazma modunda açıyoruz...
		if (Uye == NULL)//Dosya açılmassa(daha önce açılmış ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
		{
			printf("Dosya veya sunucu bulunamadi!\n");
		}
		else//Dosya daha önce varsa güncelleme işlemi yapılabilir.
		{
			system("cls");
			printf("********************************************************************************************************");
			printf("\n\t\t\t\t  SIFRE DEGISTIRME\n");
			printf("********************************************************************************************************\n\n");
			while (fscanf(Uye,"%s%s%s%s%s%s%s%s",ögrenciüye.adı, ögrenciüye.soyad, ögrenciüye.tckimlik,ögrenciüye.email, ögrenciüye.tel, ögrenciüye.adres, ögrenciüye.statü, ögrenciüye.sifre)!=EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
			{
				if (strcmp(ögrenciüye.sifre, x)==0)//Aranan isimle karşılaştırma yaptırıp doğruysa bilgileri değiştiriyoruz
				{
					denetleyici=1;
					strcpy(üyegüncelleme[k].adı,ögrenciüye.adı);			
					strcpy(üyegüncelleme[k].soyad,ögrenciüye.soyad);		
					strcpy(üyegüncelleme[k].tckimlik,ögrenciüye.tckimlik);
					strcpy(üyegüncelleme[k].email,ögrenciüye.email);
					strcpy(üyegüncelleme[k].tel,ögrenciüye.tel);		
					strcpy(üyegüncelleme[k].adres,ögrenciüye.adres);		
					strcpy(üyegüncelleme[k].statü,ögrenciüye.statü);	
					printf("\n Yeni Uyelik Sifrenizi giriniz:");
					scanf("%s",&üyegüncelleme[k].sifre);
					
				}
				else
				{
					strcpy(üyegüncelleme[k].adı,ögrenciüye.adı);			
					strcpy(üyegüncelleme[k].soyad,ögrenciüye.soyad);		
					strcpy(üyegüncelleme[k].tckimlik,ögrenciüye.tckimlik);
					strcpy(üyegüncelleme[k].email,ögrenciüye.email);	
					strcpy(üyegüncelleme[k].tel,ögrenciüye.tel);		
					strcpy(üyegüncelleme[k].adres,ögrenciüye.adres);		
					strcpy(üyegüncelleme[k].statü,ögrenciüye.statü);	
					strcpy(üyegüncelleme[k].sifre,ögrenciüye.sifre);
				}
				k++;
			}
			fclose(Uye);
		}
		if(denetleyici==0)
		{
			printf("\n\nBu sifre ile kayıtlı bir uye bulunamadi...");
			Sleep(1500);
			main();
		}
		Uye=fopen("ogrenci uyeler.dat","w");//dosyayı sıfırdan açıp tekrar yazdırmak için yazma modunda açıyoruz.
		for(int j=0 ; j<k ; j++)
		{			
			fprintf(Uye, "%s  %s  %s  %s  %s  %s  %s  %s  \n",üyegüncelleme[j].adı, üyegüncelleme[j].soyad, üyegüncelleme[j].tckimlik, üyegüncelleme[j].email, üyegüncelleme[j].tel, üyegüncelleme[j].adres, üyegüncelleme[j].statü, üyegüncelleme[j].sifre);
		}
		fclose(Uye);
		printf("\n\n Sifreniz basariyla degistirilmistir...");
		Sleep(5500);
		main();
}

void psifredegistir(char x[15])
{
	int k=0;
		int denetleyici = 0;
		char yenisifre[15];
		char sifretekrar[15];
		Uye = fopen("personel uyeler.dat", "r+");//Dosyayı okuma+yazma modunda açıyoruz...
		if (Uye == NULL)//Dosya açılmassa(daha önce açılmış ve silinmişse veya açma işlemi gerçekleştirilmemişse) NULL değeri gelir
		{
			printf("Dosya veya sunucu bulunamadi!\n");
		}
		else//Dosya daha önce varsa güncelleme işlemi yapılabilir.
		{
			system("cls");
			printf("********************************************************************************************************");
			printf("\n\t\t\t\t  SIFRE DEGISTIRME\n");
			printf("********************************************************************************************************\n\n");
			while (fscanf(Uye,"%s%s%s%s%s%s%s%s", &personelüye.adı, &personelüye.soyad, &personelüye.tckimlik, &personelüye.email, &personelüye.tel, &personelüye.adres, &personelüye.statü, &personelüye.sifre) != EOF)//Dosya sonu belirteci EOF a kadar okunur ve istenilen işlemlere geçilir.
			{
				if (strcmp(personelüye.sifre,x)==0)
				{
					denetleyici=1;
					strcmp(personelüye.sifre,yenisifre);
					strcpy(üyegüncelleme[k].adı,personelüye.adı);			
					strcpy(üyegüncelleme[k].soyad,personelüye.soyad);		
					strcpy(üyegüncelleme[k].tckimlik,personelüye.tckimlik);
					strcpy(üyegüncelleme[k].email,personelüye.email);	
					strcpy(üyegüncelleme[k].tel,personelüye.tel);		
					strcpy(üyegüncelleme[k].adres,personelüye.adres);		
					strcpy(üyegüncelleme[k].statü,personelüye.statü);
					printf("\n Yeni Uyelik Sifrenizi giriniz:");
					scanf("%s",&üyegüncelleme[k].sifre);
				}
				else
				{
					strcpy(üyegüncelleme[k].adı,personelüye.adı);			
					strcpy(üyegüncelleme[k].soyad,personelüye.soyad);		
					strcpy(üyegüncelleme[k].tckimlik,personelüye.tckimlik);
					strcpy(üyegüncelleme[k].email,personelüye.email);	
					strcpy(üyegüncelleme[k].tel,personelüye.tel);		
					strcpy(üyegüncelleme[k].adres,personelüye.adres);		
					strcpy(üyegüncelleme[k].statü,personelüye.statü);
					strcpy(üyegüncelleme[k].sifre,personelüye.sifre);
				}
				k++;
			}
			fclose(Uye);
		}
		if(denetleyici==0)
		{
			printf("\n\nBu sifre ile kayıtlı bir uye bulunamadi...");
			Sleep(1500);
			main();
		}
		Uye=fopen("personel uyeler.dat","w");//dosyayı sıfırdan açıp tekrar yazdırmak için yazma modunda açıyoruz.
		for(int j=0 ; j<k ; j++)
		{			
			fprintf(Uye, "%s  %s  %s  %s  %s  %s  %s  %s\n",üyegüncelleme[j].adı, üyegüncelleme[j].soyad, üyegüncelleme[j].tckimlik, üyegüncelleme[j].email, üyegüncelleme[j].tel, üyegüncelleme[j].adres, üyegüncelleme[j].statü, üyegüncelleme[j].sifre);
		}
		fclose(Uye);
		printf("\n\n Sifreniz basariyla degistirilmistir...");
		Sleep(2500);
		main();
}
