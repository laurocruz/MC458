#include "solution.hpp"
#include <vector>
#include <iostream>

void execute_test(const std::vector<int> & input, int L) {
  int ans = solution(input, L);
  std::cout << ans << std::endl;
}

int main(int argc, char ** argv) {
  int N, L;
  std::vector<int> input;
  std::cin >> N >> L;
  input.resize(N);
  for(int i = 0; i < N;i++) {
    std::cin >> input[i];
  }

  execute_test(input, L);
}


