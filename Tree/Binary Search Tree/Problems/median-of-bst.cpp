// https://practice.geeksforgeeks.org/problems/median-of-bst/1

int getCount(struct Node *root) {
    int count = 0;
    Node* curr = root;
    while (curr) {
        if (curr->left == NULL) {
            count++;
            curr = curr->right;
        } else {
            // find inorder predecessor
            Node* pre = curr->left;
            while (pre->right && pre->right != curr) {
                pre = pre->right;
            }

            if (pre->right == NULL) {
                pre->right = curr;
                curr = curr->left;
            } else {
                pre->right = NULL;
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}

float findMedian(struct Node *root) {
    int count = getCount(root);
    int c = 0;
    int odd1 = (count + 1) / 2, odd1Val = -1;
    int even1 = count / 2, even1Val = -1;
    int even2 = count / 2 + 1, even2Val = -1;
    Node* curr = root;
    while (curr) {
        if (curr->left == NULL) {
            c++;
            if (c == odd1) odd1Val = curr->data;
            if (c == even1) even1Val = curr->data;
            if (c == even2) even2Val = curr->data;
            curr = curr->right;
        } else {
            // find inorder predecessor
            Node* pre = curr->left;
            while (pre->right && pre->right != curr) {
                pre = pre->right;
            }

            if (pre->right == NULL) {
                pre->right = curr;
                curr = curr->left;
            } else {
                pre->right = NULL;
                c++;
                if (c == odd1) odd1Val = curr->data;
                if (c == even1) even1Val = curr->data;
                if (c == even2) even2Val = curr->data;
                curr = curr->right;
            }
        }
    }

    float median = 0;
    if (count & 1) {
        return (float)odd1Val;
    } else {
        median = (float)(even1Val + even2Val) / 2.0f;
        return median;
    }
}
