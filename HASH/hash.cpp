/*
 * C++ Program to Implement Hash Tables with Linear Probing
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <functional>

using namespace std;
const int TABLE_SIZE = 5000;
/*
 * HashNode Class Declaration
 */
class HashNode
{
  public:
    int key;
    int value;
    HashNode(int key, int value)
    {
      this->key = key;
      this->value = value;
    }
};
/*
* DeletedNode Class Declaration
*/
class DeletedNode:public HashNode
{
  private:
    static DeletedNode *entry;
      DeletedNode():HashNode(-1, -1)
        {}
  public:
    static DeletedNode *getNode()
    {
      if (entry == NULL)
        entry = new DeletedNode();
      return entry;
    }
};
DeletedNode *DeletedNode::entry = NULL;
/*
 * HashMap Class Declaration
 */
class HashMap
{
  private:
    HashNode **htable;
  public:
    HashMap()
    {
      htable = new HashNode* [TABLE_SIZE];
      for (int i = 0; i < TABLE_SIZE; i++)
      {
        htable[i] = NULL;
      }
    }
    ~HashMap()
    {
      for (int i = 0; i < TABLE_SIZE; i++)
        {
          if (htable[i] != NULL && htable[i] != DeletedNode::getNode())
            delete htable[i];
        }
      delete[] htable;
    }
    /*
    * Hash Function
    */
    int HashFunc(int key)
      {
        return key % TABLE_SIZE;
      }
      /*
      * Insert Element at a key
      */
      void Insert(int key, int value)
        {
          int hash_val = HashFunc(key);
          int init = -1;
          int deletedindex = -1;
          while (hash_val != init && (htable[hash_val]
          == DeletedNode::getNode() || htable[hash_val]
          != NULL && htable[hash_val]->key != key))
          {
            if (init == -1)
              init = hash_val;
            if (htable[hash_val] == DeletedNode::getNode())
              deletedindex = hash_val;
            hash_val = HashFunc(hash_val + 1);
          }
          if (htable[hash_val] == NULL || hash_val == init)
            {
              if(deletedindex != -1)
                htable[deletedindex] = new HashNode(key, value);
              else
                htable[hash_val] = new HashNode(key, value);
            }
            if(init != hash_val)
            {
              if (htable[hash_val] != DeletedNode::getNode())
                {
                  if (htable[hash_val] != NULL)
                    {
                      if (htable[hash_val]->key == key)
                        htable[hash_val]->value = value;
                    }
                }
                else
                  htable[hash_val] = new HashNode(key, value);
            }
        }
    /*
    * Search Element at a key
    */
     int Search(int key)
     {
        int hash_val = HashFunc(key);
        int init = -1;
        while (hash_val != init && (htable[hash_val]
        == DeletedNode::getNode() || htable[hash_val]
        != NULL && htable[hash_val]->key != key))
        {
          if (init == -1)
            init = hash_val;
          hash_val = HashFunc(hash_val + 1);
        }
        if (htable[hash_val] == NULL || hash_val == init)
          return -1;
        else
          return htable[hash_val]->value;
    }
};

int convertToASCII(string letter)
{
  int a = 1;
  for (int i = 0; i < letter.length(); i++)
  {
    char x = letter.at(i);
    a = a * int(x);
  }
  return a;
}

int main()
{
  //hash<string> hash_fn;
  //int str_hash;

  HashMap hash;
  int key, value,i;
  //int vetChaves[110000];

  string toInteger;
  string toChar;
  int fromString,fromChar;

  ifstream chave ("nomes_1.txt");
  ifstream valor ("valores_1.txt");
  ifstream pesquisa ("chaves_1.txt");
  // Insert on the hash table
  if (valor.is_open() || chave.is_open())
  {
    while (valor.good() || chave.good())
    {
      getline (chave,toInteger);
      getline (valor,toChar);
      fromString = convertToASCII(toInteger);
      if(i<5000) {fromChar = stoi(toChar,nullptr,10); i++;} // XUNXO NA CARA DURA, NO SHAME AT ALL, sem isso da um erro inexxxplicável
      //cout << toChar << endl;
      //cout << fromChar << endl;
      key = fromString;
      value = fromChar;
      hash.Insert(key,value);
      //hash.Search(key);
    }
    chave.close();
    valor.close();
  }
  else
	{
		cout << "Deu para abrir nao champz" << endl << endl;
	}

  //Search in the hash table
  if (pesquisa.is_open())
  {
    while (pesquisa.good())
    {
      getline (pesquisa,toInteger);
      fromString = convertToASCII(toInteger);
      key = fromString;
      //cout << hash.Search(key) << endl;
      hash.Search(key);
    }
    pesquisa.close();
  }
  else
	{
		cout << "Deu para abrir nao champz" << endl << endl;
	}
  return 0;
}
