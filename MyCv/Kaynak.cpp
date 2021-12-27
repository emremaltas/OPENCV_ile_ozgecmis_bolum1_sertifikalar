#include<opencv2/opencv.hpp>
#include<iostream>
//EMRE MALTAS 27.12.2021
using namespace std;
using namespace cv;


class my_cv {
   public:
	   struct semboller{

		   Mat telefon_sembolu = imread("C:\\Users\\User\\Desktop\\semboller\\telefon.png");
		   Mat githup_sembolu = imread("C:\\Users\\User\\Desktop\\semboller\\githup.png");
		   Mat linked_sembolu = imread("C:\\Users\\User\\Desktop\\semboller\\linked.png");
		   Mat mail_sembolu = imread("C:\\Users\\User\\Desktop\\semboller\\mail.png");
		   Mat konum_sembolu = imread("C:\\Users\\User\\Desktop\\semboller\\konum.png");
	   }sembol;

	   void daireCiz(Mat* cizilecekResim, double xKonum, double yKonum, double yariCap, Scalar renkler, uint8_t kalinlik)
	   {
		   xKonum *= 45;	yKonum *= 45;	 yariCap *= 45;
		   circle(*cizilecekResim, Point2d(xKonum, yKonum), yariCap, renkler, kalinlik, 8);
	   }
	   void ikiSatirArasi(Mat* cizilecekResim, double y1Konum, double y2Konum, Scalar renkler)
	   {
		   y1Konum *= 45; y2Konum *= 45;
		   (*cizilecekResim).rowRange(y1Konum, y2Konum).setTo(renkler);
	   }
	   void dikdorgenCiz(Mat* cizilecekResim, double x1Konum, double y1Konum, double x2Konum, double y2Konum, Scalar renkler)
	   {
		   x1Konum *= 45;  x2Konum *= 45;
		   y1Konum *= 45;  y2Konum *= 45;
		   rectangle(*cizilecekResim, Point2d(x1Konum, y1Konum), Point2d(x2Konum, y2Konum), renkler, 2, 8);
		   int d = 0;
		   for (int i = y1Konum; i <= y2Konum; i++)
		   {
			   line(*cizilecekResim, Point2d(x1Konum, y1Konum + d), Point2d(x2Konum, y1Konum + d), renkler, 1, 8);
			   d++;
		   }
	   }
	   void yaziYaz(Mat* yazilacakResim, string yazilacak, double xKonum, double yKonum,uint8_t boyut,Scalar renkler)
	   {
		   xKonum *= 45;			yKonum *= 45;
		   putText(*(yazilacakResim), yazilacak, Point2d(xKonum, yKonum), FONT_HERSHEY_SIMPLEX, boyut, renkler, 1, 8);
	   }

	   void resimKoy(Mat* anaResim, Mat* konulacakResim, double xKonum, double yKonum)
	   {
		   xKonum *= 45;  yKonum *= 45;
		   konulacakResim->copyTo((*anaResim)(Rect(xKonum, yKonum, konulacakResim->cols, konulacakResim->rows)));
	   }

	   struct gecisTipleri {
		   void kucultveyoket(Mat* kucultulecekResim, int donerek_mi0h1e)
		   {
			   Mat resim = *kucultulecekResim;
			   Mat donusMatrisi, sonHal;
			   float boyut = 1;
			   if (donerek_mi0h1e == 0)
			   {
				   for (int i = 0; i < 40; i++)
				   {
					   donusMatrisi = getRotationMatrix2D(Point2f(resim.cols / 2, resim.rows / 2), 0, boyut);
					   warpAffine(resim, sonHal, donusMatrisi, resim.size());
					   boyut *= 0.9;
					   if (i == 0)
					   {
						   imshow("ekran", sonHal);
						   waitKey(2000);
					   }
					   imshow("ekran", sonHal);
					   waitKey(50);
				   }
			   }
			   else
			   {
				   int donmeAcisi = 0;
				   for (int i = 0; i < 40; i++)
				   {
					   donusMatrisi = getRotationMatrix2D(Point2f(resim.cols / 2, resim.rows / 2), donmeAcisi, boyut);
					   warpAffine(resim, sonHal, donusMatrisi, resim.size());
					   boyut *= 0.9;
					   if (i == 0)
					   {
						   imshow("ekran", sonHal);
						   waitKey(2000);
					   }
					   donmeAcisi += 20;

					   imshow("ekran", sonHal);
					   waitKey(50);
				   }
			   }
		   }

		   void buyultveyoket(Mat* buyultulecekResim, int donerek_mi0h1e)
		   {
			   Mat resim = *buyultulecekResim;
			   Mat donusMatrisi, sonHal;
			   float boyut = 0.111111111111;
			   if (donerek_mi0h1e == 0)
			   {
				   for (int i = 0; i <= 23; i++)
				   {
					   donusMatrisi = getRotationMatrix2D(Point2f(resim.cols / 2, resim.rows / 2), 0, boyut);
					   warpAffine(resim, sonHal, donusMatrisi, resim.size(), 1, BORDER_TRANSPARENT, Scalar(0, 100, 150));
					   boyut *= 1.1;
					   imshow("ekran", sonHal);
					   waitKey(50);
					   if (i == 23)waitKey(2000);
				   }
			   }
			   else
			   {
				   float aci = 45;
				   for (int i = 0; i <= 23; i++)
				   {
					   donusMatrisi = getRotationMatrix2D(Point2f(resim.cols / 2, resim.rows / 2), aci, boyut);
					   warpAffine(resim, sonHal, donusMatrisi, resim.size(), 1, BORDER_TRANSPARENT, Scalar(0, 100, 150));
					   boyut *= 1.1;
					   imshow("ekran", sonHal);
					   waitKey(50);
					   aci += 45;
					   if (i == 23)waitKey(2000);
				   }
			   }
		   }
		   void piksel_piksel(Mat* piksel_resim)
		   {
			   Point resmin_boyutu = piksel_resim->size();
			   Mat beyazSayfa(resmin_boyutu.y, resmin_boyutu.x, CV_8UC3, Scalar(255, 255, 255));
			   for (int k = 0; k < 3; k++)
			   {
				   for (int i = 0; i < resmin_boyutu.x; i++)
				   {
					   for (int j = 0; j < resmin_boyutu.y; j++)
					   {
						   beyazSayfa.at<Vec3b>(j, i)[k] = piksel_resim->at<Vec3b>(j, i)[k];
					   }
					   imshow("ekran", beyazSayfa);
					   waitKey(1);
				   }
			   }
			   imshow("ekran", beyazSayfa);
			   waitKey(2000);
		   }
		   void rastgeleKare(Mat* yokEdilecekFoto)
		   {
			   imshow("ekran", *yokEdilecekFoto);
			   waitKey(3000);

			   Mat resimKopyasi = yokEdilecekFoto->clone();
			   uint8_t mavi = 0, kirmizi = 0, yesil = 0;
			   RNG &  rastgele= theRNG();
			   Point kordinat;
			   for (int i=0;i<2000;i++)
			   {
				   kordinat.x = rastgele.uniform(0,yokEdilecekFoto->cols+10);  kordinat.y = rastgele.uniform(0, yokEdilecekFoto->rows+10);
				   mavi = rastgele.uniform(0, 255); kirmizi = rastgele.uniform(0, 255); yesil = rastgele.uniform(0, 255);
				   islem.dikdorgenCiz(&resimKopyasi, kordinat.x / 45, kordinat.y / 45, (kordinat.x / 45) + 1, (kordinat.y / 45) + 1,
					   Scalar(mavi, yesil, kirmizi));
				   imshow("ekran", resimKopyasi);
				   waitKey(1);
			   }
		   }
	   }gecmeTuru;

}islem;
	
struct tumBilgiler {

		struct kisiselBilgi {

			string telefon_numarasi = "";
			string mail_adresi = "emremaltass@gmail.com";
			string githup_hesabi = "https://github.com/emremaltas";
			string dogum_tarihi = "14/06/1998";
			string adres = "";
			string medeni_hali = "BEKAR";
			string askerlik_durumu = "Tecilli";
			string ehliyet_durumu = "Yok";
			string ingilizce_Seviyesi = "A2-B1";

		}kisiselBilgileri;

		struct sertifika {

			Mat eemkon = imread("C:\\Users\\User\\Desktop\\sertifikalar\\eemkon.png");
			Mat digitaldonusum = imread("C:\\Users\\User\\Desktop\\sertifikalar\\digitaldonusum.png");
			Mat hitabet = imread("C:\\Users\\User\\Desktop\\sertifikalar\\hitabet.png");
			Mat bedendili = imread("C:\\Users\\User\\Desktop\\sertifikalar\\bedendili.png");
			Mat girisimcilik = imread("C:\\Users\\User\\Desktop\\sertifikalar\\girisimcilik.png");
			Mat kariyerdeilkadim = imread("C:\\Users\\User\\Desktop\\sertifikalar\\kariyerdeilkadim.png");
			Mat gamelab = imread("C:\\Users\\User\\Desktop\\sertifikalar\\gamelab.png");
			Mat bideb = imread("C:\\Users\\User\\Desktop\\sertifikalar\\bideb.png");

		}sertifikalari;

		struct Gecmis {

		}GecmisBilgisi;

}EmreMaltasin;


void giris()
{
	Mat girisPenceresi(645, 932, CV_8UC3, Scalar(20,20,20));
	Mat beyaz = girisPenceresi.clone();
	string isim_soyisim[10] = { "E","M","R","E","M","A","L","T","A","S"};
	string sun[5] = { "S","U","N","A","R" };
	int durum = 0 ;
		for (int t = 0; t < 10; t++)
		{

			for (int i = 200; i < 220; i+=5)
			{
					putText(girisPenceresi, isim_soyisim[t], Point(170 + t * 60, i + 0), FONT_HERSHEY_COMPLEX, 3, Scalar(255, 255, 255), 2, 8);
					imshow("ekran", girisPenceresi);
					waitKey(30);	
			}
		}
		putText(girisPenceresi, ",", Point(730, 230), FONT_HERSHEY_COMPLEX, 3, Scalar(255, 255, 255), 2, 8);
		for (int t=0;t<5;t++)
		{
			for (int i = 200; i < 220; i += 5)
			{
				putText(girisPenceresi, sun[t], Point(300 + t * 60, i + 150), FONT_HERSHEY_COMPLEX, 3, Scalar(255, 255, 255), 2, 8);
				imshow("ekran", girisPenceresi);
				waitKey(30);
			}
		}
	
		putText(girisPenceresi, "1.Bolum:Sertifikalar", Point(150, 500), FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255), 1, 8);
		imshow("ekran", girisPenceresi);    waitKey(1000);

		putText(girisPenceresi, "2.Bolum:Oz Gecmis", Point(150, 550), FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255), 1, 8);
		
		islem.gecmeTuru.kucultveyoket(&girisPenceresi,1);

}


void sertifikalariGoster()
{
	waitKey(500);
	imshow("ekran", EmreMaltasin.sertifikalari.bideb);								waitKey(2000);
	islem.gecmeTuru.buyultveyoket(&EmreMaltasin.sertifikalari.digitaldonusum, 0);   waitKey(1000);
	islem.gecmeTuru.kucultveyoket(&EmreMaltasin.sertifikalari.hitabet, 1);			
	islem.gecmeTuru.buyultveyoket(&EmreMaltasin.sertifikalari.bedendili, 1);		waitKey(1000);
	islem.gecmeTuru.kucultveyoket(&EmreMaltasin.sertifikalari.girisimcilik, 0);
	islem.gecmeTuru.piksel_piksel(&EmreMaltasin.sertifikalari.eemkon);				waitKey(1000);
	islem.gecmeTuru.rastgeleKare(&EmreMaltasin.sertifikalari.gamelab);
	imshow("ekran", EmreMaltasin.sertifikalari.kariyerdeilkadim);					waitKey(2000);
}


void cv_olustur()
{

}



int main()
{
	giris();
	sertifikalariGoster();

	waitKey(0);

}