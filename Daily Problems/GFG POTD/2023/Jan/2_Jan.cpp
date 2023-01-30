Maximum Value

class Solution {
  public:
    void dfs (Node* node, int level, vector<int>& res){ 
        if(!node) 
        	return;
        	
        if(res.size() == level){
        	res.push_back(node->data);
        }
        else{
        	res[level] = max(res[level], node->data);
        }
        
        dfs(node->left, level+1, res); 
        dfs(node->right, level+1, res);
    }

    vector<int> maximumValue (Node* node) {
    	vector<int> res;
    	dfs(node, 0, res);
    	return res;
    }
};