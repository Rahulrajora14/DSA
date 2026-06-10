#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &endd) {

        int n = start.size();

        sort(start.begin(), start.end());
        sort(endd.begin(), endd.end());

        int i = 0, j = 0;
        int rooms = 0;
        int maxRooms = 0;

        while(i < n) {

            if(start[i] < endd[j]) {
                rooms++;
                maxRooms = max(maxRooms, rooms);
                i++;
            }
            else {
                rooms--;
                j++;
            }
        }

        return maxRooms;
    }
};

int main() {

    vector<int> start = {1, 2, 3, 4};
    vector<int> endd  = {10, 2, 6, 14};

    Solution obj;

    cout << "Minimum Meeting Rooms Required = "
         << obj.minMeetingRooms(start, endd);

    return 0;
}