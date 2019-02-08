#pragma once

#include <assert.h>
#include <stdlib.h>


typedef int	Key;

typedef enum {
	EMPTY,	// �յ�
	EXIST,	// �����ݵ�
	DELETED	// ��ɾ����
}	State;

typedef struct Element {
	Key	key;
	State	state;
}	Element;

typedef int (*HashFuncType)(Key key, int capacity);

typedef struct HashTable {
	Element *table;
	int	size;		// ���ݸ���
	int	capacity;	// ����
	HashFuncType hashFunc;		// ��ϣ����
}	HashTable;

//��ʼ�� ����
void  HashInit(HashTable* pHT, int capacity, HashFuncType hashFunc)
{
     int  i = 0;
	pHT->table = (Element*)malloc(sizeof(Element)*capacity);
	assert(pHT->table);
	pHT->size = 0;
	pHT->capacity = capacity;
	pHT->hashFunc = hashFunc;
     
	for(i=0; i<capacity; i++)
	{
		pHT->table[i].state = EMPTY;
	}
}

void HashDestroy(HashTable* pHT)
{
	free(pHT->table);
}

//����


int  HashSearch(HashTable* pHT, Key key)
{
	int index = pHT->hashFunc(key, pHT->capacity);
		while(pHT->table[index].state!= EMPTY)
		{
			if(pHT->table[index].key ==key )
			{
				return index;
			}

			index = (index+1)%pHT->capacity;
		}

		return -1;
}
//����
int HashInsert(HashTable* pHT, Key key);
void ExpandIfRequired(HashTable* pHT)
{
	
	HashTable newHT;
	int i = 0;
	//������
	if(pHT->size*10 /pHT->capacity <7)
	{
		return ;
	}
	HashInit(&newHT, pHT->capacity*2, pHT->hashFunc);
    
	for(i=0; i<pHT->capacity; i++)
	{
		if(pHT->table[i].state ==EXIST)
		{
           HashInsert(&newHT, pHT->table[i].key);
		   
		}
	}
	free(pHT->table);
	pHT->table = newHT.table;
	pHT->capacity = newHT.capacity;

}
//ɾ��

int HashRemove(HashTable* pHT, Key key)
{
	int index = pHT->hashFunc(key, pHT->capacity);
	while(pHT->table[index].state!=EMPTY)
	{
		if(pHT->table[index].key == key)
		{
			pHT->table[index].state = DELETED;
			return  0;
		}
		index = (index+1)%pHT->capacity;
	}
	return -1;
}

//����
int HashInsert(HashTable* pHT, Key key)
{
	
	int index =0;
	ExpandIfRequired(pHT);

	index = pHT->hashFunc(key, pHT->capacity);
	while(1)
	{
		if(pHT->table[index].key==key
			&& pHT->table[index].state==EXIST)
		{
			return -1;
		}
		if(pHT->table[index].state!=EXIST)
		{
			pHT->table[index].key = key;
			pHT->table[index].state = EXIST;
			pHT->size++;
            
            return 0;
		}
		index = (index+1)%pHT->capacity;
	}
	
}

//��ϣ����
int mod (Key key, int capacity )
{
	return key% capacity;
}

void Test()
{
	HashTable ht;
	HashInit(&ht, 10, mod);

	HashInsert(&ht, 1);
	HashInsert(&ht, 11);
	HashInsert(&ht, 21);
	HashInsert(&ht, 31);
	HashInsert(&ht, 41);
	HashInsert(&ht, 51);
	HashInsert(&ht, 61);
	HashInsert(&ht, 71);
	HashInsert(&ht, 81);

	HashDestroy(&ht);
}