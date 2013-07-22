/*
 接近O(n^2log(n))版本,不过常熟太大 1600ms
 */
class Solution {
    static bool myCmp(const vector<int>&l,const vector<int> &r) {
        return l[0] < r[0];
    }
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        vector<vector<int> > twoTuples;
        sort(num.begin() , num.end());
        int n = num.size();
        for (int i = 0 ; i < n ; i ++) {
            if (i && num[i] == num[i-1]) {
                continue;
            }
            for (int j = i + 1 ; j < n ; j ++) {
                if (j != i + 1 && num[j] == num[j-1]) {
                    continue;
                }
                twoTuples.push_back({num[i]+num[j],i,j});
            }
        }
        sort(twoTuples.begin(), twoTuples.end() , myCmp);
        vector<int> tar(3,0);
        vector<vector<int>>::iterator lo , hi = twoTuples.end();
        for (int i = n - 1 ; i >= 0 ; i --) {
            if (i != n - 1 && num[i] == num[i+1]) {
                continue;
            }
            for (int j = i - 1 ; j >= 0 ; j --) {
                if (j != i - 1 && num[j] == num[j+1]) {
                    continue;
                }
                tar[0] = target - num[i] - num[j];
                lo = lower_bound(twoTuples.begin() , twoTuples.end() , tar , myCmp);
                hi = upper_bound(lo , twoTuples.end() , tar , myCmp);
                for (; lo != hi ; lo ++) {
                    if ((*lo)[2] < j) {
                        ret.push_back(vector<int>({num[(*lo)[1]] , num[(*lo)[2]] , num[j] , num[i]}));
                    }
                }
            }
        }
        return ret;
    }
};
/*
 O(n^3)版本 256ms
 */
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        sort(num.begin() , num.end());
        int n = num.size();
        for (int i = 0 ; i < n ; i ++) {
            if (i && num[i] == num[i-1]) {
                continue;
            }
            for (int j = i + 1 ; j < n ; j ++) {
                if (j != i + 1 && num[j] == num[j-1]) {
                    continue;
                }
                int lo = j + 1;
                int hi = n - 1;
                while (lo < hi) {
                    int sum = num[i] + num[j] + num[lo] + num[hi];
                    if (target > sum) {
                        lo ++;
                    } else if (target == sum) {
                        ret.push_back({num[i] , num[j] , num[lo] , num[hi]});
                        do {
                            lo ++;
                        } while (lo < hi && num[lo] == num[lo-1]);
                        do {
                            hi --;
                        } while (lo < hi && num[hi] == num[hi+1]);
                    } else {
                        hi --;
                    }
                }
            }
        }
        return ret;
    }
};