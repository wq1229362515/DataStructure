#pragma  once 
typedef int Datatype;


typedef struct sqlistNode {

	struct sqlistNode *Next;
	Datatype data;

}sqlistNode,*sqlist_Head;



void sqlistNode_init(sqlist_Head *Head);

void sqlistNode_popBack(sqlist_Head *Head,Datatype data);
void sqlistNode_pushBack(sqlist_Head *Head);
void sqlistNode_popFront(sqlist_Head *Head,Datatype data);
void sqlistNode_pushFront(sqlist_Head *Head);
sqlistNode * sqlistNodeFind(sqlist_Head *Head,Datatype data);
void sqlistNode_Dele_Node(sqlist_Head *Head,sqlistNode* pos);

void sqlistNode_insert_Node(sqlistNode *pos,Datatype data);
void sqlistNoderemoveallNode(sqlist_Head *Head,Datatype data);

void sqlistClear(sqlist_Head *Head);
void sqlistDestroy(sqlist_Head *Head);