/**
 * @param {string} s
 * @return {string}
 */

function reverseBySeparator(string, separator) {
  return string.split(separator).reverse().join(separator);
}

var reverseWords = function(string) {
//     remember that s is a string
   // Output becomes !ediuG tpircsavaJ siht ot emocleW
var reverseEntireSentence = reverseBySeparator(string, "");

// Output becomes emocleW ot siht tpircsavaJ !ediuG
var reverseEachWord = reverseBySeparator(reverseEntireSentence, " ");
    return reverseEachWord;
};