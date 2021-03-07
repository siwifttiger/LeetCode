class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sum = 0;
        int winMax = 0;
        int winSum = 0;
        for(int i=0; i<X; i++){
            sum += (1-grumpy[i])*customers[i];
            winSum += grumpy[i]*customers[i];
        }
        winMax = winSum;
        for (int i = X; i <customers.size() ; ++i) {
            sum += (1-grumpy[i])*customers[i];
            winSum = winSum + grumpy[i]*customers[i] - grumpy[i-X]*customers[i-X];
            winMax = max(winSum, winMax);
        }
        return sum+winMax;

    }
};