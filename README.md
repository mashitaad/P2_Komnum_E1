# P2_Komnum_E1

## Identitas Kelompok 1 (Komputasi Numerik E)
| Name           | NRP        |
| ---            | ---        |
| Glenaya        | 5025211202 |
| Mashita Dewi   | 5025211036 |
| Rayssa Ravelia | 5025211219 |

## Soal
> Salah satu kelemahan dari metode Trapezoidal adalah kita harus menggunakan jumlah interval yang besar untuk memperoleh akurasi yang diharapkan. Buatlah sebuah program komputer untuk menjelaskan bagaimana metode Integrasi Romberg dapat mengatasi kelemahan tersebut.

## Penjelasan Singkat Metode Integrasi Romberg
 Integrasi Romberg merupakan salah satu metode ekstrapolasi yang didasarkan pada perluasan ekstrapolasi Richardson, dimana pada setiap penerapan ekstrapolasi Richadson akan menaikkan orde galat pada hasil solusinya sebesar dua.

Formula Romberg pada umumnya adalah sebagai berikut:

<img width="334" alt="image" src="https://user-images.githubusercontent.com/89933907/208550543-3e54606d-1e29-455b-9629-a931c807f794.png">

dengan rumus h adalah :

![image](https://user-images.githubusercontent.com/114491445/209295987-3c53be78-ab98-4e82-b02f-6f95abfcd82e.png)

serta rumus CTR adalah :

![image](https://user-images.githubusercontent.com/114491445/209298898-db23ca08-4857-44d6-acbf-fb426a801912.png)


Notes :
- a dan b adalah batasan
- i adalah indeks baris

### Langkah - langkah melakukan formula Romberg :
1. Cari nilai h
2. Cari kolom pertama dari dua baris pertama menggunakan CTR
3. Dapatkan kolom selanjutnya di dalam baris tersebut menggunakan Formula Romberg dengan i > 1
4. Ulangi langkah satu sampai tiga setiap baris sampai mendapatkan solusi yang dibutuhkan

## Penjelasan Kode Integrasi Romberg

#### 1. Definisikan fungsi yang ingin diintegrasi dan batasannya
Sebagai contoh gunakan `1 / (1 + x)` dengan batas integrasi `a = 0` sebagai batas bawah dan `b = 1` sebagai batas atas

``` ruby
double f(double x) {
  // Definisi fungsi
  return 1 / (1 + x); // Contoh: integrasikan 1 / (1 + x) dari 0 hingga 1
}

double a = 0; // Batas bawah integrasi
double b = 1; // Batas atas integrasi

```

#### 2. Tentukan array 2D untuk menyimpan hasil antara metode integrasi Romberg
Ukuran array `harus sama` dengan jumlah tingkat akurasi yang diinginkan `+ 1`

``` ruby
const int n = 8; // Jumlah tingkat akurasi yang diinginkan
double R[n+1][n+1]; // Array 2D untuk menyimpan hasil intermediate
```

#### 3. Inisialisasi array dengan hasil trapezoidal rule untuk setiap tingkat akurasi yang diinginkan
`Aturan trapesium` adalah metode sederhana untuk mendekati integral tertentu dari suatu fungsi yang didasarkan pada `pembagian interval integrasi menjadi subinterval` yang lebih kecil dan menggunakan trapesium yang dibentuk oleh fungsi dan sumbu x untuk mendekati luas di bawah kurva.

``` ruby
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
```

#### 4. Selanjutnya gunakan metode ekstrapolasi Richardson untuk meningkatkan akurasi integrasi
Metode ekstrapolasi Richardson adalah teknik untuk `memperkirakan nilai` suatu fungsi pada tingkat ketelitian yang lebih tinggi dengan menggunakan nilai fungsi pada tingkat ketelitian yang lebih rendah. 

``` ruby
// Gunakan metode ekstrapolasi Richardson untuk meningkatkan akurasi
for (int i = 2; i <= n; i++) {
  for (int j = 2; j <= i; j++) {
    R[i][j] = (pow(4, j - 1) * R[i][j - 1] - R[i - 1][j - 1]) / (pow(4, j - 1) - 1);
		cout << "Nilai integral dengan n = 2^" << i << ": " << R[i][j] << endl;
  }
}
```

#### 5. Hasil akhir akan disimpan dalam `R[n][n]`

``` ruby
double result = R[n][n]; // Final result
```

Hasil dari `1 / (1 + x)` dengan `batas atas = 1`, `batas bawah = 0`, dan `n = 8` adalah
<p align="center">
<img width="300" alt="image" src="https://user-images.githubusercontent.com/91377782/208889350-f5d11e8e-899b-4c6f-a274-f7588cc85f7c.png">
</p>

Diperoleh hasil dengan metode Romberg adalah `0.693147`

## Kesimpulan
Metode integrasi romberg adalah metode yang sangat efisien untuk mendekati integral tertentu dari suatu fungsi. Hal ini sangat berguna untuk fungsi yang tidak dapat diintegrasikan secara analitik atau untuk fungsi dengan singularitas atau sharp corners yang menyulitkan penggunaan metode lain.
