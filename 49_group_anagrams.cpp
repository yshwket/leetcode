class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*for loop
            start at first string
            order it alphabecically
            if a word isnt in unordered map
                store that alphabecically ordered string into an unordered map 
                [word, index of vector] AND result vector<vector<string>>
            else, push vack vector<vector<string>> at the index of the similar word
        */

        unordered_map<string, int> damap;
        vector<vector<string>> result;
        vector<string> copy = strs;
        // ordering word alphabetically loop
        for (int i =0; i < strs.size(); ++i){
            sort(copy[i].begin(), copy[i].end(), less<char>());
        }

        //checking the map if its there and pushign to result
        int result_tracker = 0;
        for (int j =0; j < copy.size(); ++j){
            //if not in map
            if (damap.find(copy[j]) == damap.end()){
                damap[copy[j]] = result_tracker;
                result_tracker++;
                //{} does a list initialization
                result.push_back(vector<string>{strs[j]});
            }
            //in map
            else{
                //pull result damap (outer vector) and push back inner vector
                result[damap[copy[j]]].push_back(strs[j]);
            }
        }
        return result;
    }
};