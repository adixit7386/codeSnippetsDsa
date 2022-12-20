#include <bits/stdc++.h>
using namespace std;

class Trie
{
public:
    Trie *children[26];
    bool isEnd;

    Trie()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }

    void insert(string s, Trie *root)
    {
        Trie *curr = root;

        int n = s.length();
        for (auto ch : s)
        {
            int index = ch - 'a';
            if (curr->children[index] == NULL)
            {
                curr->children[index] = new Trie();
            }

            curr = curr->children[index];
        }
        curr->isEnd = true;
    }

    bool search(string s, Trie *root)
    {
        Trie *curr = root;

        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            int index = s[i] - 'a';

            if (curr->children[index] == NULL)
            {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->isEnd;
    }
    bool isEmpty(Trie *root)
    {
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                return false;
            }
        }
        return true;
    }
    Trie *deleteKey(string s, Trie *root, int i)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (i == s.length())
        {
            root->isEnd = false;

            if (isEmpty(root) == true)
            {
                delete (root);
                root = NULL;
            }
            return root;
        }
        int index = s[i] - 'a';
        root->children[index] = deleteKey(s, root->children[index], i + 1);

        if (root->isEnd == false && isEmpty(root) == true)
        {
            delete (root);
            root = NULL;
        }
        return root;
    }
};

int main()
{
    Trie *root = new Trie();
    string s;
    cin >> s;
    root->insert(s, root);
    root->insert("what", root);
    cout << root->search(s, root);
    cout << endl;
    root = root->deleteKey(s, root, 0);

    cout << root->search(s, root);
    return 0;
}