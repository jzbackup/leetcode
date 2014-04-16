template<class typea, class typeb>
class MyHash{
	pair<typea, typeb> *p;
	bool * exist;
	static const int HASHSIZE = 52;
public:
	MyHash(){
		p = new pair<typea, typeb>[HASHSIZE];
		memset(p, 0, HASHSIZE);
		exist = new bool[HASHSIZE];
		memset(exist, false, HASHSIZE);
	}
	~MyHash(){
		delete [] p;	//用 new [] 生成的内存，用delete [] 删除
		delete [] exist;
	}
	bool cmp(typea a, typeb b){
		return true;
	}
	unsigned hash(typea a){
		stringstream ss;
		ss << a;
		string s = ss.str();
		unsigned val = 0;
		for(int i = 0; i < s.size(); i ++){
			val = val*31 + s[i];
		}
		return val%HASHSIZE;
	}
	//要返回引用才能作为左值被赋值
	typeb& operator[](typea a){
		unsigned key = hash(a);
		unsigned probe = key;
		while(exist[probe]){
			if(p[probe].first == a){
				return p[probe].second;
			}else{
				probe ++;
			}
			if(probe == key)break;	//使用顺延法，回头了就说明找了一圈都没找到，没有
		}
		//到这里说明该元素还不存在
		//1. 开始就不存在
		//2. 存在，但是不相同，往下找，找到一个空格，判定不存在
		//3. 找了一圈回头了，判定不存在
		//不存在则建立
		p[probe] = make_pair(a, 1);
		exist[probe] = true;
		return p[probe].second;
	}
};
