struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* fast = NULL;//单链表头指针
    struct ListNode* last = NULL;//单链表尾指针
    int sum = 0;//本位和
    int cf = 0;//进位
    while (l1 != NULL || l2 != NULL)
    {
        if (l1 == NULL)//某一个链表遍历完的情况
        {
            sum = l2->val + cf;
            l2 = l2->next;
        }
        else if (l2 == NULL)//同上
        {
            sum = l1->val + cf;
            l1 = l1->next;
        }
        else//正常情况
        {
            sum = l1->val + l2->val + cf;
            l1 = l1->next;
            l2 = l2->next;
        }

        struct ListNode* sb = (struct ListNode*)malloc(sizeof(struct ListNode));//申请空间     
        sb->val = sum % 10;
        sb->next = NULL;
        cf = sum / 10;

        if (fast == NULL)
        {
            fast = sb;
            last = sb;
        }
        else
        {
            last->next = sb;
            last = sb;
        }

        if (l1 == NULL && l2 == NULL && cf != 0)//l1和l2都已经遍历完，eg：99+9  百位仍有进位的特殊情况
        {
            struct ListNode* sb = (struct ListNode*)malloc(sizeof(struct ListNode));
            sb->val = cf;
            sb->next = NULL;
            last->next = sb;
            last = sb;
        }
    }
    return fast;
}