/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let res = s.trim();
    let words = res.split(" ");
    // console.log(words)
    return words[words.length - 1].length;
};