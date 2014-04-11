class iota{
public:
	void test(){
		int x[] = {1,10,6,5,10,7,5,2};
		int rlt = solution(vector<int>(x,x+sizeof(x)/sizeof(x[0])));
	}
	int solution(const vector<int> &A) {
		// write your code in C++98
		if(A.size() <= 2)return A.size();
		if(A[0] == A.back())return 1;

		map<int, set<int>> m;
		vector<int>::const_iterator it = A.begin();

		m[*it].insert(*(it+1));
		it++;
		while(it != A.end()-1){
			m[*it].insert(*(it-1));
			m[*it].insert(*(it+1));
			it++;
		}
		m[*it].insert(*(it-1));

		queue<int> Q, P;
		Q.push(A[0]);
		int level = 1;
		set<int> visited;
		visited.insert(A[0]);	//whenever enter queue, enter visited
		while(!Q.empty()){
			int cur = Q.front();
			Q.pop();
			
			if(cur == A.back()) 
				return level;

			set<int> neighbors = m[cur];
			set<int>:: iterator t = neighbors.begin();
			while (t != neighbors.end())
			{
				if(visited.count(*t) == 0){
					P.push(*t);
					visited.insert(*t);
				}
				t++;
			}

			if(Q.empty()){
				level ++;
				swap(Q,P);
			}
		}
		return level;
	}
};
