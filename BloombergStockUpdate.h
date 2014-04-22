struct compstock{
	bool operator () (const pair<string, int> &a, const pair<string, int> &b)const{
		if (a.second != b.second)
		{
			return a.second > b.second;
		}else{
			return a.first > b.first;
		}
	}
};
class topK{
	typedef set<pair<string, int>, compstock> SET;
	SET s;
	hash_map<string, int> oldVal;
public:
	void update(string name, int val){
		int ov = oldVal[name];
		oldVal[name] = val;

		SET::iterator it = s.find(make_pair(name, ov));
		if (it != s.end()){
			//we found it
			//delete and insert
			s.erase(it);
			s.insert(make_pair(name, val));
		}else{
			//it is a new point, just insert
			s.insert(make_pair(name, val));
		}
	}
	void showTopK(){
		SET::iterator it = s.begin();
		int i = 0;
		while(i < 10 && it != s.end()){
			cout << it->first << " : " << it->second << endl;
			i++;
			it++;
		}
	}
};
