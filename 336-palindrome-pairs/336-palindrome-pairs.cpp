//trie node
struct TrieNode
{
    TrieNode* links[26];
    int index;
};


class Trie
{
private:
    //root of the trie
    TrieNode* root;
public:
    //contsructor creates the root while a object is created
    Trie()
    {
        root = getNewNode();
    }
    
    //returns a newnode with all initialized to nulls,
    TrieNode* getNewNode()
    {
        TrieNode* newNode = new TrieNode;
        for(int i=0; i<26; i++)
        {
            newNode->links[i] = NULL;
        }
        newNode->index = -1;
        
        return newNode;
        
    }
    
    //inserting in reverse order, the first letter which will be last element in the trie, will have its index as, its original index in the given array 
    void insert(string s, int ind)
    {
        
        int len = s.size();
        
        TrieNode* tempRoot = root;
        
        for(int i=len-1; i>=0; i--)
        {
            
            if(tempRoot -> links[s[i] - 'a'] == NULL)
            {
                tempRoot -> links[ s[i] - 'a' ] = getNewNode();
            }
            
            tempRoot = tempRoot -> links[s[i] - 'a'];
            
        }
        
        tempRoot -> index = ind;
        
    }
    
    //simple palindrome function 
    bool isPalindrome(string s, int low, int high)
    {
        while(low <= high)
        {
            if(s[low] != s[high])
            {
                return false;
            }
            low++;
            high--;
        }
        return true;
    }
    
    // case 2 check
    void search2ForCase2(TrieNode* root, vector<int> &palindrome, string s)
    {
        
        if(root->index != -1)
        {  
            int low = 0;
            int high = s.size() -1;
            if(isPalindrome(s, low, high))
            {
                palindrome.push_back(root->index);
            }
            
        }
        
        for(int i=0; i<26; i++)
        {
            if(root->links[i] != NULL)
            {
                s.push_back('a' + i);
                search2ForCase2(root->links[i], palindrome, s);
                s.pop_back();
            }
        }
        
        
    }
    
    //casse 1 check
    vector<int> search1ForCase1(string s, vector<int> &palindrome)
    {
    
        
        TrieNode* tempRoot = root;
        
        for(int i=0; i<s.size(); i++)
        {
            if(tempRoot -> index != -1)
            {
                int low = i;
                int high = s.size() -1;
                if(isPalindrome(s, low, high))
                {
                    palindrome.push_back(tempRoot->index);
                }
            }
            
            if(tempRoot -> links[s[i] - 'a'] == NULL)
            {
                return palindrome;
            }
            else
            {
                tempRoot = tempRoot->links[s[i] - 'a'];
        
            }
        }
        
        search2ForCase2(tempRoot, palindrome, "");
        
        return palindrome;
    }
    
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        //object
        Trie trie;
        
        //inserting all words
        int n = words.size();
        for(int i=0; i<n; i++)
        {
            trie.insert(words[i], i);
        }
        
        vector<vector<int>> ans;
        
        //finding palindromes for each word one by one
        for(int i=0; i<n; i++)
        {
            
            vector<int> palindrome;
            trie.search1ForCase1(words[i], palindrome);
            
            //appeding it to the ans, ignoring the self palindrome
            // ["aba"] if this is the only string, then [0,0] will be the output
            //which is not valid, so => (it!=i)
            for(auto it : palindrome)
            {
                if(it != i)
                {
                    ans.push_back({i, it});
                }
            }
            
        }
        
        //return the ans
        return ans;
        
    }
};