#include <iostream>
#include <string.h>
using namespace std;

class node
{
  public:
    int noMhs;
    node *next;
};

class linkedList
{
  node *START;

  public:
    linkedList()
    {
      START = NULL;
    }
    void addNode()
    {
      int nim;
      cout << "\nMasukkan Nomor Mahasiswa : ";
      cin >> nim;

      node *nodeBaru = new node;
      nodeBaru->noMhs = nim;

      if (START == NULL || nim <= START-> noMhs)
      {
        if ((START != NULL) && (nim == START->noMhs))
        {
          cout << "\nDuplikasi noMhs tidak dijalankan\n";
          return;
        }
        nodeBaru->next = START;
        START = nodeBaru;
        return;
    
      }
      node *previous = START;
      node *current = START;

      while ((current != NULL) && (nim >= current->noMhs))
      {
        if (nim == current->noMhs){
        cout << "\nDuplikasi noMhs tidak dijalankan\n";
        return;
        }
        previous = current;
        current = current->next;
      }
      nodeBaru->next = current;
      previous->next = nodeBaru;
      
    }

    bool listEmpty()
    {
      return (START == NULL);
    }
    bool Search(int nim, node **previos, node **current)
    {
      *previos = START;
      *current = START;

      while ((*current != NULL) && (nim != (*current)->noMhs))
      {
        *previos = *current;
        *current = (*current)->next;
      }

      return(*current != NULL);
    }

    bool delNode(int nim)
    {
      node *current, *previous;
      if (!Search(nim, &previous, & current))
        return false;

      if (current == START)
        START = START->next;
      else
        previous->next = current ->next;

      delete current;
      return true;
    }

    void traverse()
    {
      if (listEmpty())
      {
        cout << "\nList Kosong\n";
      }
      else
      {
        cout << "\nData didalam list adalah : \n";
        node *currentNode = START;
        while (currentNode != NULL)
        {
          cout << currentNode-> noMhs << endl;
          currentNode = currentNode->next;
        }
        cout << endl;
      }
    }
};

int main()
{
 linkedList mhs;
 int nim;
 char ch;
 while(1)
 {
  cout << endl
       << "Menu";
  cout << endl
       << "1. Menambah data kedalam list" << endl;
  cout << "2. Menghapus data dari dalam list" << endl;
  cout << "3. Menampilkan semua data didalam list" << endl;
  cout << "4. Mencari data dalam list" << endl;
  cout << "5. keluar" << endl;
  cout << endl
       << "Masukkan pilihan (1-5) : ";
  cin >> ch;
  
        cout << endl << "Data tidak ditemukan" << endl;
      else
        cout << endl << "Data dengan nomor Mahasiswa" << nim << "berhasil dihapus " << endl;
    }
    break;
    case '3': 
    {
      mhs.traverse();
    }
    break;
    case '4':
    {
      if (mhs.listEmpty() == true)
      {
        cout << "\nList Kosong\n";
        break;
      }
      node *previous, *current;
      cout << endl << "Masukkan no Mahasiswa yang dicari : ";
      cin >> nim;
      if (mhs.Search(nim, &previous ,&current) == false)
        cout << endl << "Data tidak ditemukan" << endl;
      else
      {
        cout << endl << "Data ditemukan" << endl;
        cout << "\nNo Mahasiswa : " << current->noMhs << endl;
        cout << "\n";
      }
    }
    break;
    case '5':
    {
      exit(0);
    }
    break;
    default:
    {
      cout << "Pilihan Salah !." << endl;
    }
    break;
  }
 }
}