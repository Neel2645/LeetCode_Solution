//* Question :- Single Element in a Sorted Array


//! Method - 1
//? Time Complexity =   O(n)
//? Space Complexity =   O(n)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        map<int,int>::iterator itr = mp.begin();
        while(itr != mp.end())
        {
            if(itr->second == 1) return itr->first;
            itr++;
        }
        return -1;
    }
};



//! Method - 2
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n-1;i++)
        {
            if(nums[i] != nums[i+1]) return nums[i];

            else i++;
        }
        return nums[n-1];
    }
};



//! Method - 3
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for(int &ele : nums)
        {
            ans = ans ^ ele;
        }

        return ans;
    }
};


//! Method - 4
//? Time Complexity =   O(n)
//? Space Complexity =   O(1)


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        for(int i=1;i<(n-1);i++)
        {
            if((nums[i] != nums[i+1]) and (nums[i] != nums[i-1]))
            return nums[i];
        }

        return -1; // dummy value
    }
};


//! Method - 5
//? Time Complexity =   O(log n)
//? Space Complexity =   O(1)


class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int st = 0;
        int end = n-1;

        while(st < end)
        {
            int mid = (st + end)/2;

            bool isEven;
            if((end-mid)%2 == 0) isEven = true;
            else isEven = false;

            if(arr[mid] == arr[mid+1])
            {
                if(isEven)
                {
                    st = mid + 2;
                }
                else end = mid - 1;
            }

            else
            {
                if(isEven)
                {
                    end = mid;
                }
                else
                {
                    st = mid + 1;
                }
            }
        }

        return arr[st];
    }
};


//! Method - 6
//? Time Complexity =   O(log n)
//? Space Complexity =   O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();

        if(n==1) return arr[0];
        if(arr[0] != arr[1]) return arr[0];
        if(arr[n-1] != arr[n-2]) return arr[n-1];

        int st = 1;
        int end = n-2;

        while(st <= end)
        {
            int mid = (st+end)/2;

            if((arr[mid] != arr[mid+1]) and (arr[mid] != arr[mid-1]))
            return arr[mid];

            if((mid%2==0) and (arr[mid] == arr[mid-1])) end = mid - 2;
            else if((mid%2==0) and (arr[mid] == arr[mid+1])) st = mid + 2;
            else if((mid%2!=0) and (arr[mid] == arr[mid+1])) end = mid - 1;
            else st = mid + 1;
        }
        return -1; // dummy value
    }
};