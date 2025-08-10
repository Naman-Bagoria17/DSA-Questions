    vector<vector<int>> insert(vector<vector<int>>& inter,
                               vector<int>& newInt) {
        vector<vector<int>> ans;
        if (inter.empty()) {
            ans.push_back(newInt);
            return ans;
        }
        bool pushed = false;
        for (int i = 0; i < inter.size(); i++) {
            if (!pushed) {
                if (inter[i][0] <= newInt[0]) {
                    if (inter[i][1] < newInt[0]) {
                        ans.push_back(inter[i]);
                    } else {
                        newInt[0]=inter[i][0];
                        if(newInt[1]<=inter[i][1]){
                            newInt[1]=inter[i][1];
                        }
                    }
                } else {
                    if (inter[i][0] > newInt[1]) {
                        ans.push_back(newInt);
                        ans.push_back(inter[i]);
                        pushed = true;
                    } else {
                        if (newInt[1] <= inter[i][1]) {
                            newInt[1] = inter[i][1];
                            ans.push_back(newInt);
                            pushed = true;
                        }
                    }
                }
            } else {
                ans.push_back(inter[i]);
            }
        }
        if(!pushed)ans.push_back(newInt);
        return ans;
    }
