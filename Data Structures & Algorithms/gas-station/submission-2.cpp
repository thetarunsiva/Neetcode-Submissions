class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> x;
        int n = gas.size();
        vector<int> suf(n);

        for(int i=0;i<n;i++){
            x.push_back(gas[i]-cost[i]);
            if (i>=1){
                x[i] += x[i-1];
            }
        }

        int mi = x[n-1];

        for(int i=n-1;i>=0;i--){
            mi = min(mi,x[i]);
            suf[i] = mi;
        }
        mi = x[0];
        if (x[n-1]<0) return -1;

        for(int i=0;i<n;i++){
            
            if (gas[i]-cost[i]<0) {
                mi = min(mi,x[i]);continue;
            }
            int pre = (i==0)?0:x[i-1];
            if (i==n-1 || suf[i]>=pre){
                int ex = x[n-1]-pre;

                if (i==0 || ex>=mi){
                    return i;
                }
            }
            mi = min(mi,x[i]);
        }


    }
};
