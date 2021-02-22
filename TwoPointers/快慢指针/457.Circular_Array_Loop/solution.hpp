class Solution
{
public:
    bool circularArrayLoop(vector<int> &nums)
    {
        int n = nums.size();
        int i, j, k, next, tmp;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                continue;
            }
            j = i;
            k = i;
            for (;;)
            {
                next = ((j + nums[j]) % n + n) % n;
                // 陷入长度为1的环、陷入0、方向不一致，break，并将该路径置0
                if (next == j || (nums[j] * nums[next] <= 0))
                {
                    while (i != j)
                    {
                        tmp = i;
                        i = ((i + nums[i]) % n + n) % n;
                        nums[tmp] = 0;
                    }
                    nums[j] = 0;
                    break;
                }
                j = next;
                tmp = ((k + nums[k]) % n + n) % n;
                next = ((tmp + nums[tmp]) % n + n) % n;
                 // 陷入0、方向不一致，break，并将该路径置0
                if (nums[next] * nums[k] <= 0 || nums[tmp] * nums[k] <= 0)
                {
                    while (i != k)
                    {
                        tmp = i;
                        i = ((i + nums[i]) % n + n) % n;
                        nums[tmp] = 0;
                    }
                    nums[k] = 0;
                    break;
                }
                k = next;
                if (j == k)
                {
                    if (j == ((j + nums[j]) % n + n) % n)
                    {
                        break;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};