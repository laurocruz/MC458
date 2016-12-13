#include "solution.hpp"
#include <vector>
#include <iostream>

//estrutura Time definida no solution.hpp

//calcula o tempo total dos atletas dada a ordem de partida
int verify(const std::vector<Time> & input, const std::vector<int> & order) {
  int acc_swimming_time = 0;
  vector<int> used(input.size());
  int max_time = 0;
  for(int i = 0; i < input.size(); i++) {
    used[order[i]]++;
    int cur = acc_swimming_time + input[order[i]].s + input[order[i]].p + input[order[i]].c;
    max_time = std::max(cur, max_time);
    acc_swimming_time += input[order[i]].s;
  }
  for(int i = 0; i < used.size(); i++)
    if(used[i] != 1)
      return -1;
  return max_time;
}
void execute_test(const std::vector<Time> & input) {
  std::vector<int> order = solution(input);
  int ans = verify(input, order);
  std::cout << ans << std::endl;
}

int main(int argc, char ** argv) {
  int N;
  std::vector<Time> input;

  std::cin >> N;
  input.resize(N);
  for(int i = 0; i < N;i++) {
    std::cin >> input[i].s >> input[i].p >> input[i].c;
  }

  execute_test(input);
}


