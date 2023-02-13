/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    const words = s.split(" ");
    words.reverse();
    console.log(words);
    let word = "";
    for(let i of words){
        if(i != ''){
            word += i;
            word += ' ';
        }
    }
    word = word.substring(0, word.length - 1)
    return word;
};