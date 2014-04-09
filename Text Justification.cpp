class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> rlt;
		vector<string>::iterator it = words.begin();
        while(it != words.end()){
            string line(*(it++));
			vector<int> pos;
            while(it != words.end() && line.size() + 1 + it->size() <= L){
				pos.push_back(line.size());
                line += " " + *(it++);
            }
            int moreSpaces = L - line.size();
			if(moreSpaces && (it != words.end())){
				if(pos.size() == 0){
					//only one word, but need to stuff 0s.
					line.insert(line.size(), string(L - line.size(), ' '));
				}else{
					int base = moreSpaces/pos.size();
					int more = moreSpaces%pos.size();
					int i = pos.size();
					while(--i >= 0){
						if(i >= more)
							line.insert(pos[i], string(base, ' '));
						else
							line.insert(pos[i], string(base+1, ' '));
					}
				}
			}
            
            rlt.push_back(line);
        }
        rlt.back() += string(L-rlt.back().size(), ' ');
        return rlt;
    }
};
