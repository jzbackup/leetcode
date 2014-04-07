struct DNode{
	int key;
	int value;
	DNode * left;
	DNode * right;
	DNode(int key, int value):key(key),value(value), left(NULL), right(NULL){}
};

class LRUCache{
	int capacity;
	int size;
	unordered_map<int, DNode *> keyToNode;
	DNode * head, * tail;
public:
	LRUCache(int cap) {
		capacity = cap;
		size = 0;
	}
	void moveToHead(DNode * toMove){
		if(toMove == head)return;
		if(toMove == tail){
			tail = toMove->left;
			if(tail)tail->right = NULL;
		}else{
			//unlink this node
			if(toMove->left)
				toMove->left->right = toMove->right;
			if(toMove->right)
				toMove->right->left = toMove->left;
		}
		//add it to the head
		toMove->right = head;
		head->left = toMove;
		head = toMove;
	}
	int get(int key) {
		if(keyToNode.find(key) != keyToNode.end()){
			int rlt = keyToNode[key]->value;
			moveToHead(keyToNode[key]);
			return rlt;
		}else{
			return -1;
		}
	}

	void set(int key, int value) {
		if(keyToNode.find(key) != keyToNode.end()){
			//update
			keyToNode[key]->value = value;
			moveToHead(keyToNode[key]);
		}else{
			//add
			add(key, value);
		}
	}
	void add(int key, int value){
		DNode * newNode = new DNode(key, value);
		keyToNode[key] = newNode;
		if(size == 0){
			head = newNode;
			tail = newNode;
		}else{
			if(size == capacity){
				//remove tail from the hashmap
				keyToNode.erase(tail->key);
				DNode * temp = tail;
				//remove the tail
				tail = tail->left;
				if(tail)tail->right = NULL;
				delete temp;
				size --;
			}
			newNode->right = head;
			head->left = newNode;
			head = newNode;
		}
		size++;        
	}
};
