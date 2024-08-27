struct Node {
  Node * links[26];
  int cntEndWith = 0;
  int cntPrefix = 0;

  bool containsKey(char ch) {
    return (links[ch - 'a'] != NULL);
  }
  Node * get(char ch) {
    return links[ch - 'a'];
  }
  void put(char ch, Node * node) {
    links[ch - 'a'] = node;
  }
  void increaseEnd() {
    cntEndWith++;
  }
  void increasePrefix() {
    cntPrefix++;
  }
  void deleteEnd() {
    cntEndWith--;
  }
  void reducePrefix() {
    cntPrefix--;
  }
  int getEnd() {
    return cntEndWith;
  }
  int getPrefix() {
    return cntPrefix;
  }
};
class Trie {
  private:
    Node * root;

  public:
    /** Initialize your data structure here.*/
    Trie() {
      root = new Node();
    }

  /** Inserts a word into the trie.*/
  void insert(string word) {
    Node * node = root;
    for (int i = 0; i < word.length(); i++) {
      if (!node -> containsKey(word[i])) {
        node -> put(word[i], new Node());
      }
      node = node -> get(word[i]);
      node -> increasePrefix();
    }
    node -> increaseEnd();
  }

 int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getEnd();
    }


  int countWordsStartingWith(string & word) {
    Node * node = root;
    for (int i = 0; i < word.length(); i++) {
      if (node -> containsKey(word[i])) {
        node = node -> get(word[i]);
      } else {
        return 0;
      }
    }
    return node -> getPrefix();
  }

  void erase(string & word) {
    Node * node = root;
    for (int i = 0; i < word.length(); i++) {
      if (node -> containsKey(word[i])) {
        node = node -> get(word[i]);
        node -> reducePrefix();
      } else {
        return;
      }
    }
    node -> deleteEnd();
  }
};


/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/

struct Node {
	Node *links[26];
	bool flag = false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
};
class Trie {
private:
	Node* root;
public:
	Trie() {
		//creating new obejct
		root = new Node();
	}

	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}

	bool search(string word) {
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				return false;
			}
			node = node->get(word[i]);
		}
		return node->isEnd();
	}

	bool startsWith(string prefix) {
		Node* node = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (!node->containKey(prefix[i])) {
				return false;
			}
			node = node->get(prefix[i]);
		}
		return true;
	}
};

/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/

struct Node{
    Node *links[2];

    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }
    void put(int bit,Node *node){
        links[bit]=node;
    }
    Node *get(int bit){
        return links[bit];
    }

};
class Trie{
    private:
        Node *root;
    public:
        Trie(){
            root=new Node();
            root->links[0]=root->links[1]=NULL;
        }
        void insert(int num){
            Node *node=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(node->containsKey(bit)){
                    node=node->get(bit);      
                }
                else{
                    node->put(bit,new Node());
                    node=node->get(bit);
                }
            }
        }
        int getMax(int num){
            Node *node=root;
            int ans=0;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(node->containsKey(!bit)){
                    node=node->get(!bit);
                    ans=ans | (1<<i);      
                }
                else{
                    node=node->get(bit);
                }

            }
            return ans;
        }
};

