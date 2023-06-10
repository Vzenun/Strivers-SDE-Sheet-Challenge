#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	if(node==nullptr){
		return nullptr;
	}
	graphNode* ans=new graphNode(node->data);
	queue<pair<graphNode *,graphNode *>> q;
	q.emplace(node,ans);
	map<int,int> mpt;
	map<int,graphNode *> mpt2;
	mpt2[ans->data]=ans;
	while(!q.empty()){
		graphNode * k=q.front().first;
		graphNode * k1=q.front().second;
		q.pop();
		mpt[k->data]=1;
		for(int i=0;i<k->neighbours.size();i++){
			if(mpt[k->neighbours[i]->data]==0){
				mpt[k->neighbours[i]->data]=1;
				graphNode * k2=new graphNode(k->neighbours[i]->data);
				mpt2[k->neighbours[i]->data]=k2;
				k1->neighbours.push_back(k2);
				k2->neighbours.push_back(k1);
				q.emplace(k->neighbours[i],k2);
			}
			else if(mpt[k->neighbours[i]->data]==1){
				k1->neighbours.push_back(mpt2[k->neighbours[i]->data]);
				mpt2[k->neighbours[i]->data]->neighbours.push_back(k1);
			}
		}
		mpt[k->data]=2;
	}
	return ans;
}