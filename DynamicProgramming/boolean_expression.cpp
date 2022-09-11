#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool string2bool(const char c)
{
  return c == '1' ? true : false;
}

string bool2string(bool a)
{
  if (a)
  {
    return "true";
  }
  return "false";
}

bool isOperand(const char c)
{
  if (c == '1' || c == '0')
  {
    return true;
  }
  return false;
}

bool isOperator(const char c)
{
  if (c == '^' || c == '&' || c == '|')
  {
    return true;
  }
  return false;
}

int countExp(string s, bool ans, unordered_map<string, int> memo)
{
  if (s.length() == 0)
  {
    return 0;
  }

  if (s.length() == 1)
  {
    return string2bool(s.at(0)) == ans ? 1 : 0;
  }

  string key = s + bool2string(ans);
  if (memo.find(key) != memo.end())
  {
    return memo[key];
  }

  int ret = 0;
  for (int i = 1; i < s.length(); i += 2)
  {
    string left = s.substr(0, i);
    string right = s.substr(i + 1);
    int leftTrue = countExp(left, true, memo);
    int leftFalse = countExp(left, false, memo);
    int rightTrue = countExp(right, true, memo);
    int rightFalse = countExp(right, false, memo);
    int total = (leftTrue + leftFalse) * (rightTrue + rightFalse);

    int totalTrue = 0;
    const char opt = s.at(i);
    if (opt == '^')
    {
      totalTrue = leftTrue * rightFalse + leftFalse * rightTrue;
    }
    if (opt == '&')
    {
      totalTrue = leftTrue * rightTrue;
    }
    if (opt == '|')
    {
      // totalTrue = leftTrue * rightTrue + leftFalse * rightTrue + leftTrue * rightFalse;
      totalTrue = total - leftFalse * rightFalse;
    }

    ret += (ans ? totalTrue : total - totalTrue);
  }

  memo[s + bool2string(ans)] = ret;
  return ret;
}

int main()
{
  string s, a;
  bool ans;

  cin >> s;
  cin >> a;
  ans = a == "true" ? true : false;

  unordered_map<string, int> memo;

  int ret = countExp(s, ans, memo);
  cout << "patterns: " << ret << endl;

  return 0;
}
