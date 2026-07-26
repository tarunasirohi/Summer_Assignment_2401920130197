class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
       unordered_map<int,int> mpp;
    
    int st = 0;
    int m = INT_MAX;

    for(int end = 0; end < cards.size(); end++) {
        mpp[cards[end]]++;

        // if duplicate found
        while(mpp[cards[end]] > 1) {
            m = min(m, end - st + 1);

            mpp[cards[st]]--;
            st++;
        }
    }

    return (m == INT_MAX) ? -1 : m;
    }
};