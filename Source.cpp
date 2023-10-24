#include<iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>

using namespace std;

struct riwayat
{
	float NilaiAwal;
	string matauangsumber;
	string matauangtarget;
	string waktu;
	float NilaiAkhir;
};

vector<riwayat> riwayatmatauang;//buat nyimpen riwayat

//fungsi buat ngambil waktu pas kode nya jalan
string waktusaatini() {
	time_t now = time(0);

	struct tm localTime;

	localtime_s(&localTime, &now);

	char jejakwaktu[80];
	strftime(jejakwaktu, sizeof(jejakwaktu), "%d-%m-%Y %H:%M:%S", &localTime);
	return string(jejakwaktu);
}

void tambahRiwayat(float awal, string sumber, string target, float kurs, float hasil) {
	riwayat record;
	record.NilaiAwal = awal;
	record.matauangsumber = sumber;
	record.matauangtarget = target;
	record.NilaiAkhir = hasil;
	record.waktu = waktusaatini();
	riwayatmatauang.push_back(record);
}

void menuhistory() {
	if (riwayatmatauang.empty()) {
		cout << "Tidak ada riwayat" << endl;
	}
	else {
		cout << "######## Riwayat Konversi Mata Uang ########" << endl;
		int startindex=max(0,static_cast<int>(riwayatmatauang.size())-5);//buat nampilin 5 riwayat terakhir
		for (int i = startindex;i < riwayatmatauang.size();i++) {
			const riwayat& record = riwayatmatauang[i];
			cout << endl;
			cout << "Waktu : " << record.waktu << endl;
			cout << "Mata Uang Awal :" << record.NilaiAwal << endl;
			cout << "Jumlah mata uang asal :" << setprecision(2) << fixed << record.matauangsumber << endl;
			cout << "Mata uang Tujuan " << record.matauangtarget << endl;
			cout << "Nilai Hasil Konersi " << setprecision(2) << fixed << record.NilaiAkhir << endl;
			cout << "===============================================================================" << endl;
		}
	}
}



void IDR() {
	double USD = 0.000063;
	double EUR = 0.000060;
	double YEN = 0.0094;  
	double awal;


	cout << "Masukkan nilai awal dari mata uang yang akan dikonversi (IDR/Rupiah) \n";
	cin >> awal;
	string matauang;
	cout << "Masukkan Jenis Mata Uang yang akan dikonversi (USD/EUR/JPY) \n";
	cin >> matauang;
	float hasil = 0.0;

	if (matauang == "USD"|| matauang == "Usd" || matauang == "usd" || matauang == "dollar" || matauang == "DOLLAR" || matauang == "Dollar") {
		hasil = awal * USD;
		cout << "Hasil Konversi adalah :" << setprecision(2) << fixed << hasil << " $\n";
	}
	else if (matauang == "EUR" || matauang == "eur" || matauang == "Eur" || matauang == "Euro" || matauang == "EURO" || matauang == "euro") {
		hasil = awal * EUR;
		cout << "Hasil Konversi adalah :" << setprecision(2) << fixed << hasil << "  €\n";
	}
	else if (matauang == "JPY" || matauang == "jpy" || matauang == "YEN" || matauang == "yen" || matauang == "Yen") {
		hasil = awal * YEN;
		cout << "Hasil Konversi adalah :" << setprecision(2) << fixed << hasil << "  yen \n";
	}
	else {
		
	}
	tambahRiwayat(awal, "IDR", matauang, USD, hasil);
}

void USD() {
	float IDR = 15763;
	float EUR = 0.95;
	float YEN = 149.86;
	float awal;

	cout << "Masukkan nilai awal dari mata uang yang akan dikonversi (USD/Amerika Serikat) \n";
	cin >> awal;
	string matauang;
	cout << "Masukkan Jenis Mata Uang yang akan dikonversi (IDR/EURO/JPY) \n";
	cin >> matauang;
	float hasil = 0.0;
	if (matauang == "IDR" || matauang == "Rupiah" || matauang == "rupiah" || matauang == "RUPIAH" || matauang == "idr" || matauang == "Idr") {
		hasil = awal * IDR;
		cout << "Hasil Konversi adalah :" << setprecision(2) << fixed << hasil << " RUPIAH\n";
	}
	else if (matauang == "EUR" || matauang == "eur" || matauang == "Eur" || matauang == "Euro" || matauang == "EURO" || matauang == "euro") {
		hasil = awal * EUR;
		cout << "Hasil Konversi adalah :" << setprecision(2) << fixed << hasil << " €\n";
	}
	else if (matauang == "JPY" || matauang == "jpy" || matauang == "YEN" || matauang == "yen" || matauang == "Yen") {
		hasil = awal * YEN;
		cout << "Hasil Konversi adalah :" << setprecision(2) << fixed << hasil << "  yen\n";
	}
	else {
		
	}
	tambahRiwayat(awal, "USD", matauang, IDR, hasil);
}

void JPY() {
	float IDR = 105.78;
	float EUR = 0.0063;
	float USD = 0.0067;
	float awal;
	float hasil = 0.0;

	cout << "Masukkan nilai awal dari mata uang yang akan dikonversi (JPY/Jepang Yen) \n";
	cin >> awal;
	string matauang;
	cout << "Masukkan Jenis Mata Uang yang akan dikonversi (IDR/EURO/USA) \n";
	cin >> matauang;

	if (matauang == "IDR" || matauang == "Rupiah" || matauang == "rupiah" || matauang == "RUPIAH" || matauang == "idr" || matauang == "Idr") {
		hasil = awal * IDR;
		cout << "Hasil Konversi adalah :" << setprecision(2) << fixed << hasil << " RUPIAH\n";
	}
	else if (matauang == "EUR" || matauang == "eur" || matauang == "Eur" || matauang == "Euro" || matauang == "EURO" || matauang == "euro") {
		hasil = awal * EUR;
		cout << "Hasil Konversi adalah :" << setprecision(2) << fixed << hasil << " €\n";
	}
	if (matauang == "USD" || matauang == "Usd" || matauang == "usd" || matauang == "dollar" || matauang == "DOLLAR" || matauang == "Dollar") {
		hasil = awal * USD;
		cout << "Hasil Konversi adalah :" << setprecision(2) << fixed << hasil << " $\n";
	}
	else {
		
	}
	tambahRiwayat(awal, "JPY", matauang, IDR, hasil);
}

void EURO() {
	float IDR = 16642.87;
	float YEN = 158.06;
	float USD = 1.06;
	float awal;

	cout << "Masukkan nilai awal dari mata uang yang akan dikonversi (EURO) \n";
	cin >> awal;
	string matauang;
	cout << "Masukkan Jenis Mata Uang yang akan dikonversi (1.IDR/2.JPY/3.USA) \n";
	cin >> matauang;
	float hasil = 0.0;
	if (matauang == "IDR" || matauang == "Rupiah" || matauang == "rupiah" || matauang == "RUPIAH" || matauang == "idr" || matauang == "Idr") {
		hasil = awal * IDR;
		cout << "Hasil Konversi adalah :" << setprecision(2) << fixed << hasil << " RUPIAH\n";
	}
	else if (matauang == "JPY" || matauang == "jpy" || matauang == "YEN" || matauang == "yen" || matauang == "Yen") {
		hasil = awal * YEN;
		cout << "Hasil Konversi adalah :" << setprecision(2) << fixed << hasil << "  yen \n";
	}
	if (matauang == "USD" || matauang == "Usd" || matauang == "usd" || matauang == "dollar" || matauang == "DOLLAR" || matauang == "Dollar") {
		hasil = awal * USD;
		cout << "Hasil Konversi adalah :" << setprecision(2) << fixed << hasil << " $\n";
	}
	else {
	
	}
	tambahRiwayat(awal, "EURO", matauang, IDR, hasil);
}

int main() {
	while (1) {
		int pilih;
		char milih;
		cout << endl;
		cout << "########## Selamat datang di program Konversi Mata uang ##########\n";
		cout << "Sillahkan pilih menu yang tersedia \n";
		cout << "1. Konversi Mata Uang IDR \n";
		cout << "2. Konversi Mata Uang USD \n";
		cout << "3. Konversi Mata Uang JPY \n";
		cout << "4. Konversi Mata Uang EURO \n";
		cout << "5. Lihat Riwayat \n";
		cout << "6. Exit \n";

		cin >> pilih ;
		switch (pilih) {
		case 1:
			IDR();
			break;
		case 2:
			USD();
			break;
		case 3:
			JPY();
			break;
		case 4:
			EURO();
			break;
		case 5:
			menuhistory();
			break;
		case 6:
			cout << endl;
			cout << "Terima Kasih telah menggunakan program ini \n";
			exit(1);
			break;
			
		default:
			cout << "Silahkan Pilih 1 - 6 \n";
			break;
		}
		
	}

	return 0;

}

//Mujadid Akbar Paryono
//3337230089