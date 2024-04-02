class MinStack {
public:
    vector< pair<int,int> > st;   
    MinStack() {

    }

    void push(int val) {
        if(st.empty() ) {
            pair<int,int> p = make_pair(val, val);
            st.push_back(p);
        }
        else {
            pair<int,int> p;
            p.first = val;
            p.second = min(val, st.back().second);
            st.push_back(p);
        }

    }

    void pop() {
        st.pop_back();
    }

    int top() {
        return st.back().first;
    }

    int getMin() {
       return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxLen = 0;

        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            if(ch == '(') {
                st.push(i);
            }
            else {
                st.pop();
                if(st.empty()) {
                    st.push(i);
                }
                else {
                    int len = i - st.top();
                    maxLen = max(len, maxLen);
                }

            }
        }
        return maxLen;
    }
};




class Solution {
public:
vector<int> prevSmallerElement(vector<int>& input) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(input.size());

        //left to right -> prev smaller
        for(int i=0; i<input.size(); i++) {
                int curr = input[i];

                //apka answer stack me 
                while(s.top() != -1 && input[s.top()] >= curr) {
                        s.pop();
                }

                //chotta element mil chuka h -> ans store
                ans[i] = s.top();

                //push krdo curr element ko
                s.push(i);
        }
        return ans;
}

vector<int> nextSmaller(vector<int> &input) {
  stack<int> s;
  s.push(-1);

  vector<int> ans(input.size());

  for(int i=input.size()-1; i>=0; i--) {
          int curr = input[i];

          //apka answer stack me 
          while(s.top() != -1 && input[s.top()] >= curr) {
                  s.pop();
          }

          //chotta element mil chuka h -> ans store
          ans[i] = s.top();

          //push krdo curr element ko
          s.push(i);
  }
  return ans;
}
    int largestRectangleArea(vector<int>& heights) {
         //step1: prevSmaller output
        vector<int> prev = prevSmallerElement(heights);

        //step2: nextSmaller call
        vector<int> next = nextSmaller(heights);

        int maxArea = INT_MIN;
        int size = heights.size();

        for(int i=0; i<heights.size(); i++) {
                int length = heights[i];

                if(next[i] == -1) {
                        next[i] = size;
                }

                int width = next[i] - prev[i] - 1;

                int area = length * width;
                maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};



#include <iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> prevSmallerElement(vector<int>& input) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(input.size());

        //left to right -> prev smaller
        for(int i=0; i<input.size(); i++) {
                int curr = input[i];

                //apka answer stack me 
                while(s.top() >= curr) {
                        s.pop();
                }

                //chotta element mil chuka h -> ans store
                ans[i] = s.top();

                //push krdo curr element ko
                s.push(curr);
        }
        return ans;
}

vector<int> nextSmaller(vector<int> &input) {
  stack<int> s;
  s.push(-1);

  vector<int> ans(input.size());

  for(int i=input.size()-1; i>=0; i--) {
          int curr = input[i];

          //apka answer stack me 
          while(s.top() >= curr) {
                  s.pop();
          }

          //chotta element mil chuka h -> ans store
          ans[i] = s.top();

          //push krdo curr element ko
          s.push(curr);
  }
  return ans;
}

int main() {
  vector<int> input;
  input.push_back(2);
  input.push_back(1);
  input.push_back(4);
  input.push_back(3);

  vector<int> ans1 = nextSmaller(input);

  cout << "Printing ans1" << endl;

  for(int i=0; i<input.size(); i++) {
          cout << ans1[i] << " ";
  }cout << endl;

  vector<int> ans2 = prevSmallerElement(input);
  cout << "Printing ans2 " << endl;
  for(int i=0; i<input.size(); i++) {
          cout << ans2[i] << " ";
  }cout << endl;



  return 0;
}






#include <iostream>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;

vector<int> prevSmallerElement(vector<int>& input) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(input.size());

        //left to right -> prev smaller
        for(int i=0; i<input.size(); i++) {
                int curr = input[i];

                //apka answer stack me 
                while(s.top() != -1 && input[s.top()] >= curr) {
                        s.pop();
                }

                //chotta element mil chuka h -> ans store
                ans[i] = s.top();

                //push krdo curr element ko
                s.push(i);
        }
        return ans;
}

vector<int> nextSmaller(vector<int> &input) {
  stack<int> s;
  s.push(-1);

  vector<int> ans(input.size());

  for(int i=input.size()-1; i>=0; i--) {
          int curr = input[i];

          //apka answer stack me 
          while(s.top() != -1 && input[s.top()] >= curr) {
                  s.pop();
          }

          //chotta element mil chuka h -> ans store
          ans[i] = s.top();

          //push krdo curr element ko
          s.push(i);
  }
  return ans;
}

int getRectangularAreaHistogram(vector<int> &height) {

        //step1: prevSmaller output
        vector<int> prev = prevSmallerElement(height);

        //step2: nextSmaller call
        vector<int> next = nextSmaller(height);

        int maxArea = INT_MIN;
        int size = height.size();

        for(int i=0; i<height.size(); i++) {
                int length = height[i];

                if(next[i] == -1) {
                        next[i] = size;
                }

                int width = next[i] - prev[i] - 1;

                int area = length * width;
                maxArea = max(maxArea, area);
        }

        return maxArea;
}

int main() {
  vector<int> v;
  v.push_back(2);
  v.push_back(1);
  v.push_back(5);
  v.push_back(6);
  v.push_back(2);
  v.push_back(3);

  cout << "Ans is: " << getRectangularAreaHistogram(v) << endl;
  return 0;
}