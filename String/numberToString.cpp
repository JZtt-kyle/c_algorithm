/* 
 * 题目: 替换数字
 * 功能描述: 给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。 例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。
 * 网址:https://kamacoder.com/problempage.php?pid=1064
*/

#include <iostream>
#include <string>
using namespace std;

void numberToString(string s) {
    int count = 0;
    int length1 = s.size();
    for(int i = 0; i < length1; i++) {
        if(s[i] >= '0' && s[i] <= '9') count++;
    }
    int length2 = length1 + 5 * count;
    s.resize(length2);
    while(length1 < length2) {
        if(s[length1] >= '0' && s[length1] <= '9'){
            s[length2--] = 'r';
            s[length2--] = 'e';
            s[length2--] = 'b';
            s[length2--] = 'm';
            s[length2--] = 'u';
            s[length2--] = 'n';
            length1--;
        }else{
            s[length2--] = s[length1--];
        }
    }
    cout << s <<endl;
}


int main(){

    numberToString("a1b1c1");
    return 0;
}