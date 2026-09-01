class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        // create a hashmap to store character mappings
        map<char, char> charMapping;

        for(int i = 0; i < s.length(); i++){
            char org = s[i];
            char rep = t[i];

            if(charMapping.find(org) == charMapping.end()){
                // check if replacement character is already mapped
                bool alreadyMapped = false;

                for(auto it : charMapping){
                    if(it.second == rep){
                        alreadyMapped = true;
                        break;
                    }
                }

                if(!alreadyMapped)
                    charMapping[org] = rep;
                else
                    return false;
            }
            else{
                char mappedcharacter = charMapping[org];

                if(mappedcharacter != rep)
                    return false;
            }
        }

        return true;
    }
};