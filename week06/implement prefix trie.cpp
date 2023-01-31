class Trie
{
private:
    class TrieNode
    {
        public:
        const static int LIM = 26;
        bool isEnd;
        shared_ptr<TrieNode> next[LIM];
        TrieNode()
        {
            isEnd = false;
            for(int i=0; i<LIM; i++)
            {
                next[i] = nullptr;
            }
        }
};

public:
shared_ptr<TrieNode> root;
Trie()
{
    root = make_shared<TrieNode>();
}

void insert(string word)
{
    auto currNode = root;
    for(auto &ch:word)
    {
        int index = ch-'a';
        if(currNode ->next[index] ==nullptr)
        {
            currNode->next[index] = make_shared<TrieNode>();
        }
        currNode = currNode->next[index];
    }
    currNode ->isEnd = true;
}

bool search(string word, bool isPrefix = false)
{
    auto currNode = root;
    for (auto &ch:word)
    {
        int index = ch-'a';
        if(currNode->next[index] == nullptr)
        {
            return false;
        }
        currNode = currNode->next[index];
    }
    return isPrefix || currNode->isEnd;
}

bool startsWith (string prefix)
{
    return search(prefix, true);
}
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
