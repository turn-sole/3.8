struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* fast = NULL;//������ͷָ��
    struct ListNode* last = NULL;//������βָ��
    int sum = 0;//��λ��
    int cf = 0;//��λ
    while (l1 != NULL || l2 != NULL)
    {
        if (l1 == NULL)//ĳһ���������������
        {
            sum = l2->val + cf;
            l2 = l2->next;
        }
        else if (l2 == NULL)//ͬ��
        {
            sum = l1->val + cf;
            l1 = l1->next;
        }
        else//�������
        {
            sum = l1->val + l2->val + cf;
            l1 = l1->next;
            l2 = l2->next;
        }

        struct ListNode* sb = (struct ListNode*)malloc(sizeof(struct ListNode));//����ռ�     
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

        if (l1 == NULL && l2 == NULL && cf != 0)//l1��l2���Ѿ������꣬eg��99+9  ��λ���н�λ���������
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