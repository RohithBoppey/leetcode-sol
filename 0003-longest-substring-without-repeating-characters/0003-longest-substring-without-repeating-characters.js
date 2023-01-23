/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let n = s.length;
    if(n === 0){
        // empty string
        return 0;
    }

    let ans = 0;
    let start = 0, end = 0;
    let map = new Map();
    while(end < n){
        if(map.get(s[end]) === undefined){
            map.set(s[end], 0);
        }
        map.set(s[end], map.get(s[end]) + 1)
        // console.log(map);
        if(end - start + 1 === map.size){
            // window size met and all are unique chars so far
            ans = Math.max(ans, end - start + 1);
            end++;
        }else{
            while(end - start + 1 > map.size){
                map.set(s[start], map.get(s[start]) - 1);
                if(map.get(s[start]) === 0){
                    map.delete(s[start]);
                }
                start++;
            }
            end++;
        }
    }
    return ans;
};