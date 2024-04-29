#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm> 
#include <unordered_map>

std::unordered_map<int, std::unordered_map<std::string, int>> memo; 

int dp(int prev, std::string used) {
  bool allUsed = true; 
  for (char c : used) { 
    if (c == '0') { 
      allUsed = false; 
      break; 
    }
  }
  if (allUsed) return 1; 
  if (memo.contains(prev) && memo[prev].contains(used)) return memo[prev][used];
  int ans = 0; 
  for (int i = 1; i < 16; i++) { 
    if (used[i - 1] == '0') { 
      std::string temp = used; 
      temp[i - 1] = '1';
      if (i >= prev) { 
        ans = std::max(ans, (i - prev) * dp(i, temp));
      }
      else { 
        ans = std::max(ans, dp(i, temp) / i);
      }
    }
  }
  memo[prev][used] = ans; 
  return ans;
} 

int main() { 
  std::string used(15, '0');
  std::cout << dp(0, used) << std::endl;
}