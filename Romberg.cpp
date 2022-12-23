#include <cmath>
#include <iostream>
using namespace std;

double f(double x) {
  // Definisi fungsi
	return 1/ (1 + x); // Contoh: integrasikan 1 / (1 + x) dari 0 hingga 1
}

double romberg(double a, double b, int n) {
	double R[n + 1][n + 1]; // 2D array untuk menyimpan hasil intermediate

  // Inisialisasi array dengan hasil aturan trapezoidal
	for (int i = 1; i <= n; i++) {
    	double h = (b - a) / pow(2, i - 1); // Lebar trapezoid
    	double sum = 0;
    	for (int j = 1; j <= pow(2, i - 1); j++) {
    		double x0 = a + (j - 1)*h;
     		double x1 = a + j * h;
      		sum += (f(x0) + f(x1)) * h / 2;
    	}
    	R[i][1] = sum;
	}

	cout << "Nilai integral dengan n = 2^" << 0 << ": " << R[1][1] << endl;
    cout << "Nilai integral dengan n = 2^" << 1 << ": " << R[2][1] << endl;

  // Gunakan metode ekstrapolasi Richardson untuk meningkatkan akurasi
	for (int i = 2; i <= n; i++) {
    	for (int j = 2; j <= i; j++) {
      		R[i][j] = (pow(4, j - 1) * R[i][j - 1] - R[i - 1][j - 1]) / (pow(4, j - 1) - 1);
			cout << "Nilai integral dengan n = 2^" << i << ": " << R[i][j] << endl;
		}
	}

  	// Hasil akhir tersimpan di R[n][n]
	return R[n][n];
}

double errRelative (double realValue, double measured)
{
	return (abs(measured-realValue))/realValue;
}

double errPercent (double data)
{
	return data * 100;
}

int main() {
	double a; // Batas bawah integrasi
  	double b; // Batas atas integrasi
  	int n; // Jumlah tingkat akurasi yang diinginkan
	double realValue; // Nilai real

	printf ("Masukkan batas bawah:\n");
	scanf ("%lf", &a);

	printf ("Masukkan batas atas:\n");
	scanf ("%lf", &b);

	printf ("Masukkan tingkat akurasi:\n");
	scanf ("%d", &n);

	printf ("Masukkan real value:\n");
	scanf ("%lf", &realValue);

  	double result = romberg(a, b, n);
  	printf("Result: %f\n\n", result);
  	
	double _errRelative = errRelative(realValue, result);
	printf("Error relative: %f\n", _errRelative);
  	printf("Percent error: %f%%\n", errPercent(_errRelative));
  	
	return 0;
}
