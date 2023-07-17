#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	//isi disini
	string namaP, tipeP;
	int jmlP;
	Node* next;
	Node* prev;
};
class ManajemenProduk {
private:
	Node* head;
public:
	ManajemenProduk() {
		head = NULL;
	}
	void tambahProduk() {
		string nama;
		int jumlah;
		string tipe;
		cout << "========== TAMBAH PRODUK ==========" << endl;
		cout << "Nama Produk : ";
		getline(cin, nama);
		cout << "Jumlah Produk : ";
		cin >> jumlah;
		cin.ignore(); // Membersihkan buffer input
		cout << "Tipe Produk : ";
		getline(cin, tipe);

		//isi disini
		Node* newNode = new Node();             
		newNode->namaP = nama;                   
		newNode->tipeP = tipe;  
		newNode->jmlP = jumlah;				

		//Memasukkan node diawal
		if (head == NULL){ //Jika belum ada node
		
			newNode->next = head;		 
			if (head != NULL)
				head->prev = newNode;  
			newNode->prev = NULL;       
			head = newNode;
			cout << "Produk berhasil ditambahkan!" << endl;
			return;
		}


		//Memasukkan node diantara 2 nodes
		Node* current = head;          //Step 1.a
		Node* previous = NULL;          //Step 1.b
		while (current->next != NULL ){ //Step 1.c
			previous = current;         //Step 1.d
			current = current->next;    //Step 1.e
		}

		newNode->next = current->next;  //Step 4
		newNode->prev = current;        //Step 5
		if (current->next != NULL)
		{
			current->next->prev = newNode;          //Step6
		}
		current->next = newNode;           //Step 7
		
		cout << "Produk berhasil ditambahkan!" << endl;
	}

	void tampilkanSemuaProduk() {
		cout << "========== SEMUA DATA PRODUK ==========" << endl;
		if (head == NULL) {
			cout << "Belum ada data produk yang tersimpan." << endl;
		}
		else {
			Node* current = head;

			//isi disini
			while (current != NULL) {
				
				cout << "Nama Produk\t: " << current->namaP << endl;
				cout << "Jumlah Produk\t: " << current->jmlP << endl;
				cout << "Tipe Produk\t: " << current->tipeP << "\n"<< endl;
				
				current = current->next;
			}
		}
	}
	void cariProdukByNama() {
		cout << "========== CARI PRODUK BERDASARKAN NAMA ==========" << endl;
		if (head == NULL) {
			cout << "Belum ada data produk yang tersimpan." << endl;
		}
		else {
			string targetNama;
			cout << "Nama Produk yang dicari: ";
			getline(cin, targetNama);
			Node* current = head;
			int posisi = 0;
			while (current != NULL) {
				posisi++;

				//isi disini
				if (current->namaP == targetNama) { //Jika nama produk dalam suatu node = target nama yang diinput
					cout << "Nama Produk " << targetNama << " ditemukan pada posisi ke - " << posisi;
					return;
				}
				current = current->next; //maju ke node beriktunya
			}
			if (current == NULL) {
				cout << "Nama produk " << targetNama << " TIDAK DITEMUKAN" <<
					endl;
			}
		}
	}
	void algorithmaSortByJumlahProduk() {
		if (head == NULL || head->next == NULL) {
			return; // Tidak perlu sorting jika hanya terdapat 0 atau 1 node
		}
		Node* current;
		Node* last = NULL;
		current = head;

		//isi disini

	}
};
int main() {
	ManajemenProduk manajemenProduk;
	int pilihan;
	do {
		cout << "========== APLIKASI MANAJEMEN DATA PRODUK ==========" << endl;
		cout << "1. Tambah Produk" << endl;
		cout << "2. Tampilkan Semua Produk" << endl;
		cout << "3. Cari Produk berdasarkan Nama" << endl;
		cout << "4. Urutkan Produk berdasarkan Jumlah" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore();
		switch (pilihan) {
		case 1:
			manajemenProduk.tambahProduk();
			break;
		case 2:
			manajemenProduk.tampilkanSemuaProduk();
			break;
		case 3:
			manajemenProduk.cariProdukByNama();
			break;
		case 4:
			manajemenProduk.algorithmaSortByJumlahProduk();
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}
		cout << endl;
	} while (pilihan != 5);
	return 0;
}

//2. menggunakan algoritma linked list (insert node beserta traverse) dan sorting
// 
//3. jadikan rear = head array
//	 input data ke array[rear]
//   rear++ 
//   jalankan ketika rear < front
//  
//4. Ketika data yang terakhir dimasukkan merupakan data yang kita butuhkan pertama
// contohnya fitur redo dan undo
// 
//5a. 5 depth
//5b. preorder ( 50 48 30 20 15 25 32 31 35 70 65 67 66 69 90 98 94 99 )