bool isValid(char * s){
    StackNode ps;
    Stackininit (&ps);
    if(s == NULL) {
        return false;
    }
    for(int i = 0;s[i]!= '\0';i++) {
        if((s[i] == ']')||
           (s[i] == '}')||
           (s[i] == ')')) {
            if(Stackempty(&ps)) {
                return false;
            }
            if(s[i] == ']'&& StackTop (&ps) == '[' ||
					s[i] == '}'&& StackTop (&ps) == '{' ||
					s[i] == ')'&& StackTop (&ps) == '(') {
					StackPop(&ps);
					continue;
				}
            else 
                return false;
        }
        if((s[i] == '[')||
           (s[i] == '{')||
           (s[i] == '(')) {
            StackPush(&ps,s[i]);
            }
        }
    if(Stackempty(&ps)) {
        return true;
    }
    else 
        return false;        
}