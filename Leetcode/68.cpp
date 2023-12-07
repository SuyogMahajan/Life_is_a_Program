// 68. Text Justification

// Given an array of strings words and a width maxWidth, format the text such that each 
// line has exactly maxWidth characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you 
// can in each line. Pad extra spaces ' ' when necessary so that each line has exactly
//  maxWidth characters.

// Extra spaces between words should be distributed as evenly as possible. If the 
// number of spaces on a line does not divide evenly between words, the empty slots
//  on the left will be assigned more spaces than the slots on the right.

// For the last line of text, it should be left-justified, and no extra space 
// is inserted between words.

// Note:

// A word is defined as a character sequence consisting of non-space characters
//  only.
// Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
// The input array words contains at least one word.
 

// Example 1:

// Input: words = ["This", "is", "an", "example", "of", "text", "justification."],
//  maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Example 2:

// Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
// Output:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// Explanation: Note that the last line is "shall be    " instead of "shall     be", 
// because the last line must be left-justified instead of fully-justified.
// Note that the second line is also left-justified because it contains only one word.
// Example 3:

// Input: words = ["Science","is","what","we","understand","well","enough","to",
// "explain","to","a","computer.","Art","is","everything","else","we","do"], 
// maxWidth = 20
// Output:
// [
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
// ]
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int n = words.size();
        int i = 0;
        vector<string> t;

        int crr_len = 0;
        int normal_spaces = 0;

        while(i < n) {

            if(crr_len + words[i].length() <= maxWidth ) {
                crr_len += words[i].length(); 
                t.push_back(words[i]);       
                i++; 
            }else{
                // no of total spaces
                int extra_spaces = maxWidth - (crr_len - normal_spaces);
                int l = t.size();
                int even_spaces = (extra_spaces / (l-1));
                int remaining = extra_spaces-even_spaces;
                string a = "";
                for(int j  = 0 ; j < l-1;j++) {
                    a.append(t[i]);
                    a.append(string(even_spaces,' '));
                }

                a.append(t[l-1]);
                a.append(string(remaining,' '));
                // cout << even_spaces <<" " << extra_spaces <<" ";
                // for(auto x: t) cout << x <<" ";
                // cout << endl;
                ans.push_back(a);
                crr_len = 0;
                t = vector<string>();
                continue;
            }

            if(crr_len + 1 <= maxWidth) {
                crr_len++;
                normal_spaces++;
            }
        }

        return ans;
    }
};

int main() {

        vector<string> temp;
        int n;
        cin >> n;

        for(int i = 0; i < n;i++) {
            string s;
            cin >> s;
            temp.push_back(s);
        }

        int m;
        cin >> m;
        Solution *sol = new Solution();
        vector<string> ans = sol->fullJustify(temp,m);

        for(auto x:ans) {
            cout << x << endl;
        }
    
return 0;
}