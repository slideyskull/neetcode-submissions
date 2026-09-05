struct ListNode {
    int val;
    ListNode* next;

    ListNode(int given) {
        val = given;
        next = nullptr;
    }
};

class LinkedList {
public:
    LinkedList() :
        size_{0}, head{nullptr} {}

    int get(int index) {
        if (index >= size_) {
            return -1;
        }
        auto curr = head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }

        return curr->val;
    }

    void insertHead(int val) {
        auto insert = new ListNode(val);
        insert->next = head;
        head = insert;
        ++size_;
    }
    
    void insertTail(int val) {
        auto insert = new ListNode(val);
        auto curr = head;
        if (curr == nullptr) {
            head = insert;
        } else {
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = insert;
        }
        ++size_;
    }

    bool remove(int index) {
        if (index >= size_) {
            return false;
        }
        --size_;
        if (index == 0) {
            head = head->next;
            return true;
        }

        auto prev = head;
        auto curr = head;
        for (int i = 0; i < index; ++i) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        return true;
    }

    vector<int> getValues() {
        vector<int> res;
        auto curr = head;
        while (curr != nullptr) {
            res.push_back(curr->val);
            curr = curr->next;
        }

        return res;
    }

private:
    int size_;
    ListNode* head;
};
