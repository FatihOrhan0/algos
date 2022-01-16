#include <vector>
#include <iostream>
#include <climits>

//this problem comes from 
//https://leetcode.com/problems/maximize-distance-to-closest-person/

int maxDistToClosest(std::vector<int> & seats) { 
    std::vector<int> distances(seats.size(), -1);
    int curDist = (int) seats.size();
    for (unsigned int i = 0; i < seats.size(); i++) { 
        if (seats[i] == 1) { 
            distances[i] = 0;
            curDist = 0;
        }
        else { 
            distances[i] = curDist;
        }
        curDist++;
    }
    //show the unsigned int behavior bug here.
    curDist = seats.size();
    for (int i = seats.size() - 1; i >= 0; i--) {
        if (distances[i] >= curDist) { 
            distances[i] = curDist;
        }
        else { 
            curDist = distances[i];
        }
        curDist++;
    }
    int max = 0;
    for (unsigned int i = 0; i < seats.size(); i++) { 
        if (distances[i] > max) { 
            max = distances[i];
        }
    }
    return max;
}

int main() { 
    std::vector<int> seats = {1,0,0,0,1,0,1};
    std::cout << maxDistToClosest(seats);
    return 1;
}