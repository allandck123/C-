==================================== Tata Cara Penggunaan Program ====================================_
1. Silahkan Copy Folder PPH dari CD ke komputer anda untuk menjalankan program._
_
2. Silahkan jalankan cmd dalam fullscreen pada saat running program untuk penggunaan yang efektif._
   Jika data list.csv rusak saat edit data, terdapat file backup dengan nama backup.csv di dalam CD._
   Silahkan copy, paste, lalu rename file backup.csv menjadi "data list.csv" jika file rusak._
_
3. Dalam data list.csv terdapat kolom Nama, Alamat, Status Kawin, Kelompok Jaminan Kecelakaan Kerja(JKK),_
   Gaji Pokok, Tunjangan, Bonus, THR, Lembur, Awal Mulai Bekerja._
   - Status Perkawinan dapat diisi dengan tk0/tk1/tk2/tk3/k0/k1/k2/k3, yang nantinya akan_
     mempengaruhi jumlah PTKP._
   - Kelompok JKK dapat diisi dengan angka 1 sampai 5, yang nantinya akan mempengaruhi jumlah Bruto._
   - Gaji Pokok, Tunjangan, Bonus, THR, Uang Lembur dapat diisi dengan jumlah uang dalam mata uang_ 
     rupiah._
   - Awal Masa Kerja diisi dengan notasi angka bulan._
     Misalnya Mulai Bekerja pada bulan Maret, maka dapat diisi dengan 3._
   Program ini menggunakan sistem doubly linked list sebagai sistem pengalokasian memori data dan_
   filestream sebagai input dan output data._ 
_
4. Anda dapat menambah data yang akan dihitung dalam program dengan menggunakan menu Tambah Data._
   atau dengan mengedit data list.csv secara langsung_
_
5. Anda dapat mengedit data dengan cara memilih menu Edit Data. Untuk mengedit, anda harus memilih_
   nama karyawan yang ingin diubah datanya. Jika telah mulai mengedit data, "JANGAN" tutup running_
   cmd program setelah memilih menu edit, karena dapat merusak data list.csv jika ditutup sebelum_
   selesai diedit._
_
6. Untuk melihat hasil perhitungan, silahkan memasukan pilihan Display Hasil dalam menu program._
   Hasil perhitungan ini juga bisa dilihat di result.txt setelah memilih display pada menu._
_
7. Perhitungan terdiri dari : _
   - Menentukan JKK berdasarkan Kelompok._
   - Menghitung Jaminan Kematian(JK) yang bernilai 3% dari gaji pokok._
   - Menghitung nilai Bruto satu bulan dengan menjumlahkan gaji pokok, JKK, JK, Tunjangan, Bonus, THR,_
     dan Uang Lembur._
   - Menghitung Jaminan Hari Tua(JHT) yang bernilai 2% dari gaji pokok._
   - Menghitung Iuran Pensiun(IP) yang bernilai 1% dari gaji pokok._ 
   - Menghitung Biaya Jabatan(JB) yang bernilai 5% dari bruto dan maksimum 500000 Rupiah per bulan._
   - Menghitung nilai Netto satu bulan dengan mengurangkan Bruto dengan JHT, IP, dan BJ._  
   - Menghitung nilai Netto Disetahunkan dengan Netto satu bulan dikalikan 12._
   - Menentukan PTKP berdasarkan status perkawinan._
   - Menghitung PKP dengan mengurangkan Netto disetahunkan dengan PTKP lalu dibulatkan ke bawah_
     hingga nominal ribuan penuh._
   - Menentukan Tarif Pajak Progresif berdasarkan PKP._
   - Menghitung PPH Disetahunkan dengan mengalikan PKP dengan Tarif Pajak Progresif._
   - Menghitung PPH per bulan dengan cara PPH Disetahunkan dibagi 12._
_
7. Isi Data yang terdapat di result.txt atau output display antara lain : _
   - Nama Karyawan_
   - Alamat Karyawan_
   - Status Perkawinan_
   - Kelompok JKK_
   - Masa Kerja, didapat dari Awal mulai bekerja sampai dengan bulan desember_
   - Bruto per bulan_
   - Netto disetahunkan_
   - PTKP, ditentukan dari status perkawinan_
   - PKP, didapat dari (Netto disetahunkan - PTKP)_
   - PPH disetahunkan, didapat dari PKP dikalikan tarif pajak progresif_
   - PPH per bulan, PPH disetahunkan dibagi 12_

   