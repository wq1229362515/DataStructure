/*ɾ�������е��ڸ���ֵ val �����нڵ㡣

ʾ��:

����: 1->2->6->3->4->5->6, val = 6
���: 1->2->3->4->5
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode * Node;
    struct ListNode * Temp;
    if(!head){
        return head;
    }
    Temp = head;
    Node = head;
    if( !(head->next)  && head->val == val) {
        Temp = Temp->next;
        free(head);
        head = Temp;
        return head;
    }
    while(Node){
        if(Temp->val == val) {
            Node = Node->next;
            free(Temp);
            head = Temp = Node;
        }
        else if(Node->val == val){
            Temp->next = Node->next;
            free(Node);
            Node = Temp->next;
        }
        else {
         Temp = Node;
         Node = Node->next;
        }   
    }
    return head;
}

//��ת����
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){ 
    struct ListNode* preNode  = NULL;
    struct ListNode* NextNode = NULL;
    struct ListNode* TempNode = NULL;
    if(head == NULL || head->next == NULL) {
        return head;
    }
    TempNode = head;
    while(TempNode) {
        NextNode = TempNode->next;
        TempNode->next = preNode;
        preNode = TempNode;
        TempNode = NextNode;
    }
    return preNode;
}


//����һ������ͷ��� head �ķǿյ���������������м��㡣

//����������м��㣬�򷵻صڶ����м��㡣
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode * FastNode = NULL;
    struct ListNode * SlowNode = NULL;
    if(head == NULL) {
        return head;
    }
    FastNode = head;
    SlowNode = head;
    while(FastNode != NULL && FastNode->next != NULL) {
        SlowNode = SlowNode->next;
        FastNode = FastNode->next->next;     
    }
    return SlowNode;
}
    
//����һ����������������е�����k����㡣    
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
         ListNode *FastNode = NULL;
         ListNode *SlowNode = NULL;
        if(pListHead == NULL || k == 0) {
            return NULL;
        }
        SlowNode = pListHead;
        FastNode = pListHead;
        for(int i = 1;i<=(k-1) && k>1 ;i++){
                if(FastNode ->next){
                    FastNode = FastNode->next;
                }
                else 
                    return NULL;
            }
        while(FastNode->next) {
            FastNode = FastNode->next;
            SlowNode = SlowNode->next;
        }
        return SlowNode;
    }
};

/*��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ� 

ʾ����

���룺1->2->4, 1->3->4
�����1->1->2->3->4->4
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
   /* if(l1 == NULL) {
        return l2;
    }
    if(l2 == NULL) {
        return l1;
    }
    struct ListNode *l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p  = l3;
    while(l1 && l2) {   
        if(l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;    
        }
        else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    p->next = (l1 == NULL)?l2:l1;
    return l3->next;
    */
    
    if(l1 == NULL) {
        return l2;
    }
    if(l2 == NULL) {
        return l1;
    }
    if(l1->val <= l2->val) {
        l1 ->next = mergeTwoLists(l1->next,l2);
        return l1;
    }else {
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
    
}


/*��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ

����һ�������ͷָ�� ListNode* pHead���뷵���������к�������ͷָ�롣ע�⣺�ָ��Ժ󱣳�ԭ��������˳�򲻱䡣
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        if(pHead == NULL) {
            return NULL;
        }
        if(pHead->next == NULL) {
            return pHead;
        }
        ListNode* pSmollNode = new ListNode (0);
        ListNode* pBigNode = new ListNode (0);
        ListNode* SmollHead = pSmollNode,*BigHead = pBigNode;
        while(pHead) {
            if(pHead->val < x){
                pSmollNode->next = pHead;
                pSmollNode = pSmollNode->next;
            }
            else {
                pBigNode ->next = pHead;
                pBigNode = pBigNode->next;
            }
            pHead = pHead->next;
        }
        pBigNode->next = NULL;
        pSmollNode->next = BigHead->next;
        return pHead = SmollHead->next;;
    }
};

/*��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead){
        if(pHead == NULL || pHead->next == NULL) {
           return pHead;
        }
        ListNode *NewNode = (ListNode *)malloc(sizeof(ListNode));
        NewNode->next = pHead;
        ListNode *pre = NewNode;
        ListNode *Node = pHead;
        ListNode *NextNode = NULL;
        while(Node && Node->next) {
            NextNode = Node->next;
            if(Node->val == NextNode->val){
                while(NextNode && NextNode->val == Node->val) {
                    NextNode = NextNode->next;
                }
                    pre->next = NextNode;
                    Node = NextNode;
            }
            else {
                pre = Node;
                Node = Node->next;
            }
        }
        return NewNode->next;
    }
};


/*����һ�����������һ��ʱ�临�Ӷ�ΪO(n),����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��
����������
 1->2->2->1
*/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* pHead) {
        if(pHead == NULL || pHead->next == NULL) {
            return false;
        }
            int i;
    int start,end;
    int *p = (int*)malloc(999*sizeof(int));
    for(i = 0;;i++) {
        p[i] = pHead->val;
        pHead = pHead->next;
        if(pHead == NULL) {
            break;
        }
    }
    end = i;
    int len = i+1;
    for(start = 0;start<len/2;start++,end--) {
        if(p[start] == p[end]){
            continue;
        }
        else {
            return false;
        }
    }
    return true;
    }
};


//��дһ�������ҵ������������ཻ����ʼ�ڵ㡣

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *Apcur = NULL;
    struct ListNode *Bpcur = NULL;
    if(headA == NULL || headB == NULL) {
        return NULL;
    }
    int Alen = 0;
    int Blen = 0;
    int len;
    Apcur = headA;
    Bpcur = headB;
    while(Apcur) {
        Apcur = Apcur->next;
        Alen++;
    }
    while(Bpcur) {
        Bpcur = Bpcur->next;
        Blen++;
    }
    Apcur = headA;
    Bpcur = headB;
    if(Alen>Blen) {
        len = Alen-Blen;
        while(len--) {
            Apcur = Apcur->next;            
        }
    }
    else { 
        len = Blen-Alen;
        while(len--) {
            Bpcur = Bpcur->next;
        }
    }
    
    
    while(Apcur && Bpcur) {
        if(Apcur == Bpcur) {
            return Apcur;
        }
        else {
            Apcur = Apcur->next;
            Bpcur = Bpcur->next;
        }
    }
    return NULL;
}