//=======================//
//==DOUBLE LINKED LIST==//
//=====================//
#include <iostream>

using namespace std;

// struktur linked list
struct dataBarang{
  string MerkBarang;
  int jumlahBarang, hargaBarang;

  // pointer
  dataBarang *prev;
  dataBarang *next;
};

dataBarang *head, *tail, *cur, *del, *newNode, *afterNode;

// fungsi membuat circular double Linked list
void createDataBarang( string MerkBarang, int jmlBarang, int hargaBarang ){
  head = new dataBarang();
  head->MerkBarang = MerkBarang;
  head->jumlahBarang = jmlBarang;
  head->hargaBarang = hargaBarang;
  head->prev = head;
  head->next = head;
  tail = head;
}

// add First
void addFirst( string MerkBarang, int jmlBarang, int hargaBarang ){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    newNode = new dataBarang();
    newNode->MerkBarang = MerkBarang;
    newNode->jumlahBarang = jmlBarang;
    newNode->hargaBarang = hargaBarang;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
  }
}

// add Last
void addLast( string MerkBarang, int jmlBarang, int hargaBarang ){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    newNode = new dataBarang();
    newNode->MerkBarang = MerkBarang;
    newNode->jumlahBarang = jmlBarang;
    newNode->hargaBarang = hargaBarang;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
    tail->next = newNode;
    tail = newNode;
  }
}


// remove First
void removeFirst(){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    del = head;
    head = head->next;
    tail->next = head;
    head->prev = tail;
    delete del;
  }
}

// remove Last
void removeLast(){
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    del = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete del;
  }
}


// fungsi print
void printDataBarang()
{
  if( head == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    cout << "Data Barang : " << endl;
    cur = head;
    while( cur->next != head ){
      // print
      cout << "Merk Barang : " << cur->MerkBarang << endl;
      cout << "Jumlah Barang : " << cur->jumlahBarang << " barang" << endl;
      cout << "Harga Barang : Rp." << cur->hargaBarang << "\n" << endl;

      // step
      cur = cur->next;
    }
    // print last node
      cout << "Merk Barang : " << cur->MerkBarang << endl;
      cout << "Jumlah Barang : " << cur->jumlahBarang << " barang" << endl;
      cout << "Harga Barang : Rp." << cur->hargaBarang << "\n" << endl;
  }
}

int main(){

  createDataBarang("Asus", 2, 8000000);
  printDataBarang();

  addFirst("Xioami", 15, 9000000);
  printDataBarang();

  addLast("HP", 5, 12000);
  printDataBarang();

  removeFirst();
  printDataBarang();
  
  removeLast();
  printDataBarang();

}
