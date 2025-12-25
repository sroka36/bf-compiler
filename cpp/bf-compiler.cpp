#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

int main() {

  // 입력
  string input;

  // 포인터
  list<int> pointer;
  pointer.push_back(0);
  int loc = 0;

  // 루프 처리
  list<int> temp_loc;
  list<int> bracket_open;
  list<int> bracket_close;
  int pos = 0;

  getline(cin, input); //\n까지 입력을 받음 반대로 cin<<은 공백이 기준임.

  //괄호 찾기
  for (int j = 0; j < input.length(); j++) {
    switch (input[j]) {
      case '[':
        temp_loc.push_back(j);
        break;
      case ']':
        if (temp_loc.size() != 0) {
          bracket_open.push_back(temp_loc.back());
          bracket_close.push_back(j);
          temp_loc.pop_back();
        }
        break;
    }
  }

  //본 구문: 리스트라서 iterator을 이용함
  for (int i = 0; i < input.length(); i++) {
    switch (input[i]) {
      case '+':
        *(next(pointer.begin(), loc)) += 1;
        break;
      case '-':
        *(next(pointer.begin(), loc)) -= 1;
        break;
      case '>':
        loc += 1;
        if (pointer.size() < loc + 1) {
          pointer.push_back(0);
        }
        break;
      case '<':
        if (loc > 0) { loc -= 1; }
        break;
      case '.':
        cout << char(*(next(pointer.begin(), loc)));
        break;
      case '[':
        if (*(next(pointer.begin(), loc)) == 0) {

            pos = distance(bracket_open.begin(), 
              find(bracket_open.begin(), bracket_open.end(), i));
          
          i = *(next(bracket_close.begin(), pos)) - 1;
        }
        break;
      case ']':
        if (*(next(pointer.begin(), loc)) != 0) {

            pos = distance(bracket_close.begin(), 
              find(bracket_close.begin(), bracket_close.end(), i));
          
          i = *(next(bracket_open.begin(), pos)) - 1;
        }
        break;
      }
    }
    
  //출력 오류 수정
  cout << endl;

  return 0;
}