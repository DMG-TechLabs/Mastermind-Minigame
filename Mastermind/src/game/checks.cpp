#include "checks.h"
#include <iostream>

vector<int> checks(string key, string user_try){
    int string_len = key.length();
    int full_correct[string_len];
    int correct = 0;

    for(int i=0;i<string_len;i++){
        full_correct[i] = 0;
        if(key.at(i) == user_try.at(i)) full_correct[i] = 1; 
    }

    for(int i=0;i<string_len;i++){
        for(int j=0;j<string_len;j++){
            if(user_try.at(i) == key.at(j) && full_correct[j] != 1) correct++;
        }
    }
    
    int f_correct=0;
    for(int i=0;i<string_len;i++){
        f_correct += full_correct[i];
    }
    return vector<int>{correct,f_correct};
}

