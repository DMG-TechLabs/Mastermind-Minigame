#include "checks.h"
#include <iostream>


vector<int> checks(string key, string user_try){
    int correct = 0;
    int full_correct = 0;
    int string_len = key.length();
    for(int i=0;i<string_len;i++){
        if(key.at(i) == user_try.at(i)) {
            full_correct++;
            correct++;
            continue;  
        }

        for(int j=0;j<string_len;j++){
            if(key.at(j) == user_try.at(i) && i != j) {
                correct++;
                // cout << endl << key.at(j) << ":"+j << endl << user_try.at(i) << ":"+i << endl;

                break;
            }
        }
    }
    int only_correct_char = correct - full_correct;
    return vector<int>{only_correct_char,full_correct,};
}