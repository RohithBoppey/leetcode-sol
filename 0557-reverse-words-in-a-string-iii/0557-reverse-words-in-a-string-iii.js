/**
 * @param {string} s
 * @return {string}
 */

const reverseString = (s) => {
    let result = "";    
    let n = s.length;
    for(let i = n - 1; i >= 0; i--){
        result += s[i];
    }
    return result;
}

var reverseWords = function(s) {
    const words = s.split(" ");
    let result = "";
    for(let word of words){
        result += reverseString(word);
        result += ' ';
    }
    result = result.slice(0, result.length - 1);
    return result;
};