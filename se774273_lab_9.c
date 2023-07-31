#include <stdio.h>
#include <stdlib.h>

// RecordType
struct RecordType
{
    int id;
    char name;
    int order;
};

// Fill out this structure
struct HashNode
{
    struct RecordType data;
    struct HashNode* next;
};

struct HashType
{
    struct HashNode** hashArray;
    int size;
};

// Compute the hash function
int hash(int x, int size)
{
    
    return x % size;
}

// Function to create a new node for the hash table
struct HashNode* createHashNode(struct RecordType data)
{
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a record into the hash table
void insertRecord(struct HashType* hashTable, struct RecordType data)
{
    
    int hashValue = hash(data.id, hashTable->size);

   
    struct HashNode* newNode = createHashNode(data);

    
    if (hashTable->hashArray[hashValue] == NULL)
    {
        hashTable->hashArray[hashValue] = newNode;
    }
    else
    {
      
        struct HashNode* temp = hashTable->hashArray[hashValue];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display the records in the hash table
void displayRecordsInHash(struct HashType* hashTable)
{
    int i=0;

    for(i = 0; i < hashTable->size; i++)
    {
        struct HashNode* temp = hashTable->hashArray[i];
        if (temp == NULL)
        {
            continue;
        }

        printf("Index %d->", i);
        while (temp != NULL)
        {
            printf("%d %c %d -> ", temp->data.id, temp->data.name, temp->data.order);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// parses input file to an integer array
int parseData(char* inputFileName, struct RecordType** ppData)
{
	FILE* inFile = fopen(inputFileName, "r");
	int dataSz = 0;
	int i, n;
	char c;
	struct RecordType *pRecord;
	*ppData = NULL;

	if (inFile)
	{
		fscanf(inFile, "%d\n", &dataSz);
		*ppData = (struct RecordType*) malloc(sizeof(struct RecordType) * dataSz);
		// Implement parse data block
		if (*ppData == NULL)
		{
			printf("Cannot allocate memory\n");
			exit(-1);
		}
		for (i = 0; i < dataSz; ++i)
		{
			pRecord = *ppData + i;
			fscanf(inFile, "%d ", &n);
			pRecord->id = n;
			fscanf(inFile, "%c ", &c);
			pRecord->name = c;
			fscanf(inFile, "%d ", &n);
			pRecord->order = n;
		}

		fclose(inFile);
	}

	return dataSz;
}

// prints the records
void printRecords(struct RecordType pData[], int dataSz)
{
	int i;
	printf("\nRecords:\n");
	for (i = 0; i < dataSz; ++i)
	{
		printf("\t%d %c %d\n", pData[i].id, pData[i].name, pData[i].order);
	}
	printf("\n\n");
}

int main(void)
{
    struct RecordType *pRecords;
	int recordSz = 0;

    recordSz = parseData("input2.txt", &pRecords);
	printRecords(pRecords, recordSz);

    // Create the hash table and initialize it with NULL
    struct HashType hashTable;
    hashTable.size = 31;
    hashTable.hashArray = (struct HashNode**)malloc(sizeof(struct HashNode*) * hashTable.size);
    for (int i = 0; i < hashTable.size; i++)
    {
        hashTable.hashArray[i] = NULL;
    }

    
    for (int i = 0; i < recordSz; i++)
    {
        insertRecord(&hashTable, pRecords[i]);
    }

    
    displayRecordsInHash(&hashTable);

    

    return 0;
}