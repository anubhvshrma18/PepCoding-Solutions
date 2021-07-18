#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {
    void downheapify(int idx){
		int midx=idx;
		int lci=idx*2+1;
		int rci=idx*2+2;
		if(lci<data.size() && data[midx]>data[lci]){
			midx=lci;
		}
		if(rci<data.size() && data[midx]>data[rci]){
			midx=rci;
		}
		if(midx!=idx){
			swap(data[idx],data[midx]);
			downheapify(midx);
		}
	}
	void upheapify(int idx){
		// int idx=data.size()-1;
    	while(idx>0){
    		if(data[idx]>data[(idx-1)/2]){
    			break;
    		}
    		else{
    			swap(data[idx],data[(idx-1)/2]);
    		}
    		idx=(idx-1)/2;
    	}
	}
    public:
    	vector<int> data;

    PriorityQueue() {
      data.clear();
    }
    
    void add(int val) {
      // write your code here
    	data.push_back(val);
    	int idx=data.size()-1;
    	upheapify(idx);
    }

    int remove() {
        if(data.size()==0){
            cout << "Underflow" << endl;
            return -1;
        }
        int y=data[0];
        swap(data[0],data[data.size()-1]);
        data.pop_back();
    	downheapify(0);
    	return y;

    }

    int peek() {
      // write your code here
    	if(data.size()==0){
    		cout << "Underflow" << endl;
    		return -1;
    	}
    	return data[0];
    }

    int size() {
      // write your code here
    	return data.size();
    }
};

int main()
{
	PriorityQueue pq;
	string s;
	cin >> s;
	while(s!="quit"){
		if(s=="add"){
			int val;
			cin >> val;
			pq.add(val);
		}
		else if(s=="remove"){
			int x=pq.remove();
			if(x!=-1){
				cout << x << endl;
			}
		}
		else if(s=="peek"){
			int x=pq.peek();
			if(x!=-1){
				cout << x << endl;
			}
		}
		else if(s=="size"){
			cout << pq.size() << endl;
		}
		cin >> s;

	}
	return 0;
}