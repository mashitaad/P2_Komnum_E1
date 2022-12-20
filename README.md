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

dengan 
```math
h = (b-1) /over (2^(i-1)^)
```

dimana a dan b sebagai batasan dan i adalah indeks baris
