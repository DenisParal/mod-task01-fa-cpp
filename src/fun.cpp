unsigned int faStr1(const char *str){
    long long index=0;
    unsigned int counter=0;
    bool is_word=false;
    bool is_numeric=false;
    while(str[index]!='\0') {
        if(str[index]==' '){ // Any symbol except space
            if(is_word && !is_numeric){
                ++counter;
            }
            is_word=false;
            is_numeric=false;
        }else{
            if(str[index]>47 && str[index]<58){ // integers in ASCII
                is_numeric=true;
            }
            is_word=true;
        }
        ++index;
    }
    if(is_word && !is_numeric){
        ++counter;
    }
    return counter;
}

unsigned int faStr2(const char *str){
    long long index=0;
    unsigned int counter=0;
    bool is_word=false;
    bool has_upper=false;
    while(str[index]!='\0') {
        if(str[index]==' '){ // Any symbol except space
            if(is_word && !has_upper){
                ++counter;
            }
            is_word=false;
            has_upper=false;
        }else{
            if(str[index]>64 && str[index]<91){ // Upper case letters in ASCII
                if(index==0 || index>0 && str[index-1]==' '){
                    is_word=true;
                }else{
                    has_upper=true;
                }
            }else{
                if(!(str[index]>64 && str[index]<91) && !(str[index]>96 && str[index]<123)){ // Any letter in ASCII
                    is_word=false;
                }
            }
        }
        ++index;
    }
    if(is_word && !has_upper){
        ++counter;
    }
    return counter;
}

unsigned int faStr3(const char *str){
    long long index=0;
    unsigned int counter=0;
    unsigned int symbol_counter=0;
    bool is_word=false;
    while(str[index]!='\0') {
        if(str[index]==' '){ // Any symbol except space
            if(is_word){
                ++counter;
            }
            is_word=false;
        }else{
            is_word=true;
            ++symbol_counter;
        }
        ++index;
    }
    if(is_word){
        ++counter;
    }
    if(counter==0){
        return 0;
    }
    if(((symbol_counter*10)/counter)%10>=5){
        return symbol_counter/counter+1;
    }else{
        return symbol_counter/counter;
    }
}